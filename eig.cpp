//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// eig.cpp
//
// Code generation for function 'eig'
//

// Include files
#include "eig.h"
#include "anyNonFinite.h"
#include "eigHermitianStandard.h"
#include "ishermitian.h"
#include "makeD.h"
#include "rt_nonfinite.h"
#include "schur.h"
#include "xzgeev.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void eig(const ::coder::array<real_T, 2U> &A, ::coder::array<creal_T, 2U> &V,
             ::coder::array<creal_T, 2U> &D)
    {
      ::coder::array<creal_T, 1U> alpha1;
      ::coder::array<creal_T, 1U> beta1;
      ::coder::array<real_T, 2U> b_D;
      ::coder::array<real_T, 2U> b_V;
      int32_T info;
      int32_T n;
      n = A.size(0);
      V.set_size(A.size(0), A.size(0));
      D.set_size(A.size(0), A.size(0));
      if ((A.size(0) != 0) && (A.size(1) != 0)) {
        if (internal::anyNonFinite(A)) {
          int32_T i;
          int32_T i1;
          int32_T loop_ub;
          info = A.size(0);
          loop_ub = A.size(0);
          V.set_size(A.size(0), A.size(0));
          for (i = 0; i < loop_ub; i++) {
            for (i1 = 0; i1 < info; i1++) {
              V[i1 + V.size(0) * i].re = rtNaN;
              V[i1 + V.size(0) * i].im = 0.0;
            }
          }

          info = A.size(0);
          loop_ub = A.size(0);
          D.set_size(A.size(0), A.size(0));
          for (i = 0; i < loop_ub; i++) {
            for (i1 = 0; i1 < info; i1++) {
              D[i1 + D.size(0) * i].re = 0.0;
              D[i1 + D.size(0) * i].im = 0.0;
            }
          }

          for (info = 0; info < n; info++) {
            D[info + D.size(0) * info].re = rtNaN;
            D[info + D.size(0) * info].im = 0.0;
          }
        } else if (ishermitian(A)) {
          int32_T i;
          int32_T i1;
          int32_T loop_ub;
          schur(A, b_V, b_D);
          V.set_size(b_V.size(0), b_V.size(1));
          info = b_V.size(1);
          for (i = 0; i < info; i++) {
            loop_ub = b_V.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              V[i1 + V.size(0) * i].re = b_V[i1 + b_V.size(0) * i];
              V[i1 + V.size(0) * i].im = 0.0;
            }
          }

          diagDiagUpperHessNoImag(b_D);
          D.set_size(b_D.size(0), b_D.size(1));
          info = b_D.size(1);
          for (i = 0; i < info; i++) {
            loop_ub = b_D.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              D[i1 + D.size(0) * i].re = b_D[i1 + b_D.size(0) * i];
              D[i1 + D.size(0) * i].im = 0.0;
            }
          }
        } else {
          internal::reflapack::xzgeev(A, &info, alpha1, beta1, V);
          makeD(alpha1, beta1, D);
        }
      }
    }
  }
}

// End of code generation (eig.cpp)
