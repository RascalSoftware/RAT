//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// simplexXTransform.h
//
// Code generation for function 'simplexXTransform'
//
#ifndef SIMPLEXXTRANSFORM_H
#define SIMPLEXXTRANSFORM_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void simplexXTransform(const ::coder::array<real_T, 1U> &x, const ::coder::
    array<real_T, 1U> &params_LB, const ::coder::array<real_T, 1U> &params_UB,
    const ::coder::array<real_T, 1U> &params_BoundClass, ::coder::array<real_T,
    1U> &xtrans);
}

#endif

// End of code generation (simplexXTransform.h)
