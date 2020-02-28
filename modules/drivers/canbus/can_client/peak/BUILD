load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "peak_can_client",
    srcs = ["peak_can_client.cc"],
    hdrs = ["peak_can_client.h",
            "PCANBasic.h"],
    linkopts = ["-lpcanbasic"]
    deps = [
        "//modules/drivers/canbus/can_client",
    ],
)

cc_test(
    name = "peak_can_client_test",
    size = "small",
    srcs = ["peak_can_client_test.cc"],
    deps = [
        "//cyber",
        "//modules/drivers/canbus/can_client/peak:peak_can_client",
        "//modules/drivers/canbus/common:canbus_common",
        "@gtest//:main",
    ],
)

cpplint()
