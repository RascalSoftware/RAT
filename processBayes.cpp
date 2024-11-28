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
#include "coder_bounded_array.h"
#include <algorithm>

// Function Definitions
namespace RAT
{
  void processBayes(const ::coder::array<real_T, 2U> &bayesOutputs_bestParams,
                    const ::coder::array<real_T, 2U> &bayesOutputs_chain, const
                    e_struct_T *problemStruct, const struct2_T *problemLimits,
                    struct3_T *controls, g_struct_T *b_problemStruct, struct6_T *
                    result, j_struct_T *bayesResults)
  {
    g_struct_T c_problemStruct;
    int32_T b_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    b_problemStruct->TF.size[0] = 1;
    b_problemStruct->TF.size[1] = problemStruct->TF.size[1];
    loop_ub = problemStruct->TF.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&problemStruct->TF.data[0], &problemStruct->TF.data[loop_ub],
                &b_problemStruct->TF.data[0]);
    }

    b_problemStruct->resample.set_size(1, problemStruct->resample.size(1));
    loop_ub = problemStruct->resample.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->resample[i] = problemStruct->resample[i];
    }

    b_problemStruct->data.set_size(1, problemStruct->data.size(1));
    loop_ub = problemStruct->data.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->data[i] = problemStruct->data[i];
    }

    b_problemStruct->dataPresent.set_size(1, problemStruct->dataPresent.size(1));
    loop_ub = problemStruct->dataPresent.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->dataPresent[i] = problemStruct->dataPresent[i];
    }

    b_problemStruct->dataLimits.set_size(1, problemStruct->dataLimits.size(1));
    loop_ub = problemStruct->dataLimits.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->dataLimits[i] = problemStruct->dataLimits[i];
    }

    b_problemStruct->simulationLimits.set_size(1,
      problemStruct->simulationLimits.size(1));
    loop_ub = problemStruct->simulationLimits.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->simulationLimits[i] = problemStruct->simulationLimits[i];
    }

    b_problemStruct->oilChiDataPresent.set_size(1,
      problemStruct->oilChiDataPresent.size(1));
    loop_ub = problemStruct->oilChiDataPresent.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->oilChiDataPresent[i] = problemStruct->oilChiDataPresent[i];
    }

    b_problemStruct->numberOfContrasts = problemStruct->numberOfContrasts;
    b_problemStruct->geometry.size[0] = 1;
    b_problemStruct->geometry.size[1] = problemStruct->geometry.size[1];
    loop_ub = problemStruct->geometry.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&problemStruct->geometry.data[0], &problemStruct->
                geometry.data[loop_ub], &b_problemStruct->geometry.data[0]);
    }

    b_problemStruct->useImaginary = problemStruct->useImaginary;
    b_problemStruct->repeatLayers.set_size(1, problemStruct->repeatLayers.size(1));
    loop_ub = problemStruct->repeatLayers.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->repeatLayers[i] = problemStruct->repeatLayers[i];
    }

    b_problemStruct->contrastNames.set_size(1, problemStruct->contrastNames.size
      (1));
    loop_ub = problemStruct->contrastNames.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->contrastNames[i] = problemStruct->contrastNames[i];
    }

    b_problemStruct->contrastBackgroundParams.set_size(1,
      problemStruct->contrastBackgroundParams.size(1));
    loop_ub = problemStruct->contrastBackgroundParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->contrastBackgroundParams[i] =
        problemStruct->contrastBackgroundParams[i];
    }

    b_problemStruct->contrastBackgroundTypes.set_size(1,
      problemStruct->contrastBackgroundTypes.size(1));
    loop_ub = problemStruct->contrastBackgroundTypes.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->contrastBackgroundTypes[i] =
        problemStruct->contrastBackgroundTypes[i];
    }

    b_problemStruct->contrastBackgroundActions.set_size(1,
      problemStruct->contrastBackgroundActions.size(1));
    loop_ub = problemStruct->contrastBackgroundActions.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->contrastBackgroundActions[i] =
        problemStruct->contrastBackgroundActions[i];
    }

    b_problemStruct->contrastQzshifts.set_size(1,
      problemStruct->contrastQzshifts.size(1));
    loop_ub = problemStruct->contrastQzshifts.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->contrastQzshifts[i] = problemStruct->contrastQzshifts[i];
    }

    b_problemStruct->contrastScalefactors.set_size(1,
      problemStruct->contrastScalefactors.size(1));
    loop_ub = problemStruct->contrastScalefactors.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->contrastScalefactors[i] =
        problemStruct->contrastScalefactors[i];
    }

    b_problemStruct->contrastBulkIns.set_size(1,
      problemStruct->contrastBulkIns.size(1));
    loop_ub = problemStruct->contrastBulkIns.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->contrastBulkIns[i] = problemStruct->contrastBulkIns[i];
    }

    b_problemStruct->contrastBulkOuts.set_size(1,
      problemStruct->contrastBulkOuts.size(1));
    loop_ub = problemStruct->contrastBulkOuts.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->contrastBulkOuts[i] = problemStruct->contrastBulkOuts[i];
    }

    b_problemStruct->contrastResolutionParams.set_size(1,
      problemStruct->contrastResolutionParams.size(1));
    loop_ub = problemStruct->contrastResolutionParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->contrastResolutionParams[i] =
        problemStruct->contrastResolutionParams[i];
    }

    b_problemStruct->backgroundParams.set_size(1,
      problemStruct->backgroundParams.size(1));
    loop_ub = problemStruct->backgroundParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->backgroundParams[i] = problemStruct->backgroundParams[i];
    }

    b_problemStruct->qzshifts.set_size(1, problemStruct->qzshifts.size(1));
    loop_ub = problemStruct->qzshifts.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->qzshifts[i] = problemStruct->qzshifts[i];
    }

    b_problemStruct->scalefactors.set_size(1, problemStruct->scalefactors.size(1));
    loop_ub = problemStruct->scalefactors.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->scalefactors[i] = problemStruct->scalefactors[i];
    }

    b_problemStruct->bulkIn.set_size(1, problemStruct->bulkIn.size(1));
    loop_ub = problemStruct->bulkIn.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->bulkIn[i] = problemStruct->bulkIn[i];
    }

    b_problemStruct->bulkOut.set_size(1, problemStruct->bulkOut.size(1));
    loop_ub = problemStruct->bulkOut.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->bulkOut[i] = problemStruct->bulkOut[i];
    }

    b_problemStruct->resolutionParams.set_size(1,
      problemStruct->resolutionParams.size(1));
    loop_ub = problemStruct->resolutionParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->resolutionParams[i] = problemStruct->resolutionParams[i];
    }

    b_problemStruct->params.set_size(1, problemStruct->params.size(1));
    loop_ub = problemStruct->params.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->params[i] = problemStruct->params[i];
    }

    b_problemStruct->numberOfLayers = problemStruct->numberOfLayers;
    b_problemStruct->contrastLayers.set_size(1,
      problemStruct->contrastLayers.size(1));
    loop_ub = problemStruct->contrastLayers.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->contrastLayers[i] = problemStruct->contrastLayers[i];
    }

    b_problemStruct->layersDetails.set_size(problemStruct->layersDetails.size(0),
      problemStruct->layersDetails.size(1));
    loop_ub = problemStruct->layersDetails.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = problemStruct->layersDetails.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b_problemStruct->layersDetails[i1] = problemStruct->layersDetails[i1];
      }
    }

    b_problemStruct->customFiles.set_size(problemStruct->customFiles.size(0),
      problemStruct->customFiles.size(1));
    loop_ub = problemStruct->customFiles.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = problemStruct->customFiles.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b_problemStruct->customFiles[b_problemStruct->customFiles.size(0) * i] =
          problemStruct->customFiles[problemStruct->customFiles.size(0) * i];
      }
    }

    b_problemStruct->modelType.size[0] = 1;
    b_problemStruct->modelType.size[1] = problemStruct->modelType.size[1];
    loop_ub = problemStruct->modelType.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&problemStruct->modelType.data[0],
                &problemStruct->modelType.data[loop_ub],
                &b_problemStruct->modelType.data[0]);
    }

    b_problemStruct->contrastCustomFiles.set_size(1,
      problemStruct->contrastCustomFiles.size(1));
    loop_ub = problemStruct->contrastCustomFiles.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->contrastCustomFiles[i] =
        problemStruct->contrastCustomFiles[i];
    }

    b_problemStruct->contrastDomainRatios.set_size(1,
      problemStruct->contrastDomainRatios.size(1));
    loop_ub = problemStruct->contrastDomainRatios.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->contrastDomainRatios[i] =
        problemStruct->contrastDomainRatios[i];
    }

    b_problemStruct->domainRatio.set_size(1, problemStruct->domainRatio.size(1));
    loop_ub = problemStruct->domainRatio.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->domainRatio[i] = problemStruct->domainRatio[i];
    }

    b_problemStruct->numberOfDomainContrasts =
      problemStruct->numberOfDomainContrasts;
    b_problemStruct->domainContrastLayers.set_size(1,
      problemStruct->domainContrastLayers.size(1));
    loop_ub = problemStruct->domainContrastLayers.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->domainContrastLayers[i] =
        problemStruct->domainContrastLayers[i];
    }

    b_problemStruct->otherParams.set_size(problemStruct->otherParams.size(0));
    loop_ub = problemStruct->otherParams.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->otherParams[i] = problemStruct->otherParams[i];
    }

    b_problemStruct->fitLimits.set_size(problemStruct->fitLimits.size(0), 2);
    b_problemStruct->otherLimits.set_size(problemStruct->otherLimits.size(0), 2);
    loop_ub = problemStruct->fitLimits.size(0);
    b_loop_ub = problemStruct->otherLimits.size(0);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_problemStruct->fitLimits[i1 + b_problemStruct->fitLimits.size(0) * i] =
          problemStruct->fitLimits[i1 + problemStruct->fitLimits.size(0) * i];
      }

      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b_problemStruct->otherLimits[i1 + b_problemStruct->otherLimits.size(0) *
          i] = problemStruct->otherLimits[i1 + problemStruct->otherLimits.size(0)
          * i];
      }
    }

    b_problemStruct->names = problemStruct->names;

    //  Need to impose that we calculate the SLD..
    controls->calcSldDuringFit = true;

    // ... and use the Bayes best params
    b_problemStruct->fitParams.set_size(1, bayesOutputs_bestParams.size(1));
    loop_ub = bayesOutputs_bestParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_problemStruct->fitParams[b_problemStruct->fitParams.size(0) * i] =
        bayesOutputs_bestParams[i];
    }

    unpackParams(b_problemStruct, controls->checks.fitParam,
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
    reflectivityCalculation(b_problemStruct, problemLimits->param,
      problemLimits->backgroundParam, problemLimits->scalefactor,
      problemLimits->qzshift, problemLimits->bulkIn, problemLimits->bulkOut,
      problemLimits->resolutionParam, problemLimits->domainRatio, controls,
      result);

    //  2. Reflectivity and SLD shading
    c_problemStruct = *b_problemStruct;
    refPercentileConfidenceIntervals(bayesOutputs_chain, &c_problemStruct,
      problemLimits->param, problemLimits->backgroundParam,
      problemLimits->scalefactor, problemLimits->qzshift, problemLimits->bulkIn,
      problemLimits->bulkOut, problemLimits->resolutionParam,
      problemLimits->domainRatio, controls, result,
      &bayesResults->predictionIntervals);

    //  ---------------------------------
    //  bayesResults.chain = bayesOutputs.chain;
  }
}

// End of code generation (processBayes.cpp)
