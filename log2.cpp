//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// log2.cpp
//
// Code generation for function 'log2'
//

// Include files
#include "log2.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    double b_log2(double x, double &e)
    {
      double f;
      int eint;
      if ((!std::isinf(x)) && (!std::isnan(x))) {
        f = std::frexp(x, &eint);
        e = eint;
      } else {
        f = x;
        e = 0.0;
      }

      return f;
    }
  }
}

// End of code generation (log2.cpp)
