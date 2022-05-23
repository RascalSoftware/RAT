/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_layers_core.c
 *
 * Code generation for function 'standardTF_layers_core'
 *
 */

/* Include files */
#include "standardTF_layers_core.h"
#include "adaptive_new.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "dev_custlay_paraContrasts_data.h"
#include "dev_custlay_paraContrasts_emxutil.h"
#include "dev_custlay_paraContrasts_types.h"
#include "find.h"
#include "groupLayers_Mod.h"
#include "makeSLDProfiles.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo d_emlrtRSI = {
    58,                       /* lineNo */
    "standardTF_layers_core", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    69,                       /* lineNo */
    "standardTF_layers_core", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    76,                       /* lineNo */
    "standardTF_layers_core", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    84,                       /* lineNo */
    "standardTF_layers_core", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    88,                       /* lineNo */
    "standardTF_layers_core", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    91,                       /* lineNo */
    "standardTF_layers_core", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    94,                       /* lineNo */
    "standardTF_layers_core", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pathName */
};

static emlrtRSInfo gd_emlrtRSI = {
    20,               /* lineNo */
    "resampleLayers", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m" /* pathName */
};

static emlrtRSInfo vf_emlrtRSI = {
    26,          /* lineNo */
    "shiftdata", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pathName */
};

static emlrtRSInfo wf_emlrtRSI = {
    33,          /* lineNo */
    "shiftdata", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pathName */
};

static emlrtBCInfo lc_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    11,               /* lineNo */
    12,               /* colNo */
    "x",              /* aName */
    "resampleLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    12,               /* lineNo */
    10,               /* colNo */
    "x",              /* aName */
    "resampleLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    29,               /* lineNo */
    18,               /* colNo */
    "newX",           /* aName */
    "resampleLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    30,               /* lineNo */
    18,               /* colNo */
    "newX",           /* aName */
    "resampleLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    31,               /* lineNo */
    18,               /* colNo */
    "newY",           /* aName */
    "resampleLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    32,               /* lineNo */
    18,               /* colNo */
    "newY",           /* aName */
    "resampleLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    41,               /* lineNo */
    12,               /* colNo */
    "layers",         /* aName */
    "resampleLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m", /* pName */
    0                   /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = {
    14,          /* lineNo */
    8,           /* colNo */
    "shiftdata", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    1              /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    19,          /* lineNo */
    16,          /* colNo */
    "data",      /* aName */
    "shiftdata", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtECInfo emlrtECI = {
    -1,          /* nDims */
    19,          /* lineNo */
    9,           /* colNo */
    "shiftdata", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pName */
};

static emlrtBCInfo tc_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    20,          /* lineNo */
    28,          /* colNo */
    "data",      /* aName */
    "shiftdata", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    20,          /* lineNo */
    16,          /* colNo */
    "data",      /* aName */
    "shiftdata", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtECInfo b_emlrtECI = {
    -1,          /* nDims */
    20,          /* lineNo */
    9,           /* colNo */
    "shiftdata", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pName */
};

static emlrtBCInfo vc_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    21,          /* lineNo */
    28,          /* colNo */
    "data",      /* aName */
    "shiftdata", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    21,          /* lineNo */
    16,          /* colNo */
    "data",      /* aName */
    "shiftdata", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtECInfo c_emlrtECI = {
    -1,          /* nDims */
    21,          /* lineNo */
    9,           /* colNo */
    "shiftdata", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pName */
};

static emlrtBCInfo xc_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    26,          /* lineNo */
    32,          /* colNo */
    "data",      /* aName */
    "shiftdata", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    33,          /* lineNo */
    31,          /* colNo */
    "data",      /* aName */
    "shiftdata", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    37,          /* lineNo */
    37,          /* colNo */
    "data",      /* aName */
    "shiftdata", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    40,          /* lineNo */
    29,          /* colNo */
    "data",      /* aName */
    "shiftdata", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    40,          /* lineNo */
    38,          /* colNo */
    "data",      /* aName */
    "shiftdata", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    43,          /* lineNo */
    27,          /* colNo */
    "simLimits", /* aName */
    "shiftdata", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    44,          /* lineNo */
    27,          /* colNo */
    "simLimits", /* aName */
    "shiftdata", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = {
    3,                           /* lineNo */
    8,                           /* colNo */
    "applyBackgroundCorrection", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "applyBackgroundCorrection.m", /* pName */
    1                              /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    10,                          /* lineNo */
    42,                          /* colNo */
    "shifted_dat",               /* aName */
    "applyBackgroundCorrection", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "applyBackgroundCorrection.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    10,                          /* lineNo */
    23,                          /* colNo */
    "shifted_dat",               /* aName */
    "applyBackgroundCorrection", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "applyBackgroundCorrection.m", /* pName */
    0                              /* checkKind */
};

static emlrtECInfo d_emlrtECI = {
    -1,                          /* nDims */
    10,                          /* lineNo */
    9,                           /* colNo */
    "applyBackgroundCorrection", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "applyBackgroundCorrection.m" /* pName */
};

static emlrtDCInfo o_emlrtDCI = {
    25,               /* lineNo */
    16,               /* colNo */
    "resampleLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m", /* pName */
    4                   /* checkKind */
};

static emlrtRTEInfo xb_emlrtRTEI = {
    71,                       /* lineNo */
    5,                        /* colNo */
    "standardTF_layers_core", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = {
    79,                       /* lineNo */
    5,                        /* colNo */
    "standardTF_layers_core", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = {
    80,                       /* lineNo */
    5,                        /* colNo */
    "standardTF_layers_core", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pName */
};

static emlrtRTEInfo bc_emlrtRTEI = {
    84,                       /* lineNo */
    47,                       /* colNo */
    "standardTF_layers_core", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pName */
};

static emlrtRTEInfo cc_emlrtRTEI = {
    25,               /* lineNo */
    1,                /* colNo */
    "resampleLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m" /* pName */
};

static emlrtRTEInfo dc_emlrtRTEI = {
    77,                       /* lineNo */
    5,                        /* colNo */
    "standardTF_layers_core", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = {
    20,          /* lineNo */
    21,          /* colNo */
    "shiftdata", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pName */
};

static emlrtRTEInfo fc_emlrtRTEI = {
    84,                       /* lineNo */
    1,                        /* colNo */
    "standardTF_layers_core", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = {
    21,          /* lineNo */
    21,          /* colNo */
    "shiftdata", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = {
    6,                           /* lineNo */
    9,                           /* colNo */
    "applyBackgroundCorrection", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "applyBackgroundCorrection.m" /* pName */
};

static emlrtRTEInfo ic_emlrtRTEI = {
    7,                           /* lineNo */
    9,                           /* colNo */
    "applyBackgroundCorrection", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "applyBackgroundCorrection.m" /* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = {
    10,                          /* lineNo */
    28,                          /* colNo */
    "applyBackgroundCorrection", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "applyBackgroundCorrection.m" /* pName */
};

static emlrtRTEInfo kc_emlrtRTEI = {
    26,          /* lineNo */
    25,          /* colNo */
    "shiftdata", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pName */
};

static emlrtRTEInfo lc_emlrtRTEI = {
    26,          /* lineNo */
    9,           /* colNo */
    "shiftdata", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pName */
};

static emlrtRTEInfo mc_emlrtRTEI = {
    33,          /* lineNo */
    24,          /* colNo */
    "shiftdata", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pName */
};

static emlrtRTEInfo nc_emlrtRTEI = {
    33,          /* lineNo */
    9,           /* colNo */
    "shiftdata", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pName */
};

static emlrtRTEInfo pc_emlrtRTEI = {
    20,               /* lineNo */
    1,                /* colNo */
    "resampleLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "resampleLayers.m" /* pName */
};

/* Function Definitions */
void standardTF_layers_core(
    const emlrtStack *sp, const emxArray_real_T *contrastLayers, real_T rough,
    const emxArray_char_T *geometry, real_T nba, real_T nbs, real_T resample,
    real_T calcSld, real_T sf, real_T qshift, real_T dataPresent,
    const emxArray_real_T *data, const real_T dataLimits[2],
    const real_T simLimits_data[], const int32_T simLimits_size[2],
    const real_T repeatLayers[2], real_T background, real_T resol,
    real_T backsType, real_T params, const real_T resamPars[2],
    emxArray_real_T *sldProfile, emxArray_real_T *reflect,
    emxArray_real_T *Simul, emxArray_real_T *shifted_dat,
    emxArray_real_T *theseLayers, emxArray_real_T *resamLayers, real_T *chiSq,
    real_T *ssubs)
{
  cell_18 expl_temp;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_boolean_T *c_data;
  emxArray_int32_T *ii;
  emxArray_real_T *b_data;
  emxArray_real_T *b_lowIndex;
  emxArray_real_T *layers;
  real_T b_simXData[300];
  real_T simXData[100];
  real_T b_sldProfile[2];
  real_T delta1;
  real_T delta2;
  real_T thisLayRho;
  int32_T hiIndex;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T lowIndex;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /*    This is the main reflectivity calculation for all Layers models in the
   */
  /*    standard target function.  */
  /*  */
  /*    The function first arranges the  */
  /*    roughness' in the correct order according */
  /*    to geometry. Then, if required it calculates the SLD profile and if */
  /*    requested resamples this into a number of zero-roughness layers */
  /*    (roughness resampling). It the applies any scalefactors and qz shifts */
  /*    the data requires. This is done before calculating the reflectivity to
   */
  /*    ensure that the reflectivity is calculated over the same range in qz as
   */
  /*    the shifted datapoints. The main reflectivity calculation is then */
  /*    called, including the resolution function. The calculation outputs two
   */
  /*    profiles - 'reflect' which is the same range as the points, and */
  /*    'Simulation' which can be a different range to allow extrapolation. */
  /*    The background correction is the applied, and finally chi-squared is  */
  /*    calculated. */
  /*  */
  /*  Inputs: */
  /*    contrastLayers  : */
  /*    rough           : */
  /*    geometry        : */
  /*    nba             : */
  /*    nbs             : */
  /*    resample        : */
  /*    calcSld         : */
  /*    sf              : */
  /*    qshift          : */
  /*    dataPresent     : */
  /*    data            : */
  /*    dataLimits      : */
  /*    simLimits       : */
  /*    repeatLayers    : */
  /*    background      : */
  /*    resol           : */
  /*    backsType       : */
  /*    params          : */
  /*    paralellPoints  : */
  /*  */
  /*  Outputs: */
  /*  */
  /*  */
  /*  */
  /*  ------------------------------------------------------------------------
   */
  /*  */
  /*        (c) Arwel Hughes  -   12/1/21 */
  /*  */
  /*        Last Modified: 12/1/21 by Arwel Hughes. */
  /*  */
  /*  ------------------------------------------------------------------------
   */
  /*  Bulid up the layers matrix for this contrast */
  st.site = &d_emlrtRSI;
  groupLayers_Mod(&st, contrastLayers, rough, geometry, nba, nbs, theseLayers,
                  ssubs);
  /*  Make the SLD profiles. */
  /*  If resampling is needed, then enforce the calcSLD flag, so as to catch */
  /*  the error af trying to resample a non-existent profile. */
  if ((resample == 1.0) && (calcSld == 0.0)) {
    calcSld = 1.0;
  }
  /*  If calc SLD flag is set, then calculate the SLD profile */
  if (calcSld == 1.0) {
    st.site = &e_emlrtRSI;
    makeSLDProfiles(&st, nba, nbs, theseLayers, *ssubs, repeatLayers,
                    sldProfile);
  } else {
    i = sldProfile->size[0] * sldProfile->size[1];
    sldProfile->size[0] = 1;
    sldProfile->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfile, i, &xb_emlrtRTEI);
    sldProfile->data[0] = 0.0;
    sldProfile->data[1] = 0.0;
  }
  /*  If required, then resample the SLD */
  emxInit_real_T(sp, &layers, 2, &cc_emlrtRTEI, true);
  if (resample == 1.0) {
    st.site = &f_emlrtRSI;
    /*  Function handle for adaptive resampling */
    /*  f = @(x) sldFunc(x); */
    /*   */
    if (1 > sldProfile->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, sldProfile->size[0], &lc_emlrtBCI,
                                    &st);
    }
    if (sldProfile->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(sldProfile->size[0], 1, sldProfile->size[0],
                                    &mc_emlrtBCI, &st);
    }
    emxInitStruct_cell_18(&st, &expl_temp, &pc_emlrtRTEI, true);
    /*  Keep points and minangle as constants for now */
    /*  will fix later */
    b_sldProfile[0] = sldProfile->data[0];
    b_sldProfile[1] = sldProfile->data[sldProfile->size[0] - 1];
    b_st.site = &gd_emlrtRSI;
    adaptive_new(&b_st, sldProfile, b_sldProfile,
                 resamPars[0] * 3.1415926535897931, resamPars[1], &expl_temp);
    if (expl_temp.f1->size[0] == 0) {
      lowIndex = -1;
    } else if (expl_temp.f1->size[0] > 1) {
      lowIndex = expl_temp.f1->size[0] - 1;
    } else {
      lowIndex = 0;
    }
    if (lowIndex < 0) {
      emlrtNonNegativeCheckR2012b(-1.0, &o_emlrtDCI, &st);
    }
    i = layers->size[0] * layers->size[1];
    layers->size[0] = lowIndex;
    layers->size[1] = 3;
    emxEnsureCapacity_real_T(&st, layers, i, &cc_emlrtRTEI);
    loop_ub = lowIndex * 3;
    for (i = 0; i < loop_ub; i++) {
      layers->data[i] = 0.0;
    }
    /*  Now build a layer model from these resampled points */
    if (expl_temp.f1->size[0] == 0) {
      lowIndex = -2;
    } else if (expl_temp.f1->size[0] > 1) {
      lowIndex = expl_temp.f1->size[0] - 2;
    } else {
      lowIndex = -1;
    }
    for (hiIndex = 0; hiIndex <= lowIndex; hiIndex++) {
      if (hiIndex + 1 > expl_temp.f1->size[0]) {
        emlrtDynamicBoundsCheckR2012b(hiIndex + 1, 1, expl_temp.f1->size[0],
                                      &nc_emlrtBCI, &st);
      }
      if (hiIndex + 2 > expl_temp.f1->size[0]) {
        emlrtDynamicBoundsCheckR2012b(hiIndex + 2, 1, expl_temp.f1->size[0],
                                      &oc_emlrtBCI, &st);
      }
      if (hiIndex + 1 > expl_temp.f1->size[0]) {
        emlrtDynamicBoundsCheckR2012b(hiIndex + 1, 1, expl_temp.f1->size[0],
                                      &pc_emlrtBCI, &st);
      }
      if (hiIndex + 2 > expl_temp.f1->size[0]) {
        emlrtDynamicBoundsCheckR2012b(hiIndex + 2, 1, expl_temp.f1->size[0],
                                      &qc_emlrtBCI, &st);
      }
      thisLayRho = expl_temp.f1->data[(hiIndex + expl_temp.f1->size[0]) + 1];
      if (thisLayRho > expl_temp.f1->data[hiIndex + expl_temp.f1->size[0]]) {
        thisLayRho =
            (thisLayRho - expl_temp.f1->data[hiIndex + expl_temp.f1->size[0]]) /
                2.0 +
            expl_temp.f1->data[hiIndex + expl_temp.f1->size[0]];
      } else {
        thisLayRho +=
            (expl_temp.f1->data[hiIndex + expl_temp.f1->size[0]] - thisLayRho) /
            2.0;
      }
      if (hiIndex + 1 > layers->size[0]) {
        emlrtDynamicBoundsCheckR2012b(hiIndex + 1, 1, layers->size[0],
                                      &rc_emlrtBCI, &st);
      }
      layers->data[hiIndex] =
          expl_temp.f1->data[hiIndex + 1] - expl_temp.f1->data[hiIndex];
      layers->data[hiIndex + layers->size[0]] = thisLayRho;
      layers->data[hiIndex + layers->size[0] * 2] = 2.2204460492503131E-16;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    emxFreeStruct_cell_18(&expl_temp);
    i = resamLayers->size[0] * resamLayers->size[1];
    resamLayers->size[0] = layers->size[0];
    resamLayers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, resamLayers, i, &dc_emlrtRTEI);
    loop_ub = layers->size[0] * 3;
    for (i = 0; i < loop_ub; i++) {
      resamLayers->data[i] = layers->data[i];
    }
  } else {
    i = layers->size[0] * layers->size[1];
    layers->size[0] = theseLayers->size[0];
    layers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layers, i, &yb_emlrtRTEI);
    loop_ub = theseLayers->size[0] * 3;
    for (i = 0; i < loop_ub; i++) {
      layers->data[i] = theseLayers->data[i];
    }
    i = resamLayers->size[0] * resamLayers->size[1];
    resamLayers->size[0] = 1;
    resamLayers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, resamLayers, i, &ac_emlrtRTEI);
    resamLayers->data[0] = 0.0;
    resamLayers->data[1] = 0.0;
    resamLayers->data[2] = 0.0;
  }
  emxInit_real_T(sp, &b_data, 2, &bc_emlrtRTEI, true);
  /*  Apply scale factors and q shifts to the data */
  st.site = &g_emlrtRSI;
  thisLayRho = sf;
  i = b_data->size[0] * b_data->size[1];
  b_data->size[0] = data->size[0];
  b_data->size[1] = data->size[1];
  emxEnsureCapacity_real_T(&st, b_data, i, &bc_emlrtRTEI);
  loop_ub = data->size[0] * data->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_data->data[i] = data->data[i];
  }
  /*  Shifts the data according to scale factor. If there is no data, makes  */
  /*  x-data over the simulation range. */
  /*  scalefac = problem.scalefactors; */
  /*  horshift = problem.qshifts; */
  /*  numberOfContrasts = problem.numberOfContrasts; */
  /*  dataPresent = problem.dataPresent; */
  /*  allData = problem.data; */
  /*  dataLimits = problem.dataLimits; */
  /* shifted_data = cell(1,numberOfContrasts); */
  if (dataPresent != (int32_T)muDoubleScalarFloor(dataPresent)) {
    emlrtIntegerCheckR2012b(dataPresent, &m_emlrtDCI, &st);
  }
  emxInit_real_T(&st, &b_lowIndex, 1, &lc_emlrtRTEI, true);
  switch ((int32_T)dataPresent) {
  case 1:
    if (sf == 0.0) {
      thisLayRho = 1.0E-30;
    }
    if (1 > data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, data->size[1], &sc_emlrtBCI, &st);
    }
    emlrtSubAssignSizeCheckR2012b(&data->size[0], 1, &data->size[0], 1,
                                  &emlrtECI, &st);
    loop_ub = data->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_data->data[i] = data->data[i] + qshift;
    }
    if (2 > b_data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, b_data->size[1], &uc_emlrtBCI, &st);
    }
    if (2 > b_data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, b_data->size[1], &tc_emlrtBCI, &st);
    }
    loop_ub = b_data->size[0];
    i = b_lowIndex->size[0];
    b_lowIndex->size[0] = b_data->size[0];
    emxEnsureCapacity_real_T(&st, b_lowIndex, i, &ec_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      b_lowIndex->data[i] = b_data->data[i + b_data->size[0]] / thisLayRho;
    }
    emlrtSubAssignSizeCheckR2012b(&b_data->size[0], 1, &b_lowIndex->size[0], 1,
                                  &b_emlrtECI, &st);
    loop_ub = b_lowIndex->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_data->data[i + b_data->size[0]] = b_lowIndex->data[i];
    }
    if (3 > b_data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(3, 1, b_data->size[1], &wc_emlrtBCI, &st);
    }
    if (3 > b_data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(3, 1, b_data->size[1], &vc_emlrtBCI, &st);
    }
    loop_ub = b_data->size[0];
    i = b_lowIndex->size[0];
    b_lowIndex->size[0] = b_data->size[0];
    emxEnsureCapacity_real_T(&st, b_lowIndex, i, &gc_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      b_lowIndex->data[i] = b_data->data[i + b_data->size[0] * 2] / thisLayRho;
    }
    emlrtSubAssignSizeCheckR2012b(&b_data->size[0], 1, &b_lowIndex->size[0], 1,
                                  &c_emlrtECI, &st);
    loop_ub = b_lowIndex->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_data->data[i + b_data->size[0] * 2] = b_lowIndex->data[i];
    }
    if (1 > b_data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, b_data->size[1], &xc_emlrtBCI, &st);
    }
    emxInit_boolean_T(&st, &c_data, 1, &kc_emlrtRTEI, true);
    b_st.site = &vf_emlrtRSI;
    loop_ub = b_data->size[0];
    i = c_data->size[0];
    c_data->size[0] = b_data->size[0];
    emxEnsureCapacity_boolean_T(&b_st, c_data, i, &kc_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      c_data->data[i] = (b_data->data[i] < dataLimits[0]);
    }
    emxInit_int32_T(&b_st, &ii, 1, &oc_emlrtRTEI, true);
    c_st.site = &sd_emlrtRSI;
    eml_find(&c_st, c_data, ii);
    i = b_lowIndex->size[0];
    b_lowIndex->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(&b_st, b_lowIndex, i, &lc_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_lowIndex->data[i] = ii->data[i];
    }
    if (b_lowIndex->size[0] != 0) {
      lowIndex = (int32_T)b_lowIndex->data[b_lowIndex->size[0] - 1];
    } else {
      lowIndex = 1;
    }
    if (1 > b_data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, b_data->size[1], &yc_emlrtBCI, &st);
    }
    b_st.site = &wf_emlrtRSI;
    loop_ub = b_data->size[0];
    i = c_data->size[0];
    c_data->size[0] = b_data->size[0];
    emxEnsureCapacity_boolean_T(&b_st, c_data, i, &mc_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      c_data->data[i] = (b_data->data[i] > dataLimits[1]);
    }
    c_st.site = &sd_emlrtRSI;
    eml_find(&c_st, c_data, ii);
    i = b_lowIndex->size[0];
    b_lowIndex->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(&b_st, b_lowIndex, i, &nc_emlrtRTEI);
    loop_ub = ii->size[0];
    emxFree_boolean_T(&c_data);
    for (i = 0; i < loop_ub; i++) {
      b_lowIndex->data[i] = ii->data[i];
    }
    emxFree_int32_T(&ii);
    if (b_lowIndex->size[0] != 0) {
      hiIndex = (int32_T)b_lowIndex->data[0];
    } else {
      if (1 > b_data->size[1]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, b_data->size[1], &ad_emlrtBCI, &st);
      }
      hiIndex = b_data->size[0];
    }
    if (lowIndex > hiIndex) {
      i = 0;
      hiIndex = 0;
    } else {
      if ((lowIndex < 1) || (lowIndex > b_data->size[0])) {
        emlrtDynamicBoundsCheckR2012b(lowIndex, 1, b_data->size[0],
                                      &bd_emlrtBCI, &st);
      }
      i = lowIndex - 1;
      if ((hiIndex < 1) || (hiIndex > b_data->size[0])) {
        emlrtDynamicBoundsCheckR2012b(hiIndex, 1, b_data->size[0], &cd_emlrtBCI,
                                      &st);
      }
    }
    loop_ub = b_data->size[1];
    lowIndex = hiIndex - i;
    hiIndex = shifted_dat->size[0] * shifted_dat->size[1];
    shifted_dat->size[0] = lowIndex;
    shifted_dat->size[1] = b_data->size[1];
    emxEnsureCapacity_real_T(&st, shifted_dat, hiIndex, &fc_emlrtRTEI);
    for (hiIndex = 0; hiIndex < loop_ub; hiIndex++) {
      for (i1 = 0; i1 < lowIndex; i1++) {
        shifted_dat->data[i1 + shifted_dat->size[0] * hiIndex] =
            b_data->data[(i + i1) + b_data->size[0] * hiIndex];
      }
    }
    break;
  default:
    i = simLimits_size[0] * simLimits_size[1];
    if (1 > i) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i, &dd_emlrtBCI, &st);
    }
    thisLayRho = simLimits_data[0];
    if (2 > i) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i, &ed_emlrtBCI, &st);
    }
    simXData[99] = simLimits_data[1];
    simXData[0] = simLimits_data[0];
    if (simLimits_data[0] == -simLimits_data[1]) {
      thisLayRho = simLimits_data[1] / 99.0;
      for (lowIndex = 0; lowIndex < 98; lowIndex++) {
        simXData[lowIndex + 1] =
            (2.0 * ((real_T)lowIndex + 2.0) - 101.0) * thisLayRho;
      }
    } else if (((simLimits_data[0] < 0.0) != (simLimits_data[1] < 0.0)) &&
               ((muDoubleScalarAbs(simLimits_data[0]) >
                 8.9884656743115785E+307) ||
                (muDoubleScalarAbs(simLimits_data[1]) >
                 8.9884656743115785E+307))) {
      delta1 = simLimits_data[0] / 99.0;
      delta2 = simLimits_data[1] / 99.0;
      for (lowIndex = 0; lowIndex < 98; lowIndex++) {
        simXData[lowIndex + 1] =
            (thisLayRho + delta2 * ((real_T)lowIndex + 1.0)) -
            delta1 * ((real_T)lowIndex + 1.0);
      }
    } else {
      delta1 = (simLimits_data[1] - simLimits_data[0]) / 99.0;
      for (lowIndex = 0; lowIndex < 98; lowIndex++) {
        simXData[lowIndex + 1] = thisLayRho + ((real_T)lowIndex + 1.0) * delta1;
      }
    }
    for (i = 0; i < 100; i++) {
      b_simXData[i] = simXData[i];
      b_simXData[i + 100] = 0.0;
      b_simXData[i + 200] = 0.0;
    }
    i = shifted_dat->size[0] * shifted_dat->size[1];
    shifted_dat->size[0] = 100;
    shifted_dat->size[1] = 3;
    emxEnsureCapacity_real_T(&st, shifted_dat, i, &fc_emlrtRTEI);
    for (i = 0; i < 300; i++) {
      shifted_dat->data[i] = b_simXData[i];
    }
    break;
  }
  emxFree_real_T(&b_data);
  /*  Calculate the reflectivity */
  st.site = &h_emlrtRSI;
  callReflectivity(&st, nba, nbs, simLimits_data, simLimits_size, repeatLayers,
                   shifted_dat, layers, *ssubs, resol, reflect, Simul);
  /*  Apply background correction, either to the simulation or the data */
  st.site = &i_emlrtRSI;
  emxFree_real_T(&layers);
  if (backsType != (int32_T)muDoubleScalarFloor(backsType)) {
    emlrtIntegerCheckR2012b(backsType, &n_emlrtDCI, &st);
  }
  switch ((int32_T)backsType) {
  case 1:
    /* Add background to the simulation */
    loop_ub = reflect->size[0] * 2;
    i = reflect->size[0] * reflect->size[1];
    reflect->size[1] = 2;
    emxEnsureCapacity_real_T(&st, reflect, i, &hc_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      reflect->data[i] += background;
    }
    loop_ub = Simul->size[0] * 2;
    i = Simul->size[0] * Simul->size[1];
    Simul->size[1] = 2;
    emxEnsureCapacity_real_T(&st, Simul, i, &ic_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      Simul->data[i] += background;
    }
    break;
  case 2:
    /*          %Subtract the background from the data.. */
    if (2 > shifted_dat->size[1]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, shifted_dat->size[1], &gd_emlrtBCI,
                                    &st);
    }
    if (2 > shifted_dat->size[1]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, shifted_dat->size[1], &fd_emlrtBCI,
                                    &st);
    }
    emlrtSubAssignSizeCheckR2012b(&shifted_dat->size[0], 1,
                                  &shifted_dat->size[0], 1, &d_emlrtECI, &st);
    lowIndex = shifted_dat->size[0] - 1;
    i = b_lowIndex->size[0];
    b_lowIndex->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(&st, b_lowIndex, i, &jc_emlrtRTEI);
    for (i = 0; i <= lowIndex; i++) {
      b_lowIndex->data[i] =
          shifted_dat->data[i + shifted_dat->size[0]] - background;
    }
    loop_ub = b_lowIndex->size[0];
    for (i = 0; i < loop_ub; i++) {
      shifted_dat->data[i + shifted_dat->size[0]] = b_lowIndex->data[i];
    }
    /* shifted_dat(:,3) = shifted_dat(:,3) - backg;    */
    break;
  }
  emxFree_real_T(&b_lowIndex);
  /*  Calculate chi squared. */
  st.site = &j_emlrtRSI;
  *chiSq = chiSquared(&st, shifted_dat, reflect, params);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (standardTF_layers_core.c) */
