//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    void sum(const ::coder::array<double, 2U> &x, ::coder::array<double, 2U> &y);
    creal_T sum(const ::coder::array<creal_T, 2U> &x);
    double sum(const ::coder::array<double, 1U> &x);
    double sum(const ::coder::array<double, 2U> &x);
  }
}

#endif

// End of code generation (sum.h)
