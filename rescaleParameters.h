//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// rescaleParameters.h
//
// Code generation for function 'rescaleParameters'
//
#ifndef RESCALEPARAMETERS_H
#define RESCALEPARAMETERS_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void rescaleParameters(const ::coder::array<real_T, 2U> &prior, const ::coder::
    array<real_T, 2U> &params, ::coder::array<real_T, 1U> &scaled);
}

#endif

// End of code generation (rescaleParameters.h)
