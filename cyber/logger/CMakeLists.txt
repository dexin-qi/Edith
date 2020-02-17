###### bazel lib: _logger_async_logger ######
add_library(_logger_async_logger SHARED
  "async_logger.cc"
  "async_logger.h"
  "/apollo/cyber/base/macros.h"
  "/apollo/cyber/common/environment.h"
  "/apollo/cyber/common/log.h"
  "/apollo/cyber/common/macros.h"
  "/apollo/cyber/common/time_conversion.h"
  "/apollo/cyber/common/types.h"
  "/apollo/cyber/common/util.h"
  "/apollo/cyber/binary.h"
)
target_link_libraries(_logger_async_logger _logger_log_file_object)
target_link_libraries(_logger_async_logger _common_file)
target_link_libraries(_logger_async_logger _common_global_data)
target_link_libraries(_logger_async_logger glog)

set_target_properties(_logger_async_logger PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_logger_async_logger PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _logger_logger_util ######
add_library(_logger_logger_util SHARED
  "logger_util.cc"
  "logger_util.h"
)
target_link_libraries(_logger_logger_util _common_global_data)

set_target_properties(_logger_logger_util PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_logger_logger_util PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _logger_logger ######
add_library(_logger_logger SHARED
  "logger.cc"
  "logger.h"
  "/apollo/cyber/common/environment.h"
  "/apollo/cyber/common/log.h"
  "/apollo/cyber/common/macros.h"
  "/apollo/cyber/common/time_conversion.h"
  "/apollo/cyber/common/types.h"
  "/apollo/cyber/common/util.h"
  "/apollo/cyber/binary.h"
  "/apollo/cyber/base/macros.h"
)
target_link_libraries(_logger_logger _logger_log_file_object)
target_link_libraries(_logger_logger _common_file)
target_link_libraries(_logger_logger _common_global_data)
target_link_libraries(_logger_logger glog)

set_target_properties(_logger_logger PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_logger_logger PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _logger_log_file_object ######
add_library(_logger_log_file_object SHARED
  "log_file_object.cc"
  "log_file_object.h"
  "/apollo/cyber/binary.h"
  "/apollo/cyber/common/log.h"
)
target_link_libraries(_logger_log_file_object _logger_logger_util)
target_link_libraries(_logger_log_file_object glog)

set_target_properties(_logger_log_file_object PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_logger_log_file_object PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

