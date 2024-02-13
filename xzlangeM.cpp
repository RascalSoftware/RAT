//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzlangeM.cpp
//
// Code generation for function 'xzlangeM'
//

// Include files
#include "xzlangeM.h"
#include "RATMain_rtwutil.h"
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
      namespace reflapack
      {
        real_T xzlangeM(const ::coder::array<creal_T, 2U> &x)
        {
          real_T y;
          boolean_T b;
          boolean_T b1;
          y = 0.0;
          b = (x.size(0) == 0);
          b1 = (x.size(1) == 0);
          if ((!b) && (!b1)) {
            int32_T k;
            boolean_T exitg1;
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k <= x.size(0) * x.size(1) - 1)) {
              real_T absxk;
              absxk = rt_hypotd_snf(x[k].re, x[k].im);
              if (std::isnan(absxk)) {
                y = rtNaN;
                exitg1 = true;
              } else {
                if (absxk > y) {
                  y = absxk;
                }

                k++;
              }
            }
          }

          return y;
        }
      }
    }
  }
}

// End of code generation (xzlangeM.cpp)
