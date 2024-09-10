#include "Benchmark.hpp"


void initGrid(int argc, char** argv)
{
    using namespace Grid;

    Grid_init(&argc, &argv);

    std::cout << GridLogMessage << "Lattice dimensions: " << GridDefaultLatt() << std::endl;
    std::cout << GridLogMessage << "MPI decomposition:  " << GridDefaultMpi() << std::endl;

}


Grid::GridCartesian createGrid()
{
  using namespace Grid;

  std::cout << GridLogMessage << "Creating Lattice..." << std::endl;

  Coordinate latt_size   = GridDefaultLatt();
  Coordinate simd_layout = GridDefaultSimd(Nd,vComplex::Nsimd());
  Coordinate mpi_layout  = GridDefaultMpi();
  auto grid = GridCartesian(latt_size,simd_layout,mpi_layout);
  std::cout << GridLogMessage << "Created Grid:" << std::endl;
  grid.show_decomposition();
  return grid;
}


void teardownGrid()
{
    using namespace Grid;

    Grid_finalize();
}
