//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// extractProblemParams.cpp
//
// Code generation for function 'extractProblemParams'
//

// Include files
#include "extractProblemParams.h"
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>

// Function Definitions
namespace RAT
{
  void extractProblemParams(const b_ProblemDefinition *problemStruct, double
    *numberOfContrasts, char geometry_data[], int geometry_size[2], ::coder::
    array<cell_wrap_47, 2U> &contrastBackgroundParams, ::coder::array<double, 2U>
    &contrastQzshifts, ::coder::array<double, 2U> &contrastScalefactors, ::coder::
    array<double, 2U> &contrastBulkIns, ::coder::array<double, 2U>
    &contrastBulkOuts, ::coder::array<cell_wrap_9, 2U> &contrastResolutionParams,
    ::coder::array<double, 2U> &contrastDomainRatios, ::coder::array<double, 2U>
    &backgroundParams, ::coder::array<double, 2U> &scalefactors, ::coder::array<
    double, 2U> &bulkIns, ::coder::array<double, 2U> &bulkOuts, ::coder::array<
    double, 2U> &resolutionParams, ::coder::array<double, 2U> &domainRatios, ::
    coder::array<double, 2U> &dataPresent, double *nParams, ::coder::array<
    double, 2U> &params, double *numberOfLayers, ::coder::array<double, 2U>
    &resample, ::coder::array<cell_wrap_10, 2U> &contrastBackgroundTypes, ::
    coder::array<cell_wrap_10, 2U> &contrastBackgroundActions, ::coder::array<
    cell_wrap_10, 2U> &contrastResolutionTypes, ::coder::array<double, 2U>
    &contrastCustomFiles, boolean_T *useImaginary, ::coder::array<cell_wrap_2,
    2U> &repeatLayers, ::coder::array<cell_wrap_1, 2U> &data, ::coder::array<
    cell_wrap_2, 2U> &dataLimits, ::coder::array<cell_wrap_2, 2U> &simLimits, ::
    coder::array<cell_wrap_9, 2U> &contrastLayers, ::coder::array<cell_wrap_9,
    2U> &layersDetails, ::coder::array<cell_wrap_10, 2U> &customFiles, ::coder::
    array<cell_wrap_9, 2U> &domainContrastLayers)
  {
    int b_nParams;
    int i;
    int loop_ub;
    *numberOfContrasts = problemStruct->numberOfContrasts;
    geometry_size[0] = 1;
    geometry_size[1] = problemStruct->geometry.size[1];
    loop_ub = problemStruct->geometry.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&problemStruct->geometry.data[0], &problemStruct->
                geometry.data[loop_ub], &geometry_data[0]);
    }

    cast(problemStruct->contrastBackgroundParams, contrastBackgroundParams);
    cast(problemStruct->contrastBackgroundTypes, contrastBackgroundTypes);
    cast(problemStruct->contrastBackgroundActions, contrastBackgroundActions);
    contrastScalefactors.set_size(1, problemStruct->contrastScalefactors.size(1));
    loop_ub = problemStruct->contrastScalefactors.size(1);
    for (i = 0; i < loop_ub; i++) {
      contrastScalefactors[i] = problemStruct->contrastScalefactors[i];
    }

    contrastBulkIns.set_size(1, problemStruct->contrastBulkIns.size(1));
    loop_ub = problemStruct->contrastBulkIns.size(1);
    for (i = 0; i < loop_ub; i++) {
      contrastBulkIns[i] = problemStruct->contrastBulkIns[i];
    }

    contrastBulkOuts.set_size(1, problemStruct->contrastBulkOuts.size(1));
    loop_ub = problemStruct->contrastBulkOuts.size(1);
    for (i = 0; i < loop_ub; i++) {
      contrastBulkOuts[i] = problemStruct->contrastBulkOuts[i];
    }

    cast(problemStruct->contrastResolutionParams, contrastResolutionParams);
    cast(problemStruct->contrastResolutionTypes, contrastResolutionTypes);
    contrastDomainRatios.set_size(1, problemStruct->contrastDomainRatios.size(1));
    loop_ub = problemStruct->contrastDomainRatios.size(1);
    for (i = 0; i < loop_ub; i++) {
      contrastDomainRatios[i] = problemStruct->contrastDomainRatios[i];
    }

    contrastCustomFiles.set_size(1, problemStruct->contrastCustomFiles.size(1));
    loop_ub = problemStruct->contrastCustomFiles.size(1);
    for (i = 0; i < loop_ub; i++) {
      contrastCustomFiles[i] = problemStruct->contrastCustomFiles[i];
    }

    backgroundParams.set_size(1, problemStruct->backgroundParams.size(1));
    loop_ub = problemStruct->backgroundParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      backgroundParams[i] = problemStruct->backgroundParams[i];
    }

    scalefactors.set_size(1, problemStruct->scalefactors.size(1));
    loop_ub = problemStruct->scalefactors.size(1);
    for (i = 0; i < loop_ub; i++) {
      scalefactors[i] = problemStruct->scalefactors[i];
    }

    bulkIns.set_size(1, problemStruct->bulkIns.size(1));
    loop_ub = problemStruct->bulkIns.size(1);
    for (i = 0; i < loop_ub; i++) {
      bulkIns[i] = problemStruct->bulkIns[i];
    }

    bulkOuts.set_size(1, problemStruct->bulkOuts.size(1));
    loop_ub = problemStruct->bulkOuts.size(1);
    for (i = 0; i < loop_ub; i++) {
      bulkOuts[i] = problemStruct->bulkOuts[i];
    }

    resolutionParams.set_size(1, problemStruct->resolutionParams.size(1));
    loop_ub = problemStruct->resolutionParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      resolutionParams[i] = problemStruct->resolutionParams[i];
    }

    domainRatios.set_size(1, problemStruct->domainRatios.size(1));
    loop_ub = problemStruct->domainRatios.size(1);
    for (i = 0; i < loop_ub; i++) {
      domainRatios[i] = problemStruct->domainRatios[i];
    }

    dataPresent.set_size(1, problemStruct->dataPresent.size(1));
    loop_ub = problemStruct->dataPresent.size(1);
    for (i = 0; i < loop_ub; i++) {
      dataPresent[i] = problemStruct->dataPresent[i];
    }

    b_nParams = problemStruct->params.size(1);
    params.set_size(1, problemStruct->params.size(1));
    loop_ub = problemStruct->params.size(1);
    for (i = 0; i < loop_ub; i++) {
      params[i] = problemStruct->params[i];
    }

    *numberOfLayers = problemStruct->numberOfLayers;
    resample.set_size(1, problemStruct->resample.size(1));
    loop_ub = problemStruct->resample.size(1);
    for (i = 0; i < loop_ub; i++) {
      resample[i] = problemStruct->resample[i];
    }

    *useImaginary = problemStruct->useImaginary;
    repeatLayers.set_size(1, problemStruct->repeatLayers.size(1));
    loop_ub = problemStruct->repeatLayers.size(1);
    for (i = 0; i < loop_ub; i++) {
      repeatLayers[i] = problemStruct->repeatLayers[i];
    }

    data.set_size(1, problemStruct->data.size(1));
    loop_ub = problemStruct->data.size(1);
    for (i = 0; i < loop_ub; i++) {
      data[i] = problemStruct->data[i];
    }

    dataLimits.set_size(1, problemStruct->dataLimits.size(1));
    loop_ub = problemStruct->dataLimits.size(1);
    for (i = 0; i < loop_ub; i++) {
      dataLimits[i] = problemStruct->dataLimits[i];
    }

    simLimits.set_size(1, problemStruct->simulationLimits.size(1));
    loop_ub = problemStruct->simulationLimits.size(1);
    for (i = 0; i < loop_ub; i++) {
      simLimits[i] = problemStruct->simulationLimits[i];
    }

    cast(problemStruct->contrastLayers, contrastLayers);
    cast(problemStruct->layersDetails, layersDetails);
    cast(problemStruct->customFiles, customFiles);
    cast(problemStruct->domainContrastLayers, domainContrastLayers);

    //  qzshifts are not included as a parameter in RAT, so we set up dummy
    //  values for the reflectivity calculation
    loop_ub = static_cast<int>(problemStruct->numberOfContrasts);
    contrastQzshifts.set_size(1, loop_ub);
    for (i = 0; i < loop_ub; i++) {
      contrastQzshifts[i] = 1.0;
    }

    *nParams = b_nParams;
  }
}

// End of code generation (extractProblemParams.cpp)
