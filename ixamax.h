//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// ixamax.h
//
// Code generation for function 'ixamax'
//
#ifndef IXAMAX_H
#define IXAMAX_H

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
      namespace blas
      {
        int32_T ixamax(int32_T n, const ::coder::array<real_T, 1U> &x, int32_T
                       ix0);
        int32_T ixamax(int32_T n, const ::coder::array<real_T, 2U> &x, int32_T
                       ix0);
      }
    }
  }
}

#endif

// End of code generation (ixamax.h)
