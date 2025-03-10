//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xaxpy.h
//
// Code generation for function 'xaxpy'
//
#ifndef XAXPY_H
#define XAXPY_H

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
        void xaxpy(int n, double a, const ::coder::array<double, 2U> &x, int ix0,
                   ::coder::array<double, 2U> &y, int iy0);
        void xaxpy(int n, double a, const ::coder::array<double, 2U> &x, int ix0,
                   ::coder::array<double, 1U> &y, int iy0);
      }
    }
  }
}

#endif

// End of code generation (xaxpy.h)
