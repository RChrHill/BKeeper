#pragma once

#include <Grid/Grid.h>


NAMESPACE_BEGIN(Grid);

typedef WilsonImpl<Grid::vComplexF, 
                   TwoIndexRep<4, TwoIndexSymmetry::Symmetric, Grid::GroupName::Sp>, 
                   Grid::CoeffReal> Sp4TwoIndexSymmetricWilsonImplF;
typedef WilsonImpl<Grid::vComplexD, 
                    TwoIndexRep<4, TwoIndexSymmetry::Symmetric, Grid::GroupName::Sp>, 
                    Grid::CoeffReal> Sp4TwoIndexSymmetricWilsonImplD;

NAMESPACE_END(Grid);
