/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * rdivide.c
 *
 * Code generation for function 'rdivide'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "reflectivity_calculation.h"
#include "rdivide.h"
#include "reflectivity_calculation_emxutil.h"

/* Function Definitions */
void rdivide(const emxArray_real_T *x, double y, emxArray_real_T *z)
{
  int i10;
  int loop_ub;
  i10 = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)z, i10, (int)sizeof(double));
  loop_ub = x->size[0];
  for (i10 = 0; i10 < loop_ub; i10++) {
    z->data[i10] = x->data[i10] / y;
  }
}

/* End of code generation (rdivide.c) */
