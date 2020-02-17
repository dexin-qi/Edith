file(GLOB_RECURSE ALL_PROTOS "*.proto")

set(ALL_PROTO_SRCS)
set(ALL_PROTO_HDRS)
foreach(ABS_FIL ${ALL_PROTOS})
  file(RELATIVE_PATH REL_FIL ${PROJECT_SOURCE_DIR} ${ABS_FIL})
  get_filename_component(DIR ${REL_FIL} DIRECTORY)
  get_filename_component(FIL_WE ${REL_FIL} NAME_WE)

  list(APPEND ALL_PROTO_SRCS "${PROJECT_BINARY_DIR}/${DIR}/${FIL_WE}.pb.cc")
  list(APPEND ALL_PROTO_HDRS "${PROJECT_BINARY_DIR}/${DIR}/${FIL_WE}.pb.h")

  add_custom_command(
    OUTPUT "${PROJECT_BINARY_DIR}/${DIR}/${FIL_WE}.pb.cc"
    "${PROJECT_BINARY_DIR}/${DIR}/${FIL_WE}.pb.h"
    COMMAND  ${PROTOBUF_PROTOC_EXECUTABLE}
    ARGS --cpp_out  ${PROJECT_BINARY_DIR} -I
    ${PROJECT_SOURCE_DIR} ${ABS_FIL}
    DEPENDS ${ABS_FIL}
    COMMENT "Running C++ protocol buffer compiler on ${ABS_FIL}"
    VERBATIM
  )
endforeach()
  
set_source_files_properties(${ALL_PROTO_SRCS} ${ALL_PROTO_HDRS} PROPERTIES GENERATED TRUE)

add_library(_cyber_proto_cc_lib STATIC ${ALL_PROTO_SRCS} ${ALL_PROTO_HDRS})

target_include_directories(_cyber_proto_cc_lib SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_cyber_proto_cc_lib ${PROTOBUF_LIBRARY} standalone_absl)

set_target_properties(_cyber_proto_cc_lib PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_cyber_proto_cc_lib PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)
