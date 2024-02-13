//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xgemm.cpp
//
// Code generation for function 'xgemm'
//

// Include files
#include "xgemm.h"
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
        void xgemm(int32_T m, int32_T n, int32_T k, real_T alpha1, const ::coder::
                   array<real_T, 2U> &A, int32_T lda, const ::coder::array<
                   real_T, 2U> &B, int32_T ldb, ::coder::array<real_T, 2U> &C,
                   int32_T ldc)
        {
          if ((m != 0) && (n != 0)) {
            int32_T br;
            int32_T cr;
            int32_T i;
            int32_T i1;
            int32_T ic;
            int32_T lastColC;
            lastColC = ldc * (n - 1);
            for (cr = 0; ldc < 0 ? cr >= lastColC : cr <= lastColC; cr += ldc) {
              i = cr + 1;
              i1 = cr + m;
              for (ic = i; ic <= i1; ic++) {
                C[ic - 1] = 0.0;
              }
            }

            br = -1;
            for (cr = 0; ldc < 0 ? cr >= lastColC : cr <= lastColC; cr += ldc) {
              int32_T ar;
              ar = -1;
              i = cr + 1;
              i1 = cr + m;
              for (ic = i; ic <= i1; ic++) {
                real_T temp;
                temp = 0.0;
                for (int32_T w{0}; w < k; w++) {
                  temp += A[(w + ar) + 1] * B[(w + br) + 1];
                }

                C[ic - 1] = C[ic - 1] + alpha1 * temp;
                ar += lda;
              }

              br += ldb;
            }
          }
        }

        void xgemm(int32_T k, real_T alpha1, const ::coder::array<real_T, 1U> &A,
                   const ::coder::array<real_T, 1U> &B, real_T *C)
        {
          real_T temp;
          temp = 0.0;
          for (int32_T w{0}; w < k; w++) {
            temp += A[w] * B[w];
          }

          *C = alpha1 * temp;
        }
      }
    }
  }
}

// End of code generation (xgemm.cpp)
