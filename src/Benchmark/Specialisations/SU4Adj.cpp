#include "SU2Adj.hpp"
#include <stdlib.h>
#include <iostream>
#include "../Benchmark.hpp"


void executeBenchmarkSU4Adjoint()
{
    #ifdef BKEEPER_SU4ADJ
    executeBenchmark<Grid::GroupName::SU, 4, RepresentationName::Adjoint>();
    #else
    std::cout << "BKeeper was not compiled for SU(4), Adjoint" << std::endl;
    exit(0);
    #endif
}
