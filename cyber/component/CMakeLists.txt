###### bazel lib: _component_timer_component ######
add_library(_component_timer_component SHARED
  "timer_component.cc"
  "timer_component.h"
  "/edith/cyber/component/component_base.h"
  "/edith/cyber/transport/message/history.h"
  "/edith/cyber/transport/transmitter/hybrid_transmitter.h"
  "/edith/cyber/transport/transmitter/intra_transmitter.h"
  "/edith/cyber/transport/transmitter/rtps_transmitter.h"
  "/edith/cyber/transport/transmitter/shm_transmitter.h"
  "/edith/cyber/base/signal.h"
  "/edith/cyber/base/thread_pool.h"
  "/edith/cyber/transport/message/history_attributes.h"
  "/edith/cyber/transport/transmitter/transmitter.h"
)
target_link_libraries(_component_timer_component _blocker_blocker_manager)
target_link_libraries(_component_timer_component _timer_timer)
target_link_libraries(_component_timer_component _class_loader_class_loader)
target_link_libraries(_component_timer_component _node_node)
target_link_libraries(_component_timer_component _transport_endpoint)
target_link_libraries(_component_timer_component _transport_message_info)
target_link_libraries(_component_timer_component _event_perf_event_cache)

set_target_properties(_component_timer_component PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_component_timer_component PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

