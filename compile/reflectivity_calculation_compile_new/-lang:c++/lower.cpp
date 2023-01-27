//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: lower.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "lower.h"
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : const char_T x_data[]
//                const int32_T x_size[2]
//                char_T y_data[]
//                int32_T y_size[2]
// Return Type  : void
//
namespace RAT
{
  namespace coder
  {
    void lower(const char_T x_data[], const int32_T x_size[2], char_T y_data[],
               int32_T y_size[2])
    {
      int32_T i;
      y_size[0] = 1;
      y_size[1] = x_size[1];
      i = x_size[1];
      for (int32_T k{0}; k < i; k++) {
        y_data[k] = cv[static_cast<uint8_T>(x_data[k]) & 127];
      }
    }
  }
}

//
// File trailer for lower.cpp
//
// [EOF]
//
