//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xzunorgtr.cpp
//
// Code generation for function 'xzunorgtr'
//

// Include files
#include "xzunorgtr.h"
#include "rt_nonfinite.h"
#include "xzungqr.h"
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
        void xzunorgtr(::coder::array<double, 2U> &A, const ::coder::array<
                       double, 1U> &tau)
        {
          int n;
          n = A.size(0);
          if ((A.size(0) != 0) && (A.size(1) != 0)) {
            for (int j{n}; j >= 2; j--) {
              int b_i;
              A[A.size(0) * (j - 1)] = 0.0;
              b_i = j + 1;
              for (int i{b_i}; i <= n; i++) {
                A[(i + A.size(0) * (j - 1)) - 1] = A[(i + A.size(0) * (j - 2)) -
                  1];
              }
            }

            A[0] = 1.0;
            for (int i{2}; i <= n; i++) {
              A[i - 1] = 0.0;
            }

            if (A.size(0) > 1) {
              xzungqr(A.size(0) - 1, A.size(0) - 1, A.size(0) - 1, A, A.size(0)
                      + 2, A.size(0), tau);
            }
          }
        }
      }
    }
  }
}

// End of code generation (xzunorgtr.cpp)
