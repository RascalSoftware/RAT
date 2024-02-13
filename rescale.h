//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// rescale.h
//
// Code generation for function 'rescale'
//
#ifndef RESCALE_H
#define RESCALE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    real_T anon(real_T x, real_T y);
    real_T b_anon(real_T x, real_T y);
    void rescale(::coder::array<real_T, 1U> &A, const ::coder::array<real_T, 1U>
                 &varargin_2, const ::coder::array<real_T, 1U> &varargin_4, ::
                 coder::array<real_T, 1U> &R);
  }
}

#endif

// End of code generation (rescale.h)
