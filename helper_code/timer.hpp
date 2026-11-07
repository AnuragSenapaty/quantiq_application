//
// Created by Anurag S on 11/7/26.
//

// Based off of https://cppscripts.com/cpp-timer
#pragma once
#include <chrono>
#include <iostream>

// Templated
template <class F>

// very simple benchmark
double timer(F&& func, int runs = 100)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < runs; ++i) func();

    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration<double, std::milli>(end - start).count() / runs;
}