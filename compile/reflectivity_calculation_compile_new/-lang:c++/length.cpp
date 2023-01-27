//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: length.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "length.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : int32_T varargin_1
//                int32_T varargin_2
// Return Type  : int32_T
//
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      int32_T intlength(int32_T varargin_1, int32_T varargin_2)
      {
        int32_T n;
        if ((varargin_1 == 0) || (varargin_2 == 0)) {
          n = 0;
        } else if (varargin_1 >= varargin_2) {
          n = varargin_1;
        } else {
          n = varargin_2;
        }

        return n;
      }
    }
  }
}

//
// File trailer for length.cpp
//
// [EOF]
//
