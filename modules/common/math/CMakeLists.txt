### auto generate from bazel lib : _common_math_geometry ###
add_library(_common_math_geometry SHARED
  "/edith/modules/common/math/aabox2d.cc"
  "/edith/modules/common/math/box2d.h"
  "/edith/modules/common/math/polygon2d.cc"
  "/edith/modules/common/math/math_utils.h"
  "/edith/modules/common/math/vec2d.cc"
  "/edith/modules/common/math/line_segment2d.h"
  "/edith/modules/common/math/vec2d.h"
  "/edith/modules/common/math/line_segment2d.cc"
  "/edith/cyber/binary.h"
  "/edith/modules/common/math/polygon2d.h"
  "/edith/modules/common/math/aabox2d.h"
  "/edith/modules/common/math/math_utils.cc"
  "/edith/cyber/common/log.h"
  "/edith/modules/common/math/aaboxkdtree2d.h"
  "/edith/modules/common/math/box2d.cc"
)

target_include_directories(_common_math_geometry SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_geometry ${EIGEN3_LIBRRIES})
target_link_libraries(_common_math_geometry _common_util_string_util)
target_link_libraries(_common_math_geometry glog)
target_link_libraries(_common_math_geometry libosqp.so)
target_link_libraries(_common_math_geometry standalone_absl)

set_target_properties(_common_math_geometry PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_math_geometry PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

### auto generate from bazel lib : _common_math_sin_table ###
add_library(_common_math_sin_table SHARED
  "/edith/modules/common/math/sin_table.h"
  "/edith/modules/common/math/sin_table.cc"
)


set_target_properties(_common_math_sin_table PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_math_sin_table PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

### auto generate from bazel lib : _common_math_angle ###
add_library(_common_math_angle SHARED
  "/edith/modules/common/math/angle.cc"
  "/edith/modules/common/math/angle.h"
)

target_link_libraries(_common_math_angle _common_math_sin_table)

set_target_properties(_common_math_angle PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_math_angle PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

### auto generate from bazel lib : _common_math_matrix_operations ###
add_library(_common_math_matrix_operations SHARED
  "/edith/cyber/common/log.h"
  "/edith/modules/common/math/matrix_operations.cc"
  "/edith/cyber/binary.h"
  "/edith/modules/common/math/matrix_operations.h"
)

target_include_directories(_common_math_matrix_operations SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_matrix_operations ${EIGEN3_LIBRRIES})
target_link_libraries(_common_math_matrix_operations glog)

set_target_properties(_common_math_matrix_operations PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_math_matrix_operations PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

### auto generate from bazel lib : _common_math_path_matcher ###
add_library(_common_math_path_matcher SHARED
  "/edith/modules/common/math/path_matcher.cc"
  "/edith/modules/common/math/path_matcher.h"
)

target_link_libraries(_common_math_path_matcher _common_math_linear_interpolation)
target_link_libraries(_common_math_path_matcher _modules_proto_cc_lib)

set_target_properties(_common_math_path_matcher PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_math_path_matcher PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

### auto generate from bazel lib : _common_math_mpc_osqp ###
add_library(_common_math_mpc_osqp SHARED
  "/edith/cyber/common/log.h"
  "/edith/modules/common/math/mpc_osqp.h"
  "/edith/cyber/binary.h"
  "/edith/modules/common/math/mpc_osqp.cc"
)

target_include_directories(_common_math_mpc_osqp SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_mpc_osqp ${EIGEN3_LIBRRIES})
target_link_libraries(_common_math_mpc_osqp glog)
target_link_libraries(_common_math_mpc_osqp libosqp.so)

set_target_properties(_common_math_mpc_osqp PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_math_mpc_osqp PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

### auto generate from bazel lib : _common_math_search ###
add_library(_common_math_search SHARED
  "/edith/modules/common/math/search.h"
  "/edith/modules/common/math/search.cc"
)


set_target_properties(_common_math_search PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_math_search PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

### auto generate from bazel lib : _common_math_linear_interpolation ###
add_library(_common_math_linear_interpolation SHARED
  "/edith/modules/common/math/linear_interpolation.cc"
  "/edith/modules/common/math/linear_interpolation.h"
)

target_link_libraries(_common_math_linear_interpolation _common_math_geometry)
target_link_libraries(_common_math_linear_interpolation _modules_proto_cc_lib)

set_target_properties(_common_math_linear_interpolation PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_math_linear_interpolation PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

### auto generate from bazel lib : _common_math_integral ###
add_library(_common_math_integral SHARED
  "/edith/modules/common/math/integral.h"
  "/edith/cyber/binary.h"
  "/edith/modules/common/math/integral.cc"
  "/edith/cyber/common/log.h"
)

target_link_libraries(_common_math_integral glog)

set_target_properties(_common_math_integral PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_math_integral PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

### auto generate from bazel lib : _common_math_lqr ###
add_library(_common_math_lqr SHARED
  "/edith/cyber/common/log.h"
  "/edith/modules/common/math/linear_quadratic_regulator.cc"
  "/edith/cyber/binary.h"
  "/edith/modules/common/math/linear_quadratic_regulator.h"
)

target_include_directories(_common_math_lqr SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_lqr ${EIGEN3_LIBRRIES})
target_link_libraries(_common_math_lqr glog)

set_target_properties(_common_math_lqr PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_math_lqr PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

### auto generate from bazel lib : _common_math_mpc ###
add_library(_common_math_mpc SHARED
  "/edith/cyber/common/log.h"
  "/edith/modules/common/math/mpc_solver.cc"
  "/edith/cyber/binary.h"
  "/edith/modules/common/math/mpc_solver.h"
)

target_include_directories(_common_math_mpc SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_mpc ${EIGEN3_LIBRRIES})
target_link_libraries(_common_math_mpc _common_math_qp_solver_active_set_qp_solver)
target_link_libraries(_common_math_mpc _common_math_qp_solver_qp_solver)
target_link_libraries(_common_math_mpc glog)

set_target_properties(_common_math_mpc PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_math_mpc PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

### auto generate from bazel lib : _common_math_cartesian_frenet_conversion ###
add_library(_common_math_cartesian_frenet_conversion SHARED
  "/edith/cyber/common/log.h"
  "/edith/modules/common/math/cartesian_frenet_conversion.cc"
  "/edith/modules/common/math/cartesian_frenet_conversion.h"
  "/edith/cyber/binary.h"
)

target_include_directories(_common_math_cartesian_frenet_conversion SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_cartesian_frenet_conversion ${EIGEN3_LIBRRIES})
target_link_libraries(_common_math_cartesian_frenet_conversion _common_math_geometry)
target_link_libraries(_common_math_cartesian_frenet_conversion glog)

set_target_properties(_common_math_cartesian_frenet_conversion PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_math_cartesian_frenet_conversion PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)


### auto generate from bazel test : _common_math_matrix_operations_test ###
dustin_var_append(MATRIX_OPERATIONS_TEST_FILES /edith/cyber/common/log.h)
dustin_var_append(MATRIX_OPERATIONS_TEST_FILES /edith/modules/common/math/matrix_operations_test.cc)
dustin_var_append(MATRIX_OPERATIONS_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(MATRIX_OPERATIONS_TEST_FILES /edith/modules/common/math/matrix_operations.h)

edith_test(_common_math_matrix_operations_test
SRCS
  ${MATRIX_OPERATIONS_TEST_FILES}
)
target_include_directories(_common_math_matrix_operations_test SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_matrix_operations_test ${EIGEN3_LIBRRIES})
target_link_libraries(_common_math_matrix_operations_test _common_math_matrix_operations)
target_link_libraries(_common_math_matrix_operations_test glog)

### auto generate from bazel test : _common_math_angle_test ###
dustin_var_append(ANGLE_TEST_FILES /edith/modules/common/math/sin_table.h)
dustin_var_append(ANGLE_TEST_FILES /edith/modules/common/math/angle_test.cc)
dustin_var_append(ANGLE_TEST_FILES /edith/modules/common/math/angle.h)

edith_test(_common_math_angle_test
SRCS
  ${ANGLE_TEST_FILES}
)
target_link_libraries(_common_math_angle_test _common_math_angle)
target_link_libraries(_common_math_angle_test _common_math_sin_table)

### auto generate from bazel test : _common_math_mpc_osqp_test ###
dustin_var_append(MPC_OSQP_TEST_FILES /edith/modules/common/math/qp_solver/active_set_qp_solver.h)
dustin_var_append(MPC_OSQP_TEST_FILES /edith/modules/common/math/mpc_solver.h)
dustin_var_append(MPC_OSQP_TEST_FILES /edith/modules/common/math/qp_solver/qp_solver.h)
dustin_var_append(MPC_OSQP_TEST_FILES /edith/modules/common/math/qp_solver/qp_solver_gflags.h)
dustin_var_append(MPC_OSQP_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(MPC_OSQP_TEST_FILES /edith/modules/common/math/mpc_osqp_test.cc)
dustin_var_append(MPC_OSQP_TEST_FILES /edith/cyber/common/log.h)
dustin_var_append(MPC_OSQP_TEST_FILES /edith/modules/common/math/mpc_osqp.h)

edith_test(_common_math_mpc_osqp_test
SRCS
  ${MPC_OSQP_TEST_FILES}
)
target_include_directories(_common_math_mpc_osqp_test SYSTEM PUBLIC "/usr/local/include")
target_link_libraries(_common_math_mpc_osqp_test libqpOASES.so)
target_include_directories(_common_math_mpc_osqp_test SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_mpc_osqp_test ${EIGEN3_LIBRRIES})
target_link_libraries(_common_math_mpc_osqp_test _common_math_mpc)
target_link_libraries(_common_math_mpc_osqp_test _common_math_mpc_osqp)
target_link_libraries(_common_math_mpc_osqp_test _common_math_qp_solver_active_set_qp_solver)
target_link_libraries(_common_math_mpc_osqp_test _common_math_qp_solver_qp_solver)
target_link_libraries(_common_math_mpc_osqp_test _common_math_qp_solver_qp_solver_gflags)
target_link_libraries(_common_math_mpc_osqp_test gflags)
target_link_libraries(_common_math_mpc_osqp_test glog)
target_link_libraries(_common_math_mpc_osqp_test libosqp.so)

### auto generate from bazel test : _common_math_mpc_test ###
dustin_var_append(MPC_TEST_FILES /edith/modules/common/math/qp_solver/active_set_qp_solver.h)
dustin_var_append(MPC_TEST_FILES /edith/modules/common/math/mpc_solver.h)
dustin_var_append(MPC_TEST_FILES /edith/modules/common/math/qp_solver/qp_solver.h)
dustin_var_append(MPC_TEST_FILES /edith/modules/common/math/mpc_solver_test.cc)
dustin_var_append(MPC_TEST_FILES /edith/modules/common/math/qp_solver/qp_solver_gflags.h)
dustin_var_append(MPC_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(MPC_TEST_FILES /edith/cyber/common/log.h)

edith_test(_common_math_mpc_test
SRCS
  ${MPC_TEST_FILES}
)
target_include_directories(_common_math_mpc_test SYSTEM PUBLIC "/usr/local/include")
target_link_libraries(_common_math_mpc_test libqpOASES.so)
target_include_directories(_common_math_mpc_test SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_mpc_test ${EIGEN3_LIBRRIES})
target_link_libraries(_common_math_mpc_test _common_math_mpc)
target_link_libraries(_common_math_mpc_test _common_math_qp_solver_active_set_qp_solver)
target_link_libraries(_common_math_mpc_test _common_math_qp_solver_qp_solver)
target_link_libraries(_common_math_mpc_test _common_math_qp_solver_qp_solver_gflags)
target_link_libraries(_common_math_mpc_test gflags)
target_link_libraries(_common_math_mpc_test glog)

### auto generate from bazel test : _common_math_math_utils_test ###
dustin_var_append(MATH_UTILS_TEST_FILES /edith/modules/common/util/string_util.h)
dustin_var_append(MATH_UTILS_TEST_FILES /edith/modules/common/math/box2d.h)
dustin_var_append(MATH_UTILS_TEST_FILES /edith/modules/common/math/line_segment2d.h)
dustin_var_append(MATH_UTILS_TEST_FILES /edith/modules/common/math/math_utils_test.cc)
dustin_var_append(MATH_UTILS_TEST_FILES /edith/modules/common/math/vec2d.h)
dustin_var_append(MATH_UTILS_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(MATH_UTILS_TEST_FILES /edith/modules/common/math/polygon2d.h)
dustin_var_append(MATH_UTILS_TEST_FILES /edith/modules/common/math/aabox2d.h)
dustin_var_append(MATH_UTILS_TEST_FILES /edith/cyber/common/log.h)
dustin_var_append(MATH_UTILS_TEST_FILES /edith/modules/common/util/future.h)
dustin_var_append(MATH_UTILS_TEST_FILES /edith/modules/common/math/aaboxkdtree2d.h)

edith_test(_common_math_math_utils_test
SRCS
  ${MATH_UTILS_TEST_FILES}
)
target_include_directories(_common_math_math_utils_test SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_math_utils_test ${EIGEN3_LIBRRIES})
target_include_directories(_common_math_math_utils_test SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_common_math_math_utils_test ${PROTOBUF_LIBRARY} standalone_absl)
target_link_libraries(_common_math_math_utils_test _common_math_geometry)
target_link_libraries(_common_math_math_utils_test _common_util_string_util)
target_link_libraries(_common_math_math_utils_test glog)
target_link_libraries(_common_math_math_utils_test libosqp.so)
target_link_libraries(_common_math_math_utils_test standalone_absl)

### auto generate from bazel test : _common_math_linear_interpolation_test ###
dustin_var_append(LINEAR_INTERPOLATION_TEST_FILES /edith/modules/common/util/string_util.h)
dustin_var_append(LINEAR_INTERPOLATION_TEST_FILES /edith/modules/common/math/aaboxkdtree2d.h)
dustin_var_append(LINEAR_INTERPOLATION_TEST_FILES /edith/modules/common/math/box2d.h)
dustin_var_append(LINEAR_INTERPOLATION_TEST_FILES /edith/modules/common/math/linear_interpolation_test.cc)
dustin_var_append(LINEAR_INTERPOLATION_TEST_FILES /edith/modules/common/math/line_segment2d.h)
dustin_var_append(LINEAR_INTERPOLATION_TEST_FILES /edith/modules/common/math/vec2d.h)
dustin_var_append(LINEAR_INTERPOLATION_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(LINEAR_INTERPOLATION_TEST_FILES /edith/modules/common/math/polygon2d.h)
dustin_var_append(LINEAR_INTERPOLATION_TEST_FILES /edith/modules/common/math/aabox2d.h)
dustin_var_append(LINEAR_INTERPOLATION_TEST_FILES /edith/cyber/common/log.h)
dustin_var_append(LINEAR_INTERPOLATION_TEST_FILES /edith/modules/common/util/future.h)
dustin_var_append(LINEAR_INTERPOLATION_TEST_FILES /edith/modules/common/math/linear_interpolation.h)

edith_test(_common_math_linear_interpolation_test
SRCS
  ${LINEAR_INTERPOLATION_TEST_FILES}
)
target_include_directories(_common_math_linear_interpolation_test SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_linear_interpolation_test ${EIGEN3_LIBRRIES})
target_include_directories(_common_math_linear_interpolation_test SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_common_math_linear_interpolation_test ${PROTOBUF_LIBRARY} standalone_absl)
target_link_libraries(_common_math_linear_interpolation_test _common_math_geometry)
target_link_libraries(_common_math_linear_interpolation_test _common_math_linear_interpolation)
target_link_libraries(_common_math_linear_interpolation_test _common_util_string_util)
target_link_libraries(_common_math_linear_interpolation_test _modules_proto_cc_lib)
target_link_libraries(_common_math_linear_interpolation_test glog)
target_link_libraries(_common_math_linear_interpolation_test libosqp.so)
target_link_libraries(_common_math_linear_interpolation_test standalone_absl)

### auto generate from bazel test : _common_math_search_test ###
dustin_var_append(SEARCH_TEST_FILES /edith/modules/common/math/search_test.cc)
dustin_var_append(SEARCH_TEST_FILES /edith/modules/common/math/search.h)

edith_test(_common_math_search_test
SRCS
  ${SEARCH_TEST_FILES}
)
target_link_libraries(_common_math_search_test _common_math_search)

### auto generate from bazel test : _common_math_integral_test ###
dustin_var_append(INTEGRAL_TEST_FILES /edith/modules/common/math/integral.h)
dustin_var_append(INTEGRAL_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(INTEGRAL_TEST_FILES /edith/cyber/common/log.h)
dustin_var_append(INTEGRAL_TEST_FILES /edith/modules/common/math/integral_test.cc)

edith_test(_common_math_integral_test
SRCS
  ${INTEGRAL_TEST_FILES}
)
target_link_libraries(_common_math_integral_test _common_math_integral)
target_link_libraries(_common_math_integral_test glog)

### auto generate from bazel test : _common_math_vec2d_test ###
dustin_var_append(VEC2D_TEST_FILES /edith/modules/common/util/string_util.h)
dustin_var_append(VEC2D_TEST_FILES /edith/modules/common/math/box2d.h)
dustin_var_append(VEC2D_TEST_FILES /edith/modules/common/math/line_segment2d.h)
dustin_var_append(VEC2D_TEST_FILES /edith/modules/common/math/vec2d.h)
dustin_var_append(VEC2D_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(VEC2D_TEST_FILES /edith/modules/common/math/polygon2d.h)
dustin_var_append(VEC2D_TEST_FILES /edith/modules/common/math/vec2d_test.cc)
dustin_var_append(VEC2D_TEST_FILES /edith/modules/common/math/aabox2d.h)
dustin_var_append(VEC2D_TEST_FILES /edith/cyber/common/log.h)
dustin_var_append(VEC2D_TEST_FILES /edith/modules/common/util/future.h)
dustin_var_append(VEC2D_TEST_FILES /edith/modules/common/math/aaboxkdtree2d.h)

edith_test(_common_math_vec2d_test
SRCS
  ${VEC2D_TEST_FILES}
)
target_include_directories(_common_math_vec2d_test SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_vec2d_test ${EIGEN3_LIBRRIES})
target_include_directories(_common_math_vec2d_test SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_common_math_vec2d_test ${PROTOBUF_LIBRARY} standalone_absl)
target_link_libraries(_common_math_vec2d_test _common_math_geometry)
target_link_libraries(_common_math_vec2d_test _common_util_string_util)
target_link_libraries(_common_math_vec2d_test glog)
target_link_libraries(_common_math_vec2d_test libosqp.so)
target_link_libraries(_common_math_vec2d_test standalone_absl)

### auto generate from bazel test : _common_math_quaternion_test ###
dustin_var_append(QUATERNION_TEST_FILES /edith/modules/common/util/string_util.h)
dustin_var_append(QUATERNION_TEST_FILES /edith/modules/common/math/euler_angles_zxy.h)
dustin_var_append(QUATERNION_TEST_FILES /edith/modules/common/math/box2d.h)
dustin_var_append(QUATERNION_TEST_FILES /edith/modules/common/math/line_segment2d.h)
dustin_var_append(QUATERNION_TEST_FILES /edith/modules/common/math/vec2d.h)
dustin_var_append(QUATERNION_TEST_FILES /edith/modules/common/math/quaternion.h)
dustin_var_append(QUATERNION_TEST_FILES /edith/modules/common/math/quaternion_test.cc)
dustin_var_append(QUATERNION_TEST_FILES /edith/modules/common/math/polygon2d.h)
dustin_var_append(QUATERNION_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(QUATERNION_TEST_FILES /edith/modules/common/math/aabox2d.h)
dustin_var_append(QUATERNION_TEST_FILES /edith/cyber/common/log.h)
dustin_var_append(QUATERNION_TEST_FILES /edith/modules/common/util/future.h)
dustin_var_append(QUATERNION_TEST_FILES /edith/modules/common/math/aaboxkdtree2d.h)

edith_test(_common_math_quaternion_test
SRCS
  ${QUATERNION_TEST_FILES}
)
target_include_directories(_common_math_quaternion_test SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_quaternion_test ${EIGEN3_LIBRRIES})
target_include_directories(_common_math_quaternion_test SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_common_math_quaternion_test ${PROTOBUF_LIBRARY} standalone_absl)
target_link_libraries(_common_math_quaternion_test _common_math_geometry)
target_link_libraries(_common_math_quaternion_test _common_util_string_util)
target_link_libraries(_common_math_quaternion_test _modules_proto_cc_lib)
target_link_libraries(_common_math_quaternion_test glog)
target_link_libraries(_common_math_quaternion_test libosqp.so)
target_link_libraries(_common_math_quaternion_test standalone_absl)

### auto generate from bazel test : _common_math_euler_angles_zxy_test ###
dustin_var_append(EULER_ANGLES_ZXY_TEST_FILES /edith/modules/common/util/string_util.h)
dustin_var_append(EULER_ANGLES_ZXY_TEST_FILES /edith/modules/common/math/euler_angles_zxy.h)
dustin_var_append(EULER_ANGLES_ZXY_TEST_FILES /edith/modules/common/math/box2d.h)
dustin_var_append(EULER_ANGLES_ZXY_TEST_FILES /edith/modules/common/math/line_segment2d.h)
dustin_var_append(EULER_ANGLES_ZXY_TEST_FILES /edith/modules/common/math/vec2d.h)
dustin_var_append(EULER_ANGLES_ZXY_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(EULER_ANGLES_ZXY_TEST_FILES /edith/modules/common/math/euler_angles_zxy_test.cc)
dustin_var_append(EULER_ANGLES_ZXY_TEST_FILES /edith/modules/common/math/polygon2d.h)
dustin_var_append(EULER_ANGLES_ZXY_TEST_FILES /edith/modules/common/math/aabox2d.h)
dustin_var_append(EULER_ANGLES_ZXY_TEST_FILES /edith/cyber/common/log.h)
dustin_var_append(EULER_ANGLES_ZXY_TEST_FILES /edith/modules/common/util/future.h)
dustin_var_append(EULER_ANGLES_ZXY_TEST_FILES /edith/modules/common/math/aaboxkdtree2d.h)

edith_test(_common_math_euler_angles_zxy_test
SRCS
  ${EULER_ANGLES_ZXY_TEST_FILES}
)
target_include_directories(_common_math_euler_angles_zxy_test SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_euler_angles_zxy_test ${EIGEN3_LIBRRIES})
target_include_directories(_common_math_euler_angles_zxy_test SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_common_math_euler_angles_zxy_test ${PROTOBUF_LIBRARY} standalone_absl)
target_link_libraries(_common_math_euler_angles_zxy_test _common_math_geometry)
target_link_libraries(_common_math_euler_angles_zxy_test _common_util_string_util)
target_link_libraries(_common_math_euler_angles_zxy_test glog)
target_link_libraries(_common_math_euler_angles_zxy_test libosqp.so)
target_link_libraries(_common_math_euler_angles_zxy_test standalone_absl)

### auto generate from bazel test : _common_math_aabox2d_test ###
dustin_var_append(AABOX2D_TEST_FILES /edith/modules/common/util/string_util.h)
dustin_var_append(AABOX2D_TEST_FILES /edith/modules/common/math/box2d.h)
dustin_var_append(AABOX2D_TEST_FILES /edith/modules/common/math/aabox2d_test.cc)
dustin_var_append(AABOX2D_TEST_FILES /edith/modules/common/math/line_segment2d.h)
dustin_var_append(AABOX2D_TEST_FILES /edith/modules/common/math/vec2d.h)
dustin_var_append(AABOX2D_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(AABOX2D_TEST_FILES /edith/modules/common/math/polygon2d.h)
dustin_var_append(AABOX2D_TEST_FILES /edith/modules/common/math/aabox2d.h)
dustin_var_append(AABOX2D_TEST_FILES /edith/cyber/common/log.h)
dustin_var_append(AABOX2D_TEST_FILES /edith/modules/common/util/future.h)
dustin_var_append(AABOX2D_TEST_FILES /edith/modules/common/math/aaboxkdtree2d.h)

edith_test(_common_math_aabox2d_test
SRCS
  ${AABOX2D_TEST_FILES}
)
target_include_directories(_common_math_aabox2d_test SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_aabox2d_test ${EIGEN3_LIBRRIES})
target_include_directories(_common_math_aabox2d_test SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_common_math_aabox2d_test ${PROTOBUF_LIBRARY} standalone_absl)
target_link_libraries(_common_math_aabox2d_test _common_math_geometry)
target_link_libraries(_common_math_aabox2d_test _common_util_string_util)
target_link_libraries(_common_math_aabox2d_test glog)
target_link_libraries(_common_math_aabox2d_test libosqp.so)
target_link_libraries(_common_math_aabox2d_test standalone_absl)

### auto generate from bazel test : _common_math_aaboxkdtree2d_test ###
dustin_var_append(AABOXKDTREE2D_TEST_FILES /edith/modules/common/util/string_util.h)
dustin_var_append(AABOXKDTREE2D_TEST_FILES /edith/modules/common/math/box2d.h)
dustin_var_append(AABOXKDTREE2D_TEST_FILES /edith/modules/common/math/line_segment2d.h)
dustin_var_append(AABOXKDTREE2D_TEST_FILES /edith/modules/common/math/vec2d.h)
dustin_var_append(AABOXKDTREE2D_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(AABOXKDTREE2D_TEST_FILES /edith/modules/common/math/polygon2d.h)
dustin_var_append(AABOXKDTREE2D_TEST_FILES /edith/modules/common/math/aabox2d.h)
dustin_var_append(AABOXKDTREE2D_TEST_FILES /edith/cyber/common/log.h)
dustin_var_append(AABOXKDTREE2D_TEST_FILES /edith/modules/common/util/future.h)
dustin_var_append(AABOXKDTREE2D_TEST_FILES /edith/modules/common/math/aaboxkdtree2d.h)
dustin_var_append(AABOXKDTREE2D_TEST_FILES /edith/modules/common/math/aaboxkdtree2d_test.cc)

edith_test(_common_math_aaboxkdtree2d_test
SRCS
  ${AABOXKDTREE2D_TEST_FILES}
)
target_include_directories(_common_math_aaboxkdtree2d_test SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_aaboxkdtree2d_test ${EIGEN3_LIBRRIES})
target_include_directories(_common_math_aaboxkdtree2d_test SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_common_math_aaboxkdtree2d_test ${PROTOBUF_LIBRARY} standalone_absl)
target_link_libraries(_common_math_aaboxkdtree2d_test _common_math_geometry)
target_link_libraries(_common_math_aaboxkdtree2d_test _common_util_string_util)
target_link_libraries(_common_math_aaboxkdtree2d_test glog)
target_link_libraries(_common_math_aaboxkdtree2d_test libosqp.so)
target_link_libraries(_common_math_aaboxkdtree2d_test standalone_absl)

### auto generate from bazel test : _common_math_box2d_test ###
dustin_var_append(BOX2D_TEST_FILES /edith/modules/common/util/string_util.h)
dustin_var_append(BOX2D_TEST_FILES /edith/modules/common/math/box2d.h)
dustin_var_append(BOX2D_TEST_FILES /edith/modules/common/math/box2d_test.cc)
dustin_var_append(BOX2D_TEST_FILES /edith/modules/common/math/line_segment2d.h)
dustin_var_append(BOX2D_TEST_FILES /edith/modules/common/math/vec2d.h)
dustin_var_append(BOX2D_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(BOX2D_TEST_FILES /edith/modules/common/math/polygon2d.h)
dustin_var_append(BOX2D_TEST_FILES /edith/modules/common/math/aabox2d.h)
dustin_var_append(BOX2D_TEST_FILES /edith/cyber/common/log.h)
dustin_var_append(BOX2D_TEST_FILES /edith/modules/common/util/future.h)
dustin_var_append(BOX2D_TEST_FILES /edith/modules/common/math/aaboxkdtree2d.h)

edith_test(_common_math_box2d_test
SRCS
  ${BOX2D_TEST_FILES}
)
target_include_directories(_common_math_box2d_test SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_box2d_test ${EIGEN3_LIBRRIES})
target_include_directories(_common_math_box2d_test SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_common_math_box2d_test ${PROTOBUF_LIBRARY} standalone_absl)
target_link_libraries(_common_math_box2d_test _common_math_geometry)
target_link_libraries(_common_math_box2d_test _common_util_string_util)
target_link_libraries(_common_math_box2d_test glog)
target_link_libraries(_common_math_box2d_test libosqp.so)
target_link_libraries(_common_math_box2d_test standalone_absl)

### auto generate from bazel test : _common_math_polygon2d_test ###
dustin_var_append(POLYGON2D_TEST_FILES /edith/modules/common/util/string_util.h)
dustin_var_append(POLYGON2D_TEST_FILES /edith/modules/common/math/box2d.h)
dustin_var_append(POLYGON2D_TEST_FILES /edith/modules/common/math/polygon2d_test.cc)
dustin_var_append(POLYGON2D_TEST_FILES /edith/modules/common/math/line_segment2d.h)
dustin_var_append(POLYGON2D_TEST_FILES /edith/modules/common/math/vec2d.h)
dustin_var_append(POLYGON2D_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(POLYGON2D_TEST_FILES /edith/modules/common/math/polygon2d.h)
dustin_var_append(POLYGON2D_TEST_FILES /edith/modules/common/math/aabox2d.h)
dustin_var_append(POLYGON2D_TEST_FILES /edith/cyber/common/log.h)
dustin_var_append(POLYGON2D_TEST_FILES /edith/modules/common/util/future.h)
dustin_var_append(POLYGON2D_TEST_FILES /edith/modules/common/math/aaboxkdtree2d.h)

edith_test(_common_math_polygon2d_test
SRCS
  ${POLYGON2D_TEST_FILES}
)
target_include_directories(_common_math_polygon2d_test SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_polygon2d_test ${EIGEN3_LIBRRIES})
target_include_directories(_common_math_polygon2d_test SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_common_math_polygon2d_test ${PROTOBUF_LIBRARY} standalone_absl)
target_link_libraries(_common_math_polygon2d_test _common_math_geometry)
target_link_libraries(_common_math_polygon2d_test _common_util_string_util)
target_link_libraries(_common_math_polygon2d_test glog)
target_link_libraries(_common_math_polygon2d_test libosqp.so)
target_link_libraries(_common_math_polygon2d_test standalone_absl)

### auto generate from bazel test : _common_math_line_segment2d_test ###
dustin_var_append(LINE_SEGMENT2D_TEST_FILES /edith/modules/common/util/string_util.h)
dustin_var_append(LINE_SEGMENT2D_TEST_FILES /edith/modules/common/math/line_segment2d_test.cc)
dustin_var_append(LINE_SEGMENT2D_TEST_FILES /edith/modules/common/math/box2d.h)
dustin_var_append(LINE_SEGMENT2D_TEST_FILES /edith/modules/common/math/line_segment2d.h)
dustin_var_append(LINE_SEGMENT2D_TEST_FILES /edith/modules/common/math/vec2d.h)
dustin_var_append(LINE_SEGMENT2D_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(LINE_SEGMENT2D_TEST_FILES /edith/modules/common/math/polygon2d.h)
dustin_var_append(LINE_SEGMENT2D_TEST_FILES /edith/modules/common/math/aabox2d.h)
dustin_var_append(LINE_SEGMENT2D_TEST_FILES /edith/cyber/common/log.h)
dustin_var_append(LINE_SEGMENT2D_TEST_FILES /edith/modules/common/util/future.h)
dustin_var_append(LINE_SEGMENT2D_TEST_FILES /edith/modules/common/math/aaboxkdtree2d.h)

edith_test(_common_math_line_segment2d_test
SRCS
  ${LINE_SEGMENT2D_TEST_FILES}
)
target_include_directories(_common_math_line_segment2d_test SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_line_segment2d_test ${EIGEN3_LIBRRIES})
target_include_directories(_common_math_line_segment2d_test SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_common_math_line_segment2d_test ${PROTOBUF_LIBRARY} standalone_absl)
target_link_libraries(_common_math_line_segment2d_test _common_math_geometry)
target_link_libraries(_common_math_line_segment2d_test _common_util_string_util)
target_link_libraries(_common_math_line_segment2d_test glog)
target_link_libraries(_common_math_line_segment2d_test libosqp.so)
target_link_libraries(_common_math_line_segment2d_test standalone_absl)

### auto generate from bazel test : _common_math_kalman_filter_test ###
dustin_var_append(KALMAN_FILTER_TEST_FILES /edith/modules/common/math/kalman_filter_test.cc)
dustin_var_append(KALMAN_FILTER_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(KALMAN_FILTER_TEST_FILES /edith/modules/common/math/kalman_filter.h)
dustin_var_append(KALMAN_FILTER_TEST_FILES /edith/cyber/common/log.h)
dustin_var_append(KALMAN_FILTER_TEST_FILES /edith/modules/common/math/matrix_operations.h)

edith_test(_common_math_kalman_filter_test
SRCS
  ${KALMAN_FILTER_TEST_FILES}
)
target_include_directories(_common_math_kalman_filter_test SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_kalman_filter_test ${EIGEN3_LIBRRIES})
target_link_libraries(_common_math_kalman_filter_test _common_math_matrix_operations)
target_link_libraries(_common_math_kalman_filter_test glog)

### auto generate from bazel test : _common_math_cartesian_frenet_conversion_test ###
dustin_var_append(CARTESIAN_FRENET_CONVERSION_TEST_FILES /edith/modules/common/util/string_util.h)
dustin_var_append(CARTESIAN_FRENET_CONVERSION_TEST_FILES /edith/modules/common/math/box2d.h)
dustin_var_append(CARTESIAN_FRENET_CONVERSION_TEST_FILES /edith/modules/common/math/cartesian_frenet_conversion_test.cc)
dustin_var_append(CARTESIAN_FRENET_CONVERSION_TEST_FILES /edith/modules/common/math/line_segment2d.h)
dustin_var_append(CARTESIAN_FRENET_CONVERSION_TEST_FILES /edith/modules/common/math/vec2d.h)
dustin_var_append(CARTESIAN_FRENET_CONVERSION_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(CARTESIAN_FRENET_CONVERSION_TEST_FILES /edith/modules/common/math/polygon2d.h)
dustin_var_append(CARTESIAN_FRENET_CONVERSION_TEST_FILES /edith/modules/common/math/aabox2d.h)
dustin_var_append(CARTESIAN_FRENET_CONVERSION_TEST_FILES /edith/cyber/common/log.h)
dustin_var_append(CARTESIAN_FRENET_CONVERSION_TEST_FILES /edith/modules/common/util/future.h)
dustin_var_append(CARTESIAN_FRENET_CONVERSION_TEST_FILES /edith/modules/common/math/cartesian_frenet_conversion.h)
dustin_var_append(CARTESIAN_FRENET_CONVERSION_TEST_FILES /edith/modules/common/math/aaboxkdtree2d.h)

edith_test(_common_math_cartesian_frenet_conversion_test
SRCS
  ${CARTESIAN_FRENET_CONVERSION_TEST_FILES}
)
target_include_directories(_common_math_cartesian_frenet_conversion_test SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_cartesian_frenet_conversion_test ${EIGEN3_LIBRRIES})
target_include_directories(_common_math_cartesian_frenet_conversion_test SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_common_math_cartesian_frenet_conversion_test ${PROTOBUF_LIBRARY} standalone_absl)
target_link_libraries(_common_math_cartesian_frenet_conversion_test _common_math_cartesian_frenet_conversion)
target_link_libraries(_common_math_cartesian_frenet_conversion_test _common_math_geometry)
target_link_libraries(_common_math_cartesian_frenet_conversion_test _common_util_string_util)
target_link_libraries(_common_math_cartesian_frenet_conversion_test glog)
target_link_libraries(_common_math_cartesian_frenet_conversion_test libosqp.so)
target_link_libraries(_common_math_cartesian_frenet_conversion_test standalone_absl)
