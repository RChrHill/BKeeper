#include "SU2Adj.hpp"
#include <stdlib.h>
#include <iostream>
#include "../Benchmark.hpp"


void executeBenchmarkSU4Fundamental(BKeeperParameters& params)
{
    #ifdef BKEEPER_SU4FUND
    executeBenchmark<Grid::GroupName::SU, 4, RepresentationName::Fundamental>(params);
    #else
    std::cout << "BKeeper was not compiled for SU(4), Fundamental" << std::endl;
    exit(0);
    #endif
}
