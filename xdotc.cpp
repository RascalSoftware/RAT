//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xdotc.cpp
//
// Code generation for function 'xdotc'
//

// Include files
#include "xdotc.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace blas
      {
        double xdotc(int n, const ::coder::array<double, 1U> &x, int ix0, const ::
                     coder::array<double, 2U> &y, int iy0)
        {
          double d;
          d = 0.0;
          if (n >= 1) {
            for (int k{0}; k < n; k++) {
              d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
            }
          }

          return d;
        }
      }
    }
  }
}

// End of code generation (xdotc.cpp)
