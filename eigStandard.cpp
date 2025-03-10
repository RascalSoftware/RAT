//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// eigStandard.cpp
//
// Code generation for function 'eigStandard'
//

// Include files
#include "eigStandard.h"
#include "rt_nonfinite.h"
#include "xgeev.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void eigStandard(const ::coder::array<double, 2U> &A, ::coder::array<creal_T,
                     2U> &V, ::coder::array<creal_T, 2U> &D)
    {
      ::coder::array<creal_T, 1U> dt;
      int k;
      int n;
      n = A.size(0);
      internal::lapack::xgeev(A, dt, V);
      D.set_size(A.size(0), A.size(0));
      k = A.size(0);
      for (int i{0}; i < k; i++) {
        int loop_ub;
        loop_ub = A.size(0);
        for (int i1{0}; i1 < loop_ub; i1++) {
          D[i1 + D.size(0) * i].re = 0.0;
          D[i1 + D.size(0) * i].im = 0.0;
        }
      }

      for (k = 0; k < n; k++) {
        D[k + D.size(0) * k] = dt[k];
      }
    }
  }
}

// End of code generation (eigStandard.cpp)
