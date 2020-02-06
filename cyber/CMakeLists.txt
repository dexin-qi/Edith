file(GLOB_RECURSE ALL_LIBRARY_HDRS "*.h")
file(GLOB_RECURSE ALL_LIBRARY_SRCS "*.cc")

file(GLOB_RECURSE ALL_EXAMPLE_HDRS "examples/*.h")
file(GLOB_RECURSE ALL_EXAMPLE_SRCS "examples/*.cc")
file(GLOB_RECURSE ALL_TOOLS_SRCS "tools/*.cc")
file(GLOB_RECURSE ALL_TOOLS_HDRS "tools/*.h")
file(GLOB_RECURSE ALL_MAINBOARD_HDRS "mainboard/*.h")
file(GLOB_RECURSE ALL_MAINBOARD_SRCS "mainboard/*.cc")
file(GLOB_RECURSE ALL_WRAPPER_HDRS "py_wrapper/*.h")
file(GLOB_RECURSE ALL_WRAPPER_SRCS "py_wrapper/*.cc")

file(GLOB_RECURSE ALL_PYTHON_SRCS "python/*.cc")

file(GLOB_RECURSE ALL_TESTS "*/*_test.cc")
file(GLOB_RECURSE ALL_PROTOS "*/*.proto")


list(REMOVE_ITEM ALL_LIBRARY_HDRS ${ALL_EXAMPLE_HDRS})
list(REMOVE_ITEM ALL_LIBRARY_SRCS ${ALL_EXAMPLE_SRCS})
list(REMOVE_ITEM ALL_LIBRARY_HDRS ${ALL_TOOLS_HDRS})
list(REMOVE_ITEM ALL_LIBRARY_SRCS ${ALL_TOOLS_SRCS})
list(REMOVE_ITEM ALL_LIBRARY_HDRS ${ALL_MAINBOARD_HDRS})
list(REMOVE_ITEM ALL_LIBRARY_SRCS ${ALL_MAINBOARD_SRCS})
list(REMOVE_ITEM ALL_LIBRARY_HDRS ${ALL_WRAPPER_HDRS})
list(REMOVE_ITEM ALL_LIBRARY_SRCS ${ALL_WRAPPER_SRCS})

list(REMOVE_ITEM ALL_LIBRARY_SRCS ${ALL_PYTHON_SRCS})

list(REMOVE_ITEM ALL_LIBRARY_SRCS ${ALL_TESTS})

set(ALL_LIBRARY_SRCS "croutine/detail/swap_x86_64.S;${ALL_LIBRARY_SRCS}")
# MESSAGE(STATUS "ALL_LIBRARY_SRCS: ${ALL_LIBRARY_SRCS}")

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
list(APPEND ALL_LIBRARY_HDRS ${ALL_PROTO_HDRS})
list(APPEND ALL_LIBRARY_SRCS ${ALL_PROTO_SRCS})

set(INSTALL_GENERATED_HDRS ${ALL_PROTO_HDRS})

add_library(edith_cyber STATIC ${ALL_LIBRARY_SRCS} ${ALL_LIBRARY_HDRS})

target_include_directories(edith_cyber SYSTEM PUBLIC
  "${Boost_INCLUDE_DIRS}")
target_link_libraries(edith_cyber ${Boost_LIBRARIES})

target_include_directories(edith_cyber SYSTEM PUBLIC 
  "${EIGEN3_INCLUDE_DIR}")
target_link_libraries(edith_cyber ${EIGEN3_LIBRARIES})

target_include_directories(edith_cyber SYSTEM PUBLIC
  ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(edith_cyber ${PROTOBUF_LIBRARY})

target_link_libraries(edith_cyber standalone_absl)
target_link_libraries(edith_cyber fastcdr fastrtps)
target_link_libraries(edith_cyber -latomic)
target_link_libraries(edith_cyber -lncurses)
target_link_libraries(edith_cyber -lrt)
target_link_libraries(edith_cyber -luuid)
target_link_libraries(edith_cyber -lPocoFoundation)
target_link_libraries(edith_cyber glog)
target_link_libraries(edith_cyber gflags)

set_target_properties(edith_cyber PROPERTIES
  COMPILE_FLAGS ${EDITH_CXX_FLAGS})

if(BUILD_EDITH_TEST)
  foreach(ABS_FIL ${ALL_TESTS})
    file(RELATIVE_PATH REL_FIL ${PROJECT_SOURCE_DIR} ${ABS_FIL})
    get_filename_component(DIR ${REL_FIL} DIRECTORY)
    get_filename_component(FIL_WE ${REL_FIL} NAME_WE)
    
    string(REPLACE "/" "." TEST_TARGET_NAME "${DIR}/${FIL_WE}")
    edith_test("${TEST_TARGET_NAME}" 
      SRCS
        ${ABS_FIL}
      LIBS
        edith_cyber
    )
  endforeach()
endif()

target_include_directories(edith_cyber PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

add_subdirectory(examples)