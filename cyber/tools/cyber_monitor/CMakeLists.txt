add_executable(cyber_monitor
  "cyber_topology_message.cc"
  "general_channel_message.cc"
  "general_message.cc"
  "general_message_base.cc"
  "main.cc"
  "renderable_message.cc"
  "screen.cc"
  "/edith/cyber/tools/cyber_monitor/cyber_topology_message.h"
  "/edith/cyber/tools/cyber_monitor/general_channel_message.h"
  "/edith/cyber/tools/cyber_monitor/screen.h"
  "/edith/cyber/tools/cyber_monitor/renderable_message.h"
  "/edith/cyber/tools/cyber_monitor/general_message.h"
  "/edith/cyber/tools/cyber_monitor/general_message_base.h"
  "/edith/cyber/message/raw_message.h"
  "/edith/cyber/record/record_message.h"
)
target_link_libraries(cyber_monitor _init)
target_link_libraries(cyber_monitor _service_discovery_topology_manager)
target_link_libraries(cyber_monitor -pthread)
target_link_libraries(cyber_monitor -lncurses)
target_link_libraries(cyber_monitor _message_protobuf_factory)
target_link_libraries(cyber_monitor _cyber_core)
target_link_libraries(cyber_monitor -lgflags)

set_target_properties(cyber_monitor PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(cyber_monitor PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

