//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
    void mean(const ::coder::array<double, 3U> &x, ::coder::array<double, 3U> &y)
    {
      int b_loop_ub;
      int loop_ub;
      if ((x.size(0) == 0) || (x.size(1) == 0) || (x.size(2) == 0)) {
        unsigned int sz_idx_1;
        sz_idx_1 = static_cast<unsigned int>(x.size(1));
        y.set_size(1, x.size(1), x.size(2));
        loop_ub = x.size(2);
        for (int i{0}; i < loop_ub; i++) {
          b_loop_ub = static_cast<int>(sz_idx_1);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            y[i1 + y.size(1) * i] = 0.0;
          }
        }
      } else {
        nestedIter(x, x.size(0), y);
      }

      y.set_size(1, y.size(1), y.size(2));
      loop_ub = y.size(2);
      for (int i{0}; i < loop_ub; i++) {
        b_loop_ub = y.size(1);
        for (int i1{0}; i1 < b_loop_ub; i1++) {
          y[i1 + y.size(1) * i] = y[i1 + y.size(1) * i] / static_cast<double>
            (x.size(0));
        }
      }
    }

    void mean(const ::coder::array<double, 2U> &x, ::coder::array<double, 2U> &y)
    {
      int loop_ub;
      if ((x.size(0) == 0) || (x.size(1) == 0)) {
        y.set_size(1, x.size(1));
        loop_ub = x.size(1);
        for (int i{0}; i < loop_ub; i++) {
          y[i] = 0.0;
        }
      } else {
        nestedIter(x, x.size(0), y);
      }

      y.set_size(1, y.size(1));
      loop_ub = y.size(1);
      for (int i{0}; i < loop_ub; i++) {
        y[i] = y[i] / static_cast<double>(x.size(0));
      }
    }

    double mean(const double x_data[], int x_size)
    {
      ::coder::array<double, 1U> b_x_data;
      double y;
      if (x_size == 0) {
        y = 0.0;
      } else {
        b_x_data.set((double *)&x_data[0], x_size);
        y = nestedIter(b_x_data, x_size);
      }

      y /= static_cast<double>(x_size);
      return y;
    }
  }
}

// End of code generation (mean.cpp)
