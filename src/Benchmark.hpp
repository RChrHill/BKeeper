#pragma once

#include <memory>
#include <Grid/Grid.h>
#include "FixedIterCG.hpp"
#include "PerformanceMetrics/Flops.hpp"
#include "PerformanceMetrics/Comms.hpp"
#include "PerformanceMetrics/Memory.hpp"


enum class RepresentationName
{
  Fundamental,
  Adjoint,
  TwoIndexSymmetric,
  TwoIndexAntiSymmetric
};


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


template<typename Representation, typename ConfigGroup>
auto generateUnitGauge(Grid::GridCartesian& grid, const std::vector<int>& seed)
{
  using namespace Grid;

  std::cout << GridLogMessage << "Creating gauge..." << std::endl;

  GridParallelRNG rng(&grid);
  rng.SeedFixedIntegers(seed);
  typename Representation::LatticeField gaugefield(&grid);
  ConfigGroup::ColdConfiguration(rng, gaugefield);
  return gaugefield;
}


template<typename Representation>
auto generateFermionAction(Grid::GridCartesian& grid, Grid::GridRedBlackCartesian& rbgrid, typename Representation::LatticeField& gaugefield, Grid::RealD mass)
{
  using namespace Grid;
  std::cout << GridLogMessage << "Creating Fermion Action..." << std::endl;

  typedef WilsonImpl<vComplex, Representation, CoeffReal> GaugeWilsonImpl;
  typedef WilsonFermion<GaugeWilsonImpl> WilsonFermion;

  typename WilsonFermion::ImplParams params;
  params.boundary_phases[0]=1.0;
  params.boundary_phases[1]=1.0;
  params.boundary_phases[2]=1.0;
  params.boundary_phases[3]=-1.0;

  return WilsonFermion(gaugefield, grid, rbgrid, mass, params);
}


template<typename FermionAction>
int runCG(FermionAction& action, Grid::GridCartesian& grid)
{
  using namespace Grid;
  typedef typename FermionAction::FermionField Field;
  typedef typename Field::scalar_object        FieldSite;

  MdagMLinearOperator<FermionAction,Field> hermOp(action);

  // Create point source
  std::cout << GridLogMessage << "Creating point source..." << std::endl;
  Field src(&grid);
  src = Zero();
  FieldSite unit;
  unit = 1.;
  pokeSite(unit, src, Coordinate({0, 0, 0, 0}));

  // Run CG
  std::cout << GridLogMessage << "Running CG..." << std::endl;
  Field mdagsrc(&grid);
  action.Mdag(src, mdagsrc);
  Field fermion(&grid);
  FixedIterConjugateGradient<Field> CG(1.0e-10,10000, false);
  CG(hermOp,mdagsrc, fermion);
  return CG.IterationsToComplete;
}


template<typename T>
struct type_identity
{
    typedef T type;
};


template<typename GroupName, int Nc, RepresentationName repname>
constexpr auto getRepresentation()
{
  using namespace Grid;

  if constexpr (repname == RepresentationName::Fundamental)
    return type_identity<FundamentalRep<Nc, GroupName>>{};
  else if constexpr(repname == RepresentationName::Adjoint)
    return type_identity<AdjointRep<Nc>>{};
  else if constexpr(repname == RepresentationName::TwoIndexSymmetric)
    return type_identity<TwoIndexRep<Nc, TwoIndexSymmetry::Symmetric, GroupName>>{};
  else if constexpr(repname == RepresentationName::TwoIndexAntiSymmetric)
    return type_identity<TwoIndexRep<Nc, TwoIndexSymmetry::AntiSymmetric, GroupName>>{};
}



template<typename GroupName, int Nc, RepresentationName repname>
constexpr auto getConfigGroup()
{
  using namespace Grid;

  if constexpr (repname == RepresentationName::Fundamental)
    return type_identity<GaugeGroup<Nc, GroupName>>{};
  else if constexpr(repname == RepresentationName::Adjoint)
    return type_identity<SU_Adjoint<Nc>>{};
  else if constexpr(repname == RepresentationName::TwoIndexSymmetric)
    return type_identity<GaugeGroupTwoIndex<Nc, TwoIndexSymmetry::Symmetric, GroupName>>{};
  else if constexpr(repname == RepresentationName::TwoIndexAntiSymmetric)
    return type_identity<GaugeGroupTwoIndex<Nc, TwoIndexSymmetry::AntiSymmetric, GroupName>>{};
}


template<typename GroupName, int Nc, RepresentationName RepName>
void executeBenchmark()
{
    using namespace Grid;

    // Get benchmark parameters
    size_t real_size = 8;

    int Nprocs = 1;
    for (const auto d : GridDefaultMpi())
        Nprocs *= d;
    
    size_t border_size = Nprocs>1? 1 : 0;

    // Begin benchmark
    typedef typename decltype(getRepresentation<GroupName, Nc, RepName>())::type Representation;
    typedef typename decltype(getConfigGroup<GroupName, Representation::Dimension, RepName>())::type ConfigGroup;

    auto grid = createGrid();
    GridRedBlackCartesian rbgrid(&grid);
    auto gaugefield     = generateUnitGauge<Representation, ConfigGroup>(grid, {0, 1, 2, 3});
    auto fermion_action = generateFermionAction<Representation>(grid, rbgrid, gaugefield, 0.1);
    int iterations = runCG(fermion_action, grid);
    double gflops = CloverCGSiteFlops(iterations, Representation::Dimension);
    double mcomms = CloverCGSiteCommsMB(iterations, Representation::Dimension, grid, real_size, border_size);
    double gmem   = CGLocalMemoryGB(iterations, Representation::Dimension, grid, real_size, border_size);

    std::cout << GridLogMessage << "FlOp/S (GB): " << gflops << std::endl;
    std::cout << GridLogMessage << "Comms  (MB): " << mcomms << std::endl;
    std::cout << GridLogMessage << "Memory (GB): " << gmem   << std::endl;
}


void teardownGrid()
{
    using namespace Grid;

    Grid_finalize();
}
