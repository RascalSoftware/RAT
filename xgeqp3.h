//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xgeqp3.h
//
// Code generation for function 'xgeqp3'
//
#ifndef XGEQP3_H
#define XGEQP3_H

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
        void xgeqp3(::coder::array<double, 2U> &A, ::coder::array<double, 1U>
                    &tau, ::coder::array<int, 2U> &jpvt);
      }
    }
  }
}

#endif

// End of code generation (xgeqp3.h)
