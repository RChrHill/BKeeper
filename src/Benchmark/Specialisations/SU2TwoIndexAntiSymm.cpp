#include "SU2Adj.hpp"
#include <stdlib.h>
#include <iostream>
#include "../Benchmark.hpp"


void executeBenchmarkSU2TwoIndexAntiSymmetric(BKeeperParameters& params)
{
    #ifdef BKEEPER_SU2TIAS
    executeBenchmark<Grid::GroupName::SU, 2, RepresentationName::TwoIndexAntiSymmetric>(params);
    #else
    std::cout << "BKeeper was not compiled for SU(2), TwoIndexAntiSymmetric" << std::endl;
    exit(0);
    #endif
}
