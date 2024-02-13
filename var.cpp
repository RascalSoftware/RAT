//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// var.cpp
//
// Code generation for function 'var'
//

// Include files
#include "var.h"
#include "rt_nonfinite.h"
#include "varstd.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void var(const ::coder::array<real_T, 2U> &x, ::coder::array<real_T, 2U> &y)
    {
      ::coder::array<real_T, 1U> xv;
      int32_T hi;
      int32_T k;
      int32_T loop_ub;
      int32_T nx;
      int32_T outsize_idx_0;
      y.set_size(1, x.size(1));
      hi = x.size(1);
      for (k = 0; k < hi; k++) {
        y[k] = 0.0;
      }

      hi = x.size(1);
      if (0 <= x.size(1) - 1) {
        nx = x.size(0);
        outsize_idx_0 = x.size(0);
        loop_ub = x.size(0);
      }

      for (int32_T b_k{0}; b_k < hi; b_k++) {
        xv.set_size(outsize_idx_0);
        for (k = 0; k < loop_ub; k++) {
          xv[k] = 0.0;
        }

        for (k = 0; k < nx; k++) {
          xv[k] = x[k + x.size(0) * b_k];
        }

        y[b_k] = b_anon(x.size(0), xv);
      }
    }
  }
}

// End of code generation (var.cpp)
