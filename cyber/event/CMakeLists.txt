### auto generate from bazel lib : _event_perf_event_cache ###
add_library(_event_perf_event_cache SHARED
  "/edith/cyber/event/perf_event_cache.h"
  "/edith/cyber/binary.h"
  "/edith/cyber/common/macros.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/event/perf_event_cache.cc"
  "/edith/cyber/base/bounded_queue.h"
  "/edith/cyber/base/wait_strategy.h"
  "/edith/cyber/base/macros.h"
  "/edith/cyber/event/perf_event.h"
)

target_link_libraries(_event_perf_event_cache _common_global_data)
target_link_libraries(_event_perf_event_cache _state)
target_link_libraries(_event_perf_event_cache _time_time)
target_link_libraries(_event_perf_event_cache glog)

set_target_properties(_event_perf_event_cache PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_event_perf_event_cache PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

