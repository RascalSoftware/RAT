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
  struct cell_wrap_14;
  struct cell_wrap_3;
}

// Function Declarations
namespace RAT
{
  void extractProblemParams(const struct0_T *problemStruct, real_T
    *numberOfContrasts, char_T geometry_data[], int32_T geometry_size[2], ::
    coder::array<cell_wrap_14, 2U> &contrastBackgroundParams, ::coder::array<
    real_T, 2U> &contrastQzshifts, ::coder::array<real_T, 2U>
    &contrastScalefactors, ::coder::array<real_T, 2U> &contrastBulkIns, ::coder::
    array<real_T, 2U> &contrastBulkOuts, ::coder::array<real_T, 2U>
    &contrastResolutionParams, ::coder::array<real_T, 2U> &contrastDomainRatios,
    ::coder::array<real_T, 2U> &backgroundParams, ::coder::array<real_T, 2U>
    &qzshifts, ::coder::array<real_T, 2U> &scalefactors, ::coder::array<real_T,
    2U> &bulkIn, ::coder::array<real_T, 2U> &bulkOut, ::coder::array<real_T, 2U>
    &resolutionParams, ::coder::array<real_T, 2U> &domainRatio, ::coder::array<
    real_T, 2U> &dataPresent, real_T *nParams, ::coder::array<real_T, 2U>
    &params, real_T *numberOfLayers, ::coder::array<real_T, 2U> &resample, ::
    coder::array<cell_wrap_3, 2U> &contrastBackgroundTypes, ::coder::array<
    cell_wrap_3, 2U> &contrastBackgroundActions, ::coder::array<real_T, 2U>
    &contrastCustomFiles, boolean_T *useImaginary);
}

#endif

// End of code generation (extractProblemParams.h)
