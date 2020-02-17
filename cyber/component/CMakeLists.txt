###### bazel lib: _component_timer_component ######
add_library(_component_timer_component SHARED
  "timer_component.cc"
  "timer_component.h"
  "/apollo/cyber/component/component_base.h"
  "/apollo/cyber/transport/message/history.h"
  "/apollo/cyber/transport/transmitter/hybrid_transmitter.h"
  "/apollo/cyber/transport/transmitter/intra_transmitter.h"
  "/apollo/cyber/transport/transmitter/rtps_transmitter.h"
  "/apollo/cyber/transport/transmitter/shm_transmitter.h"
  "/apollo/cyber/base/signal.h"
  "/apollo/cyber/base/thread_pool.h"
  "/apollo/cyber/transport/message/history_attributes.h"
  "/apollo/cyber/transport/transmitter/transmitter.h"
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

