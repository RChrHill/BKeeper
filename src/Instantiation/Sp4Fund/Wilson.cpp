#include <Grid/Grid.h>

#include <Grid/qcd/action/fermion/implementation/WilsonFermionImplementation.h>
#include "../KernelImplementation.hpp"
#include "Implementation.hpp"
#include "Global.h"

NAMESPACE_BEGIN(Grid);

#ifdef BKEEPER_Sp4FUND
template class WilsonFermion<Sp4FundWilsonImplF>;
template class WilsonFermion<Sp4FundWilsonImplD>;
#endif

NAMESPACE_END(Grid);
