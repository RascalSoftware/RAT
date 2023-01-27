//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: sum.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "sum.h"
#include "blockedSummation.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<real_T, 1U> &x
// Return Type  : real_T
//
namespace RAT
{
  namespace coder
  {
    real_T sum(const ::coder::array<real_T, 1U> &x)
    {
      real_T y;
      if (x.size(0) == 0) {
        y = 0.0;
      } else {
        y = nestedIter(x, x.size(0));
      }

      return y;
    }
  }
}

//
// File trailer for sum.cpp
//
// [EOF]
//
