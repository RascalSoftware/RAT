/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_custlay_paraContrasts.c
 *
 * Code generation for function 'standardTF_custlay_paraContrasts'
 *
 */

/* Include files */
#include "standardTF_custlay_paraContrasts.h"
#include "applyBackgroundCorrection.h"
#include "backSort.h"
#include "callReflectivity.h"
#include "call_customLayers.h"
#include "chiSquared.h"
#include "groupLayers_Mod.h"
#include "makeSLDProfiles.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_emxutil.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"

/* Variable Definitions */
static emlrtRSInfo uh_emlrtRSI = { 85, /* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo vh_emlrtRSI = { 87, /* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo wh_emlrtRSI = { 90, /* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo xh_emlrtRSI = { 92, /* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo yh_emlrtRSI = { 96, /* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo ai_emlrtRSI = { 103,/* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo bi_emlrtRSI = { 106,/* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo ci_emlrtRSI = { 108,/* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo di_emlrtRSI = { 113,/* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtRTEInfo rc_emlrtRTEI = { 66,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = { 72,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo tc_emlrtRTEI = { 78,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtDCInfo yb_emlrtDCI = { 84, /* lineNo */
  14,                                  /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo uc_emlrtRTEI = { 84,/* lineNo */
  12,                                  /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtECInfo x_emlrtECI = { 1,   /* nDims */
  88,                                  /* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtBCInfo wo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  85,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  93,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  125,                                 /* colNo */
  "backgs",                            /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo y_emlrtECI = { 1,   /* nDims */
  110,                                 /* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtECInfo ab_emlrtECI = { 1,  /* nDims */
  111,                                 /* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtDCInfo ac_emlrtDCI = { 51, /* lineNo */
  16,                                  /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ap_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  72,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ep_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  82,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  93,                                  /* colNo */
  "cScales",                           /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  104,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  113,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ip_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  122,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  6,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  16,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  27,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo np_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo op_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  50,                                  /* colNo */
  "resols",                            /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  70,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  78,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  16,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  58,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo up_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  17,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  60,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  72,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo aq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  8,                                   /* colNo */
  "resample",                          /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  100,                                 /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  62,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  29,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  36,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  47,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo iq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  73,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  40,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  48,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  56,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  69,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  106,                                 /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  128,                                 /* colNo */
  "resols",                            /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  87,                                  /* colNo */
  "backgs",                            /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  97,                                  /* colNo */
  "backsType",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo qn_emlrtRTEI = { 15,/* lineNo */
  26,                                  /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo rn_emlrtRTEI = { 67,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo sn_emlrtRTEI = { 73,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo tn_emlrtRTEI = { 79,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo un_emlrtRTEI = { 51,/* lineNo */
  10,                                  /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo vn_emlrtRTEI = { 88,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo wn_emlrtRTEI = { 93,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo xn_emlrtRTEI = { 100,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo yn_emlrtRTEI = { 97,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo ao_emlrtRTEI = { 103,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo bo_emlrtRTEI = { 104,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo co_emlrtRTEI = { 110,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo do_emlrtRTEI = { 111,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo eo_emlrtRTEI = { 92,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo fo_emlrtRTEI = { 96,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

/* Function Definitions */
void c_standardTF_custlay_paraContra(const emlrtStack *sp, const emxArray_real_T
  *resample, real_T numberOfContrasts, const emxArray_char_T *geometry, const
  emxArray_cell_wrap_0 *repeatLayers, const emxArray_real_T *cBacks, const
  emxArray_real_T *cShifts, const emxArray_real_T *cScales, const
  emxArray_real_T *cNbas, const emxArray_real_T *cNbss, const emxArray_real_T
  *cRes, const emxArray_real_T *backs, const emxArray_real_T *shifts, const
  emxArray_real_T *sf, const emxArray_real_T *nba, const emxArray_real_T *nbs,
  const emxArray_real_T *res, const emxArray_real_T *dataPresent, const
  emxArray_cell_wrap_1 *allData, const emxArray_cell_wrap_0 *dataLimits, const
  emxArray_cell_wrap_0 *simLimits, real_T nParams, const emxArray_real_T *params,
  const emxArray_char_T *fname, const emxArray_char_T *path, const
  emxArray_real_T *backsType, emxArray_real_T *outSsubs, emxArray_real_T *backgs,
  emxArray_real_T *qshifts, emxArray_real_T *sfs, emxArray_real_T *nbas,
  emxArray_real_T *nbss, emxArray_real_T *resols, emxArray_real_T *chis,
  emxArray_cell_wrap_8 *reflectivity, emxArray_cell_wrap_8 *Simulation,
  emxArray_cell_wrap_1 *shifted_data, emxArray_cell_wrap_1 *layerSlds,
  emxArray_cell_wrap_6 *sldProfiles, emxArray_cell_wrap_15 *allLayers,
  emxArray_real_T *allRoughs)
{
  int32_T ub_loop;
  int32_T i;
  int32_T i1;
  int32_T b_i;
  int32_T i2;
  int32_T c_i;
  emxArray_real_T *layerSld;
  emxArray_real_T *reflect;
  emxArray_real_T *sldProfile;
  emxArray_real_T *shifted_dat;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T d5;
  int32_T i3;
  int32_T loop_ub;
  int32_T i4;
  int32_T i5;
  jmp_buf * volatile emlrtJBStack;
  emlrtStack st;
  jmp_buf b_emlrtJBEnviron;
  emlrtStack b_st;
  boolean_T emlrtHadParallelError = false;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* coder.extrinsic('callModules');             */
  /* Pre-Allocation... */
  ub_loop = (int32_T)muDoubleScalarFloor(numberOfContrasts);
  if (numberOfContrasts != ub_loop) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &ac_emlrtDCI, sp);
  }

  i = (int32_T)numberOfContrasts;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &rc_emlrtRTEI, sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, reflectivity, i1, &qn_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ap_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &rn_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ap_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &rn_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ap_emlrtBCI, sp);
    }

    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ap_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ap_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ap_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ap_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ap_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &sc_emlrtRTEI, sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, Simulation, i1, &qn_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bp_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &sn_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bp_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &sn_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &bp_emlrtBCI, sp);
    }

    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &bp_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bp_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bp_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bp_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bp_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &tc_emlrtRTEI, sp);
  i1 = allLayers->size[0];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_15(sp, allLayers, i1, &qn_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &cp_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &tn_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &cp_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &tn_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &cp_emlrtBCI, sp);
    }

    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &cp_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &cp_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &cp_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
  }

  if ((int32_T)numberOfContrasts != ub_loop) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &yb_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &uc_emlrtRTEI, sp);
  ub_loop = backgs->size[0];
  backgs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, ub_loop, &un_emlrtRTEI);
  ub_loop = qshifts->size[0];
  qshifts->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, qshifts, ub_loop, &un_emlrtRTEI);
  ub_loop = sfs->size[0];
  sfs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, sfs, ub_loop, &un_emlrtRTEI);
  ub_loop = nbas->size[0];
  nbas->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbas, ub_loop, &un_emlrtRTEI);
  ub_loop = nbss->size[0];
  nbss->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbss, ub_loop, &un_emlrtRTEI);
  ub_loop = resols->size[0];
  resols->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, resols, ub_loop, &un_emlrtRTEI);
  ub_loop = allRoughs->size[0];
  allRoughs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, allRoughs, ub_loop, &un_emlrtRTEI);
  ub_loop = allLayers->size[0];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_15(sp, allLayers, ub_loop, &qn_emlrtRTEI);
  ub_loop = outSsubs->size[0];
  outSsubs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, outSsubs, ub_loop, &un_emlrtRTEI);
  ub_loop = sldProfiles->size[0];
  sldProfiles->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, sldProfiles, ub_loop, &qn_emlrtRTEI);
  ub_loop = layerSlds->size[0];
  layerSlds->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, layerSlds, ub_loop, &qn_emlrtRTEI);
  ub_loop = shifted_data->size[0];
  shifted_data->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, shifted_data, ub_loop, &qn_emlrtRTEI);
  ub_loop = chis->size[0];
  chis->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, chis, ub_loop, &un_emlrtRTEI);
  ub_loop = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, Simulation, ub_loop, &qn_emlrtRTEI);
  ub_loop = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, reflectivity, ub_loop, &qn_emlrtRTEI);
  ub_loop = (int32_T)numberOfContrasts - 1;
  emlrtEnterParallelRegion(sp, omp_in_parallel());
  emlrtPushJmpBuf(sp, &emlrtJBStack);

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(layerSld,reflect,sldProfile,shifted_dat,d,d1,d2,d3,d4,d5,b_emlrtJBEnviron,b_st,i3,loop_ub,c_i,i4,i5) \
 firstprivate(st,emlrtHadParallelError)

  {
    if (setjmp(b_emlrtJBEnviron) == 0) {
      st.prev = sp;
      st.tls = emlrtAllocTLS(sp, omp_get_thread_num());
      st.site = NULL;
      emlrtSetJmpBuf(&st, &b_emlrtJBEnviron);
      b_st.prev = &st;
      b_st.tls = st.tls;
      emxInit_real_T(&st, &layerSld, 2, &fo_emlrtRTEI, true);
      emxInit_real_T(&st, &reflect, 2, &qn_emlrtRTEI, true);
      emxInit_real_T(&st, &sldProfile, 2, &eo_emlrtRTEI, true);
      emxInit_real_T(&st, &shifted_dat, 2, &ao_emlrtRTEI, true);
    } else {
      emlrtHadParallelError = true;
    }

#pragma omp for nowait

    for (c_i = 0; c_i <= ub_loop; c_i++) {
      if (emlrtHadParallelError)
        continue;
      if (setjmp(b_emlrtJBEnviron) == 0) {
        i3 = (int32_T)(c_i + 1U);
        if ((i3 < 1) || (i3 > cBacks->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, cBacks->size[1], &dp_emlrtBCI,
            &st);
        }

        if (i3 > cShifts->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, cShifts->size[1], &ep_emlrtBCI,
            &st);
        }

        if (i3 > cScales->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, cScales->size[1], &fp_emlrtBCI,
            &st);
        }

        if (i3 > cNbas->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, cNbas->size[1], &gp_emlrtBCI, &st);
        }

        if (i3 > cNbss->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, cNbss->size[1], &hp_emlrtBCI, &st);
        }

        if (i3 > cRes->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, cRes->size[1], &ip_emlrtBCI, &st);
        }

        b_st.site = &uh_emlrtRSI;
        backSort(&b_st, cBacks->data[i3 - 1], cShifts->data[i3 - 1],
                 cScales->data[i3 - 1], cNbas->data[i3 - 1], cNbss->data[i3 - 1],
                 cRes->data[i3 - 1], backs, shifts, sf, nba, nbs, res, &d5, &d4,
                 &d3, &d2, &d1, &d);
        if (i3 > backgs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, backgs->size[0], &jp_emlrtBCI,
            &st);
        }

        backgs->data[i3 - 1] = d5;
        if (i3 > qshifts->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, qshifts->size[0], &kp_emlrtBCI,
            &st);
        }

        qshifts->data[i3 - 1] = d4;
        if (i3 > sfs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, sfs->size[0], &lp_emlrtBCI, &st);
        }

        sfs->data[i3 - 1] = d3;
        if (i3 > nbas->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, nbas->size[0], &mp_emlrtBCI, &st);
        }

        nbas->data[i3 - 1] = d2;
        if (i3 > nbss->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, nbss->size[0], &np_emlrtBCI, &st);
        }

        nbss->data[i3 - 1] = d1;
        if (i3 > resols->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, resols->size[0], &op_emlrtBCI,
            &st);
        }

        resols->data[i3 - 1] = d;
        if (i3 > nbas->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, nbas->size[0], &pp_emlrtBCI, &st);
        }

        if (i3 > nbss->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, nbss->size[0], &qp_emlrtBCI, &st);
        }

        b_st.site = &vh_emlrtRSI;
        call_customLayers(&b_st, params, (real_T)c_i + 1.0, fname, path,
                          nbas->data[i3 - 1], nbss->data[i3 - 1], shifted_dat,
                          &d);
        if (i3 > allRoughs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, allRoughs->size[0], &rp_emlrtBCI,
            &st);
        }

        allRoughs->data[i3 - 1] = d;
        if (10000 < shifted_dat->size[0]) {
          emlrtDimSizeGeqCheckR2012b(10000, shifted_dat->size[0], &x_emlrtECI,
            &st);
        }

        loop_ub = shifted_dat->size[0] * shifted_dat->size[1];
        i3 = allLayers->size[0] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &sp_emlrtBCI, &st);
        }

        i3 = allLayers->data[c_i].f1->size[0] * allLayers->data[c_i].f1->size[1];
        allLayers->data[c_i].f1->size[0] = shifted_dat->size[0];
        emxEnsureCapacity_real_T(&st, allLayers->data[c_i].f1, i3, &vn_emlrtRTEI);
        i3 = allLayers->size[0] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &sp_emlrtBCI, &st);
        }

        i3 = allLayers->data[c_i].f1->size[0] * allLayers->data[c_i].f1->size[1];
        allLayers->data[c_i].f1->size[1] = 3;
        emxEnsureCapacity_real_T(&st, allLayers->data[c_i].f1, i3, &vn_emlrtRTEI);
        i3 = allLayers->size[0] - 1;
        i4 = allLayers->size[0] - 1;
        if (c_i > i4) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &sp_emlrtBCI, &st);
        }

        i4 = allLayers->size[0] - 1;
        if (c_i > i4) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &sp_emlrtBCI, &st);
        }

        for (i4 = 0; i4 < loop_ub; i4++) {
          if (c_i > i3) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &sp_emlrtBCI, &st);
          }

          allLayers->data[c_i].f1->data[i4] = shifted_dat->data[i4];
        }

        i3 = c_i + 1;
        if ((i3 < 1) || (i3 > nbas->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, nbas->size[0], &wo_emlrtBCI, &st);
        }

        i3 = c_i + 1;
        if ((i3 < 1) || (i3 > nbss->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, nbss->size[0], &xo_emlrtBCI, &st);
        }

        i3 = c_i + 1;
        if ((i3 < 1) || (i3 > allRoughs->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, allRoughs->size[0], &tp_emlrtBCI,
            &st);
        }

        b_st.site = &wh_emlrtRSI;
        b_groupLayers_Mod(&b_st, shifted_dat, allRoughs->data[i3 - 1], geometry,
                          layerSld, &d);
        i3 = c_i + 1;
        if ((i3 < 1) || (i3 > outSsubs->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, outSsubs->size[0], &up_emlrtBCI,
            &st);
        }

        outSsubs->data[i3 - 1] = d;
        i3 = c_i + 1;
        if ((i3 < 1) || (i3 > nbas->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, nbas->size[0], &vp_emlrtBCI, &st);
        }

        i4 = c_i + 1;
        if ((i4 < 1) || (i4 > nbss->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i4, 1, nbss->size[0], &wp_emlrtBCI, &st);
        }

        loop_ub = c_i + 1;
        if ((loop_ub < 1) || (loop_ub > outSsubs->size[0])) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, outSsubs->size[0],
            &xp_emlrtBCI, &st);
        }

        i5 = repeatLayers->size[1] - 1;
        if (c_i > i5) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i5, &yp_emlrtBCI, &st);
        }

        b_st.site = &xh_emlrtRSI;
        makeSLDProfiles(&b_st, nbas->data[i3 - 1], nbss->data[i4 - 1], layerSld,
                        outSsubs->data[loop_ub - 1], repeatLayers->data[c_i].f1,
                        sldProfile);
        loop_ub = sldProfile->size[0] * sldProfile->size[1];
        i3 = sldProfiles->size[0] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &aq_emlrtBCI, &st);
        }

        i3 = sldProfiles->data[c_i].f1->size[0] * sldProfiles->data[c_i]
          .f1->size[1];
        sldProfiles->data[c_i].f1->size[0] = sldProfile->size[0];
        emxEnsureCapacity_real_T(&st, sldProfiles->data[c_i].f1, i3,
          &wn_emlrtRTEI);
        i3 = sldProfiles->size[0] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &aq_emlrtBCI, &st);
        }

        i3 = sldProfiles->data[c_i].f1->size[0] * sldProfiles->data[c_i]
          .f1->size[1];
        sldProfiles->data[c_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(&st, sldProfiles->data[c_i].f1, i3,
          &wn_emlrtRTEI);
        i3 = sldProfiles->size[0] - 1;
        i4 = sldProfiles->size[0] - 1;
        if (c_i > i4) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &aq_emlrtBCI, &st);
        }

        i4 = sldProfiles->size[0] - 1;
        if (c_i > i4) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &aq_emlrtBCI, &st);
        }

        for (i4 = 0; i4 < loop_ub; i4++) {
          if (c_i > i3) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &aq_emlrtBCI, &st);
          }

          sldProfiles->data[c_i].f1->data[i4] = sldProfile->data[i4];
        }

        i3 = c_i + 1;
        if ((i3 < 1) || (i3 > resample->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, resample->size[1], &bq_emlrtBCI,
            &st);
        }

        if (resample->data[i3 - 1] == 1.0) {
          b_st.site = &yh_emlrtRSI;
          resampleLayers(&b_st, sldProfile, layerSld);
          loop_ub = layerSld->size[0] * layerSld->size[1];
          i3 = layerSlds->size[0] - 1;
          if (c_i > i3) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &dq_emlrtBCI, &st);
          }

          i3 = layerSlds->data[c_i].f1->size[0] * layerSlds->data[c_i].f1->size
            [1];
          layerSlds->data[c_i].f1->size[0] = layerSld->size[0];
          emxEnsureCapacity_real_T(&st, layerSlds->data[c_i].f1, i3,
            &yn_emlrtRTEI);
          i3 = layerSlds->size[0] - 1;
          if (c_i > i3) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &dq_emlrtBCI, &st);
          }

          i3 = layerSlds->data[c_i].f1->size[0] * layerSlds->data[c_i].f1->size
            [1];
          layerSlds->data[c_i].f1->size[1] = 3;
          emxEnsureCapacity_real_T(&st, layerSlds->data[c_i].f1, i3,
            &yn_emlrtRTEI);
          i3 = layerSlds->size[0] - 1;
          i4 = layerSlds->size[0] - 1;
          if (c_i > i4) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &dq_emlrtBCI, &st);
          }

          i4 = layerSlds->size[0] - 1;
          if (c_i > i4) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &dq_emlrtBCI, &st);
          }

          for (i4 = 0; i4 < loop_ub; i4++) {
            if (c_i > i3) {
              emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &dq_emlrtBCI, &st);
            }

            layerSlds->data[c_i].f1->data[i4] = layerSld->data[i4];
          }
        } else {
          loop_ub = layerSld->size[0] * layerSld->size[1];
          i3 = layerSlds->size[0] - 1;
          if (c_i > i3) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &cq_emlrtBCI, &st);
          }

          i3 = layerSlds->data[c_i].f1->size[0] * layerSlds->data[c_i].f1->size
            [1];
          layerSlds->data[c_i].f1->size[0] = layerSld->size[0];
          emxEnsureCapacity_real_T(&st, layerSlds->data[c_i].f1, i3,
            &xn_emlrtRTEI);
          i3 = layerSlds->size[0] - 1;
          if (c_i > i3) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &cq_emlrtBCI, &st);
          }

          i3 = layerSlds->data[c_i].f1->size[0] * layerSlds->data[c_i].f1->size
            [1];
          layerSlds->data[c_i].f1->size[1] = 3;
          emxEnsureCapacity_real_T(&st, layerSlds->data[c_i].f1, i3,
            &xn_emlrtRTEI);
          i3 = layerSlds->size[0] - 1;
          i4 = layerSlds->size[0] - 1;
          if (c_i > i4) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &cq_emlrtBCI, &st);
          }

          i4 = layerSlds->size[0] - 1;
          if (c_i > i4) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &cq_emlrtBCI, &st);
          }

          for (i4 = 0; i4 < loop_ub; i4++) {
            if (c_i > i3) {
              emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &cq_emlrtBCI, &st);
            }

            layerSlds->data[c_i].f1->data[i4] = layerSld->data[i4];
          }
        }

        i3 = allData->size[1] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &eq_emlrtBCI, &st);
        }

        i3 = shifted_dat->size[0] * shifted_dat->size[1];
        shifted_dat->size[0] = allData->data[c_i].f1->size[0];
        shifted_dat->size[1] = 3;
        emxEnsureCapacity_real_T(&st, shifted_dat, i3, &ao_emlrtRTEI);
        i3 = allData->size[1] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &eq_emlrtBCI, &st);
        }

        i3 = allData->size[1] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &eq_emlrtBCI, &st);
        }

        loop_ub = allData->data[c_i].f1->size[0] * allData->data[c_i].f1->size[1];
        for (i3 = 0; i3 < loop_ub; i3++) {
          i4 = allData->size[1] - 1;
          if (c_i > i4) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &eq_emlrtBCI, &st);
          }

          i4 = allData->size[1] - 1;
          if (c_i > i4) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &eq_emlrtBCI, &st);
          }

          i4 = allData->size[1] - 1;
          if (c_i > i4) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &eq_emlrtBCI, &st);
          }

          shifted_dat->data[i3] = allData->data[c_i].f1->data[i3];
        }

        i3 = c_i + 1;
        if ((i3 < 1) || (i3 > sfs->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, sfs->size[0], &fq_emlrtBCI, &st);
        }

        i4 = c_i + 1;
        if ((i4 < 1) || (i4 > qshifts->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i4, 1, qshifts->size[0], &gq_emlrtBCI,
            &st);
        }

        loop_ub = c_i + 1;
        if ((loop_ub < 1) || (loop_ub > dataPresent->size[1])) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, dataPresent->size[1],
            &hq_emlrtBCI, &st);
        }

        i5 = dataLimits->size[1] - 1;
        if (c_i > i5) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i5, &iq_emlrtBCI, &st);
        }

        b_st.site = &ai_emlrtRSI;
        shiftdata(&b_st, sfs->data[i3 - 1], qshifts->data[i4 - 1],
                  dataPresent->data[loop_ub - 1], shifted_dat, dataLimits->
                  data[c_i].f1);
        loop_ub = shifted_dat->size[0] * shifted_dat->size[1];
        i3 = shifted_data->size[0] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &jq_emlrtBCI, &st);
        }

        i3 = shifted_data->data[c_i].f1->size[0] * shifted_data->data[c_i]
          .f1->size[1];
        shifted_data->data[c_i].f1->size[0] = shifted_dat->size[0];
        emxEnsureCapacity_real_T(&st, shifted_data->data[c_i].f1, i3,
          &bo_emlrtRTEI);
        i3 = shifted_data->size[0] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &jq_emlrtBCI, &st);
        }

        i3 = shifted_data->data[c_i].f1->size[0] * shifted_data->data[c_i]
          .f1->size[1];
        shifted_data->data[c_i].f1->size[1] = 3;
        emxEnsureCapacity_real_T(&st, shifted_data->data[c_i].f1, i3,
          &bo_emlrtRTEI);
        i3 = shifted_data->size[0] - 1;
        i4 = shifted_data->size[0] - 1;
        if (c_i > i4) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &jq_emlrtBCI, &st);
        }

        i4 = shifted_data->size[0] - 1;
        if (c_i > i4) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &jq_emlrtBCI, &st);
        }

        for (i4 = 0; i4 < loop_ub; i4++) {
          if (c_i > i3) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &jq_emlrtBCI, &st);
          }

          shifted_data->data[c_i].f1->data[i4] = shifted_dat->data[i4];
        }

        i3 = c_i + 1;
        if ((i3 < 1) || (i3 > backgs->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, backgs->size[0], &yo_emlrtBCI,
            &st);
        }

        i3 = c_i + 1;
        if ((i3 < 1) || (i3 > nbas->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, nbas->size[0], &kq_emlrtBCI, &st);
        }

        i4 = c_i + 1;
        if ((i4 < 1) || (i4 > nbss->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i4, 1, nbss->size[0], &lq_emlrtBCI, &st);
        }

        loop_ub = simLimits->size[1] - 1;
        if (c_i > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, loop_ub, &mq_emlrtBCI, &st);
        }

        loop_ub = repeatLayers->size[1] - 1;
        if (c_i > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, loop_ub, &nq_emlrtBCI, &st);
        }

        loop_ub = c_i + 1;
        if ((loop_ub < 1) || (loop_ub > outSsubs->size[0])) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, outSsubs->size[0],
            &oq_emlrtBCI, &st);
        }

        i5 = c_i + 1;
        if ((i5 < 1) || (i5 > resols->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i5, 1, resols->size[0], &pq_emlrtBCI,
            &st);
        }

        b_st.site = &bi_emlrtRSI;
        callReflectivity(&b_st, nbas->data[i3 - 1], nbss->data[i4 - 1],
                         simLimits->data[c_i].f1, repeatLayers->data[c_i].f1,
                         shifted_dat, layerSld, outSsubs->data[loop_ub - 1],
                         resols->data[i5 - 1], reflect, sldProfile);
        i3 = c_i + 1;
        if ((i3 < 1) || (i3 > backgs->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, backgs->size[0], &qq_emlrtBCI,
            &st);
        }

        i4 = c_i + 1;
        if ((i4 < 1) || (i4 > backsType->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i4, 1, backsType->size[1], &rq_emlrtBCI,
            &st);
        }

        b_st.site = &ci_emlrtRSI;
        applyBackgroundCorrection(&b_st, reflect, sldProfile, shifted_dat,
          backgs->data[i3 - 1], backsType->data[i4 - 1]);
        if (10000 < reflect->size[0]) {
          emlrtDimSizeGeqCheckR2012b(10000, reflect->size[0], &y_emlrtECI, &st);
        }

        loop_ub = reflect->size[0] * reflect->size[1];
        i3 = reflectivity->size[0] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &sq_emlrtBCI, &st);
        }

        i3 = reflectivity->data[c_i].f1->size[0] * reflectivity->data[c_i]
          .f1->size[1];
        reflectivity->data[c_i].f1->size[0] = reflect->size[0];
        emxEnsureCapacity_real_T(&st, reflectivity->data[c_i].f1, i3,
          &co_emlrtRTEI);
        i3 = reflectivity->size[0] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &sq_emlrtBCI, &st);
        }

        i3 = reflectivity->data[c_i].f1->size[0] * reflectivity->data[c_i]
          .f1->size[1];
        reflectivity->data[c_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(&st, reflectivity->data[c_i].f1, i3,
          &co_emlrtRTEI);
        i3 = reflectivity->size[0] - 1;
        i4 = reflectivity->size[0] - 1;
        if (c_i > i4) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &sq_emlrtBCI, &st);
        }

        i4 = reflectivity->size[0] - 1;
        if (c_i > i4) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &sq_emlrtBCI, &st);
        }

        for (i4 = 0; i4 < loop_ub; i4++) {
          if (c_i > i3) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &sq_emlrtBCI, &st);
          }

          reflectivity->data[c_i].f1->data[i4] = reflect->data[i4];
        }

        if (10000 < sldProfile->size[0]) {
          emlrtDimSizeGeqCheckR2012b(10000, sldProfile->size[0], &ab_emlrtECI,
            &st);
        }

        loop_ub = sldProfile->size[0] * sldProfile->size[1];
        i3 = Simulation->size[0] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &tq_emlrtBCI, &st);
        }

        i3 = Simulation->data[c_i].f1->size[0] * Simulation->data[c_i].f1->size
          [1];
        Simulation->data[c_i].f1->size[0] = sldProfile->size[0];
        emxEnsureCapacity_real_T(&st, Simulation->data[c_i].f1, i3,
          &do_emlrtRTEI);
        i3 = Simulation->size[0] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &tq_emlrtBCI, &st);
        }

        i3 = Simulation->data[c_i].f1->size[0] * Simulation->data[c_i].f1->size
          [1];
        Simulation->data[c_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(&st, Simulation->data[c_i].f1, i3,
          &do_emlrtRTEI);
        i3 = Simulation->size[0] - 1;
        i4 = Simulation->size[0] - 1;
        if (c_i > i4) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &tq_emlrtBCI, &st);
        }

        i4 = Simulation->size[0] - 1;
        if (c_i > i4) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &tq_emlrtBCI, &st);
        }

        for (i4 = 0; i4 < loop_ub; i4++) {
          if (c_i > i3) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &tq_emlrtBCI, &st);
          }

          Simulation->data[c_i].f1->data[i4] = sldProfile->data[i4];
        }

        i3 = c_i + 1;
        if ((i3 < 1) || (i3 > chis->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, chis->size[0], &uq_emlrtBCI, &st);
        }

        b_st.site = &di_emlrtRSI;
        chis->data[i3 - 1] = chiSquared(&b_st, shifted_dat, reflect, nParams);
      } else {
        emlrtHadParallelError = true;
      }
    }

    if (!emlrtHadParallelError) {
      emlrtHeapReferenceStackLeaveScope(&st, 4);
      emxFree_real_T(&shifted_dat);
      emxFree_real_T(&sldProfile);
      emxFree_real_T(&reflect);
      emxFree_real_T(&layerSld);
    }
  }

  emlrtPopJmpBuf(sp, &emlrtJBStack);
  emlrtExitParallelRegion(sp, omp_in_parallel());
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_custlay_paraContrasts.c) */
