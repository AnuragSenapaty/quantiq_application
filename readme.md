The problem statement was simple:

Application Requirement: Write a program in C++ that takes in a file as input, reverses every line, and puts it in a different file. Try to do this with as little memory footprint as possible and as fast as possible. Attach the file as a .txt below.*

Realistically, it would have been simple to just make an optimized piece of code and call it a day, but the process of optimization is just as important as the end result, so I wanted to walk you through the thought process I employed.

First, I started off by creating a simple timer and file equivalence function to make sure everything worked. I took one from a cppreference site and the other from Stack Overflow, with the correct attributions in helper_code. I also made very simple tests.

Then I used Claude to generate a few files and their reverses for use in testing my software.

*AI was used here*

Then I started actually working on the solution.

Solution benchmarks

Solution 1 - Default first attempt with helpers like reverse

Very simple: read each line, stored it in a string, reversed that string, and stored that in the file.

Time benchmark - 3.48597 ms

Solution 2 - Removed algorithms, tried to transfer chars one by one

This was slower due to the multitude of << ofstream calls, so I was still using a string to concat the chars instead of individually storing them into a file. It looks like a very good speedup on the surface from replacing algorithm, but thats not the case

Time benchmark - 0.396538 ms

Solution 3 - Going back to using algorithm + manual new line, no flushing the buffer with endl

Profiling allowed me to see that Solution 2’s speedups were just from replacing std::endl, since those were a massive chunk of the runtime. Replacing algorithms likely only played a tiny part in the previous speedup.

Time benchmark - 0.280269 ms

Solution 4 - Reducing ostream writes and using a string as a buffer, then writing at the end

Profiling allowed me to see that ostream calls were the next issue to solve, so I just concatenated the lines into one string and then printed that string. With very large files, this might end up being an issue.

Time benchmark - 0.181761 ms

Solution 5 - Using multithreading to try and speed up further

It seems that the calls to make new threads add more overhead than speedup, unfortunately. Solution 4 seems most optimal.

Time benchmark - 0.250387 ms

Solution 6 - Switching from ifstream and ofstream to stdio

Googled around and found out that stdio was much quicker than iostream, so I switched.

I have never used stdio before, so there was a massive learning curve, but after that the code was much, much faster. This is the final optimized code.

Time benchmark - 0.164712 ms

Final code

c++ -

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

Caveats: This only works on smaller to larger files, not huge ones. The testing file was a text file of the Bee Movie script, but no limitations were specified on file size support, so I chose to pursue maximum speed.