# Copyright DustinKsi. All Rights Reserved.
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#  http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.

include(CMakeParseArguments)

macro(_parse_arguments ARGS)
  set(OPTIONS)
  set(ONE_VALUE_ARG)
  set(MULTI_VALUE_ARGS SRCS LIBS DESCRIPTS)
  cmake_parse_arguments(ARG
    "${OPTIONS}" "${ONE_VALUE_ARG}" "${MULTI_VALUE_ARGS}" ${ARGS})
endmacro(_parse_arguments)

macro(_common_compile_stuff LIB_NAME)
  target_link_libraries(${NAME} ${LIB_NAME})
  
  set(TARGET_COMPILE_FLAGS "${TARGET_COMPILE_FLAGS} ${EDITH_CXX_FLAGS}")
  set_target_properties(${NAME} PROPERTIES COMPILE_FLAGS ${TARGET_COMPILE_FLAGS})
endmacro(_common_compile_stuff)

function(_py2_library NAME)
  _parse_arguments("${ARGN}")
  # message(STATUS "Add Edith Py2 Lib: ${NAME}")

  add_library(${NAME} SHARED ${ARG_SRCS})

  target_include_directories(${NAME} SYSTEM PUBLIC ${PYTHON2_INCLUDE_DIR})
  target_link_libraries(${NAME} ${PYTHON2_LIBRARIES})
  
  foreach(LIB ${ARG_LIBS})
    _common_compile_stuff(${LIB})
  endforeach()

  set_target_properties(${NAME} PROPERTIES PREFIX "")
  set_target_properties(${NAME} PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

  target_include_directories(${NAME} PUBLIC
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
  )
endfunction()

function(_py3_library NAME)
  _parse_arguments("${ARGN}")
  # message(STATUS "Add Edith Py3 Lib: ${NAME}")

  add_library(${NAME} SHARED ${ARG_SRCS})

  target_include_directories(${NAME} SYSTEM PUBLIC ${PYTHON3_INCLUDE_DIR})
  target_link_libraries(${NAME} ${PYTHON3_LIBRARIES})
  
  foreach(LIB ${ARG_LIBS})
    _common_compile_stuff(${LIB})
  endforeach()

  set_target_properties(${NAME} PROPERTIES PREFIX "")
  set_target_properties(${NAME} PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

  target_include_directories(${NAME} PUBLIC
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
  )
endfunction()

function(_edith_library NAME)
  _parse_arguments("${ARGN}")
  # message(STATUS "Add Edith Lib: ${NAME}")
  
  add_library(${NAME} SHARED ${ARG_SRCS})

  foreach(LIB ${ARG_LIBS})
    _common_compile_stuff(${LIB})
  endforeach()

  set_target_properties(${NAME} PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

  target_include_directories(${NAME} PUBLIC
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
  )
endfunction()


# add test block
function(edith_test NAME)
  _parse_arguments("${ARGN}")
  # message(STATUS "Add Edith Test: ${NAME}")

  add_executable(${NAME} ${ARG_SRCS})
  foreach(LIB ${ARG_LIBS})
    _common_compile_stuff(${LIB})
  endforeach()

  target_include_directories("${NAME}" SYSTEM PUBLIC "${GMOCK_INCLUDE_DIRS}")
  target_link_libraries("${NAME}" ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
  target_link_libraries("${NAME}" ${GMOCK_LIBRARIES})

  add_test(${NAME} ${NAME})
endfunction()


# add binary block
function(edith_binary NAME)
  _parse_arguments("${ARGN}")
  # message(STATUS "Add Edith Binary: ${NAME} ${ARG_DESCRIPTS}")

  add_executable(${NAME} ${ARG_SRCS})
  foreach(LIB ${ARG_LIBS})
    # message(STATUS "Add depend lib: ${LIB}")
    _common_compile_stuff(${LIB})
  endforeach()

  install(TARGETS "${NAME}" RUNTIME DESTINATION bin)
endfunction()

function(dustin_add_flag VAR_NAME FLAG)
  if (${VAR_NAME})
    set(${VAR_NAME} "${${VAR_NAME}} ${FLAG}" PARENT_SCOPE)
  else()
    set(${VAR_NAME} "${FLAG}" PARENT_SCOPE)
  endif()
endfunction()

macro(dustin_initialize_edith_project)
  if(EDITH_CMAKE_DIR)
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${EDITH_CMAKE_DIR}/modules)
  else()
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)
  endif()

  dustin_add_flag(EDITH_CXX_FLAGS "-pthread -std=c++11 -fPIC")

  dustin_add_flag(EDITH_CXX_FLAGS "-Wall")
  dustin_add_flag(EDITH_CXX_FLAGS "-Wpedantic")

  # Turn some warnings into errors.
  dustin_add_flag(EDITH_CXX_FLAGS "-Werror=format-security")
  dustin_add_flag(EDITH_CXX_FLAGS "-Werror=missing-braces")
  dustin_add_flag(EDITH_CXX_FLAGS "-Werror=reorder")
  dustin_add_flag(EDITH_CXX_FLAGS "-Werror=return-type")
  dustin_add_flag(EDITH_CXX_FLAGS "-Werror=switch")
  dustin_add_flag(EDITH_CXX_FLAGS "-Werror=uninitialized")

  # dustin_chagen_cmake : None -> Release
  if(NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "" OR CMAKE_BUILD_TYPE STREQUAL "None")
    set(CMAKE_BUILD_TYPE Release)
  endif()

  if(CMAKE_BUILD_TYPE STREQUAL "Release")
    dustin_add_flag(EDITH_CXX_FLAGS "-O3 -DNDEBUG")
  elseif(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    dustin_add_flag(EDITH_CXX_FLAGS "-O3 -g -DNDEBUG")
  elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
    if(FORCE_DEBUG_BUILD)
      message(WARNING "Building in Debug mode, expect very slow performance.")
      dustin_add_flag(EDITH_CXX_FLAGS "-g")
    else()
      message(FATAL_ERROR 
        "Compiling in Debug mode is not supported and can cause severely degraded performance. "
        "You should change the build type to Release. If you want to build in Debug mode anyway, "
        "call CMake with -DCMAKE_BUILD_TYPE=Debug -DFORCE_DEBUG_BUILD=True")
    endif()
  else()
    message(FATAL_ERROR "Unknown CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
  endif()

  message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

  # Add a hook that reruns CMake when source files are added or removed.
  set(LIST_FILES_CMD "find ${PROJECT_SOURCE_DIR}/ -not -iwholename '*.git*' | sort | sed 's/^/#/'")
  set(FILES_LIST_PATH "${PROJECT_BINARY_DIR}/AllFiles.cmake")
  set(DETECT_CHANGES_CMD "bash" "-c" "${LIST_FILES_CMD} | diff -N -q ${FILES_LIST_PATH} - || ${LIST_FILES_CMD} > ${FILES_LIST_PATH}")
  add_custom_target(${PROJECT_NAME}_detect_changes ALL
    COMMAND ${DETECT_CHANGES_CMD}
    VERBATIM
  )
  if(NOT EXISTS ${FILES_LIST_PATH})
    execute_process(COMMAND ${DETECT_CHANGES_CMD})
  endif()
  include(${FILES_LIST_PATH})
endmacro()

macro(dustin_enable_google_testing)
  enable_testing()
  find_package(GTest REQUIRED)
  find_package(GMock REQUIRED)
endmacro()
