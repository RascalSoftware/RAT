//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// eml_mtimes_helper.cpp
//
// Code generation for function 'eml_mtimes_helper'
//

// Include files
#include "eml_mtimes_helper.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void binary_expand_op(double in1_data[], const ::coder::array<double, 2U> &in2,
                        const ::coder::array<double, 2U> &in3, int in4, const ::
                        coder::array<double, 2U> &in5, int in1_size[2])
  {
    ::coder::array<double, 2U> b_in3;
    int loop_ub;
    int stride_0_1;
    int stride_1_1;
    if (in5.size(1) == 1) {
      loop_ub = in3.size(1);
    } else {
      loop_ub = in5.size(1);
    }

    b_in3.set_size(1, loop_ub);
    stride_0_1 = (in3.size(1) != 1);
    stride_1_1 = (in5.size(1) != 1);
    for (int i{0}; i < loop_ub; i++) {
      b_in3[b_in3.size(0) * i] = in3[in4 + in3.size(0) * (i * stride_0_1)] -
        in5[in5.size(0) * (i * stride_1_1)];
    }

    coder::internal::blas::mtimes(in2, b_in3, in1_data, in1_size);
  }

  void binary_expand_op(::coder::array<creal_T, 2U> &in1, const ::coder::array<
                        double, 2U> &in2, const ::coder::array<creal_T, 1U> &in3,
                        const ::coder::array<creal_T, 2U> &in4)
  {
    ::coder::array<creal_T, 2U> b_in2;
    int loop_ub;
    int stride_0_1;
    int stride_1_1;
    if (in3.size(0) == 1) {
      loop_ub = in2.size(1);
    } else {
      loop_ub = in3.size(0);
    }

    b_in2.set_size(1, loop_ub);
    stride_0_1 = (in2.size(1) != 1);
    stride_1_1 = (in3.size(0) != 1);
    for (int i{0}; i < loop_ub; i++) {
      double d;
      int in3_re_tmp;
      in3_re_tmp = i * stride_1_1;
      d = in2[i * stride_0_1];
      b_in2[i].re = d * in3[in3_re_tmp].re;
      b_in2[i].im = d * -in3[in3_re_tmp].im;
    }

    coder::internal::blas::mtimes(b_in2, in4, in1);
  }

  void binary_expand_op(::coder::array<double, 2U> &in1, double in2, const ::
                        coder::array<double, 2U> &in3, const ::coder::array<
                        double, 2U> &in4)
  {
    int loop_ub;
    int stride_0_1;
    int stride_1_1;
    in1.set_size(1, in1.size(1));
    if (in4.size(1) == 1) {
      loop_ub = in3.size(1);
    } else {
      loop_ub = in4.size(1);
    }

    in1.set_size(in1.size(0), loop_ub);
    stride_0_1 = (in3.size(1) != 1);
    stride_1_1 = (in4.size(1) != 1);
    for (int i{0}; i < loop_ub; i++) {
      in1[i] = in2 * (in3[i * stride_0_1] - in4[i * stride_1_1]);
    }
  }

  void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::array<
                        double, 2U> &in2, const ::coder::array<double, 2U> &in3)
  {
    int loop_ub;
    int stride_0_1;
    int stride_1_1;
    in1.set_size(1, in1.size(1));
    if (in3.size(1) == 1) {
      loop_ub = in2.size(1);
    } else {
      loop_ub = in3.size(1);
    }

    in1.set_size(in1.size(0), loop_ub);
    stride_0_1 = (in2.size(1) != 1);
    stride_1_1 = (in3.size(1) != 1);
    for (int i{0}; i < loop_ub; i++) {
      in1[i] = 0.0 * (in2[i * stride_0_1] - in3[i * stride_1_1]);
    }
  }

  void c_binary_expand_op(double in1_data[], const ::coder::array<double, 2U>
    &in2, const ::coder::array<double, 2U> &in3, int in4, const ::coder::array<
    double, 2U> &in5, int in1_size[2])
  {
    ::coder::array<double, 2U> b_in3;
    int aux_0_1;
    int aux_1_1;
    int loop_ub;
    int stride_0_1;
    int stride_1_1;
    if (in5.size(1) == 1) {
      loop_ub = in3.size(1);
    } else {
      loop_ub = in5.size(1);
    }

    b_in3.set_size(in5.size(0), loop_ub);
    stride_0_1 = (in3.size(1) != 1);
    stride_1_1 = (in5.size(1) != 1);
    aux_0_1 = 0;
    aux_1_1 = 0;
    for (int i{0}; i < loop_ub; i++) {
      int b_loop_ub;
      b_loop_ub = in5.size(0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        b_in3[b_in3.size(0) * i] = in3[in4 + in3.size(0) * aux_0_1] -
          in5[in5.size(0) * aux_1_1];
      }

      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }

    coder::internal::blas::mtimes(in2, b_in3, in1_data, in1_size);
  }
}

// End of code generation (eml_mtimes_helper.cpp)
