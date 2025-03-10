//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// cat.cpp
//
// Code generation for function 'cat'
//

// Include files
#include "cat.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::array<
                        double, 2U> &in2, const ::coder::array<double, 2U> &in3,
                        double in4, const ::coder::array<double, 2U> &in5)
  {
    ::coder::array<double, 1U> b_in3;
    double in3_tmp;
    int loop_ub;
    int stride_0_0;
    int stride_1_0;
    in3_tmp = in3[static_cast<int>(in4) - 1];
    if (in5.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in5.size(0);
    }

    b_in3.set_size(loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_1_0 = (in5.size(0) != 1);
    for (int i{0}; i < loop_ub; i++) {
      b_in3[i] = in3_tmp * in2[i * stride_0_0 + in2.size(0)] + (1.0 - in3_tmp) *
        in5[i * stride_1_0 + in5.size(0)];
    }

    in1.set_size(in2.size(0), 2);
    loop_ub = in2.size(0);
    for (int i{0}; i < loop_ub; i++) {
      in1[i] = in2[i];
    }

    loop_ub = b_in3.size(0);
    for (int i{0}; i < loop_ub; i++) {
      in1[i + in1.size(0)] = b_in3[i];
    }
  }
}

// End of code generation (cat.cpp)
