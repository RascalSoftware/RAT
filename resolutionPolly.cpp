//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// resolutionPolly.cpp
//
// Code generation for function 'resolutionPolly'
//

// Include files
#include "resolutionPolly.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void resolutionPolly(const ::coder::array<real_T, 1U> &xdata, const ::coder::
                       array<real_T, 1U> &ydata, const ::coder::array<real_T, 1U>
                       &resolutionValues, real_T points, ::coder::array<real_T,
                       1U> &resolutionCorrection)
  {
    int32_T i;
    int32_T loop_ub_tmp;

    //  Apply resolution correction
    loop_ub_tmp = static_cast<int32_T>(points);
    resolutionCorrection.set_size(loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      resolutionCorrection[i] = 0.0;
    }

    for (int32_T j{0}; j < loop_ub_tmp; j++) {
      real_T sumg;
      int32_T ilow;
      sumg = 0.0;
      ilow = static_cast<int32_T>(std::fmax(-10.0, -(static_cast<real_T>(j) +
        1.0) + 1.0));
      i = static_cast<int32_T>(std::fmin(10.0, points - (static_cast<real_T>(j)
        + 1.0)) + (1.0 - static_cast<real_T>(ilow)));
      for (int32_T b_i{0}; b_i < i; b_i++) {
        real_T a;
        real_T g;
        int32_T a_tmp;
        a_tmp = static_cast<int32_T>((static_cast<real_T>(j) + 1.0) +
          static_cast<real_T>(ilow + b_i)) - 1;
        a = (xdata[a_tmp] - xdata[j]) / (resolutionValues[j] * xdata[j]);
        g = std::exp(-(a * a));
        sumg += g;
        resolutionCorrection[j] = resolutionCorrection[j] + ydata[a_tmp] * g;
      }

      if (sumg != 0.0) {
        resolutionCorrection[j] = resolutionCorrection[j] / sumg;
      }
    }
  }
}

// End of code generation (resolutionPolly.cpp)
