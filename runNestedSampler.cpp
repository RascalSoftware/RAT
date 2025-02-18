//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// runNestedSampler.cpp
//
// Code generation for function 'runNestedSampler'
//

// Include files
#include "runNestedSampler.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "blockedSummation.h"
#include "getFittedPriors.h"
#include "makeEmptyBayesResultsStruct.h"
#include "nestedSampler.h"
#include "packParams.h"
#include "processBayes.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>
#include <cmath>

// Function Definitions
namespace RAT
{
  void runNestedSampler(e_struct_T *problemStruct, const ::coder::array<real_T,
                        2U> &problemLimits_params, const ::coder::array<real_T,
                        2U> &problemLimits_backgroundParams, const ::coder::
                        array<real_T, 2U> &problemLimits_scalefactors, const ::
                        coder::array<real_T, 2U> &problemLimits_qzshifts, const ::
                        coder::array<real_T, 2U> &problemLimits_bulkIns, const ::
                        coder::array<real_T, 2U> &problemLimits_bulkOuts, const ::
                        coder::array<real_T, 2U> &problemLimits_resolutionParams,
                        const ::coder::array<real_T, 2U>
                        &problemLimits_domainRatios, const struct4_T *controls,
                        struct5_T *result, struct9_T
                        *bayesResults_predictionIntervals, struct10_T
                        *bayesResults_confidenceIntervals, struct11_T
                        *bayesResults_dreamParams, struct12_T
                        *bayesResults_dreamOutput, struct13_T
                        *bayesResults_nestedSamplerOutput, ::coder::array<real_T,
                        2U> &bayesResults_chain)
  {
    static struct4_T b_controls;
    ::coder::array<cell_wrap_10, 1U> fitNames;
    ::coder::array<cell_wrap_11, 2U> expl_temp_sld;
    ::coder::array<cell_wrap_11, 1U> expl_temp_reflectivity;
    ::coder::array<real_T, 2U> b_expl_temp;
    ::coder::array<real_T, 2U> bayesOutputs_bestParams;
    ::coder::array<real_T, 2U> bayesOutputs_chain;
    ::coder::array<real_T, 2U> bayesResults_nestedSamplerOutpu;
    ::coder::array<real_T, 2U> expl_temp_mean;
    ::coder::array<real_T, 2U> expl_temp_percentile65;
    ::coder::array<real_T, 2U> expl_temp_percentile95;
    ::coder::array<real_T, 2U> r;
    ::coder::array<real_T, 2U> r1;
    ::coder::bounded_array<real_T, 1000U, 1U> expl_temp_sampleChi;
    c_struct_T expl_temp;
    i_struct_T nestResults;
    real_T H;
    int32_T b_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    packParams(problemStruct, problemLimits_params,
               problemLimits_backgroundParams, problemLimits_scalefactors,
               problemLimits_qzshifts, problemLimits_bulkIns,
               problemLimits_bulkOuts, problemLimits_resolutionParams,
               problemLimits_domainRatios, fitNames);

    //  Make an empty struct for bayesResults to hold the outputs of the
    //  calculation
    b_makeEmptyBayesResultsStruct(problemStruct->numberOfContrasts, coder::
      internal::b_strcmp(problemStruct->TF.data, problemStruct->TF.size),
      expl_temp_reflectivity, expl_temp_sld, expl_temp_sampleChi.data,
      &expl_temp_sampleChi.size[0], expl_temp_percentile95,
      expl_temp_percentile65, expl_temp_mean, bayesResults_dreamParams,
      bayesResults_dreamOutput, &expl_temp, b_expl_temp);

    //  Deal with priors.
    //  Tuning Parameters
    getFittedPriors(fitNames, problemStruct->priorNames,
                    problemStruct->priorValues, problemStruct->fitLimits, r);
    nestedSampler(problemStruct, controls, controls->nLive, controls->nMCMC,
                  controls->nsTolerance, r,
                  &bayesResults_nestedSamplerOutput->LogZ,
                  bayesResults_nestedSamplerOutput->nestSamples,
                  bayesResults_nestedSamplerOutput->postSamples, &H);

    //  Process the results...
    //  chain = nest_samples(:,1:end-1);
    if (1 > fitNames.size(0)) {
      loop_ub = 0;
    } else {
      loop_ub = fitNames.size(0);
    }

    b_loop_ub = bayesResults_nestedSamplerOutput->postSamples.size(0);
    bayesResults_nestedSamplerOutpu.set_size
      (bayesResults_nestedSamplerOutput->postSamples.size(0), loop_ub);
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        bayesResults_nestedSamplerOutpu[i1 +
          bayesResults_nestedSamplerOutpu.size(0) * i] =
          bayesResults_nestedSamplerOutput->postSamples[i1 +
          bayesResults_nestedSamplerOutput->postSamples.size(0) * i];
      }
    }

    coder::blockedSummation(bayesResults_nestedSamplerOutpu,
      bayesResults_nestedSamplerOutput->postSamples.size(0), r1);
    bayesOutputs_bestParams.set_size(1, r1.size(1));
    b_loop_ub = r1.size(1);
    for (i = 0; i < b_loop_ub; i++) {
      bayesOutputs_bestParams[i] = r1[i] / static_cast<real_T>
        (bayesResults_nestedSamplerOutput->postSamples.size(0));
    }

    b_loop_ub = bayesResults_nestedSamplerOutput->postSamples.size(0);
    bayesOutputs_chain.set_size
      (bayesResults_nestedSamplerOutput->postSamples.size(0), loop_ub);
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        bayesOutputs_chain[i1 + bayesOutputs_chain.size(0) * i] =
          bayesResults_nestedSamplerOutput->postSamples[i1 +
          bayesResults_nestedSamplerOutput->postSamples.size(0) * i];
      }
    }

    b_controls = *controls;
    processBayes(bayesOutputs_bestParams, bayesOutputs_chain, problemStruct,
                 &b_controls, result, &nestResults);
    bayesResults_predictionIntervals->reflectivity.set_size
      (nestResults.predictionIntervals.reflectivity.size(0));
    b_loop_ub = nestResults.predictionIntervals.reflectivity.size(0);
    for (i = 0; i < b_loop_ub; i++) {
      bayesResults_predictionIntervals->reflectivity[i] =
        nestResults.predictionIntervals.reflectivity[i];
    }

    bayesResults_predictionIntervals->sld.set_size
      (nestResults.predictionIntervals.sld.size(0),
       nestResults.predictionIntervals.sld.size(1));
    b_loop_ub = nestResults.predictionIntervals.sld.size(1);
    for (i = 0; i < b_loop_ub; i++) {
      int32_T c_loop_ub;
      c_loop_ub = nestResults.predictionIntervals.sld.size(0);
      for (i1 = 0; i1 < c_loop_ub; i1++) {
        bayesResults_predictionIntervals->sld[i1 +
          bayesResults_predictionIntervals->sld.size(0) * i] =
          nestResults.predictionIntervals.sld[i1 +
          nestResults.predictionIntervals.sld.size(0) * i];
      }
    }

    bayesResults_predictionIntervals->sampleChi.size[0] = 1000;
    std::copy(&nestResults.predictionIntervals.sampleChi[0],
              &nestResults.predictionIntervals.sampleChi[1000],
              &bayesResults_predictionIntervals->sampleChi.data[0]);
    *bayesResults_confidenceIntervals = nestResults.confidenceIntervals;
    b_loop_ub = bayesResults_nestedSamplerOutput->postSamples.size(0);
    bayesResults_chain.set_size
      (bayesResults_nestedSamplerOutput->postSamples.size(0), loop_ub);
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        bayesResults_chain[i1 + bayesResults_chain.size(0) * i] =
          bayesResults_nestedSamplerOutput->postSamples[i1 +
          bayesResults_nestedSamplerOutput->postSamples.size(0) * i];
      }
    }

    bayesResults_nestedSamplerOutput->LogZErr = std::sqrt(H / controls->nLive);
  }
}

// End of code generation (runNestedSampler.cpp)
