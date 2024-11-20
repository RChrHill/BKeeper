#include "Benchmark/Benchmark.hpp"
#include "Benchmark/Dispatch.hpp"
#include "Global.h" // Contains macros for executeBenchmark template parameters
#include <iostream>
#include "Parameters/Parameters.hpp"
#include "Logger/BKeeperLog.hpp"


std::vector<GroupInfo> produceBenchmarkSchedule(const std::vector<std::string>& benchmarks)
{
    std::vector<GroupInfo> out;
    for (const std::string& group : benchmarks)
    {
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
            std::cout << BKeeperLogMessage << "Did not recognise benchmark '" << group << "', skipping...\n";
    }

    return out;
}


int main(int argc, char** argv)
{    
    std::string parameterFileName;
    if (argc < 2)
    {
        std::cerr << "usage: " << argv[0] << " <parameter file> [Grid options]";
        std::cerr << std::endl;
        std::exit(EXIT_FAILURE);
    }
    parameterFileName = argv[1];

    BKeeperParameters params = readParameterFile(parameterFileName);
    auto group_infos = produceBenchmarkSchedule(params.benchmarks);
    BKeeper::initLogger();

    if (group_infos.empty())
        std::cout << BKeeperLogMessage << "WARNING: NO RECOGNISED BENCHMARKS IN PARAMETERS FILE. EXITING..." << std::endl;
    else
    {
        initGrid(argc, argv);

        {
            std::string msg = "# Setting up BKeeper with " + std::to_string(params.iterations) + " iterations and m=" + std::to_string(params.mass) + " #";
            std::string borderline = "";
            for (int i=0; i < msg.size(); ++i)
                borderline += "#";

            std::cout << BKeeperLogMessage << borderline << std::endl;
            std::cout << BKeeperLogMessage << msg        << std::endl;
            std::cout << BKeeperLogMessage << borderline << std::endl;
        }

        for (const auto& group_info : group_infos)
        {
            std::string msg = "# Performing benchmark for " + group_info.tag() + " #";

            std::string borderline = "";
            for (int i=0; i < msg.size(); ++i)
                borderline += "#";

            std::cout << BKeeperLogMessage << borderline << std::endl;
            std::cout << BKeeperLogMessage << msg        << std::endl;
            std::cout << BKeeperLogMessage << borderline << std::endl;
            executeBenchmark(group_info, params);
        }
        teardownGrid();
    }

    return 0;
}
