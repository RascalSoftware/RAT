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
#include "find.h"
#include "power.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "sum.h"

/* Variable Definitions */
static emlrtRSInfo bh_emlrtRSI = {
    12,           /* lineNo */
    "chiSquared", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/costFunctions/"
    "chiSquared/chiSquared.m" /* pathName */
};

static emlrtRSInfo ch_emlrtRSI = {
    16,           /* lineNo */
    "chiSquared", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/costFunctions/"
    "chiSquared/chiSquared.m" /* pathName */
};

static emlrtRSInfo dh_emlrtRSI = {
    17,           /* lineNo */
    "chiSquared", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/costFunctions/"
    "chiSquared/chiSquared.m" /* pathName */
};

static emlrtRSInfo eh_emlrtRSI = {
    21,           /* lineNo */
    "chiSquared", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/costFunctions/"
    "chiSquared/chiSquared.m" /* pathName */
};

static emlrtECInfo ab_emlrtECI = {
    -1,           /* nDims */
    16,           /* lineNo */
    15,           /* colNo */
    "chiSquared", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/costFunctions/"
    "chiSquared/chiSquared.m" /* pName */
};

static emlrtBCInfo jj_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    9,            /* lineNo */
    21,           /* colNo */
    "thisData",   /* aName */
    "chiSquared", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/costFunctions/"
    "chiSquared/chiSquared.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo kj_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    8,            /* lineNo */
    20,           /* colNo */
    "thisData",   /* aName */
    "chiSquared", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/costFunctions/"
    "chiSquared/chiSquared.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo lj_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    19,           /* lineNo */
    15,           /* colNo */
    "terms",      /* aName */
    "chiSquared", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/costFunctions/"
    "chiSquared/chiSquared.m", /* pName */
    0                          /* checkKind */
};

static emlrtRTEInfo vl_emlrtRTEI = {
    16,           /* lineNo */
    15,           /* colNo */
    "chiSquared", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/costFunctions/"
    "chiSquared/chiSquared.m" /* pName */
};

static emlrtRTEInfo
    wl_emlrtRTEI =
        {
            53,    /* lineNo */
            9,     /* colNo */
            "div", /* fName */
            "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
            "div.m" /* pName */
};

static emlrtRTEInfo xl_emlrtRTEI = {
    17,           /* lineNo */
    14,           /* colNo */
    "chiSquared", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/costFunctions/"
    "chiSquared/chiSquared.m" /* pName */
};

static emlrtRTEInfo yl_emlrtRTEI = {
    16,           /* lineNo */
    5,            /* colNo */
    "chiSquared", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/costFunctions/"
    "chiSquared/chiSquared.m" /* pName */
};

/* Function Definitions */
real_T chiSquared(const emlrtStack *sp, const emxArray_real_T *thisData,
                  const emxArray_real_T *thisFit, real_T P)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  emxArray_boolean_T *c_terms;
  emxArray_int32_T *ii;
  emxArray_real_T *b_terms;
  emxArray_real_T *terms;
  real_T N;
  real_T chi2;
  int32_T csz_idx_0;
  int32_T i;
  int32_T i1;
  int32_T k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /* chi_squared(func,data,numparams,errors) */
  /* allChis = zeros(1,numberOfContrasts); */
  /*      thisData = allData{i}; */
  /*      thisFit = allFits{i}; */
  if (2 > thisData->size[1]) {
    emlrtDynamicBoundsCheckR2012b(2, 1, thisData->size[1], &kj_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (3 > thisData->size[1]) {
    emlrtDynamicBoundsCheckR2012b(3, 1, thisData->size[1], &jj_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  st.site = &bh_emlrtRSI;
  b_st.site = &pd_emlrtRSI;
  c_st.site = &qd_emlrtRSI;
  d_st.site = &rd_emlrtRSI;
  e_st.site = &sd_emlrtRSI;
  f_st.site = &td_emlrtRSI;
  if (thisData->size[0] < 1) {
    N = 1.0;
  } else {
    N = (uint32_T)thisData->size[0];
  }
  if (N <= P) {
    N = P + 1.0;
  }
  if (thisData->size[0] != thisFit->size[0]) {
    emlrtSizeEqCheck1DR2012b(thisData->size[0], thisFit->size[0], &ab_emlrtECI,
                             (emlrtCTX)sp);
  }
  emxInit_real_T(sp, &terms, 1, &yl_emlrtRTEI, true);
  st.site = &ch_emlrtRSI;
  csz_idx_0 = thisData->size[0];
  i = terms->size[0];
  terms->size[0] = thisData->size[0];
  emxEnsureCapacity_real_T(&st, terms, i, &vl_emlrtRTEI);
  for (i = 0; i < csz_idx_0; i++) {
    terms->data[i] = thisData->data[i + thisData->size[0]] -
                     thisFit->data[i + thisFit->size[0]];
  }
  b_st.site = &ff_emlrtRSI;
  c_st.site = &gf_emlrtRSI;
  d_st.site = &hf_emlrtRSI;
  e_st.site = &if_emlrtRSI;
  f_st.site = &jf_emlrtRSI;
  if (terms->size[0] <= thisData->size[0]) {
    csz_idx_0 = terms->size[0];
  } else {
    csz_idx_0 = thisData->size[0];
  }
  p = true;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (k + 1 <= 1) {
      i = csz_idx_0;
      i1 = terms->size[0];
    } else {
      i = 1;
      i1 = 1;
    }
    if (i != i1) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (b_p) {
    b_p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (k + 1 <= 1) {
        i = csz_idx_0;
        i1 = thisData->size[0];
      } else {
        i = 1;
        i1 = 1;
      }
      if (i != i1) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (!b_p) {
      p = false;
    }
  } else {
    p = false;
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&f_st, &rb_emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  f_st.site = &kf_emlrtRSI;
  g_st.site = &lf_emlrtRSI;
  if (terms->size[0] <= thisData->size[0]) {
    csz_idx_0 = terms->size[0];
  } else {
    csz_idx_0 = thisData->size[0];
  }
  p = true;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (k + 1 <= 1) {
      i = csz_idx_0;
      i1 = terms->size[0];
    } else {
      i = 1;
      i1 = 1;
    }
    if (i != i1) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (b_p) {
    b_p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (k + 1 <= 1) {
        i = csz_idx_0;
        i1 = thisData->size[0];
      } else {
        i = 1;
        i1 = 1;
      }
      if (i != i1) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (!b_p) {
      p = false;
    }
  } else {
    p = false;
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&g_st, &rb_emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  g_st.site = &mf_emlrtRSI;
  if ((1 <= csz_idx_0) && (csz_idx_0 > 2147483646)) {
    h_st.site = &j_emlrtRSI;
    check_forloop_overflow_error(&h_st);
  }
  emxInit_real_T(&g_st, &b_terms, 1, &wl_emlrtRTEI, true);
  i = b_terms->size[0];
  b_terms->size[0] = terms->size[0];
  emxEnsureCapacity_real_T(sp, b_terms, i, &wl_emlrtRTEI);
  csz_idx_0 = terms->size[0];
  for (i = 0; i < csz_idx_0; i++) {
    b_terms->data[i] =
        terms->data[i] / thisData->data[i + thisData->size[0] * 2];
  }
  emxInit_boolean_T(sp, &c_terms, 1, &xl_emlrtRTEI, true);
  st.site = &ch_emlrtRSI;
  power(&st, b_terms, terms);
  st.site = &dh_emlrtRSI;
  i = c_terms->size[0];
  c_terms->size[0] = terms->size[0];
  emxEnsureCapacity_boolean_T(&st, c_terms, i, &xl_emlrtRTEI);
  csz_idx_0 = terms->size[0];
  emxFree_real_T(&b_terms);
  for (i = 0; i < csz_idx_0; i++) {
    c_terms->data[i] = (terms->data[i] == rtInf);
  }
  emxInit_int32_T(&st, &ii, 1, &xj_emlrtRTEI, true);
  b_st.site = &ie_emlrtRSI;
  eml_find(&b_st, c_terms, ii);
  emxFree_boolean_T(&c_terms);
  if (ii->size[0] != 0) {
    csz_idx_0 = ii->size[0];
    for (i = 0; i < csz_idx_0; i++) {
      if ((ii->data[i] < 1) || (ii->data[i] > terms->size[0])) {
        emlrtDynamicBoundsCheckR2012b(ii->data[i], 1, terms->size[0],
                                      &lj_emlrtBCI, (emlrtCTX)sp);
      }
    }
    csz_idx_0 = ii->size[0];
    for (i = 0; i < csz_idx_0; i++) {
      terms->data[ii->data[i] - 1] = 0.0;
    }
  }
  emxFree_int32_T(&ii);
  st.site = &eh_emlrtRSI;
  chi2 = 1.0 / (N - P) * sum(&st, terms);
  /* allChis(i) = chi2; */
  emxFree_real_T(&terms);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return chi2;
}

/* End of code generation (chiSquared.c) */
