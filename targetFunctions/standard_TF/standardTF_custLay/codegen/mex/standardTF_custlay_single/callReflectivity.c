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
#include "rt_nonfinite.h"
#include "standardTF_custlay_single.h"
#include "callReflectivity.h"
#include "mpower.h"
#include "standardTF_custlay_single_emxutil.h"
#include "indexShapeCheck.h"
#include "abeles.h"
#include "standardTF_custlay_single_data.h"

/* Variable Definitions */
static emlrtRSInfo yc_emlrtRSI = { 36, /* lineNo */
  "callReflectivity",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pathName */
};

static emlrtRSInfo ad_emlrtRSI = { 43, /* lineNo */
  "callReflectivity",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pathName */
};

static emlrtRSInfo bd_emlrtRSI = { 53, /* lineNo */
  "callReflectivity",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pathName */
};

static emlrtRSInfo cd_emlrtRSI = { 54, /* lineNo */
  "callReflectivity",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pathName */
};

static emlrtRSInfo dd_emlrtRSI = { 59, /* lineNo */
  "callReflectivity",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pathName */
};

static emlrtRSInfo ed_emlrtRSI = { 61, /* lineNo */
  "callReflectivity",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pathName */
};

static emlrtRSInfo fd_emlrtRSI = { 63, /* lineNo */
  "callReflectivity",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pathName */
};

static emlrtRSInfo kd_emlrtRSI = { 26, /* lineNo */
  "resolution_polly",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m"/* pathName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 1,/* lineNo */
  39,                                  /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 23,/* lineNo */
  5,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = { 43,/* lineNo */
  5,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = { 48,/* lineNo */
  1,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 53,/* lineNo */
  1,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 58,/* lineNo */
  1,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 5,/* lineNo */
  1,                                   /* colNo */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m"/* pName */
};

static emlrtBCInfo de_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  13,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ee_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  13,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  22,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ge_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  34,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo he_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  13,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ie_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  13,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo ec_emlrtRTEI = { 25,/* lineNo */
  13,                                  /* colNo */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m"/* pName */
};

static emlrtBCInfo je_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  48,                                  /* colNo */
  "xdata",                             /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ke_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  24,                                  /* colNo */
  "dummydata",                         /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo le_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  30,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo me_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  26,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ne_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  7,                                   /* colNo */
  "Ref",                               /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  5,                                   /* colNo */
  "dummydata",                         /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  9,                                   /* colNo */
  "dummydata",                         /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  22,                                  /* colNo */
  "xdata",                             /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo re_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  33,                                  /* colNo */
  "xdata",                             /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo se_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  28,                                  /* lineNo */
  24,                                  /* colNo */
  "dummydata",                         /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo te_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  28,                                  /* lineNo */
  39,                                  /* colNo */
  "dummyref",                          /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ue_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  28,                                  /* lineNo */
  9,                                   /* colNo */
  "dummydata",                         /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void callReflectivity(const emlrtStack *sp, real_T nbairs, real_T nbsubs, const
                      real_T simLimits[2], const real_T repeatLayers[2], const
                      real_T this_data_data[], const int32_T this_data_size[2],
                      const emxArray_real_T *layers, real_T ssubs, real_T
                      backgrounds, real_T res, real_T reflectivity_data[],
                      int32_T reflectivity_size[2], emxArray_real_T *Simulation)
{
  int32_T loop_ub;
  int32_T i12;
  emxArray_real_T *slds;
  real_T xdata_data[51];
  real_T dv0[3];
  int32_T lays;
  int32_T i13;
  real_T middleSection_data[51];
  emxArray_real_T *firstSection;
  emxArray_real_T *simXdata;
  real_T step;
  emxArray_real_T *lastSection;
  real_T kd;
  real_T ndbl;
  int32_T k;
  real_T apnd;
  int32_T lastSection_idx_0;
  real_T cdiff;
  int32_T nm1d2;
  real_T a;
  real_T absa;
  real_T absb;
  int32_T n;
  emxArray_real_T *simRef;
  emxArray_real_T *dummydata;
  int32_T varargin_2;
  int32_T tmp_size[2];
  emxArray_real_T *Ref;
  int32_T ilow;
  uint32_T tmp_data[51];
  boolean_T b4;
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
  covrtLogFcn(&emlrtCoverageInstance, 12U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 0U);

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
  loop_ub = this_data_size[0];
  for (i12 = 0; i12 < loop_ub; i12++) {
    xdata_data[i12] = this_data_data[i12];
  }

  emxInit_real_T(sp, &slds, 2, &fb_emlrtRTEI, true);
  if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 0, layers->size[0] == 0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 1U);
    dv0[0] = 0.0;
    dv0[1] = nbairs;
    dv0[2] = 0.0;
    i12 = slds->size[0] * slds->size[1];
    slds->size[0] = 1;
    slds->size[1] = 3;
    emxEnsureCapacity(sp, (emxArray__common *)slds, i12, (int32_T)sizeof(real_T),
                      &eb_emlrtRTEI);
    for (i12 = 0; i12 < 3; i12++) {
      slds->data[slds->size[0] * i12] = dv0[i12];
    }

    lays = 0;
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 2U);
    loop_ub = layers->size[0];
    i12 = slds->size[0] * slds->size[1];
    slds->size[0] = loop_ub;
    slds->size[1] = 3;
    emxEnsureCapacity(sp, (emxArray__common *)slds, i12, (int32_T)sizeof(real_T),
                      &eb_emlrtRTEI);
    for (i12 = 0; i12 < 3; i12++) {
      for (i13 = 0; i13 < loop_ub; i13++) {
        slds->data[i13 + slds->size[0] * i12] = layers->data[i13 + layers->size
          [0] * i12];
      }
    }

    lays = layers->size[0];
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 3U);
  loop_ub = this_data_size[0];
  for (i12 = 0; i12 < loop_ub; i12++) {
    middleSection_data[i12] = this_data_data[i12];
  }

  if (!(1 <= this_data_size[0])) {
    emlrtDynamicBoundsCheckR2012b(1, 1, this_data_size[0], &de_emlrtBCI, sp);
  }

  emxInit_real_T(sp, &firstSection, 2, &gb_emlrtRTEI, true);
  emxInit_real_T(sp, &simXdata, 2, &ib_emlrtRTEI, true);
  if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 1, simLimits[0] <
                 this_data_data[0])) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 4U);
    if (!(2 <= this_data_size[0])) {
      emlrtDynamicBoundsCheckR2012b(2, 1, this_data_size[0], &ee_emlrtBCI, sp);
    }

    if (!(1 <= this_data_size[0])) {
      emlrtDynamicBoundsCheckR2012b(1, 1, this_data_size[0], &fe_emlrtBCI, sp);
    }

    step = this_data_data[1] - this_data_data[0];
    if (!(1 <= this_data_size[0])) {
      emlrtDynamicBoundsCheckR2012b(1, 1, this_data_size[0], &ge_emlrtBCI, sp);
    }

    st.site = &yc_emlrtRSI;
    kd = this_data_data[0] - step;
    if (muDoubleScalarIsNaN(step) || muDoubleScalarIsNaN(kd)) {
      i12 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity(&st, (emxArray__common *)simXdata, i12, (int32_T)sizeof
                        (real_T), &eb_emlrtRTEI);
      simXdata->data[0] = rtNaN;
    } else if ((step == 0.0) || ((simLimits[0] < kd) && (step < 0.0)) || ((kd <
                 simLimits[0]) && (step > 0.0))) {
      i12 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 0;
      emxEnsureCapacity(&st, (emxArray__common *)simXdata, i12, (int32_T)sizeof
                        (real_T), &eb_emlrtRTEI);
    } else if ((muDoubleScalarIsInf(simLimits[0]) || muDoubleScalarIsInf(kd)) &&
               (muDoubleScalarIsInf(step) || (simLimits[0] == kd))) {
      i12 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity(&st, (emxArray__common *)simXdata, i12, (int32_T)sizeof
                        (real_T), &eb_emlrtRTEI);
      simXdata->data[0] = rtNaN;
    } else if (muDoubleScalarIsInf(step)) {
      i12 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity(&st, (emxArray__common *)simXdata, i12, (int32_T)sizeof
                        (real_T), &eb_emlrtRTEI);
      simXdata->data[0] = simLimits[0];
    } else if ((muDoubleScalarFloor(simLimits[0]) == simLimits[0]) &&
               (muDoubleScalarFloor(step) == step)) {
      i12 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = (int32_T)muDoubleScalarFloor((kd - simLimits[0]) /
        step) + 1;
      emxEnsureCapacity(&st, (emxArray__common *)simXdata, i12, (int32_T)sizeof
                        (real_T), &eb_emlrtRTEI);
      nm1d2 = (int32_T)muDoubleScalarFloor((kd - simLimits[0]) / step);
      for (i12 = 0; i12 <= nm1d2; i12++) {
        simXdata->data[simXdata->size[0] * i12] = simLimits[0] + step * (real_T)
          i12;
      }
    } else {
      b_st.site = &fc_emlrtRSI;
      ndbl = muDoubleScalarFloor((kd - simLimits[0]) / step + 0.5);
      apnd = simLimits[0] + ndbl * step;
      if (step > 0.0) {
        cdiff = apnd - kd;
      } else {
        cdiff = kd - apnd;
      }

      absa = muDoubleScalarAbs(simLimits[0]);
      absb = muDoubleScalarAbs(kd);
      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * muDoubleScalarMax
          (absa, absb)) {
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

      c_st.site = &gc_emlrtRSI;
      if (2.147483647E+9 < ndbl) {
        emlrtErrorWithMessageIdR2012b(&c_st, &ac_emlrtRTEI,
          "Coder:MATLAB:pmaxsize", 0);
      }

      i12 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = n;
      emxEnsureCapacity(&b_st, (emxArray__common *)simXdata, i12, (int32_T)
                        sizeof(real_T), &eb_emlrtRTEI);
      if (n > 0) {
        simXdata->data[0] = simLimits[0];
        if (n > 1) {
          simXdata->data[n - 1] = apnd;
          nm1d2 = (n - 1) / 2;
          c_st.site = &hc_emlrtRSI;
          for (k = 1; k < nm1d2; k++) {
            kd = (real_T)k * step;
            simXdata->data[k] = simLimits[0] + kd;
            simXdata->data[(n - k) - 1] = apnd - kd;
          }

          if (nm1d2 << 1 == n - 1) {
            simXdata->data[nm1d2] = (simLimits[0] + apnd) / 2.0;
          } else {
            kd = (real_T)nm1d2 * step;
            simXdata->data[nm1d2] = simLimits[0] + kd;
            simXdata->data[nm1d2 + 1] = apnd - kd;
          }
        }
      }
    }

    i12 = firstSection->size[0] * firstSection->size[1];
    firstSection->size[0] = 1;
    firstSection->size[1] = simXdata->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)firstSection, i12, (int32_T)sizeof
                      (real_T), &eb_emlrtRTEI);
    nm1d2 = simXdata->size[0] * simXdata->size[1];
    for (i12 = 0; i12 < nm1d2; i12++) {
      firstSection->data[i12] = simXdata->data[i12];
    }
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 5U);
    i12 = firstSection->size[0] * firstSection->size[1];
    firstSection->size[0] = 0;
    firstSection->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)firstSection, i12, (int32_T)sizeof
                      (real_T), &eb_emlrtRTEI);
  }

  if (!(this_data_size[0] >= 1)) {
    emlrtDynamicBoundsCheckR2012b(this_data_size[0], 1, this_data_size[0],
      &he_emlrtBCI, sp);
  }

  emxInit_real_T(sp, &lastSection, 2, &hb_emlrtRTEI, true);
  if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 2, simLimits[1] >
                 this_data_data[this_data_size[0] - 1])) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 6U);
    if (!(this_data_size[0] >= 1)) {
      emlrtDynamicBoundsCheckR2012b(this_data_size[0], 1, this_data_size[0],
        &ie_emlrtBCI, sp);
    }

    i12 = this_data_size[0] - 1;
    if (!((i12 >= 1) && (i12 <= this_data_size[0]))) {
      emlrtDynamicBoundsCheckR2012b(i12, 1, this_data_size[0], &le_emlrtBCI, sp);
    }

    step = this_data_data[this_data_size[0] - 1] - xdata_data[i12 - 1];
    st.site = &ad_emlrtRSI;
    if (!(this_data_size[0] >= 1)) {
      emlrtDynamicBoundsCheckR2012b(this_data_size[0], 1, this_data_size[0],
        &me_emlrtBCI, &st);
    }

    a = xdata_data[this_data_size[0] - 1] + step;
    if (muDoubleScalarIsNaN(a) || muDoubleScalarIsNaN(step)) {
      i12 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity(&st, (emxArray__common *)simXdata, i12, (int32_T)sizeof
                        (real_T), &eb_emlrtRTEI);
      simXdata->data[0] = rtNaN;
    } else if ((step == 0.0) || ((a < simLimits[1]) && (step < 0.0)) ||
               ((simLimits[1] < a) && (step > 0.0))) {
      i12 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 0;
      emxEnsureCapacity(&st, (emxArray__common *)simXdata, i12, (int32_T)sizeof
                        (real_T), &eb_emlrtRTEI);
    } else if ((muDoubleScalarIsInf(a) || muDoubleScalarIsInf(simLimits[1])) &&
               (muDoubleScalarIsInf(step) || (a == simLimits[1]))) {
      i12 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity(&st, (emxArray__common *)simXdata, i12, (int32_T)sizeof
                        (real_T), &eb_emlrtRTEI);
      simXdata->data[0] = rtNaN;
    } else if (muDoubleScalarIsInf(step)) {
      i12 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity(&st, (emxArray__common *)simXdata, i12, (int32_T)sizeof
                        (real_T), &eb_emlrtRTEI);
      simXdata->data[0] = a;
    } else if ((muDoubleScalarFloor(a) == a) && (muDoubleScalarFloor(step) ==
                step)) {
      i12 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = (int32_T)muDoubleScalarFloor((simLimits[1] - a) / step)
        + 1;
      emxEnsureCapacity(&st, (emxArray__common *)simXdata, i12, (int32_T)sizeof
                        (real_T), &eb_emlrtRTEI);
      nm1d2 = (int32_T)muDoubleScalarFloor((simLimits[1] - a) / step);
      for (i12 = 0; i12 <= nm1d2; i12++) {
        simXdata->data[simXdata->size[0] * i12] = a + step * (real_T)i12;
      }
    } else {
      b_st.site = &fc_emlrtRSI;
      ndbl = muDoubleScalarFloor((simLimits[1] - a) / step + 0.5);
      apnd = a + ndbl * step;
      if (step > 0.0) {
        cdiff = apnd - simLimits[1];
      } else {
        cdiff = simLimits[1] - apnd;
      }

      absa = muDoubleScalarAbs(a);
      absb = muDoubleScalarAbs(simLimits[1]);
      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * muDoubleScalarMax
          (absa, absb)) {
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

      c_st.site = &gc_emlrtRSI;
      if (2.147483647E+9 < ndbl) {
        emlrtErrorWithMessageIdR2012b(&c_st, &ac_emlrtRTEI,
          "Coder:MATLAB:pmaxsize", 0);
      }

      i12 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = n;
      emxEnsureCapacity(&b_st, (emxArray__common *)simXdata, i12, (int32_T)
                        sizeof(real_T), &eb_emlrtRTEI);
      if (n > 0) {
        simXdata->data[0] = a;
        if (n > 1) {
          simXdata->data[n - 1] = apnd;
          nm1d2 = (n - 1) / 2;
          c_st.site = &hc_emlrtRSI;
          for (k = 1; k < nm1d2; k++) {
            kd = (real_T)k * step;
            simXdata->data[k] = a + kd;
            simXdata->data[(n - k) - 1] = apnd - kd;
          }

          if (nm1d2 << 1 == n - 1) {
            simXdata->data[nm1d2] = (a + apnd) / 2.0;
          } else {
            kd = (real_T)nm1d2 * step;
            simXdata->data[nm1d2] = a + kd;
            simXdata->data[nm1d2 + 1] = apnd - kd;
          }
        }
      }
    }

    i12 = lastSection->size[0] * lastSection->size[1];
    lastSection->size[0] = 1;
    lastSection->size[1] = simXdata->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)lastSection, i12, (int32_T)sizeof
                      (real_T), &eb_emlrtRTEI);
    nm1d2 = simXdata->size[0] * simXdata->size[1];
    for (i12 = 0; i12 < nm1d2; i12++) {
      lastSection->data[i12] = simXdata->data[i12];
    }
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 7U);
    i12 = lastSection->size[0] * lastSection->size[1];
    lastSection->size[0] = 0;
    lastSection->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)lastSection, i12, (int32_T)sizeof
                      (real_T), &eb_emlrtRTEI);
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 8U);
  k = firstSection->size[0] * firstSection->size[1];
  lastSection_idx_0 = lastSection->size[0] * lastSection->size[1];
  i12 = simXdata->size[0] * simXdata->size[1];
  simXdata->size[0] = 1;
  simXdata->size[1] = (k + this_data_size[0]) + lastSection_idx_0;
  emxEnsureCapacity(sp, (emxArray__common *)simXdata, i12, (int32_T)sizeof
                    (real_T), &eb_emlrtRTEI);
  for (i12 = 0; i12 < k; i12++) {
    simXdata->data[simXdata->size[0] * i12] = firstSection->data[i12];
  }

  nm1d2 = this_data_size[0];
  for (i12 = 0; i12 < nm1d2; i12++) {
    simXdata->data[simXdata->size[0] * (i12 + k)] = middleSection_data[i12];
  }

  for (i12 = 0; i12 < lastSection_idx_0; i12++) {
    simXdata->data[simXdata->size[0] * ((i12 + k) + loop_ub)] =
      lastSection->data[i12];
  }

  if ((firstSection->size[0] == 0) || (firstSection->size[1] == 0)) {
    n = 0;
  } else {
    n = firstSection->size[1];
  }

  emxFree_real_T(&firstSection);
  emxFree_real_T(&lastSection);
  emxInit_real_T1(sp, &simRef, 1, &jb_emlrtRTEI, true);
  emxInit_real_T1(sp, &dummydata, 1, &lb_emlrtRTEI, true);
  st.site = &bd_emlrtRSI;
  abeles(&st, simXdata, slds, nbairs, nbsubs, repeatLayers[1], ssubs, lays,
         simXdata->size[1], simRef);
  varargin_2 = simXdata->size[1] - 1;
  st.site = &cd_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 14U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 14U, 0U);
  i12 = dummydata->size[0];
  dummydata->size[0] = simXdata->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)dummydata, i12, (int32_T)sizeof
                    (real_T), &eb_emlrtRTEI);
  loop_ub = simXdata->size[1];
  emxFree_real_T(&slds);
  for (i12 = 0; i12 < loop_ub; i12++) {
    dummydata->data[i12] = 0.0;
  }

  loop_ub = 0;
  while (loop_ub <= simXdata->size[1] - 1) {
    covrtLogFor(&emlrtCoverageInstance, 14U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 14U, 1U);
    ndbl = 0.0;
    i12 = dummydata->size[0];
    i13 = 1 + loop_ub;
    if (!((i13 >= 1) && (i13 <= i12))) {
      emlrtDynamicBoundsCheckR2012b(i13, 1, i12, &oe_emlrtBCI, &st);
    }

    dummydata->data[i13 - 1] = 0.0;
    if (covrtLogIf(&emlrtCoverageInstance, 14U, 0U, 0, 1 + loop_ub > 10)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 14U, 2U);
      ilow = -10;
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 14U, 3U);
      ilow = -loop_ub;
    }

    if (covrtLogIf(&emlrtCoverageInstance, 14U, 0U, 1, 1 + loop_ub < varargin_2
                   - 9)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 14U, 4U);
      nm1d2 = 10;
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 14U, 5U);
      nm1d2 = varargin_2 - loop_ub;
    }

    /*     try */
    i12 = (int32_T)((real_T)nm1d2 + (1.0 - (real_T)ilow));
    emlrtForLoopVectorCheckR2012b(ilow, 1.0, nm1d2, mxDOUBLE_CLASS, i12,
      &ec_emlrtRTEI, &st);
    nm1d2 = 0;
    while (nm1d2 <= i12 - 1) {
      cdiff = (real_T)ilow + (real_T)nm1d2;
      covrtLogFor(&emlrtCoverageInstance, 14U, 0U, 1, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 14U, 6U);
      i13 = simXdata->size[1];
      k = (int32_T)((1.0 + (real_T)loop_ub) + cdiff);
      if (!((k >= 1) && (k <= i13))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i13, &qe_emlrtBCI, &st);
      }

      i13 = simXdata->size[1];
      lastSection_idx_0 = 1 + loop_ub;
      if (!((lastSection_idx_0 >= 1) && (lastSection_idx_0 <= i13))) {
        emlrtDynamicBoundsCheckR2012b(lastSection_idx_0, 1, i13, &re_emlrtBCI,
          &st);
      }

      kd = simXdata->data[k - 1] - simXdata->data[lastSection_idx_0 - 1];
      i13 = simXdata->size[1];
      k = loop_ub + 1;
      if (!((k >= 1) && (k <= i13))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i13, &je_emlrtBCI, &st);
      }

      b_st.site = &kd_emlrtRSI;
      kd = -b_mpower(kd / ((res + 0.0001) * simXdata->data[loop_ub]));
      kd = muDoubleScalarExp(kd);
      ndbl += kd;
      i13 = dummydata->size[0];
      k = 1 + loop_ub;
      if (!((k >= 1) && (k <= i13))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i13, &se_emlrtBCI, &st);
      }

      i13 = simRef->size[0];
      lastSection_idx_0 = (int32_T)(cdiff + (1.0 + (real_T)loop_ub));
      if (!((lastSection_idx_0 >= 1) && (lastSection_idx_0 <= i13))) {
        emlrtDynamicBoundsCheckR2012b(lastSection_idx_0, 1, i13, &te_emlrtBCI,
          &st);
      }

      i13 = dummydata->size[0];
      lays = 1 + loop_ub;
      if (!((lays >= 1) && (lays <= i13))) {
        emlrtDynamicBoundsCheckR2012b(lays, 1, i13, &ue_emlrtBCI, &st);
      }

      dummydata->data[lays - 1] = dummydata->data[k - 1] + simRef->
        data[lastSection_idx_0 - 1] * kd;
      nm1d2++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 14U, 0U, 1, 0);
    if (covrtLogIf(&emlrtCoverageInstance, 14U, 0U, 2, ndbl != 0.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 14U, 7U);
      i12 = dummydata->size[0];
      i13 = loop_ub + 1;
      if (!((i13 >= 1) && (i13 <= i12))) {
        emlrtDynamicBoundsCheckR2012b(i13, 1, i12, &ke_emlrtBCI, &st);
      }

      i12 = dummydata->size[0];
      i13 = 1 + loop_ub;
      if (!((i13 >= 1) && (i13 <= i12))) {
        emlrtDynamicBoundsCheckR2012b(i13, 1, i12, &pe_emlrtBCI, &st);
      }

      dummydata->data[i13 - 1] = dummydata->data[loop_ub] / ndbl;
    }

    /*      catch */
    /*          disp('debug!'); */
    /*      end */
    loop_ub++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 14U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 14U, 8U);
  nm1d2 = dummydata->size[0];
  tmp_size[0] = 1;
  tmp_size[1] = this_data_size[0];
  loop_ub = (int32_T)(this_data_size[0] + MAX_uint32_T);
  for (i12 = 0; i12 <= loop_ub; i12++) {
    i13 = (int32_T)(((uint32_T)i12 + n) + 1U);
    if (!((i13 >= 1) && (i13 <= nm1d2))) {
      emlrtDynamicBoundsCheckR2012b(i13, 1, nm1d2, &ne_emlrtBCI, sp);
    }

    tmp_data[i12] = (uint32_T)i13;
  }

  emxInit_real_T1(sp, &Ref, 1, &kb_emlrtRTEI, true);
  st.site = &dd_emlrtRSI;
  indexShapeCheck(&st, dummydata->size[0], tmp_size);
  i12 = Ref->size[0];
  Ref->size[0] = this_data_size[0];
  emxEnsureCapacity(sp, (emxArray__common *)Ref, i12, (int32_T)sizeof(real_T),
                    &eb_emlrtRTEI);
  loop_ub = this_data_size[0];
  for (i12 = 0; i12 < loop_ub; i12++) {
    Ref->data[i12] = dummydata->data[(int32_T)tmp_data[i12] - 1] + backgrounds;
  }

  st.site = &ed_emlrtRSI;
  b_st.site = &m_emlrtRSI;
  c_st.site = &n_emlrtRSI;
  b4 = true;
  nm1d2 = Ref->size[0];
  if (this_data_size[0] != nm1d2) {
    b4 = false;
  }

  if (!b4) {
    emlrtErrorWithMessageIdR2012b(&c_st, &rb_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  nm1d2 = Ref->size[0];
  reflectivity_size[0] = this_data_size[0];
  reflectivity_size[1] = 2;
  loop_ub = this_data_size[0];
  for (i12 = 0; i12 < loop_ub; i12++) {
    reflectivity_data[i12] = middleSection_data[i12];
  }

  for (i12 = 0; i12 < nm1d2; i12++) {
    reflectivity_data[i12 + reflectivity_size[0]] = Ref->data[i12];
  }

  i12 = simRef->size[0];
  simRef->size[0] = dummydata->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)simRef, i12, (int32_T)sizeof(real_T),
                    &eb_emlrtRTEI);
  loop_ub = dummydata->size[0];
  for (i12 = 0; i12 < loop_ub; i12++) {
    simRef->data[i12] = dummydata->data[i12] + backgrounds;
  }

  emxFree_real_T(&dummydata);
  st.site = &fd_emlrtRSI;
  i12 = Ref->size[0];
  Ref->size[0] = simXdata->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)Ref, i12, (int32_T)sizeof(real_T),
                    &eb_emlrtRTEI);
  loop_ub = simXdata->size[1];
  for (i12 = 0; i12 < loop_ub; i12++) {
    Ref->data[i12] = simXdata->data[simXdata->size[0] * i12];
  }

  emxFree_real_T(&simXdata);
  b_st.site = &m_emlrtRSI;
  c_st.site = &n_emlrtRSI;
  b4 = true;
  if (Ref->size[0] != simRef->size[0]) {
    b4 = false;
  }

  if (!b4) {
    emlrtErrorWithMessageIdR2012b(&c_st, &rb_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  i12 = Simulation->size[0] * Simulation->size[1];
  Simulation->size[0] = Ref->size[0];
  Simulation->size[1] = 2;
  emxEnsureCapacity(&b_st, (emxArray__common *)Simulation, i12, (int32_T)sizeof
                    (real_T), &eb_emlrtRTEI);
  loop_ub = Ref->size[0];
  for (i12 = 0; i12 < loop_ub; i12++) {
    Simulation->data[i12] = Ref->data[i12];
  }

  emxFree_real_T(&Ref);
  loop_ub = simRef->size[0];
  for (i12 = 0; i12 < loop_ub; i12++) {
    Simulation->data[i12 + Simulation->size[0]] = simRef->data[i12];
  }

  emxFree_real_T(&simRef);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (callReflectivity.c) */
