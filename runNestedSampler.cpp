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
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "blockedSummation.h"
#include "getFitNames.h"
#include "getFittedPriors.h"
#include "ifWhileCond.h"
#include "isRATStopped.h"
#include "makeEmptyBayesResultsStruct.h"
#include "makeEmptyResultStruct.h"
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
                  &t27_predictionIntervals_reflectivity, const ::coder::array<
                  cell_wrap_11, 2U> &t27_predictionIntervals_sld, const double
                  t27_predictionIntervals_sampleChi_data[], int
                  t27_predictionIntervals_sampleChi_size, const ::coder::array<
                  double, 2U> &t27_confidenceIntervals_percentile95, const ::
                  coder::array<double, 2U> &t27_confidenceIntervals_percentile65,
                  const ::coder::array<double, 2U> &t27_confidenceIntervals_mean,
                  const DreamParams &t27_dreamParams, const DreamOutput &
                  t27_dreamOutput, const struct_T t27_nestedSamplerOutput, const
                  ::coder::array<double, 2U> &t27_chain, ::coder::array<
                  cell_wrap_11, 1U> &t28_predictionIntervals_reflectivity, ::
                  coder::array<cell_wrap_11, 2U> &t28_predictionIntervals_sld,
                  double t28_predictionIntervals_sampleChi_data[], ::coder::
                  array<double, 2U> &t28_confidenceIntervals_percentile95, ::
                  coder::array<double, 2U> &t28_confidenceIntervals_percentile65,
                  ::coder::array<double, 2U> &t28_confidenceIntervals_mean, ::
                  coder::array<double, 2U> &t28_nestedSamplerOutput_nestSamples,
                  ::coder::array<double, 2U>
                  &t28_nestedSamplerOutput_postSamples, ::coder::array<double,
                  2U> &t28_chain, DreamParams &t28_dreamParams, DreamOutput &
                  t28_dreamOutput, double &t28_nestedSamplerOutput_logZ, double
                  &t28_nestedSamplerOutput_logZErr);
}

// Function Definitions
namespace RAT
{
  static int cast(const ::coder::array<cell_wrap_11, 1U>
                  &t27_predictionIntervals_reflectivity, const ::coder::array<
                  cell_wrap_11, 2U> &t27_predictionIntervals_sld, const double
                  t27_predictionIntervals_sampleChi_data[], int
                  t27_predictionIntervals_sampleChi_size, const ::coder::array<
                  double, 2U> &t27_confidenceIntervals_percentile95, const ::
                  coder::array<double, 2U> &t27_confidenceIntervals_percentile65,
                  const ::coder::array<double, 2U> &t27_confidenceIntervals_mean,
                  const DreamParams &t27_dreamParams, const DreamOutput &
                  t27_dreamOutput, const struct_T t27_nestedSamplerOutput, const
                  ::coder::array<double, 2U> &t27_chain, ::coder::array<
                  cell_wrap_11, 1U> &t28_predictionIntervals_reflectivity, ::
                  coder::array<cell_wrap_11, 2U> &t28_predictionIntervals_sld,
                  double t28_predictionIntervals_sampleChi_data[], ::coder::
                  array<double, 2U> &t28_confidenceIntervals_percentile95, ::
                  coder::array<double, 2U> &t28_confidenceIntervals_percentile65,
                  ::coder::array<double, 2U> &t28_confidenceIntervals_mean, ::
                  coder::array<double, 2U> &t28_nestedSamplerOutput_nestSamples,
                  ::coder::array<double, 2U>
                  &t28_nestedSamplerOutput_postSamples, ::coder::array<double,
                  2U> &t28_chain, DreamParams &t28_dreamParams, DreamOutput &
                  t28_dreamOutput, double &t28_nestedSamplerOutput_logZ, double
                  &t28_nestedSamplerOutput_logZErr)
  {
    int b_loop_ub;
    int loop_ub;
    int t28_predictionIntervals_sampleChi_size;
    t28_predictionIntervals_reflectivity.set_size
      (t27_predictionIntervals_reflectivity.size(0));
    loop_ub = t27_predictionIntervals_reflectivity.size(0);
    for (int i{0}; i < loop_ub; i++) {
      t28_predictionIntervals_reflectivity[i] =
        t27_predictionIntervals_reflectivity[i];
    }

    t28_predictionIntervals_sld.set_size(t27_predictionIntervals_sld.size(0),
      t27_predictionIntervals_sld.size(1));
    loop_ub = t27_predictionIntervals_sld.size(1);
    for (int i{0}; i < loop_ub; i++) {
      b_loop_ub = t27_predictionIntervals_sld.size(0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        t28_predictionIntervals_sld[i1 + t28_predictionIntervals_sld.size(0) * i]
          = t27_predictionIntervals_sld[i1 + t27_predictionIntervals_sld.size(0)
          * i];
      }
    }

    t28_predictionIntervals_sampleChi_size =
      t27_predictionIntervals_sampleChi_size;
    if (t27_predictionIntervals_sampleChi_size - 1 >= 0) {
      std::copy(&t27_predictionIntervals_sampleChi_data[0],
                &t27_predictionIntervals_sampleChi_data[t27_predictionIntervals_sampleChi_size],
                &t28_predictionIntervals_sampleChi_data[0]);
    }

    t28_confidenceIntervals_percentile95.set_size(2,
      t27_confidenceIntervals_percentile95.size(1));
    loop_ub = t27_confidenceIntervals_percentile95.size(1);
    for (int i{0}; i < loop_ub; i++) {
      t28_confidenceIntervals_percentile95[2 * i] =
        t27_confidenceIntervals_percentile95[2 * i];
      t28_confidenceIntervals_percentile95[2 * i + 1] =
        t27_confidenceIntervals_percentile95[2 * i + 1];
    }

    t28_confidenceIntervals_percentile65.set_size(2,
      t27_confidenceIntervals_percentile65.size(1));
    loop_ub = t27_confidenceIntervals_percentile65.size(1);
    for (int i{0}; i < loop_ub; i++) {
      t28_confidenceIntervals_percentile65[2 * i] =
        t27_confidenceIntervals_percentile65[2 * i];
      t28_confidenceIntervals_percentile65[2 * i + 1] =
        t27_confidenceIntervals_percentile65[2 * i + 1];
    }

    t28_confidenceIntervals_mean.set_size(1, t27_confidenceIntervals_mean.size(1));
    loop_ub = t27_confidenceIntervals_mean.size(1);
    for (int i{0}; i < loop_ub; i++) {
      t28_confidenceIntervals_mean[i] = t27_confidenceIntervals_mean[i];
    }

    t28_dreamParams = t27_dreamParams;
    t28_dreamOutput = t27_dreamOutput;
    t28_nestedSamplerOutput_nestSamples.set_size(1, 2);
    t28_nestedSamplerOutput_postSamples.set_size(1, 2);
    t28_nestedSamplerOutput_nestSamples[0] =
      t27_nestedSamplerOutput.nestSamples.data[0];
    t28_nestedSamplerOutput_postSamples[0] =
      t27_nestedSamplerOutput.postSamples.data[0];
    t28_nestedSamplerOutput_nestSamples[t28_nestedSamplerOutput_nestSamples.size
      (0)] = t27_nestedSamplerOutput.nestSamples.data[1];
    t28_nestedSamplerOutput_postSamples[t28_nestedSamplerOutput_postSamples.size
      (0)] = t27_nestedSamplerOutput.postSamples.data[1];
    t28_chain.set_size(t27_chain.size(0), t27_chain.size(1));
    loop_ub = t27_chain.size(1);
    for (int i{0}; i < loop_ub; i++) {
      b_loop_ub = t27_chain.size(0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        t28_chain[i1 + t28_chain.size(0) * i] = t27_chain[i1 + t27_chain.size(0)
          * i];
      }
    }

    t28_nestedSamplerOutput_logZ = t27_nestedSamplerOutput.logZ;
    t28_nestedSamplerOutput_logZErr = t27_nestedSamplerOutput.logZErr;
    return t28_predictionIntervals_sampleChi_size;
  }

  void runNestedSampler(ProblemDefinition &problemStruct, const char
                        controls_parallel_data[], const int
                        controls_parallel_size[2], double
                        controls_numSimulationPoints, double
                        controls_resampleMinAngle, double
                        controls_resampleNPoints, const char
                        controls_display_data[], const int
                        controls_display_size[2], double controls_nLive, double
                        controls_nMCMC, double controls_nsTolerance, boolean_T
                        controls_calcSLD, const char controls_IPCFilePath_data[],
                        const int controls_IPCFilePath_size[2], ::coder::array<
                        cell_wrap_7, 1U> &result_reflectivity, ::coder::array<
                        cell_wrap_7, 1U> &result_simulation, ::coder::array<
                        cell_wrap_8, 1U> &result_shiftedData, ::coder::array<
                        cell_wrap_8, 1U> &result_backgrounds, ::coder::array<
                        cell_wrap_7, 1U> &result_resolutions, ::coder::array<
                        cell_wrap_9, 2U> &result_sldProfiles, ::coder::array<
                        cell_wrap_9, 2U> &result_layers, ::coder::array<
                        cell_wrap_9, 2U> &result_resampledLayers, ::coder::array<
                        double, 2U> &result_fitParams, ::coder::array<
                        cell_wrap_10, 1U> &result_fitNames, d_struct_T
                        &bayesResults, CalculationResults &
                        result_calculationResults, ContrastParams &
                        result_contrastParams)
  {
    static Controls expl_temp;
    ::coder::array<cell_wrap_10, 1U> fitNames;
    ::coder::array<cell_wrap_11, 2U> t31_predictionIntervals_sld;
    ::coder::array<cell_wrap_11, 1U> t31_predictionIntervals_reflectivity;
    ::coder::array<double, 2U> bayesOutputs_chain;
    ::coder::array<double, 2U> nestSamples;
    ::coder::array<double, 2U> postSamples;
    ::coder::array<double, 2U> r;
    ::coder::array<double, 2U> t31_chain;
    ::coder::array<double, 2U> t31_confidenceIntervals_mean;
    ::coder::array<double, 2U> t31_confidenceIntervals_percentile65;
    ::coder::array<double, 2U> t31_confidenceIntervals_percentile95;
    ::coder::array<boolean_T, 1U> b_tmp_data;
    DreamOutput t31_dreamOutput;
    DreamParams t31_dreamParams;
    b_struct_T result;
    i_struct_T nestResults;
    struct_T t31_nestedSamplerOutput;
    double t31_predictionIntervals_sampleChi_data[1000];
    double H;
    double logZ;
    int bayesOutputs_bestParams_size[2];
    int t31_predictionIntervals_sampleChi_size;
    boolean_T domains;
    boolean_T tmp_data;

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
    domains = coder::internal::b_strcmp(problemStruct.TF.data,
      problemStruct.TF.size);
    t31_predictionIntervals_sampleChi_size = b_makeEmptyBayesResultsStruct
      (problemStruct.numberOfContrasts, domains,
       t31_predictionIntervals_reflectivity, t31_predictionIntervals_sld,
       t31_predictionIntervals_sampleChi_data,
       t31_confidenceIntervals_percentile95,
       t31_confidenceIntervals_percentile65, t31_confidenceIntervals_mean,
       t31_dreamParams, t31_dreamOutput, t31_nestedSamplerOutput, t31_chain);
    bayesResults.predictionIntervals.sampleChi.size[0] = cast
      (t31_predictionIntervals_reflectivity, t31_predictionIntervals_sld,
       t31_predictionIntervals_sampleChi_data,
       t31_predictionIntervals_sampleChi_size,
       t31_confidenceIntervals_percentile95,
       t31_confidenceIntervals_percentile65, t31_confidenceIntervals_mean,
       t31_dreamParams, t31_dreamOutput, t31_nestedSamplerOutput, t31_chain,
       bayesResults.predictionIntervals.reflectivity,
       bayesResults.predictionIntervals.sld,
       bayesResults.predictionIntervals.sampleChi.data,
       bayesResults.confidenceIntervals.percentile95,
       bayesResults.confidenceIntervals.percentile65,
       bayesResults.confidenceIntervals.mean,
       bayesResults.nestedSamplerOutput.nestSamples,
       bayesResults.nestedSamplerOutput.postSamples, bayesResults.chain,
       bayesResults.dreamParams, bayesResults.dreamOutput,
       bayesResults.nestedSamplerOutput.logZ,
       bayesResults.nestedSamplerOutput.logZErr);

    //  Deal with priors.
    //  Tuning Parameters
    expl_temp.IPCFilePath.size[0] = 1;
    expl_temp.IPCFilePath.size[1] = controls_IPCFilePath_size[1];
    t31_predictionIntervals_sampleChi_size = controls_IPCFilePath_size[1];
    if (t31_predictionIntervals_sampleChi_size - 1 >= 0) {
      std::copy(&controls_IPCFilePath_data[0],
                &controls_IPCFilePath_data[t31_predictionIntervals_sampleChi_size],
                &expl_temp.IPCFilePath.data[0]);
    }

    expl_temp.calcSLD = controls_calcSLD;
    expl_temp.display.size[0] = 1;
    expl_temp.display.size[1] = controls_display_size[1];
    t31_predictionIntervals_sampleChi_size = controls_display_size[1];
    if (t31_predictionIntervals_sampleChi_size - 1 >= 0) {
      std::copy(&controls_display_data[0],
                &controls_display_data[t31_predictionIntervals_sampleChi_size],
                &expl_temp.display.data[0]);
    }

    expl_temp.resampleNPoints = controls_resampleNPoints;
    expl_temp.resampleMinAngle = controls_resampleMinAngle;
    expl_temp.numSimulationPoints = controls_numSimulationPoints;
    expl_temp.parallel.size[0] = 1;
    expl_temp.parallel.size[1] = controls_parallel_size[1];
    t31_predictionIntervals_sampleChi_size = controls_parallel_size[1];
    if (t31_predictionIntervals_sampleChi_size - 1 >= 0) {
      std::copy(&controls_parallel_data[0],
                &controls_parallel_data[t31_predictionIntervals_sampleChi_size],
                &expl_temp.parallel.data[0]);
    }

    getFittedPriors(fitNames, problemStruct.priorNames,
                    problemStruct.priorValues, problemStruct.fitLimits, r);
    logZ = nestedSampler(problemStruct, expl_temp, controls_nLive,
                         controls_nMCMC, controls_nsTolerance, r, nestSamples,
                         postSamples, H);
    t31_predictionIntervals_sampleChi_size = isRATStopped
      (controls_IPCFilePath_data, controls_IPCFilePath_size, (boolean_T *)
       &tmp_data);
    b_tmp_data.set(&tmp_data, t31_predictionIntervals_sampleChi_size);
    if (coder::internal::ifWhileCond(b_tmp_data)) {
      makeEmptyResultStruct(problemStruct.numberOfContrasts, static_cast<double>
                            (problemStruct.fitParams.size(1)), domains,
                            result_reflectivity, result_simulation,
                            result_shiftedData, result_backgrounds,
                            result_resolutions, result_sldProfiles,
                            result_layers, result_resampledLayers,
                            result_fitParams, result_fitNames,
                            result_calculationResults, result_contrastParams);
    } else {
      double bayesOutputs_bestParams_data[51];
      int loop_ub;

      //  Process the results...
      //  chain = nest_samples(:,1:end-1);
      if (fitNames.size(0) < 1) {
        t31_predictionIntervals_sampleChi_size = 0;
      } else {
        t31_predictionIntervals_sampleChi_size = fitNames.size(0);
      }

      t31_chain.set_size(postSamples.size(0),
                         t31_predictionIntervals_sampleChi_size);
      for (int i{0}; i < t31_predictionIntervals_sampleChi_size; i++) {
        loop_ub = postSamples.size(0);
        for (int i1{0}; i1 < loop_ub; i1++) {
          t31_chain[i1 + t31_chain.size(0) * i] = postSamples[i1 +
            postSamples.size(0) * i];
        }
      }

      coder::blockedSummation(t31_chain, postSamples.size(0),
        t31_confidenceIntervals_mean);
      bayesOutputs_bestParams_size[0] = 1;
      bayesOutputs_bestParams_size[1] = t31_confidenceIntervals_mean.size(1);
      loop_ub = t31_confidenceIntervals_mean.size(1);
      for (int i{0}; i < loop_ub; i++) {
        bayesOutputs_bestParams_data[i] = t31_confidenceIntervals_mean[i] /
          static_cast<double>(postSamples.size(0));
      }

      bayesOutputs_chain.set_size(postSamples.size(0),
        t31_predictionIntervals_sampleChi_size);
      for (int i{0}; i < t31_predictionIntervals_sampleChi_size; i++) {
        loop_ub = postSamples.size(0);
        for (int i1{0}; i1 < loop_ub; i1++) {
          bayesOutputs_chain[i1 + bayesOutputs_chain.size(0) * i] =
            postSamples[i1 + postSamples.size(0) * i];
        }
      }

      processBayes(bayesOutputs_bestParams_data, bayesOutputs_bestParams_size,
                   bayesOutputs_chain, problemStruct, controls_parallel_data,
                   controls_parallel_size, controls_numSimulationPoints,
                   controls_resampleMinAngle, controls_resampleNPoints, result,
                   nestResults);
      cast(result, result_reflectivity, result_simulation, result_shiftedData,
           result_backgrounds, result_resolutions, result_sldProfiles,
           result_layers, result_resampledLayers, result_fitParams,
           result_fitNames, result_calculationResults, result_contrastParams);
      bayesResults.predictionIntervals.reflectivity.set_size
        (nestResults.predictionIntervals.reflectivity.size(0));
      loop_ub = nestResults.predictionIntervals.reflectivity.size(0);
      for (int i{0}; i < loop_ub; i++) {
        bayesResults.predictionIntervals.reflectivity[i] =
          nestResults.predictionIntervals.reflectivity[i];
      }

      bayesResults.predictionIntervals.sld.set_size
        (nestResults.predictionIntervals.sld.size(0),
         nestResults.predictionIntervals.sld.size(1));
      loop_ub = nestResults.predictionIntervals.sld.size(1);
      for (int i{0}; i < loop_ub; i++) {
        int b_loop_ub;
        b_loop_ub = nestResults.predictionIntervals.sld.size(0);
        for (int i1{0}; i1 < b_loop_ub; i1++) {
          bayesResults.predictionIntervals.sld[i1 +
            bayesResults.predictionIntervals.sld.size(0) * i] =
            nestResults.predictionIntervals.sld[i1 +
            nestResults.predictionIntervals.sld.size(0) * i];
        }
      }

      bayesResults.predictionIntervals.sampleChi.size[0] = 1000;
      std::copy(&nestResults.predictionIntervals.sampleChi[0],
                &nestResults.predictionIntervals.sampleChi[1000],
                &bayesResults.predictionIntervals.sampleChi.data[0]);
      bayesResults.confidenceIntervals = nestResults.confidenceIntervals;
      bayesResults.chain.set_size(postSamples.size(0),
        t31_predictionIntervals_sampleChi_size);
      for (int i{0}; i < t31_predictionIntervals_sampleChi_size; i++) {
        loop_ub = postSamples.size(0);
        for (int i1{0}; i1 < loop_ub; i1++) {
          bayesResults.chain[i1 + bayesResults.chain.size(0) * i] =
            postSamples[i1 + postSamples.size(0) * i];
        }
      }

      bayesResults.nestedSamplerOutput.logZ = logZ;
      bayesResults.nestedSamplerOutput.logZErr = std::sqrt(H / controls_nLive);
      bayesResults.nestedSamplerOutput.nestSamples.set_size(nestSamples.size(0),
        nestSamples.size(1));
      t31_predictionIntervals_sampleChi_size = nestSamples.size(1);
      for (int i{0}; i < t31_predictionIntervals_sampleChi_size; i++) {
        loop_ub = nestSamples.size(0);
        for (int i1{0}; i1 < loop_ub; i1++) {
          bayesResults.nestedSamplerOutput.nestSamples[i1 +
            bayesResults.nestedSamplerOutput.nestSamples.size(0) * i] =
            nestSamples[i1 + nestSamples.size(0) * i];
        }
      }

      bayesResults.nestedSamplerOutput.postSamples.set_size(postSamples.size(0),
        postSamples.size(1));
      t31_predictionIntervals_sampleChi_size = postSamples.size(1);
      for (int i{0}; i < t31_predictionIntervals_sampleChi_size; i++) {
        loop_ub = postSamples.size(0);
        for (int i1{0}; i1 < loop_ub; i1++) {
          bayesResults.nestedSamplerOutput.postSamples[i1 +
            bayesResults.nestedSamplerOutput.postSamples.size(0) * i] =
            postSamples[i1 + postSamples.size(0) * i];
        }
      }
    }
  }
}

// End of code generation (runNestedSampler.cpp)
