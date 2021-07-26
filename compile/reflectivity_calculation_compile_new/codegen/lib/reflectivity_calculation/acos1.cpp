//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// acos1.cpp
//
// Code generation for function 'acos1'
//

// Include files
#include "acos1.h"
#include "asinh.h"
#include "atan2.h"
#include "complexTimes.h"
#include "rt_nonfinite.h"
#include "sqrt1.h"
#include <cmath>

// Function Definitions
namespace coder {
namespace internal {
namespace scalar {
void c_acos(creal_T *x)
{
  creal_T u;
  creal_T v;
  double d;
  if ((x->im == 0.0) && (!(std::abs(x->re) > 1.0))) {
    x->re = std::acos(x->re);
    x->im = 0.0;
  } else {
    v.re = x->re + 1.0;
    v.im = x->im;
    c_sqrt(&v);
    u.re = 1.0 - x->re;
    u.im = 0.0 - x->im;
    c_sqrt(&u);
    d = complexTimes(v.re, -v.im, u.re, u.im);
    b_asinh(&d);
    x->re = 2.0 * b_atan2(u.re, v.re);
    x->im = d;
  }
}

} // namespace scalar
} // namespace internal
} // namespace coder

// End of code generation (acos1.cpp)
