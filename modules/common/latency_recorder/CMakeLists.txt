### auto generate from bazel lib : _common_latency_recorder_latency_recorder ###
add_library(_common_latency_recorder_latency_recorder SHARED
  "/edith/cyber/binary.h"
  "/edith/modules/common/util/message_util.h"
  "/edith/cyber/common/log.h"
  "/edith/modules/common/latency_recorder/latency_recorder.h"
  "/edith/modules/common/latency_recorder/latency_recorder.cc"
)

target_include_directories(_common_latency_recorder_latency_recorder SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_common_latency_recorder_latency_recorder ${PROTOBUF_LIBRARY} standalone_absl)
target_link_libraries(_common_latency_recorder_latency_recorder _common_adapters_adapter_gflags)
target_link_libraries(_common_latency_recorder_latency_recorder _common_time_time)
target_link_libraries(_common_latency_recorder_latency_recorder _cyber_core)
target_link_libraries(_common_latency_recorder_latency_recorder _modules_proto_cc_lib)
target_link_libraries(_common_latency_recorder_latency_recorder glog)
target_link_libraries(_common_latency_recorder_latency_recorder standalone_absl)

set_target_properties(_common_latency_recorder_latency_recorder PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_latency_recorder_latency_recorder PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

