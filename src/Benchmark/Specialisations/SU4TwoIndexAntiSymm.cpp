#include "SU2Adj.hpp"
#include <stdlib.h>
#include <iostream>
#include "../Benchmark.hpp"


void executeBenchmarkSU4TwoIndexAntiSymmetric()
{
    #ifdef BKEEPER_SU4TIAS
    executeBenchmark<Grid::GroupName::SU, 4, RepresentationName::TwoIndexAntiSymmetric>();
    #else
    std::cout << "BKeeper was not compiled for SU(4), TwoIndexAntiSymmetric" << std::endl;
    exit(0);
    #endif
}
