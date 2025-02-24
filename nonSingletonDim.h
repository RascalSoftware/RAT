//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// nonSingletonDim.h
//
// Code generation for function 'nonSingletonDim'
//
#ifndef NONSINGLETONDIM_H
#define NONSINGLETONDIM_H

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
      int nonSingletonDim(const ::coder::array<double, 1U> &x);
      int nonSingletonDim(const ::coder::array<double, 2U> &x);
    }
  }
}

#endif

// End of code generation (nonSingletonDim.h)
