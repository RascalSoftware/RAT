/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
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
static emlrtRSInfo pf_emlrtRSI = {
    24,         /* lineNo */
    "sortrows", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/datafun/sortrows.m" /* pathName
                                                                          */
};

static emlrtRSInfo qf_emlrtRSI = {
    27,         /* lineNo */
    "sortrows", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/datafun/sortrows.m" /* pathName
                                                                          */
};

static emlrtRSInfo rf_emlrtRSI = {
    28,         /* lineNo */
    "sortrows", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/datafun/sortrows.m" /* pathName
                                                                          */
};

static emlrtRSInfo sf_emlrtRSI = {
    95,                     /* lineNo */
    "parseSortrowsOptions", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/"
    "parseSortrowsOptions.m" /* pathName */
};

static emlrtRSInfo tf_emlrtRSI = {
    82,        /* lineNo */
    "sortIdx", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

static emlrtRSInfo uf_emlrtRSI = {
    86,        /* lineNo */
    "sortIdx", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                           */
};

static emlrtRSInfo
    vf_emlrtRSI =
        {
            57,          /* lineNo */
            "mergesort", /* fcnName */
            "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/"
            "mergesort.m" /* pathName */
};

static emlrtRSInfo
    wf_emlrtRSI =
        {
            58,          /* lineNo */
            "mergesort", /* fcnName */
            "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/"
            "mergesort.m" /* pathName */
};

static emlrtRSInfo
    xf_emlrtRSI =
        {
            85,          /* lineNo */
            "mergesort", /* fcnName */
            "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/"
            "mergesort.m" /* pathName */
};

static emlrtRSInfo
    yf_emlrtRSI =
        {
            113,         /* lineNo */
            "mergesort", /* fcnName */
            "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/"
            "mergesort.m" /* pathName */
};

static emlrtRSInfo cg_emlrtRSI = {
    38,                      /* lineNo */
    "apply_row_permutation", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/datafun/sortrows.m" /* pathName
                                                                          */
};

static emlrtRSInfo dg_emlrtRSI = {
    39,                      /* lineNo */
    "apply_row_permutation", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/datafun/sortrows.m" /* pathName
                                                                          */
};

static emlrtRSInfo eg_emlrtRSI = {
    42,                      /* lineNo */
    "apply_row_permutation", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/datafun/sortrows.m" /* pathName
                                                                          */
};

static emlrtRTEInfo ht_emlrtRTEI = {
    27,         /* lineNo */
    1,          /* colNo */
    "sortrows", /* fName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/datafun/sortrows.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    it_emlrtRTEI =
        {
            52,          /* lineNo */
            9,           /* colNo */
            "mergesort", /* fName */
            "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/"
            "mergesort.m" /* pName */
};

static emlrtRTEInfo jt_emlrtRTEI = {
    37,         /* lineNo */
    23,         /* colNo */
    "sortrows", /* fName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/datafun/sortrows.m" /* pName
                                                                          */
};

static emlrtRTEInfo kt_emlrtRTEI = {
    37,         /* lineNo */
    1,          /* colNo */
    "sortrows", /* fName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/datafun/sortrows.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    lt_emlrtRTEI =
        {
            52,          /* lineNo */
            1,           /* colNo */
            "mergesort", /* fName */
            "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/"
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
  real_T *y_data;
  real_T *ycol_data;
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
  int32_T *idx_data;
  int32_T *iwork_data;
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
  y_data = y->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_int32_T(sp, &idx, &ht_emlrtRTEI);
  st.site = &pf_emlrtRSI;
  b_st.site = &sf_emlrtRSI;
  col_data[0] = 1;
  col_data[1] = 2;
  st.site = &qf_emlrtRSI;
  n = y->size[0] + 1;
  pEnd = idx->size[0];
  idx->size[0] = y->size[0];
  emxEnsureCapacity_int32_T(&st, idx, pEnd, &ht_emlrtRTEI);
  idx_data = idx->data;
  i2 = y->size[0];
  for (pEnd = 0; pEnd < i2; pEnd++) {
    idx_data[pEnd] = 0;
  }
  if (y->size[0] == 0) {
    b_st.site = &tf_emlrtRSI;
    if ((1 <= y->size[0]) && (y->size[0] > 2147483646)) {
      c_st.site = &j_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (k = 0; k <= n - 2; k++) {
      idx_data[k] = k + 1;
    }
  } else {
    emxInit_int32_T(&st, &iwork, &lt_emlrtRTEI);
    b_st.site = &uf_emlrtRSI;
    pEnd = iwork->size[0];
    iwork->size[0] = y->size[0];
    emxEnsureCapacity_int32_T(&b_st, iwork, pEnd, &it_emlrtRTEI);
    iwork_data = iwork->data;
    i2 = y->size[0] - 1;
    c_st.site = &vf_emlrtRSI;
    if ((1 <= y->size[0] - 1) && (y->size[0] - 1 > 2147483645)) {
      d_st.site = &j_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (k = 1; k <= i2; k += 2) {
      c_st.site = &wf_emlrtRSI;
      if (sortLE(y, col_data, k, k + 1)) {
        idx_data[k - 1] = k;
        idx_data[k] = k + 1;
      } else {
        idx_data[k - 1] = k + 1;
        idx_data[k] = k;
      }
    }
    if ((y->size[0] & 1) != 0) {
      idx_data[y->size[0] - 1] = y->size[0];
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
          c_st.site = &xf_emlrtRSI;
          if (sortLE(y, col_data, idx_data[p - 1], idx_data[q - 1])) {
            iwork_data[k] = idx_data[p - 1];
            p++;
            if (p == pEnd) {
              while (q < qEnd) {
                k++;
                iwork_data[k] = idx_data[q - 1];
                q++;
              }
            }
          } else {
            iwork_data[k] = idx_data[q - 1];
            q++;
            if (q == qEnd) {
              while (p < pEnd) {
                k++;
                iwork_data[k] = idx_data[p - 1];
                p++;
              }
            }
          }
          k++;
        }
        c_st.site = &yf_emlrtRSI;
        for (k = 0; k < kEnd; k++) {
          idx_data[(j + k) - 1] = iwork_data[k];
        }
        j = qEnd;
      }
      i = i2;
    }
    emxFree_int32_T(&b_st, &iwork);
  }
  emxInit_real_T(&st, &ycol, 1, &kt_emlrtRTEI, true);
  st.site = &rf_emlrtRSI;
  i2 = y->size[0];
  pEnd = ycol->size[0];
  ycol->size[0] = y->size[0];
  emxEnsureCapacity_real_T(&st, ycol, pEnd, &jt_emlrtRTEI);
  ycol_data = ycol->data;
  b_st.site = &cg_emlrtRSI;
  overflow = ((1 <= i2) && (i2 > 2147483646));
  b_overflow = ((1 <= i2) && (i2 > 2147483646));
  for (j = 0; j < 2; j++) {
    b_st.site = &dg_emlrtRSI;
    if (overflow) {
      c_st.site = &j_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (i = 0; i < i2; i++) {
      ycol_data[i] = y_data[(idx_data[i] + y->size[0] * j) - 1];
    }
    b_st.site = &eg_emlrtRSI;
    if (b_overflow) {
      c_st.site = &j_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (i = 0; i < i2; i++) {
      y_data[i + y->size[0] * j] = ycol_data[i];
    }
  }
  emxFree_real_T(&st, &ycol);
  emxFree_int32_T(&st, &idx);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (sortrows.c) */
