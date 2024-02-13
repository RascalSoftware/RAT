//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// makeD.cpp
//
// Code generation for function 'makeD'
//

// Include files
#include "makeD.h"
#include "RATMain_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void makeD(const ::coder::array<creal_T, 1U> &alpha1, const ::coder::array<
               creal_T, 1U> &beta1, ::coder::array<creal_T, 2U> &D)
    {
      int32_T i;
      int32_T k;
      D.set_size(alpha1.size(0), alpha1.size(0));
      k = alpha1.size(0);
      for (i = 0; i < k; i++) {
        int32_T loop_ub;
        loop_ub = alpha1.size(0);
        for (int32_T i1{0}; i1 < loop_ub; i1++) {
          D[i1 + D.size(0) * i].re = 0.0;
          D[i1 + D.size(0) * i].im = 0.0;
        }
      }

      i = alpha1.size(0);
      for (k = 0; k < i; k++) {
        real_T ai;
        real_T ar;
        real_T bi;
        real_T br;
        ar = alpha1[k].re;
        ai = alpha1[k].im;
        br = beta1[k].re;
        bi = beta1[k].im;
        if (bi == 0.0) {
          if (ai == 0.0) {
            D[k + D.size(0) * k].re = ar / br;
            D[k + D.size(0) * k].im = 0.0;
          } else if (ar == 0.0) {
            D[k + D.size(0) * k].re = 0.0;
            D[k + D.size(0) * k].im = ai / br;
          } else {
            D[k + D.size(0) * k].re = ar / br;
            D[k + D.size(0) * k].im = ai / br;
          }
        } else if (br == 0.0) {
          if (ar == 0.0) {
            D[k + D.size(0) * k].re = ai / bi;
            D[k + D.size(0) * k].im = 0.0;
          } else if (ai == 0.0) {
            D[k + D.size(0) * k].re = 0.0;
            D[k + D.size(0) * k].im = -(ar / bi);
          } else {
            D[k + D.size(0) * k].re = ai / bi;
            D[k + D.size(0) * k].im = -(ar / bi);
          }
        } else {
          real_T bim;
          real_T brm;
          brm = std::abs(br);
          bim = std::abs(bi);
          if (brm > bim) {
            real_T s;
            s = bi / br;
            bim = br + s * bi;
            D[k + D.size(0) * k].re = (ar + s * ai) / bim;
            D[k + D.size(0) * k].im = (ai - s * ar) / bim;
          } else if (bim == brm) {
            real_T s;
            if (br > 0.0) {
              s = 0.5;
            } else {
              s = -0.5;
            }

            if (bi > 0.0) {
              bim = 0.5;
            } else {
              bim = -0.5;
            }

            D[k + D.size(0) * k].re = (ar * s + ai * bim) / brm;
            D[k + D.size(0) * k].im = (ai * s - ar * bim) / brm;
          } else {
            real_T s;
            s = br / bi;
            bim = bi + s * br;
            D[k + D.size(0) * k].re = (s * ar + ai) / bim;
            D[k + D.size(0) * k].im = (s * ai - ar) / bim;
          }
        }
      }
    }
  }
}

// End of code generation (makeD.cpp)
