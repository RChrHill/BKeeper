#include <Grid/Grid.h>

#include <Grid/qcd/action/fermion/implementation/WilsonFermionImplementation.h>
#include "../KernelImplementation.hpp"
#include "Implementation.hpp"
#include "Global.h"


NAMESPACE_BEGIN(Grid);

#ifdef BKEEPER_SU2FUND
template class WilsonFermion<SU2FundWilsonImplF>;
template class WilsonFermion<SU2FundWilsonImplD>;
#endif

NAMESPACE_END(Grid);
