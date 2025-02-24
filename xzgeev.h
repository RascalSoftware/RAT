//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzgeev.h
//
// Code generation for function 'xzgeev'
//
#ifndef XZGEEV_H
#define XZGEEV_H

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
        void xzgeev(const ::coder::array<double, 2U> &A, int *info, ::coder::
                    array<creal_T, 1U> &alpha1, ::coder::array<creal_T, 1U>
                    &beta1, ::coder::array<creal_T, 2U> &V);
      }
    }
  }
}

#endif

// End of code generation (xzgeev.h)
