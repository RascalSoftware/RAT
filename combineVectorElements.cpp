//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// combineVectorElements.cpp
//
// Code generation for function 'combineVectorElements'
//

// Include files
#include "combineVectorElements.h"
#include "blockedSummation.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    real_T b_combineVectorElements(const ::coder::array<real_T, 1U> &x, int32_T
      vlen)
    {
      real_T y;
      if ((x.size(0) == 0) || (vlen == 0)) {
        y = 0.0;
      } else {
        y = nestedIter(x, vlen);
      }

      return y;
    }

    int32_T c_combineVectorElements(const ::coder::array<boolean_T, 1U> &x)
    {
      int32_T vlen;
      int32_T y;
      vlen = x.size(0);
      if (x.size(0) == 0) {
        y = 0;
      } else {
        y = x[0];
        for (int32_T k{2}; k <= vlen; k++) {
          if (vlen >= 2) {
            y += x[k - 1];
          }
        }
      }

      return y;
    }

    int32_T combineVectorElements(const ::coder::array<boolean_T, 2U> &x)
    {
      int32_T vlen;
      int32_T y;
      vlen = x.size(1);
      if (x.size(1) == 0) {
        y = 0;
      } else {
        y = x[0];
        for (int32_T k{2}; k <= vlen; k++) {
          if (vlen >= 2) {
            y += x[k - 1];
          }
        }
      }

      return y;
    }
  }
}

// End of code generation (combineVectorElements.cpp)
