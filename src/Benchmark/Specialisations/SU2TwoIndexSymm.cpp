#include "SU2Adj.hpp"
#include <stdlib.h>
#include <iostream>
#include "../Benchmark.hpp"


void executeBenchmarkSU2TwoIndexSymmetric()
{
    #ifdef BKEEPER_SU2TIS
    executeBenchmark<Grid::GroupName::SU, 2, RepresentationName::TwoIndexSymmetric>();
    #else
    std::cout << "BKeeper was not compiled for SU(2), TwoIndexSymmetric" << std::endl;
    exit(0);
    #endif
}