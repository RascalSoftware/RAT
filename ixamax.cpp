//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
        int ixamax(int n, const ::coder::array<double, 2U> &x, int ix0, int incx)
        {
          int idxmax;
          if ((n < 1) || (incx < 1)) {
            idxmax = 0;
          } else {
            idxmax = 1;
            if (n > 1) {
              double smax;
              smax = std::abs(x[ix0 - 1]);
              for (int k{2}; k <= n; k++) {
                double s;
                s = std::abs(x[(ix0 + (k - 1) * incx) - 1]);
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

        int ixamax(int n, const ::coder::array<double, 1U> &x)
        {
          int idxmax;
          idxmax = 1;
          if (n > 1) {
            double smax;
            smax = std::abs(x[0]);
            for (int k{2}; k <= n; k++) {
              double s;
              s = std::abs(x[k - 1]);
              if (s > smax) {
                idxmax = k;
                smax = s;
              }
            }
          }

          return idxmax;
        }

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
      }
    }
  }
}

// End of code generation (ixamax.cpp)
