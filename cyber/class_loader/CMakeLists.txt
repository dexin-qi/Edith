###### bazel lib: _class_loader_class_loader_manager ######
add_library(_class_loader_class_loader_manager SHARED
  "class_loader_manager.cc"
  "class_loader_manager.h"
)
target_link_libraries(_class_loader_class_loader_manager _class_loader_class_loader)

set_target_properties(_class_loader_class_loader_manager PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_class_loader_class_loader_manager PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

###### bazel lib: _class_loader_class_loader ######
add_library(_class_loader_class_loader SHARED
  "class_loader.cc"
  "utility/class_factory.cc"
  "utility/class_loader_utility.cc"
  "class_loader.h"
  "class_loader_register_macro.h"
  "utility/class_factory.h"
  "utility/class_loader_utility.h"
  "/edith/cyber/common/log.h"
  "/edith/cyber/binary.h"
)
target_link_libraries(_class_loader_class_loader _init)
target_link_libraries(_class_loader_class_loader -lPocoFoundation)
target_link_libraries(_class_loader_class_loader glog)

set_target_properties(_class_loader_class_loader PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_class_loader_class_loader PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

