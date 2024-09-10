#include <Grid/Grid.h>

#include <Grid/qcd/action/fermion/implementation/WilsonFermionImplementation.h>
#include "../KernelImplementation.hpp"
#include "Implementation.hpp"
#include "Global.h"


NAMESPACE_BEGIN(Grid);

#ifdef BKEEPER_Sp4TIS
template class WilsonFermion<Sp4TwoIndexSymmetricWilsonImplF>;
template class WilsonFermion<Sp4TwoIndexSymmetricWilsonImplD>;
#endif

NAMESPACE_END(Grid);
