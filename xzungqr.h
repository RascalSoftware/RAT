//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzungqr.h
//
// Code generation for function 'xzungqr'
//
#ifndef XZUNGQR_H
#define XZUNGQR_H

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
      namespace reflapack
      {
        void xzungqr(int m, int n, int k, ::coder::array<double, 2U> &A, int ia0,
                     int lda, const ::coder::array<double, 1U> &tau);
      }
    }
  }
}

#endif

// End of code generation (xzungqr.h)
