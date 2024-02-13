//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xgeru.cpp
//
// Code generation for function 'xgeru'
//

// Include files
#include "xgeru.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace blas
      {
        void xgeru(int32_T m, int32_T n, int32_T ix0, int32_T iy0, int32_T incy,
                   ::coder::array<real_T, 2U> &A, int32_T ia0, int32_T lda)
        {
          int32_T jA;
          jA = ia0;
          for (int32_T j{0}; j < n; j++) {
            real_T yjy;
            int32_T yjy_tmp;
            yjy_tmp = (iy0 + j * incy) - 1;
            yjy = A[yjy_tmp];
            if (A[yjy_tmp] != 0.0) {
              yjy_tmp = m + jA;
              for (int32_T ijA{jA}; ijA < yjy_tmp; ijA++) {
                A[ijA - 1] = A[ijA - 1] + A[((ix0 + ijA) - jA) - 1] * -yjy;
              }
            }

            jA += lda;
          }
        }
      }
    }
  }
}

// End of code generation (xgeru.cpp)
