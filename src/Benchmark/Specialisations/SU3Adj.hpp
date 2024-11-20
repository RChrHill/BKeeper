#pragma once
#include "Global.h"
#include "../../GaugeGroupInfo.hpp"
#include "../../Parameters/Parameters.hpp"


const static GroupInfo SU3AdjointGroupInfo("SU", 3, "adjoint");
void executeBenchmarkSU3Adjoint(BKeeperParameters& params);
