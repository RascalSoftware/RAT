//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// mergesort.cpp
//
// Code generation for function 'mergesort'
//

// Include files
#include "mergesort.h"
#include "rt_nonfinite.h"
#include "sortLE.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      void b_mergesort(int32_T idx[4], const real_T x[4])
      {
        int32_T iwork[4];
        int32_T j;
        int32_T qEnd;
        if (sortLE(x, 1, 2)) {
          idx[0] = 1;
          idx[1] = 2;
        } else {
          idx[0] = 2;
          idx[1] = 1;
        }

        if (sortLE(x, 3, 4)) {
          idx[2] = 3;
          idx[3] = 4;
        } else {
          idx[2] = 4;
          idx[3] = 3;
        }

        j = 1;
        for (int32_T pEnd{3}; pEnd < 5; pEnd = qEnd + 2) {
          int32_T k;
          int32_T p;
          int32_T q;
          p = j;
          q = pEnd;
          qEnd = j + 4;
          k = 0;
          while (k + 1 <= 4) {
            int32_T i;
            int32_T i1;
            i = idx[q - 1];
            i1 = idx[p - 1];
            if (sortLE(x, i1, i)) {
              iwork[k] = i1;
              p++;
              if (p == pEnd) {
                while (q < j + 4) {
                  k++;
                  iwork[k] = idx[q - 1];
                  q++;
                }
              }
            } else {
              iwork[k] = i;
              q++;
              if (q == j + 4) {
                while (p < pEnd) {
                  k++;
                  iwork[k] = idx[p - 1];
                  p++;
                }
              }
            }

            k++;
          }

          for (k = 0; k < 4; k++) {
            idx[(j + k) - 1] = iwork[k];
          }

          j += 4;
        }
      }

      void b_mergesort(::coder::array<int32_T, 2U> &idx, const ::coder::array<
                       real_T, 2U> &x, int32_T n)
      {
        ::coder::array<int32_T, 1U> iwork;
        int32_T b_i;
        int32_T i;
        int32_T k;
        int32_T qEnd;
        iwork.set_size(idx.size(1));
        i = n - 1;
        for (k = 1; k <= i; k += 2) {
          if (b_sortLE(x, k, k + 1)) {
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
              if (b_sortLE(x, i1, i)) {
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

      void b_mergesort(::coder::array<int32_T, 1U> &idx, const ::coder::array<
                       real_T, 1U> &x, int32_T n)
      {
        ::coder::array<int32_T, 1U> iwork;
        int32_T b_i;
        int32_T i;
        int32_T k;
        int32_T qEnd;
        iwork.set_size(idx.size(0));
        i = n - 1;
        for (k = 1; k <= i; k += 2) {
          if (sortLE(x, k, k + 1)) {
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
              if (sortLE(x, i1, i)) {
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

      void b_mergesort(::coder::array<int32_T, 1U> &idx, const ::coder::array<
                       real_T, 2U> &x, int32_T n)
      {
        ::coder::array<int32_T, 1U> iwork;
        int32_T b_i;
        int32_T i;
        int32_T k;
        int32_T qEnd;
        iwork.set_size(idx.size(0));
        i = n - 1;
        for (k = 1; k <= i; k += 2) {
          if (sortLE(x, k, k + 1)) {
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
              if (sortLE(x, i1, i)) {
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

// End of code generation (mergesort.cpp)
