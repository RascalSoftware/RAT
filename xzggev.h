//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzggev.h
//
// Code generation for function 'xzggev'
//
#ifndef XZGGEV_H
#define XZGGEV_H

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
        void xzggev(::coder::array<creal_T, 2U> &A, int32_T *info, ::coder::
                    array<creal_T, 1U> &alpha1, ::coder::array<creal_T, 1U>
                    &beta1, ::coder::array<creal_T, 2U> &V);
      }
    }
  }
}

#endif

// End of code generation (xzggev.h)
