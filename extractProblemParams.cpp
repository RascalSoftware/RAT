//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// extractProblemParams.cpp
//
// Code generation for function 'extractProblemParams'
//

// Include files
#include "extractProblemParams.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>

// Function Definitions
namespace RAT
{
  double extractProblemParams(const ProblemDefinition &problemStruct, char
    geometry_data[], int geometry_size[2], ::coder::array<cell_wrap_44, 2U>
    &contrastBackgroundParams, ::coder::array<cell_wrap_9, 2U>
    &contrastResolutionParams, ::coder::array<double, 2U> &backgroundParams, ::
    coder::array<double, 2U> &resolutionParams, ::coder::array<double, 1U>
    &qzshifts, ::coder::array<double, 1U> &scalefactors, ::coder::array<double,
    1U> &bulkIns, ::coder::array<double, 1U> &bulkOuts, ::coder::array<double,
    1U> &domainRatios, ::coder::array<double, 2U> &dataPresent, ::coder::array<
    double, 2U> &params, ::coder::array<double, 2U> &resample, ::coder::array<
    cell_wrap_10, 2U> &contrastBackgroundTypes, ::coder::array<cell_wrap_10, 2U>
    &contrastBackgroundActions, ::coder::array<cell_wrap_10, 2U>
    &contrastResolutionTypes, ::coder::array<double, 2U> &contrastCustomFiles, ::
    coder::array<double, 2U> &repeatLayers, ::coder::array<cell_wrap_1, 2U>
    &data, ::coder::array<cell_wrap_2, 2U> &dataLimits, ::coder::array<
    cell_wrap_2, 2U> &simulationLimits, ::coder::array<cell_wrap_9, 2U>
    &contrastLayers, ::coder::array<cell_wrap_10, 2U> &customFiles, ::coder::
    array<cell_wrap_9, 2U> &domainContrastLayers, double &nParams, boolean_T
    &useImaginary)
  {
    double numberOfContrasts;
    int b_nParams;
    int loop_ub;
    resample.set_size(1, problemStruct.resample.size(1));
    loop_ub = problemStruct.resample.size(1);
    for (int i{0}; i < loop_ub; i++) {
      resample[i] = problemStruct.resample[i];
    }

    data.set_size(1, problemStruct.data.size(1));
    loop_ub = problemStruct.data.size(1);
    for (int i{0}; i < loop_ub; i++) {
      data[i] = problemStruct.data[i];
    }

    dataPresent.set_size(1, problemStruct.dataPresent.size(1));
    loop_ub = problemStruct.dataPresent.size(1);
    for (int i{0}; i < loop_ub; i++) {
      dataPresent[i] = problemStruct.dataPresent[i];
    }

    dataLimits.set_size(1, problemStruct.dataLimits.size(1));
    loop_ub = problemStruct.dataLimits.size(1);
    for (int i{0}; i < loop_ub; i++) {
      dataLimits[i] = problemStruct.dataLimits[i];
    }

    simulationLimits.set_size(1, problemStruct.simulationLimits.size(1));
    loop_ub = problemStruct.simulationLimits.size(1);
    for (int i{0}; i < loop_ub; i++) {
      simulationLimits[i] = problemStruct.simulationLimits[i];
    }

    geometry_size[0] = 1;
    geometry_size[1] = problemStruct.geometry.size[1];
    loop_ub = problemStruct.geometry.size[1];
    if (loop_ub - 1 >= 0) {
      std::copy(&problemStruct.geometry.data[0],
                &problemStruct.geometry.data[loop_ub], &geometry_data[0]);
    }

    repeatLayers.set_size(1, problemStruct.repeatLayers.size(1));
    loop_ub = problemStruct.repeatLayers.size(1);
    for (int i{0}; i < loop_ub; i++) {
      repeatLayers[i] = problemStruct.repeatLayers[i];
    }

    contrastBackgroundParams.set_size(1,
      problemStruct.contrastBackgroundParams.size(1));
    loop_ub = problemStruct.contrastBackgroundParams.size(1);
    for (int i{0}; i < loop_ub; i++) {
      contrastBackgroundParams[i] = problemStruct.contrastBackgroundParams[i];
    }

    contrastBackgroundTypes.set_size(1,
      problemStruct.contrastBackgroundTypes.size(1));
    loop_ub = problemStruct.contrastBackgroundTypes.size(1);
    for (int i{0}; i < loop_ub; i++) {
      contrastBackgroundTypes[i] = problemStruct.contrastBackgroundTypes[i];
    }

    contrastBackgroundActions.set_size(1,
      problemStruct.contrastBackgroundActions.size(1));
    loop_ub = problemStruct.contrastBackgroundActions.size(1);
    for (int i{0}; i < loop_ub; i++) {
      contrastBackgroundActions[i] = problemStruct.contrastBackgroundActions[i];
    }

    contrastResolutionParams.set_size(1,
      problemStruct.contrastResolutionParams.size(1));
    loop_ub = problemStruct.contrastResolutionParams.size(1);
    for (int i{0}; i < loop_ub; i++) {
      contrastResolutionParams[i] = problemStruct.contrastResolutionParams[i];
    }

    contrastResolutionTypes.set_size(1,
      problemStruct.contrastResolutionTypes.size(1));
    loop_ub = problemStruct.contrastResolutionTypes.size(1);
    for (int i{0}; i < loop_ub; i++) {
      contrastResolutionTypes[i] = problemStruct.contrastResolutionTypes[i];
    }

    backgroundParams.set_size(1, problemStruct.backgroundParams.size(1));
    loop_ub = problemStruct.backgroundParams.size(1);
    for (int i{0}; i < loop_ub; i++) {
      backgroundParams[i] = problemStruct.backgroundParams[i];
    }

    resolutionParams.set_size(1, problemStruct.resolutionParams.size(1));
    loop_ub = problemStruct.resolutionParams.size(1);
    for (int i{0}; i < loop_ub; i++) {
      resolutionParams[i] = problemStruct.resolutionParams[i];
    }

    b_nParams = problemStruct.params.size(1);
    params.set_size(1, problemStruct.params.size(1));
    loop_ub = problemStruct.params.size(1);
    for (int i{0}; i < loop_ub; i++) {
      params[i] = problemStruct.params[i];
    }

    contrastLayers.set_size(1, problemStruct.contrastLayers.size(1));
    loop_ub = problemStruct.contrastLayers.size(1);
    for (int i{0}; i < loop_ub; i++) {
      contrastLayers[i] = problemStruct.contrastLayers[i];
    }

    customFiles.set_size(1, problemStruct.customFiles.size(1));
    loop_ub = problemStruct.customFiles.size(1);
    for (int i{0}; i < loop_ub; i++) {
      customFiles[i] = problemStruct.customFiles[i];
    }

    contrastCustomFiles.set_size(1, problemStruct.contrastCustomFiles.size(1));
    loop_ub = problemStruct.contrastCustomFiles.size(1);
    for (int i{0}; i < loop_ub; i++) {
      contrastCustomFiles[i] = problemStruct.contrastCustomFiles[i];
    }

    domainContrastLayers.set_size(1, problemStruct.domainContrastLayers.size(1));
    loop_ub = problemStruct.domainContrastLayers.size(1);
    for (int i{0}; i < loop_ub; i++) {
      domainContrastLayers[i] = problemStruct.domainContrastLayers[i];
    }

    //  qzshifts are not included as a parameter in RAT, so we set up dummy
    //  values for the reflectivity calculation
    //  Find the actual values from the indices given in each contrast
    loop_ub = static_cast<int>(problemStruct.numberOfContrasts);
    qzshifts.set_size(loop_ub);
    for (int i{0}; i < loop_ub; i++) {
      qzshifts[i] = 0.0;
    }

    scalefactors.set_size(problemStruct.contrastScalefactors.size(1));
    loop_ub = problemStruct.contrastScalefactors.size(1);
    for (int i{0}; i < loop_ub; i++) {
      scalefactors[i] = problemStruct.scalefactors[static_cast<int>
        (problemStruct.contrastScalefactors[i]) - 1];
    }

    bulkIns.set_size(problemStruct.contrastBulkIns.size(1));
    loop_ub = problemStruct.contrastBulkIns.size(1);
    for (int i{0}; i < loop_ub; i++) {
      bulkIns[i] = problemStruct.bulkIns[static_cast<int>
        (problemStruct.contrastBulkIns[i]) - 1];
    }

    bulkOuts.set_size(problemStruct.contrastBulkOuts.size(1));
    loop_ub = problemStruct.contrastBulkOuts.size(1);
    for (int i{0}; i < loop_ub; i++) {
      bulkOuts[i] = problemStruct.bulkOuts[static_cast<int>
        (problemStruct.contrastBulkOuts[i]) - 1];
    }

    domainRatios.set_size(problemStruct.contrastDomainRatios.size(1));
    loop_ub = problemStruct.contrastDomainRatios.size(1);
    for (int i{0}; i < loop_ub; i++) {
      domainRatios[i] = problemStruct.domainRatios[static_cast<int>
        (problemStruct.contrastDomainRatios[i]) - 1];
    }

    numberOfContrasts = problemStruct.numberOfContrasts;
    nParams = b_nParams;
    useImaginary = problemStruct.useImaginary;
    return numberOfContrasts;
  }
}

// End of code generation (extractProblemParams.cpp)
