###### bazel lib: _common_file ######
add_library(_common_file SHARED
  "file.cc"
  "file.h"
  "/apollo/cyber/common/log.h"
  "/apollo/cyber/binary.h"
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
  "/apollo/cyber/base/atomic_hash_map.h"
  "/apollo/cyber/base/atomic_rw_lock.h"
  "/apollo/cyber/common/environment.h"
  "/apollo/cyber/common/macros.h"
  "/apollo/cyber/common/util.h"
  "/apollo/cyber/base/rw_lock_guard.h"
  "/apollo/cyber/base/macros.h"
)
target_link_libraries(_common_global_data _common_file)
target_link_libraries(_common_global_data _cyber_proto_cc_lib)

set_target_properties(_common_global_data PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_global_data PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

