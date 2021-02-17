/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_custXY_paraPoints.c
 *
 * Code generation for function 'standardTF_custXY_paraPoints'
 *
 */

/* Include files */
#include "standardTF_custXY_paraPoints.h"
#include "applyBackgroundCorrection.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "matlabEngineCaller_customLayers.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"

/* Variable Definitions */
static emlrtRSInfo ti_emlrtRSI = { 85, /* lineNo */
  "standardTF_custXY_paraPoints",      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pathName */
};

static emlrtRSInfo ui_emlrtRSI = { 87, /* lineNo */
  "standardTF_custXY_paraPoints",      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pathName */
};

static emlrtRSInfo vi_emlrtRSI = { 96, /* lineNo */
  "standardTF_custXY_paraPoints",      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pathName */
};

static emlrtRSInfo wi_emlrtRSI = { 103,/* lineNo */
  "standardTF_custXY_paraPoints",      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pathName */
};

static emlrtRSInfo xi_emlrtRSI = { 106,/* lineNo */
  "standardTF_custXY_paraPoints",      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pathName */
};

static emlrtRSInfo yi_emlrtRSI = { 108,/* lineNo */
  "standardTF_custXY_paraPoints",      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pathName */
};

static emlrtRSInfo aj_emlrtRSI = { 113,/* lineNo */
  "standardTF_custXY_paraPoints",      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pathName */
};

static emlrtBCInfo ms_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ns_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo os_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ps_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  97,                                  /* colNo */
  "backsType",                         /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  87,                                  /* colNo */
  "backgs",                            /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  128,                                 /* colNo */
  "resols",                            /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ss_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  69,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ts_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  56,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo us_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  48,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  40,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ws_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  73,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ys_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  47,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo at_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  36,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  29,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ct_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  62,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo et_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ft_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  17,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ht_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  50,                                  /* colNo */
  "resols",                            /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo it_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  27,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  16,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  6,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ot_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo vc_emlrtDCI = { 58, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo wc_emlrtDCI = { 51, /* lineNo */
  16,                                  /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo xc_emlrtDCI = { 60, /* lineNo */
  18,                                  /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo db_emlrtECI = { 1,  /* nDims */
  111,                                 /* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtECInfo eb_emlrtECI = { 1,  /* nDims */
  110,                                 /* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtBCInfo qt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  125,                                 /* colNo */
  "backgs",                            /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  115,                                 /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo st_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  80,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  72,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ut_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  127,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  119,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  110,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  101,                                 /* colNo */
  "cScales",                           /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  90,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo au_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  79,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo gd_emlrtRTEI = { 84,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo hd_emlrtRTEI = { 78,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo id_emlrtRTEI = { 72,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo jd_emlrtRTEI = { 66,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo pq_emlrtRTEI = { 58,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo qq_emlrtRTEI = { 15,/* lineNo */
  26,                                  /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo rq_emlrtRTEI = { 67,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo sq_emlrtRTEI = { 73,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo tq_emlrtRTEI = { 51,/* lineNo */
  10,                                  /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo uq_emlrtRTEI = { 79,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo vq_emlrtRTEI = { 93,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo wq_emlrtRTEI = { 97,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo xq_emlrtRTEI = { 103,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo yq_emlrtRTEI = { 104,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo ar_emlrtRTEI = { 110,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo br_emlrtRTEI = { 111,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo cr_emlrtRTEI = { 96,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

/* Function Definitions */
void standardTF_custXY_paraPoints(const emlrtStack *sp, real_T numberOfContrasts,
  const emxArray_cell_wrap_0 *repeatLayers, const emxArray_real_T *cBacks, const
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
  int32_T loop_ub;
  int32_T i1;
  int32_T b_i;
  emxArray_real_T *layerSld;
  emxArray_real_T *shifted_dat;
  emxArray_real_T *Simul;
  emxArray_real_T *b_shifted_dat;
  real_T layers;
  int32_T b_loop_ub;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 33U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 33U, 0U);

  /* coder.extrinsic('callModules');             */
  /* Pre-Allocation... */
  i = (int32_T)muDoubleScalarFloor(numberOfContrasts);
  if (numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &wc_emlrtDCI, sp);
  }

  loop_ub = (int32_T)numberOfContrasts;
  i1 = outSsubs->size[0];
  outSsubs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, outSsubs, i1, &pq_emlrtRTEI);
  if ((int32_T)numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &vc_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    outSsubs->data[i1] = 0.0;
  }

  if ((int32_T)numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &xc_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &jd_emlrtRTEI, sp);
  i = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, reflectivity, i, &qq_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 33U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 33U, 1U);
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &pt_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &rq_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &pt_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &rq_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pt_emlrtBCI, sp);
    }

    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pt_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &pt_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &pt_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &pt_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &pt_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 33U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 33U, 2U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &id_emlrtRTEI, sp);
  i = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, Simulation, i, &qq_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 33U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 33U, 3U);
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ot_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &sq_emlrtRTEI);
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ot_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &sq_emlrtRTEI);
    i = Simulation->size[0] - 1;
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ot_emlrtBCI, sp);
    }

    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ot_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ot_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ot_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ot_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ot_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 33U, 0U, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 33U, 4U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &hd_emlrtRTEI, sp);
  i = allLayers->size[0];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_15(sp, allLayers, i, &qq_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 33U, 0U, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 33U, 5U);
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nt_emlrtBCI, sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &uq_emlrtRTEI);
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nt_emlrtBCI, sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &uq_emlrtRTEI);
    i = allLayers->size[0] - 1;
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &nt_emlrtBCI, sp);
    }

    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &nt_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nt_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nt_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 33U, 0U, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 33U, 6U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &gd_emlrtRTEI, sp);
  i = backgs->size[0];
  backgs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i, &tq_emlrtRTEI);
  i = qshifts->size[0];
  qshifts->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, qshifts, i, &tq_emlrtRTEI);
  i = sfs->size[0];
  sfs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, sfs, i, &tq_emlrtRTEI);
  i = nbas->size[0];
  nbas->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbas, i, &tq_emlrtRTEI);
  i = nbss->size[0];
  nbss->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbss, i, &tq_emlrtRTEI);
  i = resols->size[0];
  resols->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, resols, i, &tq_emlrtRTEI);
  i = allRoughs->size[0];
  allRoughs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, allRoughs, i, &tq_emlrtRTEI);
  i = allLayers->size[0];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_15(sp, allLayers, i, &qq_emlrtRTEI);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, sldProfiles, i, &qq_emlrtRTEI);
  i = layerSlds->size[0];
  layerSlds->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, layerSlds, i, &qq_emlrtRTEI);
  i = shifted_data->size[0];
  shifted_data->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, shifted_data, i, &qq_emlrtRTEI);
  i = chis->size[0];
  chis->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, chis, i, &tq_emlrtRTEI);
  i = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, Simulation, i, &qq_emlrtRTEI);
  i = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, reflectivity, i, &qq_emlrtRTEI);
  emxInit_real_T(sp, &layerSld, 2, &cr_emlrtRTEI, true);
  emxInit_real_T(sp, &shifted_dat, 2, &xq_emlrtRTEI, true);
  emxInit_real_T(sp, &Simul, 2, &qq_emlrtRTEI, true);
  emxInit_real_T(sp, &b_shifted_dat, 2, &iq_emlrtRTEI, true);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 33U, 0U, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 33U, 7U);
    st.site = &ti_emlrtRSI;
    i = b_i + 1;
    if ((i < 1) || (i > cBacks->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cBacks->size[1], &au_emlrtBCI, &st);
    }

    i = b_i + 1;
    if ((i < 1) || (i > cShifts->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cShifts->size[1], &yt_emlrtBCI, &st);
    }

    i = b_i + 1;
    if ((i < 1) || (i > cScales->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cScales->size[1], &xt_emlrtBCI, &st);
    }

    i = b_i + 1;
    if ((i < 1) || (i > cNbas->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cNbas->size[1], &wt_emlrtBCI, &st);
    }

    i = b_i + 1;
    if ((i < 1) || (i > cNbss->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cNbss->size[1], &vt_emlrtBCI, &st);
    }

    i = b_i + 1;
    if ((i < 1) || (i > cRes->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cRes->size[1], &ut_emlrtBCI, &st);
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
    i = (int32_T)(b_i + 1U);
    if ((i < 1) || (i > backgs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &mt_emlrtBCI, &st);
    }

    if (cBacks->data[b_i] != (int32_T)muDoubleScalarFloor(cBacks->data[b_i])) {
      emlrtIntegerCheckR2012b(cBacks->data[b_i], &jb_emlrtDCI, &st);
    }

    i1 = (int32_T)cBacks->data[b_i];
    if ((i1 < 1) || (i1 > backs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, backs->size[1], &lg_emlrtBCI, &st);
    }

    backgs->data[i - 1] = backs->data[i1 - 1];

    /* thisShift = cShifts(i); */
    if (i > qshifts->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, qshifts->size[0], &lt_emlrtBCI, &st);
    }

    if (cShifts->data[b_i] != (int32_T)muDoubleScalarFloor(cShifts->data[b_i]))
    {
      emlrtIntegerCheckR2012b(cShifts->data[b_i], &kb_emlrtDCI, &st);
    }

    i1 = (int32_T)cShifts->data[b_i];
    if ((i1 < 1) || (i1 > shifts->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, shifts->size[1], &ng_emlrtBCI, &st);
    }

    qshifts->data[i - 1] = shifts->data[i1 - 1];

    /* thisScale = cScales(i); */
    if (i > sfs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, sfs->size[0], &kt_emlrtBCI, &st);
    }

    if (cScales->data[b_i] != (int32_T)muDoubleScalarFloor(cScales->data[b_i]))
    {
      emlrtIntegerCheckR2012b(cScales->data[b_i], &lb_emlrtDCI, &st);
    }

    i1 = (int32_T)cScales->data[b_i];
    if ((i1 < 1) || (i1 > sf->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, sf->size[1], &pg_emlrtBCI, &st);
    }

    sfs->data[i - 1] = sf->data[i1 - 1];

    /* thisNbair = cNbas(i); */
    if (i > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, nbas->size[0], &jt_emlrtBCI, &st);
    }

    if (cNbas->data[b_i] != (int32_T)muDoubleScalarFloor(cNbas->data[b_i])) {
      emlrtIntegerCheckR2012b(cNbas->data[b_i], &mb_emlrtDCI, &st);
    }

    i1 = (int32_T)cNbas->data[b_i];
    if ((i1 < 1) || (i1 > nba->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nba->size[1], &rg_emlrtBCI, &st);
    }

    nbas->data[i - 1] = nba->data[i1 - 1];

    /* thisNbsub = cNbss(i); */
    if (i > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, nbss->size[0], &it_emlrtBCI, &st);
    }

    if (cNbss->data[b_i] != (int32_T)muDoubleScalarFloor(cNbss->data[b_i])) {
      emlrtIntegerCheckR2012b(cNbss->data[b_i], &nb_emlrtDCI, &st);
    }

    i1 = (int32_T)cNbss->data[b_i];
    if ((i1 < 1) || (i1 > nbs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbs->size[1], &tg_emlrtBCI, &st);
    }

    nbss->data[i - 1] = nbs->data[i1 - 1];

    /* thisResol = cRes(i); */
    if (i > resols->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, resols->size[0], &ht_emlrtBCI, &st);
    }

    if (cRes->data[b_i] != (int32_T)muDoubleScalarFloor(cRes->data[b_i])) {
      emlrtIntegerCheckR2012b(cRes->data[b_i], &ob_emlrtDCI, &st);
    }

    i1 = (int32_T)cRes->data[b_i];
    if ((i1 < 1) || (i1 > res->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, res->size[1], &vg_emlrtBCI, &st);
    }

    resols->data[i - 1] = res->data[i1 - 1];

    /* end */
    st.site = &ui_emlrtRSI;
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbas->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbas->size[0], &tt_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbss->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &st_emlrtBCI, &st);
    }

    covrtLogFcn(&emlrtCoverageInstance, 32U, 0U);
    covrtLogBasicBlock(&emlrtCoverageInstance, 32U, 0U);
    b_st.site = &si_emlrtRSI;
    matlabEngineCaller_customLayers(&b_st, params, (real_T)b_i + 1.0, fname,
      path, nbas->data[b_i], nbss->data[b_i], shifted_dat, &layers);
    covrtLogIf(&emlrtCoverageInstance, 32U, 0U, 0, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 32U, 1U);
    covrtLogBasicBlock(&emlrtCoverageInstance, 32U, 3U);
    if (1 > params->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, params->size[1], &bs_emlrtBCI, &st);
    }

    if (i > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, allRoughs->size[0], &gt_emlrtBCI, &st);
    }

    allRoughs->data[i - 1] = params->data[0];
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ft_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->size[0] = 0;
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ft_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->size[1] = 0;
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ft_emlrtBCI, sp);
    }

    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ft_emlrtBCI, sp);
    }

    /* [outLayers, outSsubs(i)] = groupLayers_Mod(outLayers,allRoughs(i),geometry,nbas(i),nbss(i)); */
    /* sldProfile = makeSLDProfiles(nbas(i),nbss(i),outLayers,outSsubs(i),repeatLayers{i}); */
    i = sldProfiles->size[0] - 1;
    b_loop_ub = shifted_dat->size[0];
    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &et_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &vq_emlrtRTEI);
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &et_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &vq_emlrtRTEI);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &et_emlrtBCI, sp);
      }

      sldProfiles->data[b_i].f1->data[i1] = shifted_dat->data[i1];
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &et_emlrtBCI, sp);
      }

      sldProfiles->data[b_i].f1->data[i1 + sldProfiles->data[b_i].f1->size[0]] =
        shifted_dat->data[i1 + shifted_dat->size[0]];
    }

    /* if resample(i) == 1 */
    b_loop_ub = shifted_dat->size[0];
    i = b_shifted_dat->size[0] * b_shifted_dat->size[1];
    b_shifted_dat->size[0] = shifted_dat->size[0];
    b_shifted_dat->size[1] = 2;
    emxEnsureCapacity_real_T(sp, b_shifted_dat, i, &iq_emlrtRTEI);
    for (i = 0; i < b_loop_ub; i++) {
      b_shifted_dat->data[i] = shifted_dat->data[i];
    }

    for (i = 0; i < b_loop_ub; i++) {
      b_shifted_dat->data[i + b_shifted_dat->size[0]] = shifted_dat->data[i +
        shifted_dat->size[0]];
    }

    st.site = &vi_emlrtRSI;
    resampleLayers(&st, b_shifted_dat, layerSld);
    b_loop_ub = layerSld->size[0] * layerSld->size[1];
    i = layerSlds->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &dt_emlrtBCI, sp);
    }

    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &wq_emlrtRTEI);
    i = layerSlds->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &dt_emlrtBCI, sp);
    }

    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &wq_emlrtRTEI);
    i = layerSlds->size[0] - 1;
    i1 = layerSlds->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &dt_emlrtBCI, sp);
    }

    i1 = layerSlds->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &dt_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &dt_emlrtBCI, sp);
      }

      layerSlds->data[b_i].f1->data[i1] = layerSld->data[i1];
    }

    /* else */
    /*    layerSld = outLayers; */
    /*    layerSlds{i} = layerSld; */
    /* end */
    i = allData->size[1] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ct_emlrtBCI, sp);
    }

    i = shifted_dat->size[0] * shifted_dat->size[1];
    shifted_dat->size[0] = allData->data[b_i].f1->size[0];
    shifted_dat->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_dat, i, &xq_emlrtRTEI);
    i = allData->size[1] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ct_emlrtBCI, sp);
    }

    i = allData->size[1] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ct_emlrtBCI, sp);
    }

    b_loop_ub = allData->data[b_i].f1->size[0] * allData->data[b_i].f1->size[1];
    for (i = 0; i < b_loop_ub; i++) {
      i1 = allData->size[1] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ct_emlrtBCI, sp);
      }

      i1 = allData->size[1] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ct_emlrtBCI, sp);
      }

      i1 = allData->size[1] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ct_emlrtBCI, sp);
      }

      shifted_dat->data[i] = allData->data[b_i].f1->data[i];
    }

    i = dataLimits->size[1] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xs_emlrtBCI, sp);
    }

    i = b_i + 1;
    if ((i < 1) || (i > dataPresent->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, dataPresent->size[1], &ys_emlrtBCI, sp);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > qshifts->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, qshifts->size[0], &at_emlrtBCI, sp);
    }

    b_loop_ub = b_i + 1;
    if ((b_loop_ub < 1) || (b_loop_ub > sfs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, sfs->size[0], &bt_emlrtBCI, sp);
    }

    st.site = &wi_emlrtRSI;
    shiftdata(&st, sfs->data[b_loop_ub - 1], qshifts->data[i1 - 1],
              dataPresent->data[i - 1], shifted_dat, dataLimits->data[b_i].f1);
    b_loop_ub = shifted_dat->size[0] * shifted_dat->size[1];
    i = shifted_data->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ws_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &yq_emlrtRTEI);
    i = shifted_data->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ws_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &yq_emlrtRTEI);
    i = shifted_data->size[0] - 1;
    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ws_emlrtBCI, sp);
    }

    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ws_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ws_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[i1] = shifted_dat->data[i1];
    }

    i = b_i + 1;
    if ((i < 1) || (i > backgs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &qt_emlrtBCI, sp);
    }

    i = b_i + 1;
    if ((i < 1) || (i > (int32_T)numberOfContrasts)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, (int32_T)numberOfContrasts,
        &rt_emlrtBCI, sp);
    }

    i = b_i + 1;
    if ((i < 1) || (i > resols->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, resols->size[0], &rs_emlrtBCI, sp);
    }

    i1 = repeatLayers->size[1] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ss_emlrtBCI, sp);
    }

    i1 = simLimits->size[1] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ts_emlrtBCI, sp);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbss->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &us_emlrtBCI, sp);
    }

    b_loop_ub = b_i + 1;
    if ((b_loop_ub < 1) || (b_loop_ub > nbas->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, nbas->size[0], &vs_emlrtBCI,
        sp);
    }

    st.site = &xi_emlrtRSI;
    b_callReflectivity(&st, nbas->data[b_loop_ub - 1], nbss->data[i1 - 1],
                       simLimits->data[b_i].f1, repeatLayers->data[b_i].f1,
                       shifted_dat, layerSld, 0.0, resols->data[i - 1],
                       b_shifted_dat, Simul);
    i = b_i + 1;
    if ((i < 1) || (i > backsType->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, backsType->size[1], &ps_emlrtBCI, sp);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > backgs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, backgs->size[0], &qs_emlrtBCI, sp);
    }

    st.site = &yi_emlrtRSI;
    applyBackgroundCorrection(&st, b_shifted_dat, Simul, shifted_dat,
      backgs->data[i1 - 1], backsType->data[i - 1]);
    if (10000 < b_shifted_dat->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, b_shifted_dat->size[0], &eb_emlrtECI, sp);
    }

    b_loop_ub = b_shifted_dat->size[0] * b_shifted_dat->size[1];
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &os_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = b_shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &ar_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &os_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &ar_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &os_emlrtBCI, sp);
    }

    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &os_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &os_emlrtBCI, sp);
      }

      reflectivity->data[b_i].f1->data[i1] = b_shifted_dat->data[i1];
    }

    if (10000 < Simul->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, Simul->size[0], &db_emlrtECI, sp);
    }

    b_loop_ub = Simul->size[0] * Simul->size[1];
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ns_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = Simul->size[0];
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &br_emlrtRTEI);
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ns_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &br_emlrtRTEI);
    i = Simulation->size[0] - 1;
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ns_emlrtBCI, sp);
    }

    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ns_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ns_emlrtBCI, sp);
      }

      Simulation->data[b_i].f1->data[i1] = Simul->data[i1];
    }

    i = b_i + 1;
    if ((i < 1) || (i > chis->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, chis->size[0], &ms_emlrtBCI, sp);
    }

    st.site = &aj_emlrtRSI;
    chis->data[i - 1] = chiSquared(&st, shifted_dat, b_shifted_dat, nParams);
  }

  emxFree_real_T(&b_shifted_dat);
  emxFree_real_T(&Simul);
  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&layerSld);
  covrtLogFor(&emlrtCoverageInstance, 33U, 0U, 3, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_custXY_paraPoints.c) */
