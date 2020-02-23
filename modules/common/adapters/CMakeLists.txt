### auto generate from bazel lib : _common_adapters_adapter_gflags ###
add_library(_common_adapters_adapter_gflags SHARED
  "/edith/modules/common/adapters/adapter_gflags.cc"
  "/edith/modules/common/adapters/adapter_gflags.h"
)

target_link_libraries(_common_adapters_adapter_gflags gflags)

set_target_properties(_common_adapters_adapter_gflags PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_adapters_adapter_gflags PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

