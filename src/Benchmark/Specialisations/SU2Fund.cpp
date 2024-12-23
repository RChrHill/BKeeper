#include "SU2Adj.hpp"
#include <stdlib.h>
#include <iostream>
#include "../Benchmark.hpp"


void executeBenchmarkSU2Fundamental(BKeeperParameters& params)
{
    #ifdef BKEEPER_SU2FUND
    executeBenchmark<Grid::GroupName::SU, 2, RepresentationName::Fundamental>(params);
    #else
    std::cout << "BKeeper was not compiled for SU(2), Fundamental" << std::endl;
    exit(0);
    #endif
}
