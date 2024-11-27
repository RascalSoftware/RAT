//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// ifWhileCond.cpp
//
// Code generation for function 'ifWhileCond'
//

// Include files
#include "ifWhileCond.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      static boolean_T b_checkNoNaNs(const boolean_T x_data[], const int32_T
        x_size[2]);
      static boolean_T c_checkNoNaNs(const ::coder::array<boolean_T, 2U> &x);
      static boolean_T checkNoNaNs(const boolean_T x_data[], int32_T x_size);
    }
  }
}

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      static boolean_T b_checkNoNaNs(const boolean_T x_data[], const int32_T
        x_size[2])
      {
        int32_T k;
        boolean_T exitg1;
        boolean_T y;
        y = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k <= x_size[1] - 1)) {
          if (!x_data[k]) {
            y = false;
            exitg1 = true;
          } else {
            k++;
          }
        }

        return y;
      }

      static boolean_T c_checkNoNaNs(const ::coder::array<boolean_T, 2U> &x)
      {
        int32_T i;
        int32_T k;
        boolean_T exitg1;
        boolean_T y;
        y = true;
        i = x.size(0) * x.size(1);
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k <= i - 1)) {
          if (!x[k]) {
            y = false;
            exitg1 = true;
          } else {
            k++;
          }
        }

        return y;
      }

      static boolean_T checkNoNaNs(const boolean_T x_data[], int32_T x_size)
      {
        int32_T k;
        boolean_T exitg1;
        boolean_T y;
        y = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k <= x_size - 1)) {
          if (!x_data[0]) {
            y = false;
            exitg1 = true;
          } else {
            k = 1;
          }
        }

        return y;
      }

      boolean_T b_ifWhileCond(const boolean_T x_data[], const int32_T x_size[2])
      {
        boolean_T y;
        y = (x_size[1] != 0);
        if (y) {
          y = b_checkNoNaNs(x_data, x_size);
        }

        return y;
      }

      boolean_T c_ifWhileCond(const ::coder::array<boolean_T, 2U> &x)
      {
        boolean_T y;
        y = ((x.size(0) != 0) && (x.size(1) != 0));
        if (y) {
          y = c_checkNoNaNs(x);
        }

        return y;
      }

      boolean_T ifWhileCond(const boolean_T x_data[], int32_T x_size)
      {
        boolean_T y;
        y = (x_size != 0);
        if (y) {
          y = checkNoNaNs(x_data, x_size);
        }

        return y;
      }
    }
  }
}

// End of code generation (ifWhileCond.cpp)
