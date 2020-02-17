###### bazel lib: _common_file ######
add_library(_common_file SHARED
  "file.cc"
  "file.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/binary.h"
)
target_link_libraries(_common_file glog)

set_target_properties(_common_file PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_file PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _common_global_data ######
add_library(_common_global_data SHARED
  "global_data.cc"
  "global_data.h"
  "/edith/cyber/base/atomic_hash_map.h"
  "/edith/cyber/base/atomic_rw_lock.h"
  "/edith/cyber/common/environment.h"
  "/edith/cyber/common/macros.h"
  "/edith/cyber/common/util.h"
  "/edith/cyber/base/rw_lock_guard.h"
  "/edith/cyber/base/macros.h"
)
target_link_libraries(_common_global_data _common_file)
target_link_libraries(_common_global_data _cyber_proto_cc_lib)

set_target_properties(_common_global_data PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_global_data PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

