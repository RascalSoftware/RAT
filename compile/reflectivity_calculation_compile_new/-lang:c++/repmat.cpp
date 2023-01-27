//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: repmat.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "repmat.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const real_T a[2]
//                real_T varargin_1
//                ::coder::array<real_T, 2U> &b
// Return Type  : void
//
namespace RAT
{
  namespace coder
  {
    void repmat(const real_T a[2], real_T varargin_1, ::coder::array<real_T, 2U>
                &b)
    {
      b.set_size(static_cast<int32_T>(varargin_1), 2);
      if (static_cast<int32_T>(varargin_1) != 0) {
        int32_T i;
        i = static_cast<int32_T>(varargin_1) - 1;
        for (int32_T k{0}; k < 2; k++) {
          for (int32_T t{0}; t <= i; t++) {
            b[t + b.size(0) * k] = a[k];
          }
        }
      }
    }
  }
}

//
// File trailer for repmat.cpp
//
// [EOF]
//
