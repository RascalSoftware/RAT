//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xdlapy2.cpp
//
// Code generation for function 'xdlapy2'
//

// Include files
#include "xdlapy2.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Declarations
static double rt_hypotd_snf(double u0, double u1);

// Function Definitions
static double rt_hypotd_snf(double u0, double u1)
{
  double a;
  double y;
  a = std::abs(u0);
  y = std::abs(u1);
  if (a < y) {
    a /= y;
    y *= std::sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = a * std::sqrt(y * y + 1.0);
  } else if (!std::isnan(y)) {
    y = a * 1.4142135623730951;
  }
  return y;
}

namespace coder {
namespace internal {
double xdlapy2(double x1, double x2)
{
  return rt_hypotd_snf(x1, x2);
}

} // namespace internal
} // namespace coder

// End of code generation (xdlapy2.cpp)
