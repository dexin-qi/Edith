cmake_minimum_required(VERSION 3.2)
project(edith CXX ASM)

set(EDITH_VERSION_MAJOR  1)
set(EDITH_VERSION_MINOR  0)
set(EDITH_VERSION_PATCH  0)
set(EDITH_VERSION ${EDITH_VERSION_MAJOR}.${EDITH_VERSION_MINOR}.${EDITH_VERSION_PATCH})

option(BUILD_EDITH_TEST "build Edith test" true)

include("${PROJECT_SOURCE_DIR}/cmake/functions.cmake")

dustin_initialize_edith_project()
dustin_enable_google_testing()

set(PYTHON2_INCLUDE_DIR "/usr/include/python2.7")
set(PYTHON2_LIBRARIES   "/usr/lib/x86_64-linux-gnu/libpython2.7.so")
set(PYTHON3_INCLUDE_DIR "/usr/include/python3.5m")
set(PYTHON3_LIBRARIES   "/usr/lib/x86_64-linux-gnu/libpython3.5m.so")

find_package(Abseil REQUIRED)
find_package(Boost REQUIRED QUIET)
find_package(Protobuf 3.0.0 REQUIRED QUIET)

# Find requirements
find_package(fastrtps REQUIRED)
find_package(fastcdr REQUIRED)

include(FindPkgConfig)

add_subdirectory(cyber)