/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * randperm.c
 *
 * Code generation for function 'randperm'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "linear_DE_new_test.h"
#include "randperm.h"
#include "rand.h"

/* Function Definitions */
void b_randperm(double p_data[], int p_size[2])
{
  double tmp_data[20];
  int tmp_size[2];
  int loop_ub;
  int i;
  int iwork_data[20];
  int idx_data[20];
  int i2;
  int j;
  int pEnd;
  int p;
  int q;
  int qEnd;
  int kEnd;
  b_rand(20.0, tmp_data, tmp_size);
  p_size[0] = 1;
  p_size[1] = tmp_size[1];
  loop_ub = tmp_size[0] * tmp_size[1];
  for (i = 0; i < loop_ub; i++) {
    p_data[i] = tmp_data[i];
  }

  for (loop_ub = 0; loop_ub <= 18; loop_ub += 2) {
    if (p_data[loop_ub] <= p_data[loop_ub + 1]) {
      idx_data[loop_ub] = loop_ub + 1;
      idx_data[loop_ub + 1] = loop_ub + 2;
    } else {
      idx_data[loop_ub] = loop_ub + 2;
      idx_data[loop_ub + 1] = loop_ub + 1;
    }
  }

  i = 2;
  while (i < 20) {
    i2 = i << 1;
    j = 1;
    for (pEnd = 1 + i; pEnd < 21; pEnd = qEnd + i) {
      p = j;
      q = pEnd;
      qEnd = j + i2;
      if (qEnd > 21) {
        qEnd = 21;
      }

      loop_ub = 0;
      kEnd = qEnd - j;
      while (loop_ub + 1 <= kEnd) {
        if (p_data[idx_data[p - 1] - 1] <= p_data[idx_data[q - 1] - 1]) {
          iwork_data[loop_ub] = idx_data[p - 1];
          p++;
          if (p == pEnd) {
            while (q < qEnd) {
              loop_ub++;
              iwork_data[loop_ub] = idx_data[q - 1];
              q++;
            }
          }
        } else {
          iwork_data[loop_ub] = idx_data[q - 1];
          q++;
          if (q == qEnd) {
            while (p < pEnd) {
              loop_ub++;
              iwork_data[loop_ub] = idx_data[p - 1];
              p++;
            }
          }
        }

        loop_ub++;
      }

      for (loop_ub = 0; loop_ub + 1 <= kEnd; loop_ub++) {
        idx_data[(j + loop_ub) - 1] = iwork_data[loop_ub];
      }

      j = qEnd;
    }

    i = i2;
  }

  for (i = 0; i < 2; i++) {
    tmp_size[i] = p_size[i];
  }

  p_size[0] = 1;
  p_size[1] = 20;
  for (i = 0; i < 20; i++) {
    p_data[i] = idx_data[tmp_size[0] * i];
  }
}

void randperm(double p[4])
{
  int iwork[4];
  int idx[4];
  int k;
  int i;
  int i2;
  int j;
  int pEnd;
  int b_p;
  int q;
  int qEnd;
  int kEnd;
  c_rand(p);
  for (k = 0; k <= 3; k += 2) {
    if (p[k] <= p[k + 1]) {
      idx[k] = k + 1;
      idx[k + 1] = k + 2;
    } else {
      idx[k] = k + 2;
      idx[k + 1] = k + 1;
    }
  }

  i = 2;
  while (i < 4) {
    i2 = i << 1;
    j = 1;
    for (pEnd = 1 + i; pEnd < 5; pEnd = qEnd + i) {
      b_p = j;
      q = pEnd;
      qEnd = j + i2;
      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        if (p[idx[b_p - 1] - 1] <= p[idx[q - 1] - 1]) {
          iwork[k] = idx[b_p - 1];
          b_p++;
          if (b_p == pEnd) {
            while (q < qEnd) {
              k++;
              iwork[k] = idx[q - 1];
              q++;
            }
          }
        } else {
          iwork[k] = idx[q - 1];
          q++;
          if (q == qEnd) {
            while (b_p < pEnd) {
              k++;
              iwork[k] = idx[b_p - 1];
              b_p++;
            }
          }
        }

        k++;
      }

      for (k = 0; k + 1 <= kEnd; k++) {
        idx[(j + k) - 1] = iwork[k];
      }

      j = qEnd;
    }

    i = i2;
  }

  for (k = 0; k < 4; k++) {
    p[k] = idx[k];
  }
}

/* End of code generation (randperm.c) */
