//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// eig.cpp
//
// Code generation for function 'eig'
//

// Include files
#include "eig.h"
#include "anyNonFinite.h"
#include "eigHermitianStandard.h"
#include "eigSkewHermitianStandard.h"
#include "eigStandard.h"
#include "ishermitian.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void eig(const ::coder::array<double, 2U> &A, ::coder::array<creal_T, 2U> &V,
             ::coder::array<creal_T, 2U> &D)
    {
      int n;
      n = A.size(0);
      V.set_size(A.size(0), A.size(0));
      D.set_size(A.size(0), A.size(0));
      if ((A.size(0) != 0) && (A.size(1) != 0)) {
        if (internal::anyNonFinite(A)) {
          int V_idx_1;
          int k;
          k = A.size(0);
          V_idx_1 = A.size(0);
          V.set_size(A.size(0), A.size(0));
          for (int i{0}; i < V_idx_1; i++) {
            for (int i1{0}; i1 < k; i1++) {
              V[i1 + V.size(0) * i].re = rtNaN;
              V[i1 + V.size(0) * i].im = 0.0;
            }
          }

          k = A.size(0);
          V_idx_1 = A.size(0);
          D.set_size(A.size(0), A.size(0));
          for (int i{0}; i < V_idx_1; i++) {
            for (int i1{0}; i1 < k; i1++) {
              D[i1 + D.size(0) * i].re = 0.0;
              D[i1 + D.size(0) * i].im = 0.0;
            }
          }

          for (k = 0; k < n; k++) {
            D[k + D.size(0) * k].re = rtNaN;
            D[k + D.size(0) * k].im = 0.0;
          }
        } else if (ishermitian(A)) {
          eigHermitianStandard(A, V, D);
        } else if (b_ishermitian(A)) {
          eigSkewHermitianStandard(A, V, D);
        } else {
          eigStandard(A, V, D);
        }
      }
    }
  }
}

// End of code generation (eig.cpp)
