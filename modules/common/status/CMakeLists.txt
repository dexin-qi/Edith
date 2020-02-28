
### auto generate from bazel test : _common_status_status_test ###
dustin_var_append(STATUS_TEST_FILES /edith/modules/common/status/status_test.cc)
dustin_var_append(STATUS_TEST_FILES /edith/modules/common/status/status.h)
dustin_var_append(STATUS_TEST_FILES /edith/modules/common/util/future.h)

edith_test(_common_status_status_test
SRCS
  ${STATUS_TEST_FILES}
)
target_include_directories(_common_status_status_test SYSTEM PUBLIC ${PROTOBUF_INCLUDE_DIR})
target_link_libraries(_common_status_status_test ${PROTOBUF_LIBRARY} standalone_absl)
target_link_libraries(_common_status_status_test _modules_proto_cc_lib)
target_link_libraries(_common_status_status_test standalone_absl)
