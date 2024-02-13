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
      static boolean_T checkNoNaNs(const ::coder::array<boolean_T, 2U> &x);
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
      static boolean_T checkNoNaNs(const ::coder::array<boolean_T, 2U> &x)
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

      boolean_T ifWhileCond(const ::coder::array<boolean_T, 2U> &x)
      {
        boolean_T y;
        y = ((x.size(0) != 0) && (x.size(1) != 0));
        if (y) {
          y = checkNoNaNs(x);
        }

        return y;
      }
    }
  }
}

// End of code generation (ifWhileCond.cpp)
