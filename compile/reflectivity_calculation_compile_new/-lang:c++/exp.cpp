//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: exp.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "exp.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : creal_T *x
// Return Type  : void
//
namespace RAT
{
  namespace coder
  {
    void b_exp(creal_T *x)
    {
      if (x->im == 0.0) {
        x->re = std::exp(x->re);
        x->im = 0.0;
      } else if (std::isinf(x->im) && std::isinf(x->re) && (x->re < 0.0)) {
        x->re = 0.0;
        x->im = 0.0;
      } else {
        real_T d;
        real_T r;
        r = std::exp(x->re / 2.0);
        d = x->im;
        x->re = r * (r * std::cos(x->im));
        x->im = r * (r * std::sin(d));
      }
    }
  }
}

//
// File trailer for exp.cpp
//
// [EOF]
//
