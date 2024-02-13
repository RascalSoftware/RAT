//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// pow2.cpp
//
// Code generation for function 'pow2'
//

// Include files
#include "pow2.h"
#include "RATMain_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void pow2(const ::coder::array<real_T, 1U> &a, ::coder::array<real_T, 1U> &y)
    {
      y.set_size(a.size(0));
      if (a.size(0) != 0) {
        int32_T i;
        i = a.size(0);
        for (int32_T k{0}; k < i; k++) {
          y[k] = rt_powd_snf(2.0, a[k]);
        }
      }
    }
  }
}

// End of code generation (pow2.cpp)
