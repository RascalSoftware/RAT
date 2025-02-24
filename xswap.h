//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xswap.h
//
// Code generation for function 'xswap'
//
#ifndef XSWAP_H
#define XSWAP_H

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
        void xswap(int n, ::coder::array<double, 2U> &x, int ix0, int iy0);
        void xswap(int n, ::coder::array<double, 2U> &x, int ix0, int incx, int
                   iy0, int incy);
      }
    }
  }
}

#endif

// End of code generation (xswap.h)
