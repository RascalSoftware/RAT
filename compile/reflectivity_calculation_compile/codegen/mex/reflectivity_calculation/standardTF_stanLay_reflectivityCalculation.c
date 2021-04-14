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
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"
#include "standardTF_stanlay_paraAll.h"
#include "standardTF_stanlay_paraContrasts.h"
#include "standardTF_stanlay_paraPoints.h"
#include "standardTF_stanlay_single.h"
#include "sum.h"

/* Variable Definitions */
static emlrtRSInfo d_emlrtRSI = { 53,  /* lineNo */
  "standardTF_stanLay_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 60,  /* lineNo */
  "standardTF_stanLay_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 67,  /* lineNo */
  "standardTF_stanLay_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 74,  /* lineNo */
  "standardTF_stanLay_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 88,  /* lineNo */
  "standardTF_stanLay_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pathName */
};

static emlrtDCInfo g_emlrtDCI = { 18,  /* lineNo */
  21,                                  /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo s_emlrtRTEI = { 19,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 24,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 29,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 34,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 39,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 44,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtDCInfo h_emlrtDCI = { 80,  /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 80,  /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 81,  /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 82,  /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 83,  /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 84,  /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = { 85,  /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 14,  /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = { 86,  /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = { 89,  /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  30,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo rf_emlrtRTEI = { 80,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo sf_emlrtRTEI = { 81,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo tf_emlrtRTEI = { 82,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo uf_emlrtRTEI = { 83,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo vf_emlrtRTEI = { 84,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo wf_emlrtRTEI = { 85,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo xf_emlrtRTEI = { 14,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo yf_emlrtRTEI = { 86,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ag_emlrtRTEI = { 89,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo bg_emlrtRTEI = { 1,/* lineNo */
  91,                                  /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo cg_emlrtRTEI = { 20,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo dg_emlrtRTEI = { 25,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo eg_emlrtRTEI = { 30,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo fg_emlrtRTEI = { 35,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo gg_emlrtRTEI = { 40,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo hg_emlrtRTEI = { 45,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ig_emlrtRTEI = { 87,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

/* Function Definitions */
void c_standardTF_stanLay_reflectivi(const emlrtStack *sp, const struct0_T
  *problemDef, const cell_15 *problemDef_cells, const struct2_T *controls,
  struct4_T *problem, emxArray_cell_wrap_12 *reflectivity, emxArray_cell_wrap_7 *
  Simulation, emxArray_cell_wrap_1 *shifted_data, emxArray_cell_wrap_1
  *layerSlds, emxArray_cell_wrap_12 *sldProfiles, emxArray_cell_wrap_12
  *allLayers)
{
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  emxArray_real_T *chis;
  int32_T b_i;
  boolean_T b_bool;
  int32_T exitg1;
  static const char_T b_cv[6] = { 's', 'i', 'n', 'g', 'l', 'e' };

  static const char_T cv1[6] = { 'p', 'o', 'i', 'n', 't', 's' };

  static const char_T cv2[3] = { 'a', 'l', 'l' };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 2U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 0U);

  /*  Pre-allocation - It's necessary to */
  /*  pre-allocate the memory for all the arrays */
  /*  for compilation, so do this in this block. */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &i_emlrtDCI, sp);
  }

  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &h_emlrtDCI, sp);
  }

  i1 = problem->ssubs->size[0];
  loop_ub = (int32_T)problemDef->numberOfContrasts;
  problem->ssubs->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->ssubs, i1, &rf_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &h_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->ssubs->data[i1] = 0.0;
  }

  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &j_emlrtDCI, sp);
  }

  loop_ub = (int32_T)problemDef->numberOfContrasts;
  i1 = problem->backgrounds->size[0];
  problem->backgrounds->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->backgrounds, i1, &sf_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &j_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->backgrounds->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &k_emlrtDCI, sp);
  }

  i1 = problem->qshifts->size[0];
  problem->qshifts->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->qshifts, i1, &tf_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &k_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->qshifts->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &l_emlrtDCI, sp);
  }

  i1 = problem->scalefactors->size[0];
  problem->scalefactors->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->scalefactors, i1, &uf_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &l_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->scalefactors->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &m_emlrtDCI, sp);
  }

  i1 = problem->nbairs->size[0];
  problem->nbairs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->nbairs, i1, &vf_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &m_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->nbairs->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &n_emlrtDCI, sp);
  }

  i1 = problem->nbsubs->size[0];
  problem->nbsubs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->nbsubs, i1, &wf_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &n_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->nbsubs->data[i1] = 0.0;
  }

  emxInit_real_T(sp, &chis, 1, &xf_emlrtRTEI, true);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &o_emlrtDCI, sp);
  }

  i1 = chis->size[0];
  chis->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, chis, i1, &xf_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &o_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    chis->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &p_emlrtDCI, sp);
  }

  i1 = problem->resolutions->size[0];
  problem->resolutions->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->resolutions, i1, &yf_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &p_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->resolutions->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &q_emlrtDCI, sp);
  }

  i1 = problem->allSubRough->size[0];
  problem->allSubRough->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->allSubRough, i1, &ag_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &q_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->allSubRough->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &g_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &s_emlrtRTEI, sp);
  i = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_12(sp, reflectivity, i, &bg_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 2U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 1U);
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &x_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &cg_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &x_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &cg_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &x_emlrtBCI, sp);
    }

    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &x_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &x_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &x_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &x_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &x_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 2U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 2U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &t_emlrtRTEI, sp);
  i = Simulation->size[0];
  Simulation->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_7(sp, Simulation, i, &bg_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 2U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 3U);
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &y_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &dg_emlrtRTEI);
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &y_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &dg_emlrtRTEI);
    i = Simulation->size[0] - 1;
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &y_emlrtBCI, sp);
    }

    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &y_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &y_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &y_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &y_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &y_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 2U, 0U, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 4U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &u_emlrtRTEI, sp);
  i = shifted_data->size[0];
  shifted_data->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, shifted_data, i, &bg_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 2U, 0U, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 5U);
    i = shifted_data->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ab_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &eg_emlrtRTEI);
    i = shifted_data->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ab_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &eg_emlrtRTEI);
    i = shifted_data->size[0] - 1;
    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ab_emlrtBCI, sp);
    }

    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ab_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < 6; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ab_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[i1] = 1.0;
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 2U, 0U, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 6U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &v_emlrtRTEI, sp);
  i = layerSlds->size[0];
  layerSlds->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, layerSlds, i, &bg_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 2U, 0U, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 7U);
    i = layerSlds->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bb_emlrtBCI, sp);
    }

    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &fg_emlrtRTEI);
    i = layerSlds->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bb_emlrtBCI, sp);
    }

    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &fg_emlrtRTEI);
    i = layerSlds->size[0] - 1;
    i1 = layerSlds->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bb_emlrtBCI, sp);
    }

    i1 = layerSlds->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bb_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < 6; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bb_emlrtBCI, sp);
      }

      layerSlds->data[b_i].f1->data[i1] = 1.0;
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 2U, 0U, 3, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 8U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &w_emlrtRTEI, sp);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_12(sp, sldProfiles, i, &bg_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 2U, 0U, 4, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 9U);
    i = sldProfiles->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cb_emlrtBCI, sp);
    }

    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &gg_emlrtRTEI);
    i = sldProfiles->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cb_emlrtBCI, sp);
    }

    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &gg_emlrtRTEI);
    i = sldProfiles->size[0] - 1;
    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &cb_emlrtBCI, sp);
    }

    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &cb_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cb_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cb_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cb_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cb_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 2U, 0U, 4, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 10U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &x_emlrtRTEI, sp);
  i = allLayers->size[0];
  allLayers->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_12(sp, allLayers, i, &bg_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 2U, 0U, 5, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 11U);
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &db_emlrtBCI, sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &hg_emlrtRTEI);
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &db_emlrtBCI, sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &hg_emlrtRTEI);
    i = allLayers->size[0] - 1;
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &db_emlrtBCI, sp);
    }

    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &db_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &db_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &db_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 2U, 0U, 5, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 12U);
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
      loop_ub = 1;
    } else {
      b_bool = false;
      if (controls->para->size[1] == 9) {
        loop_ub = 0;
        do {
          exitg1 = 0;
          if (loop_ub < 9) {
            if (controls->para->data[loop_ub] != cv[loop_ub]) {
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
        b_bool = false;
        if (controls->para->size[1] == 3) {
          loop_ub = 0;
          do {
            exitg1 = 0;
            if (loop_ub < 3) {
              if (controls->para->data[loop_ub] != cv2[loop_ub]) {
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
          loop_ub = 3;
        } else {
          loop_ub = -1;
        }
      }
    }
  }

  switch (loop_ub) {
   case 0:
    covrtLogSwitch(&emlrtCoverageInstance, 2U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 13U);
    st.site = &d_emlrtRSI;
    standardTF_stanlay_single(&st, problemDef, problemDef_cells, controls,
      problem->ssubs, problem->backgrounds, problem->qshifts,
      problem->scalefactors, problem->nbairs, problem->nbsubs,
      problem->resolutions, chis, reflectivity, Simulation, shifted_data,
      layerSlds, sldProfiles, allLayers, problem->allSubRough);
    break;

   case 1:
    covrtLogSwitch(&emlrtCoverageInstance, 2U, 0U, 0, 2);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 14U);
    st.site = &e_emlrtRSI;
    standardTF_stanlay_paraPoints(&st, problemDef, problemDef_cells, controls,
      problem->ssubs, problem->backgrounds, problem->qshifts,
      problem->scalefactors, problem->nbairs, problem->nbsubs,
      problem->resolutions, chis, reflectivity, Simulation, shifted_data,
      layerSlds, sldProfiles, allLayers, problem->allSubRough);
    break;

   case 2:
    covrtLogSwitch(&emlrtCoverageInstance, 2U, 0U, 0, 3);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 15U);
    st.site = &f_emlrtRSI;
    c_standardTF_stanlay_paraContra(&st, problemDef, problemDef_cells, controls,
      problem->ssubs, problem->backgrounds, problem->qshifts,
      problem->scalefactors, problem->nbairs, problem->nbsubs,
      problem->resolutions, chis, reflectivity, Simulation, shifted_data,
      layerSlds, sldProfiles, allLayers, problem->allSubRough);
    break;

   case 3:
    covrtLogSwitch(&emlrtCoverageInstance, 2U, 0U, 0, 4);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 16U);
    st.site = &g_emlrtRSI;
    standardTF_stanlay_paraAll(&st, problemDef, problemDef_cells, controls,
      problem->ssubs, problem->backgrounds, problem->qshifts,
      problem->scalefactors, problem->nbairs, problem->nbsubs,
      problem->resolutions, chis, reflectivity, Simulation, shifted_data,
      layerSlds, sldProfiles, allLayers, problem->allSubRough);
    break;

   default:
    covrtLogSwitch(&emlrtCoverageInstance, 2U, 0U, 0, 0);
    break;
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 17U);
  i = problem->calculations.all_chis->size[0];
  problem->calculations.all_chis->size[0] = chis->size[0];
  emxEnsureCapacity_real_T(sp, problem->calculations.all_chis, i, &ig_emlrtRTEI);
  loop_ub = chis->size[0];
  for (i = 0; i < loop_ub; i++) {
    problem->calculations.all_chis->data[i] = chis->data[i];
  }

  st.site = &h_emlrtRSI;
  problem->calculations.sum_chi = sum(&st, chis);
  emxFree_real_T(&chis);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_stanLay_reflectivityCalculation.c) */
