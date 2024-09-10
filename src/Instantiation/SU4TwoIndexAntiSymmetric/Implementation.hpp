#pragma once

#include <Grid/Grid.h>


NAMESPACE_BEGIN(Grid);

typedef WilsonImpl<Grid::vComplexF, 
                   TwoIndexRep<4, TwoIndexSymmetry::AntiSymmetric, Grid::GroupName::SU>, 
                   Grid::CoeffReal> SU4TwoIndexAntiSymmetricWilsonImplF;
typedef WilsonImpl<Grid::vComplexD, 
                   TwoIndexRep<4, TwoIndexSymmetry::AntiSymmetric, Grid::GroupName::SU>, 
                   Grid::CoeffReal> SU4TwoIndexAntiSymmetricWilsonImplD;

NAMESPACE_END(Grid);
