//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// constructBackground.h
//
// Code generation for function 'constructBackground'
//
#ifndef CONSTRUCTBACKGROUND_H
#define CONSTRUCTBACKGROUND_H

// Include files
#include "RATMain_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void constructBackground(const char backgroundType_data[], const int
    backgroundType_size[2], const double backgroundParamIndices_data[], const
    int backgroundParamIndices_size[2], const ::coder::array<double, 2U>
    &shiftedData, const ::coder::array<cell_wrap_10, 2U> &customFiles, const ::
    coder::array<double, 2U> &backgroundParamValues, const ::coder::array<double,
    1U> &simulationXData, const double dataIndices[2], ::coder::array<double, 2U>
    &background);
}

#endif

// End of code generation (constructBackground.h)
