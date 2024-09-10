#pragma once

#include <Grid/Grid.h>


NAMESPACE_BEGIN(Grid);

typedef WilsonImpl<Grid::vComplexF, 
                   Grid::AdjointRep<2>, 
                   Grid::CoeffReal> SU2AdjWilsonImplF;
typedef WilsonImpl<Grid::vComplexD, 
                   Grid::AdjointRep<2>, 
                   Grid::CoeffReal> SU2AdjWilsonImplD;

NAMESPACE_END(Grid);
