//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzlanhs.h
//
// Code generation for function 'xzlanhs'
//
#ifndef XZLANHS_H
#define XZLANHS_H

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
        real_T xzlanhs(const ::coder::array<creal_T, 2U> &A, int32_T ilo,
                       int32_T ihi);
      }
    }
  }
}

#endif

// End of code generation (xzlanhs.h)
