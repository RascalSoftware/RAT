//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// power.h
//
// Code generation for function 'power'
//
#ifndef POWER_H
#define POWER_H

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
    void b_power(const ::coder::array<real_T, 1U> &b, ::coder::array<real_T, 1U>
                 &y);
    void b_power(const ::coder::array<real_T, 2U> &a, ::coder::array<real_T, 2U>
                 &y);
    void power(const ::coder::array<creal_T, 2U> &a, ::coder::array<creal_T, 2U>
               &y);
    void power(const ::coder::array<real_T, 2U> &a, ::coder::array<real_T, 2U>
               &y);
    void power(const ::coder::array<real_T, 1U> &a, ::coder::array<real_T, 1U>
               &y);
  }
}

#endif

// End of code generation (power.h)
