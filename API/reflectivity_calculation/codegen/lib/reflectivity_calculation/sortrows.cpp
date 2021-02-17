//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: sortrows.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//

// Include Files
#include "sortrows.h"
#include "chiSquared.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"
#include "sortLE.h"
#include "standardTF_custXY_reflectivityCalculation.h"

// Function Definitions

//
// Arguments    : coder::array<double, 2U> *y
// Return Type  : void
//
void sortrows(coder::array<double, 2U> &y)
{
  int col_data[2];
  int n;
  coder::array<int, 1U> idx;
  int i2;
  int i;
  coder::array<int, 1U> iwork;
  int k;
  coder::array<double, 1U> ycol;
  int b_i;
  int qEnd;
  col_data[0] = 1;
  col_data[1] = 2;
  n = y.size(0) + 1;
  idx.set_size(y.size(0));
  i2 = y.size(0);
  for (i = 0; i < i2; i++) {
    idx[i] = 0;
  }

  if (y.size(0) == 0) {
    for (k = 0; k <= n - 2; k++) {
      idx[k] = k + 1;
    }
  } else {
    iwork.set_size(y.size(0));
    i = y.size(0) - 1;
    for (k = 1; k <= i; k += 2) {
      if (sortLE(y, col_data, k, k + 1)) {
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
      int j;
      i2 = b_i << 1;
      j = 1;
      for (int pEnd = b_i + 1; pEnd < n; pEnd = qEnd + b_i) {
        int p;
        int q;
        int kEnd;
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
          if (sortLE(y, col_data, i1, i)) {
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
  for (b_i = 0; b_i <= i2; b_i++) {
    ycol[b_i] = y[idx[b_i] - 1];
  }

  for (b_i = 0; b_i <= i2; b_i++) {
    y[b_i] = ycol[b_i];
  }

  for (b_i = 0; b_i <= i2; b_i++) {
    ycol[b_i] = y[(idx[b_i] + y.size(0)) - 1];
  }

  for (b_i = 0; b_i <= i2; b_i++) {
    y[b_i + y.size(0)] = ycol[b_i];
  }
}

//
// File trailer for sortrows.cpp
//
// [EOF]
//
