#include <Grid/Grid.h>

#include <Grid/qcd/action/fermion/implementation/WilsonFermionImplementation.h>
#include "../KernelImplementation.hpp"
#include "Implementation.hpp"
#include "Global.h"


NAMESPACE_BEGIN(Grid);

#ifdef BKEEPER_SU2TIAS
template class WilsonFermion<SU2TwoIndexAntiSymmetricWilsonImplF>;
template class WilsonFermion<SU2TwoIndexAntiSymmetricWilsonImplD>;
#endif

NAMESPACE_END(Grid);
