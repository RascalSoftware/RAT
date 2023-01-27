//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: allOrAny.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "allOrAny.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : int32_T n
//                const ::coder::array<boolean_T, 1U> &X
// Return Type  : boolean_T
//
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      boolean_T allOrAny_anonFcn3(int32_T n, const ::coder::array<boolean_T, 1U>
        &X)
      {
        int32_T k;
        boolean_T exitg1;
        boolean_T varargout_1;
        varargout_1 = false;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k <= n - 1)) {
          if (X[k]) {
            varargout_1 = true;
            exitg1 = true;
          } else {
            k++;
          }
        }

        return varargout_1;
      }
    }
  }
}

//
// File trailer for allOrAny.cpp
//
// [EOF]
//
