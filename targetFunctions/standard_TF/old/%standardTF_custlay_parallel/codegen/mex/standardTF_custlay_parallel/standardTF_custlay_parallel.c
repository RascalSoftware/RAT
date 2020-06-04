/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_custlay_parallel.c
 *
 * Code generation for function 'standardTF_custlay_parallel'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_custlay_parallel.h"
#include "standardTF_custlay_parallel_emxutil.h"
#include "chiSquared.h"
#include "callReflectivity.h"
#include "shiftdata.h"
#include "resampleLayers.h"
#include "makeSLDProfiles.h"
#include "groupLayers_Mod.h"
#include "call_customLayers.h"
#include "backSort.h"
#include "standardTF_custlay_parallel_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 70,    /* lineNo */
  "standardTF_custlay_parallel",       /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 71,  /* lineNo */
  "standardTF_custlay_parallel",       /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 74,  /* lineNo */
  "standardTF_custlay_parallel",       /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 76,  /* lineNo */
  "standardTF_custlay_parallel",       /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 80,  /* lineNo */
  "standardTF_custlay_parallel",       /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 87,  /* lineNo */
  "standardTF_custlay_parallel",       /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 90,  /* lineNo */
  "standardTF_custlay_parallel",       /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 94,  /* lineNo */
  "standardTF_custlay_parallel",       /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 15,  /* lineNo */
  14,                                  /* colNo */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 76,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 87,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 80,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 51,    /* lineNo */
  16,                                  /* colNo */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 51,  /* lineNo */
  16,                                  /* colNo */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 52,  /* lineNo */
  17,                                  /* colNo */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 53,  /* lineNo */
  13,                                  /* colNo */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 54,  /* lineNo */
  14,                                  /* colNo */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 55,  /* lineNo */
  14,                                  /* colNo */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 56,  /* lineNo */
  16,                                  /* colNo */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 57,  /* lineNo */
  19,                                  /* colNo */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 58,  /* lineNo */
  18,                                  /* colNo */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 59,  /* lineNo */
  15,                                  /* colNo */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 60,  /* lineNo */
  18,                                  /* colNo */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 61,  /* lineNo */
  18,                                  /* colNo */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 62,  /* lineNo */
  20,                                  /* colNo */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = { 63,  /* lineNo */
  21,                                  /* colNo */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 64,  /* lineNo */
  21,                                  /* colNo */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = { 65,  /* lineNo */
  19,                                  /* colNo */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = { 69,  /* lineNo */
  1,                                   /* colNo */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo xb_emlrtRTEI = { 69,/* lineNo */
  12,                                  /* colNo */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  72,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  82,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  93,                                  /* colNo */
  "cScales",                           /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  104,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  113,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  122,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  6,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  16,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  27,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  50,                                  /* colNo */
  "resols",                            /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  75,                                  /* colNo */
  "nbairs",                            /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  85,                                  /* colNo */
  "nbsubs",                            /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  16,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  58,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  80,                                  /* colNo */
  "nbairs",                            /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  90,                                  /* colNo */
  "nbsubs",                            /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  17,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  34,                                  /* colNo */
  "nbairs",                            /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  44,                                  /* colNo */
  "nbsubs",                            /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  64,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  76,                                  /* colNo */
  "repeats",                           /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  8,                                   /* colNo */
  "resam",                             /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  29,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  36,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  47,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  73,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  40,                                  /* colNo */
  "nbairs",                            /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  50,                                  /* colNo */
  "nbsubs",                            /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  60,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  73,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  110,                                 /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  122,                                 /* colNo */
  "backgs",                            /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  132,                                 /* colNo */
  "resols",                            /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  91,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  94,                                  /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  62,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_custlay_parallel",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_parallel/standardTF_custlay_parallel.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void standardTF_custlay_parallel(const emlrtStack *sp, const emxArray_real_T
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
  emxArray_cell_wrap_3 *Simulation, emxArray_cell_wrap_1 *shifted_data,
  emxArray_cell_wrap_1 *layerSlds, emxArray_cell_wrap_3 *sldProfiles,
  emxArray_cell_wrap_4 *allLayers, emxArray_real_T *allRoughs)
{
  emxArray_real_T *sldProfile;
  emxArray_real_T *layerSld;
  emxArray_real_T *shifted_dat;
  emxArray_real_T *outLayers;
  emxArray_real_T *reflect;
  emxArray_real_T *b_allData;
  int32_T ub_loop;
  int32_T i;
  real_T d0;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T d5;
  int32_T i0;
  int32_T i1;
  int32_T b_allLayers;
  int32_T c_allLayers;
  int32_T i2;
  int32_T i3;
  jmp_buf * volatile emlrtJBStack;
  emlrtStack st;
  jmp_buf b_emlrtJBEnviron;
  emlrtStack b_st;
  boolean_T emlrtHadParallelError = false;
  (void)contrastLayers;
  (void)numberOfLayers;
  (void)whichType;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &sldProfile, 2, &b_emlrtRTEI, true);
  emxInit_real_T(sp, &layerSld, 2, &d_emlrtRTEI, true);
  emxInit_real_T(sp, &shifted_dat, 2, &c_emlrtRTEI, true);
  emxInit_real_T(sp, &outLayers, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &reflect, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &b_allData, 2, &emlrtRTEI, true);

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
    emlrtIntegerCheckR2012b(numberOfContrasts, &q_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &xb_emlrtRTEI, sp);
  ub_loop = backgs->size[0];
  backgs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity(sp, (emxArray__common *)backgs, ub_loop, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ub_loop = qshifts->size[0];
  qshifts->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity(sp, (emxArray__common *)qshifts, ub_loop, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ub_loop = sfs->size[0];
  sfs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity(sp, (emxArray__common *)sfs, ub_loop, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  ub_loop = nbas->size[0];
  nbas->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity(sp, (emxArray__common *)nbas, ub_loop, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ub_loop = nbss->size[0];
  nbss->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity(sp, (emxArray__common *)nbss, ub_loop, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ub_loop = resols->size[0];
  resols->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity(sp, (emxArray__common *)resols, ub_loop, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ub_loop = allRoughs->size[0];
  allRoughs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity(sp, (emxArray__common *)allRoughs, ub_loop, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ub_loop = allLayers->size[0] * allLayers->size[1];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  allLayers->size[1] = 1;
  emxEnsureCapacity_cell_wrap_4(sp, allLayers, ub_loop, &emlrtRTEI);
  ub_loop = outSsubs->size[0];
  outSsubs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity(sp, (emxArray__common *)outSsubs, ub_loop, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ub_loop = sldProfiles->size[0] * sldProfiles->size[1];
  sldProfiles->size[0] = (int32_T)numberOfContrasts;
  sldProfiles->size[1] = 1;
  emxEnsureCapacity_cell_wrap_3(sp, sldProfiles, ub_loop, &emlrtRTEI);
  ub_loop = layerSlds->size[0] * layerSlds->size[1];
  layerSlds->size[0] = (int32_T)numberOfContrasts;
  layerSlds->size[1] = 1;
  emxEnsureCapacity_cell_wrap_1(sp, layerSlds, ub_loop, &emlrtRTEI);
  ub_loop = shifted_data->size[0] * shifted_data->size[1];
  shifted_data->size[0] = (int32_T)numberOfContrasts;
  shifted_data->size[1] = 1;
  emxEnsureCapacity_cell_wrap_1(sp, shifted_data, ub_loop, &emlrtRTEI);
  ub_loop = reflectivity->size[0] * reflectivity->size[1];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  reflectivity->size[1] = 1;
  emxEnsureCapacity_cell_wrap_3(sp, reflectivity, ub_loop, &emlrtRTEI);
  ub_loop = Simulation->size[0] * Simulation->size[1];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  Simulation->size[1] = 1;
  emxEnsureCapacity_cell_wrap_3(sp, Simulation, ub_loop, &emlrtRTEI);
  ub_loop = chis->size[0];
  chis->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity(sp, (emxArray__common *)chis, ub_loop, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ub_loop = (int32_T)numberOfContrasts - 1;
  emlrtEnterParallelRegion(sp, omp_in_parallel());
  emlrtPushJmpBuf(sp, &emlrtJBStack);

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(b_allData,outLayers,layerSld,shifted_dat,reflect,sldProfile,d0,d1,d2,d3,d4,d5,i0,i,i1,b_allLayers,c_allLayers,i2,i3,b_emlrtJBEnviron) \
 firstprivate(st,b_st,emlrtHadParallelError)

  {
    if (setjmp(b_emlrtJBEnviron) == 0) {
      st.prev = sp;
      st.tls = emlrtAllocTLS(sp, omp_get_thread_num());
      st.site = NULL;
      emlrtSetJmpBuf(&st, &b_emlrtJBEnviron);
      b_st.prev = &st;
      b_st.tls = st.tls;
      emxInit_real_T(&st, &b_allData, 2, &emlrtRTEI, true);
      emxInit_real_T(&st, &outLayers, 2, &emlrtRTEI, true);
      emxInit_real_T(&st, &layerSld, 2, &d_emlrtRTEI, true);
      emxInit_real_T(&st, &shifted_dat, 2, &c_emlrtRTEI, true);
      emxInit_real_T(&st, &reflect, 2, &emlrtRTEI, true);
      emxInit_real_T(&st, &sldProfile, 2, &b_emlrtRTEI, true);
    } else {
      emlrtHadParallelError = true;
    }

#pragma omp for nowait

    for (i = 0; i <= ub_loop; i++) {
      if (emlrtHadParallelError)
        continue;
      if (setjmp(b_emlrtJBEnviron) == 0) {
        i0 = cBacks->size[1];
        if (!((i + 1 >= 1) && (i + 1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i0, &emlrtBCI, &st);
        }

        i0 = cShifts->size[1];
        if (!((i + 1 >= 1) && (i + 1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i0, &b_emlrtBCI, &st);
        }

        i0 = cScales->size[1];
        if (!((i + 1 >= 1) && (i + 1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i0, &c_emlrtBCI, &st);
        }

        i0 = cNbas->size[1];
        if (!((i + 1 >= 1) && (i + 1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i0, &d_emlrtBCI, &st);
        }

        i0 = cNbss->size[1];
        if (!((i + 1 >= 1) && (i + 1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i0, &e_emlrtBCI, &st);
        }

        i0 = cRes->size[1];
        if (!((i + 1 >= 1) && (i + 1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i0, &f_emlrtBCI, &st);
        }

        b_st.site = &emlrtRSI;
        backSort(&b_st, cBacks->data[i], cShifts->data[i], cScales->data[i],
                 cNbas->data[i], cNbss->data[i], cRes->data[i], backs, shifts,
                 sf, nba, nbs, res, &d5, &d4, &d3, &d2, &d1, &d0);
        i0 = backgs->size[0];
        if (!((i + 1 >= 1) && (i + 1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i0, &g_emlrtBCI, &st);
        }

        backgs->data[i] = d5;
        i0 = qshifts->size[0];
        if (!((i + 1 >= 1) && (i + 1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i0, &h_emlrtBCI, &st);
        }

        qshifts->data[i] = d4;
        i0 = sfs->size[0];
        if (!((i + 1 >= 1) && (i + 1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i0, &i_emlrtBCI, &st);
        }

        sfs->data[i] = d3;
        i0 = nbas->size[0];
        if (!((i + 1 >= 1) && (i + 1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i0, &j_emlrtBCI, &st);
        }

        nbas->data[i] = d2;
        i0 = nbss->size[0];
        if (!((i + 1 >= 1) && (i + 1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i0, &k_emlrtBCI, &st);
        }

        nbss->data[i] = d1;
        i0 = resols->size[0];
        if (!((i + 1 >= 1) && (i + 1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i0, &l_emlrtBCI, &st);
        }

        resols->data[i] = d0;
        i0 = nbairs->size[1];
        if (!((i + 1 >= 1) && (i + 1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i0, &m_emlrtBCI, &st);
        }

        i0 = nbsubs->size[1];
        if (!((i + 1 >= 1) && (i + 1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i0, &n_emlrtBCI, &st);
        }

        b_st.site = &b_emlrtRSI;
        call_customLayers(&b_st, params, 1.0 + (real_T)i, fileHandle, path,
                          nbairs->data[i], nbsubs->data[i], outLayers, &d0);
        i0 = allRoughs->size[0];
        if (!((i + 1 >= 1) && (i + 1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i0, &o_emlrtBCI, &st);
        }

        allRoughs->data[i] = d0;
        i0 = allLayers->size[0] - 1;
        if (!((i >= 0) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, i0, &p_emlrtBCI, &st);
        }

        i0 = allLayers->data[i].f1->size[0] * allLayers->data[i].f1->size[1];
        allLayers->data[i].f1->size[0] = outLayers->size[0];
        i1 = allLayers->size[0] - 1;
        if (!((i >= 0) && (i <= i1))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, i1, &p_emlrtBCI, &st);
        }

        allLayers->data[i].f1->size[1] = outLayers->size[1];
        emxEnsureCapacity(&st, (emxArray__common *)allLayers->data[i].f1, i0,
                          (int32_T)sizeof(real_T), &emlrtRTEI);
        b_allLayers = allLayers->size[0] - 1;
        c_allLayers = allLayers->size[0] - 1;
        if (!((i >= 0) && (i <= c_allLayers))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, c_allLayers, &p_emlrtBCI, &st);
        }

        c_allLayers = allLayers->size[0] - 1;
        if (!((i >= 0) && (i <= c_allLayers))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, c_allLayers, &p_emlrtBCI, &st);
        }

        c_allLayers = outLayers->size[0] * outLayers->size[1];
        for (i0 = 0; i0 < c_allLayers; i0++) {
          if (!((i >= 0) && (i <= b_allLayers))) {
            emlrtDynamicBoundsCheckR2012b(i, 0, b_allLayers, &p_emlrtBCI, &st);
          }

          allLayers->data[i].f1->data[i0] = outLayers->data[i0];
        }

        i0 = nbairs->size[1];
        i1 = 1 + i;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &r_emlrtBCI, &st);
        }

        i0 = nbsubs->size[1];
        i1 = 1 + i;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &s_emlrtBCI, &st);
        }

        i0 = allRoughs->size[0];
        i1 = 1 + i;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &q_emlrtBCI, &st);
        }

        b_st.site = &c_emlrtRSI;
        groupLayers_Mod(&b_st, outLayers, allRoughs->data[i1 - 1], geometry,
                        layerSld, &d0);
        i0 = outSsubs->size[0];
        i1 = 1 + i;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &t_emlrtBCI, &st);
        }

        outSsubs->data[i1 - 1] = d0;
        i0 = nbairs->size[1];
        i1 = 1 + i;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &u_emlrtBCI, &st);
        }

        i0 = nbsubs->size[1];
        c_allLayers = 1 + i;
        if (!((c_allLayers >= 1) && (c_allLayers <= i0))) {
          emlrtDynamicBoundsCheckR2012b(c_allLayers, 1, i0, &v_emlrtBCI, &st);
        }

        i0 = outSsubs->size[0];
        b_allLayers = 1 + i;
        if (!((b_allLayers >= 1) && (b_allLayers <= i0))) {
          emlrtDynamicBoundsCheckR2012b(b_allLayers, 1, i0, &w_emlrtBCI, &st);
        }

        i0 = repeats->size[1] - 1;
        if (!((i >= 0) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, i0, &x_emlrtBCI, &st);
        }

        b_st.site = &d_emlrtRSI;
        makeSLDProfiles(&b_st, nbairs->data[i1 - 1], nbsubs->data[c_allLayers -
                        1], layerSld, outSsubs->data[b_allLayers - 1],
                        repeats->data[repeats->size[0] * i].f1, sldProfile);
        i0 = sldProfiles->size[0] - 1;
        if (!((i >= 0) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, i0, &y_emlrtBCI, &st);
        }

        i0 = sldProfiles->data[i].f1->size[0] * sldProfiles->data[i].f1->size[1];
        sldProfiles->data[i].f1->size[0] = sldProfile->size[0];
        i1 = sldProfiles->size[0] - 1;
        if (!((i >= 0) && (i <= i1))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, i1, &y_emlrtBCI, &st);
        }

        sldProfiles->data[i].f1->size[1] = 2;
        emxEnsureCapacity(&st, (emxArray__common *)sldProfiles->data[i].f1, i0,
                          (int32_T)sizeof(real_T), &emlrtRTEI);
        b_allLayers = sldProfiles->size[0] - 1;
        c_allLayers = sldProfiles->size[0] - 1;
        if (!((i >= 0) && (i <= c_allLayers))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, c_allLayers, &y_emlrtBCI, &st);
        }

        c_allLayers = sldProfiles->size[0] - 1;
        if (!((i >= 0) && (i <= c_allLayers))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, c_allLayers, &y_emlrtBCI, &st);
        }

        c_allLayers = sldProfile->size[0] * sldProfile->size[1];
        for (i0 = 0; i0 < c_allLayers; i0++) {
          if (!((i >= 0) && (i <= b_allLayers))) {
            emlrtDynamicBoundsCheckR2012b(i, 0, b_allLayers, &y_emlrtBCI, &st);
          }

          sldProfiles->data[i].f1->data[i0] = sldProfile->data[i0];
        }

        i0 = resam->size[0];
        i1 = 1 + i;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &ab_emlrtBCI, &st);
        }

        if (resam->data[i1 - 1] == 1.0) {
          b_st.site = &e_emlrtRSI;
          resampleLayers(&b_st, sldProfile, layerSld);
          i0 = layerSlds->size[0] - 1;
          if (!((i >= 0) && (i <= i0))) {
            emlrtDynamicBoundsCheckR2012b(i, 0, i0, &cb_emlrtBCI, &st);
          }

          i0 = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
          layerSlds->data[i].f1->size[0] = layerSld->size[0];
          i1 = layerSlds->size[0] - 1;
          if (!((i >= 0) && (i <= i1))) {
            emlrtDynamicBoundsCheckR2012b(i, 0, i1, &cb_emlrtBCI, &st);
          }

          layerSlds->data[i].f1->size[1] = 3;
          emxEnsureCapacity(&st, (emxArray__common *)layerSlds->data[i].f1, i0,
                            (int32_T)sizeof(real_T), &emlrtRTEI);
          b_allLayers = layerSlds->size[0] - 1;
          c_allLayers = layerSlds->size[0] - 1;
          if (!((i >= 0) && (i <= c_allLayers))) {
            emlrtDynamicBoundsCheckR2012b(i, 0, c_allLayers, &cb_emlrtBCI, &st);
          }

          c_allLayers = layerSlds->size[0] - 1;
          if (!((i >= 0) && (i <= c_allLayers))) {
            emlrtDynamicBoundsCheckR2012b(i, 0, c_allLayers, &cb_emlrtBCI, &st);
          }

          c_allLayers = layerSld->size[0] * layerSld->size[1];
          for (i0 = 0; i0 < c_allLayers; i0++) {
            if (!((i >= 0) && (i <= b_allLayers))) {
              emlrtDynamicBoundsCheckR2012b(i, 0, b_allLayers, &cb_emlrtBCI, &st);
            }

            layerSlds->data[i].f1->data[i0] = layerSld->data[i0];
          }
        } else {
          i0 = layerSlds->size[0] - 1;
          if (!((i >= 0) && (i <= i0))) {
            emlrtDynamicBoundsCheckR2012b(i, 0, i0, &bb_emlrtBCI, &st);
          }

          i0 = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
          layerSlds->data[i].f1->size[0] = layerSld->size[0];
          i1 = layerSlds->size[0] - 1;
          if (!((i >= 0) && (i <= i1))) {
            emlrtDynamicBoundsCheckR2012b(i, 0, i1, &bb_emlrtBCI, &st);
          }

          layerSlds->data[i].f1->size[1] = 3;
          emxEnsureCapacity(&st, (emxArray__common *)layerSlds->data[i].f1, i0,
                            (int32_T)sizeof(real_T), &emlrtRTEI);
          b_allLayers = layerSlds->size[0] - 1;
          c_allLayers = layerSlds->size[0] - 1;
          if (!((i >= 0) && (i <= c_allLayers))) {
            emlrtDynamicBoundsCheckR2012b(i, 0, c_allLayers, &bb_emlrtBCI, &st);
          }

          c_allLayers = layerSlds->size[0] - 1;
          if (!((i >= 0) && (i <= c_allLayers))) {
            emlrtDynamicBoundsCheckR2012b(i, 0, c_allLayers, &bb_emlrtBCI, &st);
          }

          c_allLayers = layerSld->size[0] * layerSld->size[1];
          for (i0 = 0; i0 < c_allLayers; i0++) {
            if (!((i >= 0) && (i <= b_allLayers))) {
              emlrtDynamicBoundsCheckR2012b(i, 0, b_allLayers, &bb_emlrtBCI, &st);
            }

            layerSlds->data[i].f1->data[i0] = layerSld->data[i0];
          }
        }

        i0 = b_allData->size[0] * b_allData->size[1];
        i1 = allData->size[1] - 1;
        if (!((i >= 0) && (i <= i1))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, i1, &sb_emlrtBCI, &st);
        }

        b_allData->size[0] = allData->data[allData->size[0] * i].f1->size[0];
        b_allData->size[1] = 3;
        emxEnsureCapacity(&st, (emxArray__common *)b_allData, i0, (int32_T)
                          sizeof(real_T), &emlrtRTEI);
        i0 = allData->size[1] - 1;
        if (!((i >= 0) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, i0, &sb_emlrtBCI, &st);
        }

        i0 = allData->size[1] - 1;
        if (!((i >= 0) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, i0, &sb_emlrtBCI, &st);
        }

        c_allLayers = allData->data[allData->size[0] * i].f1->size[0] *
          allData->data[allData->size[0] * i].f1->size[1];
        for (i0 = 0; i0 < c_allLayers; i0++) {
          i1 = allData->size[1] - 1;
          if (!((i >= 0) && (i <= i1))) {
            emlrtDynamicBoundsCheckR2012b(i, 0, i1, &sb_emlrtBCI, &st);
          }

          b_allData->data[i0] = allData->data[allData->size[0] * i].f1->data[i0];
        }

        i0 = sfs->size[0];
        i1 = 1 + i;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &db_emlrtBCI, &st);
        }

        i0 = qshifts->size[0];
        c_allLayers = 1 + i;
        if (!((c_allLayers >= 1) && (c_allLayers <= i0))) {
          emlrtDynamicBoundsCheckR2012b(c_allLayers, 1, i0, &eb_emlrtBCI, &st);
        }

        i0 = dataPresent->size[1];
        b_allLayers = 1 + i;
        if (!((b_allLayers >= 1) && (b_allLayers <= i0))) {
          emlrtDynamicBoundsCheckR2012b(b_allLayers, 1, i0, &fb_emlrtBCI, &st);
        }

        i0 = dataLimits->size[1] - 1;
        if (!((i >= 0) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, i0, &gb_emlrtBCI, &st);
        }

        b_st.site = &f_emlrtRSI;
        shiftdata(&b_st, sfs->data[i1 - 1], qshifts->data[c_allLayers - 1],
                  dataPresent->data[b_allLayers - 1], b_allData,
                  dataLimits->data[dataLimits->size[0] * i].f1, shifted_dat);
        i0 = shifted_data->size[0] - 1;
        if (!((i >= 0) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, i0, &hb_emlrtBCI, &st);
        }

        i0 = shifted_data->data[i].f1->size[0] * shifted_data->data[i].f1->size
          [1];
        shifted_data->data[i].f1->size[0] = shifted_dat->size[0];
        i1 = shifted_data->size[0] - 1;
        if (!((i >= 0) && (i <= i1))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, i1, &hb_emlrtBCI, &st);
        }

        shifted_data->data[i].f1->size[1] = 3;
        emxEnsureCapacity(&st, (emxArray__common *)shifted_data->data[i].f1, i0,
                          (int32_T)sizeof(real_T), &emlrtRTEI);
        b_allLayers = shifted_data->size[0] - 1;
        c_allLayers = shifted_data->size[0] - 1;
        if (!((i >= 0) && (i <= c_allLayers))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, c_allLayers, &hb_emlrtBCI, &st);
        }

        c_allLayers = shifted_data->size[0] - 1;
        if (!((i >= 0) && (i <= c_allLayers))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, c_allLayers, &hb_emlrtBCI, &st);
        }

        c_allLayers = shifted_dat->size[0] * shifted_dat->size[1];
        for (i0 = 0; i0 < c_allLayers; i0++) {
          if (!((i >= 0) && (i <= b_allLayers))) {
            emlrtDynamicBoundsCheckR2012b(i, 0, b_allLayers, &hb_emlrtBCI, &st);
          }

          shifted_data->data[i].f1->data[i0] = shifted_dat->data[i0];
        }

        i0 = nbairs->size[1];
        i1 = 1 + i;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &ib_emlrtBCI, &st);
        }

        i0 = nbsubs->size[1];
        c_allLayers = 1 + i;
        if (!((c_allLayers >= 1) && (c_allLayers <= i0))) {
          emlrtDynamicBoundsCheckR2012b(c_allLayers, 1, i0, &jb_emlrtBCI, &st);
        }

        i0 = simLimits->size[1] - 1;
        if (!((i >= 0) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, i0, &kb_emlrtBCI, &st);
        }

        i0 = repeatLayers->size[1] - 1;
        if (!((i >= 0) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, i0, &lb_emlrtBCI, &st);
        }

        i0 = outSsubs->size[0];
        b_allLayers = 1 + i;
        if (!((b_allLayers >= 1) && (b_allLayers <= i0))) {
          emlrtDynamicBoundsCheckR2012b(b_allLayers, 1, i0, &mb_emlrtBCI, &st);
        }

        i0 = backgs->size[0];
        i2 = 1 + i;
        if (!((i2 >= 1) && (i2 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i0, &nb_emlrtBCI, &st);
        }

        i0 = resols->size[0];
        i3 = 1 + i;
        if (!((i3 >= 1) && (i3 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, i0, &ob_emlrtBCI, &st);
        }

        b_st.site = &g_emlrtRSI;
        callReflectivity(&b_st, nbairs->data[i1 - 1], nbsubs->data[c_allLayers -
                         1], simLimits->data[simLimits->size[0] * i].f1,
                         repeatLayers->data[repeatLayers->size[0] * i].f1,
                         shifted_dat, layerSld, outSsubs->data[b_allLayers - 1],
                         backgs->data[i2 - 1], resols->data[i3 - 1], reflect,
                         sldProfile);
        i0 = reflectivity->size[0] - 1;
        if (!((i >= 0) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, i0, &pb_emlrtBCI, &st);
        }

        i0 = reflectivity->data[i].f1->size[0] * reflectivity->data[i].f1->size
          [1];
        reflectivity->data[i].f1->size[0] = reflect->size[0];
        i1 = reflectivity->size[0] - 1;
        if (!((i >= 0) && (i <= i1))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, i1, &pb_emlrtBCI, &st);
        }

        reflectivity->data[i].f1->size[1] = 2;
        emxEnsureCapacity(&st, (emxArray__common *)reflectivity->data[i].f1, i0,
                          (int32_T)sizeof(real_T), &emlrtRTEI);
        b_allLayers = reflectivity->size[0] - 1;
        c_allLayers = reflectivity->size[0] - 1;
        if (!((i >= 0) && (i <= c_allLayers))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, c_allLayers, &pb_emlrtBCI, &st);
        }

        c_allLayers = reflectivity->size[0] - 1;
        if (!((i >= 0) && (i <= c_allLayers))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, c_allLayers, &pb_emlrtBCI, &st);
        }

        c_allLayers = reflect->size[0] * reflect->size[1];
        for (i0 = 0; i0 < c_allLayers; i0++) {
          if (!((i >= 0) && (i <= b_allLayers))) {
            emlrtDynamicBoundsCheckR2012b(i, 0, b_allLayers, &pb_emlrtBCI, &st);
          }

          reflectivity->data[i].f1->data[i0] = reflect->data[i0];
        }

        i0 = Simulation->size[0] - 1;
        if (!((i >= 0) && (i <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, i0, &qb_emlrtBCI, &st);
        }

        i0 = Simulation->data[i].f1->size[0] * Simulation->data[i].f1->size[1];
        Simulation->data[i].f1->size[0] = sldProfile->size[0];
        i1 = Simulation->size[0] - 1;
        if (!((i >= 0) && (i <= i1))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, i1, &qb_emlrtBCI, &st);
        }

        Simulation->data[i].f1->size[1] = 2;
        emxEnsureCapacity(&st, (emxArray__common *)Simulation->data[i].f1, i0,
                          (int32_T)sizeof(real_T), &emlrtRTEI);
        b_allLayers = Simulation->size[0] - 1;
        c_allLayers = Simulation->size[0] - 1;
        if (!((i >= 0) && (i <= c_allLayers))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, c_allLayers, &qb_emlrtBCI, &st);
        }

        c_allLayers = Simulation->size[0] - 1;
        if (!((i >= 0) && (i <= c_allLayers))) {
          emlrtDynamicBoundsCheckR2012b(i, 0, c_allLayers, &qb_emlrtBCI, &st);
        }

        c_allLayers = sldProfile->size[0] * sldProfile->size[1];
        for (i0 = 0; i0 < c_allLayers; i0++) {
          if (!((i >= 0) && (i <= b_allLayers))) {
            emlrtDynamicBoundsCheckR2012b(i, 0, b_allLayers, &qb_emlrtBCI, &st);
          }

          Simulation->data[i].f1->data[i0] = sldProfile->data[i0];
        }

        i0 = chis->size[0];
        i1 = 1 + i;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &rb_emlrtBCI, &st);
        }

        b_st.site = &h_emlrtRSI;
        chis->data[i1 - 1] = chiSquared(&b_st, shifted_dat, reflect, nParams);
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      } else {
        emlrtHadParallelError = true;
      }
    }

    if (!emlrtHadParallelError) {
      emlrtHeapReferenceStackLeaveScope(&st, 6);
      emxFree_real_T(&sldProfile);
      emxFree_real_T(&reflect);
      emxFree_real_T(&shifted_dat);
      emxFree_real_T(&layerSld);
      emxFree_real_T(&outLayers);
      emxFree_real_T(&b_allData);
    }
  }

  emlrtPopJmpBuf(sp, &emlrtJBStack);
  emlrtExitParallelRegion(sp, omp_in_parallel());
  emxFree_real_T(&b_allData);
  emxFree_real_T(&reflect);
  emxFree_real_T(&outLayers);
  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&layerSld);
  emxFree_real_T(&sldProfile);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_custlay_parallel.c) */
