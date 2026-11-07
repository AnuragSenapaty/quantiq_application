//
// Created by Anurag S on 11/7/26.
//

// This is a blind, first attempt
#pragma once
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <tbb/tbb.h>
#include <cstdio>
#include <cstring>

inline void solution1(std::string path, std::string outPath)
{
    std::ifstream input(path);
    std::string s;
    std::ofstream output(outPath);

    while (std::getline(input, s))
    {
        std::reverse(s.begin(), s.end());
        output << s << std::endl;
    }

    input.close();
    output.close();
}

inline void solution2(const char* path, const char* outPath)
{
    std::ifstream input(path);
    std::string s;
    std::ofstream output(outPath);

    while (std::getline(input, s))
    {
        std::string rev;
        for (std::size_t i = s.size(); i > 0; --i) {
            rev.push_back(s[i - 1]);
        }
        output << rev << '\n';
    }

    input.close();
    output.close();
}

inline void solution3(const char* path, const char* outPath)
{
    std::ifstream input(path);
    std::string s;
    std::ofstream output(outPath);

    while (std::getline(input, s))
    {
        std::reverse(s.begin(), s.end());
        output << s << '\n';
    }

    input.close();
    output.close();
}

inline void solution4(const char* path, const char* outPath)
{
    std::ifstream input(path);
    std::string s;
    std::string out;
    std::ofstream output(outPath);

    while (std::getline(input, s))
    {
        std::reverse(s.begin(), s.end());
        out.append(s);
        out.push_back('\n');
    }
    output << out;

    input.close();
    output.close();
}

inline void solution5(const char* path, const char* outPath) {
    std::ifstream input(path);
    std::vector<std::string> lines;
    std::string s;

    while (std::getline(input, s)) lines.push_back(s);

    tbb::parallel_for_each(lines.begin(), lines.end(),[](std::string& line)
    {std::reverse(line.begin(), line.end());});

    std::string out;
    std::ofstream output(outPath);
    for (const auto& line : lines)
    {
        out.append(line);
        out.push_back('\n');
    }
    output << out;

    input.close();
    output.close();
}

inline void solution6(const char* path, const char* outPath)
{
    constexpr std::size_t max_len = 65535;
    char buf[max_len];

    std::freopen(path, "r", stdin);
    std::string out;

    while (std::fgets(buf, sizeof(buf), stdin))
    {
        std::size_t len = std::strlen(buf);
        if (len && buf[len - 1] == '\n') --len;
        std::reverse(buf, buf + len);
        out.append(buf, len);
        out.push_back('\n');
    }

    FILE* output = std::fopen(outPath, "w");

    std::fwrite(out.data(), 1, out.size(), output);
    std::fclose(output);
}