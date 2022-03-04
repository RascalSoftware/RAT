/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_custXY_reflectivityCalculation.c
 *
 * Code generation for function 'standardTF_custXY_reflectivityCalculation'
 *
 */

/* Include files */
#include "standardTF_custXY_reflectivityCalculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_custXY_paraContrasts.h"
#include "standardTF_custXY_paraPoints.h"
#include "standardTF_custXY_single.h"
#include "sum.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo ji_emlrtRSI = {
    64,                                          /* lineNo */
    "standardTF_custXY_reflectivityCalculation", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pathName */
};

static emlrtRSInfo ki_emlrtRSI = {
    71,                                          /* lineNo */
    "standardTF_custXY_reflectivityCalculation", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pathName */
};

static emlrtRSInfo li_emlrtRSI = {
    78,                                          /* lineNo */
    "standardTF_custXY_reflectivityCalculation", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pathName */
};

static emlrtRSInfo mi_emlrtRSI = {
    93,                                          /* lineNo */
    "standardTF_custXY_reflectivityCalculation", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pathName */
};

static emlrtDCInfo vc_emlrtDCI = {
    29,                                          /* lineNo */
    21,                                          /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    1                                              /* checkKind */
};

static emlrtRTEInfo bd_emlrtRTEI = {
    30,                                          /* lineNo */
    9,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo cd_emlrtRTEI = {
    35,                                          /* lineNo */
    9,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo dd_emlrtRTEI = {
    40,                                          /* lineNo */
    9,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo ed_emlrtRTEI = {
    45,                                          /* lineNo */
    9,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo fd_emlrtRTEI = {
    50,                                          /* lineNo */
    9,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo gd_emlrtRTEI = {
    55,                                          /* lineNo */
    9,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtBCInfo yu_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    31,                                          /* lineNo */
    18,                                          /* colNo */
    "reflectivity",                              /* aName */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    0                                              /* checkKind */
};

static emlrtBCInfo av_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    36,                                          /* lineNo */
    16,                                          /* colNo */
    "Simulation",                                /* aName */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    0                                              /* checkKind */
};

static emlrtBCInfo bv_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    41,                                          /* lineNo */
    18,                                          /* colNo */
    "shifted_data",                              /* aName */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    0                                              /* checkKind */
};

static emlrtBCInfo cv_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    46,                                          /* lineNo */
    15,                                          /* colNo */
    "layerSlds",                                 /* aName */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    0                                              /* checkKind */
};

static emlrtBCInfo dv_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    51,                                          /* lineNo */
    17,                                          /* colNo */
    "sldProfiles",                               /* aName */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    0                                              /* checkKind */
};

static emlrtBCInfo ev_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    56,                                          /* lineNo */
    15,                                          /* colNo */
    "allLayers",                                 /* aName */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    0                                              /* checkKind */
};

static emlrtDCInfo wc_emlrtDCI = {
    85,                                          /* lineNo */
    1,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    1                                              /* checkKind */
};

static emlrtDCInfo xc_emlrtDCI = {
    85,                                          /* lineNo */
    1,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    4                                              /* checkKind */
};

static emlrtDCInfo yc_emlrtDCI = {
    86,                                          /* lineNo */
    1,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    1                                              /* checkKind */
};

static emlrtDCInfo ad_emlrtDCI = {
    87,                                          /* lineNo */
    1,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    1                                              /* checkKind */
};

static emlrtDCInfo bd_emlrtDCI = {
    88,                                          /* lineNo */
    1,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    1                                              /* checkKind */
};

static emlrtDCInfo cd_emlrtDCI = {
    89,                                          /* lineNo */
    1,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    1                                              /* checkKind */
};

static emlrtDCInfo dd_emlrtDCI = {
    90,                                          /* lineNo */
    1,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    1                                              /* checkKind */
};

static emlrtDCInfo ed_emlrtDCI = {
    25,                                          /* lineNo */
    1,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    1                                              /* checkKind */
};

static emlrtDCInfo fd_emlrtDCI = {
    91,                                          /* lineNo */
    1,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    1                                              /* checkKind */
};

static emlrtDCInfo gd_emlrtDCI = {
    27,                                          /* lineNo */
    1,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    1                                              /* checkKind */
};

static emlrtBCInfo fv_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    29,                                          /* lineNo */
    39,                                          /* colNo */
    "reflectivity",                              /* aName */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    0                                              /* checkKind */
};

static emlrtBCInfo gv_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    29,                                          /* lineNo */
    39,                                          /* colNo */
    "Simulation",                                /* aName */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    0                                              /* checkKind */
};

static emlrtBCInfo hv_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    29,                                          /* lineNo */
    39,                                          /* colNo */
    "shifted_data",                              /* aName */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    0                                              /* checkKind */
};

static emlrtBCInfo iv_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    29,                                          /* lineNo */
    39,                                          /* colNo */
    "layerSlds",                                 /* aName */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    0                                              /* checkKind */
};

static emlrtBCInfo jv_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    41,                                          /* lineNo */
    5,                                           /* colNo */
    "shifted_data",                              /* aName */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    0                                              /* checkKind */
};

static emlrtBCInfo kv_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    29,                                          /* lineNo */
    39,                                          /* colNo */
    "sldProfiles",                               /* aName */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    0                                              /* checkKind */
};

static emlrtBCInfo lv_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    46,                                          /* lineNo */
    5,                                           /* colNo */
    "layerSlds",                                 /* aName */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    0                                              /* checkKind */
};

static emlrtBCInfo mv_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    29,                                          /* lineNo */
    39,                                          /* colNo */
    "allLayers",                                 /* aName */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    0                                              /* checkKind */
};

static emlrtBCInfo nv_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    56,                                          /* lineNo */
    5,                                           /* colNo */
    "allLayers",                                 /* aName */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    0                                              /* checkKind */
};

static emlrtBCInfo ov_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    51,                                          /* lineNo */
    5,                                           /* colNo */
    "sldProfiles",                               /* aName */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    0                                              /* checkKind */
};

static emlrtBCInfo pv_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    36,                                          /* lineNo */
    5,                                           /* colNo */
    "Simulation",                                /* aName */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    0                                              /* checkKind */
};

static emlrtBCInfo qv_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    31,                                          /* lineNo */
    5,                                           /* colNo */
    "reflectivity",                              /* aName */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m", /* pName */
    0                                              /* checkKind */
};

static emlrtRTEInfo yp_emlrtRTEI = {
    85,                                          /* lineNo */
    1,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo aq_emlrtRTEI = {
    86,                                          /* lineNo */
    1,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo bq_emlrtRTEI = {
    87,                                          /* lineNo */
    1,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo cq_emlrtRTEI = {
    88,                                          /* lineNo */
    1,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo dq_emlrtRTEI = {
    89,                                          /* lineNo */
    1,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo eq_emlrtRTEI = {
    90,                                          /* lineNo */
    1,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo fq_emlrtRTEI = {
    25,                                          /* lineNo */
    1,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo gq_emlrtRTEI = {
    91,                                          /* lineNo */
    1,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo hq_emlrtRTEI = {
    27,                                          /* lineNo */
    1,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo iq_emlrtRTEI = {
    1,                                           /* lineNo */
    91,                                          /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo jq_emlrtRTEI = {
    29,                                          /* lineNo */
    39,                                          /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo kq_emlrtRTEI = {
    31,                                          /* lineNo */
    5,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo lq_emlrtRTEI = {
    36,                                          /* lineNo */
    5,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo mq_emlrtRTEI = {
    41,                                          /* lineNo */
    5,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo nq_emlrtRTEI = {
    46,                                          /* lineNo */
    5,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo oq_emlrtRTEI = {
    51,                                          /* lineNo */
    5,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo pq_emlrtRTEI = {
    56,                                          /* lineNo */
    5,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo qq_emlrtRTEI = {
    78,                                          /* lineNo */
    62,                                          /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo rq_emlrtRTEI = {
    95,                                          /* lineNo */
    1,                                           /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo sq_emlrtRTEI = {
    79,                                          /* lineNo */
    60,                                          /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo tq_emlrtRTEI = {
    79,                                          /* lineNo */
    14,                                          /* colNo */
    "standardTF_custXY_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY_reflectivityCalculation.m" /* pName */
};

/* Function Definitions */
void c_standardTF_custXY_reflectivit(
    const emlrtStack *sp, const struct0_T *problemDef,
    const cell_16 *problemDef_cells, const struct2_T *controls,
    struct_T *problem, emxArray_cell_wrap_9 *reflectivity,
    emxArray_cell_wrap_9 *Simulation, emxArray_cell_wrap_14 *shifted_data,
    emxArray_cell_wrap_10 *layerSlds, emxArray_cell_wrap_14 *sldProfiles,
    emxArray_cell_wrap_14 *allLayers)
{
  static const char_T b_cv[6] = {'s', 'i', 'n', 'g', 'l', 'e'};
  static const char_T b_cv1[6] = {'p', 'o', 'i', 'n', 't', 's'};
  emlrtStack st;
  emxArray_cell_wrap_12 *r;
  emxArray_cell_wrap_12 *r1;
  emxArray_cell_wrap_14 *b_allLayers;
  emxArray_cell_wrap_25 *r2;
  emxArray_cell_wrap_9 *b_Simulation;
  emxArray_cell_wrap_9 *b_reflectivity;
  int32_T exitg1;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  boolean_T b_bool;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /*  Custom XP profile reflectivity calculation for standardTF */
  /*  This function decides on parallelisation options before calling the */
  /*  relevant version of the main custom XY calculation. It is more */
  /*  efficient to have multiple versions of the core calculation, each dealing
   */
  /*  with a different scheme for paralellisation. These are: */
  /*  single    - single threaded teflectivity calculation */
  /*  points    - parallelise over points in the reflectivity calculation */
  /*  contrasts - parallelise over contrasts. */
  /*  Pre-allocation - It's necessary to */
  /*  pre-allocate the memory for all the arrays */
  /*  for compilation, so do this in this block. */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &xc_emlrtDCI,
                                (emlrtCTX)sp);
  }
  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &wc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->ssubs->size[0];
  loop_ub = (int32_T)problemDef->numberOfContrasts;
  problem->ssubs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->ssubs, i1, &yp_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &wc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->ssubs->data[i1] = 0.0;
  }
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &yc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  loop_ub_tmp = (int32_T)problemDef->numberOfContrasts;
  i1 = problem->backgrounds->size[0];
  problem->backgrounds->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->backgrounds, i1, &aq_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &yc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->backgrounds->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ad_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->qshifts->size[0];
  problem->qshifts->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->qshifts, i1, &bq_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ad_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->qshifts->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &bd_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->scalefactors->size[0];
  problem->scalefactors->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->scalefactors, i1, &cq_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &bd_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->scalefactors->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &cd_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->nbairs->size[0];
  problem->nbairs->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->nbairs, i1, &dq_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &cd_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->nbairs->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &dd_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->nbsubs->size[0];
  problem->nbsubs->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->nbsubs, i1, &eq_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &dd_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->nbsubs->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ed_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->calculations.all_chis->size[0];
  problem->calculations.all_chis->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->calculations.all_chis, i1,
                           &fq_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ed_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->calculations.all_chis->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &fd_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->resolutions->size[0];
  problem->resolutions->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->resolutions, i1, &gq_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &fd_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->resolutions->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &gd_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->allSubRough->size[0];
  problem->allSubRough->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->allSubRough, i1, &hq_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &gd_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->allSubRough->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &vc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i = reflectivity->size[0];
  reflectivity->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &iq_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    loop_ub = reflectivity->size[0] - 1;
    if (i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, reflectivity->size[0] - 1,
                                    &fv_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[i].f1->size[0] = 0;
    if (i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub, &fv_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = reflectivity->data[i].f1->size[0] * reflectivity->data[i].f1->size[1];
    reflectivity->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[i].f1, i1, &iq_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &bd_emlrtRTEI, (emlrtCTX)sp);
  i = reflectivity->size[0];
  reflectivity->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &jq_emlrtRTEI);
  for (loop_ub = 0; loop_ub < loop_ub_tmp; loop_ub++) {
    if (loop_ub > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, reflectivity->size[0] - 1,
                                    &yu_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity->data[loop_ub].f1->size[0] *
        reflectivity->data[loop_ub].f1->size[1];
    reflectivity->data[loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[loop_ub].f1, i,
                             &kq_emlrtRTEI);
    if (loop_ub > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, reflectivity->size[0] - 1,
                                    &yu_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity->data[loop_ub].f1->size[0] *
        reflectivity->data[loop_ub].f1->size[1];
    reflectivity->data[loop_ub].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[loop_ub].f1, i,
                             &kq_emlrtRTEI);
    i = reflectivity->size[0];
    if (loop_ub > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, reflectivity->size[0] - 1,
                                    &yu_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[loop_ub].f1->data[0] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &qv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    reflectivity->data[loop_ub].f1->data[1] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &qv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    reflectivity->data[loop_ub].f1->data[2] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &qv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    reflectivity->data[loop_ub].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = Simulation->size[0];
  Simulation->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &iq_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    loop_ub = Simulation->size[0] - 1;
    if (i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, Simulation->size[0] - 1, &gv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation->data[i].f1->size[0] = 0;
    if (i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub, &gv_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = Simulation->data[i].f1->size[0] * Simulation->data[i].f1->size[1];
    Simulation->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[i].f1, i1, &iq_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &cd_emlrtRTEI, (emlrtCTX)sp);
  i = Simulation->size[0];
  Simulation->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &jq_emlrtRTEI);
  for (loop_ub = 0; loop_ub < loop_ub_tmp; loop_ub++) {
    if (loop_ub > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, Simulation->size[0] - 1,
                                    &av_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[loop_ub].f1->size[0] *
        Simulation->data[loop_ub].f1->size[1];
    Simulation->data[loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[loop_ub].f1, i,
                             &lq_emlrtRTEI);
    if (loop_ub > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, Simulation->size[0] - 1,
                                    &av_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[loop_ub].f1->size[0] *
        Simulation->data[loop_ub].f1->size[1];
    Simulation->data[loop_ub].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[loop_ub].f1, i,
                             &lq_emlrtRTEI);
    i = Simulation->size[0];
    if (loop_ub > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, Simulation->size[0] - 1,
                                    &av_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[loop_ub].f1->data[0] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &pv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation->data[loop_ub].f1->data[1] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &pv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation->data[loop_ub].f1->data[2] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &pv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation->data[loop_ub].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = shifted_data->size[0];
  shifted_data->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &iq_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    loop_ub = shifted_data->size[0] - 1;
    if (i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, shifted_data->size[0] - 1,
                                    &hv_emlrtBCI, (emlrtCTX)sp);
    }
    shifted_data->data[i].f1->size[0] = 0;
    if (i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub, &hv_emlrtBCI, (emlrtCTX)sp);
    }
    shifted_data->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &dd_emlrtRTEI, (emlrtCTX)sp);
  i = shifted_data->size[0];
  shifted_data->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &jq_emlrtRTEI);
  for (loop_ub = 0; loop_ub < loop_ub_tmp; loop_ub++) {
    if (loop_ub > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, shifted_data->size[0] - 1,
                                    &bv_emlrtBCI, (emlrtCTX)sp);
    }
    i = shifted_data->data[loop_ub].f1->size[0] *
        shifted_data->data[loop_ub].f1->size[1];
    shifted_data->data[loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, shifted_data->data[loop_ub].f1, i,
                             &mq_emlrtRTEI);
    if (loop_ub > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, shifted_data->size[0] - 1,
                                    &bv_emlrtBCI, (emlrtCTX)sp);
    }
    i = shifted_data->data[loop_ub].f1->size[0] *
        shifted_data->data[loop_ub].f1->size[1];
    shifted_data->data[loop_ub].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[loop_ub].f1, i,
                             &mq_emlrtRTEI);
    i = shifted_data->size[0];
    if (loop_ub > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, shifted_data->size[0] - 1,
                                    &bv_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 6; i1++) {
      if (loop_ub > i - 1) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &jv_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      shifted_data->data[loop_ub].f1->data[i1] = 1.0;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = layerSlds->size[0];
  layerSlds->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &iq_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    loop_ub = layerSlds->size[0] - 1;
    if (i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, layerSlds->size[0] - 1, &iv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    layerSlds->data[i].f1->size[0] = 0;
    if (i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub, &iv_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
    layerSlds->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[i].f1, i1, &iq_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &ed_emlrtRTEI, (emlrtCTX)sp);
  i = layerSlds->size[0];
  layerSlds->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &jq_emlrtRTEI);
  for (loop_ub = 0; loop_ub < loop_ub_tmp; loop_ub++) {
    if (loop_ub > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, layerSlds->size[0] - 1,
                                    &cv_emlrtBCI, (emlrtCTX)sp);
    }
    i = layerSlds->data[loop_ub].f1->size[0] *
        layerSlds->data[loop_ub].f1->size[1];
    layerSlds->data[loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, layerSlds->data[loop_ub].f1, i, &nq_emlrtRTEI);
    if (loop_ub > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, layerSlds->size[0] - 1,
                                    &cv_emlrtBCI, (emlrtCTX)sp);
    }
    i = layerSlds->data[loop_ub].f1->size[0] *
        layerSlds->data[loop_ub].f1->size[1];
    layerSlds->data[loop_ub].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[loop_ub].f1, i, &nq_emlrtRTEI);
    i = layerSlds->size[0];
    if (loop_ub > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, layerSlds->size[0] - 1,
                                    &cv_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 6; i1++) {
      if (loop_ub > i - 1) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &lv_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      layerSlds->data[loop_ub].f1->data[i1] = 1.0;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = sldProfiles->size[0];
  sldProfiles->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &iq_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    loop_ub = sldProfiles->size[0] - 1;
    if (i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, sldProfiles->size[0] - 1,
                                    &kv_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[i].f1->size[0] = 0;
    if (i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub, &kv_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &fd_emlrtRTEI, (emlrtCTX)sp);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &jq_emlrtRTEI);
  for (loop_ub = 0; loop_ub < loop_ub_tmp; loop_ub++) {
    if (loop_ub > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, sldProfiles->size[0] - 1,
                                    &dv_emlrtBCI, (emlrtCTX)sp);
    }
    i = sldProfiles->data[loop_ub].f1->size[0] *
        sldProfiles->data[loop_ub].f1->size[1];
    sldProfiles->data[loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[loop_ub].f1, i,
                             &oq_emlrtRTEI);
    if (loop_ub > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, sldProfiles->size[0] - 1,
                                    &dv_emlrtBCI, (emlrtCTX)sp);
    }
    i = sldProfiles->data[loop_ub].f1->size[0] *
        sldProfiles->data[loop_ub].f1->size[1];
    sldProfiles->data[loop_ub].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[loop_ub].f1, i,
                             &oq_emlrtRTEI);
    i = sldProfiles->size[0];
    if (loop_ub > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, sldProfiles->size[0] - 1,
                                    &dv_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[loop_ub].f1->data[0] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &ov_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sldProfiles->data[loop_ub].f1->data[1] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &ov_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sldProfiles->data[loop_ub].f1->data[2] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &ov_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sldProfiles->data[loop_ub].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = allLayers->size[0];
  allLayers->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &iq_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    loop_ub = allLayers->size[0] - 1;
    if (i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, allLayers->size[0] - 1, &mv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[i].f1->size[0] = 0;
    if (i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub, &mv_emlrtBCI, (emlrtCTX)sp);
    }
    allLayers->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &gd_emlrtRTEI, (emlrtCTX)sp);
  i = allLayers->size[0];
  allLayers->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &jq_emlrtRTEI);
  for (loop_ub = 0; loop_ub < loop_ub_tmp; loop_ub++) {
    if (loop_ub > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, allLayers->size[0] - 1,
                                    &ev_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[loop_ub].f1->size[0] *
        allLayers->data[loop_ub].f1->size[1];
    allLayers->data[loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[loop_ub].f1, i, &pq_emlrtRTEI);
    if (loop_ub > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, allLayers->size[0] - 1,
                                    &ev_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[loop_ub].f1->size[0] *
        allLayers->data[loop_ub].f1->size[1];
    allLayers->data[loop_ub].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[loop_ub].f1, i, &pq_emlrtRTEI);
    i = allLayers->size[0];
    if (loop_ub > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, allLayers->size[0] - 1,
                                    &ev_emlrtBCI, (emlrtCTX)sp);
    }
    allLayers->data[loop_ub].f1->data[0] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &nv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[loop_ub].f1->data[1] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  b_bool = false;
  if (controls->para->size[1] == 6) {
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 6) {
        if (controls->para->data[loop_ub] != b_cv[loop_ub]) {
          exitg1 = 1;
        } else {
          loop_ub++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (b_bool) {
    loop_ub = 0;
  } else {
    b_bool = false;
    if (controls->para->size[1] == 6) {
      loop_ub = 0;
      do {
        exitg1 = 0;
        if (loop_ub < 6) {
          if (controls->para->data[loop_ub] != b_cv1[loop_ub]) {
            exitg1 = 1;
          } else {
            loop_ub++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (b_bool) {
      loop_ub = 1;
    } else {
      b_bool = false;
      if (controls->para->size[1] == 9) {
        loop_ub = 0;
        do {
          exitg1 = 0;
          if (loop_ub < 9) {
            if (controls->para->data[loop_ub] != cv1[loop_ub]) {
              exitg1 = 1;
            } else {
              loop_ub++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (b_bool) {
        loop_ub = 2;
      } else {
        loop_ub = -1;
      }
    }
  }
  switch (loop_ub) {
  case 0:
    st.site = &ji_emlrtRSI;
    standardTF_custXY_single(
        &st, problemDef, problemDef_cells, controls, problem->ssubs,
        problem->backgrounds, problem->qshifts, problem->scalefactors,
        problem->nbairs, problem->nbsubs, problem->resolutions,
        problem->calculations.all_chis, reflectivity, Simulation, shifted_data,
        layerSlds, sldProfiles, allLayers, problem->allSubRough);
    break;
  case 1:
    st.site = &ki_emlrtRSI;
    standardTF_custXY_paraPoints(
        &st, problemDef, problemDef_cells, controls, problem->ssubs,
        problem->backgrounds, problem->qshifts, problem->scalefactors,
        problem->nbairs, problem->nbsubs, problem->resolutions,
        problem->calculations.all_chis, reflectivity, Simulation, shifted_data,
        layerSlds, sldProfiles, allLayers, problem->allSubRough);
    break;
  case 2:
    emxInit_cell_wrap_9(sp, &b_reflectivity, 1, &iq_emlrtRTEI, true);
    emxInit_cell_wrap_12(sp, &r, 1, &iq_emlrtRTEI, true);
    emxInit_cell_wrap_12(sp, &r1, 1, &iq_emlrtRTEI, true);
    emxInit_cell_wrap_25(sp, &r2, 1, &iq_emlrtRTEI, true);
    st.site = &li_emlrtRSI;
    standardTF_custXY_paraContrasts(
        &st, problemDef, problemDef_cells, controls, problem->ssubs,
        problem->backgrounds, problem->qshifts, problem->scalefactors,
        problem->nbairs, problem->nbsubs, problem->resolutions,
        problem->calculations.all_chis, r, r1, shifted_data, layerSlds,
        sldProfiles, r2, problem->allSubRough);
    i = b_reflectivity->size[0];
    b_reflectivity->size[0] = r->size[0];
    emxEnsureCapacity_cell_wrap_9(sp, b_reflectivity, i, &qq_emlrtRTEI);
    i = r->size[0];
    for (i1 = 0; i1 < i; i1++) {
      loop_ub_tmp = b_reflectivity->data[i1].f1->size[0] *
                    b_reflectivity->data[i1].f1->size[1];
      b_reflectivity->data[i1].f1->size[0] = r->data[i1].f1->size[0];
      b_reflectivity->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, b_reflectivity->data[i1].f1, loop_ub_tmp,
                               &qq_emlrtRTEI);
      loop_ub = r->data[i1].f1->size[0] * 2;
      for (loop_ub_tmp = 0; loop_ub_tmp < loop_ub; loop_ub_tmp++) {
        b_reflectivity->data[i1].f1->data[loop_ub_tmp] =
            r->data[i1].f1->data[loop_ub_tmp];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    emxFree_cell_wrap_12(&r);
    emxInit_cell_wrap_9(sp, &b_Simulation, 1, &iq_emlrtRTEI, true);
    i = b_Simulation->size[0];
    b_Simulation->size[0] = r1->size[0];
    emxEnsureCapacity_cell_wrap_9(sp, b_Simulation, i, &qq_emlrtRTEI);
    i = r1->size[0];
    for (i1 = 0; i1 < i; i1++) {
      loop_ub_tmp = b_Simulation->data[i1].f1->size[0] *
                    b_Simulation->data[i1].f1->size[1];
      b_Simulation->data[i1].f1->size[0] = r1->data[i1].f1->size[0];
      b_Simulation->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, b_Simulation->data[i1].f1, loop_ub_tmp,
                               &qq_emlrtRTEI);
      loop_ub = r1->data[i1].f1->size[0] * 2;
      for (loop_ub_tmp = 0; loop_ub_tmp < loop_ub; loop_ub_tmp++) {
        b_Simulation->data[i1].f1->data[loop_ub_tmp] =
            r1->data[i1].f1->data[loop_ub_tmp];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    emxFree_cell_wrap_12(&r1);
    emxInit_cell_wrap_14(sp, &b_allLayers, 1, &iq_emlrtRTEI, true);
    i = b_allLayers->size[0];
    b_allLayers->size[0] = r2->size[0];
    emxEnsureCapacity_cell_wrap_14(sp, b_allLayers, i, &sq_emlrtRTEI);
    i = r2->size[0];
    for (i1 = 0; i1 < i; i1++) {
      loop_ub_tmp =
          b_allLayers->data[i1].f1->size[0] * b_allLayers->data[i1].f1->size[1];
      b_allLayers->data[i1].f1->size[0] = r2->data[i1].f1->size[0];
      b_allLayers->data[i1].f1->size[1] = r2->data[i1].f1->size[1];
      emxEnsureCapacity_real_T(sp, b_allLayers->data[i1].f1, loop_ub_tmp,
                               &sq_emlrtRTEI);
      loop_ub = r2->data[i1].f1->size[0] * r2->data[i1].f1->size[1];
      for (loop_ub_tmp = 0; loop_ub_tmp < loop_ub; loop_ub_tmp++) {
        b_allLayers->data[i1].f1->data[loop_ub_tmp] =
            r2->data[i1].f1->data[loop_ub_tmp];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    emxFree_cell_wrap_25(&r2);
    i = reflectivity->size[0];
    reflectivity->size[0] = b_reflectivity->size[0];
    emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &qq_emlrtRTEI);
    loop_ub = b_reflectivity->size[0];
    for (i = 0; i < loop_ub; i++) {
      emxCopyStruct_cell_wrap_9(sp, &reflectivity->data[i],
                                &b_reflectivity->data[i], &qq_emlrtRTEI);
    }
    emxFree_cell_wrap_9(&b_reflectivity);
    i = Simulation->size[0];
    Simulation->size[0] = b_Simulation->size[0];
    emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &tq_emlrtRTEI);
    loop_ub = b_Simulation->size[0];
    for (i = 0; i < loop_ub; i++) {
      emxCopyStruct_cell_wrap_9(sp, &Simulation->data[i],
                                &b_Simulation->data[i], &tq_emlrtRTEI);
    }
    emxFree_cell_wrap_9(&b_Simulation);
    i = allLayers->size[0];
    allLayers->size[0] = b_allLayers->size[0];
    emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &sq_emlrtRTEI);
    loop_ub = b_allLayers->size[0];
    for (i = 0; i < loop_ub; i++) {
      emxCopyStruct_cell_wrap_14(sp, &allLayers->data[i], &b_allLayers->data[i],
                                 &sq_emlrtRTEI);
    }
    emxFree_cell_wrap_14(&b_allLayers);
    break;
  }
  st.site = &mi_emlrtRSI;
  problem->calculations.sum_chi = sum(&st, problem->calculations.all_chis);
  i = problem->resample->size[0] * problem->resample->size[1];
  problem->resample->size[0] = 1;
  problem->resample->size[1] = problem->allSubRough->size[0];
  emxEnsureCapacity_real_T(sp, problem->resample, i, &rq_emlrtRTEI);
  loop_ub = problem->allSubRough->size[0];
  for (i = 0; i < loop_ub; i++) {
    problem->resample->data[i] = 1.0;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (standardTF_custXY_reflectivityCalculation.c) */
