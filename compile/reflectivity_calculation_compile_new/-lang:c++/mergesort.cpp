//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: mergesort.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "mergesort.h"
#include "rt_nonfinite.h"
#include "sortLE.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : ::coder::array<int32_T, 1U> &idx
//                const ::coder::array<real_T, 2U> &x
//                const int32_T dir_data[]
//                int32_T n
// Return Type  : void
//
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      void b_mergesort(::coder::array<int32_T, 1U> &idx, const ::coder::array<
                       real_T, 2U> &x, const int32_T dir_data[], int32_T n)
      {
        ::coder::array<int32_T, 1U> iwork;
        int32_T b_i;
        int32_T i;
        int32_T k;
        int32_T qEnd;
        iwork.set_size(idx.size(0));
        i = n - 1;
        for (k = 1; k <= i; k += 2) {
          if (sortLE(x, dir_data, k, k + 1)) {
            idx[k - 1] = k;
            idx[k] = k + 1;
          } else {
            idx[k - 1] = k + 1;
            idx[k] = k;
          }
        }

        if ((n & 1) != 0) {
          idx[n - 1] = n;
        }

        b_i = 2;
        while (b_i < n) {
          int32_T i2;
          int32_T j;
          i2 = b_i << 1;
          j = 1;
          for (int32_T pEnd{b_i + 1}; pEnd < n + 1; pEnd = qEnd + b_i) {
            int32_T kEnd;
            int32_T p;
            int32_T q;
            p = j;
            q = pEnd;
            qEnd = j + i2;
            if (qEnd > n + 1) {
              qEnd = n + 1;
            }

            k = 0;
            kEnd = qEnd - j;
            while (k + 1 <= kEnd) {
              int32_T i1;
              i = idx[q - 1];
              i1 = idx[p - 1];
              if (sortLE(x, dir_data, i1, i)) {
                iwork[k] = i1;
                p++;
                if (p == pEnd) {
                  while (q < qEnd) {
                    k++;
                    iwork[k] = idx[q - 1];
                    q++;
                  }
                }
              } else {
                iwork[k] = i;
                q++;
                if (q == qEnd) {
                  while (p < pEnd) {
                    k++;
                    iwork[k] = idx[p - 1];
                    p++;
                  }
                }
              }

              k++;
            }

            for (k = 0; k < kEnd; k++) {
              idx[(j + k) - 1] = iwork[k];
            }

            j = qEnd;
          }

          b_i = i2;
        }
      }
    }
  }
}

//
// File trailer for mergesort.cpp
//
// [EOF]
//
