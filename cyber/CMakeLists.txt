add_subdirectory(io)
add_subdirectory(event)
add_subdirectory(service_discovery)
add_subdirectory(transport)
add_subdirectory(croutine)
add_subdirectory(timer)
add_subdirectory(time)
add_subdirectory(common)
add_subdirectory(task)
add_subdirectory(record)
add_subdirectory(component)
add_subdirectory(message)
add_subdirectory(scheduler)
add_subdirectory(blocker)
add_subdirectory(node)
add_subdirectory(class_loader/test)
add_subdirectory(sysmo)
add_subdirectory(class_loader)
add_subdirectory(logger)
add_subdirectory(py_wrapper)
add_subdirectory(parameter)
add_subdirectory(examples)
add_subdirectory(tools/cyber_monitor)
add_subdirectory(tools/cyber_recorder)
add_subdirectory(proto)

file(GLOB_RECURSE MB_CC "mainboard/*.cc")
file(GLOB_RECURSE MB_H "mainboard/*.h")
set(MB_FILE)
list(APPEND MB_FILE ${MB_CC})
list(APPEND MB_FILE ${MB_H})

edith_binary(mainboard
  SRCS 
    ${MB_FILE}
  LIBS 
    "_cyber_core;_cyber_proto_cc_lib;glog;gflags"
)

###### bazel lib: _cyber_core ######
add_library(_cyber_core SHARED
  "cyber.cc"
  "cyber.h"
  "/edith/cyber/binary.h"
  "/edith/cyber/component/component.h"
  "/edith/cyber/message/message_traits.h"
  "/edith/cyber/message/protobuf_traits.h"
  "/edith/cyber/message/py_message_traits.h"
  "/edith/cyber/message/raw_message_traits.h"
  "/edith/cyber/service/service.h"
  "/edith/cyber/service/client.h"
  "/edith/cyber/task/task.h"
  "/edith/cyber/base/atomic_hash_map.h"
  "/edith/cyber/base/atomic_rw_lock.h"
  "/edith/cyber/base/bounded_queue.h"
  "/edith/cyber/base/concurrent_object_pool.h"
  "/edith/cyber/base/for_each.h"
  "/edith/cyber/base/macros.h"
  "/edith/cyber/base/object_pool.h"
  "/edith/cyber/base/reentrant_rw_lock.h"
  "/edith/cyber/base/rw_lock_guard.h"
  "/edith/cyber/base/signal.h"
  "/edith/cyber/base/thread_pool.h"
  "/edith/cyber/base/thread_safe_queue.h"
  "/edith/cyber/base/unbounded_queue.h"
  "/edith/cyber/base/wait_strategy.h"
  "/edith/cyber/common/environment.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/common/macros.h"
  "/edith/cyber/common/time_conversion.h"
  "/edith/cyber/common/types.h"
  "/edith/cyber/common/util.h"
  "/edith/cyber/component/component_base.h"
  "/edith/cyber/data/fusion/all_latest.h"
  "/edith/cyber/data/cache_buffer.h"
  "/edith/cyber/data/channel_buffer.h"
  "/edith/cyber/data/data_dispatcher.h"
  "/edith/cyber/data/fusion/data_fusion.h"
  "/edith/cyber/data/data_notifier.h"
  "/edith/cyber/data/data_visitor.h"
  "/edith/cyber/data/data_visitor_base.h"
  "/edith/cyber/io/poll_data.h"
  "/edith/cyber/message/message_header.h"
  "/edith/cyber/message/py_message.h"
  "/edith/cyber/message/raw_message.h"
  "/edith/cyber/service/service_base.h"
  "/edith/cyber/service/client_base.h"
)
target_link_libraries(_cyber_core _init)
target_link_libraries(_cyber_core _state)
target_link_libraries(_cyber_core _blocker_blocker_manager)
target_link_libraries(_cyber_core _class_loader_class_loader)
target_link_libraries(_cyber_core _class_loader_class_loader_manager)
target_link_libraries(_cyber_core _component_timer_component)
target_link_libraries(_cyber_core _croutine_croutine)
target_link_libraries(_cyber_core _event_perf_event_cache)
target_link_libraries(_cyber_core _logger_logger)
target_link_libraries(_cyber_core _logger_async_logger)
target_link_libraries(_cyber_core _node_node)
target_link_libraries(_cyber_core _parameter_parameter_client)
target_link_libraries(_cyber_core _parameter_parameter_server)
target_link_libraries(_cyber_core _cyber_proto_cc_lib)
target_link_libraries(_cyber_core _scheduler_scheduler)
target_link_libraries(_cyber_core _scheduler_scheduler_factory)
target_link_libraries(_cyber_core _service_discovery_topology_manager)
target_link_libraries(_cyber_core _sysmo_sysmo)
target_link_libraries(_cyber_core _time_time)
target_link_libraries(_cyber_core _time_duration)
target_link_libraries(_cyber_core _time_rate)
target_link_libraries(_cyber_core _timer_timer)
target_link_libraries(_cyber_core _transport_transport)
target_link_libraries(_cyber_core _transport_participant)
target_link_libraries(_cyber_core _transport_sub_listener)
target_link_libraries(_cyber_core fastrtps fastcdr)
target_link_libraries(_cyber_core -lprotobuf)
target_link_libraries(_cyber_core -luuid)
target_link_libraries(_cyber_core -lrt)
target_link_libraries(_cyber_core _common_file)
target_link_libraries(_cyber_core _common_global_data)
target_link_libraries(_cyber_core _io_poll_handler)
target_link_libraries(_cyber_core _io_poller)
target_link_libraries(_cyber_core _io_session)
target_link_libraries(_cyber_core _message_protobuf_factory)
target_link_libraries(_cyber_core _record_record_reader)
target_link_libraries(_cyber_core _record_record_viewer)
target_link_libraries(_cyber_core _record_record_writer)
target_link_libraries(_cyber_core _task_task_manager)
target_link_libraries(_cyber_core glog)

set_target_properties(_cyber_core PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_cyber_core PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _state ######
add_library(_state SHARED
  "state.cc"
  "state.h"
  "/edith/cyber/common/environment.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/common/macros.h"
  "/edith/cyber/common/time_conversion.h"
  "/edith/cyber/common/types.h"
  "/edith/cyber/common/util.h"
  "/edith/cyber/binary.h"
  "/edith/cyber/base/macros.h"
)
target_link_libraries(_state _common_file)
target_link_libraries(_state _common_global_data)
target_link_libraries(_state glog)

set_target_properties(_state PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_state PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _init ######
add_library(_init SHARED
  "init.cc"
  "init.h"
)
target_link_libraries(_init _state)
target_link_libraries(_init _logger_async_logger)
target_link_libraries(_init _node_node)
target_link_libraries(_init _sysmo_sysmo)
target_link_libraries(_init _timer_timing_wheel)

set_target_properties(_init PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_init PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

