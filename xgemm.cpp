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
        void xgemm(int m, int n, int k, double alpha1, const ::coder::array<
                   double, 2U> &A, int lda, const ::coder::array<double, 2U> &B,
                   int ldb, ::coder::array<double, 2U> &C, int ldc)
        {
          if ((m != 0) && (n != 0)) {
            int br;
            int cr;
            int i;
            int i1;
            int ic;
            int lastColC;
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
              int ar;
              ar = -1;
              i = cr + 1;
              i1 = cr + m;
              for (ic = i; ic <= i1; ic++) {
                double temp;
                temp = 0.0;
                for (int w{0}; w < k; w++) {
                  temp += A[(w + ar) + 1] * B[(w + br) + 1];
                }

                C[ic - 1] = C[ic - 1] + alpha1 * temp;
                ar += lda;
              }

              br += ldb;
            }
          }
        }

        void xgemm(int k, double alpha1, const ::coder::array<double, 1U> &A,
                   const ::coder::array<double, 1U> &B, double *C)
        {
          double temp;
          temp = 0.0;
          for (int w{0}; w < k; w++) {
            temp += A[w] * B[w];
          }

          *C = alpha1 * temp;
        }
      }
    }
  }
}

// End of code generation (xgemm.cpp)
