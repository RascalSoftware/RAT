//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xaxpy.cpp
//
// Code generation for function 'xaxpy'
//

// Include files
#include "xaxpy.h"
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
        void xaxpy(int n, double a, const ::coder::array<double, 2U> &x, int ix0,
                   ::coder::array<double, 2U> &y, int iy0)
        {
          if ((n >= 1) && (!(a == 0.0))) {
            int i;
            i = n - 1;
            for (int k{0}; k <= i; k++) {
              int i1;
              i1 = (iy0 + k) - 1;
              y[i1] = y[i1] + a * x[(ix0 + k) - 1];
            }
          }
        }

        void xaxpy(int n, double a, const ::coder::array<double, 2U> &x, int ix0,
                   ::coder::array<double, 1U> &y, int iy0)
        {
          if ((n >= 1) && (!(a == 0.0))) {
            int i;
            i = n - 1;
            for (int k{0}; k <= i; k++) {
              int i1;
              i1 = (iy0 + k) - 1;
              y[i1] = y[i1] + a * x[(ix0 + k) - 1];
            }
          }
        }
      }
    }
  }
}

// End of code generation (xaxpy.cpp)
