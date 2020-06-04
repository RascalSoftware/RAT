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
#include "standardTF_custlay_parallel.h"
#include "callReflectivity.h"
#include "mpower.h"
#include "standardTF_custlay_parallel_emxutil.h"
#include "indexShapeCheck.h"
#include "abeles.h"
#include "standardTF_custlay_parallel_data.h"

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

static emlrtRTEInfo ib_emlrtRTEI = { 1,/* lineNo */
  39,                                  /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 19,/* lineNo */
  1,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 23,/* lineNo */
  5,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 32,/* lineNo */
  1,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = { 43,/* lineNo */
  5,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = { 48,/* lineNo */
  1,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = { 53,/* lineNo */
  1,                                   /* colNo */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"/* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = { 5,/* lineNo */
  1,                                   /* colNo */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m"/* pName */
};

static emlrtBCInfo ee_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  13,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  13,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ge_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  22,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo he_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  34,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ie_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  13,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo je_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  13,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo mc_emlrtRTEI = { 25,/* lineNo */
  13,                                  /* colNo */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m"/* pName */
};

static emlrtBCInfo ke_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  48,                                  /* colNo */
  "xdata",                             /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo le_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  24,                                  /* colNo */
  "dummydata",                         /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo me_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  30,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ne_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  26,                                  /* colNo */
  "xdata",                             /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  7,                                   /* colNo */
  "Ref",                               /* aName */
  "callReflectivity",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  5,                                   /* colNo */
  "dummydata",                         /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  9,                                   /* colNo */
  "dummydata",                         /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo re_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  22,                                  /* colNo */
  "xdata",                             /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo se_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  33,                                  /* colNo */
  "xdata",                             /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo te_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  28,                                  /* lineNo */
  24,                                  /* colNo */
  "dummydata",                         /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ue_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  28,                                  /* lineNo */
  39,                                  /* colNo */
  "dummyref",                          /* aName */
  "resolution_polly",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/resolution_polly.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ve_emlrtBCI = { -1, /* iFirst */
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
                      emxArray_real_T *this_data, const emxArray_real_T *layers,
                      real_T ssubs, real_T backgrounds, real_T res,
                      emxArray_real_T *reflectivity, emxArray_real_T *Simulation)
{
  emxArray_real_T *xdata;
  int32_T loop_ub;
  int32_T i17;
  emxArray_real_T *slds;
  real_T dv0[3];
  int32_T lays;
  int32_T i18;
  emxArray_real_T *middleSection;
  emxArray_real_T *firstSection;
  emxArray_real_T *simXdata;
  real_T step;
  emxArray_real_T *lastSection;
  real_T kd;
  int32_T i19;
  int32_T i20;
  int32_T nm1d2;
  int32_T k;
  real_T ndbl;
  real_T apnd;
  real_T cdiff;
  real_T absa;
  real_T absb;
  real_T a;
  int32_T n;
  emxArray_real_T *simRef;
  emxArray_real_T *dummydata;
  int32_T varargin_2;
  emxArray_uint32_T *r5;
  int32_T ilow;
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
  emxInit_real_T1(sp, &xdata, 1, &jb_emlrtRTEI, true);

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
  loop_ub = this_data->size[0];
  i17 = xdata->size[0];
  xdata->size[0] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)xdata, i17, (int32_T)sizeof(real_T),
                    &ib_emlrtRTEI);
  for (i17 = 0; i17 < loop_ub; i17++) {
    xdata->data[i17] = this_data->data[i17];
  }

  emxInit_real_T(sp, &slds, 2, &kb_emlrtRTEI, true);
  if (layers->size[0] == 0) {
    dv0[0] = 0.0;
    dv0[1] = nbairs;
    dv0[2] = 0.0;
    i17 = slds->size[0] * slds->size[1];
    slds->size[0] = 1;
    slds->size[1] = 3;
    emxEnsureCapacity(sp, (emxArray__common *)slds, i17, (int32_T)sizeof(real_T),
                      &ib_emlrtRTEI);
    for (i17 = 0; i17 < 3; i17++) {
      slds->data[slds->size[0] * i17] = dv0[i17];
    }

    lays = 0;
  } else {
    loop_ub = layers->size[0];
    i17 = slds->size[0] * slds->size[1];
    slds->size[0] = loop_ub;
    slds->size[1] = 3;
    emxEnsureCapacity(sp, (emxArray__common *)slds, i17, (int32_T)sizeof(real_T),
                      &ib_emlrtRTEI);
    for (i17 = 0; i17 < 3; i17++) {
      for (i18 = 0; i18 < loop_ub; i18++) {
        slds->data[i18 + slds->size[0] * i17] = layers->data[i18 + layers->size
          [0] * i17];
      }
    }

    lays = layers->size[0];
  }

  emxInit_real_T1(sp, &middleSection, 1, &lb_emlrtRTEI, true);
  loop_ub = this_data->size[0];
  i17 = middleSection->size[0];
  middleSection->size[0] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)middleSection, i17, (int32_T)sizeof
                    (real_T), &ib_emlrtRTEI);
  for (i17 = 0; i17 < loop_ub; i17++) {
    middleSection->data[i17] = this_data->data[i17];
  }

  i17 = this_data->size[0];
  if (!(1 <= i17)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i17, &ee_emlrtBCI, sp);
  }

  emxInit_real_T(sp, &firstSection, 2, &mb_emlrtRTEI, true);
  emxInit_real_T(sp, &simXdata, 2, &ob_emlrtRTEI, true);
  if (simLimits[0] < this_data->data[0]) {
    i17 = this_data->size[0];
    if (!(2 <= i17)) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i17, &fe_emlrtBCI, sp);
    }

    i17 = this_data->size[0];
    if (!(1 <= i17)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i17, &ge_emlrtBCI, sp);
    }

    step = this_data->data[1] - this_data->data[0];
    i17 = this_data->size[0];
    if (!(1 <= i17)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i17, &he_emlrtBCI, sp);
    }

    st.site = &yc_emlrtRSI;
    kd = this_data->data[0] - step;
    if (muDoubleScalarIsNaN(step) || muDoubleScalarIsNaN(kd)) {
      i17 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity(&st, (emxArray__common *)simXdata, i17, (int32_T)sizeof
                        (real_T), &ib_emlrtRTEI);
      simXdata->data[0] = rtNaN;
    } else if ((step == 0.0) || ((simLimits[0] < kd) && (step < 0.0)) || ((kd <
                 simLimits[0]) && (step > 0.0))) {
      i17 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 0;
      emxEnsureCapacity(&st, (emxArray__common *)simXdata, i17, (int32_T)sizeof
                        (real_T), &ib_emlrtRTEI);
    } else if ((muDoubleScalarIsInf(simLimits[0]) || muDoubleScalarIsInf(kd)) &&
               (muDoubleScalarIsInf(step) || (simLimits[0] == kd))) {
      i17 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity(&st, (emxArray__common *)simXdata, i17, (int32_T)sizeof
                        (real_T), &ib_emlrtRTEI);
      simXdata->data[0] = rtNaN;
    } else if (muDoubleScalarIsInf(step)) {
      i17 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity(&st, (emxArray__common *)simXdata, i17, (int32_T)sizeof
                        (real_T), &ib_emlrtRTEI);
      simXdata->data[0] = simLimits[0];
    } else if ((muDoubleScalarFloor(simLimits[0]) == simLimits[0]) &&
               (muDoubleScalarFloor(step) == step)) {
      i17 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = (int32_T)muDoubleScalarFloor((kd - simLimits[0]) /
        step) + 1;
      emxEnsureCapacity(&st, (emxArray__common *)simXdata, i17, (int32_T)sizeof
                        (real_T), &ib_emlrtRTEI);
      loop_ub = (int32_T)muDoubleScalarFloor((kd - simLimits[0]) / step);
      for (i17 = 0; i17 <= loop_ub; i17++) {
        simXdata->data[simXdata->size[0] * i17] = simLimits[0] + step * (real_T)
          i17;
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
        emlrtErrorWithMessageIdR2012b(&c_st, &ic_emlrtRTEI,
          "Coder:MATLAB:pmaxsize", 0);
      }

      i17 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = n;
      emxEnsureCapacity(&b_st, (emxArray__common *)simXdata, i17, (int32_T)
                        sizeof(real_T), &ib_emlrtRTEI);
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

    i17 = firstSection->size[0] * firstSection->size[1];
    firstSection->size[0] = 1;
    firstSection->size[1] = simXdata->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)firstSection, i17, (int32_T)sizeof
                      (real_T), &ib_emlrtRTEI);
    loop_ub = simXdata->size[0] * simXdata->size[1];
    for (i17 = 0; i17 < loop_ub; i17++) {
      firstSection->data[i17] = simXdata->data[i17];
    }
  } else {
    i17 = firstSection->size[0] * firstSection->size[1];
    firstSection->size[0] = 0;
    firstSection->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)firstSection, i17, (int32_T)sizeof
                      (real_T), &ib_emlrtRTEI);
  }

  i17 = this_data->size[0];
  i18 = this_data->size[0];
  if (!((i17 >= 1) && (i17 <= i18))) {
    emlrtDynamicBoundsCheckR2012b(i17, 1, i18, &ie_emlrtBCI, sp);
  }

  emxInit_real_T(sp, &lastSection, 2, &nb_emlrtRTEI, true);
  if (simLimits[1] > this_data->data[i17 - 1]) {
    i17 = this_data->size[0];
    i18 = this_data->size[0];
    i19 = this_data->size[0] - 1;
    i20 = this_data->size[0];
    if (!((i17 >= 1) && (i17 <= i18))) {
      emlrtDynamicBoundsCheckR2012b(i17, 1, i18, &je_emlrtBCI, sp);
    }

    if (!((i19 >= 1) && (i19 <= i20))) {
      emlrtDynamicBoundsCheckR2012b(i19, 1, i20, &me_emlrtBCI, sp);
    }

    step = this_data->data[i17 - 1] - xdata->data[i19 - 1];
    st.site = &ad_emlrtRSI;
    i17 = this_data->size[0];
    i18 = this_data->size[0];
    if (!((i17 >= 1) && (i17 <= i18))) {
      emlrtDynamicBoundsCheckR2012b(i17, 1, i18, &ne_emlrtBCI, &st);
    }

    a = xdata->data[i17 - 1] + step;
    if (muDoubleScalarIsNaN(a) || muDoubleScalarIsNaN(step)) {
      i17 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity(&st, (emxArray__common *)simXdata, i17, (int32_T)sizeof
                        (real_T), &ib_emlrtRTEI);
      simXdata->data[0] = rtNaN;
    } else if ((step == 0.0) || ((a < simLimits[1]) && (step < 0.0)) ||
               ((simLimits[1] < a) && (step > 0.0))) {
      i17 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 0;
      emxEnsureCapacity(&st, (emxArray__common *)simXdata, i17, (int32_T)sizeof
                        (real_T), &ib_emlrtRTEI);
    } else if ((muDoubleScalarIsInf(a) || muDoubleScalarIsInf(simLimits[1])) &&
               (muDoubleScalarIsInf(step) || (a == simLimits[1]))) {
      i17 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity(&st, (emxArray__common *)simXdata, i17, (int32_T)sizeof
                        (real_T), &ib_emlrtRTEI);
      simXdata->data[0] = rtNaN;
    } else if (muDoubleScalarIsInf(step)) {
      i17 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = 1;
      emxEnsureCapacity(&st, (emxArray__common *)simXdata, i17, (int32_T)sizeof
                        (real_T), &ib_emlrtRTEI);
      simXdata->data[0] = a;
    } else if ((muDoubleScalarFloor(a) == a) && (muDoubleScalarFloor(step) ==
                step)) {
      i17 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = (int32_T)muDoubleScalarFloor((simLimits[1] - a) / step)
        + 1;
      emxEnsureCapacity(&st, (emxArray__common *)simXdata, i17, (int32_T)sizeof
                        (real_T), &ib_emlrtRTEI);
      loop_ub = (int32_T)muDoubleScalarFloor((simLimits[1] - a) / step);
      for (i17 = 0; i17 <= loop_ub; i17++) {
        simXdata->data[simXdata->size[0] * i17] = a + step * (real_T)i17;
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
        emlrtErrorWithMessageIdR2012b(&c_st, &ic_emlrtRTEI,
          "Coder:MATLAB:pmaxsize", 0);
      }

      i17 = simXdata->size[0] * simXdata->size[1];
      simXdata->size[0] = 1;
      simXdata->size[1] = n;
      emxEnsureCapacity(&b_st, (emxArray__common *)simXdata, i17, (int32_T)
                        sizeof(real_T), &ib_emlrtRTEI);
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

    i17 = lastSection->size[0] * lastSection->size[1];
    lastSection->size[0] = 1;
    lastSection->size[1] = simXdata->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)lastSection, i17, (int32_T)sizeof
                      (real_T), &ib_emlrtRTEI);
    loop_ub = simXdata->size[0] * simXdata->size[1];
    for (i17 = 0; i17 < loop_ub; i17++) {
      lastSection->data[i17] = simXdata->data[i17];
    }
  } else {
    i17 = lastSection->size[0] * lastSection->size[1];
    lastSection->size[0] = 0;
    lastSection->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)lastSection, i17, (int32_T)sizeof
                      (real_T), &ib_emlrtRTEI);
  }

  nm1d2 = firstSection->size[0] * firstSection->size[1];
  k = lastSection->size[0] * lastSection->size[1];
  i17 = simXdata->size[0] * simXdata->size[1];
  simXdata->size[0] = 1;
  simXdata->size[1] = (nm1d2 + middleSection->size[0]) + k;
  emxEnsureCapacity(sp, (emxArray__common *)simXdata, i17, (int32_T)sizeof
                    (real_T), &ib_emlrtRTEI);
  for (i17 = 0; i17 < nm1d2; i17++) {
    simXdata->data[simXdata->size[0] * i17] = firstSection->data[i17];
  }

  loop_ub = middleSection->size[0];
  for (i17 = 0; i17 < loop_ub; i17++) {
    simXdata->data[simXdata->size[0] * (i17 + nm1d2)] = middleSection->data[i17];
  }

  for (i17 = 0; i17 < k; i17++) {
    simXdata->data[simXdata->size[0] * ((i17 + nm1d2) + middleSection->size[0])]
      = lastSection->data[i17];
  }

  if ((firstSection->size[0] == 0) || (firstSection->size[1] == 0)) {
    n = 0;
  } else {
    n = firstSection->size[1];
  }

  emxFree_real_T(&firstSection);
  emxFree_real_T(&lastSection);
  emxInit_real_T1(sp, &simRef, 1, &pb_emlrtRTEI, true);
  emxInit_real_T1(sp, &dummydata, 1, &qb_emlrtRTEI, true);
  i17 = this_data->size[0];
  st.site = &bd_emlrtRSI;
  abeles(&st, simXdata, slds, nbairs, nbsubs, repeatLayers[1], ssubs, lays,
         simXdata->size[1], simRef);
  varargin_2 = simXdata->size[1] - 1;
  st.site = &cd_emlrtRSI;
  i18 = dummydata->size[0];
  dummydata->size[0] = simXdata->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)dummydata, i18, (int32_T)sizeof
                    (real_T), &ib_emlrtRTEI);
  loop_ub = simXdata->size[1];
  emxFree_real_T(&slds);
  for (i18 = 0; i18 < loop_ub; i18++) {
    dummydata->data[i18] = 0.0;
  }

  lays = 0;
  while (lays <= simXdata->size[1] - 1) {
    ndbl = 0.0;
    i18 = dummydata->size[0];
    i19 = 1 + lays;
    if (!((i19 >= 1) && (i19 <= i18))) {
      emlrtDynamicBoundsCheckR2012b(i19, 1, i18, &pe_emlrtBCI, &st);
    }

    dummydata->data[i19 - 1] = 0.0;
    if (1 + lays > 10) {
      ilow = -10;
    } else {
      ilow = -lays;
    }

    if (1 + lays < varargin_2 - 9) {
      nm1d2 = 10;
    } else {
      nm1d2 = varargin_2 - lays;
    }

    /*     try */
    i18 = (int32_T)((real_T)nm1d2 + (1.0 - (real_T)ilow));
    emlrtForLoopVectorCheckR2012b(ilow, 1.0, nm1d2, mxDOUBLE_CLASS, i18,
      &mc_emlrtRTEI, &st);
    nm1d2 = 0;
    while (nm1d2 <= i18 - 1) {
      cdiff = (real_T)ilow + (real_T)nm1d2;
      i19 = simXdata->size[1];
      i20 = (int32_T)((1.0 + (real_T)lays) + cdiff);
      if (!((i20 >= 1) && (i20 <= i19))) {
        emlrtDynamicBoundsCheckR2012b(i20, 1, i19, &re_emlrtBCI, &st);
      }

      i19 = simXdata->size[1];
      k = 1 + lays;
      if (!((k >= 1) && (k <= i19))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i19, &se_emlrtBCI, &st);
      }

      kd = simXdata->data[i20 - 1] - simXdata->data[k - 1];
      i19 = simXdata->size[1];
      i20 = lays + 1;
      if (!((i20 >= 1) && (i20 <= i19))) {
        emlrtDynamicBoundsCheckR2012b(i20, 1, i19, &ke_emlrtBCI, &st);
      }

      b_st.site = &kd_emlrtRSI;
      kd = -mpower(kd / ((res + 0.0001) * simXdata->data[lays]));
      kd = muDoubleScalarExp(kd);
      ndbl += kd;
      i19 = dummydata->size[0];
      i20 = 1 + lays;
      if (!((i20 >= 1) && (i20 <= i19))) {
        emlrtDynamicBoundsCheckR2012b(i20, 1, i19, &te_emlrtBCI, &st);
      }

      i19 = simRef->size[0];
      k = (int32_T)(cdiff + (1.0 + (real_T)lays));
      if (!((k >= 1) && (k <= i19))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i19, &ue_emlrtBCI, &st);
      }

      i19 = dummydata->size[0];
      loop_ub = 1 + lays;
      if (!((loop_ub >= 1) && (loop_ub <= i19))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i19, &ve_emlrtBCI, &st);
      }

      dummydata->data[loop_ub - 1] = dummydata->data[i20 - 1] + simRef->data[k -
        1] * kd;
      nm1d2++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    if (ndbl != 0.0) {
      i18 = dummydata->size[0];
      i19 = lays + 1;
      if (!((i19 >= 1) && (i19 <= i18))) {
        emlrtDynamicBoundsCheckR2012b(i19, 1, i18, &le_emlrtBCI, &st);
      }

      i18 = dummydata->size[0];
      i19 = 1 + lays;
      if (!((i19 >= 1) && (i19 <= i18))) {
        emlrtDynamicBoundsCheckR2012b(i19, 1, i18, &qe_emlrtBCI, &st);
      }

      dummydata->data[i19 - 1] = dummydata->data[lays] / ndbl;
    }

    /*      catch */
    /*          disp('debug!'); */
    /*      end */
    lays++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  emxInit_uint32_T(&st, &r5, 2, &ib_emlrtRTEI, true);
  nm1d2 = dummydata->size[0];
  i18 = r5->size[0] * r5->size[1];
  r5->size[0] = 1;
  r5->size[1] = i17;
  emxEnsureCapacity(sp, (emxArray__common *)r5, i18, (int32_T)sizeof(uint32_T),
                    &ib_emlrtRTEI);
  loop_ub = (int32_T)(i17 + MAX_uint32_T);
  for (i17 = 0; i17 <= loop_ub; i17++) {
    i18 = (int32_T)(((uint32_T)i17 + n) + 1U);
    if (!((i18 >= 1) && (i18 <= nm1d2))) {
      emlrtDynamicBoundsCheckR2012b(i18, 1, nm1d2, &oe_emlrtBCI, sp);
    }

    r5->data[r5->size[0] * i17] = (uint32_T)i18;
  }

  st.site = &dd_emlrtRSI;
  indexShapeCheck(&st, dummydata->size[0], *(int32_T (*)[2])r5->size);
  i17 = xdata->size[0];
  xdata->size[0] = r5->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)xdata, i17, (int32_T)sizeof(real_T),
                    &ib_emlrtRTEI);
  loop_ub = r5->size[1];
  for (i17 = 0; i17 < loop_ub; i17++) {
    xdata->data[i17] = dummydata->data[(int32_T)r5->data[r5->size[0] * i17] - 1]
      + backgrounds;
  }

  emxFree_uint32_T(&r5);
  st.site = &ed_emlrtRSI;
  b_st.site = &m_emlrtRSI;
  nm1d2 = this_data->size[0];
  c_st.site = &n_emlrtRSI;
  i17 = this_data->size[0];
  b4 = (nm1d2 == i17);
  if (!b4) {
    emlrtErrorWithMessageIdR2012b(&c_st, &ac_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  k = xdata->size[0];
  if (nm1d2 != k) {
    b4 = false;
  }

  if (!b4) {
    emlrtErrorWithMessageIdR2012b(&c_st, &ac_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  loop_ub = this_data->size[0];
  k = xdata->size[0];
  i17 = reflectivity->size[0] * reflectivity->size[1];
  reflectivity->size[0] = loop_ub;
  reflectivity->size[1] = 2;
  emxEnsureCapacity(&b_st, (emxArray__common *)reflectivity, i17, (int32_T)
                    sizeof(real_T), &ib_emlrtRTEI);
  for (i17 = 0; i17 < loop_ub; i17++) {
    reflectivity->data[i17] = middleSection->data[i17];
  }

  emxFree_real_T(&middleSection);
  for (i17 = 0; i17 < k; i17++) {
    reflectivity->data[i17 + reflectivity->size[0]] = xdata->data[i17];
  }

  i17 = simRef->size[0];
  simRef->size[0] = dummydata->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)simRef, i17, (int32_T)sizeof(real_T),
                    &ib_emlrtRTEI);
  loop_ub = dummydata->size[0];
  for (i17 = 0; i17 < loop_ub; i17++) {
    simRef->data[i17] = dummydata->data[i17] + backgrounds;
  }

  emxFree_real_T(&dummydata);
  st.site = &fd_emlrtRSI;
  i17 = xdata->size[0];
  xdata->size[0] = simXdata->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)xdata, i17, (int32_T)sizeof(real_T),
                    &ib_emlrtRTEI);
  loop_ub = simXdata->size[1];
  for (i17 = 0; i17 < loop_ub; i17++) {
    xdata->data[i17] = simXdata->data[simXdata->size[0] * i17];
  }

  emxFree_real_T(&simXdata);
  b_st.site = &m_emlrtRSI;
  c_st.site = &n_emlrtRSI;
  b4 = true;
  if (xdata->size[0] != simRef->size[0]) {
    b4 = false;
  }

  if (!b4) {
    emlrtErrorWithMessageIdR2012b(&c_st, &ac_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  i17 = Simulation->size[0] * Simulation->size[1];
  Simulation->size[0] = xdata->size[0];
  Simulation->size[1] = 2;
  emxEnsureCapacity(&b_st, (emxArray__common *)Simulation, i17, (int32_T)sizeof
                    (real_T), &ib_emlrtRTEI);
  loop_ub = xdata->size[0];
  for (i17 = 0; i17 < loop_ub; i17++) {
    Simulation->data[i17] = xdata->data[i17];
  }

  emxFree_real_T(&xdata);
  loop_ub = simRef->size[0];
  for (i17 = 0; i17 < loop_ub; i17++) {
    Simulation->data[i17 + Simulation->size[0]] = simRef->data[i17];
  }

  emxFree_real_T(&simRef);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (callReflectivity.c) */
