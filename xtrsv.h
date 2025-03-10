//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xtrsv.h
//
// Code generation for function 'xtrsv'
//
#ifndef XTRSV_H
#define XTRSV_H

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
        void b_xtrsv(int n, const ::coder::array<double, 2U> &A, int lda, ::
                     coder::array<double, 1U> &x);
        void c_xtrsv(int n, const ::coder::array<double, 2U> &A, int lda, ::
                     coder::array<double, 1U> &x);
        void d_xtrsv(int n, const ::coder::array<double, 2U> &A, int lda, ::
                     coder::array<double, 1U> &x);
        void xtrsv(int n, const ::coder::array<double, 2U> &A, int lda, ::coder::
                   array<double, 1U> &x);
      }
    }
  }
}

#endif

// End of code generation (xtrsv.h)
