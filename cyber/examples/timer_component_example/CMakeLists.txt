###### bazel lib: timer_component_example ######
add_library(timer_component_example SHARED
  "timer_component_example.cc"
  "timer_component_example.h"
)
target_link_libraries(timer_component_example _examples_proto_examples_cc_proto)
target_link_libraries(timer_component_example _cyber_core)

set_target_properties(timer_component_example PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(timer_component_example PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)
