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
    void schur(const ::coder::array<double, 2U> &A, ::coder::array<double, 2U>
               &V, ::coder::array<double, 2U> &T)
    {
      ::coder::array<double, 1U> tau;
      if (internal::anyNonFinite(A)) {
        int b_loop_ub;
        int i;
        int i1;
        int loop_ub;
        unsigned int unnamed_idx_0;
        unnamed_idx_0 = static_cast<unsigned int>(A.size(0));
        V.set_size(A.size(0), A.size(1));
        loop_ub = A.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = static_cast<int>(unnamed_idx_0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            V[i1 + V.size(0) * i] = rtNaN;
          }
        }

        triu(V);
        unnamed_idx_0 = static_cast<unsigned int>(A.size(0));
        T.set_size(A.size(0), A.size(1));
        loop_ub = A.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = static_cast<int>(unnamed_idx_0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            T[i1 + T.size(0) * i] = rtNaN;
          }
        }
      } else {
        int b_loop_ub;
        int i;
        int i1;
        int loop_ub;
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
