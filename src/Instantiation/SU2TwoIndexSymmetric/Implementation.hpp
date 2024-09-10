#pragma once

#include <Grid/Grid.h>


NAMESPACE_BEGIN(Grid);

typedef WilsonImpl<Grid::vComplexF, 
                   TwoIndexRep<2, TwoIndexSymmetry::Symmetric, Grid::GroupName::SU>, 
                   Grid::CoeffReal> SU2TwoIndexSymmetricWilsonImplF;
typedef WilsonImpl<Grid::vComplexD, 
                   TwoIndexRep<2, TwoIndexSymmetry::Symmetric, Grid::GroupName::SU>, 
                   Grid::CoeffReal> SU2TwoIndexSymmetricWilsonImplD;

NAMESPACE_END(Grid);
