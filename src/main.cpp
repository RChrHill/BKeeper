#include "Benchmark/Benchmark.hpp"
#include "Benchmark/Dispatch.hpp"
#include "Global.h" // Contains macros for executeBenchmark template parameters
#include <iostream>


std::vector<GroupInfo> parseArgs(int argc, char** argv)
{
    std::vector<GroupInfo> out;
    for (int i=1; i < argc; ++i)
    {
        std::string arg(argv[i]);
        if (arg == "--benchmarks")
        {
            if (i+1 >= argc)         continue;
            if (argv[i+1][0] == '-') continue;

            std::string groups = std::string(argv[i+1]);
            size_t pos = 0;
            std::string group;
            while (true) 
            {
                pos = groups.find(",");
                group = groups.substr(0, pos);
                groups.erase(0, pos + 1);

                // SU2
                if (group=="su2fund")
                    out.push_back(SU2FundamentalGroupInfo);
                else if (group=="su2adj")
                    out.push_back(SU2AdjointGroupInfo);
                else if (group=="su2tis")
                    out.push_back(SU2TwoIndexSymmetricGroupInfo);
                else if (group=="su2tias")
                    out.push_back(SU2TwoIndexAntiSymmetricGroupInfo);
                // SU3
                else if (group=="su3fund")
                    out.push_back(SU3FundamentalGroupInfo);
                else if (group=="su3adj")
                    out.push_back(SU3AdjointGroupInfo);
                else if (group=="su3tis")
                    out.push_back(SU3TwoIndexSymmetricGroupInfo);
                else if (group=="su3tias")
                    out.push_back(SU3TwoIndexAntiSymmetricGroupInfo);
                // SU4
                else if (group=="su4fund")
                    out.push_back(SU4FundamentalGroupInfo);
                else if (group=="su4adj")
                    out.push_back(SU4AdjointGroupInfo);
                else if (group=="su4tis")
                    out.push_back(SU4TwoIndexSymmetricGroupInfo);
                else if (group=="su4tias")
                    out.push_back(SU4TwoIndexAntiSymmetricGroupInfo);
                // Sp4
                else if (group=="sp4fund")
                    out.push_back(Sp4FundamentalGroupInfo);
                else if (group=="sp4tis")
                    out.push_back(Sp4TwoIndexSymmetricGroupInfo);
                else if (group=="sp4tias")
                    out.push_back(Sp4TwoIndexAntiSymmetricGroupInfo);
                else
                    std::cout << "Did not recognise benchmark '" << group << "', skipping...\n";

                if (pos == std::string::npos)
                    break;
            }
            
            *argv[i+0] = '\x00';
            *argv[i+1] = '\x00';
            ++i;
        }
    }
    return out;
}


int main(int argc, char** argv)
{
    auto group_infos = parseArgs(argc, argv);
    initGrid(argc, argv);

    for (const auto& group_info : group_infos)
    {
        std::string msg = "# Performing benchmark for " + group_info.tag() + " #";

        std::string first_line = "";
        for (int i=0; i < msg.size(); ++i)
            first_line += "#";

        std::cout << GridLogMessage << first_line << std::endl;
        std::cout << GridLogMessage << msg        << std::endl;
        std::cout << GridLogMessage << first_line << std::endl;
        executeBenchmark(group_info);
    }
    teardownGrid();
    return 0;
}
