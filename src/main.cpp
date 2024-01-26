#include "Benchmark.hpp"


int main(int argc, char** argv)
{
    initGrid();
    executeBenchmark<::GroupName::SU, 3, RepresentationName::Fundamental>();
    teardownGrid();
    return 0;
}
