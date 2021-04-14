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
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo bc_emlrtRSI = { 70, /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 79, /* lineNo */
  "fltpower",                          /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo ne_emlrtRSI = { 66, /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo oe_emlrtRSI = { 188,/* lineNo */
  "flatIter",                          /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRTEInfo rj_emlrtRTEI = { 79,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/power.m"/* pName */
};

/* Function Definitions */
void power(const emlrtStack *sp, const emxArray_real_T *a, emxArray_real_T *y)
{
  int32_T nx;
  boolean_T overflow;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &cc_emlrtRSI;
  nx = y->size[0];
  y->size[0] = a->size[0];
  emxEnsureCapacity_real_T(&b_st, y, nx, &rj_emlrtRTEI);
  c_st.site = &ne_emlrtRSI;
  nx = a->size[0];
  d_st.site = &oe_emlrtRSI;
  overflow = ((1 <= a->size[0]) && (a->size[0] > 2147483646));
  if (overflow) {
    e_st.site = &yb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (k = 0; k < nx; k++) {
    y->data[k] = muDoubleScalarPower(a->data[k], 2.0);
  }
}

/* End of code generation (power.c) */
