//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// mean.cpp
//
// Code generation for function 'mean'
//

// Include files
#include "mean.h"
#include "blockedSummation.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void mean(const ::coder::array<real_T, 3U> &x, ::coder::array<real_T, 3U> &y)
    {
      int32_T b_loop_ub;
      int32_T i;
      int32_T i1;
      int32_T loop_ub;
      if ((x.size(0) == 0) || (x.size(1) == 0) || (x.size(2) == 0)) {
        uint32_T sz_idx_1;
        sz_idx_1 = static_cast<uint32_T>(x.size(1));
        y.set_size(1, x.size(1), x.size(2));
        loop_ub = x.size(2);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = static_cast<int32_T>(sz_idx_1);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            y[i1 + y.size(1) * i] = 0.0;
          }
        }
      } else {
        nestedIter(x, x.size(0), y);
      }

      y.set_size(1, y.size(1), y.size(2));
      loop_ub = y.size(2);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = y.size(1);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          y[i1 + y.size(1) * i] = y[i1 + y.size(1) * i] / static_cast<real_T>
            (x.size(0));
        }
      }
    }

    void mean(const ::coder::array<real_T, 2U> &x, ::coder::array<real_T, 2U> &y)
    {
      int32_T i;
      int32_T loop_ub;
      if ((x.size(0) == 0) || (x.size(1) == 0)) {
        y.set_size(1, x.size(1));
        loop_ub = x.size(1);
        for (i = 0; i < loop_ub; i++) {
          y[i] = 0.0;
        }
      } else {
        nestedIter(x, x.size(0), y);
      }

      y.set_size(1, y.size(1));
      loop_ub = y.size(1);
      for (i = 0; i < loop_ub; i++) {
        y[i] = y[i] / static_cast<real_T>(x.size(0));
      }
    }

    real_T mean(const real_T x_data[], int32_T x_size)
    {
      ::coder::array<real_T, 1U> b_x_data;
      real_T y;
      if (x_size == 0) {
        y = 0.0;
      } else {
        b_x_data.set((real_T *)&x_data[0], x_size);
        y = nestedIter(b_x_data, x_size);
      }

      y /= static_cast<real_T>(x_size);
      return y;
    }
  }
}

// End of code generation (mean.cpp)
