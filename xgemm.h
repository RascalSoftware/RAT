//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xgemm.h
//
// Code generation for function 'xgemm'
//
#ifndef XGEMM_H
#define XGEMM_H

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
        void xgemm(int32_T m, int32_T n, int32_T k, real_T alpha1, const ::coder::
                   array<real_T, 2U> &A, int32_T lda, const ::coder::array<
                   real_T, 2U> &B, int32_T ldb, ::coder::array<real_T, 2U> &C,
                   int32_T ldc);
        void xgemm(int32_T k, real_T alpha1, const ::coder::array<real_T, 1U> &A,
                   const ::coder::array<real_T, 1U> &B, real_T *C);
      }
    }
  }
}

#endif

// End of code generation (xgemm.h)
