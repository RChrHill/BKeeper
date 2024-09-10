#pragma once

#include <Grid/Grid.h>


NAMESPACE_BEGIN(Grid);

typedef WilsonImpl<Grid::vComplexF, 
                   TwoIndexRep<4, TwoIndexSymmetry::AntiSymmetric, Grid::GroupName::Sp>, 
                   Grid::CoeffReal> Sp4TwoIndexAntiSymmetricWilsonImplF;
typedef WilsonImpl<Grid::vComplexD, 
                   TwoIndexRep<4, TwoIndexSymmetry::AntiSymmetric, Grid::GroupName::Sp>, 
                   Grid::CoeffReal> Sp4TwoIndexAntiSymmetricWilsonImplD;

NAMESPACE_END(Grid);
