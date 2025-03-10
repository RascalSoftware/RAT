//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xdotc.h
//
// Code generation for function 'xdotc'
//
#ifndef XDOTC_H
#define XDOTC_H

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
        double xdotc(int n, const ::coder::array<double, 1U> &x, int ix0, const ::
                     coder::array<double, 2U> &y, int iy0);
      }
    }
  }
}

#endif

// End of code generation (xdotc.h)
