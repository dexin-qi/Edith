###### bazel lib: _service_discovery_multi_value_warehouse ######
add_library(_service_discovery_multi_value_warehouse SHARED
  "container/multi_value_warehouse.cc"
  "container/multi_value_warehouse.h"
  "/apollo/cyber/service_discovery/container/warehouse_base.h"
  "/apollo/cyber/base/atomic_rw_lock.h"
  "/apollo/cyber/base/rw_lock_guard.h"
)
target_link_libraries(_service_discovery_multi_value_warehouse _service_discovery_role)

set_target_properties(_service_discovery_multi_value_warehouse PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_service_discovery_multi_value_warehouse PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _service_discovery_role ######
add_library(_service_discovery_role SHARED
  "role/role.cc"
  "role/role.h"
  "/apollo/cyber/binary.h"
  "/apollo/cyber/common/log.h"
  "/apollo/cyber/common/types.h"
)
target_link_libraries(_service_discovery_role _cyber_proto_cc_lib)
target_link_libraries(_service_discovery_role glog)

set_target_properties(_service_discovery_role PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_service_discovery_role PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _service_discovery_subscriber_listener ######
add_library(_service_discovery_subscriber_listener SHARED
  "communication/subscriber_listener.cc"
  "communication/subscriber_listener.h"
  "/apollo/cyber/common/log.h"
  "/apollo/cyber/binary.h"
)
target_link_libraries(_service_discovery_subscriber_listener _transport_underlay_message)
target_link_libraries(_service_discovery_subscriber_listener _transport_underlay_message_type)
target_link_libraries(_service_discovery_subscriber_listener fastrtps fastcdr)
target_link_libraries(_service_discovery_subscriber_listener glog)

set_target_properties(_service_discovery_subscriber_listener PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_service_discovery_subscriber_listener PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _service_discovery_service_manager ######
add_library(_service_discovery_service_manager SHARED
  "specific_manager/service_manager.cc"
  "specific_manager/service_manager.h"
)
target_link_libraries(_service_discovery_service_manager _service_discovery_manager)
target_link_libraries(_service_discovery_service_manager _service_discovery_multi_value_warehouse)
target_link_libraries(_service_discovery_service_manager _service_discovery_single_value_warehouse)

set_target_properties(_service_discovery_service_manager PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_service_discovery_service_manager PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _service_discovery_single_value_warehouse ######
add_library(_service_discovery_single_value_warehouse SHARED
  "container/single_value_warehouse.cc"
  "container/single_value_warehouse.h"
  "/apollo/cyber/service_discovery/container/warehouse_base.h"
  "/apollo/cyber/base/atomic_rw_lock.h"
  "/apollo/cyber/base/rw_lock_guard.h"
)
target_link_libraries(_service_discovery_single_value_warehouse _service_discovery_role)

set_target_properties(_service_discovery_single_value_warehouse PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_service_discovery_single_value_warehouse PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _service_discovery_topology_manager ######
add_library(_service_discovery_topology_manager SHARED
  "topology_manager.cc"
  "topology_manager.h"
)
target_link_libraries(_service_discovery_topology_manager _service_discovery_channel_manager)
target_link_libraries(_service_discovery_topology_manager _service_discovery_node_manager)
target_link_libraries(_service_discovery_topology_manager _service_discovery_participant_listener)
target_link_libraries(_service_discovery_topology_manager _service_discovery_service_manager)
target_link_libraries(_service_discovery_topology_manager _transport_participant)

set_target_properties(_service_discovery_topology_manager PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_service_discovery_topology_manager PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _service_discovery_manager ######
add_library(_service_discovery_manager SHARED
  "specific_manager/manager.cc"
  "specific_manager/manager.h"
  "/apollo/cyber/base/signal.h"
  "/apollo/cyber/message/message_traits.h"
  "/apollo/cyber/message/message_header.h"
  "/apollo/cyber/message/protobuf_traits.h"
  "/apollo/cyber/message/py_message_traits.h"
  "/apollo/cyber/message/raw_message_traits.h"
  "/apollo/cyber/base/macros.h"
  "/apollo/cyber/message/py_message.h"
  "/apollo/cyber/message/raw_message.h"
)
target_link_libraries(_service_discovery_manager _service_discovery_subscriber_listener)
target_link_libraries(_service_discovery_manager _state)
target_link_libraries(_service_discovery_manager _message_protobuf_factory)
target_link_libraries(_service_discovery_manager _cyber_proto_cc_lib)
target_link_libraries(_service_discovery_manager _cyber_proto_cc_lib)
target_link_libraries(_service_discovery_manager _cyber_proto_cc_lib)
target_link_libraries(_service_discovery_manager _time_time)
target_link_libraries(_service_discovery_manager _transport_attributes_filler)
target_link_libraries(_service_discovery_manager _transport_qos_profile_conf)
target_link_libraries(_service_discovery_manager _transport_underlay_message_type)

set_target_properties(_service_discovery_manager PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_service_discovery_manager PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _service_discovery_participant_listener ######
add_library(_service_discovery_participant_listener SHARED
  "communication/participant_listener.cc"
  "communication/participant_listener.h"
  "/apollo/cyber/common/log.h"
  "/apollo/cyber/binary.h"
)
target_link_libraries(_service_discovery_participant_listener fastrtps fastcdr)
target_link_libraries(_service_discovery_participant_listener glog)

set_target_properties(_service_discovery_participant_listener PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_service_discovery_participant_listener PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _service_discovery_graph ######
add_library(_service_discovery_graph SHARED
  "container/graph.cc"
  "container/graph.h"
  "/apollo/cyber/base/atomic_rw_lock.h"
  "/apollo/cyber/base/rw_lock_guard.h"
)

set_target_properties(_service_discovery_graph PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_service_discovery_graph PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _service_discovery_channel_manager ######
add_library(_service_discovery_channel_manager SHARED
  "specific_manager/channel_manager.cc"
  "specific_manager/channel_manager.h"
)
target_link_libraries(_service_discovery_channel_manager _service_discovery_graph)
target_link_libraries(_service_discovery_channel_manager _service_discovery_manager)
target_link_libraries(_service_discovery_channel_manager _service_discovery_multi_value_warehouse)
target_link_libraries(_service_discovery_channel_manager _service_discovery_single_value_warehouse)

set_target_properties(_service_discovery_channel_manager PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_service_discovery_channel_manager PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _service_discovery_node_manager ######
add_library(_service_discovery_node_manager SHARED
  "specific_manager/node_manager.cc"
  "specific_manager/node_manager.h"
)
target_link_libraries(_service_discovery_node_manager _service_discovery_manager)
target_link_libraries(_service_discovery_node_manager _service_discovery_multi_value_warehouse)
target_link_libraries(_service_discovery_node_manager _service_discovery_single_value_warehouse)

set_target_properties(_service_discovery_node_manager PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_service_discovery_node_manager PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

