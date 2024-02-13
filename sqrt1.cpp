//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sqrt1.cpp
//
// Code generation for function 'sqrt1'
//

// Include files
#include "sqrt1.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void b_sqrt(::coder::array<real_T, 2U> &x)
    {
      int32_T i;
      i = x.size(1);
      for (int32_T k{0}; k < i; k++) {
        int32_T i1;
        i1 = x.size(0);
        for (int32_T b_k{0}; b_k < i1; b_k++) {
          x[b_k + x.size(0) * k] = std::sqrt(x[b_k + x.size(0) * k]);
        }
      }
    }

    void c_sqrt(::coder::array<real_T, 2U> &x)
    {
      int32_T i;
      i = x.size(1);
      for (int32_T k{0}; k < i; k++) {
        x[k] = std::sqrt(x[k]);
      }
    }
  }
}

// End of code generation (sqrt1.cpp)
