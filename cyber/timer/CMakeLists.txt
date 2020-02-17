###### bazel lib: _timer_timing_wheel ######
add_library(_timer_timing_wheel SHARED
  "timing_wheel.cc"
  "timing_wheel.h"
  "/apollo/cyber/timer/timer_bucket.h"
  "/apollo/cyber/task/task.h"
  "/apollo/cyber/timer/timer_task.h"
)
target_link_libraries(_timer_timing_wheel _time_time)
target_link_libraries(_timer_timing_wheel _time_duration)
target_link_libraries(_timer_timing_wheel _time_rate)
target_link_libraries(_timer_timing_wheel _task_task_manager)

set_target_properties(_timer_timing_wheel PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_timer_timing_wheel PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _timer_timer ######
add_library(_timer_timer SHARED
  "timer.cc"
  "timer.h"
)
target_link_libraries(_timer_timer _timer_timing_wheel)
target_link_libraries(_timer_timer _common_global_data)

set_target_properties(_timer_timer PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_timer_timer PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

