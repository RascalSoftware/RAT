/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_stanlay_single.c
 *
 * Code generation for function 'standardTF_stanlay_single'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_stanlay_single.h"
#include "standardTF_stanlay_single_emxutil.h"
#include "rdivide.h"
#include "eml_int_forloop_overflow_check.h"
#include "chiSquared.h"
#include "callReflectivity.h"
#include "indexShapeCheck.h"
#include "resampleLayers.h"
#include "makeSLDProfileXY.h"
#include "groupLayers_Mod.h"
#include "call_StandardLayers.h"
#include "standardTF_stanlay_single_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 69,    /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 70,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 73,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 75,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 79,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 86,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 89,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 94,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 12,  /* lineNo */
  "makeSLDProfiles",                   /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfiles.m"/* pathName */
};

static emlrtRSInfo xc_emlrtRSI = { 24, /* lineNo */
  "shiftdata",                         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pathName */
};

static emlrtRSInfo yc_emlrtRSI = { 31, /* lineNo */
  "shiftdata",                         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 15,  /* lineNo */
  14,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 75,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 79,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 86,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 24,/* lineNo */
  9,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  29,                                  /* colNo */
  "data",                              /* aName */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  19,                                  /* lineNo */
  9,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  18,                                  /* lineNo */
  9,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  17,                                  /* lineNo */
  9,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 12,    /* lineNo */
  8,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  12,                                  /* colNo */
  "repeats",                           /* aName */
  "makeSLDProfiles",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfiles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  4,                                   /* colNo */
  "repeats",                           /* aName */
  "makeSLDProfiles",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfiles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  54,                                  /* lineNo */
  13,                                  /* colNo */
  "res",                               /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 54,  /* lineNo */
  13,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  11,                                  /* colNo */
  "nbs",                               /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 51,  /* lineNo */
  11,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  11,                                  /* colNo */
  "nba",                               /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 48,  /* lineNo */
  11,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  10,                                  /* colNo */
  "sf",                                /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 45,  /* lineNo */
  10,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  14,                                  /* colNo */
  "shifts",                            /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 42,  /* lineNo */
  14,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  13,                                  /* colNo */
  "backs",                             /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 39,  /* lineNo */
  13,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  73,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  76,                                  /* colNo */
  "repeats",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  47,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  36,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  64,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  44,                                  /* colNo */
  "nbsubs",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  34,                                  /* colNo */
  "nbairs",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  122,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  113,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  104,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  93,                                  /* colNo */
  "cScales",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  82,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  72,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo bc_emlrtRTEI = { 68,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m"/* pName */
};

static emlrtDCInfo h_emlrtDCI = { 64,  /* lineNo */
  19,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 63,  /* lineNo */
  21,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 62,  /* lineNo */
  21,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 61,  /* lineNo */
  20,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 60,  /* lineNo */
  18,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 59,  /* lineNo */
  18,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = { 58,  /* lineNo */
  15,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 57,  /* lineNo */
  18,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = { 56,  /* lineNo */
  19,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = { 55,  /* lineNo */
  16,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = { 54,  /* lineNo */
  14,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo s_emlrtDCI = { 53,  /* lineNo */
  14,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo t_emlrtDCI = { 52,  /* lineNo */
  13,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo u_emlrtDCI = { 51,  /* lineNo */
  17,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo v_emlrtDCI = { 50,  /* lineNo */
  16,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo w_emlrtDCI = { 50,  /* lineNo */
  16,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  6,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  16,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  27,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  50,                                  /* colNo */
  "resols",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  61,                                  /* colNo */
  "contrastLayers",                    /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  16,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  58,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  80,                                  /* colNo */
  "nbairs",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  90,                                  /* colNo */
  "nbsubs",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  17,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  78,                                  /* lineNo */
  8,                                   /* colNo */
  "resam",                             /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  29,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  24,                                  /* colNo */
  "lowIndex",                          /* aName */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  40,                                  /* colNo */
  "nbairs",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  50,                                  /* colNo */
  "nbsubs",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  60,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  73,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  110,                                 /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  122,                                 /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  132,                                 /* colNo */
  "resols",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  91,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  94,                                  /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  62,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

/* Function Declarations */
static void cast(const emlrtStack *sp, const emxArray_cell_wrap_3 *x,
                 emxArray_cell_wrap_0 *y);

/* Function Definitions */
static void cast(const emlrtStack *sp, const emxArray_cell_wrap_3 *x,
                 emxArray_cell_wrap_0 *y)
{
  int32_T j;
  int32_T b_j;
  j = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity_cell_wrap_0(sp, y, j, (emlrtRTEInfo *)NULL);
  b_j = 0;
  while (b_j < x->size[1]) {
    j = y->data[b_j].f1->size[0] * y->data[b_j].f1->size[1];
    y->data[b_j].f1->size[0] = 1;
    y->data[b_j].f1->size[1] = x->data[b_j].f1.size[1];
    emxEnsureCapacity(sp, (emxArray__common *)y->data[b_j].f1, j, (int32_T)
                      sizeof(real_T), (emlrtRTEInfo *)NULL);
    j = 0;
    while (j < x->data[b_j].f1.size[1]) {
      y->data[b_j].f1->data[j] = x->data[b_j].f1.data[j];
      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    b_j++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

void standardTF_stanlay_single(const emlrtStack *sp, const emxArray_real_T
  *resam, real_T numberOfContrasts, const emxArray_char_T *geometry, const
  emxArray_real_T *nbairs, const emxArray_real_T *nbsubs, const
  emxArray_cell_wrap_0 *repeats, const emxArray_real_T *cBacks, const
  emxArray_real_T *cShifts, const emxArray_real_T *cScales, const
  emxArray_real_T *cNbas, const emxArray_real_T *cNbss, const emxArray_real_T
  *cRes, const emxArray_real_T *backs, const emxArray_real_T *shifts, const
  emxArray_real_T *sf, const emxArray_real_T *nba, const emxArray_real_T *nbs,
  const emxArray_real_T *res, const emxArray_real_T *dataPresent, const
  emxArray_cell_wrap_1 *allData, const emxArray_cell_wrap_2 *dataLimits, const
  emxArray_cell_wrap_2 *simLimits, const emxArray_cell_wrap_2 *repeatLayers,
  real_T nParams, const emxArray_real_T *params, const emxArray_cell_wrap_0
  *contrastLayers, real_T numberOfLayers, const emxArray_cell_wrap_3
  *layersDetails, real_T whichType, emxArray_real_T *outSsubs, emxArray_real_T
  *backgs, emxArray_real_T *qshifts, emxArray_real_T *sfs, emxArray_real_T *nbas,
  emxArray_real_T *nbss, emxArray_real_T *resols, emxArray_real_T *chis,
  emxArray_cell_wrap_4 *reflectivity, emxArray_cell_wrap_4 *Simulation,
  emxArray_cell_wrap_1 *shifted_data, emxArray_cell_wrap_1 *layerSlds,
  emxArray_cell_wrap_4 *sldProfiles, emxArray_cell_wrap_5 *allLayers,
  emxArray_real_T *allRoughs)
{
  int32_T i0;
  int32_T i;
  emxArray_real_T *sldProfile;
  emxArray_real_T *layerSld;
  emxArray_real_T *shifted_dat;
  emxArray_real_T *outLayers;
  emxArray_cell_wrap_0 *r0;
  emxArray_real_T *data;
  emxArray_real_T *lowIndex;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  emxArray_real_T *b_data;
  emxArray_real_T *c_data;
  emxArray_real_T *b_allData;
  int32_T i1;
  real_T reps;
  int32_T nx;
  int32_T hiIndex;
  int32_T idx;
  int32_T b_lowIndex;
  real_T scalefac;
  int32_T b_ii[1];
  int32_T c_allData[1];
  int32_T c_ii[1];
  int32_T d_ii[1];
  boolean_T overflow;
  boolean_T exitg2;
  boolean_T guard2 = false;
  int32_T iv0[2];
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv1[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  (void)whichType;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* coder.extrinsic('callModules');             */
  /* Pre-Allocation... */
  if (!(numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(numberOfContrasts, &w_emlrtDCI, sp);
  }

  if (numberOfContrasts != (int32_T)muDoubleScalarFloor(numberOfContrasts)) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &v_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &u_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &t_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &s_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &r_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &q_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &p_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &o_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &n_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &m_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &l_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &k_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &j_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &i_emlrtDCI, sp);
    emlrtIntegerCheckR2012b(numberOfContrasts, &h_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &bc_emlrtRTEI, sp);
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
  emxEnsureCapacity_cell_wrap_4(sp, sldProfiles, i0, &emlrtRTEI);
  i0 = layerSlds->size[0] * layerSlds->size[1];
  layerSlds->size[0] = (int32_T)numberOfContrasts;
  layerSlds->size[1] = 1;
  emxEnsureCapacity_cell_wrap_1(sp, layerSlds, i0, &emlrtRTEI);
  i0 = shifted_data->size[0] * shifted_data->size[1];
  shifted_data->size[0] = (int32_T)numberOfContrasts;
  shifted_data->size[1] = 1;
  emxEnsureCapacity_cell_wrap_1(sp, shifted_data, i0, &emlrtRTEI);
  i0 = reflectivity->size[0] * reflectivity->size[1];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  reflectivity->size[1] = 1;
  emxEnsureCapacity_cell_wrap_4(sp, reflectivity, i0, &emlrtRTEI);
  i0 = Simulation->size[0] * Simulation->size[1];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  Simulation->size[1] = 1;
  emxEnsureCapacity_cell_wrap_4(sp, Simulation, i0, &emlrtRTEI);
  i0 = chis->size[0];
  chis->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity(sp, (emxArray__common *)chis, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  i = 0;
  emxInit_real_T(sp, &sldProfile, 2, &c_emlrtRTEI, true);
  emxInit_real_T(sp, &layerSld, 2, &d_emlrtRTEI, true);
  emxInit_real_T(sp, &shifted_dat, 2, &e_emlrtRTEI, true);
  emxInit_real_T(sp, &outLayers, 2, &emlrtRTEI, true);
  emxInit_cell_wrap_0(sp, &r0, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &data, 2, &emlrtRTEI, true);
  emxInit_real_T1(sp, &lowIndex, 1, &f_emlrtRTEI, true);
  emxInit_boolean_T(sp, &x, 1, &emlrtRTEI, true);
  emxInit_int32_T(sp, &ii, 1, &g_emlrtRTEI, true);
  emxInit_real_T1(sp, &b_data, 1, &emlrtRTEI, true);
  emxInit_real_T1(sp, &c_data, 1, &emlrtRTEI, true);
  emxInit_real_T1(sp, &b_allData, 1, &emlrtRTEI, true);
  while (i <= (int32_T)numberOfContrasts - 1) {
    st.site = &emlrtRSI;
    i0 = cBacks->size[1];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &v_emlrtBCI, &st);
    }

    i0 = cShifts->size[1];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &u_emlrtBCI, &st);
    }

    i0 = cScales->size[1];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &t_emlrtBCI, &st);
    }

    i0 = cNbas->size[1];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &s_emlrtBCI, &st);
    }

    i0 = cNbss->size[1];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &r_emlrtBCI, &st);
    }

    i0 = cRes->size[1];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &q_emlrtBCI, &st);
    }

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
    i0 = backs->size[1];
    reps = cBacks->data[i];
    if (reps != (int32_T)muDoubleScalarFloor(reps)) {
      emlrtIntegerCheckR2012b(reps, &g_emlrtDCI, &st);
    }

    i1 = (int32_T)reps;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &i_emlrtBCI, &st);
    }

    /* thisShift = cShifts(i); */
    i0 = shifts->size[1];
    reps = cShifts->data[i];
    if (reps != (int32_T)muDoubleScalarFloor(reps)) {
      emlrtIntegerCheckR2012b(reps, &f_emlrtDCI, &st);
    }

    i1 = (int32_T)reps;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &h_emlrtBCI, &st);
    }

    /* thisScale = cScales(i); */
    i0 = sf->size[1];
    reps = cScales->data[i];
    if (reps != (int32_T)muDoubleScalarFloor(reps)) {
      emlrtIntegerCheckR2012b(reps, &e_emlrtDCI, &st);
    }

    i1 = (int32_T)reps;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &g_emlrtBCI, &st);
    }

    /* thisNbair = cNbas(i); */
    i0 = nba->size[1];
    reps = cNbas->data[i];
    if (reps != (int32_T)muDoubleScalarFloor(reps)) {
      emlrtIntegerCheckR2012b(reps, &d_emlrtDCI, &st);
    }

    i1 = (int32_T)reps;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &f_emlrtBCI, &st);
    }

    /* thisNbsub = cNbss(i); */
    i0 = nbs->size[1];
    reps = cNbss->data[i];
    if (reps != (int32_T)muDoubleScalarFloor(reps)) {
      emlrtIntegerCheckR2012b(reps, &c_emlrtDCI, &st);
    }

    i1 = (int32_T)reps;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &e_emlrtBCI, &st);
    }

    /* thisResol = cRes(i); */
    i0 = res->size[1];
    reps = cRes->data[i];
    if (reps != (int32_T)muDoubleScalarFloor(reps)) {
      emlrtIntegerCheckR2012b(reps, &b_emlrtDCI, &st);
    }

    i1 = (int32_T)reps;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &d_emlrtBCI, &st);
    }

    /* end */
    i0 = backgs->size[0];
    i1 = (int32_T)(1U + i);
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &w_emlrtBCI, sp);
    }

    backgs->data[i1 - 1] = backs->data[(int32_T)cBacks->data[i] - 1];
    i0 = qshifts->size[0];
    i1 = (int32_T)(1U + i);
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &x_emlrtBCI, sp);
    }

    qshifts->data[i1 - 1] = shifts->data[(int32_T)cShifts->data[i] - 1];
    i0 = sfs->size[0];
    i1 = (int32_T)(1U + i);
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &y_emlrtBCI, sp);
    }

    sfs->data[i1 - 1] = sf->data[(int32_T)cScales->data[i] - 1];
    i0 = nbas->size[0];
    i1 = (int32_T)(1U + i);
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &ab_emlrtBCI, sp);
    }

    nbas->data[i1 - 1] = nba->data[(int32_T)cNbas->data[i] - 1];
    i0 = nbss->size[0];
    i1 = (int32_T)(1U + i);
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &bb_emlrtBCI, sp);
    }

    nbss->data[i1 - 1] = nbs->data[(int32_T)cNbss->data[i] - 1];
    i0 = resols->size[0];
    i1 = (int32_T)(1U + i);
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &cb_emlrtBCI, sp);
    }

    resols->data[i1 - 1] = res->data[(int32_T)cRes->data[i] - 1];
    cast(sp, layersDetails, r0);
    i0 = contrastLayers->size[1] - 1;
    if (!((i >= 0) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i0, &db_emlrtBCI, sp);
    }

    i0 = allRoughs->size[0];
    i1 = (int32_T)(1U + i);
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &eb_emlrtBCI, sp);
    }

    st.site = &b_emlrtRSI;
    call_StandardLayers(&st, params, contrastLayers->data[contrastLayers->size[0]
                        * i].f1, numberOfLayers, r0, outLayers, &allRoughs->
                        data[i1 - 1]);
    i0 = allLayers->size[0] - 1;
    if (!((i >= 0) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i0, &fb_emlrtBCI, sp);
    }

    i0 = allLayers->data[i].f1->size[0] * allLayers->data[i].f1->size[1];
    allLayers->data[i].f1->size[0] = outLayers->size[0];
    i1 = allLayers->size[0] - 1;
    if (!((i >= 0) && (i <= i1))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i1, &fb_emlrtBCI, sp);
    }

    allLayers->data[i].f1->size[1] = outLayers->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)allLayers->data[i].f1, i0,
                      (int32_T)sizeof(real_T), &emlrtRTEI);
    nx = allLayers->size[0] - 1;
    hiIndex = allLayers->size[0] - 1;
    if (!((i >= 0) && (i <= hiIndex))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, hiIndex, &fb_emlrtBCI, sp);
    }

    hiIndex = allLayers->size[0] - 1;
    if (!((i >= 0) && (i <= hiIndex))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, hiIndex, &fb_emlrtBCI, sp);
    }

    idx = outLayers->size[0] * outLayers->size[1];
    for (i0 = 0; i0 < idx; i0++) {
      if (!((i >= 0) && (i <= nx))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, nx, &fb_emlrtBCI, sp);
      }

      allLayers->data[i].f1->data[i0] = outLayers->data[i0];
    }

    i0 = allRoughs->size[0];
    i1 = 1 + i;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &gb_emlrtBCI, sp);
    }

    i0 = nbairs->size[1];
    b_lowIndex = 1 + i;
    if (!((b_lowIndex >= 1) && (b_lowIndex <= i0))) {
      emlrtDynamicBoundsCheckR2012b(b_lowIndex, 1, i0, &hb_emlrtBCI, sp);
    }

    i0 = nbsubs->size[1];
    hiIndex = 1 + i;
    if (!((hiIndex >= 1) && (hiIndex <= i0))) {
      emlrtDynamicBoundsCheckR2012b(hiIndex, 1, i0, &ib_emlrtBCI, sp);
    }

    i0 = outSsubs->size[0];
    nx = 1 + i;
    if (!((nx >= 1) && (nx <= i0))) {
      emlrtDynamicBoundsCheckR2012b(nx, 1, i0, &jb_emlrtBCI, sp);
    }

    st.site = &c_emlrtRSI;
    groupLayers_Mod(&st, outLayers, allRoughs->data[i1 - 1], geometry,
                    nbairs->data[b_lowIndex - 1], nbsubs->data[hiIndex - 1],
                    layerSld, &outSsubs->data[nx - 1]);
    st.site = &d_emlrtRSI;
    i0 = nbairs->size[1];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &p_emlrtBCI, &st);
    }

    i0 = nbsubs->size[1];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &o_emlrtBCI, &st);
    }

    i0 = outSsubs->size[0];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &n_emlrtBCI, &st);
    }

    i0 = repeats->size[1] - 1;
    if (!((i >= 0) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i0, &k_emlrtBCI, &st);
    }

    i0 = repeats->data[repeats->size[0] * i].f1->size[1];
    if (!(1 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i0, &c_emlrtBCI, &st);
    }

    if (repeats->data[repeats->size[0] * i].f1->data[0] == 0.0) {
      reps = 1.0;
    } else {
      i0 = repeats->data[repeats->size[0] * i].f1->size[1];
      if (!(2 <= i0)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i0, &b_emlrtBCI, &st);
      }

      reps = repeats->data[repeats->size[0] * i].f1->data[1];
    }

    b_st.site = &p_emlrtRSI;
    makeSLDProfileXY(&b_st, nbairs->data[i], nbsubs->data[i], outSsubs->data[i],
                     layerSld, layerSld->size[0], reps, sldProfile);
    i0 = sldProfiles->size[0] - 1;
    if (!((i >= 0) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i0, &kb_emlrtBCI, sp);
    }

    i0 = sldProfiles->data[i].f1->size[0] * sldProfiles->data[i].f1->size[1];
    sldProfiles->data[i].f1->size[0] = sldProfile->size[0];
    i1 = sldProfiles->size[0] - 1;
    if (!((i >= 0) && (i <= i1))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i1, &kb_emlrtBCI, sp);
    }

    sldProfiles->data[i].f1->size[1] = 2;
    emxEnsureCapacity(sp, (emxArray__common *)sldProfiles->data[i].f1, i0,
                      (int32_T)sizeof(real_T), &emlrtRTEI);
    nx = sldProfiles->size[0] - 1;
    hiIndex = sldProfiles->size[0] - 1;
    if (!((i >= 0) && (i <= hiIndex))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, hiIndex, &kb_emlrtBCI, sp);
    }

    hiIndex = sldProfiles->size[0] - 1;
    if (!((i >= 0) && (i <= hiIndex))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, hiIndex, &kb_emlrtBCI, sp);
    }

    idx = sldProfile->size[0] * sldProfile->size[1];
    for (i0 = 0; i0 < idx; i0++) {
      if (!((i >= 0) && (i <= nx))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, nx, &kb_emlrtBCI, sp);
      }

      sldProfiles->data[i].f1->data[i0] = sldProfile->data[i0];
    }

    i0 = resam->size[0];
    i1 = 1 + i;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &lb_emlrtBCI, sp);
    }

    if (resam->data[i1 - 1] == 1.0) {
      st.site = &e_emlrtRSI;
      resampleLayers(&st, sldProfile, layerSld);
      i0 = layerSlds->size[0] - 1;
      if (!((i >= 0) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, i0, &nb_emlrtBCI, sp);
      }

      i0 = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
      layerSlds->data[i].f1->size[0] = layerSld->size[0];
      i1 = layerSlds->size[0] - 1;
      if (!((i >= 0) && (i <= i1))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, i1, &nb_emlrtBCI, sp);
      }

      layerSlds->data[i].f1->size[1] = 3;
      emxEnsureCapacity(sp, (emxArray__common *)layerSlds->data[i].f1, i0,
                        (int32_T)sizeof(real_T), &emlrtRTEI);
      nx = layerSlds->size[0] - 1;
      hiIndex = layerSlds->size[0] - 1;
      if (!((i >= 0) && (i <= hiIndex))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, hiIndex, &nb_emlrtBCI, sp);
      }

      hiIndex = layerSlds->size[0] - 1;
      if (!((i >= 0) && (i <= hiIndex))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, hiIndex, &nb_emlrtBCI, sp);
      }

      idx = layerSld->size[0] * layerSld->size[1];
      for (i0 = 0; i0 < idx; i0++) {
        if (!((i >= 0) && (i <= nx))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, nx, &nb_emlrtBCI, sp);
        }

        layerSlds->data[i].f1->data[i0] = layerSld->data[i0];
      }
    } else {
      i0 = layerSlds->size[0] - 1;
      if (!((i >= 0) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, i0, &mb_emlrtBCI, sp);
      }

      i0 = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
      layerSlds->data[i].f1->size[0] = layerSld->size[0];
      i1 = layerSlds->size[0] - 1;
      if (!((i >= 0) && (i <= i1))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, i1, &mb_emlrtBCI, sp);
      }

      layerSlds->data[i].f1->size[1] = 3;
      emxEnsureCapacity(sp, (emxArray__common *)layerSlds->data[i].f1, i0,
                        (int32_T)sizeof(real_T), &emlrtRTEI);
      nx = layerSlds->size[0] - 1;
      hiIndex = layerSlds->size[0] - 1;
      if (!((i >= 0) && (i <= hiIndex))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, hiIndex, &mb_emlrtBCI, sp);
      }

      hiIndex = layerSlds->size[0] - 1;
      if (!((i >= 0) && (i <= hiIndex))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, hiIndex, &mb_emlrtBCI, sp);
      }

      idx = layerSld->size[0] * layerSld->size[1];
      for (i0 = 0; i0 < idx; i0++) {
        if (!((i >= 0) && (i <= nx))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, nx, &mb_emlrtBCI, sp);
        }

        layerSlds->data[i].f1->data[i0] = layerSld->data[i0];
      }
    }

    st.site = &f_emlrtRSI;
    i0 = sfs->size[0];
    i1 = 1 + i;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &ob_emlrtBCI, &st);
    }

    scalefac = sfs->data[i1 - 1];
    i0 = qshifts->size[0];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &m_emlrtBCI, &st);
    }

    i0 = dataPresent->size[1];
    i1 = i + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &l_emlrtBCI, &st);
    }

    i0 = data->size[0] * data->size[1];
    i1 = allData->size[1] - 1;
    if (!((i >= 0) && (i <= i1))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i1, &cc_emlrtBCI, &st);
    }

    data->size[0] = allData->data[allData->size[0] * i].f1->size[0];
    data->size[1] = 3;
    emxEnsureCapacity(&st, (emxArray__common *)data, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    i0 = allData->size[1] - 1;
    if (!((i >= 0) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i0, &cc_emlrtBCI, &st);
    }

    i0 = allData->size[1] - 1;
    if (!((i >= 0) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i0, &cc_emlrtBCI, &st);
    }

    idx = allData->data[allData->size[0] * i].f1->size[0] * allData->
      data[allData->size[0] * i].f1->size[1];
    for (i0 = 0; i0 < idx; i0++) {
      i1 = allData->size[1] - 1;
      if (!((i >= 0) && (i <= i1))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, i1, &cc_emlrtBCI, &st);
      }

      data->data[i0] = allData->data[allData->size[0] * i].f1->data[i0];
    }

    i0 = dataLimits->size[1] - 1;
    if (!((i >= 0) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i0, &j_emlrtBCI, &st);
    }

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
      emlrtIntegerCheckR2012b(reps, &emlrtDCI, &st);
    }

    switch ((int32_T)reps) {
     case 1:
      if (sfs->data[i] == 0.0) {
        scalefac = 1.0E-30;
      }

      idx = allData->data[allData->size[0] * i].f1->size[0];
      i0 = ii->size[0];
      ii->size[0] = idx;
      emxEnsureCapacity(&st, (emxArray__common *)ii, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      for (i0 = 0; i0 < idx; i0++) {
        ii->data[i0] = i0;
      }

      b_ii[0] = ii->size[0];
      idx = allData->data[allData->size[0] * i].f1->size[0];
      i0 = b_allData->size[0];
      b_allData->size[0] = idx;
      emxEnsureCapacity(&st, (emxArray__common *)b_allData, i0, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      for (i0 = 0; i0 < idx; i0++) {
        b_allData->data[i0] = allData->data[allData->size[0] * i].f1->data[i0];
      }

      c_allData[0] = b_allData->size[0];
      emlrtSubAssignSizeCheckR2012b(b_ii, 1, c_allData, 1, &c_emlrtECI, &st);
      idx = allData->data[allData->size[0] * i].f1->size[0] - 1;
      reps = qshifts->data[i];
      for (i0 = 0; i0 <= idx; i0++) {
        data->data[ii->data[i0]] = allData->data[allData->size[0] * i].f1->
          data[i0] + reps;
      }

      idx = data->size[0];
      i0 = ii->size[0];
      ii->size[0] = idx;
      emxEnsureCapacity(&st, (emxArray__common *)ii, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      for (i0 = 0; i0 < idx; i0++) {
        ii->data[i0] = i0;
      }

      idx = data->size[0];
      i0 = c_data->size[0];
      c_data->size[0] = idx;
      emxEnsureCapacity(&st, (emxArray__common *)c_data, i0, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      for (i0 = 0; i0 < idx; i0++) {
        c_data->data[i0] = data->data[i0 + data->size[0]];
      }

      rdivide(&st, c_data, scalefac, lowIndex);
      c_ii[0] = ii->size[0];
      emlrtSubAssignSizeCheckR2012b(c_ii, 1, *(int32_T (*)[1])lowIndex->size, 1,
        &b_emlrtECI, &st);
      idx = lowIndex->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        data->data[ii->data[i0] + data->size[0]] = lowIndex->data[i0];
      }

      idx = data->size[0];
      i0 = ii->size[0];
      ii->size[0] = idx;
      emxEnsureCapacity(&st, (emxArray__common *)ii, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      for (i0 = 0; i0 < idx; i0++) {
        ii->data[i0] = i0;
      }

      idx = data->size[0];
      i0 = b_data->size[0];
      b_data->size[0] = idx;
      emxEnsureCapacity(&st, (emxArray__common *)b_data, i0, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      for (i0 = 0; i0 < idx; i0++) {
        b_data->data[i0] = data->data[i0 + (data->size[0] << 1)];
      }

      rdivide(&st, b_data, scalefac, lowIndex);
      d_ii[0] = ii->size[0];
      emlrtSubAssignSizeCheckR2012b(d_ii, 1, *(int32_T (*)[1])lowIndex->size, 1,
        &emlrtECI, &st);
      idx = lowIndex->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        data->data[ii->data[i0] + (data->size[0] << 1)] = lowIndex->data[i0];
      }

      b_st.site = &xc_emlrtRSI;
      idx = data->size[0];
      reps = dataLimits->data[dataLimits->size[0] * i].f1[0];
      i0 = x->size[0];
      x->size[0] = idx;
      emxEnsureCapacity(&b_st, (emxArray__common *)x, i0, (int32_T)sizeof
                        (boolean_T), &emlrtRTEI);
      for (i0 = 0; i0 < idx; i0++) {
        x->data[i0] = (data->data[i0] < reps);
      }

      c_st.site = &pc_emlrtRSI;
      nx = x->size[0];
      idx = 0;
      i0 = ii->size[0];
      ii->size[0] = x->size[0];
      emxEnsureCapacity(&c_st, (emxArray__common *)ii, i0, (int32_T)sizeof
                        (int32_T), &emlrtRTEI);
      d_st.site = &qc_emlrtRSI;
      overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
      if (overflow) {
        e_st.site = &eb_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }

      hiIndex = 1;
      exitg2 = false;
      while ((!exitg2) && (hiIndex <= nx)) {
        guard2 = false;
        if (x->data[hiIndex - 1]) {
          idx++;
          ii->data[idx - 1] = hiIndex;
          if (idx >= nx) {
            exitg2 = true;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          hiIndex++;
        }
      }

      if (!(idx <= x->size[0])) {
        emlrtErrorWithMessageIdR2012b(&c_st, &ac_emlrtRTEI,
          "Coder:builtins:AssertionFailed", 0);
      }

      if (x->size[0] == 1) {
        if (idx == 0) {
          i0 = ii->size[0];
          ii->size[0] = 0;
          emxEnsureCapacity(&c_st, (emxArray__common *)ii, i0, (int32_T)sizeof
                            (int32_T), &emlrtRTEI);
        }
      } else {
        if (1 > idx) {
          i0 = 0;
        } else {
          i0 = idx;
        }

        iv0[0] = 1;
        iv0[1] = i0;
        d_st.site = &rc_emlrtRSI;
        indexShapeCheck(&d_st, ii->size[0], iv0);
        i1 = ii->size[0];
        ii->size[0] = i0;
        emxEnsureCapacity(&c_st, (emxArray__common *)ii, i1, (int32_T)sizeof
                          (int32_T), &b_emlrtRTEI);
      }

      i0 = lowIndex->size[0];
      lowIndex->size[0] = ii->size[0];
      emxEnsureCapacity(&b_st, (emxArray__common *)lowIndex, i0, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      idx = ii->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        lowIndex->data[i0] = ii->data[i0];
      }

      if (!(lowIndex->size[0] == 0)) {
        i0 = lowIndex->size[0];
        i1 = lowIndex->size[0];
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &pb_emlrtBCI, &st);
        }

        b_lowIndex = (int32_T)lowIndex->data[i1 - 1];
      } else {
        b_lowIndex = 1;
      }

      b_st.site = &yc_emlrtRSI;
      idx = data->size[0];
      reps = dataLimits->data[dataLimits->size[0] * i].f1[1];
      i0 = x->size[0];
      x->size[0] = idx;
      emxEnsureCapacity(&b_st, (emxArray__common *)x, i0, (int32_T)sizeof
                        (boolean_T), &emlrtRTEI);
      for (i0 = 0; i0 < idx; i0++) {
        x->data[i0] = (data->data[i0] > reps);
      }

      c_st.site = &pc_emlrtRSI;
      nx = x->size[0];
      idx = 0;
      i0 = ii->size[0];
      ii->size[0] = x->size[0];
      emxEnsureCapacity(&c_st, (emxArray__common *)ii, i0, (int32_T)sizeof
                        (int32_T), &emlrtRTEI);
      d_st.site = &qc_emlrtRSI;
      overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
      if (overflow) {
        e_st.site = &eb_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }

      hiIndex = 1;
      exitg1 = false;
      while ((!exitg1) && (hiIndex <= nx)) {
        guard1 = false;
        if (x->data[hiIndex - 1]) {
          idx++;
          ii->data[idx - 1] = hiIndex;
          if (idx >= nx) {
            exitg1 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          hiIndex++;
        }
      }

      if (!(idx <= x->size[0])) {
        emlrtErrorWithMessageIdR2012b(&c_st, &ac_emlrtRTEI,
          "Coder:builtins:AssertionFailed", 0);
      }

      if (x->size[0] == 1) {
        if (idx == 0) {
          i0 = ii->size[0];
          ii->size[0] = 0;
          emxEnsureCapacity(&c_st, (emxArray__common *)ii, i0, (int32_T)sizeof
                            (int32_T), &emlrtRTEI);
        }
      } else {
        if (1 > idx) {
          i0 = 0;
        } else {
          i0 = idx;
        }

        iv1[0] = 1;
        iv1[1] = i0;
        d_st.site = &rc_emlrtRSI;
        indexShapeCheck(&d_st, ii->size[0], iv1);
        i1 = ii->size[0];
        ii->size[0] = i0;
        emxEnsureCapacity(&c_st, (emxArray__common *)ii, i1, (int32_T)sizeof
                          (int32_T), &b_emlrtRTEI);
      }

      i0 = lowIndex->size[0];
      lowIndex->size[0] = ii->size[0];
      emxEnsureCapacity(&b_st, (emxArray__common *)lowIndex, i0, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      idx = ii->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        lowIndex->data[i0] = ii->data[i0];
      }

      if (!(lowIndex->size[0] == 0)) {
        hiIndex = (int32_T)lowIndex->data[0];
      } else {
        hiIndex = data->size[0];
      }

      if (b_lowIndex > hiIndex) {
        i0 = 0;
        hiIndex = 0;
      } else {
        i0 = data->size[0];
        if (!((b_lowIndex >= 1) && (b_lowIndex <= i0))) {
          emlrtDynamicBoundsCheckR2012b(b_lowIndex, 1, i0, &emlrtBCI, &st);
        }

        i0 = b_lowIndex - 1;
        i1 = data->size[0];
        if (!((hiIndex >= 1) && (hiIndex <= i1))) {
          emlrtDynamicBoundsCheckR2012b(hiIndex, 1, i1, &emlrtBCI, &st);
        }
      }

      i1 = shifted_dat->size[0] * shifted_dat->size[1];
      shifted_dat->size[0] = hiIndex - i0;
      shifted_dat->size[1] = 3;
      emxEnsureCapacity(&st, (emxArray__common *)shifted_dat, i1, (int32_T)
                        sizeof(real_T), &emlrtRTEI);
      for (i1 = 0; i1 < 3; i1++) {
        idx = hiIndex - i0;
        for (b_lowIndex = 0; b_lowIndex < idx; b_lowIndex++) {
          shifted_dat->data[b_lowIndex + shifted_dat->size[0] * i1] = data->
            data[(i0 + b_lowIndex) + data->size[0] * i1];
        }
      }
      break;

     default:
      i0 = shifted_dat->size[0] * shifted_dat->size[1];
      shifted_dat->size[0] = allData->data[allData->size[0] * i].f1->size[0];
      shifted_dat->size[1] = 3;
      emxEnsureCapacity(&st, (emxArray__common *)shifted_dat, i0, (int32_T)
                        sizeof(real_T), &emlrtRTEI);
      idx = allData->data[allData->size[0] * i].f1->size[0] * allData->
        data[allData->size[0] * i].f1->size[1];
      for (i0 = 0; i0 < idx; i0++) {
        shifted_dat->data[i0] = allData->data[allData->size[0] * i].f1->data[i0];
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
      emlrtDynamicBoundsCheckR2012b(i, 0, i0, &qb_emlrtBCI, sp);
    }

    i0 = shifted_data->data[i].f1->size[0] * shifted_data->data[i].f1->size[1];
    shifted_data->data[i].f1->size[0] = shifted_dat->size[0];
    i1 = shifted_data->size[0] - 1;
    if (!((i >= 0) && (i <= i1))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i1, &qb_emlrtBCI, sp);
    }

    shifted_data->data[i].f1->size[1] = 3;
    emxEnsureCapacity(sp, (emxArray__common *)shifted_data->data[i].f1, i0,
                      (int32_T)sizeof(real_T), &emlrtRTEI);
    nx = shifted_data->size[0] - 1;
    hiIndex = shifted_data->size[0] - 1;
    if (!((i >= 0) && (i <= hiIndex))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, hiIndex, &qb_emlrtBCI, sp);
    }

    hiIndex = shifted_data->size[0] - 1;
    if (!((i >= 0) && (i <= hiIndex))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, hiIndex, &qb_emlrtBCI, sp);
    }

    idx = shifted_dat->size[0] * shifted_dat->size[1];
    for (i0 = 0; i0 < idx; i0++) {
      if (!((i >= 0) && (i <= nx))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, nx, &qb_emlrtBCI, sp);
      }

      shifted_data->data[i].f1->data[i0] = shifted_dat->data[i0];
    }

    i0 = nbairs->size[1];
    i1 = 1 + i;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &rb_emlrtBCI, sp);
    }

    i0 = nbsubs->size[1];
    b_lowIndex = 1 + i;
    if (!((b_lowIndex >= 1) && (b_lowIndex <= i0))) {
      emlrtDynamicBoundsCheckR2012b(b_lowIndex, 1, i0, &sb_emlrtBCI, sp);
    }

    i0 = simLimits->size[1] - 1;
    if (!((i >= 0) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i0, &tb_emlrtBCI, sp);
    }

    i0 = repeatLayers->size[1] - 1;
    if (!((i >= 0) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i0, &ub_emlrtBCI, sp);
    }

    i0 = outSsubs->size[0];
    hiIndex = 1 + i;
    if (!((hiIndex >= 1) && (hiIndex <= i0))) {
      emlrtDynamicBoundsCheckR2012b(hiIndex, 1, i0, &vb_emlrtBCI, sp);
    }

    i0 = backgs->size[0];
    nx = 1 + i;
    if (!((nx >= 1) && (nx <= i0))) {
      emlrtDynamicBoundsCheckR2012b(nx, 1, i0, &wb_emlrtBCI, sp);
    }

    i0 = resols->size[0];
    idx = 1 + i;
    if (!((idx >= 1) && (idx <= i0))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, i0, &xb_emlrtBCI, sp);
    }

    i0 = Simulation->size[0] - 1;
    if (!((i >= 0) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i0, &yb_emlrtBCI, sp);
    }

    st.site = &g_emlrtRSI;
    callReflectivity(&st, nbairs->data[i1 - 1], nbsubs->data[b_lowIndex - 1],
                     simLimits->data[simLimits->size[0] * i].f1,
                     repeatLayers->data[repeatLayers->size[0] * i].f1,
                     shifted_dat, layerSld, outSsubs->data[hiIndex - 1],
                     backgs->data[nx - 1], resols->data[idx - 1], sldProfile,
                     Simulation->data[i].f1);
    i0 = reflectivity->size[0] - 1;
    if (!((i >= 0) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i0, &ac_emlrtBCI, sp);
    }

    i0 = reflectivity->data[i].f1->size[0] * reflectivity->data[i].f1->size[1];
    reflectivity->data[i].f1->size[0] = sldProfile->size[0];
    i1 = reflectivity->size[0] - 1;
    if (!((i >= 0) && (i <= i1))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, i1, &ac_emlrtBCI, sp);
    }

    reflectivity->data[i].f1->size[1] = 2;
    emxEnsureCapacity(sp, (emxArray__common *)reflectivity->data[i].f1, i0,
                      (int32_T)sizeof(real_T), &emlrtRTEI);
    nx = reflectivity->size[0] - 1;
    hiIndex = reflectivity->size[0] - 1;
    if (!((i >= 0) && (i <= hiIndex))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, hiIndex, &ac_emlrtBCI, sp);
    }

    hiIndex = reflectivity->size[0] - 1;
    if (!((i >= 0) && (i <= hiIndex))) {
      emlrtDynamicBoundsCheckR2012b(i, 0, hiIndex, &ac_emlrtBCI, sp);
    }

    idx = sldProfile->size[0] * sldProfile->size[1];
    for (i0 = 0; i0 < idx; i0++) {
      if (!((i >= 0) && (i <= nx))) {
        emlrtDynamicBoundsCheckR2012b(i, 0, nx, &ac_emlrtBCI, sp);
      }

      reflectivity->data[i].f1->data[i0] = sldProfile->data[i0];
    }

    i0 = chis->size[0];
    i1 = 1 + i;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &bc_emlrtBCI, sp);
    }

    st.site = &h_emlrtRSI;
    chis->data[i1 - 1] = chiSquared(&st, shifted_dat, sldProfile, nParams);
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_allData);
  emxFree_real_T(&c_data);
  emxFree_real_T(&b_data);
  emxFree_int32_T(&ii);
  emxFree_boolean_T(&x);
  emxFree_real_T(&lowIndex);
  emxFree_real_T(&data);
  emxFree_cell_wrap_0(&r0);
  emxFree_real_T(&outLayers);
  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&layerSld);
  emxFree_real_T(&sldProfile);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_stanlay_single.c) */
