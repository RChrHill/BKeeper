#include "Flops.hpp"
#include "LatticeParameters.hpp"


size_t spinColourMatrixMulFlops(size_t fermion_rep_elements)
{
    // Is there a different formulation for adjoint?
    return SPIN_COMPONENTS*fermion_rep_elements*SPIN_COMPONENTS*fermion_rep_elements - (SPIN_COMPONENTS/2) * fermion_rep_elements;
}


static constexpr size_t REAL_OP_FLOPS      = 1;
static constexpr size_t COMPLEX_SUM_FLOPS  = 2;
static constexpr size_t COMPLEX_MUL_FLOPS  = 6;
static constexpr size_t COMPLEX_MULR_FLOPS = 2; // TODO: VERIFY THIS
static constexpr size_t COMPLEX_NORM_FLOPS = 3;


size_t colourVectorSumFlops (size_t fermion_rep_elements) { return fermion_rep_elements*COMPLEX_SUM_FLOPS;  }
size_t colourVectorMulFlops (size_t fermion_rep_elements) { return fermion_rep_elements*COMPLEX_MULR_FLOPS; } // TODO: VERIFY THIS
size_t colourVectorNormFlops(size_t fermion_rep_elements) { return fermion_rep_elements*COMPLEX_NORM_FLOPS; }


size_t spinColourVectorSumFlops (size_t fermion_rep_elements) { return colourVectorSumFlops (fermion_rep_elements)*SPIN_COMPONENTS; }
size_t spinColourVectorMulFlops (size_t fermion_rep_elements) { return colourVectorMulFlops (fermion_rep_elements)*SPIN_COMPONENTS; }
size_t spinColourVectorNormFlops(size_t fermion_rep_elements) { return colourVectorNormFlops(fermion_rep_elements)*SPIN_COMPONENTS; }
size_t spinColourVectorMulAddAssignFlops(size_t fermion_rep_elements) 
{ 
    return spinColourVectorSumFlops(fermion_rep_elements) + spinColourVectorMulFlops(fermion_rep_elements);
}


double RBSpinColourVectorNormSqFlops      (size_t fermion_rep_elements) { return (1.f/2)*spinColourVectorNormFlops        (fermion_rep_elements); }
double RBSpinColourVectorMulAddAssignFlops(size_t fermion_rep_elements) { return (1.f/2)*spinColourVectorMulAddAssignFlops(fermion_rep_elements); }
double RBSpinColourVectorMulFlops         (size_t fermion_rep_elements) { return (1.f/2)*spinColourVectorMulFlops         (fermion_rep_elements); }
double RBSpinColourVectorSubFlops         (size_t fermion_rep_elements) { return (1.f/2)*spinColourVectorSumFlops         (fermion_rep_elements); }
double RBSpinColourVectorProdReFlops      (size_t fermion_rep_elements) { return RBSpinColourVectorNormSqFlops            (fermion_rep_elements); }
double RBSpinColourVectorAddAssignFlops   (size_t fermion_rep_elements) { return (1.f/2)*spinColourVectorSumFlops         (fermion_rep_elements); }
double RBSpinColourVectorMinusFlops       (size_t fermion_rep_elements) { return (1.f/2)*spinColourVectorMulFlops         (fermion_rep_elements); }


// Action specific
double WilsonSiteFlops(size_t fermion_rep_elements)
{
    return (1.f/2) * (16 * spinColourMatrixMulFlops(fermion_rep_elements) + 45 * spinColourVectorSumFlops(fermion_rep_elements));
}

double addCloverSiteFlops(size_t fermion_rep_elements)
{
    return (1.f/2) * (8 * spinColourMatrixMulFlops(fermion_rep_elements) + 4 * spinColourVectorSumFlops(fermion_rep_elements) + spinColourVectorMulAddAssignFlops(fermion_rep_elements));
}

double addAssignCloverSiteFlops(size_t fermion_rep_elements)
{
    return addCloverSiteFlops(fermion_rep_elements) + (1.f/2) * spinColourVectorSumFlops(fermion_rep_elements);
}

double CloverMatSize(size_t fermion_rep_elements) { return 2 * fermion_rep_elements; }

double CloverForwardSubstitutionLoopFlop(size_t fermion_rep_elements)
{
    double prefactor = CloverMatSize(fermion_rep_elements)*(CloverMatSize(fermion_rep_elements)-1) / 2;
    return prefactor * (3*REAL_OP_FLOPS + 2*(COMPLEX_MUL_FLOPS + COMPLEX_SUM_FLOPS));
}

double CloverBackwardSubstitutionLoopFlop(size_t fermion_rep_elements)
{
    double res = 0;

    for (int i=CloverMatSize(fermion_rep_elements)-1; i >= 0; --i)
    {
        res += 3;
        res += COMPLEX_MULR_FLOPS;
        res += COMPLEX_MULR_FLOPS;
        for (int k=i+1; k < CloverMatSize(fermion_rep_elements); ++k)
        {
            res += 3;
            res += COMPLEX_MUL_FLOPS + COMPLEX_SUM_FLOPS;
            res += COMPLEX_MUL_FLOPS + COMPLEX_SUM_FLOPS;
        }
    }
    return res;
}


double CloverInversionFlops(size_t fermion_rep_elements)
{
    return (1.f/2)*(CloverForwardSubstitutionLoopFlop(fermion_rep_elements) + CloverBackwardSubstitutionLoopFlop(fermion_rep_elements));
}

double CloverInversionAssignFlops(size_t fermion_rep_elements)
{
    return CloverInversionFlops(fermion_rep_elements) + (1.f/2)*spinColourVectorSumFlops(fermion_rep_elements);
}

double G5CloverEvenOddPrecSqFlops(size_t fermion_rep_elements)
{
    return 2 * (WilsonSiteFlops             (fermion_rep_elements) + 
                CloverInversionFlops        (fermion_rep_elements) + 
                WilsonSiteFlops             (fermion_rep_elements) + 
                RBSpinColourVectorMinusFlops(fermion_rep_elements) + 
                addAssignCloverSiteFlops    (fermion_rep_elements));
}


double CloverCGOutOfLoopSiteFlops(double site_operator_flops, size_t fermion_rep_elements) 
{
    return (RBSpinColourVectorNormSqFlops      (fermion_rep_elements) + 
            site_operator_flops +
            RBSpinColourVectorMulAddAssignFlops(fermion_rep_elements) +
            RBSpinColourVectorSubFlops         (fermion_rep_elements) +
            RBSpinColourVectorNormSqFlops      (fermion_rep_elements) + 
            site_operator_flops +
            RBSpinColourVectorMulAddAssignFlops(fermion_rep_elements) +
            RBSpinColourVectorSubFlops         (fermion_rep_elements) +
            2 * RBSpinColourVectorNormSqFlops  (fermion_rep_elements));
}


double CloverCGIterationSiteFlops(double site_operator_flops, size_t fermion_rep_elements)
{
    return site_operator_flops + 
        RBSpinColourVectorProdReFlops      (fermion_rep_elements) +
        RBSpinColourVectorMulAddAssignFlops(fermion_rep_elements) + 
        RBSpinColourVectorMulAddAssignFlops(fermion_rep_elements) + 
        RBSpinColourVectorNormSqFlops      (fermion_rep_elements) + 
        RBSpinColourVectorMulFlops         (fermion_rep_elements) + 
        RBSpinColourVectorAddAssignFlops   (fermion_rep_elements) + 
        RBSpinColourVectorMulFlops         (fermion_rep_elements) + 
        RBSpinColourVectorAddAssignFlops   (fermion_rep_elements);
}


double CloverCGSiteFlops(double iterations, size_t fermion_rep_elements)
{
    double site_operator_flops = G5CloverEvenOddPrecSqFlops(fermion_rep_elements);
    double flops_per_site      = CloverCGIterationSiteFlops(site_operator_flops, fermion_rep_elements) * iterations;
    flops_per_site             += CloverCGOutOfLoopSiteFlops(site_operator_flops, fermion_rep_elements);
    return flops_per_site / 1e9;
}
