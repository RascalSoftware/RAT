//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// flip.cpp
//
// Code generation for function 'flip'
//

// Include files
#include "flip.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void flip(::coder::array<real_T, 1U> &x)
    {
      if ((x.size(0) != 0) && (x.size(0) > 1)) {
        int32_T lup;
        lup = x.size(0) >> 1;
        for (int32_T k{0}; k < lup; k++) {
          real_T tmp;
          int16_T subs2_idx_0;
          subs2_idx_0 = static_cast<int16_T>(x.size(0) - k);
          tmp = x[k];
          x[k] = x[subs2_idx_0 - 1];
          x[subs2_idx_0 - 1] = tmp;
        }
      }
    }
  }
}

// End of code generation (flip.cpp)
