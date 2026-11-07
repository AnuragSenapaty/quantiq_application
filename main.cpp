//
// Created by Anurag S on 11/7/26.
//
#pragma once
#include "timer_test.hpp"
int main()
{
    // timer failed
    if (not timer_test()) return 1;
    return 0;
}