//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: log2.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "log2.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : real_T x
//                real_T *f
//                real_T *e
// Return Type  : void
//
namespace RAT
{
  namespace coder
  {
    void b_log2(real_T x, real_T *f, real_T *e)
    {
      int32_T eint;
      if ((!std::isinf(x)) && (!std::isnan(x))) {
        *f = std::frexp(x, &eint);
        *e = eint;
      } else {
        *f = x;
        *e = 0.0;
      }
    }
  }
}

//
// File trailer for log2.cpp
//
// [EOF]
//
