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
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace coder {
void eml_float_colon(double a, double d, double b,
                     ::coder::array<double, 2U> &y)
{
  double apnd;
  double cdiff;
  double ndbl;
  int n;
  ndbl = std::floor((b - a) / d + 0.5);
  apnd = a + ndbl * d;
  if (d > 0.0) {
    cdiff = apnd - b;
  } else {
    cdiff = b - apnd;
  }
  if (std::abs(cdiff) <
      4.4408920985006262E-16 * std::fmax(std::abs(a), std::abs(b))) {
    ndbl++;
    apnd = b;
  } else if (cdiff > 0.0) {
    apnd = a + (ndbl - 1.0) * d;
  } else {
    ndbl++;
  }
  if (ndbl >= 0.0) {
    n = static_cast<int>(ndbl);
  } else {
    n = 0;
  }
  y.set_size(1, n);
  if (n > 0) {
    y[0] = a;
    if (n > 1) {
      int nm1d2;
      y[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (int k{0}; k <= nm1d2 - 2; k++) {
        ndbl = (static_cast<double>(k) + 1.0) * d;
        y[k + 1] = a + ndbl;
        y[(n - k) - 2] = apnd - ndbl;
      }
      if (nm1d2 << 1 == n - 1) {
        y[nm1d2] = (a + apnd) / 2.0;
      } else {
        ndbl = static_cast<double>(nm1d2) * d;
        y[nm1d2] = a + ndbl;
        y[nm1d2 + 1] = apnd - ndbl;
      }
    }
  }
}

} // namespace coder

// End of code generation (colon.cpp)
