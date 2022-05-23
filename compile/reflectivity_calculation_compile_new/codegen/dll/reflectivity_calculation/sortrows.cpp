//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sortrows.cpp
//
// Code generation for function 'sortrows'
//

// Include files
#include "sortrows.h"
#include "rt_nonfinite.h"
#include "sortLE.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
void sortrows(::coder::array<double, 2U> &y)
{
  array<double, 1U> ycol;
  array<int, 1U> idx;
  array<int, 1U> iwork;
  int col_data[2];
  int b_i;
  int i;
  int i2;
  int j;
  int n;
  int qEnd;
  col_data[0] = 1;
  col_data[1] = 2;
  n = y.size(0) + 1;
  i2 = y.size(0);
  idx.set_size(i2);
  for (i = 0; i < i2; i++) {
    idx[i] = 0;
  }
  if (y.size(0) == 0) {
    for (int k{0}; k <= n - 2; k++) {
      idx[k] = k + 1;
    }
  } else {
    int k;
    iwork.set_size(y.size(0));
    i = y.size(0) - 1;
    for (k = 1; k <= i; k += 2) {
      if (internal::sortLE(y, col_data, k, k + 1)) {
        idx[k - 1] = k;
        idx[k] = k + 1;
      } else {
        idx[k - 1] = k + 1;
        idx[k] = k;
      }
    }
    if ((y.size(0) & 1) != 0) {
      idx[y.size(0) - 1] = y.size(0);
    }
    b_i = 2;
    while (b_i < n - 1) {
      i2 = b_i << 1;
      j = 1;
      for (int pEnd{b_i + 1}; pEnd < n; pEnd = qEnd + b_i) {
        int kEnd;
        int p;
        int q;
        p = j;
        q = pEnd;
        qEnd = j + i2;
        if (qEnd > n) {
          qEnd = n;
        }
        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          int i1;
          i = idx[q - 1];
          i1 = idx[p - 1];
          if (internal::sortLE(y, col_data, i1, i)) {
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
  i2 = y.size(0) - 1;
  ycol.set_size(y.size(0));
  for (j = 0; j < 2; j++) {
    for (b_i = 0; b_i <= i2; b_i++) {
      ycol[b_i] = y[(idx[b_i] + y.size(0) * j) - 1];
    }
    for (b_i = 0; b_i <= i2; b_i++) {
      y[b_i + y.size(0) * j] = ycol[b_i];
    }
  }
}

} // namespace coder

// End of code generation (sortrows.cpp)
