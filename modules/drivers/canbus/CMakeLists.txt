### auto generate from bazel lib : _drivers_canbus_sensor_gflags ###
add_library(_drivers_canbus_sensor_gflags SHARED
  "/edith/modules/drivers/canbus/sensor_gflags.h"
  "/edith/modules/drivers/canbus/sensor_gflags.cc"
)

target_link_libraries(_drivers_canbus_sensor_gflags gflags)

set_target_properties(_drivers_canbus_sensor_gflags PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_drivers_canbus_sensor_gflags PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

