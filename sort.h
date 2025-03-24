//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      void sort(::coder::array<double, 2U> &x, int idx_data[], int idx_size[2]);
      void sort(::coder::array<double, 1U> &x, ::coder::array<int, 1U> &idx);
      void sort(::coder::array<double, 2U> &x, ::coder::array<int, 2U> &idx);
    }
  }
}

#endif

// End of code generation (sort.h)
