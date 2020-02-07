add_library(class_plugin1 SHARED
    example_class_loader/plugin1.cc 
    example_class_loader/base.h
)
target_link_libraries(class_plugin1 edith_cyber)
set_target_properties(class_plugin1 PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

add_library(class_plugin2 SHARED
    example_class_loader/plugin2.cc 
    example_class_loader/base.h
)
target_link_libraries(class_plugin2 edith_cyber)
set_target_properties(class_plugin2 PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

add_custom_command(
  OUTPUT "${PROJECT_BINARY_DIR}/cyber/examples/proto/examples.pb.cc"
  "${PROJECT_BINARY_DIR}/cyber/examples/proto/examples.pb.h"
  COMMAND  ${PROTOBUF_PROTOC_EXECUTABLE}
  ARGS --cpp_out  ${PROJECT_BINARY_DIR} -I 
  ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/cyber/examples/proto/examples.proto
  DEPENDS ${PROJECT_SOURCE_DIR}/cyber/examples/proto/examples.proto
  COMMENT "Running C++ protocol buffer compiler on examples.proto"
  VERBATIM
)

add_library(proto_example
    ${PROJECT_BINARY_DIR}/cyber/examples/proto/examples.pb.h
    ${PROJECT_BINARY_DIR}/cyber/examples/proto/examples.pb.cc
)
target_include_directories(proto_example SYSTEM PUBLIC
  ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(proto_example ${PROTOBUF_LIBRARY})
target_link_libraries(proto_example standalone_absl)
set_target_properties(proto_example PROPERTIES
  COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(proto_example PUBLIC
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

set(EXAMPLE_LIBS)
list(APPEND EXAMPLE_LIBS "edith_cyber")
list(APPEND EXAMPLE_LIBS "proto_example")

edith_binary(talker
  SRCS
    talker.cc
  LIBS
    ${EXAMPLE_LIBS}
)


edith_binary(listener
  SRCS
    listener.cc
  LIBS
    ${EXAMPLE_LIBS}
)

edith_binary(service
  SRCS
    service.cc
  LIBS
    ${EXAMPLE_LIBS}
)

edith_binary(paramserver
  SRCS
    paramserver.cc
  LIBS
    ${EXAMPLE_LIBS}
)

edith_binary(record
  SRCS
    record.cc
  LIBS
    ${EXAMPLE_LIBS}
)

add_subdirectory(example_component_common)
add_subdirectory(example_component_timer)
