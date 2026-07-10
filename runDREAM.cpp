//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// runDREAM.cpp
//
// Code generation for function 'runDREAM'
//

// Include files
#include "runDREAM.h"
#include "DREAM.h"
#include "RATMain_internal_types.h"
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "getFitNames.h"
#include "getFittedPriors.h"
#include "ifWhileCond.h"
#include "isRATStopped.h"
#include "makeEmptyBayesResultsStruct.h"
#include "makeEmptyResultStruct.h"
#include "mean.h"
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
  void runDREAM(ProblemDefinition &problemStruct, const char
                controls_parallel_data[], const int controls_parallel_size[2],
                double controls_numSimulationPoints, double
                controls_resampleMinAngle, double controls_resampleNPoints,
                const char controls_display_data[], const int
                controls_display_size[2], double controls_nSamples, double
                controls_nChains, double controls_jumpProbability, double
                controls_pUnitGamma, const char controls_boundHandling_data[],
                const int controls_boundHandling_size[2], boolean_T
                controls_adaptPCR, boolean_T controls_calcSLD, const char
                controls_IPCFilePath_data[], const int
                controls_IPCFilePath_size[2], ::coder::array<cell_wrap_7, 1U>
                &result_reflectivity, ::coder::array<cell_wrap_7, 1U>
                &result_simulation, ::coder::array<cell_wrap_8, 1U>
                &result_shiftedData, ::coder::array<cell_wrap_8, 1U>
                &result_backgrounds, ::coder::array<cell_wrap_7, 1U>
                &result_resolutions, ::coder::array<cell_wrap_9, 2U>
                &result_sldProfiles, ::coder::array<cell_wrap_9, 2U>
                &result_layers, ::coder::array<cell_wrap_9, 2U>
                &result_resampledLayers, ::coder::array<double, 2U>
                &result_fitParams, ::coder::array<cell_wrap_10, 1U>
                &result_fitNames, e_struct_T &bayesResults, CalculationResults &
                result_calculationResults, ContrastParams &result_contrastParams)
  {
    static Controls expl_temp;
    ::coder::array<cell_wrap_10, 1U> fitNames;
    ::coder::array<double, 3U> chain;
    ::coder::array<double, 2U> ParInfo_max;
    ::coder::array<double, 2U> ParInfo_min;
    ::coder::array<double, 2U> a__1;
    ::coder::array<double, 2U> b_bayesResults;
    ::coder::array<double, 2U> b_chain;
    ::coder::array<double, 2U> r;
    ::coder::array<double, 2U> r1;
    ::coder::array<boolean_T, 1U> b_tmp_data;
    b_struct_T result;
    c_struct_T dreamOutput;
    i_struct_T dreamResults;
    int b_loop_ub;
    int i;
    int i1;
    int i2;
    int loop_ub;
    boolean_T domains;
    boolean_T tmp_data;

    //  Run the DREAM algorithm for a given problem and controls.
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
    //  outProblemStruct : struct
    //      the output project struct.
    //  result : struct
    //      the calculation and optimisation results object.
    //  bayesResults : struct
    //      Additional Bayesian results from the algorithm.
    //  Make an empty struct for bayesResults to hold the outputs of the
    //  calculation
    domains = coder::internal::b_strcmp(problemStruct.TF.data,
      problemStruct.TF.size);
    bayesResults.predictionIntervals.sampleChi.size[0] =
      makeEmptyBayesResultsStruct(problemStruct.numberOfContrasts, domains,
      controls_nChains, bayesResults.predictionIntervals.reflectivity,
      bayesResults.predictionIntervals.sld,
      bayesResults.predictionIntervals.sampleChi.data,
      bayesResults.confidenceIntervals.percentile95,
      bayesResults.confidenceIntervals.percentile65,
      bayesResults.confidenceIntervals.mean, bayesResults.dreamParams,
      bayesResults.dreamOutput, bayesResults.nestedSamplerOutput,
      bayesResults.chain);

    //  Pre-allocation
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
    ParInfo_min.set_size(1, problemStruct.fitLimits.size(0));
    loop_ub = problemStruct.fitLimits.size(0);
    ParInfo_max.set_size(1, problemStruct.fitLimits.size(0));
    for (i = 0; i < loop_ub; i++) {
      ParInfo_min[i] = problemStruct.fitLimits[i];
      ParInfo_max[i] = problemStruct.fitLimits[i + problemStruct.fitLimits.size
        (0)];
    }

    //  Run the sampler....
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
    DREAM(static_cast<double>(fitNames.size(0)), controls_nChains, std::ceil
          (controls_nSamples / controls_nChains), controls_jumpProbability,
          controls_pUnitGamma, controls_adaptPCR, ParInfo_min, ParInfo_max,
          controls_boundHandling_data, controls_boundHandling_size,
          problemStruct, expl_temp, r, chain, dreamOutput, a__1);
    loop_ub = isRATStopped(controls_IPCFilePath_data, controls_IPCFilePath_size,
      (boolean_T *)&tmp_data);
    b_tmp_data.set(&tmp_data, loop_ub);
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
      int c_loop_ub;

      //  Combine all chains....
      bayesResults.chain.set_size(0, 0);
      i = static_cast<int>(controls_nChains);
      if (static_cast<int>(controls_nChains) - 1 >= 0) {
        int cutoff;
        if (fitNames.size(0) < 1) {
          b_loop_ub = 0;
        } else {
          b_loop_ub = fitNames.size(0);
        }

        cutoff = static_cast<int>(std::floor(static_cast<double>(chain.size(0)) *
          0.25));
        if (cutoff > chain.size(0)) {
          i1 = 0;
          i2 = 0;
        } else {
          i1 = cutoff - 1;
          i2 = chain.size(0);
        }
      }

      for (int b_i{0}; b_i < i; b_i++) {
        int b_result;
        int sizes_idx_0;
        boolean_T b;
        boolean_T empty_non_axis_sizes;

        //  Keep only the last 75% of the chain..
        //  Combine the parallel chains into one....
        b = ((bayesResults.chain.size(0) != 0) && (bayesResults.chain.size(1) !=
              0));
        if (b) {
          b_result = bayesResults.chain.size(1);
        } else if ((i2 - i1 != 0) && (b_loop_ub != 0)) {
          b_result = b_loop_ub;
        } else {
          b_result = bayesResults.chain.size(1);
          if (b_loop_ub > bayesResults.chain.size(1)) {
            b_result = b_loop_ub;
          }
        }

        empty_non_axis_sizes = (b_result == 0);
        if (empty_non_axis_sizes || b) {
          loop_ub = bayesResults.chain.size(0);
        } else {
          loop_ub = 0;
        }

        if (empty_non_axis_sizes || ((i2 - i1 != 0) && (b_loop_ub != 0))) {
          sizes_idx_0 = i2 - i1;
        } else {
          sizes_idx_0 = 0;
        }

        c_loop_ub = i2 - i1;
        b_chain.set_size(c_loop_ub, b_loop_ub);
        for (int i3{0}; i3 < b_loop_ub; i3++) {
          for (int i4{0}; i4 < c_loop_ub; i4++) {
            b_chain[i4 + b_chain.size(0) * i3] = chain[((i1 + i4) + chain.size(0)
              * i3) + chain.size(0) * chain.size(1) * b_i];
          }
        }

        b_bayesResults.set_size(loop_ub + sizes_idx_0, b_result);
        for (int i3{0}; i3 < b_result; i3++) {
          for (int i4{0}; i4 < loop_ub; i4++) {
            b_bayesResults[i4 + b_bayesResults.size(0) * i3] =
              bayesResults.chain[i4 + loop_ub * i3];
          }
        }

        for (int i3{0}; i3 < b_result; i3++) {
          for (int i4{0}; i4 < sizes_idx_0; i4++) {
            b_bayesResults[(i4 + loop_ub) + b_bayesResults.size(0) * i3] =
              b_chain[i4 + sizes_idx_0 * i3];
          }
        }

        bayesResults.chain.set_size(b_bayesResults.size(0), b_bayesResults.size
          (1));
        loop_ub = b_bayesResults.size(1);
        for (int i3{0}; i3 < loop_ub; i3++) {
          c_loop_ub = b_bayesResults.size(0);
          for (int i4{0}; i4 < c_loop_ub; i4++) {
            bayesResults.chain[i4 + bayesResults.chain.size(0) * i3] =
              b_bayesResults[i4 + b_bayesResults.size(0) * i3];
          }
        }
      }

      coder::mean(bayesResults.chain, r1);
      processBayes(r1, bayesResults.chain, problemStruct, controls_parallel_data,
                   controls_parallel_size, controls_numSimulationPoints,
                   controls_resampleMinAngle, controls_resampleNPoints, result,
                   dreamResults);
      cast(result, result_reflectivity, result_simulation, result_shiftedData,
           result_backgrounds, result_resolutions, result_sldProfiles,
           result_layers, result_resampledLayers, result_fitParams,
           result_fitNames, result_calculationResults, result_contrastParams);

      //  Populate the output struct
      bayesResults.predictionIntervals.reflectivity.set_size
        (dreamResults.predictionIntervals.reflectivity.size(0));
      loop_ub = dreamResults.predictionIntervals.reflectivity.size(0);
      for (i = 0; i < loop_ub; i++) {
        bayesResults.predictionIntervals.reflectivity[i] =
          dreamResults.predictionIntervals.reflectivity[i];
      }

      bayesResults.predictionIntervals.sld.set_size
        (dreamResults.predictionIntervals.sld.size(0),
         dreamResults.predictionIntervals.sld.size(1));
      loop_ub = dreamResults.predictionIntervals.sld.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = dreamResults.predictionIntervals.sld.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          bayesResults.predictionIntervals.sld[i1 +
            bayesResults.predictionIntervals.sld.size(0) * i] =
            dreamResults.predictionIntervals.sld[i1 +
            dreamResults.predictionIntervals.sld.size(0) * i];
        }
      }

      bayesResults.predictionIntervals.sampleChi.size[0] = 1000;
      std::copy(&dreamResults.predictionIntervals.sampleChi[0],
                &dreamResults.predictionIntervals.sampleChi[1000],
                &bayesResults.predictionIntervals.sampleChi.data[0]);
      bayesResults.confidenceIntervals = dreamResults.confidenceIntervals;
      bayesResults.dreamParams = dreamOutput.DREAMPar;
      bayesResults.dreamOutput.allChains.set_size(chain.size(0), chain.size(1),
        chain.size(2));
      loop_ub = chain.size(2);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = chain.size(1);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          c_loop_ub = chain.size(0);
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            bayesResults.dreamOutput.allChains[(i2 +
              bayesResults.dreamOutput.allChains.size(0) * i1) +
              bayesResults.dreamOutput.allChains.size(0) *
              bayesResults.dreamOutput.allChains.size(1) * i] = chain[(i2 +
              chain.size(0) * i1) + chain.size(0) * chain.size(1) * i];
          }
        }
      }

      bayesResults.dreamOutput.outlierChains.size[0] =
        dreamOutput.outlierChains.size[0];
      bayesResults.dreamOutput.outlierChains.size[1] = 2;
      bayesResults.dreamOutput.runtime = dreamOutput.runtime;
      bayesResults.dreamOutput.iteration = dreamOutput.iteration;
      bayesResults.dreamOutput.AR.size[0] = dreamOutput.AR.size[0];
      bayesResults.dreamOutput.AR.size[1] = 2;
      loop_ub = dreamOutput.outlierChains.size[0];
      b_loop_ub = dreamOutput.AR.size[0];
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          bayesResults.dreamOutput.outlierChains.data[i1 +
            bayesResults.dreamOutput.outlierChains.size[0] * i] =
            dreamOutput.outlierChains.data[i1 + dreamOutput.outlierChains.size[0]
            * i];
        }

        for (i1 = 0; i1 < b_loop_ub; i1++) {
          bayesResults.dreamOutput.AR.data[i1 +
            bayesResults.dreamOutput.AR.size[0] * i] = dreamOutput.AR.data[i1 +
            dreamOutput.AR.size[0] * i];
        }
      }

      bayesResults.dreamOutput.R_stat.set_size(dreamOutput.R_stat.size(0),
        dreamOutput.R_stat.size(1));
      loop_ub = dreamOutput.R_stat.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = dreamOutput.R_stat.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          bayesResults.dreamOutput.R_stat[i1 +
            bayesResults.dreamOutput.R_stat.size(0) * i] = dreamOutput.R_stat[i1
            + dreamOutput.R_stat.size(0) * i];
        }
      }

      bayesResults.dreamOutput.CR.set_size(dreamOutput.CR.size(0), 4);
      loop_ub = dreamOutput.CR.size(0);
      for (i = 0; i < 4; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          bayesResults.dreamOutput.CR[i1 + bayesResults.dreamOutput.CR.size(0) *
            i] = dreamOutput.CR[i1 + dreamOutput.CR.size(0) * i];
        }
      }
    }
  }
}

// End of code generation (runDREAM.cpp)
