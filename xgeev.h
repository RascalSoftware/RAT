//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xgeev.h
//
// Code generation for function 'xgeev'
//
#ifndef XGEEV_H
#define XGEEV_H

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
        int xgeev(const ::coder::array<double, 2U> &A, ::coder::array<creal_T,
                  1U> &W, ::coder::array<creal_T, 2U> &VR);
      }
    }
  }
}

#endif

// End of code generation (xgeev.h)
