//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sum.h
//
// Code generation for function 'sum'
//
#ifndef SUM_H
#define SUM_H

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
    void sum(const ::coder::array<real_T, 2U> &x, ::coder::array<real_T, 2U> &y);
    creal_T sum(const ::coder::array<creal_T, 2U> &x);
  }
}

#endif

// End of code generation (sum.h)
