#pragma once

#include <Grid/Grid.h>


NAMESPACE_BEGIN(Grid);

typedef WilsonImpl<Grid::vComplexF, 
                   TwoIndexRep<2, TwoIndexSymmetry::AntiSymmetric, Grid::GroupName::SU>, 
                   Grid::CoeffReal> SU2TwoIndexAntiSymmetricWilsonImplF;
typedef WilsonImpl<Grid::vComplexD, 
                   TwoIndexRep<2, TwoIndexSymmetry::AntiSymmetric, Grid::GroupName::SU>, 
                   Grid::CoeffReal> SU2TwoIndexAntiSymmetricWilsonImplD;

NAMESPACE_END(Grid);
