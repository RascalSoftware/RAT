//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xgeqp3.cpp
//
// Code generation for function 'xgeqp3'
//

// Include files
#include "xgeqp3.h"
#include "rt_nonfinite.h"
#include "xzgeqp3.h"
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
        void xgeqp3(::coder::array<double, 2U> &A, ::coder::array<double, 1U>
                    &tau, ::coder::array<int, 2U> &jpvt)
        {
          int j;
          int k;
          int n;
          n = A.size(1) - 1;
          k = A.size(0);
          j = A.size(1);
          if (k <= j) {
            j = k;
          }

          tau.set_size(j);
          for (int i{0}; i < j; i++) {
            tau[i] = 0.0;
          }

          if ((A.size(0) == 0) || (A.size(1) == 0) || (j < 1)) {
            k = A.size(1);
            jpvt.set_size(1, k);
            for (int i{0}; i < k; i++) {
              jpvt[i] = 0;
            }

            for (j = 0; j <= n; j++) {
              jpvt[j] = j + 1;
            }
          } else {
            k = A.size(1);
            jpvt.set_size(1, k);
            for (int i{0}; i < k; i++) {
              jpvt[i] = 0;
            }

            for (k = 0; k <= n; k++) {
              jpvt[k] = k + 1;
            }

            reflapack::qrpf(A, A.size(0), A.size(1), tau, jpvt);
          }
        }
      }
    }
  }
}

// End of code generation (xgeqp3.cpp)
