/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "sum.h"
#include "eml_int_forloop_overflow_check.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo kb_emlrtRSI = { 20, /* lineNo */
  "sum",                               /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/sum.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 99, /* lineNo */
  "sumprod",                           /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 125,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 185,/* lineNo */
  "colMajorFlatIter",                  /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

static emlrtRSInfo lc_emlrtRSI = { 169,/* lineNo */
  "colMajorFlatIter",                  /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

static emlrtRSInfo mc_emlrtRSI = { 187,/* lineNo */
  "colMajorFlatIter",                  /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

static emlrtRTEInfo ni_emlrtRTEI = { 20,/* lineNo */
  1,                                   /* colNo */
  "sum",                               /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/sum.m"/* pName */
};

static emlrtRTEInfo oi_emlrtRTEI = { 125,/* lineNo */
  13,                                  /* colNo */
  "combineVectorElements",             /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pName */
};

/* Function Definitions */
void b_sum(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  int32_T vlen;
  uint32_T sz_idx_0;
  int32_T vstride;
  int32_T j;
  int32_T xoffset;
  boolean_T overflow;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &lb_emlrtRSI;
  vlen = x->size[1];
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    sz_idx_0 = (uint32_T)x->size[0];
    j = y->size[0];
    y->size[0] = (int32_T)sz_idx_0;
    emxEnsureCapacity_real_T(&b_st, y, j, &ni_emlrtRTEI);
    xoffset = (int32_T)sz_idx_0;
    for (j = 0; j < xoffset; j++) {
      y->data[j] = 0.0;
    }
  } else {
    c_st.site = &mb_emlrtRSI;
    vstride = x->size[0];
    j = y->size[0];
    y->size[0] = x->size[0];
    emxEnsureCapacity_real_T(&c_st, y, j, &oi_emlrtRTEI);
    d_st.site = &lc_emlrtRSI;
    if (x->size[0] > 2147483646) {
      e_st.site = &ob_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (j = 0; j < vstride; j++) {
      y->data[j] = x->data[j];
    }

    d_st.site = &nb_emlrtRSI;
    overflow = ((2 <= x->size[1]) && (x->size[1] > 2147483646));
    if (overflow) {
      e_st.site = &ob_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (k = 2; k <= vlen; k++) {
      xoffset = (k - 1) * vstride;
      d_st.site = &mc_emlrtRSI;
      if (vstride > 2147483646) {
        e_st.site = &ob_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }

      for (j = 0; j < vstride; j++) {
        y->data[j] += x->data[xoffset + j];
      }
    }
  }
}

real_T sum(const emlrtStack *sp, const emxArray_real_T *x)
{
  real_T y;
  int32_T vlen;
  boolean_T overflow;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &lb_emlrtRSI;
  vlen = x->size[0];
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    c_st.site = &mb_emlrtRSI;
    y = x->data[0];
    d_st.site = &nb_emlrtRSI;
    overflow = ((2 <= x->size[0]) && (x->size[0] > 2147483646));
    if (overflow) {
      e_st.site = &ob_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (k = 2; k <= vlen; k++) {
      y += x->data[k - 1];
    }
  }

  return y;
}

/* End of code generation (sum.c) */
