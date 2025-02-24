//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// abs.h
//
// Code generation for function 'abs'
//
#ifndef ABS_H
#define ABS_H

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
    void b_abs(const ::coder::array<double, 2U> &x, ::coder::array<double, 2U>
               &y);
    void b_abs(const ::coder::array<double, 1U> &x, ::coder::array<double, 1U>
               &y);
    void c_abs(const ::coder::array<double, 2U> &x, ::coder::array<double, 2U>
               &y);
  }
}

#endif

// End of code generation (abs.h)
