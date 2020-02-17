###### bazel lib: common_component_example ######
add_library(common_component_example SHARED
  "common_component_example.cc"
  "common_component_example.h"
)
target_link_libraries(common_component_example _examples_proto_examples_cc_proto)
target_link_libraries(common_component_example _cyber_core)

set_target_properties(common_component_example PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(common_component_example PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)