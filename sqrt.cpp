//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// sqrt.cpp
//
// Code generation for function 'sqrt'
//

// Include files
#include "sqrt.h"
#include "RATMain_rtwutil.h"
#include "rt_nonfinite.h"
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
        void d_sqrt(creal_T *x)
        {
          double absxi;
          double absxr;
          double xi;
          double xr;
          xr = x->re;
          xi = x->im;
          if (xi == 0.0) {
            if (xr < 0.0) {
              absxr = 0.0;
              absxi = std::sqrt(-xr);
            } else {
              absxr = std::sqrt(xr);
              absxi = 0.0;
            }
          } else if (xr == 0.0) {
            if (xi < 0.0) {
              absxr = std::sqrt(-xi / 2.0);
              absxi = -absxr;
            } else {
              absxr = std::sqrt(xi / 2.0);
              absxi = absxr;
            }
          } else if (std::isnan(xr)) {
            absxr = rtNaN;
            absxi = rtNaN;
          } else if (std::isnan(xi)) {
            absxr = rtNaN;
            absxi = rtNaN;
          } else if (std::isinf(xi)) {
            absxr = std::abs(xi);
            absxi = xi;
          } else if (std::isinf(xr)) {
            if (xr < 0.0) {
              absxr = 0.0;
              absxi = xi * -xr;
            } else {
              absxr = xr;
              absxi = 0.0;
            }
          } else {
            absxr = std::abs(xr);
            absxi = std::abs(xi);
            if ((absxr > 4.4942328371557893E+307) || (absxi >
                 4.4942328371557893E+307)) {
              absxr *= 0.5;
              absxi = rt_hypotd_snf(absxr, absxi * 0.5);
              if (absxi > absxr) {
                absxr = std::sqrt(absxi) * std::sqrt(absxr / absxi + 1.0);
              } else {
                absxr = std::sqrt(absxi) * 1.4142135623730951;
              }
            } else {
              absxr = std::sqrt((rt_hypotd_snf(absxr, absxi) + absxr) * 0.5);
            }

            if (xr > 0.0) {
              absxi = 0.5 * (xi / absxr);
            } else {
              if (xi < 0.0) {
                absxi = -absxr;
              } else {
                absxi = absxr;
              }

              absxr = 0.5 * (xi / absxi);
            }
          }

          x->re = absxr;
          x->im = absxi;
        }
      }
    }
  }
}

// End of code generation (sqrt.cpp)
