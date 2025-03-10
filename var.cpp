//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
    void var(const ::coder::array<double, 2U> &x, ::coder::array<double, 2U> &y)
    {
      ::coder::array<double, 1U> xv;
      int hi;
      int loop_ub;
      int outsize_idx_0;
      y.set_size(1, x.size(1));
      hi = x.size(1);
      for (int k{0}; k < hi; k++) {
        y[k] = 0.0;
      }

      hi = x.size(1);
      if (x.size(1) - 1 >= 0) {
        outsize_idx_0 = x.size(0);
        loop_ub = x.size(0);
      }

      for (int k{0}; k < hi; k++) {
        xv.set_size(outsize_idx_0);
        for (int b_k{0}; b_k < loop_ub; b_k++) {
          xv[b_k] = x[b_k + x.size(0) * k];
        }

        y[k] = b_varstd_anonFcn3(x.size(0), xv);
      }
    }
  }
}

// End of code generation (var.cpp)
