#include "SU2Adj.hpp"
#include <stdlib.h>
#include <iostream>
#include "../Benchmark.hpp"


void executeBenchmarkSU4TwoIndexSymmetric()
{
    #ifdef BKEEPER_SU4TIS
    executeBenchmark<Grid::GroupName::SU, 4, RepresentationName::TwoIndexSymmetric>();
    #else
    std::cout << "BKeeper was not compiled for SU(4), TwoIndexSymmetric" << std::endl;
    exit(0);
    #endif
}
