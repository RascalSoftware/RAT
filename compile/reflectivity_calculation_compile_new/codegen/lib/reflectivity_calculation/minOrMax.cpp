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
#include "isnan.h"
#include "relop.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
namespace internal {
double b_maximum(const double x[2])
{
  double ex;
  if ((x[0] < x[1]) || (b_isnan(x[0]) && (!b_isnan(x[1])))) {
    ex = x[1];
  } else {
    ex = x[0];
  }
  return ex;
}

double maximum(const double x_data[])
{
  double ex;
  int idx;
  int k;
  if (!b_isnan(x_data[0])) {
    idx = 1;
  } else {
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 102)) {
      if (!b_isnan(x_data[k - 1])) {
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
      double d;
      d = x[(i + x.size(0) * j) - 1];
      if (relop(ex[j], d)) {
        ex[j] = d;
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
      double d;
      d = x[(i + x.size(0) * j) - 1];
      if (b_relop(ex[j], d)) {
        ex[j] = d;
      }
    }
  }
}

} // namespace internal
} // namespace coder

// End of code generation (minOrMax.cpp)
