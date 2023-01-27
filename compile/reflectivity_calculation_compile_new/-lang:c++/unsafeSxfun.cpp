//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: unsafeSxfun.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "unsafeSxfun.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : ::coder::array<real_T, 1U> &in1
//                const real_T in3_data[]
//                const int32_T in3_size[2]
//                const ::coder::array<real_T, 2U> &in4
// Return Type  : void
//
namespace RAT
{
  void binary_expand_op(::coder::array<real_T, 1U> &in1, const real_T in3_data[],
                        const int32_T in3_size[2], const ::coder::array<real_T,
                        2U> &in4)
  {
    ::coder::array<real_T, 1U> in3;
    int32_T i;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    int32_T stride_2_0;
    if (in3_size[0] == 1) {
      if (in4.size(0) == 1) {
        i = in3_size[0];
      } else {
        i = in4.size(0);
      }
    } else {
      i = in3_size[0];
    }

    in3.set_size(i);
    stride_0_0 = (in3_size[0] != 1);
    stride_1_0 = (in4.size(0) != 1);
    stride_2_0 = (in3_size[0] != 1);
    if (in3_size[0] == 1) {
      if (in4.size(0) == 1) {
        loop_ub = in3_size[0];
      } else {
        loop_ub = in4.size(0);
      }
    } else {
      loop_ub = in3_size[0];
    }

    for (i = 0; i < loop_ub; i++) {
      in3[i] = (in3_data[i * stride_0_0 + in3_size[0]] - in4[i * stride_1_0 +
                in4.size(0)]) / in3_data[i * stride_2_0 + in3_size[0] * 2];
    }

    in1.set_size(in3.size(0));
    loop_ub = in3.size(0);
    for (i = 0; i < loop_ub; i++) {
      real_T varargin_1;
      varargin_1 = in3[i];
      in1[i] = varargin_1 * varargin_1;
    }
  }
}

//
// File trailer for unsafeSxfun.cpp
//
// [EOF]
//
