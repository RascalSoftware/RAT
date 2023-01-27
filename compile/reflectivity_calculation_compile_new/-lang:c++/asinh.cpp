//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: asinh.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "asinh.h"
#include "log1p.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : real_T *x
// Return Type  : void
//
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace scalar
      {
        void b_asinh(real_T *x)
        {
          boolean_T xneg;
          xneg = (*x < 0.0);
          if (xneg) {
            *x = -*x;
          }

          if (*x >= 2.68435456E+8) {
            *x = std::log(*x) + 0.69314718055994529;
          } else if (*x > 2.0) {
            *x = std::log(2.0 * *x + 1.0 / (std::sqrt(*x * *x + 1.0) + *x));
          } else {
            real_T t;
            t = *x * *x;
            *x += t / (std::sqrt(t + 1.0) + 1.0);
            b_log1p(x);
          }

          if (xneg) {
            *x = -*x;
          }
        }
      }
    }
  }
}

//
// File trailer for asinh.cpp
//
// [EOF]
//
