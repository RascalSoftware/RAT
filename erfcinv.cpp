//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// erfcinv.cpp
//
// Code generation for function 'erfcinv'
//

// Include files
#include "erfcinv.h"
#include "eml_erfcore.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    double erfcinv()
    {
      double u;
      double x;
      u = -(eml_erfcore(1.8213864079517381) - 0.01) / 0.04089832340010429;
      x = 1.8213864079517381 - u / (1.8213864079517381 * u + 1.0);
      u = -(eml_erfcore(x) - 0.01) / (1.1283791670955126 * std::exp(-x * x));
      x -= u / (x * u + 1.0);
      return x;
    }
  }
}

// End of code generation (erfcinv.cpp)
