/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * callReflectivity.c
 *
 * Code generation for function 'callReflectivity'
 *
 */

/* Include files */
#include "callReflectivity.h"
#include "abeles_paraPoints.h"
#include "abeles_single.h"
#include "colon.h"
#include "indexShapeCheck.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "resolution_polly.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo cf_emlrtRSI = { 36, /* lineNo */
  "callReflectivity",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m"/* pathName */
};

static emlrtRSInfo df_emlrtRSI = { 43, /* lineNo */
  "callReflectivity",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m"/* pathName */
};

static emlrtRSInfo ef_emlrtRSI = { 62, /* lineNo */
  "callReflectivity",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m"/* pathName */
};

static emlrtRSInfo ff_emlrtRSI = { 63, /* lineNo */
  "callReflectivity",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m"/* pathName */
};

static emlrtRSInfo gf_emlrtRSI = { 69, /* lineNo */
  "callReflectivity",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m"/* pathName */
};

static emlrtRSInfo hf_emlrtRSI = { 71, /* lineNo */
  "callReflectivity",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m"/* pathName */
};

static emlrtRSInfo if_emlrtRSI = { 73, /* lineNo */
  "callReflectivity",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m"/* pathName */
};

static emlrtRSInfo jf_emlrtRSI = { 103,/* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo fg_emlrtRSI = { 55, /* lineNo */
  "callReflectivity",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m"/* pathName */
};

static emlrtRSInfo gg_emlrtRSI = { 56, /* lineNo */
  "callReflectivity",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m"/* pathName */
};

static emlrtBCInfo gh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  11,                                  /* colNo */
  "Ref",                               /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  26,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ih_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  30,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  13,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  13,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  19,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  19,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  28,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  40,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo ri_emlrtRTEI = { 23,/* lineNo */
  5,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo si_emlrtRTEI = { 26,/* lineNo */
  5,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo ti_emlrtRTEI = { 38,/* lineNo */
  5,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo ui_emlrtRTEI = { 45,/* lineNo */
  5,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo vi_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo wi_emlrtRTEI = { 48,/* lineNo */
  1,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo xi_emlrtRTEI = { 43,/* lineNo */
  5,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo yi_emlrtRTEI = { 63,/* lineNo */
  44,                                  /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo aj_emlrtRTEI = { 69,/* lineNo */
  11,                                  /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo bj_emlrtRTEI = { 71,/* lineNo */
  1,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo cj_emlrtRTEI = { 73,/* lineNo */
  15,                                  /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo dj_emlrtRTEI = { 73,/* lineNo */
  1,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo ej_emlrtRTEI = { 55,/* lineNo */
  9,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo oj_emlrtRTEI = { 56,/* lineNo */
  44,                                  /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

/* Function Definitions */
void b_callReflectivity(const emlrtStack *sp, real_T nbairs, real_T nbsubs,
  const real_T simLimits[2], const real_T repeatLayers[2], const emxArray_real_T
  *this_data, const emxArray_real_T *layers, real_T ssubs, real_T res,
  emxArray_real_T *reflectivity, emxArray_real_T *Simulation)
{
  emxArray_real_T *slds;
  int32_T loop_ub;
  int32_T i;
  int32_T lays;
  emxArray_real_T *firstSection;
  real_T step;
  emxArray_real_T *lastSection;
  real_T b;
  emxArray_real_T *simXdata;
  int32_T firstSection_idx_0;
  int32_T b_loop_ub;
  emxArray_real_T *simRef;
  emxArray_real_T *b_simRef;
  uint32_T splits_idx_0;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  nbairs = problem.nbairs; */
  /*  nbsubs = problem.nbsubs; */
  /*  simLimits = problem.simLimits; */
  /*  repeatLayers = problem.repeatLayers; */
  /*  allData = problem.shifted_data; */
  /*  layers = problem.layers; */
  /*  ssubs = problem.ssubs; */
  /*  numberOfContrasts = problem.numberOfContrasts; */
  /*  reflectivity = cell(numberOfContrasts,1); */
  /*  Simulation = cell(numberOfContrasts,1); */
  /*   */
  /*  parfor i = 1:numberOfContrasts */
  /* this_data = allData{i}; */
  emxInit_real_T(sp, &slds, 2, &ri_emlrtRTEI, true);
  if (layers->size[0] == 0) {
    i = slds->size[0] * slds->size[1];
    slds->size[0] = 1;
    slds->size[1] = 3;
    emxEnsureCapacity_real_T(sp, slds, i, &ri_emlrtRTEI);
    slds->data[0] = 0.0;
    slds->data[1] = nbairs;
    slds->data[2] = 0.0;
    lays = 0;
  } else {
    loop_ub = layers->size[0];
    i = slds->size[0] * slds->size[1];
    slds->size[0] = layers->size[0];
    slds->size[1] = 3;
    emxEnsureCapacity_real_T(sp, slds, i, &si_emlrtRTEI);
    for (i = 0; i < 3; i++) {
      for (lays = 0; lays < loop_ub; lays++) {
        slds->data[lays + slds->size[0] * i] = layers->data[lays + layers->size
          [0] * i];
      }
    }

    lays = layers->size[0];
  }

  if (1 > this_data->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &lh_emlrtBCI, sp);
  }

  emxInit_real_T(sp, &firstSection, 2, &vi_emlrtRTEI, true);
  if (simLimits[0] < this_data->data[0]) {
    if (2 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, this_data->size[0], &mh_emlrtBCI, sp);
    }

    if (1 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &nh_emlrtBCI, sp);
    }

    step = this_data->data[1] - this_data->data[0];
    if (1 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &oh_emlrtBCI, sp);
    }

    st.site = &cf_emlrtRSI;
    b = this_data->data[0] - step;
    if (muDoubleScalarIsNaN(step) || muDoubleScalarIsNaN(b)) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &vi_emlrtRTEI);
      firstSection->data[0] = rtNaN;
    } else if ((step == 0.0) || ((simLimits[0] < b) && (step < 0.0)) || ((b <
                 simLimits[0]) && (step > 0.0))) {
      firstSection->size[0] = 1;
      firstSection->size[1] = 0;
    } else if ((muDoubleScalarIsInf(simLimits[0]) || muDoubleScalarIsInf(b)) &&
               (muDoubleScalarIsInf(step) || (simLimits[0] == b))) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &vi_emlrtRTEI);
      firstSection->data[0] = rtNaN;
    } else if (muDoubleScalarIsInf(step)) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &vi_emlrtRTEI);
      firstSection->data[0] = simLimits[0];
    } else if ((muDoubleScalarFloor(simLimits[0]) == simLimits[0]) &&
               (muDoubleScalarFloor(step) == step)) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      loop_ub = (int32_T)muDoubleScalarFloor((b - simLimits[0]) / step);
      firstSection->size[1] = loop_ub + 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &vi_emlrtRTEI);
      for (i = 0; i <= loop_ub; i++) {
        firstSection->data[i] = simLimits[0] + step * (real_T)i;
      }
    } else {
      b_st.site = &jf_emlrtRSI;
      eml_float_colon(&b_st, simLimits[0], step, b, firstSection);
    }
  } else {
    i = firstSection->size[0] * firstSection->size[1];
    firstSection->size[0] = 1;
    firstSection->size[1] = 1;
    emxEnsureCapacity_real_T(sp, firstSection, i, &ti_emlrtRTEI);
    firstSection->data[0] = 0.0;
  }

  if (this_data->size[0] < 1) {
    emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
      &kh_emlrtBCI, sp);
  }

  emxInit_real_T(sp, &lastSection, 2, &xi_emlrtRTEI, true);
  if (simLimits[1] > this_data->data[this_data->size[0] - 1]) {
    i = this_data->size[0] - 1;
    if ((i < 1) || (i > this_data->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, this_data->size[0], &ih_emlrtBCI, sp);
    }

    if (this_data->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
        &jh_emlrtBCI, sp);
    }

    step = this_data->data[this_data->size[0] - 1] - this_data->data[i - 1];
    st.site = &df_emlrtRSI;
    if (this_data->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
        &hh_emlrtBCI, &st);
    }

    b = this_data->data[this_data->size[0] - 1] + step;
    if (muDoubleScalarIsNaN(b) || muDoubleScalarIsNaN(step)) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &xi_emlrtRTEI);
      lastSection->data[0] = rtNaN;
    } else if ((step == 0.0) || ((b < simLimits[1]) && (step < 0.0)) ||
               ((simLimits[1] < b) && (step > 0.0))) {
      lastSection->size[0] = 1;
      lastSection->size[1] = 0;
    } else if ((muDoubleScalarIsInf(b) || muDoubleScalarIsInf(simLimits[1])) &&
               (muDoubleScalarIsInf(step) || (b == simLimits[1]))) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &xi_emlrtRTEI);
      lastSection->data[0] = rtNaN;
    } else if (muDoubleScalarIsInf(step)) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &xi_emlrtRTEI);
      lastSection->data[0] = b;
    } else if ((muDoubleScalarFloor(b) == b) && (muDoubleScalarFloor(step) ==
                step)) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      loop_ub = (int32_T)muDoubleScalarFloor((simLimits[1] - b) / step);
      lastSection->size[1] = loop_ub + 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &xi_emlrtRTEI);
      for (i = 0; i <= loop_ub; i++) {
        lastSection->data[i] = b + step * (real_T)i;
      }
    } else {
      b_st.site = &jf_emlrtRSI;
      eml_float_colon(&b_st, b, step, simLimits[1], lastSection);
    }
  } else {
    i = lastSection->size[0] * lastSection->size[1];
    lastSection->size[0] = 1;
    lastSection->size[1] = 1;
    emxEnsureCapacity_real_T(sp, lastSection, i, &ui_emlrtRTEI);
    lastSection->data[0] = 0.0;
  }

  emxInit_real_T(sp, &simXdata, 2, &wi_emlrtRTEI, true);
  firstSection_idx_0 = firstSection->size[1];
  loop_ub = this_data->size[0];
  i = simXdata->size[0] * simXdata->size[1];
  simXdata->size[0] = 1;
  simXdata->size[1] = (firstSection->size[1] + this_data->size[0]) +
    lastSection->size[1];
  emxEnsureCapacity_real_T(sp, simXdata, i, &wi_emlrtRTEI);
  b_loop_ub = firstSection->size[1];
  for (i = 0; i < b_loop_ub; i++) {
    simXdata->data[i] = firstSection->data[i];
  }

  for (i = 0; i < loop_ub; i++) {
    simXdata->data[i + firstSection_idx_0] = this_data->data[i];
  }

  b_loop_ub = lastSection->size[1];
  for (i = 0; i < b_loop_ub; i++) {
    simXdata->data[(i + firstSection_idx_0) + loop_ub] = lastSection->data[i];
  }

  emxFree_real_T(&lastSection);
  emxInit_real_T(sp, &simRef, 1, &ej_emlrtRTEI, true);
  emxInit_real_T(sp, &b_simRef, 1, &oj_emlrtRTEI, true);
  splits_idx_0 = (uint32_T)firstSection->size[1];
  st.site = &fg_emlrtRSI;
  abeles_paraPoints(&st, simXdata, slds, nbairs, nbsubs, repeatLayers[1], ssubs,
                    lays, simXdata->size[1], simRef);

  /* (x,sld,nbair,nbsub,nrepeats,ssub,layers,points) */
  i = b_simRef->size[0];
  b_simRef->size[0] = simRef->size[0];
  emxEnsureCapacity_real_T(sp, b_simRef, i, &oj_emlrtRTEI);
  loop_ub = simRef->size[0] - 1;
  emxFree_real_T(&slds);
  for (i = 0; i <= loop_ub; i++) {
    b_simRef->data[i] = simRef->data[i];
  }

  st.site = &gg_emlrtRSI;
  resolution_polly(&st, simXdata, b_simRef, res, simXdata->size[1], simRef);
  i = firstSection->size[0] * firstSection->size[1];
  firstSection->size[0] = 1;
  firstSection->size[1] = this_data->size[0];
  emxEnsureCapacity_real_T(sp, firstSection, i, &aj_emlrtRTEI);
  loop_ub = this_data->size[0] - 1;
  for (i = 0; i <= loop_ub; i++) {
    lays = (int32_T)((i + splits_idx_0) + 1U);
    if ((lays < 1) || (lays > simRef->size[0])) {
      emlrtDynamicBoundsCheckR2012b(lays, 1, simRef->size[0], &gh_emlrtBCI, sp);
    }

    firstSection->data[i] = lays;
  }

  st.site = &gf_emlrtRSI;
  indexShapeCheck(&st, simRef->size[0], *(int32_T (*)[2])firstSection->size);

  /* Ref = Ref + backgrounds; */
  st.site = &hf_emlrtRSI;
  b_st.site = &t_emlrtRSI;
  c_st.site = &u_emlrtRSI;
  if (firstSection->size[1] != this_data->size[0]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &hb_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  loop_ub = this_data->size[0];
  i = reflectivity->size[0] * reflectivity->size[1];
  reflectivity->size[0] = this_data->size[0];
  reflectivity->size[1] = 2;
  emxEnsureCapacity_real_T(&b_st, reflectivity, i, &bj_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    reflectivity->data[i] = this_data->data[i];
  }

  loop_ub = firstSection->size[1];
  for (i = 0; i < loop_ub; i++) {
    reflectivity->data[i + reflectivity->size[0]] = simRef->data[(int32_T)
      firstSection->data[i] - 1];
  }

  emxFree_real_T(&firstSection);

  /* simRef = simRef + backgrounds; */
  st.site = &if_emlrtRSI;
  i = b_simRef->size[0];
  b_simRef->size[0] = simXdata->size[1];
  emxEnsureCapacity_real_T(&st, b_simRef, i, &cj_emlrtRTEI);
  loop_ub = simXdata->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_simRef->data[i] = simXdata->data[i];
  }

  emxFree_real_T(&simXdata);
  b_st.site = &t_emlrtRSI;
  c_st.site = &u_emlrtRSI;
  if (simRef->size[0] != b_simRef->size[0]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &hb_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  i = Simulation->size[0] * Simulation->size[1];
  Simulation->size[0] = b_simRef->size[0];
  Simulation->size[1] = 2;
  emxEnsureCapacity_real_T(&b_st, Simulation, i, &dj_emlrtRTEI);
  loop_ub = b_simRef->size[0];
  for (i = 0; i < loop_ub; i++) {
    Simulation->data[i] = b_simRef->data[i];
  }

  emxFree_real_T(&b_simRef);
  loop_ub = simRef->size[0];
  for (i = 0; i < loop_ub; i++) {
    Simulation->data[i + Simulation->size[0]] = simRef->data[i];
  }

  emxFree_real_T(&simRef);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void callReflectivity(const emlrtStack *sp, real_T nbairs, real_T nbsubs, const
                      real_T simLimits[2], const real_T repeatLayers[2], const
                      emxArray_real_T *this_data, const emxArray_real_T *layers,
                      real_T ssubs, real_T res, emxArray_real_T *reflectivity,
                      emxArray_real_T *Simulation)
{
  emxArray_real_T *slds;
  int32_T loop_ub;
  int32_T i;
  int32_T lays;
  emxArray_real_T *firstSection;
  real_T step;
  emxArray_real_T *lastSection;
  real_T b;
  emxArray_real_T *simXdata;
  int32_T firstSection_idx_0;
  int32_T b_loop_ub;
  emxArray_real_T *simRef;
  emxArray_real_T *b_simRef;
  uint32_T splits_idx_0;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  nbairs = problem.nbairs; */
  /*  nbsubs = problem.nbsubs; */
  /*  simLimits = problem.simLimits; */
  /*  repeatLayers = problem.repeatLayers; */
  /*  allData = problem.shifted_data; */
  /*  layers = problem.layers; */
  /*  ssubs = problem.ssubs; */
  /*  numberOfContrasts = problem.numberOfContrasts; */
  /*  reflectivity = cell(numberOfContrasts,1); */
  /*  Simulation = cell(numberOfContrasts,1); */
  /*   */
  /*  parfor i = 1:numberOfContrasts */
  /* this_data = allData{i}; */
  emxInit_real_T(sp, &slds, 2, &ri_emlrtRTEI, true);
  if (layers->size[0] == 0) {
    i = slds->size[0] * slds->size[1];
    slds->size[0] = 1;
    slds->size[1] = 3;
    emxEnsureCapacity_real_T(sp, slds, i, &ri_emlrtRTEI);
    slds->data[0] = 0.0;
    slds->data[1] = nbairs;
    slds->data[2] = 0.0;
    lays = 0;
  } else {
    loop_ub = layers->size[0];
    i = slds->size[0] * slds->size[1];
    slds->size[0] = layers->size[0];
    slds->size[1] = 3;
    emxEnsureCapacity_real_T(sp, slds, i, &si_emlrtRTEI);
    for (i = 0; i < 3; i++) {
      for (lays = 0; lays < loop_ub; lays++) {
        slds->data[lays + slds->size[0] * i] = layers->data[lays + layers->size
          [0] * i];
      }
    }

    lays = layers->size[0];
  }

  if (1 > this_data->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &lh_emlrtBCI, sp);
  }

  emxInit_real_T(sp, &firstSection, 2, &vi_emlrtRTEI, true);
  if (simLimits[0] < this_data->data[0]) {
    if (2 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, this_data->size[0], &mh_emlrtBCI, sp);
    }

    if (1 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &nh_emlrtBCI, sp);
    }

    step = this_data->data[1] - this_data->data[0];
    if (1 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &oh_emlrtBCI, sp);
    }

    st.site = &cf_emlrtRSI;
    b = this_data->data[0] - step;
    if (muDoubleScalarIsNaN(step) || muDoubleScalarIsNaN(b)) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &vi_emlrtRTEI);
      firstSection->data[0] = rtNaN;
    } else if ((step == 0.0) || ((simLimits[0] < b) && (step < 0.0)) || ((b <
                 simLimits[0]) && (step > 0.0))) {
      firstSection->size[0] = 1;
      firstSection->size[1] = 0;
    } else if ((muDoubleScalarIsInf(simLimits[0]) || muDoubleScalarIsInf(b)) &&
               (muDoubleScalarIsInf(step) || (simLimits[0] == b))) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &vi_emlrtRTEI);
      firstSection->data[0] = rtNaN;
    } else if (muDoubleScalarIsInf(step)) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &vi_emlrtRTEI);
      firstSection->data[0] = simLimits[0];
    } else if ((muDoubleScalarFloor(simLimits[0]) == simLimits[0]) &&
               (muDoubleScalarFloor(step) == step)) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      loop_ub = (int32_T)muDoubleScalarFloor((b - simLimits[0]) / step);
      firstSection->size[1] = loop_ub + 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &vi_emlrtRTEI);
      for (i = 0; i <= loop_ub; i++) {
        firstSection->data[i] = simLimits[0] + step * (real_T)i;
      }
    } else {
      b_st.site = &jf_emlrtRSI;
      eml_float_colon(&b_st, simLimits[0], step, b, firstSection);
    }
  } else {
    i = firstSection->size[0] * firstSection->size[1];
    firstSection->size[0] = 1;
    firstSection->size[1] = 1;
    emxEnsureCapacity_real_T(sp, firstSection, i, &ti_emlrtRTEI);
    firstSection->data[0] = 0.0;
  }

  if (this_data->size[0] < 1) {
    emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
      &kh_emlrtBCI, sp);
  }

  emxInit_real_T(sp, &lastSection, 2, &xi_emlrtRTEI, true);
  if (simLimits[1] > this_data->data[this_data->size[0] - 1]) {
    i = this_data->size[0] - 1;
    if ((i < 1) || (i > this_data->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, this_data->size[0], &ih_emlrtBCI, sp);
    }

    if (this_data->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
        &jh_emlrtBCI, sp);
    }

    step = this_data->data[this_data->size[0] - 1] - this_data->data[i - 1];
    st.site = &df_emlrtRSI;
    if (this_data->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
        &hh_emlrtBCI, &st);
    }

    b = this_data->data[this_data->size[0] - 1] + step;
    if (muDoubleScalarIsNaN(b) || muDoubleScalarIsNaN(step)) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &xi_emlrtRTEI);
      lastSection->data[0] = rtNaN;
    } else if ((step == 0.0) || ((b < simLimits[1]) && (step < 0.0)) ||
               ((simLimits[1] < b) && (step > 0.0))) {
      lastSection->size[0] = 1;
      lastSection->size[1] = 0;
    } else if ((muDoubleScalarIsInf(b) || muDoubleScalarIsInf(simLimits[1])) &&
               (muDoubleScalarIsInf(step) || (b == simLimits[1]))) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &xi_emlrtRTEI);
      lastSection->data[0] = rtNaN;
    } else if (muDoubleScalarIsInf(step)) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &xi_emlrtRTEI);
      lastSection->data[0] = b;
    } else if ((muDoubleScalarFloor(b) == b) && (muDoubleScalarFloor(step) ==
                step)) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      loop_ub = (int32_T)muDoubleScalarFloor((simLimits[1] - b) / step);
      lastSection->size[1] = loop_ub + 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &xi_emlrtRTEI);
      for (i = 0; i <= loop_ub; i++) {
        lastSection->data[i] = b + step * (real_T)i;
      }
    } else {
      b_st.site = &jf_emlrtRSI;
      eml_float_colon(&b_st, b, step, simLimits[1], lastSection);
    }
  } else {
    i = lastSection->size[0] * lastSection->size[1];
    lastSection->size[0] = 1;
    lastSection->size[1] = 1;
    emxEnsureCapacity_real_T(sp, lastSection, i, &ui_emlrtRTEI);
    lastSection->data[0] = 0.0;
  }

  emxInit_real_T(sp, &simXdata, 2, &wi_emlrtRTEI, true);
  firstSection_idx_0 = firstSection->size[1];
  loop_ub = this_data->size[0];
  i = simXdata->size[0] * simXdata->size[1];
  simXdata->size[0] = 1;
  simXdata->size[1] = (firstSection->size[1] + this_data->size[0]) +
    lastSection->size[1];
  emxEnsureCapacity_real_T(sp, simXdata, i, &wi_emlrtRTEI);
  b_loop_ub = firstSection->size[1];
  for (i = 0; i < b_loop_ub; i++) {
    simXdata->data[i] = firstSection->data[i];
  }

  for (i = 0; i < loop_ub; i++) {
    simXdata->data[i + firstSection_idx_0] = this_data->data[i];
  }

  b_loop_ub = lastSection->size[1];
  for (i = 0; i < b_loop_ub; i++) {
    simXdata->data[(i + firstSection_idx_0) + loop_ub] = lastSection->data[i];
  }

  emxFree_real_T(&lastSection);
  emxInit_real_T(sp, &simRef, 1, &ej_emlrtRTEI, true);
  emxInit_real_T(sp, &b_simRef, 1, &yi_emlrtRTEI, true);
  splits_idx_0 = (uint32_T)firstSection->size[1];

  /* simRef = abeles_single(simXdata, slds, nbairs, nbsubs, repeats, ssubs, lays, length(simXdata)); %(x,sld,nbair,nbsub,nrepeats,ssub,layers,points) */
  /* function out = paratt(x,sld,nbair,nbsub,nrepeats,rfinal,layers,points) */
  st.site = &ef_emlrtRSI;
  abeles_single(&st, simXdata, slds, nbairs, nbsubs, repeatLayers[1], ssubs,
                lays, simXdata->size[1], simRef);
  i = b_simRef->size[0];
  b_simRef->size[0] = simRef->size[0];
  emxEnsureCapacity_real_T(sp, b_simRef, i, &yi_emlrtRTEI);
  loop_ub = simRef->size[0] - 1;
  emxFree_real_T(&slds);
  for (i = 0; i <= loop_ub; i++) {
    b_simRef->data[i] = simRef->data[i];
  }

  st.site = &ff_emlrtRSI;
  resolution_polly(&st, simXdata, b_simRef, res, simXdata->size[1], simRef);
  i = firstSection->size[0] * firstSection->size[1];
  firstSection->size[0] = 1;
  firstSection->size[1] = this_data->size[0];
  emxEnsureCapacity_real_T(sp, firstSection, i, &aj_emlrtRTEI);
  loop_ub = this_data->size[0] - 1;
  for (i = 0; i <= loop_ub; i++) {
    lays = (int32_T)((i + splits_idx_0) + 1U);
    if ((lays < 1) || (lays > simRef->size[0])) {
      emlrtDynamicBoundsCheckR2012b(lays, 1, simRef->size[0], &gh_emlrtBCI, sp);
    }

    firstSection->data[i] = lays;
  }

  st.site = &gf_emlrtRSI;
  indexShapeCheck(&st, simRef->size[0], *(int32_T (*)[2])firstSection->size);

  /* Ref = Ref + backgrounds; */
  st.site = &hf_emlrtRSI;
  b_st.site = &t_emlrtRSI;
  c_st.site = &u_emlrtRSI;
  if (firstSection->size[1] != this_data->size[0]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &hb_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  loop_ub = this_data->size[0];
  i = reflectivity->size[0] * reflectivity->size[1];
  reflectivity->size[0] = this_data->size[0];
  reflectivity->size[1] = 2;
  emxEnsureCapacity_real_T(&b_st, reflectivity, i, &bj_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    reflectivity->data[i] = this_data->data[i];
  }

  loop_ub = firstSection->size[1];
  for (i = 0; i < loop_ub; i++) {
    reflectivity->data[i + reflectivity->size[0]] = simRef->data[(int32_T)
      firstSection->data[i] - 1];
  }

  emxFree_real_T(&firstSection);

  /* simRef = simRef + backgrounds; */
  st.site = &if_emlrtRSI;
  i = b_simRef->size[0];
  b_simRef->size[0] = simXdata->size[1];
  emxEnsureCapacity_real_T(&st, b_simRef, i, &cj_emlrtRTEI);
  loop_ub = simXdata->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_simRef->data[i] = simXdata->data[i];
  }

  emxFree_real_T(&simXdata);
  b_st.site = &t_emlrtRSI;
  c_st.site = &u_emlrtRSI;
  if (simRef->size[0] != b_simRef->size[0]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &hb_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  i = Simulation->size[0] * Simulation->size[1];
  Simulation->size[0] = b_simRef->size[0];
  Simulation->size[1] = 2;
  emxEnsureCapacity_real_T(&b_st, Simulation, i, &dj_emlrtRTEI);
  loop_ub = b_simRef->size[0];
  for (i = 0; i < loop_ub; i++) {
    Simulation->data[i] = b_simRef->data[i];
  }

  emxFree_real_T(&b_simRef);
  loop_ub = simRef->size[0];
  for (i = 0; i < loop_ub; i++) {
    Simulation->data[i + Simulation->size[0]] = simRef->data[i];
  }

  emxFree_real_T(&simRef);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (callReflectivity.c) */
