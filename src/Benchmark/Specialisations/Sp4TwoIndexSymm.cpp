#include "SU2Adj.hpp"
#include <stdlib.h>
#include <iostream>
#include "../Benchmark.hpp"


void executeBenchmarkSp4TwoIndexSymmetric(BKeeperParameters& params)
{
    #if defined(BKEEPER_Sp4TIS) || defined(BKEEPER_Sp4ADJ)
    executeBenchmark<Grid::GroupName::Sp, 4, RepresentationName::TwoIndexSymmetric>(params);
    #else
    std::cout << "BKeeper was not compiled for Sp(4), TwoIndexSymmetric" << std::endl;
    exit(0);
    #endif
}
