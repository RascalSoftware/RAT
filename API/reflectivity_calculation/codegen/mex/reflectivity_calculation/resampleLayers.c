/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * resampleLayers.c
 *
 * Code generation for function 'resampleLayers'
 *
 */

/* Include files */
#include "resampleLayers.h"
#include "adaptive.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo vc_emlrtRSI = { 18, /* lineNo */
  "resampleLayers",                    /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"/* pathName */
};

static emlrtBCInfo wd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  12,                                  /* colNo */
  "layers",                            /* aName */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  30,                                  /* lineNo */
  18,                                  /* colNo */
  "newY",                              /* aName */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  18,                                  /* colNo */
  "newY",                              /* aName */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  28,                                  /* lineNo */
  18,                                  /* colNo */
  "newX",                              /* aName */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo be_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  27,                                  /* lineNo */
  18,                                  /* colNo */
  "newX",                              /* aName */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ce_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  10,                                  /* colNo */
  "x",                                 /* aName */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo de_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  12,                                  /* colNo */
  "x",                                 /* aName */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo gb_emlrtDCI = { 23, /* lineNo */
  16,                                  /* colNo */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",/* pName */
  4                                    /* checkKind */
};

static emlrtRTEInfo pi_emlrtRTEI = { 18,/* lineNo */
  1,                                   /* colNo */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"/* pName */
};

static emlrtRTEInfo qi_emlrtRTEI = { 23,/* lineNo */
  1,                                   /* colNo */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"/* pName */
};

/* Function Definitions */
void resampleLayers(const emlrtStack *sp, const emxArray_real_T *sldProfile,
                    emxArray_real_T *newSLD)
{
  emxArray_real_T *out_f1;
  cell_18 expl_temp;
  real_T b_sldProfile[2];
  int32_T i;
  int32_T loop_ub;
  int32_T n;
  int32_T i1;
  real_T thisLayRho;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 12U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 0U);

  /*  Function handle for adaptive resampling */
  /*  f = @(x) sldFunc(x); */
  /*   */
  if (1 > sldProfile->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, sldProfile->size[0], &de_emlrtBCI, sp);
  }

  if (sldProfile->size[0] < 1) {
    emlrtDynamicBoundsCheckR2012b(sldProfile->size[0], 1, sldProfile->size[0],
      &ce_emlrtBCI, sp);
  }

  emxInit_real_T(sp, &out_f1, 2, &pi_emlrtRTEI, true);
  emxInitStruct_cell_18(sp, &expl_temp, &pi_emlrtRTEI, true);

  /*  Keep points and minangle as constants for now */
  /*  will fix later */
  b_sldProfile[0] = sldProfile->data[0];
  b_sldProfile[1] = sldProfile->data[sldProfile->size[0] - 1];
  st.site = &vc_emlrtRSI;
  adaptive(&st, sldProfile, b_sldProfile, &expl_temp);
  i = out_f1->size[0] * out_f1->size[1];
  out_f1->size[0] = expl_temp.f1->size[0];
  out_f1->size[1] = 2;
  emxEnsureCapacity_real_T(sp, out_f1, i, &pi_emlrtRTEI);
  loop_ub = expl_temp.f1->size[0] * expl_temp.f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    out_f1->data[i] = expl_temp.f1->data[i];
  }

  emxFreeStruct_cell_18(&expl_temp);
  if (out_f1->size[0] == 0) {
    loop_ub = -1;
  } else if (out_f1->size[0] > 1) {
    loop_ub = out_f1->size[0] - 1;
  } else {
    loop_ub = 0;
  }

  if (loop_ub < 0) {
    emlrtNonNegativeCheckR2012b(loop_ub, &gb_emlrtDCI, sp);
  }

  i = newSLD->size[0] * newSLD->size[1];
  newSLD->size[0] = loop_ub;
  newSLD->size[1] = 3;
  emxEnsureCapacity_real_T(sp, newSLD, i, &qi_emlrtRTEI);
  loop_ub *= 3;
  for (i = 0; i < loop_ub; i++) {
    newSLD->data[i] = 0.0;
  }

  /*  Now build a layer model from these resampled points */
  if (out_f1->size[0] == 0) {
    loop_ub = -2;
  } else if (out_f1->size[0] > 1) {
    loop_ub = out_f1->size[0] - 2;
  } else {
    loop_ub = -1;
  }

  for (n = 0; n <= loop_ub; n++) {
    covrtLogFor(&emlrtCoverageInstance, 12U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 1U);
    i = n + 1;
    if ((i < 1) || (i > out_f1->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, out_f1->size[0], &be_emlrtBCI, sp);
    }

    i = (int32_T)(((real_T)n + 1.0) + 1.0);
    if ((i < 1) || (i > out_f1->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, out_f1->size[0], &ae_emlrtBCI, sp);
    }

    i1 = n + 1;
    if ((i1 < 1) || (i1 > out_f1->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, out_f1->size[0], &yd_emlrtBCI, sp);
    }

    if (i > out_f1->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, out_f1->size[0], &xd_emlrtBCI, sp);
    }

    thisLayRho = out_f1->data[(n + out_f1->size[0]) + 1];
    if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 0, thisLayRho > out_f1->
                   data[n + out_f1->size[0]])) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 2U);
      thisLayRho = (thisLayRho - out_f1->data[n + out_f1->size[0]]) / 2.0 +
        out_f1->data[n + out_f1->size[0]];
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 3U);
      thisLayRho += (out_f1->data[n + out_f1->size[0]] - thisLayRho) / 2.0;
    }

    covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 4U);
    i = n + 1;
    if ((i < 1) || (i > newSLD->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, newSLD->size[0], &wd_emlrtBCI, sp);
    }

    newSLD->data[n] = out_f1->data[n + 1] - out_f1->data[n];
    newSLD->data[n + newSLD->size[0]] = thisLayRho;
    newSLD->data[n + newSLD->size[0] * 2] = 2.2204460492503131E-16;
  }

  emxFree_real_T(&out_f1);
  covrtLogFor(&emlrtCoverageInstance, 12U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 5U);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (resampleLayers.c) */
