//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// computeNormMTridiagonal.cpp
//
// Code generation for function 'computeNormMTridiagonal'
//

// Include files
#include "computeNormMTridiagonal.h"
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
        double computeNormMTridiagonal(int n, const ::coder::array<double, 1U>
          &d, const ::coder::array<double, 1U> &e, int i0)
        {
          double y;
          if (n <= 0) {
            y = 0.0;
          } else {
            int i;
            boolean_T exitg1;
            y = std::abs(d[(i0 + n) - 2]);
            i = -1;
            exitg1 = false;
            while ((!exitg1) && (i + 1 <= n - 2)) {
              double anorm;
              int anorm_tmp;
              anorm_tmp = i0 + i;
              anorm = std::abs(d[anorm_tmp]);
              if (std::isnan(anorm)) {
                y = rtNaN;
                exitg1 = true;
              } else {
                if (anorm > y) {
                  y = anorm;
                }

                anorm = std::abs(e[anorm_tmp]);
                if (std::isnan(anorm)) {
                  y = rtNaN;
                  exitg1 = true;
                } else {
                  if (anorm > y) {
                    y = anorm;
                  }

                  i++;
                }
              }
            }
          }

          return y;
        }
      }
    }
  }
}

// End of code generation (computeNormMTridiagonal.cpp)
