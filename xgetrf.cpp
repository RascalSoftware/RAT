//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
        void b_xgetrf(int m, int n, ::coder::array<double, 2U> &A, int lda, ::
                      coder::array<int, 2U> &ipiv)
        {
          int y;
          if (m <= n) {
            y = m;
          } else {
            y = n;
          }

          eml_integer_colon_dispatcher(y, ipiv);
          if ((m >= 1) && (n >= 1)) {
            int u0;
            u0 = m - 1;
            if (u0 > n) {
              u0 = n;
            }

            for (int j{0}; j < u0; j++) {
              int b_tmp;
              int jp1j;
              int mmj;
              mmj = m - j;
              b_tmp = j * (lda + 1);
              jp1j = b_tmp + 2;
              y = blas::ixamax(mmj, A, b_tmp + 1);
              if (A[(b_tmp + y) - 1] != 0.0) {
                if (y - 1 != 0) {
                  y += j;
                  ipiv[j] = y;
                  blas::xswap(n, A, j + 1, lda, y, lda);
                }

                y = b_tmp + mmj;
                for (int i{jp1j}; i <= y; i++) {
                  A[i - 1] = A[i - 1] / A[b_tmp];
                }
              }

              y = b_tmp + lda;
              blas::xgeru(mmj - 1, (n - j) - 1, b_tmp + 2, y + 1, lda, A, y + 2,
                          lda);
            }
          }
        }

        void xgetrf(int m, int n, ::coder::array<double, 2U> &A, int lda)
        {
          if ((m >= 1) && (n >= 1)) {
            int u0;
            u0 = m - 1;
            if (u0 > n) {
              u0 = n;
            }

            for (int j{0}; j < u0; j++) {
              int b_tmp;
              int jp1j;
              int jpiv_offset_tmp;
              int mmj;
              mmj = m - j;
              b_tmp = j * (lda + 1);
              jp1j = b_tmp + 2;
              jpiv_offset_tmp = blas::ixamax(mmj, A, b_tmp + 1) - 1;
              if (A[b_tmp + jpiv_offset_tmp] != 0.0) {
                if (jpiv_offset_tmp != 0) {
                  blas::xswap(n, A, j + 1, lda, (j + jpiv_offset_tmp) + 1, lda);
                }

                jpiv_offset_tmp = b_tmp + mmj;
                for (int i{jp1j}; i <= jpiv_offset_tmp; i++) {
                  A[i - 1] = A[i - 1] / A[b_tmp];
                }
              }

              jpiv_offset_tmp = b_tmp + lda;
              blas::xgeru(mmj - 1, (n - j) - 1, b_tmp + 2, jpiv_offset_tmp + 1,
                          lda, A, jpiv_offset_tmp + 2, lda);
            }
          }
        }

        int xgetrf(int m, int n, ::coder::array<double, 2U> &A, int lda, ::coder::
                   array<int, 2U> &ipiv)
        {
          int info;
          int y;
          if (m <= n) {
            y = m;
          } else {
            y = n;
          }

          eml_integer_colon_dispatcher(y, ipiv);
          info = 0;
          if ((m >= 1) && (n >= 1)) {
            int u0;
            u0 = m - 1;
            if (u0 > n) {
              u0 = n;
            }

            for (int j{0}; j < u0; j++) {
              int b_tmp;
              int jp1j;
              int mmj;
              mmj = m - j;
              b_tmp = j * (lda + 1);
              jp1j = b_tmp + 2;
              y = blas::ixamax(mmj, A, b_tmp + 1);
              if (A[(b_tmp + y) - 1] != 0.0) {
                if (y - 1 != 0) {
                  ipiv[j] = j + y;
                  blas::xswap(n, A, j + 1, lda, j + y, lda);
                }

                y = b_tmp + mmj;
                for (int i{jp1j}; i <= y; i++) {
                  A[i - 1] = A[i - 1] / A[b_tmp];
                }
              } else {
                info = j + 1;
              }

              y = b_tmp + lda;
              blas::xgeru(mmj - 1, (n - j) - 1, b_tmp + 2, y + 1, lda, A, y + 2,
                          lda);
            }

            if ((info == 0) && (m <= n) && (!(A[(m + A.size(0) * (m - 1)) - 1]
                  != 0.0))) {
              info = m;
            }
          }

          return info;
        }
      }
    }
  }
}

// End of code generation (xgetrf.cpp)
