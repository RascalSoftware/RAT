//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: erf.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "erf.h"
#include "eml_erfcore.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<real_T, 2U> &x
//                ::coder::array<real_T, 2U> &y
// Return Type  : void
//
namespace RAT
{
  namespace coder
  {
    void b_erf(const ::coder::array<real_T, 2U> &x, ::coder::array<real_T, 2U>
               &y)
    {
      y.set_size(1, x.size(1));
      if (x.size(1) != 0) {
        int32_T i;
        i = x.size(1);
        for (int32_T k{0}; k < i; k++) {
          y[k] = scalar_erf(x[k]);
        }
      }
    }
  }
}

//
// File trailer for erf.cpp
//
// [EOF]
//
