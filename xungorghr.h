//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xungorghr.h
//
// Code generation for function 'xungorghr'
//
#ifndef XUNGORGHR_H
#define XUNGORGHR_H

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
        void xungorghr(int32_T n, int32_T ihi, ::coder::array<real_T, 2U> &A,
                       int32_T lda, const ::coder::array<real_T, 1U> &tau);
      }
    }
  }
}

#endif

// End of code generation (xungorghr.h)
