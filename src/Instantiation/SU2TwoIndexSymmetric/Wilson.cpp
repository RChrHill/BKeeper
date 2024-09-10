#include <Grid/Grid.h>

#include <Grid/qcd/action/fermion/implementation/WilsonFermionImplementation.h>
#include "../KernelImplementation.hpp"
#include "Implementation.hpp"
#include "Global.h"


NAMESPACE_BEGIN(Grid);

#ifdef BKEEPER_SU2TIS
template class WilsonFermion<SU2TwoIndexSymmetricWilsonImplF>;
template class WilsonFermion<SU2TwoIndexSymmetricWilsonImplD>;
#endif

NAMESPACE_END(Grid);