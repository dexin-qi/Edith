
### auto generate from bazel test : _base_atomic_hash_map_test ###
dustin_var_append(ATOMIC_HASH_MAP_TEST_FILES /edith/cyber/base/atomic_hash_map.h)
dustin_var_append(ATOMIC_HASH_MAP_TEST_FILES /edith/cyber/base/atomic_hash_map_test.cc)

edith_test(_base_atomic_hash_map_test
SRCS
  ${ATOMIC_HASH_MAP_TEST_FILES}
)

### auto generate from bazel test : _base_atomic_rw_lock_test ###
dustin_var_append(ATOMIC_RW_LOCK_TEST_FILES /edith/cyber/base/rw_lock_guard.h)
dustin_var_append(ATOMIC_RW_LOCK_TEST_FILES /edith/cyber/base/atomic_rw_lock.h)
dustin_var_append(ATOMIC_RW_LOCK_TEST_FILES /edith/cyber/base/atomic_rw_lock_test.cc)
dustin_var_append(ATOMIC_RW_LOCK_TEST_FILES /edith/cyber/base/reentrant_rw_lock.h)

edith_test(_base_atomic_rw_lock_test
SRCS
  ${ATOMIC_RW_LOCK_TEST_FILES}
)

### auto generate from bazel test : _base_bounded_queue_test ###
dustin_var_append(BOUNDED_QUEUE_TEST_FILES /edith/cyber/base/macros.h)
dustin_var_append(BOUNDED_QUEUE_TEST_FILES /edith/cyber/base/bounded_queue.h)
dustin_var_append(BOUNDED_QUEUE_TEST_FILES /edith/cyber/base/bounded_queue_test.cc)
dustin_var_append(BOUNDED_QUEUE_TEST_FILES /edith/cyber/base/wait_strategy.h)

edith_test(_base_bounded_queue_test
SRCS
  ${BOUNDED_QUEUE_TEST_FILES}
)

### auto generate from bazel test : _base_for_each_test ###
dustin_var_append(FOR_EACH_TEST_FILES /edith/cyber/base/macros.h)
dustin_var_append(FOR_EACH_TEST_FILES /edith/cyber/base/for_each.h)
dustin_var_append(FOR_EACH_TEST_FILES /edith/cyber/base/for_each_test.cc)

edith_test(_base_for_each_test
SRCS
  ${FOR_EACH_TEST_FILES}
)

### auto generate from bazel test : _base_object_pool_test ###
dustin_var_append(OBJECT_POOL_TEST_FILES /edith/cyber/base/for_each.h)
dustin_var_append(OBJECT_POOL_TEST_FILES /edith/cyber/base/concurrent_object_pool.h)
dustin_var_append(OBJECT_POOL_TEST_FILES /edith/cyber/base/object_pool.h)
dustin_var_append(OBJECT_POOL_TEST_FILES /edith/cyber/base/object_pool_test.cc)
dustin_var_append(OBJECT_POOL_TEST_FILES /edith/cyber/base/macros.h)

edith_test(_base_object_pool_test
SRCS
  ${OBJECT_POOL_TEST_FILES}
)
target_link_libraries(_base_object_pool_test -latomic)

### auto generate from bazel test : _base_signal_test ###
dustin_var_append(SIGNAL_TEST_FILES /edith/cyber/base/signal_test.cc)
dustin_var_append(SIGNAL_TEST_FILES /edith/cyber/base/signal.h)

edith_test(_base_signal_test
SRCS
  ${SIGNAL_TEST_FILES}
)

### auto generate from bazel test : _base_unbounded_queue_test ###
dustin_var_append(UNBOUNDED_QUEUE_TEST_FILES /edith/cyber/base/unbounded_queue.h)
dustin_var_append(UNBOUNDED_QUEUE_TEST_FILES /edith/cyber/base/unbounded_queue_test.cc)

edith_test(_base_unbounded_queue_test
SRCS
  ${UNBOUNDED_QUEUE_TEST_FILES}
)
