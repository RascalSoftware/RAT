//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzgghrd.h
//
// Code generation for function 'xzgghrd'
//
#ifndef XZGGHRD_H
#define XZGGHRD_H

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
        void xzgghrd(int ilo, int ihi, ::coder::array<creal_T, 2U> &A, ::coder::
                     array<creal_T, 2U> &Z);
      }
    }
  }
}

#endif

// End of code generation (xzgghrd.h)
