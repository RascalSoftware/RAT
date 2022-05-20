/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * div.c
 *
 * Code generation for function 'div'
 *
 */

/* Include files */
#include "div.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo pt_emlrtRTEI = {
    52,    /* lineNo */
    9,     /* colNo */
    "div", /* fName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/div.m" /* pName
                                                                       */
};

/* Function Definitions */
void i_binary_expand_op(const emlrtStack *sp, emxArray_real_T *terms,
                        const emxArray_real_T *thisData)
{
  emxArray_real_T *b_terms;
  const real_T *thisData_data;
  real_T *b_terms_data;
  real_T *terms_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  thisData_data = thisData->data;
  terms_data = terms->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_terms, 1, &pt_emlrtRTEI, true);
  i = thisData->size[0];
  stride_0_0 = b_terms->size[0];
  if (i == 1) {
    b_terms->size[0] = terms->size[0];
  } else {
    b_terms->size[0] = i;
  }
  emxEnsureCapacity_real_T(sp, b_terms, stride_0_0, &pt_emlrtRTEI);
  b_terms_data = b_terms->data;
  stride_0_0 = (terms->size[0] != 1);
  stride_1_0 = (i != 1);
  if (i == 1) {
    loop_ub = terms->size[0];
  } else {
    loop_ub = i;
  }
  for (i = 0; i < loop_ub; i++) {
    b_terms_data[i] = terms_data[i * stride_0_0] /
                      thisData_data[i * stride_1_0 + thisData->size[0] * 2];
  }
  i = terms->size[0];
  terms->size[0] = b_terms->size[0];
  emxEnsureCapacity_real_T(sp, terms, i, &pt_emlrtRTEI);
  terms_data = terms->data;
  loop_ub = b_terms->size[0];
  for (i = 0; i < loop_ub; i++) {
    terms_data[i] = b_terms_data[i];
  }
  emxFree_real_T(sp, &b_terms);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void rdivide(const emlrtStack *sp, emxArray_real_T *normalizedData,
             const emxArray_real_T *XYdata)
{
  emxArray_real_T *b_XYdata;
  const real_T *XYdata_data;
  real_T *b_XYdata_data;
  real_T *normalizedData_data;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  XYdata_data = XYdata->data;
  normalizedData_data = normalizedData->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_XYdata, 2, &pt_emlrtRTEI, true);
  i = b_XYdata->size[0] * b_XYdata->size[1];
  if (normalizedData->size[0] == 1) {
    b_XYdata->size[0] = XYdata->size[0];
  } else {
    b_XYdata->size[0] = normalizedData->size[0];
  }
  b_XYdata->size[1] = 2;
  emxEnsureCapacity_real_T(sp, b_XYdata, i, &pt_emlrtRTEI);
  b_XYdata_data = b_XYdata->data;
  stride_0_0 = (XYdata->size[0] != 1);
  stride_1_0 = (normalizedData->size[0] != 1);
  if (normalizedData->size[0] == 1) {
    loop_ub = XYdata->size[0];
  } else {
    loop_ub = normalizedData->size[0];
  }
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_XYdata_data[i1 + b_XYdata->size[0] * i] =
          XYdata_data[i1 * stride_0_0 + XYdata->size[0] * i] /
          normalizedData_data[i1 * stride_1_0 + normalizedData->size[0] * i];
    }
  }
  i = normalizedData->size[0] * normalizedData->size[1];
  normalizedData->size[0] = b_XYdata->size[0];
  normalizedData->size[1] = 2;
  emxEnsureCapacity_real_T(sp, normalizedData, i, &pt_emlrtRTEI);
  normalizedData_data = normalizedData->data;
  loop_ub = b_XYdata->size[0];
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      normalizedData_data[i1 + normalizedData->size[0] * i] =
          b_XYdata_data[i1 + b_XYdata->size[0] * i];
    }
  }
  emxFree_real_T(sp, &b_XYdata);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (div.c) */
