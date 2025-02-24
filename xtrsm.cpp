//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
        void b_xtrsm(int n, const ::coder::array<double, 2U> &A, int lda, ::
                     coder::array<double, 2U> &B)
        {
          if ((n != 0) && (B.size(1) != 0)) {
            for (int j{n}; j >= 1; j--) {
              int i;
              int jAcol;
              jAcol = lda * (j - 1) - 1;
              i = j + 1;
              for (int k{i}; k <= n; k++) {
                int i1;
                i1 = k + jAcol;
                if (A[i1] != 0.0) {
                  B[j - 1] = B[j - 1] - A[i1] * B[k - 1];
                }
              }
            }
          }
        }

        void xtrsm(int n, const ::coder::array<double, 2U> &A, int lda, ::coder::
                   array<double, 2U> &B)
        {
          if ((n != 0) && (B.size(1) != 0)) {
            for (int j{0}; j < n; j++) {
              int jAcol;
              jAcol = lda * j;
              for (int k{0}; k < j; k++) {
                int i;
                i = k + jAcol;
                if (A[i] != 0.0) {
                  B[j] = B[j] - A[i] * B[k];
                }
              }

              B[j] = 1.0 / A[j + jAcol] * B[j];
            }
          }
        }
      }
    }
  }
}

// End of code generation (xtrsm.cpp)
