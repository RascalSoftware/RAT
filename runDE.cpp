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
#include "packParams.h"
#include "reflectivityCalculation.h"
#include "rt_nonfinite.h"
#include "sprintf.h"
#include "strcmp.h"
#include "triggerEvent.h"
#include "unpackParams.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>

// Function Definitions
namespace RAT
{
  void intrafun(const ::coder::array<real_T, 2U> &p, d_struct_T *problemStruct,
                const cell_13 *problemCells, const struct1_T *problemLimits,
                const struct2_T *controls, struct_T *S_MSE, e_struct_T *result)
  {
    int32_T loop_ub;
    problemStruct->fitParams.set_size(p.size(1));
    loop_ub = p.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      problemStruct->fitParams[i] = p[i];
    }

    unpackParams(problemStruct, controls->checks.fitParam,
                 controls->checks.fitBackgroundParam,
                 controls->checks.fitQzshift, controls->checks.fitScalefactor,
                 controls->checks.fitBulkIn, controls->checks.fitBulkOut,
                 controls->checks.fitResolutionParam,
                 controls->checks.fitDomainRatio);
    reflectivityCalculation(problemStruct, problemCells, problemLimits, controls,
      result);
    S_MSE->FVr_oa = result->calculationResults.sumChi;
    S_MSE->I_nc = 0.0;

    // no constraints                 THESE FIRST FEW VALS MAY BE WRONG
    S_MSE->FVr_ca = 0.0;

    // no constraint array
    S_MSE->I_no = 1.0;

    // number of objectives (costs)
  }

  void runDE(const d_struct_T *problemStruct, const cell_13 *problemCells, const
             struct1_T *problemLimits, const struct2_T *controls, g_struct_T
             *b_problemStruct, struct5_T *result)
  {
    static const real_T S_struct_FVr_x[50]{ -1.0, -0.95918367346938771,
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

    ::coder::array<cell_wrap_1, 1U> d_problemStruct;
    ::coder::array<real_T, 2U> res;
    ::coder::array<char_T, 2U> charStr;
    ::coder::array<int8_T, 2U> S_struct_FM_pop;
    d_struct_T c_problemStruct;
    h_struct_T expl_temp;
    int32_T b_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    c_problemStruct = *problemStruct;
    packParams(&c_problemStruct, problemCells->f7, problemCells->f8,
               problemCells->f9, problemCells->f10, problemCells->f11,
               problemCells->f12, problemCells->f13, problemCells->f20,
               problemLimits, &controls->checks, d_problemStruct);

    // Value to reach
    loop_ub = c_problemStruct.fitLimits.size(0);
    expl_temp.FVr_minbound.set_size(1, c_problemStruct.fitLimits.size(0));
    for (i = 0; i < loop_ub; i++) {
      expl_temp.FVr_minbound[i] = c_problemStruct.fitLimits[i];
    }

    loop_ub = c_problemStruct.fitLimits.size(0);
    expl_temp.FVr_maxbound.set_size(1, c_problemStruct.fitLimits.size(0));
    for (i = 0; i < loop_ub; i++) {
      expl_temp.FVr_maxbound[i] = c_problemStruct.fitLimits[i +
        c_problemStruct.fitLimits.size(0)];
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
    expl_temp.I_strategy = controls->strategy;
    expl_temp.F_VTR = controls->targetValue;
    expl_temp.I_itermax = controls->numGenerations;
    expl_temp.I_bnd_constr = 1.0;
    expl_temp.I_D = c_problemStruct.fitParams.size(0);
    expl_temp.F_CR = controls->crossoverProbability;
    expl_temp.fWeight = controls->fWeight;
    expl_temp.I_NP = controls->populationSize;
    for (i = 0; i < 50; i++) {
      expl_temp.FVr_lim_lo[i] = -1.0;
      expl_temp.FVr_lim_up[i] = 1.0;
      expl_temp.FVr_x[i] = S_struct_FVr_x[i];
    }

    expl_temp.I_lentol = 50.0;
    deopt(&c_problemStruct, problemCells, problemLimits, controls, &expl_temp,
          res);
    b_problemStruct->TF.size[0] = 1;
    b_problemStruct->TF.size[1] = c_problemStruct.TF.size[1];
    loop_ub = c_problemStruct.TF.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&c_problemStruct.TF.data[0], &c_problemStruct.TF.data[loop_ub],
                &b_problemStruct->TF.data[0]);
    }

    b_problemStruct->resample.set_size(1, c_problemStruct.resample.size(1));
    loop_ub = c_problemStruct.resample.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->resample[i] = c_problemStruct.resample[i];
    }

    b_problemStruct->dataPresent.set_size(1, c_problemStruct.dataPresent.size(1));
    loop_ub = c_problemStruct.dataPresent.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->dataPresent[i] = c_problemStruct.dataPresent[i];
    }

    b_problemStruct->oilChiDataPresent.set_size(1,
      c_problemStruct.oilChiDataPresent.size(1));
    loop_ub = c_problemStruct.oilChiDataPresent.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->oilChiDataPresent[i] =
        c_problemStruct.oilChiDataPresent[i];
    }

    b_problemStruct->numberOfContrasts = c_problemStruct.numberOfContrasts;
    b_problemStruct->geometry.size[0] = 1;
    b_problemStruct->geometry.size[1] = c_problemStruct.geometry.size[1];
    loop_ub = c_problemStruct.geometry.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&c_problemStruct.geometry.data[0],
                &c_problemStruct.geometry.data[loop_ub],
                &b_problemStruct->geometry.data[0]);
    }

    b_problemStruct->useImaginary = c_problemStruct.useImaginary;
    b_problemStruct->contrastBackgroundParams.set_size(1,
      c_problemStruct.contrastBackgroundParams.size(1));
    loop_ub = c_problemStruct.contrastBackgroundParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->contrastBackgroundParams[i] =
        c_problemStruct.contrastBackgroundParams[i];
    }

    b_problemStruct->contrastBackgroundActions.set_size(1,
      c_problemStruct.contrastBackgroundActions.size(1));
    loop_ub = c_problemStruct.contrastBackgroundActions.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->contrastBackgroundActions[i] =
        c_problemStruct.contrastBackgroundActions[i];
    }

    b_problemStruct->contrastQzshifts.set_size(1,
      c_problemStruct.contrastQzshifts.size(1));
    loop_ub = c_problemStruct.contrastQzshifts.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->contrastQzshifts[i] = c_problemStruct.contrastQzshifts[i];
    }

    b_problemStruct->contrastScalefactors.set_size(1,
      c_problemStruct.contrastScalefactors.size(1));
    loop_ub = c_problemStruct.contrastScalefactors.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->contrastScalefactors[i] =
        c_problemStruct.contrastScalefactors[i];
    }

    b_problemStruct->contrastBulkIns.set_size(1,
      c_problemStruct.contrastBulkIns.size(1));
    loop_ub = c_problemStruct.contrastBulkIns.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->contrastBulkIns[i] = c_problemStruct.contrastBulkIns[i];
    }

    b_problemStruct->contrastBulkOuts.set_size(1,
      c_problemStruct.contrastBulkOuts.size(1));
    loop_ub = c_problemStruct.contrastBulkOuts.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->contrastBulkOuts[i] = c_problemStruct.contrastBulkOuts[i];
    }

    b_problemStruct->contrastResolutionParams.set_size(1,
      c_problemStruct.contrastResolutionParams.size(1));
    loop_ub = c_problemStruct.contrastResolutionParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->contrastResolutionParams[i] =
        c_problemStruct.contrastResolutionParams[i];
    }

    b_problemStruct->backgroundParams.set_size(1,
      c_problemStruct.backgroundParams.size(1));
    loop_ub = c_problemStruct.backgroundParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->backgroundParams[i] = c_problemStruct.backgroundParams[i];
    }

    b_problemStruct->qzshifts.set_size(1, c_problemStruct.qzshifts.size(1));
    loop_ub = c_problemStruct.qzshifts.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->qzshifts[i] = c_problemStruct.qzshifts[i];
    }

    b_problemStruct->scalefactors.set_size(1, c_problemStruct.scalefactors.size
      (1));
    loop_ub = c_problemStruct.scalefactors.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->scalefactors[i] = c_problemStruct.scalefactors[i];
    }

    b_problemStruct->bulkIn.set_size(1, c_problemStruct.bulkIn.size(1));
    loop_ub = c_problemStruct.bulkIn.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->bulkIn[i] = c_problemStruct.bulkIn[i];
    }

    b_problemStruct->bulkOut.set_size(1, c_problemStruct.bulkOut.size(1));
    loop_ub = c_problemStruct.bulkOut.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->bulkOut[i] = c_problemStruct.bulkOut[i];
    }

    b_problemStruct->resolutionParams.set_size(1,
      c_problemStruct.resolutionParams.size(1));
    loop_ub = c_problemStruct.resolutionParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->resolutionParams[i] = c_problemStruct.resolutionParams[i];
    }

    b_problemStruct->params.set_size(1, c_problemStruct.params.size(1));
    loop_ub = c_problemStruct.params.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->params[i] = c_problemStruct.params[i];
    }

    b_problemStruct->numberOfLayers = c_problemStruct.numberOfLayers;
    b_problemStruct->modelType.size[0] = 1;
    b_problemStruct->modelType.size[1] = c_problemStruct.modelType.size[1];
    loop_ub = c_problemStruct.modelType.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&c_problemStruct.modelType.data[0],
                &c_problemStruct.modelType.data[loop_ub],
                &b_problemStruct->modelType.data[0]);
    }

    b_problemStruct->contrastCustomFiles.set_size(1,
      c_problemStruct.contrastCustomFiles.size(1));
    loop_ub = c_problemStruct.contrastCustomFiles.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->contrastCustomFiles[i] =
        c_problemStruct.contrastCustomFiles[i];
    }

    b_problemStruct->contrastDomainRatios.set_size(1,
      c_problemStruct.contrastDomainRatios.size(1));
    loop_ub = c_problemStruct.contrastDomainRatios.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->contrastDomainRatios[i] =
        c_problemStruct.contrastDomainRatios[i];
    }

    b_problemStruct->domainRatio.set_size(1, c_problemStruct.domainRatio.size(1));
    loop_ub = c_problemStruct.domainRatio.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->domainRatio[i] = c_problemStruct.domainRatio[i];
    }

    b_problemStruct->numberOfDomainContrasts =
      c_problemStruct.numberOfDomainContrasts;
    b_problemStruct->otherParams.set_size(c_problemStruct.otherParams.size(0));
    loop_ub = c_problemStruct.otherParams.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->otherParams[i] = c_problemStruct.otherParams[i];
    }

    b_problemStruct->fitLimits.set_size(c_problemStruct.fitLimits.size(0), 2);
    b_problemStruct->otherLimits.set_size(c_problemStruct.otherLimits.size(0), 2);
    loop_ub = c_problemStruct.fitLimits.size(0);
    b_loop_ub = c_problemStruct.otherLimits.size(0);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_problemStruct->fitLimits[i1 + b_problemStruct->fitLimits.size(0) * i] =
          c_problemStruct.fitLimits[i1 + c_problemStruct.fitLimits.size(0) * i];
      }

      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b_problemStruct->otherLimits[i1 + b_problemStruct->otherLimits.size(0) *
          i] = c_problemStruct.otherLimits[i1 + c_problemStruct.otherLimits.size
          (0) * i];
      }
    }

    b_problemStruct->fitParams.set_size(1, res.size(1));
    loop_ub = res.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->fitParams[b_problemStruct->fitParams.size(0) * i] = res[i];
    }

    unpackParams(b_problemStruct, controls->checks.fitParam,
                 controls->checks.fitBackgroundParam,
                 controls->checks.fitQzshift, controls->checks.fitScalefactor,
                 controls->checks.fitBulkIn, controls->checks.fitBulkOut,
                 controls->checks.fitResolutionParam,
                 controls->checks.fitDomainRatio);
    reflectivityCalculation(b_problemStruct, problemCells, problemLimits,
      controls, result);
    if (!coder::internal::p_strcmp(controls->display.data,
         controls->display.size)) {
      coder::snPrint(result->calculationResults.sumChi, charStr);
      triggerEvent(charStr);
    }
  }
}

// End of code generation (runDE.cpp)
