//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// eps.cpp
//
// Code generation for function 'eps'
//

// Include files
#include "eps.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <math.h>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    real_T eps(real_T x)
    {
      real_T absx;
      real_T r;
      int32_T exponent;
      absx = std::abs(x);
      if ((!std::isinf(absx)) && (!std::isnan(absx))) {
        if (absx <= 2.2250738585072014E-308) {
          r = 4.94065645841247E-324;
        } else {
          frexp(absx, &exponent);
          r = std::ldexp(1.0, exponent - 53);
        }
      } else {
        r = rtNaN;
      }

      return r;
    }
  }
}

// End of code generation (eps.cpp)
