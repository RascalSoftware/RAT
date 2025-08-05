//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// processBayes.cpp
//
// Code generation for function 'processBayes'
//

// Include files
#include "processBayes.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "percentileConfidenceIntervals.h"
#include "refPercentileConfidenceIntervals.h"
#include "reflectivityCalculation.h"
#include "rt_nonfinite.h"
#include "unpackParams.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>

// Function Definitions
namespace RAT
{
  void processBayes(const double bayesOutputs_bestParams_data[], const int
                    bayesOutputs_bestParams_size[2], const ::coder::array<double,
                    2U> &bayesOutputs_chain, ProblemDefinition &problemStruct,
                    const char controls_parallel_data[], const int
                    controls_parallel_size[2], double
                    controls_numSimulationPoints, double
                    controls_resampleMinAngle, double controls_resampleNPoints,
                    b_struct_T &result, e_struct_T &bayesResults)
  {
    static Controls expl_temp;
    ProblemDefinition b_problemStruct;
    int loop_ub;

    //  Process the output of a Bayesian optimisation.
    //
    //  Parameters
    //  ----------
    //  bayesOutputs : struct
    //      The outputs of the Bayesian optimisation.
    //  problemStruct : struct
    //      The struct for the project.
    //  controls : struct
    //      The struct for the controls.
    //
    //  Returns
    //  -------
    //  problemStruct : struct
    //      The struct for the output project.
    //  result : struct
    //      The results object from the optimisation.
    //  bayesResults : struct
    //      The Bayesian-specific results from the optimisation.
    //  Need to impose that we calculate the SLD
    //  ... and use the Bayes best params
    problemStruct.fitParams.set_size(1, bayesOutputs_bestParams_size[1]);
    loop_ub = bayesOutputs_bestParams_size[1];
    for (int i{0}; i < loop_ub; i++) {
      problemStruct.fitParams[i] = bayesOutputs_bestParams_data[i];
    }

    unpackParams(problemStruct);
    percentileConfidenceIntervals(bayesOutputs_chain,
      bayesResults.confidenceIntervals.percentile95,
      bayesResults.confidenceIntervals.percentile65,
      bayesResults.confidenceIntervals.mean);

    //  Calculate 'mean' best fit curves
    expl_temp.calcSLD = true;
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

    b_reflectivityCalculation(problemStruct, &expl_temp, result);

    //  2. Reflectivity and SLD shading
    b_problemStruct = problemStruct;
    refPercentileConfidenceIntervals(bayesOutputs_chain, b_problemStruct,
      controls_parallel_data, controls_parallel_size,
      controls_numSimulationPoints, controls_resampleMinAngle,
      controls_resampleNPoints, result.reflectivity, result.sldProfiles,
      bayesResults.predictionIntervals.reflectivity,
      bayesResults.predictionIntervals.sld,
      bayesResults.predictionIntervals.sampleChi);

    //  ---------------------------------
    //  bayesResults.chain = bayesOutputs.chain;
  }

  void processBayes(const ::coder::array<double, 2U> &bayesOutputs_bestParams,
                    const ::coder::array<double, 2U> &bayesOutputs_chain,
                    ProblemDefinition &problemStruct, Controls &controls,
                    b_struct_T &result, e_struct_T &bayesResults)
  {
    int loop_ub;

    //  Process the output of a Bayesian optimisation.
    //
    //  Parameters
    //  ----------
    //  bayesOutputs : struct
    //      The outputs of the Bayesian optimisation.
    //  problemStruct : struct
    //      The struct for the project.
    //  controls : struct
    //      The struct for the controls.
    //
    //  Returns
    //  -------
    //  problemStruct : struct
    //      The struct for the output project.
    //  result : struct
    //      The results object from the optimisation.
    //  bayesResults : struct
    //      The Bayesian-specific results from the optimisation.
    //  Need to impose that we calculate the SLD
    controls.calcSLD = true;

    //  ... and use the Bayes best params
    problemStruct.fitParams.set_size(1, bayesOutputs_bestParams.size(1));
    loop_ub = bayesOutputs_bestParams.size(1);
    for (int i{0}; i < loop_ub; i++) {
      problemStruct.fitParams[i] = bayesOutputs_bestParams[i];
    }

    ProblemDefinition b_problemStruct;
    unpackParams(problemStruct);
    percentileConfidenceIntervals(bayesOutputs_chain,
      bayesResults.confidenceIntervals.percentile95,
      bayesResults.confidenceIntervals.percentile65,
      bayesResults.confidenceIntervals.mean);

    //  Calculate 'mean' best fit curves
    b_reflectivityCalculation(problemStruct, &controls, result);

    //  2. Reflectivity and SLD shading
    b_problemStruct = problemStruct;
    refPercentileConfidenceIntervals(bayesOutputs_chain, b_problemStruct,
      controls, result.reflectivity, result.sldProfiles,
      bayesResults.predictionIntervals.reflectivity,
      bayesResults.predictionIntervals.sld,
      bayesResults.predictionIntervals.sampleChi);

    //  ---------------------------------
    //  bayesResults.chain = bayesOutputs.chain;
  }
}

// End of code generation (processBayes.cpp)
