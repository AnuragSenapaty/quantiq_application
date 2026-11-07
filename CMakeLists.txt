cmake_minimum_required(VERSION 4.3)
project(Quantiq)

set(CMAKE_CXX_STANDARD 26)

add_executable(Quantiq
        code/timer.hpp
        main.cpp
        tests/timer_test.hpp
        code/correctness.hpp
        tests/correctness_test.hpp)
