#include "SU2Adj.hpp"
#include <stdlib.h>
#include <iostream>
#include "../Benchmark.hpp"


void executeBenchmarkSp4TwoIndexAntiSymmetric(BKeeperParameters& params)
{
    #ifdef BKEEPER_Sp4TIAS
    executeBenchmark<Grid::GroupName::Sp, 4, RepresentationName::TwoIndexAntiSymmetric>(params);
    #else
    std::cout << "BKeeper was not compiled for Sp(4), TwoIndexAntiSymmetric" << std::endl;
    exit(0);
    #endif
}
