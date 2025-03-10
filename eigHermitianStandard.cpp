//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// eigHermitianStandard.cpp
//
// Code generation for function 'eigHermitianStandard'
//

// Include files
#include "eigHermitianStandard.h"
#include "rt_nonfinite.h"
#include "xsyheev.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void eigHermitianStandard(const ::coder::array<double, 2U> &A, ::coder::
      array<creal_T, 2U> &V, ::coder::array<creal_T, 2U> &D)
    {
      ::coder::array<double, 2U> b_A;
      ::coder::array<double, 1U> dt;
      int i;
      int loop_ub;
      int n;
      n = A.size(0);
      b_A.set_size(A.size(0), A.size(1));
      i = A.size(1);
      for (int b_i{0}; b_i < i; b_i++) {
        loop_ub = A.size(0);
        for (int i1{0}; i1 < loop_ub; i1++) {
          b_A[i1 + b_A.size(0) * b_i] = A[i1 + A.size(0) * b_i];
        }
      }

      internal::lapack::xsyheev(b_A, dt);
      D.set_size(A.size(0), A.size(0));
      i = A.size(0);
      for (int b_i{0}; b_i < i; b_i++) {
        loop_ub = A.size(0);
        for (int i1{0}; i1 < loop_ub; i1++) {
          D[i1 + D.size(0) * b_i].re = 0.0;
          D[i1 + D.size(0) * b_i].im = 0.0;
        }
      }

      for (i = 0; i < n; i++) {
        D[i + D.size(0) * i].re = dt[i];
        D[i + D.size(0) * i].im = 0.0;
      }

      V.set_size(b_A.size(0), b_A.size(1));
      i = b_A.size(1);
      for (int b_i{0}; b_i < i; b_i++) {
        loop_ub = b_A.size(0);
        for (int i1{0}; i1 < loop_ub; i1++) {
          V[i1 + V.size(0) * b_i].re = b_A[i1 + b_A.size(0) * b_i];
          V[i1 + V.size(0) * b_i].im = 0.0;
        }
      }
    }
  }
}

// End of code generation (eigHermitianStandard.cpp)
