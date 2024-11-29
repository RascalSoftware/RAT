//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// nsIntraFun.cpp
//
// Code generation for function 'nsIntraFun'
//

// Include files
#include "nsIntraFun.h"
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
  real_T nsIntraFun(const e_struct_T *data_f1, const struct3_T *data_f2, const
                    struct2_T *data_f3, const ::coder::array<real_T, 2U> &p)
  {
    g_struct_T problemStruct;
    struct6_T expl_temp;
    int32_T b_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    problemStruct.TF.size[0] = 1;
    problemStruct.TF.size[1] = data_f1->TF.size[1];
    loop_ub = data_f1->TF.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&data_f1->TF.data[0], &data_f1->TF.data[loop_ub],
                &problemStruct.TF.data[0]);
    }

    problemStruct.resample.set_size(1, data_f1->resample.size(1));
    loop_ub = data_f1->resample.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.resample[i] = data_f1->resample[i];
    }

    problemStruct.data.set_size(1, data_f1->data.size(1));
    loop_ub = data_f1->data.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.data[i] = data_f1->data[i];
    }

    problemStruct.dataPresent.set_size(1, data_f1->dataPresent.size(1));
    loop_ub = data_f1->dataPresent.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.dataPresent[i] = data_f1->dataPresent[i];
    }

    problemStruct.dataLimits.set_size(1, data_f1->dataLimits.size(1));
    loop_ub = data_f1->dataLimits.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.dataLimits[i] = data_f1->dataLimits[i];
    }

    problemStruct.simulationLimits.set_size(1, data_f1->simulationLimits.size(1));
    loop_ub = data_f1->simulationLimits.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.simulationLimits[i] = data_f1->simulationLimits[i];
    }

    problemStruct.oilChiDataPresent.set_size(1, data_f1->oilChiDataPresent.size
      (1));
    loop_ub = data_f1->oilChiDataPresent.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.oilChiDataPresent[i] = data_f1->oilChiDataPresent[i];
    }

    problemStruct.numberOfContrasts = data_f1->numberOfContrasts;
    problemStruct.geometry.size[0] = 1;
    problemStruct.geometry.size[1] = data_f1->geometry.size[1];
    loop_ub = data_f1->geometry.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&data_f1->geometry.data[0], &data_f1->geometry.data[loop_ub],
                &problemStruct.geometry.data[0]);
    }

    problemStruct.useImaginary = data_f1->useImaginary;
    problemStruct.repeatLayers.set_size(1, data_f1->repeatLayers.size(1));
    loop_ub = data_f1->repeatLayers.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.repeatLayers[i] = data_f1->repeatLayers[i];
    }

    problemStruct.contrastNames.set_size(1, data_f1->contrastNames.size(1));
    loop_ub = data_f1->contrastNames.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.contrastNames[i] = data_f1->contrastNames[i];
    }

    problemStruct.contrastBackgroundParams.set_size(1,
      data_f1->contrastBackgroundParams.size(1));
    loop_ub = data_f1->contrastBackgroundParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.contrastBackgroundParams[i] =
        data_f1->contrastBackgroundParams[i];
    }

    problemStruct.contrastBackgroundTypes.set_size(1,
      data_f1->contrastBackgroundTypes.size(1));
    loop_ub = data_f1->contrastBackgroundTypes.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.contrastBackgroundTypes[i] =
        data_f1->contrastBackgroundTypes[i];
    }

    problemStruct.contrastBackgroundActions.set_size(1,
      data_f1->contrastBackgroundActions.size(1));
    loop_ub = data_f1->contrastBackgroundActions.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.contrastBackgroundActions[i] =
        data_f1->contrastBackgroundActions[i];
    }

    problemStruct.contrastQzshifts.set_size(1, data_f1->contrastQzshifts.size(1));
    loop_ub = data_f1->contrastQzshifts.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.contrastQzshifts[i] = data_f1->contrastQzshifts[i];
    }

    problemStruct.contrastScalefactors.set_size(1,
      data_f1->contrastScalefactors.size(1));
    loop_ub = data_f1->contrastScalefactors.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.contrastScalefactors[i] = data_f1->contrastScalefactors[i];
    }

    problemStruct.contrastBulkIns.set_size(1, data_f1->contrastBulkIns.size(1));
    loop_ub = data_f1->contrastBulkIns.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.contrastBulkIns[i] = data_f1->contrastBulkIns[i];
    }

    problemStruct.contrastBulkOuts.set_size(1, data_f1->contrastBulkOuts.size(1));
    loop_ub = data_f1->contrastBulkOuts.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.contrastBulkOuts[i] = data_f1->contrastBulkOuts[i];
    }

    problemStruct.contrastResolutionParams.set_size(1,
      data_f1->contrastResolutionParams.size(1));
    loop_ub = data_f1->contrastResolutionParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.contrastResolutionParams[i] =
        data_f1->contrastResolutionParams[i];
    }

    problemStruct.backgroundParams.set_size(1, data_f1->backgroundParams.size(1));
    loop_ub = data_f1->backgroundParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.backgroundParams[i] = data_f1->backgroundParams[i];
    }

    problemStruct.qzshifts.set_size(1, data_f1->qzshifts.size(1));
    loop_ub = data_f1->qzshifts.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.qzshifts[i] = data_f1->qzshifts[i];
    }

    problemStruct.scalefactors.set_size(1, data_f1->scalefactors.size(1));
    loop_ub = data_f1->scalefactors.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.scalefactors[i] = data_f1->scalefactors[i];
    }

    problemStruct.bulkIn.set_size(1, data_f1->bulkIn.size(1));
    loop_ub = data_f1->bulkIn.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.bulkIn[i] = data_f1->bulkIn[i];
    }

    problemStruct.bulkOut.set_size(1, data_f1->bulkOut.size(1));
    loop_ub = data_f1->bulkOut.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.bulkOut[i] = data_f1->bulkOut[i];
    }

    problemStruct.resolutionParams.set_size(1, data_f1->resolutionParams.size(1));
    loop_ub = data_f1->resolutionParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.resolutionParams[i] = data_f1->resolutionParams[i];
    }

    problemStruct.params.set_size(1, data_f1->params.size(1));
    loop_ub = data_f1->params.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.params[i] = data_f1->params[i];
    }

    problemStruct.numberOfLayers = data_f1->numberOfLayers;
    problemStruct.contrastLayers.set_size(1, data_f1->contrastLayers.size(1));
    loop_ub = data_f1->contrastLayers.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.contrastLayers[i] = data_f1->contrastLayers[i];
    }

    problemStruct.layersDetails.set_size(data_f1->layersDetails.size(0),
      data_f1->layersDetails.size(1));
    loop_ub = data_f1->layersDetails.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = data_f1->layersDetails.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        problemStruct.layersDetails[i1] = data_f1->layersDetails[i1];
      }
    }

    problemStruct.customFiles.set_size(1, data_f1->customFiles.size(1));
    loop_ub = data_f1->customFiles.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.customFiles[i] = data_f1->customFiles[i];
    }

    problemStruct.modelType.size[0] = 1;
    problemStruct.modelType.size[1] = data_f1->modelType.size[1];
    loop_ub = data_f1->modelType.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&data_f1->modelType.data[0], &data_f1->modelType.data[loop_ub],
                &problemStruct.modelType.data[0]);
    }

    problemStruct.contrastCustomFiles.set_size(1,
      data_f1->contrastCustomFiles.size(1));
    loop_ub = data_f1->contrastCustomFiles.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.contrastCustomFiles[i] = data_f1->contrastCustomFiles[i];
    }

    problemStruct.contrastDomainRatios.set_size(1,
      data_f1->contrastDomainRatios.size(1));
    loop_ub = data_f1->contrastDomainRatios.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.contrastDomainRatios[i] = data_f1->contrastDomainRatios[i];
    }

    problemStruct.domainRatio.set_size(1, data_f1->domainRatio.size(1));
    loop_ub = data_f1->domainRatio.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.domainRatio[i] = data_f1->domainRatio[i];
    }

    problemStruct.numberOfDomainContrasts = data_f1->numberOfDomainContrasts;
    problemStruct.domainContrastLayers.set_size(1,
      data_f1->domainContrastLayers.size(1));
    loop_ub = data_f1->domainContrastLayers.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.domainContrastLayers[i] = data_f1->domainContrastLayers[i];
    }

    problemStruct.otherParams.set_size(data_f1->otherParams.size(0));
    loop_ub = data_f1->otherParams.size(0);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.otherParams[i] = data_f1->otherParams[i];
    }

    problemStruct.fitLimits.set_size(data_f1->fitLimits.size(0), 2);
    problemStruct.otherLimits.set_size(data_f1->otherLimits.size(0), 2);
    loop_ub = data_f1->fitLimits.size(0);
    b_loop_ub = data_f1->otherLimits.size(0);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        problemStruct.fitLimits[i1 + problemStruct.fitLimits.size(0) * i] =
          data_f1->fitLimits[i1 + data_f1->fitLimits.size(0) * i];
      }

      for (i1 = 0; i1 < b_loop_ub; i1++) {
        problemStruct.otherLimits[i1 + problemStruct.otherLimits.size(0) * i] =
          data_f1->otherLimits[i1 + data_f1->otherLimits.size(0) * i];
      }
    }

    problemStruct.names = data_f1->names;

    //  Removed use of cells....
    problemStruct.fitParams.set_size(1, p.size(1));
    loop_ub = p.size(1);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.fitParams[problemStruct.fitParams.size(0) * i] = p[i];
    }

    unpackParams(&problemStruct, data_f2->checks.fitParam,
                 data_f2->checks.fitBackgroundParam, data_f2->checks.fitQzshift,
                 data_f2->checks.fitScalefactor, data_f2->checks.fitBulkIn,
                 data_f2->checks.fitBulkOut, data_f2->checks.fitResolutionParam,
                 data_f2->checks.fitDomainRatio);
    reflectivityCalculation(&problemStruct, data_f3->param,
      data_f3->backgroundParam, data_f3->scalefactor, data_f3->qzshift,
      data_f3->bulkIn, data_f3->bulkOut, data_f3->resolutionParam,
      data_f3->domainRatio, data_f2, &expl_temp);
    return -expl_temp.calculationResults.sumChi / 2.0;
  }

  real_T nsIntraFun(const e_struct_T *data_f1, const struct3_T *data_f2, const
                    struct2_T *data_f3, const ::coder::array<real_T, 1U> &p)
  {
    e_struct_T problemStruct;
    f_struct_T expl_temp;
    int32_T loop_ub;
    problemStruct = *data_f1;

    //  Removed use of cells....
    problemStruct.fitParams.set_size(p.size(0));
    loop_ub = p.size(0);
    for (int32_T i{0}; i < loop_ub; i++) {
      problemStruct.fitParams[i] = p[i];
    }

    unpackParams(&problemStruct, data_f2->checks.fitParam,
                 data_f2->checks.fitBackgroundParam, data_f2->checks.fitQzshift,
                 data_f2->checks.fitScalefactor, data_f2->checks.fitBulkIn,
                 data_f2->checks.fitBulkOut, data_f2->checks.fitResolutionParam,
                 data_f2->checks.fitDomainRatio);
    reflectivityCalculation(&problemStruct, data_f3->param,
      data_f3->backgroundParam, data_f3->scalefactor, data_f3->qzshift,
      data_f3->bulkIn, data_f3->bulkOut, data_f3->resolutionParam,
      data_f3->domainRatio, data_f2, &expl_temp);
    return -expl_temp.calculationResults.sumChi / 2.0;
  }
}

// End of code generation (nsIntraFun.cpp)
