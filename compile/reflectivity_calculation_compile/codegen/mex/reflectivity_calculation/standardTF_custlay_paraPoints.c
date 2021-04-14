/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_custlay_paraPoints.c
 *
 * Code generation for function 'standardTF_custlay_paraPoints'
 *
 */

/* Include files */
#include "standardTF_custlay_paraPoints.h"
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
static emlrtRSInfo ph_emlrtRSI = { 53, /* lineNo */
  "standardTF_custlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo qh_emlrtRSI = { 56, /* lineNo */
  "standardTF_custlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo rh_emlrtRSI = { 78, /* lineNo */
  "standardTF_custlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pathName */
};

static emlrtRTEInfo tc_emlrtRTEI = { 29,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo uc_emlrtRTEI = { 35,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo vc_emlrtRTEI = { 41,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = { 48,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtBCInfo wl_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  84,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xl_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  95,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yl_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  106,                                 /* colNo */
  "cScales",                           /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo am_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  115,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  124,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  132,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo w_emlrtECI = { 1,   /* nDims */
  57,                                  /* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtBCInfo dm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  27,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo em_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  64,                                  /* lineNo */
  29,                                  /* colNo */
  "resample",                          /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  35,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  31,                                  /* colNo */
  "backsType",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo x_emlrtECI = { 1,   /* nDims */
  91,                                  /* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtECInfo y_emlrtECI = { 1,   /* nDims */
  92,                                  /* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtBCInfo hm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  37,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo im_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  24,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  33,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo km_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  31,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo kc_emlrtDCI = { 14, /* lineNo */
  16,                                  /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo lm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  30,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo om_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  16,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  5,                                   /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo um_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  91,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  94,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  96,                                  /* lineNo */
  5,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ym_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  5,                                   /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo an_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  98,                                  /* lineNo */
  5,                                   /* colNo */
  "sfs",                               /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  5,                                   /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  100,                                 /* lineNo */
  5,                                   /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  101,                                 /* lineNo */
  5,                                   /* colNo */
  "resols",                            /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo en_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  5,                                   /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo cn_emlrtRTEI = { 4,/* lineNo */
  13,                                  /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo dn_emlrtRTEI = { 30,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo en_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo fn_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo gn_emlrtRTEI = { 20,/* lineNo */
  13,                                  /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo hn_emlrtRTEI = { 57,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo in_emlrtRTEI = { 93,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo jn_emlrtRTEI = { 90,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo kn_emlrtRTEI = { 91,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo ln_emlrtRTEI = { 92,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo mn_emlrtRTEI = { 94,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

/* Function Definitions */
void standardTF_custlay_paraPoints(const emlrtStack *sp, const emxArray_real_T
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
  emxArray_real_T *backsType, real_T calcSld, emxArray_real_T *outSsubs,
  emxArray_real_T *backgs, emxArray_real_T *qshifts, emxArray_real_T *sfs,
  emxArray_real_T *nbas, emxArray_real_T *nbss, emxArray_real_T *resols,
  emxArray_real_T *chis, emxArray_cell_wrap_9 *reflectivity,
  emxArray_cell_wrap_9 *Simulation, emxArray_cell_wrap_1 *shifted_data,
  emxArray_cell_wrap_1 *layerSlds, emxArray_cell_wrap_12 *sldProfiles,
  emxArray_cell_wrap_17 *allLayers, emxArray_real_T *allRoughs)
{
  int32_T i;
  int32_T i1;
  int32_T b_i;
  int32_T i2;
  emxArray_real_T *sldProfile;
  emxArray_real_T *output;
  emxArray_real_T *theseLayers;
  emxArray_real_T *Simul;
  emxArray_real_T *b_sldProfile;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  real_T reps;
  int32_T i7;
  int32_T loop_ub;
  int32_T i8;
  real_T ssubs;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 32U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 32U, 0U);

  /*  Pre-Allocation of output arrays... */
  /*    --- Begin Memory Allocation --- */
  if (numberOfContrasts != (int32_T)muDoubleScalarFloor(numberOfContrasts)) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &kc_emlrtDCI, sp);
  }

  i = (int32_T)numberOfContrasts;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &tc_emlrtRTEI, sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i1, &cn_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 32U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 32U, 1U);
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &lm_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &dn_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &lm_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &dn_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &lm_emlrtBCI, sp);
    }

    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &lm_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &lm_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &lm_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &lm_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &lm_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 32U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 32U, 2U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &uc_emlrtRTEI, sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i1, &cn_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 32U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 32U, 3U);
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &mm_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &en_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &mm_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &en_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &mm_emlrtBCI, sp);
    }

    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &mm_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &mm_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &mm_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &mm_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &mm_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 32U, 0U, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 32U, 4U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &vc_emlrtRTEI, sp);
  i1 = allLayers->size[0];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_17(sp, allLayers, i1, &cn_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 32U, 0U, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 32U, 5U);
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &nm_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &fn_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &nm_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &fn_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &nm_emlrtBCI, sp);
    }

    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &nm_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &nm_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &nm_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 32U, 0U, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 32U, 6U);

  /*    --- End Memory Allocation --- */
  /*  Single cored over all contrasts */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &wc_emlrtRTEI, sp);
  i1 = allRoughs->size[0];
  allRoughs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, allRoughs, i1, &gn_emlrtRTEI);
  i1 = allLayers->size[0];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_17(sp, allLayers, i1, &cn_emlrtRTEI);
  i1 = outSsubs->size[0];
  outSsubs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, outSsubs, i1, &gn_emlrtRTEI);
  i1 = sldProfiles->size[0];
  sldProfiles->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_12(sp, sldProfiles, i1, &cn_emlrtRTEI);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i1, &cn_emlrtRTEI);
  i1 = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i1, &cn_emlrtRTEI);
  i1 = shifted_data->size[0];
  shifted_data->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, shifted_data, i1, &cn_emlrtRTEI);
  i1 = layerSlds->size[0];
  layerSlds->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, layerSlds, i1, &cn_emlrtRTEI);
  i1 = chis->size[0];
  chis->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, chis, i1, &gn_emlrtRTEI);
  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &gn_emlrtRTEI);
  i1 = qshifts->size[0];
  qshifts->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, qshifts, i1, &gn_emlrtRTEI);
  i1 = sfs->size[0];
  sfs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, sfs, i1, &gn_emlrtRTEI);
  i1 = nbas->size[0];
  nbas->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbas, i1, &gn_emlrtRTEI);
  i1 = nbss->size[0];
  nbss->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbss, i1, &gn_emlrtRTEI);
  i1 = resols->size[0];
  resols->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, resols, i1, &gn_emlrtRTEI);
  emxInit_real_T(sp, &sldProfile, 2, &cn_emlrtRTEI, true);
  emxInit_real_T(sp, &output, 2, &cn_emlrtRTEI, true);
  emxInit_real_T(sp, &theseLayers, 2, &cn_emlrtRTEI, true);
  emxInit_real_T(sp, &Simul, 2, &cn_emlrtRTEI, true);
  emxInit_real_T(sp, &b_sldProfile, 2, &yg_emlrtRTEI, true);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 32U, 0U, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 32U, 7U);

    /*  Extract the relevant parameter values for this contrast */
    /*  from the input arrays. */
    /*  First need to decide which values of the backrounds, scalefactors */
    /*  data shifts and bulk contrasts are associated with this contrast */
    st.site = &ph_emlrtRSI;
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cBacks->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cBacks->size[1], &wl_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cShifts->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cShifts->size[1], &xl_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cScales->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cScales->size[1], &yl_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cNbas->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cNbas->size[1], &am_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cNbss->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cNbss->size[1], &bm_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cRes->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cRes->size[1], &cm_emlrtBCI, &st);
    }

    covrtLogFcn(&emlrtCoverageInstance, 7U, 0U);
    covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 0U);

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
      emlrtIntegerCheckR2012b(cBacks->data[b_i], &r_emlrtDCI, &st);
    }

    i1 = (int32_T)cBacks->data[b_i];
    if ((i1 < 1) || (i1 > backs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, backs->size[1], &sb_emlrtBCI, &st);
    }

    /* thisShift = cShifts(i); */
    if (cShifts->data[b_i] != (int32_T)muDoubleScalarFloor(cShifts->data[b_i]))
    {
      emlrtIntegerCheckR2012b(cShifts->data[b_i], &s_emlrtDCI, &st);
    }

    i2 = (int32_T)cShifts->data[b_i];
    if ((i2 < 1) || (i2 > shifts->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, shifts->size[1], &tb_emlrtBCI, &st);
    }

    /* thisScale = cScales(i); */
    if (cScales->data[b_i] != (int32_T)muDoubleScalarFloor(cScales->data[b_i]))
    {
      emlrtIntegerCheckR2012b(cScales->data[b_i], &t_emlrtDCI, &st);
    }

    i3 = (int32_T)cScales->data[b_i];
    if ((i3 < 1) || (i3 > sf->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, sf->size[1], &ub_emlrtBCI, &st);
    }

    /* thisNbair = cNbas(i); */
    if (cNbas->data[b_i] != (int32_T)muDoubleScalarFloor(cNbas->data[b_i])) {
      emlrtIntegerCheckR2012b(cNbas->data[b_i], &u_emlrtDCI, &st);
    }

    i4 = (int32_T)cNbas->data[b_i];
    if ((i4 < 1) || (i4 > nba->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i4, 1, nba->size[1], &vb_emlrtBCI, &st);
    }

    /* thisNbsub = cNbss(i); */
    if (cNbss->data[b_i] != (int32_T)muDoubleScalarFloor(cNbss->data[b_i])) {
      emlrtIntegerCheckR2012b(cNbss->data[b_i], &v_emlrtDCI, &st);
    }

    i5 = (int32_T)cNbss->data[b_i];
    if ((i5 < 1) || (i5 > nbs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i5, 1, nbs->size[1], &wb_emlrtBCI, &st);
    }

    /* thisResol = cRes(i); */
    if (cRes->data[b_i] != (int32_T)muDoubleScalarFloor(cRes->data[b_i])) {
      emlrtIntegerCheckR2012b(cRes->data[b_i], &w_emlrtDCI, &st);
    }

    i6 = (int32_T)cRes->data[b_i];
    if ((i6 < 1) || (i6 > res->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i6, 1, res->size[1], &xb_emlrtBCI, &st);
    }

    /* end */
    /*  Call the custom layers function to get the layers array... */
    st.site = &qh_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 30U, 0U);
    covrtLogBasicBlock(&emlrtCoverageInstance, 30U, 0U);

    /* switch lang */
    /*     case 'matlab' */
    b_st.site = &mh_emlrtRSI;
    matlabEngineCaller_customLayers(&b_st, params, (real_T)b_i + 1.0, fname,
      path, nba->data[(int32_T)cNbas->data[b_i] - 1], nbs->data[(int32_T)
      cNbss->data[b_i] - 1], output, &reps);
    if (1 > params->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, params->size[1], &xk_emlrtBCI, &st);
    }

    i7 = (int32_T)(b_i + 1U);
    if ((i7 < 1) || (i7 > allRoughs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, allRoughs->size[0], &om_emlrtBCI, &st);
    }

    allRoughs->data[i7 - 1] = params->data[0];

    /* case 'octave' */
    /*     [output,layers] = octaveCaller_customLayers(params,contrast,file,callPath,bulkIn,bulkOut); */
    /* case 'python' */
    /*     [output,layers] = pythonCaller_customLayers(params,contrast,file,callPath,bulkIn,bulkOut); */
    /* end */
    if (10000 < output->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, output->size[0], &w_emlrtECI, sp);
    }

    loop_ub = output->size[0] * output->size[1];
    i7 = allLayers->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &pm_emlrtBCI, sp);
    }

    i7 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = output->size[0];
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i7, &hn_emlrtRTEI);
    i7 = allLayers->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &pm_emlrtBCI, sp);
    }

    i7 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i7, &hn_emlrtRTEI);
    i7 = allLayers->size[0] - 1;
    i8 = allLayers->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &pm_emlrtBCI, sp);
    }

    i8 = allLayers->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &pm_emlrtBCI, sp);
    }

    for (i8 = 0; i8 < loop_ub; i8++) {
      if (b_i > i7) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &pm_emlrtBCI, sp);
      }

      allLayers->data[b_i].f1->data[i8] = output->data[i8];
    }

    /*  For the other parameters, we extract the correct ones from the input */
    /*  arrays */
    i7 = b_i + 1;
    if ((i7 < 1) || (i7 > allRoughs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, allRoughs->size[0], &dm_emlrtBCI, sp);
    }

    /*  Substrate roughness is always first parameter for custom layers */
    i7 = repeatLayers->size[1] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &hm_emlrtBCI, sp);
    }

    i7 = b_i + 1;
    if ((i7 < 1) || (i7 > resample->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, resample->size[1], &em_emlrtBCI, sp);
    }

    i7 = allData->size[1] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &im_emlrtBCI, sp);
    }

    i7 = b_i + 1;
    if ((i7 < 1) || (i7 > dataPresent->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, dataPresent->size[1], &fm_emlrtBCI,
        sp);
    }

    i7 = dataLimits->size[1] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &jm_emlrtBCI, sp);
    }

    i7 = simLimits->size[1] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &km_emlrtBCI, sp);
    }

    i7 = b_i + 1;
    if ((i7 < 1) || (i7 > backsType->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, backsType->size[1], &gm_emlrtBCI, sp);
    }

    /*  Now call the core standardTF_stanlay reflectivity calculation */
    /*  In this case we parallelise over */
    /*  points */
    /*  Call the reflectivity calculation */
    st.site = &rh_emlrtRSI;
    reps = calcSld;
    covrtLogFcn(&emlrtCoverageInstance, 9U, 0U);
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 0U);

    /*  function [sldProfile,reflect,Simul,shifted_dat,layerSld,chiSquared,ssubs] = ... */
    /*      standardTF_stanlay_core(contrastLayers, rough, ... */
    /*      geometry, nba, nbs, resample, calcSld, sf, qshift,... */
    /*      dataPresent, data, dataLimits, simLimits, repeatLayers,... */
    /*      background,resol,backsType,params,paralellPoints) */
    /*  */
    /*    This is the main reflectivity calculation for Layers models in the  */
    /*    standard target function. The function first arranges the  */
    /*    roughness' in the correct order according */
    /*    to geometry. Then, if required it calculates the SLD profile and if */
    /*    requested resamples this into a number of zero-roughness layers */
    /*    (roughness resampling). It the applies any scalefactors and qz shifts */
    /*    the data requires. This is done before calculating the reflectivity to */
    /*    ensure that the reflectivity is calculated over the same range in qz as */
    /*    the shifted datapoints. The main reflectivity calculation is then */
    /*    called, including the resolution function. The calculation outputs two */
    /*    profiles - 'reflect' which is the same range as the points, and */
    /*    'Simulation' which can be a different range to allow extrapolation. */
    /*    The background correction is the applied, and finally chi-squared is  */
    /*    calculated. */
    /*  */
    /*  Inputs: */
    /*    contrastLayers  : */
    /*    rough           : */
    /*    geometry        : */
    /*    nba             : */
    /*    nbs             : */
    /*    resample        : */
    /*    calcSld         : */
    /*    sf              : */
    /*    qshift          : */
    /*    dataPresent     : */
    /*    data            : */
    /*    dataLimits      : */
    /*    simLimits       : */
    /*    repeatLayers    : */
    /*    background      : */
    /*    resol           : */
    /*    backsType       : */
    /*    params          : */
    /*    paralellPoints  : */
    /*  */
    /*  Outputs: */
    /*  */
    /*  */
    /*  */
    /*  ------------------------------------------------------------------------ */
    /*  */
    /*        (c) Arwel Hughes  -   12/1/21 */
    /*  */
    /*        Last Modified: 12/1/21 by Arwel Hughes. */
    /*  */
    /*  ------------------------------------------------------------------------ */
    /*  Bulid up the layers matrix for this contrast */
    b_st.site = &o_emlrtRSI;
    b_groupLayers_Mod(&b_st, output, allRoughs->data[b_i], geometry, theseLayers,
                      &ssubs);
    i7 = b_i + 1;
    if ((i7 < 1) || (i7 > outSsubs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, outSsubs->size[0], &qm_emlrtBCI, &st);
    }

    outSsubs->data[i7 - 1] = ssubs;

    /*  Make the SLD profiles. */
    /*  If resampling is needed, then enforce the calcSLD flag, so as to catch */
    /*  the error af trying to resample a non-existent profile. */
    if (covrtLogCond(&emlrtCoverageInstance, 9U, 0U, 0, resample->data[b_i] ==
                     1.0) && covrtLogCond(&emlrtCoverageInstance, 9U, 0U, 1,
         calcSld == 0.0)) {
      covrtLogMcdc(&emlrtCoverageInstance, 9U, 0U, 0, true);
      covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 0, true);
      covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 1U);
      reps = 1.0;
    } else {
      covrtLogMcdc(&emlrtCoverageInstance, 9U, 0U, 0, false);
      covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 0, false);
    }

    /*  If cal SLD flag is set, then calculate the SLD profile */
    if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 1, reps == 1.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 2U);
      b_st.site = &p_emlrtRSI;
      covrtLogFcn(&emlrtCoverageInstance, 11U, 0U);
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 0U);
      if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 0, repeatLayers->data[b_i]
                     .f1[0] == 0.0)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 1U);
        reps = 1.0;
      } else {
        covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 2U);
        reps = repeatLayers->data[b_i].f1[1];
      }

      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 3U);
      c_st.site = &jb_emlrtRSI;
      makeSLDProfileXY(&c_st, nba->data[(int32_T)cNbas->data[b_i] - 1],
                       nbs->data[(int32_T)cNbss->data[b_i] - 1], ssubs,
                       theseLayers, theseLayers->size[0], reps, b_sldProfile);
      i7 = sldProfile->size[0] * sldProfile->size[1];
      sldProfile->size[0] = b_sldProfile->size[0];
      sldProfile->size[1] = 2;
      emxEnsureCapacity_real_T(&st, sldProfile, i7, &wg_emlrtRTEI);
      loop_ub = b_sldProfile->size[0] * b_sldProfile->size[1];
      for (i7 = 0; i7 < loop_ub; i7++) {
        sldProfile->data[i7] = b_sldProfile->data[i7];
      }
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 3U);
      i7 = sldProfile->size[0] * sldProfile->size[1];
      sldProfile->size[0] = 1;
      sldProfile->size[1] = 3;
      emxEnsureCapacity_real_T(&st, sldProfile, i7, &vg_emlrtRTEI);
      sldProfile->data[0] = 0.0;
      sldProfile->data[1] = 0.0;
      sldProfile->data[2] = 0.0;
    }

    /*  If required, then resample the SLD */
    if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 2, resample->data[b_i] == 1.0))
    {
      covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 4U);
      b_st.site = &q_emlrtRSI;
      resampleLayers(&b_st, sldProfile, theseLayers);
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 5U);
    }

    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 6U);

    /*  Apply scale factors and q shifts to the data */
    i7 = output->size[0] * output->size[1];
    output->size[0] = allData->data[b_i].f1->size[0];
    output->size[1] = 3;
    emxEnsureCapacity_real_T(&st, output, i7, &xg_emlrtRTEI);
    loop_ub = allData->data[b_i].f1->size[0] * allData->data[b_i].f1->size[1];
    for (i7 = 0; i7 < loop_ub; i7++) {
      output->data[i7] = allData->data[b_i].f1->data[i7];
    }

    b_st.site = &r_emlrtRSI;
    shiftdata(&b_st, sf->data[(int32_T)cScales->data[b_i] - 1], shifts->data
              [(int32_T)cShifts->data[b_i] - 1], dataPresent->data[b_i], output,
              dataLimits->data[b_i].f1);

    /*  Calculate the reflectivity */
    b_st.site = &s_emlrtRSI;
    b_callReflectivity(&b_st, nba->data[(int32_T)cNbas->data[b_i] - 1],
                       nbs->data[(int32_T)cNbss->data[b_i] - 1], simLimits->
                       data[b_i].f1, repeatLayers->data[b_i].f1, output,
                       theseLayers, ssubs, res->data[(int32_T)cRes->data[b_i] -
                       1], b_sldProfile, Simul);

    /*  Apply background correction, either to the simulation or the data */
    b_st.site = &t_emlrtRSI;
    applyBackgroundCorrection(&b_st, b_sldProfile, Simul, output, backs->data
      [(int32_T)cBacks->data[b_i] - 1], backsType->data[b_i]);
    loop_ub = output->size[0] * output->size[1];
    i7 = shifted_data->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &rm_emlrtBCI, &st);
    }

    i7 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[0] = output->size[0];
    emxEnsureCapacity_real_T(&st, shifted_data->data[b_i].f1, i7, &in_emlrtRTEI);
    i7 = shifted_data->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &rm_emlrtBCI, &st);
    }

    i7 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(&st, shifted_data->data[b_i].f1, i7, &in_emlrtRTEI);
    i7 = shifted_data->size[0] - 1;
    i8 = shifted_data->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &rm_emlrtBCI, &st);
    }

    i8 = shifted_data->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &rm_emlrtBCI, &st);
    }

    for (i8 = 0; i8 < loop_ub; i8++) {
      if (b_i > i7) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &rm_emlrtBCI, &st);
      }

      shifted_data->data[b_i].f1->data[i8] = output->data[i8];
    }

    /*  Calculate chi squared. */
    i7 = b_i + 1;
    if ((i7 < 1) || (i7 > chis->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, chis->size[0], &sm_emlrtBCI, &st);
    }

    b_st.site = &u_emlrtRSI;
    chis->data[i7 - 1] = chiSquared(&b_st, output, b_sldProfile, nParams);

    /*  Store returned values for this contrast in the output arrays. */
    /*  As well as the calculated profiles, we also store a record of  */
    /*  the other values (background, scalefactors etc) for each contrast */
    /*  for future use. */
    loop_ub = sldProfile->size[0] * sldProfile->size[1];
    i7 = sldProfiles->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &tm_emlrtBCI, sp);
    }

    i7 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i7, &jn_emlrtRTEI);
    i7 = sldProfiles->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &tm_emlrtBCI, sp);
    }

    i7 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = sldProfile->size[1];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i7, &jn_emlrtRTEI);
    i7 = sldProfiles->size[0] - 1;
    i8 = sldProfiles->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &tm_emlrtBCI, sp);
    }

    i8 = sldProfiles->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &tm_emlrtBCI, sp);
    }

    for (i8 = 0; i8 < loop_ub; i8++) {
      if (b_i > i7) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &tm_emlrtBCI, sp);
      }

      sldProfiles->data[b_i].f1->data[i8] = sldProfile->data[i8];
    }

    if (10000 < b_sldProfile->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, b_sldProfile->size[0], &x_emlrtECI, sp);
    }

    loop_ub = b_sldProfile->size[0] * b_sldProfile->size[1];
    i7 = reflectivity->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &um_emlrtBCI, sp);
    }

    i7 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = b_sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i7, &kn_emlrtRTEI);
    i7 = reflectivity->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &um_emlrtBCI, sp);
    }

    i7 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i7, &kn_emlrtRTEI);
    i7 = reflectivity->size[0] - 1;
    i8 = reflectivity->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &um_emlrtBCI, sp);
    }

    i8 = reflectivity->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &um_emlrtBCI, sp);
    }

    for (i8 = 0; i8 < loop_ub; i8++) {
      if (b_i > i7) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &um_emlrtBCI, sp);
      }

      reflectivity->data[b_i].f1->data[i8] = b_sldProfile->data[i8];
    }

    if (10000 < Simul->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, Simul->size[0], &y_emlrtECI, sp);
    }

    loop_ub = Simul->size[0] * Simul->size[1];
    i7 = Simulation->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &vm_emlrtBCI, sp);
    }

    i7 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = Simul->size[0];
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i7, &ln_emlrtRTEI);
    i7 = Simulation->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &vm_emlrtBCI, sp);
    }

    i7 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i7, &ln_emlrtRTEI);
    i7 = Simulation->size[0] - 1;
    i8 = Simulation->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &vm_emlrtBCI, sp);
    }

    i8 = Simulation->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &vm_emlrtBCI, sp);
    }

    for (i8 = 0; i8 < loop_ub; i8++) {
      if (b_i > i7) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &vm_emlrtBCI, sp);
      }

      Simulation->data[b_i].f1->data[i8] = Simul->data[i8];
    }

    loop_ub = theseLayers->size[0] * theseLayers->size[1];
    i7 = layerSlds->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &wm_emlrtBCI, sp);
    }

    i7 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = theseLayers->size[0];
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i7, &mn_emlrtRTEI);
    i7 = layerSlds->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &wm_emlrtBCI, sp);
    }

    i7 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i7, &mn_emlrtRTEI);
    i7 = layerSlds->size[0] - 1;
    i8 = layerSlds->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &wm_emlrtBCI, sp);
    }

    i8 = layerSlds->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &wm_emlrtBCI, sp);
    }

    for (i8 = 0; i8 < loop_ub; i8++) {
      if (b_i > i7) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &wm_emlrtBCI, sp);
      }

      layerSlds->data[b_i].f1->data[i8] = theseLayers->data[i8];
    }

    i7 = b_i + 1;
    if ((i7 < 1) || (i7 > backgs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, backgs->size[0], &xm_emlrtBCI, sp);
    }

    backgs->data[i7 - 1] = backs->data[i1 - 1];
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > qshifts->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, qshifts->size[0], &ym_emlrtBCI, sp);
    }

    qshifts->data[i1 - 1] = shifts->data[i2 - 1];
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > sfs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, sfs->size[0], &an_emlrtBCI, sp);
    }

    sfs->data[i1 - 1] = sf->data[i3 - 1];
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbas->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbas->size[0], &bn_emlrtBCI, sp);
    }

    nbas->data[i1 - 1] = nba->data[i4 - 1];
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbss->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &cn_emlrtBCI, sp);
    }

    nbss->data[i1 - 1] = nbs->data[i5 - 1];
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > resols->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, resols->size[0], &dn_emlrtBCI, sp);
    }

    resols->data[i1 - 1] = res->data[i6 - 1];
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > allRoughs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, allRoughs->size[0], &en_emlrtBCI, sp);
    }

    allRoughs->data[i1 - 1] = allRoughs->data[b_i];
  }

  emxFree_real_T(&b_sldProfile);
  emxFree_real_T(&Simul);
  emxFree_real_T(&theseLayers);
  emxFree_real_T(&output);
  emxFree_real_T(&sldProfile);
  covrtLogFor(&emlrtCoverageInstance, 32U, 0U, 3, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_custlay_paraPoints.c) */
