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
static emlrtRSInfo ig_emlrtRSI = { 29, /* lineNo */
  "resolution_polly",                  /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly.m"/* pathName */
};

static emlrtRTEInfo wb_emlrtRTEI = { 28,/* lineNo */
  13,                                  /* colNo */
  "resolution_polly",                  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly.m"/* pName */
};

static emlrtBCInfo di_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  5,                                   /* colNo */
  "dummydata",                         /* aName */
  "resolution_polly",                  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ei_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  24,                                  /* colNo */
  "dummydata",                         /* aName */
  "resolution_polly",                  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  22,                                  /* colNo */
  "xdata",                             /* aName */
  "resolution_polly",                  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  33,                                  /* colNo */
  "xdata",                             /* aName */
  "resolution_polly",                  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  24,                                  /* colNo */
  "dummydata",                         /* aName */
  "resolution_polly",                  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ii_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  39,                                  /* colNo */
  "dummyref",                          /* aName */
  "resolution_polly",                  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ji_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  9,                                   /* colNo */
  "dummydata",                         /* aName */
  "resolution_polly",                  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo ul_emlrtRTEI = { 7,/* lineNo */
  1,                                   /* colNo */
  "resolution_polly",                  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly.m"/* pName */
};

/* Function Definitions */
void resolution_polly(const emlrtStack *sp, const emxArray_real_T *xdata, const
                      emxArray_real_T *ydata, real_T res, real_T points,
                      emxArray_real_T *out)
{
  emlrtStack st;
  real_T ihi;
  real_T sumg;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T ilow;
  int32_T j;
  st.prev = sp;
  st.tls = sp->tls;

  /*  Apply resolution correction */
  res += 0.0001;
  i = out->size[0];
  out->size[0] = (int32_T)points;
  emxEnsureCapacity_real_T(sp, out, i, &ul_emlrtRTEI);
  ilow = (int32_T)points;
  for (i = 0; i < ilow; i++) {
    out->data[i] = 0.0;
  }

  i = (int32_T)points;
  for (j = 0; j < i; j++) {
    sumg = 0.0;
    if (((int32_T)(j + 1U) < 1) || ((int32_T)(j + 1U) > out->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(j + 1U), 1, out->size[0],
        &di_emlrtBCI, sp);
    }

    out->data[j] = 0.0;
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
      &wb_emlrtRTEI, sp);
    for (b_i = 0; b_i < i1; b_i++) {
      st.site = &ig_emlrtRSI;
      i2 = (int32_T)(((real_T)j + 1.0) + (real_T)(ilow + b_i));
      if ((i2 < 1) || (i2 > xdata->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, xdata->size[0], &fi_emlrtBCI, &st);
      }

      if (((int32_T)(j + 1U) < 1) || ((int32_T)(j + 1U) > xdata->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(j + 1U), 1, xdata->size[0],
          &gi_emlrtBCI, &st);
      }

      ihi = (xdata->data[i2 - 1] - xdata->data[j]) / (res * xdata->data[j]);
      ihi = muDoubleScalarExp(-(ihi * ihi));
      sumg += ihi;
      if (((int32_T)(j + 1U) < 1) || ((int32_T)(j + 1U) > out->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(j + 1U), 1, out->size[0],
          &hi_emlrtBCI, sp);
      }

      if (i2 > ydata->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, ydata->size[0], &ii_emlrtBCI, sp);
      }

      if (((int32_T)(j + 1U) < 1) || ((int32_T)(j + 1U) > out->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(j + 1U), 1, out->size[0],
          &ji_emlrtBCI, sp);
      }

      out->data[j] += ydata->data[i2 - 1] * ihi;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    if (sumg != 0.0) {
      if (((int32_T)(j + 1U) < 1) || ((int32_T)(j + 1U) > out->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(j + 1U), 1, out->size[0],
          &ei_emlrtBCI, sp);
      }

      out->data[j] /= sumg;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

/* End of code generation (resolution_polly.c) */
