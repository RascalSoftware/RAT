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
namespace coder {
namespace internal {
void b_mergesort(::coder::array<int, 1U> &idx,
                 const ::coder::array<double, 2U> &x, const int dir_data[],
                 int n)
{
  array<int, 1U> iwork;
  int b_i;
  int i;
  int k;
  int qEnd;
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
    int i2;
    int j;
    i2 = b_i << 1;
    j = 1;
    for (int pEnd{b_i + 1}; pEnd < n + 1; pEnd = qEnd + b_i) {
      int kEnd;
      int p;
      int q;
      p = j;
      q = pEnd;
      qEnd = j + i2;
      if (qEnd > n + 1) {
        qEnd = n + 1;
      }
      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        int i1;
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

} // namespace internal
} // namespace coder

// End of code generation (mergesort.cpp)
