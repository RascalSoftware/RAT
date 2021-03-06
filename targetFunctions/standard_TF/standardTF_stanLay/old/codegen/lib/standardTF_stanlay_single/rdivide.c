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
#include "standardTF_stanlay_single.h"
#include "rdivide.h"
#include "standardTF_stanlay_single_emxutil.h"

/* Function Definitions */
void rdivide(const emxArray_real_T *x, double y, emxArray_real_T *z)
{
  int i7;
  int loop_ub;
  i7 = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)z, i7, (int)sizeof(double));
  loop_ub = x->size[0];
  for (i7 = 0; i7 < loop_ub; i7++) {
    z->data[i7] = x->data[i7] / y;
  }
}

/* End of code generation (rdivide.c) */
