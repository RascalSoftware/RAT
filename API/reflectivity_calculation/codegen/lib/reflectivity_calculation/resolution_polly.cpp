//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: resolution_polly.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//

// Include Files
#include "resolution_polly.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"
#include "standardTF_custXY_reflectivityCalculation.h"
#include <math.h>

// Function Definitions

//
// Arguments    : const coder::array<double, 2U> *xdata
//                const coder::array<double, 1U> *ydata
//                double res
//                double points
//                coder::array<double, 1U> *out
// Return Type  : void
//
void resolution_polly(const coder::array<double, 2U> &xdata, const coder::array<
                      double, 1U> &ydata, double res, double points, coder::
                      array<double, 1U> &out)
{
  int loop_ub;
  int i;
  double sumg;
  res += 0.0001;
  loop_ub = static_cast<int>(points);
  out.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    out[i] = 0.0;
  }

  for (int j = 0; j < loop_ub; j++) {
    int ilow;
    double g;
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
    for (int b_i = 0; b_i < i; b_i++) {
      int a_tmp;
      a_tmp = static_cast<int>((static_cast<double>(j) + 1.0) + static_cast<
        double>(ilow + b_i)) - 1;
      g = (xdata[a_tmp] - xdata[j]) / (res * xdata[j]);
      g = exp(-(g * g));
      sumg += g;
      out[j] = out[j] + ydata[a_tmp] * g;
    }

    if (sumg != 0.0) {
      out[j] = out[j] / sumg;
    }
  }
}

//
// File trailer for resolution_polly.cpp
//
// [EOF]
//
