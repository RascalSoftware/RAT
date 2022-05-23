/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_custXY_single.c
 *
 * Code generation for function 'standardTF_custXY_single'
 *
 */

/* Include files */
#include "standardTF_custXY_single.h"
#include "backSort.h"
#include "callReflectivity.h"
#include "call_customLayers.h"
#include "chiSquared.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo xh_emlrtRSI = { 56, /* lineNo */
  "standardTF_custXY_single",          /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pathName */
};

static emlrtRSInfo yh_emlrtRSI = { 59, /* lineNo */
  "standardTF_custXY_single",          /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pathName */
};

static emlrtRSInfo ai_emlrtRSI = { 64, /* lineNo */
  "standardTF_custXY_single",          /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pathName */
};

static emlrtRSInfo bi_emlrtRSI = { 68, /* lineNo */
  "standardTF_custXY_single",          /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pathName */
};

static emlrtRSInfo ci_emlrtRSI = { 72, /* lineNo */
  "standardTF_custXY_single",          /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pathName */
};

static emlrtRSInfo di_emlrtRSI = { 74, /* lineNo */
  "standardTF_custXY_single",          /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pathName */
};

static emlrtRSInfo ei_emlrtRSI = { 79, /* lineNo */
  "standardTF_custXY_single",          /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pathName */
};

static emlrtRSInfo fi_emlrtRSI = { 80, /* lineNo */
  "standardTF_custXY_single",          /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pathName */
};

static emlrtDCInfo qd_emlrtDCI = { 31, /* lineNo */
  18,                                  /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo od_emlrtRTEI = { 37,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo pd_emlrtRTEI = { 43,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo qd_emlrtRTEI = { 49,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo rd_emlrtRTEI = { 55,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtDCInfo rd_emlrtDCI = { 58, /* lineNo */
  34,                                  /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo lv_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  115,                                 /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mv_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  94,                                  /* colNo */
  "backgs",                            /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nv_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  107,                                 /* colNo */
  "backsType",                         /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ov_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  20,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pv_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  34,                                  /* colNo */
  "customFiles",                       /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qv_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  18,                                  /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rv_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  16,                                  /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sv_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  15,                                  /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tv_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  17,                                  /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uv_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  65,                                  /* lineNo */
  15,                                  /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vv_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  15,                                  /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wv_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  18,                                  /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xv_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  18,                                  /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yv_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  16,                                  /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo sd_emlrtDCI = { 23, /* lineNo */
  17,                                  /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo td_emlrtDCI = { 22, /* lineNo */
  16,                                  /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo ud_emlrtDCI = { 22, /* lineNo */
  16,                                  /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo vd_emlrtDCI = { 25, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo wd_emlrtDCI = { 29, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo aw_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  72,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bw_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  82,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cw_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  93,                                  /* colNo */
  "cScales",                           /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dw_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  104,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ew_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  113,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fw_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  122,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gw_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  6,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hw_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  16,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo iw_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  27,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jw_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kw_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lw_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  50,                                  /* colNo */
  "resols",                            /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mw_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  34,                                  /* colNo */
  "cCustFiles",                        /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nw_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  80,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ow_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  17,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pw_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qw_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  65,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rw_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sw_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  30,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tw_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  37,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uw_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  48,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vw_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  63,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ww_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  74,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xw_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  88,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yw_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ax_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  40,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bx_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  48,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cx_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  56,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dx_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  69,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ex_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  118,                                 /* colNo */
  "resols",                            /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fx_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gx_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hx_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  9,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ix_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  9,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jx_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kx_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lx_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo sr_emlrtRTEI = { 22,/* lineNo */
  10,                                  /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo tr_emlrtRTEI = { 25,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo ur_emlrtRTEI = { 29,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo vr_emlrtRTEI = { 22,/* lineNo */
  16,                                  /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo wr_emlrtRTEI = { 38,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo xr_emlrtRTEI = { 44,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo yr_emlrtRTEI = { 50,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo as_emlrtRTEI = { 61,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo bs_emlrtRTEI = { 65,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo cs_emlrtRTEI = { 66,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo ds_emlrtRTEI = { 68,/* lineNo */
  63,                                  /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo es_emlrtRTEI = { 69,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo fs_emlrtRTEI = { 76,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo gs_emlrtRTEI = { 77,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo hs_emlrtRTEI = { 64,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo is_emlrtRTEI = { 68,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo js_emlrtRTEI = { 3,/* lineNo */
  18,                                  /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

/* Function Definitions */
void standardTF_custXY_single(const emlrtStack *sp, const struct0_T *problemDef,
  const cell_16 *problemDef_cells, const struct2_T *controls, emxArray_real_T
  *outSsubs, emxArray_real_T *backgs, emxArray_real_T *qshifts, emxArray_real_T *
  sfs, emxArray_real_T *nbas, emxArray_real_T *nbss, emxArray_real_T *resols,
  emxArray_real_T *chis, emxArray_cell_wrap_9 *reflectivity,
  emxArray_cell_wrap_9 *Simulation, emxArray_cell_wrap_14 *shifted_data,
  emxArray_cell_wrap_10 *layerSlds, emxArray_cell_wrap_14 *sldProfiles,
  emxArray_cell_wrap_14 *allLayers, emxArray_real_T *allRoughs)
{
  emlrtStack st;
  emxArray_real_T *Simul;
  emxArray_real_T *b_problemDef_cells;
  emxArray_real_T *b_shifted_dat;
  emxArray_real_T *layerSld;
  emxArray_real_T *reflect;
  emxArray_real_T *shifted_dat;
  emxArray_real_T *sldProfile;
  real_T d;
  real_T numberOfContrasts;
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  Extract individual cell arrays */
  /*  Splits up the master input list of all arrays into separate arrays */
  /*  The min input array 'problemDef_cells' is a master array where */
  /*  all the cell arrays are grouped together. There are */
  /*  repeatLayers      - controls repeating of the layers stack */
  /*  allData           - Array of all the data arrays */
  /*  dataLimits        - Min max limits in q for the data arrays */
  /*  simLimits         - Limits in Q for the reflkectivity simulations */
  /*  Layers details    - Master array of all available layers */
  /*  contrastLayers    - Which specific combination of arrays are needed for */
  /*                      each contrast. */
  /*  Custom files      - Filenames and path for any custom files used */
  /*  Extract individual parameters from problemDef struct */
  /* Extract individual parameters from problemDef */
  numberOfContrasts = problemDef->numberOfContrasts;

  /* Pre-Allocation... */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &ud_emlrtDCI, sp);
  }

  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &td_emlrtDCI, sp);
  }

  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &sr_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &sd_emlrtDCI, sp);
  }

  i1 = nbas->size[0];
  loop_ub = (int32_T)problemDef->numberOfContrasts;
  nbas->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, nbas, i1, &tr_emlrtRTEI);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &vd_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    nbas->data[i1] = 0.0;
  }

  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &wd_emlrtDCI, sp);
  }

  i1 = outSsubs->size[0];
  outSsubs->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, outSsubs, i1, &ur_emlrtRTEI);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &wd_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    outSsubs->data[i1] = 0.0;
  }

  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &qd_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &od_emlrtRTEI, sp);
  i = reflectivity->size[0];
  reflectivity->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &vr_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &qv_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &wr_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &qv_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &wr_emlrtRTEI);
    i = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &qv_emlrtBCI, sp);
    }

    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &qv_emlrtBCI, sp);
    }

    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &jx_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &jx_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &jx_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &jx_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /* coder.varsize('reflectivity{:}',[10000 2],[1 0]); */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &pd_emlrtRTEI, sp);
  i = Simulation->size[0];
  Simulation->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &vr_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &rv_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &xr_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &rv_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &xr_emlrtRTEI);
    i = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &rv_emlrtBCI, sp);
    }

    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &rv_emlrtBCI, sp);
    }

    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &kx_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &kx_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &kx_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &kx_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /* coder.varsize('Simulation{:}',[10000 2],[1 0]); */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &qd_emlrtRTEI, sp);
  i = allLayers->size[0];
  allLayers->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &vr_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &sv_emlrtBCI,
        sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &yr_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &sv_emlrtBCI,
        sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &yr_emlrtRTEI);
    i = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &sv_emlrtBCI,
        sp);
    }

    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &sv_emlrtBCI,
        sp);
    }

    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &lx_emlrtBCI,
        sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &lx_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /* coder.varsize('allLayers{:}',[10000 3],[1 1]); */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &rd_emlrtRTEI, sp);
  i = qshifts->size[0];
  qshifts->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, qshifts, i, &sr_emlrtRTEI);
  i = sfs->size[0];
  sfs->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, sfs, i, &sr_emlrtRTEI);
  i = nbss->size[0];
  nbss->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, nbss, i, &sr_emlrtRTEI);
  i = resols->size[0];
  resols->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, resols, i, &sr_emlrtRTEI);
  i = allRoughs->size[0];
  allRoughs->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, allRoughs, i, &sr_emlrtRTEI);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &vr_emlrtRTEI);
  i = layerSlds->size[0];
  layerSlds->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &vr_emlrtRTEI);
  i = allLayers->size[0];
  allLayers->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &vr_emlrtRTEI);
  i = shifted_data->size[0];
  shifted_data->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &vr_emlrtRTEI);
  i = chis->size[0];
  chis->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, chis, i, &sr_emlrtRTEI);
  i = Simulation->size[0];
  Simulation->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &vr_emlrtRTEI);
  i = reflectivity->size[0];
  reflectivity->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &vr_emlrtRTEI);
  emxInit_real_T(sp, &layerSld, 2, &hs_emlrtRTEI, true);
  emxInit_real_T(sp, &shifted_dat, 2, &is_emlrtRTEI, true);
  emxInit_real_T(sp, &sldProfile, 2, &js_emlrtRTEI, true);
  emxInit_real_T(sp, &reflect, 2, &js_emlrtRTEI, true);
  emxInit_real_T(sp, &Simul, 2, &js_emlrtRTEI, true);
  emxInit_real_T(sp, &b_shifted_dat, 1, &qh_emlrtRTEI, true);
  emxInit_real_T(sp, &b_problemDef_cells, 2, &ds_emlrtRTEI, true);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if ((int32_T)(b_i + 1U) > problemDef->contrastBacks->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastBacks->size[1], &aw_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > problemDef->contrastShifts->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastShifts->size[1], &bw_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > problemDef->contrastScales->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastScales->size[1], &cw_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > problemDef->contrastNbas->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastNbas->size[1], &dw_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > problemDef->contrastNbss->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastNbss->size[1], &ew_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > problemDef->contrastRes->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastRes->size[1], &fw_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > backgs->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, backgs->size[0],
        &gw_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > qshifts->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, qshifts->size[0],
        &hw_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > sfs->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, sfs->size[0],
        &iw_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, nbas->size[0],
        &jw_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, nbss->size[0],
        &kw_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > resols->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, resols->size[0],
        &lw_emlrtBCI, sp);
    }

    st.site = &xh_emlrtRSI;
    backSort(&st, problemDef->contrastBacks->data[b_i],
             problemDef->contrastShifts->data[b_i], problemDef->
             contrastScales->data[b_i], problemDef->contrastNbas->data[b_i],
             problemDef->contrastNbss->data[b_i], problemDef->contrastRes->
             data[b_i], problemDef->backs, problemDef->shifts, problemDef->sf,
             problemDef->nba, problemDef->nbs, problemDef->res, &backgs->
             data[b_i], &qshifts->data[b_i], &sfs->data[b_i], &nbas->data[b_i],
             &nbss->data[b_i], &resols->data[b_i]);
    if ((int32_T)(b_i + 1U) > problemDef->contrastCustomFiles->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastCustomFiles->size[1], &mw_emlrtBCI, sp);
    }

    d = problemDef->contrastCustomFiles->data[b_i];
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &rd_emlrtDCI, sp);
    }

    if (((int32_T)d - 1 < 0) || ((int32_T)d - 1 > problemDef_cells->f14->size[1]
         - 1)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d - 1, 0, problemDef_cells->
        f14->size[1] - 1, &pv_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, nbss->size[0],
        &nw_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, allRoughs->size[0],
        &ow_emlrtBCI, sp);
    }

    st.site = &yh_emlrtRSI;
    b_call_customLayers(&st, problemDef->params, (real_T)b_i + 1.0,
                        problemDef_cells->f14->data[(int32_T)
                        problemDef->contrastCustomFiles->data[b_i] - 1].f1, nbas,
                        nbss->data[b_i], numberOfContrasts, sldProfile,
                        &allRoughs->data[b_i]);
    b_loop_ub = sldProfile->size[0] * sldProfile->size[1];
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &tv_emlrtBCI, sp);
    }

    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &as_emlrtRTEI);
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &tv_emlrtBCI, sp);
    }

    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = sldProfile->size[1];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &as_emlrtRTEI);
    i = sldProfiles->size[0];
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &tv_emlrtBCI, sp);
    }

    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &tv_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &pw_emlrtBCI, sp);
      }

      sldProfiles->data[b_i].f1->data[i1] = sldProfile->data[i1];
    }

    st.site = &ai_emlrtRSI;
    b_resampleLayers(&st, sldProfile, controls->resamPars, layerSld);
    b_loop_ub = layerSld->size[0] * layerSld->size[1];
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &uv_emlrtBCI,
        sp);
    }

    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &bs_emlrtRTEI);
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &uv_emlrtBCI,
        sp);
    }

    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &bs_emlrtRTEI);
    i = layerSlds->size[0];
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &uv_emlrtBCI,
        sp);
    }

    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &uv_emlrtBCI,
        sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &qw_emlrtBCI, sp);
      }

      layerSlds->data[b_i].f1->data[i1] = layerSld->data[i1];
    }

    b_loop_ub = layerSld->size[0] * layerSld->size[1];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &vv_emlrtBCI,
        sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = layerSld->size[0];
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &cs_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &vv_emlrtBCI,
        sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &cs_emlrtRTEI);
    i = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &vv_emlrtBCI,
        sp);
    }

    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &vv_emlrtBCI,
        sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &rw_emlrtBCI, sp);
      }

      allLayers->data[b_i].f1->data[i1] = layerSld->data[i1];
    }

    if (b_i + 1 > sfs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, sfs->size[0], &sw_emlrtBCI, sp);
    }

    if (b_i + 1 > qshifts->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, qshifts->size[0], &tw_emlrtBCI,
        sp);
    }

    if (b_i + 1 > problemDef->dataPresent->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, problemDef->dataPresent->size[1],
        &uw_emlrtBCI, sp);
    }

    if (b_i > problemDef_cells->f2->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f2->size[1] - 1,
        &vw_emlrtBCI, sp);
    }

    if (b_i > problemDef_cells->f3->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f3->size[1] - 1,
        &ww_emlrtBCI, sp);
    }

    if (b_i > problemDef_cells->f4->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f4->size[1] - 1,
        &xw_emlrtBCI, sp);
    }

    i = b_problemDef_cells->size[0] * b_problemDef_cells->size[1];
    b_problemDef_cells->size[0] = problemDef_cells->f2->data[b_i].f1->size[0];
    b_problemDef_cells->size[1] = problemDef_cells->f2->data[b_i].f1->size[1];
    emxEnsureCapacity_real_T(sp, b_problemDef_cells, i, &ds_emlrtRTEI);
    b_loop_ub = problemDef_cells->f2->data[b_i].f1->size[0] *
      problemDef_cells->f2->data[b_i].f1->size[1] - 1;
    for (i = 0; i <= b_loop_ub; i++) {
      b_problemDef_cells->data[i] = problemDef_cells->f2->data[b_i].f1->data[i];
    }

    st.site = &bi_emlrtRSI;
    shiftdata(&st, sfs->data[b_i], qshifts->data[b_i], problemDef->
              dataPresent->data[b_i], b_problemDef_cells, problemDef_cells->
              f3->data[b_i].f1, (real_T *)problemDef_cells->f4->data[b_i]
              .f1->data, problemDef_cells->f4->data[b_i].f1->size, shifted_dat);
    b_loop_ub = shifted_dat->size[0] * shifted_dat->size[1];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &wv_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &es_emlrtRTEI);
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &wv_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[1] = shifted_dat->size[1];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &es_emlrtRTEI);
    i = shifted_data->size[0];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &wv_emlrtBCI, sp);
    }

    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &wv_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &yw_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[i1] = shifted_dat->data[i1];
    }

    i = b_i + 1;
    if (i > (int32_T)numberOfContrasts) {
      emlrtDynamicBoundsCheckR2012b(i, 1, (int32_T)numberOfContrasts,
        &lv_emlrtBCI, sp);
    }

    if (b_i + 1 > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbas->size[0], &ax_emlrtBCI, sp);
    }

    if (b_i + 1 > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbss->size[0], &bx_emlrtBCI, sp);
    }

    if (b_i > problemDef_cells->f4->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f4->size[1] - 1,
        &cx_emlrtBCI, sp);
    }

    if (b_i > problemDef_cells->f1->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f1->size[1] - 1,
        &dx_emlrtBCI, sp);
    }

    if (b_i + 1 > resols->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, resols->size[0], &ex_emlrtBCI,
        sp);
    }

    st.site = &ci_emlrtRSI;
    callReflectivity(&st, nbas->data[b_i], nbss->data[b_i], (real_T *)
                     problemDef_cells->f4->data[b_i].f1->data,
                     problemDef_cells->f4->data[b_i].f1->size,
                     problemDef_cells->f1->data[b_i].f1, shifted_dat, layerSld,
                     0.0, resols->data[b_i], reflect, Simul);
    st.site = &di_emlrtRSI;
    i = b_i + 1;
    if (i > backgs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &mv_emlrtBCI, &st);
    }

    i = b_i + 1;
    if (i > problemDef->contrastBacksType->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastBacksType->size[1],
        &nv_emlrtBCI, &st);
    }

    if (problemDef->contrastBacksType->data[b_i] != (int32_T)muDoubleScalarFloor
        (problemDef->contrastBacksType->data[b_i])) {
      emlrtIntegerCheckR2012b(problemDef->contrastBacksType->data[b_i],
        &cb_emlrtDCI, &st);
    }

    switch ((int32_T)problemDef->contrastBacksType->data[b_i]) {
     case 1:
      /* Add background to the simulation */
      b_loop_ub = reflect->size[0] * reflect->size[1];
      i = reflect->size[0] * reflect->size[1];
      reflect->size[1] = 2;
      emxEnsureCapacity_real_T(&st, reflect, i, &ph_emlrtRTEI);
      for (i = 0; i < b_loop_ub; i++) {
        reflect->data[i] += backgs->data[b_i];
      }

      b_loop_ub = Simul->size[0] * Simul->size[1];
      i = Simul->size[0] * Simul->size[1];
      Simul->size[1] = 2;
      emxEnsureCapacity_real_T(&st, Simul, i, &rh_emlrtRTEI);
      for (i = 0; i < b_loop_ub; i++) {
        Simul->data[i] += backgs->data[b_i];
      }
      break;

     case 2:
      /*          %Subtract the background from the data.. */
      if (2 > shifted_dat->size[1]) {
        emlrtDynamicBoundsCheckR2012b(2, 1, shifted_dat->size[1], &re_emlrtBCI,
          &st);
      }

      emlrtSubAssignSizeCheckR2012b(&shifted_dat->size[0], 1, &shifted_dat->
        size[0], 1, &emlrtECI, &st);
      b_loop_ub = shifted_dat->size[0] - 1;
      i = b_shifted_dat->size[0];
      b_shifted_dat->size[0] = shifted_dat->size[0];
      emxEnsureCapacity_real_T(&st, b_shifted_dat, i, &qh_emlrtRTEI);
      for (i = 0; i <= b_loop_ub; i++) {
        b_shifted_dat->data[i] = shifted_dat->data[i + shifted_dat->size[0]] -
          backgs->data[b_i];
      }

      b_loop_ub = b_shifted_dat->size[0];
      for (i = 0; i < b_loop_ub; i++) {
        shifted_dat->data[i + shifted_dat->size[0]] = b_shifted_dat->data[i];
      }

      /* shifted_dat(:,3) = shifted_dat(:,3) - backg;    */
      break;
    }

    b_loop_ub = reflect->size[0] * reflect->size[1];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &xv_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = reflect->size[0];
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &fs_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &xv_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &fs_emlrtRTEI);
    i = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &xv_emlrtBCI, sp);
    }

    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &xv_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &fx_emlrtBCI, sp);
      }

      reflectivity->data[b_i].f1->data[i1] = reflect->data[i1];
    }

    b_loop_ub = Simul->size[0] * Simul->size[1];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &yv_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = Simul->size[0];
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &gs_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &yv_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &gs_emlrtRTEI);
    i = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &yv_emlrtBCI, sp);
    }

    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &yv_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &gx_emlrtBCI, sp);
      }

      Simulation->data[b_i].f1->data[i1] = Simul->data[i1];
    }

    i = b_i + 1;
    if (i > problemDef->dataPresent->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->dataPresent->size[1],
        &ov_emlrtBCI, sp);
    }

    st.site = &ei_emlrtRSI;
    if (muDoubleScalarIsNaN(problemDef->dataPresent->data[b_i])) {
      emlrtErrorWithMessageIdR2018a(&st, &nd_emlrtRTEI, "MATLAB:nologicalnan",
        "MATLAB:nologicalnan", 0);
    }

    if (problemDef->dataPresent->data[b_i] != 0.0) {
      if (b_i + 1 > chis->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, chis->size[0], &ix_emlrtBCI,
          sp);
      }

      st.site = &fi_emlrtRSI;
      chis->data[b_i] = chiSquared(&st, shifted_dat, reflect, problemDef->
        params->size[1]);
    } else {
      if (b_i + 1 > chis->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, chis->size[0], &hx_emlrtBCI,
          sp);
      }

      chis->data[b_i] = 0.0;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_problemDef_cells);
  emxFree_real_T(&b_shifted_dat);
  emxFree_real_T(&Simul);
  emxFree_real_T(&reflect);
  emxFree_real_T(&sldProfile);
  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&layerSld);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_custXY_single.c) */
