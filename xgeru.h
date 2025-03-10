//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xgeru.h
//
// Code generation for function 'xgeru'
//
#ifndef XGERU_H
#define XGERU_H

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
      namespace blas
      {
        void xgeru(int m, int n, int ix0, int iy0, int incy, ::coder::array<
                   double, 2U> &A, int ia0, int lda);
      }
    }
  }
}

#endif

// End of code generation (xgeru.h)
