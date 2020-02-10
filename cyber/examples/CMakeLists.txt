add_library(class_plugin1 SHARED
    example_class_loader/plugin1.cc 
    example_class_loader/base.h
)
target_link_libraries(class_plugin1 edith_cyber)
set_target_properties(class_plugin1 PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

add_library(class_plugin2 SHARED
    example_class_loader/plugin2.cc 
    example_class_loader/base.h
)
target_link_libraries(class_plugin2 edith_cyber)
set_target_properties(class_plugin2 PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

edith_binary(talker
  SRCS
    talker.cc
  LIBS
    edith_cyber
)

edith_binary(listener
  SRCS
    listener.cc
  LIBS
    edith_cyber
)

edith_binary(service
  SRCS
    service.cc
  LIBS
    edith_cyber
)

edith_binary(paramserver
  SRCS
    paramserver.cc
  LIBS
    edith_cyber
)

edith_binary(record
  SRCS
    record.cc
  LIBS
    edith_cyber
)

add_subdirectory(example_component_common)
add_subdirectory(example_component_timer)
