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
#include "applyBackgroundCorrection.h"
#include "backSort.h"
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
static emlrtRSInfo ii_emlrtRSI = { 85, /* lineNo */
  "standardTF_custXY_single",          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pathName */
};

static emlrtRSInfo ji_emlrtRSI = { 87, /* lineNo */
  "standardTF_custXY_single",          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pathName */
};

static emlrtRSInfo ki_emlrtRSI = { 96, /* lineNo */
  "standardTF_custXY_single",          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pathName */
};

static emlrtRSInfo li_emlrtRSI = { 103,/* lineNo */
  "standardTF_custXY_single",          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pathName */
};

static emlrtRSInfo mi_emlrtRSI = { 106,/* lineNo */
  "standardTF_custXY_single",          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pathName */
};

static emlrtRSInfo ni_emlrtRSI = { 108,/* lineNo */
  "standardTF_custXY_single",          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pathName */
};

static emlrtRSInfo oi_emlrtRSI = { 113,/* lineNo */
  "standardTF_custXY_single",          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pathName */
};

static emlrtBCInfo ss_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ts_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo us_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  97,                                  /* colNo */
  "backsType",                         /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ws_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  87,                                  /* colNo */
  "backgs",                            /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  128,                                 /* colNo */
  "resols",                            /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ys_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  69,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo at_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  56,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  48,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ct_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  40,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo et_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  73,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ft_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  47,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  36,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ht_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  29,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo it_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  62,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  17,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  50,                                  /* colNo */
  "resols",                            /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ot_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  27,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  16,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo st_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  6,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  122,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ut_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  113,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  104,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  93,                                  /* colNo */
  "cScales",                           /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  82,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  72,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo au_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo pc_emlrtDCI = { 58, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo qc_emlrtDCI = { 51, /* lineNo */
  16,                                  /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo rc_emlrtDCI = { 60, /* lineNo */
  18,                                  /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo db_emlrtECI = { 1,  /* nDims */
  111,                                 /* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtECInfo eb_emlrtECI = { 1,  /* nDims */
  110,                                 /* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtBCInfo du_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  125,                                 /* colNo */
  "backgs",                            /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  115,                                 /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  80,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  72,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo gd_emlrtRTEI = { 84,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo hd_emlrtRTEI = { 78,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo id_emlrtRTEI = { 72,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo jd_emlrtRTEI = { 66,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo fq_emlrtRTEI = { 58,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo gq_emlrtRTEI = { 15,/* lineNo */
  26,                                  /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo hq_emlrtRTEI = { 67,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo iq_emlrtRTEI = { 73,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo jq_emlrtRTEI = { 51,/* lineNo */
  10,                                  /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo kq_emlrtRTEI = { 79,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo lq_emlrtRTEI = { 93,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo mq_emlrtRTEI = { 97,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo nq_emlrtRTEI = { 103,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo oq_emlrtRTEI = { 104,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo pq_emlrtRTEI = { 110,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo qq_emlrtRTEI = { 111,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo rq_emlrtRTEI = { 96,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

/* Function Definitions */
void standardTF_custXY_single(const emlrtStack *sp, real_T numberOfContrasts,
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

  /* coder.extrinsic('callModules');             */
  /* Pre-Allocation... */
  i = (int32_T)muDoubleScalarFloor(numberOfContrasts);
  if (numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &qc_emlrtDCI, sp);
  }

  loop_ub = (int32_T)numberOfContrasts;
  i1 = outSsubs->size[0];
  outSsubs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, outSsubs, i1, &fq_emlrtRTEI);
  if ((int32_T)numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &pc_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    outSsubs->data[i1] = 0.0;
  }

  if ((int32_T)numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &rc_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &jd_emlrtRTEI, sp);
  i = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, reflectivity, i, &gq_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cu_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &hq_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cu_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &hq_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &cu_emlrtBCI, sp);
    }

    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &cu_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cu_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cu_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cu_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cu_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &id_emlrtRTEI, sp);
  i = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, Simulation, i, &gq_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bu_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &iq_emlrtRTEI);
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bu_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &iq_emlrtRTEI);
    i = Simulation->size[0] - 1;
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bu_emlrtBCI, sp);
    }

    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bu_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bu_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bu_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bu_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bu_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &hd_emlrtRTEI, sp);
  i = allLayers->size[0];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_15(sp, allLayers, i, &gq_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &au_emlrtBCI, sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &kq_emlrtRTEI);
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &au_emlrtBCI, sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &kq_emlrtRTEI);
    i = allLayers->size[0] - 1;
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &au_emlrtBCI, sp);
    }

    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &au_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &au_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &au_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &gd_emlrtRTEI, sp);
  i = backgs->size[0];
  backgs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i, &jq_emlrtRTEI);
  i = qshifts->size[0];
  qshifts->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, qshifts, i, &jq_emlrtRTEI);
  i = sfs->size[0];
  sfs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, sfs, i, &jq_emlrtRTEI);
  i = nbas->size[0];
  nbas->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbas, i, &jq_emlrtRTEI);
  i = nbss->size[0];
  nbss->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbss, i, &jq_emlrtRTEI);
  i = resols->size[0];
  resols->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, resols, i, &jq_emlrtRTEI);
  i = allRoughs->size[0];
  allRoughs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, allRoughs, i, &jq_emlrtRTEI);
  i = allLayers->size[0];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_15(sp, allLayers, i, &gq_emlrtRTEI);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, sldProfiles, i, &gq_emlrtRTEI);
  i = layerSlds->size[0];
  layerSlds->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, layerSlds, i, &gq_emlrtRTEI);
  i = shifted_data->size[0];
  shifted_data->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, shifted_data, i, &gq_emlrtRTEI);
  i = chis->size[0];
  chis->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, chis, i, &jq_emlrtRTEI);
  i = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, Simulation, i, &gq_emlrtRTEI);
  i = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, reflectivity, i, &gq_emlrtRTEI);
  emxInit_real_T(sp, &layerSld, 2, &rq_emlrtRTEI, true);
  emxInit_real_T(sp, &shifted_dat, 2, &nq_emlrtRTEI, true);
  emxInit_real_T(sp, &Simul, 2, &gq_emlrtRTEI, true);
  emxInit_real_T(sp, &b_shifted_dat, 2, &xp_emlrtRTEI, true);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i = (int32_T)(b_i + 1U);
    if ((i < 1) || (i > resols->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, resols->size[0], &nt_emlrtBCI, sp);
    }

    if (i > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, nbss->size[0], &ot_emlrtBCI, sp);
    }

    if (i > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, nbas->size[0], &pt_emlrtBCI, sp);
    }

    if (i > sfs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, sfs->size[0], &qt_emlrtBCI, sp);
    }

    if (i > qshifts->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, qshifts->size[0], &rt_emlrtBCI, sp);
    }

    if (i > backgs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &st_emlrtBCI, sp);
    }

    if (i > cRes->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cRes->size[1], &tt_emlrtBCI, sp);
    }

    if (i > cNbss->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cNbss->size[1], &ut_emlrtBCI, sp);
    }

    if (i > cNbas->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cNbas->size[1], &vt_emlrtBCI, sp);
    }

    if (i > cScales->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cScales->size[1], &wt_emlrtBCI, sp);
    }

    if (i > cShifts->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cShifts->size[1], &xt_emlrtBCI, sp);
    }

    if (i > cBacks->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cBacks->size[1], &yt_emlrtBCI, sp);
    }

    st.site = &ii_emlrtRSI;
    backSort(&st, cBacks->data[i - 1], cShifts->data[i - 1], cScales->data[i - 1],
             cNbas->data[i - 1], cNbss->data[i - 1], cRes->data[i - 1], backs,
             shifts, sf, nba, nbs, res, &backgs->data[i - 1], &qshifts->data[i -
             1], &sfs->data[i - 1], &nbas->data[i - 1], &nbss->data[i - 1],
             &resols->data[i - 1]);
    st.site = &ji_emlrtRSI;
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbas->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbas->size[0], &gu_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbss->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &fu_emlrtBCI, &st);
    }

    b_st.site = &pi_emlrtRSI;
    matlabEngineCaller_customLayers(&b_st, params, (real_T)b_i + 1.0, fname,
      path, nbas->data[b_i], nbss->data[b_i], shifted_dat, &layers);
    if (1 > params->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, params->size[1], &ms_emlrtBCI, &st);
    }

    if (i > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, allRoughs->size[0], &mt_emlrtBCI, &st);
    }

    allRoughs->data[i - 1] = params->data[0];
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &lt_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->size[0] = 0;
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &lt_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->size[1] = 0;
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &lt_emlrtBCI, sp);
    }

    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &lt_emlrtBCI, sp);
    }

    /* [outLayers, outSsubs(i)] = groupLayers_Mod(outLayers,allRoughs(i),geometry,nbas(i),nbss(i)); */
    /* sldProfile = makeSLDProfiles(nbas(i),nbss(i),outLayers,outSsubs(i),repeatLayers{i}); */
    i = sldProfiles->size[0] - 1;
    b_loop_ub = shifted_dat->size[0];
    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &kt_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &lq_emlrtRTEI);
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &kt_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &lq_emlrtRTEI);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &kt_emlrtBCI, sp);
      }

      sldProfiles->data[b_i].f1->data[i1] = shifted_dat->data[i1];
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &kt_emlrtBCI, sp);
      }

      sldProfiles->data[b_i].f1->data[i1 + sldProfiles->data[b_i].f1->size[0]] =
        shifted_dat->data[i1 + shifted_dat->size[0]];
    }

    /* if resample(i) == 1 */
    b_loop_ub = shifted_dat->size[0];
    i = b_shifted_dat->size[0] * b_shifted_dat->size[1];
    b_shifted_dat->size[0] = shifted_dat->size[0];
    b_shifted_dat->size[1] = 2;
    emxEnsureCapacity_real_T(sp, b_shifted_dat, i, &xp_emlrtRTEI);
    for (i = 0; i < b_loop_ub; i++) {
      b_shifted_dat->data[i] = shifted_dat->data[i];
    }

    for (i = 0; i < b_loop_ub; i++) {
      b_shifted_dat->data[i + b_shifted_dat->size[0]] = shifted_dat->data[i +
        shifted_dat->size[0]];
    }

    st.site = &ki_emlrtRSI;
    resampleLayers(&st, b_shifted_dat, layerSld);
    b_loop_ub = layerSld->size[0] * layerSld->size[1];
    i = layerSlds->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &jt_emlrtBCI, sp);
    }

    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &mq_emlrtRTEI);
    i = layerSlds->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &jt_emlrtBCI, sp);
    }

    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &mq_emlrtRTEI);
    i = layerSlds->size[0] - 1;
    i1 = layerSlds->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &jt_emlrtBCI, sp);
    }

    i1 = layerSlds->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &jt_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &jt_emlrtBCI, sp);
      }

      layerSlds->data[b_i].f1->data[i1] = layerSld->data[i1];
    }

    /* else */
    /*    layerSld = outLayers; */
    /*    layerSlds{i} = layerSld; */
    /* end */
    i = allData->size[1] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &it_emlrtBCI, sp);
    }

    i = shifted_dat->size[0] * shifted_dat->size[1];
    shifted_dat->size[0] = allData->data[b_i].f1->size[0];
    shifted_dat->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_dat, i, &nq_emlrtRTEI);
    i = allData->size[1] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &it_emlrtBCI, sp);
    }

    i = allData->size[1] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &it_emlrtBCI, sp);
    }

    b_loop_ub = allData->data[b_i].f1->size[0] * allData->data[b_i].f1->size[1];
    for (i = 0; i < b_loop_ub; i++) {
      i1 = allData->size[1] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &it_emlrtBCI, sp);
      }

      i1 = allData->size[1] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &it_emlrtBCI, sp);
      }

      i1 = allData->size[1] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &it_emlrtBCI, sp);
      }

      shifted_dat->data[i] = allData->data[b_i].f1->data[i];
    }

    i = dataLimits->size[1] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &et_emlrtBCI, sp);
    }

    i = b_i + 1;
    if ((i < 1) || (i > dataPresent->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, dataPresent->size[1], &ft_emlrtBCI, sp);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > qshifts->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, qshifts->size[0], &gt_emlrtBCI, sp);
    }

    b_loop_ub = b_i + 1;
    if ((b_loop_ub < 1) || (b_loop_ub > sfs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, sfs->size[0], &ht_emlrtBCI, sp);
    }

    st.site = &li_emlrtRSI;
    shiftdata(&st, sfs->data[b_loop_ub - 1], qshifts->data[i1 - 1],
              dataPresent->data[i - 1], shifted_dat, dataLimits->data[b_i].f1);
    b_loop_ub = shifted_dat->size[0] * shifted_dat->size[1];
    i = shifted_data->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &dt_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &oq_emlrtRTEI);
    i = shifted_data->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &dt_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &oq_emlrtRTEI);
    i = shifted_data->size[0] - 1;
    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &dt_emlrtBCI, sp);
    }

    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &dt_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &dt_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[i1] = shifted_dat->data[i1];
    }

    i = b_i + 1;
    if ((i < 1) || (i > backgs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &du_emlrtBCI, sp);
    }

    i = b_i + 1;
    if ((i < 1) || (i > (int32_T)numberOfContrasts)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, (int32_T)numberOfContrasts,
        &eu_emlrtBCI, sp);
    }

    i = b_i + 1;
    if ((i < 1) || (i > resols->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, resols->size[0], &xs_emlrtBCI, sp);
    }

    i1 = repeatLayers->size[1] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ys_emlrtBCI, sp);
    }

    i1 = simLimits->size[1] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &at_emlrtBCI, sp);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbss->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &bt_emlrtBCI, sp);
    }

    b_loop_ub = b_i + 1;
    if ((b_loop_ub < 1) || (b_loop_ub > nbas->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, nbas->size[0], &ct_emlrtBCI,
        sp);
    }

    st.site = &mi_emlrtRSI;
    callReflectivity(&st, nbas->data[b_loop_ub - 1], nbss->data[i1 - 1],
                     simLimits->data[b_i].f1, repeatLayers->data[b_i].f1,
                     shifted_dat, layerSld, 0.0, resols->data[i - 1],
                     b_shifted_dat, Simul);
    i = b_i + 1;
    if ((i < 1) || (i > backsType->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, backsType->size[1], &vs_emlrtBCI, sp);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > backgs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, backgs->size[0], &ws_emlrtBCI, sp);
    }

    st.site = &ni_emlrtRSI;
    applyBackgroundCorrection(&st, b_shifted_dat, Simul, shifted_dat,
      backgs->data[i1 - 1], backsType->data[i - 1]);
    if (10000 < b_shifted_dat->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, b_shifted_dat->size[0], &eb_emlrtECI, sp);
    }

    b_loop_ub = b_shifted_dat->size[0] * b_shifted_dat->size[1];
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &us_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = b_shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &pq_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &us_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &pq_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &us_emlrtBCI, sp);
    }

    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &us_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &us_emlrtBCI, sp);
      }

      reflectivity->data[b_i].f1->data[i1] = b_shifted_dat->data[i1];
    }

    if (10000 < Simul->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, Simul->size[0], &db_emlrtECI, sp);
    }

    b_loop_ub = Simul->size[0] * Simul->size[1];
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ts_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = Simul->size[0];
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &qq_emlrtRTEI);
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ts_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &qq_emlrtRTEI);
    i = Simulation->size[0] - 1;
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ts_emlrtBCI, sp);
    }

    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ts_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ts_emlrtBCI, sp);
      }

      Simulation->data[b_i].f1->data[i1] = Simul->data[i1];
    }

    i = b_i + 1;
    if ((i < 1) || (i > chis->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, chis->size[0], &ss_emlrtBCI, sp);
    }

    st.site = &oi_emlrtRSI;
    chis->data[i - 1] = chiSquared(&st, shifted_dat, b_shifted_dat, nParams);
  }

  emxFree_real_T(&b_shifted_dat);
  emxFree_real_T(&Simul);
  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&layerSld);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_custXY_single.c) */
