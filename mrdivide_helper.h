//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// mrdivide_helper.h
//
// Code generation for function 'mrdivide_helper'
//
#ifndef MRDIVIDE_HELPER_H
#define MRDIVIDE_HELPER_H

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
    namespace internal
    {
      void mrdiv(const ::coder::array<double, 2U> &A, const ::coder::array<
                 double, 2U> &B, ::coder::array<double, 2U> &Y);
      void mrdiv(const ::coder::array<double, 2U> &A, const ::coder::array<
                 double, 2U> &B, ::coder::array<double, 1U> &Y);
      void mrdiv(const double A_data[], int A_size, const double B_data[], int
                 B_size, double Y_data[], int Y_size[2]);
    }
  }
}

#endif

// End of code generation (mrdivide_helper.h)
