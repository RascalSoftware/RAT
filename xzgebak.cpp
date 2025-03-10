//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xzgebak.cpp
//
// Code generation for function 'xzgebak'
//

// Include files
#include "xzgebak.h"
#include "rt_nonfinite.h"
#include "xscal.h"
#include "xswap.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace reflapack
      {
        void xzgebak(int ilo, int ihi, const ::coder::array<double, 1U> &scale, ::
                     coder::array<double, 2U> &V)
        {
          int n;
          n = V.size(0);
          if ((V.size(0) != 0) && (V.size(1) != 0)) {
            int b_i;
            int i1;
            if (ilo != ihi) {
              for (int i{ilo}; i <= ihi; i++) {
                blas::xscal(n, scale[i - 1], V, i, n);
              }
            }

            b_i = ilo - 1;
            for (int i{b_i}; i >= 1; i--) {
              i1 = static_cast<int>(scale[i - 1]);
              if (i1 != i) {
                blas::xswap(n, V, i, n, i1, n);
              }
            }

            b_i = ihi + 1;
            for (int i{b_i}; i <= n; i++) {
              i1 = static_cast<int>(scale[i - 1]);
              if (i1 != i) {
                blas::xswap(n, V, i, n, i1, n);
              }
            }
          }
        }
      }
    }
  }
}

// End of code generation (xzgebak.cpp)
