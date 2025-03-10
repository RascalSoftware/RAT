//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// ixfun.cpp
//
// Code generation for function 'ixfun'
//

// Include files
#include "ixfun.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      void expand_max(const ::coder::array<double, 1U> &a, const ::coder::array<
                      double, 1U> &b, ::coder::array<double, 1U> &c)
      {
        int k;
        int u0;
        u0 = a.size(0);
        k = b.size(0);
        if (u0 <= k) {
          k = u0;
        }

        if (b.size(0) == 1) {
          u0 = a.size(0);
        } else if (a.size(0) == 1) {
          u0 = b.size(0);
        } else {
          u0 = k;
        }

        c.set_size(u0);
        if (u0 != 0) {
          boolean_T b1;
          boolean_T b_b;
          b_b = (a.size(0) != 1);
          b1 = (b.size(0) != 1);
          u0--;
          for (k = 0; k <= u0; k++) {
            c[k] = std::fmax(a[b_b * k], b[b1 * k]);
          }
        }
      }
    }
  }
}

// End of code generation (ixfun.cpp)
