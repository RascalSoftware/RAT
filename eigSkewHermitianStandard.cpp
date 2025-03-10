//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// eigSkewHermitianStandard.cpp
//
// Code generation for function 'eigSkewHermitianStandard'
//

// Include files
#include "eigSkewHermitianStandard.h"
#include "eigRealSkewSymmetricStandard.h"
#include "rt_nonfinite.h"
#include "xdlahqr.h"
#include "xzgehrd.h"
#include "xzunghr.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void eigSkewHermitianStandard(const ::coder::array<double, 2U> &A, ::coder::
      array<creal_T, 2U> &V, ::coder::array<creal_T, 2U> &D)
    {
      ::coder::array<double, 2U> Q;
      ::coder::array<double, 2U> b_A;
      ::coder::array<double, 1U> a__4;
      ::coder::array<double, 1U> tau;
      ::coder::array<double, 1U> wi;
      int b_i;
      int i;
      int info;
      int loop_ub;
      int n;
      n = A.size(0);
      b_A.set_size(A.size(0), A.size(1));
      i = A.size(1);
      for (b_i = 0; b_i < i; b_i++) {
        loop_ub = A.size(0);
        for (int i1{0}; i1 < loop_ub; i1++) {
          b_A[i1 + b_A.size(0) * b_i] = A[i1 + A.size(0) * b_i];
        }
      }

      internal::reflapack::xzgehrd(b_A, A.size(0), tau);
      Q.set_size(b_A.size(0), b_A.size(1));
      i = b_A.size(1);
      for (b_i = 0; b_i < i; b_i++) {
        loop_ub = b_A.size(0);
        for (int i1{0}; i1 < loop_ub; i1++) {
          Q[i1 + Q.size(0) * b_i] = b_A[i1 + b_A.size(0) * b_i];
        }
      }

      internal::reflapack::xzunghr(A.size(0), A.size(0), Q, A.size(0), tau);
      info = internal::reflapack::xdlahqr(A.size(0), b_A, A.size(0), Q, a__4, wi);
      D.set_size(A.size(0), A.size(0));
      i = A.size(0);
      for (b_i = 0; b_i < i; b_i++) {
        loop_ub = A.size(0);
        for (int i1{0}; i1 < loop_ub; i1++) {
          D[i1 + D.size(0) * b_i].re = 0.0;
          D[i1 + D.size(0) * b_i].im = 0.0;
        }
      }

      for (i = 0; i < info; i++) {
        D[i + D.size(0) * i].re = rtNaN;
        D[i + D.size(0) * i].im = 0.0;
      }

      b_i = info + 1;
      for (i = b_i; i <= n; i++) {
        D[(i + D.size(0) * (i - 1)) - 1].re = 0.0;
        D[(i + D.size(0) * (i - 1)) - 1].im = wi[i - 1];
      }

      if (info == 0) {
        extractEigenVectors(Q, b_A, V);
      } else {
        i = b_A.size(0);
        loop_ub = b_A.size(1);
        V.set_size(b_A.size(0), b_A.size(1));
        for (b_i = 0; b_i < loop_ub; b_i++) {
          for (int i1{0}; i1 < i; i1++) {
            V[i1 + V.size(0) * b_i].re = rtNaN;
            V[i1 + V.size(0) * b_i].im = 0.0;
          }
        }
      }
    }
  }
}

// End of code generation (eigSkewHermitianStandard.cpp)
