//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// mean.h
//
// Code generation for function 'mean'
//
#ifndef MEAN_H
#define MEAN_H

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
    void mean(const ::coder::array<real_T, 3U> &x, ::coder::array<real_T, 3U> &y);
    void mean(const ::coder::array<real_T, 2U> &x, ::coder::array<real_T, 2U> &y);
    real_T mean(const real_T x_data[], int32_T x_size);
  }
}

#endif

// End of code generation (mean.h)
