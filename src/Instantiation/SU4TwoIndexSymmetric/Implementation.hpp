#pragma once

#include <Grid/Grid.h>


NAMESPACE_BEGIN(Grid);

typedef WilsonImpl<Grid::vComplexF, 
                   TwoIndexRep<4, TwoIndexSymmetry::Symmetric, Grid::GroupName::SU>, 
                   Grid::CoeffReal> SU4TwoIndexSymmetricWilsonImplF;
typedef WilsonImpl<Grid::vComplexD, 
                   TwoIndexRep<4, TwoIndexSymmetry::Symmetric, Grid::GroupName::SU>, 
                   Grid::CoeffReal> SU4TwoIndexSymmetricWilsonImplD;

NAMESPACE_END(Grid);
