/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_custLay_reflectivityCalculation.c
 *
 * Code generation for function 'standardTF_custLay_reflectivityCalculation'
 *
 */

/* Include files */
#include "standardTF_custLay_reflectivityCalculation.h"
#include "backSort.h"
#include "call_customLayers.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_custlay_paraContrasts.h"
#include "standardTF_custlay_paraPoints.h"
#include "standardTF_layers_core.h"
#include "sum.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo ch_emlrtRSI = { 65, /* lineNo */
  "standardTF_custLay_reflectivityCalculation",/* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo dh_emlrtRSI = { 72, /* lineNo */
  "standardTF_custLay_reflectivityCalculation",/* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo eh_emlrtRSI = { 79, /* lineNo */
  "standardTF_custLay_reflectivityCalculation",/* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo fh_emlrtRSI = { 100,/* lineNo */
  "standardTF_custLay_reflectivityCalculation",/* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo gh_emlrtRSI = { 74, /* lineNo */
  "standardTF_custlay_single",         /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pathName */
};

static emlrtRSInfo hh_emlrtRSI = { 78, /* lineNo */
  "standardTF_custlay_single",         /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pathName */
};

static emlrtRSInfo ih_emlrtRSI = { 101,/* lineNo */
  "standardTF_custlay_single",         /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pathName */
};

static emlrtDCInfo tb_emlrtDCI = { 29, /* lineNo */
  21,                                  /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo hc_emlrtRTEI = { 30,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ic_emlrtRTEI = { 35,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = { 40,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo kc_emlrtRTEI = { 45,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo lc_emlrtRTEI = { 50,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo mc_emlrtRTEI = { 55,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo nc_emlrtRTEI = { 46,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo oc_emlrtRTEI = { 51,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo pc_emlrtRTEI = { 56,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo qc_emlrtRTEI = { 69,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtDCInfo ub_emlrtDCI = { 77, /* lineNo */
  34,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo dm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  27,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo em_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  29,                                  /* colNo */
  "resample",                          /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  35,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  31,                                  /* colNo */
  "backsType",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  34,                                  /* colNo */
  "customFiles",                       /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo im_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  37,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  24,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo km_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  91,                                  /* lineNo */
  33,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  31,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  18,                                  /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  16,                                  /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo om_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  18,                                  /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  15,                                  /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  17,                                  /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  15,                                  /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  18,                                  /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  16,                                  /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo um_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  15,                                  /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  15,                                  /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  17,                                  /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  116,                                 /* lineNo */
  18,                                  /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ym_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  118,                                 /* lineNo */
  15,                                  /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo vb_emlrtDCI = { 32, /* lineNo */
  17,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo wb_emlrtDCI = { 92, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo xb_emlrtDCI = { 92, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo yb_emlrtDCI = { 93, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo ac_emlrtDCI = { 94, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo bc_emlrtDCI = { 95, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo cc_emlrtDCI = { 96, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo dc_emlrtDCI = { 97, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo ec_emlrtDCI = { 25, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo fc_emlrtDCI = { 98, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo gc_emlrtDCI = { 101,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo an_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo hc_emlrtDCI = { 31, /* lineNo */
  16,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo dn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  77,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo en_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  87,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  98,                                  /* colNo */
  "cScales",                           /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  109,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  118,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo in_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  127,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  34,                                  /* colNo */
  "cCustFiles",                        /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  78,                                  /* lineNo */
  16,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ln_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  114,                                 /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  115,                                 /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo on_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  117,                                 /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  120,                                 /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  112,                                 /* lineNo */
  5,                                   /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  116,                                 /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  118,                                 /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo un_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  121,                                 /* lineNo */
  5,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  122,                                 /* lineNo */
  5,                                   /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  123,                                 /* lineNo */
  5,                                   /* colNo */
  "sfs",                               /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  124,                                 /* lineNo */
  5,                                   /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  125,                                 /* lineNo */
  5,                                   /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ao_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  126,                                 /* lineNo */
  5,                                   /* colNo */
  "resols",                            /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  127,                                 /* lineNo */
  5,                                   /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo co_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo do_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo go_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ho_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo kn_emlrtRTEI = { 92,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ln_emlrtRTEI = { 93,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo mn_emlrtRTEI = { 94,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo nn_emlrtRTEI = { 95,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo on_emlrtRTEI = { 96,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo pn_emlrtRTEI = { 97,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo qn_emlrtRTEI = { 25,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo rn_emlrtRTEI = { 98,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo sn_emlrtRTEI = { 101,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo tn_emlrtRTEI = { 18,/* lineNo */
  21,                                  /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo un_emlrtRTEI = { 31,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo vn_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo wn_emlrtRTEI = { 41,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo xn_emlrtRTEI = { 46,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo yn_emlrtRTEI = { 51,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ao_emlrtRTEI = { 56,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo co_emlrtRTEI = { 102,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo do_emlrtRTEI = { 80,/* lineNo */
  60,                                  /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo eo_emlrtRTEI = { 27,/* lineNo */
  11,                                  /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo fo_emlrtRTEI = { 47,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo go_emlrtRTEI = { 52,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo ho_emlrtRTEI = { 57,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo io_emlrtRTEI = { 80,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo jo_emlrtRTEI = { 113,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo ko_emlrtRTEI = { 116,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo lo_emlrtRTEI = { 118,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_single",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"/* pName */
};

static emlrtRTEInfo mo_emlrtRTEI = { 1,/* lineNo */
  91,                                  /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

/* Function Definitions */
void c_standardTF_custLay_reflectivi(const emlrtStack *sp, const struct0_T
  *problemDef, const cell_16 *problemDef_cells, const struct2_T *controls,
  struct_T *problem, emxArray_cell_wrap_9 *reflectivity, emxArray_cell_wrap_9
  *Simulation, emxArray_cell_wrap_14 *shifted_data, emxArray_cell_wrap_10
  *layerSlds, emxArray_cell_wrap_14 *sldProfiles, emxArray_cell_wrap_14
  *allLayers)
{
  static const char_T b_cv[6] = { 's', 'i', 'n', 'g', 'l', 'e' };

  static const char_T b_cv1[6] = { 'p', 'o', 'i', 'n', 't', 's' };

  emlrtStack b_st;
  emlrtStack st;
  emxArray_cell_wrap_14 *b_allLayers;
  emxArray_cell_wrap_25 *r;
  emxArray_real_T *backgs;
  emxArray_real_T *outLayers;
  emxArray_real_T *resamLayers;
  emxArray_real_T *shifted_dat;
  emxArray_real_T *sldProfile;
  real_T d;
  real_T thisBackground;
  real_T thisNba;
  real_T thisNbs;
  real_T thisQshift;
  real_T thisResol;
  real_T thisSf;
  int32_T b_i;
  int32_T exitg1;
  int32_T i;
  int32_T i1;
  int32_T kstr;
  int32_T loop_ub;
  boolean_T b_bool;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  Custom layers reflectivity calculation for standardTF */
  /*  This function decides on parallelisation options before calling the */
  /*  relevant version of the main custom layers calculation. It is more */
  /*  efficient to have multiple versions of the core calculation, each dealing */
  /*  with a different scheme for paralellisation. These are: */
  /*  single    - single threaded teflectivity calculation */
  /*  points    - parallelise over points in the reflectivity calculation */
  /*  contrasts - parallelise over contrasts. */
  /*  Pre-allocation - It's necessary to */
  /*  pre-allocate the memory for all the arrays */
  /*  for compilation, so do this in this block. */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &xb_emlrtDCI, sp);
  }

  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &wb_emlrtDCI, sp);
  }

  i1 = problem->ssubs->size[0];
  problem->ssubs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->ssubs, i1, &kn_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &wb_emlrtDCI, sp);
  }

  loop_ub = (int32_T)problemDef->numberOfContrasts;
  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->ssubs->data[i1] = 0.0;
  }

  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &yb_emlrtDCI, sp);
  }

  i1 = problem->backgrounds->size[0];
  loop_ub = (int32_T)problemDef->numberOfContrasts;
  problem->backgrounds->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->backgrounds, i1, &ln_emlrtRTEI);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &yb_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->backgrounds->data[i1] = 0.0;
  }

  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ac_emlrtDCI, sp);
  }

  i1 = problem->qshifts->size[0];
  problem->qshifts->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->qshifts, i1, &mn_emlrtRTEI);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ac_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->qshifts->data[i1] = 0.0;
  }

  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &bc_emlrtDCI, sp);
  }

  i1 = problem->scalefactors->size[0];
  problem->scalefactors->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->scalefactors, i1, &nn_emlrtRTEI);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &bc_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->scalefactors->data[i1] = 0.0;
  }

  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &cc_emlrtDCI, sp);
  }

  i1 = problem->nbairs->size[0];
  problem->nbairs->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->nbairs, i1, &on_emlrtRTEI);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &cc_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->nbairs->data[i1] = 0.0;
  }

  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &dc_emlrtDCI, sp);
  }

  i1 = problem->nbsubs->size[0];
  problem->nbsubs->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->nbsubs, i1, &pn_emlrtRTEI);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &dc_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->nbsubs->data[i1] = 0.0;
  }

  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ec_emlrtDCI, sp);
  }

  i1 = problem->calculations.all_chis->size[0];
  problem->calculations.all_chis->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->calculations.all_chis, i1, &qn_emlrtRTEI);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ec_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->calculations.all_chis->data[i1] = 0.0;
  }

  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &fc_emlrtDCI, sp);
  }

  i1 = problem->resolutions->size[0];
  problem->resolutions->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->resolutions, i1, &rn_emlrtRTEI);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &fc_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->resolutions->data[i1] = 0.0;
  }

  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &gc_emlrtDCI, sp);
  }

  i1 = problem->allSubRough->size[0];
  problem->allSubRough->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->allSubRough, i1, &sn_emlrtRTEI);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &gc_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->allSubRough->data[i1] = 0.0;
  }

  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &tb_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &hc_emlrtRTEI, sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i1, &tn_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &mm_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &un_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &mm_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &un_emlrtRTEI);
    i1 = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &mm_emlrtBCI, sp);
    }

    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &mm_emlrtBCI, sp);
    }

    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &co_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &co_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &co_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &co_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &ic_emlrtRTEI, sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i1, &tn_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &nm_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &vn_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &nm_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &vn_emlrtRTEI);
    i1 = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &nm_emlrtBCI, sp);
    }

    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &nm_emlrtBCI, sp);
    }

    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &do_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &do_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &do_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &do_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &jc_emlrtRTEI, sp);
  i1 = shifted_data->size[0];
  shifted_data->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i1, &tn_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &om_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i1, &wn_emlrtRTEI);
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &om_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i1, &wn_emlrtRTEI);
    i1 = shifted_data->size[0];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &om_emlrtBCI, sp);
    }

    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &om_emlrtBCI, sp);
    }

    for (kstr = 0; kstr < 6; kstr++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &an_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[kstr] = 1.0;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &kc_emlrtRTEI, sp);
  i1 = layerSlds->size[0];
  layerSlds->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i1, &tn_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &pm_emlrtBCI,
        sp);
    }

    i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &xn_emlrtRTEI);
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &pm_emlrtBCI,
        sp);
    }

    i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &xn_emlrtRTEI);
    i1 = layerSlds->size[0];
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &pm_emlrtBCI,
        sp);
    }

    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &pm_emlrtBCI,
        sp);
    }

    for (kstr = 0; kstr < 6; kstr++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &bn_emlrtBCI, sp);
      }

      layerSlds->data[b_i].f1->data[kstr] = 1.0;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &lc_emlrtRTEI, sp);
  i1 = sldProfiles->size[0];
  sldProfiles->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i1, &tn_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &qm_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &yn_emlrtRTEI);
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &qm_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &yn_emlrtRTEI);
    i1 = sldProfiles->size[0];
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &qm_emlrtBCI, sp);
    }

    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &qm_emlrtBCI, sp);
    }

    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &eo_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &eo_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &eo_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &eo_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &mc_emlrtRTEI, sp);
  i1 = allLayers->size[0];
  allLayers->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i1, &tn_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &rm_emlrtBCI,
        sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &ao_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &rm_emlrtBCI,
        sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &ao_emlrtRTEI);
    i1 = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &rm_emlrtBCI,
        sp);
    }

    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &rm_emlrtBCI,
        sp);
    }

    for (kstr = 0; kstr < 6; kstr++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &cn_emlrtBCI, sp);
      }

      allLayers->data[b_i].f1->data[kstr] = 1.0;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*  End pre-allocation */
  b_bool = false;
  if (controls->para->size[1] == 6) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 6) {
        if (controls->para->data[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  if (b_bool) {
    kstr = 0;
  } else {
    b_bool = false;
    if (controls->para->size[1] == 6) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 6) {
          if (controls->para->data[kstr] != b_cv1[kstr]) {
            exitg1 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (b_bool) {
      kstr = 1;
    } else {
      b_bool = false;
      if (controls->para->size[1] == 9) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr < 9) {
            if (controls->para->data[kstr] != cv[kstr]) {
              exitg1 = 1;
            } else {
              kstr++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }

      if (b_bool) {
        kstr = 2;
      } else {
        kstr = -1;
      }
    }
  }

  switch (kstr) {
   case 0:
    st.site = &ch_emlrtRSI;

    /*  Single threaded version of the custom layers, standardTF reflectivity */
    /*  calculation. The function extracts the relevant parameters from the input */
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
    /*  Pre-Allocation of output arrays... */
    if (problemDef->numberOfContrasts != problemDef->numberOfContrasts) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &hc_emlrtDCI, &st);
    }

    emxInit_real_T(&st, &backgs, 1, &sn_emlrtRTEI, true);
    i1 = backgs->size[0];
    backgs->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, backgs, i1, &sn_emlrtRTEI);
    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &vb_emlrtDCI, &st);
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &nc_emlrtRTEI, &st);
    i = reflectivity->size[0];
    reflectivity->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_9(&st, reflectivity, i, &eo_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      if (b_i > reflectivity->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
          &sm_emlrtBCI, &st);
      }

      i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->
        size[1];
      reflectivity->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i, &fo_emlrtRTEI);
      if (b_i > reflectivity->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
          &sm_emlrtBCI, &st);
      }

      i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->
        size[1];
      reflectivity->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i, &fo_emlrtRTEI);
      i = reflectivity->size[0];
      if (b_i > reflectivity->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
          &sm_emlrtBCI, &st);
      }

      if (b_i > reflectivity->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
          &sm_emlrtBCI, &st);
      }

      if (b_i > reflectivity->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
          &fo_emlrtBCI, &st);
      }

      reflectivity->data[b_i].f1->data[0] = 1.0;
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &fo_emlrtBCI, &st);
      }

      reflectivity->data[b_i].f1->data[1] = 1.0;
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &fo_emlrtBCI, &st);
      }

      reflectivity->data[b_i].f1->data[2] = 1.0;
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &fo_emlrtBCI, &st);
      }

      reflectivity->data[b_i].f1->data[3] = 1.0;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &oc_emlrtRTEI, &st);
    i = Simulation->size[0];
    Simulation->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_9(&st, Simulation, i, &eo_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      if (b_i > Simulation->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
          &tm_emlrtBCI, &st);
      }

      i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
      Simulation->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, Simulation->data[b_i].f1, i, &go_emlrtRTEI);
      if (b_i > Simulation->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
          &tm_emlrtBCI, &st);
      }

      i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
      Simulation->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, Simulation->data[b_i].f1, i, &go_emlrtRTEI);
      i = Simulation->size[0];
      if (b_i > Simulation->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
          &tm_emlrtBCI, &st);
      }

      if (b_i > Simulation->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
          &tm_emlrtBCI, &st);
      }

      if (b_i > Simulation->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
          &go_emlrtBCI, &st);
      }

      Simulation->data[b_i].f1->data[0] = 1.0;
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &go_emlrtBCI, &st);
      }

      Simulation->data[b_i].f1->data[1] = 1.0;
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &go_emlrtBCI, &st);
      }

      Simulation->data[b_i].f1->data[2] = 1.0;
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &go_emlrtBCI, &st);
      }

      Simulation->data[b_i].f1->data[3] = 1.0;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &pc_emlrtRTEI, &st);
    i = allLayers->size[0];
    allLayers->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_14(&st, allLayers, i, &eo_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
          &um_emlrtBCI, &st);
      }

      i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
      allLayers->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i, &ho_emlrtRTEI);
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
          &um_emlrtBCI, &st);
      }

      i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
      allLayers->data[b_i].f1->size[1] = 1;
      emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i, &ho_emlrtRTEI);
      i = allLayers->size[0];
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
          &um_emlrtBCI, &st);
      }

      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
          &um_emlrtBCI, &st);
      }

      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
          &ho_emlrtBCI, &st);
      }

      allLayers->data[b_i].f1->data[0] = 1.0;
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &ho_emlrtBCI, &st);
      }

      allLayers->data[b_i].f1->data[1] = 1.0;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    /*    --- End Memory Allocation --- */
    /*  Resampling parameters */
    /*  Custom model loop */
    /*  Single cored over all contrasts */
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &qc_emlrtRTEI, &st);
    i = problem->allSubRough->size[0];
    problem->allSubRough->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, problem->allSubRough, i, &sn_emlrtRTEI);
    i = allLayers->size[0];
    allLayers->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_14(&st, allLayers, i, &eo_emlrtRTEI);
    i = problem->ssubs->size[0];
    problem->ssubs->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, problem->ssubs, i, &sn_emlrtRTEI);
    i = sldProfiles->size[0];
    sldProfiles->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_14(&st, sldProfiles, i, &eo_emlrtRTEI);
    i = reflectivity->size[0];
    reflectivity->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_9(&st, reflectivity, i, &eo_emlrtRTEI);
    i = Simulation->size[0];
    Simulation->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_9(&st, Simulation, i, &eo_emlrtRTEI);
    i = shifted_data->size[0];
    shifted_data->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_14(&st, shifted_data, i, &eo_emlrtRTEI);
    i = layerSlds->size[0];
    layerSlds->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_10(&st, layerSlds, i, &eo_emlrtRTEI);
    i = problem->calculations.all_chis->size[0];
    problem->calculations.all_chis->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, problem->calculations.all_chis, i,
      &sn_emlrtRTEI);
    i = problem->qshifts->size[0];
    problem->qshifts->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, problem->qshifts, i, &sn_emlrtRTEI);
    i = problem->scalefactors->size[0];
    problem->scalefactors->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, problem->scalefactors, i, &sn_emlrtRTEI);
    i = problem->nbairs->size[0];
    problem->nbairs->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, problem->nbairs, i, &sn_emlrtRTEI);
    i = problem->nbsubs->size[0];
    problem->nbsubs->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, problem->nbsubs, i, &sn_emlrtRTEI);
    i = problem->resolutions->size[0];
    problem->resolutions->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, problem->resolutions, i, &sn_emlrtRTEI);
    emxInit_real_T(&st, &outLayers, 2, &mo_emlrtRTEI, true);
    emxInit_real_T(&st, &sldProfile, 2, &mo_emlrtRTEI, true);
    emxInit_real_T(&st, &shifted_dat, 2, &mo_emlrtRTEI, true);
    emxInit_real_T(&st, &resamLayers, 2, &mo_emlrtRTEI, true);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      /*  Extract the relevant parameter values for this contrast */
      /*  from the input arrays. */
      /*  First need to decide which values of the backrounds, scalefactors */
      /*  data shifts and bulk contrasts are associated with this contrast */
      if ((int32_T)(b_i + 1U) > problemDef->contrastBacks->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
          problemDef->contrastBacks->size[1], &dn_emlrtBCI, &st);
      }

      if ((int32_T)(b_i + 1U) > problemDef->contrastShifts->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
          problemDef->contrastShifts->size[1], &en_emlrtBCI, &st);
      }

      if ((int32_T)(b_i + 1U) > problemDef->contrastScales->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
          problemDef->contrastScales->size[1], &fn_emlrtBCI, &st);
      }

      if ((int32_T)(b_i + 1U) > problemDef->contrastNbas->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
          problemDef->contrastNbas->size[1], &gn_emlrtBCI, &st);
      }

      if ((int32_T)(b_i + 1U) > problemDef->contrastNbss->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
          problemDef->contrastNbss->size[1], &hn_emlrtBCI, &st);
      }

      if ((int32_T)(b_i + 1U) > problemDef->contrastRes->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
          problemDef->contrastRes->size[1], &in_emlrtBCI, &st);
      }

      b_st.site = &gh_emlrtRSI;
      backSort(&b_st, problemDef->contrastBacks->data[b_i],
               problemDef->contrastShifts->data[b_i], problemDef->
               contrastScales->data[b_i], problemDef->contrastNbas->data[b_i],
               problemDef->contrastNbss->data[b_i], problemDef->
               contrastRes->data[b_i], problemDef->backs, problemDef->shifts,
               problemDef->sf, problemDef->nba, problemDef->nbs, problemDef->res,
               &thisBackground, &thisQshift, &thisSf, &thisNba, &thisNbs,
               &thisResol);

      /*  Call the custom layers function to get the layers array... */
      if ((int32_T)(b_i + 1U) > problemDef->contrastCustomFiles->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
          problemDef->contrastCustomFiles->size[1], &jn_emlrtBCI, &st);
      }

      d = problemDef->contrastCustomFiles->data[b_i];
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &ub_emlrtDCI, &st);
      }

      if (((int32_T)d - 1 < 0) || ((int32_T)d - 1 > problemDef_cells->f14->size
           [1] - 1)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d - 1, 0, problemDef_cells->
          f14->size[1] - 1, &hm_emlrtBCI, &st);
      }

      if ((int32_T)(b_i + 1U) > problem->allSubRough->size[0]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
          problem->allSubRough->size[0], &kn_emlrtBCI, &st);
      }

      b_st.site = &hh_emlrtRSI;
      call_customLayers(&b_st, problemDef->params, (real_T)b_i + 1.0,
                        problemDef_cells->f14->data[(int32_T)
                        problemDef->contrastCustomFiles->data[b_i] - 1].f1,
                        thisNba, thisNbs, problemDef->numberOfContrasts,
                        outLayers, &problem->allSubRough->data[b_i]);
      kstr = outLayers->size[0] * outLayers->size[1];
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
          &vm_emlrtBCI, &st);
      }

      i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
      allLayers->data[b_i].f1->size[0] = outLayers->size[0];
      emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i, &io_emlrtRTEI);
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
          &vm_emlrtBCI, &st);
      }

      i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
      allLayers->data[b_i].f1->size[1] = outLayers->size[1];
      emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i, &io_emlrtRTEI);
      i = allLayers->size[0];
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
          &vm_emlrtBCI, &st);
      }

      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
          &vm_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &ln_emlrtBCI, &st);
        }

        allLayers->data[b_i].f1->data[i1] = outLayers->data[i1];
      }

      /*  For the other parameters, we extract the correct ones from the input */
      /*  arrays */
      i = b_i + 1;
      if (i > problem->allSubRough->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problem->allSubRough->size[0],
          &dm_emlrtBCI, &st);
      }

      if (b_i > problemDef_cells->f1->size[1] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f1->size[1] - 1,
          &im_emlrtBCI, &st);
      }

      if (i > problemDef->resample->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->resample->size[1],
          &em_emlrtBCI, &st);
      }

      if (b_i > problemDef_cells->f2->size[1] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f2->size[1] - 1,
          &jm_emlrtBCI, &st);
      }

      if (i > problemDef->dataPresent->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->dataPresent->size[1],
          &fm_emlrtBCI, &st);
      }

      if (b_i > problemDef_cells->f3->size[1] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f3->size[1] - 1,
          &km_emlrtBCI, &st);
      }

      if (b_i > problemDef_cells->f4->size[1] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f4->size[1] - 1,
          &lm_emlrtBCI, &st);
      }

      if (i > problemDef->contrastBacksType->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastBacksType->size
          [1], &gm_emlrtBCI, &st);
      }

      /*  Now call the core standardTF_stanlay reflectivity calculation */
      /*  In this case we are single cored, so we do not parallelise over */
      /*  points */
      /*  Call the reflectivity calculation */
      if (b_i > reflectivity->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
          &mn_emlrtBCI, &st);
      }

      if (b_i > Simulation->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
          &nn_emlrtBCI, &st);
      }

      if (b_i > layerSlds->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
          &on_emlrtBCI, &st);
      }

      if (b_i + 1 > problem->calculations.all_chis->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, problem->
          calculations.all_chis->size[0], &pn_emlrtBCI, &st);
      }

      if (b_i + 1 > problem->ssubs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, problem->ssubs->size[0],
          &qn_emlrtBCI, &st);
      }

      b_st.site = &ih_emlrtRSI;
      b_standardTF_layers_core(&b_st, outLayers, problem->allSubRough->data[b_i],
        problemDef->geometry, thisNba, thisNbs, problemDef->resample->data[b_i],
        controls->calcSld, thisSf, thisQshift, problemDef->dataPresent->data[b_i],
        problemDef_cells->f2->data[b_i].f1, problemDef_cells->f3->data[b_i].f1,
        (real_T *)problemDef_cells->f4->data[b_i].f1->data, problemDef_cells->
        f4->data[b_i].f1->size, problemDef_cells->f1->data[b_i].f1,
        thisBackground, thisResol, problemDef->contrastBacksType->data[b_i],
        problemDef->params->size[1], controls->resamPars, sldProfile,
        reflectivity->data[b_i].f1, Simulation->data[b_i].f1, shifted_dat,
        layerSlds->data[b_i].f1, resamLayers, &problem->
        calculations.all_chis->data[b_i], &problem->ssubs->data[b_i]);

      /*  Store returned values for this contrast in the output arrays. */
      /*  As well as the calculated profiles, we also store a record of  */
      /*  the other values (background, scalefactors etc) for each contrast */
      /*  for future use. */
      kstr = sldProfile->size[0] * sldProfile->size[1];
      if (b_i > sldProfiles->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
          &wm_emlrtBCI, &st);
      }

      i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
      sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
      emxEnsureCapacity_real_T(&st, sldProfiles->data[b_i].f1, i, &jo_emlrtRTEI);
      if (b_i > sldProfiles->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
          &wm_emlrtBCI, &st);
      }

      i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
      sldProfiles->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, sldProfiles->data[b_i].f1, i, &jo_emlrtRTEI);
      i = sldProfiles->size[0];
      if (b_i > sldProfiles->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
          &wm_emlrtBCI, &st);
      }

      if (b_i > sldProfiles->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
          &wm_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &rn_emlrtBCI, &st);
        }

        sldProfiles->data[b_i].f1->data[i1] = sldProfile->data[i1];
      }

      kstr = shifted_dat->size[0] * shifted_dat->size[1];
      if (b_i > shifted_data->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
          &xm_emlrtBCI, &st);
      }

      i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->
        size[1];
      shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
      emxEnsureCapacity_real_T(&st, shifted_data->data[b_i].f1, i, &ko_emlrtRTEI);
      if (b_i > shifted_data->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
          &xm_emlrtBCI, &st);
      }

      i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->
        size[1];
      shifted_data->data[b_i].f1->size[1] = shifted_dat->size[1];
      emxEnsureCapacity_real_T(&st, shifted_data->data[b_i].f1, i, &ko_emlrtRTEI);
      i = shifted_data->size[0];
      if (b_i > shifted_data->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
          &xm_emlrtBCI, &st);
      }

      if (b_i > shifted_data->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
          &xm_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &sn_emlrtBCI, &st);
        }

        shifted_data->data[b_i].f1->data[i1] = shifted_dat->data[i1];
      }

      kstr = resamLayers->size[0] * resamLayers->size[1];
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
          &ym_emlrtBCI, &st);
      }

      i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
      allLayers->data[b_i].f1->size[0] = resamLayers->size[0];
      emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i, &lo_emlrtRTEI);
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
          &ym_emlrtBCI, &st);
      }

      i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
      allLayers->data[b_i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i, &lo_emlrtRTEI);
      i = allLayers->size[0];
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
          &ym_emlrtBCI, &st);
      }

      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
          &ym_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &tn_emlrtBCI, &st);
        }

        allLayers->data[b_i].f1->data[i1] = resamLayers->data[i1];
      }

      if (b_i + 1 > backgs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, backgs->size[0], &un_emlrtBCI,
          &st);
      }

      backgs->data[b_i] = thisBackground;
      if (b_i + 1 > problem->qshifts->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, problem->qshifts->size[0],
          &vn_emlrtBCI, &st);
      }

      problem->qshifts->data[b_i] = thisQshift;
      if (b_i + 1 > problem->scalefactors->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, problem->scalefactors->size[0],
          &wn_emlrtBCI, &st);
      }

      problem->scalefactors->data[b_i] = thisSf;
      if (b_i + 1 > problem->nbairs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, problem->nbairs->size[0],
          &xn_emlrtBCI, &st);
      }

      problem->nbairs->data[b_i] = thisNba;
      if (b_i + 1 > problem->nbsubs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, problem->nbsubs->size[0],
          &yn_emlrtBCI, &st);
      }

      problem->nbsubs->data[b_i] = thisNbs;
      if (b_i + 1 > problem->resolutions->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, problem->resolutions->size[0],
          &ao_emlrtBCI, &st);
      }

      problem->resolutions->data[b_i] = thisResol;
      if (b_i + 1 > problem->allSubRough->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, problem->allSubRough->size[0],
          &bo_emlrtBCI, &st);
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    emxFree_real_T(&resamLayers);
    emxFree_real_T(&shifted_dat);
    emxFree_real_T(&sldProfile);
    emxFree_real_T(&outLayers);
    i = problem->backgrounds->size[0];
    problem->backgrounds->size[0] = backgs->size[0];
    emxEnsureCapacity_real_T(sp, problem->backgrounds, i, &sn_emlrtRTEI);
    loop_ub = backgs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->backgrounds->data[i] = backgs->data[i];
    }

    emxFree_real_T(&backgs);
    break;

   case 1:
    st.site = &dh_emlrtRSI;
    standardTF_custlay_paraPoints(&st, problemDef, problemDef_cells, controls,
      problem->ssubs, problem->backgrounds, problem->qshifts,
      problem->scalefactors, problem->nbairs, problem->nbsubs,
      problem->resolutions, problem->calculations.all_chis, reflectivity,
      Simulation, shifted_data, layerSlds, sldProfiles, allLayers,
      problem->allSubRough);
    break;

   case 2:
    emxInit_cell_wrap_14(sp, &b_allLayers, 1, &mo_emlrtRTEI, true);
    emxInit_cell_wrap_25(sp, &r, 1, &mo_emlrtRTEI, true);
    st.site = &eh_emlrtRSI;
    c_standardTF_custlay_paraContra(&st, problemDef, problemDef_cells, controls,
      problem->ssubs, problem->backgrounds, problem->qshifts,
      problem->scalefactors, problem->nbairs, problem->nbsubs,
      problem->resolutions, problem->calculations.all_chis, reflectivity,
      Simulation, shifted_data, layerSlds, sldProfiles, r, problem->allSubRough);
    i = b_allLayers->size[0];
    b_allLayers->size[0] = r->size[0];
    emxEnsureCapacity_cell_wrap_14(sp, b_allLayers, i, &bo_emlrtRTEI);
    i = r->size[0];
    for (i1 = 0; i1 < i; i1++) {
      kstr = b_allLayers->data[i1].f1->size[0] * b_allLayers->data[i1].f1->size
        [1];
      b_allLayers->data[i1].f1->size[0] = r->data[i1].f1.size[0];
      b_allLayers->data[i1].f1->size[1] = r->data[i1].f1.size[1];
      emxEnsureCapacity_real_T(sp, b_allLayers->data[i1].f1, kstr, &bo_emlrtRTEI);
      loop_ub = r->data[i1].f1.size[0] * r->data[i1].f1.size[1];
      for (kstr = 0; kstr < loop_ub; kstr++) {
        b_allLayers->data[i1].f1->data[kstr] = r->data[i1].f1.data[kstr];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    emxFree_cell_wrap_25(&r);
    i = allLayers->size[0];
    allLayers->size[0] = b_allLayers->size[0];
    emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &do_emlrtRTEI);
    loop_ub = b_allLayers->size[0];
    for (i = 0; i < loop_ub; i++) {
      emxCopyStruct_cell_wrap_14(sp, &allLayers->data[i], &b_allLayers->data[i],
        &do_emlrtRTEI);
    }

    emxFree_cell_wrap_14(&b_allLayers);

    /*            [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,... */
    /*               Simulation,shifted_data,layerSlds,sldProfiles,allLayers,... */
    /*               allRoughs] = dev_custlay_paraContrasts(problemDef,problemDef_cells,... */
    /*               problemDef_limits,controls); */
    break;
  }

  st.site = &fh_emlrtRSI;
  problem->calculations.sum_chi = sum(&st, problem->calculations.all_chis);
  i = problem->resample->size[0] * problem->resample->size[1];
  problem->resample->size[0] = 1;
  problem->resample->size[1] = problemDef->resample->size[1];
  emxEnsureCapacity_real_T(sp, problem->resample, i, &co_emlrtRTEI);
  loop_ub = problemDef->resample->size[0] * problemDef->resample->size[1];
  for (i = 0; i < loop_ub; i++) {
    problem->resample->data[i] = problemDef->resample->data[i];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_custLay_reflectivityCalculation.c) */
