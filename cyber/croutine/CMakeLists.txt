###### bazel lib: _croutine_routine_context ######
add_library(_croutine_routine_context SHARED
  "detail/routine_context.cc"
  "detail/routine_context.h"
  "/apollo/cyber/common/environment.h"
  "/apollo/cyber/common/log.h"
  "/apollo/cyber/common/macros.h"
  "/apollo/cyber/common/time_conversion.h"
  "/apollo/cyber/common/types.h"
  "/apollo/cyber/common/util.h"
  "/apollo/cyber/binary.h"
  "/apollo/cyber/base/macros.h"
)
target_link_libraries(_croutine_routine_context _common_file)
target_link_libraries(_croutine_routine_context _common_global_data)
target_link_libraries(_croutine_routine_context glog)

set_target_properties(_croutine_routine_context PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_croutine_routine_context PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _croutine_croutine ######
add_library(_croutine_croutine SHARED
  "croutine.cc"
  "croutine.h"
  "/apollo/cyber/base/atomic_hash_map.h"
  "/apollo/cyber/base/atomic_rw_lock.h"
  "/apollo/cyber/base/bounded_queue.h"
  "/apollo/cyber/base/concurrent_object_pool.h"
  "/apollo/cyber/base/macros.h"
  "/apollo/cyber/base/wait_strategy.h"
  "/apollo/cyber/croutine/routine_factory.h"
  "/apollo/cyber/base/rw_lock_guard.h"
  "/apollo/cyber/base/for_each.h"
  "/apollo/cyber/common/environment.h"
  "/apollo/cyber/common/log.h"
  "/apollo/cyber/common/macros.h"
  "/apollo/cyber/common/time_conversion.h"
  "/apollo/cyber/common/types.h"
  "/apollo/cyber/common/util.h"
  "/apollo/cyber/binary.h"
)
target_link_libraries(_croutine_croutine _croutine_routine_context)
target_link_libraries(_croutine_croutine _croutine_swap)
target_link_libraries(_croutine_croutine _event_perf_event_cache)
target_link_libraries(_croutine_croutine _time_time)
target_link_libraries(_croutine_croutine -latomic)
target_link_libraries(_croutine_croutine _common_file)
target_link_libraries(_croutine_croutine _common_global_data)
target_link_libraries(_croutine_croutine glog)

set_target_properties(_croutine_croutine PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_croutine_croutine PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _croutine_swap ######
add_library(_croutine_swap
  "detail/swap_x86_64.S"
)

set_target_properties(_croutine_swap PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_croutine_swap PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

