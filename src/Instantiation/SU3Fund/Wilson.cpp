#include <Grid/Grid.h>

#include <Grid/qcd/action/fermion/implementation/WilsonFermionImplementation.h>
#include "../KernelImplementation.hpp"
#include "Implementation.hpp"
#include "Global.h"


NAMESPACE_BEGIN(Grid);

#ifdef BKEEPER_SU3FUND
template class WilsonFermion<SU3FundWilsonImplF>;
template class WilsonFermion<SU3FundWilsonImplD>;
#endif

NAMESPACE_END(Grid);
