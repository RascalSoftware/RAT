//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
      namespace blas
      {
        void b_xtrsm(int32_T n, const ::coder::array<real_T, 2U> &A, int32_T lda,
                     ::coder::array<real_T, 2U> &B);
        void xtrsm(int32_T n, const ::coder::array<real_T, 2U> &A, int32_T lda, ::
                   coder::array<real_T, 2U> &B);
      }
    }
  }
}

#endif

// End of code generation (xtrsm.h)
