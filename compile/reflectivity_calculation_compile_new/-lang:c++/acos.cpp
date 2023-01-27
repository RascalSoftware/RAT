//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: acos.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
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
  static real_T rt_atan2d_snf(real_T u0, real_T u1);
}

// Function Definitions
//
// Arguments    : real_T u0
//                real_T u1
// Return Type  : real_T
//
namespace RAT
{
  static real_T rt_atan2d_snf(real_T u0, real_T u1)
  {
    real_T y;
    if (std::isnan(u0) || std::isnan(u1)) {
      y = rtNaN;
    } else if (std::isinf(u0) && std::isinf(u1)) {
      int32_T i;
      int32_T i1;
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

      y = std::atan2(static_cast<real_T>(i), static_cast<real_T>(i1));
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

  //
  // Arguments    : creal_T *x
  // Return Type  : void
  //
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
          real_T d;
          if ((x->im == 0.0) && (!(std::abs(x->re) > 1.0))) {
            x->re = std::acos(x->re);
            x->im = 0.0;
          } else {
            v.re = x->re + 1.0;
            v.im = x->im;
            b_sqrt(&v);
            u.re = 1.0 - x->re;
            u.im = 0.0 - x->im;
            b_sqrt(&u);
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

//
// File trailer for acos.cpp
//
// [EOF]
//
