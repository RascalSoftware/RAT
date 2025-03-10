//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xzsyheev.cpp
//
// Code generation for function 'xzsyheev'
//

// Include files
#include "xzsyheev.h"
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
        double computeNormM(const ::coder::array<double, 2U> &A)
        {
          double y;
          int j;
          boolean_T exitg2;
          y = 0.0;
          j = 0;
          exitg2 = false;
          while ((!exitg2) && (j <= A.size(0) - 1)) {
            int exitg1;
            int i;
            i = 0;
            do {
              exitg1 = 0;
              if (i <= j) {
                double absx;
                absx = std::abs(A[i + A.size(0) * j]);
                if (std::isnan(absx)) {
                  y = rtNaN;
                  exitg1 = 1;
                } else {
                  if (absx > y) {
                    y = absx;
                  }

                  i++;
                }
              } else {
                j++;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }

          return y;
        }
      }
    }
  }
}

// End of code generation (xzsyheev.cpp)
