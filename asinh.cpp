//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// asinh.cpp
//
// Code generation for function 'asinh'
//

// Include files
#include "asinh.h"
#include "log1p.h"
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
        void b_asinh(double &x)
        {
          boolean_T xneg;
          xneg = (x < 0.0);
          if (xneg) {
            x = -x;
          }

          if (x >= 2.68435456E+8) {
            x = std::log(x) + 0.69314718055994529;
          } else if (x > 2.0) {
            x = std::log(2.0 * x + 1.0 / (std::sqrt(x * x + 1.0) + x));
          } else {
            double t;
            t = x * x;
            x += t / (std::sqrt(t + 1.0) + 1.0);
            b_log1p(x);
          }

          if (xneg) {
            x = -x;
          }
        }
      }
    }
  }
}

// End of code generation (asinh.cpp)
