cmake_minimum_required(VERSION 4.3)
project(Quantiq)

set(CMAKE_CXX_STANDARD 26)

add_executable(Quantiq
        timer.hpp
        main.cpp
        timer_test.hpp)
