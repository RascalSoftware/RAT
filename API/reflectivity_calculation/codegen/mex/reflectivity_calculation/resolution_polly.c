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
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo pf_emlrtRSI = { 26, /* lineNo */
  "resolution_polly",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m"/* pathName */
};

static emlrtRTEInfo vb_emlrtRTEI = { 25,/* lineNo */
  13,                                  /* colNo */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m"/* pName */
};

static emlrtBCInfo xh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  5,                                   /* colNo */
  "dummydata",                         /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  24,                                  /* colNo */
  "dummydata",                         /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ai_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  9,                                   /* colNo */
  "dummydata",                         /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  22,                                  /* colNo */
  "xdata",                             /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ci_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  33,                                  /* colNo */
  "xdata",                             /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo di_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  28,                                  /* lineNo */
  24,                                  /* colNo */
  "dummydata",                         /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ei_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  28,                                  /* lineNo */
  39,                                  /* colNo */
  "dummyref",                          /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  28,                                  /* lineNo */
  9,                                   /* colNo */
  "dummydata",                         /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo mj_emlrtRTEI = { 5,/* lineNo */
  1,                                   /* colNo */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m"/* pName */
};

/* Function Definitions */
void resolution_polly(const emlrtStack *sp, const emxArray_real_T *xdata, const
                      emxArray_real_T *ydata, real_T res, real_T points,
                      emxArray_real_T *out)
{
  int32_T loop_ub;
  int32_T i;
  int32_T j;
  real_T sumg;
  int32_T ilow;
  real_T ihi;
  int32_T i1;
  int32_T b_i;
  int32_T i2;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  res += 0.0001;
  loop_ub = (int32_T)points;
  i = out->size[0];
  out->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, out, i, &mj_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    out->data[i] = 0.0;
  }

  for (j = 0; j < loop_ub; j++) {
    sumg = 0.0;
    i = (int32_T)(j + 1U);
    if ((i < 1) || (i > out->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, out->size[0], &xh_emlrtBCI, sp);
    }

    out->data[i - 1] = 0.0;
    if (j + 1U > 10U) {
      ilow = -10;
    } else {
      ilow = (int32_T)-((real_T)j + 1.0) + 1;
    }

    if ((real_T)j + 1.0 < points - 10.0) {
      ihi = 10.0;
    } else {
      ihi = points - ((real_T)j + 1.0);
    }

    /*     try */
    i1 = (int32_T)(ihi + (1.0 - (real_T)ilow));
    emlrtForLoopVectorCheckR2012b(ilow, 1.0, ihi, mxDOUBLE_CLASS, i1,
      &vb_emlrtRTEI, sp);
    for (b_i = 0; b_i < i1; b_i++) {
      st.site = &pf_emlrtRSI;
      i2 = (int32_T)(((real_T)j + 1.0) + (real_T)(ilow + b_i));
      if ((i2 < 1) || (i2 > xdata->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, xdata->size[1], &bi_emlrtBCI, &st);
      }

      if (i > xdata->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, xdata->size[1], &ci_emlrtBCI, &st);
      }

      ihi = (xdata->data[i2 - 1] - xdata->data[i - 1]) / (res * xdata->data[i -
        1]);
      ihi = muDoubleScalarExp(-(ihi * ihi));
      sumg += ihi;
      if (i > out->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, out->size[0], &di_emlrtBCI, sp);
      }

      if (i2 > ydata->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, ydata->size[0], &ei_emlrtBCI, sp);
      }

      if (i > out->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, out->size[0], &fi_emlrtBCI, sp);
      }

      out->data[i - 1] += ydata->data[i2 - 1] * ihi;
    }

    if (sumg != 0.0) {
      if (i > out->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, out->size[0], &yh_emlrtBCI, sp);
      }

      if (i > out->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, out->size[0], &ai_emlrtBCI, sp);
      }

      out->data[i - 1] /= sumg;
    }

    /*      catch */
    /*          disp('debug!'); */
    /*      end */
  }
}

/* End of code generation (resolution_polly.c) */
