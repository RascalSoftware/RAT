//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// minOrMax.cpp
//
// Code generation for function 'minOrMax'
//

// Include files
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace coder {
namespace internal {
double maximum(const double x_data[])
{
  double ex;
  int idx;
  int k;
  if (!std::isnan(x_data[0])) {
    idx = 1;
  } else {
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 102)) {
      if (!std::isnan(x_data[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    ex = x_data[0];
  } else {
    ex = x_data[idx - 1];
    idx++;
    for (k = idx; k < 102; k++) {
      double d;
      d = x_data[k - 1];
      if (ex < d) {
        ex = d;
      }
    }
  }
  return ex;
}

void maximum(const ::coder::array<double, 2U> &x, double ex[2])
{
  int m;
  m = x.size(0);
  for (int j{0}; j < 2; j++) {
    ex[j] = x[x.size(0) * j];
    for (int i{2}; i <= m; i++) {
      double b;
      boolean_T p;
      b = x[(i + x.size(0) * j) - 1];
      if (std::isnan(b)) {
        p = false;
      } else if (std::isnan(ex[j])) {
        p = true;
      } else {
        p = (ex[j] < b);
      }
      if (p) {
        ex[j] = b;
      }
    }
  }
}

void minimum(const ::coder::array<double, 2U> &x, double ex[2])
{
  int m;
  m = x.size(0);
  for (int j{0}; j < 2; j++) {
    ex[j] = x[x.size(0) * j];
    for (int i{2}; i <= m; i++) {
      double b;
      boolean_T p;
      b = x[(i + x.size(0) * j) - 1];
      if (std::isnan(b)) {
        p = false;
      } else if (std::isnan(ex[j])) {
        p = true;
      } else {
        p = (ex[j] > b);
      }
      if (p) {
        ex[j] = b;
      }
    }
  }
}

} // namespace internal
} // namespace coder

// End of code generation (minOrMax.cpp)
