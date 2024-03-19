//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// runDREAM.cpp
//
// Code generation for function 'runDREAM'
//

// Include files
#include "runDREAM.h"
#include "RATMain_internal_types.h"
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "getFittedPriors.h"
#include "makeEmptyBayesResultsStruct.h"
#include "mean.h"
#include "packParams.h"
#include "processBayes.h"
#include "ratDREAM.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>
#include <cmath>

// Function Definitions
namespace RAT
{
  void runDREAM(const f_struct_T *problemStruct, const cell_11 *problemCells,
                const struct1_T *problemLimits, const struct2_T *controls, const
                struct4_T *priors, f_struct_T *outProblemStruct, struct5_T
                *result, j_struct_T *bayesResults)
  {
    static f_struct_T b_problemStruct;
    ::coder::array<cell_wrap_1, 1U> fitParamNames;
    ::coder::array<real_T, 2U> Par_info_max;
    ::coder::array<real_T, 2U> Par_info_min;
    ::coder::array<real_T, 2U> a__1;
    ::coder::array<real_T, 2U> b_bayesResults;
    ::coder::array<real_T, 2U> c_bayesResults;
    ::coder::array<real_T, 2U> r;
    i_struct_T dreamResults;
    int32_T b_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T i2;
    int32_T i3;
    int32_T i4;
    int32_T loop_ub;

    //  Make an empty struct for bayesResults to hold the outputs of the
    //  calculation
    makeEmptyBayesResultsStruct(problemStruct->numberOfContrasts, coder::
      internal::b_strcmp(problemStruct->TF.data, problemStruct->TF.size),
      controls->nChains, bayesResults->bestFitsMean.ref,
      bayesResults->bestFitsMean.sld, &bayesResults->bestFitsMean.chi,
      bayesResults->bestFitsMean.data, bayesResults->predlims.refPredInts,
      bayesResults->predlims.sldPredInts, bayesResults->predlims.refXdata,
      bayesResults->predlims.sldXdata, bayesResults->predlims.sampleChi.data,
      &bayesResults->predlims.sampleChi.size[0], bayesResults->parConfInts.par95,
      bayesResults->parConfInts.par65, bayesResults->parConfInts.mean,
      bayesResults->bestPars, &bayesResults->bayesRes, bayesResults->chain);

    //  Pre-allocation
    b_problemStruct = *problemStruct;
    packParams(&b_problemStruct, problemCells->f7, problemCells->f8,
               problemCells->f9, problemCells->f10, problemCells->f11,
               problemCells->f12, problemCells->f13, problemCells->f20,
               problemLimits, &controls->checks, fitParamNames);

    //  Get the priors for the fitted parameters...
    //  Put all the RAT parameters together into one array...
    //  Get the parameters from the user
    //  Total number of generations
    //  Number of chains
    //  Set the relevant parameters for the DREAM sampler....
    //  Dimension of the problem
    //  Number of Markov Chains
    //  Number of generations per chain
    // DREAMPar.lik = 1;                              % Model output is likelihood
    //  Parallel or not...
    //  Jump probabilities...
    //  This will change...
    //  Initial sampling and parameter range
    loop_ub = b_problemStruct.fitLimits.size(0);
    Par_info_min.set_size(1, b_problemStruct.fitLimits.size(0));
    for (i = 0; i < loop_ub; i++) {
      Par_info_min[i] = b_problemStruct.fitLimits[i];
    }

    loop_ub = b_problemStruct.fitLimits.size(0);
    Par_info_max.set_size(1, b_problemStruct.fitLimits.size(0));
    for (i = 0; i < loop_ub; i++) {
      Par_info_max[i] = b_problemStruct.fitLimits[i +
        b_problemStruct.fitLimits.size(0)];
    }

    // if dreamC.prior
    // end
    //  Run the sampler....
    // [chain,output,fx] = rat_DREAM(DREAMPar,Par_info,[],ratInputs);
    // Func_name = @DREAMWrapper;
    getFittedPriors(fitParamNames, priors->priorNames, priors->priorValues,
                    b_problemStruct.fitLimits, r);
    ratDREAM(static_cast<real_T>(fitParamNames.size(0)), controls->nChains, std::
             ceil(controls->nSamples / controls->nChains),
             controls->jumpProbability, controls->pUnitGamma, controls->adaptPCR,
             Par_info_min, Par_info_max, controls->boundHandling.data,
             controls->boundHandling.size, &b_problemStruct, problemCells,
             problemLimits, controls, r, bayesResults->bayesRes.allChains,
             &bayesResults->bayesRes.dreamOutput, a__1);

    //  Combine all chains....
    bayesResults->chain.set_size(0, 0);
    i = static_cast<int32_T>(controls->nChains);
    if (0 <= i - 1) {
      int32_T cutoff;
      if (1 > fitParamNames.size(0)) {
        i1 = 0;
      } else {
        i1 = fitParamNames.size(0);
      }

      cutoff = static_cast<int32_T>(std::floor(static_cast<real_T>
        (bayesResults->bayesRes.allChains.size(0)) * 0.25));
      if (cutoff > bayesResults->bayesRes.allChains.size(0)) {
        i2 = -1;
        i3 = -1;
      } else {
        i2 = cutoff - 2;
        i3 = bayesResults->bayesRes.allChains.size(0) - 1;
      }

      i4 = i1 - 1;
      b_loop_ub = i1 - 1;
    }

    for (int32_T b_i{0}; b_i < i; b_i++) {
      int32_T b_result;
      int32_T c_loop_ub;
      int32_T i5;
      int32_T i6;
      int32_T sizes_idx_0;
      boolean_T empty_non_axis_sizes;

      //  Keep only the last 75% of the chain..
      //  Combine the parallel chains into one....
      if ((bayesResults->chain.size(0) != 0) && (bayesResults->chain.size(1) !=
           0)) {
        b_result = bayesResults->chain.size(1);
      } else if ((i3 - i2 != 0) && (i1 != 0)) {
        b_result = i1;
      } else {
        b_result = bayesResults->chain.size(1);
        if (i1 > bayesResults->chain.size(1)) {
          b_result = i1;
        }
      }

      empty_non_axis_sizes = (b_result == 0);
      if (empty_non_axis_sizes || ((bayesResults->chain.size(0) != 0) &&
           (bayesResults->chain.size(1) != 0))) {
        loop_ub = bayesResults->chain.size(0);
      } else {
        loop_ub = 0;
      }

      if (empty_non_axis_sizes || ((i3 - i2 != 0) && (i1 != 0))) {
        sizes_idx_0 = i3 - i2;
      } else {
        sizes_idx_0 = 0;
      }

      c_loop_ub = i3 - i2;
      b_bayesResults.set_size(c_loop_ub, i4 + 1);
      for (i5 = 0; i5 <= b_loop_ub; i5++) {
        for (i6 = 0; i6 < c_loop_ub; i6++) {
          b_bayesResults[i6 + b_bayesResults.size(0) * i5] =
            bayesResults->bayesRes.allChains[(((i2 + i6) +
            bayesResults->bayesRes.allChains.size(0) * i5) +
            bayesResults->bayesRes.allChains.size(0) *
            bayesResults->bayesRes.allChains.size(1) * b_i) + 1];
        }
      }

      c_bayesResults.set_size(loop_ub + sizes_idx_0, b_result);
      for (i5 = 0; i5 < b_result; i5++) {
        for (i6 = 0; i6 < loop_ub; i6++) {
          c_bayesResults[i6 + c_bayesResults.size(0) * i5] = bayesResults->
            chain[i6 + loop_ub * i5];
        }
      }

      for (i5 = 0; i5 < b_result; i5++) {
        for (i6 = 0; i6 < sizes_idx_0; i6++) {
          c_bayesResults[(i6 + loop_ub) + c_bayesResults.size(0) * i5] =
            b_bayesResults[i6 + sizes_idx_0 * i5];
        }
      }

      bayesResults->chain.set_size(c_bayesResults.size(0), c_bayesResults.size(1));
      loop_ub = c_bayesResults.size(1);
      for (i5 = 0; i5 < loop_ub; i5++) {
        c_loop_ub = c_bayesResults.size(0);
        for (i6 = 0; i6 < c_loop_ub; i6++) {
          bayesResults->chain[i6 + bayesResults->chain.size(0) * i5] =
            c_bayesResults[i6 + c_bayesResults.size(0) * i5];
        }
      }
    }

    coder::mean(bayesResults->chain, bayesResults->bestPars);
    processBayes(bayesResults->bestPars, bayesResults->chain, &b_problemStruct,
                 controls, problemLimits, problemCells, outProblemStruct, result,
                 &dreamResults);

    //  Populate the output struct
    //  bayesResults.bayesRes.allChains = chain;
    cast(dreamResults.predlims.refPredInts, bayesResults->predlims.refPredInts);
    cast(dreamResults.predlims.sldPredInts, bayesResults->predlims.sldPredInts);
    bayesResults->predlims.refXdata.set_size(dreamResults.predlims.refXdata.size
      (0));
    for (i = 0; i < dreamResults.predlims.refXdata.size(0); i++) {
      bayesResults->predlims.refXdata[i].f1.set_size(1,
        dreamResults.predlims.refXdata[i].f1.size(1));
      loop_ub = dreamResults.predlims.refXdata[i].f1.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        bayesResults->predlims.refXdata[i].f1[bayesResults->predlims.refXdata[i]
          .f1.size(0) * i1] = dreamResults.predlims.refXdata[i].f1[i1];
      }
    }

    cast(dreamResults.predlims.sldXdata, bayesResults->predlims.sldXdata);
    bayesResults->predlims.sampleChi.size[0] = 1000;
    std::copy(&dreamResults.predlims.sampleChi[0],
              &dreamResults.predlims.sampleChi[1000],
              &bayesResults->predlims.sampleChi.data[0]);
    bayesResults->parConfInts = dreamResults.parConfInts;
    cast(dreamResults.bestFitsMean.ref, bayesResults->bestFitsMean.ref);
    bayesResults->bestFitsMean.sld.set_size(dreamResults.bestFitsMean.sld.size(0),
      dreamResults.bestFitsMean.sld.size(1));
    loop_ub = dreamResults.bestFitsMean.sld.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = dreamResults.bestFitsMean.sld.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        bayesResults->bestFitsMean.sld[i1 + bayesResults->bestFitsMean.sld.size
          (0) * i] = dreamResults.bestFitsMean.sld[i1 +
          dreamResults.bestFitsMean.sld.size(0) * i];
      }
    }

    bayesResults->bestFitsMean.chi = dreamResults.bestFitsMean.chi;
    cast(dreamResults.bestFitsMean.data, bayesResults->bestFitsMean.data);

    //  These are not defined in makeEmptyBayesResultsStruct
    //  bayesResults.bayesRes.DREAMPar = DREAMPar;
    //  bayesResults.bayesRes.Meas_info = Meas_info;
    //  bayesResults.bayesRes.dreamOutput = output;
  }
}

// End of code generation (runDREAM.cpp)
