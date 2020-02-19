add_library(_driver_canbus_byte
    byte.cc
    byte.h
    canbus_consts.h
)

target_link_libraries(_driver_canbus_byte _drivers_canbus_sensor_gflags)