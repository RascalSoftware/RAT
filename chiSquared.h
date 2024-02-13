//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// chiSquared.h
//
// Code generation for function 'chiSquared'
//
#ifndef CHISQUARED_H
#define CHISQUARED_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  real_T chiSquared(const ::coder::array<real_T, 2U> &thisData, const ::coder::
                    array<real_T, 2U> &thisFit, real_T P);
}

#endif

// End of code generation (chiSquared.h)
