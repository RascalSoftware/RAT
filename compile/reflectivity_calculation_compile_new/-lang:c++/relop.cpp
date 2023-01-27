//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: relop.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "relop.h"
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
      boolean_T b_relop(real_T a, real_T b)
      {
        boolean_T p;
        if (std::isnan(b)) {
          p = false;
        } else if (std::isnan(a)) {
          p = true;
        } else {
          p = (a > b);
        }

        return p;
      }

      //
      // Arguments    : real_T a
      //                real_T b
      // Return Type  : boolean_T
      //
      boolean_T relop(real_T a, real_T b)
      {
        boolean_T p;
        if (std::isnan(b)) {
          p = false;
        } else if (std::isnan(a)) {
          p = true;
        } else {
          p = (a < b);
        }

        return p;
      }
    }
  }
}

//
// File trailer for relop.cpp
//
// [EOF]
//
