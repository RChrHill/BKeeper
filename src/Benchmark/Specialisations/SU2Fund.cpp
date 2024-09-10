#include "SU2Adj.hpp"
#include <stdlib.h>
#include <iostream>
#include "../Benchmark.hpp"


void executeBenchmarkSU2Fundamental()
{
    #ifdef BKEEPER_SU2FUND
    executeBenchmark<Grid::GroupName::SU, 2, RepresentationName::Fundamental>();
    #else
    std::cout << "BKeeper was not compiled for SU(2), Fundamental" << std::endl;
    exit(0);
    #endif
}
