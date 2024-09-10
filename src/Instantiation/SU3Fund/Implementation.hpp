#pragma once

#include <Grid/Grid.h>


NAMESPACE_BEGIN(Grid);

typedef WilsonImpl<Grid::vComplexF, 
                   Grid::FundamentalRep<3,Grid::GroupName::SU>, 
                   Grid::CoeffReal> SU3FundWilsonImplF;
typedef WilsonImpl<Grid::vComplexD, 
                   Grid::FundamentalRep<3,Grid::GroupName::SU>, 
                   Grid::CoeffReal> SU3FundWilsonImplD;

NAMESPACE_END(Grid);
