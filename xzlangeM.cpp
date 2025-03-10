//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xzlangeM.cpp
//
// Code generation for function 'xzlangeM'
//

// Include files
#include "xzlangeM.h"
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
        double xzlangeM(const ::coder::array<double, 2U> &x)
        {
          double y;
          boolean_T b;
          boolean_T b1;
          y = 0.0;
          b = (x.size(0) == 0);
          b1 = (x.size(1) == 0);
          if ((!b) && (!b1)) {
            int k;
            k = 0;
            int exitg1;
            int i;
            do {
              exitg1 = 0;
              i = x.size(0) * x.size(1);
              if (k <= i - 1) {
                double absxk;
                absxk = std::abs(x[k]);
                if (std::isnan(absxk)) {
                  y = rtNaN;
                  exitg1 = 1;
                } else {
                  if (absxk > y) {
                    y = absxk;
                  }

                  k++;
                }
              } else {
                exitg1 = 1;
              }
            } while (exitg1 == 0);
          }

          return y;
        }
      }
    }
  }
}

// End of code generation (xzlangeM.cpp)
