#!/usr/bin/env bash

PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd )"

pushd ${PROJECT_ROOT}/build/cyber/py_wrapper

ln -s lib_py_wrapper_py_cyber.so _cyber.so
ln -s lib_py_wrapper_py_time.so _cyber_time.so
ln -s lib_py_wrapper_py_timer.so _cyber_timer.so
ln -s lib_py_wrapper_py_record.so _cyber_record.so
ln -s lib_py_wrapper_py_parameter.so _cyber_parameter.so

ln -s lib_py_wrapper_py3_cyber.so _cyber_py3.so
ln -s lib_py_wrapper_py3_time.so _cyber_time_py3.so
ln -s lib_py_wrapper_py3_timer.so _cyber_timer_py3.so
ln -s lib_py_wrapper_py3_record.so _cyber_record_py3.so
ln -s lib_py_wrapper_py3_parameter.so _cyber_parameter_py3.so

popd