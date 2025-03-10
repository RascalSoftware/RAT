//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
        void xzlascl(double cfrom, double cto, int m, ::coder::array<double, 1U>
                     &A, int iA0);
        void xzlascl(double cfrom, double cto, int m, int n, ::coder::array<
                     double, 2U> &A, int lda);
      }
    }
  }
}

#endif

// End of code generation (xzlascl.h)
