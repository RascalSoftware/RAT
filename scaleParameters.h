//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// scaleParameters.h
//
// Code generation for function 'scaleParameters'
//
#ifndef SCALEPARAMETERS_H
#define SCALEPARAMETERS_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void scaleParameters(const ::coder::array<double, 2U> &prior, const ::coder::
                       array<double, 2U> &params, ::coder::array<double, 1U>
                       &scaled);
}

#endif

// End of code generation (scaleParameters.h)
