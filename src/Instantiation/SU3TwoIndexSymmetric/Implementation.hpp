#pragma once

#include <Grid/Grid.h>


NAMESPACE_BEGIN(Grid);

typedef WilsonImpl<Grid::vComplexF, 
                   TwoIndexRep<3, TwoIndexSymmetry::Symmetric, Grid::GroupName::SU>, 
                   Grid::CoeffReal> SU3TwoIndexSymmetricWilsonImplF;
typedef WilsonImpl<Grid::vComplexD, 
                   TwoIndexRep<3, TwoIndexSymmetry::Symmetric, Grid::GroupName::SU>, 
                   Grid::CoeffReal> SU3TwoIndexSymmetricWilsonImplD;

NAMESPACE_END(Grid);
