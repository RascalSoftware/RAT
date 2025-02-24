//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sortrows.h
//
// Code generation for function 'sortrows'
//
#ifndef SORTROWS_H
#define SORTROWS_H

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
    void apply_row_permutation(::coder::array<double, 2U> &y, const ::coder::
      array<int, 1U> &idx);
  }
}

#endif

// End of code generation (sortrows.h)
