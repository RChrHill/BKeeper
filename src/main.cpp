#include "Benchmark.hpp"


int main(int argc, char** argv)
{
    initGrid();
    executeBenchmark<Grid::GroupName::SU, 3, RepresentationName::Fundamental>();
    teardownGrid();
    return 0;
}
