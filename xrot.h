//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xrot.h
//
// Code generation for function 'xrot'
//
#ifndef XROT_H
#define XROT_H

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
      namespace blas
      {
        void xrot(int32_T n, ::coder::array<real_T, 2U> &x, int32_T ix0, int32_T
                  incx, int32_T iy0, int32_T incy, real_T c, real_T s);
        void xrot(int32_T n, ::coder::array<real_T, 2U> &x, int32_T ix0, int32_T
                  iy0, real_T c, real_T s);
      }
    }
  }
}

#endif

// End of code generation (xrot.h)
