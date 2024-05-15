#pragma once
#include <cstddef>
#include <Grid/Grid.h>

static inline constexpr size_t SPIN_COMPONENTS = 4;


constexpr size_t localSites(size_t x, size_t y, size_t z, size_t t, size_t Ls)
{
    return x*y*z*t*Ls;
}


constexpr size_t localSites(const Grid::Coordinate& localDims)
{
    return localSites(localDims[0], localDims[1], localDims[2], localDims[3], 1);
}


constexpr size_t localSitesRb(size_t x, size_t y, size_t z, size_t t, size_t Ls)
{
    return localSites(x,y,z,t,Ls)/2;
}


constexpr size_t localSitesRb(const Grid::Coordinate& localDims)
{
    return localSitesRb(localDims[0], localDims[1], localDims[2], localDims[3], 1);
}


constexpr size_t haloSites(
    size_t x, size_t y, size_t z, size_t t, size_t Ls,
    size_t borderX, size_t borderY, size_t borderZ, size_t borderT)
{
    return 2*localSites(x,y,z,t,Ls) * (static_cast<double>(borderX)/x) * (static_cast<double>(borderY)/y) * (static_cast<double>(borderZ)/z) * (static_cast<double>(borderT)/t);
}


constexpr size_t haloSites(const Grid::Coordinate& localDims, size_t borderSize)
{
    return haloSites(localDims[0], localDims[1], localDims[2], localDims[3], 1, borderSize, borderSize, borderSize, borderSize);
}


constexpr size_t haloSitesRb(
    size_t x, size_t y, size_t z, size_t t, size_t Ls,
    size_t borderX, size_t borderY, size_t borderZ, size_t borderT)
{
    return haloSites(x,y,z,t,Ls,borderX,borderY,borderZ,borderT)/2;
}


constexpr size_t haloSitesRb(const Grid::Coordinate& localDims, size_t borderSize)
{
    return haloSites(localDims[0], localDims[1], localDims[2], localDims[3], 1, borderSize, borderSize, borderSize, borderSize)/2;
}


constexpr size_t complexSize(size_t real_size)
{
    return real_size*2;
}


constexpr size_t colourVectorSize(size_t fermion_rep_elems, size_t real_size)
{
    return fermion_rep_elems*real_size;
}


constexpr size_t spinColourVectorSize(size_t fermion_rep_elems, size_t real_size)
{
    return colourVectorSize(fermion_rep_elems, real_size)*SPIN_COMPONENTS;
}
