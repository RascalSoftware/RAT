//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xgetrf.cpp
//
// Code generation for function 'xgetrf'
//

// Include files
#include "xgetrf.h"
#include "colon.h"
#include "ixamax.h"
#include "rt_nonfinite.h"
#include "xgeru.h"
#include "xswap.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace lapack
      {
        void xgetrf(int32_T m, int32_T n, ::coder::array<real_T, 2U> &A, int32_T
                    lda)
        {
          if ((m >= 1) && (n >= 1)) {
            int32_T u0;
            u0 = m - 1;
            if (u0 >= n) {
              u0 = n;
            }

            for (int32_T j{0}; j < u0; j++) {
              int32_T b_tmp;
              int32_T jp1j;
              int32_T jpiv_offset;
              int32_T mmj;
              mmj = m - j;
              b_tmp = j * (lda + 1);
              jp1j = b_tmp + 2;
              jpiv_offset = blas::ixamax(mmj, A, b_tmp + 1) - 1;
              if (A[b_tmp + jpiv_offset] != 0.0) {
                if (blas::ixamax(mmj, A, b_tmp + 1) - 1 != 0) {
                  blas::xswap(n, A, j + 1, lda, (j + jpiv_offset) + 1, lda);
                }

                jpiv_offset = b_tmp + mmj;
                for (int32_T i{jp1j}; i <= jpiv_offset; i++) {
                  A[i - 1] = A[i - 1] / A[b_tmp];
                }
              }

              jpiv_offset = b_tmp + lda;
              blas::xgeru(mmj - 1, (n - j) - 1, b_tmp + 2, jpiv_offset + 1, lda,
                          A, jpiv_offset + 2, lda);
            }
          }
        }

        void xgetrf(int32_T m, int32_T n, ::coder::array<real_T, 2U> &A, int32_T
                    lda, ::coder::array<int32_T, 2U> &ipiv)
        {
          int32_T y;
          if (m < n) {
            y = m;
          } else {
            y = n;
          }

          eml_integer_colon_dispatcher(y, ipiv);
          if ((m >= 1) && (n >= 1)) {
            int32_T u0;
            u0 = m - 1;
            if (u0 >= n) {
              u0 = n;
            }

            for (int32_T j{0}; j < u0; j++) {
              int32_T b_tmp;
              int32_T jp1j;
              int32_T jpiv_offset;
              int32_T mmj;
              mmj = m - j;
              b_tmp = j * (lda + 1);
              jp1j = b_tmp + 2;
              y = blas::ixamax(mmj, A, b_tmp + 1);
              jpiv_offset = blas::ixamax(mmj, A, b_tmp + 1);
              if (A[(b_tmp + jpiv_offset) - 1] != 0.0) {
                if (y - 1 != 0) {
                  ipiv[j] = j + y;
                  blas::xswap(n, A, j + 1, lda, j + jpiv_offset, lda);
                }

                y = b_tmp + mmj;
                for (jpiv_offset = jp1j; jpiv_offset <= y; jpiv_offset++) {
                  A[jpiv_offset - 1] = A[jpiv_offset - 1] / A[b_tmp];
                }
              }

              y = b_tmp + lda;
              blas::xgeru(mmj - 1, (n - j) - 1, b_tmp + 2, y + 1, lda, A, y + 2,
                          lda);
            }
          }
        }

        void xgetrf(int32_T m, int32_T n, ::coder::array<real_T, 2U> &A, int32_T
                    lda, ::coder::array<int32_T, 2U> &ipiv, int32_T *info)
        {
          int32_T y;
          if (m < n) {
            y = m;
          } else {
            y = n;
          }

          eml_integer_colon_dispatcher(y, ipiv);
          *info = 0;
          if ((m >= 1) && (n >= 1)) {
            int32_T u0;
            u0 = m - 1;
            if (u0 >= n) {
              u0 = n;
            }

            for (int32_T j{0}; j < u0; j++) {
              int32_T b_tmp;
              int32_T jp1j;
              int32_T jpiv_offset;
              int32_T mmj;
              mmj = m - j;
              b_tmp = j * (lda + 1);
              jp1j = b_tmp + 2;
              y = blas::ixamax(mmj, A, b_tmp + 1);
              jpiv_offset = blas::ixamax(mmj, A, b_tmp + 1) - 1;
              if (A[b_tmp + jpiv_offset] != 0.0) {
                if (y - 1 != 0) {
                  ipiv[j] = j + y;
                  blas::xswap(n, A, j + 1, lda, (j + jpiv_offset) + 1, lda);
                }

                y = b_tmp + mmj;
                for (jpiv_offset = jp1j; jpiv_offset <= y; jpiv_offset++) {
                  A[jpiv_offset - 1] = A[jpiv_offset - 1] / A[b_tmp];
                }
              } else {
                *info = j + 1;
              }

              y = b_tmp + lda;
              blas::xgeru(mmj - 1, (n - j) - 1, b_tmp + 2, y + 1, lda, A, y + 2,
                          lda);
            }

            if ((*info == 0) && (m <= n) && (!(A[(m + A.size(0) * (m - 1)) - 1]
                  != 0.0))) {
              *info = m;
            }
          }
        }
      }
    }
  }
}

// End of code generation (xgetrf.cpp)
