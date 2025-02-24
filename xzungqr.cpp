//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzungqr.cpp
//
// Code generation for function 'xzungqr'
//

// Include files
#include "xzungqr.h"
#include "rt_nonfinite.h"
#include "xzlarf.h"
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
        void xzungqr(int m, int n, int k, ::coder::array<double, 2U> &A, int ia0,
                     int lda, const ::coder::array<double, 1U> &tau)
        {
          ::coder::array<double, 1U> work;
          if (n >= 1) {
            int b_i;
            int i;
            int ia;
            int iaii;
            int itau;
            int j;
            i = n - 1;
            for (j = k; j <= i; j++) {
              ia = (ia0 + j * lda) - 1;
              iaii = m - 1;
              for (b_i = 0; b_i <= iaii; b_i++) {
                A[ia + b_i] = 0.0;
              }

              A[ia + j] = 1.0;
            }

            itau = k - 1;
            ia = A.size(1);
            work.set_size(ia);
            for (i = 0; i < ia; i++) {
              work[i] = 0.0;
            }

            for (b_i = k; b_i >= 1; b_i--) {
              iaii = ((ia0 + b_i) + (b_i - 1) * lda) - 1;
              if (b_i < n) {
                A[iaii - 1] = 1.0;
                c_xzlarf((m - b_i) + 1, n - b_i, iaii, tau[itau], A, iaii + lda,
                         lda, work);
              }

              if (b_i < m) {
                ia = iaii + 1;
                i = (iaii + m) - b_i;
                for (j = ia; j <= i; j++) {
                  A[j - 1] = -tau[itau] * A[j - 1];
                }
              }

              A[iaii - 1] = 1.0 - tau[itau];
              for (j = 0; j <= b_i - 2; j++) {
                A[(iaii - j) - 2] = 0.0;
              }

              itau--;
            }
          }
        }
      }
    }
  }
}

// End of code generation (xzungqr.cpp)
