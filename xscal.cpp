//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xscal.cpp
//
// Code generation for function 'xscal'
//

// Include files
#include "xscal.h"
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
        void xscal(int n, double a, ::coder::array<double, 2U> &x, int ix0, int
                   incx)
        {
          if (incx >= 1) {
            int i;
            i = ix0 + incx * (n - 1);
            for (int k{ix0}; incx < 0 ? k >= i : k <= i; k += incx) {
              x[k - 1] = a * x[k - 1];
            }
          }
        }
      }
    }
  }
}

// End of code generation (xscal.cpp)
