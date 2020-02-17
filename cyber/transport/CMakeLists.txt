###### bazel lib: _transport_shm_conf ######
add_library(_transport_shm_conf SHARED
  "shm/shm_conf.cc"
  "shm/shm_conf.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/binary.h"
)
target_link_libraries(_transport_shm_conf glog)

set_target_properties(_transport_shm_conf PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_shm_conf PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_posix_segment ######
add_library(_transport_posix_segment SHARED
  "shm/posix_segment.cc"
  "shm/posix_segment.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/common/util.h"
  "/edith/cyber/binary.h"
)
target_link_libraries(_transport_posix_segment _transport_segment)
target_link_libraries(_transport_posix_segment -lrt)
target_link_libraries(_transport_posix_segment glog)

set_target_properties(_transport_posix_segment PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_posix_segment PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_shm_dispatcher ######
add_library(_transport_shm_dispatcher SHARED
  "dispatcher/shm_dispatcher.cc"
  "dispatcher/shm_dispatcher.h"
  "/edith/cyber/message/message_traits.h"
  "/edith/cyber/message/message_header.h"
  "/edith/cyber/message/protobuf_traits.h"
  "/edith/cyber/message/py_message_traits.h"
  "/edith/cyber/message/raw_message_traits.h"
  "/edith/cyber/base/macros.h"
  "/edith/cyber/message/py_message.h"
  "/edith/cyber/message/raw_message.h"
)
target_link_libraries(_transport_shm_dispatcher _transport_dispatcher)
target_link_libraries(_transport_shm_dispatcher _transport_notifier_factory)
target_link_libraries(_transport_shm_dispatcher _transport_readable_info)
target_link_libraries(_transport_shm_dispatcher _transport_segment_factory)
target_link_libraries(_transport_shm_dispatcher _cyber_proto_cc_lib)
target_link_libraries(_transport_shm_dispatcher _scheduler_scheduler_factory)
target_link_libraries(_transport_shm_dispatcher _message_protobuf_factory)

set_target_properties(_transport_shm_dispatcher PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_shm_dispatcher PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_sub_listener ######
add_library(_transport_sub_listener SHARED
  "rtps/sub_listener.cc"
  "rtps/sub_listener.h"
)
target_link_libraries(_transport_sub_listener _transport_message_info)
target_link_libraries(_transport_sub_listener _transport_underlay_message)
target_link_libraries(_transport_sub_listener _transport_underlay_message_type)

set_target_properties(_transport_sub_listener PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_sub_listener PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_block ######
add_library(_transport_block SHARED
  "shm/block.cc"
  "shm/block.h"
  "/edith/cyber/base/atomic_rw_lock.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/base/rw_lock_guard.h"
  "/edith/cyber/binary.h"
)
target_link_libraries(_transport_block glog)

set_target_properties(_transport_block PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_block PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_attributes_filler ######
add_library(_transport_attributes_filler SHARED
  "rtps/attributes_filler.cc"
  "rtps/attributes_filler.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/binary.h"
)
target_link_libraries(_transport_attributes_filler _transport_qos_profile_conf)
target_link_libraries(_transport_attributes_filler fastrtps fastcdr)
target_link_libraries(_transport_attributes_filler glog)

set_target_properties(_transport_attributes_filler PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_attributes_filler PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_rtps_dispatcher ######
add_library(_transport_rtps_dispatcher SHARED
  "dispatcher/rtps_dispatcher.cc"
  "dispatcher/rtps_dispatcher.h"
  "/edith/cyber/message/message_traits.h"
  "/edith/cyber/message/message_header.h"
  "/edith/cyber/message/protobuf_traits.h"
  "/edith/cyber/message/py_message_traits.h"
  "/edith/cyber/message/raw_message_traits.h"
  "/edith/cyber/base/macros.h"
  "/edith/cyber/message/py_message.h"
  "/edith/cyber/message/raw_message.h"
)
target_link_libraries(_transport_rtps_dispatcher _transport_attributes_filler)
target_link_libraries(_transport_rtps_dispatcher _transport_dispatcher)
target_link_libraries(_transport_rtps_dispatcher _transport_participant)
target_link_libraries(_transport_rtps_dispatcher _transport_sub_listener)
target_link_libraries(_transport_rtps_dispatcher _cyber_proto_cc_lib)
target_link_libraries(_transport_rtps_dispatcher _message_protobuf_factory)

set_target_properties(_transport_rtps_dispatcher PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_rtps_dispatcher PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_condition_notifier ######
add_library(_transport_condition_notifier SHARED
  "shm/condition_notifier.cc"
  "shm/condition_notifier.h"
  "/edith/cyber/transport/shm/notifier_base.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/common/util.h"
  "/edith/cyber/binary.h"
)
target_link_libraries(_transport_condition_notifier _common_global_data)
target_link_libraries(_transport_condition_notifier _transport_readable_info)
target_link_libraries(_transport_condition_notifier glog)

set_target_properties(_transport_condition_notifier PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_condition_notifier PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_identity ######
add_library(_transport_identity SHARED
  "common/identity.cc"
  "common/identity.h"
  "/edith/cyber/common/util.h"
)
target_link_libraries(_transport_identity -luuid)

set_target_properties(_transport_identity PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_identity PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_readable_info ######
add_library(_transport_readable_info SHARED
  "shm/readable_info.cc"
  "shm/readable_info.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/binary.h"
)
target_link_libraries(_transport_readable_info glog)

set_target_properties(_transport_readable_info PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_readable_info PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_dispatcher ######
add_library(_transport_dispatcher SHARED
  "dispatcher/dispatcher.cc"
  "dispatcher/dispatcher.h"
  "/edith/cyber/transport/message/listener_handler.h"
  "/edith/cyber/message/message_traits.h"
  "/edith/cyber/message/message_header.h"
  "/edith/cyber/message/protobuf_traits.h"
  "/edith/cyber/message/py_message_traits.h"
  "/edith/cyber/message/raw_message_traits.h"
  "/edith/cyber/base/macros.h"
  "/edith/cyber/message/py_message.h"
  "/edith/cyber/message/raw_message.h"
)
target_link_libraries(_transport_dispatcher _transport_message_info)
target_link_libraries(_transport_dispatcher _cyber_proto_cc_lib)
target_link_libraries(_transport_dispatcher _message_protobuf_factory)

set_target_properties(_transport_dispatcher PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_dispatcher PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_underlay_message_type ######
add_library(_transport_underlay_message_type SHARED
  "rtps/underlay_message_type.cc"
  "rtps/underlay_message_type.h"
)
target_link_libraries(_transport_underlay_message_type _transport_underlay_message)
target_link_libraries(_transport_underlay_message_type fastrtps fastcdr)

set_target_properties(_transport_underlay_message_type PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_underlay_message_type PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_underlay_message ######
add_library(_transport_underlay_message SHARED
  "rtps/underlay_message.cc"
  "rtps/underlay_message.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/binary.h"
)
target_link_libraries(_transport_underlay_message fastrtps fastcdr)
target_link_libraries(_transport_underlay_message glog)

set_target_properties(_transport_underlay_message PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_underlay_message PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_participant ######
add_library(_transport_participant SHARED
  "rtps/participant.cc"
  "rtps/participant.h"
)
target_link_libraries(_transport_participant _transport_underlay_message)
target_link_libraries(_transport_participant _transport_underlay_message_type)
target_link_libraries(_transport_participant _common_global_data)

set_target_properties(_transport_participant PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_participant PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_intra_dispatcher ######
add_library(_transport_intra_dispatcher SHARED
  "dispatcher/intra_dispatcher.cc"
  "dispatcher/intra_dispatcher.h"
  "/edith/cyber/message/message_traits.h"
  "/edith/cyber/message/message_header.h"
  "/edith/cyber/message/protobuf_traits.h"
  "/edith/cyber/message/py_message_traits.h"
  "/edith/cyber/message/raw_message_traits.h"
  "/edith/cyber/base/macros.h"
  "/edith/cyber/message/py_message.h"
  "/edith/cyber/message/raw_message.h"
)
target_link_libraries(_transport_intra_dispatcher _transport_dispatcher)
target_link_libraries(_transport_intra_dispatcher _cyber_proto_cc_lib)
target_link_libraries(_transport_intra_dispatcher _message_protobuf_factory)

set_target_properties(_transport_intra_dispatcher PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_intra_dispatcher PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_segment ######
add_library(_transport_segment SHARED
  "shm/segment.cc"
  "shm/segment.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/common/util.h"
  "/edith/cyber/binary.h"
)
target_link_libraries(_transport_segment _transport_block)
target_link_libraries(_transport_segment _transport_shm_conf)
target_link_libraries(_transport_segment _transport_state)
target_link_libraries(_transport_segment glog)

set_target_properties(_transport_segment PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_segment PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_message_info ######
add_library(_transport_message_info SHARED
  "message/message_info.cc"
  "message/message_info.h"
  "/edith/cyber/base/signal.h"
  "/edith/cyber/message/raw_message.h"
  "/edith/cyber/common/environment.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/common/macros.h"
  "/edith/cyber/common/time_conversion.h"
  "/edith/cyber/common/types.h"
  "/edith/cyber/common/util.h"
  "/edith/cyber/binary.h"
  "/edith/cyber/base/macros.h"
)
target_link_libraries(_transport_message_info _transport_identity)
target_link_libraries(_transport_message_info _common_file)
target_link_libraries(_transport_message_info _common_global_data)
target_link_libraries(_transport_message_info _message_protobuf_factory)
target_link_libraries(_transport_message_info glog)

set_target_properties(_transport_message_info PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_message_info PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_endpoint ######
add_library(_transport_endpoint SHARED
  "common/endpoint.cc"
  "common/endpoint.h"
)
target_link_libraries(_transport_endpoint _transport_identity)
target_link_libraries(_transport_endpoint _common_global_data)
target_link_libraries(_transport_endpoint _cyber_proto_cc_lib)

set_target_properties(_transport_endpoint PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_endpoint PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_notifier_factory ######
add_library(_transport_notifier_factory SHARED
  "shm/notifier_factory.cc"
  "shm/notifier_factory.h"
  "/edith/cyber/transport/shm/notifier_base.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/binary.h"
)
target_link_libraries(_transport_notifier_factory _transport_condition_notifier)
target_link_libraries(_transport_notifier_factory _transport_multicast_notifier)
target_link_libraries(_transport_notifier_factory _common_global_data)
target_link_libraries(_transport_notifier_factory _transport_readable_info)
target_link_libraries(_transport_notifier_factory glog)

set_target_properties(_transport_notifier_factory PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_notifier_factory PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_xsi_segment ######
add_library(_transport_xsi_segment SHARED
  "shm/xsi_segment.cc"
  "shm/xsi_segment.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/common/util.h"
  "/edith/cyber/binary.h"
)
target_link_libraries(_transport_xsi_segment _transport_segment)
target_link_libraries(_transport_xsi_segment glog)

set_target_properties(_transport_xsi_segment PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_xsi_segment PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_multicast_notifier ######
add_library(_transport_multicast_notifier SHARED
  "shm/multicast_notifier.cc"
  "shm/multicast_notifier.h"
  "/edith/cyber/transport/shm/notifier_base.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/common/macros.h"
  "/edith/cyber/binary.h"
  "/edith/cyber/base/macros.h"
)
target_link_libraries(_transport_multicast_notifier _common_global_data)
target_link_libraries(_transport_multicast_notifier _transport_readable_info)
target_link_libraries(_transport_multicast_notifier glog)

set_target_properties(_transport_multicast_notifier PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_multicast_notifier PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_segment_factory ######
add_library(_transport_segment_factory SHARED
  "shm/segment_factory.cc"
  "shm/segment_factory.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/binary.h"
)
target_link_libraries(_transport_segment_factory _transport_posix_segment)
target_link_libraries(_transport_segment_factory _transport_segment)
target_link_libraries(_transport_segment_factory _transport_xsi_segment)
target_link_libraries(_transport_segment_factory _common_global_data)
target_link_libraries(_transport_segment_factory glog)

set_target_properties(_transport_segment_factory PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_segment_factory PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_transport ######
add_library(_transport_transport SHARED
  "transport.cc"
  "transport.h"
  "/edith/cyber/transport/message/history.h"
  "/edith/cyber/transport/receiver/hybrid_receiver.h"
  "/edith/cyber/transport/transmitter/hybrid_transmitter.h"
  "/edith/cyber/transport/receiver/intra_receiver.h"
  "/edith/cyber/transport/transmitter/intra_transmitter.h"
  "/edith/cyber/transport/receiver/rtps_receiver.h"
  "/edith/cyber/transport/transmitter/rtps_transmitter.h"
  "/edith/cyber/transport/receiver/shm_receiver.h"
  "/edith/cyber/transport/transmitter/shm_transmitter.h"
  "/edith/cyber/task/task.h"
  "/edith/cyber/transport/message/history_attributes.h"
  "/edith/cyber/transport/receiver/receiver.h"
  "/edith/cyber/transport/transmitter/transmitter.h"
)
target_link_libraries(_transport_transport _transport_attributes_filler)
target_link_libraries(_transport_transport _transport_intra_dispatcher)
target_link_libraries(_transport_transport _transport_participant)
target_link_libraries(_transport_transport _transport_qos_profile_conf)
target_link_libraries(_transport_transport _transport_rtps_dispatcher)
target_link_libraries(_transport_transport _transport_shm_dispatcher)
target_link_libraries(_transport_transport _transport_sub_listener)
target_link_libraries(_transport_transport _transport_underlay_message)
target_link_libraries(_transport_transport _transport_underlay_message_type)
target_link_libraries(_transport_transport _service_discovery_role)
target_link_libraries(_transport_transport fastrtps fastcdr)
target_link_libraries(_transport_transport _transport_readable_info)
target_link_libraries(_transport_transport _task_task_manager)
target_link_libraries(_transport_transport _transport_endpoint)
target_link_libraries(_transport_transport _transport_message_info)
target_link_libraries(_transport_transport _event_perf_event_cache)

set_target_properties(_transport_transport PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_transport PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_state ######
add_library(_transport_state SHARED
  "shm/state.cc"
  "shm/state.h"
)

set_target_properties(_transport_state PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_state PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _transport_qos_profile_conf ######
add_library(_transport_qos_profile_conf SHARED
  "qos/qos_profile_conf.cc"
  "qos/qos_profile_conf.h"
  "/edith/cyber/transport/message/history.h"
  "/edith/cyber/transport/message/history_attributes.h"
)
target_link_libraries(_transport_qos_profile_conf _cyber_proto_cc_lib)

set_target_properties(_transport_qos_profile_conf PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_transport_qos_profile_conf PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

