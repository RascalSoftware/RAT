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
#include "power.h"
#include "eml_int_forloop_overflow_check.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo oc_emlrtRSI =
    {
        71,      /* lineNo */
        "power", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\power.m" /* pathName
                                                                          */
};

static emlrtRSInfo pc_emlrtRSI =
    {
        80,         /* lineNo */
        "fltpower", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\power.m" /* pathName
                                                                          */
};

static emlrtRSInfo nf_emlrtRSI = {
    200,        /* lineNo */
    "flatIter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyBinaryScalarFunction.m" /* pathName */
};

static emlrtRTEInfo uk_emlrtRTEI = {
    127,                         /* lineNo */
    6,                           /* colNo */
    "applyBinaryScalarFunction", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyBinaryScalarFunction.m" /* pName */
};

/* Function Definitions */
void power(const emlrtStack *sp, const emxArray_real_T *a, emxArray_real_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  int32_T k;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &oc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  b_st.site = &pc_emlrtRSI;
  c_st.site = &if_emlrtRSI;
  d_st.site = &kf_emlrtRSI;
  nx = y->size[0];
  y->size[0] = a->size[0];
  emxEnsureCapacity_real_T(&d_st, y, nx, &uk_emlrtRTEI);
  nx = a->size[0];
  e_st.site = &nf_emlrtRSI;
  if ((1 <= a->size[0]) && (a->size[0] > 2147483646)) {
    f_st.site = &j_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }
  for (k = 0; k < nx; k++) {
    y->data[k] = a->data[k] * a->data[k];
  }
}

/* End of code generation (power.c) */
