//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// acos.cpp
//
// Code generation for function 'acos'
//

// Include files
#include "acos.h"
#include "RATMain_rtwutil.h"
#include "asinh.h"
#include "complexTimes.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include <cmath>

// Function Definitions
namespace RAT
{
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
            b_asinh(&d);
            x->re = 2.0 * rt_atan2d_snf(u.re, v.re);
            x->im = d;
          }
        }
      }
    }
  }
}

// End of code generation (acos.cpp)
