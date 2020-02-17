###### bazel lib: _io_poller ######
add_library(_io_poller SHARED
  "poller.cc"
  "poller.h"
  "/edith/cyber/io/poll_data.h"
  "/edith/cyber/base/atomic_rw_lock.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/common/macros.h"
  "/edith/cyber/base/rw_lock_guard.h"
  "/edith/cyber/binary.h"
  "/edith/cyber/base/macros.h"
)
target_link_libraries(_io_poller _scheduler_scheduler_factory)
target_link_libraries(_io_poller _time_time)
target_link_libraries(_io_poller glog)

set_target_properties(_io_poller PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_io_poller PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _io_poll_handler ######
add_library(_io_poll_handler SHARED
  "poll_handler.cc"
  "poll_handler.h"
  "/edith/cyber/io/poll_data.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/binary.h"
)
target_link_libraries(_io_poll_handler _io_poller)
target_link_libraries(_io_poll_handler _croutine_croutine)
target_link_libraries(_io_poll_handler glog)

set_target_properties(_io_poll_handler PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_io_poll_handler PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _io_session ######
add_library(_io_session SHARED
  "session.cc"
  "session.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/binary.h"
)
target_link_libraries(_io_session _io_poll_handler)
target_link_libraries(_io_session glog)

set_target_properties(_io_session PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_io_session PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

