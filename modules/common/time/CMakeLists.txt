### auto generate from bazel lib : _common_time_time ###
add_library(_common_time_time SHARED
  "/edith/modules/common/time/time.h"
  "/edith/modules/common/time/timer.cc"
  "/edith/modules/common/time/timer.h"
  "/edith/modules/common/time/time_util.h"
)

target_link_libraries(_common_time_time _common_configs_config_gflags)
target_link_libraries(_common_time_time _time_time)
target_link_libraries(_common_time_time standalone_absl)

set_target_properties(_common_time_time PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_common_time_time PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)


### auto generate from bazel test : _common_time_time_test ###
dustin_var_append(TIME_TEST_FILES /edith/cyber/common/macros.h)
dustin_var_append(TIME_TEST_FILES /edith/cyber/common/file.h)
dustin_var_append(TIME_TEST_FILES /edith/modules/common/time/time_test.cc)
dustin_var_append(TIME_TEST_FILES /edith/cyber/common/log.h)
dustin_var_append(TIME_TEST_FILES /edith/modules/common/configs/config_gflags.h)
dustin_var_append(TIME_TEST_FILES /edith/cyber/time/duration.h)
dustin_var_append(TIME_TEST_FILES /edith/cyber/common/global_data.h)
dustin_var_append(TIME_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(TIME_TEST_FILES /edith/cyber/base/atomic_rw_lock.h)
dustin_var_append(TIME_TEST_FILES /edith/cyber/common/util.h)
dustin_var_append(TIME_TEST_FILES /edith/cyber/common/time_conversion.h)
dustin_var_append(TIME_TEST_FILES /edith/cyber/base/atomic_hash_map.h)
dustin_var_append(TIME_TEST_FILES /edith/modules/common/time/time_util.h)
dustin_var_append(TIME_TEST_FILES /edith/cyber/base/macros.h)
dustin_var_append(TIME_TEST_FILES /edith/modules/common/time/time.h)
dustin_var_append(TIME_TEST_FILES /edith/cyber/base/rw_lock_guard.h)
dustin_var_append(TIME_TEST_FILES /edith/cyber/time/time.h)
dustin_var_append(TIME_TEST_FILES /edith/cyber/common/types.h)
dustin_var_append(TIME_TEST_FILES /edith/modules/common/time/timer.h)
dustin_var_append(TIME_TEST_FILES /edith/cyber/common/environment.h)

edith_test(_common_time_time_test
SRCS
  ${TIME_TEST_FILES}
)
target_link_libraries(_common_time_time_test _common_configs_config_gflags)
target_link_libraries(_common_time_time_test _common_file)
target_link_libraries(_common_time_time_test _common_global_data)
target_link_libraries(_common_time_time_test _common_time_time)
target_link_libraries(_common_time_time_test _cyber_proto_cc_lib)
target_link_libraries(_common_time_time_test _time_duration)
target_link_libraries(_common_time_time_test _time_time)
target_link_libraries(_common_time_time_test gflags)
target_link_libraries(_common_time_time_test glog)
target_link_libraries(_common_time_time_test standalone_absl)

### auto generate from bazel test : _common_time_timer_test ###
dustin_var_append(TIMER_TEST_FILES /edith/cyber/common/macros.h)
dustin_var_append(TIMER_TEST_FILES /edith/cyber/common/file.h)
dustin_var_append(TIMER_TEST_FILES /edith/cyber/common/log.h)
dustin_var_append(TIMER_TEST_FILES /edith/modules/common/configs/config_gflags.h)
dustin_var_append(TIMER_TEST_FILES /edith/modules/common/time/timer_test.cc)
dustin_var_append(TIMER_TEST_FILES /edith/cyber/time/duration.h)
dustin_var_append(TIMER_TEST_FILES /edith/cyber/common/global_data.h)
dustin_var_append(TIMER_TEST_FILES /edith/cyber/base/atomic_rw_lock.h)
dustin_var_append(TIMER_TEST_FILES /edith/cyber/binary.h)
dustin_var_append(TIMER_TEST_FILES /edith/cyber/common/util.h)
dustin_var_append(TIMER_TEST_FILES /edith/cyber/common/time_conversion.h)
dustin_var_append(TIMER_TEST_FILES /edith/cyber/base/atomic_hash_map.h)
dustin_var_append(TIMER_TEST_FILES /edith/modules/common/time/time_util.h)
dustin_var_append(TIMER_TEST_FILES /edith/cyber/base/macros.h)
dustin_var_append(TIMER_TEST_FILES /edith/modules/common/time/time.h)
dustin_var_append(TIMER_TEST_FILES /edith/cyber/base/rw_lock_guard.h)
dustin_var_append(TIMER_TEST_FILES /edith/cyber/time/time.h)
dustin_var_append(TIMER_TEST_FILES /edith/cyber/common/types.h)
dustin_var_append(TIMER_TEST_FILES /edith/modules/common/time/timer.h)
dustin_var_append(TIMER_TEST_FILES /edith/cyber/common/environment.h)

edith_test(_common_time_timer_test
SRCS
  ${TIMER_TEST_FILES}
)
target_link_libraries(_common_time_timer_test _common_configs_config_gflags)
target_link_libraries(_common_time_timer_test _common_file)
target_link_libraries(_common_time_timer_test _common_global_data)
target_link_libraries(_common_time_timer_test _common_time_time)
target_link_libraries(_common_time_timer_test _cyber_proto_cc_lib)
target_link_libraries(_common_time_timer_test _time_duration)
target_link_libraries(_common_time_timer_test _time_time)
target_link_libraries(_common_time_timer_test gflags)
target_link_libraries(_common_time_timer_test glog)
target_link_libraries(_common_time_timer_test standalone_absl)
