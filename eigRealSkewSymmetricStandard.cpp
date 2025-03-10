//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// eigRealSkewSymmetricStandard.cpp
//
// Code generation for function 'eigRealSkewSymmetricStandard'
//

// Include files
#include "eigRealSkewSymmetricStandard.h"
#include "RATMain_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void extractEigenVectors(const ::coder::array<double, 2U> &U, const ::coder::
      array<double, 2U> &T, ::coder::array<creal_T, 2U> &V)
    {
      int j;
      int n;
      int sgn;
      V.set_size(U.size(0), U.size(1));
      j = U.size(1);
      for (sgn = 0; sgn < j; sgn++) {
        n = U.size(0);
        for (int i{0}; i < n; i++) {
          V[i + V.size(0) * sgn].re = U[i + U.size(0) * sgn];
          V[i + V.size(0) * sgn].im = 0.0;
        }
      }

      j = 1;
      n = T.size(0);
      int exitg1;
      do {
        exitg1 = 0;
        if (j <= n) {
          if (j != n) {
            double ar;
            ar = T[j + T.size(0) * (j - 1)];
            if (ar != 0.0) {
              if (ar < 0.0) {
                sgn = 1;
              } else {
                sgn = -1;
              }

              for (int i{0}; i < n; i++) {
                double ai;
                ar = V[i + V.size(0) * (j - 1)].re;
                ai = static_cast<double>(sgn) * V[i + V.size(0) * j].re;
                if (ai == 0.0) {
                  V[i + V.size(0) * (j - 1)].re = ar / 1.4142135623730951;
                  V[i + V.size(0) * (j - 1)].im = 0.0;
                } else if (ar == 0.0) {
                  V[i + V.size(0) * (j - 1)].re = 0.0;
                  V[i + V.size(0) * (j - 1)].im = ai / 1.4142135623730951;
                } else {
                  V[i + V.size(0) * (j - 1)].re = ar / 1.4142135623730951;
                  V[i + V.size(0) * (j - 1)].im = ai / 1.4142135623730951;
                }

                V[i + V.size(0) * j].re = V[i + V.size(0) * (j - 1)].re;
                V[i + V.size(0) * j].im = -V[i + V.size(0) * (j - 1)].im;
              }

              j += 2;
            } else {
              j++;
            }
          } else {
            j++;
          }
        } else {
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
  }
}

// End of code generation (eigRealSkewSymmetricStandard.cpp)
