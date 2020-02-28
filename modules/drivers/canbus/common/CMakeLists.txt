### auto generate from bazel lib : _drivers_canbus_common_canbus_common ###
add_library(_drivers_canbus_common_canbus_common SHARED
  "/edith/modules/drivers/canbus/common/canbus_consts.h"
  "/edith/modules/drivers/canbus/common/byte.cc"
  "/edith/modules/drivers/canbus/common/byte.h"
)

target_link_libraries(_drivers_canbus_common_canbus_common _drivers_canbus_sensor_gflags)

set_target_properties(_drivers_canbus_common_canbus_common PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_drivers_canbus_common_canbus_common PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)


### auto generate from bazel test : _drivers_canbus_common_byte_test ###
dustin_var_append(BYTE_TEST_FILES /edith/modules/drivers/canbus/common/canbus_consts.h)
dustin_var_append(BYTE_TEST_FILES /edith/modules/drivers/canbus/sensor_gflags.h)
dustin_var_append(BYTE_TEST_FILES /edith/modules/drivers/canbus/common/byte_test.cc)
dustin_var_append(BYTE_TEST_FILES /edith/modules/drivers/canbus/common/byte.h)

edith_test(_drivers_canbus_common_byte_test
SRCS
  ${BYTE_TEST_FILES}
)
target_link_libraries(_drivers_canbus_common_byte_test _drivers_canbus_common_canbus_common)
target_link_libraries(_drivers_canbus_common_byte_test _drivers_canbus_sensor_gflags)
target_link_libraries(_drivers_canbus_common_byte_test gflags)
