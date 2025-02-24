//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// norm.h
//
// Code generation for function 'norm'
//
#ifndef NORM_H
#define NORM_H

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
    double b_genpnorm(const ::coder::array<double, 2U> &x);
    double b_norm(const ::coder::array<double, 2U> &x);
    double b_norm(const ::coder::array<double, 1U> &x);
  }
}

#endif

// End of code generation (norm.h)
