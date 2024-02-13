//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// mergesort.h
//
// Code generation for function 'mergesort'
//
#ifndef MERGESORT_H
#define MERGESORT_H

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
      void b_mergesort(int32_T idx[4], const real_T x[4]);
      void b_mergesort(::coder::array<int32_T, 2U> &idx, const ::coder::array<
                       real_T, 2U> &x, int32_T n);
      void b_mergesort(::coder::array<int32_T, 1U> &idx, const ::coder::array<
                       real_T, 1U> &x, int32_T n);
      void b_mergesort(::coder::array<int32_T, 1U> &idx, const ::coder::array<
                       real_T, 2U> &x, const int32_T dir_data[], int32_T n);
    }
  }
}

#endif

// End of code generation (mergesort.h)
