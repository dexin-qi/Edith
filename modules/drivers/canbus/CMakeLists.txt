add_subdirectory(common)

add_library(_drivers_canbus_sensor_gflags
    sensor_gflags.cc
    sensor_gflags.h
)

target_link_libraries(_drivers_canbus_sensor_gflags -lgflags)
