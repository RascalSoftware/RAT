//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// unsafeSxfun.cpp
//
// Code generation for function 'unsafeSxfun'
//

// Include files
#include "unsafeSxfun.h"
#include "RATMain_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::array<
                        double, 2U> &in3, int in4, int in5, const ::coder::array<
                        double, 2U> &in6, int in7, int in8, const ::coder::array<
                        double, 2U> &in9)
  {
    ::coder::array<double, 2U> b_in3;
    int aux_0_1;
    int aux_1_1;
    int aux_2_1;
    int b_loop_ub;
    int loop_ub;
    int stride_0_0;
    int stride_0_1;
    int stride_1_0;
    int stride_1_1;
    int stride_2_0;
    int stride_2_1;
    if (in9.size(0) == 1) {
      if (in7 + 1 == 1) {
        loop_ub = in4 + 1;
      } else {
        loop_ub = in7 + 1;
      }
    } else {
      loop_ub = in9.size(0);
    }

    if (in9.size(1) == 1) {
      if (in8 + 1 == 1) {
        b_loop_ub = in5 + 1;
      } else {
        b_loop_ub = in8 + 1;
      }
    } else {
      b_loop_ub = in9.size(1);
    }

    b_in3.set_size(loop_ub, b_loop_ub);
    stride_0_0 = (in4 + 1 != 1);
    stride_0_1 = (in5 + 1 != 1);
    stride_1_0 = (in7 + 1 != 1);
    stride_1_1 = (in8 + 1 != 1);
    stride_2_0 = (in9.size(0) != 1);
    stride_2_1 = (in9.size(1) != 1);
    aux_0_1 = 0;
    aux_1_1 = 0;
    aux_2_1 = 0;
    for (int i{0}; i < b_loop_ub; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        b_in3[i1 + b_in3.size(0) * i] = (in3[i1 * stride_0_0 + in3.size(0) *
          aux_0_1] - in6[i1 * stride_1_0 + in6.size(0) * aux_1_1]) / in9[i1 *
          stride_2_0 + in9.size(0) * aux_2_1];
      }

      aux_2_1 += stride_2_1;
      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }

    in1.set_size(b_in3.size(0), b_in3.size(1));
    loop_ub = b_in3.size(1);
    for (int i{0}; i < loop_ub; i++) {
      b_loop_ub = b_in3.size(0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        double varargin_1;
        varargin_1 = b_in3[i1 + b_in3.size(0) * i];
        in1[i1 + in1.size(0) * i] = rt_powd_snf(varargin_1, 2.0);
      }
    }
  }

  void binary_expand_op(::coder::array<double, 1U> &in1, const ::coder::array<
                        double, 2U> &in3, const ::coder::array<double, 2U> &in4)
  {
    ::coder::array<double, 1U> b_in3;
    int loop_ub;
    int stride_0_0_tmp;
    int stride_1_0;
    if (in3.size(0) == 1) {
      if (in4.size(0) == 1) {
        loop_ub = in3.size(0);
      } else {
        loop_ub = in4.size(0);
      }
    } else {
      loop_ub = in3.size(0);
    }

    b_in3.set_size(loop_ub);
    stride_0_0_tmp = (in3.size(0) != 1);
    stride_1_0 = (in4.size(0) != 1);
    for (int i{0}; i < loop_ub; i++) {
      int in3_tmp;
      in3_tmp = i * stride_0_0_tmp;
      b_in3[i] = (in3[in3_tmp + in3.size(0)] - in4[i * stride_1_0 + in4.size(0)])
        / in3[in3_tmp + in3.size(0) * 2];
    }

    in1.set_size(b_in3.size(0));
    loop_ub = b_in3.size(0);
    for (int i{0}; i < loop_ub; i++) {
      double varargin_1;
      varargin_1 = b_in3[i];
      in1[i] = varargin_1 * varargin_1;
    }
  }
}

// End of code generation (unsafeSxfun.cpp)
