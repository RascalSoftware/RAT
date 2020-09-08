/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_custlay_single.c
 *
 * Code generation for function 'standardTF_custlay_single'
 *
 */

/* Include files */
#include "standardTF_custlay_single.h"
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
static emlrtRSInfo ah_emlrtRSI = { 85, /* lineNo */
  "standardTF_custlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pathName */
};

static emlrtRSInfo bh_emlrtRSI = { 87, /* lineNo */
  "standardTF_custlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pathName */
};

static emlrtRSInfo ch_emlrtRSI = { 90, /* lineNo */
  "standardTF_custlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pathName */
};

static emlrtRSInfo dh_emlrtRSI = { 92, /* lineNo */
  "standardTF_custlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pathName */
};

static emlrtRSInfo eh_emlrtRSI = { 96, /* lineNo */
  "standardTF_custlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pathName */
};

static emlrtRSInfo fh_emlrtRSI = { 103,/* lineNo */
  "standardTF_custlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pathName */
};

static emlrtRSInfo gh_emlrtRSI = { 106,/* lineNo */
  "standardTF_custlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pathName */
};

static emlrtRSInfo hh_emlrtRSI = { 108,/* lineNo */
  "standardTF_custlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pathName */
};

static emlrtRSInfo ih_emlrtRSI = { 113,/* lineNo */
  "standardTF_custlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pathName */
};

static emlrtRTEInfo ic_emlrtRTEI = { 66,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = { 72,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo kc_emlrtRTEI = { 78,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo lc_emlrtRTEI = { 84,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtECInfo r_emlrtECI = { 1,   /* nDims */
  88,                                  /* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtBCInfo tk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  85,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  93,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  125,                                 /* colNo */
  "backgs",                            /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo s_emlrtECI = { 1,   /* nDims */
  110,                                 /* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtECInfo t_emlrtECI = { 1,   /* nDims */
  111,                                 /* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtDCInfo ub_emlrtDCI = { 51, /* lineNo */
  16,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo wk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo al_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  72,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bl_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  82,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cl_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  93,                                  /* colNo */
  "cScales",                           /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dl_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  104,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo el_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  113,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fl_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  122,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gl_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  6,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hl_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  16,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo il_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  27,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jl_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kl_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ll_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  50,                                  /* colNo */
  "resols",                            /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ml_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  70,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nl_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  78,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ol_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  16,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pl_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ql_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  58,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rl_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  17,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sl_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tl_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ul_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  60,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vl_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  72,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wl_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xl_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  8,                                   /* colNo */
  "resample",                          /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yl_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  100,                                 /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo am_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  62,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  29,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  36,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo em_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  47,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  73,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  40,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo im_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  48,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  56,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo km_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  69,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  106,                                 /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  128,                                 /* colNo */
  "resols",                            /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  87,                                  /* colNo */
  "backgs",                            /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo om_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  97,                                  /* colNo */
  "backsType",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo em_emlrtRTEI = { 15,/* lineNo */
  26,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo fm_emlrtRTEI = { 67,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo gm_emlrtRTEI = { 73,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo hm_emlrtRTEI = { 51,/* lineNo */
  10,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo im_emlrtRTEI = { 79,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo jm_emlrtRTEI = { 88,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo km_emlrtRTEI = { 93,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo lm_emlrtRTEI = { 100,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo mm_emlrtRTEI = { 97,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo nm_emlrtRTEI = { 103,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo om_emlrtRTEI = { 104,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo pm_emlrtRTEI = { 110,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo qm_emlrtRTEI = { 111,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo rm_emlrtRTEI = { 92,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo sm_emlrtRTEI = { 96,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

/* Function Definitions */
void standardTF_custlay_single(const emlrtStack *sp, const emxArray_real_T
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
  int32_T b_i;
  int32_T i2;
  emxArray_real_T *sldProfile;
  emxArray_real_T *layerSld;
  emxArray_real_T *shifted_dat;
  emxArray_real_T *Simul;
  int32_T loop_ub;
  int32_T i3;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* coder.extrinsic('callModules');             */
  /* Pre-Allocation... */
  if (numberOfContrasts != (int32_T)muDoubleScalarFloor(numberOfContrasts)) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &ub_emlrtDCI, sp);
  }

  i = (int32_T)numberOfContrasts;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &ic_emlrtRTEI, sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, reflectivity, i1, &em_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &wk_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &fm_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &wk_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &fm_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &wk_emlrtBCI, sp);
    }

    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &wk_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &wk_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &wk_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &wk_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &wk_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &jc_emlrtRTEI, sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, Simulation, i1, &em_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &xk_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &gm_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &xk_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &gm_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &xk_emlrtBCI, sp);
    }

    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &xk_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &xk_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &xk_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &xk_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &xk_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &kc_emlrtRTEI, sp);
  i1 = allLayers->size[0];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_15(sp, allLayers, i1, &em_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &yk_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &im_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &yk_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &im_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &yk_emlrtBCI, sp);
    }

    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &yk_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &yk_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &yk_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &lc_emlrtRTEI, sp);
  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &hm_emlrtRTEI);
  i1 = qshifts->size[0];
  qshifts->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, qshifts, i1, &hm_emlrtRTEI);
  i1 = sfs->size[0];
  sfs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, sfs, i1, &hm_emlrtRTEI);
  i1 = nbas->size[0];
  nbas->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbas, i1, &hm_emlrtRTEI);
  i1 = nbss->size[0];
  nbss->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbss, i1, &hm_emlrtRTEI);
  i1 = resols->size[0];
  resols->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, resols, i1, &hm_emlrtRTEI);
  i1 = allRoughs->size[0];
  allRoughs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, allRoughs, i1, &hm_emlrtRTEI);
  i1 = allLayers->size[0];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_15(sp, allLayers, i1, &em_emlrtRTEI);
  i1 = outSsubs->size[0];
  outSsubs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, outSsubs, i1, &hm_emlrtRTEI);
  i1 = sldProfiles->size[0];
  sldProfiles->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, sldProfiles, i1, &em_emlrtRTEI);
  i1 = layerSlds->size[0];
  layerSlds->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, layerSlds, i1, &em_emlrtRTEI);
  i1 = shifted_data->size[0];
  shifted_data->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, shifted_data, i1, &em_emlrtRTEI);
  i1 = chis->size[0];
  chis->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, chis, i1, &hm_emlrtRTEI);
  i1 = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, Simulation, i1, &em_emlrtRTEI);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, reflectivity, i1, &em_emlrtRTEI);
  emxInit_real_T(sp, &sldProfile, 2, &rm_emlrtRTEI, true);
  emxInit_real_T(sp, &layerSld, 2, &sm_emlrtRTEI, true);
  emxInit_real_T(sp, &shifted_dat, 2, &nm_emlrtRTEI, true);
  emxInit_real_T(sp, &Simul, 2, &em_emlrtRTEI, true);
  for (b_i = 0; b_i < i; b_i++) {
    i1 = (int32_T)(b_i + 1U);
    if ((i1 < 1) || (i1 > cBacks->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cBacks->size[1], &al_emlrtBCI, sp);
    }

    if (i1 > cShifts->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cShifts->size[1], &bl_emlrtBCI, sp);
    }

    if (i1 > cScales->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cScales->size[1], &cl_emlrtBCI, sp);
    }

    if (i1 > cNbas->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cNbas->size[1], &dl_emlrtBCI, sp);
    }

    if (i1 > cNbss->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cNbss->size[1], &el_emlrtBCI, sp);
    }

    if (i1 > cRes->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cRes->size[1], &fl_emlrtBCI, sp);
    }

    if (i1 > backgs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, backgs->size[0], &gl_emlrtBCI, sp);
    }

    if (i1 > qshifts->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, qshifts->size[0], &hl_emlrtBCI, sp);
    }

    if (i1 > sfs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, sfs->size[0], &il_emlrtBCI, sp);
    }

    if (i1 > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbas->size[0], &jl_emlrtBCI, sp);
    }

    if (i1 > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &kl_emlrtBCI, sp);
    }

    if (i1 > resols->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, resols->size[0], &ll_emlrtBCI, sp);
    }

    st.site = &ah_emlrtRSI;
    backSort(&st, cBacks->data[i1 - 1], cShifts->data[i1 - 1], cScales->data[i1
             - 1], cNbas->data[i1 - 1], cNbss->data[i1 - 1], cRes->data[i1 - 1],
             backs, shifts, sf, nba, nbs, res, &backgs->data[i1 - 1],
             &qshifts->data[i1 - 1], &sfs->data[i1 - 1], &nbas->data[i1 - 1],
             &nbss->data[i1 - 1], &resols->data[i1 - 1]);
    if (i1 > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbas->size[0], &ml_emlrtBCI, sp);
    }

    if (i1 > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &nl_emlrtBCI, sp);
    }

    if (i1 > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, allRoughs->size[0], &ol_emlrtBCI, sp);
    }

    st.site = &bh_emlrtRSI;
    call_customLayers(&st, params, (real_T)b_i + 1.0, fname, path, nbas->data[i1
                      - 1], nbss->data[i1 - 1], shifted_dat, &allRoughs->data[i1
                      - 1]);
    if (10000 < shifted_dat->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, shifted_dat->size[0], &r_emlrtECI, sp);
    }

    loop_ub = shifted_dat->size[0] * shifted_dat->size[1];
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pl_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &jm_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pl_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &jm_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &pl_emlrtBCI, sp);
    }

    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &pl_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pl_emlrtBCI, sp);
      }

      allLayers->data[b_i].f1->data[i2] = shifted_dat->data[i2];
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbas->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbas->size[0], &tk_emlrtBCI, sp);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbss->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &uk_emlrtBCI, sp);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > allRoughs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, allRoughs->size[0], &ql_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > outSsubs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, outSsubs->size[0], &rl_emlrtBCI, sp);
    }

    st.site = &ch_emlrtRSI;
    b_groupLayers_Mod(&st, shifted_dat, allRoughs->data[i1 - 1], geometry,
                      layerSld, &outSsubs->data[i2 - 1]);
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbas->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbas->size[0], &sl_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > nbss->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, nbss->size[0], &tl_emlrtBCI, sp);
    }

    loop_ub = b_i + 1;
    if ((loop_ub < 1) || (loop_ub > outSsubs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, outSsubs->size[0], &ul_emlrtBCI,
        sp);
    }

    i3 = repeatLayers->size[1] - 1;
    if (b_i > i3) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &vl_emlrtBCI, sp);
    }

    st.site = &dh_emlrtRSI;
    makeSLDProfiles(&st, nbas->data[i1 - 1], nbss->data[i2 - 1], layerSld,
                    outSsubs->data[loop_ub - 1], repeatLayers->data[b_i].f1,
                    sldProfile);
    loop_ub = sldProfile->size[0] * sldProfile->size[1];
    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &wl_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &km_emlrtRTEI);
    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &wl_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &km_emlrtRTEI);
    i1 = sldProfiles->size[0] - 1;
    i2 = sldProfiles->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &wl_emlrtBCI, sp);
    }

    i2 = sldProfiles->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &wl_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &wl_emlrtBCI, sp);
      }

      sldProfiles->data[b_i].f1->data[i2] = sldProfile->data[i2];
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > resample->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, resample->size[1], &xl_emlrtBCI, sp);
    }

    if (resample->data[i1 - 1] == 1.0) {
      st.site = &eh_emlrtRSI;
      resampleLayers(&st, sldProfile, layerSld);
      loop_ub = layerSld->size[0] * layerSld->size[1];
      i1 = layerSlds->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &am_emlrtBCI, sp);
      }

      i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
      layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
      emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &mm_emlrtRTEI);
      i1 = layerSlds->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &am_emlrtBCI, sp);
      }

      i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
      layerSlds->data[b_i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &mm_emlrtRTEI);
      i1 = layerSlds->size[0] - 1;
      i2 = layerSlds->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &am_emlrtBCI, sp);
      }

      i2 = layerSlds->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &am_emlrtBCI, sp);
      }

      for (i2 = 0; i2 < loop_ub; i2++) {
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &am_emlrtBCI, sp);
        }

        layerSlds->data[b_i].f1->data[i2] = layerSld->data[i2];
      }
    } else {
      loop_ub = layerSld->size[0] * layerSld->size[1];
      i1 = layerSlds->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &yl_emlrtBCI, sp);
      }

      i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
      layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
      emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &lm_emlrtRTEI);
      i1 = layerSlds->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &yl_emlrtBCI, sp);
      }

      i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
      layerSlds->data[b_i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &lm_emlrtRTEI);
      i1 = layerSlds->size[0] - 1;
      i2 = layerSlds->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &yl_emlrtBCI, sp);
      }

      i2 = layerSlds->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &yl_emlrtBCI, sp);
      }

      for (i2 = 0; i2 < loop_ub; i2++) {
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &yl_emlrtBCI, sp);
        }

        layerSlds->data[b_i].f1->data[i2] = layerSld->data[i2];
      }
    }

    i1 = allData->size[1] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bm_emlrtBCI, sp);
    }

    i1 = shifted_dat->size[0] * shifted_dat->size[1];
    shifted_dat->size[0] = allData->data[b_i].f1->size[0];
    shifted_dat->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_dat, i1, &nm_emlrtRTEI);
    i1 = allData->size[1] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bm_emlrtBCI, sp);
    }

    i1 = allData->size[1] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bm_emlrtBCI, sp);
    }

    loop_ub = allData->data[b_i].f1->size[0] * allData->data[b_i].f1->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      i2 = allData->size[1] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &bm_emlrtBCI, sp);
      }

      i2 = allData->size[1] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &bm_emlrtBCI, sp);
      }

      i2 = allData->size[1] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &bm_emlrtBCI, sp);
      }

      shifted_dat->data[i1] = allData->data[b_i].f1->data[i1];
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > sfs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, sfs->size[0], &cm_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > qshifts->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, qshifts->size[0], &dm_emlrtBCI, sp);
    }

    loop_ub = b_i + 1;
    if ((loop_ub < 1) || (loop_ub > dataPresent->size[1])) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, dataPresent->size[1],
        &em_emlrtBCI, sp);
    }

    i3 = dataLimits->size[1] - 1;
    if (b_i > i3) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &fm_emlrtBCI, sp);
    }

    st.site = &fh_emlrtRSI;
    shiftdata(&st, sfs->data[i1 - 1], qshifts->data[i2 - 1], dataPresent->
              data[loop_ub - 1], shifted_dat, dataLimits->data[b_i].f1);
    loop_ub = shifted_dat->size[0] * shifted_dat->size[1];
    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &gm_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i1, &om_emlrtRTEI);
    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &gm_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i1, &om_emlrtRTEI);
    i1 = shifted_data->size[0] - 1;
    i2 = shifted_data->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &gm_emlrtBCI, sp);
    }

    i2 = shifted_data->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &gm_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &gm_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[i2] = shifted_dat->data[i2];
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > backgs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, backgs->size[0], &vk_emlrtBCI, sp);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbas->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbas->size[0], &hm_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > nbss->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, nbss->size[0], &im_emlrtBCI, sp);
    }

    loop_ub = simLimits->size[1] - 1;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &jm_emlrtBCI, sp);
    }

    loop_ub = repeatLayers->size[1] - 1;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &km_emlrtBCI, sp);
    }

    loop_ub = b_i + 1;
    if ((loop_ub < 1) || (loop_ub > outSsubs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, outSsubs->size[0], &lm_emlrtBCI,
        sp);
    }

    i3 = b_i + 1;
    if ((i3 < 1) || (i3 > resols->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, resols->size[0], &mm_emlrtBCI, sp);
    }

    st.site = &gh_emlrtRSI;
    callReflectivity(&st, nbas->data[i1 - 1], nbss->data[i2 - 1],
                     simLimits->data[b_i].f1, repeatLayers->data[b_i].f1,
                     shifted_dat, layerSld, outSsubs->data[loop_ub - 1],
                     resols->data[i3 - 1], sldProfile, Simul);
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > backgs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, backgs->size[0], &nm_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > backsType->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, backsType->size[1], &om_emlrtBCI, sp);
    }

    st.site = &hh_emlrtRSI;
    applyBackgroundCorrection(&st, sldProfile, Simul, shifted_dat, backgs->
      data[i1 - 1], backsType->data[i2 - 1]);
    if (10000 < sldProfile->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, sldProfile->size[0], &s_emlrtECI, sp);
    }

    loop_ub = sldProfile->size[0] * sldProfile->size[1];
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pm_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &pm_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pm_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &pm_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &pm_emlrtBCI, sp);
    }

    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &pm_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pm_emlrtBCI, sp);
      }

      reflectivity->data[b_i].f1->data[i2] = sldProfile->data[i2];
    }

    if (10000 < Simul->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, Simul->size[0], &t_emlrtECI, sp);
    }

    loop_ub = Simul->size[0] * Simul->size[1];
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &qm_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = Simul->size[0];
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &qm_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &qm_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &qm_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &qm_emlrtBCI, sp);
    }

    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &qm_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &qm_emlrtBCI, sp);
      }

      Simulation->data[b_i].f1->data[i2] = Simul->data[i2];
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > chis->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, chis->size[0], &rm_emlrtBCI, sp);
    }

    st.site = &ih_emlrtRSI;
    chis->data[i1 - 1] = chiSquared(&st, shifted_dat, sldProfile, nParams);
  }

  emxFree_real_T(&Simul);
  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&layerSld);
  emxFree_real_T(&sldProfile);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_custlay_single.c) */
