add_library(class_plugin1 SHARED
    class_loader_example/plugin1.cc 
    class_loader_example/base.h
)
target_link_libraries(class_plugin1 edith_cyber)
set_target_properties(class_plugin1 PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

add_library(class_plugin2 SHARED
    class_loader_example/plugin2.cc 
    class_loader_example/base.h
)
target_link_libraries(class_plugin2 edith_cyber)
set_target_properties(class_plugin2 PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})