#include "SU2Adj.hpp"
#include <stdlib.h>
#include <iostream>
#include "../Benchmark.hpp"


void executeBenchmarkSU3Adjoint()
{
    #ifdef BKEEPER_SU3ADJ
    executeBenchmark<Grid::GroupName::SU, 3, RepresentationName::Adjoint>();
    #else
    std::cout << "BKeeper was not compiled for SU(3), Adjoint" << std::endl;
    exit(0);
    #endif
}
