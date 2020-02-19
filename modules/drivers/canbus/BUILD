load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "sensor_gflags",
    srcs = ["sensor_gflags.cc"],
    hdrs = ["sensor_gflags.h"],
    deps = [
        "//external:gflags",
    ],
)

cc_library(
    name = "_drivers_canbus_sensor_canbus_lib",
    hdrs = ["sensor_canbus.h"],
    deps = [
        _drivers_canbus_sensor_gflags
        _common_monitor_log
        _drivers_canbus_can_client_can_client_factory
        _drivers_canbus_can_comm_can_receiver
        _drivers_canbus_can_comm_message_manager_base
    ],
)

cpplint()
