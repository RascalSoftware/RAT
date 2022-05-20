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
#include "find.h"
#include "power.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "sum.h"

/* Variable Definitions */
static emlrtRSInfo jg_emlrtRSI = { 12, /* lineNo */
  "chiSquared",                        /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/costFunctions/chiSquared/chiSquared.m"/* pathName */
};

static emlrtRSInfo kg_emlrtRSI = { 16, /* lineNo */
  "chiSquared",                        /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/costFunctions/chiSquared/chiSquared.m"/* pathName */
};

static emlrtRSInfo lg_emlrtRSI = { 17, /* lineNo */
  "chiSquared",                        /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/costFunctions/chiSquared/chiSquared.m"/* pathName */
};

static emlrtRSInfo mg_emlrtRSI = { 21, /* lineNo */
  "chiSquared",                        /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/costFunctions/chiSquared/chiSquared.m"/* pathName */
};

static emlrtECInfo ab_emlrtECI = { -1, /* nDims */
  16,                                  /* lineNo */
  15,                                  /* colNo */
  "chiSquared",                        /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/costFunctions/chiSquared/chiSquared.m"/* pName */
};

static emlrtBCInfo ki_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  21,                                  /* colNo */
  "thisData",                          /* aName */
  "chiSquared",                        /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/costFunctions/chiSquared/chiSquared.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo li_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  20,                                  /* colNo */
  "thisData",                          /* aName */
  "chiSquared",                        /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/costFunctions/chiSquared/chiSquared.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  15,                                  /* colNo */
  "terms",                             /* aName */
  "chiSquared",                        /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/costFunctions/chiSquared/chiSquared.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo vl_emlrtRTEI = { 16,/* lineNo */
  15,                                  /* colNo */
  "chiSquared",                        /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/costFunctions/chiSquared/chiSquared.m"/* pName */
};

static emlrtRTEInfo wl_emlrtRTEI = { 47,/* lineNo */
  9,                                   /* colNo */
  "div",                               /* fName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/div.m"/* pName */
};

static emlrtRTEInfo xl_emlrtRTEI = { 17,/* lineNo */
  14,                                  /* colNo */
  "chiSquared",                        /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/costFunctions/chiSquared/chiSquared.m"/* pName */
};

static emlrtRTEInfo yl_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "chiSquared",                        /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/costFunctions/chiSquared/chiSquared.m"/* pName */
};

/* Function Definitions */
real_T chiSquared(const emlrtStack *sp, const emxArray_real_T *thisData, const
                  emxArray_real_T *thisFit, real_T P)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_boolean_T *c_terms;
  emxArray_int32_T *ii;
  emxArray_real_T *b_terms;
  emxArray_real_T *terms;
  real_T N;
  real_T chi2;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* chi_squared(func,data,numparams,errors) */
  /* allChis = zeros(1,numberOfContrasts); */
  /*      thisData = allData{i}; */
  /*      thisFit = allFits{i}; */
  if (2 > thisData->size[1]) {
    emlrtDynamicBoundsCheckR2012b(2, 1, thisData->size[1], &li_emlrtBCI, sp);
  }

  if (3 > thisData->size[1]) {
    emlrtDynamicBoundsCheckR2012b(3, 1, thisData->size[1], &ki_emlrtBCI, sp);
  }

  st.site = &jg_emlrtRSI;
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
      sp);
  }

  emxInit_real_T(sp, &terms, 1, &yl_emlrtRTEI, true);
  st.site = &kg_emlrtRSI;
  loop_ub = thisData->size[0];
  i = terms->size[0];
  terms->size[0] = thisData->size[0];
  emxEnsureCapacity_real_T(&st, terms, i, &vl_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    terms->data[i] = thisData->data[i + thisData->size[0]] - thisFit->data[i +
      thisFit->size[0]];
  }

  if (terms->size[0] != thisData->size[0]) {
    emlrtErrorWithMessageIdR2018a(&st, &pb_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  emxInit_real_T(&st, &b_terms, 1, &wl_emlrtRTEI, true);
  i = b_terms->size[0];
  b_terms->size[0] = terms->size[0];
  emxEnsureCapacity_real_T(sp, b_terms, i, &wl_emlrtRTEI);
  loop_ub = terms->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_terms->data[i] = terms->data[i] / thisData->data[i + thisData->size[0] * 2];
  }

  emxInit_boolean_T(sp, &c_terms, 1, &xl_emlrtRTEI, true);
  st.site = &kg_emlrtRSI;
  power(&st, b_terms, terms);
  st.site = &lg_emlrtRSI;
  i = c_terms->size[0];
  c_terms->size[0] = terms->size[0];
  emxEnsureCapacity_boolean_T(&st, c_terms, i, &xl_emlrtRTEI);
  loop_ub = terms->size[0];
  emxFree_real_T(&b_terms);
  for (i = 0; i < loop_ub; i++) {
    c_terms->data[i] = (terms->data[i] == rtInf);
  }

  emxInit_int32_T(&st, &ii, 1, &xj_emlrtRTEI, true);
  b_st.site = &xd_emlrtRSI;
  eml_find(&b_st, c_terms, ii);
  emxFree_boolean_T(&c_terms);
  if (ii->size[0] != 0) {
    loop_ub = ii->size[0];
    for (i = 0; i < loop_ub; i++) {
      if ((ii->data[i] < 1) || (ii->data[i] > terms->size[0])) {
        emlrtDynamicBoundsCheckR2012b(ii->data[i], 1, terms->size[0],
          &mi_emlrtBCI, sp);
      }
    }

    loop_ub = ii->size[0];
    for (i = 0; i < loop_ub; i++) {
      terms->data[ii->data[i] - 1] = 0.0;
    }
  }

  emxFree_int32_T(&ii);
  st.site = &mg_emlrtRSI;
  chi2 = 1.0 / (N - P) * sum(&st, terms);

  /* allChis(i) = chi2; */
  emxFree_real_T(&terms);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return chi2;
}

/* End of code generation (chiSquared.c) */
