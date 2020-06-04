/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * mean.c
 *
 * Code generation for function 'mean'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_custlay_single.h"
#include "mean.h"

/* Function Definitions */
double mean(const emxArray_real_T *x)
{
  double y;
  int k;
  y = x->data[0];
  for (k = 2; k <= x->size[1]; k++) {
    y += x->data[k - 1];
  }

  y /= (double)x->size[1];
  return y;
}

/* End of code generation (mean.c) */
