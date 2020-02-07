file(GLOB_RECURSE MONITOR_FILES "cyber_monitor/*.*")
file(GLOB_RECURSE RECORDER_FILES "cyber_recorder/*.*")

edith_binary(cyber_monitor
  SRCS
    ${MONITOR_FILES}
  LIBS
    edith_cyber
)

edith_binary(cyber_recorder
  SRCS
    ${RECORDER_FILES}
  LIBS
    edith_cyber
)