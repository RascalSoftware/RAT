//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
    real_T b_mod(real_T x)
    {
      real_T r;
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

    real_T b_mod(real_T x, real_T y)
    {
      real_T r;
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
  }
}

// End of code generation (mod.cpp)
