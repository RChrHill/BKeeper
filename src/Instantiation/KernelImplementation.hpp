#pragma once

#include <Grid/Grid.h>

#include <Grid/qcd/action/fermion/FermionCore.h>
#include <Grid/qcd/action/fermion/implementation/WilsonKernelsImplementation.h>
#include <Grid/qcd/action/fermion/implementation/WilsonKernelsHandImplementation.h>

#ifndef AVX512
#ifndef QPX
#ifndef A64FX
#ifndef A64FXFIXEDSIZE
#include <Grid/qcd/action/fermion/implementation/WilsonKernelsAsmImplementation.h>
#endif
#endif
#endif
#endif
