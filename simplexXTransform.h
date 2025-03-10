//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void simplexXTransform(const ::coder::array<double, 1U> &x, const ::coder::
    array<double, 1U> &params_LB, const ::coder::array<double, 1U> &params_UB,
    const ::coder::array<double, 1U> &params_BoundClass, ::coder::array<double,
    1U> &xtrans);
}

#endif

// End of code generation (simplexXTransform.h)
