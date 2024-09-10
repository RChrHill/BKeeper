#include <Grid/Grid.h>

#include <Grid/qcd/action/fermion/implementation/WilsonFermionImplementation.h>
#include "../KernelImplementation.hpp"
#include "Implementation.hpp"
#include "Global.h"

NAMESPACE_BEGIN(Grid);

#ifdef BKEEPER_SU2ADJ
template class WilsonFermion<SU2AdjWilsonImplF>;
template class WilsonFermion<SU2AdjWilsonImplD>;
#endif

NAMESPACE_END(Grid);
