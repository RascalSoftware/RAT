/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "resampleLayers_new.h"
#include "power.h"
#include "resampleLayers_new_emxutil.h"

/* Function Definitions */
void power(const emxArray_real_T *a, emxArray_real_T *y)
{
  unsigned int a_idx_0;
  int nx;
  int k;
  a_idx_0 = (unsigned int)a->size[0];
  nx = y->size[0];
  y->size[0] = (int)a_idx_0;
  emxEnsureCapacity_real_T(y, nx);
  a_idx_0 = (unsigned int)a->size[0];
  nx = (int)a_idx_0;
  for (k = 0; k < nx; k++) {
    y->data[k] = a->data[k] * a->data[k];
  }
}

/* End of code generation (power.c) */
