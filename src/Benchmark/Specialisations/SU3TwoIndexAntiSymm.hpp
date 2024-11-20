#pragma once
#include "Global.h"
#include "../../GaugeGroupInfo.hpp"
#include "../../Parameters/Parameters.hpp"


const static GroupInfo SU3TwoIndexAntiSymmetricGroupInfo("SU", 3, "twoindexantisymmetric");
void executeBenchmarkSU3TwoIndexAntiSymmetric(BKeeperParameters& params);
