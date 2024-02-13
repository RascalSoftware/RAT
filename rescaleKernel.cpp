//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// rescaleKernel.cpp
//
// Code generation for function 'rescaleKernel'
//

// Include files
#include "rescaleKernel.h"
#include "abs.h"
#include "bsxfun.h"
#include "log2.h"
#include "minOrMax.h"
#include "pow2.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void rescaleKernel(::coder::array<real_T, 1U> &A, const ::coder::array<
                       real_T, 1U> &inputMin, const ::coder::array<real_T, 1U>
                       &inputMax)
    {
      ::coder::array<real_T, 1U> b_A;
      ::coder::array<real_T, 1U> e1;
      ::coder::array<real_T, 1U> iMax;
      ::coder::array<real_T, 1U> iMin;
      ::coder::array<real_T, 1U> r;
      ::coder::array<real_T, 1U> r3;
      ::coder::array<real_T, 1U> sigma;
      ::coder::array<boolean_T, 1U> constReg;
      if (A.size(0) != 0) {
        int32_T i;
        int32_T k;
        internal::minimum2(inputMax, r);
        c_bsxfun(r, inputMin, sigma);
        b_A.set_size(A.size(0));
        k = A.size(0) - 1;
        for (i = 0; i <= k; i++) {
          b_A[i] = A[i];
        }

        d_bsxfun(b_A, sigma, A);
        d_bsxfun(inputMin, sigma, iMin);
        d_bsxfun(inputMax, sigma, iMax);
        b_abs(iMax, r);
        b_abs(iMin, b_A);
        internal::maximum2(r, b_A, r3);
        b_log2(r3, sigma, e1);
        b_A.set_size(e1.size(0));
        k = e1.size(0);
        for (i = 0; i < k; i++) {
          b_A[i] = e1[i] - 1.0;
        }

        pow2(b_A, sigma);
        k = e1.size(0);
        for (i = 0; i < k; i++) {
          e1[i] = (e1[i] + 1.0) / 2.0;
        }

        i = e1.size(0);
        for (k = 0; k < i; k++) {
          e1[k] = std::trunc(e1[k]);
        }

        k = e1.size(0);
        for (i = 0; i < k; i++) {
          e1[i] = e1[i] - 1.0;
        }

        pow2(e1, r3);
        constReg.set_size(iMin.size(0));
        k = iMin.size(0);
        for (i = 0; i < k; i++) {
          constReg[i] = (iMin[i] == iMax[i]);
        }

        b_A.set_size(iMax.size(0));
        k = iMax.size(0);
        for (i = 0; i < k; i++) {
          b_A[i] = iMax[i] / sigma[i];
        }

        e1.set_size(r3.size(0));
        k = r3.size(0);
        for (i = 0; i < k; i++) {
          e1[i] = 0.0 / r3[i];
        }

        r.set_size(iMin.size(0));
        k = iMin.size(0);
        for (i = 0; i < k; i++) {
          r[i] = iMin[i] / sigma[i];
        }

        k = iMax.size(0);
        for (i = 0; i < k; i++) {
          iMax[i] = 1.0 / ((iMax[i] / r3[i] - iMin[i] / r3[i]) +
                           static_cast<real_T>(constReg[i]) / r3[i]) / r3[i];
        }

        k = r3.size(0);
        for (i = 0; i < k; i++) {
          real_T r3_tmp;
          r3_tmp = static_cast<real_T>(constReg[i]) / sigma[i];
          r3[i] = r3[i] * (((b_A[i] * e1[i] - r[i] * (1.0 / r3[i])) + r3_tmp *
                            e1[i]) / ((b_A[i] - r[i]) + r3_tmp));
        }

        e_bsxfun(A, iMax, r);
        f_bsxfun(r, r3, b_A);
        bsxfun(b_A, r);
        b_bsxfun(r, b_A);
        c_bsxfun(b_A, A);
      }
    }
  }
}

// End of code generation (rescaleKernel.cpp)
