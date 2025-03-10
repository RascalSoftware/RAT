//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xunormqr.h
//
// Code generation for function 'xunormqr'
//
#ifndef XUNORMQR_H
#define XUNORMQR_H

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
        void xunormqr(const ::coder::array<double, 2U> &Q, ::coder::array<double,
                      2U> &C, const ::coder::array<double, 1U> &tau);
        void xunormqr(const ::coder::array<double, 1U> &Q, ::coder::array<double,
                      2U> &C, const double tau_data[]);
      }
    }
  }
}

#endif

// End of code generation (xunormqr.h)
