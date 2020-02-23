cmake_minimum_required(VERSION 3.2)
project(edith CXX ASM)

set(EDITH_VERSION_MAJOR  1)
set(EDITH_VERSION_MINOR  0)
set(EDITH_VERSION_PATCH  0)
set(EDITH_VERSION ${EDITH_VERSION_MAJOR}.${EDITH_VERSION_MINOR}.${EDITH_VERSION_PATCH})

option(BUILD_EDITH_TEST "Build Edith Tests" false)

include("${PROJECT_SOURCE_DIR}/cmake/functions.cmake")

dustin_initialize_edith_project()
dustin_enable_google_testing()

include(FindPkgConfig)

# Find requirements
find_package(Abseil REQUIRED)
find_package(Boost REQUIRED QUIET)
find_package(Protobuf 3.3.0 REQUIRED QUIET)
find_package(Poco REQUIRED Foundation)
find_package(Eigen3 REQUIRED QUIET)

find_package(fastrtps REQUIRED)
find_package(fastcdr REQUIRED)

set(JSONCPP_INCLUDE_DIRS "/usr/include/jsoncpp")
set(JSONCPP_LIBRARIES   "libjsoncpp.so")

set(PYTHON2_INCLUDE_DIR "/usr/include/python2.7")
set(PYTHON2_LIBRARIES   "/usr/lib/x86_64-linux-gnu/libpython2.7.so")
set(PYTHON3_INCLUDE_DIR "/usr/include/python3.6m")
set(PYTHON3_LIBRARIES   "/usr/lib/x86_64-linux-gnu/libpython3.6m.so")

# for qpOASES
link_directories("/usr/local/lib")

add_subdirectory(cyber)
add_subdirectory(modules)