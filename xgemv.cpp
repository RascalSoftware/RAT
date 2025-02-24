//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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

        void c_xgemv(int m, int n, const ::coder::array<double, 2U> &A, int ia0,
                     int lda, const ::coder::array<double, 2U> &x, int ix0, ::
                     coder::array<double, 1U> &y)
        {
          ::coder::array<double, 1U> b_y;
          int i;
          int loop_ub;
          b_y.set_size(y.size(0));
          loop_ub = y.size(0);
          for (i = 0; i < loop_ub; i++) {
            b_y[i] = y[i];
          }

          if (n != 0) {
            int iy;
            for (iy = 0; iy < n; iy++) {
              b_y[iy] = 0.0;
            }

            iy = 0;
            i = ia0 + lda * (n - 1);
            for (int iac{ia0}; lda < 0 ? iac >= i : iac <= i; iac += lda) {
              double c;
              c = 0.0;
              loop_ub = (iac + m) - 1;
              for (int ia{iac}; ia <= loop_ub; ia++) {
                c += A[ia - 1] * x[((ix0 + ia) - iac) - 1];
              }

              b_y[iy] = b_y[iy] + c;
              iy++;
            }
          }

          y.set_size(b_y.size(0));
          loop_ub = b_y.size(0);
          for (i = 0; i < loop_ub; i++) {
            y[i] = b_y[i];
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
