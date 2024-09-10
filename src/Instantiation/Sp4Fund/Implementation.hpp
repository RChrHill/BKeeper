#pragma once

#include <Grid/Grid.h>


NAMESPACE_BEGIN(Grid);

typedef WilsonImpl<Grid::vComplexF, 
                    Grid::FundamentalRep<4,Grid::GroupName::Sp>, 
                    Grid::CoeffReal> Sp4FundWilsonImplF;
typedef WilsonImpl<Grid::vComplexD, 
                    Grid::FundamentalRep<4,Grid::GroupName::Sp>, 
                    Grid::CoeffReal> Sp4FundWilsonImplD;

NAMESPACE_END(Grid);
