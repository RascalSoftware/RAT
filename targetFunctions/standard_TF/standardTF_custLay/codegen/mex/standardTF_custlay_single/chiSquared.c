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
#include "standardTF_custlay_single.h"
#include "chiSquared.h"
#include "standardTF_custlay_single_emxutil.h"
#include "sum.h"
#include "indexShapeCheck.h"
#include "scalexpAlloc.h"
#include "standardTF_custlay_single_data.h"

/* Variable Definitions */
static emlrtRSInfo fb_emlrtRSI = { 49, /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 58, /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo ld_emlrtRSI = { 16, /* lineNo */
  "chiSquared",                        /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m"/* pathName */
};

static emlrtRSInfo md_emlrtRSI = { 17, /* lineNo */
  "chiSquared",                        /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m"/* pathName */
};

static emlrtRSInfo nd_emlrtRSI = { 21, /* lineNo */
  "chiSquared",                        /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m"/* pathName */
};

static emlrtRSInfo od_emlrtRSI = { 73, /* lineNo */
  "applyScalarFunction",               /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pathName */
};

static emlrtRSInfo pd_emlrtRSI = { 132,/* lineNo */
  "applyScalarFunction",               /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pathName */
};

static emlrtRTEInfo nb_emlrtRTEI = { 1,/* lineNo */
  17,                                  /* colNo */
  "chiSquared",                        /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m"/* pName */
};

static emlrtECInfo e_emlrtECI = { -1,  /* nDims */
  16,                                  /* lineNo */
  15,                                  /* colNo */
  "chiSquared",                        /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m"/* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = { 13,/* lineNo */
  15,                                  /* colNo */
  "rdivide",                           /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/rdivide.m"/* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = { 17,/* lineNo */
  19,                                  /* colNo */
  "scalexpAlloc",                      /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/scalexpAlloc.m"/* pName */
};

static emlrtBCInfo cf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  9,                                   /* colNo */
  "terms",                             /* aName */
  "chiSquared",                        /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
real_T chiSquared(const emlrtStack *sp, const real_T thisData_data[], const
                  int32_T thisData_size[2], const real_T thisFit_data[], const
                  int32_T thisFit_size[2], real_T P)
{
  real_T chi2;
  int32_T mtmp;
  real_T N;
  int32_T terms_size[1];
  int32_T i17;
  int8_T varargin_1[2];
  real_T terms_data[51];
  int8_T varargin_2[2];
  boolean_T p;
  boolean_T b_p;
  boolean_T exitg2;
  int32_T a_size[1];
  real_T a_data[51];
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  int32_T nx;
  int32_T idx;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv9[2];
  emxArray_int32_T *i;
  int32_T tmp_size_idx_0;
  emxArray_real_T b_terms_data;
  int8_T tmp_data[51];
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
  covrtLogFcn(&emlrtCoverageInstance, 15U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 0U);

  /* chi_squared(func,data,numparams,errors) */
  /* allChis = zeros(1,numberOfContrasts); */
  /*      thisData = allData{i}; */
  /*      thisFit = allFits{i}; */
  mtmp = (int8_T)thisData_size[0];
  if (1 > (int8_T)thisData_size[0]) {
    mtmp = 1;
  }

  N = mtmp;
  if (covrtLogIf(&emlrtCoverageInstance, 15U, 0U, 0, mtmp <= P)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 1U);
    N = P + 1.0;
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 2U);
  if (thisData_size[0] != thisFit_size[0]) {
    emlrtSizeEqCheck1DR2012b(thisData_size[0], thisFit_size[0], &e_emlrtECI, sp);
  }

  st.site = &ld_emlrtRSI;
  mtmp = thisData_size[0];
  terms_size[0] = thisData_size[0];
  for (i17 = 0; i17 < mtmp; i17++) {
    terms_data[i17] = thisData_data[i17 + thisData_size[0]] - thisFit_data[i17 +
      thisFit_size[0]];
  }

  varargin_1[0] = (int8_T)terms_size[0];
  varargin_1[1] = 1;
  varargin_2[0] = (int8_T)thisData_size[0];
  varargin_2[1] = 1;
  p = false;
  b_p = true;
  mtmp = 0;
  exitg2 = false;
  while ((!exitg2) && (mtmp < 2)) {
    if (!(varargin_1[mtmp] == varargin_2[mtmp])) {
      b_p = false;
      exitg2 = true;
    } else {
      mtmp++;
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emlrtErrorWithMessageIdR2012b(&st, &gc_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  a_size[0] = terms_size[0];
  mtmp = terms_size[0];
  for (i17 = 0; i17 < mtmp; i17++) {
    a_data[i17] = terms_data[i17] / thisData_data[i17 + (thisData_size[0] << 1)];
  }

  st.site = &ld_emlrtRSI;
  b_st.site = &fb_emlrtRSI;
  c_st.site = &gb_emlrtRSI;
  d_st.site = &od_emlrtRSI;
  terms_size[0] = (int8_T)a_size[0];
  if (!dimagree(terms_size, a_size)) {
    emlrtErrorWithMessageIdR2012b(&d_st, &hc_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  d_st.site = &pd_emlrtRSI;
  for (mtmp = 0; mtmp + 1 <= a_size[0]; mtmp++) {
    terms_data[mtmp] = a_data[mtmp] * a_data[mtmp];
  }

  emxInit_boolean_T(&c_st, &x, 1, &nb_emlrtRTEI, true);
  st.site = &md_emlrtRSI;
  i17 = x->size[0];
  x->size[0] = terms_size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i17, (int32_T)sizeof(boolean_T),
                    &nb_emlrtRTEI);
  mtmp = terms_size[0];
  for (i17 = 0; i17 < mtmp; i17++) {
    x->data[i17] = (terms_data[i17] == rtInf);
  }

  emxInit_int32_T(&st, &ii, 1, &v_emlrtRTEI, true);
  b_st.site = &oc_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  i17 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i17, (int32_T)sizeof(int32_T),
                    &nb_emlrtRTEI);
  c_st.site = &pc_emlrtRSI;
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
    emlrtErrorWithMessageIdR2012b(&b_st, &yb_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i17 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i17, (int32_T)sizeof
                        (int32_T), &nb_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i17 = 0;
    } else {
      i17 = idx;
    }

    iv9[0] = 1;
    iv9[1] = i17;
    c_st.site = &qc_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv9);
    nx = ii->size[0];
    ii->size[0] = i17;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, nx, (int32_T)sizeof(int32_T),
                      &b_emlrtRTEI);
  }

  emxFree_boolean_T(&x);
  emxInit_int32_T(&b_st, &i, 1, &nb_emlrtRTEI, true);
  i17 = i->size[0];
  i->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)i, i17, (int32_T)sizeof(int32_T),
                    &nb_emlrtRTEI);
  mtmp = ii->size[0];
  for (i17 = 0; i17 < mtmp; i17++) {
    i->data[i17] = ii->data[i17];
  }

  emxFree_int32_T(&ii);
  if (covrtLogIf(&emlrtCoverageInstance, 15U, 0U, 1, covrtLogMcdc
                 (&emlrtCoverageInstance, 15U, 0U, 0, !covrtLogCond
                  (&emlrtCoverageInstance, 15U, 0U, 0, i->size[0] == 0)))) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 3U);
    idx = terms_size[0];
    tmp_size_idx_0 = i->size[0];
    mtmp = i->size[0];
    for (i17 = 0; i17 < mtmp; i17++) {
      nx = (int8_T)i->data[i17];
      if (!((nx >= 1) && (nx <= idx))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, idx, &cf_emlrtBCI, sp);
      }

      tmp_data[i17] = (int8_T)nx;
    }

    for (i17 = 0; i17 < tmp_size_idx_0; i17++) {
      terms_data[tmp_data[i17] - 1] = 0.0;
    }
  }

  emxFree_int32_T(&i);
  covrtLogBasicBlock(&emlrtCoverageInstance, 15U, 4U);
  b_terms_data.data = (real_T *)&terms_data;
  b_terms_data.size = (int32_T *)&terms_size;
  b_terms_data.allocatedSize = 51;
  b_terms_data.numDimensions = 1;
  b_terms_data.canFreeData = false;
  st.site = &nd_emlrtRSI;
  chi2 = 1.0 / (N - P) * sum(&st, &b_terms_data);

  /* allChis(i) = chi2; */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return chi2;
}

/* End of code generation (chiSquared.c) */
