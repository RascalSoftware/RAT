//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// resolution_polly_paraPoints.cpp
//
// Code generation for function 'resolution_polly_paraPoints'
//

// Include files
#include "resolution_polly_paraPoints.h"
#include "exp.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
void resolution_polly_paraPoints(const coder::array<double, 1U> &xdata,
                                 const coder::array<double, 1U> &ydata,
                                 double res, double points,
                                 coder::array<double, 1U> &out)
{
  double g;
  double sumg;
  int b_i;
  int c_i;
  int i1;
  int ilow;
  int j;
  int loop_ub_tmp;
  res += 0.0001;
  loop_ub_tmp = static_cast<int>(points);
  out.set_size(loop_ub_tmp);
  for (int i{0}; i < loop_ub_tmp; i++) {
    out[i] = 0.0;
  }
  loop_ub_tmp = static_cast<int>(points) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    g, b_i, ilow, sumg, j, i1, c_i)

  for (j = 0; j <= loop_ub_tmp; j++) {
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
      b_i = static_cast<int>((static_cast<double>(j) + 1.0) +
                             static_cast<double>(b_i)) -
            1;
      g = (xdata[b_i] - xdata[j]) / (res * xdata[j]);
      g = -(g * g);
      coder::b_exp(&g);
      sumg += g;
      out[j] = out[j] + ydata[b_i] * g;
    }
    if (sumg != 0.0) {
      out[j] = out[j] / sumg;
    }
    //      catch
    //          disp('debug!');
    //      end
  }
}

// End of code generation (resolution_polly_paraPoints.cpp)
