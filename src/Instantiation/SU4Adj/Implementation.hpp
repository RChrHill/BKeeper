#pragma once

#include <Grid/Grid.h>


NAMESPACE_BEGIN(Grid);

typedef WilsonImpl<Grid::vComplexF, 
                   Grid::AdjointRep<4>, 
                   Grid::CoeffReal> SU4AdjWilsonImplF;
typedef WilsonImpl<Grid::vComplexD, 
                   Grid::AdjointRep<4>, 
                   Grid::CoeffReal> SU4AdjWilsonImplD;

NAMESPACE_END(Grid);
