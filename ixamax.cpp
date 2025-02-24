//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// ixamax.cpp
//
// Code generation for function 'ixamax'
//

// Include files
#include "ixamax.h"
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
      namespace blas
      {
        int ixamax(int n, const ::coder::array<double, 1U> &x, int ix0)
        {
          int idxmax;
          if (n < 1) {
            idxmax = 0;
          } else {
            idxmax = 1;
            if (n > 1) {
              double smax;
              smax = std::abs(x[ix0 - 1]);
              for (int k{2}; k <= n; k++) {
                double s;
                s = std::abs(x[(ix0 + k) - 2]);
                if (s > smax) {
                  idxmax = k;
                  smax = s;
                }
              }
            }
          }

          return idxmax;
        }

        int ixamax(int n, const ::coder::array<double, 2U> &x, int ix0)
        {
          int idxmax;
          if (n < 1) {
            idxmax = 0;
          } else {
            idxmax = 1;
            if (n > 1) {
              double smax;
              smax = std::abs(x[ix0 - 1]);
              for (int k{2}; k <= n; k++) {
                double s;
                s = std::abs(x[(ix0 + k) - 2]);
                if (s > smax) {
                  idxmax = k;
                  smax = s;
                }
              }
            }
          }

          return idxmax;
        }
      }
    }
  }
}

// End of code generation (ixamax.cpp)
