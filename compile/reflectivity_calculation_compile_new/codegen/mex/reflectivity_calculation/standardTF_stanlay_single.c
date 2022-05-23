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
#include "backSort.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo o_emlrtRSI = { 65,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 77,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 82,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 102, /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 46,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 51,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 56,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 71,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtBCInfo kc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  24,                                  /* colNo */
  "params",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  29,                                  /* colNo */
  "resample",                          /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  91,                                  /* lineNo */
  35,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  94,                                  /* lineNo */
  31,                                  /* colNo */
  "backsType",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  37,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  24,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  33,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  31,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  18,                                  /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  16,                                  /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  15,                                  /* colNo */
  "allLayers",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  17,                                  /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  116,                                 /* lineNo */
  18,                                  /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  126,                                 /* lineNo */
  15,                                  /* colNo */
  "allLayers",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = { 33,  /* lineNo */
  17,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = { 32,  /* lineNo */
  16,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo s_emlrtDCI = { 32,  /* lineNo */
  16,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  77,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  87,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  98,                                  /* colNo */
  "cScales",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  109,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  118,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  127,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  52,                                  /* colNo */
  "contrastLayers",                    /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  114,                                 /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  115,                                 /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  117,                                 /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  118,                                 /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  112,                                 /* lineNo */
  5,                                   /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo md_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  116,                                 /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo od_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  119,                                 /* lineNo */
  5,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  120,                                 /* lineNo */
  5,                                   /* colNo */
  "qshifts",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  121,                                 /* lineNo */
  5,                                   /* colNo */
  "sfs",                               /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  122,                                 /* lineNo */
  5,                                   /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  123,                                 /* lineNo */
  5,                                   /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  124,                                 /* lineNo */
  5,                                   /* colNo */
  "resols",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  125,                                 /* lineNo */
  5,                                   /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  126,                                 /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo tg_emlrtRTEI = { 32,/* lineNo */
  10,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo ug_emlrtRTEI = { 29,/* lineNo */
  11,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo vg_emlrtRTEI = { 47,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo wg_emlrtRTEI = { 52,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo xg_emlrtRTEI = { 57,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo yg_emlrtRTEI = { 39,/* lineNo */
  12,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo ah_emlrtRTEI = { 113,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo bh_emlrtRTEI = { 116,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo ch_emlrtRTEI = { 126,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo dh_emlrtRTEI = { 65,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo eh_emlrtRTEI = { 82,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo fh_emlrtRTEI = { 4,/* lineNo */
  18,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

/* Function Definitions */
void standardTF_stanlay_single(const emlrtStack *sp, const struct0_T *problemDef,
  const cell_16 *problemDef_cells, const struct2_T *controls, emxArray_real_T
  *outSsubs, emxArray_real_T *backgs, emxArray_real_T *qshifts, emxArray_real_T *
  sfs, emxArray_real_T *nbas, emxArray_real_T *nbss, emxArray_real_T *resols,
  emxArray_real_T *chis, emxArray_cell_wrap_9 *reflectivity,
  emxArray_cell_wrap_9 *Simulation, emxArray_cell_wrap_14 *shifted_data,
  emxArray_cell_wrap_10 *layerSlds, emxArray_cell_wrap_14 *sldProfiles,
  emxArray_cell_wrap_14 *allLayers, emxArray_real_T *allRoughs)
{
  emlrtStack st;
  emxArray_cell_wrap_17 *outParameterisedLayers;
  emxArray_real_T *resampledLayers;
  emxArray_real_T *shifted_dat;
  emxArray_real_T *sldProfile;
  emxArray_real_T *thisContrastLayers;
  real_T thisBackground;
  real_T thisNba;
  real_T thisNbs;
  real_T thisQshift;
  real_T thisResol;
  real_T thisSf;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  Single theraded version of the Standard Layers calculation  */
  /*  This is the main reflectivity calculation of the standard layers */
  /*  calculation type. It extracts the required paramters for the contrasts */
  /*  from the input arrays, then passes the main calculation to */
  /*  'standardLayersCore', which carries out the calculation iteslf.  */
  /*  The core calculation is common for both standard and custom layers. */
  /*  Extract individual cell arrays */
  /*  Splits up the master input list of all arrays into separate arrays */
  /*  The min input array 'problemDef_cells' is a master array where */
  /*  all the cell arrays are grouped together. There are */
  /*  repeatLayers      - controls repeating of the layers stack */
  /*  allData           - Array of all the data arrays */
  /*  dataLimits        - Min max limits in q for the data arrays */
  /*  simLimits         - Limits in Q for the reflkectivity simulations */
  /*  Layers details    - Master array of all available layers */
  /*  contrastLayers    - Which specific combination of arrays are needed for */
  /*                      each contrast. */
  /*  Custom files      - Filenames and path for any custom files used */
  /*  Extract individual parameters from problemDef struct */
  /* Extract individual parameters from problemDef */
  /*  Allocate the memory for the output arrays before the main loop */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &s_emlrtDCI, sp);
  }

  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &r_emlrtDCI, sp);
  }

  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &tg_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &q_emlrtDCI, sp);
  }

  i = (int32_T)problemDef->numberOfContrasts;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &bb_emlrtRTEI, sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = i;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i1, &ug_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &sc_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &vg_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &sc_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &vg_emlrtRTEI);
    i1 = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &sc_emlrtBCI, sp);
    }

    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &sc_emlrtBCI, sp);
    }

    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &wd_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &wd_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &wd_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &wd_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &cb_emlrtRTEI, sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = i;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i1, &ug_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &tc_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &wg_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &tc_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &wg_emlrtRTEI);
    i1 = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &tc_emlrtBCI, sp);
    }

    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &tc_emlrtBCI, sp);
    }

    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &xd_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &xd_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &xd_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &xd_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &db_emlrtRTEI, sp);
  i1 = allLayers->size[0];
  allLayers->size[0] = i;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i1, &ug_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &uc_emlrtBCI,
        sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &xg_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &uc_emlrtBCI,
        sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &xg_emlrtRTEI);
    i1 = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &uc_emlrtBCI,
        sp);
    }

    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &uc_emlrtBCI,
        sp);
    }

    for (i2 = 0; i2 < 6; i2++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &yc_emlrtBCI, sp);
      }

      allLayers->data[b_i].f1->data[i2] = 1.0;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxInit_cell_wrap_17(sp, &outParameterisedLayers, 2, &dh_emlrtRTEI, true);

  /*  end memory allocation. */
  /*  First we need to allocate the absolute values of the input */
  /*  parameters to all the layers in the layers list. This only needs */
  /*  to be done once, and so is done outside the contrasts loop */
  st.site = &o_emlrtRSI;
  allocateParamsToLayers(&st, problemDef->params, problemDef_cells->f6,
    outParameterisedLayers);

  /*  Resample params if requiired */
  /*  Loop over all the contrasts */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &eb_emlrtRTEI, sp);
  i1 = outSsubs->size[0];
  outSsubs->size[0] = i;
  emxEnsureCapacity_real_T(sp, outSsubs, i1, &yg_emlrtRTEI);
  i1 = sldProfiles->size[0];
  sldProfiles->size[0] = i;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i1, &ug_emlrtRTEI);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = i;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i1, &ug_emlrtRTEI);
  i1 = Simulation->size[0];
  Simulation->size[0] = i;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i1, &ug_emlrtRTEI);
  i1 = shifted_data->size[0];
  shifted_data->size[0] = i;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i1, &ug_emlrtRTEI);
  i1 = layerSlds->size[0];
  layerSlds->size[0] = i;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i1, &ug_emlrtRTEI);
  i1 = chis->size[0];
  chis->size[0] = i;
  emxEnsureCapacity_real_T(sp, chis, i1, &yg_emlrtRTEI);
  i1 = qshifts->size[0];
  qshifts->size[0] = i;
  emxEnsureCapacity_real_T(sp, qshifts, i1, &yg_emlrtRTEI);
  i1 = sfs->size[0];
  sfs->size[0] = i;
  emxEnsureCapacity_real_T(sp, sfs, i1, &yg_emlrtRTEI);
  i1 = nbas->size[0];
  nbas->size[0] = i;
  emxEnsureCapacity_real_T(sp, nbas, i1, &yg_emlrtRTEI);
  i1 = nbss->size[0];
  nbss->size[0] = i;
  emxEnsureCapacity_real_T(sp, nbss, i1, &yg_emlrtRTEI);
  i1 = resols->size[0];
  resols->size[0] = i;
  emxEnsureCapacity_real_T(sp, resols, i1, &yg_emlrtRTEI);
  i1 = allRoughs->size[0];
  allRoughs->size[0] = i;
  emxEnsureCapacity_real_T(sp, allRoughs, i1, &yg_emlrtRTEI);
  i1 = allLayers->size[0];
  allLayers->size[0] = i;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i1, &ug_emlrtRTEI);
  emxInit_real_T(sp, &thisContrastLayers, 2, &eh_emlrtRTEI, true);
  emxInit_real_T(sp, &sldProfile, 2, &fh_emlrtRTEI, true);
  emxInit_real_T(sp, &shifted_dat, 2, &fh_emlrtRTEI, true);
  emxInit_real_T(sp, &resampledLayers, 2, &fh_emlrtRTEI, true);
  for (b_i = 0; b_i < i; b_i++) {
    /*  Extract the relevant parameter values for this contrast */
    /*  from the input arrays. */
    /*  First need to decide which values of the backrounds, scalefactors */
    /*  data shifts and bulk contrasts are associated with this contrast */
    if ((int32_T)(b_i + 1U) > problemDef->contrastBacks->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastBacks->size[1], &ad_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > problemDef->contrastShifts->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastShifts->size[1], &bd_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > problemDef->contrastScales->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastScales->size[1], &cd_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > problemDef->contrastNbas->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastNbas->size[1], &dd_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > problemDef->contrastNbss->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastNbss->size[1], &ed_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > problemDef->contrastRes->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastRes->size[1], &fd_emlrtBCI, sp);
    }

    st.site = &p_emlrtRSI;
    backSort(&st, problemDef->contrastBacks->data[b_i],
             problemDef->contrastShifts->data[b_i], problemDef->
             contrastScales->data[b_i], problemDef->contrastNbas->data[b_i],
             problemDef->contrastNbss->data[b_i], problemDef->contrastRes->
             data[b_i], problemDef->backs, problemDef->shifts, problemDef->sf,
             problemDef->nba, problemDef->nbs, problemDef->res, &thisBackground,
             &thisQshift, &thisSf, &thisNba, &thisNbs, &thisResol);

    /*  Also need to determine which layers from the overall layers list */
    /*  are required for this contrast, and put them in the correct order  */
    /*  according to geometry */
    if (b_i > problemDef_cells->f5->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f5->size[1] - 1,
        &gd_emlrtBCI, sp);
    }

    st.site = &q_emlrtRSI;
    allocateLayersForContrast(&st, problemDef_cells->f5->data[b_i].f1,
      outParameterisedLayers, thisContrastLayers);

    /*  For the other parameters, we extract the correct ones from the input */
    /*  arrays */
    if (1 > problemDef->params->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, problemDef->params->size[1],
        &kc_emlrtBCI, sp);
    }

    /*  Substrate roughness is always first parameter for standard layers */
    if (b_i > problemDef_cells->f1->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f1->size[1] - 1,
        &oc_emlrtBCI, sp);
    }

    i1 = b_i + 1;
    if (i1 > problemDef->resample->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, problemDef->resample->size[1],
        &lc_emlrtBCI, sp);
    }

    if (b_i > problemDef_cells->f2->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f2->size[1] - 1,
        &pc_emlrtBCI, sp);
    }

    if (i1 > problemDef->dataPresent->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, problemDef->dataPresent->size[1],
        &mc_emlrtBCI, sp);
    }

    if (b_i > problemDef_cells->f3->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f3->size[1] - 1,
        &qc_emlrtBCI, sp);
    }

    if (b_i > problemDef_cells->f4->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f4->size[1] - 1,
        &rc_emlrtBCI, sp);
    }

    if (i1 > problemDef->contrastBacksType->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, problemDef->contrastBacksType->size[1],
        &nc_emlrtBCI, sp);
    }

    /*  Now call the core standardTF_stanlay reflectivity calculation */
    /*  In this case we are single cored, so we do not parallelise over */
    /*  points */
    /*  Call the core layers calculation */
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &hd_emlrtBCI, sp);
    }

    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &id_emlrtBCI, sp);
    }

    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &jd_emlrtBCI,
        sp);
    }

    if (b_i + 1 > chis->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, chis->size[0], &kd_emlrtBCI, sp);
    }

    if (b_i + 1 > outSsubs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, outSsubs->size[0], &ld_emlrtBCI,
        sp);
    }

    st.site = &r_emlrtRSI;
    standardTF_layers_core(&st, thisContrastLayers, problemDef->params->data[0],
      problemDef->geometry, thisNba, thisNbs, problemDef->resample->data[b_i],
      controls->calcSld, thisSf, thisQshift, problemDef->dataPresent->data[b_i],
      problemDef_cells->f2->data[b_i].f1, problemDef_cells->f3->data[b_i].f1,
      (real_T *)problemDef_cells->f4->data[b_i].f1->data, problemDef_cells->
      f4->data[b_i].f1->size, problemDef_cells->f1->data[b_i].f1, thisBackground,
      thisResol, problemDef->contrastBacksType->data[b_i], problemDef->
      params->size[1], controls->resamPars, sldProfile, reflectivity->data[b_i].
      f1, Simulation->data[b_i].f1, shifted_dat, layerSlds->data[b_i].f1,
      resampledLayers, &chis->data[b_i], &outSsubs->data[b_i]);

    /*  Store returned values for this contrast in the output arrays. */
    /*  As well as the calculated profiles, we also store a record of  */
    /*  the other values (background, scalefactors etc) for each contrast */
    /*  for future use. */
    loop_ub = sldProfile->size[0] * sldProfile->size[1];
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &vc_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &ah_emlrtRTEI);
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &vc_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &ah_emlrtRTEI);
    i1 = sldProfiles->size[0];
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &vc_emlrtBCI, sp);
    }

    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &vc_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &md_emlrtBCI, sp);
      }

      sldProfiles->data[b_i].f1->data[i2] = sldProfile->data[i2];
    }

    loop_ub = shifted_dat->size[0] * shifted_dat->size[1];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &wc_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i1, &bh_emlrtRTEI);
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &wc_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[1] = shifted_dat->size[1];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i1, &bh_emlrtRTEI);
    i1 = shifted_data->size[0];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &wc_emlrtBCI, sp);
    }

    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &wc_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &nd_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[i2] = shifted_dat->data[i2];
    }

    if (b_i + 1 > backgs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, backgs->size[0], &od_emlrtBCI,
        sp);
    }

    backgs->data[b_i] = thisBackground;
    if (b_i + 1 > qshifts->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, qshifts->size[0], &pd_emlrtBCI,
        sp);
    }

    qshifts->data[b_i] = thisQshift;
    if (b_i + 1 > sfs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, sfs->size[0], &qd_emlrtBCI, sp);
    }

    sfs->data[b_i] = thisSf;
    if (b_i + 1 > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbas->size[0], &rd_emlrtBCI, sp);
    }

    nbas->data[b_i] = thisNba;
    if (b_i + 1 > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbss->size[0], &sd_emlrtBCI, sp);
    }

    nbss->data[b_i] = thisNbs;
    if (b_i + 1 > resols->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, resols->size[0], &td_emlrtBCI,
        sp);
    }

    resols->data[b_i] = thisResol;
    if (b_i + 1 > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, allRoughs->size[0], &ud_emlrtBCI,
        sp);
    }

    allRoughs->data[b_i] = problemDef->params->data[0];
    loop_ub = resampledLayers->size[0] * resampledLayers->size[1];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &xc_emlrtBCI,
        sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = resampledLayers->size[0];
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &ch_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &xc_emlrtBCI,
        sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &ch_emlrtRTEI);
    i1 = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &xc_emlrtBCI,
        sp);
    }

    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &xc_emlrtBCI,
        sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &vd_emlrtBCI, sp);
      }

      allLayers->data[b_i].f1->data[i2] = resampledLayers->data[i2];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&resampledLayers);
  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&sldProfile);
  emxFree_real_T(&thisContrastLayers);
  emxFree_cell_wrap_17(&outParameterisedLayers);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_stanlay_single.c) */
