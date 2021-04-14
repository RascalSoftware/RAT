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
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"
#include "standardTF_custLay_reflectivityCalculation.h"
#include "standardTF_stanLay_reflectivityCalculation.h"

/* Variable Definitions */
static emlrtRSInfo b_emlrtRSI = { 51,  /* lineNo */
  "standardTF_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 55,  /* lineNo */
  "standardTF_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pathName */
};

static emlrtDCInfo d_emlrtDCI = { 6,   /* lineNo */
  18,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 6,   /* lineNo */
  18,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 19,  /* lineNo */
  21,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo m_emlrtRTEI = { 20,/* lineNo */
  9,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 25,/* lineNo */
  9,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 30,/* lineNo */
  9,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 35,/* lineNo */
  9,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 40,/* lineNo */
  9,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 45,/* lineNo */
  9,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo se_emlrtRTEI = { 9,/* lineNo */
  26,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo te_emlrtRTEI = { 10,/* lineNo */
  32,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ue_emlrtRTEI = { 11,/* lineNo */
  28,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ve_emlrtRTEI = { 12,/* lineNo */
  33,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo we_emlrtRTEI = { 13,/* lineNo */
  27,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo xe_emlrtRTEI = { 14,/* lineNo */
  27,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ye_emlrtRTEI = { 15,/* lineNo */
  32,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo af_emlrtRTEI = { 16,/* lineNo */
  51,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo bf_emlrtRTEI = { 17,/* lineNo */
  32,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo cf_emlrtRTEI = { 1,/* lineNo */
  91,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo df_emlrtRTEI = { 21,/* lineNo */
  5,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ef_emlrtRTEI = { 26,/* lineNo */
  5,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ff_emlrtRTEI = { 31,/* lineNo */
  5,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo gf_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo hf_emlrtRTEI = { 41,/* lineNo */
  5,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo if_emlrtRTEI = { 46,/* lineNo */
  5,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo jf_emlrtRTEI = { 55,/* lineNo */
  18,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo lf_emlrtRTEI = { 56,/* lineNo */
  13,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo mf_emlrtRTEI = { 56,/* lineNo */
  36,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo of_emlrtRTEI = { 55,/* lineNo */
  31,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo pf_emlrtRTEI = { 56,/* lineNo */
  26,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo qf_emlrtRTEI = { 57,/* lineNo */
  13,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

/* Function Definitions */
void c_standardTF_reflectivityCalcul(const emlrtStack *sp, const struct0_T
  *problemDef, const cell_15 *problemDef_cells, const struct2_T *controls,
  struct4_T *problem, emxArray_cell_wrap_12 *reflectivity, emxArray_cell_wrap_7 *
  Simulation, emxArray_cell_wrap_1 *shifted_data, emxArray_cell_wrap_1
  *layerSlds, emxArray_cell_wrap_12 *sldProfiles, emxArray_cell_wrap_12
  *allLayers)
{
  int32_T i;
  int32_T loop_ub;
  int32_T i1;
  int32_T b_i;
  boolean_T b_bool;
  int32_T exitg1;
  static const char_T b_cv[6] = { 'l', 'a', 'y', 'e', 'r', 's' };

  emxArray_cell_wrap_12 *b_reflectivity;
  emxArray_cell_wrap_16 *r;
  emxArray_cell_wrap_9 *r1;
  static const char_T cv1[13] = { 'C', 'u', 's', 't', 'o', 'm', ' ', 'L', 'a',
    'y', 'e', 'r', 's' };

  emxArray_cell_wrap_10 *r2;
  emxArray_cell_wrap_10 *r3;
  emxArray_cell_wrap_9 *r4;
  emxArray_cell_wrap_17 *r5;
  emxArray_cell_wrap_7 *b_Simulation;
  emxArray_cell_wrap_1 *b_shifted_data;
  emxArray_cell_wrap_1 *b_layerSlds;
  emxArray_cell_wrap_12 *b_sldProfiles;
  emxArray_cell_wrap_12 *b_allLayers;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 1U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 0U);

  /* Decide what kind of calculation it is and call the appropriate one */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &d_emlrtDCI, sp);
  }

  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &e_emlrtDCI, sp);
  }

  /*  Pre-allocate the output arrays.. */
  loop_ub = (int32_T)problemDef->numberOfContrasts;
  i1 = problem->ssubs->size[0];
  problem->ssubs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->ssubs, i1, &se_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->ssubs->data[i1] = 0.0;
  }

  i1 = problem->backgrounds->size[0];
  problem->backgrounds->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->backgrounds, i1, &te_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->backgrounds->data[i1] = 0.0;
  }

  i1 = problem->qshifts->size[0];
  problem->qshifts->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->qshifts, i1, &ue_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->qshifts->data[i1] = 0.0;
  }

  i1 = problem->scalefactors->size[0];
  problem->scalefactors->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->scalefactors, i1, &ve_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->scalefactors->data[i1] = 0.0;
  }

  i1 = problem->nbairs->size[0];
  problem->nbairs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->nbairs, i1, &we_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->nbairs->data[i1] = 0.0;
  }

  i1 = problem->nbsubs->size[0];
  problem->nbsubs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->nbsubs, i1, &xe_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->nbsubs->data[i1] = 0.0;
  }

  i1 = problem->resolutions->size[0];
  problem->resolutions->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->resolutions, i1, &ye_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->resolutions->data[i1] = 0.0;
  }

  i1 = problem->calculations.all_chis->size[0];
  problem->calculations.all_chis->size[0] = (int32_T)
    problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->calculations.all_chis, i1, &af_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->calculations.all_chis->data[i1] = 0.0;
  }

  problem->calculations.sum_chi = 0.0;
  i1 = problem->allSubRough->size[0];
  problem->allSubRough->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->allSubRough, i1, &bf_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->allSubRough->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &f_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &m_emlrtRTEI, sp);
  i = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_12(sp, reflectivity, i, &cf_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 1U);
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &r_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &df_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &r_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &df_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &r_emlrtBCI, sp);
    }

    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &r_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &r_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &r_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &r_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &r_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 2U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &n_emlrtRTEI, sp);
  i = Simulation->size[0];
  Simulation->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_7(sp, Simulation, i, &cf_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 3U);
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &s_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &ef_emlrtRTEI);
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &s_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &ef_emlrtRTEI);
    i = Simulation->size[0] - 1;
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &s_emlrtBCI, sp);
    }

    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &s_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &s_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &s_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &s_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &s_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 4U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &o_emlrtRTEI, sp);
  i = shifted_data->size[0];
  shifted_data->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, shifted_data, i, &cf_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 5U);
    i = shifted_data->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &t_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &ff_emlrtRTEI);
    i = shifted_data->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &t_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &ff_emlrtRTEI);
    i = shifted_data->size[0] - 1;
    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &t_emlrtBCI, sp);
    }

    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &t_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < 6; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &t_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[i1] = 1.0;
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 6U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &p_emlrtRTEI, sp);
  i = layerSlds->size[0];
  layerSlds->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, layerSlds, i, &cf_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 7U);
    i = layerSlds->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &u_emlrtBCI, sp);
    }

    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &gf_emlrtRTEI);
    i = layerSlds->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &u_emlrtBCI, sp);
    }

    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &gf_emlrtRTEI);
    i = layerSlds->size[0] - 1;
    i1 = layerSlds->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &u_emlrtBCI, sp);
    }

    i1 = layerSlds->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &u_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < 6; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &u_emlrtBCI, sp);
      }

      layerSlds->data[b_i].f1->data[i1] = 1.0;
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 3, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 8U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &q_emlrtRTEI, sp);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_12(sp, sldProfiles, i, &cf_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 4, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 9U);
    i = sldProfiles->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &v_emlrtBCI, sp);
    }

    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &hf_emlrtRTEI);
    i = sldProfiles->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &v_emlrtBCI, sp);
    }

    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &hf_emlrtRTEI);
    i = sldProfiles->size[0] - 1;
    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &v_emlrtBCI, sp);
    }

    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &v_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &v_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &v_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &v_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &v_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 4, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 10U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &r_emlrtRTEI, sp);
  i = allLayers->size[0];
  allLayers->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_12(sp, allLayers, i, &cf_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 5, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 11U);
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &w_emlrtBCI, sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &if_emlrtRTEI);
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &w_emlrtBCI, sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &if_emlrtRTEI);
    i = allLayers->size[0] - 1;
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &w_emlrtBCI, sp);
    }

    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &w_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &w_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &w_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 5, 0);
  b_bool = false;
  if (problemDef->modelType->size[1] == 6) {
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 6) {
        if (problemDef->modelType->data[loop_ub] != b_cv[loop_ub]) {
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
    if (problemDef->modelType->size[1] == 13) {
      loop_ub = 0;
      do {
        exitg1 = 0;
        if (loop_ub < 13) {
          if (problemDef->modelType->data[loop_ub] != cv1[loop_ub]) {
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
      loop_ub = -1;
    }
  }

  switch (loop_ub) {
   case 0:
    covrtLogSwitch(&emlrtCoverageInstance, 1U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 12U);
    st.site = &b_emlrtRSI;
    c_standardTF_stanLay_reflectivi(&st, problemDef, problemDef_cells, controls,
      problem, reflectivity, Simulation, shifted_data, layerSlds, sldProfiles,
      allLayers);
    break;

   case 1:
    emxInit_cell_wrap_12(sp, &b_reflectivity, 1, &cf_emlrtRTEI, true);
    emxInit_cell_wrap_16(sp, &r, 1, &cf_emlrtRTEI, true);
    emxInit_cell_wrap_9(sp, &r1, 1, &cf_emlrtRTEI, true);
    emxInit_cell_wrap_10(sp, &r2, 1, &cf_emlrtRTEI, true);
    emxInit_cell_wrap_10(sp, &r3, 1, &cf_emlrtRTEI, true);
    emxInit_cell_wrap_9(sp, &r4, 1, &cf_emlrtRTEI, true);
    emxInit_cell_wrap_17(sp, &r5, 1, &cf_emlrtRTEI, true);
    covrtLogSwitch(&emlrtCoverageInstance, 1U, 0U, 0, 2);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 13U);
    st.site = &c_emlrtRSI;
    c_standardTF_custLay_reflectivi(&st, problemDef, problemDef_cells, controls,
      problem, r, r1, r2, r3, r4, r5);
    i = b_reflectivity->size[0];
    b_reflectivity->size[0] = r->size[0];
    emxEnsureCapacity_cell_wrap_12(sp, b_reflectivity, i, &jf_emlrtRTEI);
    i = r->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = b_reflectivity->data[i1].f1->size[0] * b_reflectivity->data[i1]
        .f1->size[1];
      b_reflectivity->data[i1].f1->size[0] = r->data[i1].f1->size[0];
      b_reflectivity->data[i1].f1->size[1] = r->data[i1].f1->size[1];
      emxEnsureCapacity_real_T(sp, b_reflectivity->data[i1].f1, b_i,
        &jf_emlrtRTEI);
      loop_ub = r->data[i1].f1->size[0] * r->data[i1].f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_reflectivity->data[i1].f1->data[b_i] = r->data[i1].f1->data[b_i];
      }
    }

    emxFree_cell_wrap_16(&r);
    emxInit_cell_wrap_7(sp, &b_Simulation, 1, &cf_emlrtRTEI, true);
    i = b_Simulation->size[0];
    b_Simulation->size[0] = r1->size[0];
    emxEnsureCapacity_cell_wrap_7(sp, b_Simulation, i, &kf_emlrtRTEI);
    i = r1->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = b_Simulation->data[i1].f1->size[0] * b_Simulation->data[i1].f1->
        size[1];
      b_Simulation->data[i1].f1->size[0] = r1->data[i1].f1->size[0];
      b_Simulation->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, b_Simulation->data[i1].f1, b_i, &kf_emlrtRTEI);
      loop_ub = r1->data[i1].f1->size[0] * r1->data[i1].f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_Simulation->data[i1].f1->data[b_i] = r1->data[i1].f1->data[b_i];
      }
    }

    emxFree_cell_wrap_9(&r1);
    emxInit_cell_wrap_1(sp, &b_shifted_data, 1, &cf_emlrtRTEI, true);
    i = b_shifted_data->size[0];
    b_shifted_data->size[0] = r2->size[0];
    emxEnsureCapacity_cell_wrap_1(sp, b_shifted_data, i, &lf_emlrtRTEI);
    i = r2->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = b_shifted_data->data[i1].f1->size[0] * b_shifted_data->data[i1]
        .f1->size[1];
      b_shifted_data->data[i1].f1->size[0] = r2->data[i1].f1->size[0];
      b_shifted_data->data[i1].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, b_shifted_data->data[i1].f1, b_i,
        &lf_emlrtRTEI);
      loop_ub = r2->data[i1].f1->size[0] * r2->data[i1].f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_shifted_data->data[i1].f1->data[b_i] = r2->data[i1].f1->data[b_i];
      }
    }

    emxFree_cell_wrap_10(&r2);
    emxInit_cell_wrap_1(sp, &b_layerSlds, 1, &cf_emlrtRTEI, true);
    i = b_layerSlds->size[0];
    b_layerSlds->size[0] = r3->size[0];
    emxEnsureCapacity_cell_wrap_1(sp, b_layerSlds, i, &lf_emlrtRTEI);
    i = r3->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = b_layerSlds->data[i1].f1->size[0] * b_layerSlds->data[i1].f1->size[1];
      b_layerSlds->data[i1].f1->size[0] = r3->data[i1].f1->size[0];
      b_layerSlds->data[i1].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, b_layerSlds->data[i1].f1, b_i, &lf_emlrtRTEI);
      loop_ub = r3->data[i1].f1->size[0] * r3->data[i1].f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_layerSlds->data[i1].f1->data[b_i] = r3->data[i1].f1->data[b_i];
      }
    }

    emxFree_cell_wrap_10(&r3);
    emxInit_cell_wrap_12(sp, &b_sldProfiles, 1, &cf_emlrtRTEI, true);
    i = b_sldProfiles->size[0];
    b_sldProfiles->size[0] = r4->size[0];
    emxEnsureCapacity_cell_wrap_12(sp, b_sldProfiles, i, &mf_emlrtRTEI);
    i = r4->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = b_sldProfiles->data[i1].f1->size[0] * b_sldProfiles->data[i1]
        .f1->size[1];
      b_sldProfiles->data[i1].f1->size[0] = r4->data[i1].f1->size[0];
      b_sldProfiles->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, b_sldProfiles->data[i1].f1, b_i,
        &mf_emlrtRTEI);
      loop_ub = r4->data[i1].f1->size[0] * r4->data[i1].f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_sldProfiles->data[i1].f1->data[b_i] = r4->data[i1].f1->data[b_i];
      }
    }

    emxFree_cell_wrap_9(&r4);
    emxInit_cell_wrap_12(sp, &b_allLayers, 1, &cf_emlrtRTEI, true);
    i = b_allLayers->size[0];
    b_allLayers->size[0] = r5->size[0];
    emxEnsureCapacity_cell_wrap_12(sp, b_allLayers, i, &nf_emlrtRTEI);
    i = r5->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = b_allLayers->data[i1].f1->size[0] * b_allLayers->data[i1].f1->size[1];
      b_allLayers->data[i1].f1->size[0] = r5->data[i1].f1->size[0];
      b_allLayers->data[i1].f1->size[1] = r5->data[i1].f1->size[1];
      emxEnsureCapacity_real_T(sp, b_allLayers->data[i1].f1, b_i, &nf_emlrtRTEI);
      loop_ub = r5->data[i1].f1->size[0] * r5->data[i1].f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_allLayers->data[i1].f1->data[b_i] = r5->data[i1].f1->data[b_i];
      }
    }

    emxFree_cell_wrap_17(&r5);
    i = reflectivity->size[0];
    reflectivity->size[0] = b_reflectivity->size[0];
    emxEnsureCapacity_cell_wrap_12(sp, reflectivity, i, &jf_emlrtRTEI);
    loop_ub = b_reflectivity->size[0];
    for (i = 0; i < loop_ub; i++) {
      emxCopyStruct_cell_wrap_12(sp, &reflectivity->data[i],
        &b_reflectivity->data[i], &jf_emlrtRTEI);
    }

    emxFree_cell_wrap_12(&b_reflectivity);
    i = Simulation->size[0];
    Simulation->size[0] = b_Simulation->size[0];
    emxEnsureCapacity_cell_wrap_7(sp, Simulation, i, &of_emlrtRTEI);
    loop_ub = b_Simulation->size[0];
    for (i = 0; i < loop_ub; i++) {
      emxCopyStruct_cell_wrap_7(sp, &Simulation->data[i], &b_Simulation->data[i],
        &of_emlrtRTEI);
    }

    emxFree_cell_wrap_7(&b_Simulation);
    i = shifted_data->size[0];
    shifted_data->size[0] = b_shifted_data->size[0];
    emxEnsureCapacity_cell_wrap_1(sp, shifted_data, i, &lf_emlrtRTEI);
    loop_ub = b_shifted_data->size[0];
    for (i = 0; i < loop_ub; i++) {
      emxCopyStruct_cell_wrap_1(sp, &shifted_data->data[i],
        &b_shifted_data->data[i], &lf_emlrtRTEI);
    }

    emxFree_cell_wrap_1(&b_shifted_data);
    i = layerSlds->size[0];
    layerSlds->size[0] = b_layerSlds->size[0];
    emxEnsureCapacity_cell_wrap_1(sp, layerSlds, i, &pf_emlrtRTEI);
    loop_ub = b_layerSlds->size[0];
    for (i = 0; i < loop_ub; i++) {
      emxCopyStruct_cell_wrap_1(sp, &layerSlds->data[i], &b_layerSlds->data[i],
        &pf_emlrtRTEI);
    }

    emxFree_cell_wrap_1(&b_layerSlds);
    i = sldProfiles->size[0];
    sldProfiles->size[0] = b_sldProfiles->size[0];
    emxEnsureCapacity_cell_wrap_12(sp, sldProfiles, i, &mf_emlrtRTEI);
    loop_ub = b_sldProfiles->size[0];
    for (i = 0; i < loop_ub; i++) {
      emxCopyStruct_cell_wrap_12(sp, &sldProfiles->data[i], &b_sldProfiles->
        data[i], &mf_emlrtRTEI);
    }

    emxFree_cell_wrap_12(&b_sldProfiles);
    i = allLayers->size[0];
    allLayers->size[0] = b_allLayers->size[0];
    emxEnsureCapacity_cell_wrap_12(sp, allLayers, i, &qf_emlrtRTEI);
    loop_ub = b_allLayers->size[0];
    for (i = 0; i < loop_ub; i++) {
      emxCopyStruct_cell_wrap_12(sp, &allLayers->data[i], &b_allLayers->data[i],
        &qf_emlrtRTEI);
    }

    emxFree_cell_wrap_12(&b_allLayers);

    /*     case 'Custom XY' */
    /*         [problem,reflectivity,Simulation,... */
    /*             shifted_data,layerSlds,sldProfiles,... */
    /*             allLayers] = standardTF_custXY_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls); */
    break;

   default:
    covrtLogSwitch(&emlrtCoverageInstance, 1U, 0U, 0, 0);
    break;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_reflectivityCalculation.c) */
