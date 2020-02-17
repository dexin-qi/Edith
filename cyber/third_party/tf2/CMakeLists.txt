find_package(Boost REQUIRED COMPONENTS signals system thread)
include_directories(include)

add_library(tf2 SHARED src/cache.cpp src/buffer_core.cpp src/static_cache.cpp src/time.cpp)
target_link_libraries(tf2 ${Boost_LIBRARIES}  ${console_bridge_LIBRARIES})
