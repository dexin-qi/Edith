
add_executable(cyber_recorder
  "main.cc"
  "/edith/cyber/common/time_conversion.h"
)
target_link_libraries(cyber_recorder _tools_cyber_recorder_info)
target_link_libraries(cyber_recorder _tools_cyber_recorder_player)
target_link_libraries(cyber_recorder _tools_cyber_recorder_recorder)
target_link_libraries(cyber_recorder _tools_cyber_recorder_recoverer)
target_link_libraries(cyber_recorder _tools_cyber_recorder_spliter)
target_link_libraries(cyber_recorder _init)
target_link_libraries(cyber_recorder _common_file)
target_link_libraries(cyber_recorder -pthread)
target_link_libraries(cyber_recorder -lgflags)

set_target_properties(cyber_recorder PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(cyber_recorder PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _tools_cyber_recorder_recorder ######
add_library(_tools_cyber_recorder_recorder SHARED
  "recorder.cc"
  "recorder.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/binary.h"
)
target_link_libraries(_tools_cyber_recorder_recorder _cyber_proto_cc_lib)
target_link_libraries(_tools_cyber_recorder_recorder fastrtps fastcdr)
target_link_libraries(_tools_cyber_recorder_recorder _cyber_core)
target_link_libraries(_tools_cyber_recorder_recorder glog)

set_target_properties(_tools_cyber_recorder_recorder PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_tools_cyber_recorder_recorder PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)


###### bazel lib: _tools_cyber_recorder_info ######
add_library(_tools_cyber_recorder_info SHARED
  "info.cc"
  "info.h"
  "/edith/cyber/common/time_conversion.h"
  "/edith/cyber/record/record_message.h"
)
target_link_libraries(_tools_cyber_recorder_info _cyber_proto_cc_lib)
target_link_libraries(_tools_cyber_recorder_info _record_record_file_reader)

set_target_properties(_tools_cyber_recorder_info PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_tools_cyber_recorder_info PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _tools_cyber_recorder_player ######
add_library(_tools_cyber_recorder_player SHARED
  "player/play_task.cc"
  "player/play_task_buffer.cc"
  "player/play_task_consumer.cc"
  "player/play_task_producer.cc"
  "player/player.cc"
  "player/play_param.h"
  "player/play_task.h"
  "player/play_task_buffer.h"
  "player/play_task_consumer.h"
  "player/play_task_producer.h"
  "player/player.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/binary.h"
)
target_link_libraries(_tools_cyber_recorder_player _cyber_proto_cc_lib)
target_link_libraries(_tools_cyber_recorder_player _record_record_reader)
target_link_libraries(_tools_cyber_recorder_player _cyber_core)
target_link_libraries(_tools_cyber_recorder_player glog)

set_target_properties(_tools_cyber_recorder_player PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_tools_cyber_recorder_player PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _tools_cyber_recorder_recoverer ######
add_library(_tools_cyber_recorder_recoverer SHARED
  "recoverer.cc"
  "recoverer.h"
  "/edith/cyber/base/for_each.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/base/macros.h"
  "/edith/cyber/binary.h"
)
target_link_libraries(_tools_cyber_recorder_recoverer _cyber_proto_cc_lib)
target_link_libraries(_tools_cyber_recorder_recoverer _record_header_builder)
target_link_libraries(_tools_cyber_recorder_recoverer _record_record_file_reader)
target_link_libraries(_tools_cyber_recorder_recoverer _record_record_writer)
target_link_libraries(_tools_cyber_recorder_recoverer glog)

set_target_properties(_tools_cyber_recorder_recoverer PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_tools_cyber_recorder_recoverer PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _tools_cyber_recorder_spliter ######
add_library(_tools_cyber_recorder_spliter SHARED
  "spliter.cc"
  "spliter.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/binary.h"
)
target_link_libraries(_tools_cyber_recorder_spliter _cyber_proto_cc_lib)
target_link_libraries(_tools_cyber_recorder_spliter _record_header_builder)
target_link_libraries(_tools_cyber_recorder_spliter _record_record_file_reader)
target_link_libraries(_tools_cyber_recorder_spliter _record_record_writer)
target_link_libraries(_tools_cyber_recorder_spliter glog)

set_target_properties(_tools_cyber_recorder_spliter PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_tools_cyber_recorder_spliter PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)
