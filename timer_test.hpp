//
// Created by Anurag S on 11/7/26.
//
#pragma once
#include "timer.hpp"
#include <vector>

int fib_uo(int x)
{
    if (x == 1 or x == 2) return 1;
    return fib_uo(x-1)+fib_uo(x-2);
}
int fib(int x)
{
    // base
    if (x== 0) return 0;
    if (x == 1 || x == 2) return 1;

    // Sub optimal, but i need it to take time
    // storing just 2 and alternating, x = x+y and y = x+y would be too quick
    std::vector<int> fib (x+1, 1);
    for (int i = 2; i <= x; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[x];
}

int fib_o(int x)
{
    // base
    if (x== 0) return 0;
    if (x == 1 || x == 2) return 1;

    int a = 1;
    int b = 1;
    bool flag = false;
    for (int i = 2; i <= x; i++) {
        if (not flag) b = b + a;
        else a = a + b;
        flag = not flag;
    }

    if (flag) return b;
    return a;

}

void timer_test()
{
    double time = timer([]{ fib(30); }, 100);
    std::cout << time << std::endl;

    time = timer([]{ fib_o(30); }, 100);
    std::cout << time << std::endl;

    time = timer([]{ fib_uo(30); }, 100);
    std::cout << time << std::endl;
}