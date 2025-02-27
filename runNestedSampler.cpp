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

// Function Declarations
namespace RAT
{
  static void cast(const ::coder::array<cell_wrap_11, 1U>
                   &t0_predictionIntervals_reflectivity, const ::coder::array<
                   cell_wrap_11, 2U> &t0_predictionIntervals_sld, const double
                   t0_predictionIntervals_sampleChi_data[], int
                   t0_predictionIntervals_sampleChi_size, const ::coder::array<
                   double, 2U> &t0_confidenceIntervals_percentile95, const ::
                   coder::array<double, 2U> &t0_confidenceIntervals_percentile65,
                   const ::coder::array<double, 2U> &t0_confidenceIntervals_mean,
                   const DreamParams *t0_dreamParams, const DreamOutput
                   *t0_dreamOutput, const c_struct_T t0_nestedSamplerOutput,
                   const ::coder::array<double, 2U> &t0_chain, ::coder::array<
                   cell_wrap_11, 1U> &t1_predictionIntervals_reflectivity, ::
                   coder::array<cell_wrap_11, 2U> &t1_predictionIntervals_sld,
                   double t1_predictionIntervals_sampleChi_data[], int
                   *t1_predictionIntervals_sampleChi_size, ::coder::array<double,
                   2U> &t1_confidenceIntervals_percentile95, ::coder::array<
                   double, 2U> &t1_confidenceIntervals_percentile65, ::coder::
                   array<double, 2U> &t1_confidenceIntervals_mean, DreamParams
                   *t1_dreamParams, DreamOutput *t1_dreamOutput,
                   NestedSamplerOutput *t1_nestedSamplerOutput, ::coder::array<
                   double, 2U> &t1_chain);
}

// Function Definitions
namespace RAT
{
  static void cast(const ::coder::array<cell_wrap_11, 1U>
                   &t0_predictionIntervals_reflectivity, const ::coder::array<
                   cell_wrap_11, 2U> &t0_predictionIntervals_sld, const double
                   t0_predictionIntervals_sampleChi_data[], int
                   t0_predictionIntervals_sampleChi_size, const ::coder::array<
                   double, 2U> &t0_confidenceIntervals_percentile95, const ::
                   coder::array<double, 2U> &t0_confidenceIntervals_percentile65,
                   const ::coder::array<double, 2U> &t0_confidenceIntervals_mean,
                   const DreamParams *t0_dreamParams, const DreamOutput
                   *t0_dreamOutput, const c_struct_T t0_nestedSamplerOutput,
                   const ::coder::array<double, 2U> &t0_chain, ::coder::array<
                   cell_wrap_11, 1U> &t1_predictionIntervals_reflectivity, ::
                   coder::array<cell_wrap_11, 2U> &t1_predictionIntervals_sld,
                   double t1_predictionIntervals_sampleChi_data[], int
                   *t1_predictionIntervals_sampleChi_size, ::coder::array<double,
                   2U> &t1_confidenceIntervals_percentile95, ::coder::array<
                   double, 2U> &t1_confidenceIntervals_percentile65, ::coder::
                   array<double, 2U> &t1_confidenceIntervals_mean, DreamParams
                   *t1_dreamParams, DreamOutput *t1_dreamOutput,
                   NestedSamplerOutput *t1_nestedSamplerOutput, ::coder::array<
                   double, 2U> &t1_chain)
  {
    int b_loop_ub;
    int i;
    int i1;
    int loop_ub;
    t1_predictionIntervals_reflectivity.set_size
      (t0_predictionIntervals_reflectivity.size(0));
    loop_ub = t0_predictionIntervals_reflectivity.size(0);
    for (i = 0; i < loop_ub; i++) {
      t1_predictionIntervals_reflectivity[i] =
        t0_predictionIntervals_reflectivity[i];
    }

    t1_predictionIntervals_sld.set_size(t0_predictionIntervals_sld.size(0),
      t0_predictionIntervals_sld.size(1));
    loop_ub = t0_predictionIntervals_sld.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = t0_predictionIntervals_sld.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        t1_predictionIntervals_sld[i1 + t1_predictionIntervals_sld.size(0) * i] =
          t0_predictionIntervals_sld[i1 + t0_predictionIntervals_sld.size(0) * i];
      }
    }

    *t1_predictionIntervals_sampleChi_size =
      t0_predictionIntervals_sampleChi_size;
    if (0 <= t0_predictionIntervals_sampleChi_size - 1) {
      std::copy(&t0_predictionIntervals_sampleChi_data[0],
                &t0_predictionIntervals_sampleChi_data[t0_predictionIntervals_sampleChi_size],
                &t1_predictionIntervals_sampleChi_data[0]);
    }

    t1_confidenceIntervals_percentile95.set_size(2,
      t0_confidenceIntervals_percentile95.size(1));
    loop_ub = t0_confidenceIntervals_percentile95.size(1);
    for (i = 0; i < loop_ub; i++) {
      t1_confidenceIntervals_percentile95[2 * i] =
        t0_confidenceIntervals_percentile95[2 * i];
      t1_confidenceIntervals_percentile95[2 * i + 1] =
        t0_confidenceIntervals_percentile95[2 * i + 1];
    }

    t1_confidenceIntervals_percentile65.set_size(2,
      t0_confidenceIntervals_percentile65.size(1));
    loop_ub = t0_confidenceIntervals_percentile65.size(1);
    for (i = 0; i < loop_ub; i++) {
      t1_confidenceIntervals_percentile65[2 * i] =
        t0_confidenceIntervals_percentile65[2 * i];
      t1_confidenceIntervals_percentile65[2 * i + 1] =
        t0_confidenceIntervals_percentile65[2 * i + 1];
    }

    t1_confidenceIntervals_mean.set_size(1, t0_confidenceIntervals_mean.size(1));
    loop_ub = t0_confidenceIntervals_mean.size(1);
    for (i = 0; i < loop_ub; i++) {
      t1_confidenceIntervals_mean[i] = t0_confidenceIntervals_mean[i];
    }

    *t1_dreamParams = *t0_dreamParams;
    *t1_dreamOutput = *t0_dreamOutput;
    t1_nestedSamplerOutput->LogZ = t0_nestedSamplerOutput.LogZ;
    t1_nestedSamplerOutput->LogZErr = t0_nestedSamplerOutput.LogZErr;
    t1_nestedSamplerOutput->nestSamples.set_size(1, 2);
    t1_nestedSamplerOutput->postSamples.set_size(1, 2);
    t1_nestedSamplerOutput->nestSamples[0] =
      t0_nestedSamplerOutput.nestSamples.data[0];
    t1_nestedSamplerOutput->postSamples[0] =
      t0_nestedSamplerOutput.postSamples.data[0];
    t1_nestedSamplerOutput->nestSamples[t1_nestedSamplerOutput->nestSamples.size
      (0)] = t0_nestedSamplerOutput.nestSamples.data[1];
    t1_nestedSamplerOutput->postSamples[t1_nestedSamplerOutput->postSamples.size
      (0)] = t0_nestedSamplerOutput.postSamples.data[1];
    t1_chain.set_size(t0_chain.size(0), t0_chain.size(1));
    loop_ub = t0_chain.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = t0_chain.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        t1_chain[i1 + t1_chain.size(0) * i] = t0_chain[i1 + t0_chain.size(0) * i];
      }
    }
  }

  void runNestedSampler(ProblemDefinition *problemStruct, const ::coder::array<
                        double, 2U> &problemLimits_params, const ::coder::array<
                        double, 2U> &problemLimits_backgroundParams, const ::
                        coder::array<double, 2U> &problemLimits_scalefactors,
                        const ::coder::array<double, 2U> &problemLimits_bulkIns,
                        const ::coder::array<double, 2U> &problemLimits_bulkOuts,
                        const ::coder::array<double, 2U>
                        &problemLimits_resolutionParams, const ::coder::array<
                        double, 2U> &problemLimits_domainRatios, const Controls *
                        controls, Results *result, PredictionIntervals
                        *bayesResults_predictionIntervals, ConfidenceIntervals
                        *bayesResults_confidenceIntervals, DreamParams
                        *bayesResults_dreamParams, DreamOutput
                        *bayesResults_dreamOutput, NestedSamplerOutput
                        *bayesResults_nestedSamplerOutput, ::coder::array<double,
                        2U> &bayesResults_chain)
  {
    static Controls b_controls;
    ::coder::array<cell_wrap_10, 1U> fitNames;
    ::coder::array<cell_wrap_11, 2U> t8_predictionIntervals_sld;
    ::coder::array<cell_wrap_11, 1U> t8_predictionIntervals_reflectivity;
    ::coder::array<double, 2U> bayesOutputs_bestParams;
    ::coder::array<double, 2U> bayesOutputs_chain;
    ::coder::array<double, 2U> bayesResults_nestedSamplerOutpu;
    ::coder::array<double, 2U> r;
    ::coder::array<double, 2U> t8_chain;
    ::coder::array<double, 2U> t8_confidenceIntervals_mean;
    ::coder::array<double, 2U> t8_confidenceIntervals_percentile65;
    ::coder::array<double, 2U> t8_confidenceIntervals_percentile95;
    DreamOutput t8_dreamOutput;
    DreamParams t8_dreamParams;
    c_struct_T t8_nestedSamplerOutput;
    f_struct_T nestResults;
    double t8_predictionIntervals_sampleChi_data[1000];
    double H;
    int i;
    int i1;
    int loop_ub;
    int t8_predictionIntervals_sampleChi_size;
    packParams(problemStruct, problemLimits_params,
               problemLimits_backgroundParams, problemLimits_scalefactors,
               problemLimits_bulkIns, problemLimits_bulkOuts,
               problemLimits_resolutionParams, problemLimits_domainRatios,
               fitNames);

    //  Make an empty struct for bayesResults to hold the outputs of the
    //  calculation
    b_makeEmptyBayesResultsStruct(problemStruct->numberOfContrasts, coder::
      internal::b_strcmp(problemStruct->TF.data, problemStruct->TF.size),
      t8_predictionIntervals_reflectivity, t8_predictionIntervals_sld,
      t8_predictionIntervals_sampleChi_data,
      &t8_predictionIntervals_sampleChi_size,
      t8_confidenceIntervals_percentile95, t8_confidenceIntervals_percentile65,
      t8_confidenceIntervals_mean, &t8_dreamParams, &t8_dreamOutput,
      &t8_nestedSamplerOutput, t8_chain);
    cast(t8_predictionIntervals_reflectivity, t8_predictionIntervals_sld,
         t8_predictionIntervals_sampleChi_data,
         t8_predictionIntervals_sampleChi_size,
         t8_confidenceIntervals_percentile95,
         t8_confidenceIntervals_percentile65, t8_confidenceIntervals_mean,
         &t8_dreamParams, &t8_dreamOutput, t8_nestedSamplerOutput, t8_chain,
         bayesResults_predictionIntervals->reflectivity,
         bayesResults_predictionIntervals->sld,
         bayesResults_predictionIntervals->sampleChi.data,
         &bayesResults_predictionIntervals->sampleChi.size[0],
         bayesResults_confidenceIntervals->percentile95,
         bayesResults_confidenceIntervals->percentile65,
         bayesResults_confidenceIntervals->mean, bayesResults_dreamParams,
         bayesResults_dreamOutput, bayesResults_nestedSamplerOutput,
         bayesResults_chain);

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
      t8_predictionIntervals_sampleChi_size = 0;
    } else {
      t8_predictionIntervals_sampleChi_size = fitNames.size(0);
    }

    loop_ub = bayesResults_nestedSamplerOutput->postSamples.size(0);
    bayesResults_nestedSamplerOutpu.set_size
      (bayesResults_nestedSamplerOutput->postSamples.size(0),
       t8_predictionIntervals_sampleChi_size);
    for (i = 0; i < t8_predictionIntervals_sampleChi_size; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        bayesResults_nestedSamplerOutpu[i1 +
          bayesResults_nestedSamplerOutpu.size(0) * i] =
          bayesResults_nestedSamplerOutput->postSamples[i1 +
          bayesResults_nestedSamplerOutput->postSamples.size(0) * i];
      }
    }

    coder::blockedSummation(bayesResults_nestedSamplerOutpu,
      bayesResults_nestedSamplerOutput->postSamples.size(0),
      t8_confidenceIntervals_mean);
    bayesOutputs_bestParams.set_size(1, t8_confidenceIntervals_mean.size(1));
    loop_ub = t8_confidenceIntervals_mean.size(1);
    for (i = 0; i < loop_ub; i++) {
      bayesOutputs_bestParams[i] = t8_confidenceIntervals_mean[i] / static_cast<
        double>(bayesResults_nestedSamplerOutput->postSamples.size(0));
    }

    loop_ub = bayesResults_nestedSamplerOutput->postSamples.size(0);
    bayesOutputs_chain.set_size
      (bayesResults_nestedSamplerOutput->postSamples.size(0),
       t8_predictionIntervals_sampleChi_size);
    for (i = 0; i < t8_predictionIntervals_sampleChi_size; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
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
    loop_ub = nestResults.predictionIntervals.reflectivity.size(0);
    for (i = 0; i < loop_ub; i++) {
      bayesResults_predictionIntervals->reflectivity[i] =
        nestResults.predictionIntervals.reflectivity[i];
    }

    bayesResults_predictionIntervals->sld.set_size
      (nestResults.predictionIntervals.sld.size(0),
       nestResults.predictionIntervals.sld.size(1));
    loop_ub = nestResults.predictionIntervals.sld.size(1);
    for (i = 0; i < loop_ub; i++) {
      int b_loop_ub;
      b_loop_ub = nestResults.predictionIntervals.sld.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
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
    loop_ub = bayesResults_nestedSamplerOutput->postSamples.size(0);
    bayesResults_chain.set_size
      (bayesResults_nestedSamplerOutput->postSamples.size(0),
       t8_predictionIntervals_sampleChi_size);
    for (i = 0; i < t8_predictionIntervals_sampleChi_size; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        bayesResults_chain[i1 + bayesResults_chain.size(0) * i] =
          bayesResults_nestedSamplerOutput->postSamples[i1 +
          bayesResults_nestedSamplerOutput->postSamples.size(0) * i];
      }
    }

    bayesResults_nestedSamplerOutput->LogZErr = std::sqrt(H / controls->nLive);
  }
}

// End of code generation (runNestedSampler.cpp)
