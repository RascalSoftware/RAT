//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xzsteqr.h
//
// Code generation for function 'xzsteqr'
//
#ifndef XZSTEQR_H
#define XZSTEQR_H

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
        int xzsteqr(::coder::array<double, 1U> &d, ::coder::array<double, 1U> &e,
                    ::coder::array<double, 2U> &z);
      }
    }
  }
}

#endif

// End of code generation (xzsteqr.h)
