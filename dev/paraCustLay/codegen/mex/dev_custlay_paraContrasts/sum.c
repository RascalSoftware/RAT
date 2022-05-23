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
#include "dev_custlay_paraContrasts_data.h"
#include "dev_custlay_paraContrasts_emxutil.h"
#include "dev_custlay_paraContrasts_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"

/* Variable Definitions */
static emlrtRSInfo kb_emlrtRSI = {
    20,    /* lineNo */
    "sum", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/sum.m" /* pathName
                                                                            */
};

static emlrtRSInfo lb_emlrtRSI = {
    99,        /* lineNo */
    "sumprod", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/private/"
    "sumprod.m" /* pathName */
};

static emlrtRSInfo mb_emlrtRSI = {
    74,                      /* lineNo */
    "combineVectorElements", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pathName */
};

static emlrtRSInfo nb_emlrtRSI = {
    107,                /* lineNo */
    "blockedSummation", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

static emlrtRSInfo ob_emlrtRSI = {
    22,                    /* lineNo */
    "sumMatrixIncludeNaN", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo pb_emlrtRSI = {
    42,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo qb_emlrtRSI = {
    57,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo tc_emlrtRSI = {
    112,                /* lineNo */
    "blockedSummation", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

static emlrtRSInfo uc_emlrtRSI = {
    173,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

static emlrtRSInfo vc_emlrtRSI = {
    192,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

static emlrtRSInfo wc_emlrtRSI = {
    207,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

static emlrtRSInfo xc_emlrtRSI = {
    227,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

static emlrtRSInfo yc_emlrtRSI = {
    238,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

static emlrtRTEInfo qd_emlrtRTEI = {
    20,    /* lineNo */
    1,     /* colNo */
    "sum", /* fName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/sum.m" /* pName
                                                                            */
};

static emlrtRTEInfo rd_emlrtRTEI = {
    146,                /* lineNo */
    24,                 /* colNo */
    "blockedSummation", /* fName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pName */
};

static emlrtRTEInfo sd_emlrtRTEI = {
    153,                /* lineNo */
    23,                 /* colNo */
    "blockedSummation", /* fName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pName */
};

static emlrtRTEInfo td_emlrtRTEI = {
    153,                /* lineNo */
    1,                  /* colNo */
    "blockedSummation", /* fName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pName */
};

/* Function Definitions */
void b_sum(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_real_T *bsum;
  int32_T bvstride;
  int32_T firstBlockLength;
  int32_T hi;
  int32_T ib;
  int32_T k;
  int32_T lastBlockLength;
  int32_T nblocks;
  int32_T vstride;
  int32_T xj;
  int32_T xoffset;
  st.prev = sp;
  st.tls = sp->tls;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &kb_emlrtRSI;
  b_st.site = &lb_emlrtRSI;
  c_st.site = &mb_emlrtRSI;
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    hi = y->size[0];
    y->size[0] = x->size[0];
    emxEnsureCapacity_real_T(&c_st, y, hi, &qd_emlrtRTEI);
    firstBlockLength = x->size[0];
    for (hi = 0; hi < firstBlockLength; hi++) {
      y->data[hi] = 0.0;
    }
  } else {
    emxInit_real_T(&c_st, &bsum, 1, &td_emlrtRTEI, true);
    d_st.site = &tc_emlrtRSI;
    vstride = x->size[0];
    bvstride = x->size[0] << 10;
    hi = y->size[0];
    y->size[0] = x->size[0];
    emxEnsureCapacity_real_T(&d_st, y, hi, &rd_emlrtRTEI);
    hi = bsum->size[0];
    bsum->size[0] = x->size[0];
    emxEnsureCapacity_real_T(&d_st, bsum, hi, &sd_emlrtRTEI);
    if (x->size[1] <= 1024) {
      firstBlockLength = x->size[1];
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = x->size[1] / 1024;
      lastBlockLength = x->size[1] - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    e_st.site = &uc_emlrtRSI;
    if (x->size[0] > 2147483646) {
      f_st.site = &wb_emlrtRSI;
      check_forloop_overflow_error(&f_st);
    }
    for (xj = 0; xj < vstride; xj++) {
      y->data[xj] = x->data[xj];
      bsum->data[xj] = 0.0;
    }
    for (k = 2; k <= firstBlockLength; k++) {
      xoffset = (k - 1) * vstride;
      e_st.site = &vc_emlrtRSI;
      if (vstride > 2147483646) {
        f_st.site = &wb_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }
      for (xj = 0; xj < vstride; xj++) {
        y->data[xj] += x->data[xoffset + xj];
      }
    }
    for (ib = 2; ib <= nblocks; ib++) {
      firstBlockLength = (ib - 1) * bvstride;
      e_st.site = &wc_emlrtRSI;
      if (vstride > 2147483646) {
        f_st.site = &wb_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }
      for (xj = 0; xj < vstride; xj++) {
        bsum->data[xj] = x->data[firstBlockLength + xj];
      }
      if (ib == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }
      for (k = 2; k <= hi; k++) {
        xoffset = firstBlockLength + (k - 1) * vstride;
        e_st.site = &xc_emlrtRSI;
        for (xj = 0; xj < vstride; xj++) {
          bsum->data[xj] += x->data[xoffset + xj];
        }
      }
      e_st.site = &yc_emlrtRSI;
      for (xj = 0; xj < vstride; xj++) {
        y->data[xj] += bsum->data[xj];
      }
    }
    emxFree_real_T(&bsum);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

real_T sum(const emlrtStack *sp, const emxArray_real_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T y;
  int32_T ib;
  int32_T inb;
  int32_T nfb;
  int32_T nleft;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  b_st.site = &lb_emlrtRSI;
  c_st.site = &mb_emlrtRSI;
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    d_st.site = &nb_emlrtRSI;
    e_st.site = &ob_emlrtRSI;
    if (x->size[0] < 4096) {
      f_st.site = &pb_emlrtRSI;
      y = sumColumnB(&f_st, x, x->size[0]);
    } else {
      nfb = x->size[0] / 4096;
      inb = nfb << 12;
      nleft = x->size[0] - inb;
      y = sumColumnB4(x, 1);
      for (ib = 2; ib <= nfb; ib++) {
        y += sumColumnB4(x, ((ib - 1) << 12) + 1);
      }
      if (nleft > 0) {
        f_st.site = &qb_emlrtRSI;
        y += b_sumColumnB(&f_st, x, nleft, inb + 1);
      }
    }
  }
  return y;
}

/* End of code generation (sum.c) */
