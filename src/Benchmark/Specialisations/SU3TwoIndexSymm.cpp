#include "SU2Adj.hpp"
#include <stdlib.h>
#include <iostream>
#include "../Benchmark.hpp"


void executeBenchmarkSU3TwoIndexSymmetric()
{
    #ifdef BKEEPER_SU3TIS
    executeBenchmark<Grid::GroupName::SU, 3, RepresentationName::TwoIndexSymmetric>();
    #else
    std::cout << "BKeeper was not compiled for SU(3), TwoIndexSymmetric" << std::endl;
    exit(0);
    #endif
}
