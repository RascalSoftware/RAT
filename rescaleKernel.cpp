//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// rescaleKernel.cpp
//
// Code generation for function 'rescaleKernel'
//

// Include files
#include "rescaleKernel.h"
#include "abs.h"
#include "bsxfun.h"
#include "div.h"
#include "log2.h"
#include "minOrMax.h"
#include "pow2.h"
#include "rdivide_helper.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 1U> &in1, const ::coder::
    array<double, 1U> &in2, const ::coder::array<double, 1U> &in3, const ::coder::
    array<double, 1U> &in4, const ::coder::array<double, 1U> &in5, const ::coder::
    array<signed char, 1U> &in6);
  static void binary_expand_op(::coder::array<double, 1U> &in1, const ::coder::
    array<double, 1U> &in2, const ::coder::array<double, 1U> &in3, const ::coder::
    array<double, 1U> &in4, const ::coder::array<double, 1U> &in5, const ::coder::
    array<signed char, 1U> &in6, const ::coder::array<double, 1U> &in7);
}

// Function Definitions
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 1U> &in1, const ::coder::
    array<double, 1U> &in2, const ::coder::array<double, 1U> &in3, const ::coder::
    array<double, 1U> &in4, const ::coder::array<double, 1U> &in5, const ::coder::
    array<signed char, 1U> &in6)
  {
    ::coder::array<double, 1U> r;
    int i;
    int loop_ub;
    int stride_0_0;
    int stride_1_0_tmp;
    int stride_2_0;
    int stride_4_0;
    if (in4.size(0) == 1) {
      i = in5.size(0);
      loop_ub = in6.size(0);
      if (loop_ub == 1) {
        if (i == 1) {
          if (in4.size(0) == 1) {
            loop_ub = in3.size(0);
          } else {
            loop_ub = in4.size(0);
          }
        } else {
          loop_ub = i;
        }
      }
    } else {
      loop_ub = in4.size(0);
    }

    r.set_size(loop_ub);
    stride_0_0 = (in3.size(0) != 1);
    stride_1_0_tmp = (in4.size(0) != 1);
    stride_2_0 = (in5.size(0) != 1);
    stride_4_0 = (in6.size(0) != 1);
    for (i = 0; i < loop_ub; i++) {
      double d;
      d = in4[i * stride_1_0_tmp];
      r[i] = 1.0 / ((in3[i * stride_0_0] / d - in5[i * stride_2_0] / d) +
                    static_cast<double>(in6[i * stride_4_0]) / d) / d;
    }

    coder::e_bsxfun(in2, r, in1);
  }

  static void binary_expand_op(::coder::array<double, 1U> &in1, const ::coder::
    array<double, 1U> &in2, const ::coder::array<double, 1U> &in3, const ::coder::
    array<double, 1U> &in4, const ::coder::array<double, 1U> &in5, const ::coder::
    array<signed char, 1U> &in6, const ::coder::array<double, 1U> &in7)
  {
    ::coder::array<double, 1U> b_in3;
    int i;
    int loop_ub;
    int stride_0_0_tmp;
    int stride_1_0_tmp;
    int stride_2_0_tmp;
    int stride_3_0_tmp;
    int stride_5_0_tmp;
    int stride_6_0_tmp;
    if (in7.size(0) == 1) {
      i = in6.size(0);
    } else {
      i = in7.size(0);
    }

    if (in3.size(0) == 1) {
      loop_ub = in5.size(0);
    } else {
      loop_ub = in3.size(0);
    }

    if (in4.size(0) == 1) {
      stride_0_0_tmp = i;
    } else {
      stride_0_0_tmp = in4.size(0);
    }

    if (i == 1) {
      if (in5.size(0) == 1) {
        i = in1.size(0);
      } else {
        i = in5.size(0);
      }
    }

    if (i == 1) {
      if (stride_0_0_tmp == 1) {
        if (loop_ub == 1) {
          if (in4.size(0) == 1) {
            i = in1.size(0);
          } else {
            i = in4.size(0);
          }
        } else {
          i = loop_ub;
        }
      } else {
        i = stride_0_0_tmp;
      }
    }

    if (i == 1) {
      loop_ub = in3.size(0);
    } else {
      loop_ub = i;
    }

    b_in3.set_size(loop_ub);
    stride_0_0_tmp = (in3.size(0) != 1);
    stride_1_0_tmp = (in1.size(0) != 1);
    stride_2_0_tmp = (in4.size(0) != 1);
    stride_3_0_tmp = (in5.size(0) != 1);
    stride_5_0_tmp = (in6.size(0) != 1);
    stride_6_0_tmp = (in7.size(0) != 1);
    for (i = 0; i < loop_ub; i++) {
      double b_in3_tmp;
      double c_in3_tmp;
      double d_in3_tmp;
      double e_in3_tmp;
      double in3_tmp;
      in3_tmp = in3[i * stride_0_0_tmp];
      b_in3_tmp = in4[i * stride_2_0_tmp];
      c_in3_tmp = in1[i * stride_1_0_tmp];
      d_in3_tmp = in5[i * stride_3_0_tmp];
      e_in3_tmp = static_cast<double>(in6[i * stride_5_0_tmp]) / in7[i *
        stride_6_0_tmp];
      b_in3[i] = in3_tmp * (((c_in3_tmp * b_in3_tmp - d_in3_tmp * (1.0 / in3_tmp))
        + e_in3_tmp * b_in3_tmp) / ((c_in3_tmp - d_in3_tmp) + e_in3_tmp));
    }

    coder::f_bsxfun(in2, b_in3, in1);
  }

  namespace coder
  {
    void rescaleKernel(::coder::array<double, 1U> &A, const ::coder::array<
                       double, 1U> &inputMin, const ::coder::array<double, 1U>
                       &inputMax)
    {
      ::coder::array<double, 1U> b_e1;
      ::coder::array<double, 1U> e1;
      ::coder::array<double, 1U> iMax;
      ::coder::array<double, 1U> iMin;
      ::coder::array<double, 1U> r;
      ::coder::array<double, 1U> r1;
      ::coder::array<double, 1U> r3;
      ::coder::array<double, 1U> sigma;
      ::coder::array<signed char, 1U> x_tmp;
      if (A.size(0) != 0) {
        double varargin_2;
        int i;
        int i1;
        int i2;
        int i3;
        int i4;
        int i5;
        int i6;
        int i7;
        int k;
        e1.set_size(inputMax.size(0));
        k = inputMax.size(0);
        for (i = 0; i < k; i++) {
          varargin_2 = inputMax[i];
          e1[i] = std::fmin(0.0, varargin_2);
        }

        c_bsxfun(e1, inputMin, sigma);
        e1.set_size(A.size(0));
        k = A.size(0) - 1;
        for (i = 0; i <= k; i++) {
          e1[i] = A[i];
        }

        d_bsxfun(e1, sigma, A);
        d_bsxfun(inputMin, sigma, iMin);
        d_bsxfun(inputMax, sigma, iMax);
        b_abs(iMax, r1);
        b_abs(iMin, e1);
        internal::maximum2(r1, e1, r);
        b_log2(r, sigma, b_e1);
        e1.set_size(b_e1.size(0));
        k = b_e1.size(0);
        for (i = 0; i < k; i++) {
          e1[i] = b_e1[i] - 1.0;
          b_e1[i] = (b_e1[i] + 1.0) / 2.0;
        }

        pow2(e1, r1);
        i = b_e1.size(0);
        for (k = 0; k < i; k++) {
          b_e1[k] = std::trunc(b_e1[k]);
        }

        e1.set_size(b_e1.size(0));
        k = b_e1.size(0);
        for (i = 0; i < k; i++) {
          e1[i] = b_e1[i] - 1.0;
        }

        pow2(e1, r3);
        if (iMax.size(0) == r1.size(0)) {
          b_e1.set_size(iMax.size(0));
          k = iMax.size(0);
          for (i = 0; i < k; i++) {
            b_e1[i] = iMax[i] / r1[i];
          }
        } else {
          rdivide(b_e1, iMax, r1);
        }

        e1.set_size(r3.size(0));
        k = r3.size(0);
        for (i = 0; i < k; i++) {
          e1[i] = 0.0 / r3[i];
        }

        if (iMin.size(0) == r1.size(0)) {
          r.set_size(iMin.size(0));
          k = iMin.size(0);
          for (i = 0; i < k; i++) {
            r[i] = iMin[i] / r1[i];
          }
        } else {
          rdivide(r, iMin, r1);
        }

        if (iMin.size(0) == iMax.size(0)) {
          x_tmp.set_size(iMin.size(0));
          k = iMin.size(0);
          for (i = 0; i < k; i++) {
            x_tmp[i] = static_cast<signed char>(iMin[i] == iMax[i]);
          }
        } else {
          binary_expand_op(x_tmp, iMin, iMax);
        }

        if (iMax.size(0) == 1) {
          i = r3.size(0);
        } else {
          i = iMax.size(0);
        }

        if (iMin.size(0) == 1) {
          k = r3.size(0);
        } else {
          k = iMin.size(0);
        }

        if (i == 1) {
          i1 = k;
        } else {
          i1 = i;
        }

        if (x_tmp.size(0) == 1) {
          i2 = r3.size(0);
        } else {
          i2 = x_tmp.size(0);
        }

        if (i1 == 1) {
          i3 = i2;
        } else {
          i3 = i1;
        }

        if ((iMax.size(0) == r3.size(0)) && (iMin.size(0) == r3.size(0)) && (i ==
             k) && (x_tmp.size(0) == r3.size(0)) && (i1 == i2) && (i3 == r3.size
             (0))) {
          k = iMax.size(0);
          for (i = 0; i < k; i++) {
            iMax[i] = 1.0 / ((iMax[i] / r3[i] - iMin[i] / r3[i]) + static_cast<
                             double>(x_tmp[i]) / r3[i]) / r3[i];
          }

          e_bsxfun(A, iMax, sigma);
        } else {
          binary_expand_op(sigma, A, iMax, r3, iMin, x_tmp);
        }

        if (b_e1.size(0) == 1) {
          i = e1.size(0);
        } else {
          i = b_e1.size(0);
        }

        if (r.size(0) == 1) {
          k = r3.size(0);
        } else {
          k = r.size(0);
        }

        if (x_tmp.size(0) == 1) {
          i1 = r1.size(0);
        } else {
          i1 = x_tmp.size(0);
        }

        if (i == 1) {
          i2 = k;
        } else {
          i2 = i;
        }

        if (i1 == 1) {
          i3 = e1.size(0);
        } else {
          i3 = i1;
        }

        if (b_e1.size(0) == 1) {
          i4 = r.size(0);
        } else {
          i4 = b_e1.size(0);
        }

        if (i2 == 1) {
          i5 = i3;
        } else {
          i5 = i2;
        }

        if (i4 == 1) {
          i6 = i1;
        } else {
          i6 = i4;
        }

        if (i5 == 1) {
          i7 = i6;
        } else {
          i7 = i5;
        }

        if ((b_e1.size(0) == e1.size(0)) && (r.size(0) == r3.size(0)) && (i == k)
            && (x_tmp.size(0) == r1.size(0)) && (i1 == e1.size(0)) && (i2 == i3)
            && (b_e1.size(0) == r.size(0)) && (x_tmp.size(0) == r1.size(0)) &&
            (i4 == i1) && (i5 == i6) && (r3.size(0) == i7)) {
          k = r3.size(0);
          for (i = 0; i < k; i++) {
            varargin_2 = static_cast<double>(x_tmp[i]) / r1[i];
            r3[i] = r3[i] * (((b_e1[i] * e1[i] - r[i] * (1.0 / r3[i])) +
                              varargin_2 * e1[i]) / ((b_e1[i] - r[i]) +
              varargin_2));
          }

          f_bsxfun(sigma, r3, b_e1);
        } else {
          binary_expand_op(b_e1, sigma, r3, e1, r, x_tmp, r1);
        }

        bsxfun(b_e1, r1);
        b_bsxfun(r1, e1);
        c_bsxfun(e1, A);
      }
    }
  }
}

// End of code generation (rescaleKernel.cpp)
