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
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"
#include "standardTF_stanlay_paraContrasts.h"
#include "sum.h"

/* Variable Definitions */
static emlrtRSInfo d_emlrtRSI = { 92,  /* lineNo */
  "standardTF_stanLay_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 104, /* lineNo */
  "standardTF_stanLay_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 116, /* lineNo */
  "standardTF_stanLay_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 135, /* lineNo */
  "standardTF_stanLay_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 78,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 81,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 84,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 85,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 93,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 101, /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 108, /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 110, /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 112, /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 118, /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo vf_emlrtRSI = { 78, /* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo wf_emlrtRSI = { 81, /* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo xf_emlrtRSI = { 84, /* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo yf_emlrtRSI = { 85, /* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo ag_emlrtRSI = { 93, /* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo bg_emlrtRSI = { 101,/* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo cg_emlrtRSI = { 108,/* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo dg_emlrtRSI = { 110,/* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo eg_emlrtRSI = { 112,/* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo fg_emlrtRSI = { 118,/* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  19,                                  /* colNo */
  "params",                            /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 57,  /* lineNo */
  21,                                  /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo s_emlrtRTEI = { 58,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 63,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 68,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 73,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 78,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 83,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 62,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 67,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 72,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 80,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  27,                                  /* colNo */
  "params",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  125,                                 /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo db_emlrtRTEI = { 62,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 67,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 72,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 80,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  27,                                  /* colNo */
  "params",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  125,                                 /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 46,  /* lineNo */
  16,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 46,  /* lineNo */
  16,                                  /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 128, /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 128, /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 129, /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 130, /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 131, /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = { 132, /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 53,  /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = { 133, /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = { 136, /* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  64,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  72,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  82,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  93,                                  /* colNo */
  "cScales",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  104,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  113,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  122,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  6,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  16,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  27,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  50,                                  /* colNo */
  "resols",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  72,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  82,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  93,                                  /* colNo */
  "cScales",                           /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  104,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  113,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  122,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  6,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  16,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  27,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  50,                                  /* colNo */
  "resols",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  5,                                   /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  5,                                   /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  52,                                  /* colNo */
  "contrastLayers",                    /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  52,                                  /* colNo */
  "contrastLayers",                    /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  67,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  89,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  97,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  17,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  67,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  89,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  97,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  17,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  8,                                   /* colNo */
  "resample",                          /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  8,                                   /* colNo */
  "resample",                          /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  38,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  46,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  64,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  76,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  38,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  46,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  64,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  76,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  98,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo md_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  98,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  100,                                 /* lineNo */
  8,                                   /* colNo */
  "resample",                          /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo od_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  100,                                 /* lineNo */
  8,                                   /* colNo */
  "resample",                          /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  62,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  62,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  29,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  36,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  47,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  73,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  29,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo be_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  36,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ce_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  47,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo de_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  73,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ee_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  40,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  48,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ge_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  56,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo he_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  69,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ie_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  106,                                 /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo je_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  128,                                 /* colNo */
  "resols",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ke_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  115,                                 /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo le_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  40,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo me_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  48,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ne_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  56,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  69,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  106,                                 /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  128,                                 /* colNo */
  "resols",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo re_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  115,                                 /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo se_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  112,                                 /* lineNo */
  87,                                  /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo te_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  112,                                 /* lineNo */
  97,                                  /* colNo */
  "backsType",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ue_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  112,                                 /* lineNo */
  87,                                  /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ve_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  112,                                 /* lineNo */
  97,                                  /* colNo */
  "backsType",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo we_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  114,                                 /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  114,                                 /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ye_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  116,                                 /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo af_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  116,                                 /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  118,                                 /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  118,                                 /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo kf_emlrtRTEI = { 127,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo lf_emlrtRTEI = { 128,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo mf_emlrtRTEI = { 129,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo nf_emlrtRTEI = { 130,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo of_emlrtRTEI = { 131,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo pf_emlrtRTEI = { 132,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo qf_emlrtRTEI = { 53,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo rf_emlrtRTEI = { 133,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo sf_emlrtRTEI = { 136,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo tf_emlrtRTEI = { 1,/* lineNo */
  91,                                  /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo uf_emlrtRTEI = { 59,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo vf_emlrtRTEI = { 64,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo wf_emlrtRTEI = { 69,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo xf_emlrtRTEI = { 74,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo yf_emlrtRTEI = { 79,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ag_emlrtRTEI = { 84,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo bg_emlrtRTEI = { 134,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo cg_emlrtRTEI = { 63,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo dg_emlrtRTEI = { 63,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo eg_emlrtRTEI = { 68,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo fg_emlrtRTEI = { 68,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo gg_emlrtRTEI = { 73,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo hg_emlrtRTEI = { 73,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo ig_emlrtRTEI = { 95,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo jg_emlrtRTEI = { 95,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo kg_emlrtRTEI = { 98,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo lg_emlrtRTEI = { 98,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo mg_emlrtRTEI = { 93,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo ng_emlrtRTEI = { 93,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo og_emlrtRTEI = { 105,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo pg_emlrtRTEI = { 105,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo qg_emlrtRTEI = { 102,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo rg_emlrtRTEI = { 102,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo sg_emlrtRTEI = { 108,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo tg_emlrtRTEI = { 108,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo ug_emlrtRTEI = { 114,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo vg_emlrtRTEI = { 114,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo wg_emlrtRTEI = { 116,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo xg_emlrtRTEI = { 116,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo yg_emlrtRTEI = { 78,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo ah_emlrtRTEI = { 84,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo bh_emlrtRTEI = { 101,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo ch_emlrtRTEI = { 93,/* lineNo */
  22,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

/* Function Definitions */
void c_standardTF_stanLay_reflectivi(const emlrtStack *sp, const struct0_T
  *problemDef, const cell_13 *problemDef_cells, const struct2_T *controls,
  struct4_T *problem, emxArray_cell_wrap_11 *reflectivity, emxArray_cell_wrap_6 *
  Simulation, emxArray_cell_wrap_1 *shifted_data, emxArray_cell_wrap_1
  *layerSlds, emxArray_cell_wrap_11 *sldProfiles, emxArray_cell_wrap_11
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
  static const char_T b_cv[6] = { 's', 'i', 'n', 'g', 'l', 'e' };

  emxArray_real_T *qshifts;
  emxArray_real_T *sfs;
  emxArray_real_T *nbas;
  static const char_T b_cv1[6] = { 'p', 'o', 'i', 'n', 't', 's' };

  emxArray_real_T *nbss;
  emxArray_real_T *resols;
  emxArray_real_T *allRoughs;
  emxArray_cell_wrap_17 *outParameterisedLayers;
  emxArray_real_T *thisContrastLayers;
  emxArray_real_T *sldProfile;
  emxArray_real_T *layerSld;
  emxArray_real_T *shifted_dat;
  emxArray_real_T *reflect;
  real_T thisCalcSld;
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
  emxEnsureCapacity_real_T(sp, problem->ssubs, i, &kf_emlrtRTEI);
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
  emxEnsureCapacity_real_T(sp, problem->backgrounds, i1, &lf_emlrtRTEI);
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
  emxEnsureCapacity_real_T(sp, problem->qshifts, i1, &mf_emlrtRTEI);
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
  emxEnsureCapacity_real_T(sp, problem->scalefactors, i1, &nf_emlrtRTEI);
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
  emxEnsureCapacity_real_T(sp, problem->nbairs, i1, &of_emlrtRTEI);
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
  emxEnsureCapacity_real_T(sp, problem->nbsubs, i1, &pf_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &n_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->nbsubs->data[i1] = 0.0;
  }

  emxInit_real_T(sp, &chis, 1, &qf_emlrtRTEI, true);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &o_emlrtDCI, sp);
  }

  i1 = chis->size[0];
  chis->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, chis, i1, &qf_emlrtRTEI);
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
  emxEnsureCapacity_real_T(sp, problem->resolutions, i1, &rf_emlrtRTEI);
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
  emxEnsureCapacity_real_T(sp, problem->allSubRough, i1, &sf_emlrtRTEI);
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
  emxEnsureCapacity_cell_wrap_111(sp, reflectivity, i1, &tf_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &db_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &uf_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &db_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &uf_emlrtRTEI);
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
  emxEnsureCapacity_cell_wrap_6(sp, Simulation, i1, &tf_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &eb_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &vf_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &eb_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &vf_emlrtRTEI);
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
  emxEnsureCapacity_cell_wrap_1(sp, shifted_data, i1, &tf_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &fb_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i1, &wf_emlrtRTEI);
    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &fb_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i1, &wf_emlrtRTEI);
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
  emxEnsureCapacity_cell_wrap_1(sp, layerSlds, i1, &tf_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = layerSlds->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &gb_emlrtBCI, sp);
    }

    i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &xf_emlrtRTEI);
    i1 = layerSlds->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &gb_emlrtBCI, sp);
    }

    i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &xf_emlrtRTEI);
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
  emxEnsureCapacity_cell_wrap_111(sp, sldProfiles, i1, &tf_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hb_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &yf_emlrtRTEI);
    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hb_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &yf_emlrtRTEI);
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
  emxEnsureCapacity_cell_wrap_111(sp, allLayers, i1, &tf_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ib_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &ag_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ib_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &ag_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ib_emlrtBCI, sp);
    }

    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ib_emlrtBCI, sp);
    }

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
        if (controls->para->data[kstr] != b_cv[kstr]) {
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
          if (controls->para->data[kstr] != b_cv1[kstr]) {
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
        kstr = 2;
      } else {
        kstr = -1;
      }
    }
  }

  emxInit_real_T(sp, &backgs, 1, &sf_emlrtRTEI, true);
  emxInit_real_T(sp, &qshifts, 1, &sf_emlrtRTEI, true);
  emxInit_real_T(sp, &sfs, 1, &sf_emlrtRTEI, true);
  emxInit_real_T(sp, &nbas, 1, &sf_emlrtRTEI, true);
  emxInit_real_T(sp, &nbss, 1, &sf_emlrtRTEI, true);
  emxInit_real_T(sp, &resols, 1, &sf_emlrtRTEI, true);
  emxInit_real_T(sp, &allRoughs, 1, &sf_emlrtRTEI, true);
  emxInit_cell_wrap_17(sp, &outParameterisedLayers, 2, &yg_emlrtRTEI, true);
  emxInit_real_T(sp, &thisContrastLayers, 2, &ah_emlrtRTEI, true);
  emxInit_real_T(sp, &sldProfile, 2, &mg_emlrtRTEI, true);
  emxInit_real_T(sp, &layerSld, 2, &bh_emlrtRTEI, true);
  emxInit_real_T(sp, &shifted_dat, 2, &sg_emlrtRTEI, true);
  emxInit_real_T(sp, &reflect, 2, &ch_emlrtRTEI, true);
  switch (kstr) {
   case 0:
    st.site = &d_emlrtRSI;

    /* Pre-Allocation... */
    if ((int32_T)problemDef->numberOfContrasts != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &g_emlrtDCI, &st);
    }

    /*   */
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &y_emlrtRTEI, &st);
    i = reflectivity->size[0];
    reflectivity->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_111(&st, reflectivity, i, &sf_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = reflectivity->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &jb_emlrtBCI, &st);
      }

      i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->
        size[1];
      reflectivity->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i, &cg_emlrtRTEI);
      i = reflectivity->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &jb_emlrtBCI, &st);
      }

      i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->
        size[1];
      reflectivity->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i, &cg_emlrtRTEI);
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
    emxEnsureCapacity_cell_wrap_6(&st, Simulation, i, &sf_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = Simulation->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &lb_emlrtBCI, &st);
      }

      i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
      Simulation->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, Simulation->data[b_i].f1, i, &eg_emlrtRTEI);
      i = Simulation->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &lb_emlrtBCI, &st);
      }

      i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
      Simulation->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, Simulation->data[b_i].f1, i, &eg_emlrtRTEI);
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
    emxEnsureCapacity_cell_wrap_111(&st, allLayers, i, &sf_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = allLayers->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nb_emlrtBCI, &st);
      }

      i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
      allLayers->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i, &gg_emlrtRTEI);
      i = allLayers->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nb_emlrtBCI, &st);
      }

      i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
      allLayers->data[b_i].f1->size[1] = 1;
      emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i, &gg_emlrtRTEI);
      i = allLayers->size[0] - 1;
      i1 = allLayers->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &nb_emlrtBCI, &st);
      }

      i1 = allLayers->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &nb_emlrtBCI, &st);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nb_emlrtBCI, &st);
      }

      allLayers->data[b_i].f1->data[0] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nb_emlrtBCI, &st);
      }

      allLayers->data[b_i].f1->data[1] = 1.0;
    }

    b_st.site = &h_emlrtRSI;
    allocateParamsToLayers(&b_st, problemDef->params, problemDef_cells->f6,
      outParameterisedLayers);
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &cb_emlrtRTEI, &st);
    i = backgs->size[0];
    backgs->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, backgs, i, &sf_emlrtRTEI);
    i = qshifts->size[0];
    qshifts->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, qshifts, i, &sf_emlrtRTEI);
    i = sfs->size[0];
    sfs->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, sfs, i, &sf_emlrtRTEI);
    i = nbas->size[0];
    nbas->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, nbas, i, &sf_emlrtRTEI);
    i = nbss->size[0];
    nbss->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, nbss, i, &sf_emlrtRTEI);
    i = resols->size[0];
    resols->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, resols, i, &sf_emlrtRTEI);
    i = allRoughs->size[0];
    allRoughs->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, allRoughs, i, &sf_emlrtRTEI);
    i = problem->ssubs->size[0];
    problem->ssubs->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, problem->ssubs, i, &sf_emlrtRTEI);
    i = sldProfiles->size[0];
    sldProfiles->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_111(&st, sldProfiles, i, &sf_emlrtRTEI);
    i = layerSlds->size[0];
    layerSlds->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_1(&st, layerSlds, i, &sf_emlrtRTEI);
    i = shifted_data->size[0];
    shifted_data->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_1(&st, shifted_data, i, &sf_emlrtRTEI);
    i = Simulation->size[0];
    Simulation->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_6(&st, Simulation, i, &sf_emlrtRTEI);
    i = reflectivity->size[0];
    reflectivity->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_111(&st, reflectivity, i, &sf_emlrtRTEI);
    i = chis->size[0];
    chis->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, chis, i, &sf_emlrtRTEI);
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

      b_st.site = &i_emlrtRSI;
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

      b_st.site = &j_emlrtRSI;
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

      b_st.site = &k_emlrtRSI;
      groupLayers_Mod(&b_st, thisContrastLayers, allRoughs->data[i - 1],
                      problemDef->geometry, nbas->data[i1 - 1], nbss->data[i2 -
                      1], layerSld, &problem->ssubs->data[kstr - 1]);
      thisCalcSld = controls->calcSld;
      i = b_i + 1;
      if (i > problemDef->resample->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->resample->size[1],
          &bd_emlrtBCI, &st);
      }

      if (problemDef->resample->data[i - 1] == 1.0) {
        thisCalcSld = 1.0;
      }

      if (thisCalcSld == 1.0) {
        i = b_i + 1;
        if (i > nbas->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i, 1, nbas->size[0], &dd_emlrtBCI, &st);
        }

        i1 = b_i + 1;
        if (i1 > nbss->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &ed_emlrtBCI, &st);
        }

        i2 = b_i + 1;
        if (i2 > problem->ssubs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, problem->ssubs->size[0],
            &fd_emlrtBCI, &st);
        }

        kstr = problemDef_cells->f1->size[1] - 1;
        if (b_i > kstr) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &gd_emlrtBCI, &st);
        }

        b_st.site = &l_emlrtRSI;
        makeSLDProfiles(&b_st, nbas->data[i - 1], nbss->data[i1 - 1], layerSld,
                        problem->ssubs->data[i2 - 1], problemDef_cells->f1->
                        data[b_i].f1, reflect);
        i = sldProfile->size[0] * sldProfile->size[1];
        sldProfile->size[0] = reflect->size[0];
        sldProfile->size[1] = 2;
        emxEnsureCapacity_real_T(&st, sldProfile, i, &mg_emlrtRTEI);
        kstr = reflect->size[0] * reflect->size[1];
        for (i = 0; i < kstr; i++) {
          sldProfile->data[i] = reflect->data[i];
        }
      } else {
        i = sldProfile->size[0] * sldProfile->size[1];
        sldProfile->size[0] = 1;
        sldProfile->size[1] = 3;
        emxEnsureCapacity_real_T(&st, sldProfile, i, &ig_emlrtRTEI);
        sldProfile->data[0] = 0.0;
        sldProfile->data[1] = 0.0;
        sldProfile->data[2] = 0.0;
      }

      kstr = sldProfile->size[0] * sldProfile->size[1];
      i = sldProfiles->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ld_emlrtBCI, &st);
      }

      i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
      sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
      emxEnsureCapacity_real_T(&st, sldProfiles->data[b_i].f1, i, &kg_emlrtRTEI);
      i = sldProfiles->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ld_emlrtBCI, &st);
      }

      i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
      sldProfiles->data[b_i].f1->size[1] = sldProfile->size[1];
      emxEnsureCapacity_real_T(&st, sldProfiles->data[b_i].f1, i, &kg_emlrtRTEI);
      i = sldProfiles->size[0] - 1;
      i1 = sldProfiles->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ld_emlrtBCI, &st);
      }

      i1 = sldProfiles->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ld_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ld_emlrtBCI, &st);
        }

        sldProfiles->data[b_i].f1->data[i1] = sldProfile->data[i1];
      }

      i = b_i + 1;
      if (i > problemDef->resample->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->resample->size[1],
          &nd_emlrtBCI, &st);
      }

      if (problemDef->resample->data[i - 1] == 1.0) {
        b_st.site = &m_emlrtRSI;
        resampleLayers(&b_st, sldProfile, layerSld);
        kstr = layerSld->size[0] * layerSld->size[1];
        i = layerSlds->size[0] - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &rd_emlrtBCI, &st);
        }

        i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
        layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
        emxEnsureCapacity_real_T(&st, layerSlds->data[b_i].f1, i, &qg_emlrtRTEI);
        i = layerSlds->size[0] - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &rd_emlrtBCI, &st);
        }

        i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
        layerSlds->data[b_i].f1->size[1] = 3;
        emxEnsureCapacity_real_T(&st, layerSlds->data[b_i].f1, i, &qg_emlrtRTEI);
        i = layerSlds->size[0] - 1;
        i1 = layerSlds->size[0] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &rd_emlrtBCI, &st);
        }

        i1 = layerSlds->size[0] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &rd_emlrtBCI, &st);
        }

        for (i1 = 0; i1 < kstr; i1++) {
          if (b_i > i) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &rd_emlrtBCI, &st);
          }

          layerSlds->data[b_i].f1->data[i1] = layerSld->data[i1];
        }
      } else {
        kstr = layerSld->size[0] * layerSld->size[1];
        i = layerSlds->size[0] - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &pd_emlrtBCI, &st);
        }

        i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
        layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
        emxEnsureCapacity_real_T(&st, layerSlds->data[b_i].f1, i, &og_emlrtRTEI);
        i = layerSlds->size[0] - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &pd_emlrtBCI, &st);
        }

        i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
        layerSlds->data[b_i].f1->size[1] = 3;
        emxEnsureCapacity_real_T(&st, layerSlds->data[b_i].f1, i, &og_emlrtRTEI);
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
      }

      i = problemDef_cells->f2->size[1] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &td_emlrtBCI, &st);
      }

      i = shifted_dat->size[0] * shifted_dat->size[1];
      shifted_dat->size[0] = problemDef_cells->f2->data[b_i].f1->size[0];
      shifted_dat->size[1] = 3;
      emxEnsureCapacity_real_T(&st, shifted_dat, i, &sg_emlrtRTEI);
      i = problemDef_cells->f2->size[1] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &td_emlrtBCI, &st);
      }

      i = problemDef_cells->f2->size[1] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &td_emlrtBCI, &st);
      }

      kstr = problemDef_cells->f2->data[b_i].f1->size[0] * problemDef_cells->
        f2->data[b_i].f1->size[1];
      for (i = 0; i < kstr; i++) {
        i1 = problemDef_cells->f2->size[1] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &td_emlrtBCI, &st);
        }

        i1 = problemDef_cells->f2->size[1] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &td_emlrtBCI, &st);
        }

        i1 = problemDef_cells->f2->size[1] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &td_emlrtBCI, &st);
        }

        shifted_dat->data[i] = problemDef_cells->f2->data[b_i].f1->data[i];
      }

      i = b_i + 1;
      if (i > sfs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, sfs->size[0], &vd_emlrtBCI, &st);
      }

      i1 = b_i + 1;
      if (i1 > qshifts->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, qshifts->size[0], &wd_emlrtBCI, &st);
      }

      i2 = b_i + 1;
      if (i2 > problemDef->dataPresent->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, problemDef->dataPresent->size[1],
          &xd_emlrtBCI, &st);
      }

      kstr = problemDef_cells->f3->size[1] - 1;
      if (b_i > kstr) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &yd_emlrtBCI, &st);
      }

      b_st.site = &n_emlrtRSI;
      shiftdata(&b_st, sfs->data[i - 1], qshifts->data[i1 - 1],
                problemDef->dataPresent->data[i2 - 1], shifted_dat,
                problemDef_cells->f3->data[b_i].f1);
      i = b_i + 1;
      if (i > backgs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &ab_emlrtBCI, &st);
      }

      i = b_i + 1;
      if (i > nbas->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, nbas->size[0], &ee_emlrtBCI, &st);
      }

      i1 = b_i + 1;
      if (i1 > nbss->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &fe_emlrtBCI, &st);
      }

      i2 = problemDef_cells->f4->size[1] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ge_emlrtBCI, &st);
      }

      i2 = problemDef_cells->f1->size[1] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &he_emlrtBCI, &st);
      }

      i2 = b_i + 1;
      if (i2 > problem->ssubs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, problem->ssubs->size[0],
          &ie_emlrtBCI, &st);
      }

      kstr = b_i + 1;
      if (kstr > resols->size[0]) {
        emlrtDynamicBoundsCheckR2012b(kstr, 1, resols->size[0], &je_emlrtBCI,
          &st);
      }

      i3 = Simulation->size[0] - 1;
      if (b_i > i3) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &ke_emlrtBCI, &st);
      }

      b_st.site = &o_emlrtRSI;
      callReflectivity(&b_st, nbas->data[i - 1], nbss->data[i1 - 1],
                       problemDef_cells->f4->data[b_i].f1, problemDef_cells->
                       f1->data[b_i].f1, shifted_dat, layerSld, problem->
                       ssubs->data[i2 - 1], resols->data[kstr - 1], reflect,
                       Simulation->data[b_i].f1);
      i = Simulation->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ke_emlrtBCI, &st);
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

      b_st.site = &p_emlrtRSI;
      applyBackgroundCorrection(&b_st, reflect, Simulation->data[b_i].f1,
        shifted_dat, backgs->data[i - 1], problemDef->contrastBacksType->data[i1
        - 1]);
      kstr = reflect->size[0] * reflect->size[1];
      i = reflectivity->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &we_emlrtBCI, &st);
      }

      i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->
        size[1];
      reflectivity->data[b_i].f1->size[0] = reflect->size[0];
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i, &ug_emlrtRTEI);
      i = reflectivity->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &we_emlrtBCI, &st);
      }

      i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->
        size[1];
      reflectivity->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i, &ug_emlrtRTEI);
      i = reflectivity->size[0] - 1;
      i1 = reflectivity->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &we_emlrtBCI, &st);
      }

      i1 = reflectivity->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &we_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &we_emlrtBCI, &st);
        }

        reflectivity->data[b_i].f1->data[i1] = reflect->data[i1];
      }

      kstr = shifted_dat->size[0] * shifted_dat->size[1];
      i = shifted_data->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ye_emlrtBCI, &st);
      }

      i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->
        size[1];
      shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
      emxEnsureCapacity_real_T(&st, shifted_data->data[b_i].f1, i, &wg_emlrtRTEI);
      i = shifted_data->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ye_emlrtBCI, &st);
      }

      i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->
        size[1];
      shifted_data->data[b_i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(&st, shifted_data->data[b_i].f1, i, &wg_emlrtRTEI);
      i = shifted_data->size[0] - 1;
      i1 = shifted_data->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ye_emlrtBCI, &st);
      }

      i1 = shifted_data->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ye_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ye_emlrtBCI, &st);
        }

        shifted_data->data[b_i].f1->data[i1] = shifted_dat->data[i1];
      }

      i = b_i + 1;
      if (i > chis->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, chis->size[0], &bf_emlrtBCI, &st);
      }

      b_st.site = &q_emlrtRSI;
      chis->data[i - 1] = chiSquared(&b_st, shifted_dat, reflect,
        problemDef->params->size[1]);
    }

    i = problem->backgrounds->size[0];
    problem->backgrounds->size[0] = backgs->size[0];
    emxEnsureCapacity_real_T(sp, problem->backgrounds, i, &sf_emlrtRTEI);
    loop_ub = backgs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->backgrounds->data[i] = backgs->data[i];
    }

    i = problem->qshifts->size[0];
    problem->qshifts->size[0] = qshifts->size[0];
    emxEnsureCapacity_real_T(sp, problem->qshifts, i, &sf_emlrtRTEI);
    loop_ub = qshifts->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->qshifts->data[i] = qshifts->data[i];
    }

    i = problem->scalefactors->size[0];
    problem->scalefactors->size[0] = sfs->size[0];
    emxEnsureCapacity_real_T(sp, problem->scalefactors, i, &sf_emlrtRTEI);
    loop_ub = sfs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->scalefactors->data[i] = sfs->data[i];
    }

    i = problem->nbairs->size[0];
    problem->nbairs->size[0] = nbas->size[0];
    emxEnsureCapacity_real_T(sp, problem->nbairs, i, &sf_emlrtRTEI);
    loop_ub = nbas->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->nbairs->data[i] = nbas->data[i];
    }

    i = problem->nbsubs->size[0];
    problem->nbsubs->size[0] = nbss->size[0];
    emxEnsureCapacity_real_T(sp, problem->nbsubs, i, &sf_emlrtRTEI);
    loop_ub = nbss->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->nbsubs->data[i] = nbss->data[i];
    }

    i = problem->resolutions->size[0];
    problem->resolutions->size[0] = resols->size[0];
    emxEnsureCapacity_real_T(sp, problem->resolutions, i, &sf_emlrtRTEI);
    loop_ub = resols->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->resolutions->data[i] = resols->data[i];
    }

    i = problem->allSubRough->size[0];
    problem->allSubRough->size[0] = allRoughs->size[0];
    emxEnsureCapacity_real_T(sp, problem->allSubRough, i, &sf_emlrtRTEI);
    loop_ub = allRoughs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->allSubRough->data[i] = allRoughs->data[i];
    }
    break;

   case 1:
    st.site = &e_emlrtRSI;

    /* Pre-Allocation... */
    if ((int32_T)problemDef->numberOfContrasts != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &h_emlrtDCI, &st);
    }

    /*   */
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &db_emlrtRTEI, &st);
    i = reflectivity->size[0];
    reflectivity->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_111(&st, reflectivity, i, &sf_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = reflectivity->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &kb_emlrtBCI, &st);
      }

      i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->
        size[1];
      reflectivity->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i, &dg_emlrtRTEI);
      i = reflectivity->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &kb_emlrtBCI, &st);
      }

      i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->
        size[1];
      reflectivity->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i, &dg_emlrtRTEI);
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
    emxEnsureCapacity_cell_wrap_6(&st, Simulation, i, &sf_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = Simulation->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &mb_emlrtBCI, &st);
      }

      i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
      Simulation->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, Simulation->data[b_i].f1, i, &fg_emlrtRTEI);
      i = Simulation->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &mb_emlrtBCI, &st);
      }

      i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
      Simulation->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, Simulation->data[b_i].f1, i, &fg_emlrtRTEI);
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
    emxEnsureCapacity_cell_wrap_111(&st, allLayers, i, &sf_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = allLayers->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ob_emlrtBCI, &st);
      }

      i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
      allLayers->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i, &hg_emlrtRTEI);
      i = allLayers->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ob_emlrtBCI, &st);
      }

      i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
      allLayers->data[b_i].f1->size[1] = 1;
      emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i, &hg_emlrtRTEI);
      i = allLayers->size[0] - 1;
      i1 = allLayers->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ob_emlrtBCI, &st);
      }

      i1 = allLayers->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ob_emlrtBCI, &st);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ob_emlrtBCI, &st);
      }

      allLayers->data[b_i].f1->data[0] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ob_emlrtBCI, &st);
      }

      allLayers->data[b_i].f1->data[1] = 1.0;
    }

    b_st.site = &vf_emlrtRSI;
    allocateParamsToLayers(&b_st, problemDef->params, problemDef_cells->f6,
      outParameterisedLayers);
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &gb_emlrtRTEI, &st);
    i = backgs->size[0];
    backgs->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, backgs, i, &sf_emlrtRTEI);
    i = qshifts->size[0];
    qshifts->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, qshifts, i, &sf_emlrtRTEI);
    i = sfs->size[0];
    sfs->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, sfs, i, &sf_emlrtRTEI);
    i = nbas->size[0];
    nbas->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, nbas, i, &sf_emlrtRTEI);
    i = nbss->size[0];
    nbss->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, nbss, i, &sf_emlrtRTEI);
    i = resols->size[0];
    resols->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, resols, i, &sf_emlrtRTEI);
    i = allRoughs->size[0];
    allRoughs->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, allRoughs, i, &sf_emlrtRTEI);
    i = problem->ssubs->size[0];
    problem->ssubs->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, problem->ssubs, i, &sf_emlrtRTEI);
    i = sldProfiles->size[0];
    sldProfiles->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_111(&st, sldProfiles, i, &sf_emlrtRTEI);
    i = layerSlds->size[0];
    layerSlds->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_1(&st, layerSlds, i, &sf_emlrtRTEI);
    i = shifted_data->size[0];
    shifted_data->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_1(&st, shifted_data, i, &sf_emlrtRTEI);
    i = Simulation->size[0];
    Simulation->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_6(&st, Simulation, i, &sf_emlrtRTEI);
    i = reflectivity->size[0];
    reflectivity->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_111(&st, reflectivity, i, &sf_emlrtRTEI);
    i = chis->size[0];
    chis->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, chis, i, &sf_emlrtRTEI);
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

      b_st.site = &wf_emlrtRSI;
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

      b_st.site = &xf_emlrtRSI;
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

      b_st.site = &yf_emlrtRSI;
      groupLayers_Mod(&b_st, thisContrastLayers, allRoughs->data[i - 1],
                      problemDef->geometry, nbas->data[i1 - 1], nbss->data[i2 -
                      1], layerSld, &problem->ssubs->data[kstr - 1]);
      thisCalcSld = controls->calcSld;
      i = b_i + 1;
      if (i > problemDef->resample->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->resample->size[1],
          &cd_emlrtBCI, &st);
      }

      if (problemDef->resample->data[i - 1] == 1.0) {
        thisCalcSld = 1.0;
      }

      if (thisCalcSld == 1.0) {
        i = b_i + 1;
        if (i > nbas->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i, 1, nbas->size[0], &hd_emlrtBCI, &st);
        }

        i1 = b_i + 1;
        if (i1 > nbss->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &id_emlrtBCI, &st);
        }

        i2 = b_i + 1;
        if (i2 > problem->ssubs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, problem->ssubs->size[0],
            &jd_emlrtBCI, &st);
        }

        kstr = problemDef_cells->f1->size[1] - 1;
        if (b_i > kstr) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &kd_emlrtBCI, &st);
        }

        b_st.site = &ag_emlrtRSI;
        makeSLDProfiles(&b_st, nbas->data[i - 1], nbss->data[i1 - 1], layerSld,
                        problem->ssubs->data[i2 - 1], problemDef_cells->f1->
                        data[b_i].f1, reflect);
        i = sldProfile->size[0] * sldProfile->size[1];
        sldProfile->size[0] = reflect->size[0];
        sldProfile->size[1] = 2;
        emxEnsureCapacity_real_T(&st, sldProfile, i, &ng_emlrtRTEI);
        kstr = reflect->size[0] * reflect->size[1];
        for (i = 0; i < kstr; i++) {
          sldProfile->data[i] = reflect->data[i];
        }
      } else {
        i = sldProfile->size[0] * sldProfile->size[1];
        sldProfile->size[0] = 1;
        sldProfile->size[1] = 3;
        emxEnsureCapacity_real_T(&st, sldProfile, i, &jg_emlrtRTEI);
        sldProfile->data[0] = 0.0;
        sldProfile->data[1] = 0.0;
        sldProfile->data[2] = 0.0;
      }

      kstr = sldProfile->size[0] * sldProfile->size[1];
      i = sldProfiles->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &md_emlrtBCI, &st);
      }

      i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
      sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
      emxEnsureCapacity_real_T(&st, sldProfiles->data[b_i].f1, i, &lg_emlrtRTEI);
      i = sldProfiles->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &md_emlrtBCI, &st);
      }

      i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
      sldProfiles->data[b_i].f1->size[1] = sldProfile->size[1];
      emxEnsureCapacity_real_T(&st, sldProfiles->data[b_i].f1, i, &lg_emlrtRTEI);
      i = sldProfiles->size[0] - 1;
      i1 = sldProfiles->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &md_emlrtBCI, &st);
      }

      i1 = sldProfiles->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &md_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &md_emlrtBCI, &st);
        }

        sldProfiles->data[b_i].f1->data[i1] = sldProfile->data[i1];
      }

      i = b_i + 1;
      if (i > problemDef->resample->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->resample->size[1],
          &od_emlrtBCI, &st);
      }

      if (problemDef->resample->data[i - 1] == 1.0) {
        b_st.site = &bg_emlrtRSI;
        resampleLayers(&b_st, sldProfile, layerSld);
        kstr = layerSld->size[0] * layerSld->size[1];
        i = layerSlds->size[0] - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &sd_emlrtBCI, &st);
        }

        i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
        layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
        emxEnsureCapacity_real_T(&st, layerSlds->data[b_i].f1, i, &rg_emlrtRTEI);
        i = layerSlds->size[0] - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &sd_emlrtBCI, &st);
        }

        i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
        layerSlds->data[b_i].f1->size[1] = 3;
        emxEnsureCapacity_real_T(&st, layerSlds->data[b_i].f1, i, &rg_emlrtRTEI);
        i = layerSlds->size[0] - 1;
        i1 = layerSlds->size[0] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &sd_emlrtBCI, &st);
        }

        i1 = layerSlds->size[0] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &sd_emlrtBCI, &st);
        }

        for (i1 = 0; i1 < kstr; i1++) {
          if (b_i > i) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &sd_emlrtBCI, &st);
          }

          layerSlds->data[b_i].f1->data[i1] = layerSld->data[i1];
        }
      } else {
        kstr = layerSld->size[0] * layerSld->size[1];
        i = layerSlds->size[0] - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &qd_emlrtBCI, &st);
        }

        i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
        layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
        emxEnsureCapacity_real_T(&st, layerSlds->data[b_i].f1, i, &pg_emlrtRTEI);
        i = layerSlds->size[0] - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &qd_emlrtBCI, &st);
        }

        i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
        layerSlds->data[b_i].f1->size[1] = 3;
        emxEnsureCapacity_real_T(&st, layerSlds->data[b_i].f1, i, &pg_emlrtRTEI);
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
      }

      i = problemDef_cells->f2->size[1] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ud_emlrtBCI, &st);
      }

      i = shifted_dat->size[0] * shifted_dat->size[1];
      shifted_dat->size[0] = problemDef_cells->f2->data[b_i].f1->size[0];
      shifted_dat->size[1] = 3;
      emxEnsureCapacity_real_T(&st, shifted_dat, i, &tg_emlrtRTEI);
      i = problemDef_cells->f2->size[1] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ud_emlrtBCI, &st);
      }

      i = problemDef_cells->f2->size[1] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ud_emlrtBCI, &st);
      }

      kstr = problemDef_cells->f2->data[b_i].f1->size[0] * problemDef_cells->
        f2->data[b_i].f1->size[1];
      for (i = 0; i < kstr; i++) {
        i1 = problemDef_cells->f2->size[1] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ud_emlrtBCI, &st);
        }

        i1 = problemDef_cells->f2->size[1] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ud_emlrtBCI, &st);
        }

        i1 = problemDef_cells->f2->size[1] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ud_emlrtBCI, &st);
        }

        shifted_dat->data[i] = problemDef_cells->f2->data[b_i].f1->data[i];
      }

      i = b_i + 1;
      if (i > sfs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, sfs->size[0], &ae_emlrtBCI, &st);
      }

      i1 = b_i + 1;
      if (i1 > qshifts->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, qshifts->size[0], &be_emlrtBCI, &st);
      }

      i2 = b_i + 1;
      if (i2 > problemDef->dataPresent->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, problemDef->dataPresent->size[1],
          &ce_emlrtBCI, &st);
      }

      kstr = problemDef_cells->f3->size[1] - 1;
      if (b_i > kstr) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &de_emlrtBCI, &st);
      }

      b_st.site = &cg_emlrtRSI;
      shiftdata(&b_st, sfs->data[i - 1], qshifts->data[i1 - 1],
                problemDef->dataPresent->data[i2 - 1], shifted_dat,
                problemDef_cells->f3->data[b_i].f1);
      i = b_i + 1;
      if (i > backgs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &cb_emlrtBCI, &st);
      }

      i = b_i + 1;
      if (i > nbas->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, nbas->size[0], &le_emlrtBCI, &st);
      }

      i1 = b_i + 1;
      if (i1 > nbss->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &me_emlrtBCI, &st);
      }

      i2 = problemDef_cells->f4->size[1] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ne_emlrtBCI, &st);
      }

      i2 = problemDef_cells->f1->size[1] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &oe_emlrtBCI, &st);
      }

      i2 = b_i + 1;
      if (i2 > problem->ssubs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, problem->ssubs->size[0],
          &pe_emlrtBCI, &st);
      }

      kstr = b_i + 1;
      if (kstr > resols->size[0]) {
        emlrtDynamicBoundsCheckR2012b(kstr, 1, resols->size[0], &qe_emlrtBCI,
          &st);
      }

      i3 = Simulation->size[0] - 1;
      if (b_i > i3) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &re_emlrtBCI, &st);
      }

      b_st.site = &dg_emlrtRSI;
      b_callReflectivity(&b_st, nbas->data[i - 1], nbss->data[i1 - 1],
                         problemDef_cells->f4->data[b_i].f1,
                         problemDef_cells->f1->data[b_i].f1, shifted_dat,
                         layerSld, problem->ssubs->data[i2 - 1], resols->
                         data[kstr - 1], reflect, Simulation->data[b_i].f1);
      i = Simulation->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &re_emlrtBCI, &st);
      }

      i = b_i + 1;
      if (i > backgs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &ue_emlrtBCI, &st);
      }

      i1 = b_i + 1;
      if (i1 > problemDef->contrastBacksType->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, problemDef->contrastBacksType->
          size[1], &ve_emlrtBCI, &st);
      }

      b_st.site = &eg_emlrtRSI;
      applyBackgroundCorrection(&b_st, reflect, Simulation->data[b_i].f1,
        shifted_dat, backgs->data[i - 1], problemDef->contrastBacksType->data[i1
        - 1]);
      kstr = reflect->size[0] * reflect->size[1];
      i = reflectivity->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xe_emlrtBCI, &st);
      }

      i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->
        size[1];
      reflectivity->data[b_i].f1->size[0] = reflect->size[0];
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i, &vg_emlrtRTEI);
      i = reflectivity->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xe_emlrtBCI, &st);
      }

      i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->
        size[1];
      reflectivity->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i, &vg_emlrtRTEI);
      i = reflectivity->size[0] - 1;
      i1 = reflectivity->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &xe_emlrtBCI, &st);
      }

      i1 = reflectivity->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &xe_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xe_emlrtBCI, &st);
        }

        reflectivity->data[b_i].f1->data[i1] = reflect->data[i1];
      }

      kstr = shifted_dat->size[0] * shifted_dat->size[1];
      i = shifted_data->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &af_emlrtBCI, &st);
      }

      i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->
        size[1];
      shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
      emxEnsureCapacity_real_T(&st, shifted_data->data[b_i].f1, i, &xg_emlrtRTEI);
      i = shifted_data->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &af_emlrtBCI, &st);
      }

      i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->
        size[1];
      shifted_data->data[b_i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(&st, shifted_data->data[b_i].f1, i, &xg_emlrtRTEI);
      i = shifted_data->size[0] - 1;
      i1 = shifted_data->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &af_emlrtBCI, &st);
      }

      i1 = shifted_data->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &af_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &af_emlrtBCI, &st);
        }

        shifted_data->data[b_i].f1->data[i1] = shifted_dat->data[i1];
      }

      i = b_i + 1;
      if (i > chis->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, chis->size[0], &cf_emlrtBCI, &st);
      }

      b_st.site = &fg_emlrtRSI;
      chis->data[i - 1] = chiSquared(&b_st, shifted_dat, reflect,
        problemDef->params->size[1]);
    }

    i = problem->backgrounds->size[0];
    problem->backgrounds->size[0] = backgs->size[0];
    emxEnsureCapacity_real_T(sp, problem->backgrounds, i, &sf_emlrtRTEI);
    loop_ub = backgs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->backgrounds->data[i] = backgs->data[i];
    }

    i = problem->qshifts->size[0];
    problem->qshifts->size[0] = qshifts->size[0];
    emxEnsureCapacity_real_T(sp, problem->qshifts, i, &sf_emlrtRTEI);
    loop_ub = qshifts->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->qshifts->data[i] = qshifts->data[i];
    }

    i = problem->scalefactors->size[0];
    problem->scalefactors->size[0] = sfs->size[0];
    emxEnsureCapacity_real_T(sp, problem->scalefactors, i, &sf_emlrtRTEI);
    loop_ub = sfs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->scalefactors->data[i] = sfs->data[i];
    }

    i = problem->nbairs->size[0];
    problem->nbairs->size[0] = nbas->size[0];
    emxEnsureCapacity_real_T(sp, problem->nbairs, i, &sf_emlrtRTEI);
    loop_ub = nbas->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->nbairs->data[i] = nbas->data[i];
    }

    i = problem->nbsubs->size[0];
    problem->nbsubs->size[0] = nbss->size[0];
    emxEnsureCapacity_real_T(sp, problem->nbsubs, i, &sf_emlrtRTEI);
    loop_ub = nbss->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->nbsubs->data[i] = nbss->data[i];
    }

    i = problem->resolutions->size[0];
    problem->resolutions->size[0] = resols->size[0];
    emxEnsureCapacity_real_T(sp, problem->resolutions, i, &sf_emlrtRTEI);
    loop_ub = resols->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->resolutions->data[i] = resols->data[i];
    }

    i = problem->allSubRough->size[0];
    problem->allSubRough->size[0] = allRoughs->size[0];
    emxEnsureCapacity_real_T(sp, problem->allSubRough, i, &sf_emlrtRTEI);
    loop_ub = allRoughs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->allSubRough->data[i] = allRoughs->data[i];
    }
    break;

   case 2:
    st.site = &f_emlrtRSI;
    c_standardTF_stanlay_paraContra(&st, problemDef->resample,
      problemDef->numberOfContrasts, problemDef->geometry, problemDef_cells->f1,
      problemDef->contrastBacks, problemDef->contrastShifts,
      problemDef->contrastScales, problemDef->contrastNbas,
      problemDef->contrastNbss, problemDef->contrastRes, problemDef->backs,
      problemDef->shifts, problemDef->sf, problemDef->nba, problemDef->nbs,
      problemDef->res, problemDef->dataPresent, problemDef_cells->f2,
      problemDef_cells->f3, problemDef_cells->f4, problemDef->params->size[1],
      problemDef->params, problemDef_cells->f5, problemDef_cells->f6,
      problemDef->contrastBacksType, controls->calcSld, problem->ssubs,
      problem->backgrounds, problem->qshifts, problem->scalefactors,
      problem->nbairs, problem->nbsubs, problem->resolutions, chis, reflectivity,
      Simulation, shifted_data, layerSlds, sldProfiles, allLayers,
      problem->allSubRough);
    break;
  }

  emxFree_real_T(&reflect);
  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&layerSld);
  emxFree_real_T(&sldProfile);
  emxFree_real_T(&thisContrastLayers);
  emxFree_cell_wrap_17(&outParameterisedLayers);
  emxFree_real_T(&allRoughs);
  emxFree_real_T(&resols);
  emxFree_real_T(&nbss);
  emxFree_real_T(&nbas);
  emxFree_real_T(&sfs);
  emxFree_real_T(&qshifts);
  emxFree_real_T(&backgs);
  i = problem->calculations.all_chis->size[0];
  problem->calculations.all_chis->size[0] = chis->size[0];
  emxEnsureCapacity_real_T(sp, problem->calculations.all_chis, i, &bg_emlrtRTEI);
  loop_ub = chis->size[0];
  for (i = 0; i < loop_ub; i++) {
    problem->calculations.all_chis->data[i] = chis->data[i];
  }

  st.site = &g_emlrtRSI;
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
