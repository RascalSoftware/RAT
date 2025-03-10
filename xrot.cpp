//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xrot.cpp
//
// Code generation for function 'xrot'
//

// Include files
#include "xrot.h"
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
        void xrot(int n, ::coder::array<double, 2U> &x, int ix0, int incx, int
                  iy0, int incy, double c, double s)
        {
          if (n >= 1) {
            for (int k{0}; k < n; k++) {
              double temp;
              int b_temp_tmp;
              int temp_tmp;
              temp_tmp = (iy0 + k * incy) - 1;
              b_temp_tmp = (ix0 + k * incx) - 1;
              temp = c * x[b_temp_tmp] + s * x[temp_tmp];
              x[temp_tmp] = c * x[temp_tmp] - s * x[b_temp_tmp];
              x[b_temp_tmp] = temp;
            }
          }
        }

        void xrot(int n, ::coder::array<double, 2U> &x, int ix0, int iy0, double
                  c, double s)
        {
          if (n >= 1) {
            for (int k{0}; k < n; k++) {
              double temp;
              int b_temp_tmp;
              int temp_tmp;
              temp_tmp = (iy0 + k) - 1;
              b_temp_tmp = (ix0 + k) - 1;
              temp = c * x[b_temp_tmp] + s * x[temp_tmp];
              x[temp_tmp] = c * x[temp_tmp] - s * x[b_temp_tmp];
              x[b_temp_tmp] = temp;
            }
          }
        }
      }
    }
  }
}

// End of code generation (xrot.cpp)
