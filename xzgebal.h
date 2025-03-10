//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xzgebal.h
//
// Code generation for function 'xzgebal'
//
#ifndef XZGEBAL_H
#define XZGEBAL_H

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
        int xzgebal(::coder::array<double, 2U> &A, ::coder::array<double, 1U>
                    &scale, int &ihi);
      }
    }
  }
}

#endif

// End of code generation (xzgebal.h)
