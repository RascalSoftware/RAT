//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
    void b_abs(const ::coder::array<double, 2U> &x, ::coder::array<double, 2U>
               &y)
    {
      y.set_size(1, x.size(1));
      if (x.size(1) != 0) {
        int i;
        i = x.size(1);
        for (int k{0}; k < i; k++) {
          y[k] = std::abs(x[k]);
        }
      }
    }

    void b_abs(const ::coder::array<double, 1U> &x, ::coder::array<double, 1U>
               &y)
    {
      y.set_size(x.size(0));
      if (x.size(0) != 0) {
        int i;
        i = x.size(0);
        for (int k{0}; k < i; k++) {
          y[k] = std::abs(x[k]);
        }
      }
    }

    void c_abs(const ::coder::array<double, 2U> &x, ::coder::array<double, 2U>
               &y)
    {
      y.set_size(static_cast<int>(static_cast<short>(x.size(0))), static_cast<
                 int>(static_cast<short>(x.size(1))));
      if ((x.size(0) != 0) && (x.size(1) != 0)) {
        int i;
        i = static_cast<short>(x.size(1));
        for (int k{0}; k < i; k++) {
          int i1;
          i1 = y.size(0);
          for (int b_k{0}; b_k < i1; b_k++) {
            y[b_k + y.size(0) * k] = std::abs(x[b_k + x.size(0) * k]);
          }
        }
      }
    }
  }
}

// End of code generation (abs.cpp)
