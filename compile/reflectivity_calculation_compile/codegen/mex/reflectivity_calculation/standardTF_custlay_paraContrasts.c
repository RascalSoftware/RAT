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
#include "matlabEngineCaller_customLayers.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"

/* Variable Definitions */
static emlrtRSInfo sh_emlrtRSI = { 53, /* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo th_emlrtRSI = { 56, /* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo uh_emlrtRSI = { 78, /* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtRTEInfo xc_emlrtRTEI = { 29,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo yc_emlrtRTEI = { 35,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = { 41,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = { 48,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtBCInfo fn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  84,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  95,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  106,                                 /* colNo */
  "cScales",                           /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo in_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  115,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  124,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  132,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo ab_emlrtECI = { 1,  /* nDims */
  57,                                  /* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtBCInfo ln_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  27,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  64,                                  /* lineNo */
  29,                                  /* colNo */
  "resample",                          /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  35,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo on_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  31,                                  /* colNo */
  "backsType",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo bb_emlrtECI = { 1,  /* nDims */
  91,                                  /* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtECInfo cb_emlrtECI = { 1,  /* nDims */
  92,                                  /* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtBCInfo pn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  37,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  24,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  33,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  31,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo lc_emlrtDCI = { 14, /* lineNo */
  16,                                  /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo tn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  30,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo un_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  16,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ao_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  94,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo co_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  5,                                   /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo do_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  91,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo go_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  96,                                  /* lineNo */
  5,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ho_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  5,                                   /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo io_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  98,                                  /* lineNo */
  5,                                   /* colNo */
  "sfs",                               /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  5,                                   /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ko_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  100,                                 /* lineNo */
  5,                                   /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  101,                                 /* lineNo */
  5,                                   /* colNo */
  "resols",                            /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  5,                                   /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo nn_emlrtRTEI = { 4,/* lineNo */
  13,                                  /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo on_emlrtRTEI = { 30,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo pn_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo qn_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo rn_emlrtRTEI = { 20,/* lineNo */
  13,                                  /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo sn_emlrtRTEI = { 57,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo tn_emlrtRTEI = { 90,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo un_emlrtRTEI = { 91,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo vn_emlrtRTEI = { 92,/* lineNo */
  5,                                   /* colNo */
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
  emxArray_real_T *reflect;
  emxArray_real_T *Simul;
  emxArray_real_T *output;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  real_T layers;
  int32_T i7;
  int32_T loop_ub;
  int32_T i8;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 33U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 33U, 0U);

  /*  Pre-Allocation of output arrays... */
  /*    --- Begin Memory Allocation --- */
  if (numberOfContrasts != (int32_T)muDoubleScalarFloor(numberOfContrasts)) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &lc_emlrtDCI, sp);
  }

  i = (int32_T)numberOfContrasts;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &xc_emlrtRTEI, sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i1, &nn_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 33U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 33U, 1U);
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &tn_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &on_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &tn_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &on_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &tn_emlrtBCI, sp);
    }

    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &tn_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &tn_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &tn_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &tn_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &tn_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 33U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 33U, 2U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &yc_emlrtRTEI, sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i1, &nn_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 33U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 33U, 3U);
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &un_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &pn_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &un_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &pn_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &un_emlrtBCI, sp);
    }

    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &un_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &un_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &un_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &un_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &un_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 33U, 0U, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 33U, 4U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &ad_emlrtRTEI, sp);
  i1 = allLayers->size[0];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_17(sp, allLayers, i1, &nn_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 33U, 0U, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 33U, 5U);
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &vn_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &qn_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &vn_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &qn_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &vn_emlrtBCI, sp);
    }

    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &vn_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &vn_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &vn_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 33U, 0U, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 33U, 6U);

  /*    --- End Memory Allocation --- */
  /*  Parallelise  over all contrasts */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &bd_emlrtRTEI, sp);
  i1 = allRoughs->size[0];
  allRoughs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, allRoughs, i1, &rn_emlrtRTEI);
  i1 = allLayers->size[0];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_17(sp, allLayers, i1, &nn_emlrtRTEI);
  i1 = outSsubs->size[0];
  outSsubs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, outSsubs, i1, &rn_emlrtRTEI);
  i1 = sldProfiles->size[0];
  sldProfiles->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_12(sp, sldProfiles, i1, &nn_emlrtRTEI);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i1, &nn_emlrtRTEI);
  i1 = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i1, &nn_emlrtRTEI);
  i1 = shifted_data->size[0];
  shifted_data->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, shifted_data, i1, &nn_emlrtRTEI);
  i1 = layerSlds->size[0];
  layerSlds->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, layerSlds, i1, &nn_emlrtRTEI);
  i1 = chis->size[0];
  chis->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, chis, i1, &rn_emlrtRTEI);
  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &rn_emlrtRTEI);
  i1 = qshifts->size[0];
  qshifts->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, qshifts, i1, &rn_emlrtRTEI);
  i1 = sfs->size[0];
  sfs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, sfs, i1, &rn_emlrtRTEI);
  i1 = nbas->size[0];
  nbas->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbas, i1, &rn_emlrtRTEI);
  i1 = nbss->size[0];
  nbss->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbss, i1, &rn_emlrtRTEI);
  i1 = resols->size[0];
  resols->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, resols, i1, &rn_emlrtRTEI);
  emxInit_real_T(sp, &sldProfile, 2, &nn_emlrtRTEI, true);
  emxInit_real_T(sp, &reflect, 2, &nn_emlrtRTEI, true);
  emxInit_real_T(sp, &Simul, 2, &nn_emlrtRTEI, true);
  emxInit_real_T(sp, &output, 2, &nn_emlrtRTEI, true);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 33U, 0U, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 33U, 7U);

    /*  Extract the relevant parameter values for this contrast */
    /*  from the input arrays. */
    /*  First need to decide which values of the backrounds, scalefactors */
    /*  data shifts and bulk contrasts are associated with this contrast */
    st.site = &sh_emlrtRSI;
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cBacks->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cBacks->size[1], &fn_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cShifts->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cShifts->size[1], &gn_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cScales->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cScales->size[1], &hn_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cNbas->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cNbas->size[1], &in_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cNbss->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cNbss->size[1], &jn_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cRes->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cRes->size[1], &kn_emlrtBCI, &st);
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
    st.site = &th_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 30U, 0U);
    covrtLogBasicBlock(&emlrtCoverageInstance, 30U, 0U);

    /* switch lang */
    /*     case 'matlab' */
    b_st.site = &mh_emlrtRSI;
    matlabEngineCaller_customLayers(&b_st, params, (real_T)b_i + 1.0, fname,
      path, nba->data[(int32_T)cNbas->data[b_i] - 1], nbs->data[(int32_T)
      cNbss->data[b_i] - 1], output, &layers);
    if (1 > params->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, params->size[1], &xk_emlrtBCI, &st);
    }

    i7 = (int32_T)(b_i + 1U);
    if ((i7 < 1) || (i7 > allRoughs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, allRoughs->size[0], &wn_emlrtBCI, &st);
    }

    allRoughs->data[i7 - 1] = params->data[0];

    /* case 'octave' */
    /*     [output,layers] = octaveCaller_customLayers(params,contrast,file,callPath,bulkIn,bulkOut); */
    /* case 'python' */
    /*     [output,layers] = pythonCaller_customLayers(params,contrast,file,callPath,bulkIn,bulkOut); */
    /* end */
    if (10000 < output->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, output->size[0], &ab_emlrtECI, sp);
    }

    loop_ub = output->size[0] * output->size[1];
    i7 = allLayers->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &xn_emlrtBCI, sp);
    }

    i7 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = output->size[0];
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i7, &sn_emlrtRTEI);
    i7 = allLayers->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &xn_emlrtBCI, sp);
    }

    i7 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i7, &sn_emlrtRTEI);
    i7 = allLayers->size[0] - 1;
    i8 = allLayers->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &xn_emlrtBCI, sp);
    }

    i8 = allLayers->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &xn_emlrtBCI, sp);
    }

    for (i8 = 0; i8 < loop_ub; i8++) {
      if (b_i > i7) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &xn_emlrtBCI, sp);
      }

      allLayers->data[b_i].f1->data[i8] = output->data[i8];
    }

    /*  For the other parameters, we extract the correct ones from the input */
    /*  arrays */
    i7 = b_i + 1;
    if ((i7 < 1) || (i7 > allRoughs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, allRoughs->size[0], &ln_emlrtBCI, sp);
    }

    /*  Substrate roughness is always first parameter for custom layers */
    i7 = repeatLayers->size[1] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &pn_emlrtBCI, sp);
    }

    i7 = b_i + 1;
    if ((i7 < 1) || (i7 > resample->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, resample->size[1], &mn_emlrtBCI, sp);
    }

    i7 = allData->size[1] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &qn_emlrtBCI, sp);
    }

    i7 = b_i + 1;
    if ((i7 < 1) || (i7 > dataPresent->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, dataPresent->size[1], &nn_emlrtBCI,
        sp);
    }

    i7 = dataLimits->size[1] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &rn_emlrtBCI, sp);
    }

    i7 = simLimits->size[1] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &sn_emlrtBCI, sp);
    }

    i7 = b_i + 1;
    if ((i7 < 1) || (i7 > backsType->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, backsType->size[1], &on_emlrtBCI, sp);
    }

    /*  Now call the core standardTF_stanlay reflectivity calculation */
    /*  In this case we are single cored, so we do not parallelise over */
    /*  points */
    /*  Call the reflectivity calculation */
    i7 = shifted_data->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &yn_emlrtBCI, sp);
    }

    i7 = layerSlds->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &ao_emlrtBCI, sp);
    }

    i7 = b_i + 1;
    if ((i7 < 1) || (i7 > chis->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, chis->size[0], &bo_emlrtBCI, sp);
    }

    i8 = b_i + 1;
    if ((i8 < 1) || (i8 > outSsubs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i8, 1, outSsubs->size[0], &co_emlrtBCI, sp);
    }

    st.site = &uh_emlrtRSI;
    c_standardTF_layers_core(&st, output, allRoughs->data[b_i], geometry,
      nba->data[(int32_T)cNbas->data[b_i] - 1], nbs->data[(int32_T)cNbss->
      data[b_i] - 1], resample->data[b_i], calcSld, sf->data[(int32_T)
      cScales->data[b_i] - 1], shifts->data[(int32_T)cShifts->data[b_i] - 1],
      dataPresent->data[b_i], allData->data[b_i].f1, dataLimits->data[b_i].f1,
      simLimits->data[b_i].f1, repeatLayers->data[b_i].f1, backs->data[(int32_T)
      cBacks->data[b_i] - 1], res->data[(int32_T)cRes->data[b_i] - 1],
      backsType->data[b_i], nParams, sldProfile, reflect, Simul,
      shifted_data->data[b_i].f1, layerSlds->data[b_i].f1, &chis->data[i7 - 1],
      &outSsubs->data[i8 - 1]);

    /*  Store returned values for this contrast in the output arrays. */
    /*  As well as the calculated profiles, we also store a record of  */
    /*  the other values (background, scalefactors etc) for each contrast */
    /*  for future use. */
    loop_ub = sldProfile->size[0] * sldProfile->size[1];
    i7 = sldProfiles->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &do_emlrtBCI, sp);
    }

    i7 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i7, &tn_emlrtRTEI);
    i7 = sldProfiles->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &do_emlrtBCI, sp);
    }

    i7 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = sldProfile->size[1];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i7, &tn_emlrtRTEI);
    i7 = sldProfiles->size[0] - 1;
    i8 = sldProfiles->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &do_emlrtBCI, sp);
    }

    i8 = sldProfiles->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &do_emlrtBCI, sp);
    }

    for (i8 = 0; i8 < loop_ub; i8++) {
      if (b_i > i7) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &do_emlrtBCI, sp);
      }

      sldProfiles->data[b_i].f1->data[i8] = sldProfile->data[i8];
    }

    if (10000 < reflect->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, reflect->size[0], &bb_emlrtECI, sp);
    }

    loop_ub = reflect->size[0] * reflect->size[1];
    i7 = reflectivity->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &eo_emlrtBCI, sp);
    }

    i7 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = reflect->size[0];
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i7, &un_emlrtRTEI);
    i7 = reflectivity->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &eo_emlrtBCI, sp);
    }

    i7 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i7, &un_emlrtRTEI);
    i7 = reflectivity->size[0] - 1;
    i8 = reflectivity->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &eo_emlrtBCI, sp);
    }

    i8 = reflectivity->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &eo_emlrtBCI, sp);
    }

    for (i8 = 0; i8 < loop_ub; i8++) {
      if (b_i > i7) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &eo_emlrtBCI, sp);
      }

      reflectivity->data[b_i].f1->data[i8] = reflect->data[i8];
    }

    if (10000 < Simul->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, Simul->size[0], &cb_emlrtECI, sp);
    }

    loop_ub = Simul->size[0] * Simul->size[1];
    i7 = Simulation->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &fo_emlrtBCI, sp);
    }

    i7 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = Simul->size[0];
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i7, &vn_emlrtRTEI);
    i7 = Simulation->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &fo_emlrtBCI, sp);
    }

    i7 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i7, &vn_emlrtRTEI);
    i7 = Simulation->size[0] - 1;
    i8 = Simulation->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &fo_emlrtBCI, sp);
    }

    i8 = Simulation->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &fo_emlrtBCI, sp);
    }

    for (i8 = 0; i8 < loop_ub; i8++) {
      if (b_i > i7) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &fo_emlrtBCI, sp);
      }

      Simulation->data[b_i].f1->data[i8] = Simul->data[i8];
    }

    i7 = b_i + 1;
    if ((i7 < 1) || (i7 > backgs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, backgs->size[0], &go_emlrtBCI, sp);
    }

    backgs->data[i7 - 1] = backs->data[i1 - 1];
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > qshifts->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, qshifts->size[0], &ho_emlrtBCI, sp);
    }

    qshifts->data[i1 - 1] = shifts->data[i2 - 1];
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > sfs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, sfs->size[0], &io_emlrtBCI, sp);
    }

    sfs->data[i1 - 1] = sf->data[i3 - 1];
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbas->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbas->size[0], &jo_emlrtBCI, sp);
    }

    nbas->data[i1 - 1] = nba->data[i4 - 1];
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbss->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &ko_emlrtBCI, sp);
    }

    nbss->data[i1 - 1] = nbs->data[i5 - 1];
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > resols->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, resols->size[0], &lo_emlrtBCI, sp);
    }

    resols->data[i1 - 1] = res->data[i6 - 1];
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > allRoughs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, allRoughs->size[0], &mo_emlrtBCI, sp);
    }

    allRoughs->data[i1 - 1] = allRoughs->data[b_i];
  }

  emxFree_real_T(&output);
  emxFree_real_T(&Simul);
  emxFree_real_T(&reflect);
  emxFree_real_T(&sldProfile);
  covrtLogFor(&emlrtCoverageInstance, 33U, 0U, 3, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_custlay_paraContrasts.c) */
