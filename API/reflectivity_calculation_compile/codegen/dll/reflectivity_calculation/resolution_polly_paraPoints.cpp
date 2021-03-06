//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: resolution_polly_paraPoints.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 24-Feb-2021 09:21:20
//

// Include Files
#include "resolution_polly_paraPoints.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"
#include "standardTF_stanLay_reflectivityCalculation.h"
#include <math.h>

// Function Definitions

//
// Arguments    : const coder::array<double, 1U> *xdata
//                const coder::array<double, 1U> *ydata
//                double res
//                double points
//                coder::array<double, 1U> *out
// Return Type  : void
//
void resolution_polly_paraPoints(const coder::array<double, 1U> &xdata, const
  coder::array<double, 1U> &ydata, double res, double points, coder::array<
  double, 1U> &out)
{
  int loop_ub;
  int i;
  coder::array<double, 1U> dummyref;
  int b_loop_ub;
  double g;
  int b_i;
  int ilow;
  double sumg;
  int i1;
  int c_i;
  res += 0.0001;
  loop_ub = static_cast<int>(points);
  out.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    out[i] = 0.0;
  }

  dummyref.set_size(ydata.size(0));
  b_loop_ub = ydata.size(0);
  for (i = 0; i < b_loop_ub; i++) {
    dummyref[i] = ydata[i];
  }

  loop_ub--;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(g,b_i,ilow,sumg,i1,c_i)

  for (int j = 0; j <= loop_ub; j++) {
    sumg = 0.0;
    out[j] = 0.0;
    if (j + 1U > 10U) {
      ilow = -10;
    } else {
      ilow = static_cast<int>(-(static_cast<double>(j) + 1.0)) + 1;
    }

    if (static_cast<double>(j) + 1.0 < points - 10.0) {
      g = 10.0;
    } else {
      g = points - (static_cast<double>(j) + 1.0);
    }

    //     try
    i1 = static_cast<int>(g + (1.0 - static_cast<double>(ilow)));
    for (c_i = 0; c_i < i1; c_i++) {
      b_i = ilow + c_i;
      b_i = static_cast<int>((static_cast<double>(j) + 1.0) + static_cast<double>
        (b_i)) - 1;
      g = (xdata[b_i] - xdata[j]) / (res * xdata[j]);
      g = exp(-(g * g));
      sumg += g;
      out[j] = out[j] + dummyref[b_i] * g;
    }

    if (sumg != 0.0) {
      out[j] = out[j] / sumg;
    }

    //      catch
    //          disp('debug!');
    //      end
  }
}

//
// File trailer for resolution_polly_paraPoints.cpp
//
// [EOF]
//
