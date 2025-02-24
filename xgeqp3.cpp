//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
          int k;
          int minmana;
          int n;
          boolean_T guard1{ false };

          n = A.size(1) - 1;
          k = A.size(0);
          minmana = A.size(1);
          if (k < minmana) {
            minmana = k;
          }

          tau.set_size(minmana);
          for (k = 0; k < minmana; k++) {
            tau[k] = 0.0;
          }

          guard1 = false;
          if ((A.size(0) == 0) || (A.size(1) == 0)) {
            guard1 = true;
          } else {
            k = A.size(0);
            minmana = A.size(1);
            if (k < minmana) {
              minmana = k;
            }

            if (minmana < 1) {
              guard1 = true;
            } else {
              minmana = A.size(1);
              jpvt.set_size(1, minmana);
              for (k = 0; k < minmana; k++) {
                jpvt[k] = 0;
              }

              for (k = 0; k <= n; k++) {
                jpvt[k] = k + 1;
              }

              reflapack::qrpf(A, A.size(0), A.size(1), tau, jpvt);
            }
          }

          if (guard1) {
            minmana = A.size(1);
            jpvt.set_size(1, minmana);
            for (k = 0; k < minmana; k++) {
              jpvt[k] = 0;
            }

            for (minmana = 0; minmana <= n; minmana++) {
              jpvt[minmana] = minmana + 1;
            }
          }
        }
      }
    }
  }
}

// End of code generation (xgeqp3.cpp)
