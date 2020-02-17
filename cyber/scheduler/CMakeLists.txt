###### bazel lib: _scheduler_scheduler_classic ######
add_library(_scheduler_scheduler_classic SHARED
  "policy/scheduler_classic.cc"
  "policy/scheduler_classic.h"
)
target_link_libraries(_scheduler_scheduler_classic _scheduler_scheduler)
target_link_libraries(_scheduler_scheduler_classic _scheduler_classic_context)

set_target_properties(_scheduler_scheduler_classic PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_scheduler_scheduler_classic PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _scheduler_scheduler_choreography ######
add_library(_scheduler_scheduler_choreography SHARED
  "policy/scheduler_choreography.cc"
  "policy/scheduler_choreography.h"
)
target_link_libraries(_scheduler_scheduler_choreography _scheduler_scheduler)
target_link_libraries(_scheduler_scheduler_choreography _scheduler_choreography_context)
target_link_libraries(_scheduler_scheduler_choreography _scheduler_classic_context)

set_target_properties(_scheduler_scheduler_choreography PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_scheduler_scheduler_choreography PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _scheduler_choreography_context ######
add_library(_scheduler_choreography_context SHARED
  "policy/choreography_context.cc"
  "policy/choreography_context.h"
)
target_link_libraries(_scheduler_choreography_context _croutine_croutine)
target_link_libraries(_scheduler_choreography_context _cyber_proto_cc_lib)
target_link_libraries(_scheduler_choreography_context _scheduler_processor)

set_target_properties(_scheduler_choreography_context PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_scheduler_choreography_context PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _scheduler_processor ######
add_library(_scheduler_processor SHARED
  "processor.cc"
  "processor.h"
  "/edith/cyber/data/fusion/all_latest.h"
  "/edith/cyber/data/cache_buffer.h"
  "/edith/cyber/data/channel_buffer.h"
  "/edith/cyber/data/data_dispatcher.h"
  "/edith/cyber/data/fusion/data_fusion.h"
  "/edith/cyber/data/data_notifier.h"
  "/edith/cyber/data/data_visitor.h"
  "/edith/cyber/data/data_visitor_base.h"
)
target_link_libraries(_scheduler_processor _scheduler_processor_context)
target_link_libraries(_scheduler_processor _cyber_proto_cc_lib)

set_target_properties(_scheduler_processor PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_scheduler_processor PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _scheduler_processor_context ######
add_library(_scheduler_processor_context SHARED
  "processor_context.cc"
  "processor_context.h"
  "/edith/cyber/data/fusion/all_latest.h"
  "/edith/cyber/data/cache_buffer.h"
  "/edith/cyber/data/channel_buffer.h"
  "/edith/cyber/data/data_dispatcher.h"
  "/edith/cyber/data/fusion/data_fusion.h"
  "/edith/cyber/data/data_notifier.h"
  "/edith/cyber/data/data_visitor.h"
  "/edith/cyber/data/data_visitor_base.h"
)
target_link_libraries(_scheduler_processor_context _croutine_croutine)
target_link_libraries(_scheduler_processor_context _cyber_proto_cc_lib)

set_target_properties(_scheduler_processor_context PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_scheduler_processor_context PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _scheduler_scheduler ######
add_library(_scheduler_scheduler SHARED
  "scheduler.cc"
  "scheduler.h"
  "/edith/cyber/scheduler/common/mutex_wrapper.h"
)
target_link_libraries(_scheduler_scheduler _croutine_croutine)
target_link_libraries(_scheduler_scheduler _scheduler_pin_thread)
target_link_libraries(_scheduler_scheduler _scheduler_processor)

set_target_properties(_scheduler_scheduler PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_scheduler_scheduler PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _scheduler_classic_context ######
add_library(_scheduler_classic_context SHARED
  "policy/classic_context.cc"
  "policy/classic_context.h"
  "/edith/cyber/scheduler/common/cv_wrapper.h"
  "/edith/cyber/scheduler/common/mutex_wrapper.h"
)
target_link_libraries(_scheduler_classic_context _croutine_croutine)
target_link_libraries(_scheduler_classic_context _cyber_proto_cc_lib)
target_link_libraries(_scheduler_classic_context _scheduler_processor)

set_target_properties(_scheduler_classic_context PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_scheduler_classic_context PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _scheduler_pin_thread ######
add_library(_scheduler_pin_thread SHARED
  "common/pin_thread.cc"
  "common/pin_thread.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/binary.h"
)
target_link_libraries(_scheduler_pin_thread glog)

set_target_properties(_scheduler_pin_thread PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_scheduler_pin_thread PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _scheduler_scheduler_factory ######
add_library(_scheduler_scheduler_factory SHARED
  "scheduler_factory.cc"
  "scheduler_factory.h"
)
target_link_libraries(_scheduler_scheduler_factory _cyber_proto_cc_lib)
target_link_libraries(_scheduler_scheduler_factory _scheduler_scheduler_choreography)
target_link_libraries(_scheduler_scheduler_factory _scheduler_scheduler_classic)

set_target_properties(_scheduler_scheduler_factory PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_scheduler_scheduler_factory PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

