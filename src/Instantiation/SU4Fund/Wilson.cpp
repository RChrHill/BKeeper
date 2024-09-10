#include <Grid/Grid.h>

#include <Grid/qcd/action/fermion/implementation/WilsonFermionImplementation.h>
#include "../KernelImplementation.hpp"
#include "Implementation.hpp"
#include "Global.h"


NAMESPACE_BEGIN(Grid);

#ifdef BKEEPER_SU4FUND
template class WilsonFermion<SU4FundWilsonImplF>;
template class WilsonFermion<SU4FundWilsonImplD>;
#endif

NAMESPACE_END(Grid);
