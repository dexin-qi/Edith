### auto generate from bazel lib : _common_kv_db_kv_db ###
add_library(_common_kv_db_kv_db SHARED
  "/edith/cyber/binary.h"
  "/edith/modules/common/kv_db/kv_db.h"
  "/edith/modules/common/kv_db/kv_db.cc"
  "/edith/cyber/common/log.h"
  "/edith/modules/common/util/future.h"
)

target_link_libraries(_common_kv_db_kv_db -lsqlite3)
target_link_libraries(_common_kv_db_kv_db _common_util_util)
target_link_libraries(_common_kv_db_kv_db gflags)
target_link_libraries(_common_kv_db_kv_db glog)
target_link_libraries(_common_kv_db_kv_db standalone_absl)

set_target_properties(_common_kv_db_kv_db PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_kv_db_kv_db PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)


### auto generate from bazel test : _common_kv_db_kv_db_test ###
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/util/util.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/math/integral.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/math/angle.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/math/polygon2d.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/math/factorial.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/math/sin_table.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/math/curve_fitting.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/math/linear_interpolation.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/math/matrix_operations.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/math/aabox2d.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/math/cartesian_frenet_conversion.h)
dustin_var_append(KV_DB_TEST_FILES /edith/cyber/common/types.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/util/string_util.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/math/qp_solver/active_set_qp_solver.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/math/mpc_solver.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/math/line_segment2d.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/kv_db/kv_db_test.cc)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/math/linear_quadratic_regulator.h)
dustin_var_append(KV_DB_TEST_FILES /edith/cyber/common/log.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/util/future.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/math/euler_angles_zxy.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/math/box2d.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/math/qp_solver/qp_solver.h)
dustin_var_append(KV_DB_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/math/vec2d.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/math/kalman_filter.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/math/quaternion.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/math/qp_solver/qp_solver_gflags.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/kv_db/kv_db.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/math/search.h)
dustin_var_append(KV_DB_TEST_FILES /edith/modules/common/math/aaboxkdtree2d.h)

edith_test(_common_kv_db_kv_db_test
SRCS
  ${KV_DB_TEST_FILES}
)
target_include_directories(_common_kv_db_kv_db_test SYSTEM PUBLIC "/usr/local/include")
target_link_libraries(_common_kv_db_kv_db_test libqpOASES.so)
target_include_directories(_common_kv_db_kv_db_test SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_kv_db_kv_db_test ${EIGEN3_LIBRRIES})
target_include_directories(_common_kv_db_kv_db_test SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_common_kv_db_kv_db_test ${PROTOBUF_LIBRARY} standalone_absl)
target_link_libraries(_common_kv_db_kv_db_test -lsqlite3)
target_link_libraries(_common_kv_db_kv_db_test _common_kv_db_kv_db)
target_link_libraries(_common_kv_db_kv_db_test _common_math_angle)
target_link_libraries(_common_kv_db_kv_db_test _common_math_cartesian_frenet_conversion)
target_link_libraries(_common_kv_db_kv_db_test _common_math_geometry)
target_link_libraries(_common_kv_db_kv_db_test _common_math_integral)
target_link_libraries(_common_kv_db_kv_db_test _common_math_linear_interpolation)
target_link_libraries(_common_kv_db_kv_db_test _common_math_lqr)
target_link_libraries(_common_kv_db_kv_db_test _common_math_matrix_operations)
target_link_libraries(_common_kv_db_kv_db_test _common_math_mpc)
target_link_libraries(_common_kv_db_kv_db_test _common_math_qp_solver_active_set_qp_solver)
target_link_libraries(_common_kv_db_kv_db_test _common_math_qp_solver_qp_solver)
target_link_libraries(_common_kv_db_kv_db_test _common_math_qp_solver_qp_solver_gflags)
target_link_libraries(_common_kv_db_kv_db_test _common_math_search)
target_link_libraries(_common_kv_db_kv_db_test _common_math_sin_table)
target_link_libraries(_common_kv_db_kv_db_test _common_util_string_util)
target_link_libraries(_common_kv_db_kv_db_test _common_util_util)
target_link_libraries(_common_kv_db_kv_db_test _modules_proto_cc_lib)
target_link_libraries(_common_kv_db_kv_db_test gflags)
target_link_libraries(_common_kv_db_kv_db_test glog)
target_link_libraries(_common_kv_db_kv_db_test libosqp.so)
target_link_libraries(_common_kv_db_kv_db_test standalone_absl)
