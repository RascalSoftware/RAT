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

/* Variable Definitions */
static emlrtRTEInfo cc_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "rdivide",                           /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/rdivide.m"/* pName */
};

/* Function Definitions */
void rdivide(const emlrtStack *sp, const emxArray_real_T *x, real_T y,
             emxArray_real_T *z)
{
  int32_T i21;
  int32_T loop_ub;
  i21 = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)z, i21, (int32_T)sizeof(real_T),
                    &cc_emlrtRTEI);
  loop_ub = x->size[0];
  for (i21 = 0; i21 < loop_ub; i21++) {
    z->data[i21] = x->data[i21] / y;
  }
}

/* End of code generation (rdivide.c) */
