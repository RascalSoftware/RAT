//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// extractProblemParams.h
//
// Code generation for function 'extractProblemParams'
//
#ifndef EXTRACTPROBLEMPARAMS_H
#define EXTRACTPROBLEMPARAMS_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct b_ProblemDefinition;
  struct cell_wrap_47;
  struct cell_wrap_9;
  struct cell_wrap_10;
  struct cell_wrap_2;
  struct cell_wrap_1;
}

// Function Declarations
namespace RAT
{
  void extractProblemParams(const b_ProblemDefinition *problemStruct, double
    *numberOfContrasts, char geometry_data[], int geometry_size[2], ::coder::
    array<cell_wrap_47, 2U> &contrastBackgroundParams, ::coder::array<double, 2U>
    &contrastQzshifts, ::coder::array<double, 2U> &contrastScalefactors, ::coder::
    array<double, 2U> &contrastBulkIns, ::coder::array<double, 2U>
    &contrastBulkOuts, ::coder::array<cell_wrap_9, 2U> &contrastResolutionParams,
    ::coder::array<double, 2U> &contrastDomainRatios, ::coder::array<double, 2U>
    &backgroundParams, ::coder::array<double, 2U> &qzshifts, ::coder::array<
    double, 2U> &scalefactors, ::coder::array<double, 2U> &bulkIns, ::coder::
    array<double, 2U> &bulkOuts, ::coder::array<double, 2U> &resolutionParams, ::
    coder::array<double, 2U> &domainRatios, ::coder::array<double, 2U>
    &dataPresent, double *nParams, ::coder::array<double, 2U> &params, double
    *numberOfLayers, ::coder::array<double, 2U> &resample, ::coder::array<
    cell_wrap_10, 2U> &contrastBackgroundTypes, ::coder::array<cell_wrap_10, 2U>
    &contrastBackgroundActions, ::coder::array<cell_wrap_10, 2U>
    &contrastResolutionTypes, ::coder::array<double, 2U> &contrastCustomFiles,
    boolean_T *useImaginary, ::coder::array<cell_wrap_2, 2U> &repeatLayers, ::
    coder::array<cell_wrap_1, 2U> &data, ::coder::array<cell_wrap_2, 2U>
    &dataLimits, ::coder::array<cell_wrap_2, 2U> &simLimits, ::coder::array<
    cell_wrap_9, 2U> &contrastLayers, ::coder::array<cell_wrap_9, 2U>
    &layersDetails, ::coder::array<cell_wrap_10, 2U> &customFiles, ::coder::
    array<cell_wrap_9, 2U> &domainContrastLayers);
}

#endif

// End of code generation (extractProblemParams.h)
