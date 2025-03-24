//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      boolean_T b_sortLE(const ::coder::array<double, 2U> &v, int idx1, int idx2);
      boolean_T sortLE(const double v[4], int idx1, int idx2);
      boolean_T sortLE(const ::coder::array<double, 2U> &v, int idx1, int idx2);
      boolean_T sortLE(const ::coder::array<double, 1U> &v, int idx1, int idx2);
    }
  }
}

#endif

// End of code generation (sortLE.h)
