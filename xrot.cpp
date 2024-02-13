//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
        void xrot(int32_T n, ::coder::array<real_T, 2U> &x, int32_T ix0, int32_T
                  incx, int32_T iy0, int32_T incy, real_T c, real_T s)
        {
          if (n >= 1) {
            for (int32_T k{0}; k < n; k++) {
              real_T temp;
              int32_T b_temp_tmp;
              int32_T temp_tmp;
              temp_tmp = (iy0 + k * incx) - 1;
              b_temp_tmp = (ix0 + k * incy) - 1;
              temp = c * x[b_temp_tmp] + s * x[temp_tmp];
              x[temp_tmp] = c * x[temp_tmp] - s * x[b_temp_tmp];
              x[b_temp_tmp] = temp;
            }
          }
        }

        void xrot(int32_T n, ::coder::array<real_T, 2U> &x, int32_T ix0, int32_T
                  iy0, real_T c, real_T s)
        {
          if (n >= 1) {
            for (int32_T k{0}; k < n; k++) {
              real_T temp;
              int32_T b_temp_tmp;
              int32_T temp_tmp;
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
