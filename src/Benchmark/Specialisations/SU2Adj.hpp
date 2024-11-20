#pragma once
#include "Global.h"
#include "../../GaugeGroupInfo.hpp"
#include "../../Parameters/Parameters.hpp"


const static GroupInfo SU2AdjointGroupInfo("SU", 2, "adjoint");
void executeBenchmarkSU2Adjoint(BKeeperParameters& params);
