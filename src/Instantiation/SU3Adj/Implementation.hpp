#pragma once

#include <Grid/Grid.h>


NAMESPACE_BEGIN(Grid);

typedef WilsonImpl<Grid::vComplexF, 
                   Grid::AdjointRep<3>, 
                   Grid::CoeffReal> SU3AdjWilsonImplF;
typedef WilsonImpl<Grid::vComplexD, 
                   Grid::AdjointRep<3>, 
                   Grid::CoeffReal> SU3AdjWilsonImplD;

NAMESPACE_END(Grid);
