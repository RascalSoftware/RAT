//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void applyBackgroundCorrection(::coder::array<real_T, 2U> &reflect, ::coder::
    array<real_T, 2U> &simul, ::coder::array<real_T, 2U> &shiftedData, real_T
    backgroundParams, real_T contrastBackgroundsType);
}

#endif

// End of code generation (applyBackgroundCorrection.h)
