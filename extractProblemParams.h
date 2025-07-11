//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// extractProblemParams.h
//
// Code generation for function 'extractProblemParams'
//
#ifndef EXTRACTPROBLEMPARAMS_H
#define EXTRACTPROBLEMPARAMS_H

// Include files
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  double extractProblemParams(const ProblemDefinition &problemStruct, char
    geometry_data[], int geometry_size[2], ::coder::array<cell_wrap_44, 2U>
    &contrastBackgroundParams, ::coder::array<cell_wrap_9, 2U>
    &contrastResolutionParams, ::coder::array<double, 2U> &contrastDomainRatios,
    ::coder::array<double, 2U> &backgroundParams, ::coder::array<double, 2U>
    &resolutionParams, ::coder::array<double, 1U> &qzshifts, ::coder::array<
    double, 1U> &scalefactors, ::coder::array<double, 1U> &bulkIns, ::coder::
    array<double, 1U> &bulkOuts, ::coder::array<double, 2U> &domainRatios, ::
    coder::array<double, 2U> &dataPresent, ::coder::array<double, 2U> &params, ::
    coder::array<double, 2U> &resample, ::coder::array<cell_wrap_10, 2U>
    &contrastBackgroundTypes, ::coder::array<cell_wrap_10, 2U>
    &contrastBackgroundActions, ::coder::array<cell_wrap_10, 2U>
    &contrastResolutionTypes, ::coder::array<double, 2U> &contrastCustomFiles, ::
    coder::array<double, 2U> &repeatLayers, ::coder::array<cell_wrap_1, 2U>
    &data, ::coder::array<cell_wrap_2, 2U> &dataLimits, ::coder::array<
    cell_wrap_2, 2U> &simulationLimits, ::coder::array<cell_wrap_9, 2U>
    &contrastLayers, ::coder::array<cell_wrap_9, 2U> &layersDetails, ::coder::
    array<cell_wrap_10, 2U> &customFiles, ::coder::array<cell_wrap_9, 2U>
    &domainContrastLayers, double &nParams, boolean_T &useImaginary);
}

#endif

// End of code generation (extractProblemParams.h)
