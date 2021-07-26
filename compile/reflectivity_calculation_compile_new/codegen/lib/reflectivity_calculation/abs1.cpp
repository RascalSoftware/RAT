//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// abs1.cpp
//
// Code generation for function 'abs1'
//

// Include files
#include "abs1.h"
#include "rt_nonfinite.h"
#include "xdlapy2.h"
#include <cmath>

// Function Definitions
namespace coder {
namespace internal {
namespace scalar {
int c_abs(int x)
{
  return x;
}

double c_abs(const creal_T x)
{
  return xdlapy2(x.re, x.im);
}

double c_abs(double x)
{
  return std::abs(x);
}

} // namespace scalar
} // namespace internal
} // namespace coder

// End of code generation (abs1.cpp)
