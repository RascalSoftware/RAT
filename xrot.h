//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
        void xrot(int n, ::coder::array<double, 2U> &x, int ix0, int incx, int
                  iy0, int incy, double c, double s);
        void xrot(int n, ::coder::array<double, 2U> &x, int ix0, int iy0, double
                  c, double s);
      }
    }
  }
}

#endif

// End of code generation (xrot.h)
