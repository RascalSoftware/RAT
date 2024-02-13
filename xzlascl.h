//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzlascl.h
//
// Code generation for function 'xzlascl'
//
#ifndef XZLASCL_H
#define XZLASCL_H

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
        void xzlascl(real_T cfrom, real_T cto, ::coder::array<creal_T, 1U> &A);
        void xzlascl(real_T cfrom, real_T cto, ::coder::array<creal_T, 2U> &A);
      }
    }
  }
}

#endif

// End of code generation (xzlascl.h)
