//
// Created by Anurag S on 11/7/26.
//

// This is a blind, first attempt
#pragma once
#include <string>
#include <fstream>
#include <algorithm>

void solution1(std::string path)
{
    std::ifstream input(path);
    std::string s;
    std::ofstream output("../files/default_out.txt");

    while (std::getline(input, s))
    {
        std::reverse(s.begin(), s.end());
        output << s << std::endl;
    }

    input.close();
    output.close();
}
