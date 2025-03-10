//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// det.cpp
//
// Code generation for function 'det'
//

// Include files
#include "det.h"
#include "rt_nonfinite.h"
#include "xgetrf.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    double det(const ::coder::array<double, 2U> &x)
    {
      ::coder::array<double, 2U> b_x;
      ::coder::array<int, 2U> ipiv;
      double y;
      if ((x.size(0) == 0) || (x.size(1) == 0)) {
        y = 1.0;
      } else {
        int i;
        int k;
        int loop_ub;
        boolean_T isodd;
        b_x.set_size(x.size(0), x.size(1));
        k = x.size(1);
        loop_ub = x.size(0);
        for (i = 0; i < k; i++) {
          for (int i1{0}; i1 < loop_ub; i1++) {
            b_x[i1 + b_x.size(0) * i] = x[i1 + x.size(0) * i];
          }
        }

        internal::lapack::b_xgetrf(x.size(0), x.size(1), b_x, x.size(0), ipiv);
        y = b_x[0];
        i = b_x.size(0);
        for (k = 0; k <= i - 2; k++) {
          y *= b_x[(k + b_x.size(0) * (k + 1)) + 1];
        }

        isodd = false;
        i = ipiv.size(1);
        for (k = 0; k <= i - 2; k++) {
          if (ipiv[k] > k + 1) {
            isodd = !isodd;
          }
        }

        if (isodd) {
          y = -y;
        }
      }

      return y;
    }
  }
}

// End of code generation (det.cpp)
