file(GLOB_RECURSE ALL_MAINBOARD_FILES "*.*")

edith_binary(mainboard
  SRCS
    ${ALL_MAINBOARD_FILES}
  LIBS
    edith_cyber
)