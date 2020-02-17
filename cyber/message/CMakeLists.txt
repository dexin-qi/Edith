###### bazel lib: _message_protobuf_factory ######
add_library(_message_protobuf_factory SHARED
  "protobuf_factory.cc"
  "protobuf_factory.h"
  "/apollo/cyber/common/log.h"
  "/apollo/cyber/common/macros.h"
  "/apollo/cyber/binary.h"
  "/apollo/cyber/base/macros.h"
)
target_link_libraries(_message_protobuf_factory _cyber_proto_cc_lib)
target_link_libraries(_message_protobuf_factory glog)

set_target_properties(_message_protobuf_factory PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_message_protobuf_factory PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

