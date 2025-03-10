//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xzsyhetrd.h
//
// Code generation for function 'xzsyhetrd'
//
#ifndef XZSYHETRD_H
#define XZSYHETRD_H

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
        void xzsyhetrd(::coder::array<double, 2U> &A, ::coder::array<double, 1U>
                       &D, ::coder::array<double, 1U> &E, ::coder::array<double,
                       1U> &tau);
      }
    }
  }
}

#endif

// End of code generation (xzsyhetrd.h)
