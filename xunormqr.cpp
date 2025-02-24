//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xunormqr.cpp
//
// Code generation for function 'xunormqr'
//

// Include files
#include "xunormqr.h"
#include "rt_nonfinite.h"
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
        void xunormqr(const ::coder::array<double, 2U> &Q, ::coder::array<double,
                      1U> &C, const ::coder::array<double, 1U> &tau)
        {
          int m;
          int mn;
          int u0;
          m = Q.size(0);
          u0 = Q.size(0);
          mn = Q.size(1);
          if (u0 < mn) {
            mn = u0;
          }

          for (int j{0}; j < mn; j++) {
            if (tau[j] != 0.0) {
              double wj;
              int i;
              wj = C[j];
              u0 = j + 2;
              for (i = u0; i <= m; i++) {
                wj += Q[(i + Q.size(0) * j) - 1] * C[i - 1];
              }

              wj *= tau[j];
              if (wj != 0.0) {
                C[j] = C[j] - wj;
                for (i = u0; i <= m; i++) {
                  C[i - 1] = C[i - 1] - Q[(i + Q.size(0) * j) - 1] * wj;
                }
              }
            }
          }
        }

        void xunormqr(const ::coder::array<double, 1U> &Q, ::coder::array<double,
                      2U> &C, const double tau_data[])
        {
          int m;
          int mn;
          int nb;
          m = Q.size(0);
          nb = C.size(1);
          if (Q.size(0) < 1) {
            mn = -1;
          } else {
            mn = 0;
          }

          for (int j{0}; j <= mn; j++) {
            if (tau_data[0] != 0.0) {
              for (int k{0}; k < nb; k++) {
                double wj;
                int i;
                wj = C[C.size(0) * k];
                for (i = 2; i <= m; i++) {
                  wj += Q[i - 1] * C[(i + C.size(0) * k) - 1];
                }

                wj *= tau_data[0];
                if (wj != 0.0) {
                  C[C.size(0) * k] = C[C.size(0) * k] - wj;
                  for (i = 2; i <= m; i++) {
                    C[(i + C.size(0) * k) - 1] = C[(i + C.size(0) * k) - 1] -
                      Q[i - 1] * wj;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

// End of code generation (xunormqr.cpp)
