###### bazel lib: _event_perf_event_cache ######
add_library(_event_perf_event_cache SHARED
  "perf_event_cache.cc"
  "perf_event_cache.h"
  "/apollo/cyber/event/perf_event.h"
  "/apollo/cyber/base/bounded_queue.h"
  "/apollo/cyber/common/log.h"
  "/apollo/cyber/common/macros.h"
  "/apollo/cyber/base/macros.h"
  "/apollo/cyber/base/wait_strategy.h"
  "/apollo/cyber/binary.h"
)
target_link_libraries(_event_perf_event_cache _state)
target_link_libraries(_event_perf_event_cache _common_global_data)
target_link_libraries(_event_perf_event_cache _time_time)
target_link_libraries(_event_perf_event_cache glog)

set_target_properties(_event_perf_event_cache PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_event_perf_event_cache PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

