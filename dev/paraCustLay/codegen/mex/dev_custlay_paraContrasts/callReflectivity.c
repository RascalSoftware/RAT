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
#include "abeles_single.h"
#include "colon.h"
#include "dev_custlay_paraContrasts_data.h"
#include "dev_custlay_paraContrasts_emxutil.h"
#include "dev_custlay_paraContrasts_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo xf_emlrtRSI = {
    21,                 /* lineNo */
    "callReflectivity", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pathName */
};

static emlrtRSInfo yf_emlrtRSI = {
    28,                 /* lineNo */
    "callReflectivity", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pathName */
};

static emlrtRSInfo ag_emlrtRSI = {
    79,                 /* lineNo */
    "callReflectivity", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pathName */
};

static emlrtRSInfo bg_emlrtRSI = {
    83,                 /* lineNo */
    "callReflectivity", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pathName */
};

static emlrtRSInfo cg_emlrtRSI = {
    85,                 /* lineNo */
    "callReflectivity", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pathName */
};

static emlrtRSInfo dg_emlrtRSI = {
    117,     /* lineNo */
    "colon", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/ops/colon.m" /* pathName
                                                                          */
};

static emlrtRSInfo jg_emlrtRSI = {
    27,                      /* lineNo */
    "data_resolution_polly", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/data_resolution_polly.m" /* pathName
                                                                    */
};

static emlrtRSInfo kg_emlrtRSI = {
    29,                 /* lineNo */
    "resolution_polly", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/resolution_polly.m" /* pathName */
};

static emlrtRTEInfo s_emlrtRTEI = {
    26,                      /* lineNo */
    13,                      /* colNo */
    "data_resolution_polly", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/data_resolution_polly.m" /* pName */
};

static emlrtBCInfo re_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    9,                       /* lineNo */
    19,                      /* colNo */
    "resData",               /* aName */
    "data_resolution_polly", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/data_resolution_polly.m", /* pName */
    0 /* checkKind */
};

static emlrtRTEInfo t_emlrtRTEI = {
    28,                 /* lineNo */
    13,                 /* colNo */
    "resolution_polly", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/resolution_polly.m" /* pName */
};

static emlrtBCInfo se_emlrtBCI = {
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

static emlrtBCInfo te_emlrtBCI = {
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

static emlrtECInfo ab_emlrtECI = {
    -1,                 /* nDims */
    90,                 /* lineNo */
    1,                  /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtECInfo bb_emlrtECI = {
    -1,                 /* nDims */
    37,                 /* lineNo */
    1,                  /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtBCInfo ue_emlrtBCI = {
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

static emlrtBCInfo ve_emlrtBCI = {
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

static emlrtBCInfo we_emlrtBCI = {
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

static emlrtBCInfo xe_emlrtBCI = {
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

static emlrtBCInfo ye_emlrtBCI = {
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

static emlrtBCInfo af_emlrtBCI = {
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

static emlrtBCInfo bf_emlrtBCI = {
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

static emlrtBCInfo cf_emlrtBCI = {
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

static emlrtBCInfo df_emlrtBCI = {
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

static emlrtBCInfo ef_emlrtBCI = {
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

static emlrtBCInfo ff_emlrtBCI = {
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

static emlrtBCInfo gf_emlrtBCI = {
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

static emlrtBCInfo hf_emlrtBCI = {
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

static emlrtBCInfo if_emlrtBCI = {
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

static emlrtBCInfo jf_emlrtBCI = {
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

static emlrtBCInfo kf_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    13,                 /* lineNo */
    5,                  /* colNo */
    "dummydata",        /* aName */
    "resolution_polly", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/resolution_polly.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo lf_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    12,                      /* lineNo */
    5,                       /* colNo */
    "dummydata",             /* aName */
    "data_resolution_polly", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/data_resolution_polly.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo mf_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    34,                 /* lineNo */
    24,                 /* colNo */
    "dummydata",        /* aName */
    "resolution_polly", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/resolution_polly.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo nf_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    32,                      /* lineNo */
    24,                      /* colNo */
    "dummydata",             /* aName */
    "data_resolution_polly", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/data_resolution_polly.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo of_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    29,                 /* lineNo */
    22,                 /* colNo */
    "xdata",            /* aName */
    "resolution_polly", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/resolution_polly.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo pf_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    29,                 /* lineNo */
    33,                 /* colNo */
    "xdata",            /* aName */
    "resolution_polly", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/resolution_polly.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo qf_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    29,                 /* lineNo */
    48,                 /* colNo */
    "xdata",            /* aName */
    "resolution_polly", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/resolution_polly.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo rf_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    27,                      /* lineNo */
    22,                      /* colNo */
    "xdata",                 /* aName */
    "data_resolution_polly", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/data_resolution_polly.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo sf_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    27,                      /* lineNo */
    33,                      /* colNo */
    "xdata",                 /* aName */
    "data_resolution_polly", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/data_resolution_polly.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo tf_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    27,                      /* lineNo */
    48,                      /* colNo */
    "xdata",                 /* aName */
    "data_resolution_polly", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/data_resolution_polly.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo uf_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    31,                 /* lineNo */
    24,                 /* colNo */
    "dummydata",        /* aName */
    "resolution_polly", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/resolution_polly.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo vf_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    31,                 /* lineNo */
    39,                 /* colNo */
    "dummyref",         /* aName */
    "resolution_polly", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/resolution_polly.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo wf_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    31,                 /* lineNo */
    9,                  /* colNo */
    "dummydata",        /* aName */
    "resolution_polly", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/resolution_polly.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo xf_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    29,                      /* lineNo */
    24,                      /* colNo */
    "dummydata",             /* aName */
    "data_resolution_polly", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/data_resolution_polly.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo yf_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    29,                      /* lineNo */
    39,                      /* colNo */
    "dummyref",              /* aName */
    "data_resolution_polly", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/data_resolution_polly.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ag_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    29,                      /* lineNo */
    9,                       /* colNo */
    "dummydata",             /* aName */
    "data_resolution_polly", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/data_resolution_polly.m", /* pName */
    0 /* checkKind */
};

static emlrtRTEInfo uf_emlrtRTEI = {
    7,                  /* lineNo */
    5,                  /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo vf_emlrtRTEI = {
    10,                 /* lineNo */
    5,                  /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo wf_emlrtRTEI = {
    33,                 /* lineNo */
    1,                  /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo xf_emlrtRTEI = {
    21,                 /* lineNo */
    5,                  /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo yf_emlrtRTEI = {
    28,                 /* lineNo */
    5,                  /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo ag_emlrtRTEI = {
    36,                 /* lineNo */
    1,                  /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo bg_emlrtRTEI = {
    42,                 /* lineNo */
    1,                  /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo cg_emlrtRTEI = {
    7,                  /* lineNo */
    1,                  /* colNo */
    "resolution_polly", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/resolution_polly.m" /* pName */
};

static emlrtRTEInfo dg_emlrtRTEI = {
    5,                       /* lineNo */
    1,                       /* colNo */
    "data_resolution_polly", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "Resolution_Functions/Simple_Gaussian/data_resolution_polly.m" /* pName */
};

static emlrtRTEInfo eg_emlrtRTEI = {
    49,                 /* lineNo */
    5,                  /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo fg_emlrtRTEI = {
    85,                 /* lineNo */
    21,                 /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo gg_emlrtRTEI = {
    83,                 /* lineNo */
    21,                 /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo hg_emlrtRTEI = {
    91,                 /* lineNo */
    1,                  /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

static emlrtRTEInfo ig_emlrtRTEI = {
    61,                 /* lineNo */
    17,                 /* colNo */
    "callReflectivity", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "callReflectivity.m" /* pName */
};

/* Function Definitions */
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
  emxArray_real_T *dummydata;
  emxArray_real_T *firstSection;
  emxArray_real_T *lastSection;
  emxArray_real_T *simRef;
  emxArray_real_T *simResolData;
  emxArray_real_T *simXdata;
  emxArray_real_T *slds;
  real_T g;
  real_T step;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T ilow;
  int32_T lays;
  int32_T loop_ub;
  uint32_T splits_idx_1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (1 > this_data->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[1], &ff_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  emxInit_real_T(sp, &slds, 2, &uf_emlrtRTEI, true);
  if (layers->size[0] == 0) {
    i = slds->size[0] * slds->size[1];
    slds->size[0] = 1;
    slds->size[1] = 3;
    emxEnsureCapacity_real_T(sp, slds, i, &uf_emlrtRTEI);
    slds->data[0] = 0.0;
    slds->data[1] = nbairs;
    slds->data[2] = 0.0;
    lays = 0;
  } else {
    loop_ub = layers->size[0];
    i = slds->size[0] * slds->size[1];
    slds->size[0] = layers->size[0];
    slds->size[1] = 3;
    emxEnsureCapacity_real_T(sp, slds, i, &vf_emlrtRTEI);
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        slds->data[i1 + slds->size[0] * i] =
            layers->data[i1 + layers->size[0] * i];
      }
    }
    lays = layers->size[0];
  }
  i = simLimits_size[0] * simLimits_size[1];
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &ef_emlrtBCI, (emlrtCTX)sp);
  }
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &df_emlrtBCI, (emlrtCTX)sp);
  }
  if (1 > this_data->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[1], &cf_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (1 > this_data->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &bf_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  emxInit_real_T(sp, &firstSection, 2, &xf_emlrtRTEI, true);
  if (simLimits_data[0] < this_data->data[0]) {
    if (2 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, this_data->size[0], &af_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (1 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &ye_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    step = this_data->data[1] - this_data->data[0];
    if (1 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &xe_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    st.site = &xf_emlrtRSI;
    g = this_data->data[0] - step;
    if (muDoubleScalarIsNaN(simLimits_data[0]) || muDoubleScalarIsNaN(step) ||
        muDoubleScalarIsNaN(g)) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &xf_emlrtRTEI);
      firstSection->data[0] = rtNaN;
    } else if ((step == 0.0) || ((simLimits_data[0] < g) && (step < 0.0)) ||
               ((g < simLimits_data[0]) && (step > 0.0))) {
      firstSection->size[0] = 1;
      firstSection->size[1] = 0;
    } else if ((muDoubleScalarIsInf(simLimits_data[0]) ||
                muDoubleScalarIsInf(g)) &&
               (muDoubleScalarIsInf(step) || (simLimits_data[0] == g))) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &xf_emlrtRTEI);
      firstSection->data[0] = rtNaN;
    } else if (muDoubleScalarIsInf(step)) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      firstSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &xf_emlrtRTEI);
      firstSection->data[0] = simLimits_data[0];
    } else if ((muDoubleScalarFloor(simLimits_data[0]) == simLimits_data[0]) &&
               (muDoubleScalarFloor(step) == step)) {
      i = firstSection->size[0] * firstSection->size[1];
      firstSection->size[0] = 1;
      loop_ub = (int32_T)muDoubleScalarFloor((g - simLimits_data[0]) / step);
      firstSection->size[1] = loop_ub + 1;
      emxEnsureCapacity_real_T(&st, firstSection, i, &xf_emlrtRTEI);
      for (i = 0; i <= loop_ub; i++) {
        firstSection->data[i] = simLimits_data[0] + step * (real_T)i;
      }
    } else {
      b_st.site = &dg_emlrtRSI;
      eml_float_colon(&b_st, simLimits_data[0], step, g, firstSection);
    }
  } else {
    firstSection->size[0] = 1;
    firstSection->size[1] = 0;
  }
  if (this_data->size[0] < 1) {
    emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
                                  &gf_emlrtBCI, (emlrtCTX)sp);
  }
  emxInit_real_T(sp, &lastSection, 2, &yf_emlrtRTEI, true);
  if (simLimits_data[1] > this_data->data[this_data->size[0] - 1]) {
    if (this_data->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
                                    &hf_emlrtBCI, (emlrtCTX)sp);
    }
    if ((this_data->size[0] - 1 < 1) ||
        (this_data->size[0] - 1 > this_data->size[0])) {
      emlrtDynamicBoundsCheckR2012b(this_data->size[0] - 1, 1,
                                    this_data->size[0], &if_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    step = this_data->data[this_data->size[0] - 1] -
           this_data->data[this_data->size[0] - 2];
    st.site = &yf_emlrtRSI;
    if (this_data->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
                                    &jf_emlrtBCI, &st);
    }
    g = this_data->data[this_data->size[0] - 1] + step;
    if (muDoubleScalarIsNaN(g) || muDoubleScalarIsNaN(step) ||
        muDoubleScalarIsNaN(simLimits_data[1])) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &yf_emlrtRTEI);
      lastSection->data[0] = rtNaN;
    } else if ((step == 0.0) || ((g < simLimits_data[1]) && (step < 0.0)) ||
               ((simLimits_data[1] < g) && (step > 0.0))) {
      lastSection->size[0] = 1;
      lastSection->size[1] = 0;
    } else if ((muDoubleScalarIsInf(g) ||
                muDoubleScalarIsInf(simLimits_data[1])) &&
               (muDoubleScalarIsInf(step) || (g == simLimits_data[1]))) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &yf_emlrtRTEI);
      lastSection->data[0] = rtNaN;
    } else if (muDoubleScalarIsInf(step)) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      lastSection->size[1] = 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &yf_emlrtRTEI);
      lastSection->data[0] = g;
    } else if ((muDoubleScalarFloor(g) == g) &&
               (muDoubleScalarFloor(step) == step)) {
      i = lastSection->size[0] * lastSection->size[1];
      lastSection->size[0] = 1;
      loop_ub = (int32_T)muDoubleScalarFloor((simLimits_data[1] - g) / step);
      lastSection->size[1] = loop_ub + 1;
      emxEnsureCapacity_real_T(&st, lastSection, i, &yf_emlrtRTEI);
      for (i = 0; i <= loop_ub; i++) {
        lastSection->data[i] = g + step * (real_T)i;
      }
    } else {
      b_st.site = &dg_emlrtRSI;
      eml_float_colon(&b_st, g, step, simLimits_data[1], lastSection);
    }
  } else {
    lastSection->size[0] = 1;
    lastSection->size[1] = 0;
  }
  emxInit_real_T(sp, &simXdata, 1, &wf_emlrtRTEI, true);
  ilow = firstSection->size[1];
  loop_ub = this_data->size[0];
  i = simXdata->size[0];
  simXdata->size[0] =
      (this_data->size[0] + firstSection->size[1]) + lastSection->size[1];
  emxEnsureCapacity_real_T(sp, simXdata, i, &wf_emlrtRTEI);
  b_loop_ub = firstSection->size[1];
  for (i = 0; i < b_loop_ub; i++) {
    simXdata->data[i] = firstSection->data[i];
  }
  for (i = 0; i < loop_ub; i++) {
    simXdata->data[i + ilow] = this_data->data[i];
  }
  b_loop_ub = lastSection->size[1];
  for (i = 0; i < b_loop_ub; i++) {
    simXdata->data[(i + ilow) + loop_ub] = lastSection->data[i];
  }
  splits_idx_1 = (uint32_T)firstSection->size[1] + this_data->size[0];
  i = Simulation->size[0] * Simulation->size[1];
  Simulation->size[0] = simXdata->size[0];
  Simulation->size[1] = 2;
  emxEnsureCapacity_real_T(sp, Simulation, i, &ag_emlrtRTEI);
  loop_ub = simXdata->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    Simulation->data[i] = 0.0;
  }
  emlrtSubAssignSizeCheckR2012b(&simXdata->size[0], 1, &simXdata->size[0], 1,
                                &bb_emlrtECI, (emlrtCTX)sp);
  loop_ub = simXdata->size[0];
  for (i = 0; i < loop_ub; i++) {
    Simulation->data[i] = simXdata->data[i];
  }
  emxInit_real_T(sp, &simResolData, 1, &bg_emlrtRTEI, true);
  /*  If we are using data resolutions, then we also need to adjust the length
   */
  /*  of the reolution column. We do thit by just extending with the rosolution
   */
  /*  values at the ends of the curve. */
  i = simResolData->size[0];
  simResolData->size[0] = 1;
  emxEnsureCapacity_real_T(sp, simResolData, i, &bg_emlrtRTEI);
  simResolData->data[0] = 0.0;
  if (res == -1.0) {
    if (4 > this_data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(4, 1, this_data->size[1], &we_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (1 > this_data->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, this_data->size[0], &ve_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (this_data->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(this_data->size[0], 1, this_data->size[0],
                                    &ue_emlrtBCI, (emlrtCTX)sp);
    }
    ilow = firstSection->size[1];
    loop_ub = this_data->size[0];
    i = simResolData->size[0];
    simResolData->size[0] =
        (this_data->size[0] + firstSection->size[1]) + lastSection->size[1];
    emxEnsureCapacity_real_T(sp, simResolData, i, &eg_emlrtRTEI);
    b_loop_ub = firstSection->size[1];
    for (i = 0; i < b_loop_ub; i++) {
      simResolData->data[i] = this_data->data[this_data->size[0] * 3];
    }
    for (i = 0; i < loop_ub; i++) {
      simResolData->data[i + ilow] =
          this_data->data[i + this_data->size[0] * 3];
    }
    b_loop_ub = lastSection->size[1];
    for (i = 0; i < b_loop_ub; i++) {
      simResolData->data[(i + ilow) + loop_ub] =
          this_data->data[(this_data->size[0] + this_data->size[0] * 3) - 1];
    }
  }
  emxFree_real_T(&lastSection);
  emxInit_real_T(sp, &simRef, 1, &ig_emlrtRTEI, true);
  /*  Single cored over points */
  /*  Calculate reflectivity..... */
  st.site = &ag_emlrtRSI;
  abeles_single(&st, simXdata, slds, nbairs, nbsubs, repeatLayers[1], ssubs,
                lays, simXdata->size[0], simRef);
  /*  Apply resolution correction... */
  emxFree_real_T(&slds);
  emxInit_real_T(sp, &dummydata, 1, &cg_emlrtRTEI, true);
  if (res == -1.0) {
    st.site = &bg_emlrtRSI;
    b_loop_ub = simXdata->size[0] - 10;
    /*  Apply resolution correction */
    i = dummydata->size[0];
    dummydata->size[0] = simXdata->size[0];
    emxEnsureCapacity_real_T(&st, dummydata, i, &dg_emlrtRTEI);
    loop_ub = simXdata->size[0];
    for (i = 0; i < loop_ub; i++) {
      dummydata->data[i] = 0.0;
    }
    i = simXdata->size[0];
    for (loop_ub = 0; loop_ub < i; loop_ub++) {
      if (loop_ub + 1 > simResolData->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, simResolData->size[0],
                                      &re_emlrtBCI, &st);
      }
      step = 0.0;
      if (loop_ub + 1 > dummydata->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, dummydata->size[0],
                                      &lf_emlrtBCI, &st);
      }
      dummydata->data[loop_ub] = 0.0;
      if (loop_ub + 1 > 10) {
        ilow = -10;
      } else {
        ilow = -loop_ub;
      }
      if (loop_ub + 1 < b_loop_ub) {
        lays = 1;
      } else {
        lays = b_loop_ub - loop_ub;
      }
      i1 = (lays - ilow) + 9;
      emlrtForLoopVectorCheckR2021a(ilow, 1.0, lays + 9, mxDOUBLE_CLASS, i1 + 1,
                                    &s_emlrtRTEI, &st);
      for (lays = 0; lays <= i1; lays++) {
        b_st.site = &jg_emlrtRSI;
        i2 = ((loop_ub + ilow) + lays) + 1;
        if ((i2 < 1) || (i2 > simXdata->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, simXdata->size[0], &rf_emlrtBCI,
                                        &b_st);
        }
        if (loop_ub + 1 > simXdata->size[0]) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, simXdata->size[0],
                                        &sf_emlrtBCI, &b_st);
        }
        if (loop_ub + 1 > simXdata->size[0]) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, simXdata->size[0],
                                        &tf_emlrtBCI, &b_st);
        }
        g = (simXdata->data[i2 - 1] - simXdata->data[loop_ub]) /
            (simResolData->data[loop_ub] * simXdata->data[loop_ub]);
        g = muDoubleScalarExp(-(g * g));
        step += g;
        if (loop_ub + 1 > dummydata->size[0]) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, dummydata->size[0],
                                        &xf_emlrtBCI, &st);
        }
        if (i2 > simRef->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, simRef->size[0], &yf_emlrtBCI,
                                        &st);
        }
        if (loop_ub + 1 > dummydata->size[0]) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, dummydata->size[0],
                                        &ag_emlrtBCI, &st);
        }
        dummydata->data[loop_ub] += simRef->data[i2 - 1] * g;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }
      if (step != 0.0) {
        if (loop_ub + 1 > dummydata->size[0]) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, dummydata->size[0],
                                        &nf_emlrtBCI, &st);
        }
        dummydata->data[loop_ub] /= step;
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    i = simRef->size[0];
    simRef->size[0] = dummydata->size[0];
    emxEnsureCapacity_real_T(&st, simRef, i, &gg_emlrtRTEI);
    loop_ub = dummydata->size[0];
    for (i = 0; i < loop_ub; i++) {
      simRef->data[i] = dummydata->data[i];
    }
  } else {
    st.site = &cg_emlrtRSI;
    b_loop_ub = simXdata->size[0] - 10;
    /*  Apply resolution correction */
    i = dummydata->size[0];
    dummydata->size[0] = simXdata->size[0];
    emxEnsureCapacity_real_T(&st, dummydata, i, &cg_emlrtRTEI);
    loop_ub = simXdata->size[0];
    for (i = 0; i < loop_ub; i++) {
      dummydata->data[i] = 0.0;
    }
    i = simXdata->size[0];
    for (loop_ub = 0; loop_ub < i; loop_ub++) {
      step = 0.0;
      if (loop_ub + 1 > dummydata->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, dummydata->size[0],
                                      &kf_emlrtBCI, &st);
      }
      dummydata->data[loop_ub] = 0.0;
      if (loop_ub + 1 > 10) {
        ilow = -10;
      } else {
        ilow = -loop_ub;
      }
      if (loop_ub + 1 < b_loop_ub) {
        lays = 1;
      } else {
        lays = b_loop_ub - loop_ub;
      }
      /*     try */
      i1 = (lays - ilow) + 9;
      emlrtForLoopVectorCheckR2021a(ilow, 1.0, lays + 9, mxDOUBLE_CLASS, i1 + 1,
                                    &t_emlrtRTEI, &st);
      for (lays = 0; lays <= i1; lays++) {
        b_st.site = &kg_emlrtRSI;
        i2 = ((loop_ub + ilow) + lays) + 1;
        if ((i2 < 1) || (i2 > simXdata->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, simXdata->size[0], &of_emlrtBCI,
                                        &b_st);
        }
        if (loop_ub + 1 > simXdata->size[0]) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, simXdata->size[0],
                                        &pf_emlrtBCI, &b_st);
        }
        if (loop_ub + 1 > simXdata->size[0]) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, simXdata->size[0],
                                        &qf_emlrtBCI, &b_st);
        }
        g = (simXdata->data[i2 - 1] - simXdata->data[loop_ub]) /
            ((res + 0.0001) * simXdata->data[loop_ub]);
        g = muDoubleScalarExp(-(g * g));
        step += g;
        if (loop_ub + 1 > dummydata->size[0]) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, dummydata->size[0],
                                        &uf_emlrtBCI, &st);
        }
        if (i2 > simRef->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, simRef->size[0], &vf_emlrtBCI,
                                        &st);
        }
        if (loop_ub + 1 > dummydata->size[0]) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, dummydata->size[0],
                                        &wf_emlrtBCI, &st);
        }
        dummydata->data[loop_ub] += simRef->data[i2 - 1] * g;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }
      if (step != 0.0) {
        if (loop_ub + 1 > dummydata->size[0]) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, dummydata->size[0],
                                        &mf_emlrtBCI, &st);
        }
        dummydata->data[loop_ub] /= step;
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    i = simRef->size[0];
    simRef->size[0] = dummydata->size[0];
    emxEnsureCapacity_real_T(&st, simRef, i, &fg_emlrtRTEI);
    loop_ub = dummydata->size[0];
    for (i = 0; i < loop_ub; i++) {
      simRef->data[i] = dummydata->data[i];
    }
  }
  emxFree_real_T(&dummydata);
  emxFree_real_T(&simResolData);
  emxFree_real_T(&simXdata);
  emlrtSubAssignSizeCheckR2012b(&Simulation->size[0], 1, &simRef->size[0], 1,
                                &ab_emlrtECI, (emlrtCTX)sp);
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
                                    Simulation->size[0], &te_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i = firstSection->size[1];
    if (((int32_T)splits_idx_1 < 1) ||
        ((int32_T)splits_idx_1 > Simulation->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)splits_idx_1, 1,
                                    Simulation->size[0], &se_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = (int32_T)splits_idx_1;
  }
  emxFree_real_T(&firstSection);
  loop_ub = i1 - i;
  i1 = reflectivity->size[0] * reflectivity->size[1];
  reflectivity->size[0] = loop_ub;
  reflectivity->size[1] = 2;
  emxEnsureCapacity_real_T(sp, reflectivity, i1, &hg_emlrtRTEI);
  for (i1 = 0; i1 < 2; i1++) {
    for (i2 = 0; i2 < loop_ub; i2++) {
      reflectivity->data[i2 + reflectivity->size[0] * i1] =
          Simulation->data[(i + i2) + Simulation->size[0] * i1];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (callReflectivity.c) */
