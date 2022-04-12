/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_custLay_reflectivityCalculation.c
 *
 * Code generation for function 'standardTF_custLay_reflectivityCalculation'
 *
 */

/* Include files */
#include "standardTF_custLay_reflectivityCalculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_custlay_paraContrasts.h"
#include "standardTF_custlay_paraPoints.h"
#include "standardTF_custlay_single.h"
#include "sum.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo sh_emlrtRSI = {
    65,                                           /* lineNo */
    "standardTF_custLay_reflectivityCalculation", /* fcnName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pathName */
};

static emlrtRSInfo th_emlrtRSI = {
    72,                                           /* lineNo */
    "standardTF_custLay_reflectivityCalculation", /* fcnName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pathName */
};

static emlrtRSInfo uh_emlrtRSI = {
    79,                                           /* lineNo */
    "standardTF_custLay_reflectivityCalculation", /* fcnName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pathName */
};

static emlrtRSInfo vh_emlrtRSI = {
    100,                                          /* lineNo */
    "standardTF_custLay_reflectivityCalculation", /* fcnName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pathName */
};

static emlrtDCInfo tb_emlrtDCI = {
    29,                                           /* lineNo */
    21,                                           /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    1                                                   /* checkKind */
};

static emlrtRTEInfo gc_emlrtRTEI = {
    30,                                           /* lineNo */
    9,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = {
    35,                                           /* lineNo */
    9,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo ic_emlrtRTEI = {
    40,                                           /* lineNo */
    9,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = {
    45,                                           /* lineNo */
    9,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo kc_emlrtRTEI = {
    50,                                           /* lineNo */
    9,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo lc_emlrtRTEI = {
    55,                                           /* lineNo */
    9,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

static emlrtBCInfo on_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    31,                                           /* lineNo */
    18,                                           /* colNo */
    "reflectivity",                               /* aName */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo pn_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    36,                                           /* lineNo */
    16,                                           /* colNo */
    "Simulation",                                 /* aName */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo qn_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    41,                                           /* lineNo */
    18,                                           /* colNo */
    "shifted_data",                               /* aName */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo rn_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    46,                                           /* lineNo */
    15,                                           /* colNo */
    "layerSlds",                                  /* aName */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo sn_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    51,                                           /* lineNo */
    17,                                           /* colNo */
    "sldProfiles",                                /* aName */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo tn_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    56,                                           /* lineNo */
    15,                                           /* colNo */
    "allLayers",                                  /* aName */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtDCInfo ub_emlrtDCI = {
    92,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    1                                                   /* checkKind */
};

static emlrtDCInfo vb_emlrtDCI = {
    92,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    4                                                   /* checkKind */
};

static emlrtDCInfo wb_emlrtDCI = {
    93,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    1                                                   /* checkKind */
};

static emlrtDCInfo xb_emlrtDCI = {
    94,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    1                                                   /* checkKind */
};

static emlrtDCInfo yb_emlrtDCI = {
    95,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    1                                                   /* checkKind */
};

static emlrtDCInfo ac_emlrtDCI = {
    96,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    1                                                   /* checkKind */
};

static emlrtDCInfo bc_emlrtDCI = {
    97,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    1                                                   /* checkKind */
};

static emlrtDCInfo cc_emlrtDCI = {
    25,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    1                                                   /* checkKind */
};

static emlrtDCInfo dc_emlrtDCI = {
    98,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    1                                                   /* checkKind */
};

static emlrtDCInfo ec_emlrtDCI = {
    101,                                          /* lineNo */
    1,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    1                                                   /* checkKind */
};

static emlrtBCInfo un_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    29,                                           /* lineNo */
    39,                                           /* colNo */
    "reflectivity",                               /* aName */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo vn_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    29,                                           /* lineNo */
    39,                                           /* colNo */
    "Simulation",                                 /* aName */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo wn_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    29,                                           /* lineNo */
    39,                                           /* colNo */
    "shifted_data",                               /* aName */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo xn_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    29,                                           /* lineNo */
    39,                                           /* colNo */
    "layerSlds",                                  /* aName */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo yn_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    41,                                           /* lineNo */
    5,                                            /* colNo */
    "shifted_data",                               /* aName */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo ao_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    29,                                           /* lineNo */
    39,                                           /* colNo */
    "sldProfiles",                                /* aName */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo bo_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    46,                                           /* lineNo */
    5,                                            /* colNo */
    "layerSlds",                                  /* aName */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo co_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    29,                                           /* lineNo */
    39,                                           /* colNo */
    "allLayers",                                  /* aName */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo do_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    56,                                           /* lineNo */
    5,                                            /* colNo */
    "allLayers",                                  /* aName */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo eo_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    51,                                           /* lineNo */
    5,                                            /* colNo */
    "sldProfiles",                                /* aName */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo fo_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    36,                                           /* lineNo */
    5,                                            /* colNo */
    "Simulation",                                 /* aName */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo go_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    31,                                           /* lineNo */
    5,                                            /* colNo */
    "reflectivity",                               /* aName */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtRTEInfo kn_emlrtRTEI = {
    92,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo ln_emlrtRTEI = {
    93,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo mn_emlrtRTEI = {
    94,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo nn_emlrtRTEI = {
    95,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo on_emlrtRTEI = {
    96,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo pn_emlrtRTEI = {
    97,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo qn_emlrtRTEI = {
    25,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo rn_emlrtRTEI = {
    98,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo sn_emlrtRTEI = {
    101,                                          /* lineNo */
    1,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo tn_emlrtRTEI = {
    1,                                            /* lineNo */
    91,                                           /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo un_emlrtRTEI = {
    29,                                           /* lineNo */
    39,                                           /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo vn_emlrtRTEI = {
    31,                                           /* lineNo */
    5,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo wn_emlrtRTEI = {
    36,                                           /* lineNo */
    5,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo xn_emlrtRTEI = {
    41,                                           /* lineNo */
    5,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo yn_emlrtRTEI = {
    46,                                           /* lineNo */
    5,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo ao_emlrtRTEI = {
    51,                                           /* lineNo */
    5,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo bo_emlrtRTEI = {
    56,                                           /* lineNo */
    5,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo co_emlrtRTEI = {
    102,                                          /* lineNo */
    1,                                            /* colNo */
    "standardTF_custLay_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay_reflectivityCalculation.m" /* pName */
};

/* Function Definitions */
void c_standardTF_custLay_reflectivi(
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
  int32_T exitg1;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  boolean_T b_bool;
  st.prev = sp;
  st.tls = sp->tls;
  /*  Custom layers reflectivity calculation for standardTF */
  /*  This function decides on parallelisation options before calling the */
  /*  relevant version of the main custom layers calculation. It is more */
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
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &vb_emlrtDCI,
                                (emlrtCTX)sp);
  }
  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ub_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->ssubs->size[0];
  loop_ub = (int32_T)problemDef->numberOfContrasts;
  problem->ssubs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->ssubs, i1, &kn_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ub_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->ssubs->data[i1] = 0.0;
  }
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &wb_emlrtDCI,
                            (emlrtCTX)sp);
  }
  loop_ub_tmp = (int32_T)problemDef->numberOfContrasts;
  i1 = problem->backgrounds->size[0];
  problem->backgrounds->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->backgrounds, i1, &ln_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &wb_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->backgrounds->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &xb_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->qshifts->size[0];
  problem->qshifts->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->qshifts, i1, &mn_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &xb_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->qshifts->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &yb_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->scalefactors->size[0];
  problem->scalefactors->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->scalefactors, i1, &nn_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &yb_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->scalefactors->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ac_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->nbairs->size[0];
  problem->nbairs->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->nbairs, i1, &on_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ac_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->nbairs->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &bc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->nbsubs->size[0];
  problem->nbsubs->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->nbsubs, i1, &pn_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &bc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->nbsubs->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &cc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->calculations.all_chis->size[0];
  problem->calculations.all_chis->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->calculations.all_chis, i1,
                           &qn_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &cc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->calculations.all_chis->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &dc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->resolutions->size[0];
  problem->resolutions->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->resolutions, i1, &rn_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &dc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->resolutions->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ec_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->allSubRough->size[0];
  problem->allSubRough->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->allSubRough, i1, &sn_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ec_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->allSubRough->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &tb_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i = reflectivity->size[0];
  reflectivity->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &tn_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    loop_ub = reflectivity->size[0] - 1;
    if (i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, reflectivity->size[0] - 1,
                                    &un_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[i].f1->size[0] = 0;
    if (i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub, &un_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = reflectivity->data[i].f1->size[0] * reflectivity->data[i].f1->size[1];
    reflectivity->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[i].f1, i1, &tn_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &gc_emlrtRTEI, (emlrtCTX)sp);
  i = reflectivity->size[0];
  reflectivity->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &un_emlrtRTEI);
  for (loop_ub = 0; loop_ub < loop_ub_tmp; loop_ub++) {
    if (loop_ub > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, reflectivity->size[0] - 1,
                                    &on_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity->data[loop_ub].f1->size[0] *
        reflectivity->data[loop_ub].f1->size[1];
    reflectivity->data[loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[loop_ub].f1, i,
                             &vn_emlrtRTEI);
    if (loop_ub > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, reflectivity->size[0] - 1,
                                    &on_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity->data[loop_ub].f1->size[0] *
        reflectivity->data[loop_ub].f1->size[1];
    reflectivity->data[loop_ub].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[loop_ub].f1, i,
                             &vn_emlrtRTEI);
    i = reflectivity->size[0];
    if (loop_ub > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, reflectivity->size[0] - 1,
                                    &on_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[loop_ub].f1->data[0] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &go_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    reflectivity->data[loop_ub].f1->data[1] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &go_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    reflectivity->data[loop_ub].f1->data[2] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &go_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    reflectivity->data[loop_ub].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = Simulation->size[0];
  Simulation->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &tn_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    loop_ub = Simulation->size[0] - 1;
    if (i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, Simulation->size[0] - 1, &vn_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation->data[i].f1->size[0] = 0;
    if (i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub, &vn_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = Simulation->data[i].f1->size[0] * Simulation->data[i].f1->size[1];
    Simulation->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[i].f1, i1, &tn_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &hc_emlrtRTEI, (emlrtCTX)sp);
  i = Simulation->size[0];
  Simulation->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &un_emlrtRTEI);
  for (loop_ub = 0; loop_ub < loop_ub_tmp; loop_ub++) {
    if (loop_ub > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, Simulation->size[0] - 1,
                                    &pn_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[loop_ub].f1->size[0] *
        Simulation->data[loop_ub].f1->size[1];
    Simulation->data[loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[loop_ub].f1, i,
                             &wn_emlrtRTEI);
    if (loop_ub > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, Simulation->size[0] - 1,
                                    &pn_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[loop_ub].f1->size[0] *
        Simulation->data[loop_ub].f1->size[1];
    Simulation->data[loop_ub].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[loop_ub].f1, i,
                             &wn_emlrtRTEI);
    i = Simulation->size[0];
    if (loop_ub > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, Simulation->size[0] - 1,
                                    &pn_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[loop_ub].f1->data[0] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &fo_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation->data[loop_ub].f1->data[1] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &fo_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation->data[loop_ub].f1->data[2] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &fo_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation->data[loop_ub].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = shifted_data->size[0];
  shifted_data->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &tn_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    loop_ub = shifted_data->size[0] - 1;
    if (i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, shifted_data->size[0] - 1,
                                    &wn_emlrtBCI, (emlrtCTX)sp);
    }
    shifted_data->data[i].f1->size[0] = 0;
    if (i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub, &wn_emlrtBCI, (emlrtCTX)sp);
    }
    shifted_data->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &ic_emlrtRTEI, (emlrtCTX)sp);
  i = shifted_data->size[0];
  shifted_data->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &un_emlrtRTEI);
  for (loop_ub = 0; loop_ub < loop_ub_tmp; loop_ub++) {
    if (loop_ub > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, shifted_data->size[0] - 1,
                                    &qn_emlrtBCI, (emlrtCTX)sp);
    }
    i = shifted_data->data[loop_ub].f1->size[0] *
        shifted_data->data[loop_ub].f1->size[1];
    shifted_data->data[loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, shifted_data->data[loop_ub].f1, i,
                             &xn_emlrtRTEI);
    if (loop_ub > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, shifted_data->size[0] - 1,
                                    &qn_emlrtBCI, (emlrtCTX)sp);
    }
    i = shifted_data->data[loop_ub].f1->size[0] *
        shifted_data->data[loop_ub].f1->size[1];
    shifted_data->data[loop_ub].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[loop_ub].f1, i,
                             &xn_emlrtRTEI);
    i = shifted_data->size[0];
    if (loop_ub > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, shifted_data->size[0] - 1,
                                    &qn_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 6; i1++) {
      if (loop_ub > i - 1) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &yn_emlrtBCI,
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
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &tn_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    loop_ub = layerSlds->size[0] - 1;
    if (i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, layerSlds->size[0] - 1, &xn_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    layerSlds->data[i].f1->size[0] = 0;
    if (i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub, &xn_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
    layerSlds->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[i].f1, i1, &tn_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &jc_emlrtRTEI, (emlrtCTX)sp);
  i = layerSlds->size[0];
  layerSlds->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &un_emlrtRTEI);
  for (loop_ub = 0; loop_ub < loop_ub_tmp; loop_ub++) {
    if (loop_ub > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, layerSlds->size[0] - 1,
                                    &rn_emlrtBCI, (emlrtCTX)sp);
    }
    i = layerSlds->data[loop_ub].f1->size[0] *
        layerSlds->data[loop_ub].f1->size[1];
    layerSlds->data[loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, layerSlds->data[loop_ub].f1, i, &yn_emlrtRTEI);
    if (loop_ub > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, layerSlds->size[0] - 1,
                                    &rn_emlrtBCI, (emlrtCTX)sp);
    }
    i = layerSlds->data[loop_ub].f1->size[0] *
        layerSlds->data[loop_ub].f1->size[1];
    layerSlds->data[loop_ub].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[loop_ub].f1, i, &yn_emlrtRTEI);
    i = layerSlds->size[0];
    if (loop_ub > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, layerSlds->size[0] - 1,
                                    &rn_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 6; i1++) {
      if (loop_ub > i - 1) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &bo_emlrtBCI,
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
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &tn_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    loop_ub = sldProfiles->size[0] - 1;
    if (i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, sldProfiles->size[0] - 1,
                                    &ao_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[i].f1->size[0] = 0;
    if (i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub, &ao_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &kc_emlrtRTEI, (emlrtCTX)sp);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &un_emlrtRTEI);
  for (loop_ub = 0; loop_ub < loop_ub_tmp; loop_ub++) {
    if (loop_ub > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, sldProfiles->size[0] - 1,
                                    &sn_emlrtBCI, (emlrtCTX)sp);
    }
    i = sldProfiles->data[loop_ub].f1->size[0] *
        sldProfiles->data[loop_ub].f1->size[1];
    sldProfiles->data[loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[loop_ub].f1, i,
                             &ao_emlrtRTEI);
    if (loop_ub > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, sldProfiles->size[0] - 1,
                                    &sn_emlrtBCI, (emlrtCTX)sp);
    }
    i = sldProfiles->data[loop_ub].f1->size[0] *
        sldProfiles->data[loop_ub].f1->size[1];
    sldProfiles->data[loop_ub].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[loop_ub].f1, i,
                             &ao_emlrtRTEI);
    i = sldProfiles->size[0];
    if (loop_ub > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, sldProfiles->size[0] - 1,
                                    &sn_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[loop_ub].f1->data[0] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &eo_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sldProfiles->data[loop_ub].f1->data[1] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &eo_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sldProfiles->data[loop_ub].f1->data[2] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &eo_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sldProfiles->data[loop_ub].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = allLayers->size[0];
  allLayers->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &tn_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    loop_ub = allLayers->size[0] - 1;
    if (i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, allLayers->size[0] - 1, &co_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[i].f1->size[0] = 0;
    if (i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub, &co_emlrtBCI, (emlrtCTX)sp);
    }
    allLayers->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &lc_emlrtRTEI, (emlrtCTX)sp);
  i = allLayers->size[0];
  allLayers->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &un_emlrtRTEI);
  for (loop_ub = 0; loop_ub < loop_ub_tmp; loop_ub++) {
    if (loop_ub > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, allLayers->size[0] - 1,
                                    &tn_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[loop_ub].f1->size[0] *
        allLayers->data[loop_ub].f1->size[1];
    allLayers->data[loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[loop_ub].f1, i, &bo_emlrtRTEI);
    if (loop_ub > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, allLayers->size[0] - 1,
                                    &tn_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[loop_ub].f1->size[0] *
        allLayers->data[loop_ub].f1->size[1];
    allLayers->data[loop_ub].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers->data[loop_ub].f1, i, &bo_emlrtRTEI);
    i = allLayers->size[0];
    if (loop_ub > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, allLayers->size[0] - 1,
                                    &tn_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 6; i1++) {
      if (loop_ub > i - 1) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &do_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      allLayers->data[loop_ub].f1->data[i1] = 1.0;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  /*  End pre-allocation */
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
    st.site = &sh_emlrtRSI;
    standardTF_custlay_single(
        &st, problemDef, problemDef_cells, controls, problem->ssubs,
        problem->backgrounds, problem->qshifts, problem->scalefactors,
        problem->nbairs, problem->nbsubs, problem->resolutions,
        problem->calculations.all_chis, reflectivity, Simulation, shifted_data,
        layerSlds, sldProfiles, allLayers, problem->allSubRough);
    break;
  case 1:
    st.site = &th_emlrtRSI;
    standardTF_custlay_paraPoints(
        &st, problemDef, problemDef_cells, controls, problem->ssubs,
        problem->backgrounds, problem->qshifts, problem->scalefactors,
        problem->nbairs, problem->nbsubs, problem->resolutions,
        problem->calculations.all_chis, reflectivity, Simulation, shifted_data,
        layerSlds, sldProfiles, allLayers, problem->allSubRough);
    break;
  case 2:
    st.site = &uh_emlrtRSI;
    c_standardTF_custlay_paraContra(
        &st, problemDef, problemDef_cells, controls, problem->ssubs,
        problem->backgrounds, problem->qshifts, problem->scalefactors,
        problem->nbairs, problem->nbsubs, problem->resolutions,
        problem->calculations.all_chis, reflectivity, Simulation, shifted_data,
        layerSlds, sldProfiles, allLayers, problem->allSubRough);
    /*            [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
     */
    /*               Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
     */
    /*               allRoughs] =
     * dev_custlay_paraContrasts(problemDef,problemDef_cells,... */
    /*               problemDef_limits,controls); */
    break;
  }
  st.site = &vh_emlrtRSI;
  problem->calculations.sum_chi = sum(&st, problem->calculations.all_chis);
  i = problem->resample->size[0] * problem->resample->size[1];
  problem->resample->size[0] = 1;
  problem->resample->size[1] = problemDef->resample->size[1];
  emxEnsureCapacity_real_T(sp, problem->resample, i, &co_emlrtRTEI);
  loop_ub = problemDef->resample->size[1];
  for (i = 0; i < loop_ub; i++) {
    problem->resample->data[i] = problemDef->resample->data[i];
  }
}

/* End of code generation (standardTF_custLay_reflectivityCalculation.c) */
