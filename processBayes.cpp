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

// Function Definitions
namespace RAT
{
  void processBayes(const double bayesOutputs_bestParams_data[], const int
                    bayesOutputs_bestParams_size[2], const ::coder::array<double,
                    2U> &bayesOutputs_chain, ProblemDefinition &problemStruct,
                    Controls &controls, Results *result, e_struct_T
                    &bayesResults)
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
    //  Need to impose that we calculate the SLD..
    controls.calcSldDuringFit = true;

    //  ... and use the Bayes best params
    problemStruct.fitParams.set_size(1, bayesOutputs_bestParams_size[1]);
    loop_ub = bayesOutputs_bestParams_size[1];
    for (int i{0}; i < loop_ub; i++) {
      problemStruct.fitParams[i] = bayesOutputs_bestParams_data[i];
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
      controls, result->reflectivity, result->sldProfiles,
      bayesResults.predictionIntervals.reflectivity,
      bayesResults.predictionIntervals.sld,
      bayesResults.predictionIntervals.sampleChi);

    //  ---------------------------------
    //  bayesResults.chain = bayesOutputs.chain;
  }

  void processBayes(const ::coder::array<double, 2U> &bayesOutputs_bestParams,
                    const ::coder::array<double, 2U> &bayesOutputs_chain,
                    ProblemDefinition &problemStruct, Controls &controls,
                    Results *result, e_struct_T &bayesResults)
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
    //  Need to impose that we calculate the SLD..
    controls.calcSldDuringFit = true;

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
      controls, result->reflectivity, result->sldProfiles,
      bayesResults.predictionIntervals.reflectivity,
      bayesResults.predictionIntervals.sld,
      bayesResults.predictionIntervals.sampleChi);

    //  ---------------------------------
    //  bayesResults.chain = bayesOutputs.chain;
  }
}

// End of code generation (processBayes.cpp)
