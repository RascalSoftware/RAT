//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    double b_norm(const ::coder::array<double, 2U> &x);
    double b_norm(const ::coder::array<double, 1U> &x);
    double c_norm(const ::coder::array<double, 2U> &x);
  }
}

#endif

// End of code generation (norm.h)
