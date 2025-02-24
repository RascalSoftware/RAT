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
      void b_mergesort(int idx[4], const double x[4]);
      void b_mergesort(::coder::array<int, 2U> &idx, const ::coder::array<double,
                       2U> &x, int n);
      void b_mergesort(::coder::array<int, 1U> &idx, const ::coder::array<double,
                       1U> &x, int n);
      void b_mergesort(::coder::array<int, 1U> &idx, const ::coder::array<double,
                       2U> &x, int n);
    }
  }
}

#endif

// End of code generation (mergesort.h)
