//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xsyheev.h
//
// Code generation for function 'xsyheev'
//
#ifndef XSYHEEV_H
#define XSYHEEV_H

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
      namespace lapack
      {
        int xsyheev(::coder::array<double, 2U> &A, ::coder::array<double, 1U> &W);
      }
    }
  }
}

#endif

// End of code generation (xsyheev.h)
