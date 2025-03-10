//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
        int ixamax(int n, const ::coder::array<double, 2U> &x, int ix0, int incx);
        int ixamax(int n, const ::coder::array<double, 2U> &x, int ix0);
        int ixamax(int n, const ::coder::array<double, 1U> &x);
        int ixamax(int n, const ::coder::array<double, 1U> &x, int ix0);
      }
    }
  }
}

#endif

// End of code generation (ixamax.h)
