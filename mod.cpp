//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// mod.cpp
//
// Code generation for function 'mod'
//

// Include files
#include "mod.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    double b_mod(double x)
    {
      double r;
      if (std::isnan(x) || std::isinf(x)) {
        r = rtNaN;
      } else if (x == 0.0) {
        r = 0.0;
      } else {
        r = std::fmod(x, 1.0);
        if (r == 0.0) {
          r = 0.0;
        } else if (x < 0.0) {
          r++;
        }
      }

      return r;
    }

    double b_mod(double x, double y)
    {
      double r;
      r = x;
      if (std::isnan(x) || std::isnan(y) || std::isinf(x)) {
        r = rtNaN;
      } else if (!std::isinf(y)) {
        r = std::fmod(x, y);
        if (r == 0.0) {
          r = y * 0.0;
        }
      }

      return r;
    }

    double c_mod(double x)
    {
      double r;
      if (std::isnan(x) || std::isinf(x)) {
        r = rtNaN;
      } else if (x == 0.0) {
        r = 0.0;
      } else {
        r = std::fmod(x, 100.0);
        if (r == 0.0) {
          r = 0.0;
        }
      }

      return r;
    }
  }
}

// End of code generation (mod.cpp)
