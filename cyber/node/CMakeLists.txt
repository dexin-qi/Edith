###### bazel lib: _node_node ######
add_library(_node_node SHARED
  "node.cc"
  "node.h"
  "/edith/cyber/node/node_channel_impl.h"
  "/edith/cyber/node/node_service_impl.h"
  "/edith/cyber/node/reader.h"
  "/edith/cyber/node/writer.h"
  "/edith/cyber/blocker/intra_reader.h"
  "/edith/cyber/blocker/intra_writer.h"
  "/edith/cyber/message/message_traits.h"
  "/edith/cyber/service/service.h"
  "/edith/cyber/service/client.h"
  "/edith/cyber/node/reader_base.h"
  "/edith/cyber/blocker/blocker.h"
  "/edith/cyber/croutine/routine_factory.h"
  "/edith/cyber/data/data_visitor.h"
  "/edith/cyber/node/writer_base.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/message/message_header.h"
  "/edith/cyber/message/protobuf_traits.h"
  "/edith/cyber/message/py_message_traits.h"
  "/edith/cyber/message/raw_message_traits.h"
  "/edith/cyber/base/macros.h"
  "/edith/cyber/service/service_base.h"
  "/edith/cyber/service/client_base.h"
  "/edith/cyber/common/macros.h"
  "/edith/cyber/common/util.h"
  "/edith/cyber/binary.h"
  "/edith/cyber/message/py_message.h"
  "/edith/cyber/message/raw_message.h"
  "/edith/cyber/common/environment.h"
  "/edith/cyber/common/time_conversion.h"
  "/edith/cyber/common/types.h"
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

