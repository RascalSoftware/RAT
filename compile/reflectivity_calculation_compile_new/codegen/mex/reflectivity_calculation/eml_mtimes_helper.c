/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * eml_mtimes_helper.c
 *
 * Code generation for function 'eml_mtimes_helper'
 *
 */

/* Include files */
#include "eml_mtimes_helper.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo mt_emlrtRTEI =
    {
        76,                  /* lineNo */
        13,                  /* colNo */
        "eml_mtimes_helper", /* fName */
        "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" /* pName */
};

/* Function Definitions */
void b_binary_expand_op(const emlrtStack *sp, emxArray_real_T *f, real_T a,
                        const emxArray_real_T *r1)
{
  emxArray_real_T *b_a;
  const real_T *r;
  real_T *a_data;
  real_T *f_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  r = r1->data;
  f_data = f->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_a, 2, &mt_emlrtRTEI, true);
  i = b_a->size[0] * b_a->size[1];
  b_a->size[0] = 1;
  if (r1->size[1] == 1) {
    b_a->size[1] = f->size[1];
  } else {
    b_a->size[1] = r1->size[1];
  }
  emxEnsureCapacity_real_T(sp, b_a, i, &mt_emlrtRTEI);
  a_data = b_a->data;
  stride_0_1 = (f->size[1] != 1);
  stride_1_1 = (r1->size[1] != 1);
  if (r1->size[1] == 1) {
    loop_ub = f->size[1];
  } else {
    loop_ub = r1->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    a_data[i] = a * (f_data[i * stride_0_1] - r[i * stride_1_1]);
  }
  i = f->size[0] * f->size[1];
  f->size[0] = 1;
  f->size[1] = b_a->size[1];
  emxEnsureCapacity_real_T(sp, f, i, &mt_emlrtRTEI);
  f_data = f->data;
  loop_ub = b_a->size[1];
  for (i = 0; i < loop_ub; i++) {
    f_data[i] = a_data[i];
  }
  emxFree_real_T(sp, &b_a);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void c_binary_expand_op(const emlrtStack *sp, emxArray_real_T *newDomain,
                        const emxArray_real_T *dataPoints,
                        const emxArray_int32_T *r2, const emxArray_int32_T *r3)
{
  const real_T *dataPoints_data;
  real_T *newDomain_data;
  const int32_T *r;
  const int32_T *r1;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  r = r3->data;
  r1 = r2->data;
  dataPoints_data = dataPoints->data;
  i = newDomain->size[0];
  if (r3->size[0] == 1) {
    newDomain->size[0] = r2->size[0];
  } else {
    newDomain->size[0] = r3->size[0];
  }
  emxEnsureCapacity_real_T(sp, newDomain, i, &ij_emlrtRTEI);
  newDomain_data = newDomain->data;
  stride_0_0 = (r2->size[0] != 1);
  stride_1_0 = (r3->size[0] != 1);
  if (r3->size[0] == 1) {
    loop_ub = r2->size[0];
  } else {
    loop_ub = r3->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    newDomain_data[i] = 0.5 * (dataPoints_data[r1[i * stride_0_0] - 1] +
                               dataPoints_data[r[i * stride_1_0] - 1]);
  }
}

/* End of code generation (eml_mtimes_helper.c) */
