//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
        void xswap(int n, ::coder::array<double, 2U> &x, int ix0, int incx, int
                   iy0, int incy);
        void xswap(int n, ::coder::array<double, 2U> &x, int ix0, int iy0);
        void xswap(::coder::array<double, 2U> &x, int ix0);
      }
    }
  }
}

#endif

// End of code generation (xswap.h)
