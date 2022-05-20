/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * data_resolution_polly.c
 *
 * Code generation for function 'data_resolution_polly'
 *
 */

/* Include files */
#include "data_resolution_polly.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo hg_emlrtRSI = { 27, /* lineNo */
  "data_resolution_polly",             /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/data_resolution_polly.m"/* pathName */
};

static emlrtRTEInfo vb_emlrtRTEI = { 26,/* lineNo */
  13,                                  /* colNo */
  "data_resolution_polly",             /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/data_resolution_polly.m"/* pName */
};

static emlrtBCInfo uh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  19,                                  /* colNo */
  "resData",                           /* aName */
  "data_resolution_polly",             /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/data_resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  5,                                   /* colNo */
  "dummydata",                         /* aName */
  "data_resolution_polly",             /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/data_resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  32,                                  /* lineNo */
  24,                                  /* colNo */
  "dummydata",                         /* aName */
  "data_resolution_polly",             /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/data_resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  27,                                  /* lineNo */
  22,                                  /* colNo */
  "xdata",                             /* aName */
  "data_resolution_polly",             /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/data_resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  27,                                  /* lineNo */
  33,                                  /* colNo */
  "xdata",                             /* aName */
  "data_resolution_polly",             /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/data_resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ai_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  24,                                  /* colNo */
  "dummydata",                         /* aName */
  "data_resolution_polly",             /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/data_resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  39,                                  /* colNo */
  "dummyref",                          /* aName */
  "data_resolution_polly",             /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/data_resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ci_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  9,                                   /* colNo */
  "dummydata",                         /* aName */
  "data_resolution_polly",             /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/data_resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo tl_emlrtRTEI = { 5,/* lineNo */
  1,                                   /* colNo */
  "data_resolution_polly",             /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/data_resolution_polly.m"/* pName */
};

/* Function Definitions */
void data_resolution_polly(const emlrtStack *sp, const emxArray_real_T *xdata,
  const emxArray_real_T *ydata, const emxArray_real_T *resData, real_T points,
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
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;

  /*  Apply resolution correction */
  i = out->size[0];
  out->size[0] = (int32_T)points;
  emxEnsureCapacity_real_T(sp, out, i, &tl_emlrtRTEI);
  loop_ub = (int32_T)points;
  for (i = 0; i < loop_ub; i++) {
    out->data[i] = 0.0;
  }

  i = (int32_T)points;
  for (j = 0; j < i; j++) {
    loop_ub = j + 1;
    if ((loop_ub < 1) || (loop_ub > resData->size[0])) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, resData->size[0], &uh_emlrtBCI,
        sp);
    }

    sumg = 0.0;
    if (((int32_T)(j + 1U) < 1) || ((int32_T)(j + 1U) > out->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(j + 1U), 1, out->size[0],
        &vh_emlrtBCI, sp);
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

    loop_ub = (int32_T)(ihi + (1.0 - (real_T)ilow));
    emlrtForLoopVectorCheckR2012b(ilow, 1.0, ihi, mxDOUBLE_CLASS, loop_ub,
      &vb_emlrtRTEI, sp);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      st.site = &hg_emlrtRSI;
      i1 = (int32_T)(((real_T)j + 1.0) + (real_T)(ilow + b_i));
      if ((i1 < 1) || (i1 > xdata->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, xdata->size[0], &xh_emlrtBCI, &st);
      }

      if (((int32_T)(j + 1U) < 1) || ((int32_T)(j + 1U) > xdata->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(j + 1U), 1, xdata->size[0],
          &yh_emlrtBCI, &st);
      }

      ihi = (xdata->data[i1 - 1] - xdata->data[j]) / (resData->data[j] *
        xdata->data[j]);
      ihi = muDoubleScalarExp(-(ihi * ihi));
      sumg += ihi;
      if (((int32_T)(j + 1U) < 1) || ((int32_T)(j + 1U) > out->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(j + 1U), 1, out->size[0],
          &ai_emlrtBCI, sp);
      }

      if (i1 > ydata->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, ydata->size[0], &bi_emlrtBCI, sp);
      }

      if (((int32_T)(j + 1U) < 1) || ((int32_T)(j + 1U) > out->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(j + 1U), 1, out->size[0],
          &ci_emlrtBCI, sp);
      }

      out->data[j] += ydata->data[i1 - 1] * ihi;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    if (sumg != 0.0) {
      if (((int32_T)(j + 1U) < 1) || ((int32_T)(j + 1U) > out->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(j + 1U), 1, out->size[0],
          &wh_emlrtBCI, sp);
      }

      out->data[j] /= sumg;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

/* End of code generation (data_resolution_polly.c) */
