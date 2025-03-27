#include <Grid/Grid.h>

#include <Grid/qcd/action/fermion/implementation/WilsonFermionImplementation.h>
#include "../KernelImplementation.hpp"
#include "Implementation.hpp"
#include "Global.h"


NAMESPACE_BEGIN(Grid);

#if defined(BKEEPER_Sp4TIS) || defined(BKEEPER_Sp4ADJ)
template class WilsonFermion<Sp4TwoIndexSymmetricWilsonImplF>;
template class WilsonFermion<Sp4TwoIndexSymmetricWilsonImplD>;
#endif

NAMESPACE_END(Grid);
