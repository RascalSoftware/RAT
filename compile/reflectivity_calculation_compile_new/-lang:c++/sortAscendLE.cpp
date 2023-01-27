//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: sortAscendLE.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "sortAscendLE.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : real_T a
//                real_T b
// Return Type  : boolean_T
//
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      boolean_T sortAscendLE(real_T a, real_T b)
      {
        boolean_T p;
        if ((a <= b) || std::isnan(b)) {
          p = true;
        } else {
          p = false;
        }

        return p;
      }
    }
  }
}

//
// File trailer for sortAscendLE.cpp
//
// [EOF]
//
