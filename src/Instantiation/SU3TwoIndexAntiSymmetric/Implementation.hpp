#pragma once

#include <Grid/Grid.h>


NAMESPACE_BEGIN(Grid);

typedef WilsonImpl<Grid::vComplexF, 
                   TwoIndexRep<3, TwoIndexSymmetry::AntiSymmetric, Grid::GroupName::SU>, 
                   Grid::CoeffReal> SU3TwoIndexAntiSymmetricWilsonImplF;
typedef WilsonImpl<Grid::vComplexD, 
                   TwoIndexRep<3, TwoIndexSymmetry::AntiSymmetric, Grid::GroupName::SU>, 
                   Grid::CoeffReal> SU3TwoIndexAntiSymmetricWilsonImplD;

NAMESPACE_END(Grid);
