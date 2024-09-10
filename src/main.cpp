#include "Benchmark/Benchmark.hpp"
#include "Benchmark/Dispatch.hpp"
#include "Global.h" // Contains macros for executeBenchmark template parameters
#include <iostream>


GroupInfo parseArgs(int argc, char** argv)
{
    GroupInfo out;
    for (int i=1; i < argc; ++i)
    {
        std::string arg(argv[i]);
        if (arg == "--group")
        {
            if (i+1 >= argc)         continue;
            if (argv[i+1][0] == '-') continue;
            out.group = std::string(argv[i+1]);
            *argv[i+0] = '\x00';
            *argv[i+1] = '\x00';
            ++i;
        }
        else if (arg == "--Nc")
        {
            if (i+1 >= argc)         continue;
            if (argv[i+1][0] == '-') continue;
            try
            {
                out.Nc = std::stoi(std::string(argv[i+1]));
            }
            catch(const std::runtime_error& error)
            {
                std::cout << "'--Nc' argument cannot be interpreted as an integer: " << argv[i+1] << std::endl;
            }
            *argv[i+0] = '\x00';
            *argv[i+1] = '\x00';
            ++i;
        }
        else if (arg == "--representation")
        {
            if (i+1 >= argc)         continue;
            if (argv[i+1][0] == '-') continue;
            out.representation = std::string(argv[i+1]);
            *argv[i+0] = '\x00';
            *argv[i+1] = '\x00';
            ++i;
        }
    }
    return out;
}


int main(int argc, char** argv)
{
    GroupInfo group_info = parseArgs(argc, argv);
    initGrid(argc, argv);
    executeBenchmark(group_info);
    teardownGrid();
    return 0;
}
