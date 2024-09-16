//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sortrows.cpp
//
// Code generation for function 'sortrows'
//

// Include files
#include "sortrows.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void apply_row_permutation(::coder::array<real_T, 2U> &y, const ::coder::
      array<int32_T, 1U> &idx)
    {
      ::coder::array<real_T, 1U> ycol;
      int32_T m;
      m = y.size(0) - 1;
      ycol.set_size(y.size(0));
      for (int32_T j{0}; j < 2; j++) {
        int32_T i;
        for (i = 0; i <= m; i++) {
          ycol[i] = y[(idx[i] + y.size(0) * j) - 1];
        }

        for (i = 0; i <= m; i++) {
          y[i + y.size(0) * j] = ycol[i];
        }
      }
    }
  }
}

// End of code generation (sortrows.cpp)
