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
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo gc_emlrtRSI = { 70, /* lineNo */
  "power",                             /* fcnName */
  "/opt/matlab2020b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 79, /* lineNo */
  "fltpower",                          /* fcnName */
  "/opt/matlab2020b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo ue_emlrtRSI = { 66, /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo ve_emlrtRSI = { 188,/* lineNo */
  "flatIter",                          /* fcnName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRTEInfo uk_emlrtRTEI = { 46,/* lineNo */
  6,                                   /* colNo */
  "applyBinaryScalarFunction",         /* fName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"/* pName */
};

/* Function Definitions */
void power(const emlrtStack *sp, const emxArray_real_T *a, emxArray_real_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T k;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &gc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &hc_emlrtRSI;
  nx = y->size[0];
  y->size[0] = a->size[0];
  emxEnsureCapacity_real_T(&b_st, y, nx, &uk_emlrtRTEI);
  c_st.site = &ue_emlrtRSI;
  nx = a->size[0];
  d_st.site = &ve_emlrtRSI;
  if ((1 <= a->size[0]) && (a->size[0] > 2147483646)) {
    e_st.site = &j_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (k = 0; k < nx; k++) {
    y->data[k] = muDoubleScalarPower(a->data[k], 2.0);
  }
}

/* End of code generation (power.c) */
