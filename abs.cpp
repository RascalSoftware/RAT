//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// abs.cpp
//
// Code generation for function 'abs'
//

// Include files
#include "abs.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void b_abs(const ::coder::array<real_T, 2U> &x, ::coder::array<real_T, 2U>
               &y)
    {
      y.set_size(1, x.size(1));
      if (x.size(1) != 0) {
        int32_T i;
        i = x.size(1);
        for (int32_T k{0}; k < i; k++) {
          y[k] = std::abs(x[k]);
        }
      }
    }

    void b_abs(const ::coder::array<real_T, 1U> &x, ::coder::array<real_T, 1U>
               &y)
    {
      y.set_size(x.size(0));
      if (x.size(0) != 0) {
        int32_T i;
        i = x.size(0);
        for (int32_T k{0}; k < i; k++) {
          y[k] = std::abs(x[k]);
        }
      }
    }

    void c_abs(const ::coder::array<real_T, 2U> &x, ::coder::array<real_T, 2U>
               &y)
    {
      y.set_size(x.size(0), x.size(1));
      if ((x.size(0) != 0) && (x.size(1) != 0)) {
        int32_T i;
        i = x.size(1);
        for (int32_T k{0}; k < i; k++) {
          int32_T i1;
          i1 = y.size(0);
          for (int32_T b_k{0}; b_k < i1; b_k++) {
            y[b_k + y.size(0) * k] = std::abs(x[b_k + x.size(0) * k]);
          }
        }
      }
    }
  }
}

// End of code generation (abs.cpp)
