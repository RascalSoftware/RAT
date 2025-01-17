//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// constructResolution.h
//
// Code generation for function 'constructResolution'
//
#ifndef CONSTRUCTRESOLUTION_H
#define CONSTRUCTRESOLUTION_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void constructResolution(const char_T resolutionType_data[], const int32_T
    resolutionType_size[2], const real_T resolutionParamIndex_data[], const
    int32_T resolutionParamIndex_size[2], const ::coder::array<real_T, 2U>
    &shiftedData, const ::coder::array<real_T, 2U> &resolutionParamArray, const ::
    coder::array<real_T, 1U> &simulationXData, const real_T dataIndices[2], ::
    coder::array<real_T, 2U> &resolution);
}

#endif

// End of code generation (constructResolution.h)
