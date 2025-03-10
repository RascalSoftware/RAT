//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xtrsm.cpp
//
// Code generation for function 'xtrsm'
//

// Include files
#include "xtrsm.h"
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
        void b_xtrsm(int m, int n, const ::coder::array<double, 2U> &A, int lda,
                     ::coder::array<double, 2U> &B, int ldb)
        {
          if ((n != 0) && ((B.size(0) != 0) && (B.size(1) != 0))) {
            for (int j{n}; j >= 1; j--) {
              int i;
              int jAcol;
              int jBcol;
              jBcol = ldb * (j - 1);
              jAcol = lda * (j - 1) - 1;
              i = j + 1;
              for (int k{i}; k <= n; k++) {
                int i1;
                int kBcol;
                kBcol = ldb * (k - 1);
                i1 = k + jAcol;
                if (A[i1] != 0.0) {
                  int i2;
                  i2 = static_cast<unsigned char>(m);
                  for (int b_i{0}; b_i < i2; b_i++) {
                    B[jBcol] = B[jBcol] - A[i1] * B[kBcol];
                  }
                }
              }
            }
          }
        }

        void xtrsm(int m, int n, const ::coder::array<double, 2U> &A, int lda, ::
                   coder::array<double, 2U> &B, int ldb)
        {
          if ((n != 0) && ((B.size(0) != 0) && (B.size(1) != 0))) {
            int i;
            i = static_cast<unsigned char>(m);
            for (int j{0}; j < n; j++) {
              double temp;
              int jAcol;
              int jBcol;
              jBcol = ldb * j;
              jAcol = lda * j;
              for (int k{0}; k < j; k++) {
                int i1;
                int kBcol;
                kBcol = ldb * k;
                i1 = k + jAcol;
                if (A[i1] != 0.0) {
                  for (int b_i{0}; b_i < i; b_i++) {
                    B[jBcol] = B[jBcol] - A[i1] * B[kBcol];
                  }
                }
              }

              temp = 1.0 / A[j + jAcol];
              for (int b_i{0}; b_i < i; b_i++) {
                B[jBcol] = temp * B[jBcol];
              }
            }
          }
        }
      }
    }
  }
}

// End of code generation (xtrsm.cpp)
