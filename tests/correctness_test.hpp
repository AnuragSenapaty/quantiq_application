//
// Created by Anurag S on 11/7/26.
//

#pragma once
#include "../code/correctness.hpp"

bool correctness_test() {
    if (compareFiles("../files/tester1.txt", "../files/tester2.txt"))
    {
        std::cout << "File comparer works" << std::endl;
        return true;
    }
    std::cout << "File comparer does not work" << std::endl;
    return false;
}