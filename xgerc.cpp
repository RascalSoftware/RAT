//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xgerc.cpp
//
// Code generation for function 'xgerc'
//

// Include files
#include "xgerc.h"
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
        void xgerc(int32_T m, int32_T n, real_T alpha1, const ::coder::array<
                   real_T, 1U> &x, int32_T iy0, ::coder::array<real_T, 2U> &A,
                   int32_T ia0, int32_T lda)
        {
          if (!(alpha1 == 0.0)) {
            int32_T jA;
            jA = ia0;
            for (int32_T j{0}; j < n; j++) {
              int32_T i;
              i = (iy0 + j) - 1;
              if (A[i] != 0.0) {
                real_T temp;
                temp = A[i] * alpha1;
                i = m + jA;
                for (int32_T ijA{jA}; ijA < i; ijA++) {
                  A[ijA - 1] = A[ijA - 1] + x[ijA - jA] * temp;
                }
              }

              jA += lda;
            }
          }
        }

        void xgerc(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const ::
                   coder::array<real_T, 1U> &y, ::coder::array<real_T, 2U> &A,
                   int32_T ia0, int32_T lda)
        {
          if (!(alpha1 == 0.0)) {
            int32_T jA;
            jA = ia0;
            for (int32_T j{0}; j < n; j++) {
              if (y[j] != 0.0) {
                real_T temp;
                int32_T i;
                temp = y[j] * alpha1;
                i = m + jA;
                for (int32_T ijA{jA}; ijA < i; ijA++) {
                  A[ijA - 1] = A[ijA - 1] + A[((ix0 + ijA) - jA) - 1] * temp;
                }
              }

              jA += lda;
            }
          }
        }
      }
    }
  }
}

// End of code generation (xgerc.cpp)
