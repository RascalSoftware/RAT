//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xzunghr.h
//
// Code generation for function 'xzunghr'
//
#ifndef XZUNGHR_H
#define XZUNGHR_H

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
      namespace reflapack
      {
        void xzunghr(int n, int ilo, int ihi, ::coder::array<double, 2U> &A, int
                     lda, const ::coder::array<double, 1U> &tau);
        void xzunghr(int n, int ihi, ::coder::array<double, 2U> &A, int lda,
                     const ::coder::array<double, 1U> &tau);
      }
    }
  }
}

#endif

// End of code generation (xzunghr.h)
