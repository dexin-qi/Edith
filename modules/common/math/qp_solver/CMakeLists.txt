### auto generate from bazel lib : _common_math_qp_solver_qp_solver_gflags ###
add_library(_common_math_qp_solver_qp_solver_gflags SHARED
  "/edith/modules/common/math/qp_solver/qp_solver_gflags.cc"
  "/edith/modules/common/math/qp_solver/qp_solver_gflags.h"
)

target_link_libraries(_common_math_qp_solver_qp_solver_gflags gflags)

set_target_properties(_common_math_qp_solver_qp_solver_gflags PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_math_qp_solver_qp_solver_gflags PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

### auto generate from bazel lib : _common_math_qp_solver_qp_solver ###
add_library(_common_math_qp_solver_qp_solver SHARED
  "/edith/modules/common/math/qp_solver/qp_solver.h"
  "/edith/modules/common/math/qp_solver/qp_solver.cc"
)

target_include_directories(_common_math_qp_solver_qp_solver SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_qp_solver_qp_solver ${EIGEN3_LIBRRIES})

set_target_properties(_common_math_qp_solver_qp_solver PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_math_qp_solver_qp_solver PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

### auto generate from bazel lib : _common_math_qp_solver_active_set_qp_solver ###
add_library(_common_math_qp_solver_active_set_qp_solver SHARED
  "/edith/cyber/common/log.h"
  "/edith/modules/common/math/qp_solver/active_set_qp_solver.h"
  "/edith/cyber/binary.h"
  "/edith/modules/common/math/qp_solver/active_set_qp_solver.cc"
)

target_include_directories(_common_math_qp_solver_active_set_qp_solver SYSTEM PUBLIC "/usr/local/include")
target_link_libraries(_common_math_qp_solver_active_set_qp_solver libqpOASES.so)
target_include_directories(_common_math_qp_solver_active_set_qp_solver SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_qp_solver_active_set_qp_solver ${EIGEN3_LIBRRIES})
target_link_libraries(_common_math_qp_solver_active_set_qp_solver _common_math_qp_solver_qp_solver)
target_link_libraries(_common_math_qp_solver_active_set_qp_solver _common_math_qp_solver_qp_solver_gflags)
target_link_libraries(_common_math_qp_solver_active_set_qp_solver glog)

set_target_properties(_common_math_qp_solver_active_set_qp_solver PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_math_qp_solver_active_set_qp_solver PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)


### auto generate from bazel test : _common_math_qp_solver_active_set_qp_solver_test ###
dustin_var_append(ACTIVE_SET_QP_SOLVER_TEST_FILES /edith/modules/common/math/qp_solver/active_set_qp_solver.h)
dustin_var_append(ACTIVE_SET_QP_SOLVER_TEST_FILES /edith/modules/common/math/qp_solver/qp_solver.h)
dustin_var_append(ACTIVE_SET_QP_SOLVER_TEST_FILES /edith/modules/common/math/qp_solver/qp_solver_gflags.h)
dustin_var_append(ACTIVE_SET_QP_SOLVER_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(ACTIVE_SET_QP_SOLVER_TEST_FILES /edith/modules/common/math/qp_solver/active_set_qp_solver_test.cc)
dustin_var_append(ACTIVE_SET_QP_SOLVER_TEST_FILES /edith/cyber/common/log.h)

edith_test(_common_math_qp_solver_active_set_qp_solver_test
SRCS
  ${ACTIVE_SET_QP_SOLVER_TEST_FILES}
)
target_include_directories(_common_math_qp_solver_active_set_qp_solver_test SYSTEM PUBLIC "/usr/local/include")
target_link_libraries(_common_math_qp_solver_active_set_qp_solver_test libqpOASES.so)
target_include_directories(_common_math_qp_solver_active_set_qp_solver_test SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(_common_math_qp_solver_active_set_qp_solver_test ${EIGEN3_LIBRRIES})
target_link_libraries(_common_math_qp_solver_active_set_qp_solver_test _common_math_qp_solver_active_set_qp_solver)
target_link_libraries(_common_math_qp_solver_active_set_qp_solver_test _common_math_qp_solver_qp_solver)
target_link_libraries(_common_math_qp_solver_active_set_qp_solver_test _common_math_qp_solver_qp_solver_gflags)
target_link_libraries(_common_math_qp_solver_active_set_qp_solver_test gflags)
target_link_libraries(_common_math_qp_solver_active_set_qp_solver_test glog)
