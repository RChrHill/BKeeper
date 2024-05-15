#include "Memory.hpp"
#include "LatticeParameters.hpp"


double ldlTSize(size_t fermion_rep_elements, size_t real_size)
{
    return 2 * fermion_rep_elements * (2 * fermion_rep_elements + 1) * complexSize(real_size);
}


double gaugeMatrixSize(size_t fermion_rep_elements, size_t real_size)
{
    return fermion_rep_elements * colourVectorSize(fermion_rep_elements, real_size);
}


double localSpinColourVectorFieldRbMemory(const Grid::Coordinate& localDims, size_t fermion_rep_elements, size_t real_size, size_t borderSize)
{
    return colourVectorSize(fermion_rep_elements, real_size) * (localSitesRb(localDims) + haloSitesRb(localDims, borderSize));
}


double localSpinColourVectorFieldRbNoHaloMemory(const Grid::Coordinate& localDims, size_t fermion_rep_elements, size_t real_size)
{
    return spinColourVectorSize(fermion_rep_elements, real_size) * localSitesRb(localDims);
}


double localGaugeFieldMemory(const Grid::Coordinate& localDims, size_t fermion_rep_elements, size_t real_size, size_t border_size)
{
    return gaugeMatrixSize(fermion_rep_elements, real_size) * (localSites(localDims) * 4 + haloSites(localDims, border_size) / 2);
}


double localCloverFieldRbMemory(const Grid::Coordinate& localDims, size_t fermion_rep_elements, size_t real_size)
{
    return gaugeMatrixSize(fermion_rep_elements, real_size) * localSitesRb(localDims) * 4;
}


double localLDLFieldRbMemory(const Grid::Coordinate& localDims, size_t fermion_rep_elements, size_t real_size)
{
    return ldlTSize(fermion_rep_elements, real_size) * localSitesRb(localDims);
}


double localWilsonMemory(const Grid::Coordinate& localDims, size_t fermion_rep_elements, size_t real_size, size_t border_size)
{
    return 2*localSpinColourVectorFieldRbMemory(localDims, fermion_rep_elements, real_size, border_size) + localGaugeFieldMemory(localDims, fermion_rep_elements, real_size, border_size);
}


double localCloverTermMemory(const Grid::Coordinate& localDims, size_t fermion_rep_elements, size_t real_size, size_t border_size)
{
    return 2*localSpinColourVectorFieldRbMemory(localDims, fermion_rep_elements, real_size, border_size) + localCloverFieldRbMemory(localDims, fermion_rep_elements, real_size);
}


double localCloverTermInvMemory(const Grid::Coordinate& localDims, size_t fermion_rep_elements, size_t real_size, size_t border_size)
{
    return 2*localSpinColourVectorFieldRbMemory(localDims, fermion_rep_elements, real_size, border_size) + localLDLFieldRbMemory(localDims, fermion_rep_elements, real_size);
}


double tSliceExtSites(const Grid::Coordinate& localDims)
{
    return (localDims[0] + 2) * (localDims[1] + 2) * (localDims[2] + 2);
}


double localSpinColourFieldRbTSliceMemory(const Grid::Coordinate& localDims, size_t fermion_rep_elements, size_t real_size, size_t border_size)
{
    return spinColourVectorSize(fermion_rep_elements, real_size) * tSliceExtSites(localDims);
}


double localApplyBCsOnSpinColourVectorMemory(const Grid::Coordinate& localDims, size_t fermion_rep_elements, size_t real_size, size_t border_size)
{
    return localSpinColourFieldRbTSliceMemory(localDims, fermion_rep_elements, real_size, border_size);
}


double localSpinColourVectorFieldMinusFMemory(const Grid::Coordinate& localDims, size_t fermion_rep_elements, size_t real_size, size_t border_size)
{
    return 2*localSpinColourVectorFieldRbMemory(localDims, fermion_rep_elements, real_size, border_size);
}


double localCloverTermRbPreMemory(const Grid::Coordinate& localDims, size_t fermion_rep_elements, float bc_op_memory, size_t real_size, size_t border_size)
{
    double ops = 0;
    ops += bc_op_memory;
    ops += localWilsonMemory(localDims, fermion_rep_elements, real_size, border_size);
    ops += localCloverTermInvMemory(localDims, fermion_rep_elements, real_size, border_size);
    ops += bc_op_memory;
    ops += localWilsonMemory(localDims, fermion_rep_elements, real_size, border_size);
    ops += localSpinColourVectorFieldMinusFMemory(localDims, fermion_rep_elements, real_size, border_size);
    ops += localCloverTermMemory(localDims, fermion_rep_elements, real_size, border_size);
    ops += bc_op_memory;
    return ops;
}


double localSpinColourVectorFieldG5AssignFMemory(const Grid::Coordinate& localDims, size_t fermion_rep_elements, size_t real_size, size_t border_size)
{
    return 2*localSpinColourVectorFieldRbMemory(localDims, fermion_rep_elements, real_size, border_size);
}


double localG5CloverTermRbPreSqMemory(const Grid::Coordinate& localDims, size_t fermion_rep_elements, float bc_op_memory, size_t real_size, size_t border_size)
{
    return localCloverTermRbPreMemory(localDims, fermion_rep_elements, bc_op_memory, real_size, border_size) + localSpinColourVectorFieldG5AssignFMemory(localDims, fermion_rep_elements, real_size, border_size);
}


double localSpinColourVectorFieldSqNormFMemory(const Grid::Coordinate& localDims, size_t fermion_rep_elements, size_t real_size)
{
    return real_size + localSpinColourVectorFieldRbNoHaloMemory(localDims, fermion_rep_elements, real_size);
}


double localSpinColourVectorFieldMulAddAssignFMemory(const Grid::Coordinate& localDims, size_t fermion_rep_elements, size_t real_size, size_t border_size)
{
    return real_size + 2 * localSpinColourVectorFieldRbMemory(localDims, fermion_rep_elements, real_size, border_size);
}


double localSpinColourVectorFieldSubFMemory(const Grid::Coordinate& localDims, size_t fermion_rep_elements, size_t real_size, size_t border_size)
{
    return 2 * localSpinColourVectorFieldRbMemory(localDims, fermion_rep_elements, real_size, border_size);
}


double localSpinColourVectorFieldCopyFMemory(const Grid::Coordinate& localDims, size_t fermion_rep_elements, size_t real_size, size_t border_size)
{
    return 2 * localSpinColourVectorFieldRbMemory(localDims, fermion_rep_elements, real_size, border_size);
}


double localCGOutOfLoopMemory(const Grid::Coordinate& localDims, size_t fermion_rep_elements, double local_op_memory, size_t real_size, size_t border_size)
{
    double ops = 0;
    ops += localSpinColourVectorFieldSqNormFMemory(localDims, fermion_rep_elements, real_size);
    ops += local_op_memory;
    ops += localSpinColourVectorFieldMulAddAssignFMemory(localDims, fermion_rep_elements, real_size, border_size);
    ops += localSpinColourVectorFieldSubFMemory(localDims, fermion_rep_elements, real_size, border_size);
    ops += localSpinColourVectorFieldCopyFMemory(localDims, fermion_rep_elements, real_size, border_size);
    ops += localSpinColourVectorFieldMulAddAssignFMemory(localDims, fermion_rep_elements, real_size, border_size);
    ops += localSpinColourVectorFieldSubFMemory(localDims, fermion_rep_elements, real_size, border_size);
    ops += localSpinColourVectorFieldSqNormFMemory(localDims, fermion_rep_elements, real_size);
    return ops;
}


double localSpinColourVectorProdReFMemory(const Grid::Coordinate& localDims, size_t fermion_rep_elements, size_t real_size, size_t border_size)
{
    return real_size + 2 * localSpinColourVectorFieldRbMemory(localDims, fermion_rep_elements, real_size, border_size);
}


double localSpinColourVectorMulFMemory(const Grid::Coordinate& localDims, size_t fermion_rep_elements, size_t real_size, size_t border_size)
{
    return real_size + 2 * localSpinColourVectorFieldRbMemory(localDims, fermion_rep_elements, real_size, border_size);
}


double localCGIterationMemory(const Grid::Coordinate& localDims, size_t fermion_rep_elements, double local_op_memory, size_t real_size, size_t border_size)
{
    double ops = 0;
    ops += local_op_memory;
    ops += localSpinColourVectorProdReFMemory(localDims, fermion_rep_elements, real_size, border_size);
    ops += localSpinColourVectorFieldMulAddAssignFMemory(localDims, fermion_rep_elements, real_size, border_size);
    ops += localSpinColourVectorFieldMulAddAssignFMemory(localDims, fermion_rep_elements, real_size, border_size);
    ops += localSpinColourVectorFieldSqNormFMemory(localDims, fermion_rep_elements, real_size);
    ops += localSpinColourVectorMulFMemory(localDims, fermion_rep_elements, real_size, border_size);
    ops += localSpinColourVectorFieldMulAddAssignFMemory(localDims, fermion_rep_elements, real_size, border_size);
    return ops;
}


double CGLocalMemoryGB(double iterations, size_t fermion_rep_elements, Grid::GridCartesian& grid, size_t real_size, size_t border_size)
{
    const Grid::Coordinate& localDims = grid.LocalDimensions();

    double local_bc_ops_memory  = localApplyBCsOnSpinColourVectorMemory(localDims, fermion_rep_elements, real_size, border_size);
    double local_ops_memory     = localG5CloverTermRbPreSqMemory(localDims, fermion_rep_elements, local_bc_ops_memory, real_size, border_size);
    double mem_per_iter         = localCGIterationMemory(localDims, fermion_rep_elements, local_ops_memory, real_size, border_size);
    mem_per_iter               += localCGOutOfLoopMemory(localDims, fermion_rep_elements, local_ops_memory, real_size, border_size);
    
    return mem_per_iter * iterations / 1e9;
}
