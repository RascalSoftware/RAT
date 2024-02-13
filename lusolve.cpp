//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// lusolve.cpp
//
// Code generation for function 'lusolve'
//

// Include files
#include "lusolve.h"
#include "rt_nonfinite.h"
#include "xgetrf.h"
#include "xtrsm.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      void lusolve(const ::coder::array<real_T, 2U> &A, const ::coder::array<
                   real_T, 2U> &B, ::coder::array<real_T, 2U> &X)
      {
        ::coder::array<real_T, 2U> b_A;
        ::coder::array<int32_T, 2U> ipiv;
        int32_T i;
        int32_T i1;
        int32_T info;
        b_A.set_size(A.size(0), A.size(1));
        info = A.size(1);
        for (i = 0; i < info; i++) {
          int32_T loop_ub;
          loop_ub = A.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_A[i1 + b_A.size(0) * i] = A[i1 + A.size(0) * i];
          }
        }

        lapack::xgetrf(A.size(1), A.size(1), b_A, A.size(1), ipiv, &info);
        X.set_size(1, B.size(1));
        info = B.size(1);
        for (i = 0; i < info; i++) {
          X[i] = B[i];
        }

        blas::xtrsm(A.size(1), b_A, A.size(1), X);
        blas::b_xtrsm(A.size(1), b_A, A.size(1), X);
        i = A.size(1) - 1;
        for (info = i; info >= 1; info--) {
          i1 = ipiv[info - 1];
          if (i1 != info) {
            real_T temp;
            temp = X[info - 1];
            X[info - 1] = X[i1 - 1];
            X[i1 - 1] = temp;
          }
        }
      }
    }
  }
}

// End of code generation (lusolve.cpp)
