#include "Benchmark.hpp"
#include "Global.h" // Contains macros for executeBenchmark template parameters


int main(int argc, char** argv)
{
    initGrid(argc, argv);

    std::cout << GridLogMessage << "==================================================" << std::endl;
    
    #ifdef BKEEPER_DEFAULTGAUGEGROUP
    std::cout << GridLogMessage << "No gauge group defined by autotools: defaulting to SU" << std::endl;
    #endif

    #ifdef BKEEPER_DEFAULTNC
    std::cout << GridLogMessage << "No number of colours defined by autotools: defaulting to 3" << std::endl;
    #endif

    #ifdef BKEEPER_DEFAULTREPRESENTATION
    std::cout << GridLogMessage << "No group representation defined by autotools: defaulting to Fundamental" << std::endl;
    #endif

    // Message to remind which group + rep the benchmark was compiled for.
    std::cout << GridLogMessage << "Using ";
    if constexpr(std::is_same_v<BKEEPER_GAUGEGROUP, Grid::GroupName::SU>)
        std::cout << "SU";
    else if constexpr(std::is_same_v<BKEEPER_GAUGEGROUP, Grid::GroupName::Sp>)
        std::cout << "Sp";
    std::cout << "(" << BKEEPER_NC << ")";
    constexpr RepresentationName repname = BKEEPER_REPRESENTATION;
    switch(repname)
    {
        case RepresentationName::Fundamental:
            std::cout << ", Fundamental";
            break;
        case RepresentationName::Adjoint:
            std::cout << ", Adjoint";
            break;
        case RepresentationName::TwoIndexSymmetric:
            std::cout << ", TwoIndexSymmetric";
            break;
        case RepresentationName::TwoIndexAntiSymmetric:
            std::cout << ", TwoIndexAntiSymmetric";
            break;
        default:
            break;
    }
    std::cout << " representation" << std::endl;

    std::cout << GridLogMessage << "==================================================" << std::endl;
    
    executeBenchmark<BKEEPER_GAUGEGROUP, BKEEPER_NC, BKEEPER_REPRESENTATION>();
    teardownGrid();
    return 0;
}
