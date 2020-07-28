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
#include "chiSquared.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "power.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"
#include "sum.h"

/* Variable Definitions */
static emlrtRSInfo sf_emlrtRSI = { 12, /* lineNo */
  "chiSquared",                        /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m"/* pathName */
};

static emlrtRSInfo tf_emlrtRSI = { 16, /* lineNo */
  "chiSquared",                        /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m"/* pathName */
};

static emlrtRSInfo uf_emlrtRSI = { 17, /* lineNo */
  "chiSquared",                        /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m"/* pathName */
};

static emlrtRSInfo vf_emlrtRSI = { 21, /* lineNo */
  "chiSquared",                        /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m"/* pathName */
};

static emlrtBCInfo hg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  15,                                  /* colNo */
  "terms",                             /* aName */
  "chiSquared",                        /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo q_emlrtECI = { -1,  /* nDims */
  16,                                  /* lineNo */
  15,                                  /* colNo */
  "chiSquared",                        /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m"/* pName */
};

static emlrtRTEInfo ek_emlrtRTEI = { 16,/* lineNo */
  15,                                  /* colNo */
  "chiSquared",                        /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m"/* pName */
};

static emlrtRTEInfo fk_emlrtRTEI = { 47,/* lineNo */
  9,                                   /* colNo */
  "div",                               /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/div.m"/* pName */
};

static emlrtRTEInfo gk_emlrtRTEI = { 17,/* lineNo */
  14,                                  /* colNo */
  "chiSquared",                        /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m"/* pName */
};

static emlrtRTEInfo hk_emlrtRTEI = { 17,/* lineNo */
  5,                                   /* colNo */
  "chiSquared",                        /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m"/* pName */
};

static emlrtRTEInfo ik_emlrtRTEI = { 19,/* lineNo */
  15,                                  /* colNo */
  "chiSquared",                        /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m"/* pName */
};

static emlrtRTEInfo jk_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "chiSquared",                        /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/chiSquared/chiSquared.m"/* pName */
};

/* Function Definitions */
real_T chiSquared(const emlrtStack *sp, const emxArray_real_T *thisData, const
                  emxArray_real_T *thisFit, real_T P)
{
  real_T chi2;
  real_T N;
  emxArray_real_T *terms;
  int32_T loop_ub;
  int32_T i;
  uint32_T varargin_1[2];
  uint32_T varargin_2[2];
  boolean_T p;
  boolean_T exitg1;
  boolean_T overflow;
  emxArray_real_T *b_terms;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  int32_T nx;
  int32_T idx;
  int32_T iv[2];
  emxArray_uint32_T *n;
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
  covrtLogFcn(&emlrtCoverageInstance, 20U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 20U, 0U);

  /* chi_squared(func,data,numparams,errors) */
  /* allChis = zeros(1,numberOfContrasts); */
  /*      thisData = allData{i}; */
  /*      thisFit = allFits{i}; */
  st.site = &sf_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  d_st.site = &oc_emlrtRSI;
  if (thisData->size[0] < 1) {
    N = 1.0;
  } else {
    N = (uint32_T)thisData->size[0];
  }

  if (covrtLogIf(&emlrtCoverageInstance, 20U, 0U, 0, N <= P)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 20U, 1U);
    N = P + 1.0;
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 20U, 2U);
  if (thisData->size[0] != thisFit->size[0]) {
    emlrtSizeEqCheck1DR2012b(thisData->size[0], thisFit->size[0], &q_emlrtECI,
      sp);
  }

  emxInit_real_T(sp, &terms, 1, &jk_emlrtRTEI, true);
  st.site = &tf_emlrtRSI;
  loop_ub = thisData->size[0];
  i = terms->size[0];
  terms->size[0] = thisData->size[0];
  emxEnsureCapacity_real_T(&st, terms, i, &ek_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    terms->data[i] = thisData->data[i + thisData->size[0]] - thisFit->data[i +
      thisFit->size[0]];
  }

  varargin_1[0] = (uint32_T)terms->size[0];
  varargin_1[1] = 1U;
  varargin_2[0] = (uint32_T)thisData->size[0];
  varargin_2[1] = 1U;
  p = true;
  loop_ub = 0;
  exitg1 = false;
  while ((!exitg1) && (loop_ub < 2)) {
    if ((int32_T)varargin_1[loop_ub] != (int32_T)varargin_2[loop_ub]) {
      p = false;
      exitg1 = true;
    } else {
      loop_ub++;
    }
  }

  overflow = (int32_T)p;
  if (!overflow) {
    emlrtErrorWithMessageIdR2018a(&st, &lb_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  emxInit_real_T(&st, &b_terms, 1, &fk_emlrtRTEI, true);
  i = b_terms->size[0];
  b_terms->size[0] = terms->size[0];
  emxEnsureCapacity_real_T(sp, b_terms, i, &fk_emlrtRTEI);
  loop_ub = terms->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_terms->data[i] = terms->data[i] / thisData->data[i + thisData->size[0] * 2];
  }

  emxInit_boolean_T(sp, &x, 1, &gk_emlrtRTEI, true);
  st.site = &tf_emlrtRSI;
  power(&st, b_terms, terms);
  st.site = &uf_emlrtRSI;
  i = x->size[0];
  x->size[0] = terms->size[0];
  emxEnsureCapacity_boolean_T(&st, x, i, &gk_emlrtRTEI);
  loop_ub = terms->size[0];
  emxFree_real_T(&b_terms);
  for (i = 0; i < loop_ub; i++) {
    x->data[i] = (terms->data[i] == rtInf);
  }

  emxInit_int32_T(&st, &ii, 1, &ti_emlrtRTEI, true);
  b_st.site = &fd_emlrtRSI;
  nx = x->size[0];
  c_st.site = &gd_emlrtRSI;
  idx = 0;
  i = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity_int32_T(&c_st, ii, i, &ji_emlrtRTEI);
  d_st.site = &hd_emlrtRSI;
  overflow = ((1 <= x->size[0]) && (x->size[0] > 2147483646));
  if (overflow) {
    e_st.site = &nb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  loop_ub = 0;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= nx - 1)) {
    if (x->data[loop_ub]) {
      idx++;
      ii->data[idx - 1] = loop_ub + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        loop_ub++;
      }
    } else {
      loop_ub++;
    }
  }

  if (idx > x->size[0]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &kb_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      ii->size[0] = 0;
    }
  } else {
    if (1 > idx) {
      idx = 0;
    }

    iv[0] = 1;
    iv[1] = idx;
    d_st.site = &id_emlrtRSI;
    indexShapeCheck(&d_st, ii->size[0], iv);
    i = ii->size[0];
    ii->size[0] = idx;
    emxEnsureCapacity_int32_T(&c_st, ii, i, &li_emlrtRTEI);
  }

  emxFree_boolean_T(&x);
  emxInit_uint32_T(&c_st, &n, 1, &hk_emlrtRTEI, true);
  i = n->size[0];
  n->size[0] = ii->size[0];
  emxEnsureCapacity_uint32_T(&st, n, i, &hk_emlrtRTEI);
  loop_ub = ii->size[0];
  for (i = 0; i < loop_ub; i++) {
    n->data[i] = (uint32_T)ii->data[i];
  }

  if (covrtLogIf(&emlrtCoverageInstance, 20U, 0U, 1, covrtLogMcdc
                 (&emlrtCoverageInstance, 20U, 0U, 0, !covrtLogCond
                  (&emlrtCoverageInstance, 20U, 0U, 0, n->size[0] == 0)))) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 20U, 3U);
    i = ii->size[0];
    ii->size[0] = n->size[0];
    emxEnsureCapacity_int32_T(sp, ii, i, &ik_emlrtRTEI);
    loop_ub = n->size[0];
    for (i = 0; i < loop_ub; i++) {
      if (((int32_T)n->data[i] < 1) || ((int32_T)n->data[i] > terms->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)n->data[i], 1, terms->size[0],
          &hg_emlrtBCI, sp);
      }

      ii->data[i] = (int32_T)n->data[i];
    }

    loop_ub = ii->size[0];
    for (i = 0; i < loop_ub; i++) {
      terms->data[ii->data[i] - 1] = 0.0;
    }
  }

  emxFree_int32_T(&ii);
  emxFree_uint32_T(&n);
  covrtLogBasicBlock(&emlrtCoverageInstance, 20U, 4U);
  st.site = &vf_emlrtRSI;
  chi2 = 1.0 / (N - P) * sum(&st, terms);

  /* allChis(i) = chi2; */
  emxFree_real_T(&terms);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return chi2;
}

/* End of code generation (chiSquared.c) */
