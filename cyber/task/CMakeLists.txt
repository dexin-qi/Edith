###### bazel lib: _task_task_manager ######
add_library(_task_task_manager SHARED
  "task_manager.cc"
  "task_manager.h"
)
target_link_libraries(_task_task_manager _scheduler_scheduler_factory)

set_target_properties(_task_task_manager PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_task_task_manager PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

