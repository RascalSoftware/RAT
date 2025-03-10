//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// eps.cpp
//
// Code generation for function 'eps'
//

// Include files
#include "eps.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    double eps(double x)
    {
      double absx;
      double r;
      int exponent;
      absx = std::abs(x);
      if (std::isinf(absx) || std::isnan(absx)) {
        r = rtNaN;
      } else if (absx < 4.4501477170144028E-308) {
        r = 4.94065645841247E-324;
      } else {
        std::frexp(absx, &exponent);
        r = std::ldexp(1.0, exponent - 53);
      }

      return r;
    }
  }
}

// End of code generation (eps.cpp)
