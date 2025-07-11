//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// applyBackgroundCorrection.h
//
// Code generation for function 'applyBackgroundCorrection'
//
#ifndef APPLYBACKGROUNDCORRECTION_H
#define APPLYBACKGROUNDCORRECTION_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void applyBackgroundCorrection(::coder::array<double, 2U> &reflectivity, ::
    coder::array<double, 2U> &simulation, ::coder::array<double, 2U>
    &shiftedData, const ::coder::array<double, 2U> &background, const char
    backgroundAction_data[], const int backgroundAction_size[2]);
}

#endif

// End of code generation (applyBackgroundCorrection.h)
