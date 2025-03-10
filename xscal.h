//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xscal.h
//
// Code generation for function 'xscal'
//
#ifndef XSCAL_H
#define XSCAL_H

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
        void xscal(int n, double a, ::coder::array<double, 2U> &x, int ix0, int
                   incx);
      }
    }
  }
}

#endif

// End of code generation (xscal.h)
