//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzggbak.h
//
// Code generation for function 'xzggbak'
//
#ifndef XZGGBAK_H
#define XZGGBAK_H

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
        void xzggbak(::coder::array<creal_T, 2U> &V, int ilo, int ihi, const ::
                     coder::array<int, 1U> &rscale);
      }
    }
  }
}

#endif

// End of code generation (xzggbak.h)
