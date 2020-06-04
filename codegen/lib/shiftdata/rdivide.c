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
#include "shiftdata.h"
#include "rdivide.h"
#include "shiftdata_emxutil.h"

/* Function Definitions */
void rdivide(const emxArray_real_T *x, double y, emxArray_real_T *z)
{
  int i1;
  int loop_ub;
  i1 = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)z, i1, (int)sizeof(double));
  loop_ub = x->size[0];
  for (i1 = 0; i1 < loop_ub; i1++) {
    z->data[i1] = x->data[i1] / y;
  }
}

/* End of code generation (rdivide.c) */
