//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzggbal.h
//
// Code generation for function 'xzggbal'
//
#ifndef XZGGBAL_H
#define XZGGBAL_H

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
        void xzggbal(::coder::array<creal_T, 2U> &A, int32_T *ilo, int32_T *ihi,
                     ::coder::array<int32_T, 1U> &rscale);
      }
    }
  }
}

#endif

// End of code generation (xzggbal.h)
