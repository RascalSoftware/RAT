//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
                      2U> &C, const ::coder::array<double, 1U> &tau)
        {
          int m;
          int mn;
          int nb;
          int u0;
          m = Q.size(0);
          nb = C.size(1);
          u0 = Q.size(0);
          mn = Q.size(1);
          if (u0 <= mn) {
            mn = u0;
          }

          for (int j{0}; j < mn; j++) {
            if (tau[j] != 0.0) {
              for (int k{0}; k < nb; k++) {
                double wj;
                wj = C[j];
                u0 = j + 2;
                for (int i{u0}; i <= m; i++) {
                  wj += Q[(i + Q.size(0) * j) - 1] * C[i - 1];
                }

                wj *= tau[j];
                if (wj != 0.0) {
                  C[j] = C[j] - wj;
                  for (int i{u0}; i <= m; i++) {
                    C[i - 1] = C[i - 1] - Q[(i + Q.size(0) * j) - 1] * wj;
                  }
                }
              }
            }
          }
        }

        void xunormqr(const ::coder::array<double, 1U> &Q, ::coder::array<double,
                      2U> &C, const double tau_data[])
        {
          int i;
          int m;
          int nb;
          m = Q.size(0);
          nb = C.size(1);
          if (Q.size(0) < 1) {
            i = -1;
          } else {
            i = 0;
          }

          for (int j{0}; j <= i; j++) {
            if (tau_data[0] != 0.0) {
              for (int k{0}; k < nb; k++) {
                double wj;
                wj = C[C.size(0) * k];
                for (int b_i{2}; b_i <= m; b_i++) {
                  wj += Q[b_i - 1] * C[(b_i + C.size(0) * k) - 1];
                }

                wj *= tau_data[0];
                if (wj != 0.0) {
                  C[C.size(0) * k] = C[C.size(0) * k] - wj;
                  for (int b_i{2}; b_i <= m; b_i++) {
                    C[(b_i + C.size(0) * k) - 1] = C[(b_i + C.size(0) * k) - 1]
                      - Q[b_i - 1] * wj;
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
