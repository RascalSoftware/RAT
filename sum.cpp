//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// sum.cpp
//
// Code generation for function 'sum'
//

// Include files
#include "sum.h"
#include "blockedSummation.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void sum(const ::coder::array<double, 2U> &x, ::coder::array<double, 2U> &y)
    {
      if ((x.size(0) == 0) || (x.size(1) == 0)) {
        int loop_ub;
        y.set_size(1, x.size(1));
        loop_ub = x.size(1);
        for (int i{0}; i < loop_ub; i++) {
          y[i] = 0.0;
        }
      } else {
        nestedIter(x, x.size(0), y);
      }
    }

    creal_T sum(const ::coder::array<creal_T, 2U> &x)
    {
      creal_T y;
      if (x.size(1) == 0) {
        y.re = 0.0;
        y.im = 0.0;
      } else {
        y = nestedIter(x, x.size(1));
      }

      return y;
    }

    double sum(const ::coder::array<double, 1U> &x)
    {
      double y;
      if (x.size(0) == 0) {
        y = 0.0;
      } else {
        y = nestedIter(x, x.size(0));
      }

      return y;
    }

    double sum(const ::coder::array<double, 2U> &x)
    {
      double y;
      if (x.size(1) == 0) {
        y = 0.0;
      } else {
        y = nestedIter(x, x.size(1));
      }

      return y;
    }
  }
}

// End of code generation (sum.cpp)
