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
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"
#include "standardTF_custlay_paraContrasts.h"
#include "standardTF_custlay_paraPoints.h"
#include "standardTF_custlay_single.h"
#include "sum.h"

/* Variable Definitions */
static emlrtRSInfo wg_emlrtRSI = { 102,/* lineNo */
  "standardTF_custLay_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo xg_emlrtRSI = { 149,/* lineNo */
  "standardTF_custLay_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo yg_emlrtRSI = { 196,/* lineNo */
  "standardTF_custLay_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo ah_emlrtRSI = { 252,/* lineNo */
  "standardTF_custLay_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pathName */
};

static emlrtBCInfo mk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  19,                                  /* colNo */
  "params",                            /* aName */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo lb_emlrtDCI = { 61, /* lineNo */
  21,                                  /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo cc_emlrtRTEI = { 62,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo dc_emlrtRTEI = { 68,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = { 75,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo fc_emlrtRTEI = { 81,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = { 87,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = { 93,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtDCInfo mb_emlrtDCI = { 245,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo nb_emlrtDCI = { 245,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo ob_emlrtDCI = { 246,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo pb_emlrtDCI = { 247,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo qb_emlrtDCI = { 248,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo rb_emlrtDCI = { 249,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo sb_emlrtDCI = { 57, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo tb_emlrtDCI = { 250,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo ub_emlrtDCI = { 253,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo nk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ok_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  94,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo hm_emlrtRTEI = { 244,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo im_emlrtRTEI = { 245,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo jm_emlrtRTEI = { 246,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo km_emlrtRTEI = { 247,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo lm_emlrtRTEI = { 248,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo mm_emlrtRTEI = { 249,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo nm_emlrtRTEI = { 57,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo om_emlrtRTEI = { 250,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo pm_emlrtRTEI = { 253,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo qm_emlrtRTEI = { 1,/* lineNo */
  91,                                  /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo rm_emlrtRTEI = { 63,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo sm_emlrtRTEI = { 69,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo tm_emlrtRTEI = { 76,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo um_emlrtRTEI = { 82,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo vm_emlrtRTEI = { 88,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo wm_emlrtRTEI = { 94,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo xm_emlrtRTEI = { 251,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

/* Function Definitions */
void c_standardTF_custLay_reflectivi(const emlrtStack *sp, const struct0_T
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
      &mk_emlrtBCI, sp);
  }

  i = problem->ssubs->size[0];
  problem->ssubs->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->ssubs, i, &hm_emlrtRTEI);
  problem->ssubs->data[0] = problemDef->params->data[0];
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &nb_emlrtDCI, sp);
  }

  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &mb_emlrtDCI, sp);
  }

  i1 = problem->backgrounds->size[0];
  loop_ub = (int32_T)problemDef->numberOfContrasts;
  problem->backgrounds->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->backgrounds, i1, &im_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &mb_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->backgrounds->data[i1] = 0.0;
  }

  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ob_emlrtDCI, sp);
  }

  loop_ub = (int32_T)problemDef->numberOfContrasts;
  i1 = problem->qshifts->size[0];
  problem->qshifts->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->qshifts, i1, &jm_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ob_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->qshifts->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &pb_emlrtDCI, sp);
  }

  i1 = problem->scalefactors->size[0];
  problem->scalefactors->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->scalefactors, i1, &km_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &pb_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->scalefactors->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &qb_emlrtDCI, sp);
  }

  i1 = problem->nbairs->size[0];
  problem->nbairs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->nbairs, i1, &lm_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &qb_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->nbairs->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &rb_emlrtDCI, sp);
  }

  i1 = problem->nbsubs->size[0];
  problem->nbsubs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->nbsubs, i1, &mm_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &rb_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->nbsubs->data[i1] = 0.0;
  }

  emxInit_real_T(sp, &chis, 1, &nm_emlrtRTEI, true);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &sb_emlrtDCI, sp);
  }

  i1 = chis->size[0];
  chis->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, chis, i1, &nm_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &sb_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    chis->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &tb_emlrtDCI, sp);
  }

  i1 = problem->resolutions->size[0];
  problem->resolutions->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->resolutions, i1, &om_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &tb_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->resolutions->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ub_emlrtDCI, sp);
  }

  i1 = problem->allSubRough->size[0];
  problem->allSubRough->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->allSubRough, i1, &pm_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ub_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->allSubRough->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &lb_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &cc_emlrtRTEI, sp);
  i = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_14(sp, reflectivity, i, &qm_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nk_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &rm_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nk_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &rm_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &nk_emlrtBCI, sp);
    }

    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &nk_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nk_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nk_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nk_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nk_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &dc_emlrtRTEI, sp);
  i = Simulation->size[0];
  Simulation->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, Simulation, i, &qm_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ok_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &sm_emlrtRTEI);
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ok_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &sm_emlrtRTEI);
    i = Simulation->size[0] - 1;
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ok_emlrtBCI, sp);
    }

    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ok_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ok_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ok_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ok_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ok_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &ec_emlrtRTEI, sp);
  i = shifted_data->size[0];
  shifted_data->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_9(sp, shifted_data, i, &qm_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i = shifted_data->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &pk_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &tm_emlrtRTEI);
    i = shifted_data->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &pk_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &tm_emlrtRTEI);
    i = shifted_data->size[0] - 1;
    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pk_emlrtBCI, sp);
    }

    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pk_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < 6; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &pk_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[i1] = 1.0;
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &fc_emlrtRTEI, sp);
  i = layerSlds->size[0];
  layerSlds->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_9(sp, layerSlds, i, &qm_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i = layerSlds->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &qk_emlrtBCI, sp);
    }

    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &um_emlrtRTEI);
    i = layerSlds->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &qk_emlrtBCI, sp);
    }

    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &um_emlrtRTEI);
    i = layerSlds->size[0] - 1;
    i1 = layerSlds->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &qk_emlrtBCI, sp);
    }

    i1 = layerSlds->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &qk_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < 6; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &qk_emlrtBCI, sp);
      }

      layerSlds->data[b_i].f1->data[i1] = 1.0;
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &gc_emlrtRTEI, sp);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, sldProfiles, i, &qm_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i = sldProfiles->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &rk_emlrtBCI, sp);
    }

    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &vm_emlrtRTEI);
    i = sldProfiles->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &rk_emlrtBCI, sp);
    }

    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &vm_emlrtRTEI);
    i = sldProfiles->size[0] - 1;
    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &rk_emlrtBCI, sp);
    }

    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &rk_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &rk_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &rk_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &rk_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &rk_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[3] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &hc_emlrtRTEI, sp);
  i = allLayers->size[0];
  allLayers->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_15(sp, allLayers, i, &qm_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &sk_emlrtBCI, sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &wm_emlrtRTEI);
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &sk_emlrtBCI, sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &wm_emlrtRTEI);
    i = allLayers->size[0] - 1;
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &sk_emlrtBCI, sp);
    }

    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &sk_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &sk_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &sk_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
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
        loop_ub = -1;
      }
    }
  }

  emxInit_cell_wrap_6(sp, &b_reflectivity, 1, &qm_emlrtRTEI, true);
  emxInit_cell_wrap_6(sp, &b_Simulation, 1, &qm_emlrtRTEI, true);
  emxInit_cell_wrap_1(sp, &b_shifted_data, 1, &qm_emlrtRTEI, true);
  emxInit_cell_wrap_1(sp, &b_layerSlds, 1, &qm_emlrtRTEI, true);
  emxInit_cell_wrap_6(sp, &b_sldProfiles, 1, &qm_emlrtRTEI, true);
  emxInit_cell_wrap_11(sp, &b_allLayers, 1, &qm_emlrtRTEI, true);
  emxInit_cell_wrap_8(sp, &r, 1, &qm_emlrtRTEI, true);
  emxInit_cell_wrap_8(sp, &r1, 1, &qm_emlrtRTEI, true);
  emxInit_cell_wrap_15(sp, &r2, 1, &qm_emlrtRTEI, true);
  switch (loop_ub) {
   case 0:
    st.site = &wg_emlrtRSI;
    standardTF_custlay_single(&st, problemDef->resample,
      problemDef->numberOfContrasts, problemDef->geometry, problemDef_cells->f1,
      problemDef->contrastBacks, problemDef->contrastShifts,
      problemDef->contrastScales, problemDef->contrastNbas,
      problemDef->contrastNbss, problemDef->contrastRes, problemDef->backs,
      problemDef->shifts, problemDef->sf, problemDef->nba, problemDef->nbs,
      problemDef->res, problemDef->dataPresent, problemDef_cells->f2,
      problemDef_cells->f3, problemDef_cells->f4, problemDef->params->size[1],
      problemDef->params, problemDef->modelFilename, problemDef->path,
      problemDef->contrastBacksType, problem->ssubs, problem->backgrounds,
      problem->qshifts, problem->scalefactors, problem->nbairs, problem->nbsubs,
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
    emxEnsureCapacity_cell_wrap_111(sp, b_allLayers, i, &vf_emlrtRTEI);
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
    st.site = &xg_emlrtRSI;
    standardTF_custlay_paraPoints(&st, problemDef->resample,
      problemDef->numberOfContrasts, problemDef->geometry, problemDef_cells->f1,
      problemDef->contrastBacks, problemDef->contrastShifts,
      problemDef->contrastScales, problemDef->contrastNbas,
      problemDef->contrastNbss, problemDef->contrastRes, problemDef->backs,
      problemDef->shifts, problemDef->sf, problemDef->nba, problemDef->nbs,
      problemDef->res, problemDef->dataPresent, problemDef_cells->f2,
      problemDef_cells->f3, problemDef_cells->f4, problemDef->params->size[1],
      problemDef->params, problemDef->modelFilename, problemDef->path,
      problemDef->contrastBacksType, problem->ssubs, problem->backgrounds,
      problem->qshifts, problem->scalefactors, problem->nbairs, problem->nbsubs,
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
    emxEnsureCapacity_cell_wrap_111(sp, b_allLayers, i, &vf_emlrtRTEI);
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

   case 2:
    st.site = &yg_emlrtRSI;
    c_standardTF_custlay_paraContra(&st, problemDef->resample,
      problemDef->numberOfContrasts, problemDef->geometry, problemDef_cells->f1,
      problemDef->contrastBacks, problemDef->contrastShifts,
      problemDef->contrastScales, problemDef->contrastNbas,
      problemDef->contrastNbss, problemDef->contrastRes, problemDef->backs,
      problemDef->shifts, problemDef->sf, problemDef->nba, problemDef->nbs,
      problemDef->res, problemDef->dataPresent, problemDef_cells->f2,
      problemDef_cells->f3, problemDef_cells->f4, problemDef->params->size[1],
      problemDef->params, problemDef->modelFilename, problemDef->path,
      problemDef->contrastBacksType, problem->ssubs, problem->backgrounds,
      problem->qshifts, problem->scalefactors, problem->nbairs, problem->nbsubs,
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
    emxEnsureCapacity_cell_wrap_111(sp, b_allLayers, i, &vf_emlrtRTEI);
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
  i = problem->calculations.all_chis->size[0];
  problem->calculations.all_chis->size[0] = chis->size[0];
  emxEnsureCapacity_real_T(sp, problem->calculations.all_chis, i, &xm_emlrtRTEI);
  loop_ub = chis->size[0];
  for (i = 0; i < loop_ub; i++) {
    problem->calculations.all_chis->data[i] = chis->data[i];
  }

  st.site = &ah_emlrtRSI;
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
  emxFree_real_T(&chis);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_custLay_reflectivityCalculation.c) */
