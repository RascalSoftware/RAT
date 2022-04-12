/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_reflectivityCalculation.c
 *
 * Code generation for function 'standardTF_reflectivityCalculation'
 *
 */

/* Include files */
#include "standardTF_reflectivityCalculation.h"
#include "eml_int_forloop_overflow_check.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_custLay_reflectivityCalculation.h"
#include "standardTF_custXY_reflectivityCalculation.h"
#include "standardTF_stanLay_reflectivityCalculation.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo b_emlrtRSI = {
    65,                                   /* lineNo */
    "standardTF_reflectivityCalculation", /* fcnName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    68,                                   /* lineNo */
    "standardTF_reflectivityCalculation", /* fcnName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    73,                                   /* lineNo */
    "standardTF_reflectivityCalculation", /* fcnName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    78,                                   /* lineNo */
    "standardTF_reflectivityCalculation", /* fcnName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    16,      /* lineNo */
    "lower", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\strfun\\lower.m" /* pathName
                                                                         */
};

static emlrtRSInfo g_emlrtRSI = {
    10,                     /* lineNo */
    "eml_string_transform", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\strfun\\eml_string_"
    "transform.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    14,                      /* lineNo */
    "assertSupportedString", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\assertSupportedString.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    33,        /* lineNo */
    "inrange", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\assertSupportedString.m" /* pathName */
};

static emlrtDCInfo d_emlrtDCI = {
    23,                                   /* lineNo */
    18,                                   /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m", /* pName */
    4                                           /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    23,                                   /* lineNo */
    18,                                   /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m", /* pName */
    1                                           /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    35,                                   /* lineNo */
    21,                                   /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m", /* pName */
    1                                           /* checkKind */
};

static emlrtRTEInfo m_emlrtRTEI = {
    36,                                   /* lineNo */
    9,                                    /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo n_emlrtRTEI = {
    41,                                   /* lineNo */
    9,                                    /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    46,                                   /* lineNo */
    9,                                    /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    51,                                   /* lineNo */
    9,                                    /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo q_emlrtRTEI = {
    56,                                   /* lineNo */
    9,                                    /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo r_emlrtRTEI = {
    61,                                   /* lineNo */
    9,                                    /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pName */
};

static emlrtBCInfo xb_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    37,                                   /* lineNo */
    18,                                   /* colNo */
    "reflectivity",                       /* aName */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    42,                                   /* lineNo */
    16,                                   /* colNo */
    "Simulation",                         /* aName */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    47,                                   /* lineNo */
    18,                                   /* colNo */
    "shifted_data",                       /* aName */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    52,                                   /* lineNo */
    15,                                   /* colNo */
    "layerSlds",                          /* aName */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    57,                                   /* lineNo */
    17,                                   /* colNo */
    "sldProfiles",                        /* aName */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    62,                                   /* lineNo */
    15,                                   /* colNo */
    "allLayers",                          /* aName */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    35,                                   /* lineNo */
    39,                                   /* colNo */
    "reflectivity",                       /* aName */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    35,                                   /* lineNo */
    39,                                   /* colNo */
    "Simulation",                         /* aName */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    35,                                   /* lineNo */
    39,                                   /* colNo */
    "shifted_data",                       /* aName */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    35,                                   /* lineNo */
    39,                                   /* colNo */
    "layerSlds",                          /* aName */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    47,                                   /* lineNo */
    5,                                    /* colNo */
    "shifted_data",                       /* aName */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    35,                                   /* lineNo */
    39,                                   /* colNo */
    "sldProfiles",                        /* aName */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    52,                                   /* lineNo */
    5,                                    /* colNo */
    "layerSlds",                          /* aName */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    35,                                   /* lineNo */
    39,                                   /* colNo */
    "allLayers",                          /* aName */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    62,                                   /* lineNo */
    5,                                    /* colNo */
    "allLayers",                          /* aName */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    57,                                   /* lineNo */
    5,                                    /* colNo */
    "sldProfiles",                        /* aName */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    42,                                   /* lineNo */
    5,                                    /* colNo */
    "Simulation",                         /* aName */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    37,                                   /* lineNo */
    5,                                    /* colNo */
    "reflectivity",                       /* aName */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m", /* pName */
    0                                           /* checkKind */
};

static emlrtRTEInfo hf_emlrtRTEI = {
    31,                                   /* lineNo */
    51,                                   /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo if_emlrtRTEI = {
    24,                                   /* lineNo */
    1,                                    /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo jf_emlrtRTEI = {
    1,                                    /* lineNo */
    91,                                   /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo kf_emlrtRTEI = {
    35,                                   /* lineNo */
    39,                                   /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo lf_emlrtRTEI = {
    37,                                   /* lineNo */
    5,                                    /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo mf_emlrtRTEI = {
    42,                                   /* lineNo */
    5,                                    /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo nf_emlrtRTEI = {
    47,                                   /* lineNo */
    5,                                    /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo of_emlrtRTEI = {
    52,                                   /* lineNo */
    5,                                    /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo pf_emlrtRTEI = {
    57,                                   /* lineNo */
    5,                                    /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo qf_emlrtRTEI = {
    62,                                   /* lineNo */
    5,                                    /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo rf_emlrtRTEI = {
    65,                                   /* lineNo */
    8,                                    /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo sf_emlrtRTEI = {
    68,                                   /* lineNo */
    10,                                   /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo tf_emlrtRTEI = {
    73,                                   /* lineNo */
    9,                                    /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo uf_emlrtRTEI = {
    78,                                   /* lineNo */
    9,                                    /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo vf_emlrtRTEI = {
    73,                                   /* lineNo */
    10,                                   /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo wf_emlrtRTEI = {
    78,                                   /* lineNo */
    10,                                   /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pName */
};

static emlrtRTEInfo xf_emlrtRTEI = {
    68,                                   /* lineNo */
    9,                                    /* colNo */
    "standardTF_reflectivityCalculation", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_reflectivityCalculation.m" /* pName */
};

/* Function Definitions */
void c_standardTF_reflectivityCalcul(
    const emlrtStack *sp, const struct0_T *problemDef,
    const cell_16 *problemDef_cells, const struct2_T *controls,
    struct4_T *problem, emxArray_cell_wrap_9 *reflectivity,
    emxArray_cell_wrap_9 *Simulation, emxArray_cell_wrap_14 *shifted_data,
    emxArray_cell_wrap_10 *layerSlds, emxArray_cell_wrap_14 *sldProfiles,
    emxArray_cell_wrap_14 *allLayers)
{
  static const char_T b_cv1[13] = {'c', 'u', 's', 't', 'o', 'm', ' ',
                                   'l', 'a', 'y', 'e', 'r', 's'};
  static const char_T cv2[9] = {'c', 'u', 's', 't', 'o', 'm', ' ', 'x', 'y'};
  static const char_T b_cv[6] = {'l', 'a', 'y', 'e', 'r', 's'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_char_T *switch_expression;
  emxArray_int8_T *t0_calculations_all_chis;
  struct_T b_problem;
  struct_T c_problem;
  int32_T exitg1;
  int32_T i;
  int32_T i1;
  int32_T loop_ub_tmp;
  int32_T ns;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /*  Main function for the standardTF reflectivity calculation */
  /*  This function decides what type of model is being analysed and barnches */
  /*  to the correct one. The main options are: */
  /*  layers            - This is the equivalent of Standard Layers in RasCAL */
  /*  Custom Layers     - This is also a layers calculation, but the */
  /*                    specification of the layers is dne using a user defined
   */
  /*                    function. */
  /*  Custom XY         - This also has a model described by a user supplied */
  /*                    function, but in this case the function generates an */
  /*                    SLD profile (i.e. XY function) rather than a list of */
  /*                    layers. */
  /*  Find out the model type from the input structs */
  /*  Pre-allocate the output arrays.. this is necessary because otherwise */
  /*  the compiler complains with 'Output argument <....> is not assigned on  */
  /*  some execution paths' error. */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &d_emlrtDCI,
                                (emlrtCTX)sp);
  }
  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &e_emlrtDCI,
                            (emlrtCTX)sp);
  }
  emxInit_int8_T(sp, &t0_calculations_all_chis, 1, &jf_emlrtRTEI, true);
  loop_ub_tmp = (int32_T)problemDef->numberOfContrasts;
  i1 = t0_calculations_all_chis->size[0];
  t0_calculations_all_chis->size[0] = loop_ub_tmp;
  emxEnsureCapacity_int8_T(sp, t0_calculations_all_chis, i1, &hf_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    t0_calculations_all_chis->data[i1] = 0;
  }
  i1 = problem->ssubs->size[0];
  problem->ssubs->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->ssubs, i1, &if_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->ssubs->data[i1] = 0.0;
  }
  i1 = problem->backgrounds->size[0];
  problem->backgrounds->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->backgrounds, i1, &if_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->backgrounds->data[i1] = 0.0;
  }
  i1 = problem->qshifts->size[0];
  problem->qshifts->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->qshifts, i1, &if_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->qshifts->data[i1] = 0.0;
  }
  i1 = problem->scalefactors->size[0];
  problem->scalefactors->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->scalefactors, i1, &if_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->scalefactors->data[i1] = 0.0;
  }
  i1 = problem->nbairs->size[0];
  problem->nbairs->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->nbairs, i1, &if_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->nbairs->data[i1] = 0.0;
  }
  i1 = problem->nbsubs->size[0];
  problem->nbsubs->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->nbsubs, i1, &if_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->nbsubs->data[i1] = 0.0;
  }
  i1 = problem->resolutions->size[0];
  problem->resolutions->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->resolutions, i1, &if_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->resolutions->data[i1] = 0.0;
  }
  i1 = problem->calculations.all_chis->size[0];
  problem->calculations.all_chis->size[0] = t0_calculations_all_chis->size[0];
  emxEnsureCapacity_real_T(sp, problem->calculations.all_chis, i1,
                           &if_emlrtRTEI);
  ns = t0_calculations_all_chis->size[0];
  emxFree_int8_T(&t0_calculations_all_chis);
  for (i1 = 0; i1 < ns; i1++) {
    problem->calculations.all_chis->data[i1] = 0.0;
  }
  problem->calculations.sum_chi = 0.0;
  i1 = problem->allSubRough->size[0];
  problem->allSubRough->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, problem->allSubRough, i1, &if_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->allSubRough->data[i1] = 0.0;
  }
  i1 = problem->resample->size[0] * problem->resample->size[1];
  problem->resample->size[0] = loop_ub_tmp;
  problem->resample->size[1] = 1;
  emxEnsureCapacity_real_T(sp, problem->resample, i1, &if_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->resample->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &f_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i = reflectivity->size[0];
  reflectivity->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &jf_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    ns = reflectivity->size[0] - 1;
    if (i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, reflectivity->size[0] - 1,
                                    &ec_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[i].f1->size[0] = 0;
    if (i > ns) {
      emlrtDynamicBoundsCheckR2012b(i, 0, ns, &ec_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = reflectivity->data[i].f1->size[0] * reflectivity->data[i].f1->size[1];
    reflectivity->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[i].f1, i1, &jf_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &m_emlrtRTEI, (emlrtCTX)sp);
  i = reflectivity->size[0];
  reflectivity->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &kf_emlrtRTEI);
  for (ns = 0; ns < loop_ub_tmp; ns++) {
    if (ns > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, reflectivity->size[0] - 1,
                                    &xb_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity->data[ns].f1->size[0] * reflectivity->data[ns].f1->size[1];
    reflectivity->data[ns].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[ns].f1, i, &lf_emlrtRTEI);
    if (ns > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, reflectivity->size[0] - 1,
                                    &xb_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity->data[ns].f1->size[0] * reflectivity->data[ns].f1->size[1];
    reflectivity->data[ns].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[ns].f1, i, &lf_emlrtRTEI);
    i = reflectivity->size[0];
    if (ns > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, reflectivity->size[0] - 1,
                                    &xb_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[ns].f1->data[0] = 1.0;
    if (ns > i - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, i - 1, &pc_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[ns].f1->data[1] = 1.0;
    if (ns > i - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, i - 1, &pc_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[ns].f1->data[2] = 1.0;
    if (ns > i - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, i - 1, &pc_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[ns].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = Simulation->size[0];
  Simulation->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &jf_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    ns = Simulation->size[0] - 1;
    if (i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, Simulation->size[0] - 1, &fc_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation->data[i].f1->size[0] = 0;
    if (i > ns) {
      emlrtDynamicBoundsCheckR2012b(i, 0, ns, &fc_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = Simulation->data[i].f1->size[0] * Simulation->data[i].f1->size[1];
    Simulation->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[i].f1, i1, &jf_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &n_emlrtRTEI, (emlrtCTX)sp);
  i = Simulation->size[0];
  Simulation->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &kf_emlrtRTEI);
  for (ns = 0; ns < loop_ub_tmp; ns++) {
    if (ns > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, Simulation->size[0] - 1,
                                    &yb_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[ns].f1->size[0] * Simulation->data[ns].f1->size[1];
    Simulation->data[ns].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[ns].f1, i, &mf_emlrtRTEI);
    if (ns > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, Simulation->size[0] - 1,
                                    &yb_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[ns].f1->size[0] * Simulation->data[ns].f1->size[1];
    Simulation->data[ns].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[ns].f1, i, &mf_emlrtRTEI);
    i = Simulation->size[0];
    if (ns > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, Simulation->size[0] - 1,
                                    &yb_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[ns].f1->data[0] = 1.0;
    if (ns > i - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, i - 1, &oc_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[ns].f1->data[1] = 1.0;
    if (ns > i - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, i - 1, &oc_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[ns].f1->data[2] = 1.0;
    if (ns > i - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, i - 1, &oc_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[ns].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = shifted_data->size[0];
  shifted_data->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &jf_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    ns = shifted_data->size[0] - 1;
    if (i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, shifted_data->size[0] - 1,
                                    &gc_emlrtBCI, (emlrtCTX)sp);
    }
    shifted_data->data[i].f1->size[0] = 0;
    if (i > ns) {
      emlrtDynamicBoundsCheckR2012b(i, 0, ns, &gc_emlrtBCI, (emlrtCTX)sp);
    }
    shifted_data->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &o_emlrtRTEI, (emlrtCTX)sp);
  i = shifted_data->size[0];
  shifted_data->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &kf_emlrtRTEI);
  for (ns = 0; ns < loop_ub_tmp; ns++) {
    if (ns > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, shifted_data->size[0] - 1,
                                    &ac_emlrtBCI, (emlrtCTX)sp);
    }
    i = shifted_data->data[ns].f1->size[0] * shifted_data->data[ns].f1->size[1];
    shifted_data->data[ns].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, shifted_data->data[ns].f1, i, &nf_emlrtRTEI);
    if (ns > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, shifted_data->size[0] - 1,
                                    &ac_emlrtBCI, (emlrtCTX)sp);
    }
    i = shifted_data->data[ns].f1->size[0] * shifted_data->data[ns].f1->size[1];
    shifted_data->data[ns].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[ns].f1, i, &nf_emlrtRTEI);
    i = shifted_data->size[0];
    if (ns > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, shifted_data->size[0] - 1,
                                    &ac_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 6; i1++) {
      if (ns > i - 1) {
        emlrtDynamicBoundsCheckR2012b(ns, 0, i - 1, &ic_emlrtBCI, (emlrtCTX)sp);
      }
      shifted_data->data[ns].f1->data[i1] = 1.0;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = layerSlds->size[0];
  layerSlds->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &jf_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    ns = layerSlds->size[0] - 1;
    if (i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, layerSlds->size[0] - 1, &hc_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    layerSlds->data[i].f1->size[0] = 0;
    if (i > ns) {
      emlrtDynamicBoundsCheckR2012b(i, 0, ns, &hc_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
    layerSlds->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[i].f1, i1, &jf_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &p_emlrtRTEI, (emlrtCTX)sp);
  i = layerSlds->size[0];
  layerSlds->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &kf_emlrtRTEI);
  for (ns = 0; ns < loop_ub_tmp; ns++) {
    if (ns > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, layerSlds->size[0] - 1, &bc_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i = layerSlds->data[ns].f1->size[0] * layerSlds->data[ns].f1->size[1];
    layerSlds->data[ns].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, layerSlds->data[ns].f1, i, &of_emlrtRTEI);
    if (ns > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, layerSlds->size[0] - 1, &bc_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i = layerSlds->data[ns].f1->size[0] * layerSlds->data[ns].f1->size[1];
    layerSlds->data[ns].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[ns].f1, i, &of_emlrtRTEI);
    i = layerSlds->size[0];
    if (ns > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, layerSlds->size[0] - 1, &bc_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 6; i1++) {
      if (ns > i - 1) {
        emlrtDynamicBoundsCheckR2012b(ns, 0, i - 1, &kc_emlrtBCI, (emlrtCTX)sp);
      }
      layerSlds->data[ns].f1->data[i1] = 1.0;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = sldProfiles->size[0];
  sldProfiles->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &jf_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    ns = sldProfiles->size[0] - 1;
    if (i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, sldProfiles->size[0] - 1,
                                    &jc_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[i].f1->size[0] = 0;
    if (i > ns) {
      emlrtDynamicBoundsCheckR2012b(i, 0, ns, &jc_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &q_emlrtRTEI, (emlrtCTX)sp);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &kf_emlrtRTEI);
  for (ns = 0; ns < loop_ub_tmp; ns++) {
    if (ns > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, sldProfiles->size[0] - 1,
                                    &cc_emlrtBCI, (emlrtCTX)sp);
    }
    i = sldProfiles->data[ns].f1->size[0] * sldProfiles->data[ns].f1->size[1];
    sldProfiles->data[ns].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[ns].f1, i, &pf_emlrtRTEI);
    if (ns > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, sldProfiles->size[0] - 1,
                                    &cc_emlrtBCI, (emlrtCTX)sp);
    }
    i = sldProfiles->data[ns].f1->size[0] * sldProfiles->data[ns].f1->size[1];
    sldProfiles->data[ns].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[ns].f1, i, &pf_emlrtRTEI);
    i = sldProfiles->size[0];
    if (ns > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, sldProfiles->size[0] - 1,
                                    &cc_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[ns].f1->data[0] = 1.0;
    if (ns > i - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, i - 1, &nc_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[ns].f1->data[1] = 1.0;
    if (ns > i - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, i - 1, &nc_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[ns].f1->data[2] = 1.0;
    if (ns > i - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, i - 1, &nc_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[ns].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = allLayers->size[0];
  allLayers->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &jf_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    ns = allLayers->size[0] - 1;
    if (i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, allLayers->size[0] - 1, &lc_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[i].f1->size[0] = 0;
    if (i > ns) {
      emlrtDynamicBoundsCheckR2012b(i, 0, ns, &lc_emlrtBCI, (emlrtCTX)sp);
    }
    allLayers->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &r_emlrtRTEI, (emlrtCTX)sp);
  i = allLayers->size[0];
  allLayers->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &kf_emlrtRTEI);
  for (ns = 0; ns < loop_ub_tmp; ns++) {
    if (ns > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, allLayers->size[0] - 1, &dc_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i = allLayers->data[ns].f1->size[0] * allLayers->data[ns].f1->size[1];
    allLayers->data[ns].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[ns].f1, i, &qf_emlrtRTEI);
    if (ns > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, allLayers->size[0] - 1, &dc_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i = allLayers->data[ns].f1->size[0] * allLayers->data[ns].f1->size[1];
    allLayers->data[ns].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers->data[ns].f1, i, &qf_emlrtRTEI);
    i = allLayers->size[0];
    if (ns > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(ns, 0, allLayers->size[0] - 1, &dc_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 6; i1++) {
      if (ns > i - 1) {
        emlrtDynamicBoundsCheckR2012b(ns, 0, i - 1, &mc_emlrtBCI, (emlrtCTX)sp);
      }
      allLayers->data[ns].f1->data[i1] = 1.0;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  st.site = &b_emlrtRSI;
  b_st.site = &f_emlrtRSI;
  c_st.site = &g_emlrtRSI;
  d_st.site = &h_emlrtRSI;
  ns = problemDef->modelType->size[1];
  p = true;
  e_st.site = &i_emlrtRSI;
  if ((1 <= problemDef->modelType->size[1]) &&
      (problemDef->modelType->size[1] > 2147483646)) {
    f_st.site = &j_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }
  for (loop_ub_tmp = 0; loop_ub_tmp < ns; loop_ub_tmp++) {
    p = (p && ((uint8_T)problemDef->modelType->data[loop_ub_tmp] <= 127));
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &s_emlrtRTEI, "Coder:toolbox:unsupportedString",
        "Coder:toolbox:unsupportedString", 2, 12, 127);
  }
  emxInit_char_T(&c_st, &switch_expression, 2, &rf_emlrtRTEI, true);
  i = switch_expression->size[0] * switch_expression->size[1];
  switch_expression->size[0] = 1;
  switch_expression->size[1] = problemDef->modelType->size[1];
  emxEnsureCapacity_char_T(&b_st, switch_expression, i, &rf_emlrtRTEI);
  i = problemDef->modelType->size[1];
  for (loop_ub_tmp = 0; loop_ub_tmp < i; loop_ub_tmp++) {
    switch_expression->data[loop_ub_tmp] =
        cv[(uint8_T)problemDef->modelType->data[loop_ub_tmp] & 127];
  }
  p = false;
  if (switch_expression->size[1] == 6) {
    ns = 0;
    do {
      exitg1 = 0;
      if (ns < 6) {
        if (switch_expression->data[ns] != b_cv[ns]) {
          exitg1 = 1;
        } else {
          ns++;
        }
      } else {
        p = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (p) {
    ns = 0;
  } else {
    p = false;
    if (switch_expression->size[1] == 13) {
      ns = 0;
      do {
        exitg1 = 0;
        if (ns < 13) {
          if (switch_expression->data[ns] != b_cv1[ns]) {
            exitg1 = 1;
          } else {
            ns++;
          }
        } else {
          p = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (p) {
      ns = 1;
    } else {
      p = false;
      if (switch_expression->size[1] == 9) {
        ns = 0;
        do {
          exitg1 = 0;
          if (ns < 9) {
            if (switch_expression->data[ns] != cv2[ns]) {
              exitg1 = 1;
            } else {
              ns++;
            }
          } else {
            p = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (p) {
        ns = 2;
      } else {
        ns = -1;
      }
    }
  }
  emxFree_char_T(&switch_expression);
  emxInitStruct_struct_T(sp, &b_problem, &xf_emlrtRTEI, true);
  emxInitStruct_struct_T(sp, &c_problem, &tf_emlrtRTEI, true);
  switch (ns) {
  case 0:
    /*  Standard layers calculation */
    st.site = &c_emlrtRSI;
    c_standardTF_stanLay_reflectivi(
        &st, problemDef, problemDef_cells, controls, &b_problem, reflectivity,
        Simulation, shifted_data, layerSlds, sldProfiles, allLayers);
    i = problem->ssubs->size[0];
    problem->ssubs->size[0] = b_problem.ssubs->size[0];
    emxEnsureCapacity_real_T(sp, problem->ssubs, i, &sf_emlrtRTEI);
    ns = b_problem.ssubs->size[0];
    for (i = 0; i < ns; i++) {
      problem->ssubs->data[i] = b_problem.ssubs->data[i];
    }
    i = problem->backgrounds->size[0];
    problem->backgrounds->size[0] = b_problem.backgrounds->size[0];
    emxEnsureCapacity_real_T(sp, problem->backgrounds, i, &sf_emlrtRTEI);
    ns = b_problem.backgrounds->size[0];
    for (i = 0; i < ns; i++) {
      problem->backgrounds->data[i] = b_problem.backgrounds->data[i];
    }
    i = problem->qshifts->size[0];
    problem->qshifts->size[0] = b_problem.qshifts->size[0];
    emxEnsureCapacity_real_T(sp, problem->qshifts, i, &sf_emlrtRTEI);
    ns = b_problem.qshifts->size[0];
    for (i = 0; i < ns; i++) {
      problem->qshifts->data[i] = b_problem.qshifts->data[i];
    }
    i = problem->scalefactors->size[0];
    problem->scalefactors->size[0] = b_problem.scalefactors->size[0];
    emxEnsureCapacity_real_T(sp, problem->scalefactors, i, &sf_emlrtRTEI);
    ns = b_problem.scalefactors->size[0];
    for (i = 0; i < ns; i++) {
      problem->scalefactors->data[i] = b_problem.scalefactors->data[i];
    }
    i = problem->nbairs->size[0];
    problem->nbairs->size[0] = b_problem.nbairs->size[0];
    emxEnsureCapacity_real_T(sp, problem->nbairs, i, &sf_emlrtRTEI);
    ns = b_problem.nbairs->size[0];
    for (i = 0; i < ns; i++) {
      problem->nbairs->data[i] = b_problem.nbairs->data[i];
    }
    i = problem->nbsubs->size[0];
    problem->nbsubs->size[0] = b_problem.nbsubs->size[0];
    emxEnsureCapacity_real_T(sp, problem->nbsubs, i, &sf_emlrtRTEI);
    ns = b_problem.nbsubs->size[0];
    for (i = 0; i < ns; i++) {
      problem->nbsubs->data[i] = b_problem.nbsubs->data[i];
    }
    i = problem->resolutions->size[0];
    problem->resolutions->size[0] = b_problem.resolutions->size[0];
    emxEnsureCapacity_real_T(sp, problem->resolutions, i, &sf_emlrtRTEI);
    ns = b_problem.resolutions->size[0];
    for (i = 0; i < ns; i++) {
      problem->resolutions->data[i] = b_problem.resolutions->data[i];
    }
    emxCopyStruct_struct5_T(sp, &problem->calculations, &b_problem.calculations,
                            &sf_emlrtRTEI);
    i = problem->allSubRough->size[0];
    problem->allSubRough->size[0] = b_problem.allSubRough->size[0];
    emxEnsureCapacity_real_T(sp, problem->allSubRough, i, &sf_emlrtRTEI);
    ns = b_problem.allSubRough->size[0];
    for (i = 0; i < ns; i++) {
      problem->allSubRough->data[i] = b_problem.allSubRough->data[i];
    }
    i = problem->resample->size[0] * problem->resample->size[1];
    problem->resample->size[0] = 1;
    problem->resample->size[1] = b_problem.resample->size[1];
    emxEnsureCapacity_real_T(sp, problem->resample, i, &sf_emlrtRTEI);
    ns = b_problem.resample->size[1];
    for (i = 0; i < ns; i++) {
      problem->resample->data[i] = b_problem.resample->data[i];
    }
    break;
  case 1:
    /*  Custom layers with user supplied custom model file */
    st.site = &d_emlrtRSI;
    c_standardTF_custLay_reflectivi(
        &st, problemDef, problemDef_cells, controls, &c_problem, reflectivity,
        Simulation, shifted_data, layerSlds, sldProfiles, allLayers);
    i = b_problem.ssubs->size[0];
    b_problem.ssubs->size[0] = c_problem.ssubs->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.ssubs, i, &tf_emlrtRTEI);
    ns = c_problem.ssubs->size[0];
    for (i = 0; i < ns; i++) {
      b_problem.ssubs->data[i] = c_problem.ssubs->data[i];
    }
    i = b_problem.backgrounds->size[0];
    b_problem.backgrounds->size[0] = c_problem.backgrounds->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.backgrounds, i, &tf_emlrtRTEI);
    ns = c_problem.backgrounds->size[0];
    for (i = 0; i < ns; i++) {
      b_problem.backgrounds->data[i] = c_problem.backgrounds->data[i];
    }
    i = b_problem.qshifts->size[0];
    b_problem.qshifts->size[0] = c_problem.qshifts->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.qshifts, i, &tf_emlrtRTEI);
    ns = c_problem.qshifts->size[0];
    for (i = 0; i < ns; i++) {
      b_problem.qshifts->data[i] = c_problem.qshifts->data[i];
    }
    i = b_problem.scalefactors->size[0];
    b_problem.scalefactors->size[0] = c_problem.scalefactors->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.scalefactors, i, &tf_emlrtRTEI);
    ns = c_problem.scalefactors->size[0];
    for (i = 0; i < ns; i++) {
      b_problem.scalefactors->data[i] = c_problem.scalefactors->data[i];
    }
    i = b_problem.nbairs->size[0];
    b_problem.nbairs->size[0] = c_problem.nbairs->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.nbairs, i, &tf_emlrtRTEI);
    ns = c_problem.nbairs->size[0];
    for (i = 0; i < ns; i++) {
      b_problem.nbairs->data[i] = c_problem.nbairs->data[i];
    }
    i = b_problem.nbsubs->size[0];
    b_problem.nbsubs->size[0] = c_problem.nbsubs->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.nbsubs, i, &tf_emlrtRTEI);
    ns = c_problem.nbsubs->size[0];
    for (i = 0; i < ns; i++) {
      b_problem.nbsubs->data[i] = c_problem.nbsubs->data[i];
    }
    i = b_problem.resolutions->size[0];
    b_problem.resolutions->size[0] = c_problem.resolutions->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.resolutions, i, &tf_emlrtRTEI);
    ns = c_problem.resolutions->size[0];
    for (i = 0; i < ns; i++) {
      b_problem.resolutions->data[i] = c_problem.resolutions->data[i];
    }
    i = b_problem.allSubRough->size[0];
    b_problem.allSubRough->size[0] = c_problem.allSubRough->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.allSubRough, i, &tf_emlrtRTEI);
    ns = c_problem.allSubRough->size[0];
    for (i = 0; i < ns; i++) {
      b_problem.allSubRough->data[i] = c_problem.allSubRough->data[i];
    }
    i = b_problem.resample->size[0] * b_problem.resample->size[1];
    b_problem.resample->size[0] = 1;
    b_problem.resample->size[1] = c_problem.resample->size[1];
    emxEnsureCapacity_real_T(sp, b_problem.resample, i, &tf_emlrtRTEI);
    ns = c_problem.resample->size[1];
    for (i = 0; i < ns; i++) {
      b_problem.resample->data[i] = c_problem.resample->data[i];
    }
    i = problem->ssubs->size[0];
    problem->ssubs->size[0] = b_problem.ssubs->size[0];
    emxEnsureCapacity_real_T(sp, problem->ssubs, i, &vf_emlrtRTEI);
    ns = b_problem.ssubs->size[0];
    for (i = 0; i < ns; i++) {
      problem->ssubs->data[i] = b_problem.ssubs->data[i];
    }
    i = problem->backgrounds->size[0];
    problem->backgrounds->size[0] = b_problem.backgrounds->size[0];
    emxEnsureCapacity_real_T(sp, problem->backgrounds, i, &vf_emlrtRTEI);
    ns = b_problem.backgrounds->size[0];
    for (i = 0; i < ns; i++) {
      problem->backgrounds->data[i] = b_problem.backgrounds->data[i];
    }
    i = problem->qshifts->size[0];
    problem->qshifts->size[0] = b_problem.qshifts->size[0];
    emxEnsureCapacity_real_T(sp, problem->qshifts, i, &vf_emlrtRTEI);
    ns = b_problem.qshifts->size[0];
    for (i = 0; i < ns; i++) {
      problem->qshifts->data[i] = b_problem.qshifts->data[i];
    }
    i = problem->scalefactors->size[0];
    problem->scalefactors->size[0] = b_problem.scalefactors->size[0];
    emxEnsureCapacity_real_T(sp, problem->scalefactors, i, &vf_emlrtRTEI);
    ns = b_problem.scalefactors->size[0];
    for (i = 0; i < ns; i++) {
      problem->scalefactors->data[i] = b_problem.scalefactors->data[i];
    }
    i = problem->nbairs->size[0];
    problem->nbairs->size[0] = b_problem.nbairs->size[0];
    emxEnsureCapacity_real_T(sp, problem->nbairs, i, &vf_emlrtRTEI);
    ns = b_problem.nbairs->size[0];
    for (i = 0; i < ns; i++) {
      problem->nbairs->data[i] = b_problem.nbairs->data[i];
    }
    i = problem->nbsubs->size[0];
    problem->nbsubs->size[0] = b_problem.nbsubs->size[0];
    emxEnsureCapacity_real_T(sp, problem->nbsubs, i, &vf_emlrtRTEI);
    ns = b_problem.nbsubs->size[0];
    for (i = 0; i < ns; i++) {
      problem->nbsubs->data[i] = b_problem.nbsubs->data[i];
    }
    i = problem->resolutions->size[0];
    problem->resolutions->size[0] = b_problem.resolutions->size[0];
    emxEnsureCapacity_real_T(sp, problem->resolutions, i, &vf_emlrtRTEI);
    ns = b_problem.resolutions->size[0];
    for (i = 0; i < ns; i++) {
      problem->resolutions->data[i] = b_problem.resolutions->data[i];
    }
    emxCopyStruct_struct5_T(sp, &problem->calculations, &c_problem.calculations,
                            &vf_emlrtRTEI);
    i = problem->allSubRough->size[0];
    problem->allSubRough->size[0] = b_problem.allSubRough->size[0];
    emxEnsureCapacity_real_T(sp, problem->allSubRough, i, &vf_emlrtRTEI);
    ns = b_problem.allSubRough->size[0];
    for (i = 0; i < ns; i++) {
      problem->allSubRough->data[i] = b_problem.allSubRough->data[i];
    }
    i = problem->resample->size[0] * problem->resample->size[1];
    problem->resample->size[0] = 1;
    problem->resample->size[1] = b_problem.resample->size[1];
    emxEnsureCapacity_real_T(sp, problem->resample, i, &sf_emlrtRTEI);
    ns = b_problem.resample->size[1];
    for (i = 0; i < ns; i++) {
      problem->resample->data[i] = b_problem.resample->data[i];
    }
    break;
  case 2:
    /*  Custom SLD profile with user defined model file */
    st.site = &e_emlrtRSI;
    c_standardTF_custXY_reflectivit(
        &st, problemDef, problemDef_cells, controls, &c_problem, reflectivity,
        Simulation, shifted_data, layerSlds, sldProfiles, allLayers);
    i = b_problem.ssubs->size[0];
    b_problem.ssubs->size[0] = c_problem.ssubs->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.ssubs, i, &uf_emlrtRTEI);
    ns = c_problem.ssubs->size[0];
    for (i = 0; i < ns; i++) {
      b_problem.ssubs->data[i] = c_problem.ssubs->data[i];
    }
    i = b_problem.backgrounds->size[0];
    b_problem.backgrounds->size[0] = c_problem.backgrounds->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.backgrounds, i, &uf_emlrtRTEI);
    ns = c_problem.backgrounds->size[0];
    for (i = 0; i < ns; i++) {
      b_problem.backgrounds->data[i] = c_problem.backgrounds->data[i];
    }
    i = b_problem.qshifts->size[0];
    b_problem.qshifts->size[0] = c_problem.qshifts->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.qshifts, i, &uf_emlrtRTEI);
    ns = c_problem.qshifts->size[0];
    for (i = 0; i < ns; i++) {
      b_problem.qshifts->data[i] = c_problem.qshifts->data[i];
    }
    i = b_problem.scalefactors->size[0];
    b_problem.scalefactors->size[0] = c_problem.scalefactors->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.scalefactors, i, &uf_emlrtRTEI);
    ns = c_problem.scalefactors->size[0];
    for (i = 0; i < ns; i++) {
      b_problem.scalefactors->data[i] = c_problem.scalefactors->data[i];
    }
    i = b_problem.nbairs->size[0];
    b_problem.nbairs->size[0] = c_problem.nbairs->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.nbairs, i, &uf_emlrtRTEI);
    ns = c_problem.nbairs->size[0];
    for (i = 0; i < ns; i++) {
      b_problem.nbairs->data[i] = c_problem.nbairs->data[i];
    }
    i = b_problem.nbsubs->size[0];
    b_problem.nbsubs->size[0] = c_problem.nbsubs->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.nbsubs, i, &uf_emlrtRTEI);
    ns = c_problem.nbsubs->size[0];
    for (i = 0; i < ns; i++) {
      b_problem.nbsubs->data[i] = c_problem.nbsubs->data[i];
    }
    i = b_problem.resolutions->size[0];
    b_problem.resolutions->size[0] = c_problem.resolutions->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.resolutions, i, &uf_emlrtRTEI);
    ns = c_problem.resolutions->size[0];
    for (i = 0; i < ns; i++) {
      b_problem.resolutions->data[i] = c_problem.resolutions->data[i];
    }
    i = b_problem.allSubRough->size[0];
    b_problem.allSubRough->size[0] = c_problem.allSubRough->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.allSubRough, i, &uf_emlrtRTEI);
    ns = c_problem.allSubRough->size[0];
    for (i = 0; i < ns; i++) {
      b_problem.allSubRough->data[i] = c_problem.allSubRough->data[i];
    }
    i = b_problem.resample->size[0] * b_problem.resample->size[1];
    b_problem.resample->size[0] = 1;
    b_problem.resample->size[1] = c_problem.resample->size[1];
    emxEnsureCapacity_real_T(sp, b_problem.resample, i, &uf_emlrtRTEI);
    ns = c_problem.resample->size[1];
    for (i = 0; i < ns; i++) {
      b_problem.resample->data[i] = c_problem.resample->data[i];
    }
    i = problem->ssubs->size[0];
    problem->ssubs->size[0] = b_problem.ssubs->size[0];
    emxEnsureCapacity_real_T(sp, problem->ssubs, i, &wf_emlrtRTEI);
    ns = b_problem.ssubs->size[0];
    for (i = 0; i < ns; i++) {
      problem->ssubs->data[i] = b_problem.ssubs->data[i];
    }
    i = problem->backgrounds->size[0];
    problem->backgrounds->size[0] = b_problem.backgrounds->size[0];
    emxEnsureCapacity_real_T(sp, problem->backgrounds, i, &wf_emlrtRTEI);
    ns = b_problem.backgrounds->size[0];
    for (i = 0; i < ns; i++) {
      problem->backgrounds->data[i] = b_problem.backgrounds->data[i];
    }
    i = problem->qshifts->size[0];
    problem->qshifts->size[0] = b_problem.qshifts->size[0];
    emxEnsureCapacity_real_T(sp, problem->qshifts, i, &wf_emlrtRTEI);
    ns = b_problem.qshifts->size[0];
    for (i = 0; i < ns; i++) {
      problem->qshifts->data[i] = b_problem.qshifts->data[i];
    }
    i = problem->scalefactors->size[0];
    problem->scalefactors->size[0] = b_problem.scalefactors->size[0];
    emxEnsureCapacity_real_T(sp, problem->scalefactors, i, &wf_emlrtRTEI);
    ns = b_problem.scalefactors->size[0];
    for (i = 0; i < ns; i++) {
      problem->scalefactors->data[i] = b_problem.scalefactors->data[i];
    }
    i = problem->nbairs->size[0];
    problem->nbairs->size[0] = b_problem.nbairs->size[0];
    emxEnsureCapacity_real_T(sp, problem->nbairs, i, &wf_emlrtRTEI);
    ns = b_problem.nbairs->size[0];
    for (i = 0; i < ns; i++) {
      problem->nbairs->data[i] = b_problem.nbairs->data[i];
    }
    i = problem->nbsubs->size[0];
    problem->nbsubs->size[0] = b_problem.nbsubs->size[0];
    emxEnsureCapacity_real_T(sp, problem->nbsubs, i, &wf_emlrtRTEI);
    ns = b_problem.nbsubs->size[0];
    for (i = 0; i < ns; i++) {
      problem->nbsubs->data[i] = b_problem.nbsubs->data[i];
    }
    i = problem->resolutions->size[0];
    problem->resolutions->size[0] = b_problem.resolutions->size[0];
    emxEnsureCapacity_real_T(sp, problem->resolutions, i, &wf_emlrtRTEI);
    ns = b_problem.resolutions->size[0];
    for (i = 0; i < ns; i++) {
      problem->resolutions->data[i] = b_problem.resolutions->data[i];
    }
    emxCopyStruct_struct5_T(sp, &problem->calculations, &c_problem.calculations,
                            &wf_emlrtRTEI);
    i = problem->allSubRough->size[0];
    problem->allSubRough->size[0] = b_problem.allSubRough->size[0];
    emxEnsureCapacity_real_T(sp, problem->allSubRough, i, &wf_emlrtRTEI);
    ns = b_problem.allSubRough->size[0];
    for (i = 0; i < ns; i++) {
      problem->allSubRough->data[i] = b_problem.allSubRough->data[i];
    }
    i = problem->resample->size[0] * problem->resample->size[1];
    problem->resample->size[0] = 1;
    problem->resample->size[1] = b_problem.resample->size[1];
    emxEnsureCapacity_real_T(sp, problem->resample, i, &sf_emlrtRTEI);
    ns = b_problem.resample->size[1];
    for (i = 0; i < ns; i++) {
      problem->resample->data[i] = b_problem.resample->data[i];
    }
    break;
  }
  emxFreeStruct_struct_T(&c_problem);
  emxFreeStruct_struct_T(&b_problem);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (standardTF_reflectivityCalculation.c) */
