/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * sortrows.c
 *
 * Code generation for function 'sortrows'
 *
 */

/* Include files */
#include "sortrows.h"
#include "eml_int_forloop_overflow_check.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "sortLE.h"

/* Variable Definitions */
static emlrtRSInfo vf_emlrtRSI =
    {
        24,         /* lineNo */
        "sortrows", /* fcnName */
        "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/"
        "sortrows.m" /* pathName */
};

static emlrtRSInfo wf_emlrtRSI =
    {
        27,         /* lineNo */
        "sortrows", /* fcnName */
        "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/"
        "sortrows.m" /* pathName */
};

static emlrtRSInfo xf_emlrtRSI =
    {
        28,         /* lineNo */
        "sortrows", /* fcnName */
        "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/"
        "sortrows.m" /* pathName */
};

static emlrtRSInfo yf_emlrtRSI = {
    95,                     /* lineNo */
    "parseSortrowsOptions", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "parseSortrowsOptions.m" /* pathName */
};

static emlrtRSInfo ag_emlrtRSI =
    {
        82,        /* lineNo */
        "sortIdx", /* fcnName */
        "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
        "sortIdx.m" /* pathName */
};

static emlrtRSInfo bg_emlrtRSI =
    {
        86,        /* lineNo */
        "sortIdx", /* fcnName */
        "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
        "sortIdx.m" /* pathName */
};

static emlrtRSInfo cg_emlrtRSI = {
    57,          /* lineNo */
    "mergesort", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "mergesort.m" /* pathName */
};

static emlrtRSInfo dg_emlrtRSI = {
    58,          /* lineNo */
    "mergesort", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "mergesort.m" /* pathName */
};

static emlrtRSInfo eg_emlrtRSI = {
    85,          /* lineNo */
    "mergesort", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "mergesort.m" /* pathName */
};

static emlrtRSInfo fg_emlrtRSI = {
    113,         /* lineNo */
    "mergesort", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "mergesort.m" /* pathName */
};

static emlrtRSInfo ig_emlrtRSI =
    {
        38,                      /* lineNo */
        "apply_row_permutation", /* fcnName */
        "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/"
        "sortrows.m" /* pathName */
};

static emlrtRSInfo jg_emlrtRSI =
    {
        39,                      /* lineNo */
        "apply_row_permutation", /* fcnName */
        "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/"
        "sortrows.m" /* pathName */
};

static emlrtRSInfo kg_emlrtRSI =
    {
        42,                      /* lineNo */
        "apply_row_permutation", /* fcnName */
        "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/"
        "sortrows.m" /* pathName */
};

static emlrtRTEInfo ys_emlrtRTEI =
    {
        27,         /* lineNo */
        1,          /* colNo */
        "sortrows", /* fName */
        "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/"
        "sortrows.m" /* pName */
};

static emlrtRTEInfo at_emlrtRTEI = {
    52,          /* lineNo */
    9,           /* colNo */
    "mergesort", /* fName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "mergesort.m" /* pName */
};

static emlrtRTEInfo bt_emlrtRTEI =
    {
        37,         /* lineNo */
        23,         /* colNo */
        "sortrows", /* fName */
        "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/"
        "sortrows.m" /* pName */
};

static emlrtRTEInfo ct_emlrtRTEI =
    {
        37,         /* lineNo */
        1,          /* colNo */
        "sortrows", /* fName */
        "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/"
        "sortrows.m" /* pName */
};

static emlrtRTEInfo dt_emlrtRTEI = {
    52,          /* lineNo */
    1,           /* colNo */
    "mergesort", /* fName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "mergesort.m" /* pName */
};

/* Function Definitions */
void sortrows(const emlrtStack *sp, emxArray_real_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_int32_T *idx;
  emxArray_int32_T *iwork;
  emxArray_real_T *ycol;
  int32_T col_data[2];
  int32_T i;
  int32_T i2;
  int32_T j;
  int32_T k;
  int32_T kEnd;
  int32_T n;
  int32_T p;
  int32_T pEnd;
  int32_T q;
  int32_T qEnd;
  boolean_T b_overflow;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_int32_T(sp, &idx, 1, &ys_emlrtRTEI, true);
  st.site = &vf_emlrtRSI;
  b_st.site = &yf_emlrtRSI;
  col_data[0] = 1;
  col_data[1] = 2;
  st.site = &wf_emlrtRSI;
  n = y->size[0] + 1;
  pEnd = idx->size[0];
  idx->size[0] = y->size[0];
  emxEnsureCapacity_int32_T(&st, idx, pEnd, &ys_emlrtRTEI);
  i2 = y->size[0];
  for (pEnd = 0; pEnd < i2; pEnd++) {
    idx->data[pEnd] = 0;
  }
  if (y->size[0] == 0) {
    b_st.site = &ag_emlrtRSI;
    if ((1 <= y->size[0]) && (y->size[0] > 2147483646)) {
      c_st.site = &j_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (k = 0; k <= n - 2; k++) {
      idx->data[k] = k + 1;
    }
  } else {
    emxInit_int32_T(&st, &iwork, 1, &dt_emlrtRTEI, true);
    b_st.site = &bg_emlrtRSI;
    pEnd = iwork->size[0];
    iwork->size[0] = y->size[0];
    emxEnsureCapacity_int32_T(&b_st, iwork, pEnd, &at_emlrtRTEI);
    i2 = y->size[0] - 1;
    c_st.site = &cg_emlrtRSI;
    if ((1 <= y->size[0] - 1) && (y->size[0] - 1 > 2147483645)) {
      d_st.site = &j_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (k = 1; k <= i2; k += 2) {
      c_st.site = &dg_emlrtRSI;
      if (sortLE(y, col_data, k, k + 1)) {
        idx->data[k - 1] = k;
        idx->data[k] = k + 1;
      } else {
        idx->data[k - 1] = k + 1;
        idx->data[k] = k;
      }
    }
    if ((y->size[0] & 1) != 0) {
      idx->data[y->size[0] - 1] = y->size[0];
    }
    i = 2;
    while (i < n - 1) {
      i2 = i << 1;
      j = 1;
      for (pEnd = i + 1; pEnd < n; pEnd = qEnd + i) {
        p = j;
        q = pEnd;
        qEnd = j + i2;
        if (qEnd > n) {
          qEnd = n;
        }
        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          c_st.site = &eg_emlrtRSI;
          if (sortLE(y, col_data, idx->data[p - 1], idx->data[q - 1])) {
            iwork->data[k] = idx->data[p - 1];
            p++;
            if (p == pEnd) {
              while (q < qEnd) {
                k++;
                iwork->data[k] = idx->data[q - 1];
                q++;
              }
            }
          } else {
            iwork->data[k] = idx->data[q - 1];
            q++;
            if (q == qEnd) {
              while (p < pEnd) {
                k++;
                iwork->data[k] = idx->data[p - 1];
                p++;
              }
            }
          }
          k++;
        }
        c_st.site = &fg_emlrtRSI;
        for (k = 0; k < kEnd; k++) {
          idx->data[(j + k) - 1] = iwork->data[k];
        }
        j = qEnd;
      }
      i = i2;
    }
    emxFree_int32_T(&iwork);
  }
  emxInit_real_T(&st, &ycol, 1, &ct_emlrtRTEI, true);
  st.site = &xf_emlrtRSI;
  i2 = y->size[0];
  pEnd = ycol->size[0];
  ycol->size[0] = y->size[0];
  emxEnsureCapacity_real_T(&st, ycol, pEnd, &bt_emlrtRTEI);
  b_st.site = &ig_emlrtRSI;
  overflow = ((1 <= i2) && (i2 > 2147483646));
  b_overflow = ((1 <= i2) && (i2 > 2147483646));
  for (j = 0; j < 2; j++) {
    b_st.site = &jg_emlrtRSI;
    if (overflow) {
      c_st.site = &j_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (i = 0; i < i2; i++) {
      ycol->data[i] = y->data[(idx->data[i] + y->size[0] * j) - 1];
    }
    b_st.site = &kg_emlrtRSI;
    if (b_overflow) {
      c_st.site = &j_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (i = 0; i < i2; i++) {
      y->data[i + y->size[0] * j] = ycol->data[i];
    }
  }
  emxFree_real_T(&ycol);
  emxFree_int32_T(&idx);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (sortrows.c) */
