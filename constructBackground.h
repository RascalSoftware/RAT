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
    &backgroundType, const double backgroundParamIndices_data[], const int
    backgroundParamIndices_size[2], const ::coder::array<double, 2U>
    &shiftedData, const ::coder::array<cell_wrap_10, 2U> &customFiles, const ::
    coder::array<double, 2U> &backgroundParamArray, const ::coder::array<double,
    1U> &simulationXData, const double dataIndices[2], ::coder::array<double, 2U>
    &background);
  void constructBackground(const char backgroundType_data[], const int
    backgroundType_size[2], const double backgroundParamIndices_data[], const
    int backgroundParamIndices_size[2], const ::coder::array<double, 2U>
    &shiftedData, const ::coder::array<cell_wrap_10, 2U> &customFiles, const ::
    coder::array<double, 2U> &backgroundParamArray, const ::coder::array<double,
    1U> &simulationXData, const double dataIndices[2], ::coder::array<double, 2U>
    &background);
}

#endif

// End of code generation (constructBackground.h)
