#pragma once

#include <iostream>
#include "Specialisations/SU2Fund.hpp"
#include "Specialisations/SU2Adj.hpp"
#include "Specialisations/SU2TwoIndexSymm.hpp"
#include "Specialisations/SU2TwoIndexAntiSymm.hpp"
#include "Specialisations/SU3Fund.hpp"
#include "Specialisations/SU3Adj.hpp"
#include "Specialisations/SU3TwoIndexSymm.hpp"
#include "Specialisations/SU3TwoIndexAntiSymm.hpp"
#include "Specialisations/SU4Fund.hpp"
#include "Specialisations/SU4Adj.hpp"
#include "Specialisations/SU4TwoIndexSymm.hpp"
#include "Specialisations/SU4TwoIndexAntiSymm.hpp"
#include "Specialisations/Sp4Fund.hpp"
#include "Specialisations/Sp4TwoIndexSymm.hpp"
#include "Specialisations/Sp4TwoIndexAntiSymm.hpp"


void executeBenchmark(const GroupInfo& group_info)
{
    if      (group_info==SU2FundamentalGroupInfo)
        executeBenchmarkSU2Fundamental();
    else if (group_info==SU2AdjointGroupInfo)
        executeBenchmarkSU2Adjoint();
    else if (group_info==SU2TwoIndexSymmetricGroupInfo)
        executeBenchmarkSU2TwoIndexSymmetric();
    else if (group_info==SU2TwoIndexAntiSymmetricGroupInfo)
        executeBenchmarkSU2TwoIndexAntiSymmetric();
    else if (group_info==SU3FundamentalGroupInfo)
        executeBenchmarkSU3Fundamental();
    else if (group_info==SU3AdjointGroupInfo)
        executeBenchmarkSU3Adjoint();
    else if (group_info==SU3TwoIndexSymmetricGroupInfo)
        executeBenchmarkSU3TwoIndexSymmetric();
    else if (group_info==SU3TwoIndexAntiSymmetricGroupInfo)
        executeBenchmarkSU3TwoIndexAntiSymmetric();
    else if (group_info==SU4FundamentalGroupInfo)
        executeBenchmarkSU4Fundamental();
    else if (group_info==SU4AdjointGroupInfo)
        executeBenchmarkSU4Adjoint();
    else if (group_info==SU4TwoIndexSymmetricGroupInfo)
        executeBenchmarkSU4TwoIndexSymmetric();
    else if (group_info==SU4TwoIndexAntiSymmetricGroupInfo)
        executeBenchmarkSU4TwoIndexAntiSymmetric();
    else if (group_info==Sp4FundamentalGroupInfo)
        executeBenchmarkSp4Fundamental();
    else if (group_info==Sp4TwoIndexSymmetricGroupInfo)
        executeBenchmarkSp4TwoIndexSymmetric();
    else if (group_info==Sp4TwoIndexAntiSymmetricGroupInfo)
        executeBenchmarkSp4TwoIndexAntiSymmetric();
    else
        std::cout << "No benchmark is available for '" << group_info.tag() << "'" << std::endl;
}
