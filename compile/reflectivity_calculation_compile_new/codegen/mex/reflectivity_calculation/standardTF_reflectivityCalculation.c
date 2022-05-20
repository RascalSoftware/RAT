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
#include "lower.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_custLay_reflectivityCalculation.h"
#include "standardTF_custXY_reflectivityCalculation.h"
#include "standardTF_stanlay_paraContrasts.h"
#include "standardTF_stanlay_paraPoints.h"
#include "standardTF_stanlay_single.h"
#include "sum.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo b_emlrtRSI = { 65,  /* lineNo */
  "standardTF_reflectivityCalculation",/* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 68,  /* lineNo */
  "standardTF_reflectivityCalculation",/* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 73,  /* lineNo */
  "standardTF_reflectivityCalculation",/* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 78,  /* lineNo */
  "standardTF_reflectivityCalculation",/* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 64,  /* lineNo */
  "standardTF_stanLay_reflectivityCalculation",/* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 70,  /* lineNo */
  "standardTF_stanLay_reflectivityCalculation",/* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 76,  /* lineNo */
  "standardTF_stanLay_reflectivityCalculation",/* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 91,  /* lineNo */
  "standardTF_stanLay_reflectivityCalculation",/* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pathName */
};

static emlrtDCInfo d_emlrtDCI = { 23,  /* lineNo */
  18,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 23,  /* lineNo */
  18,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 35,  /* lineNo */
  21,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo m_emlrtRTEI = { 36,/* lineNo */
  9,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 41,/* lineNo */
  9,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 46,/* lineNo */
  9,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 51,/* lineNo */
  9,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 56,/* lineNo */
  9,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 61,/* lineNo */
  9,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtDCInfo g_emlrtDCI = { 28,  /* lineNo */
  21,                                  /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo s_emlrtRTEI = { 29,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 34,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 39,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 44,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 49,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 54,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  37,                                  /* lineNo */
  18,                                  /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  16,                                  /* colNo */
  "Simulation",                        /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  18,                                  /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  15,                                  /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  17,                                  /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  15,                                  /* colNo */
  "allLayers",                         /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  30,                                  /* lineNo */
  18,                                  /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  16,                                  /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  18,                                  /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  15,                                  /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  17,                                  /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  55,                                  /* lineNo */
  15,                                  /* colNo */
  "allLayers",                         /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 83,  /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 84,  /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 85,  /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 86,  /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 87,  /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 88,  /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = { 24,  /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 89,  /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = { 92,  /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  55,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  37,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  30,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo lf_emlrtRTEI = { 31,/* lineNo */
  51,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo mf_emlrtRTEI = { 24,/* lineNo */
  1,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo nf_emlrtRTEI = { 17,/* lineNo */
  8,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo of_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo pf_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo qf_emlrtRTEI = { 47,/* lineNo */
  5,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo rf_emlrtRTEI = { 52,/* lineNo */
  5,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo sf_emlrtRTEI = { 57,/* lineNo */
  5,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo tf_emlrtRTEI = { 62,/* lineNo */
  5,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo uf_emlrtRTEI = { 73,/* lineNo */
  10,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo vf_emlrtRTEI = { 78,/* lineNo */
  9,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo wf_emlrtRTEI = { 83,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo xf_emlrtRTEI = { 84,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo yf_emlrtRTEI = { 85,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ag_emlrtRTEI = { 68,/* lineNo */
  10,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo bg_emlrtRTEI = { 78,/* lineNo */
  10,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo cg_emlrtRTEI = { 86,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo dg_emlrtRTEI = { 87,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo eg_emlrtRTEI = { 88,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo fg_emlrtRTEI = { 24,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo gg_emlrtRTEI = { 89,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo hg_emlrtRTEI = { 92,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ig_emlrtRTEI = { 17,/* lineNo */
  21,                                  /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo jg_emlrtRTEI = { 30,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo kg_emlrtRTEI = { 35,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo lg_emlrtRTEI = { 40,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo mg_emlrtRTEI = { 45,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ng_emlrtRTEI = { 50,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo og_emlrtRTEI = { 55,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo pg_emlrtRTEI = { 1,/* lineNo */
  91,                                  /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo qg_emlrtRTEI = { 65,/* lineNo */
  8,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo rg_emlrtRTEI = { 73,/* lineNo */
  9,                                   /* colNo */
  "standardTF_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"/* pName */
};

/* Function Definitions */
void c_standardTF_reflectivityCalcul(const emlrtStack *sp, const struct0_T
  *problemDef, const cell_16 *problemDef_cells, const struct2_T *controls,
  struct4_T *problem, emxArray_cell_wrap_9 *reflectivity, emxArray_cell_wrap_9
  *Simulation, emxArray_cell_wrap_14 *shifted_data, emxArray_cell_wrap_10
  *layerSlds, emxArray_cell_wrap_14 *sldProfiles, emxArray_cell_wrap_14
  *allLayers)
{
  static const char_T b_cv1[13] = { 'c', 'u', 's', 't', 'o', 'm', ' ', 'l', 'a',
    'y', 'e', 'r', 's' };

  static const char_T cv2[9] = { 'c', 'u', 's', 't', 'o', 'm', ' ', 'x', 'y' };

  static const char_T b_cv[6] = { 'l', 'a', 'y', 'e', 'r', 's' };

  static const char_T cv3[6] = { 's', 'i', 'n', 'g', 'l', 'e' };

  static const char_T cv4[6] = { 'p', 'o', 'i', 'n', 't', 's' };

  emlrtStack b_st;
  emlrtStack st;
  emxArray_char_T *switch_expression;
  emxArray_int8_T *t0_calculations_all_chis;
  struct_T b_problem;
  struct_T c_problem;
  int32_T b_loop_ub;
  int32_T exitg1;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  boolean_T b_bool;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  Main function for the standardTF reflectivity calculation */
  /*  This function decides what type of model is being analysed and barnches */
  /*  to the correct one. The main options are: */
  /*  layers            - This is the equivalent of Standard Layers in RasCAL */
  /*  Custom Layers     - This is also a layers calculation, but the */
  /*                    specification of the layers is dne using a user defined */
  /*                    function. */
  /*  Custom XY         - This also has a model described by a user supplied */
  /*                    function, but in this case the function generates an     */
  /*                    SLD profile (i.e. XY function) rather than a list of */
  /*                    layers. */
  /*  Find out the model type from the input structs */
  /*  Pre-allocate the output arrays.. this is necessary because otherwise */
  /*  the compiler complains with 'Output argument <....> is not assigned on  */
  /*  some execution paths' error. */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &d_emlrtDCI, sp);
  }

  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &e_emlrtDCI, sp);
  }

  emxInit_int8_T(sp, &t0_calculations_all_chis, 1, &pg_emlrtRTEI, true);
  i1 = t0_calculations_all_chis->size[0];
  loop_ub = (int32_T)problemDef->numberOfContrasts;
  t0_calculations_all_chis->size[0] = loop_ub;
  emxEnsureCapacity_int8_T(sp, t0_calculations_all_chis, i1, &lf_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    t0_calculations_all_chis->data[i1] = 0;
  }

  i1 = problem->ssubs->size[0];
  problem->ssubs->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->ssubs, i1, &mf_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->ssubs->data[i1] = 0.0;
  }

  i1 = problem->backgrounds->size[0];
  problem->backgrounds->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->backgrounds, i1, &mf_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->backgrounds->data[i1] = 0.0;
  }

  i1 = problem->qshifts->size[0];
  problem->qshifts->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->qshifts, i1, &mf_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->qshifts->data[i1] = 0.0;
  }

  i1 = problem->scalefactors->size[0];
  problem->scalefactors->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->scalefactors, i1, &mf_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->scalefactors->data[i1] = 0.0;
  }

  i1 = problem->nbairs->size[0];
  problem->nbairs->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->nbairs, i1, &mf_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->nbairs->data[i1] = 0.0;
  }

  i1 = problem->nbsubs->size[0];
  problem->nbsubs->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->nbsubs, i1, &mf_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->nbsubs->data[i1] = 0.0;
  }

  i1 = problem->resolutions->size[0];
  problem->resolutions->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->resolutions, i1, &mf_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->resolutions->data[i1] = 0.0;
  }

  i1 = problem->calculations.all_chis->size[0];
  problem->calculations.all_chis->size[0] = t0_calculations_all_chis->size[0];
  emxEnsureCapacity_real_T(sp, problem->calculations.all_chis, i1, &mf_emlrtRTEI);
  b_loop_ub = t0_calculations_all_chis->size[0];
  for (i1 = 0; i1 < b_loop_ub; i1++) {
    problem->calculations.all_chis->data[i1] = t0_calculations_all_chis->data[i1];
  }

  emxFree_int8_T(&t0_calculations_all_chis);
  problem->calculations.sum_chi = 0.0;
  i1 = problem->allSubRough->size[0];
  problem->allSubRough->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->allSubRough, i1, &mf_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->allSubRough->data[i1] = 0.0;
  }

  i1 = problem->resample->size[0] * problem->resample->size[1];
  problem->resample->size[0] = loop_ub;
  problem->resample->size[1] = 1;
  emxEnsureCapacity_real_T(sp, problem->resample, i1, &mf_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->resample->data[i1] = 0.0;
  }

  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &f_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &m_emlrtRTEI, sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i1, &nf_emlrtRTEI);
  for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
    if (b_loop_ub > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, reflectivity->size[0] - 1,
        &lb_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_loop_ub].f1->size[0] * reflectivity->
      data[b_loop_ub].f1->size[1];
    reflectivity->data[b_loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_loop_ub].f1, i1,
      &of_emlrtRTEI);
    if (b_loop_ub > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, reflectivity->size[0] - 1,
        &lb_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_loop_ub].f1->size[0] * reflectivity->
      data[b_loop_ub].f1->size[1];
    reflectivity->data[b_loop_ub].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_loop_ub].f1, i1,
      &of_emlrtRTEI);
    i1 = reflectivity->size[0];
    if (b_loop_ub > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, reflectivity->size[0] - 1,
        &lb_emlrtBCI, sp);
    }

    if (b_loop_ub > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, reflectivity->size[0] - 1,
        &lb_emlrtBCI, sp);
    }

    if (b_loop_ub > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, reflectivity->size[0] - 1,
        &ec_emlrtBCI, sp);
    }

    reflectivity->data[b_loop_ub].f1->data[0] = 1.0;
    if (b_loop_ub > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i1 - 1, &ec_emlrtBCI, sp);
    }

    reflectivity->data[b_loop_ub].f1->data[1] = 1.0;
    if (b_loop_ub > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i1 - 1, &ec_emlrtBCI, sp);
    }

    reflectivity->data[b_loop_ub].f1->data[2] = 1.0;
    if (b_loop_ub > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i1 - 1, &ec_emlrtBCI, sp);
    }

    reflectivity->data[b_loop_ub].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &n_emlrtRTEI, sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i1, &nf_emlrtRTEI);
  for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
    if (b_loop_ub > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, Simulation->size[0] - 1,
        &mb_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_loop_ub].f1->size[0] * Simulation->data[b_loop_ub].
      f1->size[1];
    Simulation->data[b_loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_loop_ub].f1, i1,
      &pf_emlrtRTEI);
    if (b_loop_ub > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, Simulation->size[0] - 1,
        &mb_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_loop_ub].f1->size[0] * Simulation->data[b_loop_ub].
      f1->size[1];
    Simulation->data[b_loop_ub].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_loop_ub].f1, i1,
      &pf_emlrtRTEI);
    i1 = Simulation->size[0];
    if (b_loop_ub > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, Simulation->size[0] - 1,
        &mb_emlrtBCI, sp);
    }

    if (b_loop_ub > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, Simulation->size[0] - 1,
        &mb_emlrtBCI, sp);
    }

    if (b_loop_ub > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, Simulation->size[0] - 1,
        &fc_emlrtBCI, sp);
    }

    Simulation->data[b_loop_ub].f1->data[0] = 1.0;
    if (b_loop_ub > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i1 - 1, &fc_emlrtBCI, sp);
    }

    Simulation->data[b_loop_ub].f1->data[1] = 1.0;
    if (b_loop_ub > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i1 - 1, &fc_emlrtBCI, sp);
    }

    Simulation->data[b_loop_ub].f1->data[2] = 1.0;
    if (b_loop_ub > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i1 - 1, &fc_emlrtBCI, sp);
    }

    Simulation->data[b_loop_ub].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &o_emlrtRTEI, sp);
  i1 = shifted_data->size[0];
  shifted_data->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i1, &nf_emlrtRTEI);
  for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
    if (b_loop_ub > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, shifted_data->size[0] - 1,
        &nb_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_loop_ub].f1->size[0] * shifted_data->
      data[b_loop_ub].f1->size[1];
    shifted_data->data[b_loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_loop_ub].f1, i1,
      &qf_emlrtRTEI);
    if (b_loop_ub > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, shifted_data->size[0] - 1,
        &nb_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_loop_ub].f1->size[0] * shifted_data->
      data[b_loop_ub].f1->size[1];
    shifted_data->data[b_loop_ub].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_loop_ub].f1, i1,
      &qf_emlrtRTEI);
    i1 = shifted_data->size[0];
    if (b_loop_ub > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, shifted_data->size[0] - 1,
        &nb_emlrtBCI, sp);
    }

    if (b_loop_ub > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, shifted_data->size[0] - 1,
        &nb_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < 6; i2++) {
      if (b_loop_ub > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i1 - 1, &xb_emlrtBCI, sp);
      }

      shifted_data->data[b_loop_ub].f1->data[i2] = 1.0;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &p_emlrtRTEI, sp);
  i1 = layerSlds->size[0];
  layerSlds->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i1, &nf_emlrtRTEI);
  for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
    if (b_loop_ub > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, layerSlds->size[0] - 1,
        &ob_emlrtBCI, sp);
    }

    i1 = layerSlds->data[b_loop_ub].f1->size[0] * layerSlds->data[b_loop_ub].
      f1->size[1];
    layerSlds->data[b_loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_loop_ub].f1, i1,
      &rf_emlrtRTEI);
    if (b_loop_ub > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, layerSlds->size[0] - 1,
        &ob_emlrtBCI, sp);
    }

    i1 = layerSlds->data[b_loop_ub].f1->size[0] * layerSlds->data[b_loop_ub].
      f1->size[1];
    layerSlds->data[b_loop_ub].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_loop_ub].f1, i1,
      &rf_emlrtRTEI);
    i1 = layerSlds->size[0];
    if (b_loop_ub > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, layerSlds->size[0] - 1,
        &ob_emlrtBCI, sp);
    }

    if (b_loop_ub > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, layerSlds->size[0] - 1,
        &ob_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < 6; i2++) {
      if (b_loop_ub > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i1 - 1, &yb_emlrtBCI, sp);
      }

      layerSlds->data[b_loop_ub].f1->data[i2] = 1.0;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &q_emlrtRTEI, sp);
  i1 = sldProfiles->size[0];
  sldProfiles->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i1, &nf_emlrtRTEI);
  for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
    if (b_loop_ub > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, sldProfiles->size[0] - 1,
        &pb_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_loop_ub].f1->size[0] * sldProfiles->data[b_loop_ub]
      .f1->size[1];
    sldProfiles->data[b_loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_loop_ub].f1, i1,
      &sf_emlrtRTEI);
    if (b_loop_ub > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, sldProfiles->size[0] - 1,
        &pb_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_loop_ub].f1->size[0] * sldProfiles->data[b_loop_ub]
      .f1->size[1];
    sldProfiles->data[b_loop_ub].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_loop_ub].f1, i1,
      &sf_emlrtRTEI);
    i1 = sldProfiles->size[0];
    if (b_loop_ub > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, sldProfiles->size[0] - 1,
        &pb_emlrtBCI, sp);
    }

    if (b_loop_ub > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, sldProfiles->size[0] - 1,
        &pb_emlrtBCI, sp);
    }

    if (b_loop_ub > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, sldProfiles->size[0] - 1,
        &gc_emlrtBCI, sp);
    }

    sldProfiles->data[b_loop_ub].f1->data[0] = 1.0;
    if (b_loop_ub > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i1 - 1, &gc_emlrtBCI, sp);
    }

    sldProfiles->data[b_loop_ub].f1->data[1] = 1.0;
    if (b_loop_ub > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i1 - 1, &gc_emlrtBCI, sp);
    }

    sldProfiles->data[b_loop_ub].f1->data[2] = 1.0;
    if (b_loop_ub > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i1 - 1, &gc_emlrtBCI, sp);
    }

    sldProfiles->data[b_loop_ub].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &r_emlrtRTEI, sp);
  i1 = allLayers->size[0];
  allLayers->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i1, &nf_emlrtRTEI);
  for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
    if (b_loop_ub > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, allLayers->size[0] - 1,
        &qb_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_loop_ub].f1->size[0] * allLayers->data[b_loop_ub].
      f1->size[1];
    allLayers->data[b_loop_ub].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_loop_ub].f1, i1,
      &tf_emlrtRTEI);
    if (b_loop_ub > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, allLayers->size[0] - 1,
        &qb_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_loop_ub].f1->size[0] * allLayers->data[b_loop_ub].
      f1->size[1];
    allLayers->data[b_loop_ub].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_loop_ub].f1, i1,
      &tf_emlrtRTEI);
    i1 = allLayers->size[0];
    if (b_loop_ub > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, allLayers->size[0] - 1,
        &qb_emlrtBCI, sp);
    }

    if (b_loop_ub > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, allLayers->size[0] - 1,
        &qb_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < 6; i2++) {
      if (b_loop_ub > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i1 - 1, &ac_emlrtBCI, sp);
      }

      allLayers->data[b_loop_ub].f1->data[i2] = 1.0;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxInit_char_T(sp, &switch_expression, 2, &qg_emlrtRTEI, true);
  st.site = &b_emlrtRSI;
  lower(&st, problemDef->modelType, switch_expression);
  b_bool = false;
  if (switch_expression->size[1] == 6) {
    b_loop_ub = 0;
    do {
      exitg1 = 0;
      if (b_loop_ub < 6) {
        if (switch_expression->data[b_loop_ub] != b_cv[b_loop_ub]) {
          exitg1 = 1;
        } else {
          b_loop_ub++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  if (b_bool) {
    b_loop_ub = 0;
  } else {
    b_bool = false;
    if (switch_expression->size[1] == 13) {
      b_loop_ub = 0;
      do {
        exitg1 = 0;
        if (b_loop_ub < 13) {
          if (switch_expression->data[b_loop_ub] != b_cv1[b_loop_ub]) {
            exitg1 = 1;
          } else {
            b_loop_ub++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (b_bool) {
      b_loop_ub = 1;
    } else {
      b_bool = false;
      if (switch_expression->size[1] == 9) {
        b_loop_ub = 0;
        do {
          exitg1 = 0;
          if (b_loop_ub < 9) {
            if (switch_expression->data[b_loop_ub] != cv2[b_loop_ub]) {
              exitg1 = 1;
            } else {
              b_loop_ub++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }

      if (b_bool) {
        b_loop_ub = 2;
      } else {
        b_loop_ub = -1;
      }
    }
  }

  emxFree_char_T(&switch_expression);
  emxInitStruct_struct_T(sp, &b_problem, &rg_emlrtRTEI, true);
  switch (b_loop_ub) {
   case 0:
    /*  Standard layers calculation */
    st.site = &c_emlrtRSI;

    /*  Standard layers reflectivity calculation for standardTF */
    /*  This function decides on parallelisation options before calling the */
    /*  relevant version ofthe main standard layers calculation. Parallelisation  */
    /*  is either over the outer loop ('contrasts'), or the inner loop */
    /*  ('points'). The easiest way to do this is to have multiple versions of  */
    /*  the same core calculation, rather than trying to make the paralell */
    /*  for loops conditional (although that would be much neater) There are: */
    /*  points    - parallelise over points in the reflectivity calculation */
    /*  contrasts - parallelise over contrasts (outer for loop) */
    /*  Pre-allocation - It's necessary to */
    /*  pre-define the types for all the arrays */
    /*  for compilation, so do this in this block. */
    if (problemDef->numberOfContrasts != problemDef->numberOfContrasts) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &h_emlrtDCI, &st);
    }

    i1 = b_problem.ssubs->size[0];
    b_problem.ssubs->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, b_problem.ssubs, i1, &wf_emlrtRTEI);
    if (problemDef->numberOfContrasts != problemDef->numberOfContrasts) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &h_emlrtDCI, &st);
    }

    for (i1 = 0; i1 < loop_ub; i1++) {
      b_problem.ssubs->data[i1] = 0.0;
    }

    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &i_emlrtDCI, &st);
    }

    i1 = b_problem.backgrounds->size[0];
    b_problem.backgrounds->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, b_problem.backgrounds, i1, &xf_emlrtRTEI);
    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &i_emlrtDCI, &st);
    }

    for (i1 = 0; i1 < loop_ub; i1++) {
      b_problem.backgrounds->data[i1] = 0.0;
    }

    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &j_emlrtDCI, &st);
    }

    i1 = b_problem.qshifts->size[0];
    b_problem.qshifts->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, b_problem.qshifts, i1, &yf_emlrtRTEI);
    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &j_emlrtDCI, &st);
    }

    for (i1 = 0; i1 < loop_ub; i1++) {
      b_problem.qshifts->data[i1] = 0.0;
    }

    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &k_emlrtDCI, &st);
    }

    i1 = b_problem.scalefactors->size[0];
    b_problem.scalefactors->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, b_problem.scalefactors, i1, &cg_emlrtRTEI);
    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &k_emlrtDCI, &st);
    }

    for (i1 = 0; i1 < loop_ub; i1++) {
      b_problem.scalefactors->data[i1] = 0.0;
    }

    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &l_emlrtDCI, &st);
    }

    i1 = b_problem.nbairs->size[0];
    b_problem.nbairs->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, b_problem.nbairs, i1, &dg_emlrtRTEI);
    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &l_emlrtDCI, &st);
    }

    for (i1 = 0; i1 < loop_ub; i1++) {
      b_problem.nbairs->data[i1] = 0.0;
    }

    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &m_emlrtDCI, &st);
    }

    i1 = b_problem.nbsubs->size[0];
    b_problem.nbsubs->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, b_problem.nbsubs, i1, &eg_emlrtRTEI);
    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &m_emlrtDCI, &st);
    }

    for (i1 = 0; i1 < loop_ub; i1++) {
      b_problem.nbsubs->data[i1] = 0.0;
    }

    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &n_emlrtDCI, &st);
    }

    i1 = b_problem.calculations.all_chis->size[0];
    b_problem.calculations.all_chis->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, b_problem.calculations.all_chis, i1,
      &fg_emlrtRTEI);
    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &n_emlrtDCI, &st);
    }

    for (i1 = 0; i1 < loop_ub; i1++) {
      b_problem.calculations.all_chis->data[i1] = 0.0;
    }

    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &o_emlrtDCI, &st);
    }

    i1 = b_problem.resolutions->size[0];
    b_problem.resolutions->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, b_problem.resolutions, i1, &gg_emlrtRTEI);
    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &o_emlrtDCI, &st);
    }

    for (i1 = 0; i1 < loop_ub; i1++) {
      b_problem.resolutions->data[i1] = 0.0;
    }

    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &p_emlrtDCI, &st);
    }

    i1 = b_problem.allSubRough->size[0];
    b_problem.allSubRough->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, b_problem.allSubRough, i1, &hg_emlrtRTEI);
    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &p_emlrtDCI, &st);
    }

    for (i1 = 0; i1 < loop_ub; i1++) {
      b_problem.allSubRough->data[i1] = 0.0;
    }

    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &g_emlrtDCI, &st);
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &s_emlrtRTEI, &st);
    i = reflectivity->size[0];
    reflectivity->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_9(&st, reflectivity, i, &ig_emlrtRTEI);
    for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
      if (b_loop_ub > reflectivity->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, reflectivity->size[0] - 1,
          &rb_emlrtBCI, &st);
      }

      i = reflectivity->data[b_loop_ub].f1->size[0] * reflectivity->
        data[b_loop_ub].f1->size[1];
      reflectivity->data[b_loop_ub].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_loop_ub].f1, i,
        &jg_emlrtRTEI);
      if (b_loop_ub > reflectivity->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, reflectivity->size[0] - 1,
          &rb_emlrtBCI, &st);
      }

      i = reflectivity->data[b_loop_ub].f1->size[0] * reflectivity->
        data[b_loop_ub].f1->size[1];
      reflectivity->data[b_loop_ub].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_loop_ub].f1, i,
        &jg_emlrtRTEI);
      i = reflectivity->size[0];
      if (b_loop_ub > reflectivity->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, reflectivity->size[0] - 1,
          &rb_emlrtBCI, &st);
      }

      if (b_loop_ub > reflectivity->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, reflectivity->size[0] - 1,
          &rb_emlrtBCI, &st);
      }

      if (b_loop_ub > reflectivity->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, reflectivity->size[0] - 1,
          &hc_emlrtBCI, &st);
      }

      reflectivity->data[b_loop_ub].f1->data[0] = 1.0;
      if (b_loop_ub > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i - 1, &hc_emlrtBCI, &st);
      }

      reflectivity->data[b_loop_ub].f1->data[1] = 1.0;
      if (b_loop_ub > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i - 1, &hc_emlrtBCI, &st);
      }

      reflectivity->data[b_loop_ub].f1->data[2] = 1.0;
      if (b_loop_ub > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i - 1, &hc_emlrtBCI, &st);
      }

      reflectivity->data[b_loop_ub].f1->data[3] = 1.0;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &t_emlrtRTEI, &st);
    i = Simulation->size[0];
    Simulation->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_9(&st, Simulation, i, &ig_emlrtRTEI);
    for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
      if (b_loop_ub > Simulation->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, Simulation->size[0] - 1,
          &sb_emlrtBCI, &st);
      }

      i = Simulation->data[b_loop_ub].f1->size[0] * Simulation->data[b_loop_ub].
        f1->size[1];
      Simulation->data[b_loop_ub].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, Simulation->data[b_loop_ub].f1, i,
        &kg_emlrtRTEI);
      if (b_loop_ub > Simulation->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, Simulation->size[0] - 1,
          &sb_emlrtBCI, &st);
      }

      i = Simulation->data[b_loop_ub].f1->size[0] * Simulation->data[b_loop_ub].
        f1->size[1];
      Simulation->data[b_loop_ub].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, Simulation->data[b_loop_ub].f1, i,
        &kg_emlrtRTEI);
      i = Simulation->size[0];
      if (b_loop_ub > Simulation->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, Simulation->size[0] - 1,
          &sb_emlrtBCI, &st);
      }

      if (b_loop_ub > Simulation->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, Simulation->size[0] - 1,
          &sb_emlrtBCI, &st);
      }

      if (b_loop_ub > Simulation->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, Simulation->size[0] - 1,
          &ic_emlrtBCI, &st);
      }

      Simulation->data[b_loop_ub].f1->data[0] = 1.0;
      if (b_loop_ub > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i - 1, &ic_emlrtBCI, &st);
      }

      Simulation->data[b_loop_ub].f1->data[1] = 1.0;
      if (b_loop_ub > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i - 1, &ic_emlrtBCI, &st);
      }

      Simulation->data[b_loop_ub].f1->data[2] = 1.0;
      if (b_loop_ub > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i - 1, &ic_emlrtBCI, &st);
      }

      Simulation->data[b_loop_ub].f1->data[3] = 1.0;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &u_emlrtRTEI, &st);
    i = shifted_data->size[0];
    shifted_data->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_14(&st, shifted_data, i, &ig_emlrtRTEI);
    for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
      if (b_loop_ub > shifted_data->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, shifted_data->size[0] - 1,
          &tb_emlrtBCI, &st);
      }

      i = shifted_data->data[b_loop_ub].f1->size[0] * shifted_data->
        data[b_loop_ub].f1->size[1];
      shifted_data->data[b_loop_ub].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, shifted_data->data[b_loop_ub].f1, i,
        &lg_emlrtRTEI);
      if (b_loop_ub > shifted_data->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, shifted_data->size[0] - 1,
          &tb_emlrtBCI, &st);
      }

      i = shifted_data->data[b_loop_ub].f1->size[0] * shifted_data->
        data[b_loop_ub].f1->size[1];
      shifted_data->data[b_loop_ub].f1->size[1] = 3;
      emxEnsureCapacity_real_T(&st, shifted_data->data[b_loop_ub].f1, i,
        &lg_emlrtRTEI);
      i = shifted_data->size[0];
      if (b_loop_ub > shifted_data->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, shifted_data->size[0] - 1,
          &tb_emlrtBCI, &st);
      }

      if (b_loop_ub > shifted_data->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, shifted_data->size[0] - 1,
          &tb_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < 6; i1++) {
        if (b_loop_ub > i - 1) {
          emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i - 1, &bc_emlrtBCI, &st);
        }

        shifted_data->data[b_loop_ub].f1->data[i1] = 1.0;
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &v_emlrtRTEI, &st);
    i = layerSlds->size[0];
    layerSlds->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_10(&st, layerSlds, i, &ig_emlrtRTEI);
    for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
      if (b_loop_ub > layerSlds->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, layerSlds->size[0] - 1,
          &ub_emlrtBCI, &st);
      }

      i = layerSlds->data[b_loop_ub].f1->size[0] * layerSlds->data[b_loop_ub].
        f1->size[1];
      layerSlds->data[b_loop_ub].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, layerSlds->data[b_loop_ub].f1, i,
        &mg_emlrtRTEI);
      if (b_loop_ub > layerSlds->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, layerSlds->size[0] - 1,
          &ub_emlrtBCI, &st);
      }

      i = layerSlds->data[b_loop_ub].f1->size[0] * layerSlds->data[b_loop_ub].
        f1->size[1];
      layerSlds->data[b_loop_ub].f1->size[1] = 3;
      emxEnsureCapacity_real_T(&st, layerSlds->data[b_loop_ub].f1, i,
        &mg_emlrtRTEI);
      i = layerSlds->size[0];
      if (b_loop_ub > layerSlds->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, layerSlds->size[0] - 1,
          &ub_emlrtBCI, &st);
      }

      if (b_loop_ub > layerSlds->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, layerSlds->size[0] - 1,
          &ub_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < 6; i1++) {
        if (b_loop_ub > i - 1) {
          emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i - 1, &cc_emlrtBCI, &st);
        }

        layerSlds->data[b_loop_ub].f1->data[i1] = 1.0;
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &w_emlrtRTEI, &st);
    i = sldProfiles->size[0];
    sldProfiles->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_14(&st, sldProfiles, i, &ig_emlrtRTEI);
    for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
      if (b_loop_ub > sldProfiles->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, sldProfiles->size[0] - 1,
          &vb_emlrtBCI, &st);
      }

      i = sldProfiles->data[b_loop_ub].f1->size[0] * sldProfiles->data[b_loop_ub]
        .f1->size[1];
      sldProfiles->data[b_loop_ub].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, sldProfiles->data[b_loop_ub].f1, i,
        &ng_emlrtRTEI);
      if (b_loop_ub > sldProfiles->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, sldProfiles->size[0] - 1,
          &vb_emlrtBCI, &st);
      }

      i = sldProfiles->data[b_loop_ub].f1->size[0] * sldProfiles->data[b_loop_ub]
        .f1->size[1];
      sldProfiles->data[b_loop_ub].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, sldProfiles->data[b_loop_ub].f1, i,
        &ng_emlrtRTEI);
      i = sldProfiles->size[0];
      if (b_loop_ub > sldProfiles->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, sldProfiles->size[0] - 1,
          &vb_emlrtBCI, &st);
      }

      if (b_loop_ub > sldProfiles->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, sldProfiles->size[0] - 1,
          &vb_emlrtBCI, &st);
      }

      if (b_loop_ub > sldProfiles->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, sldProfiles->size[0] - 1,
          &jc_emlrtBCI, &st);
      }

      sldProfiles->data[b_loop_ub].f1->data[0] = 1.0;
      if (b_loop_ub > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i - 1, &jc_emlrtBCI, &st);
      }

      sldProfiles->data[b_loop_ub].f1->data[1] = 1.0;
      if (b_loop_ub > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i - 1, &jc_emlrtBCI, &st);
      }

      sldProfiles->data[b_loop_ub].f1->data[2] = 1.0;
      if (b_loop_ub > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i - 1, &jc_emlrtBCI, &st);
      }

      sldProfiles->data[b_loop_ub].f1->data[3] = 1.0;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &x_emlrtRTEI, &st);
    i = allLayers->size[0];
    allLayers->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_14(&st, allLayers, i, &ig_emlrtRTEI);
    for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
      if (b_loop_ub > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, allLayers->size[0] - 1,
          &wb_emlrtBCI, &st);
      }

      i = allLayers->data[b_loop_ub].f1->size[0] * allLayers->data[b_loop_ub].
        f1->size[1];
      allLayers->data[b_loop_ub].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, allLayers->data[b_loop_ub].f1, i,
        &og_emlrtRTEI);
      if (b_loop_ub > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, allLayers->size[0] - 1,
          &wb_emlrtBCI, &st);
      }

      i = allLayers->data[b_loop_ub].f1->size[0] * allLayers->data[b_loop_ub].
        f1->size[1];
      allLayers->data[b_loop_ub].f1->size[1] = 3;
      emxEnsureCapacity_real_T(&st, allLayers->data[b_loop_ub].f1, i,
        &og_emlrtRTEI);
      i = allLayers->size[0];
      if (b_loop_ub > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, allLayers->size[0] - 1,
          &wb_emlrtBCI, &st);
      }

      if (b_loop_ub > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, allLayers->size[0] - 1,
          &wb_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < 6; i1++) {
        if (b_loop_ub > i - 1) {
          emlrtDynamicBoundsCheckR2012b(b_loop_ub, 0, i - 1, &dc_emlrtBCI, &st);
        }

        allLayers->data[b_loop_ub].f1->data[i1] = 1.0;
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    /*  ------- End type definitions ------------- */
    b_bool = false;
    if (controls->para->size[1] == 6) {
      b_loop_ub = 0;
      do {
        exitg1 = 0;
        if (b_loop_ub < 6) {
          if (controls->para->data[b_loop_ub] != cv3[b_loop_ub]) {
            exitg1 = 1;
          } else {
            b_loop_ub++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (b_bool) {
      b_loop_ub = 0;
    } else {
      b_bool = false;
      if (controls->para->size[1] == 6) {
        b_loop_ub = 0;
        do {
          exitg1 = 0;
          if (b_loop_ub < 6) {
            if (controls->para->data[b_loop_ub] != cv4[b_loop_ub]) {
              exitg1 = 1;
            } else {
              b_loop_ub++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }

      if (b_bool) {
        b_loop_ub = 1;
      } else {
        b_bool = false;
        if (controls->para->size[1] == 9) {
          b_loop_ub = 0;
          do {
            exitg1 = 0;
            if (b_loop_ub < 9) {
              if (controls->para->data[b_loop_ub] != cv[b_loop_ub]) {
                exitg1 = 1;
              } else {
                b_loop_ub++;
              }
            } else {
              b_bool = true;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (b_bool) {
          b_loop_ub = 2;
        } else {
          b_loop_ub = -1;
        }
      }
    }

    switch (b_loop_ub) {
     case 0:
      b_st.site = &k_emlrtRSI;
      standardTF_stanlay_single(&b_st, problemDef, problemDef_cells, controls,
        b_problem.ssubs, b_problem.backgrounds, b_problem.qshifts,
        b_problem.scalefactors, b_problem.nbairs, b_problem.nbsubs,
        b_problem.resolutions, b_problem.calculations.all_chis, reflectivity,
        Simulation, shifted_data, layerSlds, sldProfiles, allLayers,
        b_problem.allSubRough);
      break;

     case 1:
      b_st.site = &l_emlrtRSI;
      standardTF_stanlay_paraPoints(&b_st, problemDef, problemDef_cells,
        controls, b_problem.ssubs, b_problem.backgrounds, b_problem.qshifts,
        b_problem.scalefactors, b_problem.nbairs, b_problem.nbsubs,
        b_problem.resolutions, b_problem.calculations.all_chis, reflectivity,
        Simulation, shifted_data, layerSlds, sldProfiles, allLayers,
        b_problem.allSubRough);
      break;

     case 2:
      b_st.site = &m_emlrtRSI;
      c_standardTF_stanlay_paraContra(&b_st, problemDef, problemDef_cells,
        controls, b_problem.ssubs, b_problem.backgrounds, b_problem.qshifts,
        b_problem.scalefactors, b_problem.nbairs, b_problem.nbsubs,
        b_problem.resolutions, b_problem.calculations.all_chis, reflectivity,
        Simulation, shifted_data, layerSlds, sldProfiles, allLayers,
        b_problem.allSubRough);
      break;
    }

    /*  Package everything into one array for tidy output */
    b_st.site = &n_emlrtRSI;
    b_problem.calculations.sum_chi = sum(&b_st, b_problem.calculations.all_chis);
    i = problem->ssubs->size[0];
    problem->ssubs->size[0] = b_problem.ssubs->size[0];
    emxEnsureCapacity_real_T(sp, problem->ssubs, i, &ag_emlrtRTEI);
    loop_ub = b_problem.ssubs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->ssubs->data[i] = b_problem.ssubs->data[i];
    }

    i = problem->backgrounds->size[0];
    problem->backgrounds->size[0] = b_problem.backgrounds->size[0];
    emxEnsureCapacity_real_T(sp, problem->backgrounds, i, &ag_emlrtRTEI);
    loop_ub = b_problem.backgrounds->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->backgrounds->data[i] = b_problem.backgrounds->data[i];
    }

    i = problem->qshifts->size[0];
    problem->qshifts->size[0] = b_problem.qshifts->size[0];
    emxEnsureCapacity_real_T(sp, problem->qshifts, i, &ag_emlrtRTEI);
    loop_ub = b_problem.qshifts->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->qshifts->data[i] = b_problem.qshifts->data[i];
    }

    i = problem->scalefactors->size[0];
    problem->scalefactors->size[0] = b_problem.scalefactors->size[0];
    emxEnsureCapacity_real_T(sp, problem->scalefactors, i, &ag_emlrtRTEI);
    loop_ub = b_problem.scalefactors->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->scalefactors->data[i] = b_problem.scalefactors->data[i];
    }

    i = problem->nbairs->size[0];
    problem->nbairs->size[0] = b_problem.nbairs->size[0];
    emxEnsureCapacity_real_T(sp, problem->nbairs, i, &ag_emlrtRTEI);
    loop_ub = b_problem.nbairs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->nbairs->data[i] = b_problem.nbairs->data[i];
    }

    i = problem->nbsubs->size[0];
    problem->nbsubs->size[0] = b_problem.nbsubs->size[0];
    emxEnsureCapacity_real_T(sp, problem->nbsubs, i, &ag_emlrtRTEI);
    loop_ub = b_problem.nbsubs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->nbsubs->data[i] = b_problem.nbsubs->data[i];
    }

    i = problem->resolutions->size[0];
    problem->resolutions->size[0] = b_problem.resolutions->size[0];
    emxEnsureCapacity_real_T(sp, problem->resolutions, i, &ag_emlrtRTEI);
    loop_ub = b_problem.resolutions->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->resolutions->data[i] = b_problem.resolutions->data[i];
    }

    emxCopyStruct_struct5_T(sp, &problem->calculations, &b_problem.calculations,
      &ag_emlrtRTEI);
    i = problem->allSubRough->size[0];
    problem->allSubRough->size[0] = b_problem.allSubRough->size[0];
    emxEnsureCapacity_real_T(sp, problem->allSubRough, i, &ag_emlrtRTEI);
    loop_ub = b_problem.allSubRough->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->allSubRough->data[i] = b_problem.allSubRough->data[i];
    }

    i = problem->resample->size[0] * problem->resample->size[1];
    problem->resample->size[0] = 1;
    problem->resample->size[1] = problemDef->resample->size[1];
    emxEnsureCapacity_real_T(sp, problem->resample, i, &ag_emlrtRTEI);
    loop_ub = problemDef->resample->size[0] * problemDef->resample->size[1];
    for (i = 0; i < loop_ub; i++) {
      problem->resample->data[i] = problemDef->resample->data[i];
    }
    break;

   case 1:
    /*  Custom layers with user supplied custom model file */
    st.site = &d_emlrtRSI;
    c_standardTF_custLay_reflectivi(&st, problemDef, problemDef_cells, controls,
      &b_problem, reflectivity, Simulation, shifted_data, layerSlds, sldProfiles,
      allLayers);
    i = problem->ssubs->size[0];
    problem->ssubs->size[0] = b_problem.ssubs->size[0];
    emxEnsureCapacity_real_T(sp, problem->ssubs, i, &uf_emlrtRTEI);
    loop_ub = b_problem.ssubs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->ssubs->data[i] = b_problem.ssubs->data[i];
    }

    i = problem->backgrounds->size[0];
    problem->backgrounds->size[0] = b_problem.backgrounds->size[0];
    emxEnsureCapacity_real_T(sp, problem->backgrounds, i, &uf_emlrtRTEI);
    loop_ub = b_problem.backgrounds->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->backgrounds->data[i] = b_problem.backgrounds->data[i];
    }

    i = problem->qshifts->size[0];
    problem->qshifts->size[0] = b_problem.qshifts->size[0];
    emxEnsureCapacity_real_T(sp, problem->qshifts, i, &uf_emlrtRTEI);
    loop_ub = b_problem.qshifts->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->qshifts->data[i] = b_problem.qshifts->data[i];
    }

    i = problem->scalefactors->size[0];
    problem->scalefactors->size[0] = b_problem.scalefactors->size[0];
    emxEnsureCapacity_real_T(sp, problem->scalefactors, i, &uf_emlrtRTEI);
    loop_ub = b_problem.scalefactors->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->scalefactors->data[i] = b_problem.scalefactors->data[i];
    }

    i = problem->nbairs->size[0];
    problem->nbairs->size[0] = b_problem.nbairs->size[0];
    emxEnsureCapacity_real_T(sp, problem->nbairs, i, &uf_emlrtRTEI);
    loop_ub = b_problem.nbairs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->nbairs->data[i] = b_problem.nbairs->data[i];
    }

    i = problem->nbsubs->size[0];
    problem->nbsubs->size[0] = b_problem.nbsubs->size[0];
    emxEnsureCapacity_real_T(sp, problem->nbsubs, i, &uf_emlrtRTEI);
    loop_ub = b_problem.nbsubs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->nbsubs->data[i] = b_problem.nbsubs->data[i];
    }

    i = problem->resolutions->size[0];
    problem->resolutions->size[0] = b_problem.resolutions->size[0];
    emxEnsureCapacity_real_T(sp, problem->resolutions, i, &uf_emlrtRTEI);
    loop_ub = b_problem.resolutions->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->resolutions->data[i] = b_problem.resolutions->data[i];
    }

    emxCopyStruct_struct5_T(sp, &problem->calculations, &b_problem.calculations,
      &uf_emlrtRTEI);
    i = problem->allSubRough->size[0];
    problem->allSubRough->size[0] = b_problem.allSubRough->size[0];
    emxEnsureCapacity_real_T(sp, problem->allSubRough, i, &uf_emlrtRTEI);
    loop_ub = b_problem.allSubRough->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->allSubRough->data[i] = b_problem.allSubRough->data[i];
    }

    i = problem->resample->size[0] * problem->resample->size[1];
    problem->resample->size[0] = 1;
    problem->resample->size[1] = b_problem.resample->size[1];
    emxEnsureCapacity_real_T(sp, problem->resample, i, &ag_emlrtRTEI);
    loop_ub = b_problem.resample->size[0] * b_problem.resample->size[1];
    for (i = 0; i < loop_ub; i++) {
      problem->resample->data[i] = b_problem.resample->data[i];
    }
    break;

   case 2:
    emxInitStruct_struct_T(sp, &c_problem, &vf_emlrtRTEI, true);

    /*  Custom SLD profile with user defined model file */
    st.site = &e_emlrtRSI;
    c_standardTF_custXY_reflectivit(&st, problemDef, problemDef_cells, controls,
      &c_problem, reflectivity, Simulation, shifted_data, layerSlds, sldProfiles,
      allLayers);
    i = b_problem.ssubs->size[0];
    b_problem.ssubs->size[0] = c_problem.ssubs->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.ssubs, i, &vf_emlrtRTEI);
    loop_ub = c_problem.ssubs->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_problem.ssubs->data[i] = c_problem.ssubs->data[i];
    }

    i = b_problem.backgrounds->size[0];
    b_problem.backgrounds->size[0] = c_problem.backgrounds->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.backgrounds, i, &vf_emlrtRTEI);
    loop_ub = c_problem.backgrounds->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_problem.backgrounds->data[i] = c_problem.backgrounds->data[i];
    }

    i = b_problem.qshifts->size[0];
    b_problem.qshifts->size[0] = c_problem.qshifts->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.qshifts, i, &vf_emlrtRTEI);
    loop_ub = c_problem.qshifts->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_problem.qshifts->data[i] = c_problem.qshifts->data[i];
    }

    i = b_problem.scalefactors->size[0];
    b_problem.scalefactors->size[0] = c_problem.scalefactors->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.scalefactors, i, &vf_emlrtRTEI);
    loop_ub = c_problem.scalefactors->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_problem.scalefactors->data[i] = c_problem.scalefactors->data[i];
    }

    i = b_problem.nbairs->size[0];
    b_problem.nbairs->size[0] = c_problem.nbairs->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.nbairs, i, &vf_emlrtRTEI);
    loop_ub = c_problem.nbairs->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_problem.nbairs->data[i] = c_problem.nbairs->data[i];
    }

    i = b_problem.nbsubs->size[0];
    b_problem.nbsubs->size[0] = c_problem.nbsubs->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.nbsubs, i, &vf_emlrtRTEI);
    loop_ub = c_problem.nbsubs->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_problem.nbsubs->data[i] = c_problem.nbsubs->data[i];
    }

    i = b_problem.resolutions->size[0];
    b_problem.resolutions->size[0] = c_problem.resolutions->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.resolutions, i, &vf_emlrtRTEI);
    loop_ub = c_problem.resolutions->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_problem.resolutions->data[i] = c_problem.resolutions->data[i];
    }

    i = b_problem.allSubRough->size[0];
    b_problem.allSubRough->size[0] = c_problem.allSubRough->size[0];
    emxEnsureCapacity_real_T(sp, b_problem.allSubRough, i, &vf_emlrtRTEI);
    loop_ub = c_problem.allSubRough->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_problem.allSubRough->data[i] = c_problem.allSubRough->data[i];
    }

    i = b_problem.resample->size[0] * b_problem.resample->size[1];
    b_problem.resample->size[0] = 1;
    b_problem.resample->size[1] = c_problem.resample->size[1];
    emxEnsureCapacity_real_T(sp, b_problem.resample, i, &vf_emlrtRTEI);
    loop_ub = c_problem.resample->size[0] * c_problem.resample->size[1];
    for (i = 0; i < loop_ub; i++) {
      b_problem.resample->data[i] = c_problem.resample->data[i];
    }

    i = problem->ssubs->size[0];
    problem->ssubs->size[0] = b_problem.ssubs->size[0];
    emxEnsureCapacity_real_T(sp, problem->ssubs, i, &bg_emlrtRTEI);
    loop_ub = b_problem.ssubs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->ssubs->data[i] = b_problem.ssubs->data[i];
    }

    i = problem->backgrounds->size[0];
    problem->backgrounds->size[0] = b_problem.backgrounds->size[0];
    emxEnsureCapacity_real_T(sp, problem->backgrounds, i, &bg_emlrtRTEI);
    loop_ub = b_problem.backgrounds->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->backgrounds->data[i] = b_problem.backgrounds->data[i];
    }

    i = problem->qshifts->size[0];
    problem->qshifts->size[0] = b_problem.qshifts->size[0];
    emxEnsureCapacity_real_T(sp, problem->qshifts, i, &bg_emlrtRTEI);
    loop_ub = b_problem.qshifts->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->qshifts->data[i] = b_problem.qshifts->data[i];
    }

    i = problem->scalefactors->size[0];
    problem->scalefactors->size[0] = b_problem.scalefactors->size[0];
    emxEnsureCapacity_real_T(sp, problem->scalefactors, i, &bg_emlrtRTEI);
    loop_ub = b_problem.scalefactors->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->scalefactors->data[i] = b_problem.scalefactors->data[i];
    }

    i = problem->nbairs->size[0];
    problem->nbairs->size[0] = b_problem.nbairs->size[0];
    emxEnsureCapacity_real_T(sp, problem->nbairs, i, &bg_emlrtRTEI);
    loop_ub = b_problem.nbairs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->nbairs->data[i] = b_problem.nbairs->data[i];
    }

    i = problem->nbsubs->size[0];
    problem->nbsubs->size[0] = b_problem.nbsubs->size[0];
    emxEnsureCapacity_real_T(sp, problem->nbsubs, i, &bg_emlrtRTEI);
    loop_ub = b_problem.nbsubs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->nbsubs->data[i] = b_problem.nbsubs->data[i];
    }

    i = problem->resolutions->size[0];
    problem->resolutions->size[0] = b_problem.resolutions->size[0];
    emxEnsureCapacity_real_T(sp, problem->resolutions, i, &bg_emlrtRTEI);
    loop_ub = b_problem.resolutions->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->resolutions->data[i] = b_problem.resolutions->data[i];
    }

    emxCopyStruct_struct5_T(sp, &problem->calculations, &c_problem.calculations,
      &bg_emlrtRTEI);
    i = problem->allSubRough->size[0];
    problem->allSubRough->size[0] = b_problem.allSubRough->size[0];
    emxEnsureCapacity_real_T(sp, problem->allSubRough, i, &bg_emlrtRTEI);
    loop_ub = b_problem.allSubRough->size[0];
    emxFreeStruct_struct_T(&c_problem);
    for (i = 0; i < loop_ub; i++) {
      problem->allSubRough->data[i] = b_problem.allSubRough->data[i];
    }

    i = problem->resample->size[0] * problem->resample->size[1];
    problem->resample->size[0] = 1;
    problem->resample->size[1] = b_problem.resample->size[1];
    emxEnsureCapacity_real_T(sp, problem->resample, i, &ag_emlrtRTEI);
    loop_ub = b_problem.resample->size[0] * b_problem.resample->size[1];
    for (i = 0; i < loop_ub; i++) {
      problem->resample->data[i] = b_problem.resample->data[i];
    }
    break;
  }

  emxFreeStruct_struct_T(&b_problem);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_reflectivityCalculation.c) */
