### auto generate from bazel lib : _localization_common_localization_common ###
add_library(_localization_common_localization_common SHARED
  "/edith/modules/localization/common/localization_gflags.h"
  "/edith/modules/localization/common/localization_gflags.cc"
)

target_link_libraries(_localization_common_localization_common _cyber_core)
target_link_libraries(_localization_common_localization_common _modules_proto_cc_lib)

set_target_properties(_localization_common_localization_common PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_localization_common_localization_common PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

