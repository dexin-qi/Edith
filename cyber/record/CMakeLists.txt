###### bazel lib: _record_header_builder ######
add_library(_record_header_builder SHARED
  "header_builder.cc"
  "header_builder.h"
)
target_link_libraries(_record_header_builder _cyber_proto_cc_lib)

set_target_properties(_record_header_builder PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_record_header_builder PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _record_record_file_writer ######
add_library(_record_record_file_writer SHARED
  "file/record_file_writer.cc"
  "file/record_file_writer.h"
  "/edith/cyber/record/file/section.h"
)
target_link_libraries(_record_record_file_writer _record_record_file_base)
target_link_libraries(_record_record_file_writer _common_file)
target_link_libraries(_record_record_file_writer _time_time)
target_include_directories(_record_record_file_writer SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_record_record_file_writer ${PROTOBUF_LIBRARY} standalone_absl)

set_target_properties(_record_record_file_writer PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_record_record_file_writer PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _record_record_viewer ######
add_library(_record_record_viewer SHARED
  "record_viewer.cc"
  "record_viewer.h"
  "/edith/cyber/record/record_message.h"
)
target_link_libraries(_record_record_viewer _record_record_reader)

set_target_properties(_record_record_viewer PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_record_record_viewer PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _record_record_file_base ######
add_library(_record_record_file_base SHARED
  "file/record_file_base.cc"
  "file/record_file_base.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/binary.h"
)
target_link_libraries(_record_record_file_base _cyber_proto_cc_lib)
target_link_libraries(_record_record_file_base glog)

set_target_properties(_record_record_file_base PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_record_record_file_base PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _record_record_writer ######
add_library(_record_record_writer SHARED
  "record_writer.cc"
  "record_writer.h"
  "/edith/cyber/record/record_base.h"
  "/edith/cyber/message/message_traits.h"
  "/edith/cyber/message/raw_message.h"
  "/edith/cyber/message/message_header.h"
  "/edith/cyber/message/protobuf_traits.h"
  "/edith/cyber/message/py_message_traits.h"
  "/edith/cyber/message/raw_message_traits.h"
  "/edith/cyber/base/macros.h"
  "/edith/cyber/message/py_message.h"
)
target_link_libraries(_record_record_writer _record_header_builder)
target_link_libraries(_record_record_writer _record_record_file_writer)
target_link_libraries(_record_record_writer _cyber_proto_cc_lib)
target_link_libraries(_record_record_writer _message_protobuf_factory)

set_target_properties(_record_record_writer PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_record_record_writer PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _record_record_reader ######
add_library(_record_record_reader SHARED
  "record_reader.cc"
  "record_reader.h"
  "/edith/cyber/record/record_base.h"
  "/edith/cyber/record/record_message.h"
)
target_link_libraries(_record_record_reader _record_record_file_reader)
target_link_libraries(_record_record_reader _cyber_proto_cc_lib)

set_target_properties(_record_record_reader PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_record_record_reader PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _record_record_file_reader ######
add_library(_record_record_file_reader SHARED
  "file/record_file_reader.cc"
  "file/record_file_reader.h"
  "/edith/cyber/record/file/section.h"
)
target_link_libraries(_record_record_file_reader _record_record_file_base)
target_link_libraries(_record_record_file_reader _common_file)
target_link_libraries(_record_record_file_reader _time_time)
target_include_directories(_record_record_file_reader SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_record_record_file_reader ${PROTOBUF_LIBRARY} standalone_absl)

set_target_properties(_record_record_file_reader PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_record_record_file_reader PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

