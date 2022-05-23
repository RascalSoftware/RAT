/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * chiSquared.c
 *
 * Code generation for function 'chiSquared'
 *
 */

/* Include files */
#include "chiSquared.h"
#include "assertCompatibleDims.h"
#include "div.h"
#include "find.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "sum.h"

/* Variable Definitions */
static emlrtRSInfo ug_emlrtRSI = {
    16,           /* lineNo */
    "chiSquared", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/costFunctions/"
    "chiSquared/chiSquared.m" /* pathName */
};

static emlrtRSInfo vg_emlrtRSI = {
    17,           /* lineNo */
    "chiSquared", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/costFunctions/"
    "chiSquared/chiSquared.m" /* pathName */
};

static emlrtRSInfo wg_emlrtRSI = {
    21,           /* lineNo */
    "chiSquared", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/costFunctions/"
    "chiSquared/chiSquared.m" /* pathName */
};

static emlrtECInfo ab_emlrtECI = {
    1,            /* nDims */
    16,           /* lineNo */
    15,           /* colNo */
    "chiSquared", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/costFunctions/"
    "chiSquared/chiSquared.m" /* pName */
};

static emlrtBCInfo dj_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    9,            /* lineNo */
    21,           /* colNo */
    "thisData",   /* aName */
    "chiSquared", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/costFunctions/"
    "chiSquared/chiSquared.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo ej_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    8,            /* lineNo */
    20,           /* colNo */
    "thisData",   /* aName */
    "chiSquared", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/costFunctions/"
    "chiSquared/chiSquared.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo fj_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    19,           /* lineNo */
    15,           /* colNo */
    "terms",      /* aName */
    "chiSquared", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/costFunctions/"
    "chiSquared/chiSquared.m", /* pName */
    0                          /* checkKind */
};

static emlrtRTEInfo xl_emlrtRTEI = {
    16,           /* lineNo */
    15,           /* colNo */
    "chiSquared", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/costFunctions/"
    "chiSquared/chiSquared.m" /* pName */
};

static emlrtRTEInfo yl_emlrtRTEI = {
    9,            /* lineNo */
    10,           /* colNo */
    "chiSquared", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/costFunctions/"
    "chiSquared/chiSquared.m" /* pName */
};

static emlrtRTEInfo am_emlrtRTEI = {
    17,           /* lineNo */
    14,           /* colNo */
    "chiSquared", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/costFunctions/"
    "chiSquared/chiSquared.m" /* pName */
};

static emlrtRTEInfo bm_emlrtRTEI = {
    16,           /* lineNo */
    5,            /* colNo */
    "chiSquared", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/costFunctions/"
    "chiSquared/chiSquared.m" /* pName */
};

/* Function Declarations */
static void j_binary_expand_op(const emlrtStack *sp, emxArray_real_T *terms,
                               const emxArray_real_T *thisData,
                               const emxArray_real_T *thisFit);

/* Function Definitions */
static void j_binary_expand_op(const emlrtStack *sp, emxArray_real_T *terms,
                               const emxArray_real_T *thisData,
                               const emxArray_real_T *thisFit)
{
  const real_T *thisData_data;
  const real_T *thisFit_data;
  real_T *terms_data;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  thisFit_data = thisFit->data;
  thisData_data = thisData->data;
  i = thisData->size[0];
  i1 = thisFit->size[0];
  loop_ub = terms->size[0];
  if (i1 == 1) {
    terms->size[0] = i;
  } else {
    terms->size[0] = i1;
  }
  emxEnsureCapacity_real_T(sp, terms, loop_ub, &xl_emlrtRTEI);
  terms_data = terms->data;
  stride_0_0 = (i != 1);
  stride_1_0 = (i1 != 1);
  if (i1 == 1) {
    loop_ub = i;
  } else {
    loop_ub = i1;
  }
  for (i = 0; i < loop_ub; i++) {
    terms_data[i] = thisData_data[i * stride_0_0 + thisData->size[0]] -
                    thisFit_data[i * stride_1_0 + thisFit->size[0]];
  }
}

real_T chiSquared(const emlrtStack *sp, const emxArray_real_T *thisData,
                  const emxArray_real_T *thisFit, real_T P)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_boolean_T *b_terms;
  emxArray_int32_T *ii;
  emxArray_real_T *b_thisData;
  emxArray_real_T *terms;
  const real_T *thisData_data;
  const real_T *thisFit_data;
  real_T N;
  real_T chi2;
  real_T varargin_1;
  real_T *b_thisData_data;
  real_T *terms_data;
  int32_T i;
  int32_T loop_ub;
  int32_T *ii_data;
  boolean_T *b_terms_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  thisFit_data = thisFit->data;
  thisData_data = thisData->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /* chi_squared(func,data,numparams,errors) */
  /* allChis = zeros(1,numberOfContrasts); */
  /*      thisData = allData{i}; */
  /*      thisFit = allFits{i}; */
  if (2 > thisData->size[1]) {
    emlrtDynamicBoundsCheckR2012b(2, 1, thisData->size[1], &ej_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (3 > thisData->size[1]) {
    emlrtDynamicBoundsCheckR2012b(3, 1, thisData->size[1], &dj_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (thisData->size[0] < 1) {
    N = 1.0;
  } else {
    N = (uint32_T)thisData->size[0];
  }
  if (N <= P) {
    N = P + 1.0;
  }
  if ((thisData->size[0] != thisFit->size[0]) &&
      ((thisData->size[0] != 1) && (thisFit->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(thisData->size[0], thisFit->size[0],
                                &ab_emlrtECI, (emlrtCTX)sp);
  }
  st.site = &ug_emlrtRSI;
  emxInit_real_T(&st, &terms, 1, &bm_emlrtRTEI, true);
  if (thisData->size[0] == thisFit->size[0]) {
    loop_ub = thisData->size[0];
    i = terms->size[0];
    terms->size[0] = thisData->size[0];
    emxEnsureCapacity_real_T(&st, terms, i, &xl_emlrtRTEI);
    terms_data = terms->data;
    for (i = 0; i < loop_ub; i++) {
      terms_data[i] = thisData_data[i + thisData->size[0]] -
                      thisFit_data[i + thisFit->size[0]];
    }
  } else {
    b_st.site = &ug_emlrtRSI;
    j_binary_expand_op(&b_st, terms, thisData, thisFit);
    terms_data = terms->data;
  }
  emxInit_real_T(&st, &b_thisData, 1, &yl_emlrtRTEI, true);
  b_st.site = &ff_emlrtRSI;
  loop_ub = thisData->size[0];
  i = b_thisData->size[0];
  b_thisData->size[0] = thisData->size[0];
  emxEnsureCapacity_real_T(&b_st, b_thisData, i, &yl_emlrtRTEI);
  b_thisData_data = b_thisData->data;
  for (i = 0; i < loop_ub; i++) {
    b_thisData_data[i] = thisData_data[i + thisData->size[0] * 2];
  }
  c_st.site = &gf_emlrtRSI;
  assertCompatibleDims(&c_st, terms, b_thisData);
  st.site = &ug_emlrtRSI;
  emxFree_real_T(&st, &b_thisData);
  if (terms->size[0] == thisData->size[0]) {
    loop_ub = terms->size[0];
    for (i = 0; i < loop_ub; i++) {
      terms_data[i] /= thisData_data[i + thisData->size[0] * 2];
    }
  } else {
    b_st.site = &mj_emlrtRSI;
    i_binary_expand_op(&b_st, terms, thisData);
    terms_data = terms->data;
  }
  b_st.site = &oc_emlrtRSI;
  loop_ub = terms->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargin_1 = terms_data[i];
    terms_data[i] = varargin_1 * varargin_1;
  }
  emxInit_boolean_T(&b_st, &b_terms, &am_emlrtRTEI);
  st.site = &vg_emlrtRSI;
  i = b_terms->size[0];
  b_terms->size[0] = terms->size[0];
  emxEnsureCapacity_boolean_T(&st, b_terms, i, &am_emlrtRTEI);
  b_terms_data = b_terms->data;
  loop_ub = terms->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_terms_data[i] = (terms_data[i] == rtInf);
  }
  emxInit_int32_T(&st, &ii, &yj_emlrtRTEI);
  b_st.site = &ie_emlrtRSI;
  eml_find(&b_st, b_terms, ii);
  ii_data = ii->data;
  emxFree_boolean_T(sp, &b_terms);
  if (ii->size[0] != 0) {
    loop_ub = ii->size[0];
    for (i = 0; i < loop_ub; i++) {
      if ((ii_data[i] < 1) || (ii_data[i] > terms->size[0])) {
        emlrtDynamicBoundsCheckR2012b(ii_data[i], 1, terms->size[0],
                                      &fj_emlrtBCI, (emlrtCTX)sp);
      }
    }
    loop_ub = ii->size[0];
    for (i = 0; i < loop_ub; i++) {
      terms_data[ii_data[i] - 1] = 0.0;
    }
  }
  emxFree_int32_T(sp, &ii);
  st.site = &wg_emlrtRSI;
  chi2 = 1.0 / (N - P) * sum(&st, terms);
  /* allChis(i) = chi2; */
  emxFree_real_T(sp, &terms);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return chi2;
}

/* End of code generation (chiSquared.c) */
