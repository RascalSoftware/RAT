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
static emlrtRSInfo li_emlrtRSI = { 85, /* lineNo */
  "standardTF_custXY_single",          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pathName */
};

static emlrtRSInfo mi_emlrtRSI = { 87, /* lineNo */
  "standardTF_custXY_single",          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pathName */
};

static emlrtRSInfo ni_emlrtRSI = { 96, /* lineNo */
  "standardTF_custXY_single",          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pathName */
};

static emlrtRSInfo oi_emlrtRSI = { 103,/* lineNo */
  "standardTF_custXY_single",          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pathName */
};

static emlrtRSInfo pi_emlrtRSI = { 106,/* lineNo */
  "standardTF_custXY_single",          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pathName */
};

static emlrtRSInfo qi_emlrtRSI = { 108,/* lineNo */
  "standardTF_custXY_single",          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pathName */
};

static emlrtRSInfo ri_emlrtRSI = { 113,/* lineNo */
  "standardTF_custXY_single",          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pathName */
};

static emlrtBCInfo wq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ar_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  97,                                  /* colNo */
  "backsType",                         /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo br_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  87,                                  /* colNo */
  "backgs",                            /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  128,                                 /* colNo */
  "resols",                            /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  69,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo er_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  56,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  48,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  40,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ir_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  73,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  47,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  36,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  29,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  62,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo or_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  17,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  50,                                  /* colNo */
  "resols",                            /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ur_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  27,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  16,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  6,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo as_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo sc_emlrtDCI = { 58, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo tc_emlrtDCI = { 51, /* lineNo */
  16,                                  /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo uc_emlrtDCI = { 60, /* lineNo */
  18,                                  /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo bb_emlrtECI = { 1,  /* nDims */
  111,                                 /* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtECInfo cb_emlrtECI = { 1,  /* nDims */
  110,                                 /* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtBCInfo cs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  125,                                 /* colNo */
  "backgs",                            /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ds_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  115,                                 /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo es_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  80,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  72,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  127,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  119,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo is_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  110,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo js_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  101,                                 /* colNo */
  "cScales",                           /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ks_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  90,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ls_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  79,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo cd_emlrtRTEI = { 84,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo dd_emlrtRTEI = { 78,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo ed_emlrtRTEI = { 72,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo fd_emlrtRTEI = { 66,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo bq_emlrtRTEI = { 58,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo cq_emlrtRTEI = { 15,/* lineNo */
  26,                                  /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo dq_emlrtRTEI = { 67,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo eq_emlrtRTEI = { 73,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo fq_emlrtRTEI = { 51,/* lineNo */
  10,                                  /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo gq_emlrtRTEI = { 79,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo hq_emlrtRTEI = { 93,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo jq_emlrtRTEI = { 97,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo kq_emlrtRTEI = { 103,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo lq_emlrtRTEI = { 104,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo mq_emlrtRTEI = { 110,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo nq_emlrtRTEI = { 111,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_single",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_single.m"/* pName */
};

static emlrtRTEInfo oq_emlrtRTEI = { 96,/* lineNo */
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
  covrtLogFcn(&emlrtCoverageInstance, 31U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 31U, 0U);

  /* coder.extrinsic('callModules');             */
  /* Pre-Allocation... */
  i = (int32_T)muDoubleScalarFloor(numberOfContrasts);
  if (numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &tc_emlrtDCI, sp);
  }

  loop_ub = (int32_T)numberOfContrasts;
  i1 = outSsubs->size[0];
  outSsubs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, outSsubs, i1, &bq_emlrtRTEI);
  if ((int32_T)numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &sc_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    outSsubs->data[i1] = 0.0;
  }

  if ((int32_T)numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &uc_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &fd_emlrtRTEI, sp);
  i = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, reflectivity, i, &cq_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 31U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 31U, 1U);
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &as_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &dq_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &as_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &dq_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &as_emlrtBCI, sp);
    }

    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &as_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &as_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &as_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &as_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &as_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 31U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 31U, 2U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &ed_emlrtRTEI, sp);
  i = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, Simulation, i, &cq_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 31U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 31U, 3U);
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &yr_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &eq_emlrtRTEI);
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &yr_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &eq_emlrtRTEI);
    i = Simulation->size[0] - 1;
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &yr_emlrtBCI, sp);
    }

    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &yr_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &yr_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &yr_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &yr_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &yr_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 31U, 0U, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 31U, 4U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &dd_emlrtRTEI, sp);
  i = allLayers->size[0];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_15(sp, allLayers, i, &cq_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 31U, 0U, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 31U, 5U);
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xr_emlrtBCI, sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &gq_emlrtRTEI);
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xr_emlrtBCI, sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &gq_emlrtRTEI);
    i = allLayers->size[0] - 1;
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &xr_emlrtBCI, sp);
    }

    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &xr_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xr_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xr_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 31U, 0U, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 31U, 6U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &cd_emlrtRTEI, sp);
  i = backgs->size[0];
  backgs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i, &fq_emlrtRTEI);
  i = qshifts->size[0];
  qshifts->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, qshifts, i, &fq_emlrtRTEI);
  i = sfs->size[0];
  sfs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, sfs, i, &fq_emlrtRTEI);
  i = nbas->size[0];
  nbas->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbas, i, &fq_emlrtRTEI);
  i = nbss->size[0];
  nbss->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbss, i, &fq_emlrtRTEI);
  i = resols->size[0];
  resols->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, resols, i, &fq_emlrtRTEI);
  i = allRoughs->size[0];
  allRoughs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, allRoughs, i, &fq_emlrtRTEI);
  i = allLayers->size[0];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_15(sp, allLayers, i, &cq_emlrtRTEI);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, sldProfiles, i, &cq_emlrtRTEI);
  i = layerSlds->size[0];
  layerSlds->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, layerSlds, i, &cq_emlrtRTEI);
  i = shifted_data->size[0];
  shifted_data->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, shifted_data, i, &cq_emlrtRTEI);
  i = chis->size[0];
  chis->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, chis, i, &fq_emlrtRTEI);
  i = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, Simulation, i, &cq_emlrtRTEI);
  i = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, reflectivity, i, &cq_emlrtRTEI);
  emxInit_real_T(sp, &layerSld, 2, &oq_emlrtRTEI, true);
  emxInit_real_T(sp, &shifted_dat, 2, &kq_emlrtRTEI, true);
  emxInit_real_T(sp, &Simul, 2, &cq_emlrtRTEI, true);
  emxInit_real_T(sp, &b_shifted_dat, 2, &iq_emlrtRTEI, true);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 31U, 0U, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 31U, 7U);
    st.site = &li_emlrtRSI;
    i = b_i + 1;
    if ((i < 1) || (i > cBacks->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cBacks->size[1], &ls_emlrtBCI, &st);
    }

    i = b_i + 1;
    if ((i < 1) || (i > cShifts->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cShifts->size[1], &ks_emlrtBCI, &st);
    }

    i = b_i + 1;
    if ((i < 1) || (i > cScales->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cScales->size[1], &js_emlrtBCI, &st);
    }

    i = b_i + 1;
    if ((i < 1) || (i > cNbas->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cNbas->size[1], &is_emlrtBCI, &st);
    }

    i = b_i + 1;
    if ((i < 1) || (i > cNbss->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cNbss->size[1], &hs_emlrtBCI, &st);
    }

    i = b_i + 1;
    if ((i < 1) || (i > cRes->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cRes->size[1], &gs_emlrtBCI, &st);
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
      emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &wr_emlrtBCI, &st);
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
      emlrtDynamicBoundsCheckR2012b(i, 1, qshifts->size[0], &vr_emlrtBCI, &st);
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
      emlrtDynamicBoundsCheckR2012b(i, 1, sfs->size[0], &ur_emlrtBCI, &st);
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
      emlrtDynamicBoundsCheckR2012b(i, 1, nbas->size[0], &tr_emlrtBCI, &st);
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
      emlrtDynamicBoundsCheckR2012b(i, 1, nbss->size[0], &sr_emlrtBCI, &st);
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
      emlrtDynamicBoundsCheckR2012b(i, 1, resols->size[0], &rr_emlrtBCI, &st);
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
    st.site = &mi_emlrtRSI;
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbas->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbas->size[0], &fs_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbss->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &es_emlrtBCI, &st);
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
      emlrtDynamicBoundsCheckR2012b(i, 1, allRoughs->size[0], &qr_emlrtBCI, &st);
    }

    allRoughs->data[i - 1] = params->data[0];
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &pr_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->size[0] = 0;
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &pr_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->size[1] = 0;
    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &pr_emlrtBCI, sp);
    }

    i = allLayers->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &pr_emlrtBCI, sp);
    }

    /* [outLayers, outSsubs(i)] = groupLayers_Mod(outLayers,allRoughs(i),geometry,nbas(i),nbss(i)); */
    /* sldProfile = makeSLDProfiles(nbas(i),nbss(i),outLayers,outSsubs(i),repeatLayers{i}); */
    i = sldProfiles->size[0] - 1;
    b_loop_ub = shifted_dat->size[0];
    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &or_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &hq_emlrtRTEI);
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &or_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &hq_emlrtRTEI);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &or_emlrtBCI, sp);
      }

      sldProfiles->data[b_i].f1->data[i1] = shifted_dat->data[i1];
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &or_emlrtBCI, sp);
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

    st.site = &ni_emlrtRSI;
    resampleLayers(&st, b_shifted_dat, layerSld);
    b_loop_ub = layerSld->size[0] * layerSld->size[1];
    i = layerSlds->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nr_emlrtBCI, sp);
    }

    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &jq_emlrtRTEI);
    i = layerSlds->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nr_emlrtBCI, sp);
    }

    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &jq_emlrtRTEI);
    i = layerSlds->size[0] - 1;
    i1 = layerSlds->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &nr_emlrtBCI, sp);
    }

    i1 = layerSlds->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &nr_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nr_emlrtBCI, sp);
      }

      layerSlds->data[b_i].f1->data[i1] = layerSld->data[i1];
    }

    /* else */
    /*    layerSld = outLayers; */
    /*    layerSlds{i} = layerSld; */
    /* end */
    i = allData->size[1] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &mr_emlrtBCI, sp);
    }

    i = shifted_dat->size[0] * shifted_dat->size[1];
    shifted_dat->size[0] = allData->data[b_i].f1->size[0];
    shifted_dat->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_dat, i, &kq_emlrtRTEI);
    i = allData->size[1] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &mr_emlrtBCI, sp);
    }

    i = allData->size[1] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &mr_emlrtBCI, sp);
    }

    b_loop_ub = allData->data[b_i].f1->size[0] * allData->data[b_i].f1->size[1];
    for (i = 0; i < b_loop_ub; i++) {
      i1 = allData->size[1] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &mr_emlrtBCI, sp);
      }

      i1 = allData->size[1] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &mr_emlrtBCI, sp);
      }

      i1 = allData->size[1] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &mr_emlrtBCI, sp);
      }

      shifted_dat->data[i] = allData->data[b_i].f1->data[i];
    }

    i = dataLimits->size[1] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ir_emlrtBCI, sp);
    }

    i = b_i + 1;
    if ((i < 1) || (i > dataPresent->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, dataPresent->size[1], &jr_emlrtBCI, sp);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > qshifts->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, qshifts->size[0], &kr_emlrtBCI, sp);
    }

    b_loop_ub = b_i + 1;
    if ((b_loop_ub < 1) || (b_loop_ub > sfs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, sfs->size[0], &lr_emlrtBCI, sp);
    }

    st.site = &oi_emlrtRSI;
    shiftdata(&st, sfs->data[b_loop_ub - 1], qshifts->data[i1 - 1],
              dataPresent->data[i - 1], shifted_dat, dataLimits->data[b_i].f1);
    b_loop_ub = shifted_dat->size[0] * shifted_dat->size[1];
    i = shifted_data->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &hr_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &lq_emlrtRTEI);
    i = shifted_data->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &hr_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &lq_emlrtRTEI);
    i = shifted_data->size[0] - 1;
    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hr_emlrtBCI, sp);
    }

    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hr_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &hr_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[i1] = shifted_dat->data[i1];
    }

    i = b_i + 1;
    if ((i < 1) || (i > backgs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &cs_emlrtBCI, sp);
    }

    i = b_i + 1;
    if ((i < 1) || (i > (int32_T)numberOfContrasts)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, (int32_T)numberOfContrasts,
        &ds_emlrtBCI, sp);
    }

    i = b_i + 1;
    if ((i < 1) || (i > resols->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, resols->size[0], &cr_emlrtBCI, sp);
    }

    i1 = repeatLayers->size[1] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &dr_emlrtBCI, sp);
    }

    i1 = simLimits->size[1] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &er_emlrtBCI, sp);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbss->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &fr_emlrtBCI, sp);
    }

    b_loop_ub = b_i + 1;
    if ((b_loop_ub < 1) || (b_loop_ub > nbas->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, nbas->size[0], &gr_emlrtBCI,
        sp);
    }

    st.site = &pi_emlrtRSI;
    callReflectivity(&st, nbas->data[b_loop_ub - 1], nbss->data[i1 - 1],
                     simLimits->data[b_i].f1, repeatLayers->data[b_i].f1,
                     shifted_dat, layerSld, 0.0, resols->data[i - 1],
                     b_shifted_dat, Simul);
    i = b_i + 1;
    if ((i < 1) || (i > backsType->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, backsType->size[1], &ar_emlrtBCI, sp);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > backgs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, backgs->size[0], &br_emlrtBCI, sp);
    }

    st.site = &qi_emlrtRSI;
    applyBackgroundCorrection(&st, b_shifted_dat, Simul, shifted_dat,
      backgs->data[i1 - 1], backsType->data[i - 1]);
    if (10000 < b_shifted_dat->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, b_shifted_dat->size[0], &cb_emlrtECI, sp);
    }

    b_loop_ub = b_shifted_dat->size[0] * b_shifted_dat->size[1];
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &yq_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = b_shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &mq_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &yq_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &mq_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &yq_emlrtBCI, sp);
    }

    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &yq_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &yq_emlrtBCI, sp);
      }

      reflectivity->data[b_i].f1->data[i1] = b_shifted_dat->data[i1];
    }

    if (10000 < Simul->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, Simul->size[0], &bb_emlrtECI, sp);
    }

    b_loop_ub = Simul->size[0] * Simul->size[1];
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xq_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = Simul->size[0];
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &nq_emlrtRTEI);
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xq_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &nq_emlrtRTEI);
    i = Simulation->size[0] - 1;
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &xq_emlrtBCI, sp);
    }

    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &xq_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xq_emlrtBCI, sp);
      }

      Simulation->data[b_i].f1->data[i1] = Simul->data[i1];
    }

    i = b_i + 1;
    if ((i < 1) || (i > chis->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, chis->size[0], &wq_emlrtBCI, sp);
    }

    st.site = &ri_emlrtRSI;
    chis->data[i - 1] = chiSquared(&st, shifted_dat, b_shifted_dat, nParams);
  }

  emxFree_real_T(&b_shifted_dat);
  emxFree_real_T(&Simul);
  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&layerSld);
  covrtLogFor(&emlrtCoverageInstance, 31U, 0U, 3, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_custXY_single.c) */
