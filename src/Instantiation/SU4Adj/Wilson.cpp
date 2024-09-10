#include <Grid/Grid.h>

#include <Grid/qcd/action/fermion/implementation/WilsonFermionImplementation.h>
#include "../KernelImplementation.hpp"
#include "Implementation.hpp"
#include "Global.h"


NAMESPACE_BEGIN(Grid);

#ifdef BKEEPER_SU4ADJ
template class WilsonFermion<SU4AdjWilsonImplF>;
template class WilsonFermion<SU4AdjWilsonImplD>;
#endif

NAMESPACE_END(Grid);
