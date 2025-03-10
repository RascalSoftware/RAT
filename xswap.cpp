//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xswap.cpp
//
// Code generation for function 'xswap'
//

// Include files
#include "xswap.h"
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
        void xswap(int n, ::coder::array<double, 2U> &x, int ix0, int incx, int
                   iy0, int incy)
        {
          for (int k{0}; k < n; k++) {
            double temp;
            int i;
            int temp_tmp;
            temp_tmp = (ix0 + k * incx) - 1;
            temp = x[temp_tmp];
            i = (iy0 + k * incy) - 1;
            x[temp_tmp] = x[i];
            x[i] = temp;
          }
        }

        void xswap(int n, ::coder::array<double, 2U> &x, int ix0, int iy0)
        {
          for (int k{0}; k < n; k++) {
            double temp;
            int i;
            int temp_tmp;
            temp_tmp = (ix0 + k) - 1;
            temp = x[temp_tmp];
            i = (iy0 + k) - 1;
            x[temp_tmp] = x[i];
            x[i] = temp;
          }
        }

        void xswap(::coder::array<double, 2U> &x, int ix0)
        {
          double temp;
          temp = x[ix0 - 1];
          x[ix0 - 1] = x[0];
          x[0] = temp;
        }
      }
    }
  }
}

// End of code generation (xswap.cpp)
