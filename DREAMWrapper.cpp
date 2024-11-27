//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// DREAMWrapper.cpp
//
// Code generation for function 'DREAMWrapper'
//

// Include files
#include "DREAMWrapper.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "reflectivityCalculation.h"
#include "rt_nonfinite.h"
#include "unpackParams.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>

// Function Definitions
namespace RAT
{
  real_T DREAMWrapper(const ::coder::array<real_T, 2U> &pars, const d_struct_T
                      *ratInputs_problemStruct, const cell_16
                      *ratInputs_problemCells, const struct1_T
                      *ratInputs_problemLimits, const struct2_T
                      *ratInputs_controls)
  {
    f_struct_T problemStruct;
    struct5_T expl_temp;
    int32_T b_loop_ub;
    int32_T i;
    int32_T loop_ub;

    //  Get the inputs for Reflectivity Calculation
    problemStruct.TF.size[0] = 1;
    problemStruct.TF.size[1] = ratInputs_problemStruct->TF.size[1];
    loop_ub = ratInputs_problemStruct->TF.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&ratInputs_problemStruct->TF.data[0],
                &ratInputs_problemStruct->TF.data[loop_ub],
                &problemStruct.TF.data[0]);
    }

    problemStruct.resample.set_size(1, ratInputs_problemStruct->resample.size(1));
    loop_ub = ratInputs_problemStruct->resample.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.resample[i] = ratInputs_problemStruct->resample[i];
    }

    problemStruct.dataPresent.set_size(1,
      ratInputs_problemStruct->dataPresent.size(1));
    loop_ub = ratInputs_problemStruct->dataPresent.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.dataPresent[i] = ratInputs_problemStruct->dataPresent[i];
    }

    problemStruct.oilChiDataPresent.set_size(1,
      ratInputs_problemStruct->oilChiDataPresent.size(1));
    loop_ub = ratInputs_problemStruct->oilChiDataPresent.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.oilChiDataPresent[i] =
        ratInputs_problemStruct->oilChiDataPresent[i];
    }

    problemStruct.numberOfContrasts = ratInputs_problemStruct->numberOfContrasts;
    problemStruct.geometry.size[0] = 1;
    problemStruct.geometry.size[1] = ratInputs_problemStruct->geometry.size[1];
    loop_ub = ratInputs_problemStruct->geometry.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&ratInputs_problemStruct->geometry.data[0],
                &ratInputs_problemStruct->geometry.data[loop_ub],
                &problemStruct.geometry.data[0]);
    }

    problemStruct.useImaginary = ratInputs_problemStruct->useImaginary;
    problemStruct.contrastBackgroundParams.set_size(1,
      ratInputs_problemStruct->contrastBackgroundParams.size(1));
    loop_ub = ratInputs_problemStruct->contrastBackgroundParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.contrastBackgroundParams[i] =
        ratInputs_problemStruct->contrastBackgroundParams[i];
    }

    problemStruct.contrastBackgroundTypes.set_size(1,
      ratInputs_problemStruct->contrastBackgroundTypes.size(1));
    loop_ub = ratInputs_problemStruct->contrastBackgroundTypes.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.contrastBackgroundTypes[i] =
        ratInputs_problemStruct->contrastBackgroundTypes[i];
    }

    problemStruct.contrastBackgroundActions.set_size(1,
      ratInputs_problemStruct->contrastBackgroundActions.size(1));
    loop_ub = ratInputs_problemStruct->contrastBackgroundActions.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.contrastBackgroundActions[i] =
        ratInputs_problemStruct->contrastBackgroundActions[i];
    }

    problemStruct.contrastQzshifts.set_size(1,
      ratInputs_problemStruct->contrastQzshifts.size(1));
    loop_ub = ratInputs_problemStruct->contrastQzshifts.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.contrastQzshifts[i] =
        ratInputs_problemStruct->contrastQzshifts[i];
    }

    problemStruct.contrastScalefactors.set_size(1,
      ratInputs_problemStruct->contrastScalefactors.size(1));
    loop_ub = ratInputs_problemStruct->contrastScalefactors.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.contrastScalefactors[i] =
        ratInputs_problemStruct->contrastScalefactors[i];
    }

    problemStruct.contrastBulkIns.set_size(1,
      ratInputs_problemStruct->contrastBulkIns.size(1));
    loop_ub = ratInputs_problemStruct->contrastBulkIns.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.contrastBulkIns[i] =
        ratInputs_problemStruct->contrastBulkIns[i];
    }

    problemStruct.contrastBulkOuts.set_size(1,
      ratInputs_problemStruct->contrastBulkOuts.size(1));
    loop_ub = ratInputs_problemStruct->contrastBulkOuts.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.contrastBulkOuts[i] =
        ratInputs_problemStruct->contrastBulkOuts[i];
    }

    problemStruct.contrastResolutionParams.set_size(1,
      ratInputs_problemStruct->contrastResolutionParams.size(1));
    loop_ub = ratInputs_problemStruct->contrastResolutionParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.contrastResolutionParams[i] =
        ratInputs_problemStruct->contrastResolutionParams[i];
    }

    problemStruct.backgroundParams.set_size(1,
      ratInputs_problemStruct->backgroundParams.size(1));
    loop_ub = ratInputs_problemStruct->backgroundParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.backgroundParams[i] =
        ratInputs_problemStruct->backgroundParams[i];
    }

    problemStruct.qzshifts.set_size(1, ratInputs_problemStruct->qzshifts.size(1));
    loop_ub = ratInputs_problemStruct->qzshifts.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.qzshifts[i] = ratInputs_problemStruct->qzshifts[i];
    }

    problemStruct.scalefactors.set_size(1,
      ratInputs_problemStruct->scalefactors.size(1));
    loop_ub = ratInputs_problemStruct->scalefactors.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.scalefactors[i] = ratInputs_problemStruct->scalefactors[i];
    }

    problemStruct.bulkIn.set_size(1, ratInputs_problemStruct->bulkIn.size(1));
    loop_ub = ratInputs_problemStruct->bulkIn.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.bulkIn[i] = ratInputs_problemStruct->bulkIn[i];
    }

    problemStruct.bulkOut.set_size(1, ratInputs_problemStruct->bulkOut.size(1));
    loop_ub = ratInputs_problemStruct->bulkOut.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.bulkOut[i] = ratInputs_problemStruct->bulkOut[i];
    }

    problemStruct.resolutionParams.set_size(1,
      ratInputs_problemStruct->resolutionParams.size(1));
    loop_ub = ratInputs_problemStruct->resolutionParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.resolutionParams[i] =
        ratInputs_problemStruct->resolutionParams[i];
    }

    problemStruct.params.set_size(1, ratInputs_problemStruct->params.size(1));
    loop_ub = ratInputs_problemStruct->params.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.params[i] = ratInputs_problemStruct->params[i];
    }

    problemStruct.numberOfLayers = ratInputs_problemStruct->numberOfLayers;
    problemStruct.modelType.size[0] = 1;
    problemStruct.modelType.size[1] = ratInputs_problemStruct->modelType.size[1];
    loop_ub = ratInputs_problemStruct->modelType.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&ratInputs_problemStruct->modelType.data[0],
                &ratInputs_problemStruct->modelType.data[loop_ub],
                &problemStruct.modelType.data[0]);
    }

    problemStruct.contrastCustomFiles.set_size(1,
      ratInputs_problemStruct->contrastCustomFiles.size(1));
    loop_ub = ratInputs_problemStruct->contrastCustomFiles.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.contrastCustomFiles[i] =
        ratInputs_problemStruct->contrastCustomFiles[i];
    }

    problemStruct.contrastDomainRatios.set_size(1,
      ratInputs_problemStruct->contrastDomainRatios.size(1));
    loop_ub = ratInputs_problemStruct->contrastDomainRatios.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.contrastDomainRatios[i] =
        ratInputs_problemStruct->contrastDomainRatios[i];
    }

    problemStruct.domainRatio.set_size(1,
      ratInputs_problemStruct->domainRatio.size(1));
    loop_ub = ratInputs_problemStruct->domainRatio.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.domainRatio[i] = ratInputs_problemStruct->domainRatio[i];
    }

    problemStruct.numberOfDomainContrasts =
      ratInputs_problemStruct->numberOfDomainContrasts;
    problemStruct.otherParams.set_size(ratInputs_problemStruct->otherParams.size
      (0));
    loop_ub = ratInputs_problemStruct->otherParams.size(0);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.otherParams[i] = ratInputs_problemStruct->otherParams[i];
    }

    problemStruct.fitLimits.set_size(ratInputs_problemStruct->fitLimits.size(0),
      2);
    problemStruct.otherLimits.set_size(ratInputs_problemStruct->otherLimits.size
      (0), 2);
    loop_ub = ratInputs_problemStruct->fitLimits.size(0);
    b_loop_ub = ratInputs_problemStruct->otherLimits.size(0);
    for (i = 0; i < 2; i++) {
      int32_T i1;
      for (i1 = 0; i1 < loop_ub; i1++) {
        problemStruct.fitLimits[i1 + problemStruct.fitLimits.size(0) * i] =
          ratInputs_problemStruct->fitLimits[i1 +
          ratInputs_problemStruct->fitLimits.size(0) * i];
      }

      for (i1 = 0; i1 < b_loop_ub; i1++) {
        problemStruct.otherLimits[i1 + problemStruct.otherLimits.size(0) * i] =
          ratInputs_problemStruct->otherLimits[i1 +
          ratInputs_problemStruct->otherLimits.size(0) * i];
      }
    }

    //  Put the current parameters into problem
    problemStruct.fitParams.set_size(1, pars.size(1));
    loop_ub = pars.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.fitParams[problemStruct.fitParams.size(0) * i] = pars[i];
    }

    //  Distribute them to the right parts
    unpackParams(&problemStruct, ratInputs_controls->checks.fitParam,
                 ratInputs_controls->checks.fitBackgroundParam,
                 ratInputs_controls->checks.fitQzshift,
                 ratInputs_controls->checks.fitScalefactor,
                 ratInputs_controls->checks.fitBulkIn,
                 ratInputs_controls->checks.fitBulkOut,
                 ratInputs_controls->checks.fitResolutionParam,
                 ratInputs_controls->checks.fitDomainRatio);

    //  Calculate....
    reflectivityCalculation(&problemStruct, ratInputs_problemCells,
      ratInputs_problemLimits, ratInputs_controls, &expl_temp);

    //  Function value is chi-squared....
    return -expl_temp.calculationResults.sumChi / 2.0;
  }
}

// End of code generation (DREAMWrapper.cpp)
