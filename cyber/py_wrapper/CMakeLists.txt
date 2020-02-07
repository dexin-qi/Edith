message(STATUS "Python2: ${PYTHON2_INCLUDE_DIR}")
message(STATUS "Python2: ${PYTHON2_LIBRARIES}")
message(STATUS "Python3: ${PYTHON3_INCLUDE_DIR}")
message(STATUS "Python3: ${PYTHON3_LIBRARIES}")

# Python2 Interface
_py2_library(_cyber 
    SRCS 
        "py_cyber.h;py_cyber.cc" 
    LIBS
        edith_cyber
)

_py2_library(_cyber_record 
    SRCS 
        "py_record.h;py_record.cc" 
    LIBS 
        edith_cyber
)


_py2_library(_cyber_time 
    SRCS 
        "py_time.h;py_time.cc" 
    LIBS 
        edith_cyber
)


_py2_library(_cyber_timer 
    SRCS 
        "py_timer.h;py_timer.cc" 
    LIBS 
        edith_cyber
)


_py2_library(_cyber_parameter 
    SRCS 
        "py_parameter.h;py_parameter.cc" 
    LIBS 
        edith_cyber
)

# Python3 Interface
_py3_library(_cyber_py3 
    SRCS
        "py_cyber.h;py_cyber.cc"
    LIBS
        edith_cyber
)

_py3_library(_cyber_record_py3 
    SRCS 
        "py_record.h;py_record.cc" 
    LIBS 
        edith_cyber
)

_py3_library(_cyber_time_py3 
    SRCS 
        "py_time.h;py_time.cc" 
    LIBS 
        edith_cyber
)

_py3_library(_cyber_timer_py3 
    SRCS 
        "py_timer.h;py_timer.cc" 
    LIBS 
        edith_cyber
)

_py3_library(_cyber_parameter_py3 
    SRCS 
        "py_parameter.h;py_parameter.cc" 
    LIBS 
        edith_cyber
)

# Tests
edith_test("cyber.py_wrapper.py_cyber_test"
    SRCS 
        py_cyber_test.cc
    LIBS 
        _cyber_py3
)

edith_test("cyber.py_wrapper.py_record_test"
    SRCS 
        py_record_test.cc
    LIBS 
        _cyber_record
)
