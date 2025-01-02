//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
  void processBayes(const ::coder::array<real_T, 2U> &bayesOutputs_bestParams,
                    const ::coder::array<real_T, 2U> &bayesOutputs_chain,
                    e_struct_T *problemStruct, struct4_T *controls, struct6_T
                    *result, i_struct_T *bayesResults)
  {
    e_struct_T b_problemStruct;
    int32_T loop_ub;

    //  Need to impose that we calculate the SLD..
    controls->calcSldDuringFit = true;

    //  ... and use the Bayes best params
    problemStruct->fitParams.set_size(1, bayesOutputs_bestParams.size(1));
    loop_ub = bayesOutputs_bestParams.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      problemStruct->fitParams[i] = bayesOutputs_bestParams[i];
    }

    unpackParams(problemStruct);
    percentileConfidenceIntervals(bayesOutputs_chain,
      bayesResults->confidenceIntervals.percentile95,
      bayesResults->confidenceIntervals.percentile65,
      bayesResults->confidenceIntervals.mean);

    // iterShortest(output.chain,length(fitNames),[],0.95);
    //  Calculate 'mean' best fit curves
    b_reflectivityCalculation(problemStruct, controls, result);

    //  2. Reflectivity and SLD shading
    b_problemStruct = *problemStruct;
    refPercentileConfidenceIntervals(bayesOutputs_chain, &b_problemStruct,
      controls, result->reflectivity, result->sldProfiles,
      bayesResults->predictionIntervals.reflectivity,
      bayesResults->predictionIntervals.sld,
      bayesResults->predictionIntervals.sampleChi);

    //  ---------------------------------
    //  bayesResults.chain = bayesOutputs.chain;
  }
}

// End of code generation (processBayes.cpp)
