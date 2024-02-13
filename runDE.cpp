//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// runDE.cpp
//
// Code generation for function 'runDE'
//

// Include files
#include "runDE.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "deopt.h"
#include "length.h"
#include "packParams.h"
#include "reflectivityCalculation.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "unpackParams.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>
#include <stdio.h>

// Function Definitions
namespace RAT
{
  struct_T intrafun(const ::coder::array<real_T, 2U> &p, d_struct_T
                    *problemStruct, const char_T controls_parallel_data[], const
                    int32_T controls_parallel_size[2], const real_T
                    controls_resamPars[2], boolean_T controls_calcSldDuringFit,
                    const struct3_T *controls_checks, const ::coder::array<
                    cell_wrap_2, 2U> &problemCells_f1, const ::coder::array<
                    cell_wrap_8, 2U> &problemCells_f2, const ::coder::array<
                    cell_wrap_2, 2U> &problemCells_f3, const ::coder::array<
                    cell_wrap_2, 2U> &problemCells_f4, const ::coder::array<
                    cell_wrap_8, 2U> &problemCells_f5, const ::coder::array<
                    cell_wrap_8, 1U> &problemCells_f6, const ::coder::array<
                    cell_wrap_1, 2U> &problemCells_f14, const ::coder::array<
                    cell_wrap_8, 2U> &problemCells_f19)
  {
    cell_11 expl_temp;
    cell_wrap_9 a__2[6];
    e_struct_T b_problemStruct;
    struct2_T b_expl_temp;
    struct_T S_MSE;
    int32_T i;
    int32_T loop_ub;
    problemStruct->fitParams.set_size(1, p.size(1));
    loop_ub = p.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct->fitParams[problemStruct->fitParams.size(0) * i] = p[i];
    }

    unpackParams(problemStruct, controls_checks->fitParam,
                 controls_checks->fitBackgroundParam,
                 controls_checks->fitQzshift, controls_checks->fitScalefactor,
                 controls_checks->fitBulkIn, controls_checks->fitBulkOut,
                 controls_checks->fitResolutionParam,
                 controls_checks->fitDomainRatio);
    expl_temp.f19.set_size(1, problemCells_f19.size(1));
    loop_ub = problemCells_f19.size(1);
    for (i = 0; i < loop_ub; i++) {
      expl_temp.f19[i] = problemCells_f19[i];
    }

    expl_temp.f14.set_size(1, problemCells_f14.size(1));
    loop_ub = problemCells_f14.size(1);
    for (i = 0; i < loop_ub; i++) {
      expl_temp.f14[i] = problemCells_f14[i];
    }

    expl_temp.f6.set_size(problemCells_f6.size(0));
    loop_ub = problemCells_f6.size(0);
    for (i = 0; i < loop_ub; i++) {
      expl_temp.f6[i] = problemCells_f6[i];
    }

    expl_temp.f5.set_size(1, problemCells_f5.size(1));
    loop_ub = problemCells_f5.size(1);
    for (i = 0; i < loop_ub; i++) {
      expl_temp.f5[i] = problemCells_f5[i];
    }

    expl_temp.f4.set_size(1, problemCells_f4.size(1));
    loop_ub = problemCells_f4.size(1);
    for (i = 0; i < loop_ub; i++) {
      expl_temp.f4[i] = problemCells_f4[i];
    }

    expl_temp.f3.set_size(1, problemCells_f3.size(1));
    loop_ub = problemCells_f3.size(1);
    for (i = 0; i < loop_ub; i++) {
      expl_temp.f3[i] = problemCells_f3[i];
    }

    expl_temp.f2.set_size(1, problemCells_f2.size(1));
    loop_ub = problemCells_f2.size(1);
    for (i = 0; i < loop_ub; i++) {
      expl_temp.f2[i] = problemCells_f2[i];
    }

    expl_temp.f1.set_size(1, problemCells_f1.size(1));
    loop_ub = problemCells_f1.size(1);
    for (i = 0; i < loop_ub; i++) {
      expl_temp.f1[i] = problemCells_f1[i];
    }

    b_expl_temp.checks = *controls_checks;
    b_expl_temp.calcSldDuringFit = controls_calcSldDuringFit;
    b_expl_temp.resamPars[0] = controls_resamPars[0];
    b_expl_temp.resamPars[1] = controls_resamPars[1];
    b_expl_temp.parallel.size[0] = 1;
    b_expl_temp.parallel.size[1] = controls_parallel_size[1];
    loop_ub = controls_parallel_size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&controls_parallel_data[0], &controls_parallel_data[loop_ub],
                &b_expl_temp.parallel.data[0]);
    }

    reflectivityCalculation(problemStruct, &expl_temp, &b_expl_temp,
      &b_problemStruct, a__2);
    S_MSE.FVr_oa = b_problemStruct.calculations.sumChi;
    S_MSE.I_nc = 0.0;

    // no constraints                 THESE FIRST FEW VALS MAY BE WRONG
    S_MSE.FVr_ca = 0.0;

    // no constraint array
    S_MSE.I_no = 1.0;

    // number of objectives (costs)
    return S_MSE;
  }

  void runDE(d_struct_T *problemStruct, const cell_11 *problemCells, const
             struct1_T *problemLimits, const struct2_T *controls, e_struct_T
             *contrastParams, cell_wrap_9 result[6])
  {
    static const real_T FVr_x[50]{ -1.0, -0.95918367346938771,
      -0.91836734693877542, -0.87755102040816324, -0.836734693877551,
      -0.79591836734693866, -0.75510204081632648, -0.71428571428571419,
      -0.673469387755102, -0.63265306122448972, -0.59183673469387754,
      -0.55102040816326525, -0.51020408163265307, -0.46938775510204078,
      -0.42857142857142855, -0.38775510204081631, -0.34693877551020408,
      -0.30612244897959179, -0.26530612244897955, -0.22448979591836732,
      -0.18367346938775508, -0.14285714285714285, -0.1020408163265306,
      -0.061224489795918366, -0.020408163265306121, 0.020408163265306121,
      0.061224489795918366, 0.1020408163265306, 0.14285714285714285,
      0.18367346938775508, 0.22448979591836732, 0.26530612244897955,
      0.30612244897959179, 0.34693877551020408, 0.38775510204081631,
      0.42857142857142855, 0.46938775510204078, 0.51020408163265307,
      0.55102040816326525, 0.59183673469387754, 0.63265306122448972,
      0.673469387755102, 0.71428571428571419, 0.75510204081632648,
      0.79591836734693866, 0.836734693877551, 0.87755102040816324,
      0.91836734693877542, 0.95918367346938771, 1.0 };

    ::coder::array<cell_wrap_1, 1U> b_problemStruct;
    ::coder::array<real_T, 2U> res;
    ::coder::array<int8_T, 2U> S_struct_FM_pop;
    k_struct_T expl_temp;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    packParams(problemStruct, problemCells->f7, problemCells->f8,
               problemCells->f9, problemCells->f10, problemCells->f11,
               problemCells->f12, problemCells->f13, problemCells->f20,
               problemLimits, &controls->checks, b_problemStruct);

    // Value to reach
    loop_ub = problemStruct->fitLimits.size(0);
    expl_temp.FVr_minbound.set_size(1, loop_ub);
    for (i = 0; i < loop_ub; i++) {
      expl_temp.FVr_minbound[i] = problemStruct->fitLimits[i];
    }

    loop_ub = problemStruct->fitLimits.size(0);
    expl_temp.FVr_maxbound.set_size(1, loop_ub);
    for (i = 0; i < loop_ub; i++) {
      expl_temp.FVr_maxbound[i] = problemStruct->fitLimits[i +
        problemStruct->fitLimits.size(0)];
    }

    // 1: use bounds as bound constraints, 0: no bound constraints
    //  I_NP            number of population members
    //  I_itermax       maximum number of iterations (generations)
    //  fWeight        DE-stepsize fWeight ex [0, 2]
    //  F_CR            crossover probability constant ex [0, 1]
    //  I_strategy     1 --> DE/rand/1:
    //                       the classical version of DE.
    //                 2 --> DE/local-to-best/1:
    //                       a version which has been used by quite a number
    //                       of scientists. Attempts a balance between robustness
    //                       and fast convergence.
    //                 3 --> DE/best/1 with jitter:
    //                       taylored for small population sizes and fast convergence.
    //                       Dimensionality should not be too high.
    //                 4 --> DE/rand/1 with per-vector-dither:
    //                       Classical DE with dither to become even more robust.
    //                 5 --> DE/rand/1 with per-generation-dither:
    //                       Classical DE with dither to become even more robust.
    //                       Choosing fWeight = 0.3 is a good start here.
    //                 6 --> DE/rand/1 either-or-algorithm:
    //                       Alternates between differential mutation and three-point-
    //                       recombination.
    //  I_refresh     intermediate output will be produced after "I_refresh"
    //                iterations. No intermediate output will be produced
    //                if I_refresh is < 1
    //  I_plotting    Will use plotting if set to 1. Will skip plotting otherwise.
    // -----Definition of tolerance scheme--------------------------------------
    // -----The scheme is sampled at I_lentol points----------------------------
    // ordinate running from -1 to +1
    // upper limit is 1
    // lower limit is -1
    // Tell compiler abut variable sizes
    // -----tie all important values to a structure that can be passed along----
    expl_temp.FVr_x.size[0] = 1;
    expl_temp.FVr_x.size[1] = 50;
    std::copy(&FVr_x[0], &FVr_x[50], &expl_temp.FVr_x.data[0]);
    loop_ub = static_cast<int32_T>(controls->populationSize);
    S_struct_FM_pop.set_size(loop_ub, 2);
    expl_temp.FVr_bestmem.set_size(1, 2);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        S_struct_FM_pop[i1 + S_struct_FM_pop.size(0) * i] = 0;
      }

      expl_temp.FVr_bestmem[i] = 0.0;
    }

    expl_temp.FM_pop.set_size(S_struct_FM_pop.size(0), 2);
    loop_ub = S_struct_FM_pop.size(0);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        expl_temp.FM_pop[i1 + expl_temp.FM_pop.size(0) * i] = 0.0;
      }
    }

    expl_temp.I_plotting = 0.0;
    expl_temp.I_refresh = 1.0;
    expl_temp.I_strategy = 5.0;
    expl_temp.F_VTR = controls->targetValue;
    expl_temp.I_itermax = controls->numGenerations;
    expl_temp.I_bnd_constr = 1.0;
    expl_temp.I_D = coder::internal::intlength(problemStruct->fitParams.size(0),
      problemStruct->fitParams.size(1));
    expl_temp.F_CR = controls->crossoverProbability;
    expl_temp.fWeight = controls->fWeight;
    expl_temp.I_NP = controls->populationSize;
    expl_temp.FVr_lim_lo.size[0] = 1;
    expl_temp.FVr_lim_lo.size[1] = 50;
    expl_temp.FVr_lim_up.size[0] = 1;
    expl_temp.FVr_lim_up.size[1] = 50;
    for (i = 0; i < 50; i++) {
      expl_temp.FVr_lim_lo.data[i] = -1.0;
      expl_temp.FVr_lim_up.data[i] = 1.0;
    }

    expl_temp.I_lentol.size[0] = 1;
    expl_temp.I_lentol.data[0] = 50.0;
    deopt(problemStruct, problemCells->f1, problemCells->f2, problemCells->f3,
          problemCells->f4, problemCells->f5, problemCells->f6,
          problemCells->f14, problemCells->f19, controls->parallel.data,
          controls->parallel.size, controls->resamPars,
          controls->calcSldDuringFit, controls->display.data,
          controls->display.size, &controls->checks, &expl_temp, res);
    problemStruct->fitParams.set_size(1, res.size(1));
    loop_ub = res.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct->fitParams[problemStruct->fitParams.size(0) * i] = res[i];
    }

    unpackParams(problemStruct, controls->checks.fitParam,
                 controls->checks.fitBackgroundParam,
                 controls->checks.fitQzshift, controls->checks.fitScalefactor,
                 controls->checks.fitBulkIn, controls->checks.fitBulkOut,
                 controls->checks.fitResolutionParam,
                 controls->checks.fitDomainRatio);
    reflectivityCalculation(problemStruct, problemCells, controls,
      contrastParams, result);
    if (!coder::internal::q_strcmp(controls->display.data,
         controls->display.size)) {
      printf("Final chi squared is %g\n", contrastParams->calculations.sumChi);
      fflush(stdout);
    }
  }
}

// End of code generation (runDE.cpp)
