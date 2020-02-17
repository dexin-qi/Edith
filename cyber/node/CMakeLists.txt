###### bazel lib: _node_node ######
add_library(_node_node SHARED
  "node.cc"
  "node.h"
  "/apollo/cyber/node/node_channel_impl.h"
  "/apollo/cyber/node/node_service_impl.h"
  "/apollo/cyber/node/reader.h"
  "/apollo/cyber/node/writer.h"
  "/apollo/cyber/blocker/intra_reader.h"
  "/apollo/cyber/blocker/intra_writer.h"
  "/apollo/cyber/message/message_traits.h"
  "/apollo/cyber/service/service.h"
  "/apollo/cyber/service/client.h"
  "/apollo/cyber/node/reader_base.h"
  "/apollo/cyber/blocker/blocker.h"
  "/apollo/cyber/croutine/routine_factory.h"
  "/apollo/cyber/data/data_visitor.h"
  "/apollo/cyber/node/writer_base.h"
  "/apollo/cyber/common/log.h"
  "/apollo/cyber/message/message_header.h"
  "/apollo/cyber/message/protobuf_traits.h"
  "/apollo/cyber/message/py_message_traits.h"
  "/apollo/cyber/message/raw_message_traits.h"
  "/apollo/cyber/base/macros.h"
  "/apollo/cyber/service/service_base.h"
  "/apollo/cyber/service/client_base.h"
  "/apollo/cyber/common/macros.h"
  "/apollo/cyber/common/util.h"
  "/apollo/cyber/binary.h"
  "/apollo/cyber/message/py_message.h"
  "/apollo/cyber/message/raw_message.h"
  "/apollo/cyber/common/environment.h"
  "/apollo/cyber/common/time_conversion.h"
  "/apollo/cyber/common/types.h"
)
target_link_libraries(_node_node _common_global_data)
target_link_libraries(_node_node _cyber_proto_cc_lib)
target_link_libraries(_node_node _service_discovery_topology_manager)
target_link_libraries(_node_node _scheduler_scheduler)
target_link_libraries(_node_node _time_time)
target_link_libraries(_node_node _transport_transport)
target_link_libraries(_node_node _blocker_blocker_manager)
target_link_libraries(_node_node _event_perf_event_cache)
target_link_libraries(_node_node glog)
target_link_libraries(_node_node _message_protobuf_factory)
target_link_libraries(_node_node _common_file)

set_target_properties(_node_node PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_node_node PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

