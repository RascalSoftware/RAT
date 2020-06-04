/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "resampleLayers.h"
#include "sum.h"

/* Function Definitions */
double sum(const emxArray_real_T *x)
{
  double y;
  int k;
  y = x->data[0];
  for (k = 2; k <= x->size[1]; k++) {
    y += x->data[k - 1];
  }

  return y;
}

/* End of code generation (sum.c) */
