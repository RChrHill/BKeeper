#pragma once

#include <memory>
#include <Grid/Grid.h>
#include "FixedIterCG.hpp"
#include "PerformanceMetrics/Flops.hpp"
#include "PerformanceMetrics/Comms.hpp"
#include "PerformanceMetrics/Memory.hpp"
#include "../GaugeGroupInfo.hpp"
#include "../Logger/BKeeperLog.hpp"
#include "../Parameters/Parameters.hpp"


void initGrid(int argc, char** argv);
Grid::GridCartesian createGrid();
void teardownGrid();


template<typename Representation, typename ConfigGroup>
auto generateUnitGauge(Grid::GridCartesian& grid, const std::vector<int>& seed)
{
  using namespace Grid;

  std::cout << BKeeperLogMessage << "Creating gauge..." << std::endl;

  GridParallelRNG rng(&grid);
  rng.SeedFixedIntegers(seed);
  GaugeField<Representation> gaugefield(&grid);
  ConfigGroup::ColdConfiguration(rng, gaugefield);
  return gaugefield;
}


template<typename Representation>
auto generateFermionAction(Grid::GridCartesian& grid, Grid::GridRedBlackCartesian& rbgrid, GaugeField<Representation>& gaugefield, Grid::RealD mass)
{
  using namespace Grid;
  std::cout << BKeeperLogMessage << "Creating Fermion Action..." << std::endl;

  typedef WilsonFermion<Impl<Representation>> WilsonFermion;

  typename WilsonFermion::ImplParams params;
  params.boundary_phases[0]=1.0;
  params.boundary_phases[1]=1.0;
  params.boundary_phases[2]=1.0;
  params.boundary_phases[3]=-1.0;

  return WilsonFermion(gaugefield, grid, rbgrid, mass, params);
}


template<typename FermionAction>
int runCG(FermionAction& action, Grid::GridCartesian& grid, Integer iteration_count)
{
  using namespace Grid;
  typedef typename FermionAction::FermionField Field;
  typedef typename Field::scalar_object        FieldSite;

  MdagMLinearOperator<FermionAction,Field> hermOp(action);

  // Create point source
  std::cout << BKeeperLogMessage << "Creating point source..." << std::endl;
  Field src(&grid);
  src = Zero();
  FieldSite unit;
  unit = 1.;
  pokeSite(unit, src, Coordinate({0, 0, 0, 0}));

  // Run CG
  std::cout << BKeeperLogMessage << "Running CG..." << std::endl;
  Field mdagsrc(&grid);
  action.Mdag(src, mdagsrc);
  Field fermion(&grid);
  FixedIterConjugateGradient<Field> CG(1.0e-10, iteration_count, false);
  CG(hermOp,mdagsrc, fermion);
  return CG.IterationsToComplete;
}


template<typename GroupName, int Nc, RepresentationName RepName>
void executeBenchmark(BKeeperParameters& params)
{
    using namespace Grid;

    GridStopWatch CGTimer;

    // Get benchmark parameters
    size_t real_size = 8;

    int Nprocs = 1;
    for (const auto d : GridDefaultMpi())
        Nprocs *= d;
    
    size_t border_size = Nprocs>1? 1 : 0;

    // Begin benchmark
    typedef typename decltype(getRepresentation<GroupName, Nc,                        RepName>())::type Representation;
    typedef typename decltype(getConfigGroup   <GroupName, Representation::Dimension, RepName>())::type ConfigGroup;

    auto grid = createGrid();
    int volume = 1;
    for (const auto d : grid.FullDimensions())
        volume *= d;
    
    GridRedBlackCartesian rbgrid(&grid);
    auto   gaugefield     = generateUnitGauge<Representation, ConfigGroup>(grid, {0, 1, 2, 3});
    auto   fermion_action = generateFermionAction<Representation>(grid, rbgrid, gaugefield, params.mass);
    CGTimer.Start();
    int    iterations     = runCG(fermion_action, grid, params.iterations);
    CGTimer.Stop();
    double gflops = volume*CloverCGSiteFlops(iterations, Representation::Dimension);
    double mcomms = CloverCGSiteCommsMB(iterations, Representation::Dimension, grid, real_size, border_size);
    double gmem   = Nprocs*CGLocalMemoryGB(iterations, Representation::Dimension, grid, real_size, border_size);

    double time = std::chrono::duration<double>(CGTimer.Elapsed()).count();

    std::cout << BKeeperLogResult << "CG Run Time (s): " << time << std::endl;
    std::cout << BKeeperLogResult << "FlOp/S (GFlOp/s):   " << gflops/time << std::endl;
    std::cout << BKeeperLogResult << "Comms  (MB):     " << mcomms << std::endl;
    std::cout << BKeeperLogResult << "Memory (GB):     " << gmem   << std::endl;
}
