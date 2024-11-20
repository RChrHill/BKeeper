#pragma once
#include "Global.h"
#include "../../GaugeGroupInfo.hpp"
#include "../../Parameters/Parameters.hpp"


const static GroupInfo SU4AdjointGroupInfo("SU", 4, "adjoint");
void executeBenchmarkSU4Adjoint(BKeeperParameters& params);
