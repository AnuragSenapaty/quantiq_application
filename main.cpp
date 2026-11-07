//
// Created by Anurag S on 11/7/26.
//
#pragma once
#include "tests/timer_test.hpp"
#include "tests/correctness_test.hpp"

int main()
{
    // timer failed
    if (not timer_test()) return 1;
    if (not correctness_test()) return 1;
    return 0;
}