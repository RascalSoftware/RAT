//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: data_resolution_polly.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "data_resolution_polly.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Apply resolution correction
//
// Arguments    : const ::coder::array<real_T, 1U> &xdata
//                const ::coder::array<real_T, 1U> &ydata
//                const ::coder::array<real_T, 1U> &resData
//                real_T points
//                ::coder::array<real_T, 1U> &out
// Return Type  : void
//
namespace RAT
{
  void data_resolution_polly(const ::coder::array<real_T, 1U> &xdata, const ::
    coder::array<real_T, 1U> &ydata, const ::coder::array<real_T, 1U> &resData,
    real_T points, ::coder::array<real_T, 1U> &out)
  {
    int32_T i;
    int32_T loop_ub_tmp;
    loop_ub_tmp = static_cast<int32_T>(points);
    out.set_size(loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      out[i] = 0.0;
    }

    for (int32_T j{0}; j < loop_ub_tmp; j++) {
      real_T a;
      real_T sumg;
      int32_T ilow;
      sumg = 0.0;
      out[j] = 0.0;
      if (static_cast<uint32_T>(j) + 1U > 10U) {
        ilow = -10;
      } else {
        ilow = static_cast<int32_T>(-(static_cast<real_T>(j) + 1.0)) + 1;
      }

      if (static_cast<real_T>(j) + 1.0 < points - 10.0) {
        a = 10.0;
      } else {
        a = points - (static_cast<real_T>(j) + 1.0);
      }

      i = static_cast<int32_T>(a + (1.0 - static_cast<real_T>(ilow)));
      for (int32_T b_i{0}; b_i < i; b_i++) {
        real_T g;
        int32_T a_tmp;
        a_tmp = static_cast<int32_T>((static_cast<real_T>(j) + 1.0) +
          static_cast<real_T>(ilow + b_i)) - 1;
        a = (xdata[a_tmp] - xdata[j]) / (resData[j] * xdata[j]);
        g = std::exp(-(a * a));
        sumg += g;
        out[j] = out[j] + ydata[a_tmp] * g;
      }

      if (sumg != 0.0) {
        out[j] = out[j] / sumg;
      }
    }
  }
}

//
// File trailer for data_resolution_polly.cpp
//
// [EOF]
//
