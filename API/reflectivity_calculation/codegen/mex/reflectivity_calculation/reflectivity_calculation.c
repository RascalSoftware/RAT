/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * reflectivity_calculation.c
 *
 * Code generation for function 'reflectivity_calculation'
 *
 */

/* Include files */
#include "reflectivity_calculation.h"
#include "mwmathutil.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"
#include "standardTF_reflectivityCalculation.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 59,    /* lineNo */
  "reflectivity_calculation",          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pathName */
};

static emlrtDCInfo emlrtDCI = { 19,    /* lineNo */
  21,                                  /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 19,  /* lineNo */
  21,                                  /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = { 20,  /* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtDCInfo c_emlrtDCI = { 25,  /* lineNo */
  19,                                  /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = { 26,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 32,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 38,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 44,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 50,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 72,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 79,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 86,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 93,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 100,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 107,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  27,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  33,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  16,                                  /* colNo */
  "reflectivity",                      /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  5,                                   /* colNo */
  "cell1",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  16,                                  /* colNo */
  "Simulation",                        /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  5,                                   /* colNo */
  "cell2",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  16,                                  /* colNo */
  "shifted_data",                      /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  5,                                   /* colNo */
  "cell3",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  94,                                  /* lineNo */
  16,                                  /* colNo */
  "layerSlds",                         /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  94,                                  /* lineNo */
  5,                                   /* colNo */
  "cell4",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  101,                                 /* lineNo */
  16,                                  /* colNo */
  "sldProfiles",                       /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  101,                                 /* lineNo */
  5,                                   /* colNo */
  "cell5",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  5,                                   /* colNo */
  "cell6",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo kd_emlrtRTEI = { 6,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ld_emlrtRTEI = { 7,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo md_emlrtRTEI = { 8,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo nd_emlrtRTEI = { 9,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo od_emlrtRTEI = { 10,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo pd_emlrtRTEI = { 11,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo qd_emlrtRTEI = { 12,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo rd_emlrtRTEI = { 13,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo sd_emlrtRTEI = { 15,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo td_emlrtRTEI = { 2,/* lineNo */
  29,                                  /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ud_emlrtRTEI = { 21,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo vd_emlrtRTEI = { 27,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo wd_emlrtRTEI = { 33,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo xd_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo yd_emlrtRTEI = { 45,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ae_emlrtRTEI = { 51,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo be_emlrtRTEI = { 59,/* lineNo */
  136,                                 /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ce_emlrtRTEI = { 75,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo de_emlrtRTEI = { 82,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ee_emlrtRTEI = { 73,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo fe_emlrtRTEI = { 89,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ge_emlrtRTEI = { 80,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo he_emlrtRTEI = { 96,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ie_emlrtRTEI = { 87,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo je_emlrtRTEI = { 103,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ke_emlrtRTEI = { 94,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo le_emlrtRTEI = { 110,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo me_emlrtRTEI = { 101,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ne_emlrtRTEI = { 59,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo oe_emlrtRTEI = { 59,/* lineNo */
  18,                                  /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo re_emlrtRTEI = { 19,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo se_emlrtRTEI = { 25,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo te_emlrtRTEI = { 31,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ue_emlrtRTEI = { 37,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ve_emlrtRTEI = { 43,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo we_emlrtRTEI = { 49,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo xe_emlrtRTEI = { 71,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ye_emlrtRTEI = { 85,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo af_emlrtRTEI = { 106,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

/* Function Definitions */
void reflectivity_calculation(const emlrtStack *sp, const struct0_T *problemDef,
  const cell_5 *problemDef_cells, const struct1_T *problemDef_limits, const
  struct2_T *controls, struct4_T *problem, cell_7 *result)
{
  int32_T i;
  emxArray_cell_wrap_8 *reflectivity;
  int32_T i1;
  int32_T i2;
  int32_T b_i;
  emxArray_cell_wrap_8 *Simulation;
  emxArray_cell_wrap_9 *shifted_data;
  int32_T i3;
  emxArray_cell_wrap_9 *layerSlds;
  emxArray_cell_wrap_8 *sldProfiles;
  emxArray_cell_wrap_10 *allLayers;
  boolean_T b_bool;
  int32_T kstr;
  int32_T exitg1;
  emxArray_cell_wrap_6 *cell1;
  static const char_T b_cv[10] = { 's', 't', 'a', 'n', 'd', 'a', 'r', 'd', 'T',
    'F' };

  emxArray_cell_wrap_1 *cell3;
  emxArray_cell_wrap_0 *t0_f1;
  emxArray_cell_wrap_1 *t0_f2;
  emxArray_cell_wrap_0 *t0_f3;
  emxArray_cell_wrap_0 *t0_f4;
  emxArray_cell_wrap_11 *t0_f5;
  emxArray_cell_wrap_3 *t0_f6;
  emxArray_cell_wrap_4 *t0_f7;
  emxArray_cell_wrap_4 *t0_f8;
  emxArray_cell_wrap_4 *t0_f9;
  emxArray_cell_wrap_4 *t0_f10;
  emxArray_cell_wrap_4 *t0_f11;
  emxArray_int8_T *cell6;
  emxArray_cell_wrap_4 *t0_f12;
  emxArray_cell_wrap_4 *t0_f13;
  cell_13 expl_temp;
  emxArray_cell_wrap_11 *b_reflectivity;
  emxArray_cell_wrap_1 *b_layerSlds;
  emxArray_cell_wrap_11 *b_sldProfiles;
  emxArray_cell_wrap_11 *b_allLayers;
  emlrtStack st;
  (void)problemDef_limits;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);

  /* Preallocatin of outputs */
  i = problem->ssubs->size[0];
  problem->ssubs->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->ssubs, i, &kd_emlrtRTEI);
  problem->ssubs->data[0] = 0.0;
  i = problem->backgrounds->size[0];
  problem->backgrounds->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->backgrounds, i, &ld_emlrtRTEI);
  problem->backgrounds->data[0] = 0.0;
  i = problem->qshifts->size[0];
  problem->qshifts->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->qshifts, i, &md_emlrtRTEI);
  problem->qshifts->data[0] = 0.0;
  i = problem->scalefactors->size[0];
  problem->scalefactors->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->scalefactors, i, &nd_emlrtRTEI);
  problem->scalefactors->data[0] = 0.0;
  i = problem->nbairs->size[0];
  problem->nbairs->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->nbairs, i, &od_emlrtRTEI);
  problem->nbairs->data[0] = 0.0;
  i = problem->nbsubs->size[0];
  problem->nbsubs->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->nbsubs, i, &pd_emlrtRTEI);
  problem->nbsubs->data[0] = 0.0;
  i = problem->resolutions->size[0];
  problem->resolutions->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->resolutions, i, &qd_emlrtRTEI);
  problem->resolutions->data[0] = 0.0;
  i = problem->calculations.all_chis->size[0];
  problem->calculations.all_chis->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->calculations.all_chis, i, &rd_emlrtRTEI);
  problem->calculations.all_chis->data[0] = 0.0;
  problem->calculations.sum_chi = 0.0;
  i = problem->allSubRough->size[0];
  problem->allSubRough->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->allSubRough, i, &sd_emlrtRTEI);
  problem->allSubRough->data[0] = 0.0;
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &emlrtDCI, sp);
  }

  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &b_emlrtDCI, sp);
  }

  emxInit_cell_wrap_8(sp, &reflectivity, 1, &re_emlrtRTEI, true);
  i1 = (int32_T)problemDef->numberOfContrasts;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &emlrtRTEI, sp);
  i2 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, reflectivity, i2, &td_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 1U);
    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &emlrtBCI, sp);
    }

    i2 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i2, &ud_emlrtRTEI);
    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &emlrtBCI, sp);
    }

    i2 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i2, &ud_emlrtRTEI);
    i2 = reflectivity->size[0] - 1;
    i3 = reflectivity->size[0] - 1;
    if (b_i > i3) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &emlrtBCI, sp);
    }

    i3 = reflectivity->size[0] - 1;
    if (b_i > i3) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &emlrtBCI, sp);
    }

    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 2U);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &c_emlrtDCI, sp);
  }

  emxInit_cell_wrap_8(sp, &Simulation, 1, &se_emlrtRTEI, true);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &b_emlrtRTEI, sp);
  i = Simulation->size[0];
  Simulation->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, Simulation, i, &td_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 3U);
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &b_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &vd_emlrtRTEI);
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &b_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &vd_emlrtRTEI);
    i = Simulation->size[0] - 1;
    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &b_emlrtBCI, sp);
    }

    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &b_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &b_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &b_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &b_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &b_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
  }

  emxInit_cell_wrap_9(sp, &shifted_data, 1, &te_emlrtRTEI, true);
  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 4U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &c_emlrtRTEI, sp);
  i = shifted_data->size[0];
  shifted_data->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_9(sp, shifted_data, i, &td_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 5U);
    i = shifted_data->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &c_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &wd_emlrtRTEI);
    i = shifted_data->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &c_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &wd_emlrtRTEI);
    i = shifted_data->size[0] - 1;
    i2 = shifted_data->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &c_emlrtBCI, sp);
    }

    i2 = shifted_data->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &c_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < 6; i2++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &c_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[i2] = 1.0;
    }
  }

  emxInit_cell_wrap_9(sp, &layerSlds, 1, &ue_emlrtRTEI, true);
  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 6U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &d_emlrtRTEI, sp);
  i = layerSlds->size[0];
  layerSlds->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_9(sp, layerSlds, i, &td_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 7U);
    i = layerSlds->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &d_emlrtBCI, sp);
    }

    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &xd_emlrtRTEI);
    i = layerSlds->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &d_emlrtBCI, sp);
    }

    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &xd_emlrtRTEI);
    i = layerSlds->size[0] - 1;
    i2 = layerSlds->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &d_emlrtBCI, sp);
    }

    i2 = layerSlds->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &d_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < 6; i2++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &d_emlrtBCI, sp);
      }

      layerSlds->data[b_i].f1->data[i2] = 1.0;
    }
  }

  emxInit_cell_wrap_8(sp, &sldProfiles, 1, &ve_emlrtRTEI, true);
  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 3, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 8U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &e_emlrtRTEI, sp);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, sldProfiles, i, &td_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 4, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 9U);
    i = sldProfiles->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &e_emlrtBCI, sp);
    }

    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &yd_emlrtRTEI);
    i = sldProfiles->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &e_emlrtBCI, sp);
    }

    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &yd_emlrtRTEI);
    i = sldProfiles->size[0] - 1;
    i2 = sldProfiles->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &e_emlrtBCI, sp);
    }

    i2 = sldProfiles->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &e_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &e_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &e_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &e_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &e_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[3] = 1.0;
  }

  emxInit_cell_wrap_10(sp, &allLayers, 1, &we_emlrtRTEI, true);
  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 4, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 10U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &f_emlrtRTEI, sp);
  i = allLayers->size[0];
  allLayers->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_10(sp, allLayers, i, &td_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 5, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 11U);
    i = allLayers->size[0] - 1;
    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &f_emlrtBCI, sp);
    }

    i2 = allLayers->data[b_i].f1->size[0];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i2, &ae_emlrtRTEI);
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &f_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &f_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
  }

  emxFree_cell_wrap_10(&allLayers);
  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 5, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 12U);

  /* Decide which target function we are calling */
  b_bool = false;
  if (problemDef->TF->size[1] == 10) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 10) {
        if (problemDef->TF->data[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  if (b_bool) {
    kstr = 0;
  } else {
    kstr = -1;
  }

  emxInit_cell_wrap_6(sp, &cell1, 1, &xe_emlrtRTEI, true);
  emxInit_cell_wrap_1(sp, &cell3, 1, &ye_emlrtRTEI, true);
  switch (kstr) {
   case 0:
    emxInit_cell_wrap_0(sp, &t0_f1, 2, &be_emlrtRTEI, true);
    covrtLogSwitch(&emlrtCoverageInstance, 0U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 13U);
    i = t0_f1->size[0] * t0_f1->size[1];
    t0_f1->size[0] = 1;
    t0_f1->size[1] = problemDef_cells->f1->size[1];
    emxEnsureCapacity_cell_wrap_0(sp, t0_f1, i, &be_emlrtRTEI);
    kstr = problemDef_cells->f1->size[0] * problemDef_cells->f1->size[1];
    for (i = 0; i < kstr; i++) {
      t0_f1->data[i] = problemDef_cells->f1->data[i];
    }

    emxInit_cell_wrap_1(sp, &t0_f2, 2, &be_emlrtRTEI, true);
    i = t0_f2->size[0] * t0_f2->size[1];
    t0_f2->size[0] = 1;
    t0_f2->size[1] = problemDef_cells->f2->size[1];
    emxEnsureCapacity_cell_wrap_1(sp, t0_f2, i, &be_emlrtRTEI);
    kstr = problemDef_cells->f2->size[0] * problemDef_cells->f2->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_1(sp, &t0_f2->data[i], &problemDef_cells->f2->
        data[i], &be_emlrtRTEI);
    }

    emxInit_cell_wrap_0(sp, &t0_f3, 2, &be_emlrtRTEI, true);
    i = t0_f3->size[0] * t0_f3->size[1];
    t0_f3->size[0] = 1;
    t0_f3->size[1] = problemDef_cells->f3->size[1];
    emxEnsureCapacity_cell_wrap_0(sp, t0_f3, i, &be_emlrtRTEI);
    kstr = problemDef_cells->f3->size[0] * problemDef_cells->f3->size[1];
    for (i = 0; i < kstr; i++) {
      t0_f3->data[i] = problemDef_cells->f3->data[i];
    }

    emxInit_cell_wrap_0(sp, &t0_f4, 2, &be_emlrtRTEI, true);
    i = t0_f4->size[0] * t0_f4->size[1];
    t0_f4->size[0] = 1;
    t0_f4->size[1] = problemDef_cells->f4->size[1];
    emxEnsureCapacity_cell_wrap_0(sp, t0_f4, i, &be_emlrtRTEI);
    kstr = problemDef_cells->f4->size[0] * problemDef_cells->f4->size[1];
    for (i = 0; i < kstr; i++) {
      t0_f4->data[i] = problemDef_cells->f4->data[i];
    }

    emxInit_cell_wrap_11(sp, &t0_f5, 2, &be_emlrtRTEI, true);
    i = t0_f5->size[0] * t0_f5->size[1];
    t0_f5->size[0] = 1;
    t0_f5->size[1] = problemDef_cells->f5->size[1];
    emxEnsureCapacity_cell_wrap_11(sp, t0_f5, i, &be_emlrtRTEI);
    i = problemDef_cells->f5->size[1] - 1;
    for (i2 = 0; i2 <= i; i2++) {
      i3 = t0_f5->data[i2].f1->size[0] * t0_f5->data[i2].f1->size[1];
      t0_f5->data[i2].f1->size[0] = problemDef_cells->f5->data[i2].f1->size[0];
      t0_f5->data[i2].f1->size[1] = problemDef_cells->f5->data[i2].f1->size[1];
      emxEnsureCapacity_real_T(sp, t0_f5->data[i2].f1, i3, &be_emlrtRTEI);
      kstr = problemDef_cells->f5->data[i2].f1->size[0] * problemDef_cells->
        f5->data[i2].f1->size[1];
      for (i3 = 0; i3 < kstr; i3++) {
        t0_f5->data[i2].f1->data[i3] = problemDef_cells->f5->data[i2].f1->
          data[i3];
      }
    }

    emxInit_cell_wrap_3(sp, &t0_f6, 1, &be_emlrtRTEI, true);
    i = t0_f6->size[0];
    t0_f6->size[0] = problemDef_cells->f6->size[0];
    emxEnsureCapacity_cell_wrap_3(sp, t0_f6, i, &be_emlrtRTEI);
    kstr = problemDef_cells->f6->size[0];
    for (i = 0; i < kstr; i++) {
      t0_f6->data[i] = problemDef_cells->f6->data[i];
    }

    emxInit_cell_wrap_4(sp, &t0_f7, 2, &be_emlrtRTEI, true);
    i = t0_f7->size[0] * t0_f7->size[1];
    t0_f7->size[0] = 1;
    t0_f7->size[1] = problemDef_cells->f7->size[1];
    emxEnsureCapacity_cell_wrap_4(sp, t0_f7, i, &be_emlrtRTEI);
    kstr = problemDef_cells->f7->size[0] * problemDef_cells->f7->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_4(sp, &t0_f7->data[i], &problemDef_cells->f7->
        data[i], &be_emlrtRTEI);
    }

    emxInit_cell_wrap_4(sp, &t0_f8, 2, &be_emlrtRTEI, true);
    i = t0_f8->size[0] * t0_f8->size[1];
    t0_f8->size[0] = 1;
    t0_f8->size[1] = problemDef_cells->f8->size[1];
    emxEnsureCapacity_cell_wrap_4(sp, t0_f8, i, &be_emlrtRTEI);
    kstr = problemDef_cells->f8->size[0] * problemDef_cells->f8->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_4(sp, &t0_f8->data[i], &problemDef_cells->f8->
        data[i], &be_emlrtRTEI);
    }

    emxInit_cell_wrap_4(sp, &t0_f9, 2, &be_emlrtRTEI, true);
    i = t0_f9->size[0] * t0_f9->size[1];
    t0_f9->size[0] = 1;
    t0_f9->size[1] = problemDef_cells->f9->size[1];
    emxEnsureCapacity_cell_wrap_4(sp, t0_f9, i, &be_emlrtRTEI);
    kstr = problemDef_cells->f9->size[0] * problemDef_cells->f9->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_4(sp, &t0_f9->data[i], &problemDef_cells->f9->
        data[i], &be_emlrtRTEI);
    }

    emxInit_cell_wrap_4(sp, &t0_f10, 2, &be_emlrtRTEI, true);
    i = t0_f10->size[0] * t0_f10->size[1];
    t0_f10->size[0] = 1;
    t0_f10->size[1] = problemDef_cells->f10->size[1];
    emxEnsureCapacity_cell_wrap_4(sp, t0_f10, i, &be_emlrtRTEI);
    kstr = problemDef_cells->f10->size[0] * problemDef_cells->f10->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_4(sp, &t0_f10->data[i], &problemDef_cells->
        f10->data[i], &be_emlrtRTEI);
    }

    emxInit_cell_wrap_4(sp, &t0_f11, 2, &be_emlrtRTEI, true);
    i = t0_f11->size[0] * t0_f11->size[1];
    t0_f11->size[0] = 1;
    t0_f11->size[1] = problemDef_cells->f11->size[1];
    emxEnsureCapacity_cell_wrap_4(sp, t0_f11, i, &be_emlrtRTEI);
    kstr = problemDef_cells->f11->size[0] * problemDef_cells->f11->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_4(sp, &t0_f11->data[i], &problemDef_cells->
        f11->data[i], &be_emlrtRTEI);
    }

    emxInit_cell_wrap_4(sp, &t0_f12, 2, &be_emlrtRTEI, true);
    i = t0_f12->size[0] * t0_f12->size[1];
    t0_f12->size[0] = 1;
    t0_f12->size[1] = problemDef_cells->f12->size[1];
    emxEnsureCapacity_cell_wrap_4(sp, t0_f12, i, &be_emlrtRTEI);
    kstr = problemDef_cells->f12->size[0] * problemDef_cells->f12->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_4(sp, &t0_f12->data[i], &problemDef_cells->
        f12->data[i], &be_emlrtRTEI);
    }

    emxInit_cell_wrap_4(sp, &t0_f13, 2, &be_emlrtRTEI, true);
    i = t0_f13->size[0] * t0_f13->size[1];
    t0_f13->size[0] = 1;
    t0_f13->size[1] = problemDef_cells->f13->size[1];
    emxEnsureCapacity_cell_wrap_4(sp, t0_f13, i, &be_emlrtRTEI);
    kstr = problemDef_cells->f13->size[0] * problemDef_cells->f13->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_4(sp, &t0_f13->data[i], &problemDef_cells->
        f13->data[i], &be_emlrtRTEI);
    }

    emxInitStruct_cell_13(sp, &expl_temp, &ne_emlrtRTEI, true);
    i = expl_temp.f13->size[0] * expl_temp.f13->size[1];
    expl_temp.f13->size[0] = 1;
    expl_temp.f13->size[1] = t0_f13->size[1];
    emxEnsureCapacity_cell_wrap_4(sp, expl_temp.f13, i, &ne_emlrtRTEI);
    kstr = t0_f13->size[0] * t0_f13->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_4(sp, &expl_temp.f13->data[i], &t0_f13->data[i],
        &ne_emlrtRTEI);
    }

    emxFree_cell_wrap_4(&t0_f13);
    i = expl_temp.f12->size[0] * expl_temp.f12->size[1];
    expl_temp.f12->size[0] = 1;
    expl_temp.f12->size[1] = t0_f12->size[1];
    emxEnsureCapacity_cell_wrap_4(sp, expl_temp.f12, i, &ne_emlrtRTEI);
    kstr = t0_f12->size[0] * t0_f12->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_4(sp, &expl_temp.f12->data[i], &t0_f12->data[i],
        &ne_emlrtRTEI);
    }

    emxFree_cell_wrap_4(&t0_f12);
    i = expl_temp.f11->size[0] * expl_temp.f11->size[1];
    expl_temp.f11->size[0] = 1;
    expl_temp.f11->size[1] = t0_f11->size[1];
    emxEnsureCapacity_cell_wrap_4(sp, expl_temp.f11, i, &ne_emlrtRTEI);
    kstr = t0_f11->size[0] * t0_f11->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_4(sp, &expl_temp.f11->data[i], &t0_f11->data[i],
        &ne_emlrtRTEI);
    }

    emxFree_cell_wrap_4(&t0_f11);
    i = expl_temp.f10->size[0] * expl_temp.f10->size[1];
    expl_temp.f10->size[0] = 1;
    expl_temp.f10->size[1] = t0_f10->size[1];
    emxEnsureCapacity_cell_wrap_4(sp, expl_temp.f10, i, &ne_emlrtRTEI);
    kstr = t0_f10->size[0] * t0_f10->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_4(sp, &expl_temp.f10->data[i], &t0_f10->data[i],
        &ne_emlrtRTEI);
    }

    emxFree_cell_wrap_4(&t0_f10);
    i = expl_temp.f9->size[0] * expl_temp.f9->size[1];
    expl_temp.f9->size[0] = 1;
    expl_temp.f9->size[1] = t0_f9->size[1];
    emxEnsureCapacity_cell_wrap_4(sp, expl_temp.f9, i, &ne_emlrtRTEI);
    kstr = t0_f9->size[0] * t0_f9->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_4(sp, &expl_temp.f9->data[i], &t0_f9->data[i],
        &ne_emlrtRTEI);
    }

    emxFree_cell_wrap_4(&t0_f9);
    i = expl_temp.f8->size[0] * expl_temp.f8->size[1];
    expl_temp.f8->size[0] = 1;
    expl_temp.f8->size[1] = t0_f8->size[1];
    emxEnsureCapacity_cell_wrap_4(sp, expl_temp.f8, i, &ne_emlrtRTEI);
    kstr = t0_f8->size[0] * t0_f8->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_4(sp, &expl_temp.f8->data[i], &t0_f8->data[i],
        &ne_emlrtRTEI);
    }

    emxFree_cell_wrap_4(&t0_f8);
    i = expl_temp.f7->size[0] * expl_temp.f7->size[1];
    expl_temp.f7->size[0] = 1;
    expl_temp.f7->size[1] = t0_f7->size[1];
    emxEnsureCapacity_cell_wrap_4(sp, expl_temp.f7, i, &ne_emlrtRTEI);
    kstr = t0_f7->size[0] * t0_f7->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_4(sp, &expl_temp.f7->data[i], &t0_f7->data[i],
        &ne_emlrtRTEI);
    }

    emxFree_cell_wrap_4(&t0_f7);
    i = expl_temp.f6->size[0];
    expl_temp.f6->size[0] = t0_f6->size[0];
    emxEnsureCapacity_cell_wrap_3(sp, expl_temp.f6, i, &ne_emlrtRTEI);
    kstr = t0_f6->size[0];
    for (i = 0; i < kstr; i++) {
      expl_temp.f6->data[i] = t0_f6->data[i];
    }

    emxFree_cell_wrap_3(&t0_f6);
    i = expl_temp.f5->size[0] * expl_temp.f5->size[1];
    expl_temp.f5->size[0] = 1;
    expl_temp.f5->size[1] = t0_f5->size[1];
    emxEnsureCapacity_cell_wrap_11(sp, expl_temp.f5, i, &ne_emlrtRTEI);
    kstr = t0_f5->size[0] * t0_f5->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_11(sp, &expl_temp.f5->data[i], &t0_f5->data[i],
        &ne_emlrtRTEI);
    }

    emxFree_cell_wrap_11(&t0_f5);
    i = expl_temp.f4->size[0] * expl_temp.f4->size[1];
    expl_temp.f4->size[0] = 1;
    expl_temp.f4->size[1] = t0_f4->size[1];
    emxEnsureCapacity_cell_wrap_0(sp, expl_temp.f4, i, &ne_emlrtRTEI);
    kstr = t0_f4->size[0] * t0_f4->size[1];
    for (i = 0; i < kstr; i++) {
      expl_temp.f4->data[i] = t0_f4->data[i];
    }

    emxFree_cell_wrap_0(&t0_f4);
    i = expl_temp.f3->size[0] * expl_temp.f3->size[1];
    expl_temp.f3->size[0] = 1;
    expl_temp.f3->size[1] = t0_f3->size[1];
    emxEnsureCapacity_cell_wrap_0(sp, expl_temp.f3, i, &ne_emlrtRTEI);
    kstr = t0_f3->size[0] * t0_f3->size[1];
    for (i = 0; i < kstr; i++) {
      expl_temp.f3->data[i] = t0_f3->data[i];
    }

    emxFree_cell_wrap_0(&t0_f3);
    i = expl_temp.f2->size[0] * expl_temp.f2->size[1];
    expl_temp.f2->size[0] = 1;
    expl_temp.f2->size[1] = t0_f2->size[1];
    emxEnsureCapacity_cell_wrap_1(sp, expl_temp.f2, i, &ne_emlrtRTEI);
    kstr = t0_f2->size[0] * t0_f2->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_1(sp, &expl_temp.f2->data[i], &t0_f2->data[i],
        &ne_emlrtRTEI);
    }

    emxFree_cell_wrap_1(&t0_f2);
    i = expl_temp.f1->size[0] * expl_temp.f1->size[1];
    expl_temp.f1->size[0] = 1;
    expl_temp.f1->size[1] = t0_f1->size[1];
    emxEnsureCapacity_cell_wrap_0(sp, expl_temp.f1, i, &ne_emlrtRTEI);
    kstr = t0_f1->size[0] * t0_f1->size[1];
    for (i = 0; i < kstr; i++) {
      expl_temp.f1->data[i] = t0_f1->data[i];
    }

    emxFree_cell_wrap_0(&t0_f1);
    emxInit_cell_wrap_11(sp, &b_reflectivity, 1, &td_emlrtRTEI, true);
    emxInit_cell_wrap_1(sp, &b_layerSlds, 1, &td_emlrtRTEI, true);
    emxInit_cell_wrap_11(sp, &b_sldProfiles, 1, &td_emlrtRTEI, true);
    emxInit_cell_wrap_11(sp, &b_allLayers, 1, &td_emlrtRTEI, true);
    st.site = &emlrtRSI;
    c_standardTF_reflectivityCalcul(&st, problemDef, &expl_temp, controls,
      problem, b_reflectivity, cell1, cell3, b_layerSlds, b_sldProfiles,
      b_allLayers);
    i = reflectivity->size[0];
    reflectivity->size[0] = b_reflectivity->size[0];
    emxEnsureCapacity_cell_wrap_8(sp, reflectivity, i, &oe_emlrtRTEI);
    i = b_reflectivity->size[0];
    emxFreeStruct_cell_13(&expl_temp);
    emxFree_cell_wrap_11(&b_allLayers);
    for (i2 = 0; i2 < i; i2++) {
      i3 = reflectivity->data[i2].f1->size[0] * reflectivity->data[i2].f1->size
        [1];
      reflectivity->data[i2].f1->size[0] = b_reflectivity->data[i2].f1->size[0];
      reflectivity->data[i2].f1->size[1] = b_reflectivity->data[i2].f1->size[1];
      emxEnsureCapacity_real_T(sp, reflectivity->data[i2].f1, i3, &oe_emlrtRTEI);
      kstr = b_reflectivity->data[i2].f1->size[0] * b_reflectivity->data[i2].
        f1->size[1];
      for (i3 = 0; i3 < kstr; i3++) {
        reflectivity->data[i2].f1->data[i3] = b_reflectivity->data[i2].f1->
          data[i3];
      }
    }

    emxFree_cell_wrap_11(&b_reflectivity);
    i = Simulation->size[0];
    Simulation->size[0] = cell1->size[0];
    emxEnsureCapacity_cell_wrap_8(sp, Simulation, i, &pe_emlrtRTEI);
    i = cell1->size[0];
    for (i2 = 0; i2 < i; i2++) {
      i3 = Simulation->data[i2].f1->size[0] * Simulation->data[i2].f1->size[1];
      Simulation->data[i2].f1->size[0] = cell1->data[i2].f1->size[0];
      Simulation->data[i2].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, Simulation->data[i2].f1, i3, &pe_emlrtRTEI);
      kstr = cell1->data[i2].f1->size[0] * cell1->data[i2].f1->size[1];
      for (i3 = 0; i3 < kstr; i3++) {
        Simulation->data[i2].f1->data[i3] = cell1->data[i2].f1->data[i3];
      }
    }

    i = shifted_data->size[0];
    shifted_data->size[0] = cell3->size[0];
    emxEnsureCapacity_cell_wrap_9(sp, shifted_data, i, &qe_emlrtRTEI);
    i = cell3->size[0];
    for (i2 = 0; i2 < i; i2++) {
      i3 = shifted_data->data[i2].f1->size[0] * shifted_data->data[i2].f1->size
        [1];
      shifted_data->data[i2].f1->size[0] = cell3->data[i2].f1->size[0];
      shifted_data->data[i2].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, shifted_data->data[i2].f1, i3, &qe_emlrtRTEI);
      kstr = cell3->data[i2].f1->size[0] * cell3->data[i2].f1->size[1];
      for (i3 = 0; i3 < kstr; i3++) {
        shifted_data->data[i2].f1->data[i3] = cell3->data[i2].f1->data[i3];
      }
    }

    i = layerSlds->size[0];
    layerSlds->size[0] = b_layerSlds->size[0];
    emxEnsureCapacity_cell_wrap_9(sp, layerSlds, i, &qe_emlrtRTEI);
    i = b_layerSlds->size[0];
    for (i2 = 0; i2 < i; i2++) {
      i3 = layerSlds->data[i2].f1->size[0] * layerSlds->data[i2].f1->size[1];
      layerSlds->data[i2].f1->size[0] = b_layerSlds->data[i2].f1->size[0];
      layerSlds->data[i2].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, layerSlds->data[i2].f1, i3, &qe_emlrtRTEI);
      kstr = b_layerSlds->data[i2].f1->size[0] * b_layerSlds->data[i2].f1->size
        [1];
      for (i3 = 0; i3 < kstr; i3++) {
        layerSlds->data[i2].f1->data[i3] = b_layerSlds->data[i2].f1->data[i3];
      }
    }

    emxFree_cell_wrap_1(&b_layerSlds);
    i = sldProfiles->size[0];
    sldProfiles->size[0] = b_sldProfiles->size[0];
    emxEnsureCapacity_cell_wrap_8(sp, sldProfiles, i, &oe_emlrtRTEI);
    i = b_sldProfiles->size[0];
    for (i2 = 0; i2 < i; i2++) {
      i3 = sldProfiles->data[i2].f1->size[0] * sldProfiles->data[i2].f1->size[1];
      sldProfiles->data[i2].f1->size[0] = b_sldProfiles->data[i2].f1->size[0];
      sldProfiles->data[i2].f1->size[1] = b_sldProfiles->data[i2].f1->size[1];
      emxEnsureCapacity_real_T(sp, sldProfiles->data[i2].f1, i3, &oe_emlrtRTEI);
      kstr = b_sldProfiles->data[i2].f1->size[0] * b_sldProfiles->data[i2]
        .f1->size[1];
      for (i3 = 0; i3 < kstr; i3++) {
        sldProfiles->data[i2].f1->data[i3] = b_sldProfiles->data[i2].f1->data[i3];
      }
    }

    emxFree_cell_wrap_11(&b_sldProfiles);

    /* case 'oilWaterTF' */
    /* problem = oilWaterTF_reflectivityCalculation(problemDef,problemDef_cells,controls);     */
    /* case 'polarisedTF' */
    /* problem = polarisedTF_reflectivityCalculation(problemDef,problemDef_cells,controls); */
    /* case 'domainsTF' */
    /* problem = domainsTF_reflectivityCalculation(problemDef,problemDef_cells,controls); */
    break;

   default:
    covrtLogSwitch(&emlrtCoverageInstance, 0U, 0U, 0, 0);
    break;
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 14U);

  /* cell1Length = numberOfContrasts; */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &g_emlrtRTEI, sp);
  i = cell1->size[0];
  cell1->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, cell1, i, &td_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 6, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 15U);
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &g_emlrtBCI, sp);
    }

    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &g_emlrtBCI, sp);
    }

    kstr = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i]
      .f1->size[1];
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &g_emlrtBCI, sp);
    }

    i = cell1->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &h_emlrtBCI, sp);
    }

    i = cell1->data[b_i].f1->size[0] * cell1->data[b_i].f1->size[1];
    cell1->data[b_i].f1->size[0] = reflectivity->data[b_i].f1->size[0];
    emxEnsureCapacity_real_T(sp, cell1->data[b_i].f1, i, &ee_emlrtRTEI);
    i = cell1->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &h_emlrtBCI, sp);
    }

    i = cell1->data[b_i].f1->size[0] * cell1->data[b_i].f1->size[1];
    cell1->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, cell1->data[b_i].f1, i, &ee_emlrtRTEI);
    i = cell1->size[0] - 1;
    i2 = cell1->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &h_emlrtBCI, sp);
    }

    i2 = cell1->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &h_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < kstr; i2++) {
      i3 = reflectivity->size[0] - 1;
      if (b_i > i3) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &g_emlrtBCI, sp);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &h_emlrtBCI, sp);
      }

      cell1->data[b_i].f1->data[i2] = reflectivity->data[b_i].f1->data[i2];
    }
  }

  emxFree_cell_wrap_8(&reflectivity);
  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 6, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 16U);
  i = result->f1->size[0];
  result->f1->size[0] = cell1->size[0];
  emxEnsureCapacity_cell_wrap_6(sp, result->f1, i, &ce_emlrtRTEI);
  kstr = cell1->size[0];
  for (i = 0; i < kstr; i++) {
    emxCopyStruct_cell_wrap_6(sp, &result->f1->data[i], &cell1->data[i],
      &ce_emlrtRTEI);
  }

  /*  cell2Length = 7; */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &h_emlrtRTEI, sp);
  i = cell1->size[0];
  cell1->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, cell1, i, &td_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 7, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 17U);
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &i_emlrtBCI, sp);
    }

    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &i_emlrtBCI, sp);
    }

    kstr = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &i_emlrtBCI, sp);
    }

    i = cell1->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &j_emlrtBCI, sp);
    }

    i = cell1->data[b_i].f1->size[0] * cell1->data[b_i].f1->size[1];
    cell1->data[b_i].f1->size[0] = Simulation->data[b_i].f1->size[0];
    emxEnsureCapacity_real_T(sp, cell1->data[b_i].f1, i, &ge_emlrtRTEI);
    i = cell1->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &j_emlrtBCI, sp);
    }

    i = cell1->data[b_i].f1->size[0] * cell1->data[b_i].f1->size[1];
    cell1->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, cell1->data[b_i].f1, i, &ge_emlrtRTEI);
    i = cell1->size[0] - 1;
    i2 = cell1->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &j_emlrtBCI, sp);
    }

    i2 = cell1->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &j_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < kstr; i2++) {
      i3 = Simulation->size[0] - 1;
      if (b_i > i3) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &i_emlrtBCI, sp);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &j_emlrtBCI, sp);
      }

      cell1->data[b_i].f1->data[i2] = Simulation->data[b_i].f1->data[i2];
    }
  }

  emxFree_cell_wrap_8(&Simulation);
  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 7, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 18U);
  i = result->f2->size[0];
  result->f2->size[0] = cell1->size[0];
  emxEnsureCapacity_cell_wrap_6(sp, result->f2, i, &de_emlrtRTEI);
  kstr = cell1->size[0];
  for (i = 0; i < kstr; i++) {
    emxCopyStruct_cell_wrap_6(sp, &result->f2->data[i], &cell1->data[i],
      &de_emlrtRTEI);
  }

  /*   */
  /*  cell3Length = 7; */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &i_emlrtRTEI, sp);
  i = cell3->size[0];
  cell3->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, cell3, i, &td_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 8, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 19U);
    i = shifted_data->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &k_emlrtBCI, sp);
    }

    i = shifted_data->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &k_emlrtBCI, sp);
    }

    kstr = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i]
      .f1->size[1];
    i = shifted_data->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &k_emlrtBCI, sp);
    }

    i = cell3->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &l_emlrtBCI, sp);
    }

    i = cell3->data[b_i].f1->size[0] * cell3->data[b_i].f1->size[1];
    cell3->data[b_i].f1->size[0] = shifted_data->data[b_i].f1->size[0];
    emxEnsureCapacity_real_T(sp, cell3->data[b_i].f1, i, &ie_emlrtRTEI);
    i = cell3->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &l_emlrtBCI, sp);
    }

    i = cell3->data[b_i].f1->size[0] * cell3->data[b_i].f1->size[1];
    cell3->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, cell3->data[b_i].f1, i, &ie_emlrtRTEI);
    i = cell3->size[0] - 1;
    i2 = cell3->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &l_emlrtBCI, sp);
    }

    i2 = cell3->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &l_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < kstr; i2++) {
      i3 = shifted_data->size[0] - 1;
      if (b_i > i3) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &k_emlrtBCI, sp);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &l_emlrtBCI, sp);
      }

      cell3->data[b_i].f1->data[i2] = shifted_data->data[b_i].f1->data[i2];
    }
  }

  emxFree_cell_wrap_9(&shifted_data);
  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 8, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 20U);
  i = result->f3->size[0];
  result->f3->size[0] = cell3->size[0];
  emxEnsureCapacity_cell_wrap_1(sp, result->f3, i, &fe_emlrtRTEI);
  kstr = cell3->size[0];
  for (i = 0; i < kstr; i++) {
    emxCopyStruct_cell_wrap_1(sp, &result->f3->data[i], &cell3->data[i],
      &fe_emlrtRTEI);
  }

  /*   */
  /*  cell4Length = 7; */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &j_emlrtRTEI, sp);
  i = cell3->size[0];
  cell3->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, cell3, i, &td_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 9, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 21U);
    i = layerSlds->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &m_emlrtBCI, sp);
    }

    i = layerSlds->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &m_emlrtBCI, sp);
    }

    kstr = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    i = layerSlds->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &m_emlrtBCI, sp);
    }

    i = cell3->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &n_emlrtBCI, sp);
    }

    i = cell3->data[b_i].f1->size[0] * cell3->data[b_i].f1->size[1];
    cell3->data[b_i].f1->size[0] = layerSlds->data[b_i].f1->size[0];
    emxEnsureCapacity_real_T(sp, cell3->data[b_i].f1, i, &ke_emlrtRTEI);
    i = cell3->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &n_emlrtBCI, sp);
    }

    i = cell3->data[b_i].f1->size[0] * cell3->data[b_i].f1->size[1];
    cell3->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, cell3->data[b_i].f1, i, &ke_emlrtRTEI);
    i = cell3->size[0] - 1;
    i2 = cell3->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &n_emlrtBCI, sp);
    }

    i2 = cell3->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &n_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < kstr; i2++) {
      i3 = layerSlds->size[0] - 1;
      if (b_i > i3) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &m_emlrtBCI, sp);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &n_emlrtBCI, sp);
      }

      cell3->data[b_i].f1->data[i2] = layerSlds->data[b_i].f1->data[i2];
    }
  }

  emxFree_cell_wrap_9(&layerSlds);
  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 9, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 22U);
  i = result->f4->size[0];
  result->f4->size[0] = cell3->size[0];
  emxEnsureCapacity_cell_wrap_1(sp, result->f4, i, &he_emlrtRTEI);
  kstr = cell3->size[0];
  for (i = 0; i < kstr; i++) {
    emxCopyStruct_cell_wrap_1(sp, &result->f4->data[i], &cell3->data[i],
      &he_emlrtRTEI);
  }

  emxFree_cell_wrap_1(&cell3);

  /*   */
  /*  cell5Length = 7; */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &k_emlrtRTEI, sp);
  i = cell1->size[0];
  cell1->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, cell1, i, &td_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 10, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 23U);
    i = sldProfiles->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &o_emlrtBCI, sp);
    }

    i = sldProfiles->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &o_emlrtBCI, sp);
    }

    kstr = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size
      [1];
    i = sldProfiles->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &o_emlrtBCI, sp);
    }

    i = cell1->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &p_emlrtBCI, sp);
    }

    i = cell1->data[b_i].f1->size[0] * cell1->data[b_i].f1->size[1];
    cell1->data[b_i].f1->size[0] = sldProfiles->data[b_i].f1->size[0];
    emxEnsureCapacity_real_T(sp, cell1->data[b_i].f1, i, &me_emlrtRTEI);
    i = cell1->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &p_emlrtBCI, sp);
    }

    i = cell1->data[b_i].f1->size[0] * cell1->data[b_i].f1->size[1];
    cell1->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, cell1->data[b_i].f1, i, &me_emlrtRTEI);
    i = cell1->size[0] - 1;
    i2 = cell1->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &p_emlrtBCI, sp);
    }

    i2 = cell1->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &p_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < kstr; i2++) {
      i3 = sldProfiles->size[0] - 1;
      if (b_i > i3) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &o_emlrtBCI, sp);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &p_emlrtBCI, sp);
      }

      cell1->data[b_i].f1->data[i2] = sldProfiles->data[b_i].f1->data[i2];
    }
  }

  emxFree_cell_wrap_8(&sldProfiles);
  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 10, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 24U);
  i = result->f5->size[0];
  result->f5->size[0] = cell1->size[0];
  emxEnsureCapacity_cell_wrap_6(sp, result->f5, i, &je_emlrtRTEI);
  kstr = cell1->size[0];
  for (i = 0; i < kstr; i++) {
    emxCopyStruct_cell_wrap_6(sp, &result->f5->data[i], &cell1->data[i],
      &je_emlrtRTEI);
  }

  emxFree_cell_wrap_6(&cell1);
  emxInit_int8_T(sp, &cell6, 1, &af_emlrtRTEI, true);

  /*   */
  /*  cell6Length = 7; */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &l_emlrtRTEI, sp);
  i = cell6->size[0];
  cell6->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_int8_T(sp, cell6, i, &td_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 11, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 25U);
    i = cell6->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &q_emlrtBCI, sp);
    }

    cell6->data[b_i] = 0;
  }

  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 11, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 26U);
  i = result->f6->size[0];
  result->f6->size[0] = cell6->size[0];
  emxEnsureCapacity_real_T(sp, result->f6, i, &le_emlrtRTEI);
  kstr = cell6->size[0];
  for (i = 0; i < kstr; i++) {
    result->f6->data[i] = cell6->data[i];
  }

  emxFree_int8_T(&cell6);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (reflectivity_calculation.c) */
