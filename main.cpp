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

    // Starting to test solutions for speed and correctness
    std::cout << '\n'<< "Solution benchmarks" << std::endl;

    std::cout << "\nSolution 1 - Default first attempt with helpers like reverse" << std::endl;
    solution1("../files/input.txt", "../files/file_out1.txt");
    std::cout << "File correctness - " << compareFiles("../files/output.txt", "../files/file_out1.txt") << std::endl;
    std::cout << "Time benchmark - " << timer([]{ solution1("../files/inputL.txt", "../files/file_out1.txt");}, 1000) << std::endl;


    std::cout << "\nSolution 2 - Removed algorithms, tried to transfer chars one by one" << std::endl;
    std::cout << "This was slower, dues to the multitude << calls, so still using a string" << std::endl;
    std::cout << "to concat, decent speedup" << std::endl;
    const char *path = "../files/inputL.txt";
    const char *pathT = "../files/input.txt";
    const char *output = "../files/file_out2.txt";
    solution2(pathT,output);
    std::cout << "File correctness - " << compareFiles("../files/output.txt", "../files/file_out2.txt") << std::endl;
    std::cout << "Time benchmark - " << timer([path, output]{ solution2(path,output);}, 1000) << std::endl;


    std::cout << "\nSolution 3 - Going back to using algorithm + manual new line no flushing with endl" << std::endl;
    std::cout << "Profiling allowed me to see that solution 2 speedups were just from replacing std::endl" << std::endl;
    output = "../files/file_out3.txt";
    solution3(pathT,output);
    std::cout << "File correctness - " << compareFiles("../files/output.txt", "../files/file_out3.txt") << std::endl;
    std::cout << "Time benchmark - " << timer([path, output]{ solution3(path,output);}, 1000) << std::endl;

    std::cout << "\nSolution 4 - Reducing oStream writes and using a string as a buffer, then writing at the end" << std::endl;
    std::cout << "Profiling allowed me to see that ostream calls were the next issue to solve" << std::endl;
    output = "../files/file_out4.txt";
    solution4(pathT,output);
    std::cout << "File correctness - " << compareFiles("../files/output.txt", "../files/file_out4.txt") << std::endl;
    std::cout << "Time benchmark - " << timer([path, output]{ solution4(path,output);}, 1000) << std::endl;

    std::cout << "\nSolution 5 - Using multi threading to try and speed up further" << std::endl;
    std::cout << "It seems that the calls to make new threads add more overhead than speed up, unfortunately" << std::endl;
    std::cout << "Solution 4 seems most optimal" << std::endl;
    output = "../files/file_out5.txt";
    solution5(pathT,output);
    std::cout << "File correctness - " << compareFiles("../files/output.txt", "../files/file_out5.txt") << std::endl;
    std::cout << "Time benchmark - " << timer([path, output]{ solution5(path,output);}, 1000) << std::endl;

    std::cout << "\nSolution 6 - Switching from if and of stream to stdio" << std::endl;
    std::cout << "Googled around and found out that stdio was much quicker than iostream so I switched" << std::endl;
    std::cout << "I have never used stdio before so there was a massive learning curve, but after that" << std::endl;
    std::cout << "the code was much, much faster, this is the final optimized code" << std::endl;
    output = "../files/file_out6.txt";
    solution6(pathT,output);
    std::cout << "File correctness - " << compareFiles("../files/output.txt", "../files/file_out6.txt") << std::endl;
    std::cout << "Time benchmark - " << timer([path, output]{ solution6(path,output);}, 1000) << std::endl;
}