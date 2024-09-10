#include "SU2Adj.hpp"
#include <stdlib.h>
#include <iostream>
#include "../Benchmark.hpp"


void executeBenchmarkSU3Fundamental()
{
    #ifdef BKEEPER_SU3FUND
    executeBenchmark<Grid::GroupName::SU, 3, RepresentationName::Fundamental>();
    #else
    std::cout << "BKeeper was not compiled for SU(3), Fundamental" << std::endl;
    exit(0);
    #endif
}
