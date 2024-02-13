//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xgehrd.cpp
//
// Code generation for function 'xgehrd'
//

// Include files
#include "xgehrd.h"
#include "rt_nonfinite.h"
#include "xzlarf.h"
#include "xzlarfg.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace lapack
      {
        void xgehrd(::coder::array<real_T, 2U> &a, ::coder::array<real_T, 1U>
                    &tau)
        {
          ::coder::array<real_T, 1U> work;
          real_T alpha1;
          int32_T i;
          int32_T n;
          int32_T unnamed_idx_0;
          n = a.size(0);
          if (a.size(0) < 1) {
            i = 0;
          } else {
            i = a.size(0) - 1;
          }

          tau.set_size(i);
          unnamed_idx_0 = a.size(0);
          work.set_size(unnamed_idx_0);
          for (i = 0; i < unnamed_idx_0; i++) {
            work[i] = 0.0;
          }

          i = a.size(0);
          for (int32_T b_i{0}; b_i <= i - 2; b_i++) {
            real_T d;
            int32_T i1;
            int32_T in;
            in = (b_i + 1) * n;
            alpha1 = a[(b_i + a.size(0) * b_i) + 1];
            unnamed_idx_0 = b_i + 3;
            if (unnamed_idx_0 >= n) {
              unnamed_idx_0 = n;
            }

            d = reflapack::xzlarfg((n - b_i) - 1, &alpha1, a, unnamed_idx_0 +
              b_i * n);
            tau[b_i] = d;
            a[(b_i + a.size(0) * b_i) + 1] = 1.0;
            unnamed_idx_0 = (n - b_i) - 1;
            i1 = (b_i + b_i * n) + 2;
            reflapack::b_xzlarf(n, unnamed_idx_0, i1, d, a, in + 1, n, work);
            reflapack::c_xzlarf(unnamed_idx_0, unnamed_idx_0, i1, d, a, (b_i +
              in) + 2, n, work);
            a[(b_i + a.size(0) * b_i) + 1] = alpha1;
          }
        }
      }
    }
  }
}

// End of code generation (xgehrd.cpp)
