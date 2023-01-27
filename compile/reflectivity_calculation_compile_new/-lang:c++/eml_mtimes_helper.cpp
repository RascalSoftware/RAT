//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: eml_mtimes_helper.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "eml_mtimes_helper.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : ::coder::array<real_T, 2U> &in1
//                real_T in2
//                const ::coder::array<real_T, 2U> &in3
//                const ::coder::array<real_T, 2U> &in4
// Return Type  : void
//
namespace RAT
{
  void binary_expand_op(::coder::array<real_T, 2U> &in1, real_T in2, const ::
                        coder::array<real_T, 2U> &in3, const ::coder::array<
                        real_T, 2U> &in4)
  {
    int32_T i;
    int32_T loop_ub;
    int32_T stride_0_1;
    int32_T stride_1_1;
    if (in4.size(1) == 1) {
      i = in3.size(1);
    } else {
      i = in4.size(1);
    }

    in1.set_size(1, i);
    stride_0_1 = (in3.size(1) != 1);
    stride_1_1 = (in4.size(1) != 1);
    if (in4.size(1) == 1) {
      loop_ub = in3.size(1);
    } else {
      loop_ub = in4.size(1);
    }

    for (i = 0; i < loop_ub; i++) {
      in1[i] = in2 * (in3[i * stride_0_1] - in4[i * stride_1_1]);
    }
  }

  //
  // Arguments    : ::coder::array<real_T, 2U> &in1
  //                const ::coder::array<real_T, 2U> &in3
  //                const ::coder::array<int32_T, 1U> &in4
  //                const ::coder::array<int32_T, 1U> &in5
  // Return Type  : void
  //
  void binary_expand_op(::coder::array<real_T, 2U> &in1, const ::coder::array<
                        real_T, 2U> &in3, const ::coder::array<int32_T, 1U> &in4,
                        const ::coder::array<int32_T, 1U> &in5)
  {
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    stride_0_0 = (in4.size(0) != 1);
    stride_1_0 = (in5.size(0) != 1);
    if (in5.size(0) == 1) {
      loop_ub = in4.size(0);
    } else {
      loop_ub = in5.size(0);
    }

    for (int32_T i{0}; i < loop_ub; i++) {
      in1[i] = 0.5 * (in3[in4[i * stride_0_0] - 1] + in3[in5[i * stride_1_0] - 1]);
    }
  }
}

//
// File trailer for eml_mtimes_helper.cpp
//
// [EOF]
//
