###### bazel lib: _sysmo_sysmo ######
add_library(_sysmo_sysmo SHARED
  "sysmo.cc"
  "sysmo.h"
)
target_link_libraries(_sysmo_sysmo _scheduler_scheduler_factory)

set_target_properties(_sysmo_sysmo PROPERTIES COMPILE_FLAGS ${EDITH_CXX_FLAGS})

target_include_directories(_sysmo_sysmo PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

