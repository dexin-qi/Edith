#!/usr/bin/env bash

###############################################################################
# Copyright 2020 The EdithRT Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
###############################################################################

VERSION=""
ARCH=$(uname -m)
VERSION_X86_64="x86_64"
VERSION_AARCH64="aarch64_dev"
VERSION_OPT=""

function show_usage()
{
cat <<EOF
Usage: $(basename $0) [options] ...
OPTIONS:
    -h, --help             Display this help and exit.
    -t, --tag <version>    Specify which version of a docker image to pull.
    stop                   Stop all running cyber containers.
EOF
exit 0
}

function stop_containers()
{
running_containers=$(docker ps --format "{{.Names}}")

for i in ${running_containers[*]}
do
  if [[ "$i" =~ edith_* ]];then
    printf %-*s 70 "stopping container: $i ..."
    docker stop $i > /dev/null
    if [ $? -eq 0 ];then
      printf "\033[32m[DONE]\033[0m\n"
    else
      printf "\033[31m[FAILED]\033[0m\n"
    fi
  fi
done
}

PROJECT_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )/../.." && pwd )"

if [ ! -e /edith ]; then
    sudo ln -sf ${PROJECT_ROOT} /edith
fi

if [ -e /proc/sys/kernel ]; then
    echo "/edith/data/core/core_%e.%p" | sudo tee /proc/sys/kernel/core_pattern > /dev/null
fi

source ${PROJECT_ROOT}/scripts/edith_base.sh CYBER_ONLY

while [ $# -gt 0 ]
do
    case "$1" in
    -t|--tag)
        VAR=$1
        [ -z $VERSION_OPT ] || echo -e "\033[093mWarning\033[0m: mixed option $VAR with $VERSION_OPT, only the last one will take effect.\n"
        shift
        VERSION_OPT=$1
        [ -z ${VERSION_OPT// /} ] && echo -e "Missing parameter for $VAR" && exit 2
        [[ $VERSION_OPT =~ ^-.* ]] && echo -e "Missing parameter for $VAR" && exit 2
        ;;
    -h|--help)
        show_usage
        ;;
    stop)
	    stop_containers
	    exit 0
	    ;;
    *)
        echo -e "\033[93mWarning\033[0m: Unknown option: $1"
        exit 2
        ;;
    esac
    shift
done

if [ ! -z "$VERSION_OPT" ]; then
    VERSION=$VERSION_OPT
elif [ ${ARCH} == "x86_64" ]; then
    VERSION=${VERSION_X86_64}
elif [ ${ARCH} == "aarch64" ]; then
    VERSION=${VERSION_AARCH64}
else
    echo "Unknown architecture: ${ARCH}"
    exit 0
fi

if [ -z "${DOCKER_REPO}" ]; then
    DOCKER_REPO=dustinksi/edith
fi

if [ -z "$VERSION_OPT" ]; then
    VERSION="x86_64"
fi


IMG=${DOCKER_REPO}:$VERSION

function local_volumes() {
    volumes="-v $PROJECT_ROOT:/edith"
    case "$(uname -s)" in
        Linux)
            case "$(lsb_release -r | cut -f2)" in
                14.04)
                    volumes="${volumes} "
                    ;;
                *)
                    volumes="${volumes} -v /dev:/dev "
                    ;;
            esac
            volumes="${volumes} -v /media:/media \
                                -v /tmp/.X11-unix:/tmp/.X11-unix:rw \
                                -v /etc/localtime:/etc/localtime:ro \
                                -v /usr/src:/usr/src \
                                -v /lib/modules:/lib/modules"
            ;;
    esac
    echo "${volumes}"
}

function main(){
    info "Start pulling docker image $IMG ..."
    docker pull $IMG
    if [ $? -ne 0 ];then
        error "Failed to pull docker image."
        exit 1
    fi

    DOCKER_NAME="edith_cyber_${USER}"
    docker ps -a --format "{{.Names}}" | grep "$DOCKER_NAME" 1>/dev/null
    if [ $? == 0 ]; then
        docker stop $DOCKER_NAME 1>/dev/null
        docker rm -v -f $DOCKER_NAME 1>/dev/null
    fi

    local display=""
    if [[ -z ${DISPLAY} ]];then
        display=":0"
    else
        display="${DISPLAY}"
    fi

    setup_device

    USER_ID=$(id -u)
    GRP=$(id -g -n)
    GRP_ID=$(id -g)
    LOCAL_HOST=`hostname`
    DOCKER_HOME="/home/$USER"
    if [ "$USER" == "root" ];then
        DOCKER_HOME="/root"
    fi

    info "Starting docker container \"${DOCKER_NAME}\" ..."

    docker run -it \
        -d \
        --privileged \
        --name $DOCKER_NAME \
        -e DISPLAY=$display \
        -e DOCKER_USER=$USER \
        -e USER=$USER \
        -e DOCKER_USER_ID=$USER_ID \
        -e DOCKER_GRP="$GRP" \
        -e DOCKER_GRP_ID=$GRP_ID \
        -e DOCKER_IMG=$IMG \
        -e OMP_NUM_THREADS=1 \
        $(local_volumes) \
        --net host \
        -w /edith \
        --add-host in_edith_docker:127.0.0.1 \
        --add-host ${LOCAL_HOST}:127.0.0.1 \
        --hostname in_edith_docker \
        --shm-size 2G \
        --pid=host \
        -v /dev/null:/dev/raw1394 \
        $IMG \
        /bin/bash

    if [ $? -ne 0 ];then
        error "Failed to start docker container \"${DOCKER_NAME}\" based on image: $IMG"
        exit 1
    fi

    if [ ${ARCH} == "x86_64" ]; then
        if [ "${USER}" != "root" ]; then
            docker exec $DOCKER_NAME bash -c '/edith/scripts/docker_adduser.sh'
        fi
    else
        warning "!!! Due to the problem with 'docker exec' on Drive PX platform, please run '/edith/scripts/docker_adduser.sh' for the first time when you get into the docker !!!"
    fi

    ok "Finished setting up edith docker environment. Now you can enter with: \nbash docker/scripts/edith_into.sh"
    ok "Enjoy!"
}

main
