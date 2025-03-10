//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xzgehrd.h
//
// Code generation for function 'xzgehrd'
//
#ifndef XZGEHRD_H
#define XZGEHRD_H

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
        void xzgehrd(::coder::array<double, 2U> &a, int ilo, int ihi, ::coder::
                     array<double, 1U> &tau);
        void xzgehrd(::coder::array<double, 2U> &a, int ihi, ::coder::array<
                     double, 1U> &tau);
      }
    }
  }
}

#endif

// End of code generation (xzgehrd.h)
