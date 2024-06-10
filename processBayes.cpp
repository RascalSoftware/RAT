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
  void processBayes(const real_T bayesOutputs_bestParams_data[], const int32_T
                    bayesOutputs_bestParams_size[2], const ::coder::array<real_T,
                    2U> &bayesOutputs_chain, f_struct_T *problemStruct, const
                    cell_11 *problemCells, const struct1_T *problemLimits,
                    struct2_T *controls, struct5_T *result, i_struct_T
                    *bayesResults)
  {
    static f_struct_T b_problemStruct;
    int32_T loop_ub;

    //  Need to impose that we calculate the SLD..
    controls->calcSldDuringFit = true;

    // ... and use the Bayes best params
    problemStruct->fitParams.set_size(1, bayesOutputs_bestParams_size[1]);
    loop_ub = bayesOutputs_bestParams_size[1];
    for (int32_T i{0}; i < loop_ub; i++) {
      problemStruct->fitParams[problemStruct->fitParams.size(0) * i] =
        bayesOutputs_bestParams_data[i];
    }

    unpackParams(problemStruct, controls->checks.fitParam,
                 controls->checks.fitBackgroundParam,
                 controls->checks.fitQzshift, controls->checks.fitScalefactor,
                 controls->checks.fitBulkIn, controls->checks.fitBulkOut,
                 controls->checks.fitResolutionParam,
                 controls->checks.fitDomainRatio);
    percentileConfidenceIntervals(bayesOutputs_chain,
      bayesResults->confidenceIntervals.percentile95,
      bayesResults->confidenceIntervals.percentile65,
      bayesResults->confidenceIntervals.mean);

    // iterShortest(output.chain,length(fitNames),[],0.95);
    //  Calculate 'mean' best fit curves
    reflectivityCalculation(problemStruct, problemCells, problemLimits, controls,
      result);

    //  2. Reflectivity and SLD shading
    b_problemStruct = *problemStruct;
    refPercentileConfidenceIntervals(bayesOutputs_chain, &b_problemStruct,
      problemCells, problemLimits, controls, &bayesResults->predictionIntervals);

    //  ---------------------------------
    //  bayesResults.chain = bayesOutputs.chain;
  }

  void processBayes(const ::coder::array<real_T, 2U> &bayesOutputs_bestParams,
                    const ::coder::array<real_T, 2U> &bayesOutputs_chain,
                    f_struct_T *problemStruct, const cell_11 *problemCells,
                    const struct1_T *problemLimits, struct2_T *controls,
                    struct5_T *result, i_struct_T *bayesResults)
  {
    f_struct_T b_problemStruct;
    int32_T loop_ub;

    //  Need to impose that we calculate the SLD..
    controls->calcSldDuringFit = true;

    // ... and use the Bayes best params
    problemStruct->fitParams.set_size(1, bayesOutputs_bestParams.size(1));
    loop_ub = bayesOutputs_bestParams.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      problemStruct->fitParams[problemStruct->fitParams.size(0) * i] =
        bayesOutputs_bestParams[i];
    }

    unpackParams(problemStruct, controls->checks.fitParam,
                 controls->checks.fitBackgroundParam,
                 controls->checks.fitQzshift, controls->checks.fitScalefactor,
                 controls->checks.fitBulkIn, controls->checks.fitBulkOut,
                 controls->checks.fitResolutionParam,
                 controls->checks.fitDomainRatio);
    percentileConfidenceIntervals(bayesOutputs_chain,
      bayesResults->confidenceIntervals.percentile95,
      bayesResults->confidenceIntervals.percentile65,
      bayesResults->confidenceIntervals.mean);

    // iterShortest(output.chain,length(fitNames),[],0.95);
    //  Calculate 'mean' best fit curves
    reflectivityCalculation(problemStruct, problemCells, problemLimits, controls,
      result);

    //  2. Reflectivity and SLD shading
    b_problemStruct = *problemStruct;
    refPercentileConfidenceIntervals(bayesOutputs_chain, &b_problemStruct,
      problemCells, problemLimits, controls, &bayesResults->predictionIntervals);

    //  ---------------------------------
    //  bayesResults.chain = bayesOutputs.chain;
  }
}

// End of code generation (processBayes.cpp)
