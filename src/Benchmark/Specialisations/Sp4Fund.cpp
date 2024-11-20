#include "SU2Adj.hpp"
#include <stdlib.h>
#include <iostream>
#include "../Benchmark.hpp"


void executeBenchmarkSp4Fundamental(BKeeperParameters& params)
{
    #ifdef BKEEPER_Sp4FUND
    executeBenchmark<Grid::GroupName::Sp, 4, RepresentationName::Fundamental>(params);
    #else
    std::cout << "BKeeper was not compiled for Sp(4), Fundamental" << std::endl;
    exit(0);
    #endif
}
