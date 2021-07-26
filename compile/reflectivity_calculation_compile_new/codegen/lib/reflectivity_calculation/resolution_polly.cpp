//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// resolution_polly.cpp
//
// Code generation for function 'resolution_polly'
//

// Include files
#include "resolution_polly.h"
#include "exp.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
void resolution_polly(const coder::array<double, 1U> &xdata,
                      const coder::array<double, 1U> &ydata, double res,
                      double points, coder::array<double, 1U> &out)
{
  double g;
  int i;
  int loop_ub_tmp;
  res += 0.0001;
  loop_ub_tmp = static_cast<int>(points);
  out.set_size(loop_ub_tmp);
  for (i = 0; i < loop_ub_tmp; i++) {
    out[i] = 0.0;
  }
  for (int j{0}; j < loop_ub_tmp; j++) {
    double sumg;
    int ilow;
    sumg = 0.0;
    out[j] = 0.0;
    if (j + 1U > 10U) {
      ilow = -10;
    } else {
      ilow = static_cast<int>(-(static_cast<double>(j) + 1.0)) + 1;
    }
    //     try
    if (static_cast<double>(j) + 1.0 < points - 10.0) {
      g = 10.0;
    } else {
      g = points - (static_cast<double>(j) + 1.0);
    }
    i = static_cast<int>(g + (1.0 - static_cast<double>(ilow)));
    for (int b_i{0}; b_i < i; b_i++) {
      int a_tmp;
      a_tmp = static_cast<int>((static_cast<double>(j) + 1.0) +
                               static_cast<double>(ilow + b_i)) -
              1;
      g = (xdata[a_tmp] - xdata[j]) / (res * xdata[j]);
      g = -(g * g);
      coder::b_exp(&g);
      sumg += g;
      out[j] = out[j] + ydata[a_tmp] * g;
    }
    if (sumg != 0.0) {
      out[j] = out[j] / sumg;
    }
  }
}

// End of code generation (resolution_polly.cpp)
