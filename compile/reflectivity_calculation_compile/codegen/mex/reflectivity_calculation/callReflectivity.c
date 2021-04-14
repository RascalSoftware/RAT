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
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "resolution_polly.h"
#include "resolution_polly_paraPoints.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo pf_emlrtRSI = { 37, /* lineNo */
  "callReflectivity",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pathName */
};

static emlrtRSInfo qf_emlrtRSI = { 44, /* lineNo */
  "callReflectivity",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pathName */
};

static emlrtRSInfo rf_emlrtRSI = { 67, /* lineNo */
  "callReflectivity",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pathName */
};

static emlrtRSInfo sf_emlrtRSI = { 68, /* lineNo */
  "callReflectivity",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pathName */
};

static emlrtRSInfo tf_emlrtRSI = { 103,/* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo uf_emlrtRSI = { 288,/* lineNo */
  "eml_float_colon",                   /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo lg_emlrtRSI = { 62, /* lineNo */
  "callReflectivity",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pathName */
};

static emlrtRSInfo mg_emlrtRSI = { 63, /* lineNo */
  "callReflectivity",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pathName */
};

static emlrtBCInfo re_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  26,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo se_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  30,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo te_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  13,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ue_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  13,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ve_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  13,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo we_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  19,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  28,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ye_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  37,                                  /* lineNo */
  40,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo q_emlrtECI = { -1,  /* nDims */
  53,                                  /* lineNo */
  1,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtECInfo r_emlrtECI = { -1,  /* nDims */
  73,                                  /* lineNo */
  1,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtBCInfo af_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  27,                                  /* colNo */
  "Simulation",                        /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  37,                                  /* colNo */
  "Simulation",                        /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo pb_emlrtRTEI = { 405,/* lineNo */
  15,                                  /* colNo */
  "assert_pmaxsize",                   /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

static emlrtRTEInfo sj_emlrtRTEI = { 23,/* lineNo */
  5,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo tj_emlrtRTEI = { 26,/* lineNo */
  5,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo uj_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo vj_emlrtRTEI = { 49,/* lineNo */
  1,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo wj_emlrtRTEI = { 44,/* lineNo */
  5,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo xj_emlrtRTEI = { 52,/* lineNo */
  1,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo yj_emlrtRTEI = { 68,/* lineNo */
  52,                                  /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo ak_emlrtRTEI = { 103,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

static emlrtRTEInfo bk_emlrtRTEI = { 74,/* lineNo */
  1,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo ck_emlrtRTEI = { 62,/* lineNo */
  17,                                  /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo vk_emlrtRTEI = { 63,/* lineNo */
  63,                                  /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
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
  int32_T nm1d2;
  emxArray_real_T *firstSection;
  real_T step;
  emxArray_real_T *lastSection;
  real_T kd;
  emxArray_real_T *simXdata;
  real_T ndbl;
  real_T apnd;
  real_T a;
  int32_T n;
  real_T cdiff;
  real_T absa;
  real_T absb;
  uint32_T splits_idx_1;
  emxArray_real_T *simRef;
  emxArray_real_T *b_simRef;
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
  covrtLogFcn(&emlrtCoverageInstance, 18U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 0U);

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
  emxInit_real_T(sp, &slds, 2, &sj_emlrtRTEI, true);
  if (covrtLogIf(&emlrtCoverageInstance, 18U, 0U, 0, layers->size[0] == 0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 1U);
    i = slds->size[0] * slds->size[1];
    slds->size[0] = 1;
    slds->size[1] = 3;
    emxEnsureCapacity_real_T(sp, slds, i, &sj_emlrtRTEI);
    slds->data[0] = 0.0;
    slds->data[1] = nbairs;
    slds->data[2] = 0.0;
    lays = 0;
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 2U);
    loop_ub = layers->size[0];
    i = slds->size[0] * slds->size[1];
    slds->size[0] = layers->size[0];
    slds->size[1] = 3;
    emxEnsureCapacity_real_T(sp, slds, i, &tj_emlrtRTEI);
    for (i = 0; i < 3; i++) {
      for (nm1d2 = 0; nm1d2 < loop_ub; nm1d2++) {
        slds->data[nm1d2 + slds->size[0] * i] = layers->data[nm1d2 +
          layers->size[0] * i];
      }
    }

    lays = layers->size[0];
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 3U);
  if (1 > this_data->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &ve_emlrtBCI, sp);
  }

  emxInit_real_T(sp, &firstSection, 2, &uj_emlrtRTEI, true);
  if (covrtLogIf(&emlrtCoverageInstance, 18U, 0U, 1, simLimits[0] <
                 this_data->data[0])) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 4U);
    if (2 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, this_data->size[0], &we_emlrtBCI, sp);
    }

    if (1 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &xe_emlrtBCI, sp);
    }

    step = this_data->data[1] - this_data->data[0];
    if (1 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &ye_emlrtBCI, sp);
    }

    st.site = &pf_emlrtRSI;
    kd = this_data->data[0] - step;
    if (muDoubleScalarIsNaN(step) || muDoubleScalarIsNaN(kd)) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &uj_emlrtRTEI);
      firstSection->data[0] = rtNaN;
    } else if ((step == 0.0) || ((simLimits[0] < kd) && (step < 0.0)) || ((kd <
                 simLimits[0]) && (step > 0.0))) {
      firstSection->size[0] = 1;
      firstSection->size[1] = 0;
    } else if ((muDoubleScalarIsInf(simLimits[0]) || muDoubleScalarIsInf(kd)) &&
               (muDoubleScalarIsInf(step) || (simLimits[0] == kd))) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &uj_emlrtRTEI);
      firstSection->data[0] = rtNaN;
    } else if (muDoubleScalarIsInf(step)) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &uj_emlrtRTEI);
      firstSection->data[0] = simLimits[0];
    } else if ((muDoubleScalarFloor(simLimits[0]) == simLimits[0]) &&
               (muDoubleScalarFloor(step) == step)) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      loop_ub = (int32_T)muDoubleScalarFloor((kd - simLimits[0]) / step);
      firstSection->size[1] = loop_ub + 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &uj_emlrtRTEI);
      for (i = 0; i <= loop_ub; i++) {
        firstSection->data[i] = simLimits[0] + step * (real_T)i;
      }
    } else {
      b_st.site = &tf_emlrtRSI;
      ndbl = muDoubleScalarFloor((kd - simLimits[0]) / step + 0.5);
      apnd = simLimits[0] + ndbl * step;
      if (step > 0.0) {
        cdiff = apnd - kd;
      } else {
        cdiff = kd - apnd;
      }

      absa = muDoubleScalarAbs(simLimits[0]);
      absb = muDoubleScalarAbs(kd);
      if (absa > absb) {
        absb = absa;
      }

      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * absb) {
        ndbl++;
        apnd = kd;
      } else if (cdiff > 0.0) {
        apnd = simLimits[0] + (ndbl - 1.0) * step;
      } else {
        ndbl++;
      }

      if (ndbl >= 0.0) {
        n = (int32_T)ndbl;
      } else {
        n = 0;
      }

      c_st.site = &uf_emlrtRSI;
      if (ndbl > 2.147483647E+9) {
        emlrtErrorWithMessageIdR2018a(&c_st, &pb_emlrtRTEI,
          "Coder:MATLAB:pmaxsize", "Coder:MATLAB:pmaxsize", 0);
      }

      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = n;
      emxEnsureCapacity_real_T(&b_st, firstSection, i, &ak_emlrtRTEI);
      if (n > 0) {
        firstSection->data[0] = simLimits[0];
        if (n > 1) {
          firstSection->data[n - 1] = apnd;
          nm1d2 = (n - 1) / 2;
          for (loop_ub = 0; loop_ub <= nm1d2 - 2; loop_ub++) {
            kd = ((real_T)loop_ub + 1.0) * step;
            firstSection->data[loop_ub + 1] = simLimits[0] + kd;
            firstSection->data[(n - loop_ub) - 2] = apnd - kd;
          }

          if (nm1d2 << 1 == n - 1) {
            firstSection->data[nm1d2] = (simLimits[0] + apnd) / 2.0;
          } else {
            kd = (real_T)nm1d2 * step;
            firstSection->data[nm1d2] = simLimits[0] + kd;
            firstSection->data[nm1d2 + 1] = apnd - kd;
          }
        }
      }
    }
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 5U);
    firstSection->size[0] = 1;
    firstSection->size[1] = 0;
  }

  if (this_data->size[0] < 1) {
    emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
      &ue_emlrtBCI, sp);
  }

  emxInit_real_T(sp, &lastSection, 2, &wj_emlrtRTEI, true);
  if (covrtLogIf(&emlrtCoverageInstance, 18U, 0U, 2, simLimits[1] >
                 this_data->data[this_data->size[0] - 1])) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 6U);
    i = this_data->size[0] - 1;
    if ((i < 1) || (i > this_data->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, this_data->size[0], &se_emlrtBCI, sp);
    }

    if (this_data->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
        &te_emlrtBCI, sp);
    }

    step = this_data->data[this_data->size[0] - 1] - this_data->data[i - 1];
    st.site = &qf_emlrtRSI;
    if (this_data->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
        &re_emlrtBCI, &st);
    }

    a = this_data->data[this_data->size[0] - 1] + step;
    if (muDoubleScalarIsNaN(a) || muDoubleScalarIsNaN(step)) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &wj_emlrtRTEI);
      lastSection->data[0] = rtNaN;
    } else if ((step == 0.0) || ((a < simLimits[1]) && (step < 0.0)) ||
               ((simLimits[1] < a) && (step > 0.0))) {
      lastSection->size[0] = 1;
      lastSection->size[1] = 0;
    } else if ((muDoubleScalarIsInf(a) || muDoubleScalarIsInf(simLimits[1])) &&
               (muDoubleScalarIsInf(step) || (a == simLimits[1]))) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &wj_emlrtRTEI);
      lastSection->data[0] = rtNaN;
    } else if (muDoubleScalarIsInf(step)) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &wj_emlrtRTEI);
      lastSection->data[0] = a;
    } else if ((muDoubleScalarFloor(a) == a) && (muDoubleScalarFloor(step) ==
                step)) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      loop_ub = (int32_T)muDoubleScalarFloor((simLimits[1] - a) / step);
      lastSection->size[1] = loop_ub + 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &wj_emlrtRTEI);
      for (i = 0; i <= loop_ub; i++) {
        lastSection->data[i] = a + step * (real_T)i;
      }
    } else {
      b_st.site = &tf_emlrtRSI;
      ndbl = muDoubleScalarFloor((simLimits[1] - a) / step + 0.5);
      apnd = a + ndbl * step;
      if (step > 0.0) {
        cdiff = apnd - simLimits[1];
      } else {
        cdiff = simLimits[1] - apnd;
      }

      absa = muDoubleScalarAbs(a);
      absb = muDoubleScalarAbs(simLimits[1]);
      if (absa > absb) {
        absb = absa;
      }

      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * absb) {
        ndbl++;
        apnd = simLimits[1];
      } else if (cdiff > 0.0) {
        apnd = a + (ndbl - 1.0) * step;
      } else {
        ndbl++;
      }

      if (ndbl >= 0.0) {
        n = (int32_T)ndbl;
      } else {
        n = 0;
      }

      c_st.site = &uf_emlrtRSI;
      if (ndbl > 2.147483647E+9) {
        emlrtErrorWithMessageIdR2018a(&c_st, &pb_emlrtRTEI,
          "Coder:MATLAB:pmaxsize", "Coder:MATLAB:pmaxsize", 0);
      }

      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = n;
      emxEnsureCapacity_real_T(&b_st, lastSection, i, &ak_emlrtRTEI);
      if (n > 0) {
        lastSection->data[0] = a;
        if (n > 1) {
          lastSection->data[n - 1] = apnd;
          nm1d2 = (n - 1) / 2;
          for (loop_ub = 0; loop_ub <= nm1d2 - 2; loop_ub++) {
            kd = ((real_T)loop_ub + 1.0) * step;
            lastSection->data[loop_ub + 1] = a + kd;
            lastSection->data[(n - loop_ub) - 2] = apnd - kd;
          }

          if (nm1d2 << 1 == n - 1) {
            lastSection->data[nm1d2] = (a + apnd) / 2.0;
          } else {
            kd = (real_T)nm1d2 * step;
            lastSection->data[nm1d2] = a + kd;
            lastSection->data[nm1d2 + 1] = apnd - kd;
          }
        }
      }
    }
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 7U);
    lastSection->size[0] = 1;
    lastSection->size[1] = 0;
  }

  emxInit_real_T(sp, &simXdata, 1, &vj_emlrtRTEI, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 8U);
  nm1d2 = firstSection->size[1];
  loop_ub = this_data->size[0];
  i = simXdata->size[0];
  simXdata->size[0] = (firstSection->size[1] + this_data->size[0]) +
    lastSection->size[1];
  emxEnsureCapacity_real_T(sp, simXdata, i, &vj_emlrtRTEI);
  n = firstSection->size[1];
  for (i = 0; i < n; i++) {
    simXdata->data[i] = firstSection->data[i];
  }

  for (i = 0; i < loop_ub; i++) {
    simXdata->data[i + nm1d2] = this_data->data[i];
  }

  n = lastSection->size[1];
  for (i = 0; i < n; i++) {
    simXdata->data[(i + nm1d2) + loop_ub] = lastSection->data[i];
  }

  emxFree_real_T(&lastSection);
  splits_idx_1 = (uint32_T)firstSection->size[1] + this_data->size[0];
  i = Simulation->size[0] * Simulation->size[1];
  Simulation->size[0] = simXdata->size[0];
  Simulation->size[1] = 2;
  emxEnsureCapacity_real_T(sp, Simulation, i, &xj_emlrtRTEI);
  loop_ub = simXdata->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    Simulation->data[i] = 0.0;
  }

  emlrtSubAssignSizeCheckR2012b(&simXdata->size[0], 1, &simXdata->size[0], 1,
    &q_emlrtECI, sp);
  loop_ub = simXdata->size[0];
  for (i = 0; i < loop_ub; i++) {
    Simulation->data[i] = simXdata->data[i];
  }

  emxInit_real_T(sp, &simRef, 1, &ck_emlrtRTEI, true);
  emxInit_real_T(sp, &b_simRef, 1, &vk_emlrtRTEI, true);
  covrtLogSwitch(&emlrtCoverageInstance, 18U, 0U, 0, 1);
  covrtLogSwitch(&emlrtCoverageInstance, 18U, 0U, 1, 1);
  covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 9U);

  /*  Parallelise over points */
  st.site = &lg_emlrtRSI;
  abeles_paraPoints(&st, simXdata, slds, nbairs, nbsubs, repeatLayers[1], ssubs,
                    lays, simXdata->size[0], simRef);

  /* (x,sld,nbair,nbsub,nrepeats,ssub,layers,points) */
  i = b_simRef->size[0];
  b_simRef->size[0] = simRef->size[0];
  emxEnsureCapacity_real_T(sp, b_simRef, i, &vk_emlrtRTEI);
  loop_ub = simRef->size[0] - 1;
  emxFree_real_T(&slds);
  for (i = 0; i <= loop_ub; i++) {
    b_simRef->data[i] = simRef->data[i];
  }

  st.site = &mg_emlrtRSI;
  resolution_polly_paraPoints(&st, simXdata, b_simRef, res, simXdata->size[0],
    simRef);
  covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 11U);
  emlrtSubAssignSizeCheckR2012b(&Simulation->size[0], 1, &simRef->size[0], 1,
    &r_emlrtECI, sp);
  loop_ub = simRef->size[0];
  emxFree_real_T(&b_simRef);
  emxFree_real_T(&simXdata);
  for (i = 0; i < loop_ub; i++) {
    Simulation->data[i + Simulation->size[0]] = simRef->data[i];
  }

  emxFree_real_T(&simRef);
  if (firstSection->size[1] + 1U > splits_idx_1) {
    i = 0;
    nm1d2 = 0;
  } else {
    i = (int32_T)(firstSection->size[1] + 1U);
    if ((i < 1) || (i > Simulation->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, Simulation->size[0], &af_emlrtBCI, sp);
    }

    i--;
    if (((int32_T)splits_idx_1 < 1) || ((int32_T)splits_idx_1 > Simulation->
         size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)splits_idx_1, 1, Simulation->size[0],
        &bf_emlrtBCI, sp);
    }

    nm1d2 = (int32_T)splits_idx_1;
  }

  emxFree_real_T(&firstSection);
  loop_ub = nm1d2 - i;
  nm1d2 = reflectivity->size[0] * reflectivity->size[1];
  reflectivity->size[0] = loop_ub;
  reflectivity->size[1] = 2;
  emxEnsureCapacity_real_T(sp, reflectivity, nm1d2, &bk_emlrtRTEI);
  for (nm1d2 = 0; nm1d2 < loop_ub; nm1d2++) {
    reflectivity->data[nm1d2] = Simulation->data[i + nm1d2];
  }

  for (nm1d2 = 0; nm1d2 < loop_ub; nm1d2++) {
    reflectivity->data[nm1d2 + reflectivity->size[0]] = Simulation->data[(i +
      nm1d2) + Simulation->size[0]];
  }

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
  int32_T nm1d2;
  emxArray_real_T *firstSection;
  real_T step;
  emxArray_real_T *lastSection;
  real_T kd;
  emxArray_real_T *simXdata;
  real_T ndbl;
  real_T apnd;
  real_T a;
  int32_T n;
  real_T cdiff;
  real_T absa;
  real_T absb;
  uint32_T splits_idx_1;
  emxArray_real_T *simRef;
  emxArray_real_T *b_simRef;
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
  covrtLogFcn(&emlrtCoverageInstance, 18U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 0U);

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
  emxInit_real_T(sp, &slds, 2, &sj_emlrtRTEI, true);
  if (covrtLogIf(&emlrtCoverageInstance, 18U, 0U, 0, layers->size[0] == 0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 1U);
    i = slds->size[0] * slds->size[1];
    slds->size[0] = 1;
    slds->size[1] = 3;
    emxEnsureCapacity_real_T(sp, slds, i, &sj_emlrtRTEI);
    slds->data[0] = 0.0;
    slds->data[1] = nbairs;
    slds->data[2] = 0.0;
    lays = 0;
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 2U);
    loop_ub = layers->size[0];
    i = slds->size[0] * slds->size[1];
    slds->size[0] = layers->size[0];
    slds->size[1] = 3;
    emxEnsureCapacity_real_T(sp, slds, i, &tj_emlrtRTEI);
    for (i = 0; i < 3; i++) {
      for (nm1d2 = 0; nm1d2 < loop_ub; nm1d2++) {
        slds->data[nm1d2 + slds->size[0] * i] = layers->data[nm1d2 +
          layers->size[0] * i];
      }
    }

    lays = layers->size[0];
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 3U);
  if (1 > this_data->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &ve_emlrtBCI, sp);
  }

  emxInit_real_T(sp, &firstSection, 2, &uj_emlrtRTEI, true);
  if (covrtLogIf(&emlrtCoverageInstance, 18U, 0U, 1, simLimits[0] <
                 this_data->data[0])) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 4U);
    if (2 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, this_data->size[0], &we_emlrtBCI, sp);
    }

    if (1 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &xe_emlrtBCI, sp);
    }

    step = this_data->data[1] - this_data->data[0];
    if (1 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &ye_emlrtBCI, sp);
    }

    st.site = &pf_emlrtRSI;
    kd = this_data->data[0] - step;
    if (muDoubleScalarIsNaN(step) || muDoubleScalarIsNaN(kd)) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &uj_emlrtRTEI);
      firstSection->data[0] = rtNaN;
    } else if ((step == 0.0) || ((simLimits[0] < kd) && (step < 0.0)) || ((kd <
                 simLimits[0]) && (step > 0.0))) {
      firstSection->size[0] = 1;
      firstSection->size[1] = 0;
    } else if ((muDoubleScalarIsInf(simLimits[0]) || muDoubleScalarIsInf(kd)) &&
               (muDoubleScalarIsInf(step) || (simLimits[0] == kd))) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &uj_emlrtRTEI);
      firstSection->data[0] = rtNaN;
    } else if (muDoubleScalarIsInf(step)) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &uj_emlrtRTEI);
      firstSection->data[0] = simLimits[0];
    } else if ((muDoubleScalarFloor(simLimits[0]) == simLimits[0]) &&
               (muDoubleScalarFloor(step) == step)) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      loop_ub = (int32_T)muDoubleScalarFloor((kd - simLimits[0]) / step);
      firstSection->size[1] = loop_ub + 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &uj_emlrtRTEI);
      for (i = 0; i <= loop_ub; i++) {
        firstSection->data[i] = simLimits[0] + step * (real_T)i;
      }
    } else {
      b_st.site = &tf_emlrtRSI;
      ndbl = muDoubleScalarFloor((kd - simLimits[0]) / step + 0.5);
      apnd = simLimits[0] + ndbl * step;
      if (step > 0.0) {
        cdiff = apnd - kd;
      } else {
        cdiff = kd - apnd;
      }

      absa = muDoubleScalarAbs(simLimits[0]);
      absb = muDoubleScalarAbs(kd);
      if (absa > absb) {
        absb = absa;
      }

      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * absb) {
        ndbl++;
        apnd = kd;
      } else if (cdiff > 0.0) {
        apnd = simLimits[0] + (ndbl - 1.0) * step;
      } else {
        ndbl++;
      }

      if (ndbl >= 0.0) {
        n = (int32_T)ndbl;
      } else {
        n = 0;
      }

      c_st.site = &uf_emlrtRSI;
      if (ndbl > 2.147483647E+9) {
        emlrtErrorWithMessageIdR2018a(&c_st, &pb_emlrtRTEI,
          "Coder:MATLAB:pmaxsize", "Coder:MATLAB:pmaxsize", 0);
      }

      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = n;
      emxEnsureCapacity_real_T(&b_st, firstSection, i, &ak_emlrtRTEI);
      if (n > 0) {
        firstSection->data[0] = simLimits[0];
        if (n > 1) {
          firstSection->data[n - 1] = apnd;
          nm1d2 = (n - 1) / 2;
          for (loop_ub = 0; loop_ub <= nm1d2 - 2; loop_ub++) {
            kd = ((real_T)loop_ub + 1.0) * step;
            firstSection->data[loop_ub + 1] = simLimits[0] + kd;
            firstSection->data[(n - loop_ub) - 2] = apnd - kd;
          }

          if (nm1d2 << 1 == n - 1) {
            firstSection->data[nm1d2] = (simLimits[0] + apnd) / 2.0;
          } else {
            kd = (real_T)nm1d2 * step;
            firstSection->data[nm1d2] = simLimits[0] + kd;
            firstSection->data[nm1d2 + 1] = apnd - kd;
          }
        }
      }
    }
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 5U);
    firstSection->size[0] = 1;
    firstSection->size[1] = 0;
  }

  if (this_data->size[0] < 1) {
    emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
      &ue_emlrtBCI, sp);
  }

  emxInit_real_T(sp, &lastSection, 2, &wj_emlrtRTEI, true);
  if (covrtLogIf(&emlrtCoverageInstance, 18U, 0U, 2, simLimits[1] >
                 this_data->data[this_data->size[0] - 1])) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 6U);
    i = this_data->size[0] - 1;
    if ((i < 1) || (i > this_data->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, this_data->size[0], &se_emlrtBCI, sp);
    }

    if (this_data->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
        &te_emlrtBCI, sp);
    }

    step = this_data->data[this_data->size[0] - 1] - this_data->data[i - 1];
    st.site = &qf_emlrtRSI;
    if (this_data->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
        &re_emlrtBCI, &st);
    }

    a = this_data->data[this_data->size[0] - 1] + step;
    if (muDoubleScalarIsNaN(a) || muDoubleScalarIsNaN(step)) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &wj_emlrtRTEI);
      lastSection->data[0] = rtNaN;
    } else if ((step == 0.0) || ((a < simLimits[1]) && (step < 0.0)) ||
               ((simLimits[1] < a) && (step > 0.0))) {
      lastSection->size[0] = 1;
      lastSection->size[1] = 0;
    } else if ((muDoubleScalarIsInf(a) || muDoubleScalarIsInf(simLimits[1])) &&
               (muDoubleScalarIsInf(step) || (a == simLimits[1]))) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &wj_emlrtRTEI);
      lastSection->data[0] = rtNaN;
    } else if (muDoubleScalarIsInf(step)) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &wj_emlrtRTEI);
      lastSection->data[0] = a;
    } else if ((muDoubleScalarFloor(a) == a) && (muDoubleScalarFloor(step) ==
                step)) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      loop_ub = (int32_T)muDoubleScalarFloor((simLimits[1] - a) / step);
      lastSection->size[1] = loop_ub + 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &wj_emlrtRTEI);
      for (i = 0; i <= loop_ub; i++) {
        lastSection->data[i] = a + step * (real_T)i;
      }
    } else {
      b_st.site = &tf_emlrtRSI;
      ndbl = muDoubleScalarFloor((simLimits[1] - a) / step + 0.5);
      apnd = a + ndbl * step;
      if (step > 0.0) {
        cdiff = apnd - simLimits[1];
      } else {
        cdiff = simLimits[1] - apnd;
      }

      absa = muDoubleScalarAbs(a);
      absb = muDoubleScalarAbs(simLimits[1]);
      if (absa > absb) {
        absb = absa;
      }

      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * absb) {
        ndbl++;
        apnd = simLimits[1];
      } else if (cdiff > 0.0) {
        apnd = a + (ndbl - 1.0) * step;
      } else {
        ndbl++;
      }

      if (ndbl >= 0.0) {
        n = (int32_T)ndbl;
      } else {
        n = 0;
      }

      c_st.site = &uf_emlrtRSI;
      if (ndbl > 2.147483647E+9) {
        emlrtErrorWithMessageIdR2018a(&c_st, &pb_emlrtRTEI,
          "Coder:MATLAB:pmaxsize", "Coder:MATLAB:pmaxsize", 0);
      }

      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = n;
      emxEnsureCapacity_real_T(&b_st, lastSection, i, &ak_emlrtRTEI);
      if (n > 0) {
        lastSection->data[0] = a;
        if (n > 1) {
          lastSection->data[n - 1] = apnd;
          nm1d2 = (n - 1) / 2;
          for (loop_ub = 0; loop_ub <= nm1d2 - 2; loop_ub++) {
            kd = ((real_T)loop_ub + 1.0) * step;
            lastSection->data[loop_ub + 1] = a + kd;
            lastSection->data[(n - loop_ub) - 2] = apnd - kd;
          }

          if (nm1d2 << 1 == n - 1) {
            lastSection->data[nm1d2] = (a + apnd) / 2.0;
          } else {
            kd = (real_T)nm1d2 * step;
            lastSection->data[nm1d2] = a + kd;
            lastSection->data[nm1d2 + 1] = apnd - kd;
          }
        }
      }
    }
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 7U);
    lastSection->size[0] = 1;
    lastSection->size[1] = 0;
  }

  emxInit_real_T(sp, &simXdata, 1, &vj_emlrtRTEI, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 8U);
  nm1d2 = firstSection->size[1];
  loop_ub = this_data->size[0];
  i = simXdata->size[0];
  simXdata->size[0] = (firstSection->size[1] + this_data->size[0]) +
    lastSection->size[1];
  emxEnsureCapacity_real_T(sp, simXdata, i, &vj_emlrtRTEI);
  n = firstSection->size[1];
  for (i = 0; i < n; i++) {
    simXdata->data[i] = firstSection->data[i];
  }

  for (i = 0; i < loop_ub; i++) {
    simXdata->data[i + nm1d2] = this_data->data[i];
  }

  n = lastSection->size[1];
  for (i = 0; i < n; i++) {
    simXdata->data[(i + nm1d2) + loop_ub] = lastSection->data[i];
  }

  emxFree_real_T(&lastSection);
  splits_idx_1 = (uint32_T)firstSection->size[1] + this_data->size[0];
  i = Simulation->size[0] * Simulation->size[1];
  Simulation->size[0] = simXdata->size[0];
  Simulation->size[1] = 2;
  emxEnsureCapacity_real_T(sp, Simulation, i, &xj_emlrtRTEI);
  loop_ub = simXdata->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    Simulation->data[i] = 0.0;
  }

  emlrtSubAssignSizeCheckR2012b(&simXdata->size[0], 1, &simXdata->size[0], 1,
    &q_emlrtECI, sp);
  loop_ub = simXdata->size[0];
  for (i = 0; i < loop_ub; i++) {
    Simulation->data[i] = simXdata->data[i];
  }

  emxInit_real_T(sp, &simRef, 1, &ck_emlrtRTEI, true);
  emxInit_real_T(sp, &b_simRef, 1, &yj_emlrtRTEI, true);
  covrtLogSwitch(&emlrtCoverageInstance, 18U, 0U, 0, 1);
  covrtLogSwitch(&emlrtCoverageInstance, 18U, 0U, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 10U);

  /*  Single cored over points */
  st.site = &rf_emlrtRSI;
  abeles_single(&st, simXdata, slds, nbairs, nbsubs, repeatLayers[1], ssubs,
                lays, simXdata->size[0], simRef);
  i = b_simRef->size[0];
  b_simRef->size[0] = simRef->size[0];
  emxEnsureCapacity_real_T(sp, b_simRef, i, &yj_emlrtRTEI);
  loop_ub = simRef->size[0] - 1;
  emxFree_real_T(&slds);
  for (i = 0; i <= loop_ub; i++) {
    b_simRef->data[i] = simRef->data[i];
  }

  st.site = &sf_emlrtRSI;
  resolution_polly(&st, simXdata, b_simRef, res, simXdata->size[0], simRef);
  covrtLogBasicBlock(&emlrtCoverageInstance, 18U, 11U);
  emlrtSubAssignSizeCheckR2012b(&Simulation->size[0], 1, &simRef->size[0], 1,
    &r_emlrtECI, sp);
  loop_ub = simRef->size[0];
  emxFree_real_T(&b_simRef);
  emxFree_real_T(&simXdata);
  for (i = 0; i < loop_ub; i++) {
    Simulation->data[i + Simulation->size[0]] = simRef->data[i];
  }

  emxFree_real_T(&simRef);
  if (firstSection->size[1] + 1U > splits_idx_1) {
    i = 0;
    nm1d2 = 0;
  } else {
    i = (int32_T)(firstSection->size[1] + 1U);
    if ((i < 1) || (i > Simulation->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, Simulation->size[0], &af_emlrtBCI, sp);
    }

    i--;
    if (((int32_T)splits_idx_1 < 1) || ((int32_T)splits_idx_1 > Simulation->
         size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)splits_idx_1, 1, Simulation->size[0],
        &bf_emlrtBCI, sp);
    }

    nm1d2 = (int32_T)splits_idx_1;
  }

  emxFree_real_T(&firstSection);
  loop_ub = nm1d2 - i;
  nm1d2 = reflectivity->size[0] * reflectivity->size[1];
  reflectivity->size[0] = loop_ub;
  reflectivity->size[1] = 2;
  emxEnsureCapacity_real_T(sp, reflectivity, nm1d2, &bk_emlrtRTEI);
  for (nm1d2 = 0; nm1d2 < loop_ub; nm1d2++) {
    reflectivity->data[nm1d2] = Simulation->data[i + nm1d2];
  }

  for (nm1d2 = 0; nm1d2 < loop_ub; nm1d2++) {
    reflectivity->data[nm1d2 + reflectivity->size[0]] = Simulation->data[(i +
      nm1d2) + Simulation->size[0]];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (callReflectivity.c) */
