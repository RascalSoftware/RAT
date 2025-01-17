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
  void runDREAM(const e_struct_T *problemStruct, const struct3_T *problemLimits,
                const struct4_T *controls, const struct5_T *priors, e_struct_T
                *outProblemStruct, struct6_T *result, g_struct_T *bayesResults)
  {
    static struct4_T b_controls;
    ::coder::array<cell_wrap_8, 1U> fitParamNames;
    ::coder::array<real_T, 2U> ParInfo_max;
    ::coder::array<real_T, 2U> ParInfo_min;
    ::coder::array<real_T, 2U> a__1;
    ::coder::array<real_T, 2U> b_bayesResults;
    ::coder::array<real_T, 2U> c_bayesResults;
    ::coder::array<real_T, 2U> r;
    ::coder::array<real_T, 2U> r1;
    i_struct_T dreamResults;
    j_struct_T dreamOutput;
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
      controls->nChains, bayesResults->predictionIntervals.reflectivity,
      bayesResults->predictionIntervals.sld,
      bayesResults->predictionIntervals.sampleChi.data,
      &bayesResults->predictionIntervals.sampleChi.size[0],
      bayesResults->confidenceIntervals.percentile95,
      bayesResults->confidenceIntervals.percentile65,
      bayesResults->confidenceIntervals.mean, &bayesResults->dreamParams,
      &bayesResults->dreamOutput, &bayesResults->nestedSamplerOutput,
      bayesResults->chain);

    //  Pre-allocation
    *outProblemStruct = *problemStruct;
    packParams(outProblemStruct, problemLimits->params,
               problemLimits->backgroundParams, problemLimits->scalefactors,
               problemLimits->qzshifts, problemLimits->bulkIns,
               problemLimits->bulkOuts, problemLimits->resolutionParams,
               problemLimits->domainRatios, fitParamNames);

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
    loop_ub = outProblemStruct->fitLimits.size(0);
    ParInfo_min.set_size(1, outProblemStruct->fitLimits.size(0));
    for (i = 0; i < loop_ub; i++) {
      ParInfo_min[i] = outProblemStruct->fitLimits[i];
    }

    loop_ub = outProblemStruct->fitLimits.size(0);
    ParInfo_max.set_size(1, outProblemStruct->fitLimits.size(0));
    for (i = 0; i < loop_ub; i++) {
      ParInfo_max[i] = outProblemStruct->fitLimits[i +
        outProblemStruct->fitLimits.size(0)];
    }

    //  Run the sampler....
    getFittedPriors(fitParamNames, priors->priorNames, priors->priorValues,
                    outProblemStruct->fitLimits, r);
    ratDREAM(static_cast<real_T>(fitParamNames.size(0)), controls->nChains, std::
             ceil(controls->nSamples / controls->nChains),
             controls->jumpProbability, controls->pUnitGamma, controls->adaptPCR,
             ParInfo_min, ParInfo_max, controls->boundHandling.data,
             controls->boundHandling.size, outProblemStruct, controls, r,
             bayesResults->dreamOutput.allChains, &dreamOutput, a__1);

    //  Combine all chains....
    bayesResults->chain.set_size(0, 0);
    i = static_cast<int32_T>(controls->nChains);
    if (0 <= static_cast<int32_T>(controls->nChains) - 1) {
      int32_T cutoff;
      if (1 > fitParamNames.size(0)) {
        i1 = 0;
      } else {
        i1 = fitParamNames.size(0);
      }

      cutoff = static_cast<int32_T>(std::floor(static_cast<real_T>
        (bayesResults->dreamOutput.allChains.size(0)) * 0.25));
      if (cutoff > bayesResults->dreamOutput.allChains.size(0)) {
        i2 = -1;
        i3 = -1;
      } else {
        i2 = cutoff - 2;
        i3 = bayesResults->dreamOutput.allChains.size(0) - 1;
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
            bayesResults->dreamOutput.allChains[(((i2 + i6) +
            bayesResults->dreamOutput.allChains.size(0) * i5) +
            bayesResults->dreamOutput.allChains.size(0) *
            bayesResults->dreamOutput.allChains.size(1) * b_i) + 1];
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

    coder::mean(bayesResults->chain, r1);
    b_controls = *controls;
    processBayes(r1, bayesResults->chain, outProblemStruct, &b_controls, result,
                 &dreamResults);

    //  Populate the output struct
    bayesResults->predictionIntervals.reflectivity.set_size
      (dreamResults.predictionIntervals.reflectivity.size(0));
    loop_ub = dreamResults.predictionIntervals.reflectivity.size(0);
    for (i = 0; i < loop_ub; i++) {
      bayesResults->predictionIntervals.reflectivity[i] =
        dreamResults.predictionIntervals.reflectivity[i];
    }

    bayesResults->predictionIntervals.sld.set_size
      (dreamResults.predictionIntervals.sld.size(0),
       dreamResults.predictionIntervals.sld.size(1));
    loop_ub = dreamResults.predictionIntervals.sld.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = dreamResults.predictionIntervals.sld.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        bayesResults->predictionIntervals.sld[i1 +
          bayesResults->predictionIntervals.sld.size(0) * i] =
          dreamResults.predictionIntervals.sld[i1 +
          dreamResults.predictionIntervals.sld.size(0) * i];
      }
    }

    bayesResults->predictionIntervals.sampleChi.size[0] = 1000;
    std::copy(&dreamResults.predictionIntervals.sampleChi[0],
              &dreamResults.predictionIntervals.sampleChi[1000],
              &bayesResults->predictionIntervals.sampleChi.data[0]);
    bayesResults->confidenceIntervals = dreamResults.confidenceIntervals;
    bayesResults->dreamParams = dreamOutput.DREAMPar;
    bayesResults->dreamOutput.outlierChains.size[0] =
      dreamOutput.outlierChains.size[0];
    bayesResults->dreamOutput.outlierChains.size[1] = 2;
    bayesResults->dreamOutput.runtime = dreamOutput.runtime;
    bayesResults->dreamOutput.iteration = dreamOutput.iteration;
    bayesResults->dreamOutput.modelOutput = 0.0;
    bayesResults->dreamOutput.AR.size[0] = dreamOutput.AR.size[0];
    bayesResults->dreamOutput.AR.size[1] = 2;
    loop_ub = dreamOutput.outlierChains.size[0];
    b_loop_ub = dreamOutput.AR.size[0];
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        bayesResults->dreamOutput.outlierChains.data[i1 +
          bayesResults->dreamOutput.outlierChains.size[0] * i] =
          dreamOutput.outlierChains.data[i1 + dreamOutput.outlierChains.size[0] *
          i];
      }

      for (i1 = 0; i1 < b_loop_ub; i1++) {
        bayesResults->dreamOutput.AR.data[i1 + bayesResults->
          dreamOutput.AR.size[0] * i] = dreamOutput.AR.data[i1 +
          dreamOutput.AR.size[0] * i];
      }
    }

    bayesResults->dreamOutput.R_stat.set_size(dreamOutput.R_stat.size(0),
      dreamOutput.R_stat.size(1));
    loop_ub = dreamOutput.R_stat.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = dreamOutput.R_stat.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        bayesResults->dreamOutput.R_stat[i1 +
          bayesResults->dreamOutput.R_stat.size(0) * i] = dreamOutput.R_stat[i1
          + dreamOutput.R_stat.size(0) * i];
      }
    }

    bayesResults->dreamOutput.CR.set_size(dreamOutput.CR.size(0), 4);
    loop_ub = dreamOutput.CR.size(0);
    for (i = 0; i < 4; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        bayesResults->dreamOutput.CR[i1 + bayesResults->dreamOutput.CR.size(0) *
          i] = dreamOutput.CR[i1 + dreamOutput.CR.size(0) * i];
      }
    }
  }
}

// End of code generation (runDREAM.cpp)
