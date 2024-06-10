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
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "getFittedPriors.h"
#include "makeEmptyBayesResultsStruct.h"
#include "mean.h"
#include "nestedSampler.h"
#include "packParams.h"
#include "processBayes.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>

// Function Definitions
namespace RAT
{
  void runNestedSampler(f_struct_T *problemStruct, const cell_11 *problemCells,
                        const struct1_T *problemLimits, const struct2_T
                        *controls, const struct4_T *inPriors, struct5_T *result,
                        struct8_T *bayesResults)
  {
    static struct2_T b_controls;
    ::coder::array<cell_wrap_1, 1U> fitNames;
    ::coder::array<cell_wrap_10, 2U> t6_predictionIntervals_sld;
    ::coder::array<cell_wrap_10, 2U> t6_predictionIntervals_sldXData;
    ::coder::array<cell_wrap_10, 1U> t6_predictionIntervals_reflectivity;
    ::coder::array<real_T, 2U> b_bayesResults;
    ::coder::array<real_T, 2U> b_expl_temp;
    ::coder::array<real_T, 2U> bayesOutputs_chain;
    ::coder::array<real_T, 2U> expl_temp_mean;
    ::coder::array<real_T, 2U> expl_temp_percentile65;
    ::coder::array<real_T, 2U> expl_temp_percentile95;
    ::coder::array<real_T, 2U> r;
    ::coder::array<real_T, 2U> r1;
    e_struct_T expl_temp;
    i_struct_T nestResults;
    real_T t6_predictionIntervals_sampleChi_data[1000];
    real_T bayesOutputs_bestParams_data[51];
    real_T H;
    real_T logZ;
    int32_T bayesOutputs_bestParams_size[2];
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    int32_T t6_predictionIntervals_sampleChi_size;
    packParams(problemStruct, problemCells->f7, problemCells->f8,
               problemCells->f9, problemCells->f10, problemCells->f11,
               problemCells->f12, problemCells->f13, problemCells->f20,
               problemLimits, &controls->checks, fitNames);

    //  Make an empty struct for bayesResults to hold the outputs of the
    //  calculation
    b_makeEmptyBayesResultsStruct(problemStruct->numberOfContrasts, coder::
      internal::b_strcmp(problemStruct->TF.data, problemStruct->TF.size),
      t6_predictionIntervals_reflectivity, t6_predictionIntervals_sld,
      bayesResults->predictionIntervals.reflectivityXData,
      t6_predictionIntervals_sldXData, t6_predictionIntervals_sampleChi_data,
      &t6_predictionIntervals_sampleChi_size, expl_temp_percentile95,
      expl_temp_percentile65, expl_temp_mean, &bayesResults->dreamParams,
      &bayesResults->dreamOutput, &expl_temp, b_expl_temp);

    // Deal with priors.
    // Tuning Parameters
    getFittedPriors(fitNames, inPriors->priorNames, inPriors->priorValues,
                    problemStruct->fitLimits, r);
    nestedSampler(problemStruct, controls, problemLimits, problemCells,
                  controls->nLive, controls->nMCMC, controls->nsTolerance, r,
                  &logZ, bayesResults->nestedSamplerOutput.nestSamples,
                  bayesResults->nestedSamplerOutput.postSamples, &H);

    //  Process the results...
    //  chain = nest_samples(:,1:end-1);
    if (1 > fitNames.size(0)) {
      t6_predictionIntervals_sampleChi_size = 0;
    } else {
      t6_predictionIntervals_sampleChi_size = fitNames.size(0);
    }

    loop_ub = bayesResults->nestedSamplerOutput.postSamples.size(0);
    b_bayesResults.set_size(bayesResults->nestedSamplerOutput.postSamples.size(0),
      t6_predictionIntervals_sampleChi_size);
    for (i = 0; i < t6_predictionIntervals_sampleChi_size; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_bayesResults[i1 + b_bayesResults.size(0) * i] =
          bayesResults->nestedSamplerOutput.postSamples[i1 +
          bayesResults->nestedSamplerOutput.postSamples.size(0) * i];
      }
    }

    coder::mean(b_bayesResults, r1);
    bayesOutputs_bestParams_size[0] = 1;
    bayesOutputs_bestParams_size[1] = r1.size(1);
    loop_ub = r1.size(1);
    for (i = 0; i < loop_ub; i++) {
      bayesOutputs_bestParams_data[i] = r1[i];
    }

    loop_ub = bayesResults->nestedSamplerOutput.postSamples.size(0);
    bayesOutputs_chain.set_size
      (bayesResults->nestedSamplerOutput.postSamples.size(0),
       t6_predictionIntervals_sampleChi_size);
    for (i = 0; i < t6_predictionIntervals_sampleChi_size; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        bayesOutputs_chain[i1 + bayesOutputs_chain.size(0) * i] =
          bayesResults->nestedSamplerOutput.postSamples[i1 +
          bayesResults->nestedSamplerOutput.postSamples.size(0) * i];
      }
    }

    b_controls = *controls;
    processBayes(bayesOutputs_bestParams_data, bayesOutputs_bestParams_size,
                 bayesOutputs_chain, problemStruct, problemCells, problemLimits,
                 &b_controls, result, &nestResults);
    cast(nestResults.predictionIntervals.reflectivity,
         bayesResults->predictionIntervals.reflectivity);
    cast(nestResults.predictionIntervals.sld,
         bayesResults->predictionIntervals.sld);
    bayesResults->predictionIntervals.reflectivityXData.set_size
      (nestResults.predictionIntervals.reflectivityXData.size(0));
    for (i = 0; i < nestResults.predictionIntervals.reflectivityXData.size(0); i
         ++) {
      bayesResults->predictionIntervals.reflectivityXData[i].f1.set_size(1,
        nestResults.predictionIntervals.reflectivityXData[i].f1.size(1));
      loop_ub = nestResults.predictionIntervals.reflectivityXData[i].f1.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        bayesResults->predictionIntervals.reflectivityXData[i].f1
          [bayesResults->predictionIntervals.reflectivityXData[i].f1.size(0) *
          i1] = nestResults.predictionIntervals.reflectivityXData[i].f1[i1];
      }
    }

    cast(nestResults.predictionIntervals.sldXData,
         bayesResults->predictionIntervals.sldXData);
    bayesResults->predictionIntervals.sampleChi.size[0] = 1000;
    std::copy(&nestResults.predictionIntervals.sampleChi[0],
              &nestResults.predictionIntervals.sampleChi[1000],
              &bayesResults->predictionIntervals.sampleChi.data[0]);
    bayesResults->confidenceIntervals = nestResults.confidenceIntervals;
    loop_ub = bayesResults->nestedSamplerOutput.postSamples.size(0);
    bayesResults->chain.set_size
      (bayesResults->nestedSamplerOutput.postSamples.size(0),
       t6_predictionIntervals_sampleChi_size);
    for (i = 0; i < t6_predictionIntervals_sampleChi_size; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        bayesResults->chain[i1 + bayesResults->chain.size(0) * i] =
          bayesResults->nestedSamplerOutput.postSamples[i1 +
          bayesResults->nestedSamplerOutput.postSamples.size(0) * i];
      }
    }

    bayesResults->nestedSamplerOutput.LogZ = logZ;
  }
}

// End of code generation (runNestedSampler.cpp)
