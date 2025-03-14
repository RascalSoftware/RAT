//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void constructResolution(const char resolutionType_data[], const int
    resolutionType_size[2], const double resolutionParamIndex_data[], const int
    resolutionParamIndex_size[2], const ::coder::array<double, 2U> &shiftedData,
    const ::coder::array<double, 2U> &resolutionParamValues, const ::coder::
    array<double, 1U> &simulationXData, const double dataIndices[2], ::coder::
    array<double, 2U> &resolution);
}

#endif

// End of code generation (constructResolution.h)
