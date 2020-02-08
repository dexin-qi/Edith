export CYBER_PATH=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
export EDITH_PATH=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)

# cxx app: mainboard
binary_path="/Edith/build/cyber"
# cxx tools(recorder, monitor) path
cxx_tools_path="/Edith/build/cyber/tools"
# python tools
launch_path="${CYBER_PATH}/tools/cyber_launch"
channel_path="${CYBER_PATH}/tools/cyber_channel"
node_path="${CYBER_PATH}/tools/cyber_node"
service_path="${CYBER_PATH}/tools/cyber_service"
# add binarise to PATH
export PATH=${binary_path}:${cxx_tools_path}:${recorder_path}:${launch_path}:${channel_path}:${node_path}:${service_path}:$PATH

# cxx shared libs for Python Interface
PYTHON_LD_PATH="${EDITH_PATH}/build/cyber/py_wrapper"
export PYTHONPATH=${PYTHON_LD_PATH}:${EDITH_PATH}/py_proto:${CYBER_PATH}/python:$PYTHONPATH

# execute env values
export CYBER_DOMAIN_ID=80
export CYBER_IP=127.0.0.1

export GLOG_log_dir=/Edith/data/log
export GLOG_alsologtostderr=1
export GLOG_colorlogtostderr=1
export GLOG_minloglevel=0

# DEBUG log
# export GLOG_minloglevel=-1
# export GLOG_v=4

export sysmo_start=0

source ${CYBER_PATH}/tools/cyber_tools_auto_complete.bash
