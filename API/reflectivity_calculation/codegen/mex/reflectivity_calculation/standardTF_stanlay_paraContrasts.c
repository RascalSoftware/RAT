/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_stanlay_paraContrasts.c
 *
 * Code generation for function 'standardTF_stanlay_paraContrasts'
 *
 */

/* Include files */
#include "standardTF_stanlay_paraContrasts.h"
#include "allocateLayersForContrast.h"
#include "allocateParamsToLayers.h"
#include "applyBackgroundCorrection.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "groupLayers_Mod.h"
#include "makeSLDProfileXY.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"

/* Variable Definitions */
static emlrtRSInfo ng_emlrtRSI = { 78, /* lineNo */
  "standardTF_stanlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo og_emlrtRSI = { 81, /* lineNo */
  "standardTF_stanlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo pg_emlrtRSI = { 84, /* lineNo */
  "standardTF_stanlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo qg_emlrtRSI = { 85, /* lineNo */
  "standardTF_stanlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo rg_emlrtRSI = { 93, /* lineNo */
  "standardTF_stanlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo sg_emlrtRSI = { 102,/* lineNo */
  "standardTF_stanlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo tg_emlrtRSI = { 109,/* lineNo */
  "standardTF_stanlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo ug_emlrtRSI = { 111,/* lineNo */
  "standardTF_stanlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo vg_emlrtRSI = { 113,/* lineNo */
  "standardTF_stanlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo wg_emlrtRSI = { 119,/* lineNo */
  "standardTF_stanlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pathName */
};

static emlrtRTEInfo xb_emlrtRTEI = { 62,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = { 67,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = { 72,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtDCInfo pb_emlrtDCI = { 80, /* lineNo */
  14,                                  /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo bc_emlrtRTEI = { 80,/* lineNo */
  12,                                  /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtBCInfo hi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  79,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ii_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  90,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ji_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  101,                                 /* colNo */
  "cScales",                           /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ki_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  110,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo li_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  119,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  127,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ni_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  27,                                  /* colNo */
  "params",                            /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  43,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  51,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  73,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ri_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  125,                                 /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo si_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  89,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo qb_emlrtDCI = { 46, /* lineNo */
  16,                                  /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ti_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ui_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  6,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  16,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  27,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo aj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  50,                                  /* colNo */
  "resols",                            /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  5,                                   /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ej_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  52,                                  /* colNo */
  "contrastLayers",                    /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  67,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  89,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  97,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ij_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  17,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  8,                                   /* colNo */
  "resample",                          /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  101,                                 /* lineNo */
  8,                                   /* colNo */
  "resample",                          /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  62,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  29,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  36,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  47,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  73,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  40,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  48,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  56,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  69,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  106,                                 /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  128,                                 /* colNo */
  "resols",                            /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ak_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  116,                                 /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  87,                                  /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ck_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  97,                                  /* colNo */
  "backsType",                         /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  115,                                 /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ek_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  117,                                 /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  119,                                 /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo xl_emlrtRTEI = { 15,/* lineNo */
  26,                                  /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo yl_emlrtRTEI = { 63,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo am_emlrtRTEI = { 68,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo bm_emlrtRTEI = { 73,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo cm_emlrtRTEI = { 46,/* lineNo */
  10,                                  /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo dm_emlrtRTEI = { 96,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo em_emlrtRTEI = { 99,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo fm_emlrtRTEI = { 93,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo gm_emlrtRTEI = { 106,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo hm_emlrtRTEI = { 103,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo im_emlrtRTEI = { 109,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo jm_emlrtRTEI = { 115,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo km_emlrtRTEI = { 117,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo lm_emlrtRTEI = { 78,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo mm_emlrtRTEI = { 84,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo nm_emlrtRTEI = { 102,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo om_emlrtRTEI = { 93,/* lineNo */
  22,                                  /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

/* Function Definitions */
void c_standardTF_stanlay_paraContra(const emlrtStack *sp, const emxArray_real_T
  *resample, real_T numberOfContrasts, const emxArray_char_T *geometry, const
  emxArray_cell_wrap_0 *repeatLayers, const emxArray_real_T *cBacks, const
  emxArray_real_T *cShifts, const emxArray_real_T *cScales, const
  emxArray_real_T *cNbas, const emxArray_real_T *cNbss, const emxArray_real_T
  *cRes, const emxArray_real_T *backs, const emxArray_real_T *shifts, const
  emxArray_real_T *sf, const emxArray_real_T *nba, const emxArray_real_T *nbs,
  const emxArray_real_T *res, const emxArray_real_T *dataPresent, const
  emxArray_cell_wrap_1 *allData, const emxArray_cell_wrap_0 *dataLimits, const
  emxArray_cell_wrap_0 *simLimits, real_T nParams, const emxArray_real_T *params,
  const emxArray_cell_wrap_11 *contrastLayers, const emxArray_cell_wrap_3
  *layersDetails, const emxArray_real_T *backsType, real_T calcSld,
  emxArray_real_T *outSsubs, emxArray_real_T *backgs, emxArray_real_T *qshifts,
  emxArray_real_T *sfs, emxArray_real_T *nbas, emxArray_real_T *nbss,
  emxArray_real_T *resols, emxArray_real_T *chis, emxArray_cell_wrap_11
  *reflectivity, emxArray_cell_wrap_6 *Simulation, emxArray_cell_wrap_1
  *shifted_data, emxArray_cell_wrap_1 *layerSlds, emxArray_cell_wrap_11
  *sldProfiles, emxArray_cell_wrap_11 *allLayers, emxArray_real_T *allRoughs)
{
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T b_i;
  int32_T loop_ub;
  emxArray_cell_wrap_16 *outParameterisedLayers;
  emxArray_real_T *thisContrastLayers;
  emxArray_real_T *sldProfile;
  emxArray_real_T *layerSld;
  emxArray_real_T *shifted_dat;
  emxArray_real_T *b_sldProfile;
  int32_T i3;
  real_T thisCalcSld;
  int32_T i4;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 23U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 0U);

  /* Pre-Allocation... */
  i = (int32_T)muDoubleScalarFloor(numberOfContrasts);
  if (numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &qb_emlrtDCI, sp);
  }

  /*   */
  i1 = (int32_T)numberOfContrasts;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &xb_emlrtRTEI, sp);
  i2 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_11(sp, reflectivity, i2, &xl_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 23U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 1U);
    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ti_emlrtBCI, sp);
    }

    i2 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i2, &yl_emlrtRTEI);
    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ti_emlrtBCI, sp);
    }

    i2 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i2, &yl_emlrtRTEI);
    i2 = reflectivity->size[0] - 1;
    loop_ub = reflectivity->size[0] - 1;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &ti_emlrtBCI, sp);
    }

    loop_ub = reflectivity->size[0] - 1;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &ti_emlrtBCI, sp);
    }

    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ti_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ti_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ti_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ti_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 23U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 2U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &yb_emlrtRTEI, sp);
  i2 = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, Simulation, i2, &xl_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 23U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 3U);
    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ui_emlrtBCI, sp);
    }

    i2 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i2, &am_emlrtRTEI);
    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ui_emlrtBCI, sp);
    }

    i2 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i2, &am_emlrtRTEI);
    i2 = Simulation->size[0] - 1;
    loop_ub = Simulation->size[0] - 1;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &ui_emlrtBCI, sp);
    }

    loop_ub = Simulation->size[0] - 1;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &ui_emlrtBCI, sp);
    }

    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ui_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ui_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ui_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ui_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 23U, 0U, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 4U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &ac_emlrtRTEI, sp);
  i2 = allLayers->size[0];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_11(sp, allLayers, i2, &xl_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 23U, 0U, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 5U);
    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &vi_emlrtBCI, sp);
    }

    i2 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i2, &bm_emlrtRTEI);
    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &vi_emlrtBCI, sp);
    }

    i2 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i2, &bm_emlrtRTEI);
    i2 = allLayers->size[0] - 1;
    loop_ub = allLayers->size[0] - 1;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &vi_emlrtBCI, sp);
    }

    loop_ub = allLayers->size[0] - 1;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &vi_emlrtBCI, sp);
    }

    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &vi_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &vi_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
  }

  emxInit_cell_wrap_16(sp, &outParameterisedLayers, 2, &lm_emlrtRTEI, true);
  covrtLogFor(&emlrtCoverageInstance, 23U, 0U, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 6U);
  st.site = &ng_emlrtRSI;
  allocateParamsToLayers(&st, params, layersDetails, outParameterisedLayers);
  if ((int32_T)numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &pb_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &bc_emlrtRTEI, sp);
  i = backgs->size[0];
  backgs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i, &cm_emlrtRTEI);
  i = qshifts->size[0];
  qshifts->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, qshifts, i, &cm_emlrtRTEI);
  i = sfs->size[0];
  sfs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, sfs, i, &cm_emlrtRTEI);
  i = nbas->size[0];
  nbas->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbas, i, &cm_emlrtRTEI);
  i = nbss->size[0];
  nbss->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbss, i, &cm_emlrtRTEI);
  i = resols->size[0];
  resols->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, resols, i, &cm_emlrtRTEI);
  i = allRoughs->size[0];
  allRoughs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, allRoughs, i, &cm_emlrtRTEI);
  i = outSsubs->size[0];
  outSsubs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, outSsubs, i, &cm_emlrtRTEI);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_11(sp, sldProfiles, i, &xl_emlrtRTEI);
  i = layerSlds->size[0];
  layerSlds->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, layerSlds, i, &xl_emlrtRTEI);
  i = shifted_data->size[0];
  shifted_data->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, shifted_data, i, &xl_emlrtRTEI);
  i = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, Simulation, i, &xl_emlrtRTEI);
  i = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_11(sp, reflectivity, i, &xl_emlrtRTEI);
  i = chis->size[0];
  chis->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, chis, i, &cm_emlrtRTEI);
  emxInit_real_T(sp, &thisContrastLayers, 2, &mm_emlrtRTEI, true);
  emxInit_real_T(sp, &sldProfile, 2, &fm_emlrtRTEI, true);
  emxInit_real_T(sp, &layerSld, 2, &nm_emlrtRTEI, true);
  emxInit_real_T(sp, &shifted_dat, 2, &im_emlrtRTEI, true);
  emxInit_real_T(sp, &b_sldProfile, 2, &om_emlrtRTEI, true);
  for (b_i = 0; b_i < i1; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 23U, 0U, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 7U);
    st.site = &og_emlrtRSI;
    i = b_i + 1;
    if ((i < 1) || (i > cBacks->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cBacks->size[1], &hi_emlrtBCI, &st);
    }

    i = b_i + 1;
    if ((i < 1) || (i > cShifts->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cShifts->size[1], &ii_emlrtBCI, &st);
    }

    i = b_i + 1;
    if ((i < 1) || (i > cScales->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cScales->size[1], &ji_emlrtBCI, &st);
    }

    i = b_i + 1;
    if ((i < 1) || (i > cNbas->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cNbas->size[1], &ki_emlrtBCI, &st);
    }

    i = b_i + 1;
    if ((i < 1) || (i > cNbss->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cNbss->size[1], &li_emlrtBCI, &st);
    }

    i = b_i + 1;
    if ((i < 1) || (i > cRes->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, cRes->size[1], &mi_emlrtBCI, &st);
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
      emlrtDynamicBoundsCheckR2012b(i2, 1, backgs->size[0], &wi_emlrtBCI, &st);
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
      emlrtDynamicBoundsCheckR2012b(i2, 1, qshifts->size[0], &xi_emlrtBCI, &st);
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
      emlrtDynamicBoundsCheckR2012b(i2, 1, sfs->size[0], &yi_emlrtBCI, &st);
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
      emlrtDynamicBoundsCheckR2012b(i2, 1, nbas->size[0], &aj_emlrtBCI, &st);
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
      emlrtDynamicBoundsCheckR2012b(i2, 1, nbss->size[0], &bj_emlrtBCI, &st);
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
      emlrtDynamicBoundsCheckR2012b(i2, 1, resols->size[0], &cj_emlrtBCI, &st);
    }

    resols->data[i2 - 1] = res->data[i - 1];

    /* end */
    if (1 > params->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, params->size[1], &ni_emlrtBCI, sp);
    }

    if (i2 > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, allRoughs->size[0], &dj_emlrtBCI, sp);
    }

    allRoughs->data[i2 - 1] = params->data[0];
    i = contrastLayers->size[1] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ej_emlrtBCI, sp);
    }

    st.site = &pg_emlrtRSI;
    allocateLayersForContrast(&st, contrastLayers->data[b_i].f1,
      outParameterisedLayers, thisContrastLayers);
    i = b_i + 1;
    if ((i < 1) || (i > allRoughs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, allRoughs->size[0], &fj_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > nbas->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, nbas->size[0], &gj_emlrtBCI, sp);
    }

    loop_ub = b_i + 1;
    if ((loop_ub < 1) || (loop_ub > nbss->size[0])) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, nbss->size[0], &hj_emlrtBCI, sp);
    }

    i3 = b_i + 1;
    if ((i3 < 1) || (i3 > outSsubs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, outSsubs->size[0], &ij_emlrtBCI, sp);
    }

    st.site = &qg_emlrtRSI;
    groupLayers_Mod(&st, thisContrastLayers, allRoughs->data[i - 1], geometry,
                    nbas->data[i2 - 1], nbss->data[loop_ub - 1], layerSld,
                    &outSsubs->data[i3 - 1]);
    thisCalcSld = calcSld;
    i = b_i + 1;
    if ((i < 1) || (i > resample->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, resample->size[1], &jj_emlrtBCI, sp);
    }

    if (covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 0, resample->data[i - 1] ==
                   1.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 8U);
      thisCalcSld = 1.0;
    }

    if (covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 1, thisCalcSld == 1.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 9U);
      st.site = &rg_emlrtRSI;
      i = b_i + 1;
      if ((i < 1) || (i > nbas->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i, 1, nbas->size[0], &oi_emlrtBCI, &st);
      }

      i = b_i + 1;
      if ((i < 1) || (i > nbss->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i, 1, nbss->size[0], &pi_emlrtBCI, &st);
      }

      i = b_i + 1;
      if ((i < 1) || (i > outSsubs->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i, 1, outSsubs->size[0], &qi_emlrtBCI, &st);
      }

      i = repeatLayers->size[1] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &si_emlrtBCI, &st);
      }

      covrtLogFcn(&emlrtCoverageInstance, 9U, 0U);
      covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 0U);
      if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 0, repeatLayers->data[b_i].
                     f1[0] == 0.0)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 1U);
        thisCalcSld = 1.0;
      } else {
        covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 2U);
        thisCalcSld = repeatLayers->data[b_i].f1[1];
      }

      covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 3U);
      b_st.site = &y_emlrtRSI;
      makeSLDProfileXY(&b_st, nbas->data[b_i], nbss->data[b_i], outSsubs->
                       data[b_i], layerSld, layerSld->size[0], thisCalcSld,
                       b_sldProfile);
      i = sldProfile->size[0] * sldProfile->size[1];
      sldProfile->size[0] = b_sldProfile->size[0];
      sldProfile->size[1] = 2;
      emxEnsureCapacity_real_T(sp, sldProfile, i, &fm_emlrtRTEI);
      loop_ub = b_sldProfile->size[0] * b_sldProfile->size[1];
      for (i = 0; i < loop_ub; i++) {
        sldProfile->data[i] = b_sldProfile->data[i];
      }
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 10U);
      i = sldProfile->size[0] * sldProfile->size[1];
      sldProfile->size[0] = 1;
      sldProfile->size[1] = 3;
      emxEnsureCapacity_real_T(sp, sldProfile, i, &dm_emlrtRTEI);
      sldProfile->data[0] = 0.0;
      sldProfile->data[1] = 0.0;
      sldProfile->data[2] = 0.0;
    }

    covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 11U);
    loop_ub = sldProfile->size[0] * sldProfile->size[1];
    i = sldProfiles->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &kj_emlrtBCI, sp);
    }

    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &em_emlrtRTEI);
    i = sldProfiles->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &kj_emlrtBCI, sp);
    }

    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = sldProfile->size[1];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &em_emlrtRTEI);
    i = sldProfiles->size[0] - 1;
    i2 = sldProfiles->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &kj_emlrtBCI, sp);
    }

    i2 = sldProfiles->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &kj_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &kj_emlrtBCI, sp);
      }

      sldProfiles->data[b_i].f1->data[i2] = sldProfile->data[i2];
    }

    i = b_i + 1;
    if ((i < 1) || (i > resample->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, resample->size[1], &lj_emlrtBCI, sp);
    }

    if (covrtLogIf(&emlrtCoverageInstance, 23U, 0U, 2, resample->data[i - 1] ==
                   1.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 12U);
      st.site = &sg_emlrtRSI;
      resampleLayers(&st, sldProfile, layerSld);
      loop_ub = layerSld->size[0] * layerSld->size[1];
      i = layerSlds->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nj_emlrtBCI, sp);
      }

      i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
      layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
      emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &hm_emlrtRTEI);
      i = layerSlds->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nj_emlrtBCI, sp);
      }

      i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
      layerSlds->data[b_i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &hm_emlrtRTEI);
      i = layerSlds->size[0] - 1;
      i2 = layerSlds->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &nj_emlrtBCI, sp);
      }

      i2 = layerSlds->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &nj_emlrtBCI, sp);
      }

      for (i2 = 0; i2 < loop_ub; i2++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nj_emlrtBCI, sp);
        }

        layerSlds->data[b_i].f1->data[i2] = layerSld->data[i2];
      }
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 13U);
      loop_ub = layerSld->size[0] * layerSld->size[1];
      i = layerSlds->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &mj_emlrtBCI, sp);
      }

      i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
      layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
      emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &gm_emlrtRTEI);
      i = layerSlds->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &mj_emlrtBCI, sp);
      }

      i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
      layerSlds->data[b_i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &gm_emlrtRTEI);
      i = layerSlds->size[0] - 1;
      i2 = layerSlds->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &mj_emlrtBCI, sp);
      }

      i2 = layerSlds->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &mj_emlrtBCI, sp);
      }

      for (i2 = 0; i2 < loop_ub; i2++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &mj_emlrtBCI, sp);
        }

        layerSlds->data[b_i].f1->data[i2] = layerSld->data[i2];
      }
    }

    covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 14U);
    i = allData->size[1] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &oj_emlrtBCI, sp);
    }

    i = shifted_dat->size[0] * shifted_dat->size[1];
    shifted_dat->size[0] = allData->data[b_i].f1->size[0];
    shifted_dat->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_dat, i, &im_emlrtRTEI);
    i = allData->size[1] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &oj_emlrtBCI, sp);
    }

    i = allData->size[1] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &oj_emlrtBCI, sp);
    }

    loop_ub = allData->data[b_i].f1->size[0] * allData->data[b_i].f1->size[1];
    for (i = 0; i < loop_ub; i++) {
      i2 = allData->size[1] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &oj_emlrtBCI, sp);
      }

      i2 = allData->size[1] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &oj_emlrtBCI, sp);
      }

      i2 = allData->size[1] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &oj_emlrtBCI, sp);
      }

      shifted_dat->data[i] = allData->data[b_i].f1->data[i];
    }

    i = b_i + 1;
    if ((i < 1) || (i > sfs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, sfs->size[0], &pj_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > qshifts->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, qshifts->size[0], &qj_emlrtBCI, sp);
    }

    loop_ub = b_i + 1;
    if ((loop_ub < 1) || (loop_ub > dataPresent->size[1])) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, dataPresent->size[1],
        &rj_emlrtBCI, sp);
    }

    i3 = dataLimits->size[1] - 1;
    if (b_i > i3) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &sj_emlrtBCI, sp);
    }

    st.site = &tg_emlrtRSI;
    shiftdata(&st, sfs->data[i - 1], qshifts->data[i2 - 1], dataPresent->
              data[loop_ub - 1], shifted_dat, dataLimits->data[b_i].f1);
    i = b_i + 1;
    if ((i < 1) || (i > backgs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &ri_emlrtBCI, sp);
    }

    i = b_i + 1;
    if ((i < 1) || (i > nbas->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, nbas->size[0], &tj_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > nbss->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, nbss->size[0], &uj_emlrtBCI, sp);
    }

    loop_ub = simLimits->size[1] - 1;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &vj_emlrtBCI, sp);
    }

    loop_ub = repeatLayers->size[1] - 1;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &wj_emlrtBCI, sp);
    }

    loop_ub = b_i + 1;
    if ((loop_ub < 1) || (loop_ub > outSsubs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, outSsubs->size[0], &xj_emlrtBCI,
        sp);
    }

    i3 = b_i + 1;
    if ((i3 < 1) || (i3 > resols->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, resols->size[0], &yj_emlrtBCI, sp);
    }

    i4 = Simulation->size[0] - 1;
    if (b_i > i4) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i4, &ak_emlrtBCI, sp);
    }

    st.site = &ug_emlrtRSI;
    callReflectivity(&st, nbas->data[i - 1], nbss->data[i2 - 1], simLimits->
                     data[b_i].f1, repeatLayers->data[b_i].f1, shifted_dat,
                     layerSld, outSsubs->data[loop_ub - 1], resols->data[i3 - 1],
                     b_sldProfile, Simulation->data[b_i].f1);
    i = Simulation->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ak_emlrtBCI, sp);
    }

    i = b_i + 1;
    if ((i < 1) || (i > backgs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &bk_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > backsType->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, backsType->size[1], &ck_emlrtBCI, sp);
    }

    st.site = &vg_emlrtRSI;
    applyBackgroundCorrection(&st, b_sldProfile, Simulation->data[b_i].f1,
      shifted_dat, backgs->data[i - 1], backsType->data[i2 - 1]);
    loop_ub = b_sldProfile->size[0] * b_sldProfile->size[1];
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &dk_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = b_sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &jm_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &dk_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &jm_emlrtRTEI);
    i = reflectivity->size[0] - 1;
    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &dk_emlrtBCI, sp);
    }

    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &dk_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &dk_emlrtBCI, sp);
      }

      reflectivity->data[b_i].f1->data[i2] = b_sldProfile->data[i2];
    }

    loop_ub = shifted_dat->size[0] * shifted_dat->size[1];
    i = shifted_data->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ek_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &km_emlrtRTEI);
    i = shifted_data->size[0] - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ek_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &km_emlrtRTEI);
    i = shifted_data->size[0] - 1;
    i2 = shifted_data->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ek_emlrtBCI, sp);
    }

    i2 = shifted_data->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ek_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ek_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[i2] = shifted_dat->data[i2];
    }

    i = b_i + 1;
    if ((i < 1) || (i > chis->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, chis->size[0], &fk_emlrtBCI, sp);
    }

    st.site = &wg_emlrtRSI;
    chis->data[i - 1] = chiSquared(&st, shifted_dat, b_sldProfile, nParams);
  }

  emxFree_real_T(&b_sldProfile);
  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&layerSld);
  emxFree_real_T(&sldProfile);
  emxFree_real_T(&thisContrastLayers);
  emxFree_cell_wrap_16(&outParameterisedLayers);
  covrtLogFor(&emlrtCoverageInstance, 23U, 0U, 3, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_stanlay_paraContrasts.c) */
