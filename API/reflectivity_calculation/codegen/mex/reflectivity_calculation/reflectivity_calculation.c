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
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"
#include "standardTF_stanLay_reflectivityCalculation.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 63,    /* lineNo */
  "reflectivity_calculation",          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 52,  /* lineNo */
  "standardTF_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pathName */
};

static emlrtDCInfo emlrtDCI = { 23,    /* lineNo */
  21,                                  /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 23,  /* lineNo */
  21,                                  /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = { 24,  /* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtDCInfo c_emlrtDCI = { 29,  /* lineNo */
  19,                                  /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = { 30,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 36,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 42,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 48,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 54,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 76,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 83,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 90,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 97,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 104,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 111,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtDCInfo d_emlrtDCI = { 6,   /* lineNo */
  18,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 20,  /* lineNo */
  21,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo m_emlrtRTEI = { 21,/* lineNo */
  9,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 26,/* lineNo */
  9,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 31,/* lineNo */
  9,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 36,/* lineNo */
  9,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 41,/* lineNo */
  9,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 46,/* lineNo */
  9,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  37,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  49,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  55,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  16,                                  /* colNo */
  "reflectivity",                      /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  5,                                   /* colNo */
  "cell1",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  16,                                  /* colNo */
  "Simulation",                        /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  5,                                   /* colNo */
  "cell2",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  91,                                  /* lineNo */
  16,                                  /* colNo */
  "shifted_data",                      /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  91,                                  /* lineNo */
  5,                                   /* colNo */
  "cell3",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  98,                                  /* lineNo */
  16,                                  /* colNo */
  "layerSlds",                         /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  98,                                  /* lineNo */
  5,                                   /* colNo */
  "cell4",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  16,                                  /* colNo */
  "sldProfiles",                       /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  5,                                   /* colNo */
  "cell5",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  112,                                 /* lineNo */
  5,                                   /* colNo */
  "cell6",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  27,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  32,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  37,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo cc_emlrtRTEI = { 10,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo dc_emlrtRTEI = { 11,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = { 12,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo fc_emlrtRTEI = { 13,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = { 14,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = { 15,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ic_emlrtRTEI = { 16,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = { 17,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo kc_emlrtRTEI = { 19,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo lc_emlrtRTEI = { 2,/* lineNo */
  29,                                  /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo mc_emlrtRTEI = { 25,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo nc_emlrtRTEI = { 31,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo oc_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo pc_emlrtRTEI = { 43,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo qc_emlrtRTEI = { 49,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo rc_emlrtRTEI = { 55,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = { 63,/* lineNo */
  136,                                 /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo tc_emlrtRTEI = { 79,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo uc_emlrtRTEI = { 86,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo vc_emlrtRTEI = { 77,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = { 93,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo xc_emlrtRTEI = { 84,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo yc_emlrtRTEI = { 100,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = { 91,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = { 107,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo cd_emlrtRTEI = { 98,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo dd_emlrtRTEI = { 114,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ed_emlrtRTEI = { 105,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo fd_emlrtRTEI = { 10,/* lineNo */
  26,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo gd_emlrtRTEI = { 11,/* lineNo */
  32,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo hd_emlrtRTEI = { 12,/* lineNo */
  28,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo id_emlrtRTEI = { 13,/* lineNo */
  33,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo jd_emlrtRTEI = { 14,/* lineNo */
  27,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo kd_emlrtRTEI = { 15,/* lineNo */
  27,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ld_emlrtRTEI = { 16,/* lineNo */
  32,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo md_emlrtRTEI = { 17,/* lineNo */
  51,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo nd_emlrtRTEI = { 18,/* lineNo */
  32,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo od_emlrtRTEI = { 63,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo pd_emlrtRTEI = { 22,/* lineNo */
  5,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo qd_emlrtRTEI = { 27,/* lineNo */
  5,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo rd_emlrtRTEI = { 32,/* lineNo */
  5,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo sd_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo td_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ud_emlrtRTEI = { 47,/* lineNo */
  5,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo vd_emlrtRTEI = { 63,/* lineNo */
  10,                                  /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo wd_emlrtRTEI = { 63,/* lineNo */
  18,                                  /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo xd_emlrtRTEI = { 63,/* lineNo */
  42,                                  /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo yd_emlrtRTEI = { 23,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ae_emlrtRTEI = { 29,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo be_emlrtRTEI = { 35,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ce_emlrtRTEI = { 41,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo de_emlrtRTEI = { 47,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ee_emlrtRTEI = { 53,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo fe_emlrtRTEI = { 75,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ge_emlrtRTEI = { 89,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo he_emlrtRTEI = { 110,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

/* Function Definitions */
void reflectivity_calculation(const emlrtStack *sp, const struct0_T *problemDef,
  const cell_5 *problemDef_cells, const struct1_T *problemDef_limits, const
  struct2_T *controls, struct4_T *problem, cell_7 *result)
{
  int32_T i;
  emxArray_cell_wrap_8 *reflectivity;
  int32_T loop_ub;
  int32_T i1;
  int32_T b_i;
  emxArray_cell_wrap_8 *Simulation;
  emxArray_cell_wrap_9 *shifted_data;
  int32_T i2;
  emxArray_cell_wrap_9 *layerSlds;
  emxArray_cell_wrap_8 *sldProfiles;
  emxArray_cell_wrap_10 *allLayers;
  boolean_T b_bool;
  int32_T kstr;
  emxArray_cell_wrap_6 *cell1;
  emxArray_cell_wrap_1 *cell3;
  int32_T exitg1;
  static const char_T cv[10] = { 's', 't', 'a', 'n', 'd', 'a', 'r', 'd', 'T',
    'F' };

  emxArray_cell_wrap_0 *t0_f1;
  emxArray_cell_wrap_1 *t0_f2;
  emxArray_cell_wrap_0 *t0_f3;
  emxArray_cell_wrap_0 *t0_f4;
  emxArray_cell_wrap_2 *t0_f5;
  emxArray_cell_wrap_2 *t0_f6;
  emxArray_cell_wrap_4 *t0_f7;
  emxArray_cell_wrap_4 *t0_f8;
  emxArray_cell_wrap_4 *t0_f9;
  emxArray_cell_wrap_4 *t0_f10;
  emxArray_int8_T *cell6;
  emxArray_cell_wrap_4 *t0_f11;
  emxArray_cell_wrap_4 *t0_f12;
  emxArray_cell_wrap_4 *t0_f13;
  emxArray_cell_wrap_6 *b_Simulation;
  emxArray_cell_wrap_1 *b_layerSlds;
  emxArray_cell_wrap_6 *b_sldProfiles;
  static const char_T cv1[6] = { 'l', 'a', 'y', 'e', 'r', 's' };

  cell_11 expl_temp;
  emlrtStack st;
  emlrtStack b_st;
  (void)problemDef_limits;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* Preallocatin of outputs */
  i = problem->ssubs->size[0];
  problem->ssubs->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->ssubs, i, &cc_emlrtRTEI);
  problem->ssubs->data[0] = 0.0;
  i = problem->backgrounds->size[0];
  problem->backgrounds->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->backgrounds, i, &dc_emlrtRTEI);
  problem->backgrounds->data[0] = 0.0;
  i = problem->qshifts->size[0];
  problem->qshifts->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->qshifts, i, &ec_emlrtRTEI);
  problem->qshifts->data[0] = 0.0;
  i = problem->scalefactors->size[0];
  problem->scalefactors->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->scalefactors, i, &fc_emlrtRTEI);
  problem->scalefactors->data[0] = 0.0;
  i = problem->nbairs->size[0];
  problem->nbairs->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->nbairs, i, &gc_emlrtRTEI);
  problem->nbairs->data[0] = 0.0;
  i = problem->nbsubs->size[0];
  problem->nbsubs->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->nbsubs, i, &hc_emlrtRTEI);
  problem->nbsubs->data[0] = 0.0;
  i = problem->resolutions->size[0];
  problem->resolutions->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->resolutions, i, &ic_emlrtRTEI);
  problem->resolutions->data[0] = 0.0;
  i = problem->calculations.all_chis->size[0];
  problem->calculations.all_chis->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->calculations.all_chis, i, &jc_emlrtRTEI);
  problem->calculations.all_chis->data[0] = 0.0;
  problem->calculations.sum_chi = 0.0;
  i = problem->allSubRough->size[0];
  problem->allSubRough->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->allSubRough, i, &kc_emlrtRTEI);
  problem->allSubRough->data[0] = 0.0;
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &emlrtDCI, sp);
  }

  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &b_emlrtDCI, sp);
  }

  emxInit_cell_wrap_8(sp, &reflectivity, 1, &yd_emlrtRTEI, true);
  loop_ub = (int32_T)problemDef->numberOfContrasts;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &emlrtRTEI, sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, reflectivity, i1, &lc_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &mc_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &mc_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &emlrtBCI, sp);
    }

    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &c_emlrtDCI, sp);
  }

  emxInit_cell_wrap_8(sp, &Simulation, 1, &ae_emlrtRTEI, true);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &b_emlrtRTEI, sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, Simulation, i1, &lc_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &b_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &nc_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &b_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &nc_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &b_emlrtBCI, sp);
    }

    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &b_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &b_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &b_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &b_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &b_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
  }

  emxInit_cell_wrap_9(sp, &shifted_data, 1, &be_emlrtRTEI, true);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &c_emlrtRTEI, sp);
  i1 = shifted_data->size[0];
  shifted_data->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_9(sp, shifted_data, i1, &lc_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &c_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i1, &oc_emlrtRTEI);
    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &c_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i1, &oc_emlrtRTEI);
    i1 = shifted_data->size[0] - 1;
    i2 = shifted_data->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &c_emlrtBCI, sp);
    }

    i2 = shifted_data->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &c_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < 6; i2++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &c_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[i2] = 1.0;
    }
  }

  emxInit_cell_wrap_9(sp, &layerSlds, 1, &ce_emlrtRTEI, true);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &d_emlrtRTEI, sp);
  i1 = layerSlds->size[0];
  layerSlds->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_9(sp, layerSlds, i1, &lc_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = layerSlds->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &d_emlrtBCI, sp);
    }

    i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &pc_emlrtRTEI);
    i1 = layerSlds->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &d_emlrtBCI, sp);
    }

    i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &pc_emlrtRTEI);
    i1 = layerSlds->size[0] - 1;
    i2 = layerSlds->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &d_emlrtBCI, sp);
    }

    i2 = layerSlds->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &d_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < 6; i2++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &d_emlrtBCI, sp);
      }

      layerSlds->data[b_i].f1->data[i2] = 1.0;
    }
  }

  emxInit_cell_wrap_8(sp, &sldProfiles, 1, &de_emlrtRTEI, true);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &e_emlrtRTEI, sp);
  i1 = sldProfiles->size[0];
  sldProfiles->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, sldProfiles, i1, &lc_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &e_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &qc_emlrtRTEI);
    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &e_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &qc_emlrtRTEI);
    i1 = sldProfiles->size[0] - 1;
    i2 = sldProfiles->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &e_emlrtBCI, sp);
    }

    i2 = sldProfiles->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &e_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &e_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &e_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &e_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &e_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[3] = 1.0;
  }

  emxInit_cell_wrap_10(sp, &allLayers, 1, &ee_emlrtRTEI, true);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &f_emlrtRTEI, sp);
  i1 = allLayers->size[0];
  allLayers->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_10(sp, allLayers, i1, &lc_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = allLayers->size[0] - 1;
    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &f_emlrtBCI, sp);
    }

    i2 = allLayers->data[b_i].f1->size[0];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i2, &rc_emlrtRTEI);
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &f_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &f_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
  }

  /* Decide which target function we are calling */
  b_bool = false;
  if (problemDef->TF->size[1] == 10) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 10) {
        if (problemDef->TF->data[kstr] != cv[kstr]) {
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

  emxInit_cell_wrap_6(sp, &cell1, 1, &fe_emlrtRTEI, true);
  emxInit_cell_wrap_1(sp, &cell3, 1, &ge_emlrtRTEI, true);
  if (b_bool) {
    kstr = 0;
  } else {
    kstr = -1;
  }

  switch (kstr) {
   case 0:
    emxInit_cell_wrap_0(sp, &t0_f1, 2, &sc_emlrtRTEI, true);
    i1 = t0_f1->size[0] * t0_f1->size[1];
    t0_f1->size[0] = 1;
    t0_f1->size[1] = problemDef_cells->f1->size[1];
    emxEnsureCapacity_cell_wrap_0(sp, t0_f1, i1, &sc_emlrtRTEI);
    kstr = problemDef_cells->f1->size[0] * problemDef_cells->f1->size[1];
    for (i1 = 0; i1 < kstr; i1++) {
      t0_f1->data[i1] = problemDef_cells->f1->data[i1];
    }

    emxInit_cell_wrap_1(sp, &t0_f2, 2, &sc_emlrtRTEI, true);
    i1 = t0_f2->size[0] * t0_f2->size[1];
    t0_f2->size[0] = 1;
    t0_f2->size[1] = problemDef_cells->f2->size[1];
    emxEnsureCapacity_cell_wrap_1(sp, t0_f2, i1, &sc_emlrtRTEI);
    kstr = problemDef_cells->f2->size[0] * problemDef_cells->f2->size[1];
    for (i1 = 0; i1 < kstr; i1++) {
      emxCopyStruct_cell_wrap_1(sp, &t0_f2->data[i1], &problemDef_cells->
        f2->data[i1], &sc_emlrtRTEI);
    }

    emxInit_cell_wrap_0(sp, &t0_f3, 2, &sc_emlrtRTEI, true);
    i1 = t0_f3->size[0] * t0_f3->size[1];
    t0_f3->size[0] = 1;
    t0_f3->size[1] = problemDef_cells->f3->size[1];
    emxEnsureCapacity_cell_wrap_0(sp, t0_f3, i1, &sc_emlrtRTEI);
    kstr = problemDef_cells->f3->size[0] * problemDef_cells->f3->size[1];
    for (i1 = 0; i1 < kstr; i1++) {
      t0_f3->data[i1] = problemDef_cells->f3->data[i1];
    }

    emxInit_cell_wrap_0(sp, &t0_f4, 2, &sc_emlrtRTEI, true);
    i1 = t0_f4->size[0] * t0_f4->size[1];
    t0_f4->size[0] = 1;
    t0_f4->size[1] = problemDef_cells->f4->size[1];
    emxEnsureCapacity_cell_wrap_0(sp, t0_f4, i1, &sc_emlrtRTEI);
    kstr = problemDef_cells->f4->size[0] * problemDef_cells->f4->size[1];
    for (i1 = 0; i1 < kstr; i1++) {
      t0_f4->data[i1] = problemDef_cells->f4->data[i1];
    }

    emxInit_cell_wrap_2(sp, &t0_f5, 2, &sc_emlrtRTEI, true);
    i1 = t0_f5->size[0] * t0_f5->size[1];
    t0_f5->size[0] = 1;
    t0_f5->size[1] = problemDef_cells->f5->size[1];
    emxEnsureCapacity_cell_wrap_2(sp, t0_f5, i1, &sc_emlrtRTEI);
    kstr = problemDef_cells->f5->size[0] * problemDef_cells->f5->size[1];
    for (i1 = 0; i1 < kstr; i1++) {
      emxCopyStruct_cell_wrap_2(sp, &t0_f5->data[i1], &problemDef_cells->
        f5->data[i1], &sc_emlrtRTEI);
    }

    emxInit_cell_wrap_2(sp, &t0_f6, 1, &sc_emlrtRTEI, true);
    i1 = t0_f6->size[0];
    t0_f6->size[0] = problemDef_cells->f6->size[0];
    emxEnsureCapacity_cell_wrap_2(sp, t0_f6, i1, &sc_emlrtRTEI);
    i1 = problemDef_cells->f6->size[0];
    for (i2 = 0; i2 < i1; i2++) {
      b_i = t0_f6->data[i2].f1->size[0] * t0_f6->data[i2].f1->size[1];
      t0_f6->data[i2].f1->size[0] = 1;
      t0_f6->data[i2].f1->size[1] = problemDef_cells->f6->data[i2].f1.size[1];
      emxEnsureCapacity_real_T(sp, t0_f6->data[i2].f1, b_i, &sc_emlrtRTEI);
      kstr = problemDef_cells->f6->data[i2].f1.size[0] * problemDef_cells->
        f6->data[i2].f1.size[1];
      for (b_i = 0; b_i < kstr; b_i++) {
        t0_f6->data[i2].f1->data[b_i] = problemDef_cells->f6->data[i2]
          .f1.data[b_i];
      }
    }

    emxInit_cell_wrap_4(sp, &t0_f7, 2, &sc_emlrtRTEI, true);
    i1 = t0_f7->size[0] * t0_f7->size[1];
    t0_f7->size[0] = 1;
    t0_f7->size[1] = problemDef_cells->f7->size[1];
    emxEnsureCapacity_cell_wrap_4(sp, t0_f7, i1, &sc_emlrtRTEI);
    kstr = problemDef_cells->f7->size[0] * problemDef_cells->f7->size[1];
    for (i1 = 0; i1 < kstr; i1++) {
      emxCopyStruct_cell_wrap_4(sp, &t0_f7->data[i1], &problemDef_cells->
        f7->data[i1], &sc_emlrtRTEI);
    }

    emxInit_cell_wrap_4(sp, &t0_f8, 2, &sc_emlrtRTEI, true);
    i1 = t0_f8->size[0] * t0_f8->size[1];
    t0_f8->size[0] = 1;
    t0_f8->size[1] = problemDef_cells->f8->size[1];
    emxEnsureCapacity_cell_wrap_4(sp, t0_f8, i1, &sc_emlrtRTEI);
    kstr = problemDef_cells->f8->size[0] * problemDef_cells->f8->size[1];
    for (i1 = 0; i1 < kstr; i1++) {
      emxCopyStruct_cell_wrap_4(sp, &t0_f8->data[i1], &problemDef_cells->
        f8->data[i1], &sc_emlrtRTEI);
    }

    emxInit_cell_wrap_4(sp, &t0_f9, 2, &sc_emlrtRTEI, true);
    i1 = t0_f9->size[0] * t0_f9->size[1];
    t0_f9->size[0] = 1;
    t0_f9->size[1] = problemDef_cells->f9->size[1];
    emxEnsureCapacity_cell_wrap_4(sp, t0_f9, i1, &sc_emlrtRTEI);
    kstr = problemDef_cells->f9->size[0] * problemDef_cells->f9->size[1];
    for (i1 = 0; i1 < kstr; i1++) {
      emxCopyStruct_cell_wrap_4(sp, &t0_f9->data[i1], &problemDef_cells->
        f9->data[i1], &sc_emlrtRTEI);
    }

    emxInit_cell_wrap_4(sp, &t0_f10, 2, &sc_emlrtRTEI, true);
    i1 = t0_f10->size[0] * t0_f10->size[1];
    t0_f10->size[0] = 1;
    t0_f10->size[1] = problemDef_cells->f10->size[1];
    emxEnsureCapacity_cell_wrap_4(sp, t0_f10, i1, &sc_emlrtRTEI);
    kstr = problemDef_cells->f10->size[0] * problemDef_cells->f10->size[1];
    for (i1 = 0; i1 < kstr; i1++) {
      emxCopyStruct_cell_wrap_4(sp, &t0_f10->data[i1], &problemDef_cells->
        f10->data[i1], &sc_emlrtRTEI);
    }

    emxInit_cell_wrap_4(sp, &t0_f11, 2, &sc_emlrtRTEI, true);
    i1 = t0_f11->size[0] * t0_f11->size[1];
    t0_f11->size[0] = 1;
    t0_f11->size[1] = problemDef_cells->f11->size[1];
    emxEnsureCapacity_cell_wrap_4(sp, t0_f11, i1, &sc_emlrtRTEI);
    kstr = problemDef_cells->f11->size[0] * problemDef_cells->f11->size[1];
    for (i1 = 0; i1 < kstr; i1++) {
      emxCopyStruct_cell_wrap_4(sp, &t0_f11->data[i1], &problemDef_cells->
        f11->data[i1], &sc_emlrtRTEI);
    }

    emxInit_cell_wrap_4(sp, &t0_f12, 2, &sc_emlrtRTEI, true);
    i1 = t0_f12->size[0] * t0_f12->size[1];
    t0_f12->size[0] = 1;
    t0_f12->size[1] = problemDef_cells->f12->size[1];
    emxEnsureCapacity_cell_wrap_4(sp, t0_f12, i1, &sc_emlrtRTEI);
    kstr = problemDef_cells->f12->size[0] * problemDef_cells->f12->size[1];
    for (i1 = 0; i1 < kstr; i1++) {
      emxCopyStruct_cell_wrap_4(sp, &t0_f12->data[i1], &problemDef_cells->
        f12->data[i1], &sc_emlrtRTEI);
    }

    emxInit_cell_wrap_4(sp, &t0_f13, 2, &sc_emlrtRTEI, true);
    i1 = t0_f13->size[0] * t0_f13->size[1];
    t0_f13->size[0] = 1;
    t0_f13->size[1] = problemDef_cells->f13->size[1];
    emxEnsureCapacity_cell_wrap_4(sp, t0_f13, i1, &sc_emlrtRTEI);
    kstr = problemDef_cells->f13->size[0] * problemDef_cells->f13->size[1];
    for (i1 = 0; i1 < kstr; i1++) {
      emxCopyStruct_cell_wrap_4(sp, &t0_f13->data[i1], &problemDef_cells->
        f13->data[i1], &sc_emlrtRTEI);
    }

    st.site = &emlrtRSI;

    /* Decide what kind of calculation it is and call the appropriate one */
    if ((int32_T)problemDef->numberOfContrasts != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &d_emlrtDCI, &st);
    }

    /*  Pre-allocate the output arrays.. */
    i1 = problem->ssubs->size[0];
    problem->ssubs->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, problem->ssubs, i1, &fd_emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      problem->ssubs->data[i1] = 0.0;
    }

    i1 = problem->backgrounds->size[0];
    problem->backgrounds->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, problem->backgrounds, i1, &gd_emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      problem->backgrounds->data[i1] = 0.0;
    }

    i1 = problem->qshifts->size[0];
    problem->qshifts->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, problem->qshifts, i1, &hd_emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      problem->qshifts->data[i1] = 0.0;
    }

    i1 = problem->scalefactors->size[0];
    problem->scalefactors->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, problem->scalefactors, i1, &id_emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      problem->scalefactors->data[i1] = 0.0;
    }

    i1 = problem->nbairs->size[0];
    problem->nbairs->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, problem->nbairs, i1, &jd_emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      problem->nbairs->data[i1] = 0.0;
    }

    i1 = problem->nbsubs->size[0];
    problem->nbsubs->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, problem->nbsubs, i1, &kd_emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      problem->nbsubs->data[i1] = 0.0;
    }

    i1 = problem->resolutions->size[0];
    problem->resolutions->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, problem->resolutions, i1, &ld_emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      problem->resolutions->data[i1] = 0.0;
    }

    i1 = problem->calculations.all_chis->size[0];
    problem->calculations.all_chis->size[0] = (int32_T)
      problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, problem->calculations.all_chis, i1,
      &md_emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      problem->calculations.all_chis->data[i1] = 0.0;
    }

    problem->calculations.sum_chi = 0.0;
    i1 = problem->allSubRough->size[0];
    problem->allSubRough->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, problem->allSubRough, i1, &nd_emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      problem->allSubRough->data[i1] = 0.0;
    }

    if ((int32_T)problemDef->numberOfContrasts != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &e_emlrtDCI, &st);
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &m_emlrtRTEI, &st);
    i = cell1->size[0];
    cell1->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_6(&st, cell1, i, &od_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = cell1->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &r_emlrtBCI, &st);
      }

      i = cell1->data[b_i].f1->size[0] * cell1->data[b_i].f1->size[1];
      cell1->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, cell1->data[b_i].f1, i, &pd_emlrtRTEI);
      i = cell1->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &r_emlrtBCI, &st);
      }

      i = cell1->data[b_i].f1->size[0] * cell1->data[b_i].f1->size[1];
      cell1->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, cell1->data[b_i].f1, i, &pd_emlrtRTEI);
      i = cell1->size[0] - 1;
      i1 = cell1->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &r_emlrtBCI, &st);
      }

      i1 = cell1->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &r_emlrtBCI, &st);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &r_emlrtBCI, &st);
      }

      cell1->data[b_i].f1->data[0] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &r_emlrtBCI, &st);
      }

      cell1->data[b_i].f1->data[1] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &r_emlrtBCI, &st);
      }

      cell1->data[b_i].f1->data[2] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &r_emlrtBCI, &st);
      }

      cell1->data[b_i].f1->data[3] = 1.0;
    }

    emxInit_cell_wrap_6(&st, &b_Simulation, 1, &lc_emlrtRTEI, true);
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &n_emlrtRTEI, &st);
    i = b_Simulation->size[0];
    b_Simulation->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_6(&st, b_Simulation, i, &od_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = b_Simulation->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &s_emlrtBCI, &st);
      }

      i = b_Simulation->data[b_i].f1->size[0] * b_Simulation->data[b_i].f1->
        size[1];
      b_Simulation->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, b_Simulation->data[b_i].f1, i, &qd_emlrtRTEI);
      i = b_Simulation->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &s_emlrtBCI, &st);
      }

      i = b_Simulation->data[b_i].f1->size[0] * b_Simulation->data[b_i].f1->
        size[1];
      b_Simulation->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, b_Simulation->data[b_i].f1, i, &qd_emlrtRTEI);
      i = b_Simulation->size[0] - 1;
      i1 = b_Simulation->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &s_emlrtBCI, &st);
      }

      i1 = b_Simulation->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &s_emlrtBCI, &st);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &s_emlrtBCI, &st);
      }

      b_Simulation->data[b_i].f1->data[0] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &s_emlrtBCI, &st);
      }

      b_Simulation->data[b_i].f1->data[1] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &s_emlrtBCI, &st);
      }

      b_Simulation->data[b_i].f1->data[2] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &s_emlrtBCI, &st);
      }

      b_Simulation->data[b_i].f1->data[3] = 1.0;
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &o_emlrtRTEI, &st);
    i = cell3->size[0];
    cell3->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_1(&st, cell3, i, &od_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = cell3->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &t_emlrtBCI, &st);
      }

      i = cell3->data[b_i].f1->size[0] * cell3->data[b_i].f1->size[1];
      cell3->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, cell3->data[b_i].f1, i, &rd_emlrtRTEI);
      i = cell3->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &t_emlrtBCI, &st);
      }

      i = cell3->data[b_i].f1->size[0] * cell3->data[b_i].f1->size[1];
      cell3->data[b_i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(&st, cell3->data[b_i].f1, i, &rd_emlrtRTEI);
      i = cell3->size[0] - 1;
      i1 = cell3->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &t_emlrtBCI, &st);
      }

      i1 = cell3->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &t_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < 6; i1++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &t_emlrtBCI, &st);
        }

        cell3->data[b_i].f1->data[i1] = 1.0;
      }
    }

    emxInit_cell_wrap_1(&st, &b_layerSlds, 1, &lc_emlrtRTEI, true);
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &p_emlrtRTEI, &st);
    i = b_layerSlds->size[0];
    b_layerSlds->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_1(&st, b_layerSlds, i, &od_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = b_layerSlds->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &u_emlrtBCI, &st);
      }

      i = b_layerSlds->data[b_i].f1->size[0] * b_layerSlds->data[b_i].f1->size[1];
      b_layerSlds->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, b_layerSlds->data[b_i].f1, i, &sd_emlrtRTEI);
      i = b_layerSlds->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &u_emlrtBCI, &st);
      }

      i = b_layerSlds->data[b_i].f1->size[0] * b_layerSlds->data[b_i].f1->size[1];
      b_layerSlds->data[b_i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(&st, b_layerSlds->data[b_i].f1, i, &sd_emlrtRTEI);
      i = b_layerSlds->size[0] - 1;
      i1 = b_layerSlds->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &u_emlrtBCI, &st);
      }

      i1 = b_layerSlds->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &u_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < 6; i1++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &u_emlrtBCI, &st);
        }

        b_layerSlds->data[b_i].f1->data[i1] = 1.0;
      }
    }

    emxInit_cell_wrap_6(&st, &b_sldProfiles, 1, &lc_emlrtRTEI, true);
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &q_emlrtRTEI, &st);
    i = b_sldProfiles->size[0];
    b_sldProfiles->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_6(&st, b_sldProfiles, i, &od_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = b_sldProfiles->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &v_emlrtBCI, &st);
      }

      i = b_sldProfiles->data[b_i].f1->size[0] * b_sldProfiles->data[b_i]
        .f1->size[1];
      b_sldProfiles->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, b_sldProfiles->data[b_i].f1, i,
        &td_emlrtRTEI);
      i = b_sldProfiles->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &v_emlrtBCI, &st);
      }

      i = b_sldProfiles->data[b_i].f1->size[0] * b_sldProfiles->data[b_i]
        .f1->size[1];
      b_sldProfiles->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, b_sldProfiles->data[b_i].f1, i,
        &td_emlrtRTEI);
      i = b_sldProfiles->size[0] - 1;
      i1 = b_sldProfiles->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &v_emlrtBCI, &st);
      }

      i1 = b_sldProfiles->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &v_emlrtBCI, &st);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &v_emlrtBCI, &st);
      }

      b_sldProfiles->data[b_i].f1->data[0] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &v_emlrtBCI, &st);
      }

      b_sldProfiles->data[b_i].f1->data[1] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &v_emlrtBCI, &st);
      }

      b_sldProfiles->data[b_i].f1->data[2] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &v_emlrtBCI, &st);
      }

      b_sldProfiles->data[b_i].f1->data[3] = 1.0;
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &r_emlrtRTEI, &st);
    i = allLayers->size[0];
    allLayers->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_10(&st, allLayers, i, &od_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = allLayers->size[0] - 1;
      i1 = allLayers->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &w_emlrtBCI, &st);
      }

      i1 = allLayers->data[b_i].f1->size[0];
      allLayers->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i1, &ud_emlrtRTEI);
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &w_emlrtBCI, &st);
      }

      allLayers->data[b_i].f1->data[0] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &w_emlrtBCI, &st);
      }

      allLayers->data[b_i].f1->data[1] = 1.0;
    }

    b_bool = false;
    if (problemDef->modelType->size[1] == 6) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 6) {
          if (problemDef->modelType->data[kstr] != cv1[kstr]) {
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

    switch (kstr) {
     case 0:
      emxInitStruct_cell_11(&st, &expl_temp, &vd_emlrtRTEI, true);
      i = expl_temp.f13->size[0] * expl_temp.f13->size[1];
      expl_temp.f13->size[0] = 1;
      expl_temp.f13->size[1] = t0_f13->size[1];
      emxEnsureCapacity_cell_wrap_4(&st, expl_temp.f13, i, &vd_emlrtRTEI);
      kstr = t0_f13->size[0] * t0_f13->size[1];
      for (i = 0; i < kstr; i++) {
        emxCopyStruct_cell_wrap_4(&st, &expl_temp.f13->data[i], &t0_f13->data[i],
          &vd_emlrtRTEI);
      }

      i = expl_temp.f12->size[0] * expl_temp.f12->size[1];
      expl_temp.f12->size[0] = 1;
      expl_temp.f12->size[1] = t0_f12->size[1];
      emxEnsureCapacity_cell_wrap_4(&st, expl_temp.f12, i, &vd_emlrtRTEI);
      kstr = t0_f12->size[0] * t0_f12->size[1];
      for (i = 0; i < kstr; i++) {
        emxCopyStruct_cell_wrap_4(&st, &expl_temp.f12->data[i], &t0_f12->data[i],
          &vd_emlrtRTEI);
      }

      i = expl_temp.f11->size[0] * expl_temp.f11->size[1];
      expl_temp.f11->size[0] = 1;
      expl_temp.f11->size[1] = t0_f11->size[1];
      emxEnsureCapacity_cell_wrap_4(&st, expl_temp.f11, i, &vd_emlrtRTEI);
      kstr = t0_f11->size[0] * t0_f11->size[1];
      for (i = 0; i < kstr; i++) {
        emxCopyStruct_cell_wrap_4(&st, &expl_temp.f11->data[i], &t0_f11->data[i],
          &vd_emlrtRTEI);
      }

      i = expl_temp.f10->size[0] * expl_temp.f10->size[1];
      expl_temp.f10->size[0] = 1;
      expl_temp.f10->size[1] = t0_f10->size[1];
      emxEnsureCapacity_cell_wrap_4(&st, expl_temp.f10, i, &vd_emlrtRTEI);
      kstr = t0_f10->size[0] * t0_f10->size[1];
      for (i = 0; i < kstr; i++) {
        emxCopyStruct_cell_wrap_4(&st, &expl_temp.f10->data[i], &t0_f10->data[i],
          &vd_emlrtRTEI);
      }

      i = expl_temp.f9->size[0] * expl_temp.f9->size[1];
      expl_temp.f9->size[0] = 1;
      expl_temp.f9->size[1] = t0_f9->size[1];
      emxEnsureCapacity_cell_wrap_4(&st, expl_temp.f9, i, &vd_emlrtRTEI);
      kstr = t0_f9->size[0] * t0_f9->size[1];
      for (i = 0; i < kstr; i++) {
        emxCopyStruct_cell_wrap_4(&st, &expl_temp.f9->data[i], &t0_f9->data[i],
          &vd_emlrtRTEI);
      }

      i = expl_temp.f8->size[0] * expl_temp.f8->size[1];
      expl_temp.f8->size[0] = 1;
      expl_temp.f8->size[1] = t0_f8->size[1];
      emxEnsureCapacity_cell_wrap_4(&st, expl_temp.f8, i, &vd_emlrtRTEI);
      kstr = t0_f8->size[0] * t0_f8->size[1];
      for (i = 0; i < kstr; i++) {
        emxCopyStruct_cell_wrap_4(&st, &expl_temp.f8->data[i], &t0_f8->data[i],
          &vd_emlrtRTEI);
      }

      i = expl_temp.f7->size[0] * expl_temp.f7->size[1];
      expl_temp.f7->size[0] = 1;
      expl_temp.f7->size[1] = t0_f7->size[1];
      emxEnsureCapacity_cell_wrap_4(&st, expl_temp.f7, i, &vd_emlrtRTEI);
      kstr = t0_f7->size[0] * t0_f7->size[1];
      for (i = 0; i < kstr; i++) {
        emxCopyStruct_cell_wrap_4(&st, &expl_temp.f7->data[i], &t0_f7->data[i],
          &vd_emlrtRTEI);
      }

      i = expl_temp.f6->size[0];
      expl_temp.f6->size[0] = t0_f6->size[0];
      emxEnsureCapacity_cell_wrap_2(&st, expl_temp.f6, i, &vd_emlrtRTEI);
      kstr = t0_f6->size[0];
      for (i = 0; i < kstr; i++) {
        emxCopyStruct_cell_wrap_2(&st, &expl_temp.f6->data[i], &t0_f6->data[i],
          &vd_emlrtRTEI);
      }

      i = expl_temp.f5->size[0] * expl_temp.f5->size[1];
      expl_temp.f5->size[0] = 1;
      expl_temp.f5->size[1] = t0_f5->size[1];
      emxEnsureCapacity_cell_wrap_2(&st, expl_temp.f5, i, &vd_emlrtRTEI);
      kstr = t0_f5->size[0] * t0_f5->size[1];
      for (i = 0; i < kstr; i++) {
        emxCopyStruct_cell_wrap_2(&st, &expl_temp.f5->data[i], &t0_f5->data[i],
          &vd_emlrtRTEI);
      }

      i = expl_temp.f4->size[0] * expl_temp.f4->size[1];
      expl_temp.f4->size[0] = 1;
      expl_temp.f4->size[1] = t0_f4->size[1];
      emxEnsureCapacity_cell_wrap_0(&st, expl_temp.f4, i, &vd_emlrtRTEI);
      kstr = t0_f4->size[0] * t0_f4->size[1];
      for (i = 0; i < kstr; i++) {
        expl_temp.f4->data[i] = t0_f4->data[i];
      }

      i = expl_temp.f3->size[0] * expl_temp.f3->size[1];
      expl_temp.f3->size[0] = 1;
      expl_temp.f3->size[1] = t0_f3->size[1];
      emxEnsureCapacity_cell_wrap_0(&st, expl_temp.f3, i, &vd_emlrtRTEI);
      kstr = t0_f3->size[0] * t0_f3->size[1];
      for (i = 0; i < kstr; i++) {
        expl_temp.f3->data[i] = t0_f3->data[i];
      }

      i = expl_temp.f2->size[0] * expl_temp.f2->size[1];
      expl_temp.f2->size[0] = 1;
      expl_temp.f2->size[1] = t0_f2->size[1];
      emxEnsureCapacity_cell_wrap_1(&st, expl_temp.f2, i, &vd_emlrtRTEI);
      kstr = t0_f2->size[0] * t0_f2->size[1];
      for (i = 0; i < kstr; i++) {
        emxCopyStruct_cell_wrap_1(&st, &expl_temp.f2->data[i], &t0_f2->data[i],
          &vd_emlrtRTEI);
      }

      i = expl_temp.f1->size[0] * expl_temp.f1->size[1];
      expl_temp.f1->size[0] = 1;
      expl_temp.f1->size[1] = t0_f1->size[1];
      emxEnsureCapacity_cell_wrap_0(&st, expl_temp.f1, i, &vd_emlrtRTEI);
      kstr = t0_f1->size[0] * t0_f1->size[1];
      for (i = 0; i < kstr; i++) {
        expl_temp.f1->data[i] = t0_f1->data[i];
      }

      b_st.site = &b_emlrtRSI;
      c_standardTF_stanLay_reflectivi(&b_st, problemDef, &expl_temp, controls,
        problem, cell1, b_Simulation, cell3, b_layerSlds, b_sldProfiles,
        allLayers);

      /* case 'custom layers' */
      /*     [problem,reflectivity,Simulation,shifted_data,layerSlds,sldProfiles,allLayers] = standardTF_custLay_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls); */
      /* case 'custXY' */
      /* problem = standardTF_custXY_reflectivityCalculation(problemDef,problemDef_cells,controls); */
      emxFreeStruct_cell_11(&expl_temp);
      break;
    }

    emxFree_cell_wrap_4(&t0_f13);
    emxFree_cell_wrap_4(&t0_f12);
    emxFree_cell_wrap_4(&t0_f11);
    emxFree_cell_wrap_4(&t0_f10);
    emxFree_cell_wrap_4(&t0_f9);
    emxFree_cell_wrap_4(&t0_f8);
    emxFree_cell_wrap_4(&t0_f7);
    emxFree_cell_wrap_2(&t0_f6);
    emxFree_cell_wrap_2(&t0_f5);
    emxFree_cell_wrap_0(&t0_f4);
    emxFree_cell_wrap_0(&t0_f3);
    emxFree_cell_wrap_1(&t0_f2);
    emxFree_cell_wrap_0(&t0_f1);
    i = reflectivity->size[0];
    reflectivity->size[0] = cell1->size[0];
    emxEnsureCapacity_cell_wrap_8(sp, reflectivity, i, &wd_emlrtRTEI);
    i = cell1->size[0];
    for (i1 = 0; i1 < i; i1++) {
      i2 = reflectivity->data[i1].f1->size[0] * reflectivity->data[i1].f1->size
        [1];
      reflectivity->data[i1].f1->size[0] = cell1->data[i1].f1->size[0];
      reflectivity->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, reflectivity->data[i1].f1, i2, &wd_emlrtRTEI);
      kstr = cell1->data[i1].f1->size[0] * cell1->data[i1].f1->size[1];
      for (i2 = 0; i2 < kstr; i2++) {
        reflectivity->data[i1].f1->data[i2] = cell1->data[i1].f1->data[i2];
      }
    }

    i = Simulation->size[0];
    Simulation->size[0] = b_Simulation->size[0];
    emxEnsureCapacity_cell_wrap_8(sp, Simulation, i, &wd_emlrtRTEI);
    i = b_Simulation->size[0];
    for (i1 = 0; i1 < i; i1++) {
      i2 = Simulation->data[i1].f1->size[0] * Simulation->data[i1].f1->size[1];
      Simulation->data[i1].f1->size[0] = b_Simulation->data[i1].f1->size[0];
      Simulation->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, Simulation->data[i1].f1, i2, &wd_emlrtRTEI);
      kstr = b_Simulation->data[i1].f1->size[0] * b_Simulation->data[i1]
        .f1->size[1];
      for (i2 = 0; i2 < kstr; i2++) {
        Simulation->data[i1].f1->data[i2] = b_Simulation->data[i1].f1->data[i2];
      }
    }

    emxFree_cell_wrap_6(&b_Simulation);
    i = shifted_data->size[0];
    shifted_data->size[0] = cell3->size[0];
    emxEnsureCapacity_cell_wrap_9(sp, shifted_data, i, &xd_emlrtRTEI);
    i = cell3->size[0];
    for (i1 = 0; i1 < i; i1++) {
      i2 = shifted_data->data[i1].f1->size[0] * shifted_data->data[i1].f1->size
        [1];
      shifted_data->data[i1].f1->size[0] = cell3->data[i1].f1->size[0];
      shifted_data->data[i1].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, shifted_data->data[i1].f1, i2, &xd_emlrtRTEI);
      kstr = cell3->data[i1].f1->size[0] * cell3->data[i1].f1->size[1];
      for (i2 = 0; i2 < kstr; i2++) {
        shifted_data->data[i1].f1->data[i2] = cell3->data[i1].f1->data[i2];
      }
    }

    i = layerSlds->size[0];
    layerSlds->size[0] = b_layerSlds->size[0];
    emxEnsureCapacity_cell_wrap_9(sp, layerSlds, i, &xd_emlrtRTEI);
    i = b_layerSlds->size[0];
    for (i1 = 0; i1 < i; i1++) {
      i2 = layerSlds->data[i1].f1->size[0] * layerSlds->data[i1].f1->size[1];
      layerSlds->data[i1].f1->size[0] = b_layerSlds->data[i1].f1->size[0];
      layerSlds->data[i1].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, layerSlds->data[i1].f1, i2, &xd_emlrtRTEI);
      kstr = b_layerSlds->data[i1].f1->size[0] * b_layerSlds->data[i1].f1->size
        [1];
      for (i2 = 0; i2 < kstr; i2++) {
        layerSlds->data[i1].f1->data[i2] = b_layerSlds->data[i1].f1->data[i2];
      }
    }

    emxFree_cell_wrap_1(&b_layerSlds);
    i = sldProfiles->size[0];
    sldProfiles->size[0] = b_sldProfiles->size[0];
    emxEnsureCapacity_cell_wrap_8(sp, sldProfiles, i, &wd_emlrtRTEI);
    i = b_sldProfiles->size[0];
    for (i1 = 0; i1 < i; i1++) {
      i2 = sldProfiles->data[i1].f1->size[0] * sldProfiles->data[i1].f1->size[1];
      sldProfiles->data[i1].f1->size[0] = b_sldProfiles->data[i1].f1->size[0];
      sldProfiles->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, sldProfiles->data[i1].f1, i2, &wd_emlrtRTEI);
      kstr = b_sldProfiles->data[i1].f1->size[0] * b_sldProfiles->data[i1]
        .f1->size[1];
      for (i2 = 0; i2 < kstr; i2++) {
        sldProfiles->data[i1].f1->data[i2] = b_sldProfiles->data[i1].f1->data[i2];
      }
    }

    emxFree_cell_wrap_6(&b_sldProfiles);

    /* case 'oilWaterTF' */
    /* problem = oilWaterTF_reflectivityCalculation(problemDef,problemDef_cells,controls);     */
    /* case 'polarisedTF' */
    /* problem = polarisedTF_reflectivityCalculation(problemDef,problemDef_cells,controls); */
    /* case 'domainsTF' */
    /* problem = domainsTF_reflectivityCalculation(problemDef,problemDef_cells,controls); */
    break;
  }

  emxFree_cell_wrap_10(&allLayers);

  /* cell1Length = numberOfContrasts; */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &g_emlrtRTEI, sp);
  i = cell1->size[0];
  cell1->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, cell1, i, &lc_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
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
    emxEnsureCapacity_real_T(sp, cell1->data[b_i].f1, i, &vc_emlrtRTEI);
    i = cell1->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &h_emlrtBCI, sp);
    }

    i = cell1->data[b_i].f1->size[0] * cell1->data[b_i].f1->size[1];
    cell1->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, cell1->data[b_i].f1, i, &vc_emlrtRTEI);
    i = cell1->size[0] - 1;
    i1 = cell1->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &h_emlrtBCI, sp);
    }

    i1 = cell1->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &h_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < kstr; i1++) {
      i2 = reflectivity->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &g_emlrtBCI, sp);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &h_emlrtBCI, sp);
      }

      cell1->data[b_i].f1->data[i1] = reflectivity->data[b_i].f1->data[i1];
    }
  }

  emxFree_cell_wrap_8(&reflectivity);
  i = result->f1->size[0];
  result->f1->size[0] = cell1->size[0];
  emxEnsureCapacity_cell_wrap_6(sp, result->f1, i, &tc_emlrtRTEI);
  kstr = cell1->size[0];
  for (i = 0; i < kstr; i++) {
    emxCopyStruct_cell_wrap_6(sp, &result->f1->data[i], &cell1->data[i],
      &tc_emlrtRTEI);
  }

  /*  cell2Length = 7; */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &h_emlrtRTEI, sp);
  i = cell1->size[0];
  cell1->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, cell1, i, &lc_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
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
    emxEnsureCapacity_real_T(sp, cell1->data[b_i].f1, i, &xc_emlrtRTEI);
    i = cell1->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &j_emlrtBCI, sp);
    }

    i = cell1->data[b_i].f1->size[0] * cell1->data[b_i].f1->size[1];
    cell1->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, cell1->data[b_i].f1, i, &xc_emlrtRTEI);
    i = cell1->size[0] - 1;
    i1 = cell1->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &j_emlrtBCI, sp);
    }

    i1 = cell1->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &j_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < kstr; i1++) {
      i2 = Simulation->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &i_emlrtBCI, sp);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &j_emlrtBCI, sp);
      }

      cell1->data[b_i].f1->data[i1] = Simulation->data[b_i].f1->data[i1];
    }
  }

  emxFree_cell_wrap_8(&Simulation);
  i = result->f2->size[0];
  result->f2->size[0] = cell1->size[0];
  emxEnsureCapacity_cell_wrap_6(sp, result->f2, i, &uc_emlrtRTEI);
  kstr = cell1->size[0];
  for (i = 0; i < kstr; i++) {
    emxCopyStruct_cell_wrap_6(sp, &result->f2->data[i], &cell1->data[i],
      &uc_emlrtRTEI);
  }

  /*   */
  /*  cell3Length = 7; */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &i_emlrtRTEI, sp);
  i = cell3->size[0];
  cell3->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, cell3, i, &lc_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
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
    emxEnsureCapacity_real_T(sp, cell3->data[b_i].f1, i, &ad_emlrtRTEI);
    i = cell3->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &l_emlrtBCI, sp);
    }

    i = cell3->data[b_i].f1->size[0] * cell3->data[b_i].f1->size[1];
    cell3->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, cell3->data[b_i].f1, i, &ad_emlrtRTEI);
    i = cell3->size[0] - 1;
    i1 = cell3->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &l_emlrtBCI, sp);
    }

    i1 = cell3->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &l_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < kstr; i1++) {
      i2 = shifted_data->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &k_emlrtBCI, sp);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &l_emlrtBCI, sp);
      }

      cell3->data[b_i].f1->data[i1] = shifted_data->data[b_i].f1->data[i1];
    }
  }

  emxFree_cell_wrap_9(&shifted_data);
  i = result->f3->size[0];
  result->f3->size[0] = cell3->size[0];
  emxEnsureCapacity_cell_wrap_1(sp, result->f3, i, &wc_emlrtRTEI);
  kstr = cell3->size[0];
  for (i = 0; i < kstr; i++) {
    emxCopyStruct_cell_wrap_1(sp, &result->f3->data[i], &cell3->data[i],
      &wc_emlrtRTEI);
  }

  /*   */
  /*  cell4Length = 7; */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &j_emlrtRTEI, sp);
  i = cell3->size[0];
  cell3->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, cell3, i, &lc_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
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
    emxEnsureCapacity_real_T(sp, cell3->data[b_i].f1, i, &cd_emlrtRTEI);
    i = cell3->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &n_emlrtBCI, sp);
    }

    i = cell3->data[b_i].f1->size[0] * cell3->data[b_i].f1->size[1];
    cell3->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, cell3->data[b_i].f1, i, &cd_emlrtRTEI);
    i = cell3->size[0] - 1;
    i1 = cell3->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &n_emlrtBCI, sp);
    }

    i1 = cell3->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &n_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < kstr; i1++) {
      i2 = layerSlds->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &m_emlrtBCI, sp);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &n_emlrtBCI, sp);
      }

      cell3->data[b_i].f1->data[i1] = layerSlds->data[b_i].f1->data[i1];
    }
  }

  emxFree_cell_wrap_9(&layerSlds);
  i = result->f4->size[0];
  result->f4->size[0] = cell3->size[0];
  emxEnsureCapacity_cell_wrap_1(sp, result->f4, i, &yc_emlrtRTEI);
  kstr = cell3->size[0];
  for (i = 0; i < kstr; i++) {
    emxCopyStruct_cell_wrap_1(sp, &result->f4->data[i], &cell3->data[i],
      &yc_emlrtRTEI);
  }

  emxFree_cell_wrap_1(&cell3);

  /*   */
  /*  cell5Length = 7; */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &k_emlrtRTEI, sp);
  i = cell1->size[0];
  cell1->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, cell1, i, &lc_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
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
    emxEnsureCapacity_real_T(sp, cell1->data[b_i].f1, i, &ed_emlrtRTEI);
    i = cell1->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &p_emlrtBCI, sp);
    }

    i = cell1->data[b_i].f1->size[0] * cell1->data[b_i].f1->size[1];
    cell1->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, cell1->data[b_i].f1, i, &ed_emlrtRTEI);
    i = cell1->size[0] - 1;
    i1 = cell1->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &p_emlrtBCI, sp);
    }

    i1 = cell1->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &p_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < kstr; i1++) {
      i2 = sldProfiles->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &o_emlrtBCI, sp);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &p_emlrtBCI, sp);
      }

      cell1->data[b_i].f1->data[i1] = sldProfiles->data[b_i].f1->data[i1];
    }
  }

  emxFree_cell_wrap_8(&sldProfiles);
  i = result->f5->size[0];
  result->f5->size[0] = cell1->size[0];
  emxEnsureCapacity_cell_wrap_6(sp, result->f5, i, &bd_emlrtRTEI);
  kstr = cell1->size[0];
  for (i = 0; i < kstr; i++) {
    emxCopyStruct_cell_wrap_6(sp, &result->f5->data[i], &cell1->data[i],
      &bd_emlrtRTEI);
  }

  emxFree_cell_wrap_6(&cell1);
  emxInit_int8_T(sp, &cell6, 1, &he_emlrtRTEI, true);

  /*   */
  /*  cell6Length = 7; */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &l_emlrtRTEI, sp);
  i = cell6->size[0];
  cell6->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_int8_T(sp, cell6, i, &lc_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i = cell6->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &q_emlrtBCI, sp);
    }

    cell6->data[b_i] = 0;
  }

  i = result->f6->size[0];
  result->f6->size[0] = cell6->size[0];
  emxEnsureCapacity_real_T(sp, result->f6, i, &dd_emlrtRTEI);
  loop_ub = cell6->size[0];
  for (i = 0; i < loop_ub; i++) {
    result->f6->data[i] = cell6->data[i];
  }

  emxFree_int8_T(&cell6);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (reflectivity_calculation.c) */
