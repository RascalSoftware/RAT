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
#include "rt_nonfinite.h"
#include "standardTF_custlay_single.h"
#include "standardTF_custlay_single_emxutil.h"
#include "chiSquared.h"
#include "callReflectivity.h"
#include "indexShapeCheck.h"
#include "resampleLayers.h"
#include "makeSLDProfileXY.h"
#include "groupLayers_Mod.h"
#include "call_customLayers.h"
#include "standardTF_custlay_single_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 70,    /* lineNo */
  "standardTF_custlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 71,  /* lineNo */
  "standardTF_custlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 74,  /* lineNo */
  "standardTF_custlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 76,  /* lineNo */
  "standardTF_custlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 80,  /* lineNo */
  "standardTF_custlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 87,  /* lineNo */
  "standardTF_custlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 90,  /* lineNo */
  "standardTF_custlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 94,  /* lineNo */
  "standardTF_custlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 12,  /* lineNo */
  "makeSLDProfiles",                   /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfiles.m"/* pathName */
};

static emlrtRSInfo wc_emlrtRSI = { 24, /* lineNo */
  "shiftdata",                         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pathName */
};

static emlrtRSInfo xc_emlrtRSI = { 31, /* lineNo */
  "shiftdata",                         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 15,  /* lineNo */
  14,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 76,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 80,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 51,    /* lineNo */
  16,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 51,  /* lineNo */
  16,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 52,  /* lineNo */
  17,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 53,  /* lineNo */
  13,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 54,  /* lineNo */
  14,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 55,  /* lineNo */
  14,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 56,  /* lineNo */
  16,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 57,  /* lineNo */
  19,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 58,  /* lineNo */
  18,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 59,  /* lineNo */
  15,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 60,  /* lineNo */
  18,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 61,  /* lineNo */
  18,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 62,  /* lineNo */
  20,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = { 63,  /* lineNo */
  21,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 64,  /* lineNo */
  21,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = { 65,  /* lineNo */
  19,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo pb_emlrtRTEI = { 69,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  72,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  82,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  93,                                  /* colNo */
  "cScales",                           /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  104,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  113,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  122,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  34,                                  /* colNo */
  "nbairs",                            /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  44,                                  /* colNo */
  "nbsubs",                            /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  64,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  36,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  47,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  76,                                  /* colNo */
  "repeats",                           /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  73,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = { 39,  /* lineNo */
  13,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  13,                                  /* colNo */
  "backs",                             /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = { 42,  /* lineNo */
  14,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  14,                                  /* colNo */
  "shifts",                            /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo s_emlrtDCI = { 45,  /* lineNo */
  10,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  10,                                  /* colNo */
  "sf",                                /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo t_emlrtDCI = { 48,  /* lineNo */
  11,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  11,                                  /* colNo */
  "nba",                               /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo u_emlrtDCI = { 51,  /* lineNo */
  11,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  11,                                  /* colNo */
  "nbs",                               /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo v_emlrtDCI = { 54,  /* lineNo */
  13,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  54,                                  /* lineNo */
  13,                                  /* colNo */
  "res",                               /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo w_emlrtDCI = { 12,  /* lineNo */
  8,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  6,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  16,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  27,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  50,                                  /* colNo */
  "resols",                            /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  75,                                  /* colNo */
  "nbairs",                            /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  85,                                  /* colNo */
  "nbsubs",                            /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  16,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  58,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  80,                                  /* colNo */
  "nbairs",                            /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  90,                                  /* colNo */
  "nbsubs",                            /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  17,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  8,                                   /* colNo */
  "resam",                             /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  29,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  24,                                  /* colNo */
  "lowIndex",                          /* aName */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  40,                                  /* colNo */
  "nbairs",                            /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  50,                                  /* colNo */
  "nbsubs",                            /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  60,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  73,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  110,                                 /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  122,                                 /* colNo */
  "backgs",                            /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  132,                                 /* colNo */
  "resols",                            /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  91,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  94,                                  /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  62,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void standardTF_custlay_single(const emlrtStack *sp, const emxArray_real_T
  *resam, real_T numberOfContrasts, const emxArray_char_T *geometry, const
  emxArray_real_T *nbairs, const emxArray_real_T *nbsubs, const
  emxArray_cell_wrap_0 *repeats, const emxArray_real_T *cBacks, const
  emxArray_real_T *cShifts, const emxArray_real_T *cScales, const
  emxArray_real_T *cNbas, const emxArray_real_T *cNbss, const emxArray_real_T
  *cRes, const emxArray_real_T *backs, const emxArray_real_T *shifts, const
  emxArray_real_T *sf, const emxArray_real_T *nba, const emxArray_real_T *nbs,
  const emxArray_real_T *res, const emxArray_real_T *dataPresent, const
  emxArray_cell_wrap_1 *allData, const emxArray_cell_wrap_0 *dataLimits, const
  emxArray_cell_wrap_0 *simLimits, const emxArray_cell_wrap_0 *repeatLayers,
  real_T nParams, const emxArray_real_T *params, const emxArray_cell_wrap_2
  *contrastLayers, real_T numberOfLayers, real_T whichType, const
  emxArray_char_T *fileHandle, const emxArray_char_T *path, emxArray_real_T
  *outSsubs, emxArray_real_T *backgs, emxArray_real_T *qshifts, emxArray_real_T *
  sfs, emxArray_real_T *nbas, emxArray_real_T *nbss, emxArray_real_T *resols,
  emxArray_real_T *chis, emxArray_cell_wrap_3 *reflectivity,
  emxArray_cell_wrap_3 *Simulation, emxArray_cell_wrap_4 *shifted_data,
  emxArray_cell_wrap_4 *layerSlds, emxArray_cell_wrap_3 *sldProfiles,
  emxArray_cell_wrap_5 *allLayers, emxArray_real_T *allRoughs)
{
  int32_T i0;
  int32_T i;
  emxArray_real_T *sldProfile;
  emxArray_real_T *layerSld;
  emxArray_real_T *outLayers;
  int32_T i1;
  real_T reps;
  int32_T i2;
  int32_T idx;
  int32_T b_allLayers;
  int32_T loop_ub;
  real_T scalefac;
  real_T data[153];
  int32_T shifted_dat_size[2];
  real_T shifted_dat_data[153];
  boolean_T x[51];
  int8_T ii_data[51];
  boolean_T exitg2;
  boolean_T guard2 = false;
  int32_T iv0[2];
  int8_T lowIndex_data[51];
  int32_T lowIndex;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv1[2];
  real_T reflect_data[102];
  int32_T reflect_size[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  (void)contrastLayers;
  (void)numberOfLayers;
  (void)whichType;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);

  /* coder.extrinsic('callModules');             */
  /* Pre-Allocation... */
  if (!(numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(numberOfContrasts, &emlrtDCI, sp);
  }

  if (numberOfContrasts != (int32_T)muDoubleScalarFloor(numberOfContrasts)) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &b_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &c_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &d_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &e_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &f_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &g_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &h_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &i_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &j_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &k_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &l_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &m_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &n_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &o_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &p_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &pb_emlrtRTEI, sp);
  i0 = backgs->size[0];
  backgs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity(sp, (emxArray__common *)backgs, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  i0 = qshifts->size[0];
  qshifts->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity(sp, (emxArray__common *)qshifts, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  i0 = sfs->size[0];
  sfs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity(sp, (emxArray__common *)sfs, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  i0 = nbas->size[0];
  nbas->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity(sp, (emxArray__common *)nbas, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  i0 = nbss->size[0];
  nbss->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity(sp, (emxArray__common *)nbss, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  i0 = resols->size[0];
  resols->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity(sp, (emxArray__common *)resols, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  i0 = allRoughs->size[0];
  allRoughs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity(sp, (emxArray__common *)allRoughs, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  i0 = allLayers->size[0] * allLayers->size[1];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  allLayers->size[1] = 1;
  emxEnsureCapacity_cell_wrap_5(sp, allLayers, i0, &emlrtRTEI);
  i0 = outSsubs->size[0];
  outSsubs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity(sp, (emxArray__common *)outSsubs, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  i0 = sldProfiles->size[0] * sldProfiles->size[1];
  sldProfiles->size[0] = (int32_T)numberOfContrasts;
  sldProfiles->size[1] = 1;
  emxEnsureCapacity_cell_wrap_3(sp, sldProfiles, i0, &emlrtRTEI);
  i0 = layerSlds->size[0] * layerSlds->size[1];
  layerSlds->size[0] = (int32_T)numberOfContrasts;
  layerSlds->size[1] = 1;
  emxEnsureCapacity_cell_wrap_4(sp, layerSlds, i0, &emlrtRTEI);
  i0 = shifted_data->size[0] * shifted_data->size[1];
  shifted_data->size[0] = (int32_T)numberOfContrasts;
  shifted_data->size[1] = 1;
  emxEnsureCapacity_cell_wrap_4(sp, shifted_data, i0, &emlrtRTEI);
  i0 = reflectivity->size[0] * reflectivity->size[1];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  reflectivity->size[1] = 1;
  emxEnsureCapacity_cell_wrap_3(sp, reflectivity, i0, &emlrtRTEI);
  i0 = Simulation->size[0] * Simulation->size[1];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  Simulation->size[1] = 1;
  emxEnsureCapacity_cell_wrap_3(sp, Simulation, i0, &emlrtRTEI);
  i0 = chis->size[0];
  chis->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity(sp, (emxArray__common *)chis, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  i = 0;
  emxInit_real_T(sp, &sldProfile, 2, &c_emlrtRTEI, true);
  emxInit_real_T(sp, &layerSld, 2, &d_emlrtRTEI, true);
  emxInit_real_T(sp, &outLayers, 2, &emlrtRTEI, true);
  while (i <= (int32_T)numberOfContrasts - 1) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 1U);
    st.site = &emlrtRSI;
    i0 = cBacks->size[1];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &emlrtBCI, &st);
    }

    i0 = cShifts->size[1];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &b_emlrtBCI, &st);
    }

    i0 = cScales->size[1];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &c_emlrtBCI, &st);
    }

    i0 = cNbas->size[1];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &d_emlrtBCI, &st);
    }

    i0 = cNbss->size[1];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &e_emlrtBCI, &st);
    }

    i0 = cRes->size[1];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &f_emlrtBCI, &st);
    }

    covrtLogFcn(&emlrtCoverageInstance, 1U, 0U);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 0U);

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
    reps = cBacks->data[i];
    if (reps != (int32_T)muDoubleScalarFloor(reps)) {
      emlrtIntegerCheckR2012b(reps, &q_emlrtDCI, &st);
    }

    i0 = backs->size[1];
    i1 = (int32_T)reps;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &n_emlrtBCI, &st);
    }

    /* thisShift = cShifts(i); */
    reps = cShifts->data[i];
    if (reps != (int32_T)muDoubleScalarFloor(reps)) {
      emlrtIntegerCheckR2012b(reps, &r_emlrtDCI, &st);
    }

    i0 = shifts->size[1];
    i1 = (int32_T)reps;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &o_emlrtBCI, &st);
    }

    /* thisScale = cScales(i); */
    reps = cScales->data[i];
    if (reps != (int32_T)muDoubleScalarFloor(reps)) {
      emlrtIntegerCheckR2012b(reps, &s_emlrtDCI, &st);
    }

    i0 = sf->size[1];
    i1 = (int32_T)reps;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &p_emlrtBCI, &st);
    }

    /* thisNbair = cNbas(i); */
    reps = cNbas->data[i];
    if (reps != (int32_T)muDoubleScalarFloor(reps)) {
      emlrtIntegerCheckR2012b(reps, &t_emlrtDCI, &st);
    }

    i0 = nba->size[1];
    i1 = (int32_T)reps;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &q_emlrtBCI, &st);
    }

    /* thisNbsub = cNbss(i); */
    reps = cNbss->data[i];
    if (reps != (int32_T)muDoubleScalarFloor(reps)) {
      emlrtIntegerCheckR2012b(reps, &u_emlrtDCI, &st);
    }

    i0 = nbs->size[1];
    i1 = (int32_T)reps;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &r_emlrtBCI, &st);
    }

    /* thisResol = cRes(i); */
    reps = cRes->data[i];
    if (reps != (int32_T)muDoubleScalarFloor(reps)) {
      emlrtIntegerCheckR2012b(reps, &v_emlrtDCI, &st);
    }

    i0 = res->size[1];
    i1 = (int32_T)reps;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &s_emlrtBCI, &st);
    }

    /* end */
    i0 = backgs->size[0];
    i1 = (int32_T)(1U + i);
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &t_emlrtBCI, sp);
    }

    backgs->data[i1 - 1] = backs->data[(int32_T)cBacks->data[i] - 1];
    i0 = qshifts->size[0];
    i1 = (int32_T)(1U + i);
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &u_emlrtBCI, sp);
    }

    qshifts->data[i1 - 1] = shifts->data[(int32_T)cShifts->data[i] - 1];
    i0 = sfs->size[0];
    i1 = (int32_T)(1U + i);
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &v_emlrtBCI, sp);
    }

    sfs->data[i1 - 1] = sf->data[(int32_T)cScales->data[i] - 1];
    i0 = nbas->size[0];
    i1 = (int32_T)(1U + i);
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &w_emlrtBCI, sp);
    }

    nbas->data[i1 - 1] = nba->data[(int32_T)cNbas->data[i] - 1];
    i0 = nbss->size[0];
    i1 = (int32_T)(1U + i);
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &x_emlrtBCI, sp);
    }

    nbss->data[i1 - 1] = nbs->data[(int32_T)cNbss->data[i] - 1];
    i0 = resols->size[0];
    i1 = (int32_T)(1U + i);
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &y_emlrtBCI, sp);
    }

    resols->data[i1 - 1] = res->data[(int32_T)cRes->data[i] - 1];
    i0 = nbairs->size[1];
    i1 = (int32_T)(1U + i);
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &ab_emlrtBCI, sp);
    }

    i0 = nbsubs->size[1];
    i2 = (int32_T)(1U + i);
    if (!((i2 >= 1) && (i2 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, i0, &bb_emlrtBCI, sp);
    }

    i0 = allRoughs->size[0];
    idx = (int32_T)(1U + i);
    if (!((idx >= 1) && (idx <= i0))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, i0, &cb_emlrtBCI, sp);
    }

    st.site = &b_emlrtRSI;
    call_customLayers(&st, params, 1.0 + (real_T)i, fileHandle, path,
                      nbairs->data[i1 - 1], nbsubs->data[i2 - 1], outLayers,
                      &allRoughs->data[idx - 1]);
    i0 = allLayers->size[0] - 1;
    if (!((i >= 0) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i0, &db_emlrtBCI, sp);
    }

    i0 = allLayers->data[i].f1->size[0] * allLayers->data[i].f1->size[1];
    allLayers->data[i].f1->size[0] = outLayers->size[0];
    i1 = allLayers->size[0] - 1;
    if (!((i >= 0) && (i <= i1))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i1, &db_emlrtBCI, sp);
    }

    allLayers->data[i].f1->size[1] = outLayers->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)allLayers->data[i].f1, i0,
                      (int32_T)sizeof(real_T), &emlrtRTEI);
    b_allLayers = allLayers->size[0] - 1;
    idx = allLayers->size[0] - 1;
    if (!((i >= 0) && (i <= idx))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, idx, &db_emlrtBCI, sp);
    }

    idx = allLayers->size[0] - 1;
    if (!((i >= 0) && (i <= idx))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, idx, &db_emlrtBCI, sp);
    }

    loop_ub = outLayers->size[0] * outLayers->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      if (!((i >= 0) && (i <= b_allLayers))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, b_allLayers, &db_emlrtBCI, sp);
      }

      allLayers->data[i].f1->data[i0] = outLayers->data[i0];
    }

    i0 = nbairs->size[1];
    i1 = 1 + i;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &fb_emlrtBCI, sp);
    }

    i0 = nbsubs->size[1];
    i1 = 1 + i;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &gb_emlrtBCI, sp);
    }

    i0 = allRoughs->size[0];
    i1 = 1 + i;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &eb_emlrtBCI, sp);
    }

    i0 = outSsubs->size[0];
    i2 = 1 + i;
    if (!((i2 >= 1) && (i2 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, i0, &hb_emlrtBCI, sp);
    }

    st.site = &c_emlrtRSI;
    groupLayers_Mod(&st, outLayers, allRoughs->data[i1 - 1], geometry, layerSld,
                    &outSsubs->data[i2 - 1]);
    st.site = &d_emlrtRSI;
    i0 = nbairs->size[1];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &g_emlrtBCI, &st);
    }

    i0 = nbsubs->size[1];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &h_emlrtBCI, &st);
    }

    i0 = outSsubs->size[0];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &i_emlrtBCI, &st);
    }

    i0 = repeats->size[1] - 1;
    if (!((i >= 0) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i0, &l_emlrtBCI, &st);
    }

    covrtLogFcn(&emlrtCoverageInstance, 5U, 0U);
    covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 0U);
    if (covrtLogIf(&emlrtCoverageInstance, 5U, 0U, 0, repeats->data
                   [repeats->size[0] * i].f1[0] == 0.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 1U);
      reps = 1.0;
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 2U);
      reps = repeats->data[repeats->size[0] * i].f1[1];
    }

    covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 3U);
    b_st.site = &o_emlrtRSI;
    makeSLDProfileXY(&b_st, nbairs->data[i], nbsubs->data[i], outSsubs->data[i],
                     layerSld, layerSld->size[0], reps, sldProfile);
    i0 = sldProfiles->size[0] - 1;
    if (!((i >= 0) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i0, &ib_emlrtBCI, sp);
    }

    i0 = sldProfiles->data[i].f1->size[0] * sldProfiles->data[i].f1->size[1];
    sldProfiles->data[i].f1->size[0] = sldProfile->size[0];
    i1 = sldProfiles->size[0] - 1;
    if (!((i >= 0) && (i <= i1))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i1, &ib_emlrtBCI, sp);
    }

    sldProfiles->data[i].f1->size[1] = 2;
    emxEnsureCapacity(sp, (emxArray__common *)sldProfiles->data[i].f1, i0,
                      (int32_T)sizeof(real_T), &emlrtRTEI);
    b_allLayers = sldProfiles->size[0] - 1;
    idx = sldProfiles->size[0] - 1;
    if (!((i >= 0) && (i <= idx))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, idx, &ib_emlrtBCI, sp);
    }

    idx = sldProfiles->size[0] - 1;
    if (!((i >= 0) && (i <= idx))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, idx, &ib_emlrtBCI, sp);
    }

    loop_ub = sldProfile->size[0] * sldProfile->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      if (!((i >= 0) && (i <= b_allLayers))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, b_allLayers, &ib_emlrtBCI, sp);
      }

      sldProfiles->data[i].f1->data[i0] = sldProfile->data[i0];
    }

    i0 = resam->size[0];
    i1 = 1 + i;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &jb_emlrtBCI, sp);
    }

    if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 0, resam->data[i1 - 1] == 1.0))
    {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 2U);
      st.site = &e_emlrtRSI;
      resampleLayers(&st, sldProfile, layerSld);
      i0 = layerSlds->size[0] - 1;
      if (!((i >= 0) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, i0, &lb_emlrtBCI, sp);
      }

      i0 = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
      layerSlds->data[i].f1->size[0] = layerSld->size[0];
      i1 = layerSlds->size[0] - 1;
      if (!((i >= 0) && (i <= i1))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, i1, &lb_emlrtBCI, sp);
      }

      layerSlds->data[i].f1->size[1] = 3;
      emxEnsureCapacity(sp, (emxArray__common *)layerSlds->data[i].f1, i0,
                        (int32_T)sizeof(real_T), &emlrtRTEI);
      b_allLayers = layerSlds->size[0] - 1;
      idx = layerSlds->size[0] - 1;
      if (!((i >= 0) && (i <= idx))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, idx, &lb_emlrtBCI, sp);
      }

      idx = layerSlds->size[0] - 1;
      if (!((i >= 0) && (i <= idx))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, idx, &lb_emlrtBCI, sp);
      }

      loop_ub = layerSld->size[0] * layerSld->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        if (!((i >= 0) && (i <= b_allLayers))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, b_allLayers, &lb_emlrtBCI, sp);
        }

        layerSlds->data[i].f1->data[i0] = layerSld->data[i0];
      }
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 3U);
      i0 = layerSlds->size[0] - 1;
      if (!((i >= 0) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, i0, &kb_emlrtBCI, sp);
      }

      i0 = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
      layerSlds->data[i].f1->size[0] = layerSld->size[0];
      i1 = layerSlds->size[0] - 1;
      if (!((i >= 0) && (i <= i1))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, i1, &kb_emlrtBCI, sp);
      }

      layerSlds->data[i].f1->size[1] = 3;
      emxEnsureCapacity(sp, (emxArray__common *)layerSlds->data[i].f1, i0,
                        (int32_T)sizeof(real_T), &emlrtRTEI);
      b_allLayers = layerSlds->size[0] - 1;
      idx = layerSlds->size[0] - 1;
      if (!((i >= 0) && (i <= idx))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, idx, &kb_emlrtBCI, sp);
      }

      idx = layerSlds->size[0] - 1;
      if (!((i >= 0) && (i <= idx))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, idx, &kb_emlrtBCI, sp);
      }

      loop_ub = layerSld->size[0] * layerSld->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        if (!((i >= 0) && (i <= b_allLayers))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, b_allLayers, &kb_emlrtBCI, sp);
        }

        layerSlds->data[i].f1->data[i0] = layerSld->data[i0];
      }
    }

    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 4U);
    st.site = &f_emlrtRSI;
    i0 = sfs->size[0];
    i1 = 1 + i;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &mb_emlrtBCI, &st);
    }

    scalefac = sfs->data[i1 - 1];
    i0 = qshifts->size[0];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &j_emlrtBCI, &st);
    }

    i0 = dataPresent->size[1];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &k_emlrtBCI, &st);
    }

    for (i0 = 0; i0 < 153; i0++) {
      i1 = allData->size[1] - 1;
      if (!((i >= 0) && (i <= i1))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, i1, &ac_emlrtBCI, &st);
      }

      data[i0] = allData->data[allData->size[0] * i].f1[i0];
    }

    i0 = dataLimits->size[1] - 1;
    if (!((i >= 0) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i0, &m_emlrtBCI, &st);
    }

    covrtLogFcn(&emlrtCoverageInstance, 11U, 0U);

    /* Shifts the data according to scale factor */
    /*  scalefac = problem.scalefactors; */
    /*  horshift = problem.qshifts; */
    /*  numberOfContrasts = problem.numberOfContrasts; */
    /*  dataPresent = problem.dataPresent; */
    /*  allData = problem.data; */
    /*  dataLimits = problem.dataLimits; */
    /* shifted_data = cell(1,numberOfContrasts); */
    reps = dataPresent->data[i];
    if (reps != (int32_T)muDoubleScalarFloor(reps)) {
      emlrtIntegerCheckR2012b(reps, &w_emlrtDCI, &st);
    }

    switch ((int32_T)reps) {
     case 1:
      covrtLogSwitch(&emlrtCoverageInstance, 11U, 0U, 0, 1);
      if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 0, sfs->data[i] == 0.0)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 0U);
        scalefac = 1.0E-30;
      }

      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 1U);
      reps = qshifts->data[i];
      for (i0 = 0; i0 < 51; i0++) {
        data[i0] = allData->data[allData->size[0] * i].f1[i0] + reps;
      }

      for (i0 = 0; i0 < 51; i0++) {
        data[51 + i0] /= scalefac;
        data[102 + i0] /= scalefac;
      }

      b_st.site = &wc_emlrtRSI;
      reps = dataLimits->data[dataLimits->size[0] * i].f1[0];
      for (i0 = 0; i0 < 51; i0++) {
        x[i0] = (data[i0] < reps);
      }

      c_st.site = &oc_emlrtRSI;
      idx = 0;
      b_allLayers = 1;
      exitg2 = false;
      while ((!exitg2) && (b_allLayers < 52)) {
        guard2 = false;
        if (x[b_allLayers - 1]) {
          idx++;
          ii_data[idx - 1] = (int8_T)b_allLayers;
          if (idx >= 51) {
            exitg2 = true;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          b_allLayers++;
        }
      }

      if (1 > idx) {
        loop_ub = 0;
      } else {
        loop_ub = idx;
      }

      iv0[0] = 1;
      iv0[1] = loop_ub;
      d_st.site = &qc_emlrtRSI;
      indexShapeCheck(&d_st, 51, iv0);
      for (i0 = 0; i0 < loop_ub; i0++) {
        lowIndex_data[i0] = ii_data[i0];
      }

      if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 1, covrtLogMcdc
                     (&emlrtCoverageInstance, 11U, 0U, 0, !covrtLogCond
                      (&emlrtCoverageInstance, 11U, 0U, 0, loop_ub == 0)))) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 2U);
        if (!(loop_ub >= 1)) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, loop_ub, &nb_emlrtBCI, &st);
        }

        lowIndex = lowIndex_data[loop_ub - 1];
      } else {
        covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 3U);
        lowIndex = 1;
      }

      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 4U);
      b_st.site = &xc_emlrtRSI;
      reps = dataLimits->data[dataLimits->size[0] * i].f1[1];
      for (i0 = 0; i0 < 51; i0++) {
        x[i0] = (data[i0] > reps);
      }

      c_st.site = &oc_emlrtRSI;
      idx = 0;
      b_allLayers = 1;
      exitg1 = false;
      while ((!exitg1) && (b_allLayers < 52)) {
        guard1 = false;
        if (x[b_allLayers - 1]) {
          idx++;
          ii_data[idx - 1] = (int8_T)b_allLayers;
          if (idx >= 51) {
            exitg1 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          b_allLayers++;
        }
      }

      if (1 > idx) {
        loop_ub = 0;
      } else {
        loop_ub = idx;
      }

      iv1[0] = 1;
      iv1[1] = loop_ub;
      d_st.site = &qc_emlrtRSI;
      indexShapeCheck(&d_st, 51, iv1);
      for (i0 = 0; i0 < loop_ub; i0++) {
        lowIndex_data[i0] = ii_data[i0];
      }

      if (covrtLogIf(&emlrtCoverageInstance, 11U, 0U, 2, covrtLogMcdc
                     (&emlrtCoverageInstance, 11U, 0U, 1, !covrtLogCond
                      (&emlrtCoverageInstance, 11U, 0U, 1, loop_ub == 0)))) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 5U);
        idx = lowIndex_data[0];
      } else {
        covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 6U);
        idx = 51;
      }

      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 7U);
      if (lowIndex > idx) {
        i0 = 0;
        idx = 0;
      } else {
        i0 = lowIndex - 1;
      }

      shifted_dat_size[0] = idx - i0;
      shifted_dat_size[1] = 3;
      for (i1 = 0; i1 < 3; i1++) {
        loop_ub = idx - i0;
        for (i2 = 0; i2 < loop_ub; i2++) {
          shifted_dat_data[i2 + shifted_dat_size[0] * i1] = data[(i0 + i2) + 51 *
            i1];
        }
      }
      break;

     default:
      covrtLogSwitch(&emlrtCoverageInstance, 11U, 0U, 0, 0);
      covrtLogBasicBlock(&emlrtCoverageInstance, 11U, 8U);
      shifted_dat_size[0] = 51;
      shifted_dat_size[1] = 3;
      for (i0 = 0; i0 < 153; i0++) {
        shifted_dat_data[i0] = allData->data[allData->size[0] * i].f1[i0];
      }
      break;
    }

    /*  function Ref = makeFresnelData(problem,contrast) */
    /*   */
    /*      this_data = problem.shifted_data{contrast}; */
    /*      xdata = this_data(:,1); */
    /*      nbair = problem.nbairs(contrast); */
    /*      nbsub = problem.nbsubs(contrast); */
    /*      slds = [0 0 0]; */
    /*      resol = problem.resolution; */
    /*      resolType = problem.resolType; */
    /*      %abeles(xdata,SLDs,nbair,nbsub,ssub,nrepeats,sinter,resol) */
    /*      %Ref = abeles_new_2(xdata,slds,nbair,nbsub,s_sub,repeats, */
    /*      Ref = abeles_new_2(xdata,slds,nbair,nbsub,0,1,resolType,resol); */
    i0 = shifted_data->size[0] - 1;
    if (!((i >= 0) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i0, &ob_emlrtBCI, sp);
    }

    i0 = shifted_data->data[i].f1->size[0] * shifted_data->data[i].f1->size[1];
    shifted_data->data[i].f1->size[0] = shifted_dat_size[0];
    i1 = shifted_data->size[0] - 1;
    if (!((i >= 0) && (i <= i1))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i1, &ob_emlrtBCI, sp);
    }

    shifted_data->data[i].f1->size[1] = 3;
    emxEnsureCapacity(sp, (emxArray__common *)shifted_data->data[i].f1, i0,
                      (int32_T)sizeof(real_T), &emlrtRTEI);
    b_allLayers = shifted_data->size[0] - 1;
    idx = shifted_data->size[0] - 1;
    if (!((i >= 0) && (i <= idx))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, idx, &ob_emlrtBCI, sp);
    }

    idx = shifted_data->size[0] - 1;
    if (!((i >= 0) && (i <= idx))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, idx, &ob_emlrtBCI, sp);
    }

    loop_ub = shifted_dat_size[0] * 3;
    for (i0 = 0; i0 < loop_ub; i0++) {
      if (!((i >= 0) && (i <= b_allLayers))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, b_allLayers, &ob_emlrtBCI, sp);
      }

      shifted_data->data[i].f1->data[i0] = shifted_dat_data[i0];
    }

    i0 = nbairs->size[1];
    i1 = 1 + i;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &pb_emlrtBCI, sp);
    }

    i0 = nbsubs->size[1];
    i2 = 1 + i;
    if (!((i2 >= 1) && (i2 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, i0, &qb_emlrtBCI, sp);
    }

    i0 = simLimits->size[1] - 1;
    if (!((i >= 0) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i0, &rb_emlrtBCI, sp);
    }

    i0 = repeatLayers->size[1] - 1;
    if (!((i >= 0) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i0, &sb_emlrtBCI, sp);
    }

    i0 = outSsubs->size[0];
    idx = 1 + i;
    if (!((idx >= 1) && (idx <= i0))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, i0, &tb_emlrtBCI, sp);
    }

    i0 = backgs->size[0];
    b_allLayers = 1 + i;
    if (!((b_allLayers >= 1) && (b_allLayers <= i0))) {
      emlrtDynamicBoundsCheckR2012b(b_allLayers, 1, i0, &ub_emlrtBCI, sp);
    }

    i0 = resols->size[0];
    lowIndex = 1 + i;
    if (!((lowIndex >= 1) && (lowIndex <= i0))) {
      emlrtDynamicBoundsCheckR2012b(lowIndex, 1, i0, &vb_emlrtBCI, sp);
    }

    i0 = Simulation->size[0] - 1;
    if (!((i >= 0) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i0, &wb_emlrtBCI, sp);
    }

    st.site = &g_emlrtRSI;
    callReflectivity(&st, nbairs->data[i1 - 1], nbsubs->data[i2 - 1],
                     simLimits->data[simLimits->size[0] * i].f1,
                     repeatLayers->data[repeatLayers->size[0] * i].f1,
                     shifted_dat_data, shifted_dat_size, layerSld,
                     outSsubs->data[idx - 1], backgs->data[b_allLayers - 1],
                     resols->data[lowIndex - 1], reflect_data, reflect_size,
                     Simulation->data[i].f1);
    i0 = reflectivity->size[0] - 1;
    if (!((i >= 0) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i0, &xb_emlrtBCI, sp);
    }

    i0 = reflectivity->data[i].f1->size[0] * reflectivity->data[i].f1->size[1];
    reflectivity->data[i].f1->size[0] = reflect_size[0];
    i1 = reflectivity->size[0] - 1;
    if (!((i >= 0) && (i <= i1))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i1, &xb_emlrtBCI, sp);
    }

    reflectivity->data[i].f1->size[1] = 2;
    emxEnsureCapacity(sp, (emxArray__common *)reflectivity->data[i].f1, i0,
                      (int32_T)sizeof(real_T), &emlrtRTEI);
    b_allLayers = reflectivity->size[0] - 1;
    idx = reflectivity->size[0] - 1;
    if (!((i >= 0) && (i <= idx))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, idx, &xb_emlrtBCI, sp);
    }

    idx = reflectivity->size[0] - 1;
    if (!((i >= 0) && (i <= idx))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, idx, &xb_emlrtBCI, sp);
    }

    loop_ub = reflect_size[0] * reflect_size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      if (!((i >= 0) && (i <= b_allLayers))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, b_allLayers, &xb_emlrtBCI, sp);
      }

      reflectivity->data[i].f1->data[i0] = reflect_data[i0];
    }

    i0 = chis->size[0];
    i1 = 1 + i;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &yb_emlrtBCI, sp);
    }

    st.site = &h_emlrtRSI;
    chis->data[i1 - 1] = chiSquared(&st, shifted_dat_data, shifted_dat_size,
      reflect_data, reflect_size, nParams);
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&outLayers);
  emxFree_real_T(&layerSld);
  emxFree_real_T(&sldProfile);
  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_custlay_single.c) */
