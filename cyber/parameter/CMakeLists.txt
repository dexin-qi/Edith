###### bazel lib: _parameter_parameter_server ######
add_library(_parameter_parameter_server SHARED
  "parameter_server.cc"
  "parameter_server.h"
  "/edith/cyber/parameter/parameter_service_names.h"
  "/edith/cyber/service/service.h"
  "/edith/cyber/service/service_base.h"
)
target_link_libraries(_parameter_parameter_server _parameter_parameter)
target_link_libraries(_parameter_parameter_server _node_node)
target_link_libraries(_parameter_parameter_server fastrtps fastcdr)
target_link_libraries(_parameter_parameter_server _scheduler_scheduler)

set_target_properties(_parameter_parameter_server PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_parameter_parameter_server PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _parameter_parameter_client ######
add_library(_parameter_parameter_client SHARED
  "parameter_client.cc"
  "parameter_client.h"
  "/edith/cyber/parameter/parameter_service_names.h"
  "/edith/cyber/service/client.h"
  "/edith/cyber/service/client_base.h"
)
target_link_libraries(_parameter_parameter_client _parameter_parameter)
target_link_libraries(_parameter_parameter_client _node_node)
target_link_libraries(_parameter_parameter_client fastrtps fastcdr)

set_target_properties(_parameter_parameter_client PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_parameter_parameter_client PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _parameter_parameter ######
add_library(_parameter_parameter SHARED
  "parameter.cc"
  "parameter.h"
)
target_link_libraries(_parameter_parameter _message_protobuf_factory)
target_link_libraries(_parameter_parameter _cyber_proto_cc_lib)

set_target_properties(_parameter_parameter PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_parameter_parameter PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

