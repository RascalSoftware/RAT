//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
#include "omp.h"
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
        void xunormqr(const ::coder::array<real_T, 2U> &Q, ::coder::array<real_T,
                      1U> &C, const ::coder::array<real_T, 1U> &tau);
        void xunormqr(const ::coder::array<real_T, 1U> &Q, ::coder::array<real_T,
                      2U> &C, const real_T tau_data[]);
      }
    }
  }
}

#endif

// End of code generation (xunormqr.h)
