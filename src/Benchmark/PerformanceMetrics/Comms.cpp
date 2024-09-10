#include "Comms.hpp"
#include "LatticeParameters.hpp"


double spinColourVectorFieldComms(Grid::GridCartesian& grid, size_t fermion_rep_elements, size_t real_size, size_t border_size)
{
    return 2 * haloSitesRb(grid.LocalDimensions(), border_size) * spinColourVectorSize(fermion_rep_elements, real_size);
}


double WilsonComms(Grid::GridCartesian& grid, size_t fermion_rep_elements, size_t real_size, size_t border_size)
{ 
    return spinColourVectorFieldComms(grid, fermion_rep_elements, real_size, border_size);
}

double g5CloverTermRbSqComms(Grid::GridCartesian& grid, size_t fermion_rep_elements, size_t real_size, size_t border_size)
{
    return 2 * 2 * WilsonComms(grid, fermion_rep_elements, real_size, border_size);
}


double CloverCGSiteCommsMB(double iterations, size_t fermion_rep_elements, Grid::GridCartesian& grid, size_t real_size, size_t border_size)
{
    double op_comms = g5CloverTermRbSqComms(grid, fermion_rep_elements, real_size, border_size);
    return iterations * (2*op_comms) / 1.e6;
}
