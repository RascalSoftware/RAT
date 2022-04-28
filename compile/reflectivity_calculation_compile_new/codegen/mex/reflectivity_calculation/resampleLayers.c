/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * resampleLayers.c
 *
 * Code generation for function 'resampleLayers'
 *
 */

/* Include files */
#include "resampleLayers.h"
#include "adaptive_new.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo vd_emlrtRSI = {
    20,               /* lineNo */
    "resampleLayers", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m" /* pathName */
};

static emlrtBCInfo dg_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    41,               /* lineNo */
    12,               /* colNo */
    "layers",         /* aName */
    "resampleLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo eg_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    32,               /* lineNo */
    18,               /* colNo */
    "newY",           /* aName */
    "resampleLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo fg_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    31,               /* lineNo */
    18,               /* colNo */
    "newY",           /* aName */
    "resampleLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo gg_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    30,               /* lineNo */
    18,               /* colNo */
    "newX",           /* aName */
    "resampleLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo hg_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    29,               /* lineNo */
    18,               /* colNo */
    "newX",           /* aName */
    "resampleLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo ig_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    12,               /* lineNo */
    10,               /* colNo */
    "x",              /* aName */
    "resampleLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo jg_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    11,               /* lineNo */
    12,               /* colNo */
    "x",              /* aName */
    "resampleLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m", /* pName */
    0                   /* checkKind */
};

static emlrtDCInfo kb_emlrtDCI = {
    25,               /* lineNo */
    16,               /* colNo */
    "resampleLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m", /* pName */
    4                   /* checkKind */
};

static emlrtBCInfo wx_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    9,                /* lineNo */
    21,               /* colNo */
    "sldProfile",     /* aName */
    "resampleLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo xx_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    8,                /* lineNo */
    18,               /* colNo */
    "sldProfile",     /* aName */
    "resampleLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m", /* pName */
    0                   /* checkKind */
};

static emlrtRTEInfo ti_emlrtRTEI = {
    25,               /* lineNo */
    1,                /* colNo */
    "resampleLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m" /* pName */
};

static emlrtRTEInfo ui_emlrtRTEI = {
    20,               /* lineNo */
    1,                /* colNo */
    "resampleLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m" /* pName */
};

/* Function Definitions */
void b_resampleLayers(const emlrtStack *sp, const emxArray_real_T *sldProfile,
                      const real_T resamPars[2], emxArray_real_T *newSLD)
{
  cell_19 expl_temp;
  emlrtStack st;
  real_T b_sldProfile[2];
  const real_T *sldProfile_data;
  real_T thisLayRho;
  real_T *newSLD_data;
  int32_T b_n;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  sldProfile_data = sldProfile->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /*  Function handle for adaptive resampling */
  /*  f = @(x) sldFunc(x); */
  /*   */
  if (1 > sldProfile->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, sldProfile->size[1], &xx_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (2 > sldProfile->size[1]) {
    emlrtDynamicBoundsCheckR2012b(2, 1, sldProfile->size[1], &wx_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (1 > sldProfile->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, sldProfile->size[0], &jg_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (sldProfile->size[0] < 1) {
    emlrtDynamicBoundsCheckR2012b(sldProfile->size[0], 1, sldProfile->size[0],
                                  &ig_emlrtBCI, (emlrtCTX)sp);
  }
  emxInitStruct_cell_19(sp, &expl_temp, &ui_emlrtRTEI);
  /*  Keep points and minangle as constants for now */
  /*  will fix later */
  b_sldProfile[0] = sldProfile_data[0];
  b_sldProfile[1] = sldProfile_data[sldProfile->size[0] - 1];
  st.site = &vd_emlrtRSI;
  b_adaptive_new(&st, sldProfile, b_sldProfile,
                 resamPars[0] * 3.1415926535897931, resamPars[1], &expl_temp);
  if (expl_temp.f1->size[0] == 0) {
    n = -1;
  } else if (expl_temp.f1->size[0] > 1) {
    n = expl_temp.f1->size[0] - 1;
  } else {
    n = 0;
  }
  if (n < 0) {
    emlrtNonNegativeCheckR2012b(-1.0, &kb_emlrtDCI, (emlrtCTX)sp);
  }
  b_n = newSLD->size[0] * newSLD->size[1];
  newSLD->size[0] = n;
  newSLD->size[1] = 3;
  emxEnsureCapacity_real_T(sp, newSLD, b_n, &ti_emlrtRTEI);
  newSLD_data = newSLD->data;
  n *= 3;
  for (b_n = 0; b_n < n; b_n++) {
    newSLD_data[b_n] = 0.0;
  }
  /*  Now build a layer model from these resampled points */
  if (expl_temp.f1->size[0] == 0) {
    n = -2;
  } else if (expl_temp.f1->size[0] > 1) {
    n = expl_temp.f1->size[0] - 2;
  } else {
    n = -1;
  }
  for (b_n = 0; b_n <= n; b_n++) {
    if (b_n + 1 > expl_temp.f1->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_n + 1, 1, expl_temp.f1->size[0],
                                    &hg_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_n + 2 > expl_temp.f1->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_n + 2, 1, expl_temp.f1->size[0],
                                    &gg_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_n + 1 > expl_temp.f1->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_n + 1, 1, expl_temp.f1->size[0],
                                    &fg_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_n + 2 > expl_temp.f1->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_n + 2, 1, expl_temp.f1->size[0],
                                    &eg_emlrtBCI, (emlrtCTX)sp);
    }
    thisLayRho = expl_temp.f1->data[(b_n + expl_temp.f1->size[0]) + 1];
    if (thisLayRho > expl_temp.f1->data[b_n + expl_temp.f1->size[0]]) {
      thisLayRho =
          (thisLayRho - expl_temp.f1->data[b_n + expl_temp.f1->size[0]]) / 2.0 +
          expl_temp.f1->data[b_n + expl_temp.f1->size[0]];
    } else {
      thisLayRho +=
          (expl_temp.f1->data[b_n + expl_temp.f1->size[0]] - thisLayRho) / 2.0;
    }
    if (b_n + 1 > newSLD->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_n + 1, 1, newSLD->size[0], &dg_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    newSLD_data[b_n] = expl_temp.f1->data[b_n + 1] - expl_temp.f1->data[b_n];
    newSLD_data[b_n + newSLD->size[0]] = thisLayRho;
    newSLD_data[b_n + newSLD->size[0] * 2] = 2.2204460492503131E-16;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFreeStruct_cell_19(sp, &expl_temp);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void resampleLayers(const emlrtStack *sp, const emxArray_real_T *sldProfile,
                    const real_T resamPars[2], emxArray_real_T *newSLD)
{
  cell_19 expl_temp;
  emlrtStack st;
  real_T b_sldProfile[2];
  const real_T *sldProfile_data;
  real_T thisLayRho;
  real_T *newSLD_data;
  int32_T b_n;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  sldProfile_data = sldProfile->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /*  Function handle for adaptive resampling */
  /*  f = @(x) sldFunc(x); */
  /*   */
  if (1 > sldProfile->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, sldProfile->size[0], &jg_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (sldProfile->size[0] < 1) {
    emlrtDynamicBoundsCheckR2012b(sldProfile->size[0], 1, sldProfile->size[0],
                                  &ig_emlrtBCI, (emlrtCTX)sp);
  }
  emxInitStruct_cell_19(sp, &expl_temp, &ui_emlrtRTEI);
  /*  Keep points and minangle as constants for now */
  /*  will fix later */
  b_sldProfile[0] = sldProfile_data[0];
  b_sldProfile[1] = sldProfile_data[sldProfile->size[0] - 1];
  st.site = &vd_emlrtRSI;
  adaptive_new(&st, sldProfile, b_sldProfile, resamPars[0] * 3.1415926535897931,
               resamPars[1], &expl_temp);
  if (expl_temp.f1->size[0] == 0) {
    n = -1;
  } else if (expl_temp.f1->size[0] > 1) {
    n = expl_temp.f1->size[0] - 1;
  } else {
    n = 0;
  }
  if (n < 0) {
    emlrtNonNegativeCheckR2012b(-1.0, &kb_emlrtDCI, (emlrtCTX)sp);
  }
  b_n = newSLD->size[0] * newSLD->size[1];
  newSLD->size[0] = n;
  newSLD->size[1] = 3;
  emxEnsureCapacity_real_T(sp, newSLD, b_n, &ti_emlrtRTEI);
  newSLD_data = newSLD->data;
  n *= 3;
  for (b_n = 0; b_n < n; b_n++) {
    newSLD_data[b_n] = 0.0;
  }
  /*  Now build a layer model from these resampled points */
  if (expl_temp.f1->size[0] == 0) {
    n = -2;
  } else if (expl_temp.f1->size[0] > 1) {
    n = expl_temp.f1->size[0] - 2;
  } else {
    n = -1;
  }
  for (b_n = 0; b_n <= n; b_n++) {
    if (b_n + 1 > expl_temp.f1->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_n + 1, 1, expl_temp.f1->size[0],
                                    &hg_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_n + 2 > expl_temp.f1->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_n + 2, 1, expl_temp.f1->size[0],
                                    &gg_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_n + 1 > expl_temp.f1->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_n + 1, 1, expl_temp.f1->size[0],
                                    &fg_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_n + 2 > expl_temp.f1->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_n + 2, 1, expl_temp.f1->size[0],
                                    &eg_emlrtBCI, (emlrtCTX)sp);
    }
    thisLayRho = expl_temp.f1->data[(b_n + expl_temp.f1->size[0]) + 1];
    if (thisLayRho > expl_temp.f1->data[b_n + expl_temp.f1->size[0]]) {
      thisLayRho =
          (thisLayRho - expl_temp.f1->data[b_n + expl_temp.f1->size[0]]) / 2.0 +
          expl_temp.f1->data[b_n + expl_temp.f1->size[0]];
    } else {
      thisLayRho +=
          (expl_temp.f1->data[b_n + expl_temp.f1->size[0]] - thisLayRho) / 2.0;
    }
    if (b_n + 1 > newSLD->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_n + 1, 1, newSLD->size[0], &dg_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    newSLD_data[b_n] = expl_temp.f1->data[b_n + 1] - expl_temp.f1->data[b_n];
    newSLD_data[b_n + newSLD->size[0]] = thisLayRho;
    newSLD_data[b_n + newSLD->size[0] * 2] = 2.2204460492503131E-16;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFreeStruct_cell_19(sp, &expl_temp);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (resampleLayers.c) */
