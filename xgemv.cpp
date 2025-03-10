//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xgemv.cpp
//
// Code generation for function 'xgemv'
//

// Include files
#include "xgemv.h"
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
        void b_xgemv(int m, int n, const ::coder::array<double, 2U> &A, int ia0,
                     int lda, const ::coder::array<double, 2U> &x, int ix0, ::
                     coder::array<double, 1U> &y)
        {
          if (m != 0) {
            int i;
            int ix;
            for (ix = 0; ix < m; ix++) {
              y[ix] = 0.0;
            }

            ix = ix0;
            i = ia0 + lda * (n - 1);
            for (int iac{ia0}; lda < 0 ? iac >= i : iac <= i; iac += lda) {
              int i1;
              i1 = (iac + m) - 1;
              for (int ia{iac}; ia <= i1; ia++) {
                int i2;
                i2 = ia - iac;
                y[i2] = y[i2] + A[ia - 1] * x[ix - 1];
              }

              ix++;
            }
          }
        }

        void xgemv(int m, int n, int lda, const ::coder::array<double, 2U> &x,
                   int ix0, double beta1, ::coder::array<double, 2U> &y, int iy0)
        {
          if (m != 0) {
            int iy;
            int iyend;
            iyend = (iy0 + m) - 1;
            if (beta1 != 1.0) {
              if (beta1 == 0.0) {
                for (iy = iy0; iy <= iyend; iy++) {
                  y[iy - 1] = 0.0;
                }
              } else {
                for (iy = iy0; iy <= iyend; iy++) {
                  y[iy - 1] = beta1 * y[iy - 1];
                }
              }
            }

            iyend = ix0;
            iy = lda * (n - 1) + 1;
            for (int iac{1}; lda < 0 ? iac >= iy : iac <= iy; iac += lda) {
              int i;
              i = (iac + m) - 1;
              for (int ia{iac}; ia <= i; ia++) {
                int i1;
                i1 = ((iy0 + ia) - iac) - 1;
                y[i1] = y[i1] + y[ia - 1] * x[iyend - 1];
              }

              iyend++;
            }
          }
        }

        void xgemv(int m, int n, const ::coder::array<double, 2U> &A, int ia0,
                   int lda, const ::coder::array<double, 2U> &x, int ix0, ::
                   coder::array<double, 1U> &y)
        {
          if (n != 0) {
            int i;
            int iy;
            for (iy = 0; iy < n; iy++) {
              y[iy] = 0.0;
            }

            iy = 0;
            i = ia0 + lda * (n - 1);
            for (int iac{ia0}; lda < 0 ? iac >= i : iac <= i; iac += lda) {
              double c;
              int i1;
              c = 0.0;
              i1 = (iac + m) - 1;
              for (int ia{iac}; ia <= i1; ia++) {
                c += A[ia - 1] * x[((ix0 + ia) - iac) - 1];
              }

              y[iy] = y[iy] + c;
              iy++;
            }
          }
        }
      }
    }
  }
}

// End of code generation (xgemv.cpp)
