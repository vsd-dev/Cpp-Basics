#!/bin/bash
set -e
make clean
make install
source setup.bash cpp_thread_callback
python3 src/pybind/cpp_thread_callback/tick_test.py