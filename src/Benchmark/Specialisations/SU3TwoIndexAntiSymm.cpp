#include "SU2Adj.hpp"
#include <stdlib.h>
#include <iostream>
#include "../Benchmark.hpp"


void executeBenchmarkSU3TwoIndexAntiSymmetric(BKeeperParameters& params)
{
    #ifdef BKEEPER_SU3TIAS
    executeBenchmark<Grid::GroupName::SU, 3, RepresentationName::TwoIndexAntiSymmetric>(params);
    #else
    std::cout << "BKeeper was not compiled for SU(3), TwoIndexAntiSymmetric" << std::endl;
    exit(0);
    #endif
}
