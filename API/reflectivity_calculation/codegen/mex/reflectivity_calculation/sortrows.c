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
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"
#include "sortLE.h"

/* Variable Definitions */
static emlrtRSInfo ke_emlrtRSI = { 24, /* lineNo */
  "sortrows",                          /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pathName */
};

static emlrtRSInfo le_emlrtRSI = { 27, /* lineNo */
  "sortrows",                          /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pathName */
};

static emlrtRSInfo me_emlrtRSI = { 28, /* lineNo */
  "sortrows",                          /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pathName */
};

static emlrtRSInfo ne_emlrtRSI = { 95, /* lineNo */
  "parseSortrowsOptions",              /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/parseSortrowsOptions.m"/* pathName */
};

static emlrtRSInfo oe_emlrtRSI = { 82, /* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo pe_emlrtRSI = { 86, /* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo qe_emlrtRSI = { 57, /* lineNo */
  "mergesort",                         /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pathName */
};

static emlrtRSInfo re_emlrtRSI = { 58, /* lineNo */
  "mergesort",                         /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pathName */
};

static emlrtRSInfo se_emlrtRSI = { 85, /* lineNo */
  "mergesort",                         /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pathName */
};

static emlrtRSInfo te_emlrtRSI = { 113,/* lineNo */
  "mergesort",                         /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pathName */
};

static emlrtRSInfo we_emlrtRSI = { 39, /* lineNo */
  "apply_row_permutation",             /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pathName */
};

static emlrtRSInfo xe_emlrtRSI = { 40, /* lineNo */
  "apply_row_permutation",             /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pathName */
};

static emlrtRSInfo ye_emlrtRSI = { 43, /* lineNo */
  "apply_row_permutation",             /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pathName */
};

static emlrtRTEInfo wk_emlrtRTEI = { 27,/* lineNo */
  1,                                   /* colNo */
  "sortrows",                          /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pName */
};

static emlrtRTEInfo xk_emlrtRTEI = { 86,/* lineNo */
  15,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo yk_emlrtRTEI = { 28,/* lineNo */
  5,                                   /* colNo */
  "sortrows",                          /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pName */
};

static emlrtRTEInfo al_emlrtRTEI = { 38,/* lineNo */
  1,                                   /* colNo */
  "sortrows",                          /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pName */
};

static emlrtRTEInfo bl_emlrtRTEI = { 52,/* lineNo */
  1,                                   /* colNo */
  "mergesort",                         /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pName */
};

/* Function Definitions */
void sortrows(const emlrtStack *sp, emxArray_real_T *y)
{
  emxArray_int32_T *idx;
  int32_T col_data[2];
  int32_T n;
  int32_T j;
  int32_T i2;
  emxArray_int32_T *iwork;
  int32_T k;
  emxArray_real_T *ycol;
  int32_T i;
  int32_T pEnd;
  int32_T p;
  int32_T q;
  int32_T qEnd;
  int32_T kEnd;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_int32_T(sp, &idx, 1, &wk_emlrtRTEI, true);
  st.site = &ke_emlrtRSI;
  b_st.site = &ne_emlrtRSI;
  col_data[0] = 1;
  col_data[1] = 2;
  st.site = &le_emlrtRSI;
  n = y->size[0] + 1;
  j = idx->size[0];
  idx->size[0] = y->size[0];
  emxEnsureCapacity_int32_T(&st, idx, j, &wk_emlrtRTEI);
  i2 = y->size[0];
  for (j = 0; j < i2; j++) {
    idx->data[j] = 0;
  }

  if (y->size[0] == 0) {
    b_st.site = &oe_emlrtRSI;
    if ((1 <= y->size[0]) && (y->size[0] > 2147483646)) {
      c_st.site = &lb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (k = 0; k <= n - 2; k++) {
      idx->data[k] = k + 1;
    }
  } else {
    emxInit_int32_T(&st, &iwork, 1, &bl_emlrtRTEI, true);
    b_st.site = &pe_emlrtRSI;
    j = iwork->size[0];
    iwork->size[0] = y->size[0];
    emxEnsureCapacity_int32_T(&b_st, iwork, j, &xk_emlrtRTEI);
    i2 = y->size[0] - 1;
    c_st.site = &qe_emlrtRSI;
    if ((1 <= y->size[0] - 1) && (y->size[0] - 1 > 2147483645)) {
      d_st.site = &lb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 1; k <= i2; k += 2) {
      c_st.site = &re_emlrtRSI;
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
          c_st.site = &se_emlrtRSI;
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

        c_st.site = &te_emlrtRSI;
        for (k = 0; k < kEnd; k++) {
          idx->data[(j + k) - 1] = iwork->data[k];
        }

        j = qEnd;
      }

      i = i2;
    }

    emxFree_int32_T(&iwork);
  }

  emxInit_real_T(&st, &ycol, 1, &al_emlrtRTEI, true);
  st.site = &me_emlrtRSI;
  i2 = y->size[0];
  j = ycol->size[0];
  ycol->size[0] = y->size[0];
  emxEnsureCapacity_real_T(&st, ycol, j, &yk_emlrtRTEI);
  b_st.site = &we_emlrtRSI;
  b_st.site = &xe_emlrtRSI;
  if ((1 <= i2) && (i2 > 2147483646)) {
    c_st.site = &lb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (i = 0; i < i2; i++) {
    ycol->data[i] = y->data[idx->data[i] - 1];
  }

  b_st.site = &ye_emlrtRSI;
  if ((1 <= i2) && (i2 > 2147483646)) {
    c_st.site = &lb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (i = 0; i < i2; i++) {
    y->data[i] = ycol->data[i];
  }

  b_st.site = &xe_emlrtRSI;
  for (i = 0; i < i2; i++) {
    ycol->data[i] = y->data[(idx->data[i] + y->size[0]) - 1];
  }

  emxFree_int32_T(&idx);
  b_st.site = &ye_emlrtRSI;
  for (i = 0; i < i2; i++) {
    y->data[i + y->size[0]] = ycol->data[i];
  }

  emxFree_real_T(&ycol);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (sortrows.c) */
