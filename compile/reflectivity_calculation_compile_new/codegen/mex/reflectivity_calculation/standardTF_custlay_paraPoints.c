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
#include "backSort.h"
#include "callReflectivity.h"
#include "call_customLayers.h"
#include "chiSquared.h"
#include "groupLayers_Mod.h"
#include "makeSLDProfiles.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo lh_emlrtRSI = { 70, /* lineNo */
  "standardTF_custlay_paraPoints",     /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo mh_emlrtRSI = { 74, /* lineNo */
  "standardTF_custlay_paraPoints",     /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo nh_emlrtRSI = { 96, /* lineNo */
  "standardTF_custlay_paraPoints",     /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pathName */
};

static emlrtRTEInfo rc_emlrtRTEI = { 46,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = { 51,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo tc_emlrtRTEI = { 56,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo uc_emlrtRTEI = { 65,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtDCInfo lc_emlrtDCI = { 73, /* lineNo */
  34,                                  /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo wo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  27,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  29,                                  /* colNo */
  "resample",                          /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  35,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ap_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  31,                                  /* colNo */
  "backsType",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  34,                                  /* colNo */
  "customFiles",                       /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  37,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  24,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ep_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  33,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  31,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  18,                                  /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  16,                                  /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ip_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  15,                                  /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  15,                                  /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  17,                                  /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  18,                                  /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  16,                                  /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo np_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  18,                                  /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo op_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  112,                                 /* lineNo */
  15,                                  /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  15,                                  /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo mc_emlrtDCI = { 32, /* lineNo */
  17,                                  /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo nc_emlrtDCI = { 31, /* lineNo */
  16,                                  /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo oc_emlrtDCI = { 31, /* lineNo */
  16,                                  /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo qp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  77,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  87,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  98,                                  /* colNo */
  "cScales",                           /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  109,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo up_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  118,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  127,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  34,                                  /* colNo */
  "cCustFiles",                        /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  16,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yp_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo aq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  107,                                 /* lineNo */
  5,                                   /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  115,                                 /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  112,                                 /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo iq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  116,                                 /* lineNo */
  5,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  117,                                 /* lineNo */
  5,                                   /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  118,                                 /* lineNo */
  5,                                   /* colNo */
  "sfs",                               /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  119,                                 /* lineNo */
  5,                                   /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  120,                                 /* lineNo */
  5,                                   /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  121,                                 /* lineNo */
  5,                                   /* colNo */
  "resols",                            /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  122,                                 /* lineNo */
  5,                                   /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo so_emlrtRTEI = { 31,/* lineNo */
  10,                                  /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo to_emlrtRTEI = { 27,/* lineNo */
  11,                                  /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo uo_emlrtRTEI = { 47,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo vo_emlrtRTEI = { 52,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo wo_emlrtRTEI = { 57,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo xo_emlrtRTEI = { 37,/* lineNo */
  13,                                  /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo yo_emlrtRTEI = { 75,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo ap_emlrtRTEI = { 84,/* lineNo */
  16,                                  /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo bp_emlrtRTEI = { 108,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo cp_emlrtRTEI = { 109,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo dp_emlrtRTEI = { 110,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo ep_emlrtRTEI = { 111,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo fp_emlrtRTEI = { 112,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo gp_emlrtRTEI = { 113,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo hp_emlrtRTEI = { 3,/* lineNo */
  18,                                  /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

/* Function Definitions */
void standardTF_custlay_paraPoints(const emlrtStack *sp, const struct0_T
  *problemDef, const cell_16 *problemDef_cells, const struct2_T *controls,
  emxArray_real_T *outSsubs, emxArray_real_T *backgs, emxArray_real_T *qshifts,
  emxArray_real_T *sfs, emxArray_real_T *nbas, emxArray_real_T *nbss,
  emxArray_real_T *resols, emxArray_real_T *chis, emxArray_cell_wrap_9
  *reflectivity, emxArray_cell_wrap_9 *Simulation, emxArray_cell_wrap_14
  *shifted_data, emxArray_cell_wrap_10 *layerSlds, emxArray_cell_wrap_14
  *sldProfiles, emxArray_cell_wrap_14 *allLayers, emxArray_real_T *allRoughs)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T *Simul;
  emxArray_real_T *b_problemDef_cells;
  emxArray_real_T *b_shifted_dat;
  emxArray_real_T *layerSld;
  emxArray_real_T *outLayers;
  emxArray_real_T *reflect;
  emxArray_real_T *resamLayers;
  emxArray_real_T *shifted_dat;
  emxArray_real_T *sldProfile;
  emxArray_real_T *theseLayers;
  real_T b_calcSld;
  real_T calcSld;
  real_T ssubs;
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
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  Multi threaded version of the custom layers over reflectivity poimnts */
  /*  for standardTF reflectivity calculation.  */
  /*  The function extracts the relevant parameters from the input */
  /*  arrays, allocates these on a pre-contrast basis, then calls the 'core'  */
  /*  calculation (the core layers standardTf calc is shared between multiple */
  /*  calculation types). */
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
  calcSld = controls->calcSld;

  /*  Pre-Allocation of output arrays... */
  /*    --- Begin Memory Allocation --- */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &oc_emlrtDCI, sp);
  }

  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &nc_emlrtDCI, sp);
  }

  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &so_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &mc_emlrtDCI, sp);
  }

  i = (int32_T)problemDef->numberOfContrasts;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &rc_emlrtRTEI, sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = i;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i1, &to_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &gp_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &uo_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &gp_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &uo_emlrtRTEI);
    i1 = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &gp_emlrtBCI, sp);
    }

    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &gp_emlrtBCI, sp);
    }

    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &pq_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &pq_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &pq_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &pq_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &sc_emlrtRTEI, sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = i;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i1, &to_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &hp_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &vo_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &hp_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &vo_emlrtRTEI);
    i1 = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &hp_emlrtBCI, sp);
    }

    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &hp_emlrtBCI, sp);
    }

    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &qq_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &qq_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &qq_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &qq_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &tc_emlrtRTEI, sp);
  i1 = allLayers->size[0];
  allLayers->size[0] = i;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i1, &to_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &ip_emlrtBCI,
        sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &wo_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &ip_emlrtBCI,
        sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &wo_emlrtRTEI);
    i1 = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &ip_emlrtBCI,
        sp);
    }

    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &ip_emlrtBCI,
        sp);
    }

    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &rq_emlrtBCI,
        sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &rq_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*    --- End Memory Allocation --- */
  /*  Single cored over all contrasts */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &uc_emlrtRTEI, sp);
  i1 = allRoughs->size[0];
  allRoughs->size[0] = i;
  emxEnsureCapacity_real_T(sp, allRoughs, i1, &xo_emlrtRTEI);
  i1 = allLayers->size[0];
  allLayers->size[0] = i;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i1, &to_emlrtRTEI);
  i1 = outSsubs->size[0];
  outSsubs->size[0] = i;
  emxEnsureCapacity_real_T(sp, outSsubs, i1, &xo_emlrtRTEI);
  i1 = sldProfiles->size[0];
  sldProfiles->size[0] = i;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i1, &to_emlrtRTEI);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = i;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i1, &to_emlrtRTEI);
  i1 = Simulation->size[0];
  Simulation->size[0] = i;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i1, &to_emlrtRTEI);
  i1 = shifted_data->size[0];
  shifted_data->size[0] = i;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i1, &to_emlrtRTEI);
  i1 = layerSlds->size[0];
  layerSlds->size[0] = i;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i1, &to_emlrtRTEI);
  i1 = chis->size[0];
  chis->size[0] = i;
  emxEnsureCapacity_real_T(sp, chis, i1, &xo_emlrtRTEI);
  i1 = qshifts->size[0];
  qshifts->size[0] = i;
  emxEnsureCapacity_real_T(sp, qshifts, i1, &xo_emlrtRTEI);
  i1 = sfs->size[0];
  sfs->size[0] = i;
  emxEnsureCapacity_real_T(sp, sfs, i1, &xo_emlrtRTEI);
  i1 = nbas->size[0];
  nbas->size[0] = i;
  emxEnsureCapacity_real_T(sp, nbas, i1, &xo_emlrtRTEI);
  i1 = nbss->size[0];
  nbss->size[0] = i;
  emxEnsureCapacity_real_T(sp, nbss, i1, &xo_emlrtRTEI);
  i1 = resols->size[0];
  resols->size[0] = i;
  emxEnsureCapacity_real_T(sp, resols, i1, &xo_emlrtRTEI);
  emxInit_real_T(sp, &outLayers, 2, &hp_emlrtRTEI, true);
  emxInit_real_T(sp, &sldProfile, 2, &hp_emlrtRTEI, true);
  emxInit_real_T(sp, &shifted_dat, 2, &hp_emlrtRTEI, true);
  emxInit_real_T(sp, &resamLayers, 2, &hp_emlrtRTEI, true);
  emxInit_real_T(sp, &layerSld, 2, &sh_emlrtRTEI, true);
  emxInit_real_T(sp, &theseLayers, 2, &hp_emlrtRTEI, true);
  emxInit_real_T(sp, &reflect, 2, &hp_emlrtRTEI, true);
  emxInit_real_T(sp, &Simul, 2, &hp_emlrtRTEI, true);
  emxInit_real_T(sp, &b_shifted_dat, 1, &qh_emlrtRTEI, true);
  emxInit_real_T(sp, &b_problemDef_cells, 2, &ap_emlrtRTEI, true);
  for (b_i = 0; b_i < i; b_i++) {
    /*  Extract the relevant parameter values for this contrast */
    /*  from the input arrays. */
    /*  First need to decide which values of the backrounds, scalefactors */
    /*  data shifts and bulk contrasts are associated with this contrast */
    if ((int32_T)(b_i + 1U) > problemDef->contrastBacks->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastBacks->size[1], &qp_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > problemDef->contrastShifts->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastShifts->size[1], &rp_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > problemDef->contrastScales->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastScales->size[1], &sp_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > problemDef->contrastNbas->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastNbas->size[1], &tp_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > problemDef->contrastNbss->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastNbss->size[1], &up_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > problemDef->contrastRes->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastRes->size[1], &vp_emlrtBCI, sp);
    }

    st.site = &lh_emlrtRSI;
    backSort(&st, problemDef->contrastBacks->data[b_i],
             problemDef->contrastShifts->data[b_i], problemDef->
             contrastScales->data[b_i], problemDef->contrastNbas->data[b_i],
             problemDef->contrastNbss->data[b_i], problemDef->contrastRes->
             data[b_i], problemDef->backs, problemDef->shifts, problemDef->sf,
             problemDef->nba, problemDef->nbs, problemDef->res, &thisBackground,
             &thisQshift, &thisSf, &thisNba, &thisNbs, &thisResol);

    /*  Call the custom layers function to get the layers array... */
    if ((int32_T)(b_i + 1U) > problemDef->contrastCustomFiles->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastCustomFiles->size[1], &wp_emlrtBCI, sp);
    }

    b_calcSld = problemDef->contrastCustomFiles->data[b_i];
    if (b_calcSld != (int32_T)muDoubleScalarFloor(b_calcSld)) {
      emlrtIntegerCheckR2012b(b_calcSld, &lc_emlrtDCI, sp);
    }

    if (((int32_T)b_calcSld - 1 < 0) || ((int32_T)b_calcSld - 1 >
         problemDef_cells->f14->size[1] - 1)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b_calcSld - 1, 0,
        problemDef_cells->f14->size[1] - 1, &bp_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, allRoughs->size[0],
        &xp_emlrtBCI, sp);
    }

    st.site = &mh_emlrtRSI;
    call_customLayers(&st, problemDef->params, (real_T)b_i + 1.0,
                      problemDef_cells->f14->data[(int32_T)
                      problemDef->contrastCustomFiles->data[b_i] - 1].f1,
                      thisNba, thisNbs, problemDef->numberOfContrasts, outLayers,
                      &allRoughs->data[b_i]);
    loop_ub = outLayers->size[0] * outLayers->size[1];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &jp_emlrtBCI,
        sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = outLayers->size[0];
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &yo_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &jp_emlrtBCI,
        sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = outLayers->size[1];
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &yo_emlrtRTEI);
    i1 = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &jp_emlrtBCI,
        sp);
    }

    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &jp_emlrtBCI,
        sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &yp_emlrtBCI, sp);
      }

      allLayers->data[b_i].f1->data[i2] = outLayers->data[i2];
    }

    /*  For the other parameters, we extract the correct ones from the input */
    /*  arrays */
    i1 = b_i + 1;
    if (i1 > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, allRoughs->size[0], &wo_emlrtBCI, sp);
    }

    if (b_i > problemDef_cells->f1->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f1->size[1] - 1,
        &cp_emlrtBCI, sp);
    }

    if (i1 > problemDef->resample->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, problemDef->resample->size[1],
        &xo_emlrtBCI, sp);
    }

    if (b_i > problemDef_cells->f2->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f2->size[1] - 1,
        &dp_emlrtBCI, sp);
    }

    if (i1 > problemDef->dataPresent->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, problemDef->dataPresent->size[1],
        &yo_emlrtBCI, sp);
    }

    if (b_i > problemDef_cells->f3->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f3->size[1] - 1,
        &ep_emlrtBCI, sp);
    }

    if (b_i > problemDef_cells->f4->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f4->size[1] - 1,
        &fp_emlrtBCI, sp);
    }

    if (i1 > problemDef->contrastBacksType->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, problemDef->contrastBacksType->size[1],
        &ap_emlrtBCI, sp);
    }

    /*  Now call the core standardTF_stanlay reflectivity calculation */
    /*  In this case we are single cored, so we do not parallelise over */
    /*  points */
    /*  Call the reflectivity calculation */
    st.site = &nh_emlrtRSI;
    b_calcSld = calcSld;

    /*    This is the main reflectivity calculation for all Layers models in the  */
    /*    standard target function.  */
    /*  */
    /*    The function first arranges the  */
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
    b_st.site = &w_emlrtRSI;
    b_groupLayers_Mod(&b_st, outLayers, allRoughs->data[b_i],
                      problemDef->geometry, thisNba, thisNbs, theseLayers,
                      &ssubs);
    if (b_i + 1 > outSsubs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, outSsubs->size[0], &aq_emlrtBCI,
        &st);
    }

    outSsubs->data[b_i] = ssubs;

    /*  Make the SLD profiles. */
    /*  If resampling is needed, then enforce the calcSLD flag, so as to catch */
    /*  the error af trying to resample a non-existent profile. */
    if ((problemDef->resample->data[b_i] == 1.0) && (calcSld == 0.0)) {
      b_calcSld = 1.0;
    }

    /*  If calc SLD flag is set, then calculate the SLD profile */
    if (b_calcSld == 1.0) {
      b_st.site = &x_emlrtRSI;
      makeSLDProfiles(&b_st, thisNba, thisNbs, theseLayers, ssubs,
                      problemDef_cells->f1->data[b_i].f1, sldProfile);
    } else {
      i1 = sldProfile->size[0] * sldProfile->size[1];
      sldProfile->size[0] = 1;
      sldProfile->size[1] = 2;
      emxEnsureCapacity_real_T(&st, sldProfile, i1, &kh_emlrtRTEI);
      sldProfile->data[0] = 0.0;
      sldProfile->data[1] = 0.0;
    }

    /*  If required, then resample the SLD */
    if (problemDef->resample->data[b_i] == 1.0) {
      b_st.site = &y_emlrtRSI;
      resampleLayers(&b_st, sldProfile, controls->resamPars, layerSld);
      i1 = resamLayers->size[0] * resamLayers->size[1];
      resamLayers->size[0] = layerSld->size[0];
      resamLayers->size[1] = 3;
      emxEnsureCapacity_real_T(&st, resamLayers, i1, &mh_emlrtRTEI);
      loop_ub = layerSld->size[0] * layerSld->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        resamLayers->data[i1] = layerSld->data[i1];
      }
    } else {
      i1 = layerSld->size[0] * layerSld->size[1];
      layerSld->size[0] = theseLayers->size[0];
      layerSld->size[1] = 3;
      emxEnsureCapacity_real_T(&st, layerSld, i1, &lh_emlrtRTEI);
      loop_ub = theseLayers->size[0] * theseLayers->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        layerSld->data[i1] = theseLayers->data[i1];
      }

      i1 = resamLayers->size[0] * resamLayers->size[1];
      resamLayers->size[0] = 1;
      resamLayers->size[1] = 3;
      emxEnsureCapacity_real_T(&st, resamLayers, i1, &nh_emlrtRTEI);
      resamLayers->data[0] = 0.0;
      resamLayers->data[1] = 0.0;
      resamLayers->data[2] = 0.0;
    }

    /*  Apply scale factors and q shifts to the data */
    i1 = b_problemDef_cells->size[0] * b_problemDef_cells->size[1];
    b_problemDef_cells->size[0] = problemDef_cells->f2->data[b_i].f1->size[0];
    b_problemDef_cells->size[1] = problemDef_cells->f2->data[b_i].f1->size[1];
    emxEnsureCapacity_real_T(&st, b_problemDef_cells, i1, &ap_emlrtRTEI);
    loop_ub = problemDef_cells->f2->data[b_i].f1->size[0] * problemDef_cells->
      f2->data[b_i].f1->size[1] - 1;
    for (i1 = 0; i1 <= loop_ub; i1++) {
      b_problemDef_cells->data[i1] = problemDef_cells->f2->data[b_i].f1->data[i1];
    }

    b_st.site = &ab_emlrtRSI;
    shiftdata(&b_st, thisSf, thisQshift, problemDef->dataPresent->data[b_i],
              b_problemDef_cells, problemDef_cells->f3->data[b_i].f1, (real_T *)
              problemDef_cells->f4->data[b_i].f1->data, problemDef_cells->
              f4->data[b_i].f1->size, shifted_dat);

    /*  Calculate the reflectivity */
    b_st.site = &bb_emlrtRSI;
    b_callReflectivity(&b_st, thisNba, thisNbs, (real_T *)problemDef_cells->
                       f4->data[b_i].f1->data, problemDef_cells->f4->data[b_i].
                       f1->size, problemDef_cells->f1->data[b_i].f1, shifted_dat,
                       layerSld, ssubs, thisResol, reflect, Simul);

    /*  Apply background correction, either to the simulation or the data */
    b_st.site = &cb_emlrtRSI;
    if (problemDef->contrastBacksType->data[b_i] != (int32_T)muDoubleScalarFloor
        (problemDef->contrastBacksType->data[b_i])) {
      emlrtIntegerCheckR2012b(problemDef->contrastBacksType->data[b_i],
        &cb_emlrtDCI, &b_st);
    }

    switch ((int32_T)problemDef->contrastBacksType->data[b_i]) {
     case 1:
      /* Add background to the simulation */
      loop_ub = reflect->size[0] * reflect->size[1];
      i1 = reflect->size[0] * reflect->size[1];
      reflect->size[1] = 2;
      emxEnsureCapacity_real_T(&b_st, reflect, i1, &ph_emlrtRTEI);
      for (i1 = 0; i1 < loop_ub; i1++) {
        reflect->data[i1] += thisBackground;
      }

      loop_ub = Simul->size[0] * Simul->size[1];
      i1 = Simul->size[0] * Simul->size[1];
      Simul->size[1] = 2;
      emxEnsureCapacity_real_T(&b_st, Simul, i1, &rh_emlrtRTEI);
      for (i1 = 0; i1 < loop_ub; i1++) {
        Simul->data[i1] += thisBackground;
      }
      break;

     case 2:
      /*          %Subtract the background from the data.. */
      if (2 > shifted_dat->size[1]) {
        emlrtDynamicBoundsCheckR2012b(2, 1, shifted_dat->size[1], &re_emlrtBCI,
          &b_st);
      }

      emlrtSubAssignSizeCheckR2012b(&shifted_dat->size[0], 1, &shifted_dat->
        size[0], 1, &emlrtECI, &b_st);
      loop_ub = shifted_dat->size[0] - 1;
      i1 = b_shifted_dat->size[0];
      b_shifted_dat->size[0] = shifted_dat->size[0];
      emxEnsureCapacity_real_T(&b_st, b_shifted_dat, i1, &qh_emlrtRTEI);
      for (i1 = 0; i1 <= loop_ub; i1++) {
        b_shifted_dat->data[i1] = shifted_dat->data[i1 + shifted_dat->size[0]] -
          thisBackground;
      }

      loop_ub = b_shifted_dat->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        shifted_dat->data[i1 + shifted_dat->size[0]] = b_shifted_dat->data[i1];
      }

      /* shifted_dat(:,3) = shifted_dat(:,3) - backg;    */
      break;
    }

    /*  Calculate chi squared. */
    if (b_i + 1 > chis->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, chis->size[0], &bq_emlrtBCI, &st);
    }

    b_st.site = &db_emlrtRSI;
    chis->data[b_i] = chiSquared(&b_st, shifted_dat, reflect, problemDef->
      params->size[1]);

    /*  Store returned values for this contrast in the output arrays. */
    /*  As well as the calculated profiles, we also store a record of  */
    /*  the other values (background, scalefactors etc) for each contrast */
    /*  for future use. */
    loop_ub = sldProfile->size[0] * sldProfile->size[1];
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &kp_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &bp_emlrtRTEI);
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &kp_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &bp_emlrtRTEI);
    i1 = sldProfiles->size[0];
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &kp_emlrtBCI, sp);
    }

    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &kp_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &cq_emlrtBCI, sp);
      }

      sldProfiles->data[b_i].f1->data[i2] = sldProfile->data[i2];
    }

    loop_ub = reflect->size[0] * reflect->size[1];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &lp_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = reflect->size[0];
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &cp_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &lp_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &cp_emlrtRTEI);
    i1 = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &lp_emlrtBCI, sp);
    }

    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &lp_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &dq_emlrtBCI, sp);
      }

      reflectivity->data[b_i].f1->data[i2] = reflect->data[i2];
    }

    loop_ub = Simul->size[0] * Simul->size[1];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &mp_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = Simul->size[0];
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &dp_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &mp_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &dp_emlrtRTEI);
    i1 = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &mp_emlrtBCI, sp);
    }

    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &mp_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &eq_emlrtBCI, sp);
      }

      Simulation->data[b_i].f1->data[i2] = Simul->data[i2];
    }

    loop_ub = shifted_dat->size[0] * shifted_dat->size[1];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &np_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i1, &ep_emlrtRTEI);
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &np_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[1] = shifted_dat->size[1];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i1, &ep_emlrtRTEI);
    i1 = shifted_data->size[0];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &np_emlrtBCI, sp);
    }

    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &np_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &fq_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[i2] = shifted_dat->data[i2];
    }

    loop_ub = theseLayers->size[0] * theseLayers->size[1];
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &op_emlrtBCI,
        sp);
    }

    i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = theseLayers->size[0];
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &fp_emlrtRTEI);
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &op_emlrtBCI,
        sp);
    }

    i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &fp_emlrtRTEI);
    i1 = layerSlds->size[0];
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &op_emlrtBCI,
        sp);
    }

    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &op_emlrtBCI,
        sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &gq_emlrtBCI, sp);
      }

      layerSlds->data[b_i].f1->data[i2] = theseLayers->data[i2];
    }

    loop_ub = resamLayers->size[0] * resamLayers->size[1];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &pp_emlrtBCI,
        sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = resamLayers->size[0];
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &gp_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &pp_emlrtBCI,
        sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &gp_emlrtRTEI);
    i1 = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &pp_emlrtBCI,
        sp);
    }

    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &pp_emlrtBCI,
        sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &hq_emlrtBCI, sp);
      }

      allLayers->data[b_i].f1->data[i2] = resamLayers->data[i2];
    }

    if (b_i + 1 > backgs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, backgs->size[0], &iq_emlrtBCI,
        sp);
    }

    backgs->data[b_i] = thisBackground;
    if (b_i + 1 > qshifts->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, qshifts->size[0], &jq_emlrtBCI,
        sp);
    }

    qshifts->data[b_i] = thisQshift;
    if (b_i + 1 > sfs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, sfs->size[0], &kq_emlrtBCI, sp);
    }

    sfs->data[b_i] = thisSf;
    if (b_i + 1 > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbas->size[0], &lq_emlrtBCI, sp);
    }

    nbas->data[b_i] = thisNba;
    if (b_i + 1 > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbss->size[0], &mq_emlrtBCI, sp);
    }

    nbss->data[b_i] = thisNbs;
    if (b_i + 1 > resols->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, resols->size[0], &nq_emlrtBCI,
        sp);
    }

    resols->data[b_i] = thisResol;
    if (b_i + 1 > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, allRoughs->size[0], &oq_emlrtBCI,
        sp);
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_problemDef_cells);
  emxFree_real_T(&b_shifted_dat);
  emxFree_real_T(&Simul);
  emxFree_real_T(&reflect);
  emxFree_real_T(&theseLayers);
  emxFree_real_T(&layerSld);
  emxFree_real_T(&resamLayers);
  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&sldProfile);
  emxFree_real_T(&outLayers);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_custlay_paraPoints.c) */
