//
// Created by Anurag S on 11/7/26.
//
#pragma once
#include "tests/timer_test.hpp"
#include "tests/correctness_test.hpp"

#include "application_code/default.hpp"

int main()
{
    // testing helper functions
    if (not timer_test()) return 1;
    if (not correctness_test()) return 1;

    std::cout << '\n'<< "Solution benchmarks" << std::endl;
    std::cout << "\nSolution 1 - default file" << std::endl;
    std::cout << "Time benchmark - " << timer([]{ solution1("../files/input.txt");}, 100) << std::endl;
    std::cout << "File correctness - " << compareFiles("../files/output.txt", "../files/default_out.txt") << std::endl;

    return 0;
}