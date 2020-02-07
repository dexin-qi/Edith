message(STATUS "Python2: ${PYTHON2_INCLUDE_DIR}")
message(STATUS "Python2: ${PYTHON2_LIBRARIES}")
message(STATUS "Python3: ${PYTHON3_INCLUDE_DIR}")
message(STATUS "Python3: ${PYTHON3_LIBRARIES}")

_py2_library(_cyber "py_cyber.h;py_cyber.cc" edith_cyber)
_py3_library(_cyber_py3 "py_cyber.h;py_cyber.cc" edith_cyber)

_py2_library(_cyber_record "py_record.h;py_record.cc" edith_cyber)
_py3_library(_cyber_record_py3 "py_record.h;py_record.cc" edith_cyber)

_py2_library(_cyber_time "py_time.h;py_time.cc" edith_cyber)
_py3_library(_cyber_time_py3 "py_time.h;py_time.cc" edith_cyber)

_py2_library(_cyber_timer "py_timer.h;py_timer.cc" edith_cyber)
_py3_library(_cyber_timer_py3 "py_timer.h;py_timer.cc" edith_cyber)

_py2_library(_cyber_parameter "py_parameter.h;py_parameter.cc" edith_cyber)
_py3_library(_cyber_parameter_py3 "py_parameter.h;py_parameter.cc" edith_cyber)

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
