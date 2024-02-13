//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// rem.cpp
//
// Code generation for function 'rem'
//

// Include files
#include "rem.h"
#include "RATMain_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void b_rem(const ::coder::array<real_T, 2U> &x, real_T y, ::coder::array<
               real_T, 2U> &r)
    {
      int32_T N;
      r.set_size(1, x.size(1));
      N = x.size(1);
      for (int32_T k{0}; k < N; k++) {
        r[k] = rt_remd_snf(x[k], y);
      }
    }
  }
}

// End of code generation (rem.cpp)
