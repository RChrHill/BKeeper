#include <Grid/Grid.h>

#include <Grid/qcd/action/fermion/implementation/WilsonFermionImplementation.h>
#include "../KernelImplementation.hpp"
#include "Implementation.hpp"
#include "Global.h"


NAMESPACE_BEGIN(Grid);

#ifdef BKEEPER_Sp4TIAS
template class WilsonFermion<Sp4TwoIndexAntiSymmetricWilsonImplF>;
template class WilsonFermion<Sp4TwoIndexAntiSymmetricWilsonImplD>;
#endif

NAMESPACE_END(Grid);