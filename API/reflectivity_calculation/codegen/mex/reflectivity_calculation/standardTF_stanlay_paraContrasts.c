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

/* Variable Definitions */
static emlrtRSInfo lg_emlrtRSI = { 78, /* lineNo */
  "standardTF_stanlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo mg_emlrtRSI = { 81, /* lineNo */
  "standardTF_stanlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo ng_emlrtRSI = { 84, /* lineNo */
  "standardTF_stanlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo og_emlrtRSI = { 85, /* lineNo */
  "standardTF_stanlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo pg_emlrtRSI = { 93, /* lineNo */
  "standardTF_stanlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo qg_emlrtRSI = { 102,/* lineNo */
  "standardTF_stanlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo rg_emlrtRSI = { 109,/* lineNo */
  "standardTF_stanlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo sg_emlrtRSI = { 111,/* lineNo */
  "standardTF_stanlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo tg_emlrtRSI = { 113,/* lineNo */
  "standardTF_stanlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo ug_emlrtRSI = { 119,/* lineNo */
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

static emlrtDCInfo ib_emlrtDCI = { 80, /* lineNo */
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
  111,                                 /* lineNo */
  125,                                 /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo jb_emlrtDCI = { 46, /* lineNo */
  16,                                  /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo pi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ri_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo si_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  72,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ti_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  82,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ui_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  93,                                  /* colNo */
  "cScales",                           /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  104,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  113,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  122,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  6,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo aj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  16,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  27,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ej_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  50,                                  /* colNo */
  "resols",                            /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  5,                                   /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  52,                                  /* colNo */
  "contrastLayers",                    /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  67,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ij_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  89,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  97,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  17,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  8,                                   /* colNo */
  "resample",                          /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  38,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  46,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  64,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  76,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  101,                                 /* lineNo */
  8,                                   /* colNo */
  "resample",                          /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  62,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  29,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  36,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  47,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yj_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  73,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ak_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  40,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  48,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ck_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  56,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  69,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ek_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  106,                                 /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  128,                                 /* colNo */
  "resols",                            /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  87,                                  /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  97,                                  /* colNo */
  "backsType",                         /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ik_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  115,                                 /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  116,                                 /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  117,                                 /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  119,                                 /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo sk_emlrtRTEI = { 15,/* lineNo */
  26,                                  /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo tk_emlrtRTEI = { 63,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo uk_emlrtRTEI = { 68,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo vk_emlrtRTEI = { 73,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo wk_emlrtRTEI = { 46,/* lineNo */
  10,                                  /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo xk_emlrtRTEI = { 96,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo yk_emlrtRTEI = { 99,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo al_emlrtRTEI = { 93,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo bl_emlrtRTEI = { 106,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo cl_emlrtRTEI = { 103,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo dl_emlrtRTEI = { 109,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo el_emlrtRTEI = { 115,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo fl_emlrtRTEI = { 116,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo gl_emlrtRTEI = { 117,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo hl_emlrtRTEI = { 93,/* lineNo */
  22,                                  /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo il_emlrtRTEI = { 102,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo jl_emlrtRTEI = { 84,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo kl_emlrtRTEI = { 78,/* lineNo */
  1,                                   /* colNo */
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
  int32_T ub_loop;
  int32_T i;
  int32_T i1;
  int32_T b_i;
  emxArray_cell_wrap_17 *outParameterisedLayers;
  int32_T i2;
  int32_T c_i;
  emxArray_real_T *thisContrastLayers;
  emxArray_real_T *sldProfile;
  emxArray_real_T *layerSld;
  emxArray_real_T *reflect;
  emxArray_real_T *Simul;
  emxArray_real_T *shifted_dat;
  real_T thisCalcSld;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  int32_T i3;
  int32_T i4;
  int32_T loop_ub;
  int32_T i5;
  jmp_buf * volatile emlrtJBStack;
  emlrtStack st;
  emlrtStack b_st;
  jmp_buf b_emlrtJBEnviron;
  emlrtStack c_st;
  boolean_T emlrtHadParallelError = false;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* Pre-Allocation... */
  ub_loop = (int32_T)muDoubleScalarFloor(numberOfContrasts);
  if (numberOfContrasts != ub_loop) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &jb_emlrtDCI, sp);
  }

  /*   */
  i = (int32_T)numberOfContrasts;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &xb_emlrtRTEI, sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_111(sp, reflectivity, i1, &sk_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pi_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &tk_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pi_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &tk_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &pi_emlrtBCI, sp);
    }

    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &pi_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pi_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pi_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pi_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pi_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &yb_emlrtRTEI, sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, Simulation, i1, &sk_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &qi_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &uk_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &qi_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &uk_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &qi_emlrtBCI, sp);
    }

    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &qi_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &qi_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &qi_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &qi_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &qi_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &ac_emlrtRTEI, sp);
  i1 = allLayers->size[0];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_111(sp, allLayers, i1, &sk_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ri_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &vk_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ri_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &vk_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ri_emlrtBCI, sp);
    }

    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ri_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ri_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ri_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
  }

  emxInit_cell_wrap_17(sp, &outParameterisedLayers, 2, &kl_emlrtRTEI, true);
  st.site = &lg_emlrtRSI;
  allocateParamsToLayers(&st, params, layersDetails, outParameterisedLayers);
  if ((int32_T)numberOfContrasts != ub_loop) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &ib_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &bc_emlrtRTEI, sp);
  ub_loop = backgs->size[0];
  backgs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, ub_loop, &wk_emlrtRTEI);
  ub_loop = qshifts->size[0];
  qshifts->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, qshifts, ub_loop, &wk_emlrtRTEI);
  ub_loop = sfs->size[0];
  sfs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, sfs, ub_loop, &wk_emlrtRTEI);
  ub_loop = nbas->size[0];
  nbas->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbas, ub_loop, &wk_emlrtRTEI);
  ub_loop = nbss->size[0];
  nbss->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbss, ub_loop, &wk_emlrtRTEI);
  ub_loop = resols->size[0];
  resols->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, resols, ub_loop, &wk_emlrtRTEI);
  ub_loop = allRoughs->size[0];
  allRoughs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, allRoughs, ub_loop, &wk_emlrtRTEI);
  ub_loop = outSsubs->size[0];
  outSsubs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, outSsubs, ub_loop, &wk_emlrtRTEI);
  ub_loop = sldProfiles->size[0];
  sldProfiles->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_111(sp, sldProfiles, ub_loop, &sk_emlrtRTEI);
  ub_loop = layerSlds->size[0];
  layerSlds->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, layerSlds, ub_loop, &sk_emlrtRTEI);
  ub_loop = shifted_data->size[0];
  shifted_data->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, shifted_data, ub_loop, &sk_emlrtRTEI);
  ub_loop = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, Simulation, ub_loop, &sk_emlrtRTEI);
  ub_loop = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_111(sp, reflectivity, ub_loop, &sk_emlrtRTEI);
  ub_loop = chis->size[0];
  chis->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, chis, ub_loop, &wk_emlrtRTEI);
  ub_loop = (int32_T)numberOfContrasts - 1;
  emlrtEnterParallelRegion(sp, omp_in_parallel());
  emlrtPushJmpBuf(sp, &emlrtJBStack);

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(thisContrastLayers,sldProfile,layerSld,reflect,Simul,shifted_dat,thisCalcSld,d,d1,d2,d3,d4,b_emlrtJBEnviron,c_st,i3,c_i,i4,loop_ub,i5) \
 firstprivate(b_st,emlrtHadParallelError)

  {
    if (setjmp(b_emlrtJBEnviron) == 0) {
      b_st.prev = sp;
      b_st.tls = emlrtAllocTLS(sp, omp_get_thread_num());
      b_st.site = NULL;
      emlrtSetJmpBuf(&b_st, &b_emlrtJBEnviron);
      c_st.prev = &b_st;
      c_st.tls = b_st.tls;
      emxInit_real_T(&b_st, &thisContrastLayers, 2, &jl_emlrtRTEI, true);
      emxInit_real_T(&b_st, &sldProfile, 2, &al_emlrtRTEI, true);
      emxInit_real_T(&b_st, &layerSld, 2, &il_emlrtRTEI, true);
      emxInit_real_T(&b_st, &reflect, 2, &sk_emlrtRTEI, true);
      emxInit_real_T(&b_st, &Simul, 2, &hl_emlrtRTEI, true);
      emxInit_real_T(&b_st, &shifted_dat, 2, &dl_emlrtRTEI, true);
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
          emlrtDynamicBoundsCheckR2012b(i3, 1, cBacks->size[1], &si_emlrtBCI,
            &b_st);
        }

        if (i3 > cShifts->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, cShifts->size[1], &ti_emlrtBCI,
            &b_st);
        }

        if (i3 > cScales->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, cScales->size[1], &ui_emlrtBCI,
            &b_st);
        }

        if (i3 > cNbas->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, cNbas->size[1], &vi_emlrtBCI,
            &b_st);
        }

        if (i3 > cNbss->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, cNbss->size[1], &wi_emlrtBCI,
            &b_st);
        }

        if (i3 > cRes->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, cRes->size[1], &xi_emlrtBCI,
            &b_st);
        }

        c_st.site = &mg_emlrtRSI;
        backSort(&c_st, cBacks->data[i3 - 1], cShifts->data[i3 - 1],
                 cScales->data[i3 - 1], cNbas->data[i3 - 1], cNbss->data[i3 - 1],
                 cRes->data[i3 - 1], backs, shifts, sf, nba, nbs, res, &d4, &d3,
                 &d2, &d1, &d, &thisCalcSld);
        if (i3 > backgs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, backgs->size[0], &yi_emlrtBCI,
            &b_st);
        }

        backgs->data[i3 - 1] = d4;
        if (i3 > qshifts->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, qshifts->size[0], &aj_emlrtBCI,
            &b_st);
        }

        qshifts->data[i3 - 1] = d3;
        if (i3 > sfs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, sfs->size[0], &bj_emlrtBCI, &b_st);
        }

        sfs->data[i3 - 1] = d2;
        if (i3 > nbas->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, nbas->size[0], &cj_emlrtBCI,
            &b_st);
        }

        nbas->data[i3 - 1] = d1;
        if (i3 > nbss->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, nbss->size[0], &dj_emlrtBCI,
            &b_st);
        }

        nbss->data[i3 - 1] = d;
        if (i3 > resols->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, resols->size[0], &ej_emlrtBCI,
            &b_st);
        }

        resols->data[i3 - 1] = thisCalcSld;
        if (1 > params->size[1]) {
          emlrtDynamicBoundsCheckR2012b(1, 1, params->size[1], &ni_emlrtBCI,
            &b_st);
        }

        if (i3 > allRoughs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, allRoughs->size[0], &fj_emlrtBCI,
            &b_st);
        }

        allRoughs->data[i3 - 1] = params->data[0];
        i3 = contrastLayers->size[1] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &gj_emlrtBCI, &b_st);
        }

        c_st.site = &ng_emlrtRSI;
        allocateLayersForContrast(&c_st, contrastLayers->data[c_i].f1,
          outParameterisedLayers, thisContrastLayers);
        i3 = c_i + 1;
        if ((i3 < 1) || (i3 > allRoughs->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, allRoughs->size[0], &hj_emlrtBCI,
            &b_st);
        }

        i4 = c_i + 1;
        if ((i4 < 1) || (i4 > nbas->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i4, 1, nbas->size[0], &ij_emlrtBCI,
            &b_st);
        }

        loop_ub = c_i + 1;
        if ((loop_ub < 1) || (loop_ub > nbss->size[0])) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, nbss->size[0], &jj_emlrtBCI,
            &b_st);
        }

        c_st.site = &og_emlrtRSI;
        groupLayers_Mod(&c_st, thisContrastLayers, allRoughs->data[i3 - 1],
                        geometry, nbas->data[i4 - 1], nbss->data[loop_ub - 1],
                        layerSld, &thisCalcSld);
        i3 = c_i + 1;
        if ((i3 < 1) || (i3 > outSsubs->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, outSsubs->size[0], &kj_emlrtBCI,
            &b_st);
        }

        outSsubs->data[i3 - 1] = thisCalcSld;
        thisCalcSld = calcSld;
        i3 = c_i + 1;
        if ((i3 < 1) || (i3 > resample->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, resample->size[1], &lj_emlrtBCI,
            &b_st);
        }

        if (resample->data[i3 - 1] == 1.0) {
          thisCalcSld = 1.0;
        }

        if (thisCalcSld == 1.0) {
          i3 = c_i + 1;
          if ((i3 < 1) || (i3 > nbas->size[0])) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, nbas->size[0], &mj_emlrtBCI,
              &b_st);
          }

          i4 = c_i + 1;
          if ((i4 < 1) || (i4 > nbss->size[0])) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, nbss->size[0], &nj_emlrtBCI,
              &b_st);
          }

          loop_ub = c_i + 1;
          if ((loop_ub < 1) || (loop_ub > outSsubs->size[0])) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, outSsubs->size[0],
              &oj_emlrtBCI, &b_st);
          }

          i5 = repeatLayers->size[1] - 1;
          if (c_i > i5) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i5, &pj_emlrtBCI, &b_st);
          }

          c_st.site = &pg_emlrtRSI;
          makeSLDProfiles(&c_st, nbas->data[i3 - 1], nbss->data[i4 - 1],
                          layerSld, outSsubs->data[loop_ub - 1],
                          repeatLayers->data[c_i].f1, Simul);
          i3 = sldProfile->size[0] * sldProfile->size[1];
          sldProfile->size[0] = Simul->size[0];
          sldProfile->size[1] = 2;
          emxEnsureCapacity_real_T(&b_st, sldProfile, i3, &al_emlrtRTEI);
          loop_ub = Simul->size[0] * Simul->size[1];
          for (i3 = 0; i3 < loop_ub; i3++) {
            sldProfile->data[i3] = Simul->data[i3];
          }
        } else {
          i3 = sldProfile->size[0] * sldProfile->size[1];
          sldProfile->size[0] = 1;
          sldProfile->size[1] = 3;
          emxEnsureCapacity_real_T(&b_st, sldProfile, i3, &xk_emlrtRTEI);
          sldProfile->data[0] = 0.0;
          sldProfile->data[1] = 0.0;
          sldProfile->data[2] = 0.0;
        }

        loop_ub = sldProfile->size[0] * sldProfile->size[1];
        i3 = sldProfiles->size[0] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &qj_emlrtBCI, &b_st);
        }

        i3 = sldProfiles->data[c_i].f1->size[0] * sldProfiles->data[c_i]
          .f1->size[1];
        sldProfiles->data[c_i].f1->size[0] = sldProfile->size[0];
        emxEnsureCapacity_real_T(&b_st, sldProfiles->data[c_i].f1, i3,
          &yk_emlrtRTEI);
        i3 = sldProfiles->size[0] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &qj_emlrtBCI, &b_st);
        }

        i3 = sldProfiles->data[c_i].f1->size[0] * sldProfiles->data[c_i]
          .f1->size[1];
        sldProfiles->data[c_i].f1->size[1] = sldProfile->size[1];
        emxEnsureCapacity_real_T(&b_st, sldProfiles->data[c_i].f1, i3,
          &yk_emlrtRTEI);
        i3 = sldProfiles->size[0] - 1;
        i4 = sldProfiles->size[0] - 1;
        if (c_i > i4) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &qj_emlrtBCI, &b_st);
        }

        i4 = sldProfiles->size[0] - 1;
        if (c_i > i4) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &qj_emlrtBCI, &b_st);
        }

        for (i4 = 0; i4 < loop_ub; i4++) {
          if (c_i > i3) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &qj_emlrtBCI, &b_st);
          }

          sldProfiles->data[c_i].f1->data[i4] = sldProfile->data[i4];
        }

        i3 = c_i + 1;
        if ((i3 < 1) || (i3 > resample->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, resample->size[1], &rj_emlrtBCI,
            &b_st);
        }

        if (resample->data[i3 - 1] == 1.0) {
          c_st.site = &qg_emlrtRSI;
          resampleLayers(&c_st, sldProfile, layerSld);
          loop_ub = layerSld->size[0] * layerSld->size[1];
          i3 = layerSlds->size[0] - 1;
          if (c_i > i3) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &tj_emlrtBCI, &b_st);
          }

          i3 = layerSlds->data[c_i].f1->size[0] * layerSlds->data[c_i].f1->size
            [1];
          layerSlds->data[c_i].f1->size[0] = layerSld->size[0];
          emxEnsureCapacity_real_T(&b_st, layerSlds->data[c_i].f1, i3,
            &cl_emlrtRTEI);
          i3 = layerSlds->size[0] - 1;
          if (c_i > i3) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &tj_emlrtBCI, &b_st);
          }

          i3 = layerSlds->data[c_i].f1->size[0] * layerSlds->data[c_i].f1->size
            [1];
          layerSlds->data[c_i].f1->size[1] = 3;
          emxEnsureCapacity_real_T(&b_st, layerSlds->data[c_i].f1, i3,
            &cl_emlrtRTEI);
          i3 = layerSlds->size[0] - 1;
          i4 = layerSlds->size[0] - 1;
          if (c_i > i4) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &tj_emlrtBCI, &b_st);
          }

          i4 = layerSlds->size[0] - 1;
          if (c_i > i4) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &tj_emlrtBCI, &b_st);
          }

          for (i4 = 0; i4 < loop_ub; i4++) {
            if (c_i > i3) {
              emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &tj_emlrtBCI, &b_st);
            }

            layerSlds->data[c_i].f1->data[i4] = layerSld->data[i4];
          }
        } else {
          loop_ub = layerSld->size[0] * layerSld->size[1];
          i3 = layerSlds->size[0] - 1;
          if (c_i > i3) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &sj_emlrtBCI, &b_st);
          }

          i3 = layerSlds->data[c_i].f1->size[0] * layerSlds->data[c_i].f1->size
            [1];
          layerSlds->data[c_i].f1->size[0] = layerSld->size[0];
          emxEnsureCapacity_real_T(&b_st, layerSlds->data[c_i].f1, i3,
            &bl_emlrtRTEI);
          i3 = layerSlds->size[0] - 1;
          if (c_i > i3) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &sj_emlrtBCI, &b_st);
          }

          i3 = layerSlds->data[c_i].f1->size[0] * layerSlds->data[c_i].f1->size
            [1];
          layerSlds->data[c_i].f1->size[1] = 3;
          emxEnsureCapacity_real_T(&b_st, layerSlds->data[c_i].f1, i3,
            &bl_emlrtRTEI);
          i3 = layerSlds->size[0] - 1;
          i4 = layerSlds->size[0] - 1;
          if (c_i > i4) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &sj_emlrtBCI, &b_st);
          }

          i4 = layerSlds->size[0] - 1;
          if (c_i > i4) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &sj_emlrtBCI, &b_st);
          }

          for (i4 = 0; i4 < loop_ub; i4++) {
            if (c_i > i3) {
              emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &sj_emlrtBCI, &b_st);
            }

            layerSlds->data[c_i].f1->data[i4] = layerSld->data[i4];
          }
        }

        i3 = allData->size[1] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &uj_emlrtBCI, &b_st);
        }

        i3 = shifted_dat->size[0] * shifted_dat->size[1];
        shifted_dat->size[0] = allData->data[c_i].f1->size[0];
        shifted_dat->size[1] = 3;
        emxEnsureCapacity_real_T(&b_st, shifted_dat, i3, &dl_emlrtRTEI);
        i3 = allData->size[1] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &uj_emlrtBCI, &b_st);
        }

        i3 = allData->size[1] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &uj_emlrtBCI, &b_st);
        }

        loop_ub = allData->data[c_i].f1->size[0] * allData->data[c_i].f1->size[1];
        for (i3 = 0; i3 < loop_ub; i3++) {
          i4 = allData->size[1] - 1;
          if (c_i > i4) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &uj_emlrtBCI, &b_st);
          }

          i4 = allData->size[1] - 1;
          if (c_i > i4) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &uj_emlrtBCI, &b_st);
          }

          i4 = allData->size[1] - 1;
          if (c_i > i4) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &uj_emlrtBCI, &b_st);
          }

          shifted_dat->data[i3] = allData->data[c_i].f1->data[i3];
        }

        i3 = c_i + 1;
        if ((i3 < 1) || (i3 > sfs->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, sfs->size[0], &vj_emlrtBCI, &b_st);
        }

        i4 = c_i + 1;
        if ((i4 < 1) || (i4 > qshifts->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i4, 1, qshifts->size[0], &wj_emlrtBCI,
            &b_st);
        }

        loop_ub = c_i + 1;
        if ((loop_ub < 1) || (loop_ub > dataPresent->size[1])) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, dataPresent->size[1],
            &xj_emlrtBCI, &b_st);
        }

        i5 = dataLimits->size[1] - 1;
        if (c_i > i5) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i5, &yj_emlrtBCI, &b_st);
        }

        c_st.site = &rg_emlrtRSI;
        shiftdata(&c_st, sfs->data[i3 - 1], qshifts->data[i4 - 1],
                  dataPresent->data[loop_ub - 1], shifted_dat, dataLimits->
                  data[c_i].f1);
        i3 = c_i + 1;
        if ((i3 < 1) || (i3 > backgs->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, backgs->size[0], &oi_emlrtBCI,
            &b_st);
        }

        i3 = c_i + 1;
        if ((i3 < 1) || (i3 > nbas->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, nbas->size[0], &ak_emlrtBCI,
            &b_st);
        }

        i4 = c_i + 1;
        if ((i4 < 1) || (i4 > nbss->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i4, 1, nbss->size[0], &bk_emlrtBCI,
            &b_st);
        }

        loop_ub = simLimits->size[1] - 1;
        if (c_i > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, loop_ub, &ck_emlrtBCI, &b_st);
        }

        loop_ub = repeatLayers->size[1] - 1;
        if (c_i > loop_ub) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, loop_ub, &dk_emlrtBCI, &b_st);
        }

        loop_ub = c_i + 1;
        if ((loop_ub < 1) || (loop_ub > outSsubs->size[0])) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, outSsubs->size[0],
            &ek_emlrtBCI, &b_st);
        }

        i5 = c_i + 1;
        if ((i5 < 1) || (i5 > resols->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i5, 1, resols->size[0], &fk_emlrtBCI,
            &b_st);
        }

        c_st.site = &sg_emlrtRSI;
        callReflectivity(&c_st, nbas->data[i3 - 1], nbss->data[i4 - 1],
                         simLimits->data[c_i].f1, repeatLayers->data[c_i].f1,
                         shifted_dat, layerSld, outSsubs->data[loop_ub - 1],
                         resols->data[i5 - 1], reflect, Simul);
        i3 = c_i + 1;
        if ((i3 < 1) || (i3 > backgs->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, backgs->size[0], &gk_emlrtBCI,
            &b_st);
        }

        i4 = c_i + 1;
        if ((i4 < 1) || (i4 > backsType->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i4, 1, backsType->size[1], &hk_emlrtBCI,
            &b_st);
        }

        c_st.site = &tg_emlrtRSI;
        applyBackgroundCorrection(&c_st, reflect, Simul, shifted_dat,
          backgs->data[i3 - 1], backsType->data[i4 - 1]);
        loop_ub = reflect->size[0] * reflect->size[1];
        i3 = reflectivity->size[0] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &ik_emlrtBCI, &b_st);
        }

        i3 = reflectivity->data[c_i].f1->size[0] * reflectivity->data[c_i]
          .f1->size[1];
        reflectivity->data[c_i].f1->size[0] = reflect->size[0];
        emxEnsureCapacity_real_T(&b_st, reflectivity->data[c_i].f1, i3,
          &el_emlrtRTEI);
        i3 = reflectivity->size[0] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &ik_emlrtBCI, &b_st);
        }

        i3 = reflectivity->data[c_i].f1->size[0] * reflectivity->data[c_i]
          .f1->size[1];
        reflectivity->data[c_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(&b_st, reflectivity->data[c_i].f1, i3,
          &el_emlrtRTEI);
        i3 = reflectivity->size[0] - 1;
        i4 = reflectivity->size[0] - 1;
        if (c_i > i4) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &ik_emlrtBCI, &b_st);
        }

        i4 = reflectivity->size[0] - 1;
        if (c_i > i4) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &ik_emlrtBCI, &b_st);
        }

        for (i4 = 0; i4 < loop_ub; i4++) {
          if (c_i > i3) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &ik_emlrtBCI, &b_st);
          }

          reflectivity->data[c_i].f1->data[i4] = reflect->data[i4];
        }

        loop_ub = Simul->size[0] * Simul->size[1];
        i3 = Simulation->size[0] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &jk_emlrtBCI, &b_st);
        }

        i3 = Simulation->data[c_i].f1->size[0] * Simulation->data[c_i].f1->size
          [1];
        Simulation->data[c_i].f1->size[0] = Simul->size[0];
        emxEnsureCapacity_real_T(&b_st, Simulation->data[c_i].f1, i3,
          &fl_emlrtRTEI);
        i3 = Simulation->size[0] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &jk_emlrtBCI, &b_st);
        }

        i3 = Simulation->data[c_i].f1->size[0] * Simulation->data[c_i].f1->size
          [1];
        Simulation->data[c_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(&b_st, Simulation->data[c_i].f1, i3,
          &fl_emlrtRTEI);
        i3 = Simulation->size[0] - 1;
        i4 = Simulation->size[0] - 1;
        if (c_i > i4) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &jk_emlrtBCI, &b_st);
        }

        i4 = Simulation->size[0] - 1;
        if (c_i > i4) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &jk_emlrtBCI, &b_st);
        }

        for (i4 = 0; i4 < loop_ub; i4++) {
          if (c_i > i3) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &jk_emlrtBCI, &b_st);
          }

          Simulation->data[c_i].f1->data[i4] = Simul->data[i4];
        }

        loop_ub = shifted_dat->size[0] * shifted_dat->size[1];
        i3 = shifted_data->size[0] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &kk_emlrtBCI, &b_st);
        }

        i3 = shifted_data->data[c_i].f1->size[0] * shifted_data->data[c_i]
          .f1->size[1];
        shifted_data->data[c_i].f1->size[0] = shifted_dat->size[0];
        emxEnsureCapacity_real_T(&b_st, shifted_data->data[c_i].f1, i3,
          &gl_emlrtRTEI);
        i3 = shifted_data->size[0] - 1;
        if (c_i > i3) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &kk_emlrtBCI, &b_st);
        }

        i3 = shifted_data->data[c_i].f1->size[0] * shifted_data->data[c_i]
          .f1->size[1];
        shifted_data->data[c_i].f1->size[1] = 3;
        emxEnsureCapacity_real_T(&b_st, shifted_data->data[c_i].f1, i3,
          &gl_emlrtRTEI);
        i3 = shifted_data->size[0] - 1;
        i4 = shifted_data->size[0] - 1;
        if (c_i > i4) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &kk_emlrtBCI, &b_st);
        }

        i4 = shifted_data->size[0] - 1;
        if (c_i > i4) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, i4, &kk_emlrtBCI, &b_st);
        }

        for (i4 = 0; i4 < loop_ub; i4++) {
          if (c_i > i3) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3, &kk_emlrtBCI, &b_st);
          }

          shifted_data->data[c_i].f1->data[i4] = shifted_dat->data[i4];
        }

        i3 = c_i + 1;
        if ((i3 < 1) || (i3 > chis->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, chis->size[0], &lk_emlrtBCI,
            &b_st);
        }

        c_st.site = &ug_emlrtRSI;
        chis->data[i3 - 1] = chiSquared(&c_st, shifted_dat, reflect, nParams);
      } else {
        emlrtHadParallelError = true;
      }
    }

    if (!emlrtHadParallelError) {
      emlrtHeapReferenceStackLeaveScope(&b_st, 6);
      emxFree_real_T(&shifted_dat);
      emxFree_real_T(&Simul);
      emxFree_real_T(&reflect);
      emxFree_real_T(&layerSld);
      emxFree_real_T(&sldProfile);
      emxFree_real_T(&thisContrastLayers);
    }
  }

  emlrtPopJmpBuf(sp, &emlrtJBStack);
  emlrtExitParallelRegion(sp, omp_in_parallel());
  emxFree_cell_wrap_17(&outParameterisedLayers);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_stanlay_paraContrasts.c) */
