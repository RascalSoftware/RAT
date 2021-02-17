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
#include "standardTF_stanlay_single.h"
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
static emlrtRSInfo j_emlrtRSI = { 39,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 44,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 48,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 49,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 60,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 67,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 73,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 76,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 79,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 82,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRTEInfo y_emlrtRTEI = { 25,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 30,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 35,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 41,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  84,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  95,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  106,                                 /* colNo */
  "cScales",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  115,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  124,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  132,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  24,                                  /* colNo */
  "params",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  75,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  91,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = { 41,  /* lineNo */
  19,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  19,                                  /* colNo */
  "backs",                             /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = { 44,  /* lineNo */
  21,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  21,                                  /* colNo */
  "shifts",                            /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo s_emlrtDCI = { 47,  /* lineNo */
  13,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  13,                                  /* colNo */
  "sf",                                /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo t_emlrtDCI = { 50,  /* lineNo */
  15,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  15,                                  /* colNo */
  "nba",                               /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo u_emlrtDCI = { 53,  /* lineNo */
  15,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  15,                                  /* colNo */
  "nbs",                               /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo v_emlrtDCI = { 56,  /* lineNo */
  17,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  17,                                  /* colNo */
  "res",                               /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo w_emlrtDCI = { 11,  /* lineNo */
  16,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  52,                                  /* colNo */
  "contrastLayers",                    /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  49,                                  /* lineNo */
  19,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  54,                                  /* lineNo */
  8,                                   /* colNo */
  "resample",                          /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  8,                                   /* colNo */
  "resample",                          /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  62,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  47,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  73,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  56,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  69,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  106,                                 /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  102,                                 /* colNo */
  "backsType",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  91,                                  /* lineNo */
  5,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  5,                                   /* colNo */
  "qshifts",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  5,                                   /* colNo */
  "sfs",                               /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  94,                                  /* lineNo */
  5,                                   /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  5,                                   /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  96,                                  /* lineNo */
  5,                                   /* colNo */
  "resols",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  5,                                   /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo xg_emlrtRTEI = { 3,/* lineNo */
  26,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo yg_emlrtRTEI = { 26,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo ah_emlrtRTEI = { 31,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo bh_emlrtRTEI = { 18,/* lineNo */
  12,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo ch_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo dh_emlrtRTEI = { 62,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo eh_emlrtRTEI = { 60,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo fh_emlrtRTEI = { 73,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo gh_emlrtRTEI = { 85,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo hh_emlrtRTEI = { 86,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo ih_emlrtRTEI = { 88,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo jh_emlrtRTEI = { 89,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo kh_emlrtRTEI = { 39,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo lh_emlrtRTEI = { 48,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo mh_emlrtRTEI = { 67,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo nh_emlrtRTEI = { 60,/* lineNo */
  22,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

/* Function Definitions */
void standardTF_stanlay_single(const emlrtStack *sp, const emxArray_real_T
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
  int32_T b_i;
  int32_T i2;
  emxArray_cell_wrap_16 *outParameterisedLayers;
  emxArray_real_T *thisContrastLayers;
  emxArray_real_T *sldProfile;
  emxArray_real_T *layerSld;
  emxArray_real_T *shifted_dat;
  emxArray_real_T *b_sldProfile;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T i7;
  real_T thisCalcSld;
  int32_T loop_ub;
  int32_T i8;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 4U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 0U);

  /* Pre-Allocation... */
  if (numberOfContrasts != (int32_T)muDoubleScalarFloor(numberOfContrasts)) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &w_emlrtDCI, sp);
  }

  /*   */
  i = (int32_T)numberOfContrasts;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &y_emlrtRTEI, sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_11(sp, reflectivity, i1, &xg_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 4U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 1U);
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ub_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &yg_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ub_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &yg_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ub_emlrtBCI, sp);
    }

    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ub_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ub_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ub_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ub_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ub_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 4U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 2U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &ab_emlrtRTEI, sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, Simulation, i1, &xg_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 4U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 3U);
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &vb_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &ah_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &vb_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &ah_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &vb_emlrtBCI, sp);
    }

    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &vb_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &vb_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &vb_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &vb_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &vb_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 4U, 0U, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 4U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &bb_emlrtRTEI, sp);
  i1 = allLayers->size[0];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_11(sp, allLayers, i1, &xg_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 4U, 0U, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 5U);
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &wb_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &ch_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &wb_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &ch_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &wb_emlrtBCI, sp);
    }

    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &wb_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &wb_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &wb_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
  }

  emxInit_cell_wrap_16(sp, &outParameterisedLayers, 2, &kh_emlrtRTEI, true);
  covrtLogFor(&emlrtCoverageInstance, 4U, 0U, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 6U);
  st.site = &j_emlrtRSI;
  allocateParamsToLayers(&st, params, layersDetails, outParameterisedLayers);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &cb_emlrtRTEI, sp);
  i1 = outSsubs->size[0];
  outSsubs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, outSsubs, i1, &bh_emlrtRTEI);
  i1 = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, Simulation, i1, &xg_emlrtRTEI);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_11(sp, reflectivity, i1, &xg_emlrtRTEI);
  i1 = sldProfiles->size[0];
  sldProfiles->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_11(sp, sldProfiles, i1, &xg_emlrtRTEI);
  i1 = shifted_data->size[0];
  shifted_data->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, shifted_data, i1, &xg_emlrtRTEI);
  i1 = layerSlds->size[0];
  layerSlds->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, layerSlds, i1, &xg_emlrtRTEI);
  i1 = chis->size[0];
  chis->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, chis, i1, &bh_emlrtRTEI);
  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &bh_emlrtRTEI);
  i1 = qshifts->size[0];
  qshifts->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, qshifts, i1, &bh_emlrtRTEI);
  i1 = sfs->size[0];
  sfs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, sfs, i1, &bh_emlrtRTEI);
  i1 = nbas->size[0];
  nbas->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbas, i1, &bh_emlrtRTEI);
  i1 = nbss->size[0];
  nbss->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbss, i1, &bh_emlrtRTEI);
  i1 = resols->size[0];
  resols->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, resols, i1, &bh_emlrtRTEI);
  i1 = allRoughs->size[0];
  allRoughs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, allRoughs, i1, &bh_emlrtRTEI);
  emxInit_real_T(sp, &thisContrastLayers, 2, &lh_emlrtRTEI, true);
  emxInit_real_T(sp, &sldProfile, 2, &eh_emlrtRTEI, true);
  emxInit_real_T(sp, &layerSld, 2, &mh_emlrtRTEI, true);
  emxInit_real_T(sp, &shifted_dat, 2, &fh_emlrtRTEI, true);
  emxInit_real_T(sp, &b_sldProfile, 2, &nh_emlrtRTEI, true);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 4U, 0U, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 7U);

    /*  Extract the correct parameter values for this contrast */
    st.site = &k_emlrtRSI;
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cBacks->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cBacks->size[1], &fb_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cShifts->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cShifts->size[1], &gb_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cScales->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cScales->size[1], &hb_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cNbas->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cNbas->size[1], &ib_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cNbss->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cNbss->size[1], &jb_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cRes->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cRes->size[1], &kb_emlrtBCI, &st);
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
      emlrtIntegerCheckR2012b(cBacks->data[b_i], &q_emlrtDCI, &st);
    }

    i1 = (int32_T)cBacks->data[b_i];
    if ((i1 < 1) || (i1 > backs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, backs->size[1], &ob_emlrtBCI, &st);
    }

    /* thisShift = cShifts(i); */
    if (cShifts->data[b_i] != (int32_T)muDoubleScalarFloor(cShifts->data[b_i]))
    {
      emlrtIntegerCheckR2012b(cShifts->data[b_i], &r_emlrtDCI, &st);
    }

    i2 = (int32_T)cShifts->data[b_i];
    if ((i2 < 1) || (i2 > shifts->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, shifts->size[1], &pb_emlrtBCI, &st);
    }

    /* thisScale = cScales(i); */
    if (cScales->data[b_i] != (int32_T)muDoubleScalarFloor(cScales->data[b_i]))
    {
      emlrtIntegerCheckR2012b(cScales->data[b_i], &s_emlrtDCI, &st);
    }

    i3 = (int32_T)cScales->data[b_i];
    if ((i3 < 1) || (i3 > sf->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, sf->size[1], &qb_emlrtBCI, &st);
    }

    /* thisNbair = cNbas(i); */
    if (cNbas->data[b_i] != (int32_T)muDoubleScalarFloor(cNbas->data[b_i])) {
      emlrtIntegerCheckR2012b(cNbas->data[b_i], &t_emlrtDCI, &st);
    }

    i4 = (int32_T)cNbas->data[b_i];
    if ((i4 < 1) || (i4 > nba->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i4, 1, nba->size[1], &rb_emlrtBCI, &st);
    }

    /* thisNbsub = cNbss(i); */
    if (cNbss->data[b_i] != (int32_T)muDoubleScalarFloor(cNbss->data[b_i])) {
      emlrtIntegerCheckR2012b(cNbss->data[b_i], &u_emlrtDCI, &st);
    }

    i5 = (int32_T)cNbss->data[b_i];
    if ((i5 < 1) || (i5 > nbs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i5, 1, nbs->size[1], &sb_emlrtBCI, &st);
    }

    /* thisResol = cRes(i); */
    if (cRes->data[b_i] != (int32_T)muDoubleScalarFloor(cRes->data[b_i])) {
      emlrtIntegerCheckR2012b(cRes->data[b_i], &v_emlrtDCI, &st);
    }

    i6 = (int32_T)cRes->data[b_i];
    if ((i6 < 1) || (i6 > res->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i6, 1, res->size[1], &tb_emlrtBCI, &st);
    }

    /* end */
    if (1 > params->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, params->size[1], &lb_emlrtBCI, sp);
    }

    /*  Bulid up the layers matrix for this contrast */
    i7 = contrastLayers->size[1] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &xb_emlrtBCI, sp);
    }

    st.site = &l_emlrtRSI;
    allocateLayersForContrast(&st, contrastLayers->data[b_i].f1,
      outParameterisedLayers, thisContrastLayers);
    i7 = b_i + 1;
    if ((i7 < 1) || (i7 > outSsubs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, outSsubs->size[0], &yb_emlrtBCI, sp);
    }

    st.site = &m_emlrtRSI;
    groupLayers_Mod(&st, thisContrastLayers, params->data[0], geometry,
                    nba->data[(int32_T)cNbas->data[b_i] - 1], nbs->data[(int32_T)
                    cNbss->data[b_i] - 1], layerSld, &outSsubs->data[i7 - 1]);

    /*  Make the SLD profiles. */
    /*  If resampling is done, then enforce th calcSLD flag */
    thisCalcSld = calcSld;
    i7 = b_i + 1;
    if ((i7 < 1) || (i7 > resample->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, resample->size[1], &ac_emlrtBCI, sp);
    }

    if (covrtLogIf(&emlrtCoverageInstance, 4U, 0U, 0, resample->data[i7 - 1] ==
                   1.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 8U);
      thisCalcSld = 1.0;
    }

    /*  If cal SLD flag is set, then calculate the SLD profile */
    if (covrtLogIf(&emlrtCoverageInstance, 4U, 0U, 1, thisCalcSld == 1.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 9U);
      st.site = &n_emlrtRSI;
      i7 = b_i + 1;
      if ((i7 < 1) || (i7 > outSsubs->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i7, 1, outSsubs->size[0], &mb_emlrtBCI,
          &st);
      }

      i7 = repeatLayers->size[1] - 1;
      if (b_i > i7) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &nb_emlrtBCI, &st);
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
      makeSLDProfileXY(&b_st, nba->data[(int32_T)cNbas->data[b_i] - 1],
                       nbs->data[(int32_T)cNbss->data[b_i] - 1], outSsubs->
                       data[b_i], layerSld, layerSld->size[0], thisCalcSld,
                       b_sldProfile);
      i7 = sldProfile->size[0] * sldProfile->size[1];
      sldProfile->size[0] = b_sldProfile->size[0];
      sldProfile->size[1] = 2;
      emxEnsureCapacity_real_T(sp, sldProfile, i7, &eh_emlrtRTEI);
      loop_ub = b_sldProfile->size[0] * b_sldProfile->size[1];
      for (i7 = 0; i7 < loop_ub; i7++) {
        sldProfile->data[i7] = b_sldProfile->data[i7];
      }
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 10U);
      i7 = sldProfile->size[0] * sldProfile->size[1];
      sldProfile->size[0] = 1;
      sldProfile->size[1] = 3;
      emxEnsureCapacity_real_T(sp, sldProfile, i7, &dh_emlrtRTEI);
      sldProfile->data[0] = 0.0;
      sldProfile->data[1] = 0.0;
      sldProfile->data[2] = 0.0;
    }

    /*  If required, then resample the SLD */
    i7 = b_i + 1;
    if ((i7 < 1) || (i7 > resample->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, resample->size[1], &bc_emlrtBCI, sp);
    }

    if (covrtLogIf(&emlrtCoverageInstance, 4U, 0U, 2, resample->data[i7 - 1] ==
                   1.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 11U);
      st.site = &o_emlrtRSI;
      resampleLayers(&st, sldProfile, layerSld);
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 12U);
    }

    covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 13U);

    /*  Apply scale factors and q shifts to the data */
    i7 = allData->size[1] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &cc_emlrtBCI, sp);
    }

    i7 = shifted_dat->size[0] * shifted_dat->size[1];
    shifted_dat->size[0] = allData->data[b_i].f1->size[0];
    shifted_dat->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_dat, i7, &fh_emlrtRTEI);
    i7 = allData->size[1] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &cc_emlrtBCI, sp);
    }

    i7 = allData->size[1] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &cc_emlrtBCI, sp);
    }

    loop_ub = allData->data[b_i].f1->size[0] * allData->data[b_i].f1->size[1];
    for (i7 = 0; i7 < loop_ub; i7++) {
      i8 = allData->size[1] - 1;
      if (b_i > i8) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &cc_emlrtBCI, sp);
      }

      i8 = allData->size[1] - 1;
      if (b_i > i8) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &cc_emlrtBCI, sp);
      }

      i8 = allData->size[1] - 1;
      if (b_i > i8) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &cc_emlrtBCI, sp);
      }

      shifted_dat->data[i7] = allData->data[b_i].f1->data[i7];
    }

    i7 = b_i + 1;
    if ((i7 < 1) || (i7 > dataPresent->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, dataPresent->size[1], &dc_emlrtBCI,
        sp);
    }

    i8 = dataLimits->size[1] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &ec_emlrtBCI, sp);
    }

    st.site = &p_emlrtRSI;
    shiftdata(&st, sf->data[(int32_T)cScales->data[b_i] - 1], shifts->data
              [(int32_T)cShifts->data[b_i] - 1], dataPresent->data[i7 - 1],
              shifted_dat, dataLimits->data[b_i].f1);

    /*  Calculate the reflectivity */
    i7 = simLimits->size[1] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &fc_emlrtBCI, sp);
    }

    i7 = repeatLayers->size[1] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &gc_emlrtBCI, sp);
    }

    i7 = b_i + 1;
    if ((i7 < 1) || (i7 > outSsubs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, outSsubs->size[0], &hc_emlrtBCI, sp);
    }

    i8 = Simulation->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &ic_emlrtBCI, sp);
    }

    st.site = &q_emlrtRSI;
    callReflectivity(&st, nba->data[(int32_T)cNbas->data[b_i] - 1], nbs->data
                     [(int32_T)cNbss->data[b_i] - 1], simLimits->data[b_i].f1,
                     repeatLayers->data[b_i].f1, shifted_dat, layerSld,
                     outSsubs->data[i7 - 1], res->data[(int32_T)cRes->data[b_i]
                     - 1], b_sldProfile, Simulation->data[b_i].f1);

    /*  Apply background correction, either to the simulation or the data */
    i7 = Simulation->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &ic_emlrtBCI, sp);
    }

    i7 = b_i + 1;
    if ((i7 < 1) || (i7 > backsType->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, backsType->size[1], &jc_emlrtBCI, sp);
    }

    st.site = &r_emlrtRSI;
    applyBackgroundCorrection(&st, b_sldProfile, Simulation->data[b_i].f1,
      shifted_dat, backs->data[(int32_T)cBacks->data[b_i] - 1], backsType->
      data[i7 - 1]);

    /*  Calculate chi squared. */
    i7 = b_i + 1;
    if ((i7 < 1) || (i7 > chis->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, chis->size[0], &kc_emlrtBCI, sp);
    }

    st.site = &s_emlrtRSI;
    chis->data[i7 - 1] = chiSquared(&st, shifted_dat, b_sldProfile, nParams);

    /*  Store relevant values for this contrast in output arrays  */
    loop_ub = sldProfile->size[0] * sldProfile->size[1];
    i7 = sldProfiles->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &lc_emlrtBCI, sp);
    }

    i7 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i7, &gh_emlrtRTEI);
    i7 = sldProfiles->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &lc_emlrtBCI, sp);
    }

    i7 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = sldProfile->size[1];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i7, &gh_emlrtRTEI);
    i7 = sldProfiles->size[0] - 1;
    i8 = sldProfiles->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &lc_emlrtBCI, sp);
    }

    i8 = sldProfiles->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &lc_emlrtBCI, sp);
    }

    for (i8 = 0; i8 < loop_ub; i8++) {
      if (b_i > i7) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &lc_emlrtBCI, sp);
      }

      sldProfiles->data[b_i].f1->data[i8] = sldProfile->data[i8];
    }

    loop_ub = b_sldProfile->size[0] * b_sldProfile->size[1];
    i7 = reflectivity->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &mc_emlrtBCI, sp);
    }

    i7 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = b_sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i7, &hh_emlrtRTEI);
    i7 = reflectivity->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &mc_emlrtBCI, sp);
    }

    i7 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i7, &hh_emlrtRTEI);
    i7 = reflectivity->size[0] - 1;
    i8 = reflectivity->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &mc_emlrtBCI, sp);
    }

    i8 = reflectivity->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &mc_emlrtBCI, sp);
    }

    for (i8 = 0; i8 < loop_ub; i8++) {
      if (b_i > i7) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &mc_emlrtBCI, sp);
      }

      reflectivity->data[b_i].f1->data[i8] = b_sldProfile->data[i8];
    }

    loop_ub = shifted_dat->size[0] * shifted_dat->size[1];
    i7 = shifted_data->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &nc_emlrtBCI, sp);
    }

    i7 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i7, &ih_emlrtRTEI);
    i7 = shifted_data->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &nc_emlrtBCI, sp);
    }

    i7 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i7, &ih_emlrtRTEI);
    i7 = shifted_data->size[0] - 1;
    i8 = shifted_data->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &nc_emlrtBCI, sp);
    }

    i8 = shifted_data->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &nc_emlrtBCI, sp);
    }

    for (i8 = 0; i8 < loop_ub; i8++) {
      if (b_i > i7) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &nc_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[i8] = shifted_dat->data[i8];
    }

    loop_ub = layerSld->size[0] * layerSld->size[1];
    i7 = layerSlds->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &oc_emlrtBCI, sp);
    }

    i7 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i7, &jh_emlrtRTEI);
    i7 = layerSlds->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &oc_emlrtBCI, sp);
    }

    i7 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i7, &jh_emlrtRTEI);
    i7 = layerSlds->size[0] - 1;
    i8 = layerSlds->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &oc_emlrtBCI, sp);
    }

    i8 = layerSlds->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &oc_emlrtBCI, sp);
    }

    for (i8 = 0; i8 < loop_ub; i8++) {
      if (b_i > i7) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &oc_emlrtBCI, sp);
      }

      layerSlds->data[b_i].f1->data[i8] = layerSld->data[i8];
    }

    i7 = b_i + 1;
    if ((i7 < 1) || (i7 > backgs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, backgs->size[0], &pc_emlrtBCI, sp);
    }

    backgs->data[i7 - 1] = backs->data[i1 - 1];
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > qshifts->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, qshifts->size[0], &qc_emlrtBCI, sp);
    }

    qshifts->data[i1 - 1] = shifts->data[i2 - 1];
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > sfs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, sfs->size[0], &rc_emlrtBCI, sp);
    }

    sfs->data[i1 - 1] = sf->data[i3 - 1];
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbas->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbas->size[0], &sc_emlrtBCI, sp);
    }

    nbas->data[i1 - 1] = nba->data[i4 - 1];
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbss->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &tc_emlrtBCI, sp);
    }

    nbss->data[i1 - 1] = nbs->data[i5 - 1];
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > resols->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, resols->size[0], &uc_emlrtBCI, sp);
    }

    resols->data[i1 - 1] = res->data[i6 - 1];
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > allRoughs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, allRoughs->size[0], &vc_emlrtBCI, sp);
    }

    allRoughs->data[i1 - 1] = params->data[0];
  }

  emxFree_real_T(&b_sldProfile);
  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&layerSld);
  emxFree_real_T(&sldProfile);
  emxFree_real_T(&thisContrastLayers);
  emxFree_cell_wrap_16(&outParameterisedLayers);
  covrtLogFor(&emlrtCoverageInstance, 4U, 0U, 3, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_stanlay_single.c) */
