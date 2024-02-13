//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
        void xgerc(int32_T m, int32_T n, real_T alpha1, const ::coder::array<
                   real_T, 1U> &x, int32_T iy0, ::coder::array<real_T, 2U> &A,
                   int32_T ia0, int32_T lda);
        void xgerc(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const ::
                   coder::array<real_T, 1U> &y, ::coder::array<real_T, 2U> &A,
                   int32_T ia0, int32_T lda);
      }
    }
  }
}

#endif

// End of code generation (xgerc.h)
