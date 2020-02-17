export CYBER_PATH=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

binary_path="/edith/build/cyber"

launch_path="/edith/cyber/tools/cyber_launch"
channel_path="/edith/cyber/tools/cyber_channel"
node_path="/edith/cyber/tools/cyber_node"
service_path="/edith/cyber/tools/cyber_service"

recorder_path="/edith/build/cyber/tools/cyber_recorder"
monitor_path="/edith/build/cyber/tools/cyber_monitor"
# qt_path=/usr/local/Qt5.5.1/5.5/gcc_64
# visualizer_path="${apollo_tool_path}/visualizer"
# rosbag_to_record_path="/edith/bazel-bin/modules/data/tools/rosbag_to_record"

python_load_path="/edith/build/cyber/py_wrapper"
py_proto_path="/edith/py_proto"

# export LD_LIBRARY_PATH=${qt_path}/lib:$LD_LIBRARY_PATH
# export QT_QPA_PLATFORM_PLUGIN_PATH=${qt_path}/plugins
#:${qt_path}/bin:${visualizer_path}:${rosbag_to_record_path}
export PATH=${binary_path}:${launch_path}:${channel_path}:${node_path}:${service_path}:${recorder_path}:${monitor_path}:$PATH
export PYTHONPATH=${python_load_path}:${py_proto_path}:${CYBER_PATH}/python:$PYTHONPATH

export CYBER_DOMAIN_ID=80
export CYBER_IP=127.0.0.1

export GLOG_log_dir=/edith/data/log
export GLOG_alsologtostderr=1
export GLOG_colorlogtostderr=1
export GLOG_minloglevel=0

# for DEBUG log
#export GLOG_minloglevel=-1
#export GLOG_v=4
export sysmo_start=0

source ${CYBER_PATH}/tools/cyber_tools_auto_complete.bash
