#include "SU2Adj.hpp"
#include <stdlib.h>
#include <iostream>
#include "../Benchmark.hpp"


void executeBenchmarkSU2Adjoint(BKeeperParameters& params)
{
    #ifdef BKEEPER_SU2ADJ
    executeBenchmark<Grid::GroupName::SU, 2, RepresentationName::Adjoint>(params);
    #else
    std::cout << "BKeeper was not compiled for SU(2), Adjoint" << std::endl;
    exit(0);
    #endif
}
