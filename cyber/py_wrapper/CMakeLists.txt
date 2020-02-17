###### bazel lib: _py_wrapper_py3_timer ######
add_library(_py_wrapper_py3_timer SHARED
  "py_timer.cc"
  "py_timer.h"
)
target_link_libraries(_py_wrapper_py3_timer _cyber_core)
target_include_directories(_py_wrapper_py3_timer SYSTEM PUBLIC ${PYTHON3_INCLUDE_DIR})
target_link_libraries(_py_wrapper_py3_timer ${PYTHON3_LIBRARIES})

set_target_properties(_py_wrapper_py3_timer PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_py_wrapper_py3_timer PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _py_wrapper_py3_time ######
add_library(_py_wrapper_py3_time SHARED
  "py_time.cc"
  "py_time.h"
)
target_link_libraries(_py_wrapper_py3_time _cyber_core)
target_link_libraries(_py_wrapper_py3_time fastrtps fastcdr)
target_include_directories(_py_wrapper_py3_time SYSTEM PUBLIC ${PYTHON3_INCLUDE_DIR})
target_link_libraries(_py_wrapper_py3_time ${PYTHON3_LIBRARIES})

set_target_properties(_py_wrapper_py3_time PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_py_wrapper_py3_time PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _py_wrapper_py_timer ######
add_library(_py_wrapper_py_timer SHARED
  "py_timer.cc"
  "py_timer.h"
)
target_link_libraries(_py_wrapper_py_timer _cyber_core)
target_include_directories(_py_wrapper_py_timer SYSTEM PUBLIC ${PYTHON2_INCLUDE_DIR})
target_link_libraries(_py_wrapper_py_timer ${PYTHON2_LIBRARIES})

set_target_properties(_py_wrapper_py_timer PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_py_wrapper_py_timer PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _py_wrapper_py_record ######
add_library(_py_wrapper_py_record SHARED
  "py_record.cc"
  "py_record.h"
  "/apollo/cyber/message/py_message.h"
)
target_include_directories(_py_wrapper_py_record SYSTEM PUBLIC ${PYTHON2_INCLUDE_DIR})
target_link_libraries(_py_wrapper_py_record ${PYTHON2_LIBRARIES})
target_link_libraries(_py_wrapper_py_record _message_protobuf_factory)
target_link_libraries(_py_wrapper_py_record _record_record_reader)
target_link_libraries(_py_wrapper_py_record _record_record_viewer)
target_link_libraries(_py_wrapper_py_record _record_record_writer)

set_target_properties(_py_wrapper_py_record PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_py_wrapper_py_record PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _py_wrapper_py_cyber ######
add_library(_py_wrapper_py_cyber SHARED
  "py_cyber.cc"
  "py_cyber.h"
)
target_link_libraries(_py_wrapper_py_cyber _cyber_core)
target_include_directories(_py_wrapper_py_cyber SYSTEM PUBLIC ${PYTHON2_INCLUDE_DIR})
target_link_libraries(_py_wrapper_py_cyber ${PYTHON2_LIBRARIES})
target_link_libraries(_py_wrapper_py_cyber -lrt)

set_target_properties(_py_wrapper_py_cyber PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_py_wrapper_py_cyber PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _py_wrapper_py3_cyber ######
add_library(_py_wrapper_py3_cyber SHARED
  "py_cyber.cc"
  "py_cyber.h"
)
target_link_libraries(_py_wrapper_py3_cyber _cyber_core)
target_include_directories(_py_wrapper_py3_cyber SYSTEM PUBLIC ${PYTHON3_INCLUDE_DIR})
target_link_libraries(_py_wrapper_py3_cyber ${PYTHON3_LIBRARIES})
target_link_libraries(_py_wrapper_py3_cyber -lrt)

set_target_properties(_py_wrapper_py3_cyber PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_py_wrapper_py3_cyber PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _py_wrapper_py_parameter ######
add_library(_py_wrapper_py_parameter SHARED
  "py_parameter.cc"
  "py_parameter.h"
)
target_link_libraries(_py_wrapper_py_parameter _py_wrapper_py_cyber)
target_link_libraries(_py_wrapper_py_parameter _cyber_core)
target_include_directories(_py_wrapper_py_parameter SYSTEM PUBLIC ${PYTHON2_INCLUDE_DIR})
target_link_libraries(_py_wrapper_py_parameter ${PYTHON2_LIBRARIES})

set_target_properties(_py_wrapper_py_parameter PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_py_wrapper_py_parameter PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _py_wrapper_py3_parameter ######
add_library(_py_wrapper_py3_parameter SHARED
  "py_parameter.cc"
  "py_parameter.h"
)
target_link_libraries(_py_wrapper_py3_parameter _py_wrapper_py3_cyber)
target_link_libraries(_py_wrapper_py3_parameter _cyber_core)
target_include_directories(_py_wrapper_py3_parameter SYSTEM PUBLIC ${PYTHON3_INCLUDE_DIR})
target_link_libraries(_py_wrapper_py3_parameter ${PYTHON3_LIBRARIES})

set_target_properties(_py_wrapper_py3_parameter PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_py_wrapper_py3_parameter PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _py_wrapper_py3_record ######
add_library(_py_wrapper_py3_record SHARED
  "py_record.cc"
  "py_record.h"
  "/apollo/cyber/message/py_message.h"
)
target_include_directories(_py_wrapper_py3_record SYSTEM PUBLIC ${PYTHON3_INCLUDE_DIR})
target_link_libraries(_py_wrapper_py3_record ${PYTHON3_LIBRARIES})
target_link_libraries(_py_wrapper_py3_record _message_protobuf_factory)
target_link_libraries(_py_wrapper_py3_record _record_record_reader)
target_link_libraries(_py_wrapper_py3_record _record_record_viewer)
target_link_libraries(_py_wrapper_py3_record _record_record_writer)

set_target_properties(_py_wrapper_py3_record PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_py_wrapper_py3_record PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _py_wrapper_py_time ######
add_library(_py_wrapper_py_time SHARED
  "py_time.cc"
  "py_time.h"
)
target_link_libraries(_py_wrapper_py_time _cyber_core)
target_link_libraries(_py_wrapper_py_time fastrtps fastcdr)
target_include_directories(_py_wrapper_py_time SYSTEM PUBLIC ${PYTHON2_INCLUDE_DIR})
target_link_libraries(_py_wrapper_py_time ${PYTHON2_LIBRARIES})

set_target_properties(_py_wrapper_py_time PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_py_wrapper_py_time PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

