###### bazel lib: _blocker_blocker_manager ######
add_library(_blocker_blocker_manager SHARED
  "blocker_manager.cc"
  "blocker_manager.h"
  "/apollo/cyber/blocker/blocker.h"
)

set_target_properties(_blocker_blocker_manager PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_blocker_blocker_manager PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

