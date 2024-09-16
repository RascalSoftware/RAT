//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sortLE.h
//
// Code generation for function 'sortLE'
//
#ifndef SORTLE_H
#define SORTLE_H

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
      boolean_T b_sortLE(const ::coder::array<real_T, 2U> &v, int32_T idx1,
                         int32_T idx2);
      boolean_T sortLE(const real_T v[4], int32_T idx1, int32_T idx2);
      boolean_T sortLE(const ::coder::array<real_T, 1U> &v, int32_T idx1,
                       int32_T idx2);
      boolean_T sortLE(const ::coder::array<real_T, 2U> &v, int32_T idx1,
                       int32_T idx2);
    }
  }
}

#endif

// End of code generation (sortLE.h)
