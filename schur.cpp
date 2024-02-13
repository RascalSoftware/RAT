//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// schur.cpp
//
// Code generation for function 'schur'
//

// Include files
#include "schur.h"
#include "anyNonFinite.h"
#include "rt_nonfinite.h"
#include "triu.h"
#include "xdhseqr.h"
#include "xgehrd.h"
#include "xungorghr.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void schur(const ::coder::array<real_T, 2U> &A, ::coder::array<real_T, 2U>
               &V, ::coder::array<real_T, 2U> &T)
    {
      ::coder::array<real_T, 1U> tau;
      if (internal::anyNonFinite(A)) {
        int32_T b_loop_ub;
        int32_T i;
        int32_T i1;
        int32_T loop_ub;
        uint32_T unnamed_idx_0;
        unnamed_idx_0 = static_cast<uint32_T>(A.size(0));
        V.set_size(A.size(0), A.size(1));
        loop_ub = A.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = static_cast<int32_T>(unnamed_idx_0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            V[i1 + V.size(0) * i] = rtNaN;
          }
        }

        triu(V);
        unnamed_idx_0 = static_cast<uint32_T>(A.size(0));
        T.set_size(A.size(0), A.size(1));
        loop_ub = A.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = static_cast<int32_T>(unnamed_idx_0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            T[i1 + T.size(0) * i] = rtNaN;
          }
        }
      } else {
        int32_T b_loop_ub;
        int32_T i;
        int32_T i1;
        int32_T loop_ub;
        T.set_size(A.size(0), A.size(1));
        loop_ub = A.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = A.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            T[i1 + T.size(0) * i] = A[i1 + A.size(0) * i];
          }
        }

        internal::lapack::xgehrd(T, tau);
        V.set_size(T.size(0), T.size(1));
        loop_ub = T.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = T.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            V[i1 + V.size(0) * i] = T[i1 + T.size(0) * i];
          }
        }

        internal::lapack::xungorghr(A.size(0), A.size(0), V, A.size(0), tau);
        internal::reflapack::eml_dlahqr(T, V);
        b_triu(T);
      }
    }
  }
}

// End of code generation (schur.cpp)
