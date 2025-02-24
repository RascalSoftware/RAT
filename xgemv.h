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
        void b_xgemv(int m, int n, const ::coder::array<double, 2U> &A, int ia0,
                     int lda, const ::coder::array<double, 2U> &x, int ix0, ::
                     coder::array<double, 1U> &y);
        void c_xgemv(int m, int n, const ::coder::array<double, 2U> &A, int ia0,
                     int lda, const ::coder::array<double, 2U> &x, int ix0, ::
                     coder::array<double, 1U> &y);
        void xgemv(int m, int n, const ::coder::array<double, 2U> &A, int ia0,
                   int lda, const ::coder::array<double, 2U> &x, int ix0, ::
                   coder::array<double, 1U> &y);
      }
    }
  }
}

#endif

// End of code generation (xgemv.h)
