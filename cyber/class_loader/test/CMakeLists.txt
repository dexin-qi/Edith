###### bazel lib: _class_loader_test_plugin1 ######
add_library(_class_loader_test_plugin1 SHARED
  "plugin1.cc"
  "/edith/cyber/class_loader/test/base.h"
)
target_link_libraries(_class_loader_test_plugin1 _class_loader_class_loader_manager)

set_target_properties(_class_loader_test_plugin1 PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_class_loader_test_plugin1 PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _class_loader_test_plugin2 ######
add_library(_class_loader_test_plugin2 SHARED
  "plugin2.cc"
  "/edith/cyber/class_loader/test/base.h"
)
target_link_libraries(_class_loader_test_plugin2 _class_loader_class_loader_manager)

set_target_properties(_class_loader_test_plugin2 PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_class_loader_test_plugin2 PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

