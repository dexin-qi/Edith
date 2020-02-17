###### bazel lib: _time_time ######
add_library(_time_time SHARED
  "time.cc"
  "time.h"
  "/edith/cyber/common/environment.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/common/macros.h"
  "/edith/cyber/common/time_conversion.h"
  "/edith/cyber/common/types.h"
  "/edith/cyber/common/util.h"
  "/edith/cyber/binary.h"
  "/edith/cyber/base/macros.h"
)
target_link_libraries(_time_time _time_duration)
target_link_libraries(_time_time _common_file)
target_link_libraries(_time_time _common_global_data)
target_link_libraries(_time_time glog)

set_target_properties(_time_time PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_time_time PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _time_rate ######
add_library(_time_rate SHARED
  "rate.cc"
  "rate.h"
  "/edith/cyber/common/environment.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/common/macros.h"
  "/edith/cyber/common/time_conversion.h"
  "/edith/cyber/common/types.h"
  "/edith/cyber/common/util.h"
  "/edith/cyber/binary.h"
  "/edith/cyber/base/macros.h"
)
target_link_libraries(_time_rate _time_duration)
target_link_libraries(_time_rate _time_time)
target_link_libraries(_time_rate _common_file)
target_link_libraries(_time_rate _common_global_data)
target_link_libraries(_time_rate glog)

set_target_properties(_time_rate PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_time_rate PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _time_duration ######
add_library(_time_duration SHARED
  "duration.cc"
  "duration.h"
  "/edith/cyber/common/environment.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/common/macros.h"
  "/edith/cyber/common/time_conversion.h"
  "/edith/cyber/common/types.h"
  "/edith/cyber/common/util.h"
  "/edith/cyber/binary.h"
  "/edith/cyber/base/macros.h"
)
target_link_libraries(_time_duration _common_file)
target_link_libraries(_time_duration _common_global_data)
target_link_libraries(_time_duration glog)

set_target_properties(_time_duration PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_time_duration PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

