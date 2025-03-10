//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// div.cpp
//
// Code generation for function 'div'
//

// Include files
#include "div.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void rdivide(::coder::array<double, 1U> &in1, const ::coder::array<double, 1U>
               &in2, const ::coder::array<double, 1U> &in3)
  {
    int loop_ub;
    int stride_0_0;
    int stride_1_0;
    if (in3.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in3.size(0);
    }

    in1.set_size(loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_1_0 = (in3.size(0) != 1);
    for (int i{0}; i < loop_ub; i++) {
      in1[i] = in2[i * stride_0_0] / in3[i * stride_1_0];
    }
  }
}

// End of code generation (div.cpp)
