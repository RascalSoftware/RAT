//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xgerc.h
//
// Code generation for function 'xgerc'
//
#ifndef XGERC_H
#define XGERC_H

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
        void xgerc(int m, int n, double alpha1, const ::coder::array<double, 1U>
                   &x, int iy0, ::coder::array<double, 2U> &A, int ia0, int lda);
        void xgerc(int m, int n, double alpha1, int ix0, const ::coder::array<
                   double, 1U> &y, ::coder::array<double, 2U> &A, int ia0, int
                   lda);
      }
    }
  }
}

#endif

// End of code generation (xgerc.h)
