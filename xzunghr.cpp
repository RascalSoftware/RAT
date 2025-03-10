//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xzunghr.cpp
//
// Code generation for function 'xzunghr'
//

// Include files
#include "xzunghr.h"
#include "rt_nonfinite.h"
#include "xzungqr.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace reflapack
      {
        void xzunghr(int n, int ilo, int ihi, ::coder::array<double, 2U> &A, int
                     lda, const ::coder::array<double, 1U> &tau)
        {
          int a;
          int b_i;
          int ia;
          int nh;
          nh = ihi - ilo;
          a = ilo + 1;
          for (int j{ihi}; j >= a; j--) {
            int iajm1;
            ia = (j - 1) * lda - 1;
            for (int i{0}; i <= j - 2; i++) {
              A[(ia + i) + 1] = 0.0;
            }

            iajm1 = ia - lda;
            b_i = j + 1;
            for (int i{b_i}; i <= ihi; i++) {
              A[ia + i] = A[iajm1 + i];
            }

            b_i = ihi + 1;
            for (int i{b_i}; i <= n; i++) {
              A[ia + i] = 0.0;
            }
          }

          for (int j{0}; j < ilo; j++) {
            ia = j * lda;
            for (int i{0}; i < n; i++) {
              A[ia + i] = 0.0;
            }

            A[ia + j] = 1.0;
          }

          b_i = ihi + 1;
          for (int j{b_i}; j <= n; j++) {
            ia = (j - 1) * lda;
            for (int i{0}; i < n; i++) {
              A[ia + i] = 0.0;
            }

            A[(ia + j) - 1] = 1.0;
          }

          xzungqr(nh, nh, nh, A, (ilo + ilo * lda) + 1, lda, tau, ilo);
        }

        void xzunghr(int n, int ihi, ::coder::array<double, 2U> &A, int lda,
                     const ::coder::array<double, 1U> &tau)
        {
          if (n != 0) {
            int b_i;
            int ia;
            for (int j{ihi}; j >= 2; j--) {
              int iajm1;
              ia = (j - 1) * lda - 1;
              for (int i{0}; i <= j - 2; i++) {
                A[(ia + i) + 1] = 0.0;
              }

              iajm1 = ia - lda;
              b_i = j + 1;
              for (int i{b_i}; i <= ihi; i++) {
                A[ia + i] = A[iajm1 + i];
              }

              b_i = ihi + 1;
              for (int i{b_i}; i <= n; i++) {
                A[ia + i] = 0.0;
              }
            }

            for (int i{0}; i < n; i++) {
              A[i] = 0.0;
            }

            A[0] = 1.0;
            b_i = ihi + 1;
            for (int j{b_i}; j <= n; j++) {
              ia = (j - 1) * lda;
              for (int i{0}; i < n; i++) {
                A[ia + i] = 0.0;
              }

              A[(ia + j) - 1] = 1.0;
            }

            xzungqr(ihi - 1, ihi - 1, ihi - 1, A, lda + 2, lda, tau);
          }
        }
      }
    }
  }
}

// End of code generation (xzunghr.cpp)
