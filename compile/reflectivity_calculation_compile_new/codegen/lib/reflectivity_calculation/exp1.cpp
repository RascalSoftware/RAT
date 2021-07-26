//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// exp1.cpp
//
// Code generation for function 'exp1'
//

// Include files
#include "exp1.h"
#include "isinf.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace coder {
namespace internal {
namespace scalar {
void c_exp(creal_T *x)
{
  if (x->im == 0.0) {
    x->re = std::exp(x->re);
    x->im = 0.0;
  } else if (b_isinf(x->im) && b_isinf(x->re) && (x->re < 0.0)) {
    x->re = 0.0;
    x->im = 0.0;
  } else {
    double d;
    double r;
    r = std::exp(x->re / 2.0);
    d = x->im;
    x->re = r * (r * std::cos(x->im));
    x->im = r * (r * std::sin(d));
  }
}

void c_exp(double *x)
{
  *x = std::exp(*x);
}

} // namespace scalar
} // namespace internal
} // namespace coder

// End of code generation (exp1.cpp)
