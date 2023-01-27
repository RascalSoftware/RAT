//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: find.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "find.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<boolean_T, 1U> &x
//                ::coder::array<int32_T, 1U> &i
// Return Type  : void
//
namespace RAT
{
  namespace coder
  {
    void eml_find(const ::coder::array<boolean_T, 1U> &x, ::coder::array<int32_T,
                  1U> &i)
    {
      int32_T idx;
      int32_T ii;
      int32_T nx;
      boolean_T exitg1;
      nx = x.size(0);
      idx = 0;
      i.set_size(x.size(0));
      ii = 0;
      exitg1 = false;
      while ((!exitg1) && (ii <= nx - 1)) {
        if (x[ii]) {
          idx++;
          i[idx - 1] = ii + 1;
          if (idx >= nx) {
            exitg1 = true;
          } else {
            ii++;
          }
        } else {
          ii++;
        }
      }

      if (x.size(0) == 1) {
        if (idx == 0) {
          i.set_size(0);
        }
      } else {
        if (idx < 1) {
          idx = 0;
        }

        i.set_size(idx);
      }
    }
  }
}

//
// File trailer for find.cpp
//
// [EOF]
//
