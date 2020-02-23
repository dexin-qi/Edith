### auto generate from bazel lib : _common_util_util ###
add_library(_common_util_util SHARED
  "/edith/modules/common/math/euler_angles_zxy.h"
  "/edith/modules/common/util/util.h"
  "/edith/cyber/binary.h"
  "/edith/modules/common/math/kalman_filter.h"
  "/edith/modules/common/math/quaternion.h"
  "/edith/modules/common/util/util.cc"
  "/edith/modules/common/math/factorial.h"
  "/edith/modules/common/math/curve_fitting.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/common/types.h"
)

target_include_directories(_common_util_util SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_util_util ${EIGEN3_LIBRRIES})
target_link_libraries(_common_util_util _common_math_angle)
target_link_libraries(_common_util_util _common_math_cartesian_frenet_conversion)
target_link_libraries(_common_util_util _common_math_geometry)
target_link_libraries(_common_util_util _common_math_integral)
target_link_libraries(_common_util_util _common_math_linear_interpolation)
target_link_libraries(_common_util_util _common_math_lqr)
target_link_libraries(_common_util_util _common_math_matrix_operations)
target_link_libraries(_common_util_util _common_math_mpc)
target_link_libraries(_common_util_util _common_math_search)
target_link_libraries(_common_util_util _common_math_sin_table)
target_link_libraries(_common_util_util _modules_proto_cc_lib)
target_link_libraries(_common_util_util glog)

set_target_properties(_common_util_util PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_util_util PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

### auto generate from bazel lib : _common_util_string_util ###
add_library(_common_util_string_util SHARED
  "/edith/modules/common/util/string_util.h"
  "/edith/modules/common/util/future.h"
  "/edith/modules/common/util/string_util.cc"
)

target_include_directories(_common_util_string_util SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_common_util_string_util ${PROTOBUF_LIBRARY} standalone_absl)
target_link_libraries(_common_util_string_util standalone_absl)

set_target_properties(_common_util_string_util PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_util_string_util PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

### auto generate from bazel lib : _common_util_json_util ###
add_library(_common_util_json_util SHARED
  "/edith/modules/common/util/json.hpp"
  "/edith/cyber/common/macros.h"
  "/edith/modules/common/util/json_util.cc"
  "/edith/modules/common/util/json_util.h"
  "/edith/cyber/binary.h"
  "/edith/cyber/base/macros.h"
  "/edith/cyber/common/time_conversion.h"
  "/edith/cyber/common/util.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/common/types.h"
  "/edith/cyber/common/environment.h"
)

target_include_directories(_common_util_json_util SYSTEM PUBLIC ${JSONCPP_INCLUDE_DIRS})
target_link_libraries(_common_util_json_util ${JSONCPP_LIBRARIES})
target_include_directories(_common_util_json_util SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_common_util_json_util ${PROTOBUF_LIBRARY} standalone_absl)
target_link_libraries(_common_util_json_util _common_file)
target_link_libraries(_common_util_json_util _common_global_data)
target_link_libraries(_common_util_json_util glog)

set_target_properties(_common_util_json_util PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_util_json_util PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)


### auto generate from bazel test : _common_util_util_test ###
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/util/util.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/math/integral.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/math/angle.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/math/polygon2d.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/math/factorial.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/math/sin_table.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/math/curve_fitting.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/math/linear_interpolation.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/math/matrix_operations.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/math/aabox2d.h)
dustin_var_append(UTIL_TEST_FILES /edith/cyber/common/types.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/math/cartesian_frenet_conversion.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/util/string_util.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/math/qp_solver/active_set_qp_solver.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/math/mpc_solver.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/math/line_segment2d.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/math/linear_quadratic_regulator.h)
dustin_var_append(UTIL_TEST_FILES /edith/cyber/common/log.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/util/future.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/math/euler_angles_zxy.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/math/box2d.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/math/qp_solver/qp_solver.h)
dustin_var_append(UTIL_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/math/vec2d.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/math/quaternion.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/math/kalman_filter.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/math/qp_solver/qp_solver_gflags.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/util/util_test.cc)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/math/search.h)
dustin_var_append(UTIL_TEST_FILES /edith/modules/common/math/aaboxkdtree2d.h)

edith_test(_common_util_util_test
SRCS
  ${UTIL_TEST_FILES}
)
target_include_directories(_common_util_util_test SYSTEM PUBLIC "/usr/local/include")
target_link_libraries(_common_util_util_test libqpOASES.so)
target_include_directories(_common_util_util_test SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_util_util_test ${EIGEN3_LIBRRIES})
target_include_directories(_common_util_util_test SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_common_util_util_test ${PROTOBUF_LIBRARY} standalone_absl)
target_link_libraries(_common_util_util_test _common_math_angle)
target_link_libraries(_common_util_util_test _common_math_cartesian_frenet_conversion)
target_link_libraries(_common_util_util_test _common_math_geometry)
target_link_libraries(_common_util_util_test _common_math_integral)
target_link_libraries(_common_util_util_test _common_math_linear_interpolation)
target_link_libraries(_common_util_util_test _common_math_lqr)
target_link_libraries(_common_util_util_test _common_math_matrix_operations)
target_link_libraries(_common_util_util_test _common_math_mpc)
target_link_libraries(_common_util_util_test _common_math_qp_solver_active_set_qp_solver)
target_link_libraries(_common_util_util_test _common_math_qp_solver_qp_solver)
target_link_libraries(_common_util_util_test _common_math_qp_solver_qp_solver_gflags)
target_link_libraries(_common_util_util_test _common_math_search)
target_link_libraries(_common_util_util_test _common_math_sin_table)
target_link_libraries(_common_util_util_test _common_util_string_util)
target_link_libraries(_common_util_util_test _common_util_util)
target_link_libraries(_common_util_util_test _modules_proto_cc_lib)
target_link_libraries(_common_util_util_test gflags)
target_link_libraries(_common_util_util_test glog)
target_link_libraries(_common_util_util_test libosqp.so)
target_link_libraries(_common_util_util_test standalone_absl)

### auto generate from bazel test : _common_util_message_util_test ###
dustin_var_append(MESSAGE_UTIL_TEST_FILES /edith/cyber/common/file.h)
dustin_var_append(MESSAGE_UTIL_TEST_FILES /edith/cyber/time/duration.h)
dustin_var_append(MESSAGE_UTIL_TEST_FILES /edith/cyber/base/atomic_rw_lock.h)
dustin_var_append(MESSAGE_UTIL_TEST_FILES /edith/modules/common/time/timer.h)
dustin_var_append(MESSAGE_UTIL_TEST_FILES /edith/cyber/common/time_conversion.h)
dustin_var_append(MESSAGE_UTIL_TEST_FILES /edith/cyber/base/atomic_hash_map.h)
dustin_var_append(MESSAGE_UTIL_TEST_FILES /edith/modules/common/time/time.h)
dustin_var_append(MESSAGE_UTIL_TEST_FILES /edith/cyber/common/types.h)
dustin_var_append(MESSAGE_UTIL_TEST_FILES /edith/modules/common/configs/config_gflags.h)
dustin_var_append(MESSAGE_UTIL_TEST_FILES /edith/cyber/base/macros.h)
dustin_var_append(MESSAGE_UTIL_TEST_FILES /edith/cyber/common/log.h)
dustin_var_append(MESSAGE_UTIL_TEST_FILES /edith/cyber/base/rw_lock_guard.h)
dustin_var_append(MESSAGE_UTIL_TEST_FILES /edith/modules/common/util/message_util.h)
dustin_var_append(MESSAGE_UTIL_TEST_FILES /edith/cyber/common/macros.h)
dustin_var_append(MESSAGE_UTIL_TEST_FILES /edith/modules/common/util/message_util_test.cc)
dustin_var_append(MESSAGE_UTIL_TEST_FILES /edith/cyber/common/global_data.h)
dustin_var_append(MESSAGE_UTIL_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(MESSAGE_UTIL_TEST_FILES /edith/cyber/common/util.h)
dustin_var_append(MESSAGE_UTIL_TEST_FILES /edith/modules/common/time/time_util.h)
dustin_var_append(MESSAGE_UTIL_TEST_FILES /edith/cyber/time/time.h)
dustin_var_append(MESSAGE_UTIL_TEST_FILES /edith/cyber/common/environment.h)

edith_test(_common_util_message_util_test
SRCS
  ${MESSAGE_UTIL_TEST_FILES}
)
target_include_directories(_common_util_message_util_test SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_common_util_message_util_test ${PROTOBUF_LIBRARY} standalone_absl)
target_link_libraries(_common_util_message_util_test _common_configs_config_gflags)
target_link_libraries(_common_util_message_util_test _common_file)
target_link_libraries(_common_util_message_util_test _common_global_data)
target_link_libraries(_common_util_message_util_test _common_time_time)
target_link_libraries(_common_util_message_util_test _cyber_proto_cc_lib)
target_link_libraries(_common_util_message_util_test _modules_proto_cc_lib)
target_link_libraries(_common_util_message_util_test _time_duration)
target_link_libraries(_common_util_message_util_test _time_time)
target_link_libraries(_common_util_message_util_test gflags)
target_link_libraries(_common_util_message_util_test glog)
target_link_libraries(_common_util_message_util_test standalone_absl)

### auto generate from bazel test : _common_util_string_util_test ###
dustin_var_append(STRING_UTIL_TEST_FILES /edith/modules/common/util/string_util_test.cc)
dustin_var_append(STRING_UTIL_TEST_FILES /edith/modules/common/util/future.h)
dustin_var_append(STRING_UTIL_TEST_FILES /edith/modules/common/util/string_util.h)

edith_test(_common_util_string_util_test
SRCS
  ${STRING_UTIL_TEST_FILES}
)
target_include_directories(_common_util_string_util_test SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_common_util_string_util_test ${PROTOBUF_LIBRARY} standalone_absl)
target_link_libraries(_common_util_string_util_test _common_util_string_util)
target_link_libraries(_common_util_string_util_test standalone_absl)

### auto generate from bazel test : _common_util_factory_test ###
dustin_var_append(FACTORY_TEST_FILES /edith/modules/common/util/factory_test.cc)
dustin_var_append(FACTORY_TEST_FILES /edith/cyber/common/macros.h)
dustin_var_append(FACTORY_TEST_FILES /edith/cyber/common/file.h)
dustin_var_append(FACTORY_TEST_FILES /edith/modules/common/util/factory.h)
dustin_var_append(FACTORY_TEST_FILES /edith/cyber/common/global_data.h)
dustin_var_append(FACTORY_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(FACTORY_TEST_FILES /edith/cyber/base/atomic_rw_lock.h)
dustin_var_append(FACTORY_TEST_FILES /edith/cyber/common/util.h)
dustin_var_append(FACTORY_TEST_FILES /edith/cyber/common/time_conversion.h)
dustin_var_append(FACTORY_TEST_FILES /edith/cyber/base/atomic_hash_map.h)
dustin_var_append(FACTORY_TEST_FILES /edith/cyber/base/macros.h)
dustin_var_append(FACTORY_TEST_FILES /edith/cyber/common/log.h)
dustin_var_append(FACTORY_TEST_FILES /edith/cyber/base/rw_lock_guard.h)
dustin_var_append(FACTORY_TEST_FILES /edith/cyber/common/types.h)
dustin_var_append(FACTORY_TEST_FILES /edith/cyber/common/environment.h)

edith_test(_common_util_factory_test
SRCS
  ${FACTORY_TEST_FILES}
)
target_link_libraries(_common_util_factory_test _common_file)
target_link_libraries(_common_util_factory_test _common_global_data)
target_link_libraries(_common_util_factory_test _cyber_proto_cc_lib)
target_link_libraries(_common_util_factory_test glog)

### auto generate from bazel test : _common_util_lru_cache_test ###
dustin_var_append(LRU_CACHE_TEST_FILES /edith/modules/common/util/lru_cache_test.cc)
dustin_var_append(LRU_CACHE_TEST_FILES /edith/modules/common/util/lru_cache.h)

edith_test(_common_util_lru_cache_test
SRCS
  ${LRU_CACHE_TEST_FILES}
)

### auto generate from bazel test : _common_util_points_downsampler_test ###
dustin_var_append(POINTS_DOWNSAMPLER_TEST_FILES /edith/cyber/common/file.h)
dustin_var_append(POINTS_DOWNSAMPLER_TEST_FILES /edith/modules/common/math/polygon2d.h)
dustin_var_append(POINTS_DOWNSAMPLER_TEST_FILES /edith/cyber/base/atomic_rw_lock.h)
dustin_var_append(POINTS_DOWNSAMPLER_TEST_FILES /edith/modules/common/math/aabox2d.h)
dustin_var_append(POINTS_DOWNSAMPLER_TEST_FILES /edith/cyber/common/time_conversion.h)
dustin_var_append(POINTS_DOWNSAMPLER_TEST_FILES /edith/cyber/base/atomic_hash_map.h)
dustin_var_append(POINTS_DOWNSAMPLER_TEST_FILES /edith/modules/common/util/points_downsampler.h)
dustin_var_append(POINTS_DOWNSAMPLER_TEST_FILES /edith/cyber/common/types.h)
dustin_var_append(POINTS_DOWNSAMPLER_TEST_FILES /edith/modules/common/util/string_util.h)
dustin_var_append(POINTS_DOWNSAMPLER_TEST_FILES /edith/modules/common/math/line_segment2d.h)
dustin_var_append(POINTS_DOWNSAMPLER_TEST_FILES /edith/cyber/base/macros.h)
dustin_var_append(POINTS_DOWNSAMPLER_TEST_FILES /edith/cyber/common/log.h)
dustin_var_append(POINTS_DOWNSAMPLER_TEST_FILES /edith/cyber/base/rw_lock_guard.h)
dustin_var_append(POINTS_DOWNSAMPLER_TEST_FILES /edith/modules/common/util/future.h)
dustin_var_append(POINTS_DOWNSAMPLER_TEST_FILES /edith/cyber/common/macros.h)
dustin_var_append(POINTS_DOWNSAMPLER_TEST_FILES /edith/modules/common/math/box2d.h)
dustin_var_append(POINTS_DOWNSAMPLER_TEST_FILES /edith/cyber/common/global_data.h)
dustin_var_append(POINTS_DOWNSAMPLER_TEST_FILES /edith/modules/common/math/vec2d.h)
dustin_var_append(POINTS_DOWNSAMPLER_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(POINTS_DOWNSAMPLER_TEST_FILES /edith/modules/common/util/points_downsampler_test.cc)
dustin_var_append(POINTS_DOWNSAMPLER_TEST_FILES /edith/cyber/common/util.h)
dustin_var_append(POINTS_DOWNSAMPLER_TEST_FILES /edith/modules/common/math/aaboxkdtree2d.h)
dustin_var_append(POINTS_DOWNSAMPLER_TEST_FILES /edith/cyber/common/environment.h)

edith_test(_common_util_points_downsampler_test
SRCS
  ${POINTS_DOWNSAMPLER_TEST_FILES}
)
target_include_directories(_common_util_points_downsampler_test SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_util_points_downsampler_test ${EIGEN3_LIBRRIES})
target_include_directories(_common_util_points_downsampler_test SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_common_util_points_downsampler_test ${PROTOBUF_LIBRARY} standalone_absl)
target_link_libraries(_common_util_points_downsampler_test _common_file)
target_link_libraries(_common_util_points_downsampler_test _common_global_data)
target_link_libraries(_common_util_points_downsampler_test _common_math_geometry)
target_link_libraries(_common_util_points_downsampler_test _common_util_string_util)
target_link_libraries(_common_util_points_downsampler_test _cyber_proto_cc_lib)
target_link_libraries(_common_util_points_downsampler_test glog)
target_link_libraries(_common_util_points_downsampler_test libosqp.so)
target_link_libraries(_common_util_points_downsampler_test standalone_absl)

### auto generate from bazel test : _common_util_json_util_test ###
dustin_var_append(JSON_UTIL_TEST_FILES /edith/modules/common/util/json.hpp)
dustin_var_append(JSON_UTIL_TEST_FILES /edith/cyber/common/macros.h)
dustin_var_append(JSON_UTIL_TEST_FILES /edith/cyber/common/file.h)
dustin_var_append(JSON_UTIL_TEST_FILES /edith/modules/common/util/json_util.h)
dustin_var_append(JSON_UTIL_TEST_FILES /edith/cyber/common/global_data.h)
dustin_var_append(JSON_UTIL_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(JSON_UTIL_TEST_FILES /edith/cyber/base/atomic_rw_lock.h)
dustin_var_append(JSON_UTIL_TEST_FILES /edith/cyber/common/util.h)
dustin_var_append(JSON_UTIL_TEST_FILES /edith/cyber/common/time_conversion.h)
dustin_var_append(JSON_UTIL_TEST_FILES /edith/cyber/base/atomic_hash_map.h)
dustin_var_append(JSON_UTIL_TEST_FILES /edith/cyber/base/macros.h)
dustin_var_append(JSON_UTIL_TEST_FILES /edith/cyber/common/log.h)
dustin_var_append(JSON_UTIL_TEST_FILES /edith/cyber/base/rw_lock_guard.h)
dustin_var_append(JSON_UTIL_TEST_FILES /edith/modules/common/util/json_util_test.cc)
dustin_var_append(JSON_UTIL_TEST_FILES /edith/cyber/common/types.h)
dustin_var_append(JSON_UTIL_TEST_FILES /edith/cyber/common/environment.h)

edith_test(_common_util_json_util_test
SRCS
  ${JSON_UTIL_TEST_FILES}
)
target_include_directories(_common_util_json_util_test SYSTEM PUBLIC ${JSONCPP_INCLUDE_DIRS})
target_link_libraries(_common_util_json_util_test ${JSONCPP_LIBRARIES})
target_include_directories(_common_util_json_util_test SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_common_util_json_util_test ${PROTOBUF_LIBRARY} standalone_absl)
target_link_libraries(_common_util_json_util_test _common_file)
target_link_libraries(_common_util_json_util_test _common_global_data)
target_link_libraries(_common_util_json_util_test _common_util_json_util)
target_link_libraries(_common_util_json_util_test _cyber_proto_cc_lib)
target_link_libraries(_common_util_json_util_test _modules_proto_cc_lib)
target_link_libraries(_common_util_json_util_test glog)
