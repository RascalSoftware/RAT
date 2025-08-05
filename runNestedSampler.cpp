//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include "getFitNames.h"
#include "getFittedPriors.h"
#include "makeEmptyBayesResultsStruct.h"
#include "nestedSampler.h"
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
  static int cast(const ::coder::array<cell_wrap_11, 1U>
                  &t0_predictionIntervals_reflectivity, const ::coder::array<
                  cell_wrap_11, 2U> &t0_predictionIntervals_sld, const double
                  t0_predictionIntervals_sampleChi_data[], int
                  t0_predictionIntervals_sampleChi_size, const ::coder::array<
                  double, 2U> &t0_confidenceIntervals_percentile95, const ::
                  coder::array<double, 2U> &t0_confidenceIntervals_percentile65,
                  const ::coder::array<double, 2U> &t0_confidenceIntervals_mean,
                  const DreamParams &t0_dreamParams, const DreamOutput &
                  t0_dreamOutput, const struct_T t0_nestedSamplerOutput, const ::
                  coder::array<double, 2U> &t0_chain, ::coder::array<
                  cell_wrap_11, 1U> &t1_predictionIntervals_reflectivity, ::
                  coder::array<cell_wrap_11, 2U> &t1_predictionIntervals_sld,
                  double t1_predictionIntervals_sampleChi_data[], ::coder::array<
                  double, 2U> &t1_confidenceIntervals_percentile95, ::coder::
                  array<double, 2U> &t1_confidenceIntervals_percentile65, ::
                  coder::array<double, 2U> &t1_confidenceIntervals_mean,
                  NestedSamplerOutput &t1_nestedSamplerOutput, ::coder::array<
                  double, 2U> &t1_chain, DreamParams &t1_dreamParams,
                  DreamOutput &t1_dreamOutput);
}

// Function Definitions
namespace RAT
{
  static int cast(const ::coder::array<cell_wrap_11, 1U>
                  &t0_predictionIntervals_reflectivity, const ::coder::array<
                  cell_wrap_11, 2U> &t0_predictionIntervals_sld, const double
                  t0_predictionIntervals_sampleChi_data[], int
                  t0_predictionIntervals_sampleChi_size, const ::coder::array<
                  double, 2U> &t0_confidenceIntervals_percentile95, const ::
                  coder::array<double, 2U> &t0_confidenceIntervals_percentile65,
                  const ::coder::array<double, 2U> &t0_confidenceIntervals_mean,
                  const DreamParams &t0_dreamParams, const DreamOutput &
                  t0_dreamOutput, const struct_T t0_nestedSamplerOutput, const ::
                  coder::array<double, 2U> &t0_chain, ::coder::array<
                  cell_wrap_11, 1U> &t1_predictionIntervals_reflectivity, ::
                  coder::array<cell_wrap_11, 2U> &t1_predictionIntervals_sld,
                  double t1_predictionIntervals_sampleChi_data[], ::coder::array<
                  double, 2U> &t1_confidenceIntervals_percentile95, ::coder::
                  array<double, 2U> &t1_confidenceIntervals_percentile65, ::
                  coder::array<double, 2U> &t1_confidenceIntervals_mean,
                  NestedSamplerOutput &t1_nestedSamplerOutput, ::coder::array<
                  double, 2U> &t1_chain, DreamParams &t1_dreamParams,
                  DreamOutput &t1_dreamOutput)
  {
    int b_loop_ub;
    int loop_ub;
    int t1_predictionIntervals_sampleChi_size;
    t1_predictionIntervals_reflectivity.set_size
      (t0_predictionIntervals_reflectivity.size(0));
    loop_ub = t0_predictionIntervals_reflectivity.size(0);
    for (int i{0}; i < loop_ub; i++) {
      t1_predictionIntervals_reflectivity[i] =
        t0_predictionIntervals_reflectivity[i];
    }

    t1_predictionIntervals_sld.set_size(t0_predictionIntervals_sld.size(0),
      t0_predictionIntervals_sld.size(1));
    loop_ub = t0_predictionIntervals_sld.size(1);
    for (int i{0}; i < loop_ub; i++) {
      b_loop_ub = t0_predictionIntervals_sld.size(0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        t1_predictionIntervals_sld[i1 + t1_predictionIntervals_sld.size(0) * i] =
          t0_predictionIntervals_sld[i1 + t0_predictionIntervals_sld.size(0) * i];
      }
    }

    t1_predictionIntervals_sampleChi_size =
      t0_predictionIntervals_sampleChi_size;
    if (t0_predictionIntervals_sampleChi_size - 1 >= 0) {
      std::copy(&t0_predictionIntervals_sampleChi_data[0],
                &t0_predictionIntervals_sampleChi_data[t0_predictionIntervals_sampleChi_size],
                &t1_predictionIntervals_sampleChi_data[0]);
    }

    t1_confidenceIntervals_percentile95.set_size(2,
      t0_confidenceIntervals_percentile95.size(1));
    loop_ub = t0_confidenceIntervals_percentile95.size(1);
    for (int i{0}; i < loop_ub; i++) {
      t1_confidenceIntervals_percentile95[2 * i] =
        t0_confidenceIntervals_percentile95[2 * i];
      t1_confidenceIntervals_percentile95[2 * i + 1] =
        t0_confidenceIntervals_percentile95[2 * i + 1];
    }

    t1_confidenceIntervals_percentile65.set_size(2,
      t0_confidenceIntervals_percentile65.size(1));
    loop_ub = t0_confidenceIntervals_percentile65.size(1);
    for (int i{0}; i < loop_ub; i++) {
      t1_confidenceIntervals_percentile65[2 * i] =
        t0_confidenceIntervals_percentile65[2 * i];
      t1_confidenceIntervals_percentile65[2 * i + 1] =
        t0_confidenceIntervals_percentile65[2 * i + 1];
    }

    t1_confidenceIntervals_mean.set_size(1, t0_confidenceIntervals_mean.size(1));
    loop_ub = t0_confidenceIntervals_mean.size(1);
    for (int i{0}; i < loop_ub; i++) {
      t1_confidenceIntervals_mean[i] = t0_confidenceIntervals_mean[i];
    }

    t1_dreamParams = t0_dreamParams;
    t1_dreamOutput = t0_dreamOutput;
    t1_nestedSamplerOutput.LogZ = t0_nestedSamplerOutput.LogZ;
    t1_nestedSamplerOutput.LogZErr = t0_nestedSamplerOutput.LogZErr;
    t1_nestedSamplerOutput.nestSamples.set_size(1, 2);
    t1_nestedSamplerOutput.postSamples.set_size(1, 2);
    t1_nestedSamplerOutput.nestSamples[0] =
      t0_nestedSamplerOutput.nestSamples.data[0];
    t1_nestedSamplerOutput.postSamples[0] =
      t0_nestedSamplerOutput.postSamples.data[0];
    t1_nestedSamplerOutput.nestSamples[t1_nestedSamplerOutput.nestSamples.size(0)]
      = t0_nestedSamplerOutput.nestSamples.data[1];
    t1_nestedSamplerOutput.postSamples[t1_nestedSamplerOutput.postSamples.size(0)]
      = t0_nestedSamplerOutput.postSamples.data[1];
    t1_chain.set_size(t0_chain.size(0), t0_chain.size(1));
    loop_ub = t0_chain.size(1);
    for (int i{0}; i < loop_ub; i++) {
      b_loop_ub = t0_chain.size(0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        t1_chain[i1 + t1_chain.size(0) * i] = t0_chain[i1 + t0_chain.size(0) * i];
      }
    }

    return t1_predictionIntervals_sampleChi_size;
  }

  int runNestedSampler(ProblemDefinition &problemStruct, const char
                       controls_parallel_data[], const int
                       controls_parallel_size[2], double
                       controls_numSimulationPoints, double
                       controls_resampleMinAngle, double
                       controls_resampleNPoints, const char
                       controls_display_data[], const int controls_display_size
                       [2], double controls_nLive, double controls_nMCMC, double
                       controls_nsTolerance, boolean_T controls_calcSLD, const
                       char controls_IPCFilePath_data[], const int
                       controls_IPCFilePath_size[2], b_struct_T &result, ::coder::
                       array<cell_wrap_11, 1U>
                       &bayesResults_predictionIntervals_reflectivity, ::coder::
                       array<cell_wrap_11, 2U>
                       &bayesResults_predictionIntervals_sld, double
                       bayesResults_predictionIntervals_sampleChi_data[],
                       ConfidenceIntervals &bayesResults_confidenceIntervals,
                       NestedSamplerOutput &bayesResults_nestedSamplerOutput, ::
                       coder::array<double, 2U> &bayesResults_chain, DreamParams
                       &bayesResults_dreamParams, DreamOutput &
                       bayesResults_dreamOutput)
  {
    static Controls expl_temp;
    ::coder::array<cell_wrap_10, 1U> fitNames;
    ::coder::array<cell_wrap_11, 2U> t8_predictionIntervals_sld;
    ::coder::array<cell_wrap_11, 1U> t8_predictionIntervals_reflectivity;
    ::coder::array<double, 2U> bayesOutputs_chain;
    ::coder::array<double, 2U> r;
    ::coder::array<double, 2U> t8_chain;
    ::coder::array<double, 2U> t8_confidenceIntervals_mean;
    ::coder::array<double, 2U> t8_confidenceIntervals_percentile65;
    ::coder::array<double, 2U> t8_confidenceIntervals_percentile95;
    DreamOutput t8_dreamOutput;
    DreamParams t8_dreamParams;
    e_struct_T nestResults;
    struct_T t8_nestedSamplerOutput;
    double t8_predictionIntervals_sampleChi_data[1000];
    double bayesOutputs_bestParams_data[51];
    double H;
    int bayesOutputs_bestParams_size[2];
    int b_loop_ub;
    int bayesResults_predictionIntervals_sampleChi_size;
    int loop_ub;
    int t8_predictionIntervals_sampleChi_size;

    //  Run the nested sampling algorithm for a given problem and controls.
    //
    //  Parameters
    //  ----------
    //  problemStruct : struct
    //      the Project struct.
    //  controls : struct
    //      the Controls struct.
    //
    //  Returns
    //  -------
    //  problemStruct : struct
    //      the output project struct.
    //  result : struct
    //      the calculation and optimisation results object.
    //  bayesResults : struct
    //      Additional Bayesian results from the algorithm.
    //
    getFitNames(problemStruct.names.params, problemStruct.names.backgroundParams,
                problemStruct.names.scalefactors, problemStruct.names.bulkIns,
                problemStruct.names.bulkOuts,
                problemStruct.names.resolutionParams,
                problemStruct.names.domainRatios, problemStruct.checks.params,
                problemStruct.checks.backgroundParams,
                problemStruct.checks.scalefactors, problemStruct.checks.bulkIns,
                problemStruct.checks.bulkOuts,
                problemStruct.checks.resolutionParams,
                problemStruct.checks.domainRatios, fitNames);

    //  Make an empty struct for bayesResults to hold the outputs of the
    //  calculation
    t8_predictionIntervals_sampleChi_size = b_makeEmptyBayesResultsStruct
      (problemStruct.numberOfContrasts, coder::internal::b_strcmp
       (problemStruct.TF.data, problemStruct.TF.size),
       t8_predictionIntervals_reflectivity, t8_predictionIntervals_sld,
       t8_predictionIntervals_sampleChi_data,
       t8_confidenceIntervals_percentile95, t8_confidenceIntervals_percentile65,
       t8_confidenceIntervals_mean, t8_dreamParams, t8_dreamOutput,
       t8_nestedSamplerOutput, t8_chain);
    cast(t8_predictionIntervals_reflectivity, t8_predictionIntervals_sld,
         t8_predictionIntervals_sampleChi_data,
         t8_predictionIntervals_sampleChi_size,
         t8_confidenceIntervals_percentile95,
         t8_confidenceIntervals_percentile65, t8_confidenceIntervals_mean,
         t8_dreamParams, t8_dreamOutput, t8_nestedSamplerOutput, t8_chain,
         bayesResults_predictionIntervals_reflectivity,
         bayesResults_predictionIntervals_sld,
         bayesResults_predictionIntervals_sampleChi_data,
         bayesResults_confidenceIntervals.percentile95,
         bayesResults_confidenceIntervals.percentile65,
         bayesResults_confidenceIntervals.mean, bayesResults_nestedSamplerOutput,
         bayesResults_chain, bayesResults_dreamParams, bayesResults_dreamOutput);

    //  Deal with priors.
    //  Tuning Parameters
    expl_temp.IPCFilePath.size[0] = 1;
    expl_temp.IPCFilePath.size[1] = controls_IPCFilePath_size[1];
    loop_ub = controls_IPCFilePath_size[1];
    if (loop_ub - 1 >= 0) {
      std::copy(&controls_IPCFilePath_data[0],
                &controls_IPCFilePath_data[loop_ub],
                &expl_temp.IPCFilePath.data[0]);
    }

    expl_temp.calcSLD = controls_calcSLD;
    expl_temp.display.size[0] = 1;
    expl_temp.display.size[1] = controls_display_size[1];
    loop_ub = controls_display_size[1];
    if (loop_ub - 1 >= 0) {
      std::copy(&controls_display_data[0], &controls_display_data[loop_ub],
                &expl_temp.display.data[0]);
    }

    expl_temp.resampleNPoints = controls_resampleNPoints;
    expl_temp.resampleMinAngle = controls_resampleMinAngle;
    expl_temp.numSimulationPoints = controls_numSimulationPoints;
    expl_temp.parallel.size[0] = 1;
    expl_temp.parallel.size[1] = controls_parallel_size[1];
    loop_ub = controls_parallel_size[1];
    if (loop_ub - 1 >= 0) {
      std::copy(&controls_parallel_data[0], &controls_parallel_data[loop_ub],
                &expl_temp.parallel.data[0]);
    }

    getFittedPriors(fitNames, problemStruct.priorNames,
                    problemStruct.priorValues, problemStruct.fitLimits, r);
    bayesResults_nestedSamplerOutput.LogZ = nestedSampler(problemStruct,
      expl_temp, controls_nLive, controls_nMCMC, controls_nsTolerance, r,
      bayesResults_nestedSamplerOutput.nestSamples,
      bayesResults_nestedSamplerOutput.postSamples, H);

    //  Process the results...
    //  chain = nest_samples(:,1:end-1);
    if (fitNames.size(0) < 1) {
      loop_ub = 0;
    } else {
      loop_ub = fitNames.size(0);
    }

    t8_chain.set_size(bayesResults_nestedSamplerOutput.postSamples.size(0),
                      loop_ub);
    for (int i{0}; i < loop_ub; i++) {
      b_loop_ub = bayesResults_nestedSamplerOutput.postSamples.size(0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        t8_chain[i1 + t8_chain.size(0) * i] =
          bayesResults_nestedSamplerOutput.postSamples[i1 +
          bayesResults_nestedSamplerOutput.postSamples.size(0) * i];
      }
    }

    coder::blockedSummation(t8_chain,
      bayesResults_nestedSamplerOutput.postSamples.size(0),
      t8_confidenceIntervals_mean);
    bayesOutputs_bestParams_size[0] = 1;
    bayesOutputs_bestParams_size[1] = t8_confidenceIntervals_mean.size(1);
    b_loop_ub = t8_confidenceIntervals_mean.size(1);
    for (int i{0}; i < b_loop_ub; i++) {
      bayesOutputs_bestParams_data[i] = t8_confidenceIntervals_mean[i] /
        static_cast<double>(bayesResults_nestedSamplerOutput.postSamples.size(0));
    }

    bayesOutputs_chain.set_size
      (bayesResults_nestedSamplerOutput.postSamples.size(0), loop_ub);
    for (int i{0}; i < loop_ub; i++) {
      b_loop_ub = bayesResults_nestedSamplerOutput.postSamples.size(0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        bayesOutputs_chain[i1 + bayesOutputs_chain.size(0) * i] =
          bayesResults_nestedSamplerOutput.postSamples[i1 +
          bayesResults_nestedSamplerOutput.postSamples.size(0) * i];
      }
    }

    processBayes(bayesOutputs_bestParams_data, bayesOutputs_bestParams_size,
                 bayesOutputs_chain, problemStruct, controls_parallel_data,
                 controls_parallel_size, controls_numSimulationPoints,
                 controls_resampleMinAngle, controls_resampleNPoints, result,
                 nestResults);
    bayesResults_predictionIntervals_reflectivity.set_size
      (nestResults.predictionIntervals.reflectivity.size(0));
    b_loop_ub = nestResults.predictionIntervals.reflectivity.size(0);
    for (int i{0}; i < b_loop_ub; i++) {
      bayesResults_predictionIntervals_reflectivity[i] =
        nestResults.predictionIntervals.reflectivity[i];
    }

    bayesResults_predictionIntervals_sld.set_size
      (nestResults.predictionIntervals.sld.size(0),
       nestResults.predictionIntervals.sld.size(1));
    b_loop_ub = nestResults.predictionIntervals.sld.size(1);
    for (int i{0}; i < b_loop_ub; i++) {
      t8_predictionIntervals_sampleChi_size =
        nestResults.predictionIntervals.sld.size(0);
      for (int i1{0}; i1 < t8_predictionIntervals_sampleChi_size; i1++) {
        bayesResults_predictionIntervals_sld[i1 +
          bayesResults_predictionIntervals_sld.size(0) * i] =
          nestResults.predictionIntervals.sld[i1 +
          nestResults.predictionIntervals.sld.size(0) * i];
      }
    }

    bayesResults_predictionIntervals_sampleChi_size = 1000;
    std::copy(&nestResults.predictionIntervals.sampleChi[0],
              &nestResults.predictionIntervals.sampleChi[1000],
              &bayesResults_predictionIntervals_sampleChi_data[0]);
    bayesResults_confidenceIntervals = nestResults.confidenceIntervals;
    bayesResults_chain.set_size
      (bayesResults_nestedSamplerOutput.postSamples.size(0), loop_ub);
    for (int i{0}; i < loop_ub; i++) {
      b_loop_ub = bayesResults_nestedSamplerOutput.postSamples.size(0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        bayesResults_chain[i1 + bayesResults_chain.size(0) * i] =
          bayesResults_nestedSamplerOutput.postSamples[i1 +
          bayesResults_nestedSamplerOutput.postSamples.size(0) * i];
      }
    }

    bayesResults_nestedSamplerOutput.LogZErr = std::sqrt(H / controls_nLive);
    return bayesResults_predictionIntervals_sampleChi_size;
  }
}

// End of code generation (runNestedSampler.cpp)
