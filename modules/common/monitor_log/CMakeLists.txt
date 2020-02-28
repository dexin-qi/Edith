### auto generate from bazel lib : _common_monitor_log_monitor_log ###
add_library(_common_monitor_log_monitor_log SHARED
  "/edith/modules/common/util/message_util.h"
  "/edith/modules/common/monitor_log/monitor_log_buffer.cc"
  "/edith/modules/common/monitor_log/monitor_log_buffer.h"
  "/edith/modules/common/monitor_log/monitor_logger.h"
  "/edith/modules/common/monitor_log/monitor_logger.cc"
)

target_include_directories(_common_monitor_log_monitor_log SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_common_monitor_log_monitor_log ${PROTOBUF_LIBRARY} standalone_absl)
target_link_libraries(_common_monitor_log_monitor_log _common_time_time)
target_link_libraries(_common_monitor_log_monitor_log _cyber_core)
target_link_libraries(_common_monitor_log_monitor_log _cyber_proto_cc_lib)
target_link_libraries(_common_monitor_log_monitor_log _modules_proto_cc_lib)
target_link_libraries(_common_monitor_log_monitor_log standalone_absl)

set_target_properties(_common_monitor_log_monitor_log PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_monitor_log_monitor_log PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

