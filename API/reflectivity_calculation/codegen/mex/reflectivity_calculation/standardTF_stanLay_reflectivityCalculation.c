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
#include "allocateLayersForContrast.h"
#include "allocateParamsToLayers.h"
#include "applyBackgroundCorrection.h"
#include "backSort.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "groupLayers_Mod.h"
#include "makeSLDProfiles.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_emxutil.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"
#include "standardTF_stanlay_paraContrasts.h"
#include "sum.h"

/* Variable Definitions */
static emlrtRSInfo c_emlrtRSI = { 91,  /* lineNo */
  "standardTF_stanLay_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 103, /* lineNo */
  "standardTF_stanLay_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 114, /* lineNo */
  "standardTF_stanLay_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 133, /* lineNo */
  "standardTF_stanLay_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 77,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 80,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 83,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 84,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 86,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 90,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 97,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 99,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 101, /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 107, /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo uf_emlrtRSI = { 77, /* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo vf_emlrtRSI = { 80, /* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo wf_emlrtRSI = { 83, /* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo xf_emlrtRSI = { 84, /* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo yf_emlrtRSI = { 86, /* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo ag_emlrtRSI = { 90, /* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo bg_emlrtRSI = { 97, /* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo cg_emlrtRSI = { 99, /* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo dg_emlrtRSI = { 101,/* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo eg_emlrtRSI = { 107,/* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  19,                                  /* colNo */
  "params",                            /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 56,  /* lineNo */
  21,                                  /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo s_emlrtRTEI = { 57,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 62,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 67,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 72,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 77,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 82,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 61,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 66,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 71,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 79,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  27,                                  /* colNo */
  "params",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  125,                                 /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo db_emlrtRTEI = { 61,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 66,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 71,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 79,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  27,                                  /* colNo */
  "params",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  125,                                 /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 45,  /* lineNo */
  16,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 45,  /* lineNo */
  16,                                  /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 126, /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 126, /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 127, /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 128, /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 129, /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = { 130, /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 52,  /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = { 131, /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = { 134, /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  78,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  72,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  82,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  93,                                  /* colNo */
  "cScales",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  104,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  113,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  122,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  6,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  16,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  27,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  50,                                  /* colNo */
  "resols",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  72,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  82,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  93,                                  /* colNo */
  "cScales",                           /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  104,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  113,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  122,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  6,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  16,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  27,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  50,                                  /* colNo */
  "resols",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  5,                                   /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  5,                                   /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  52,                                  /* colNo */
  "contrastLayers",                    /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  52,                                  /* colNo */
  "contrastLayers",                    /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  67,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  89,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  97,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  17,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  67,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  89,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  97,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  17,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  60,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  72,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  60,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  72,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  8,                                   /* colNo */
  "resample",                          /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo md_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  8,                                   /* colNo */
  "resample",                          /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  94,                                  /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo od_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  94,                                  /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  91,                                  /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  91,                                  /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  62,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  62,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  29,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  36,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  47,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  73,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  29,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  36,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  47,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo be_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  73,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ce_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  40,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo de_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  48,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ee_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  56,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  69,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ge_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  106,                                 /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo he_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  128,                                 /* colNo */
  "resols",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ie_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo je_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  40,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ke_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  48,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo le_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  56,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo me_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  69,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ne_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  106,                                 /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  128,                                 /* colNo */
  "resols",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  101,                                 /* lineNo */
  87,                                  /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo re_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  101,                                 /* lineNo */
  97,                                  /* colNo */
  "backsType",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo se_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  101,                                 /* lineNo */
  87,                                  /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo te_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  101,                                 /* lineNo */
  97,                                  /* colNo */
  "backsType",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ue_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ve_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo we_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ye_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  107,                                 /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo af_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  107,                                 /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo ie_emlrtRTEI = { 125,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo je_emlrtRTEI = { 126,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ke_emlrtRTEI = { 127,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo le_emlrtRTEI = { 128,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo me_emlrtRTEI = { 129,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ne_emlrtRTEI = { 130,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo oe_emlrtRTEI = { 52,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo pe_emlrtRTEI = { 131,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo qe_emlrtRTEI = { 134,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo re_emlrtRTEI = { 1,/* lineNo */
  91,                                  /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo se_emlrtRTEI = { 58,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo te_emlrtRTEI = { 63,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ue_emlrtRTEI = { 68,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ve_emlrtRTEI = { 73,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo we_emlrtRTEI = { 78,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo xe_emlrtRTEI = { 83,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ye_emlrtRTEI = { 132,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo af_emlrtRTEI = { 62,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo bf_emlrtRTEI = { 62,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo cf_emlrtRTEI = { 67,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo df_emlrtRTEI = { 67,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo ef_emlrtRTEI = { 72,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo ff_emlrtRTEI = { 72,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo gf_emlrtRTEI = { 87,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo hf_emlrtRTEI = { 87,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo if_emlrtRTEI = { 94,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo jf_emlrtRTEI = { 94,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo kf_emlrtRTEI = { 91,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo lf_emlrtRTEI = { 91,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo mf_emlrtRTEI = { 97,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo nf_emlrtRTEI = { 97,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo of_emlrtRTEI = { 103,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo pf_emlrtRTEI = { 103,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo qf_emlrtRTEI = { 105,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo rf_emlrtRTEI = { 105,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo sf_emlrtRTEI = { 77,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo tf_emlrtRTEI = { 83,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo uf_emlrtRTEI = { 86,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo vf_emlrtRTEI = { 90,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

/* Function Definitions */
void c_standardTF_stanLay_reflectivi(const emlrtStack *sp, const struct0_T
  *problemDef, const cell_11 *problemDef_cells, const struct2_T *controls,
  struct4_T *problem, emxArray_cell_wrap_6 *reflectivity, emxArray_cell_wrap_6
  *Simulation, emxArray_cell_wrap_1 *shifted_data, emxArray_cell_wrap_1
  *layerSlds, emxArray_cell_wrap_6 *sldProfiles, emxArray_cell_wrap_10
  *allLayers)
{
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  emxArray_real_T *chis;
  int32_T b_i;
  int32_T i2;
  boolean_T b_bool;
  int32_T kstr;
  int32_T exitg1;
  emxArray_real_T *backgs;
  static const char_T cv[6] = { 's', 'i', 'n', 'g', 'l', 'e' };

  emxArray_real_T *qshifts;
  emxArray_real_T *sfs;
  emxArray_real_T *nbas;
  static const char_T cv1[6] = { 'p', 'o', 'i', 'n', 't', 's' };

  emxArray_real_T *nbss;
  emxArray_real_T *resols;
  emxArray_real_T *allRoughs;
  emxArray_cell_wrap_13 *outParameterisedLayers;
  static const char_T cv2[9] = { 'c', 'o', 'n', 't', 'r', 'a', 's', 't', 's' };

  emxArray_real_T *thisContrastLayers;
  emxArray_real_T *sldProfile;
  emxArray_real_T *layerSld;
  emxArray_real_T *shifted_dat;
  int32_T i3;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
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
    emlrtDynamicBoundsCheckR2012b(1, 1, problemDef->params->size[1], &x_emlrtBCI,
      sp);
  }

  i = problem->ssubs->size[0];
  problem->ssubs->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->ssubs, i, &ie_emlrtRTEI);
  problem->ssubs->data[0] = problemDef->params->data[0];
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &j_emlrtDCI, sp);
  }

  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &i_emlrtDCI, sp);
  }

  i1 = problem->backgrounds->size[0];
  loop_ub = (int32_T)problemDef->numberOfContrasts;
  problem->backgrounds->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->backgrounds, i1, &je_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &i_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->backgrounds->data[i1] = 0.0;
  }

  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &k_emlrtDCI, sp);
  }

  loop_ub = (int32_T)problemDef->numberOfContrasts;
  i1 = problem->qshifts->size[0];
  problem->qshifts->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->qshifts, i1, &ke_emlrtRTEI);
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
  emxEnsureCapacity_real_T(sp, problem->scalefactors, i1, &le_emlrtRTEI);
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
  emxEnsureCapacity_real_T(sp, problem->nbairs, i1, &me_emlrtRTEI);
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
  emxEnsureCapacity_real_T(sp, problem->nbsubs, i1, &ne_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &n_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->nbsubs->data[i1] = 0.0;
  }

  emxInit_real_T(sp, &chis, 1, &oe_emlrtRTEI, true);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &o_emlrtDCI, sp);
  }

  i1 = chis->size[0];
  chis->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, chis, i1, &oe_emlrtRTEI);
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
  emxEnsureCapacity_real_T(sp, problem->resolutions, i1, &pe_emlrtRTEI);
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
  emxEnsureCapacity_real_T(sp, problem->allSubRough, i1, &qe_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &q_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->allSubRough->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &f_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &s_emlrtRTEI, sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, reflectivity, i1, &re_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &db_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &se_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &db_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &se_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &db_emlrtBCI, sp);
    }

    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &db_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &db_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &db_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &db_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &db_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &t_emlrtRTEI, sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, Simulation, i1, &re_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &eb_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &te_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &eb_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &te_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &eb_emlrtBCI, sp);
    }

    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &eb_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &eb_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &eb_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &eb_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &eb_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &u_emlrtRTEI, sp);
  i1 = shifted_data->size[0];
  shifted_data->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, shifted_data, i1, &re_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &fb_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i1, &ue_emlrtRTEI);
    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &fb_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i1, &ue_emlrtRTEI);
    i1 = shifted_data->size[0] - 1;
    i2 = shifted_data->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &fb_emlrtBCI, sp);
    }

    i2 = shifted_data->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &fb_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < 6; i2++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &fb_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[i2] = 1.0;
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &v_emlrtRTEI, sp);
  i1 = layerSlds->size[0];
  layerSlds->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, layerSlds, i1, &re_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = layerSlds->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &gb_emlrtBCI, sp);
    }

    i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &ve_emlrtRTEI);
    i1 = layerSlds->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &gb_emlrtBCI, sp);
    }

    i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &ve_emlrtRTEI);
    i1 = layerSlds->size[0] - 1;
    i2 = layerSlds->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &gb_emlrtBCI, sp);
    }

    i2 = layerSlds->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &gb_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < 6; i2++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &gb_emlrtBCI, sp);
      }

      layerSlds->data[b_i].f1->data[i2] = 1.0;
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &w_emlrtRTEI, sp);
  i1 = sldProfiles->size[0];
  sldProfiles->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, sldProfiles, i1, &re_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hb_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &we_emlrtRTEI);
    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hb_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &we_emlrtRTEI);
    i1 = sldProfiles->size[0] - 1;
    i2 = sldProfiles->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &hb_emlrtBCI, sp);
    }

    i2 = sldProfiles->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &hb_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hb_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hb_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hb_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hb_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[3] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &x_emlrtRTEI, sp);
  i1 = allLayers->size[0];
  allLayers->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_10(sp, allLayers, i1, &re_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = allLayers->size[0] - 1;
    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ib_emlrtBCI, sp);
    }

    i2 = allLayers->data[b_i].f1->size[0];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i2, &xe_emlrtRTEI);
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ib_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ib_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
  }

  b_bool = false;
  if (controls->para->size[1] == 6) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 6) {
        if (controls->para->data[kstr] != cv[kstr]) {
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
    b_bool = false;
    if (controls->para->size[1] == 6) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 6) {
          if (controls->para->data[kstr] != cv1[kstr]) {
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
      kstr = 1;
    } else {
      b_bool = false;
      if (controls->para->size[1] == 9) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr < 9) {
            if (controls->para->data[kstr] != cv2[kstr]) {
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
        kstr = 2;
      } else {
        kstr = -1;
      }
    }
  }

  emxInit_real_T(sp, &backgs, 1, &qe_emlrtRTEI, true);
  emxInit_real_T(sp, &qshifts, 1, &qe_emlrtRTEI, true);
  emxInit_real_T(sp, &sfs, 1, &qe_emlrtRTEI, true);
  emxInit_real_T(sp, &nbas, 1, &qe_emlrtRTEI, true);
  emxInit_real_T(sp, &nbss, 1, &qe_emlrtRTEI, true);
  emxInit_real_T(sp, &resols, 1, &qe_emlrtRTEI, true);
  emxInit_real_T(sp, &allRoughs, 1, &qe_emlrtRTEI, true);
  emxInit_cell_wrap_13(sp, &outParameterisedLayers, 2, &sf_emlrtRTEI, true);
  emxInit_real_T(sp, &thisContrastLayers, 2, &tf_emlrtRTEI, true);
  emxInit_real_T(sp, &sldProfile, 2, &uf_emlrtRTEI, true);
  emxInit_real_T(sp, &layerSld, 2, &vf_emlrtRTEI, true);
  emxInit_real_T(sp, &shifted_dat, 2, &mf_emlrtRTEI, true);
  switch (kstr) {
   case 0:
    st.site = &c_emlrtRSI;

    /* Pre-Allocation... */
    if ((int32_T)problemDef->numberOfContrasts != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &g_emlrtDCI, &st);
    }

    /*   */
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &y_emlrtRTEI, &st);
    i = reflectivity->size[0];
    reflectivity->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_6(&st, reflectivity, i, &qe_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = reflectivity->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &jb_emlrtBCI, &st);
      }

      i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->
        size[1];
      reflectivity->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i, &af_emlrtRTEI);
      i = reflectivity->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &jb_emlrtBCI, &st);
      }

      i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->
        size[1];
      reflectivity->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i, &af_emlrtRTEI);
      i = reflectivity->size[0] - 1;
      i1 = reflectivity->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &jb_emlrtBCI, &st);
      }

      i1 = reflectivity->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &jb_emlrtBCI, &st);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &jb_emlrtBCI, &st);
      }

      reflectivity->data[b_i].f1->data[0] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &jb_emlrtBCI, &st);
      }

      reflectivity->data[b_i].f1->data[1] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &jb_emlrtBCI, &st);
      }

      reflectivity->data[b_i].f1->data[2] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &jb_emlrtBCI, &st);
      }

      reflectivity->data[b_i].f1->data[3] = 1.0;
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &ab_emlrtRTEI, &st);
    i = Simulation->size[0];
    Simulation->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_6(&st, Simulation, i, &qe_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = Simulation->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &lb_emlrtBCI, &st);
      }

      i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
      Simulation->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, Simulation->data[b_i].f1, i, &cf_emlrtRTEI);
      i = Simulation->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &lb_emlrtBCI, &st);
      }

      i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
      Simulation->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, Simulation->data[b_i].f1, i, &cf_emlrtRTEI);
      i = Simulation->size[0] - 1;
      i1 = Simulation->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &lb_emlrtBCI, &st);
      }

      i1 = Simulation->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &lb_emlrtBCI, &st);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &lb_emlrtBCI, &st);
      }

      Simulation->data[b_i].f1->data[0] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &lb_emlrtBCI, &st);
      }

      Simulation->data[b_i].f1->data[1] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &lb_emlrtBCI, &st);
      }

      Simulation->data[b_i].f1->data[2] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &lb_emlrtBCI, &st);
      }

      Simulation->data[b_i].f1->data[3] = 1.0;
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &bb_emlrtRTEI, &st);
    i = allLayers->size[0];
    allLayers->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_10(&st, allLayers, i, &qe_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = allLayers->size[0] - 1;
      i1 = allLayers->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &nb_emlrtBCI, &st);
      }

      i1 = allLayers->data[b_i].f1->size[0];
      allLayers->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i1, &ef_emlrtRTEI);
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nb_emlrtBCI, &st);
      }

      allLayers->data[b_i].f1->data[0] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nb_emlrtBCI, &st);
      }

      allLayers->data[b_i].f1->data[1] = 1.0;
    }

    b_st.site = &g_emlrtRSI;
    allocateParamsToLayers(&b_st, problemDef->params, problemDef_cells->f6,
      outParameterisedLayers);
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &cb_emlrtRTEI, &st);
    i = backgs->size[0];
    backgs->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, backgs, i, &qe_emlrtRTEI);
    i = qshifts->size[0];
    qshifts->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, qshifts, i, &qe_emlrtRTEI);
    i = sfs->size[0];
    sfs->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, sfs, i, &qe_emlrtRTEI);
    i = nbas->size[0];
    nbas->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, nbas, i, &qe_emlrtRTEI);
    i = nbss->size[0];
    nbss->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, nbss, i, &qe_emlrtRTEI);
    i = resols->size[0];
    resols->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, resols, i, &qe_emlrtRTEI);
    i = allRoughs->size[0];
    allRoughs->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, allRoughs, i, &qe_emlrtRTEI);
    i = problem->ssubs->size[0];
    problem->ssubs->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, problem->ssubs, i, &qe_emlrtRTEI);
    i = sldProfiles->size[0];
    sldProfiles->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_6(&st, sldProfiles, i, &qe_emlrtRTEI);
    i = layerSlds->size[0];
    layerSlds->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_1(&st, layerSlds, i, &qe_emlrtRTEI);
    i = shifted_data->size[0];
    shifted_data->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_1(&st, shifted_data, i, &qe_emlrtRTEI);
    i = Simulation->size[0];
    Simulation->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_6(&st, Simulation, i, &qe_emlrtRTEI);
    i = reflectivity->size[0];
    reflectivity->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_6(&st, reflectivity, i, &qe_emlrtRTEI);
    i = chis->size[0];
    chis->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, chis, i, &qe_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = (int32_T)(b_i + 1U);
      if (i > problemDef->contrastBacks->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastBacks->size[1],
          &pb_emlrtBCI, &st);
      }

      if (i > problemDef->contrastShifts->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastShifts->size[1],
          &qb_emlrtBCI, &st);
      }

      if (i > problemDef->contrastScales->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastScales->size[1],
          &rb_emlrtBCI, &st);
      }

      if (i > problemDef->contrastNbas->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastNbas->size[1],
          &sb_emlrtBCI, &st);
      }

      if (i > problemDef->contrastNbss->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastNbss->size[1],
          &tb_emlrtBCI, &st);
      }

      if (i > problemDef->contrastRes->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastRes->size[1],
          &ub_emlrtBCI, &st);
      }

      if (i > backgs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &vb_emlrtBCI, &st);
      }

      if (i > qshifts->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, qshifts->size[0], &wb_emlrtBCI, &st);
      }

      if (i > sfs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, sfs->size[0], &xb_emlrtBCI, &st);
      }

      if (i > nbas->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, nbas->size[0], &yb_emlrtBCI, &st);
      }

      if (i > nbss->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, nbss->size[0], &ac_emlrtBCI, &st);
      }

      if (i > resols->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, resols->size[0], &bc_emlrtBCI, &st);
      }

      b_st.site = &h_emlrtRSI;
      backSort(&b_st, problemDef->contrastBacks->data[i - 1],
               problemDef->contrastShifts->data[i - 1],
               problemDef->contrastScales->data[i - 1], problemDef->
               contrastNbas->data[i - 1], problemDef->contrastNbss->data[i - 1],
               problemDef->contrastRes->data[i - 1], problemDef->backs,
               problemDef->shifts, problemDef->sf, problemDef->nba,
               problemDef->nbs, problemDef->res, &backgs->data[i - 1],
               &qshifts->data[i - 1], &sfs->data[i - 1], &nbas->data[i - 1],
               &nbss->data[i - 1], &resols->data[i - 1]);
      if (1 > problemDef->params->size[1]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, problemDef->params->size[1],
          &y_emlrtBCI, &st);
      }

      if (i > allRoughs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, allRoughs->size[0], &oc_emlrtBCI,
          &st);
      }

      allRoughs->data[i - 1] = problemDef->params->data[0];
      i = problemDef_cells->f5->size[1] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &qc_emlrtBCI, &st);
      }

      b_st.site = &i_emlrtRSI;
      allocateLayersForContrast(&b_st, problemDef_cells->f5->data[b_i].f1,
        outParameterisedLayers, thisContrastLayers);
      i = b_i + 1;
      if (i > allRoughs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, allRoughs->size[0], &sc_emlrtBCI,
          &st);
      }

      i1 = b_i + 1;
      if (i1 > nbas->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, nbas->size[0], &tc_emlrtBCI, &st);
      }

      i2 = b_i + 1;
      if (i2 > nbss->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, nbss->size[0], &uc_emlrtBCI, &st);
      }

      kstr = b_i + 1;
      if (kstr > problem->ssubs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(kstr, 1, problem->ssubs->size[0],
          &vc_emlrtBCI, &st);
      }

      b_st.site = &j_emlrtRSI;
      groupLayers_Mod(&b_st, thisContrastLayers, allRoughs->data[i - 1],
                      problemDef->geometry, nbas->data[i1 - 1], nbss->data[i2 -
                      1], layerSld, &problem->ssubs->data[kstr - 1]);
      i = b_i + 1;
      if (i > nbas->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, nbas->size[0], &bd_emlrtBCI, &st);
      }

      i1 = b_i + 1;
      if (i1 > nbss->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &cd_emlrtBCI, &st);
      }

      i2 = b_i + 1;
      if (i2 > problem->ssubs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, problem->ssubs->size[0],
          &dd_emlrtBCI, &st);
      }

      kstr = problemDef_cells->f1->size[1] - 1;
      if (b_i > kstr) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &ed_emlrtBCI, &st);
      }

      b_st.site = &k_emlrtRSI;
      makeSLDProfiles(&b_st, nbas->data[i - 1], nbss->data[i1 - 1], layerSld,
                      problem->ssubs->data[i2 - 1], problemDef_cells->f1->
                      data[b_i].f1, sldProfile);
      kstr = sldProfile->size[0] * sldProfile->size[1];
      i = sldProfiles->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &jd_emlrtBCI, &st);
      }

      i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
      sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
      emxEnsureCapacity_real_T(&st, sldProfiles->data[b_i].f1, i, &gf_emlrtRTEI);
      i = sldProfiles->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &jd_emlrtBCI, &st);
      }

      i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
      sldProfiles->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, sldProfiles->data[b_i].f1, i, &gf_emlrtRTEI);
      i = sldProfiles->size[0] - 1;
      i1 = sldProfiles->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &jd_emlrtBCI, &st);
      }

      i1 = sldProfiles->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &jd_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &jd_emlrtBCI, &st);
        }

        sldProfiles->data[b_i].f1->data[i1] = sldProfile->data[i1];
      }

      i = b_i + 1;
      if (i > problemDef->resample->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->resample->size[1],
          &ld_emlrtBCI, &st);
      }

      if (problemDef->resample->data[i - 1] == 1.0) {
        b_st.site = &l_emlrtRSI;
        resampleLayers(&b_st, sldProfile, layerSld);
        kstr = layerSld->size[0] * layerSld->size[1];
        i = layerSlds->size[0] - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &pd_emlrtBCI, &st);
        }

        i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
        layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
        emxEnsureCapacity_real_T(&st, layerSlds->data[b_i].f1, i, &kf_emlrtRTEI);
        i = layerSlds->size[0] - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &pd_emlrtBCI, &st);
        }

        i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
        layerSlds->data[b_i].f1->size[1] = 3;
        emxEnsureCapacity_real_T(&st, layerSlds->data[b_i].f1, i, &kf_emlrtRTEI);
        i = layerSlds->size[0] - 1;
        i1 = layerSlds->size[0] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pd_emlrtBCI, &st);
        }

        i1 = layerSlds->size[0] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pd_emlrtBCI, &st);
        }

        for (i1 = 0; i1 < kstr; i1++) {
          if (b_i > i) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &pd_emlrtBCI, &st);
          }

          layerSlds->data[b_i].f1->data[i1] = layerSld->data[i1];
        }
      } else {
        kstr = layerSld->size[0] * layerSld->size[1];
        i = layerSlds->size[0] - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nd_emlrtBCI, &st);
        }

        i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
        layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
        emxEnsureCapacity_real_T(&st, layerSlds->data[b_i].f1, i, &if_emlrtRTEI);
        i = layerSlds->size[0] - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nd_emlrtBCI, &st);
        }

        i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
        layerSlds->data[b_i].f1->size[1] = 3;
        emxEnsureCapacity_real_T(&st, layerSlds->data[b_i].f1, i, &if_emlrtRTEI);
        i = layerSlds->size[0] - 1;
        i1 = layerSlds->size[0] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &nd_emlrtBCI, &st);
        }

        i1 = layerSlds->size[0] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &nd_emlrtBCI, &st);
        }

        for (i1 = 0; i1 < kstr; i1++) {
          if (b_i > i) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nd_emlrtBCI, &st);
          }

          layerSlds->data[b_i].f1->data[i1] = layerSld->data[i1];
        }
      }

      i = problemDef_cells->f2->size[1] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &rd_emlrtBCI, &st);
      }

      i = shifted_dat->size[0] * shifted_dat->size[1];
      shifted_dat->size[0] = problemDef_cells->f2->data[b_i].f1->size[0];
      shifted_dat->size[1] = 3;
      emxEnsureCapacity_real_T(&st, shifted_dat, i, &mf_emlrtRTEI);
      i = problemDef_cells->f2->size[1] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &rd_emlrtBCI, &st);
      }

      i = problemDef_cells->f2->size[1] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &rd_emlrtBCI, &st);
      }

      kstr = problemDef_cells->f2->data[b_i].f1->size[0] * problemDef_cells->
        f2->data[b_i].f1->size[1];
      for (i = 0; i < kstr; i++) {
        i1 = problemDef_cells->f2->size[1] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &rd_emlrtBCI, &st);
        }

        i1 = problemDef_cells->f2->size[1] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &rd_emlrtBCI, &st);
        }

        i1 = problemDef_cells->f2->size[1] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &rd_emlrtBCI, &st);
        }

        shifted_dat->data[i] = problemDef_cells->f2->data[b_i].f1->data[i];
      }

      i = b_i + 1;
      if (i > sfs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, sfs->size[0], &td_emlrtBCI, &st);
      }

      i1 = b_i + 1;
      if (i1 > qshifts->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, qshifts->size[0], &ud_emlrtBCI, &st);
      }

      i2 = b_i + 1;
      if (i2 > problemDef->dataPresent->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, problemDef->dataPresent->size[1],
          &vd_emlrtBCI, &st);
      }

      kstr = problemDef_cells->f3->size[1] - 1;
      if (b_i > kstr) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &wd_emlrtBCI, &st);
      }

      b_st.site = &m_emlrtRSI;
      shiftdata(&b_st, sfs->data[i - 1], qshifts->data[i1 - 1],
                problemDef->dataPresent->data[i2 - 1], shifted_dat,
                problemDef_cells->f3->data[b_i].f1);
      i = b_i + 1;
      if (i > backgs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &ab_emlrtBCI, &st);
      }

      i = b_i + 1;
      if (i > nbas->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, nbas->size[0], &ce_emlrtBCI, &st);
      }

      i1 = b_i + 1;
      if (i1 > nbss->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &de_emlrtBCI, &st);
      }

      i2 = problemDef_cells->f4->size[1] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ee_emlrtBCI, &st);
      }

      i2 = problemDef_cells->f1->size[1] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &fe_emlrtBCI, &st);
      }

      i2 = b_i + 1;
      if (i2 > problem->ssubs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, problem->ssubs->size[0],
          &ge_emlrtBCI, &st);
      }

      kstr = b_i + 1;
      if (kstr > resols->size[0]) {
        emlrtDynamicBoundsCheckR2012b(kstr, 1, resols->size[0], &he_emlrtBCI,
          &st);
      }

      i3 = Simulation->size[0] - 1;
      if (b_i > i3) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &ie_emlrtBCI, &st);
      }

      b_st.site = &n_emlrtRSI;
      callReflectivity(&b_st, nbas->data[i - 1], nbss->data[i1 - 1],
                       problemDef_cells->f4->data[b_i].f1, problemDef_cells->
                       f1->data[b_i].f1, shifted_dat, layerSld, problem->
                       ssubs->data[i2 - 1], resols->data[kstr - 1], sldProfile,
                       Simulation->data[b_i].f1);
      i = Simulation->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ie_emlrtBCI, &st);
      }

      i = b_i + 1;
      if (i > backgs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &qe_emlrtBCI, &st);
      }

      i1 = b_i + 1;
      if (i1 > problemDef->contrastBacksType->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, problemDef->contrastBacksType->
          size[1], &re_emlrtBCI, &st);
      }

      b_st.site = &o_emlrtRSI;
      applyBackgroundCorrection(&b_st, sldProfile, Simulation->data[b_i].f1,
        shifted_dat, backgs->data[i - 1], problemDef->contrastBacksType->data[i1
        - 1]);
      kstr = sldProfile->size[0] * sldProfile->size[1];
      i = reflectivity->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ue_emlrtBCI, &st);
      }

      i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->
        size[1];
      reflectivity->data[b_i].f1->size[0] = sldProfile->size[0];
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i, &of_emlrtRTEI);
      i = reflectivity->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ue_emlrtBCI, &st);
      }

      i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->
        size[1];
      reflectivity->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i, &of_emlrtRTEI);
      i = reflectivity->size[0] - 1;
      i1 = reflectivity->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ue_emlrtBCI, &st);
      }

      i1 = reflectivity->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ue_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ue_emlrtBCI, &st);
        }

        reflectivity->data[b_i].f1->data[i1] = sldProfile->data[i1];
      }

      kstr = shifted_dat->size[0] * shifted_dat->size[1];
      i = shifted_data->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &we_emlrtBCI, &st);
      }

      i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->
        size[1];
      shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
      emxEnsureCapacity_real_T(&st, shifted_data->data[b_i].f1, i, &qf_emlrtRTEI);
      i = shifted_data->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &we_emlrtBCI, &st);
      }

      i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->
        size[1];
      shifted_data->data[b_i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(&st, shifted_data->data[b_i].f1, i, &qf_emlrtRTEI);
      i = shifted_data->size[0] - 1;
      i1 = shifted_data->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &we_emlrtBCI, &st);
      }

      i1 = shifted_data->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &we_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &we_emlrtBCI, &st);
        }

        shifted_data->data[b_i].f1->data[i1] = shifted_dat->data[i1];
      }

      i = b_i + 1;
      if (i > chis->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, chis->size[0], &ye_emlrtBCI, &st);
      }

      b_st.site = &p_emlrtRSI;
      chis->data[i - 1] = chiSquared(&b_st, shifted_dat, sldProfile,
        problemDef->params->size[1]);
    }

    i = problem->backgrounds->size[0];
    problem->backgrounds->size[0] = backgs->size[0];
    emxEnsureCapacity_real_T(sp, problem->backgrounds, i, &qe_emlrtRTEI);
    loop_ub = backgs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->backgrounds->data[i] = backgs->data[i];
    }

    i = problem->qshifts->size[0];
    problem->qshifts->size[0] = qshifts->size[0];
    emxEnsureCapacity_real_T(sp, problem->qshifts, i, &qe_emlrtRTEI);
    loop_ub = qshifts->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->qshifts->data[i] = qshifts->data[i];
    }

    i = problem->scalefactors->size[0];
    problem->scalefactors->size[0] = sfs->size[0];
    emxEnsureCapacity_real_T(sp, problem->scalefactors, i, &qe_emlrtRTEI);
    loop_ub = sfs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->scalefactors->data[i] = sfs->data[i];
    }

    i = problem->nbairs->size[0];
    problem->nbairs->size[0] = nbas->size[0];
    emxEnsureCapacity_real_T(sp, problem->nbairs, i, &qe_emlrtRTEI);
    loop_ub = nbas->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->nbairs->data[i] = nbas->data[i];
    }

    i = problem->nbsubs->size[0];
    problem->nbsubs->size[0] = nbss->size[0];
    emxEnsureCapacity_real_T(sp, problem->nbsubs, i, &qe_emlrtRTEI);
    loop_ub = nbss->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->nbsubs->data[i] = nbss->data[i];
    }

    i = problem->resolutions->size[0];
    problem->resolutions->size[0] = resols->size[0];
    emxEnsureCapacity_real_T(sp, problem->resolutions, i, &qe_emlrtRTEI);
    loop_ub = resols->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->resolutions->data[i] = resols->data[i];
    }

    i = problem->allSubRough->size[0];
    problem->allSubRough->size[0] = allRoughs->size[0];
    emxEnsureCapacity_real_T(sp, problem->allSubRough, i, &qe_emlrtRTEI);
    loop_ub = allRoughs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->allSubRough->data[i] = allRoughs->data[i];
    }
    break;

   case 1:
    st.site = &d_emlrtRSI;

    /* Pre-Allocation... */
    if ((int32_T)problemDef->numberOfContrasts != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &h_emlrtDCI, &st);
    }

    /*   */
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &db_emlrtRTEI, &st);
    i = reflectivity->size[0];
    reflectivity->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_6(&st, reflectivity, i, &qe_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = reflectivity->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &kb_emlrtBCI, &st);
      }

      i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->
        size[1];
      reflectivity->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i, &bf_emlrtRTEI);
      i = reflectivity->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &kb_emlrtBCI, &st);
      }

      i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->
        size[1];
      reflectivity->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i, &bf_emlrtRTEI);
      i = reflectivity->size[0] - 1;
      i1 = reflectivity->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &kb_emlrtBCI, &st);
      }

      i1 = reflectivity->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &kb_emlrtBCI, &st);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &kb_emlrtBCI, &st);
      }

      reflectivity->data[b_i].f1->data[0] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &kb_emlrtBCI, &st);
      }

      reflectivity->data[b_i].f1->data[1] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &kb_emlrtBCI, &st);
      }

      reflectivity->data[b_i].f1->data[2] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &kb_emlrtBCI, &st);
      }

      reflectivity->data[b_i].f1->data[3] = 1.0;
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &eb_emlrtRTEI, &st);
    i = Simulation->size[0];
    Simulation->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_6(&st, Simulation, i, &qe_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = Simulation->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &mb_emlrtBCI, &st);
      }

      i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
      Simulation->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, Simulation->data[b_i].f1, i, &df_emlrtRTEI);
      i = Simulation->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &mb_emlrtBCI, &st);
      }

      i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
      Simulation->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, Simulation->data[b_i].f1, i, &df_emlrtRTEI);
      i = Simulation->size[0] - 1;
      i1 = Simulation->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &mb_emlrtBCI, &st);
      }

      i1 = Simulation->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &mb_emlrtBCI, &st);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &mb_emlrtBCI, &st);
      }

      Simulation->data[b_i].f1->data[0] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &mb_emlrtBCI, &st);
      }

      Simulation->data[b_i].f1->data[1] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &mb_emlrtBCI, &st);
      }

      Simulation->data[b_i].f1->data[2] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &mb_emlrtBCI, &st);
      }

      Simulation->data[b_i].f1->data[3] = 1.0;
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &fb_emlrtRTEI, &st);
    i = allLayers->size[0];
    allLayers->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_10(&st, allLayers, i, &qe_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = allLayers->size[0] - 1;
      i1 = allLayers->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ob_emlrtBCI, &st);
      }

      i1 = allLayers->data[b_i].f1->size[0];
      allLayers->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i1, &ff_emlrtRTEI);
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ob_emlrtBCI, &st);
      }

      allLayers->data[b_i].f1->data[0] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ob_emlrtBCI, &st);
      }

      allLayers->data[b_i].f1->data[1] = 1.0;
    }

    b_st.site = &uf_emlrtRSI;
    allocateParamsToLayers(&b_st, problemDef->params, problemDef_cells->f6,
      outParameterisedLayers);
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &gb_emlrtRTEI, &st);
    i = backgs->size[0];
    backgs->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, backgs, i, &qe_emlrtRTEI);
    i = qshifts->size[0];
    qshifts->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, qshifts, i, &qe_emlrtRTEI);
    i = sfs->size[0];
    sfs->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, sfs, i, &qe_emlrtRTEI);
    i = nbas->size[0];
    nbas->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, nbas, i, &qe_emlrtRTEI);
    i = nbss->size[0];
    nbss->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, nbss, i, &qe_emlrtRTEI);
    i = resols->size[0];
    resols->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, resols, i, &qe_emlrtRTEI);
    i = allRoughs->size[0];
    allRoughs->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, allRoughs, i, &qe_emlrtRTEI);
    i = problem->ssubs->size[0];
    problem->ssubs->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, problem->ssubs, i, &qe_emlrtRTEI);
    i = sldProfiles->size[0];
    sldProfiles->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_6(&st, sldProfiles, i, &qe_emlrtRTEI);
    i = layerSlds->size[0];
    layerSlds->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_1(&st, layerSlds, i, &qe_emlrtRTEI);
    i = shifted_data->size[0];
    shifted_data->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_1(&st, shifted_data, i, &qe_emlrtRTEI);
    i = Simulation->size[0];
    Simulation->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_6(&st, Simulation, i, &qe_emlrtRTEI);
    i = reflectivity->size[0];
    reflectivity->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_6(&st, reflectivity, i, &qe_emlrtRTEI);
    i = chis->size[0];
    chis->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, chis, i, &qe_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = (int32_T)(b_i + 1U);
      if (i > problemDef->contrastBacks->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastBacks->size[1],
          &cc_emlrtBCI, &st);
      }

      if (i > problemDef->contrastShifts->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastShifts->size[1],
          &dc_emlrtBCI, &st);
      }

      if (i > problemDef->contrastScales->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastScales->size[1],
          &ec_emlrtBCI, &st);
      }

      if (i > problemDef->contrastNbas->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastNbas->size[1],
          &fc_emlrtBCI, &st);
      }

      if (i > problemDef->contrastNbss->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastNbss->size[1],
          &gc_emlrtBCI, &st);
      }

      if (i > problemDef->contrastRes->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastRes->size[1],
          &hc_emlrtBCI, &st);
      }

      if (i > backgs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &ic_emlrtBCI, &st);
      }

      if (i > qshifts->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, qshifts->size[0], &jc_emlrtBCI, &st);
      }

      if (i > sfs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, sfs->size[0], &kc_emlrtBCI, &st);
      }

      if (i > nbas->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, nbas->size[0], &lc_emlrtBCI, &st);
      }

      if (i > nbss->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, nbss->size[0], &mc_emlrtBCI, &st);
      }

      if (i > resols->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, resols->size[0], &nc_emlrtBCI, &st);
      }

      b_st.site = &vf_emlrtRSI;
      backSort(&b_st, problemDef->contrastBacks->data[i - 1],
               problemDef->contrastShifts->data[i - 1],
               problemDef->contrastScales->data[i - 1], problemDef->
               contrastNbas->data[i - 1], problemDef->contrastNbss->data[i - 1],
               problemDef->contrastRes->data[i - 1], problemDef->backs,
               problemDef->shifts, problemDef->sf, problemDef->nba,
               problemDef->nbs, problemDef->res, &backgs->data[i - 1],
               &qshifts->data[i - 1], &sfs->data[i - 1], &nbas->data[i - 1],
               &nbss->data[i - 1], &resols->data[i - 1]);
      if (1 > problemDef->params->size[1]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, problemDef->params->size[1],
          &bb_emlrtBCI, &st);
      }

      if (i > allRoughs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, allRoughs->size[0], &pc_emlrtBCI,
          &st);
      }

      allRoughs->data[i - 1] = problemDef->params->data[0];
      i = problemDef_cells->f5->size[1] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &rc_emlrtBCI, &st);
      }

      b_st.site = &wf_emlrtRSI;
      allocateLayersForContrast(&b_st, problemDef_cells->f5->data[b_i].f1,
        outParameterisedLayers, thisContrastLayers);
      i = b_i + 1;
      if (i > allRoughs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, allRoughs->size[0], &wc_emlrtBCI,
          &st);
      }

      i1 = b_i + 1;
      if (i1 > nbas->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, nbas->size[0], &xc_emlrtBCI, &st);
      }

      i2 = b_i + 1;
      if (i2 > nbss->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, nbss->size[0], &yc_emlrtBCI, &st);
      }

      kstr = b_i + 1;
      if (kstr > problem->ssubs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(kstr, 1, problem->ssubs->size[0],
          &ad_emlrtBCI, &st);
      }

      b_st.site = &xf_emlrtRSI;
      groupLayers_Mod(&b_st, thisContrastLayers, allRoughs->data[i - 1],
                      problemDef->geometry, nbas->data[i1 - 1], nbss->data[i2 -
                      1], layerSld, &problem->ssubs->data[kstr - 1]);
      i = b_i + 1;
      if (i > nbas->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, nbas->size[0], &fd_emlrtBCI, &st);
      }

      i1 = b_i + 1;
      if (i1 > nbss->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &gd_emlrtBCI, &st);
      }

      i2 = b_i + 1;
      if (i2 > problem->ssubs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, problem->ssubs->size[0],
          &hd_emlrtBCI, &st);
      }

      kstr = problemDef_cells->f1->size[1] - 1;
      if (b_i > kstr) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &id_emlrtBCI, &st);
      }

      b_st.site = &yf_emlrtRSI;
      makeSLDProfiles(&b_st, nbas->data[i - 1], nbss->data[i1 - 1], layerSld,
                      problem->ssubs->data[i2 - 1], problemDef_cells->f1->
                      data[b_i].f1, sldProfile);
      kstr = sldProfile->size[0] * sldProfile->size[1];
      i = sldProfiles->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &kd_emlrtBCI, &st);
      }

      i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
      sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
      emxEnsureCapacity_real_T(&st, sldProfiles->data[b_i].f1, i, &hf_emlrtRTEI);
      i = sldProfiles->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &kd_emlrtBCI, &st);
      }

      i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
      sldProfiles->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, sldProfiles->data[b_i].f1, i, &hf_emlrtRTEI);
      i = sldProfiles->size[0] - 1;
      i1 = sldProfiles->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &kd_emlrtBCI, &st);
      }

      i1 = sldProfiles->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &kd_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &kd_emlrtBCI, &st);
        }

        sldProfiles->data[b_i].f1->data[i1] = sldProfile->data[i1];
      }

      i = b_i + 1;
      if (i > problemDef->resample->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->resample->size[1],
          &md_emlrtBCI, &st);
      }

      if (problemDef->resample->data[i - 1] == 1.0) {
        b_st.site = &ag_emlrtRSI;
        resampleLayers(&b_st, sldProfile, layerSld);
        kstr = layerSld->size[0] * layerSld->size[1];
        i = layerSlds->size[0] - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &qd_emlrtBCI, &st);
        }

        i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
        layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
        emxEnsureCapacity_real_T(&st, layerSlds->data[b_i].f1, i, &lf_emlrtRTEI);
        i = layerSlds->size[0] - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &qd_emlrtBCI, &st);
        }

        i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
        layerSlds->data[b_i].f1->size[1] = 3;
        emxEnsureCapacity_real_T(&st, layerSlds->data[b_i].f1, i, &lf_emlrtRTEI);
        i = layerSlds->size[0] - 1;
        i1 = layerSlds->size[0] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &qd_emlrtBCI, &st);
        }

        i1 = layerSlds->size[0] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &qd_emlrtBCI, &st);
        }

        for (i1 = 0; i1 < kstr; i1++) {
          if (b_i > i) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &qd_emlrtBCI, &st);
          }

          layerSlds->data[b_i].f1->data[i1] = layerSld->data[i1];
        }
      } else {
        kstr = layerSld->size[0] * layerSld->size[1];
        i = layerSlds->size[0] - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &od_emlrtBCI, &st);
        }

        i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
        layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
        emxEnsureCapacity_real_T(&st, layerSlds->data[b_i].f1, i, &jf_emlrtRTEI);
        i = layerSlds->size[0] - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &od_emlrtBCI, &st);
        }

        i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
        layerSlds->data[b_i].f1->size[1] = 3;
        emxEnsureCapacity_real_T(&st, layerSlds->data[b_i].f1, i, &jf_emlrtRTEI);
        i = layerSlds->size[0] - 1;
        i1 = layerSlds->size[0] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &od_emlrtBCI, &st);
        }

        i1 = layerSlds->size[0] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &od_emlrtBCI, &st);
        }

        for (i1 = 0; i1 < kstr; i1++) {
          if (b_i > i) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &od_emlrtBCI, &st);
          }

          layerSlds->data[b_i].f1->data[i1] = layerSld->data[i1];
        }
      }

      i = problemDef_cells->f2->size[1] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &sd_emlrtBCI, &st);
      }

      i = shifted_dat->size[0] * shifted_dat->size[1];
      shifted_dat->size[0] = problemDef_cells->f2->data[b_i].f1->size[0];
      shifted_dat->size[1] = 3;
      emxEnsureCapacity_real_T(&st, shifted_dat, i, &nf_emlrtRTEI);
      i = problemDef_cells->f2->size[1] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &sd_emlrtBCI, &st);
      }

      i = problemDef_cells->f2->size[1] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &sd_emlrtBCI, &st);
      }

      kstr = problemDef_cells->f2->data[b_i].f1->size[0] * problemDef_cells->
        f2->data[b_i].f1->size[1];
      for (i = 0; i < kstr; i++) {
        i1 = problemDef_cells->f2->size[1] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &sd_emlrtBCI, &st);
        }

        i1 = problemDef_cells->f2->size[1] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &sd_emlrtBCI, &st);
        }

        i1 = problemDef_cells->f2->size[1] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &sd_emlrtBCI, &st);
        }

        shifted_dat->data[i] = problemDef_cells->f2->data[b_i].f1->data[i];
      }

      i = b_i + 1;
      if (i > sfs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, sfs->size[0], &xd_emlrtBCI, &st);
      }

      i1 = b_i + 1;
      if (i1 > qshifts->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, qshifts->size[0], &yd_emlrtBCI, &st);
      }

      i2 = b_i + 1;
      if (i2 > problemDef->dataPresent->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, problemDef->dataPresent->size[1],
          &ae_emlrtBCI, &st);
      }

      kstr = problemDef_cells->f3->size[1] - 1;
      if (b_i > kstr) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &be_emlrtBCI, &st);
      }

      b_st.site = &bg_emlrtRSI;
      shiftdata(&b_st, sfs->data[i - 1], qshifts->data[i1 - 1],
                problemDef->dataPresent->data[i2 - 1], shifted_dat,
                problemDef_cells->f3->data[b_i].f1);
      i = b_i + 1;
      if (i > backgs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &cb_emlrtBCI, &st);
      }

      i = b_i + 1;
      if (i > nbas->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, nbas->size[0], &je_emlrtBCI, &st);
      }

      i1 = b_i + 1;
      if (i1 > nbss->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &ke_emlrtBCI, &st);
      }

      i2 = problemDef_cells->f4->size[1] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &le_emlrtBCI, &st);
      }

      i2 = problemDef_cells->f1->size[1] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &me_emlrtBCI, &st);
      }

      i2 = b_i + 1;
      if (i2 > problem->ssubs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, problem->ssubs->size[0],
          &ne_emlrtBCI, &st);
      }

      kstr = b_i + 1;
      if (kstr > resols->size[0]) {
        emlrtDynamicBoundsCheckR2012b(kstr, 1, resols->size[0], &oe_emlrtBCI,
          &st);
      }

      i3 = Simulation->size[0] - 1;
      if (b_i > i3) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &pe_emlrtBCI, &st);
      }

      b_st.site = &cg_emlrtRSI;
      b_callReflectivity(&b_st, nbas->data[i - 1], nbss->data[i1 - 1],
                         problemDef_cells->f4->data[b_i].f1,
                         problemDef_cells->f1->data[b_i].f1, shifted_dat,
                         layerSld, problem->ssubs->data[i2 - 1], resols->
                         data[kstr - 1], sldProfile, Simulation->data[b_i].f1);
      i = Simulation->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &pe_emlrtBCI, &st);
      }

      i = b_i + 1;
      if (i > backgs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &se_emlrtBCI, &st);
      }

      i1 = b_i + 1;
      if (i1 > problemDef->contrastBacksType->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, problemDef->contrastBacksType->
          size[1], &te_emlrtBCI, &st);
      }

      b_st.site = &dg_emlrtRSI;
      applyBackgroundCorrection(&b_st, sldProfile, Simulation->data[b_i].f1,
        shifted_dat, backgs->data[i - 1], problemDef->contrastBacksType->data[i1
        - 1]);
      kstr = sldProfile->size[0] * sldProfile->size[1];
      i = reflectivity->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ve_emlrtBCI, &st);
      }

      i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->
        size[1];
      reflectivity->data[b_i].f1->size[0] = sldProfile->size[0];
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i, &pf_emlrtRTEI);
      i = reflectivity->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ve_emlrtBCI, &st);
      }

      i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->
        size[1];
      reflectivity->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i, &pf_emlrtRTEI);
      i = reflectivity->size[0] - 1;
      i1 = reflectivity->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ve_emlrtBCI, &st);
      }

      i1 = reflectivity->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ve_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ve_emlrtBCI, &st);
        }

        reflectivity->data[b_i].f1->data[i1] = sldProfile->data[i1];
      }

      kstr = shifted_dat->size[0] * shifted_dat->size[1];
      i = shifted_data->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xe_emlrtBCI, &st);
      }

      i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->
        size[1];
      shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
      emxEnsureCapacity_real_T(&st, shifted_data->data[b_i].f1, i, &rf_emlrtRTEI);
      i = shifted_data->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xe_emlrtBCI, &st);
      }

      i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->
        size[1];
      shifted_data->data[b_i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(&st, shifted_data->data[b_i].f1, i, &rf_emlrtRTEI);
      i = shifted_data->size[0] - 1;
      i1 = shifted_data->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &xe_emlrtBCI, &st);
      }

      i1 = shifted_data->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &xe_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xe_emlrtBCI, &st);
        }

        shifted_data->data[b_i].f1->data[i1] = shifted_dat->data[i1];
      }

      i = b_i + 1;
      if (i > chis->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, chis->size[0], &af_emlrtBCI, &st);
      }

      b_st.site = &eg_emlrtRSI;
      chis->data[i - 1] = chiSquared(&b_st, shifted_dat, sldProfile,
        problemDef->params->size[1]);
    }

    i = problem->backgrounds->size[0];
    problem->backgrounds->size[0] = backgs->size[0];
    emxEnsureCapacity_real_T(sp, problem->backgrounds, i, &qe_emlrtRTEI);
    loop_ub = backgs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->backgrounds->data[i] = backgs->data[i];
    }

    i = problem->qshifts->size[0];
    problem->qshifts->size[0] = qshifts->size[0];
    emxEnsureCapacity_real_T(sp, problem->qshifts, i, &qe_emlrtRTEI);
    loop_ub = qshifts->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->qshifts->data[i] = qshifts->data[i];
    }

    i = problem->scalefactors->size[0];
    problem->scalefactors->size[0] = sfs->size[0];
    emxEnsureCapacity_real_T(sp, problem->scalefactors, i, &qe_emlrtRTEI);
    loop_ub = sfs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->scalefactors->data[i] = sfs->data[i];
    }

    i = problem->nbairs->size[0];
    problem->nbairs->size[0] = nbas->size[0];
    emxEnsureCapacity_real_T(sp, problem->nbairs, i, &qe_emlrtRTEI);
    loop_ub = nbas->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->nbairs->data[i] = nbas->data[i];
    }

    i = problem->nbsubs->size[0];
    problem->nbsubs->size[0] = nbss->size[0];
    emxEnsureCapacity_real_T(sp, problem->nbsubs, i, &qe_emlrtRTEI);
    loop_ub = nbss->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->nbsubs->data[i] = nbss->data[i];
    }

    i = problem->resolutions->size[0];
    problem->resolutions->size[0] = resols->size[0];
    emxEnsureCapacity_real_T(sp, problem->resolutions, i, &qe_emlrtRTEI);
    loop_ub = resols->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->resolutions->data[i] = resols->data[i];
    }

    i = problem->allSubRough->size[0];
    problem->allSubRough->size[0] = allRoughs->size[0];
    emxEnsureCapacity_real_T(sp, problem->allSubRough, i, &qe_emlrtRTEI);
    loop_ub = allRoughs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->allSubRough->data[i] = allRoughs->data[i];
    }
    break;

   case 2:
    st.site = &e_emlrtRSI;
    c_standardTF_stanlay_paraContra(&st, problemDef->resample,
      problemDef->numberOfContrasts, problemDef->geometry, problemDef_cells->f1,
      problemDef->contrastBacks, problemDef->contrastShifts,
      problemDef->contrastScales, problemDef->contrastNbas,
      problemDef->contrastNbss, problemDef->contrastRes, problemDef->backs,
      problemDef->shifts, problemDef->sf, problemDef->nba, problemDef->nbs,
      problemDef->res, problemDef->dataPresent, problemDef_cells->f2,
      problemDef_cells->f3, problemDef_cells->f4, problemDef->params->size[1],
      problemDef->params, problemDef_cells->f5, problemDef_cells->f6,
      problemDef->contrastBacksType, problem->ssubs, problem->backgrounds,
      problem->qshifts, problem->scalefactors, problem->nbairs, problem->nbsubs,
      problem->resolutions, chis, reflectivity, Simulation, shifted_data,
      layerSlds, sldProfiles, allLayers, problem->allSubRough);
    break;
  }

  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&layerSld);
  emxFree_real_T(&sldProfile);
  emxFree_real_T(&thisContrastLayers);
  emxFree_cell_wrap_13(&outParameterisedLayers);
  emxFree_real_T(&allRoughs);
  emxFree_real_T(&resols);
  emxFree_real_T(&nbss);
  emxFree_real_T(&nbas);
  emxFree_real_T(&sfs);
  emxFree_real_T(&qshifts);
  emxFree_real_T(&backgs);
  i = problem->calculations.all_chis->size[0];
  problem->calculations.all_chis->size[0] = chis->size[0];
  emxEnsureCapacity_real_T(sp, problem->calculations.all_chis, i, &ye_emlrtRTEI);
  loop_ub = chis->size[0];
  for (i = 0; i < loop_ub; i++) {
    problem->calculations.all_chis->data[i] = chis->data[i];
  }

  st.site = &f_emlrtRSI;
  problem->calculations.sum_chi = sum(&st, chis);

  /* problem.calculations.reflectivity = reflectivity; */
  /* problem.calculations.Simulation = Simulation; */
  /* problem.shifted_data = shifted_data; */
  /* problem.layers = layerSlds; */
  /* problem.calculations.slds = sldProfiles; */
  /* problem.allLayers = allLayers; */
  emxFree_real_T(&chis);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_stanLay_reflectivityCalculation.c) */
