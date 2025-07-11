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
#include "RATMain_types.h"
#include "getFitNames.h"
#include "getFittedPriors.h"
#include "makeEmptyBayesResultsStruct.h"
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
  void runDREAM(const ProblemDefinition &problemStruct, const Controls *controls,
                b_struct_T &result, c_struct_T &bayesResults, ProblemDefinition
                &outProblemStruct)
  {
    static Controls b_controls;
    ::coder::array<cell_wrap_10, 1U> fitNames;
    ::coder::array<double, 2U> ParInfo_max;
    ::coder::array<double, 2U> ParInfo_min;
    ::coder::array<double, 2U> a__1;
    ::coder::array<double, 2U> b_bayesResults;
    ::coder::array<double, 2U> c_bayesResults;
    ::coder::array<double, 2U> r;
    ::coder::array<double, 2U> r1;
    e_struct_T dreamResults;
    f_struct_T dreamOutput;
    int b_loop_ub;
    int i;
    int i1;
    int i2;
    int loop_ub;

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
    bayesResults.predictionIntervals.sampleChi.size[0] =
      makeEmptyBayesResultsStruct(problemStruct.numberOfContrasts, coder::
      internal::b_strcmp(problemStruct.TF.data, problemStruct.TF.size),
      controls->nChains, bayesResults.predictionIntervals.reflectivity,
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
    getFittedPriors(fitNames, problemStruct.priorNames,
                    problemStruct.priorValues, problemStruct.fitLimits, r);
    DREAM(static_cast<double>(fitNames.size(0)), controls->nChains, std::ceil
          (controls->nSamples / controls->nChains), controls->jumpProbability,
          controls->pUnitGamma, controls->adaptPCR, ParInfo_min, ParInfo_max,
          controls->boundHandling.data, controls->boundHandling.size,
          problemStruct, controls, r, bayesResults.dreamOutput.allChains,
          dreamOutput, a__1);

    //  Combine all chains....
    bayesResults.chain.set_size(0, 0);
    i = static_cast<int>(controls->nChains);
    if (static_cast<int>(controls->nChains) - 1 >= 0) {
      int cutoff;
      if (fitNames.size(0) < 1) {
        b_loop_ub = 0;
      } else {
        b_loop_ub = fitNames.size(0);
      }

      cutoff = static_cast<int>(std::floor(static_cast<double>
        (bayesResults.dreamOutput.allChains.size(0)) * 0.25));
      if (cutoff > bayesResults.dreamOutput.allChains.size(0)) {
        i1 = 0;
        i2 = 0;
      } else {
        i1 = cutoff - 1;
        i2 = bayesResults.dreamOutput.allChains.size(0);
      }
    }

    for (int b_i{0}; b_i < i; b_i++) {
      int b_result;
      int c_loop_ub;
      int sizes_idx_0;
      boolean_T b;
      boolean_T empty_non_axis_sizes;

      //  Keep only the last 75% of the chain..
      //  Combine the parallel chains into one....
      b = ((bayesResults.chain.size(0) != 0) && (bayesResults.chain.size(1) != 0));
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
      b_bayesResults.set_size(c_loop_ub, b_loop_ub);
      for (int i3{0}; i3 < b_loop_ub; i3++) {
        for (int i4{0}; i4 < c_loop_ub; i4++) {
          b_bayesResults[i4 + b_bayesResults.size(0) * i3] =
            bayesResults.dreamOutput.allChains[((i1 + i4) +
            bayesResults.dreamOutput.allChains.size(0) * i3) +
            bayesResults.dreamOutput.allChains.size(0) *
            bayesResults.dreamOutput.allChains.size(1) * b_i];
        }
      }

      c_bayesResults.set_size(loop_ub + sizes_idx_0, b_result);
      for (int i3{0}; i3 < b_result; i3++) {
        for (int i4{0}; i4 < loop_ub; i4++) {
          c_bayesResults[i4 + c_bayesResults.size(0) * i3] =
            bayesResults.chain[i4 + loop_ub * i3];
        }
      }

      for (int i3{0}; i3 < b_result; i3++) {
        for (int i4{0}; i4 < sizes_idx_0; i4++) {
          c_bayesResults[(i4 + loop_ub) + c_bayesResults.size(0) * i3] =
            b_bayesResults[i4 + sizes_idx_0 * i3];
        }
      }

      bayesResults.chain.set_size(c_bayesResults.size(0), c_bayesResults.size(1));
      loop_ub = c_bayesResults.size(1);
      for (int i3{0}; i3 < loop_ub; i3++) {
        c_loop_ub = c_bayesResults.size(0);
        for (int i4{0}; i4 < c_loop_ub; i4++) {
          bayesResults.chain[i4 + bayesResults.chain.size(0) * i3] =
            c_bayesResults[i4 + c_bayesResults.size(0) * i3];
        }
      }
    }

    outProblemStruct = problemStruct;
    coder::mean(bayesResults.chain, r1);
    b_controls = *controls;
    processBayes(r1, bayesResults.chain, outProblemStruct, b_controls, result,
                 dreamResults);

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
          dreamOutput.outlierChains.data[i1 + dreamOutput.outlierChains.size[0] *
          i];
      }

      for (i1 = 0; i1 < b_loop_ub; i1++) {
        bayesResults.dreamOutput.AR.data[i1 + bayesResults.dreamOutput.AR.size[0]
          * i] = dreamOutput.AR.data[i1 + dreamOutput.AR.size[0] * i];
      }
    }

    bayesResults.dreamOutput.R_stat.set_size(dreamOutput.R_stat.size(0),
      dreamOutput.R_stat.size(1));
    loop_ub = dreamOutput.R_stat.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = dreamOutput.R_stat.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        bayesResults.dreamOutput.R_stat[i1 +
          bayesResults.dreamOutput.R_stat.size(0) * i] = dreamOutput.R_stat[i1 +
          dreamOutput.R_stat.size(0) * i];
      }
    }

    bayesResults.dreamOutput.CR.set_size(dreamOutput.CR.size(0), 4);
    loop_ub = dreamOutput.CR.size(0);
    for (i = 0; i < 4; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        bayesResults.dreamOutput.CR[i1 + bayesResults.dreamOutput.CR.size(0) * i]
          = dreamOutput.CR[i1 + dreamOutput.CR.size(0) * i];
      }
    }
  }
}

// End of code generation (runDREAM.cpp)
