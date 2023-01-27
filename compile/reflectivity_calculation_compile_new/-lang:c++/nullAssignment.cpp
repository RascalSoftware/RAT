//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: nullAssignment.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "nullAssignment.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : real_T x_data[]
//                int32_T x_size[2]
// Return Type  : void
//
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      void nullAssignment(real_T x_data[], int32_T x_size[2])
      {
        int32_T b_i;
        int32_T nrows;
        nrows = x_size[0];
        for (int32_T j{0}; j < 5; j++) {
          for (int32_T i{0}; i <= nrows - 2; i++) {
            b_i = i + x_size[0] * j;
            x_data[b_i] = x_data[b_i + 1];
          }
        }

        if (x_size[0] - 1 < 1) {
          nrows = 0;
        } else {
          nrows = x_size[0] - 1;
        }

        for (b_i = 0; b_i < 5; b_i++) {
          for (int32_T j{0}; j < nrows; j++) {
            x_data[j + nrows * b_i] = x_data[j + x_size[0] * b_i];
          }
        }

        x_size[0] = nrows;
        x_size[1] = 5;
      }
    }
  }
}

//
// File trailer for nullAssignment.cpp
//
// [EOF]
//
