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
#include "colon.h"
#include "data_resolution_polly.h"
#include "exp.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "resolution_polly.h"
#include "rt_nonfinite.h"
#include "sqrt1.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ng_emlrtRSI = {
    21,                 /* lineNo */
    "callReflectivity", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pathName */
};

static emlrtRSInfo og_emlrtRSI = {
    28,                 /* lineNo */
    "callReflectivity", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pathName */
};

static emlrtRSInfo pg_emlrtRSI = {
    79,                 /* lineNo */
    "callReflectivity", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pathName */
};

static emlrtRSInfo qg_emlrtRSI = {
    83,                 /* lineNo */
    "callReflectivity", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pathName */
};

static emlrtRSInfo rg_emlrtRSI = {
    85,                 /* lineNo */
    "callReflectivity", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pathName */
};

static emlrtRSInfo sg_emlrtRSI = {
    117,     /* lineNo */
    "colon", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/ops/colon.m" /* pathName
                                                                          */
};

static emlrtRSInfo vg_emlrtRSI = {
    28,              /* lineNo */
    "abeles_single", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "reflectivityCalculations/Abeles/abeles_single.m" /* pathName */
};

static emlrtRSInfo jh_emlrtRSI = {
    61,                 /* lineNo */
    "callReflectivity", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pathName */
};

static emlrtRSInfo kh_emlrtRSI = {
    69,                 /* lineNo */
    "callReflectivity", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pathName */
};

static emlrtRSInfo lh_emlrtRSI = {
    72,                 /* lineNo */
    "callReflectivity", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pathName */
};

static emlrtBCInfo yh_emlrtBCI = {
    -1,              /* iFirst */
    -1,              /* iLast */
    41,              /* lineNo */
    25,              /* colNo */
    "sld",           /* aName */
    "abeles_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "reflectivityCalculations/Abeles/abeles_single.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtRTEInfo sb_emlrtRTEI = {
    39,              /* lineNo */
    19,              /* colNo */
    "abeles_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "reflectivityCalculations/Abeles/abeles_single.m" /* pName */
};

static emlrtBCInfo ai_emlrtBCI = {
    -1,              /* iFirst */
    -1,              /* iLast */
    27,              /* lineNo */
    11,              /* colNo */
    "x",             /* aName */
    "abeles_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "reflectivityCalculations/Abeles/abeles_single.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo bi_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    91,                 /* lineNo */
    37,                 /* colNo */
    "Simulation",       /* aName */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m", /* pName */
    0                     /* checkKind */
};

static emlrtBCInfo ci_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    91,                 /* lineNo */
    27,                 /* colNo */
    "Simulation",       /* aName */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m", /* pName */
    0                     /* checkKind */
};

static emlrtECInfo x_emlrtECI = {
    -1,                 /* nDims */
    90,                 /* lineNo */
    1,                  /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtECInfo y_emlrtECI = {
    -1,                 /* nDims */
    37,                 /* lineNo */
    1,                  /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtBCInfo di_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    46,                 /* lineNo */
    28,                 /* colNo */
    "thisDataResol",    /* aName */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m", /* pName */
    0                     /* checkKind */
};

static emlrtBCInfo ei_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    45,                 /* lineNo */
    28,                 /* colNo */
    "thisDataResol",    /* aName */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m", /* pName */
    0                     /* checkKind */
};

static emlrtBCInfo fi_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    44,                 /* lineNo */
    33,                 /* colNo */
    "this_data",        /* aName */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m", /* pName */
    0                     /* checkKind */
};

static emlrtBCInfo gi_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    21,                 /* lineNo */
    40,                 /* colNo */
    "xdata",            /* aName */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m", /* pName */
    0                     /* checkKind */
};

static emlrtBCInfo hi_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    20,                 /* lineNo */
    28,                 /* colNo */
    "xdata",            /* aName */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m", /* pName */
    0                     /* checkKind */
};

static emlrtBCInfo ii_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    20,                 /* lineNo */
    19,                 /* colNo */
    "xdata",            /* aName */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m", /* pName */
    0                     /* checkKind */
};

static emlrtBCInfo ji_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    19,                 /* lineNo */
    19,                 /* colNo */
    "xdata",            /* aName */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m", /* pName */
    0                     /* checkKind */
};

static emlrtBCInfo ki_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    16,                 /* lineNo */
    29,                 /* colNo */
    "this_data",        /* aName */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m", /* pName */
    0                     /* checkKind */
};

static emlrtBCInfo li_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    15,                 /* lineNo */
    20,                 /* colNo */
    "simLimits",        /* aName */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m", /* pName */
    0                     /* checkKind */
};

static emlrtBCInfo mi_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    14,                 /* lineNo */
    20,                 /* colNo */
    "simLimits",        /* aName */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m", /* pName */
    0                     /* checkKind */
};

static emlrtBCInfo ni_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    3,                  /* lineNo */
    21,                 /* colNo */
    "this_data",        /* aName */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m", /* pName */
    0                     /* checkKind */
};

static emlrtBCInfo oi_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    26,                 /* lineNo */
    13,                 /* colNo */
    "xdata",            /* aName */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m", /* pName */
    0                     /* checkKind */
};

static emlrtBCInfo pi_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    27,                 /* lineNo */
    13,                 /* colNo */
    "xdata",            /* aName */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m", /* pName */
    0                     /* checkKind */
};

static emlrtBCInfo qi_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    27,                 /* lineNo */
    30,                 /* colNo */
    "xdata",            /* aName */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m", /* pName */
    0                     /* checkKind */
};

static emlrtBCInfo ri_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    28,                 /* lineNo */
    26,                 /* colNo */
    "xdata",            /* aName */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m", /* pName */
    0                     /* checkKind */
};

static emlrtBCInfo si_emlrtBCI = {
    -1,              /* iFirst */
    -1,              /* iLast */
    72,              /* lineNo */
    5,               /* colNo */
    "out",           /* aName */
    "abeles_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "reflectivityCalculations/Abeles/abeles_single.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtRTEInfo fl_emlrtRTEI = {
    7,                  /* lineNo */
    5,                  /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo gl_emlrtRTEI = {
    10,                 /* lineNo */
    5,                  /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo hl_emlrtRTEI = {
    33,                 /* lineNo */
    1,                  /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo il_emlrtRTEI = {
    21,                 /* lineNo */
    5,                  /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo jl_emlrtRTEI = {
    28,                 /* lineNo */
    5,                  /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo kl_emlrtRTEI = {
    36,                 /* lineNo */
    1,                  /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo ll_emlrtRTEI = {
    42,                 /* lineNo */
    1,                  /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo ml_emlrtRTEI = {
    79,                 /* lineNo */
    26,                 /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo nl_emlrtRTEI = {
    49,                 /* lineNo */
    5,                  /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo ol_emlrtRTEI = {
    85,                 /* lineNo */
    56,                 /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo pl_emlrtRTEI = {
    83,                 /* lineNo */
    61,                 /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo ql_emlrtRTEI = {
    91,                 /* lineNo */
    1,                  /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo rl_emlrtRTEI = {
    61,                 /* lineNo */
    17,                 /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo qm_emlrtRTEI = {
    72,                 /* lineNo */
    56,                 /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo rm_emlrtRTEI = {
    69,                 /* lineNo */
    61,                 /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

/* Function Definitions */
void b_callReflectivity(const emlrtStack *sp, real_T nbairs, real_T nbsubs,
                        const real_T simLimits_data[],
                        const int32_T simLimits_size[2],
                        const real_T repeatLayers[2],
                        const emxArray_real_T *this_data,
                        const emxArray_real_T *layers, real_T ssubs, real_T res,
                        emxArray_real_T *reflectivity,
                        emxArray_real_T *Simulation)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T *b_simRef;
  emxArray_real_T *firstSection;
  emxArray_real_T *lastSection;
  emxArray_real_T *simRef;
  emxArray_real_T *simResolData;
  emxArray_real_T *simXdata;
  emxArray_real_T *slds;
  real_T b;
  real_T step;
  int32_T b_loop_ub;
  int32_T i;
  int32_T lays;
  int32_T loop_ub;
  int32_T simLimits;
  uint32_T splits_idx_1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (1 > this_data->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[1], &ni_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  emxInit_real_T(sp, &slds, 2, &fl_emlrtRTEI, true);
  if (layers->size[0] == 0) {
    i = slds->size[0] * slds->size[1];
    slds->size[0] = 1;
    slds->size[1] = 3;
    emxEnsureCapacity_real_T(sp, slds, i, &fl_emlrtRTEI);
    slds->data[0] = 0.0;
    slds->data[1] = nbairs;
    slds->data[2] = 0.0;
    lays = 0;
  } else {
    loop_ub = layers->size[0];
    i = slds->size[0] * slds->size[1];
    slds->size[0] = layers->size[0];
    slds->size[1] = 3;
    emxEnsureCapacity_real_T(sp, slds, i, &gl_emlrtRTEI);
    for (i = 0; i < 3; i++) {
      for (lays = 0; lays < loop_ub; lays++) {
        slds->data[lays + slds->size[0] * i] =
            layers->data[lays + layers->size[0] * i];
      }
    }
    lays = layers->size[0];
  }
  i = simLimits_size[0] * simLimits_size[1];
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &mi_emlrtBCI, (emlrtCTX)sp);
  }
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &li_emlrtBCI, (emlrtCTX)sp);
  }
  if (1 > this_data->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[1], &ki_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (1 > this_data->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &ji_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  emxInit_real_T(sp, &firstSection, 2, &il_emlrtRTEI, true);
  if (simLimits_data[0] < this_data->data[0]) {
    if (2 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, this_data->size[0], &ii_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (1 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &hi_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    step = this_data->data[1] - this_data->data[0];
    if (1 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &gi_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    st.site = &ng_emlrtRSI;
    b = this_data->data[0] - step;
    if (muDoubleScalarIsNaN(simLimits_data[0]) || muDoubleScalarIsNaN(step) ||
        muDoubleScalarIsNaN(b)) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &il_emlrtRTEI);
      firstSection->data[0] = rtNaN;
    } else if ((step == 0.0) || ((simLimits_data[0] < b) && (step < 0.0)) ||
               ((b < simLimits_data[0]) && (step > 0.0))) {
      firstSection->size[0] = 1;
      firstSection->size[1] = 0;
    } else if ((muDoubleScalarIsInf(simLimits_data[0]) ||
                muDoubleScalarIsInf(b)) &&
               (muDoubleScalarIsInf(step) || (simLimits_data[0] == b))) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &il_emlrtRTEI);
      firstSection->data[0] = rtNaN;
    } else if (muDoubleScalarIsInf(step)) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &il_emlrtRTEI);
      firstSection->data[0] = simLimits_data[0];
    } else if ((muDoubleScalarFloor(simLimits_data[0]) == simLimits_data[0]) &&
               (muDoubleScalarFloor(step) == step)) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      loop_ub = (int32_T)muDoubleScalarFloor((b - simLimits_data[0]) / step);
      firstSection->size[1] = loop_ub + 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &il_emlrtRTEI);
      for (i = 0; i <= loop_ub; i++) {
        firstSection->data[i] = simLimits_data[0] + step * (real_T)i;
      }
    } else {
      b_st.site = &sg_emlrtRSI;
      eml_float_colon(&b_st, simLimits_data[0], step, b, firstSection);
    }
  } else {
    firstSection->size[0] = 1;
    firstSection->size[1] = 0;
  }
  if (this_data->size[0] < 1) {
    emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
                                  &oi_emlrtBCI, (emlrtCTX)sp);
  }
  emxInit_real_T(sp, &lastSection, 2, &jl_emlrtRTEI, true);
  if (simLimits_data[1] > this_data->data[this_data->size[0] - 1]) {
    if (this_data->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
                                    &pi_emlrtBCI, (emlrtCTX)sp);
    }
    if ((this_data->size[0] - 1 < 1) ||
        (this_data->size[0] - 1 > this_data->size[0])) {
      emlrtDynamicBoundsCheckR2012b(this_data->size[0] - 1, 1,
                                    this_data->size[0], &qi_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    step = this_data->data[this_data->size[0] - 1] -
           this_data->data[this_data->size[0] - 2];
    st.site = &og_emlrtRSI;
    if (this_data->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
                                    &ri_emlrtBCI, &st);
    }
    b = this_data->data[this_data->size[0] - 1] + step;
    if (muDoubleScalarIsNaN(b) || muDoubleScalarIsNaN(step) ||
        muDoubleScalarIsNaN(simLimits_data[1])) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &jl_emlrtRTEI);
      lastSection->data[0] = rtNaN;
    } else if ((step == 0.0) || ((b < simLimits_data[1]) && (step < 0.0)) ||
               ((simLimits_data[1] < b) && (step > 0.0))) {
      lastSection->size[0] = 1;
      lastSection->size[1] = 0;
    } else if ((muDoubleScalarIsInf(b) ||
                muDoubleScalarIsInf(simLimits_data[1])) &&
               (muDoubleScalarIsInf(step) || (b == simLimits_data[1]))) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &jl_emlrtRTEI);
      lastSection->data[0] = rtNaN;
    } else if (muDoubleScalarIsInf(step)) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &jl_emlrtRTEI);
      lastSection->data[0] = b;
    } else if ((muDoubleScalarFloor(b) == b) &&
               (muDoubleScalarFloor(step) == step)) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      loop_ub = (int32_T)muDoubleScalarFloor((simLimits_data[1] - b) / step);
      lastSection->size[1] = loop_ub + 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &jl_emlrtRTEI);
      for (i = 0; i <= loop_ub; i++) {
        lastSection->data[i] = b + step * (real_T)i;
      }
    } else {
      b_st.site = &sg_emlrtRSI;
      eml_float_colon(&b_st, b, step, simLimits_data[1], lastSection);
    }
  } else {
    lastSection->size[0] = 1;
    lastSection->size[1] = 0;
  }
  emxInit_real_T(sp, &simXdata, 1, &hl_emlrtRTEI, true);
  simLimits = firstSection->size[1];
  loop_ub = this_data->size[0];
  i = simXdata->size[0];
  simXdata->size[0] =
      (this_data->size[0] + firstSection->size[1]) + lastSection->size[1];
  emxEnsureCapacity_real_T(sp, simXdata, i, &hl_emlrtRTEI);
  b_loop_ub = firstSection->size[1];
  for (i = 0; i < b_loop_ub; i++) {
    simXdata->data[i] = firstSection->data[i];
  }
  for (i = 0; i < loop_ub; i++) {
    simXdata->data[i + simLimits] = this_data->data[i];
  }
  b_loop_ub = lastSection->size[1];
  for (i = 0; i < b_loop_ub; i++) {
    simXdata->data[(i + simLimits) + loop_ub] = lastSection->data[i];
  }
  splits_idx_1 = (uint32_T)firstSection->size[1] + this_data->size[0];
  i = Simulation->size[0] * Simulation->size[1];
  Simulation->size[0] = simXdata->size[0];
  Simulation->size[1] = 2;
  emxEnsureCapacity_real_T(sp, Simulation, i, &kl_emlrtRTEI);
  loop_ub = simXdata->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    Simulation->data[i] = 0.0;
  }
  emlrtSubAssignSizeCheckR2012b(&simXdata->size[0], 1, &simXdata->size[0], 1,
                                &y_emlrtECI, (emlrtCTX)sp);
  loop_ub = simXdata->size[0];
  for (i = 0; i < loop_ub; i++) {
    Simulation->data[i] = simXdata->data[i];
  }
  emxInit_real_T(sp, &simResolData, 1, &ll_emlrtRTEI, true);
  /*  If we are using data resolutions, then we also need to adjust the length
   */
  /*  of the reolution column. We do thit by just extending with the rosolution
   */
  /*  values at the ends of the curve. */
  i = simResolData->size[0];
  simResolData->size[0] = 1;
  emxEnsureCapacity_real_T(sp, simResolData, i, &ll_emlrtRTEI);
  simResolData->data[0] = 0.0;
  if (res == -1.0) {
    if (4 > this_data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(4, 1, this_data->size[1], &fi_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (1 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &ei_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (this_data->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
                                    &di_emlrtBCI, (emlrtCTX)sp);
    }
    simLimits = firstSection->size[1];
    loop_ub = this_data->size[0];
    i = simResolData->size[0];
    simResolData->size[0] =
        (this_data->size[0] + firstSection->size[1]) + lastSection->size[1];
    emxEnsureCapacity_real_T(sp, simResolData, i, &nl_emlrtRTEI);
    b_loop_ub = firstSection->size[1];
    for (i = 0; i < b_loop_ub; i++) {
      simResolData->data[i] = this_data->data[this_data->size[0] * 3];
    }
    for (i = 0; i < loop_ub; i++) {
      simResolData->data[i + simLimits] =
          this_data->data[i + this_data->size[0] * 3];
    }
    b_loop_ub = lastSection->size[1];
    for (i = 0; i < b_loop_ub; i++) {
      simResolData->data[(i + simLimits) + loop_ub] =
          this_data->data[(this_data->size[0] + this_data->size[0] * 3) - 1];
    }
  }
  emxFree_real_T(&lastSection);
  emxInit_real_T(sp, &simRef, 1, &rl_emlrtRTEI, true);
  /*  Parallelise over points */
  /*  Calculate reflectivity.... */
  st.site = &jh_emlrtRSI;
  abeles_paraPoints(&st, simXdata, slds, nbairs, nbsubs, repeatLayers[1], ssubs,
                    lays, simXdata->size[0], simRef);
  /* (x,sld,nbair,nbsub,nrepeats,ssub,layers,points) */
  /*  Apply resolution */
  /*  Note: paraPoints gives an error during valifation, so use */
  /*  single cored resolution as a workaround for now. */
  emxFree_real_T(&slds);
  emxInit_real_T(sp, &b_simRef, 1, &qm_emlrtRTEI, true);
  if (res == -1.0) {
    /* simRef =
     * data_resolution_polly_paraPoints(simXdata,simRef,simResolData,length(simXdata));
     */
    i = b_simRef->size[0];
    b_simRef->size[0] = simRef->size[0];
    emxEnsureCapacity_real_T(sp, b_simRef, i, &rm_emlrtRTEI);
    loop_ub = simRef->size[0] - 1;
    for (i = 0; i <= loop_ub; i++) {
      b_simRef->data[i] = simRef->data[i];
    }
    st.site = &kh_emlrtRSI;
    data_resolution_polly(&st, simXdata, b_simRef, simResolData,
                          simXdata->size[0], simRef);
  } else {
    /* simRef =
     * resolution_polly_paraPoints(simXdata,simRef,res,length(simXdata)); */
    i = b_simRef->size[0];
    b_simRef->size[0] = simRef->size[0];
    emxEnsureCapacity_real_T(sp, b_simRef, i, &qm_emlrtRTEI);
    loop_ub = simRef->size[0] - 1;
    for (i = 0; i <= loop_ub; i++) {
      b_simRef->data[i] = simRef->data[i];
    }
    st.site = &lh_emlrtRSI;
    resolution_polly(&st, simXdata, b_simRef, res, simXdata->size[0], simRef);
  }
  emxFree_real_T(&b_simRef);
  emxFree_real_T(&simResolData);
  emxFree_real_T(&simXdata);
  emlrtSubAssignSizeCheckR2012b(&Simulation->size[0], 1, &simRef->size[0], 1,
                                &x_emlrtECI, (emlrtCTX)sp);
  loop_ub = simRef->size[0];
  for (i = 0; i < loop_ub; i++) {
    Simulation->data[i + Simulation->size[0]] = simRef->data[i];
  }
  emxFree_real_T(&simRef);
  if (firstSection->size[1] + 1U > splits_idx_1) {
    i = 0;
    lays = 0;
  } else {
    if (((int32_T)(firstSection->size[1] + 1U) < 1) ||
        ((int32_T)(firstSection->size[1] + 1U) > Simulation->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(firstSection->size[1] + 1U), 1,
                                    Simulation->size[0], &ci_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i = firstSection->size[1];
    if (((int32_T)splits_idx_1 < 1) ||
        ((int32_T)splits_idx_1 > Simulation->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)splits_idx_1, 1,
                                    Simulation->size[0], &bi_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    lays = (int32_T)splits_idx_1;
  }
  emxFree_real_T(&firstSection);
  loop_ub = lays - i;
  lays = reflectivity->size[0] * reflectivity->size[1];
  reflectivity->size[0] = loop_ub;
  reflectivity->size[1] = 2;
  emxEnsureCapacity_real_T(sp, reflectivity, lays, &ql_emlrtRTEI);
  for (lays = 0; lays < 2; lays++) {
    for (simLimits = 0; simLimits < loop_ub; simLimits++) {
      reflectivity->data[simLimits + reflectivity->size[0] * lays] =
          Simulation->data[(i + simLimits) + Simulation->size[0] * lays];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void callReflectivity(const emlrtStack *sp, real_T nbairs, real_T nbsubs,
                      const real_T simLimits_data[],
                      const int32_T simLimits_size[2],
                      const real_T repeatLayers[2],
                      const emxArray_real_T *this_data,
                      const emxArray_real_T *layers, real_T ssubs, real_T res,
                      emxArray_real_T *reflectivity,
                      emxArray_real_T *Simulation)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T *b_simRef;
  emxArray_real_T *firstSection;
  emxArray_real_T *lastSection;
  emxArray_real_T *simRef;
  emxArray_real_T *simResolData;
  emxArray_real_T *simXdata;
  emxArray_real_T *slds;
  creal_T MI[4];
  creal_T N[4];
  creal_T b_MI[4];
  creal_T N_tmp;
  creal_T pair;
  creal_T pimag;
  creal_T psub;
  creal_T rij;
  real_T ar;
  real_T ar_tmp;
  real_T bim;
  real_T blast_im;
  real_T blast_re;
  real_T brm;
  real_T d;
  real_T d1;
  real_T nrepeats;
  real_T pair_re;
  real_T psub_tmp_tmp;
  real_T re;
  real_T rough;
  real_T snair;
  real_T snlay;
  real_T snsub;
  real_T step;
  int32_T b_layers;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T simLimits;
  uint32_T splits_idx_1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (1 > this_data->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[1], &ni_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  emxInit_real_T(sp, &slds, 2, &fl_emlrtRTEI, true);
  if (layers->size[0] == 0) {
    i = slds->size[0] * slds->size[1];
    slds->size[0] = 1;
    slds->size[1] = 3;
    emxEnsureCapacity_real_T(sp, slds, i, &fl_emlrtRTEI);
    slds->data[0] = 0.0;
    slds->data[1] = nbairs;
    slds->data[2] = 0.0;
    b_layers = -1;
  } else {
    loop_ub = layers->size[0];
    i = slds->size[0] * slds->size[1];
    slds->size[0] = layers->size[0];
    slds->size[1] = 3;
    emxEnsureCapacity_real_T(sp, slds, i, &gl_emlrtRTEI);
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        slds->data[i1 + slds->size[0] * i] =
            layers->data[i1 + layers->size[0] * i];
      }
    }
    b_layers = layers->size[0] - 1;
  }
  i = simLimits_size[0] * simLimits_size[1];
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &mi_emlrtBCI, (emlrtCTX)sp);
  }
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &li_emlrtBCI, (emlrtCTX)sp);
  }
  if (1 > this_data->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[1], &ki_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (1 > this_data->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &ji_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  emxInit_real_T(sp, &firstSection, 2, &il_emlrtRTEI, true);
  if (simLimits_data[0] < this_data->data[0]) {
    if (2 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, this_data->size[0], &ii_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (1 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &hi_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    step = this_data->data[1] - this_data->data[0];
    if (1 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &gi_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    st.site = &ng_emlrtRSI;
    snlay = this_data->data[0] - step;
    if (muDoubleScalarIsNaN(simLimits_data[0]) || muDoubleScalarIsNaN(step) ||
        muDoubleScalarIsNaN(snlay)) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &il_emlrtRTEI);
      firstSection->data[0] = rtNaN;
    } else if ((step == 0.0) || ((simLimits_data[0] < snlay) && (step < 0.0)) ||
               ((snlay < simLimits_data[0]) && (step > 0.0))) {
      firstSection->size[0] = 1;
      firstSection->size[1] = 0;
    } else if ((muDoubleScalarIsInf(simLimits_data[0]) ||
                muDoubleScalarIsInf(snlay)) &&
               (muDoubleScalarIsInf(step) || (simLimits_data[0] == snlay))) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &il_emlrtRTEI);
      firstSection->data[0] = rtNaN;
    } else if (muDoubleScalarIsInf(step)) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &il_emlrtRTEI);
      firstSection->data[0] = simLimits_data[0];
    } else if ((muDoubleScalarFloor(simLimits_data[0]) == simLimits_data[0]) &&
               (muDoubleScalarFloor(step) == step)) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      loop_ub =
          (int32_T)muDoubleScalarFloor((snlay - simLimits_data[0]) / step);
      firstSection->size[1] = loop_ub + 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &il_emlrtRTEI);
      for (i = 0; i <= loop_ub; i++) {
        firstSection->data[i] = simLimits_data[0] + step * (real_T)i;
      }
    } else {
      b_st.site = &sg_emlrtRSI;
      eml_float_colon(&b_st, simLimits_data[0], step, snlay, firstSection);
    }
  } else {
    firstSection->size[0] = 1;
    firstSection->size[1] = 0;
  }
  if (this_data->size[0] < 1) {
    emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
                                  &oi_emlrtBCI, (emlrtCTX)sp);
  }
  emxInit_real_T(sp, &lastSection, 2, &jl_emlrtRTEI, true);
  if (simLimits_data[1] > this_data->data[this_data->size[0] - 1]) {
    if (this_data->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
                                    &pi_emlrtBCI, (emlrtCTX)sp);
    }
    if ((this_data->size[0] - 1 < 1) ||
        (this_data->size[0] - 1 > this_data->size[0])) {
      emlrtDynamicBoundsCheckR2012b(this_data->size[0] - 1, 1,
                                    this_data->size[0], &qi_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    step = this_data->data[this_data->size[0] - 1] -
           this_data->data[this_data->size[0] - 2];
    st.site = &og_emlrtRSI;
    if (this_data->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
                                    &ri_emlrtBCI, &st);
    }
    snlay = this_data->data[this_data->size[0] - 1] + step;
    if (muDoubleScalarIsNaN(snlay) || muDoubleScalarIsNaN(step) ||
        muDoubleScalarIsNaN(simLimits_data[1])) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &jl_emlrtRTEI);
      lastSection->data[0] = rtNaN;
    } else if ((step == 0.0) || ((snlay < simLimits_data[1]) && (step < 0.0)) ||
               ((simLimits_data[1] < snlay) && (step > 0.0))) {
      lastSection->size[0] = 1;
      lastSection->size[1] = 0;
    } else if ((muDoubleScalarIsInf(snlay) ||
                muDoubleScalarIsInf(simLimits_data[1])) &&
               (muDoubleScalarIsInf(step) || (snlay == simLimits_data[1]))) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &jl_emlrtRTEI);
      lastSection->data[0] = rtNaN;
    } else if (muDoubleScalarIsInf(step)) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &jl_emlrtRTEI);
      lastSection->data[0] = snlay;
    } else if ((muDoubleScalarFloor(snlay) == snlay) &&
               (muDoubleScalarFloor(step) == step)) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      loop_ub =
          (int32_T)muDoubleScalarFloor((simLimits_data[1] - snlay) / step);
      lastSection->size[1] = loop_ub + 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &jl_emlrtRTEI);
      for (i = 0; i <= loop_ub; i++) {
        lastSection->data[i] = snlay + step * (real_T)i;
      }
    } else {
      b_st.site = &sg_emlrtRSI;
      eml_float_colon(&b_st, snlay, step, simLimits_data[1], lastSection);
    }
  } else {
    lastSection->size[0] = 1;
    lastSection->size[1] = 0;
  }
  emxInit_real_T(sp, &simXdata, 1, &hl_emlrtRTEI, true);
  simLimits = firstSection->size[1];
  loop_ub = this_data->size[0];
  i = simXdata->size[0];
  simXdata->size[0] =
      (this_data->size[0] + firstSection->size[1]) + lastSection->size[1];
  emxEnsureCapacity_real_T(sp, simXdata, i, &hl_emlrtRTEI);
  b_loop_ub = firstSection->size[1];
  for (i = 0; i < b_loop_ub; i++) {
    simXdata->data[i] = firstSection->data[i];
  }
  for (i = 0; i < loop_ub; i++) {
    simXdata->data[i + simLimits] = this_data->data[i];
  }
  b_loop_ub = lastSection->size[1];
  for (i = 0; i < b_loop_ub; i++) {
    simXdata->data[(i + simLimits) + loop_ub] = lastSection->data[i];
  }
  splits_idx_1 = (uint32_T)firstSection->size[1] + this_data->size[0];
  i = Simulation->size[0] * Simulation->size[1];
  Simulation->size[0] = simXdata->size[0];
  Simulation->size[1] = 2;
  emxEnsureCapacity_real_T(sp, Simulation, i, &kl_emlrtRTEI);
  loop_ub = simXdata->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    Simulation->data[i] = 0.0;
  }
  emlrtSubAssignSizeCheckR2012b(&simXdata->size[0], 1, &simXdata->size[0], 1,
                                &y_emlrtECI, (emlrtCTX)sp);
  loop_ub = simXdata->size[0];
  for (i = 0; i < loop_ub; i++) {
    Simulation->data[i] = simXdata->data[i];
  }
  emxInit_real_T(sp, &simResolData, 1, &ll_emlrtRTEI, true);
  /*  If we are using data resolutions, then we also need to adjust the length
   */
  /*  of the reolution column. We do thit by just extending with the rosolution
   */
  /*  values at the ends of the curve. */
  i = simResolData->size[0];
  simResolData->size[0] = 1;
  emxEnsureCapacity_real_T(sp, simResolData, i, &ll_emlrtRTEI);
  simResolData->data[0] = 0.0;
  if (res == -1.0) {
    if (4 > this_data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(4, 1, this_data->size[1], &fi_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (1 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &ei_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (this_data->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
                                    &di_emlrtBCI, (emlrtCTX)sp);
    }
    simLimits = firstSection->size[1];
    loop_ub = this_data->size[0];
    i = simResolData->size[0];
    simResolData->size[0] =
        (this_data->size[0] + firstSection->size[1]) + lastSection->size[1];
    emxEnsureCapacity_real_T(sp, simResolData, i, &nl_emlrtRTEI);
    b_loop_ub = firstSection->size[1];
    for (i = 0; i < b_loop_ub; i++) {
      simResolData->data[i] = this_data->data[this_data->size[0] * 3];
    }
    for (i = 0; i < loop_ub; i++) {
      simResolData->data[i + simLimits] =
          this_data->data[i + this_data->size[0] * 3];
    }
    b_loop_ub = lastSection->size[1];
    for (i = 0; i < b_loop_ub; i++) {
      simResolData->data[(i + simLimits) + loop_ub] =
          this_data->data[(this_data->size[0] + this_data->size[0] * 3) - 1];
    }
  }
  emxFree_real_T(&lastSection);
  emxInit_real_T(sp, &simRef, 1, &rl_emlrtRTEI, true);
  nrepeats = repeatLayers[1];
  /*  Single cored over points */
  /*  Calculate reflectivity..... */
  st.site = &pg_emlrtRSI;
  /*  nbair = nbairs(thisCont); */
  /*  nbsub = nbsubs(thisCont); */
  /*  ssub = ssubs(thisCont); */
  /*  nrepeats = nrepeatss(thisCont); */
  /*  resol = resols(thisCont); */
  i = simRef->size[0];
  simRef->size[0] = simXdata->size[0];
  emxEnsureCapacity_real_T(&st, simRef, i, &ml_emlrtRTEI);
  /* pi = 3.141592653589; */
  snair = 1.0 - nbairs * 0.377451863036739;
  snsub = 1.0 - nbsubs * 0.377451863036739;
  i = simXdata->size[0];
  if (0 <= i - 1) {
    i2 = (int32_T)nrepeats;
    ar_tmp = ssubs * ssubs;
  }
  for (simLimits = 0; simLimits < i; simLimits++) {
    if (simLimits + 1 > simXdata->size[0]) {
      emlrtDynamicBoundsCheckR2012b(simLimits + 1, 1, simXdata->size[0],
                                    &ai_emlrtBCI, &st);
    }
    b_st.site = &vg_emlrtRSI;
    step = simXdata->data[simLimits] * 1.54 / 12.566370614359172;
    if ((step < -1.0) || (step > 1.0)) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &rb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "asin");
    }
    step = muDoubleScalarAsin(step);
    snlay = muDoubleScalarCos(step);
    psub_tmp_tmp = snair * snair * (snlay * snlay);
    snlay = snsub * snsub - psub_tmp_tmp;
    psub.re = snlay;
    psub.im = snlay * 0.0;
    c_sqrt(&psub);
    snlay = snair * muDoubleScalarSin(step);
    pair.re = snlay;
    pair.im = snlay * 0.0;
    blast_re = 0.0;
    blast_im = 0.0;
    MI[0].re = 1.0;
    MI[0].im = 0.0;
    MI[3].re = 1.0;
    MI[3].im = 0.0;
    MI[2].re = 0.0;
    MI[2].im = 0.0;
    MI[1].re = 0.0;
    MI[1].im = 0.0;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, nrepeats, mxDOUBLE_CLASS,
                                  (int32_T)nrepeats, &sb_emlrtRTEI, &st);
    for (b_loop_ub = 0; b_loop_ub < i2; b_loop_ub++) {
      for (loop_ub = 0; loop_ub <= b_layers; loop_ub++) {
        if (loop_ub + 1 > slds->size[0]) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, slds->size[0],
                                        &yh_emlrtBCI, &st);
        }
        rough = slds->data[loop_ub + slds->size[0] * 2];
        snlay = 1.0 - slds->data[loop_ub + slds->size[0]] * 0.377451863036739;
        step = snlay * snlay - psub_tmp_tmp;
        pimag.re = step;
        pimag.im = step * 0.0;
        c_sqrt(&pimag);
        re = -78.956835208714864 * pair.re;
        snlay = -78.956835208714864 * pair.im;
        step = rough * rough;
        ar = (re * pimag.re - snlay * pimag.im) * step;
        rough = (re * pimag.im + snlay * pimag.re) * step;
        if (rough == 0.0) {
          rij.re = ar / 2.3716;
          rij.im = 0.0;
        } else if (ar == 0.0) {
          rij.re = 0.0;
          rij.im = rough / 2.3716;
        } else {
          rij.re = ar / 2.3716;
          rij.im = rough / 2.3716;
        }
        b_exp(&rij);
        ar = pair.re - pimag.re;
        rough = pair.im - pimag.im;
        step = pair.re + pimag.re;
        snlay = pair.im + pimag.im;
        if (snlay == 0.0) {
          if (rough == 0.0) {
            pair_re = ar / step;
            step = 0.0;
          } else if (ar == 0.0) {
            pair_re = 0.0;
            step = rough / step;
          } else {
            pair_re = ar / step;
            step = rough / step;
          }
        } else if (step == 0.0) {
          if (ar == 0.0) {
            pair_re = rough / snlay;
            step = 0.0;
          } else if (rough == 0.0) {
            pair_re = 0.0;
            step = -(ar / snlay);
          } else {
            pair_re = rough / snlay;
            step = -(ar / snlay);
          }
        } else {
          brm = muDoubleScalarAbs(step);
          bim = muDoubleScalarAbs(snlay);
          if (brm > bim) {
            bim = snlay / step;
            step += bim * snlay;
            pair_re = (ar + bim * rough) / step;
            step = (rough - bim * ar) / step;
          } else if (bim == brm) {
            if (step > 0.0) {
              bim = 0.5;
            } else {
              bim = -0.5;
            }
            if (snlay > 0.0) {
              step = 0.5;
            } else {
              step = -0.5;
            }
            pair_re = (ar * bim + rough * step) / brm;
            step = (rough * bim - ar * step) / brm;
          } else {
            bim = step / snlay;
            step = snlay + bim * step;
            pair_re = (bim * ar + rough) / step;
            step = (bim * rough - ar) / step;
          }
        }
        re = pair_re * rij.re - step * rij.im;
        snlay = pair_re * rij.im + step * rij.re;
        N_tmp.re = blast_re * 0.0 - blast_im;
        N_tmp.im = blast_re + blast_im * 0.0;
        b_exp(&N_tmp);
        pair.re = -blast_re * 0.0 - (-blast_im);
        pair.im = -blast_re + -blast_im * 0.0;
        b_exp(&pair);
        ar = re * pair.re - snlay * pair.im;
        d = re * pair.im + snlay * pair.re;
        N[3] = pair;
        d1 = re * N_tmp.re - snlay * N_tmp.im;
        step = re * N_tmp.im + snlay * N_tmp.re;
        pair = pimag;
        blast_re = 4.0799904592075231 * slds->data[loop_ub] * pimag.re;
        blast_im = 4.0799904592075231 * slds->data[loop_ub] * pimag.im;
        snlay = N[3].re;
        rough = N[3].im;
        for (i1 = 0; i1 < 2; i1++) {
          re = MI[i1].re;
          bim = MI[i1].im;
          pair_re = MI[i1 + 2].re;
          brm = MI[i1 + 2].im;
          b_MI[i1].re =
              (re * N_tmp.re - bim * N_tmp.im) + (pair_re * ar - brm * d);
          b_MI[i1].im =
              (re * N_tmp.im + bim * N_tmp.re) + (pair_re * d + brm * ar);
          b_MI[i1 + 2].re =
              (re * d1 - bim * step) + (pair_re * snlay - brm * rough);
          b_MI[i1 + 2].im =
              (re * step + bim * d1) + (pair_re * rough + brm * snlay);
        }
        memcpy(&MI[0], &b_MI[0], 4U * sizeof(creal_T));
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    re = -78.956835208714864 * pair.re;
    snlay = -78.956835208714864 * pair.im;
    ar = (re * psub.re - snlay * psub.im) * ar_tmp;
    rough = (re * psub.im + snlay * psub.re) * ar_tmp;
    if (rough == 0.0) {
      rij.re = ar / 2.3716;
      rij.im = 0.0;
    } else if (ar == 0.0) {
      rij.re = 0.0;
      rij.im = rough / 2.3716;
    } else {
      rij.re = ar / 2.3716;
      rij.im = rough / 2.3716;
    }
    b_exp(&rij);
    ar = pair.re - psub.re;
    rough = pair.im - psub.im;
    step = pair.re + psub.re;
    snlay = pair.im + psub.im;
    if (snlay == 0.0) {
      if (rough == 0.0) {
        pair_re = ar / step;
        step = 0.0;
      } else if (ar == 0.0) {
        pair_re = 0.0;
        step = rough / step;
      } else {
        pair_re = ar / step;
        step = rough / step;
      }
    } else if (step == 0.0) {
      if (ar == 0.0) {
        pair_re = rough / snlay;
        step = 0.0;
      } else if (rough == 0.0) {
        pair_re = 0.0;
        step = -(ar / snlay);
      } else {
        pair_re = rough / snlay;
        step = -(ar / snlay);
      }
    } else {
      brm = muDoubleScalarAbs(step);
      bim = muDoubleScalarAbs(snlay);
      if (brm > bim) {
        bim = snlay / step;
        step += bim * snlay;
        pair_re = (ar + bim * rough) / step;
        step = (rough - bim * ar) / step;
      } else if (bim == brm) {
        if (step > 0.0) {
          bim = 0.5;
        } else {
          bim = -0.5;
        }
        if (snlay > 0.0) {
          step = 0.5;
        } else {
          step = -0.5;
        }
        pair_re = (ar * bim + rough * step) / brm;
        step = (rough * bim - ar * step) / brm;
      } else {
        bim = step / snlay;
        step = snlay + bim * step;
        pair_re = (bim * ar + rough) / step;
        step = (bim * rough - ar) / step;
      }
    }
    re = pair_re * rij.re - step * rij.im;
    snlay = pair_re * rij.im + step * rij.re;
    N_tmp.re = blast_re * 0.0 - blast_im;
    N_tmp.im = blast_re + blast_im * 0.0;
    b_exp(&N_tmp);
    pair.re = -blast_re * 0.0 - (-blast_im);
    pair.im = -blast_re + -blast_im * 0.0;
    b_exp(&pair);
    ar = re * pair.re - snlay * pair.im;
    d = re * pair.im + snlay * pair.re;
    d1 = re * N_tmp.re - snlay * N_tmp.im;
    step = re * N_tmp.im + snlay * N_tmp.re;
    for (i1 = 0; i1 < 2; i1++) {
      snlay = MI[i1].re;
      rough = MI[i1].im;
      re = MI[i1 + 2].re;
      bim = MI[i1 + 2].im;
      b_MI[i1].re = (snlay * N_tmp.re - rough * N_tmp.im) + (re * ar - bim * d);
      b_MI[i1].im = (snlay * N_tmp.im + rough * N_tmp.re) + (re * d + bim * ar);
      b_MI[i1 + 2].re =
          (snlay * d1 - rough * step) + (re * pair.re - bim * pair.im);
      b_MI[i1 + 2].im =
          (snlay * step + rough * d1) + (re * pair.im + bim * pair.re);
    }
    rough = b_MI[1].re * b_MI[1].re - b_MI[1].im * -b_MI[1].im;
    re = b_MI[1].re * -b_MI[1].im + b_MI[1].im * b_MI[1].re;
    step = b_MI[0].re * b_MI[0].re - b_MI[0].im * -b_MI[0].im;
    snlay = b_MI[0].re * -b_MI[0].im + b_MI[0].im * b_MI[0].re;
    if (snlay == 0.0) {
      if (re == 0.0) {
        pair.re = rough / step;
        pair.im = 0.0;
      } else if (rough == 0.0) {
        pair.re = 0.0;
        pair.im = re / step;
      } else {
        pair.re = rough / step;
        pair.im = re / step;
      }
    } else if (step == 0.0) {
      if (rough == 0.0) {
        pair.re = re / snlay;
        pair.im = 0.0;
      } else if (re == 0.0) {
        pair.re = 0.0;
        pair.im = -(rough / snlay);
      } else {
        pair.re = re / snlay;
        pair.im = -(rough / snlay);
      }
    } else {
      brm = muDoubleScalarAbs(step);
      bim = muDoubleScalarAbs(snlay);
      if (brm > bim) {
        bim = snlay / step;
        step += bim * snlay;
        pair.re = (rough + bim * re) / step;
        pair.im = (re - bim * rough) / step;
      } else if (bim == brm) {
        if (step > 0.0) {
          bim = 0.5;
        } else {
          bim = -0.5;
        }
        if (snlay > 0.0) {
          step = 0.5;
        } else {
          step = -0.5;
        }
        pair.re = (rough * bim + re * step) / brm;
        pair.im = (re * bim - rough * step) / brm;
      } else {
        bim = step / snlay;
        step = snlay + bim * step;
        pair.re = (bim * rough + re) / step;
        pair.im = (bim * re - rough) / step;
      }
    }
    if (simLimits + 1 > simRef->size[0]) {
      emlrtDynamicBoundsCheckR2012b(simLimits + 1, 1, simRef->size[0],
                                    &si_emlrtBCI, &st);
    }
    simRef->data[simLimits] = muDoubleScalarHypot(pair.re, pair.im);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  emxFree_real_T(&slds);
  /*  Apply resolution correction... */
  emxInit_real_T(sp, &b_simRef, 1, &ol_emlrtRTEI, true);
  if (res == -1.0) {
    i = b_simRef->size[0];
    b_simRef->size[0] = simRef->size[0];
    emxEnsureCapacity_real_T(sp, b_simRef, i, &pl_emlrtRTEI);
    loop_ub = simRef->size[0] - 1;
    for (i = 0; i <= loop_ub; i++) {
      b_simRef->data[i] = simRef->data[i];
    }
    st.site = &qg_emlrtRSI;
    data_resolution_polly(&st, simXdata, b_simRef, simResolData,
                          simXdata->size[0], simRef);
  } else {
    i = b_simRef->size[0];
    b_simRef->size[0] = simRef->size[0];
    emxEnsureCapacity_real_T(sp, b_simRef, i, &ol_emlrtRTEI);
    loop_ub = simRef->size[0] - 1;
    for (i = 0; i <= loop_ub; i++) {
      b_simRef->data[i] = simRef->data[i];
    }
    st.site = &rg_emlrtRSI;
    resolution_polly(&st, simXdata, b_simRef, res, simXdata->size[0], simRef);
  }
  emxFree_real_T(&b_simRef);
  emxFree_real_T(&simResolData);
  emxFree_real_T(&simXdata);
  emlrtSubAssignSizeCheckR2012b(&Simulation->size[0], 1, &simRef->size[0], 1,
                                &x_emlrtECI, (emlrtCTX)sp);
  loop_ub = simRef->size[0];
  for (i = 0; i < loop_ub; i++) {
    Simulation->data[i + Simulation->size[0]] = simRef->data[i];
  }
  emxFree_real_T(&simRef);
  if (firstSection->size[1] + 1U > splits_idx_1) {
    i = 0;
    i1 = 0;
  } else {
    if (((int32_T)(firstSection->size[1] + 1U) < 1) ||
        ((int32_T)(firstSection->size[1] + 1U) > Simulation->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(firstSection->size[1] + 1U), 1,
                                    Simulation->size[0], &ci_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i = firstSection->size[1];
    if (((int32_T)splits_idx_1 < 1) ||
        ((int32_T)splits_idx_1 > Simulation->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)splits_idx_1, 1,
                                    Simulation->size[0], &bi_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = (int32_T)splits_idx_1;
  }
  emxFree_real_T(&firstSection);
  loop_ub = i1 - i;
  i1 = reflectivity->size[0] * reflectivity->size[1];
  reflectivity->size[0] = loop_ub;
  reflectivity->size[1] = 2;
  emxEnsureCapacity_real_T(sp, reflectivity, i1, &ql_emlrtRTEI);
  for (i1 = 0; i1 < 2; i1++) {
    for (i2 = 0; i2 < loop_ub; i2++) {
      reflectivity->data[i2 + reflectivity->size[0] * i1] =
          Simulation->data[(i + i2) + Simulation->size[0] * i1];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (callReflectivity.c) */
