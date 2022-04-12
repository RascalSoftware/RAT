/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * resolution_polly.c
 *
 * Code generation for function 'resolution_polly'
 *
 */

/* Include files */
#include "resolution_polly.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo ah_emlrtRSI = {
    29,                 /* lineNo */
    "resolution_polly", /* fcnName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\Reso"
    "lution_Functions\\Simple_Gaussian\\resolution_polly.m" /* pathName */
};

static emlrtRTEInfo vb_emlrtRTEI = {
    28,                 /* lineNo */
    13,                 /* colNo */
    "resolution_polly", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\Reso"
    "lution_Functions\\Simple_Gaussian\\resolution_polly.m" /* pName */
};

static emlrtBCInfo cj_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    13,                 /* lineNo */
    5,                  /* colNo */
    "dummydata",        /* aName */
    "resolution_polly", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\Reso"
    "lution_Functions\\Simple_Gaussian\\resolution_polly.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo dj_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    34,                 /* lineNo */
    24,                 /* colNo */
    "dummydata",        /* aName */
    "resolution_polly", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\Reso"
    "lution_Functions\\Simple_Gaussian\\resolution_polly.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ej_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    29,                 /* lineNo */
    22,                 /* colNo */
    "xdata",            /* aName */
    "resolution_polly", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\Reso"
    "lution_Functions\\Simple_Gaussian\\resolution_polly.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo fj_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    29,                 /* lineNo */
    33,                 /* colNo */
    "xdata",            /* aName */
    "resolution_polly", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\Reso"
    "lution_Functions\\Simple_Gaussian\\resolution_polly.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo gj_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    31,                 /* lineNo */
    24,                 /* colNo */
    "dummydata",        /* aName */
    "resolution_polly", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\Reso"
    "lution_Functions\\Simple_Gaussian\\resolution_polly.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo hj_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    31,                 /* lineNo */
    39,                 /* colNo */
    "dummyref",         /* aName */
    "resolution_polly", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\Reso"
    "lution_Functions\\Simple_Gaussian\\resolution_polly.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ij_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    31,                 /* lineNo */
    9,                  /* colNo */
    "dummydata",        /* aName */
    "resolution_polly", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\Reso"
    "lution_Functions\\Simple_Gaussian\\resolution_polly.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtRTEInfo ul_emlrtRTEI = {
    7,                  /* lineNo */
    1,                  /* colNo */
    "resolution_polly", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\Reso"
    "lution_Functions\\Simple_Gaussian\\resolution_polly.m" /* pName */
};

/* Function Definitions */
void resolution_polly(const emlrtStack *sp, const emxArray_real_T *xdata,
                      const emxArray_real_T *ydata, real_T res, real_T points,
                      emxArray_real_T *out)
{
  emlrtStack st;
  real_T ihi;
  real_T sumg;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T ilow;
  int32_T j;
  int32_T loop_ub_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  /*  Apply resolution correction */
  res += 0.0001;
  loop_ub_tmp = (int32_T)points;
  i = out->size[0];
  out->size[0] = (int32_T)points;
  emxEnsureCapacity_real_T(sp, out, i, &ul_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    out->data[i] = 0.0;
  }
  for (j = 0; j < loop_ub_tmp; j++) {
    sumg = 0.0;
    if (((int32_T)(j + 1U) < 1) || ((int32_T)(j + 1U) > out->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(j + 1U), 1, out->size[0],
                                    &cj_emlrtBCI, (emlrtCTX)sp);
    }
    out->data[j] = 0.0;
    if (j + 1U > 10U) {
      ilow = -10;
    } else {
      ilow = (int32_T) - ((real_T)j + 1.0) + 1;
    }
    if ((real_T)j + 1.0 < points - 10.0) {
      ihi = 10.0;
    } else {
      ihi = points - ((real_T)j + 1.0);
    }
    /*     try */
    i = (int32_T)(ihi + (1.0 - (real_T)ilow));
    emlrtForLoopVectorCheckR2021a(ilow, 1.0, ihi, mxDOUBLE_CLASS, i,
                                  &vb_emlrtRTEI, (emlrtCTX)sp);
    for (b_i = 0; b_i < i; b_i++) {
      st.site = &ah_emlrtRSI;
      i1 = (int32_T)(((real_T)j + 1.0) + (real_T)(ilow + b_i));
      if ((i1 < 1) || (i1 > xdata->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, xdata->size[0], &ej_emlrtBCI, &st);
      }
      if (((int32_T)(j + 1U) < 1) || ((int32_T)(j + 1U) > xdata->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(j + 1U), 1, xdata->size[0],
                                      &fj_emlrtBCI, &st);
      }
      ihi = (xdata->data[i1 - 1] - xdata->data[j]) / (res * xdata->data[j]);
      ihi = muDoubleScalarExp(-(ihi * ihi));
      sumg += ihi;
      if (((int32_T)(j + 1U) < 1) || ((int32_T)(j + 1U) > out->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(j + 1U), 1, out->size[0],
                                      &gj_emlrtBCI, (emlrtCTX)sp);
      }
      if (i1 > ydata->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, ydata->size[0], &hj_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (((int32_T)(j + 1U) < 1) || ((int32_T)(j + 1U) > out->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(j + 1U), 1, out->size[0],
                                      &ij_emlrtBCI, (emlrtCTX)sp);
      }
      out->data[j] += ydata->data[i1 - 1] * ihi;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    if (sumg != 0.0) {
      if (((int32_T)(j + 1U) < 1) || ((int32_T)(j + 1U) > out->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(j + 1U), 1, out->size[0],
                                      &dj_emlrtBCI, (emlrtCTX)sp);
      }
      out->data[j] /= sumg;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
}

/* End of code generation (resolution_polly.c) */
