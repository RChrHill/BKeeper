#pragma once

#include <Grid/Grid.h>


NAMESPACE_BEGIN(Grid);

typedef WilsonImpl<Grid::vComplexF, 
                   Grid::FundamentalRep<2,Grid::GroupName::SU>, 
                   Grid::CoeffReal> SU2FundWilsonImplF;
typedef WilsonImpl<Grid::vComplexD, 
                   Grid::FundamentalRep<2,Grid::GroupName::SU>, 
                   Grid::CoeffReal> SU2FundWilsonImplD;

NAMESPACE_END(Grid);
