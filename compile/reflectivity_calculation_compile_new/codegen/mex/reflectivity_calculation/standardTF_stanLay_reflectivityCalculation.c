/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_stanLay_reflectivityCalculation.c
 *
 * Code generation for function 'standardTF_stanLay_reflectivityCalculation'
 *
 */

/* Include files */
#include "standardTF_stanLay_reflectivityCalculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_stanlay_paraContrasts.h"
#include "standardTF_stanlay_paraPoints.h"
#include "standardTF_stanlay_single.h"
#include "sum.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo k_emlrtRSI = {
    64,                                           /* lineNo */
    "standardTF_stanLay_reflectivityCalculation", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pathName */
};

static emlrtRSInfo l_emlrtRSI = {
    70,                                           /* lineNo */
    "standardTF_stanLay_reflectivityCalculation", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pathName */
};

static emlrtRSInfo m_emlrtRSI = {
    76,                                           /* lineNo */
    "standardTF_stanLay_reflectivityCalculation", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pathName */
};

static emlrtRSInfo n_emlrtRSI = {
    91,                                           /* lineNo */
    "standardTF_stanLay_reflectivityCalculation", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pathName */
};

static emlrtDCInfo g_emlrtDCI = {
    28,                                           /* lineNo */
    21,                                           /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    1                                               /* checkKind */
};

static emlrtRTEInfo u_emlrtRTEI = {
    29,                                           /* lineNo */
    9,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo v_emlrtRTEI = {
    34,                                           /* lineNo */
    9,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo w_emlrtRTEI = {
    39,                                           /* lineNo */
    9,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo x_emlrtRTEI = {
    44,                                           /* lineNo */
    9,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo y_emlrtRTEI = {
    49,                                           /* lineNo */
    9,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    54,                                           /* lineNo */
    9,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

static emlrtBCInfo qc_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    30,                                           /* lineNo */
    18,                                           /* colNo */
    "reflectivity",                               /* aName */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    35,                                           /* lineNo */
    16,                                           /* colNo */
    "Simulation",                                 /* aName */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    40,                                           /* lineNo */
    18,                                           /* colNo */
    "shifted_data",                               /* aName */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    45,                                           /* lineNo */
    15,                                           /* colNo */
    "layerSlds",                                  /* aName */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    50,                                           /* lineNo */
    17,                                           /* colNo */
    "sldProfiles",                                /* aName */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    55,                                           /* lineNo */
    15,                                           /* colNo */
    "allLayers",                                  /* aName */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    0                                               /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    83,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    1                                               /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    83,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    4                                               /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = {
    84,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    1                                               /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = {
    85,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    1                                               /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = {
    86,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    1                                               /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = {
    87,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    1                                               /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = {
    88,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    1                                               /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = {
    24,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    1                                               /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = {
    89,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    1                                               /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = {
    92,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    1                                               /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    28,                                           /* lineNo */
    39,                                           /* colNo */
    "reflectivity",                               /* aName */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    28,                                           /* lineNo */
    39,                                           /* colNo */
    "Simulation",                                 /* aName */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    28,                                           /* lineNo */
    39,                                           /* colNo */
    "shifted_data",                               /* aName */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    28,                                           /* lineNo */
    39,                                           /* colNo */
    "layerSlds",                                  /* aName */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    40,                                           /* lineNo */
    5,                                            /* colNo */
    "shifted_data",                               /* aName */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    28,                                           /* lineNo */
    39,                                           /* colNo */
    "sldProfiles",                                /* aName */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    45,                                           /* lineNo */
    5,                                            /* colNo */
    "layerSlds",                                  /* aName */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    28,                                           /* lineNo */
    39,                                           /* colNo */
    "allLayers",                                  /* aName */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    55,                                           /* lineNo */
    5,                                            /* colNo */
    "allLayers",                                  /* aName */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    50,                                           /* lineNo */
    5,                                            /* colNo */
    "sldProfiles",                                /* aName */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo hd_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    35,                                           /* lineNo */
    5,                                            /* colNo */
    "Simulation",                                 /* aName */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    0                                               /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    30,                                           /* lineNo */
    5,                                            /* colNo */
    "reflectivity",                               /* aName */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m", /* pName */
    0                                               /* checkKind */
};

static emlrtRTEInfo yf_emlrtRTEI = {
    83,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo ag_emlrtRTEI = {
    84,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo bg_emlrtRTEI = {
    85,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo cg_emlrtRTEI = {
    86,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo dg_emlrtRTEI = {
    87,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo eg_emlrtRTEI = {
    88,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo fg_emlrtRTEI = {
    24,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo gg_emlrtRTEI = {
    89,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo hg_emlrtRTEI = {
    92,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo ig_emlrtRTEI = {
    1,                                            /* lineNo */
    91,                                           /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo jg_emlrtRTEI = {
    28,                                           /* lineNo */
    39,                                           /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo kg_emlrtRTEI = {
    30,                                           /* lineNo */
    5,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo lg_emlrtRTEI = {
    35,                                           /* lineNo */
    5,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo mg_emlrtRTEI = {
    40,                                           /* lineNo */
    5,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo ng_emlrtRTEI = {
    45,                                           /* lineNo */
    5,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo og_emlrtRTEI = {
    50,                                           /* lineNo */
    5,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo pg_emlrtRTEI = {
    55,                                           /* lineNo */
    5,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo qg_emlrtRTEI = {
    93,                                           /* lineNo */
    1,                                            /* colNo */
    "standardTF_stanLay_reflectivityCalculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay_reflectivityCalculation.m" /* pName */
};

/* Function Definitions */
void c_standardTF_stanLay_reflectivi(
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
  /*  Standard layers reflectivity calculation for standardTF */
  /*  This function decides on parallelisation options before calling the */
  /*  relevant version ofthe main standard layers calculation. Parallelisation
   */
  /*  is either over the outer loop ('contrasts'), or the inner loop */
  /*  ('points'). The easiest way to do this is to have multiple versions of  */
  /*  the same core calculation, rather than trying to make the paralell */
  /*  for loops conditional (although that would be much neater) There are: */
  /*  points    - parallelise over points in the reflectivity calculation */
  /*  contrasts - parallelise over contrasts (outer for loop) */
  /*  Pre-allocation - It's necessary to */
  /*  pre-define the types for all the arrays */
  /*  for compilation, so do this in this block. */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &i_emlrtDCI,
                                (emlrtCTX)sp);
  }
  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &h_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->ssubs->size[0];
  loop_ub = (int32_T)problemDef->numberOfContrasts;
  problem->ssubs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->ssubs, i1, &yf_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &h_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->ssubs->data[i1] = 0.0;
  }
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &j_emlrtDCI,
                            (emlrtCTX)sp);
  }
  loop_ub_tmp = (int32_T)problemDef->numberOfContrasts;
  i1 = problem->backgrounds->size[0];
  problem->backgrounds->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->backgrounds, i1, &ag_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &j_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->backgrounds->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &k_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->qshifts->size[0];
  problem->qshifts->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->qshifts, i1, &bg_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &k_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->qshifts->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &l_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->scalefactors->size[0];
  problem->scalefactors->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->scalefactors, i1, &cg_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &l_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->scalefactors->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &m_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->nbairs->size[0];
  problem->nbairs->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->nbairs, i1, &dg_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &m_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->nbairs->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &n_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->nbsubs->size[0];
  problem->nbsubs->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->nbsubs, i1, &eg_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &n_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->nbsubs->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &o_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->calculations.all_chis->size[0];
  problem->calculations.all_chis->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->calculations.all_chis, i1,
                           &fg_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &o_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->calculations.all_chis->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &p_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->resolutions->size[0];
  problem->resolutions->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->resolutions, i1, &gg_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &p_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->resolutions->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &q_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = problem->allSubRough->size[0];
  problem->allSubRough->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->allSubRough, i1, &hg_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &q_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->allSubRough->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &g_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i = reflectivity->size[0];
  reflectivity->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &ig_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    loop_ub = reflectivity->size[0] - 1;
    if (i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, reflectivity->size[0] - 1,
                                    &wc_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[i].f1->size[0] = 0;
    if (i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub, &wc_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = reflectivity->data[i].f1->size[0] * reflectivity->data[i].f1->size[1];
    reflectivity->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[i].f1, i1, &ig_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &u_emlrtRTEI, (emlrtCTX)sp);
  i = reflectivity->size[0];
  reflectivity->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &jg_emlrtRTEI);
  for (loop_ub = 0; loop_ub < loop_ub_tmp; loop_ub++) {
    if (loop_ub > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, reflectivity->size[0] - 1,
                                    &qc_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity->data[loop_ub].f1->size[0] *
        reflectivity->data[loop_ub].f1->size[1];
    reflectivity->data[loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[loop_ub].f1, i,
                             &kg_emlrtRTEI);
    if (loop_ub > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, reflectivity->size[0] - 1,
                                    &qc_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity->data[loop_ub].f1->size[0] *
        reflectivity->data[loop_ub].f1->size[1];
    reflectivity->data[loop_ub].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[loop_ub].f1, i,
                             &kg_emlrtRTEI);
    i = reflectivity->size[0];
    if (loop_ub > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, reflectivity->size[0] - 1,
                                    &qc_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[loop_ub].f1->data[0] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &id_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    reflectivity->data[loop_ub].f1->data[1] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &id_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    reflectivity->data[loop_ub].f1->data[2] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &id_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    reflectivity->data[loop_ub].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = Simulation->size[0];
  Simulation->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &ig_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    loop_ub = Simulation->size[0] - 1;
    if (i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, Simulation->size[0] - 1, &xc_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation->data[i].f1->size[0] = 0;
    if (i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub, &xc_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = Simulation->data[i].f1->size[0] * Simulation->data[i].f1->size[1];
    Simulation->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[i].f1, i1, &ig_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &v_emlrtRTEI, (emlrtCTX)sp);
  i = Simulation->size[0];
  Simulation->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &jg_emlrtRTEI);
  for (loop_ub = 0; loop_ub < loop_ub_tmp; loop_ub++) {
    if (loop_ub > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, Simulation->size[0] - 1,
                                    &rc_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[loop_ub].f1->size[0] *
        Simulation->data[loop_ub].f1->size[1];
    Simulation->data[loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[loop_ub].f1, i,
                             &lg_emlrtRTEI);
    if (loop_ub > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, Simulation->size[0] - 1,
                                    &rc_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[loop_ub].f1->size[0] *
        Simulation->data[loop_ub].f1->size[1];
    Simulation->data[loop_ub].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[loop_ub].f1, i,
                             &lg_emlrtRTEI);
    i = Simulation->size[0];
    if (loop_ub > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, Simulation->size[0] - 1,
                                    &rc_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[loop_ub].f1->data[0] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &hd_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation->data[loop_ub].f1->data[1] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &hd_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation->data[loop_ub].f1->data[2] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &hd_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation->data[loop_ub].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = shifted_data->size[0];
  shifted_data->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &ig_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    loop_ub = shifted_data->size[0] - 1;
    if (i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, shifted_data->size[0] - 1,
                                    &yc_emlrtBCI, (emlrtCTX)sp);
    }
    shifted_data->data[i].f1->size[0] = 0;
    if (i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub, &yc_emlrtBCI, (emlrtCTX)sp);
    }
    shifted_data->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &w_emlrtRTEI, (emlrtCTX)sp);
  i = shifted_data->size[0];
  shifted_data->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &jg_emlrtRTEI);
  for (loop_ub = 0; loop_ub < loop_ub_tmp; loop_ub++) {
    if (loop_ub > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, shifted_data->size[0] - 1,
                                    &sc_emlrtBCI, (emlrtCTX)sp);
    }
    i = shifted_data->data[loop_ub].f1->size[0] *
        shifted_data->data[loop_ub].f1->size[1];
    shifted_data->data[loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, shifted_data->data[loop_ub].f1, i,
                             &mg_emlrtRTEI);
    if (loop_ub > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, shifted_data->size[0] - 1,
                                    &sc_emlrtBCI, (emlrtCTX)sp);
    }
    i = shifted_data->data[loop_ub].f1->size[0] *
        shifted_data->data[loop_ub].f1->size[1];
    shifted_data->data[loop_ub].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[loop_ub].f1, i,
                             &mg_emlrtRTEI);
    i = shifted_data->size[0];
    if (loop_ub > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, shifted_data->size[0] - 1,
                                    &sc_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 6; i1++) {
      if (loop_ub > i - 1) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &bd_emlrtBCI,
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
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &ig_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    loop_ub = layerSlds->size[0] - 1;
    if (i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, layerSlds->size[0] - 1, &ad_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    layerSlds->data[i].f1->size[0] = 0;
    if (i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub, &ad_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
    layerSlds->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[i].f1, i1, &ig_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &x_emlrtRTEI, (emlrtCTX)sp);
  i = layerSlds->size[0];
  layerSlds->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &jg_emlrtRTEI);
  for (loop_ub = 0; loop_ub < loop_ub_tmp; loop_ub++) {
    if (loop_ub > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, layerSlds->size[0] - 1,
                                    &tc_emlrtBCI, (emlrtCTX)sp);
    }
    i = layerSlds->data[loop_ub].f1->size[0] *
        layerSlds->data[loop_ub].f1->size[1];
    layerSlds->data[loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, layerSlds->data[loop_ub].f1, i, &ng_emlrtRTEI);
    if (loop_ub > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, layerSlds->size[0] - 1,
                                    &tc_emlrtBCI, (emlrtCTX)sp);
    }
    i = layerSlds->data[loop_ub].f1->size[0] *
        layerSlds->data[loop_ub].f1->size[1];
    layerSlds->data[loop_ub].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[loop_ub].f1, i, &ng_emlrtRTEI);
    i = layerSlds->size[0];
    if (loop_ub > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, layerSlds->size[0] - 1,
                                    &tc_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 6; i1++) {
      if (loop_ub > i - 1) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &dd_emlrtBCI,
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
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &ig_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    loop_ub = sldProfiles->size[0] - 1;
    if (i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, sldProfiles->size[0] - 1,
                                    &cd_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[i].f1->size[0] = 0;
    if (i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub, &cd_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &y_emlrtRTEI, (emlrtCTX)sp);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &jg_emlrtRTEI);
  for (loop_ub = 0; loop_ub < loop_ub_tmp; loop_ub++) {
    if (loop_ub > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, sldProfiles->size[0] - 1,
                                    &uc_emlrtBCI, (emlrtCTX)sp);
    }
    i = sldProfiles->data[loop_ub].f1->size[0] *
        sldProfiles->data[loop_ub].f1->size[1];
    sldProfiles->data[loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[loop_ub].f1, i,
                             &og_emlrtRTEI);
    if (loop_ub > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, sldProfiles->size[0] - 1,
                                    &uc_emlrtBCI, (emlrtCTX)sp);
    }
    i = sldProfiles->data[loop_ub].f1->size[0] *
        sldProfiles->data[loop_ub].f1->size[1];
    sldProfiles->data[loop_ub].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[loop_ub].f1, i,
                             &og_emlrtRTEI);
    i = sldProfiles->size[0];
    if (loop_ub > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, sldProfiles->size[0] - 1,
                                    &uc_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[loop_ub].f1->data[0] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &gd_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sldProfiles->data[loop_ub].f1->data[1] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &gd_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sldProfiles->data[loop_ub].f1->data[2] = 1.0;
    if (loop_ub > i - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &gd_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sldProfiles->data[loop_ub].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = allLayers->size[0];
  allLayers->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &ig_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    loop_ub = allLayers->size[0] - 1;
    if (i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, allLayers->size[0] - 1, &ed_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[i].f1->size[0] = 0;
    if (i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i, 0, loop_ub, &ed_emlrtBCI, (emlrtCTX)sp);
    }
    allLayers->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &ab_emlrtRTEI, (emlrtCTX)sp);
  i = allLayers->size[0];
  allLayers->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &jg_emlrtRTEI);
  for (loop_ub = 0; loop_ub < loop_ub_tmp; loop_ub++) {
    if (loop_ub > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, allLayers->size[0] - 1,
                                    &vc_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[loop_ub].f1->size[0] *
        allLayers->data[loop_ub].f1->size[1];
    allLayers->data[loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[loop_ub].f1, i, &pg_emlrtRTEI);
    if (loop_ub > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, allLayers->size[0] - 1,
                                    &vc_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[loop_ub].f1->size[0] *
        allLayers->data[loop_ub].f1->size[1];
    allLayers->data[loop_ub].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers->data[loop_ub].f1, i, &pg_emlrtRTEI);
    i = allLayers->size[0];
    if (loop_ub > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, allLayers->size[0] - 1,
                                    &vc_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 6; i1++) {
      if (loop_ub > i - 1) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i - 1, &fd_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      allLayers->data[loop_ub].f1->data[i1] = 1.0;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  /*  ------- End type definitions ------------- */
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
    st.site = &k_emlrtRSI;
    standardTF_stanlay_single(
        &st, problemDef, problemDef_cells, controls, problem->ssubs,
        problem->backgrounds, problem->qshifts, problem->scalefactors,
        problem->nbairs, problem->nbsubs, problem->resolutions,
        problem->calculations.all_chis, reflectivity, Simulation, shifted_data,
        layerSlds, sldProfiles, allLayers, problem->allSubRough);
    break;
  case 1:
    st.site = &l_emlrtRSI;
    standardTF_stanlay_paraPoints(
        &st, problemDef, problemDef_cells, controls, problem->ssubs,
        problem->backgrounds, problem->qshifts, problem->scalefactors,
        problem->nbairs, problem->nbsubs, problem->resolutions,
        problem->calculations.all_chis, reflectivity, Simulation, shifted_data,
        layerSlds, sldProfiles, allLayers, problem->allSubRough);
    break;
  case 2:
    st.site = &m_emlrtRSI;
    c_standardTF_stanlay_paraContra(
        &st, problemDef, problemDef_cells, controls, problem->ssubs,
        problem->backgrounds, problem->qshifts, problem->scalefactors,
        problem->nbairs, problem->nbsubs, problem->resolutions,
        problem->calculations.all_chis, reflectivity, Simulation, shifted_data,
        layerSlds, sldProfiles, allLayers, problem->allSubRough);
    break;
  }
  /*  Package everything into one array for tidy output */
  st.site = &n_emlrtRSI;
  problem->calculations.sum_chi = sum(&st, problem->calculations.all_chis);
  i = problem->resample->size[0] * problem->resample->size[1];
  problem->resample->size[0] = 1;
  problem->resample->size[1] = problemDef->resample->size[1];
  emxEnsureCapacity_real_T(sp, problem->resample, i, &qg_emlrtRTEI);
  loop_ub = problemDef->resample->size[1];
  for (i = 0; i < loop_ub; i++) {
    problem->resample->data[i] = problemDef->resample->data[i];
  }
}

/* End of code generation (standardTF_stanLay_reflectivityCalculation.c) */
