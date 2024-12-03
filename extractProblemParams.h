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
  struct struct0_T;
  struct cell_wrap_13;
  struct cell_wrap_7;
  struct cell_wrap_2;
  struct cell_wrap_1;
  struct cell_wrap_10;
}

// Function Declarations
namespace RAT
{
  void extractProblemParams(const struct0_T *problemStruct, real_T
    *numberOfContrasts, char_T geometry_data[], int32_T geometry_size[2], ::
    coder::array<cell_wrap_13, 2U> &contrastBackgroundParams, ::coder::array<
    real_T, 2U> &contrastQzshifts, ::coder::array<real_T, 2U>
    &contrastScalefactors, ::coder::array<real_T, 2U> &contrastBulkIns, ::coder::
    array<real_T, 2U> &contrastBulkOuts, ::coder::array<real_T, 2U>
    &contrastResolutionParams, ::coder::array<real_T, 2U> &contrastDomainRatios,
    ::coder::array<real_T, 2U> &backgroundParams, ::coder::array<real_T, 2U>
    &qzshifts, ::coder::array<real_T, 2U> &scalefactors, ::coder::array<real_T,
    2U> &bulkIns, ::coder::array<real_T, 2U> &bulkOuts, ::coder::array<real_T,
    2U> &resolutionParams, ::coder::array<real_T, 2U> &domainRatios, ::coder::
    array<real_T, 2U> &dataPresent, real_T *nParams, ::coder::array<real_T, 2U>
    &params, real_T *numberOfLayers, ::coder::array<real_T, 2U> &resample, ::
    coder::array<cell_wrap_7, 2U> &contrastBackgroundTypes, ::coder::array<
    cell_wrap_7, 2U> &contrastBackgroundActions, ::coder::array<real_T, 2U>
    &contrastCustomFiles, boolean_T *useImaginary, ::coder::array<cell_wrap_2,
    2U> &repeatLayers, ::coder::array<cell_wrap_1, 2U> &data, ::coder::array<
    cell_wrap_2, 2U> &dataLimits, ::coder::array<cell_wrap_2, 2U> &simLimits, ::
    coder::array<cell_wrap_10, 2U> &contrastLayers, ::coder::array<cell_wrap_10,
    2U> &layersDetails, ::coder::array<cell_wrap_7, 2U> &customFiles, ::coder::
    array<cell_wrap_10, 2U> &domainContrastLayers);
}

#endif

// End of code generation (extractProblemParams.h)
