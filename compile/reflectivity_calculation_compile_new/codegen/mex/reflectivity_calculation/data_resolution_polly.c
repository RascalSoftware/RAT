/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
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
static emlrtRSInfo sg_emlrtRSI = {
    27,                      /* lineNo */
    "data_resolution_polly", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/data_resolution_polly.m" /* pathName
                                                                    */
};

static emlrtRTEInfo vb_emlrtRTEI = {
    26,                      /* lineNo */
    13,                      /* colNo */
    "data_resolution_polly", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/data_resolution_polly.m" /* pName */
};

static emlrtBCInfo ni_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    9,                       /* lineNo */
    19,                      /* colNo */
    "resData",               /* aName */
    "data_resolution_polly", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/data_resolution_polly.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo oi_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    12,                      /* lineNo */
    15,                      /* colNo */
    "dummydata",             /* aName */
    "data_resolution_polly", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/data_resolution_polly.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo pi_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    32,                      /* lineNo */
    34,                      /* colNo */
    "dummydata",             /* aName */
    "data_resolution_polly", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/data_resolution_polly.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo qi_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    27,                      /* lineNo */
    28,                      /* colNo */
    "xdata",                 /* aName */
    "data_resolution_polly", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/data_resolution_polly.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ri_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    27,                      /* lineNo */
    39,                      /* colNo */
    "xdata",                 /* aName */
    "data_resolution_polly", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/data_resolution_polly.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo si_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    29,                      /* lineNo */
    34,                      /* colNo */
    "dummydata",             /* aName */
    "data_resolution_polly", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/data_resolution_polly.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ti_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    29,                      /* lineNo */
    48,                      /* colNo */
    "dummyref",              /* aName */
    "data_resolution_polly", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/data_resolution_polly.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ui_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    29,                      /* lineNo */
    19,                      /* colNo */
    "dummydata",             /* aName */
    "data_resolution_polly", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/data_resolution_polly.m", /* pName */
    0 /* checkKind */
};

static emlrtRTEInfo vl_emlrtRTEI = {
    5,                       /* lineNo */
    1,                       /* colNo */
    "data_resolution_polly", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/data_resolution_polly.m" /* pName */
};

/* Function Definitions */
void data_resolution_polly(const emlrtStack *sp, const emxArray_real_T *xdata,
                           const emxArray_real_T *ydata,
                           const emxArray_real_T *resData, real_T points,
                           emxArray_real_T *out)
{
  emlrtStack st;
  const real_T *resData_data;
  const real_T *xdata_data;
  const real_T *ydata_data;
  real_T ihi;
  real_T sumg;
  real_T *out_data;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T ilow;
  int32_T j;
  int32_T loop_ub_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  resData_data = resData->data;
  ydata_data = ydata->data;
  xdata_data = xdata->data;
  /*  Apply resolution correction */
  loop_ub_tmp = (int32_T)points;
  i = out->size[0];
  out->size[0] = (int32_T)points;
  emxEnsureCapacity_real_T(sp, out, i, &vl_emlrtRTEI);
  out_data = out->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    out_data[i] = 0.0;
  }
  for (j = 0; j < loop_ub_tmp; j++) {
    if ((j + 1 < 1) || (j + 1 > resData->size[0])) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, resData->size[0], &ni_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sumg = 0.0;
    if (((int32_T)(j + 1U) < 1) || ((int32_T)(j + 1U) > out->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(j + 1U), 1, out->size[0],
                                    &oi_emlrtBCI, (emlrtCTX)sp);
    }
    out_data[j] = 0.0;
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
    i = (int32_T)(ihi + (1.0 - (real_T)ilow));
    emlrtForLoopVectorCheckR2021a(ilow, 1.0, ihi, mxDOUBLE_CLASS, i,
                                  &vb_emlrtRTEI, (emlrtCTX)sp);
    for (b_i = 0; b_i < i; b_i++) {
      st.site = &sg_emlrtRSI;
      i1 = (int32_T)(((real_T)j + 1.0) + (real_T)(ilow + b_i));
      if ((i1 < 1) || (i1 > xdata->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, xdata->size[0], &qi_emlrtBCI, &st);
      }
      if (((int32_T)(j + 1U) < 1) || ((int32_T)(j + 1U) > xdata->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(j + 1U), 1, xdata->size[0],
                                      &ri_emlrtBCI, &st);
      }
      ihi = (xdata_data[i1 - 1] - xdata_data[j]) /
            (resData_data[j] * xdata_data[j]);
      ihi = muDoubleScalarExp(-(ihi * ihi));
      sumg += ihi;
      if (((int32_T)(j + 1U) < 1) || ((int32_T)(j + 1U) > out->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(j + 1U), 1, out->size[0],
                                      &si_emlrtBCI, (emlrtCTX)sp);
      }
      if (i1 > ydata->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, ydata->size[0], &ti_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (((int32_T)(j + 1U) < 1) || ((int32_T)(j + 1U) > out->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(j + 1U), 1, out->size[0],
                                      &ui_emlrtBCI, (emlrtCTX)sp);
      }
      out_data[j] += ydata_data[i1 - 1] * ihi;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    if (sumg != 0.0) {
      if (((int32_T)(j + 1U) < 1) || ((int32_T)(j + 1U) > out->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(j + 1U), 1, out->size[0],
                                      &pi_emlrtBCI, (emlrtCTX)sp);
      }
      out_data[j] /= sumg;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
}

/* End of code generation (data_resolution_polly.c) */
