//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// constructBackground.h
//
// Code generation for function 'constructBackground'
//
#ifndef CONSTRUCTBACKGROUND_H
#define CONSTRUCTBACKGROUND_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct cell_wrap_10;
}

// Function Declarations
namespace RAT
{
  void constructBackground(const ::coder::array<cell_wrap_10, 2U>
    &backgroundType, const real_T backgroundParamIndices_data[], const int32_T
    backgroundParamIndices_size[2], const ::coder::array<real_T, 2U>
    &shiftedData, const ::coder::array<cell_wrap_10, 2U> &customFiles, const ::
    coder::array<real_T, 2U> &backgroundParamArray, const ::coder::array<real_T,
    1U> &simulationXData, const real_T dataIndices[2], ::coder::array<real_T, 2U>
    &background);
  void constructBackground(const char_T backgroundType_data[], const int32_T
    backgroundType_size[2], const real_T backgroundParamIndices_data[], const
    int32_T backgroundParamIndices_size[2], const ::coder::array<real_T, 2U>
    &shiftedData, const ::coder::array<cell_wrap_10, 2U> &customFiles, const ::
    coder::array<real_T, 2U> &backgroundParamArray, const ::coder::array<real_T,
    1U> &simulationXData, const real_T dataIndices[2], ::coder::array<real_T, 2U>
    &background);
}

#endif

// End of code generation (constructBackground.h)
