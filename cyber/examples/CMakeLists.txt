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