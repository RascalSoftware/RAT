//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
        void xswap(int32_T n, ::coder::array<real_T, 2U> &x, int32_T ix0,
                   int32_T iy0)
        {
          for (int32_T k{0}; k < n; k++) {
            real_T temp;
            int32_T i;
            int32_T temp_tmp;
            temp_tmp = (ix0 + k) - 1;
            temp = x[temp_tmp];
            i = (iy0 + k) - 1;
            x[temp_tmp] = x[i];
            x[i] = temp;
          }
        }

        void xswap(int32_T n, ::coder::array<real_T, 2U> &x, int32_T ix0,
                   int32_T incx, int32_T iy0, int32_T incy)
        {
          for (int32_T k{0}; k < n; k++) {
            real_T temp;
            int32_T i;
            int32_T temp_tmp;
            temp_tmp = (ix0 + k * incx) - 1;
            temp = x[temp_tmp];
            i = (iy0 + k * incy) - 1;
            x[temp_tmp] = x[i];
            x[i] = temp;
          }
        }
      }
    }
  }
}

// End of code generation (xswap.cpp)
