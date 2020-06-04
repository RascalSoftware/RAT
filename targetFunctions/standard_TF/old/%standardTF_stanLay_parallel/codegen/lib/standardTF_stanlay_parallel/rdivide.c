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
#include "standardTF_stanlay_parallel.h"
#include "rdivide.h"
#include "standardTF_stanlay_parallel_emxutil.h"

/* Function Definitions */
void rdivide(const emxArray_real_T *x, double y, emxArray_real_T *z)
{
  int i8;
  int loop_ub;
  i8 = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)z, i8, (int)sizeof(double));
  loop_ub = x->size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    z->data[i8] = x->data[i8] / y;
  }
}

/* End of code generation (rdivide.c) */
