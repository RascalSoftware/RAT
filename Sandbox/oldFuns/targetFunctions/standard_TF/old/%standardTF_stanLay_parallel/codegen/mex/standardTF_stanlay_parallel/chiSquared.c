/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * chiSquared.c
 *
 * Code generation for function 'chiSquared'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_stanlay_parallel.h"
#include "chiSquared.h"
#include "standardTF_stanlay_parallel_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "sum.h"
#include "indexShapeCheck.h"
#include "scalexpAlloc.h"
#include "standardTF_stanlay_parallel_data.h"

/* Variable Definitions */
static emlrtRSInfo hb_emlrtRSI = { 58, /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo md_emlrtRSI = { 16, /* lineNo */
  "chiSquared",                        /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m"/* pathName */
};

static emlrtRSInfo nd_emlrtRSI = { 17, /* lineNo */
  "chiSquared",                        /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m"/* pathName */
};

static emlrtRSInfo od_emlrtRSI = { 21, /* lineNo */
  "chiSquared",                        /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m"/* pathName */
};

static emlrtRSInfo pd_emlrtRSI = { 73, /* lineNo */
  "applyScalarFunction",               /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pathName */
};

static emlrtRSInfo qd_emlrtRSI = { 132,/* lineNo */
  "applyScalarFunction",               /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pathName */
};

static emlrtRTEInfo wb_emlrtRTEI = { 1,/* lineNo */
  17,                                  /* colNo */
  "chiSquared",                        /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m"/* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = { 16,/* lineNo */
  9,                                   /* colNo */
  "scalexpAlloc",                      /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/scalexpAlloc.m"/* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "chiSquared",                        /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m"/* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = { 17,/* lineNo */
  5,                                   /* colNo */
  "chiSquared",                        /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m"/* pName */
};

static emlrtECInfo i_emlrtECI = { -1,  /* nDims */
  16,                                  /* lineNo */
  15,                                  /* colNo */
  "chiSquared",                        /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m"/* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = { 13,/* lineNo */
  15,                                  /* colNo */
  "rdivide",                           /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/rdivide.m"/* pName */
};

static emlrtRTEInfo tc_emlrtRTEI = { 17,/* lineNo */
  19,                                  /* colNo */
  "scalexpAlloc",                      /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/scalexpAlloc.m"/* pName */
};

static emlrtBCInfo rf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  9,                                   /* colNo */
  "terms",                             /* aName */
  "chiSquared",                        /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
real_T chiSquared(const emlrtStack *sp, const emxArray_real_T *thisData, const
                  emxArray_real_T *thisFit, real_T P)
{
  real_T chi2;
  int32_T mtmp;
  real_T N;
  emxArray_real_T *n;
  int32_T i24;
  int32_T nx;
  uint32_T varargin_1[2];
  uint32_T varargin_2[2];
  boolean_T overflow;
  boolean_T p;
  boolean_T exitg2;
  emxArray_real_T *a;
  emxArray_real_T *terms;
  uint32_T a_idx_0;
  int32_T k;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  int32_T idx;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv11[2];
  jmp_buf * volatile emlrtJBStack;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* chi_squared(func,data,numparams,errors) */
  /* allChis = zeros(1,numberOfContrasts); */
  /*      thisData = allData{i}; */
  /*      thisFit = allFits{i}; */
  mtmp = thisData->size[0];
  if (1 > mtmp) {
    mtmp = 1;
  }

  N = mtmp;
  if (mtmp <= P) {
    N = P + 1.0;
  }

  emxInit_real_T1(sp, &n, 1, &ac_emlrtRTEI, true);
  i24 = thisData->size[0];
  mtmp = thisFit->size[0];
  if (i24 != mtmp) {
    emlrtSizeEqCheck1DR2012b(i24, mtmp, &i_emlrtECI, sp);
  }

  st.site = &md_emlrtRSI;
  nx = thisData->size[0];
  i24 = n->size[0];
  n->size[0] = nx;
  emxEnsureCapacity(&st, (emxArray__common *)n, i24, (int32_T)sizeof(real_T),
                    &wb_emlrtRTEI);
  for (i24 = 0; i24 < nx; i24++) {
    n->data[i24] = thisData->data[i24 + thisData->size[0]] - thisFit->data[i24 +
      thisFit->size[0]];
  }

  varargin_1[0] = (uint32_T)n->size[0];
  varargin_1[1] = 1U;
  i24 = thisData->size[0];
  varargin_2[0] = (uint32_T)i24;
  varargin_2[1] = 1U;
  overflow = false;
  p = true;
  mtmp = 0;
  exitg2 = false;
  while ((!exitg2) && (mtmp < 2)) {
    if (!((int32_T)varargin_1[mtmp] == (int32_T)varargin_2[mtmp])) {
      p = false;
      exitg2 = true;
    } else {
      mtmp++;
    }
  }

  if (p) {
    overflow = true;
  }

  if (!overflow) {
    emlrtErrorWithMessageIdR2012b(&st, &sc_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  emxInit_real_T1(&st, &a, 1, &wb_emlrtRTEI, true);
  i24 = a->size[0];
  a->size[0] = n->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)a, i24, (int32_T)sizeof(real_T),
                    &wb_emlrtRTEI);
  nx = n->size[0];
  for (i24 = 0; i24 < nx; i24++) {
    a->data[i24] = n->data[i24] / thisData->data[i24 + (thisData->size[0] << 1)];
  }

  emxInit_real_T1(&st, &terms, 1, &yb_emlrtRTEI, true);
  st.site = &md_emlrtRSI;
  b_st.site = &gb_emlrtRSI;
  c_st.site = &hb_emlrtRSI;
  d_st.site = &pd_emlrtRSI;
  a_idx_0 = (uint32_T)a->size[0];
  i24 = terms->size[0];
  terms->size[0] = (int32_T)a_idx_0;
  emxEnsureCapacity(&d_st, (emxArray__common *)terms, i24, (int32_T)sizeof
                    (real_T), &xb_emlrtRTEI);
  if (!dimagree(terms, a)) {
    emlrtErrorWithMessageIdR2012b(&d_st, &tc_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  mtmp = a->size[0];
  d_st.site = &qd_emlrtRSI;
  overflow = ((!(1 > a->size[0])) && (a->size[0] > 2147483646));
  if (overflow) {
    e_st.site = &eb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  emlrtEnterParallelRegion(&c_st, omp_in_parallel());
  emlrtPushJmpBuf(&c_st, &emlrtJBStack);

#pragma omp parallel for \
 num_threads(emlrtAllocRegionTLSs(c_st.tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs()))

  for (k = 1; k <= mtmp; k++) {
    terms->data[k - 1] = a->data[k - 1] * a->data[k - 1];
  }

  emlrtPopJmpBuf(&c_st, &emlrtJBStack);
  emlrtExitParallelRegion(&c_st, omp_in_parallel());
  emxFree_real_T(&a);
  emxInit_boolean_T(&c_st, &x, 1, &wb_emlrtRTEI, true);
  st.site = &nd_emlrtRSI;
  i24 = x->size[0];
  x->size[0] = terms->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i24, (int32_T)sizeof(boolean_T),
                    &wb_emlrtRTEI);
  nx = terms->size[0];
  for (i24 = 0; i24 < nx; i24++) {
    x->data[i24] = (terms->data[i24] == rtInf);
  }

  emxInit_int32_T(&st, &ii, 1, &bb_emlrtRTEI, true);
  b_st.site = &pc_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  i24 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i24, (int32_T)sizeof(int32_T),
                    &wb_emlrtRTEI);
  c_st.site = &qc_emlrtRSI;
  overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &eb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  mtmp = 1;
  exitg1 = false;
  while ((!exitg1) && (mtmp <= nx)) {
    guard1 = false;
    if (x->data[mtmp - 1]) {
      idx++;
      ii->data[idx - 1] = mtmp;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      mtmp++;
    }
  }

  if (!(idx <= x->size[0])) {
    emlrtErrorWithMessageIdR2012b(&b_st, &lc_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i24 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i24, (int32_T)sizeof
                        (int32_T), &wb_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i24 = 0;
    } else {
      i24 = idx;
    }

    iv11[0] = 1;
    iv11[1] = i24;
    c_st.site = &rc_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv11);
    mtmp = ii->size[0];
    ii->size[0] = i24;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, mtmp, (int32_T)sizeof
                      (int32_T), &v_emlrtRTEI);
  }

  emxFree_boolean_T(&x);
  i24 = n->size[0];
  n->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)n, i24, (int32_T)sizeof(real_T),
                    &wb_emlrtRTEI);
  nx = ii->size[0];
  for (i24 = 0; i24 < nx; i24++) {
    n->data[i24] = ii->data[i24];
  }

  if (!(n->size[0] == 0)) {
    idx = terms->size[0];
    i24 = ii->size[0];
    ii->size[0] = n->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, i24, (int32_T)sizeof(int32_T),
                      &wb_emlrtRTEI);
    nx = n->size[0];
    for (i24 = 0; i24 < nx; i24++) {
      mtmp = (int32_T)n->data[i24];
      if (!((mtmp >= 1) && (mtmp <= idx))) {
        emlrtDynamicBoundsCheckR2012b(mtmp, 1, idx, &rf_emlrtBCI, sp);
      }

      ii->data[i24] = mtmp;
    }

    nx = ii->size[0];
    for (i24 = 0; i24 < nx; i24++) {
      terms->data[ii->data[i24] - 1] = 0.0;
    }
  }

  emxFree_int32_T(&ii);
  emxFree_real_T(&n);
  st.site = &od_emlrtRSI;
  chi2 = 1.0 / (N - P) * sum(&st, terms);

  /* allChis(i) = chi2; */
  emxFree_real_T(&terms);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return chi2;
}

/* End of code generation (chiSquared.c) */
