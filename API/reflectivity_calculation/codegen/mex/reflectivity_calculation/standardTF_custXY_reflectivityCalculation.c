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
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"
#include "standardTF_custXY_paraPoints.h"
#include "standardTF_custXY_single.h"
#include "sum.h"

/* Variable Definitions */
static emlrtRSInfo ii_emlrtRSI = { 102,/* lineNo */
  "standardTF_custXY_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo ji_emlrtRSI = { 149,/* lineNo */
  "standardTF_custXY_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo ki_emlrtRSI = { 252,/* lineNo */
  "standardTF_custXY_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pathName */
};

static emlrtBCInfo pq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  19,                                  /* colNo */
  "params",                            /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo ic_emlrtDCI = { 61, /* lineNo */
  21,                                  /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo vc_emlrtRTEI = { 62,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = { 68,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo xc_emlrtRTEI = { 75,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo yc_emlrtRTEI = { 81,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = { 87,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = { 93,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtDCInfo jc_emlrtDCI = { 245,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo kc_emlrtDCI = { 245,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo lc_emlrtDCI = { 246,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo mc_emlrtDCI = { 247,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo nc_emlrtDCI = { 248,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo oc_emlrtDCI = { 249,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo pc_emlrtDCI = { 57, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo qc_emlrtDCI = { 250,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo rc_emlrtDCI = { 253,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo qq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  94,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo jp_emlrtRTEI = { 244,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo kp_emlrtRTEI = { 245,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo lp_emlrtRTEI = { 246,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo mp_emlrtRTEI = { 247,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo np_emlrtRTEI = { 248,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo op_emlrtRTEI = { 249,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo pp_emlrtRTEI = { 57,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo qp_emlrtRTEI = { 250,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo rp_emlrtRTEI = { 253,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo sp_emlrtRTEI = { 1,/* lineNo */
  91,                                  /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo tp_emlrtRTEI = { 63,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo up_emlrtRTEI = { 69,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo vp_emlrtRTEI = { 76,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo wp_emlrtRTEI = { 82,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo xp_emlrtRTEI = { 88,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo yp_emlrtRTEI = { 94,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo aq_emlrtRTEI = { 251,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

/* Function Definitions */
void c_standardTF_custXY_reflectivit(const emlrtStack *sp, const struct0_T
  *problemDef, const cell_13 *problemDef_cells, const struct2_T *controls,
  struct4_T *problem, emxArray_cell_wrap_14 *reflectivity, emxArray_cell_wrap_8 *
  Simulation, emxArray_cell_wrap_9 *shifted_data, emxArray_cell_wrap_9
  *layerSlds, emxArray_cell_wrap_8 *sldProfiles, emxArray_cell_wrap_15
  *allLayers)
{
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  emxArray_real_T *chis;
  int32_T b_i;
  boolean_T b_bool;
  int32_T exitg1;
  emxArray_cell_wrap_6 *b_reflectivity;
  static const char_T b_cv[6] = { 's', 'i', 'n', 'g', 'l', 'e' };

  emxArray_cell_wrap_6 *b_Simulation;
  emxArray_cell_wrap_1 *b_shifted_data;
  emxArray_cell_wrap_1 *b_layerSlds;
  static const char_T b_cv1[6] = { 'p', 'o', 'i', 'n', 't', 's' };

  emxArray_cell_wrap_6 *b_sldProfiles;
  emxArray_cell_wrap_11 *b_allLayers;
  emxArray_cell_wrap_8 *r;
  emxArray_cell_wrap_8 *r1;
  emxArray_cell_wrap_15 *r2;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 30U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 30U, 0U);
  covrtLogFcn(&emlrtCoverageInstance, 3U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 0U);

  /* Extract individual parameters from problemDef */
  /* nbairs = problemDef.nbairs; */
  /* nbsubs = problemDef.nbsubs; */
  /* repeats = problemDef.repeatLayers; */
  /* allData = problemDef.allData; */
  /* dataLimits = problemDef.dataLimits; */
  /* simLimits = problemDef.simLimits; */
  /* repeatLayers = problemDef.repeatLayers; */
  /* contrastLayers = problemDef.contrastLayers; */
  /* layersDetails = problemDef.layersDetails; */
  /* Pre-allocation */
  if (1 > problemDef->params->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, problemDef->params->size[1],
      &pq_emlrtBCI, sp);
  }

  i = problem->ssubs->size[0];
  problem->ssubs->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->ssubs, i, &jp_emlrtRTEI);
  problem->ssubs->data[0] = problemDef->params->data[0];
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &kc_emlrtDCI, sp);
  }

  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &jc_emlrtDCI, sp);
  }

  i1 = problem->backgrounds->size[0];
  loop_ub = (int32_T)problemDef->numberOfContrasts;
  problem->backgrounds->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->backgrounds, i1, &kp_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &jc_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->backgrounds->data[i1] = 0.0;
  }

  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &lc_emlrtDCI, sp);
  }

  loop_ub = (int32_T)problemDef->numberOfContrasts;
  i1 = problem->qshifts->size[0];
  problem->qshifts->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->qshifts, i1, &lp_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &lc_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->qshifts->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &mc_emlrtDCI, sp);
  }

  i1 = problem->scalefactors->size[0];
  problem->scalefactors->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->scalefactors, i1, &mp_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &mc_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->scalefactors->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &nc_emlrtDCI, sp);
  }

  i1 = problem->nbairs->size[0];
  problem->nbairs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->nbairs, i1, &np_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &nc_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->nbairs->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &oc_emlrtDCI, sp);
  }

  i1 = problem->nbsubs->size[0];
  problem->nbsubs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->nbsubs, i1, &op_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &oc_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->nbsubs->data[i1] = 0.0;
  }

  emxInit_real_T(sp, &chis, 1, &pp_emlrtRTEI, true);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &pc_emlrtDCI, sp);
  }

  i1 = chis->size[0];
  chis->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, chis, i1, &pp_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &pc_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    chis->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &qc_emlrtDCI, sp);
  }

  i1 = problem->resolutions->size[0];
  problem->resolutions->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->resolutions, i1, &qp_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &qc_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->resolutions->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &rc_emlrtDCI, sp);
  }

  i1 = problem->allSubRough->size[0];
  problem->allSubRough->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->allSubRough, i1, &rp_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &rc_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->allSubRough->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ic_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &vc_emlrtRTEI, sp);
  i = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_14(sp, reflectivity, i, &sp_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 30U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 30U, 1U);
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &qq_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &tp_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &qq_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &tp_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &qq_emlrtBCI, sp);
    }

    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &qq_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &qq_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &qq_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &qq_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &qq_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 30U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 30U, 2U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &wc_emlrtRTEI, sp);
  i = Simulation->size[0];
  Simulation->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, Simulation, i, &sp_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 30U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 30U, 3U);
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &rq_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &up_emlrtRTEI);
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &rq_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &up_emlrtRTEI);
    i = Simulation->size[0] - 1;
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &rq_emlrtBCI, sp);
    }

    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &rq_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &rq_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &rq_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &rq_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &rq_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 30U, 0U, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 30U, 4U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &xc_emlrtRTEI, sp);
  i = shifted_data->size[0];
  shifted_data->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_9(sp, shifted_data, i, &sp_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 30U, 0U, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 30U, 5U);
    i = shifted_data->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &sq_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &vp_emlrtRTEI);
    i = shifted_data->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &sq_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &vp_emlrtRTEI);
    i = shifted_data->size[0] - 1;
    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &sq_emlrtBCI, sp);
    }

    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &sq_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < 6; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &sq_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[i1] = 1.0;
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 30U, 0U, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 30U, 6U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &yc_emlrtRTEI, sp);
  i = layerSlds->size[0];
  layerSlds->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_9(sp, layerSlds, i, &sp_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 30U, 0U, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 30U, 7U);
    i = layerSlds->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &tq_emlrtBCI, sp);
    }

    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &wp_emlrtRTEI);
    i = layerSlds->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &tq_emlrtBCI, sp);
    }

    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &wp_emlrtRTEI);
    i = layerSlds->size[0] - 1;
    i1 = layerSlds->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &tq_emlrtBCI, sp);
    }

    i1 = layerSlds->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &tq_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < 6; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &tq_emlrtBCI, sp);
      }

      layerSlds->data[b_i].f1->data[i1] = 1.0;
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 30U, 0U, 3, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 30U, 8U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &ad_emlrtRTEI, sp);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, sldProfiles, i, &sp_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 30U, 0U, 4, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 30U, 9U);
    i = sldProfiles->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &uq_emlrtBCI, sp);
    }

    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &xp_emlrtRTEI);
    i = sldProfiles->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &uq_emlrtBCI, sp);
    }

    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &xp_emlrtRTEI);
    i = sldProfiles->size[0] - 1;
    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &uq_emlrtBCI, sp);
    }

    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &uq_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &uq_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &uq_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &uq_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &uq_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 30U, 0U, 4, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 30U, 10U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &bd_emlrtRTEI, sp);
  i = allLayers->size[0];
  allLayers->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_15(sp, allLayers, i, &sp_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 30U, 0U, 5, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 30U, 11U);
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &vq_emlrtBCI, sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &yp_emlrtRTEI);
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &vq_emlrtBCI, sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &yp_emlrtRTEI);
    i = allLayers->size[0] - 1;
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &vq_emlrtBCI, sp);
    }

    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &vq_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &vq_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &vq_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 30U, 0U, 5, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 30U, 12U);
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
      loop_ub = -1;
    }
  }

  emxInit_cell_wrap_6(sp, &b_reflectivity, 1, &sp_emlrtRTEI, true);
  emxInit_cell_wrap_6(sp, &b_Simulation, 1, &sp_emlrtRTEI, true);
  emxInit_cell_wrap_1(sp, &b_shifted_data, 1, &sp_emlrtRTEI, true);
  emxInit_cell_wrap_1(sp, &b_layerSlds, 1, &sp_emlrtRTEI, true);
  emxInit_cell_wrap_6(sp, &b_sldProfiles, 1, &sp_emlrtRTEI, true);
  emxInit_cell_wrap_11(sp, &b_allLayers, 1, &sp_emlrtRTEI, true);
  emxInit_cell_wrap_8(sp, &r, 1, &sp_emlrtRTEI, true);
  emxInit_cell_wrap_8(sp, &r1, 1, &sp_emlrtRTEI, true);
  emxInit_cell_wrap_15(sp, &r2, 1, &sp_emlrtRTEI, true);
  switch (loop_ub) {
   case 0:
    covrtLogSwitch(&emlrtCoverageInstance, 30U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 30U, 13U);
    st.site = &ii_emlrtRSI;
    standardTF_custXY_single(&st, problemDef->numberOfContrasts,
      problemDef_cells->f1, problemDef->contrastBacks,
      problemDef->contrastShifts, problemDef->contrastScales,
      problemDef->contrastNbas, problemDef->contrastNbss,
      problemDef->contrastRes, problemDef->backs, problemDef->shifts,
      problemDef->sf, problemDef->nba, problemDef->nbs, problemDef->res,
      problemDef->dataPresent, problemDef_cells->f2, problemDef_cells->f3,
      problemDef_cells->f4, problemDef->params->size[1], problemDef->params,
      problemDef->modelFilename, problemDef->path, problemDef->contrastBacksType,
      problem->ssubs, problem->backgrounds, problem->qshifts,
      problem->scalefactors, problem->nbairs, problem->nbsubs,
      problem->resolutions, chis, r, r1, b_shifted_data, b_layerSlds,
      b_sldProfiles, r2, problem->allSubRough);
    i = b_reflectivity->size[0];
    b_reflectivity->size[0] = r->size[0];
    emxEnsureCapacity_cell_wrap_6(sp, b_reflectivity, i, &sf_emlrtRTEI);
    i = r->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = b_reflectivity->data[i1].f1->size[0] * b_reflectivity->data[i1]
        .f1->size[1];
      b_reflectivity->data[i1].f1->size[0] = r->data[i1].f1->size[0];
      b_reflectivity->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, b_reflectivity->data[i1].f1, b_i,
        &sf_emlrtRTEI);
      loop_ub = r->data[i1].f1->size[0] * r->data[i1].f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_reflectivity->data[i1].f1->data[b_i] = r->data[i1].f1->data[b_i];
      }
    }

    i = b_Simulation->size[0];
    b_Simulation->size[0] = r1->size[0];
    emxEnsureCapacity_cell_wrap_6(sp, b_Simulation, i, &sf_emlrtRTEI);
    i = r1->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = b_Simulation->data[i1].f1->size[0] * b_Simulation->data[i1].f1->
        size[1];
      b_Simulation->data[i1].f1->size[0] = r1->data[i1].f1->size[0];
      b_Simulation->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, b_Simulation->data[i1].f1, b_i, &sf_emlrtRTEI);
      loop_ub = r1->data[i1].f1->size[0] * r1->data[i1].f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_Simulation->data[i1].f1->data[b_i] = r1->data[i1].f1->data[b_i];
      }
    }

    i = b_allLayers->size[0];
    b_allLayers->size[0] = r2->size[0];
    emxEnsureCapacity_cell_wrap_11(sp, b_allLayers, i, &vf_emlrtRTEI);
    i = r2->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = b_allLayers->data[i1].f1->size[0] * b_allLayers->data[i1].f1->size[1];
      b_allLayers->data[i1].f1->size[0] = r2->data[i1].f1->size[0];
      b_allLayers->data[i1].f1->size[1] = r2->data[i1].f1->size[1];
      emxEnsureCapacity_real_T(sp, b_allLayers->data[i1].f1, b_i, &vf_emlrtRTEI);
      loop_ub = r2->data[i1].f1->size[0] * r2->data[i1].f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_allLayers->data[i1].f1->data[b_i] = r2->data[i1].f1->data[b_i];
      }
    }

    i = reflectivity->size[0];
    reflectivity->size[0] = b_reflectivity->size[0];
    emxEnsureCapacity_cell_wrap_14(sp, reflectivity, i, &sf_emlrtRTEI);
    i = b_reflectivity->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = reflectivity->data[i1].f1->size[0] * reflectivity->data[i1].f1->
        size[1];
      reflectivity->data[i1].f1->size[0] = b_reflectivity->data[i1].f1->size[0];
      reflectivity->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, reflectivity->data[i1].f1, b_i, &sf_emlrtRTEI);
      loop_ub = b_reflectivity->data[i1].f1->size[0] * b_reflectivity->data[i1].
        f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        reflectivity->data[i1].f1->data[b_i] = b_reflectivity->data[i1].f1->
          data[b_i];
      }
    }

    i = Simulation->size[0];
    Simulation->size[0] = b_Simulation->size[0];
    emxEnsureCapacity_cell_wrap_8(sp, Simulation, i, &pe_emlrtRTEI);
    i = b_Simulation->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = Simulation->data[i1].f1->size[0] * Simulation->data[i1].f1->size[1];
      Simulation->data[i1].f1->size[0] = b_Simulation->data[i1].f1->size[0];
      Simulation->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, Simulation->data[i1].f1, b_i, &pe_emlrtRTEI);
      loop_ub = b_Simulation->data[i1].f1->size[0] * b_Simulation->data[i1]
        .f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        Simulation->data[i1].f1->data[b_i] = b_Simulation->data[i1].f1->data[b_i];
      }
    }

    i = shifted_data->size[0];
    shifted_data->size[0] = b_shifted_data->size[0];
    emxEnsureCapacity_cell_wrap_9(sp, shifted_data, i, &qe_emlrtRTEI);
    i = b_shifted_data->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = shifted_data->data[i1].f1->size[0] * shifted_data->data[i1].f1->
        size[1];
      shifted_data->data[i1].f1->size[0] = b_shifted_data->data[i1].f1->size[0];
      shifted_data->data[i1].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, shifted_data->data[i1].f1, b_i, &qe_emlrtRTEI);
      loop_ub = b_shifted_data->data[i1].f1->size[0] * b_shifted_data->data[i1].
        f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        shifted_data->data[i1].f1->data[b_i] = b_shifted_data->data[i1].f1->
          data[b_i];
      }
    }

    i = layerSlds->size[0];
    layerSlds->size[0] = b_layerSlds->size[0];
    emxEnsureCapacity_cell_wrap_9(sp, layerSlds, i, &qe_emlrtRTEI);
    i = b_layerSlds->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = layerSlds->data[i1].f1->size[0] * layerSlds->data[i1].f1->size[1];
      layerSlds->data[i1].f1->size[0] = b_layerSlds->data[i1].f1->size[0];
      layerSlds->data[i1].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, layerSlds->data[i1].f1, b_i, &qe_emlrtRTEI);
      loop_ub = b_layerSlds->data[i1].f1->size[0] * b_layerSlds->data[i1]
        .f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        layerSlds->data[i1].f1->data[b_i] = b_layerSlds->data[i1].f1->data[b_i];
      }
    }

    i = sldProfiles->size[0];
    sldProfiles->size[0] = b_sldProfiles->size[0];
    emxEnsureCapacity_cell_wrap_8(sp, sldProfiles, i, &pe_emlrtRTEI);
    i = b_sldProfiles->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = sldProfiles->data[i1].f1->size[0] * sldProfiles->data[i1].f1->size[1];
      sldProfiles->data[i1].f1->size[0] = b_sldProfiles->data[i1].f1->size[0];
      sldProfiles->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, sldProfiles->data[i1].f1, b_i, &pe_emlrtRTEI);
      loop_ub = b_sldProfiles->data[i1].f1->size[0] * b_sldProfiles->data[i1].
        f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        sldProfiles->data[i1].f1->data[b_i] = b_sldProfiles->data[i1].f1->
          data[b_i];
      }
    }

    i = allLayers->size[0];
    allLayers->size[0] = b_allLayers->size[0];
    emxEnsureCapacity_cell_wrap_15(sp, allLayers, i, &vf_emlrtRTEI);
    i = b_allLayers->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = allLayers->data[i1].f1->size[0] * allLayers->data[i1].f1->size[1];
      allLayers->data[i1].f1->size[0] = b_allLayers->data[i1].f1->size[0];
      allLayers->data[i1].f1->size[1] = b_allLayers->data[i1].f1->size[1];
      emxEnsureCapacity_real_T(sp, allLayers->data[i1].f1, b_i, &vf_emlrtRTEI);
      loop_ub = b_allLayers->data[i1].f1->size[0] * b_allLayers->data[i1]
        .f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        allLayers->data[i1].f1->data[b_i] = b_allLayers->data[i1].f1->data[b_i];
      }
    }
    break;

   case 1:
    covrtLogSwitch(&emlrtCoverageInstance, 30U, 0U, 0, 2);
    covrtLogBasicBlock(&emlrtCoverageInstance, 30U, 14U);
    st.site = &ji_emlrtRSI;
    standardTF_custXY_paraPoints(&st, problemDef->numberOfContrasts,
      problemDef_cells->f1, problemDef->contrastBacks,
      problemDef->contrastShifts, problemDef->contrastScales,
      problemDef->contrastNbas, problemDef->contrastNbss,
      problemDef->contrastRes, problemDef->backs, problemDef->shifts,
      problemDef->sf, problemDef->nba, problemDef->nbs, problemDef->res,
      problemDef->dataPresent, problemDef_cells->f2, problemDef_cells->f3,
      problemDef_cells->f4, problemDef->params->size[1], problemDef->params,
      problemDef->modelFilename, problemDef->path, problemDef->contrastBacksType,
      problem->ssubs, problem->backgrounds, problem->qshifts,
      problem->scalefactors, problem->nbairs, problem->nbsubs,
      problem->resolutions, chis, r, r1, b_shifted_data, b_layerSlds,
      b_sldProfiles, r2, problem->allSubRough);
    i = b_reflectivity->size[0];
    b_reflectivity->size[0] = r->size[0];
    emxEnsureCapacity_cell_wrap_6(sp, b_reflectivity, i, &sf_emlrtRTEI);
    i = r->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = b_reflectivity->data[i1].f1->size[0] * b_reflectivity->data[i1]
        .f1->size[1];
      b_reflectivity->data[i1].f1->size[0] = r->data[i1].f1->size[0];
      b_reflectivity->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, b_reflectivity->data[i1].f1, b_i,
        &sf_emlrtRTEI);
      loop_ub = r->data[i1].f1->size[0] * r->data[i1].f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_reflectivity->data[i1].f1->data[b_i] = r->data[i1].f1->data[b_i];
      }
    }

    i = b_Simulation->size[0];
    b_Simulation->size[0] = r1->size[0];
    emxEnsureCapacity_cell_wrap_6(sp, b_Simulation, i, &sf_emlrtRTEI);
    i = r1->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = b_Simulation->data[i1].f1->size[0] * b_Simulation->data[i1].f1->
        size[1];
      b_Simulation->data[i1].f1->size[0] = r1->data[i1].f1->size[0];
      b_Simulation->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, b_Simulation->data[i1].f1, b_i, &sf_emlrtRTEI);
      loop_ub = r1->data[i1].f1->size[0] * r1->data[i1].f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_Simulation->data[i1].f1->data[b_i] = r1->data[i1].f1->data[b_i];
      }
    }

    i = b_allLayers->size[0];
    b_allLayers->size[0] = r2->size[0];
    emxEnsureCapacity_cell_wrap_11(sp, b_allLayers, i, &vf_emlrtRTEI);
    i = r2->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = b_allLayers->data[i1].f1->size[0] * b_allLayers->data[i1].f1->size[1];
      b_allLayers->data[i1].f1->size[0] = r2->data[i1].f1->size[0];
      b_allLayers->data[i1].f1->size[1] = r2->data[i1].f1->size[1];
      emxEnsureCapacity_real_T(sp, b_allLayers->data[i1].f1, b_i, &vf_emlrtRTEI);
      loop_ub = r2->data[i1].f1->size[0] * r2->data[i1].f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_allLayers->data[i1].f1->data[b_i] = r2->data[i1].f1->data[b_i];
      }
    }

    i = reflectivity->size[0];
    reflectivity->size[0] = b_reflectivity->size[0];
    emxEnsureCapacity_cell_wrap_14(sp, reflectivity, i, &sf_emlrtRTEI);
    i = b_reflectivity->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = reflectivity->data[i1].f1->size[0] * reflectivity->data[i1].f1->
        size[1];
      reflectivity->data[i1].f1->size[0] = b_reflectivity->data[i1].f1->size[0];
      reflectivity->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, reflectivity->data[i1].f1, b_i, &sf_emlrtRTEI);
      loop_ub = b_reflectivity->data[i1].f1->size[0] * b_reflectivity->data[i1].
        f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        reflectivity->data[i1].f1->data[b_i] = b_reflectivity->data[i1].f1->
          data[b_i];
      }
    }

    i = Simulation->size[0];
    Simulation->size[0] = b_Simulation->size[0];
    emxEnsureCapacity_cell_wrap_8(sp, Simulation, i, &pe_emlrtRTEI);
    i = b_Simulation->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = Simulation->data[i1].f1->size[0] * Simulation->data[i1].f1->size[1];
      Simulation->data[i1].f1->size[0] = b_Simulation->data[i1].f1->size[0];
      Simulation->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, Simulation->data[i1].f1, b_i, &pe_emlrtRTEI);
      loop_ub = b_Simulation->data[i1].f1->size[0] * b_Simulation->data[i1]
        .f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        Simulation->data[i1].f1->data[b_i] = b_Simulation->data[i1].f1->data[b_i];
      }
    }

    i = shifted_data->size[0];
    shifted_data->size[0] = b_shifted_data->size[0];
    emxEnsureCapacity_cell_wrap_9(sp, shifted_data, i, &qe_emlrtRTEI);
    i = b_shifted_data->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = shifted_data->data[i1].f1->size[0] * shifted_data->data[i1].f1->
        size[1];
      shifted_data->data[i1].f1->size[0] = b_shifted_data->data[i1].f1->size[0];
      shifted_data->data[i1].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, shifted_data->data[i1].f1, b_i, &qe_emlrtRTEI);
      loop_ub = b_shifted_data->data[i1].f1->size[0] * b_shifted_data->data[i1].
        f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        shifted_data->data[i1].f1->data[b_i] = b_shifted_data->data[i1].f1->
          data[b_i];
      }
    }

    i = layerSlds->size[0];
    layerSlds->size[0] = b_layerSlds->size[0];
    emxEnsureCapacity_cell_wrap_9(sp, layerSlds, i, &qe_emlrtRTEI);
    i = b_layerSlds->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = layerSlds->data[i1].f1->size[0] * layerSlds->data[i1].f1->size[1];
      layerSlds->data[i1].f1->size[0] = b_layerSlds->data[i1].f1->size[0];
      layerSlds->data[i1].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, layerSlds->data[i1].f1, b_i, &qe_emlrtRTEI);
      loop_ub = b_layerSlds->data[i1].f1->size[0] * b_layerSlds->data[i1]
        .f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        layerSlds->data[i1].f1->data[b_i] = b_layerSlds->data[i1].f1->data[b_i];
      }
    }

    i = sldProfiles->size[0];
    sldProfiles->size[0] = b_sldProfiles->size[0];
    emxEnsureCapacity_cell_wrap_8(sp, sldProfiles, i, &pe_emlrtRTEI);
    i = b_sldProfiles->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = sldProfiles->data[i1].f1->size[0] * sldProfiles->data[i1].f1->size[1];
      sldProfiles->data[i1].f1->size[0] = b_sldProfiles->data[i1].f1->size[0];
      sldProfiles->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, sldProfiles->data[i1].f1, b_i, &pe_emlrtRTEI);
      loop_ub = b_sldProfiles->data[i1].f1->size[0] * b_sldProfiles->data[i1].
        f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        sldProfiles->data[i1].f1->data[b_i] = b_sldProfiles->data[i1].f1->
          data[b_i];
      }
    }

    i = allLayers->size[0];
    allLayers->size[0] = b_allLayers->size[0];
    emxEnsureCapacity_cell_wrap_15(sp, allLayers, i, &vf_emlrtRTEI);
    i = b_allLayers->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = allLayers->data[i1].f1->size[0] * allLayers->data[i1].f1->size[1];
      allLayers->data[i1].f1->size[0] = b_allLayers->data[i1].f1->size[0];
      allLayers->data[i1].f1->size[1] = b_allLayers->data[i1].f1->size[1];
      emxEnsureCapacity_real_T(sp, allLayers->data[i1].f1, b_i, &vf_emlrtRTEI);
      loop_ub = b_allLayers->data[i1].f1->size[0] * b_allLayers->data[i1]
        .f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        allLayers->data[i1].f1->data[b_i] = b_allLayers->data[i1].f1->data[b_i];
      }
    }

    /*       case 'contrasts' */
    /*          [outSsubs,... */
    /*              backgs,... */
    /*              qshifts,... */
    /*              sfs,... */
    /*              nbas,... */
    /*              nbss,... */
    /*              resols,... */
    /*              chis,... */
    /*              reflectivity,... */
    /*              Simulation,... */
    /*              shifted_data,... */
    /*              layerSlds,... */
    /*              sldProfiles,... */
    /*              allLayers,... */
    /*              allRoughs] = standardTF_custXY_paraContrasts(resample, ... */
    /*              numberOfContrasts, ... */
    /*              geometry, ... */
    /*              repeatLayers , ... */
    /*              cBacks , ... */
    /*              cShifts , ... */
    /*              cScales , ... */
    /*              cNbas , ... */
    /*              cNbss, ... */
    /*              cRes , ... */
    /*              backs , ... */
    /*              shifts , ... */
    /*              sf, ... */
    /*              nba , ... */
    /*              nbs , ... */
    /*              res , ... */
    /*              dataPresent , ... */
    /*              allData , ... */
    /*              dataLimits , ... */
    /*              simLimits , ... */
    /*              nParams , ... */
    /*              params , ... */
    /*              contrastLayers , ... */
    /*              numberOfLayers , ... */
    /*              layersDetails, ... */
    /*              problemDef_limits, ... */
    /*              fname, ... */
    /*              lang, ... */
    /*              path,... */
    /*              backsType,... */
    /*              calcSLD); */
    break;

   default:
    covrtLogSwitch(&emlrtCoverageInstance, 30U, 0U, 0, 0);
    break;
  }

  emxFree_cell_wrap_15(&r2);
  emxFree_cell_wrap_8(&r1);
  emxFree_cell_wrap_8(&r);
  emxFree_cell_wrap_11(&b_allLayers);
  emxFree_cell_wrap_6(&b_sldProfiles);
  emxFree_cell_wrap_1(&b_layerSlds);
  emxFree_cell_wrap_1(&b_shifted_data);
  emxFree_cell_wrap_6(&b_Simulation);
  emxFree_cell_wrap_6(&b_reflectivity);
  covrtLogBasicBlock(&emlrtCoverageInstance, 30U, 15U);
  i = problem->calculations.all_chis->size[0];
  problem->calculations.all_chis->size[0] = chis->size[0];
  emxEnsureCapacity_real_T(sp, problem->calculations.all_chis, i, &aq_emlrtRTEI);
  loop_ub = chis->size[0];
  for (i = 0; i < loop_ub; i++) {
    problem->calculations.all_chis->data[i] = chis->data[i];
  }

  st.site = &ki_emlrtRSI;
  problem->calculations.sum_chi = sum(&st, chis);

  /* problem.calculations.reflectivity = reflectivity; */
  /* problem.calculations.Simulation = Simulation; */
  /* problem.shifted_data = shifted_data; */
  /* problem.layers = layerSlds; */
  /* problem.calculations.slds = sldProfiles; */
  /* problem.allLayers = allLayers; */
  /*  result = cell(1,6); */
  /*   */
  /*   */
  /*   */
  /*  %result = {{};{};{};{};{};{};{}}; */
  /*  result{1} = reflectivity; */
  /*  result{2} = Simulation; */
  /*  result{3} = shifted_data; */
  /*  result{4} = layerSlds; */
  /*  result{5} = sldProfiles; */
  /*  result{6} = allLayers; */
  /*   */
  /*   */
  /*  %Result coder definitions.... */
  /*   coder.varsize('result{1}',[Inf 1],[1 0]);           %Reflectivity */
  /*   coder.varsize('result{1}{:}',[Inf 2],[1 0]);         */
  /*  %  */
  /*   coder.varsize('result{2}',[Inf 1],[1 0]);           %Simulatin */
  /*   coder.varsize('result{2}{:}',[Inf 2],[1 0]); */
  /*  %  */
  /*   coder.varsize('result{3}',[Inf 1],[1 0]);           %Shifted data */
  /*   coder.varsize('result{3}{:}',[Inf 3],[1 0]); */
  /*  %  */
  /*   coder.varsize('result{4}',[Inf 1],[1 0]);           %Layers slds */
  /*   coder.varsize('result{4}{:}',[Inf 3],[1 0]); */
  /*  %  */
  /*   coder.varsize('result{5}',[Inf 1],[1 0]);           %Sld profiles */
  /*   coder.varsize('results{5}{:}',[Inf 2],[1 0]); */
  /*  %  */
  /*   coder.varsize('result{6}',[Inf 1],[1 0]);           %All layers  */
  /*   coder.varsize('result{6}{:}',[Inf 1],[1 0]); */
  covrtLogIf(&emlrtCoverageInstance, 30U, 0U, 0, false);
  emxFree_real_T(&chis);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_custXY_reflectivityCalculation.c) */
