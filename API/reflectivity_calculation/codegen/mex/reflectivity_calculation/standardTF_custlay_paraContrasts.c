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
#include "callReflectivity.h"
#include "chiSquared.h"
#include "groupLayers_Mod.h"
#include "makeSLDProfileXY.h"
#include "matlabEngineCaller_customLayers.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"

/* Variable Definitions */
static emlrtRSInfo xh_emlrtRSI = { 85, /* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo yh_emlrtRSI = { 87, /* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo ai_emlrtRSI = { 90, /* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo bi_emlrtRSI = { 92, /* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo ci_emlrtRSI = { 96, /* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo di_emlrtRSI = { 103,/* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo ei_emlrtRSI = { 106,/* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo fi_emlrtRSI = { 108,/* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo gi_emlrtRSI = { 113,/* lineNo */
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

static emlrtDCInfo gc_emlrtDCI = { 84, /* lineNo */
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

static emlrtBCInfo qo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  79,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ro_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  90,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo so_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  101,                                 /* colNo */
  "cScales",                           /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo to_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  110,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  119,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  127,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  75,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  83,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo x_emlrtECI = { 1,   /* nDims */
  88,                                  /* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtBCInfo yo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  85,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ap_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  93,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  39,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  47,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  69,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ep_emlrtBCI = { -1, /* iFirst */
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

static emlrtBCInfo fp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  85,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo hc_emlrtDCI = { 51, /* lineNo */
  16,                                  /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo gp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ip_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
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
  16,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  58,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  17,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo up_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  8,                                   /* colNo */
  "resample",                          /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  100,                                 /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  62,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  29,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo aq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  36,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  47,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  73,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  40,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  48,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  56,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  69,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo iq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  106,                                 /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  128,                                 /* colNo */
  "resols",                            /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  87,                                  /* colNo */
  "backgs",                            /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  97,                                  /* colNo */
  "backsType",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo to_emlrtRTEI = { 15,/* lineNo */
  26,                                  /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo uo_emlrtRTEI = { 67,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo vo_emlrtRTEI = { 73,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo wo_emlrtRTEI = { 79,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo xo_emlrtRTEI = { 51,/* lineNo */
  10,                                  /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo yo_emlrtRTEI = { 88,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo ap_emlrtRTEI = { 93,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo bp_emlrtRTEI = { 100,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo cp_emlrtRTEI = { 97,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo dp_emlrtRTEI = { 103,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo ep_emlrtRTEI = { 104,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo fp_emlrtRTEI = { 110,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo gp_emlrtRTEI = { 111,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo hp_emlrtRTEI = { 92,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo ip_emlrtRTEI = { 96,/* lineNo */
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
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T b_i;
  int32_T loop_ub;
  emxArray_real_T *sldProfile;
  emxArray_real_T *layerSld;
  emxArray_real_T *shifted_dat;
  emxArray_real_T *Simul;
  real_T reps;
  int32_T i3;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 29U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 29U, 0U);

  /* coder.extrinsic('callModules');             */
  /* Pre-Allocation... */
  i = (int32_T)muDoubleScalarFloor(numberOfContrasts);
  if (numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &hc_emlrtDCI, sp);
  }

  i1 = (int32_T)numberOfContrasts;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &rc_emlrtRTEI, sp);
  i2 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, reflectivity, i2, &to_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 29U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 29U, 1U);
    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &gp_emlrtBCI, sp);
    }

    i2 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i2, &uo_emlrtRTEI);
    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &gp_emlrtBCI, sp);
    }

    i2 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i2, &uo_emlrtRTEI);
    i2 = reflectivity->size[0] - 1;
    loop_ub = reflectivity->size[0] - 1;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &gp_emlrtBCI, sp);
    }

    loop_ub = reflectivity->size[0] - 1;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &gp_emlrtBCI, sp);
    }

    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &gp_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &gp_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &gp_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &gp_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 29U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 29U, 2U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &sc_emlrtRTEI, sp);
  i2 = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, Simulation, i2, &to_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 29U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 29U, 3U);
    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &hp_emlrtBCI, sp);
    }

    i2 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i2, &vo_emlrtRTEI);
    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &hp_emlrtBCI, sp);
    }

    i2 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i2, &vo_emlrtRTEI);
    i2 = Simulation->size[0] - 1;
    loop_ub = Simulation->size[0] - 1;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &hp_emlrtBCI, sp);
    }

    loop_ub = Simulation->size[0] - 1;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &hp_emlrtBCI, sp);
    }

    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &hp_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &hp_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &hp_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &hp_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 29U, 0U, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 29U, 4U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &tc_emlrtRTEI, sp);
  i2 = allLayers->size[0];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_15(sp, allLayers, i2, &to_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 29U, 0U, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 29U, 5U);
    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ip_emlrtBCI, sp);
    }

    i2 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i2, &wo_emlrtRTEI);
    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ip_emlrtBCI, sp);
    }

    i2 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i2, &wo_emlrtRTEI);
    i2 = allLayers->size[0] - 1;
    loop_ub = allLayers->size[0] - 1;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &ip_emlrtBCI, sp);
    }

    loop_ub = allLayers->size[0] - 1;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &ip_emlrtBCI, sp);
    }

    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ip_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ip_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 29U, 0U, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 29U, 6U);
  if ((int32_T)numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &gc_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &uc_emlrtRTEI, sp);
  i = backgs->size[0];
  backgs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i, &xo_emlrtRTEI);
  i = qshifts->size[0];
  qshifts->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, qshifts, i, &xo_emlrtRTEI);
  i = sfs->size[0];
  sfs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, sfs, i, &xo_emlrtRTEI);
  i = nbas->size[0];
  nbas->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbas, i, &xo_emlrtRTEI);
  i = nbss->size[0];
  nbss->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbss, i, &xo_emlrtRTEI);
  i = resols->size[0];
  resols->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, resols, i, &xo_emlrtRTEI);
  i = allRoughs->size[0];
  allRoughs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, allRoughs, i, &xo_emlrtRTEI);
  i = allLayers->size[0];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_15(sp, allLayers, i, &to_emlrtRTEI);
  i = outSsubs->size[0];
  outSsubs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, outSsubs, i, &xo_emlrtRTEI);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, sldProfiles, i, &to_emlrtRTEI);
  i = layerSlds->size[0];
  layerSlds->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, layerSlds, i, &to_emlrtRTEI);
  i = shifted_data->size[0];
  shifted_data->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, shifted_data, i, &to_emlrtRTEI);
  i = chis->size[0];
  chis->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, chis, i, &xo_emlrtRTEI);
  i = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, Simulation, i, &to_emlrtRTEI);
  i = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, reflectivity, i, &to_emlrtRTEI);
  emxInit_real_T(sp, &sldProfile, 2, &hp_emlrtRTEI, true);
  emxInit_real_T(sp, &layerSld, 2, &ip_emlrtRTEI, true);
  emxInit_real_T(sp, &shifted_dat, 2, &dp_emlrtRTEI, true);
  emxInit_real_T(sp, &Simul, 2, &to_emlrtRTEI, true);
  for (b_i = 0; b_i < i1; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 29U, 0U, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 29U, 7U);
    st.site = &xh_emlrtRSI;
    i = b_i + 1;
    if ((i < 1) || (i > cBacks->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cBacks->size[1], &qo_emlrtBCI, &st);
    }

    i = b_i + 1;
    if ((i < 1) || (i > cShifts->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cShifts->size[1], &ro_emlrtBCI, &st);
    }

    i = b_i + 1;
    if ((i < 1) || (i > cScales->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cScales->size[1], &so_emlrtBCI, &st);
    }

    i = b_i + 1;
    if ((i < 1) || (i > cNbas->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cNbas->size[1], &to_emlrtBCI, &st);
    }

    i = b_i + 1;
    if ((i < 1) || (i > cNbss->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cNbss->size[1], &uo_emlrtBCI, &st);
    }

    i = b_i + 1;
    if ((i < 1) || (i > cRes->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cRes->size[1], &vo_emlrtBCI, &st);
    }

    covrtLogFcn(&emlrtCoverageInstance, 6U, 0U);
    covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 0U);

    /* Distributes the background and shift values among the different contrasts. */
    /*  */
    /* [backgs,qshifts,sfs,nbas,nbss,resols] = backSort(nc,cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,shifts,sf,nba,nbs,res) */
    /*  Inputs: */
    /*        nc = number of contrasts (double) */
    /*        cBacks = Which backround value is associated with each contrast? */
    /*        cShifts = Which qz_shift value is associated with each contrast? */
    /*        cScales = Which scalefactor value is associated with each contrast? */
    /*        cNba = Which NBa value is associated with each contrast? */
    /*        cNbs = Which Nbs value is associated with each contrast? */
    /*        cRes = Which resolution value is associated with each contrast? */
    /*        backs = List of all background values. */
    /*        shifts = List of all qz-shift values */
    /*        sf = List of all scalefactor values */
    /*        nba = List of all nba values */
    /*        nbs = List of all nbs values */
    /*        res = List of all resolution values */
    /*  */
    /*  Outputs: */
    /*        backgs = list of actual background values for each contrast */
    /*        qshifts = list of actual shift values for each contrast       */
    /*        sfs = list of actual shift values for each contrast      */
    /*        nbas = list of actual shift values for each contrast      */
    /*        nbss = list of actual shift values for each contrast */
    /*        nbss = list of actual shift values for each contrast   */
    /*  backgs = 0;%zeros(1,nc); */
    /*  qshifts = 0;%zeros(1,nc); */
    /*  sfs = 0;%zeros(1,nc); */
    /*  nbas = 0;%zeros(1,nc); */
    /*  nbss = 0;%zeros(1,nc); */
    /*  resols = 0;%zeros(1,nc); */
    /* for i = 1:nc */
    /* thisBack = cBacks(i); */
    if (cBacks->data[b_i] != (int32_T)muDoubleScalarFloor(cBacks->data[b_i])) {
      emlrtIntegerCheckR2012b(cBacks->data[b_i], &jb_emlrtDCI, &st);
    }

    i = (int32_T)cBacks->data[b_i];
    if ((i < 1) || (i > backs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, backs->size[1], &lg_emlrtBCI, &st);
    }

    i2 = (int32_T)(b_i + 1U);
    if ((i2 < 1) || (i2 > backgs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, backgs->size[0], &jp_emlrtBCI, &st);
    }

    backgs->data[i2 - 1] = backs->data[i - 1];

    /* thisShift = cShifts(i); */
    if (cShifts->data[b_i] != (int32_T)muDoubleScalarFloor(cShifts->data[b_i]))
    {
      emlrtIntegerCheckR2012b(cShifts->data[b_i], &kb_emlrtDCI, &st);
    }

    i = (int32_T)cShifts->data[b_i];
    if ((i < 1) || (i > shifts->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, shifts->size[1], &ng_emlrtBCI, &st);
    }

    if (i2 > qshifts->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, qshifts->size[0], &kp_emlrtBCI, &st);
    }

    qshifts->data[i2 - 1] = shifts->data[i - 1];

    /* thisScale = cScales(i); */
    if (cScales->data[b_i] != (int32_T)muDoubleScalarFloor(cScales->data[b_i]))
    {
      emlrtIntegerCheckR2012b(cScales->data[b_i], &lb_emlrtDCI, &st);
    }

    i = (int32_T)cScales->data[b_i];
    if ((i < 1) || (i > sf->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, sf->size[1], &pg_emlrtBCI, &st);
    }

    if (i2 > sfs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, sfs->size[0], &lp_emlrtBCI, &st);
    }

    sfs->data[i2 - 1] = sf->data[i - 1];

    /* thisNbair = cNbas(i); */
    if (cNbas->data[b_i] != (int32_T)muDoubleScalarFloor(cNbas->data[b_i])) {
      emlrtIntegerCheckR2012b(cNbas->data[b_i], &mb_emlrtDCI, &st);
    }

    i = (int32_T)cNbas->data[b_i];
    if ((i < 1) || (i > nba->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, nba->size[1], &rg_emlrtBCI, &st);
    }

    if (i2 > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, nbas->size[0], &mp_emlrtBCI, &st);
    }

    nbas->data[i2 - 1] = nba->data[i - 1];

    /* thisNbsub = cNbss(i); */
    if (cNbss->data[b_i] != (int32_T)muDoubleScalarFloor(cNbss->data[b_i])) {
      emlrtIntegerCheckR2012b(cNbss->data[b_i], &nb_emlrtDCI, &st);
    }

    i = (int32_T)cNbss->data[b_i];
    if ((i < 1) || (i > nbs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, nbs->size[1], &tg_emlrtBCI, &st);
    }

    if (i2 > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, nbss->size[0], &np_emlrtBCI, &st);
    }

    nbss->data[i2 - 1] = nbs->data[i - 1];

    /* thisResol = cRes(i); */
    if (cRes->data[b_i] != (int32_T)muDoubleScalarFloor(cRes->data[b_i])) {
      emlrtIntegerCheckR2012b(cRes->data[b_i], &ob_emlrtDCI, &st);
    }

    i = (int32_T)cRes->data[b_i];
    if ((i < 1) || (i > res->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, res->size[1], &vg_emlrtBCI, &st);
    }

    if (i2 > resols->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, resols->size[0], &op_emlrtBCI, &st);
    }

    resols->data[i2 - 1] = res->data[i - 1];

    /* end */
    st.site = &yh_emlrtRSI;
    i = b_i + 1;
    if ((i < 1) || (i > nbas->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, nbas->size[0], &wo_emlrtBCI, &st);
    }

    i = b_i + 1;
    if ((i < 1) || (i > nbss->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, nbss->size[0], &xo_emlrtBCI, &st);
    }

    covrtLogFcn(&emlrtCoverageInstance, 26U, 0U);
    covrtLogBasicBlock(&emlrtCoverageInstance, 26U, 0U);
    b_st.site = &mh_emlrtRSI;
    matlabEngineCaller_customLayers(&b_st, params, (real_T)b_i + 1.0, fname,
      path, nbas->data[b_i], nbss->data[b_i], shifted_dat, &reps);
    if (1 > params->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, params->size[1], &dl_emlrtBCI, &st);
    }

    if (i2 > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, allRoughs->size[0], &pp_emlrtBCI, &st);
    }

    allRoughs->data[i2 - 1] = params->data[0];
    if (10000 < shifted_dat->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, shifted_dat->size[0], &x_emlrtECI, sp);
    }

    loop_ub = shifted_dat->size[0] * shifted_dat->size[1];
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &qp_emlrtBCI, sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &yo_emlrtRTEI);
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &qp_emlrtBCI, sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &yo_emlrtRTEI);
    i = allLayers->size[0] - 1;
    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &qp_emlrtBCI, sp);
    }

    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &qp_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &qp_emlrtBCI, sp);
      }

      allLayers->data[b_i].f1->data[i2] = shifted_dat->data[i2];
    }

    i = b_i + 1;
    if ((i < 1) || (i > nbas->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, nbas->size[0], &yo_emlrtBCI, sp);
    }

    i = b_i + 1;
    if ((i < 1) || (i > nbss->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, nbss->size[0], &ap_emlrtBCI, sp);
    }

    i = b_i + 1;
    if ((i < 1) || (i > allRoughs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, allRoughs->size[0], &rp_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > outSsubs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, outSsubs->size[0], &sp_emlrtBCI, sp);
    }

    st.site = &ai_emlrtRSI;
    b_groupLayers_Mod(&st, shifted_dat, allRoughs->data[i - 1], geometry,
                      layerSld, &outSsubs->data[i2 - 1]);
    st.site = &bi_emlrtRSI;
    i = b_i + 1;
    if ((i < 1) || (i > nbas->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, nbas->size[0], &bp_emlrtBCI, &st);
    }

    i = b_i + 1;
    if ((i < 1) || (i > nbss->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, nbss->size[0], &cp_emlrtBCI, &st);
    }

    i = b_i + 1;
    if ((i < 1) || (i > outSsubs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, outSsubs->size[0], &dp_emlrtBCI, &st);
    }

    i = repeatLayers->size[1] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &fp_emlrtBCI, &st);
    }

    covrtLogFcn(&emlrtCoverageInstance, 9U, 0U);
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 0U);
    if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 0, repeatLayers->data[b_i]
                   .f1[0] == 0.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 1U);
      reps = 1.0;
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 2U);
      reps = repeatLayers->data[b_i].f1[1];
    }

    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 3U);
    b_st.site = &y_emlrtRSI;
    makeSLDProfileXY(&b_st, nbas->data[b_i], nbss->data[b_i], outSsubs->data[b_i],
                     layerSld, layerSld->size[0], reps, sldProfile);
    loop_ub = sldProfile->size[0] * sldProfile->size[1];
    i = sldProfiles->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &tp_emlrtBCI, sp);
    }

    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &ap_emlrtRTEI);
    i = sldProfiles->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &tp_emlrtBCI, sp);
    }

    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &ap_emlrtRTEI);
    i = sldProfiles->size[0] - 1;
    i2 = sldProfiles->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &tp_emlrtBCI, sp);
    }

    i2 = sldProfiles->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &tp_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &tp_emlrtBCI, sp);
      }

      sldProfiles->data[b_i].f1->data[i2] = sldProfile->data[i2];
    }

    i = b_i + 1;
    if ((i < 1) || (i > resample->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, resample->size[1], &up_emlrtBCI, sp);
    }

    if (covrtLogIf(&emlrtCoverageInstance, 29U, 0U, 0, resample->data[i - 1] ==
                   1.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 29U, 8U);
      st.site = &ci_emlrtRSI;
      resampleLayers(&st, sldProfile, layerSld);
      loop_ub = layerSld->size[0] * layerSld->size[1];
      i = layerSlds->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &wp_emlrtBCI, sp);
      }

      i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
      layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
      emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &cp_emlrtRTEI);
      i = layerSlds->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &wp_emlrtBCI, sp);
      }

      i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
      layerSlds->data[b_i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &cp_emlrtRTEI);
      i = layerSlds->size[0] - 1;
      i2 = layerSlds->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &wp_emlrtBCI, sp);
      }

      i2 = layerSlds->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &wp_emlrtBCI, sp);
      }

      for (i2 = 0; i2 < loop_ub; i2++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &wp_emlrtBCI, sp);
        }

        layerSlds->data[b_i].f1->data[i2] = layerSld->data[i2];
      }
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 29U, 9U);
      loop_ub = layerSld->size[0] * layerSld->size[1];
      i = layerSlds->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &vp_emlrtBCI, sp);
      }

      i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
      layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
      emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &bp_emlrtRTEI);
      i = layerSlds->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &vp_emlrtBCI, sp);
      }

      i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
      layerSlds->data[b_i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &bp_emlrtRTEI);
      i = layerSlds->size[0] - 1;
      i2 = layerSlds->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &vp_emlrtBCI, sp);
      }

      i2 = layerSlds->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &vp_emlrtBCI, sp);
      }

      for (i2 = 0; i2 < loop_ub; i2++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &vp_emlrtBCI, sp);
        }

        layerSlds->data[b_i].f1->data[i2] = layerSld->data[i2];
      }
    }

    covrtLogBasicBlock(&emlrtCoverageInstance, 29U, 10U);
    i = allData->size[1] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xp_emlrtBCI, sp);
    }

    i = shifted_dat->size[0] * shifted_dat->size[1];
    shifted_dat->size[0] = allData->data[b_i].f1->size[0];
    shifted_dat->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_dat, i, &dp_emlrtRTEI);
    i = allData->size[1] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xp_emlrtBCI, sp);
    }

    i = allData->size[1] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xp_emlrtBCI, sp);
    }

    loop_ub = allData->data[b_i].f1->size[0] * allData->data[b_i].f1->size[1];
    for (i = 0; i < loop_ub; i++) {
      i2 = allData->size[1] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &xp_emlrtBCI, sp);
      }

      i2 = allData->size[1] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &xp_emlrtBCI, sp);
      }

      i2 = allData->size[1] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &xp_emlrtBCI, sp);
      }

      shifted_dat->data[i] = allData->data[b_i].f1->data[i];
    }

    i = b_i + 1;
    if ((i < 1) || (i > sfs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, sfs->size[0], &yp_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > qshifts->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, qshifts->size[0], &aq_emlrtBCI, sp);
    }

    loop_ub = b_i + 1;
    if ((loop_ub < 1) || (loop_ub > dataPresent->size[1])) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, dataPresent->size[1],
        &bq_emlrtBCI, sp);
    }

    i3 = dataLimits->size[1] - 1;
    if (b_i > i3) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &cq_emlrtBCI, sp);
    }

    st.site = &di_emlrtRSI;
    shiftdata(&st, sfs->data[i - 1], qshifts->data[i2 - 1], dataPresent->
              data[loop_ub - 1], shifted_dat, dataLimits->data[b_i].f1);
    loop_ub = shifted_dat->size[0] * shifted_dat->size[1];
    i = shifted_data->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &dq_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &ep_emlrtRTEI);
    i = shifted_data->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &dq_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &ep_emlrtRTEI);
    i = shifted_data->size[0] - 1;
    i2 = shifted_data->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &dq_emlrtBCI, sp);
    }

    i2 = shifted_data->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &dq_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &dq_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[i2] = shifted_dat->data[i2];
    }

    i = b_i + 1;
    if ((i < 1) || (i > backgs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &ep_emlrtBCI, sp);
    }

    i = b_i + 1;
    if ((i < 1) || (i > nbas->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, nbas->size[0], &eq_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > nbss->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, nbss->size[0], &fq_emlrtBCI, sp);
    }

    loop_ub = simLimits->size[1] - 1;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &gq_emlrtBCI, sp);
    }

    loop_ub = repeatLayers->size[1] - 1;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &hq_emlrtBCI, sp);
    }

    loop_ub = b_i + 1;
    if ((loop_ub < 1) || (loop_ub > outSsubs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, outSsubs->size[0], &iq_emlrtBCI,
        sp);
    }

    i3 = b_i + 1;
    if ((i3 < 1) || (i3 > resols->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, resols->size[0], &jq_emlrtBCI, sp);
    }

    st.site = &ei_emlrtRSI;
    callReflectivity(&st, nbas->data[i - 1], nbss->data[i2 - 1], simLimits->
                     data[b_i].f1, repeatLayers->data[b_i].f1, shifted_dat,
                     layerSld, outSsubs->data[loop_ub - 1], resols->data[i3 - 1],
                     sldProfile, Simul);
    i = b_i + 1;
    if ((i < 1) || (i > backgs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &kq_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > backsType->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, backsType->size[1], &lq_emlrtBCI, sp);
    }

    st.site = &fi_emlrtRSI;
    applyBackgroundCorrection(&st, sldProfile, Simul, shifted_dat, backgs->
      data[i - 1], backsType->data[i2 - 1]);
    if (10000 < sldProfile->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, sldProfile->size[0], &y_emlrtECI, sp);
    }

    loop_ub = sldProfile->size[0] * sldProfile->size[1];
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &mq_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &fp_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &mq_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &fp_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &mq_emlrtBCI, sp);
    }

    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &mq_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &mq_emlrtBCI, sp);
      }

      reflectivity->data[b_i].f1->data[i2] = sldProfile->data[i2];
    }

    if (10000 < Simul->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, Simul->size[0], &ab_emlrtECI, sp);
    }

    loop_ub = Simul->size[0] * Simul->size[1];
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nq_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = Simul->size[0];
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &gp_emlrtRTEI);
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nq_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &gp_emlrtRTEI);
    i = Simulation->size[0] - 1;
    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &nq_emlrtBCI, sp);
    }

    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &nq_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nq_emlrtBCI, sp);
      }

      Simulation->data[b_i].f1->data[i2] = Simul->data[i2];
    }

    i = b_i + 1;
    if ((i < 1) || (i > chis->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, chis->size[0], &oq_emlrtBCI, sp);
    }

    st.site = &gi_emlrtRSI;
    chis->data[i - 1] = chiSquared(&st, shifted_dat, sldProfile, nParams);
  }

  emxFree_real_T(&Simul);
  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&layerSld);
  emxFree_real_T(&sldProfile);
  covrtLogFor(&emlrtCoverageInstance, 29U, 0U, 3, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_custlay_paraContrasts.c) */
