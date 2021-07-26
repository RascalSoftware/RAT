//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// asinh.cpp
//
// Code generation for function 'asinh'
//

// Include files
#include "asinh.h"
#include "log1p.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Declarations
namespace coder {
namespace internal {
namespace scalar {
static void eml_asinh(double *x);

}
} // namespace internal
} // namespace coder

// Function Definitions
namespace coder {
namespace internal {
namespace scalar {
static void eml_asinh(double *x)
{
  boolean_T xneg;
  xneg = (*x < 0.0);
  if (xneg) {
    *x = -*x;
  }
  if (*x >= 2.68435456E+8) {
    *x = std::log(*x) + 0.69314718055994529;
  } else if (*x > 2.0) {
    *x = std::log(2.0 * *x + 1.0 / (std::sqrt(*x * *x + 1.0) + *x));
  } else {
    double t;
    t = *x * *x;
    *x += t / (std::sqrt(t + 1.0) + 1.0);
    b_log1p(x);
  }
  if (xneg) {
    *x = -*x;
  }
}

void b_asinh(double *x)
{
  eml_asinh(x);
}

} // namespace scalar
} // namespace internal
} // namespace coder

// End of code generation (asinh.cpp)
