//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sort.h
//
// Code generation for function 'sort'
//
#ifndef SORT_H
#define SORT_H

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
      void b_sort(::coder::array<double, 2U> &x, ::coder::array<int, 2U> &idx);
      void sort(::coder::array<double, 2U> &x, ::coder::array<int, 2U> &idx);
      void sort(::coder::array<double, 1U> &x, ::coder::array<int, 1U> &idx);
    }
  }
}

#endif

// End of code generation (sort.h)
