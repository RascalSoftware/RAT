//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// combineVectorElements.cpp
//
// Code generation for function 'combineVectorElements'
//

// Include files
#include "combineVectorElements.h"
#include "blockedSummation.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::array<
                        double, 2U> &in2, const ::coder::array<double, 2U> &in3,
                        const ::coder::array<double, 1U> &in4, int in5, int in6,
                        int in7)
  {
    ::coder::array<double, 2U> b_in2;
    int aux_0_1;
    int aux_1_1;
    int b_loop_ub;
    int i;
    int loop_ub;
    int stride_0_0;
    int stride_0_1;
    int stride_1_0;
    int stride_1_1;
    if (in3.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in3.size(0);
    }

    if (in3.size(1) == 1) {
      b_loop_ub = in2.size(1);
    } else {
      b_loop_ub = in3.size(1);
    }

    b_in2.set_size(loop_ub, b_loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_0_1 = (in2.size(1) != 1);
    stride_1_0 = (in3.size(0) != 1);
    stride_1_1 = (in3.size(1) != 1);
    aux_0_1 = 0;
    aux_1_1 = 0;
    for (i = 0; i < b_loop_ub; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        b_in2[i1 + b_in2.size(0) * i] = in2[i1 * stride_0_0 + in2.size(0) *
          aux_0_1] - in3[i1 * stride_1_0 + in3.size(0) * aux_1_1];
      }

      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }

    i = static_cast<int>(in4[in5]);
    if (i == 1) {
      i = in6 - in7;
    }

    coder::blockedSummation(b_in2, i, in1);
  }

  void c_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::array<
    double, 2U> &in2, const ::coder::array<double, 2U> &in3, const ::coder::
    array<double, 1U> &in4, int in5, int in6, int in7)
  {
    ::coder::array<double, 2U> b_in2;
    int b_loop_ub;
    int i;
    int loop_ub;
    int stride_0_0;
    int stride_1_0;
    if (in3.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in3.size(0);
    }

    b_in2.set_size(loop_ub, in2.size(1));
    stride_0_0 = (in2.size(0) != 1);
    stride_1_0 = (in3.size(0) != 1);
    b_loop_ub = in2.size(1);
    for (i = 0; i < b_loop_ub; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        b_in2[i1 + b_in2.size(0) * i] = in2[i1 * stride_0_0 + in2.size(0) * i] -
          in3[i1 * stride_1_0 + in3.size(0) * i];
      }
    }

    i = static_cast<int>(in4[in5]);
    if (i == 1) {
      i = in6 - in7;
    }

    coder::blockedSummation(b_in2, i, in1);
  }

  namespace coder
  {
    double b_combineVectorElements(const ::coder::array<double, 1U> &x, int vlen)
    {
      double y;
      if ((x.size(0) == 0) || (vlen == 0)) {
        y = 0.0;
      } else {
        y = nestedIter(x, vlen);
      }

      return y;
    }

    int c_combineVectorElements(const ::coder::array<boolean_T, 1U> &x)
    {
      int vlen;
      int y;
      vlen = x.size(0);
      if (x.size(0) == 0) {
        y = 0;
      } else {
        y = x[0];
        for (int k{2}; k <= vlen; k++) {
          if (vlen >= 2) {
            y += x[k - 1];
          }
        }
      }

      return y;
    }

    int combineVectorElements(const ::coder::array<boolean_T, 2U> &x)
    {
      int vlen;
      int y;
      vlen = x.size(1);
      if (x.size(1) == 0) {
        y = 0;
      } else {
        y = x[0];
        for (int k{2}; k <= vlen; k++) {
          if (vlen >= 2) {
            y += x[k - 1];
          }
        }
      }

      return y;
    }
  }
}

// End of code generation (combineVectorElements.cpp)
