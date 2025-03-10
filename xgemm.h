//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
        void xgemm(int m, int n, int k, double alpha1, const ::coder::array<
                   double, 2U> &A, int lda, const ::coder::array<double, 2U> &B,
                   int ldb, ::coder::array<double, 2U> &C, int ldc);
        double xgemm(int k, double alpha1, const ::coder::array<double, 1U> &A,
                     const ::coder::array<double, 1U> &B);
      }
    }
  }
}

#endif

// End of code generation (xgemm.h)
