//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xgemv.h
//
// Code generation for function 'xgemv'
//
#ifndef XGEMV_H
#define XGEMV_H

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
        void b_xgemv(int32_T m, int32_T n, const ::coder::array<real_T, 2U> &A,
                     int32_T ia0, int32_T lda, const ::coder::array<real_T, 2U>
                     &x, int32_T ix0, ::coder::array<real_T, 1U> &y);
        void c_xgemv(int32_T m, int32_T n, const ::coder::array<real_T, 2U> &A,
                     int32_T ia0, int32_T lda, const ::coder::array<real_T, 2U>
                     &x, int32_T ix0, ::coder::array<real_T, 1U> &y);
        void xgemv(int32_T m, int32_T n, const ::coder::array<real_T, 2U> &A,
                   int32_T ia0, int32_T lda, const ::coder::array<real_T, 2U> &x,
                   int32_T ix0, ::coder::array<real_T, 1U> &y);
      }
    }
  }
}

#endif

// End of code generation (xgemv.h)
