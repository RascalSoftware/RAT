//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xtrsm.h
//
// Code generation for function 'xtrsm'
//
#ifndef XTRSM_H
#define XTRSM_H

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
        void b_xtrsm(int m, int n, const ::coder::array<double, 2U> &A, int lda,
                     ::coder::array<double, 2U> &B, int ldb);
        void xtrsm(int m, int n, const ::coder::array<double, 2U> &A, int lda, ::
                   coder::array<double, 2U> &B, int ldb);
      }
    }
  }
}

#endif

// End of code generation (xtrsm.h)
