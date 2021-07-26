//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// colon.cpp
//
// Code generation for function 'colon'
//

// Include files
#include "colon.h"
#include "abs.h"
#include "floor1.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace coder {
static void float_colon_length(double a, double d, double b, int *n,
                               double *anew, double *bnew,
                               boolean_T *n_too_large);

static double maxabs(double a, double b);

} // namespace coder

// Function Definitions
namespace coder {
static void float_colon_length(double a, double d, double b, int *n,
                               double *anew, double *bnew,
                               boolean_T *n_too_large)
{
  double cdiff;
  double ndbl;
  *anew = a;
  ndbl = (b - a) / d + 0.5;
  b_floor(&ndbl);
  *bnew = a + ndbl * d;
  if (d > 0.0) {
    cdiff = *bnew - b;
  } else {
    cdiff = b - *bnew;
  }
  if (b_abs(cdiff) < 4.4408920985006262E-16 * maxabs(a, b)) {
    ndbl++;
    *bnew = b;
  } else if (cdiff > 0.0) {
    *bnew = a + (ndbl - 1.0) * d;
  } else {
    ndbl++;
  }
  *n_too_large = (ndbl > 2.147483647E+9);
  if (ndbl >= 0.0) {
    *n = static_cast<int>(std::floor(ndbl));
  } else {
    *n = 0;
  }
}

static double maxabs(double a, double b)
{
  return std::fmax(b_abs(a), b_abs(b));
}

void eml_float_colon(double a, double d, double b,
                     ::coder::array<double, 2U> &y)
{
  double a1;
  double b1;
  int n;
  boolean_T n_too_large;
  float_colon_length(a, d, b, &n, &a1, &b1, &n_too_large);
  y.set_size(1, n);
  if (n > 0) {
    y[0] = a1;
    if (n > 1) {
      double kd;
      int nm1d2;
      y[n - 1] = b1;
      nm1d2 = (n - 1) / 2;
      for (int k{0}; k <= nm1d2 - 2; k++) {
        kd = (static_cast<double>(k) + 1.0) * d;
        y[k + 1] = a1 + kd;
        y[(n - k) - 2] = b1 - kd;
      }
      if (nm1d2 << 1 == n - 1) {
        y[nm1d2] = (a1 + b1) / 2.0;
      } else {
        kd = static_cast<double>(nm1d2) * d;
        y[nm1d2] = a1 + kd;
        y[nm1d2 + 1] = b1 - kd;
      }
    }
  }
}

} // namespace coder

// End of code generation (colon.cpp)
