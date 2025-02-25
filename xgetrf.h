//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xgetrf.h
//
// Code generation for function 'xgetrf'
//
#ifndef XGETRF_H
#define XGETRF_H

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
      namespace lapack
      {
        void xgetrf(int m, int n, ::coder::array<double, 2U> &A, int lda, ::
                    coder::array<int, 2U> &ipiv);
        void xgetrf(int m, int n, ::coder::array<double, 2U> &A, int lda, ::
                    coder::array<int, 2U> &ipiv, int *info);
      }
    }
  }
}

#endif

// End of code generation (xgetrf.h)
