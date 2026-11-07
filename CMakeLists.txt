cmake_minimum_required(VERSION 4.3)
project(Quantiq)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(TBB REQUIRED)

add_executable(Quantiq
        helper_code/timer.hpp
        main.cpp
        tests/timer_test.hpp
        helper_code/correctness.hpp
        tests/correctness_test.hpp
        application_code/default.hpp)

target_link_libraries(Quantiq PRIVATE TBB::tbb)
target_compile_options(Quantiq PRIVATE -fexperimental-library)