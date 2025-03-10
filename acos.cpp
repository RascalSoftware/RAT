//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// acos.cpp
//
// Code generation for function 'acos'
//

// Include files
#include "acos.h"
#include "asinh.h"
#include "complexTimes.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "rt_defines.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  static double rt_atan2d_snf(double u0, double u1);
}

// Function Definitions
namespace RAT
{
  static double rt_atan2d_snf(double u0, double u1)
  {
    double y;
    if (std::isnan(u0) || std::isnan(u1)) {
      y = rtNaN;
    } else if (std::isinf(u0) && std::isinf(u1)) {
      int i;
      int i1;
      if (u0 > 0.0) {
        i = 1;
      } else {
        i = -1;
      }

      if (u1 > 0.0) {
        i1 = 1;
      } else {
        i1 = -1;
      }

      y = std::atan2(static_cast<double>(i), static_cast<double>(i1));
    } else if (u1 == 0.0) {
      if (u0 > 0.0) {
        y = RT_PI / 2.0;
      } else if (u0 < 0.0) {
        y = -(RT_PI / 2.0);
      } else {
        y = 0.0;
      }
    } else {
      y = std::atan2(u0, u1);
    }

    return y;
  }

  namespace coder
  {
    namespace internal
    {
      namespace scalar
      {
        void b_acos(creal_T *x)
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
            d_sqrt(&v);
            u.re = 1.0 - x->re;
            u.im = 0.0 - x->im;
            d_sqrt(&u);
            d = complexTimes(v.re, -v.im, u.re, u.im);
            b_asinh(d);
            x->re = 2.0 * rt_atan2d_snf(u.re, v.re);
            x->im = d;
          }
        }
      }
    }
  }
}

// End of code generation (acos.cpp)
