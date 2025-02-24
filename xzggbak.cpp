//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzggbak.cpp
//
// Code generation for function 'xzggbak'
//

// Include files
#include "xzggbak.h"
#include "rt_nonfinite.h"
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
        void xzggbak(::coder::array<creal_T, 2U> &V, int ilo, int ihi, const ::
                     coder::array<int, 1U> &rscale)
        {
          double tmp_im;
          double tmp_re;
          int i;
          int j;
          int k;
          int m;
          int n;
          n = V.size(0);
          m = V.size(1) - 1;
          if (ilo > 1) {
            for (i = ilo - 2; i + 1 >= 1; i--) {
              k = rscale[i] - 1;
              if (rscale[i] != i + 1) {
                for (j = 0; j <= m; j++) {
                  tmp_re = V[i + V.size(0) * j].re;
                  tmp_im = V[i + V.size(0) * j].im;
                  V[i + V.size(0) * j] = V[k + V.size(0) * j];
                  V[k + V.size(0) * j].re = tmp_re;
                  V[k + V.size(0) * j].im = tmp_im;
                }
              }
            }
          }

          if (ihi < n) {
            k = ihi + 1;
            for (i = k; i <= n; i++) {
              int b_i;
              b_i = rscale[i - 1];
              if (b_i != i) {
                for (j = 0; j <= m; j++) {
                  tmp_re = V[(i + V.size(0) * j) - 1].re;
                  tmp_im = V[(i + V.size(0) * j) - 1].im;
                  V[(i + V.size(0) * j) - 1] = V[(b_i + V.size(0) * j) - 1];
                  V[(b_i + V.size(0) * j) - 1].re = tmp_re;
                  V[(b_i + V.size(0) * j) - 1].im = tmp_im;
                }
              }
            }
          }
        }
      }
    }
  }
}

// End of code generation (xzggbak.cpp)
