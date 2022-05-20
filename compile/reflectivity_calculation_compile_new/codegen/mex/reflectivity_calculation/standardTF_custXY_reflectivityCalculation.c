/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_custXY_reflectivityCalculation.c
 *
 * Code generation for function 'standardTF_custXY_reflectivityCalculation'
 *
 */

/* Include files */
#include "standardTF_custXY_reflectivityCalculation.h"
#include "backSort.h"
#include "callReflectivity.h"
#include "call_customLayers.h"
#include "chiSquared.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"
#include "standardTF_custXY_paraContrasts.h"
#include "standardTF_custXY_single.h"
#include "sum.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo th_emlrtRSI = { 64, /* lineNo */
  "standardTF_custXY_reflectivityCalculation",/* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo uh_emlrtRSI = { 71, /* lineNo */
  "standardTF_custXY_reflectivityCalculation",/* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo vh_emlrtRSI = { 78, /* lineNo */
  "standardTF_custXY_reflectivityCalculation",/* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo wh_emlrtRSI = { 93, /* lineNo */
  "standardTF_custXY_reflectivityCalculation",/* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo gi_emlrtRSI = { 59, /* lineNo */
  "standardTF_custXY_paraPoints",      /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pathName */
};

static emlrtRSInfo hi_emlrtRSI = { 62, /* lineNo */
  "standardTF_custXY_paraPoints",      /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pathName */
};

static emlrtRSInfo ii_emlrtRSI = { 67, /* lineNo */
  "standardTF_custXY_paraPoints",      /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pathName */
};

static emlrtRSInfo ji_emlrtRSI = { 71, /* lineNo */
  "standardTF_custXY_paraPoints",      /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pathName */
};

static emlrtRSInfo ki_emlrtRSI = { 75, /* lineNo */
  "standardTF_custXY_paraPoints",      /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pathName */
};

static emlrtRSInfo li_emlrtRSI = { 77, /* lineNo */
  "standardTF_custXY_paraPoints",      /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pathName */
};

static emlrtRSInfo mi_emlrtRSI = { 82, /* lineNo */
  "standardTF_custXY_paraPoints",      /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pathName */
};

static emlrtRSInfo ni_emlrtRSI = { 83, /* lineNo */
  "standardTF_custXY_paraPoints",      /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pathName */
};

static emlrtDCInfo yc_emlrtDCI = { 29, /* lineNo */
  21,                                  /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo dd_emlrtRTEI = { 30,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ed_emlrtRTEI = { 35,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo fd_emlrtRTEI = { 40,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo gd_emlrtRTEI = { 45,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo hd_emlrtRTEI = { 50,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo id_emlrtRTEI = { 55,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtDCInfo ad_emlrtDCI = { 34, /* lineNo */
  18,                                  /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo jd_emlrtRTEI = { 40,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo kd_emlrtRTEI = { 46,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo ld_emlrtRTEI = { 52,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo md_emlrtRTEI = { 58,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtDCInfo bd_emlrtDCI = { 61, /* lineNo */
  34,                                  /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo xs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  115,                                 /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ys_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  94,                                  /* colNo */
  "backgs",                            /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo at_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  107,                                 /* colNo */
  "backsType",                         /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  20,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ct_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  34,                                  /* colNo */
  "customFiles",                       /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  18,                                  /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo et_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  16,                                  /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ft_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  18,                                  /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  15,                                  /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ht_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  17,                                  /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo it_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  15,                                  /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  18,                                  /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  16,                                  /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  15,                                  /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  64,                                  /* lineNo */
  17,                                  /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  15,                                  /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ot_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  15,                                  /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  18,                                  /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  18,                                  /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  16,                                  /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo cd_emlrtDCI = { 26, /* lineNo */
  17,                                  /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo dd_emlrtDCI = { 85, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo ed_emlrtDCI = { 85, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo fd_emlrtDCI = { 86, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo gd_emlrtDCI = { 87, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo hd_emlrtDCI = { 88, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo id_emlrtDCI = { 89, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo jd_emlrtDCI = { 90, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo kd_emlrtDCI = { 25, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo ld_emlrtDCI = { 91, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo md_emlrtDCI = { 27, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo st_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo nd_emlrtDCI = { 25, /* lineNo */
  16,                                  /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo od_emlrtDCI = { 28, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo pd_emlrtDCI = { 32, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ut_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  72,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  82,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  93,                                  /* colNo */
  "cScales",                           /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  104,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yt_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  113,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo au_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  122,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  6,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  16,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo du_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  27,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  50,                                  /* colNo */
  "resols",                            /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  34,                                  /* colNo */
  "cCustFiles",                        /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo iu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  80,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ju_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  17,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ku_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  64,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  30,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ou_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  37,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  48,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  63,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ru_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  74,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo su_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  88,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  40,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  48,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  56,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  69,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  118,                                 /* colNo */
  "resols",                            /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo av_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bv_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cv_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  9,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dv_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  9,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ev_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fv_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gv_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hv_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo iv_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jv_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kv_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo gq_emlrtRTEI = { 85,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo hq_emlrtRTEI = { 86,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo iq_emlrtRTEI = { 87,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo jq_emlrtRTEI = { 88,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo kq_emlrtRTEI = { 89,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo lq_emlrtRTEI = { 90,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo mq_emlrtRTEI = { 25,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo nq_emlrtRTEI = { 91,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo oq_emlrtRTEI = { 27,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo pq_emlrtRTEI = { 18,/* lineNo */
  21,                                  /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo qq_emlrtRTEI = { 31,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo rq_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo sq_emlrtRTEI = { 41,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo tq_emlrtRTEI = { 46,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo uq_emlrtRTEI = { 51,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo vq_emlrtRTEI = { 56,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo wq_emlrtRTEI = { 78,/* lineNo */
  62,                                  /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo xq_emlrtRTEI = { 95,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo yq_emlrtRTEI = { 79,/* lineNo */
  60,                                  /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ar_emlrtRTEI = { 79,/* lineNo */
  14,                                  /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo br_emlrtRTEI = { 28,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo cr_emlrtRTEI = { 32,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo dr_emlrtRTEI = { 25,/* lineNo */
  16,                                  /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo er_emlrtRTEI = { 41,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo fr_emlrtRTEI = { 47,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo gr_emlrtRTEI = { 53,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo hr_emlrtRTEI = { 62,/* lineNo */
  75,                                  /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo ir_emlrtRTEI = { 64,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo jr_emlrtRTEI = { 68,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo kr_emlrtRTEI = { 69,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo lr_emlrtRTEI = { 71,/* lineNo */
  63,                                  /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo mr_emlrtRTEI = { 72,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo nr_emlrtRTEI = { 79,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo or_emlrtRTEI = { 80,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo pr_emlrtRTEI = { 1,/* lineNo */
  91,                                  /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo qr_emlrtRTEI = { 67,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo rr_emlrtRTEI = { 71,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

/* Function Definitions */
void c_standardTF_custXY_reflectivit(const emlrtStack *sp, const struct0_T
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
  emxArray_cell_wrap_12 *r;
  emxArray_cell_wrap_12 *r1;
  emxArray_cell_wrap_14 *b_allLayers;
  emxArray_cell_wrap_28 *r2;
  emxArray_cell_wrap_9 *b_Simulation;
  emxArray_cell_wrap_9 *b_reflectivity;
  emxArray_real_T *Simul;
  emxArray_real_T *b_problem;
  emxArray_real_T *b_problemDef_cells;
  emxArray_real_T *backgs;
  emxArray_real_T *layerSld;
  emxArray_real_T *reflect;
  emxArray_real_T *shifted_dat;
  emxArray_real_T *sldProfile;
  real_T d;
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

  /*  Custom XP profile reflectivity calculation for standardTF */
  /*  This function decides on parallelisation options before calling the */
  /*  relevant version of the main custom XY calculation. It is more */
  /*  efficient to have multiple versions of the core calculation, each dealing */
  /*  with a different scheme for paralellisation. These are: */
  /*  single    - single threaded teflectivity calculation */
  /*  points    - parallelise over points in the reflectivity calculation */
  /*  contrasts - parallelise over contrasts. */
  /*  Pre-allocation - It's necessary to */
  /*  pre-allocate the memory for all the arrays */
  /*  for compilation, so do this in this block. */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &ed_emlrtDCI, sp);
  }

  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &dd_emlrtDCI, sp);
  }

  i1 = problem->ssubs->size[0];
  problem->ssubs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->ssubs, i1, &gq_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &dd_emlrtDCI, sp);
  }

  loop_ub = (int32_T)problemDef->numberOfContrasts;
  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->ssubs->data[i1] = 0.0;
  }

  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &fd_emlrtDCI, sp);
  }

  i1 = problem->backgrounds->size[0];
  loop_ub = (int32_T)problemDef->numberOfContrasts;
  problem->backgrounds->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->backgrounds, i1, &hq_emlrtRTEI);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &fd_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->backgrounds->data[i1] = 0.0;
  }

  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &gd_emlrtDCI, sp);
  }

  i1 = problem->qshifts->size[0];
  problem->qshifts->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->qshifts, i1, &iq_emlrtRTEI);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &gd_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->qshifts->data[i1] = 0.0;
  }

  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &hd_emlrtDCI, sp);
  }

  i1 = problem->scalefactors->size[0];
  problem->scalefactors->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->scalefactors, i1, &jq_emlrtRTEI);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &hd_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->scalefactors->data[i1] = 0.0;
  }

  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &id_emlrtDCI, sp);
  }

  i1 = problem->nbairs->size[0];
  problem->nbairs->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->nbairs, i1, &kq_emlrtRTEI);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &id_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->nbairs->data[i1] = 0.0;
  }

  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &jd_emlrtDCI, sp);
  }

  i1 = problem->nbsubs->size[0];
  problem->nbsubs->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->nbsubs, i1, &lq_emlrtRTEI);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &jd_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->nbsubs->data[i1] = 0.0;
  }

  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &kd_emlrtDCI, sp);
  }

  i1 = problem->calculations.all_chis->size[0];
  problem->calculations.all_chis->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->calculations.all_chis, i1, &mq_emlrtRTEI);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &kd_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->calculations.all_chis->data[i1] = 0.0;
  }

  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ld_emlrtDCI, sp);
  }

  i1 = problem->resolutions->size[0];
  problem->resolutions->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->resolutions, i1, &nq_emlrtRTEI);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ld_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->resolutions->data[i1] = 0.0;
  }

  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &md_emlrtDCI, sp);
  }

  i1 = problem->allSubRough->size[0];
  problem->allSubRough->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, problem->allSubRough, i1, &oq_emlrtRTEI);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &md_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->allSubRough->data[i1] = 0.0;
  }

  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &yc_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &dd_emlrtRTEI, sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i1, &pq_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &dt_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &qq_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &dt_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &qq_emlrtRTEI);
    i1 = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &dt_emlrtBCI, sp);
    }

    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &dt_emlrtBCI, sp);
    }

    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &ev_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &ev_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &ev_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &ev_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &ed_emlrtRTEI, sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i1, &pq_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &et_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &rq_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &et_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &rq_emlrtRTEI);
    i1 = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &et_emlrtBCI, sp);
    }

    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &et_emlrtBCI, sp);
    }

    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &fv_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &fv_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &fv_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &fv_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &fd_emlrtRTEI, sp);
  i1 = shifted_data->size[0];
  shifted_data->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i1, &pq_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &ft_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i1, &sq_emlrtRTEI);
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &ft_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i1, &sq_emlrtRTEI);
    i1 = shifted_data->size[0];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &ft_emlrtBCI, sp);
    }

    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &ft_emlrtBCI, sp);
    }

    for (kstr = 0; kstr < 6; kstr++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &st_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[kstr] = 1.0;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &gd_emlrtRTEI, sp);
  i1 = layerSlds->size[0];
  layerSlds->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i1, &pq_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &gt_emlrtBCI,
        sp);
    }

    i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &tq_emlrtRTEI);
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &gt_emlrtBCI,
        sp);
    }

    i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &tq_emlrtRTEI);
    i1 = layerSlds->size[0];
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &gt_emlrtBCI,
        sp);
    }

    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &gt_emlrtBCI,
        sp);
    }

    for (kstr = 0; kstr < 6; kstr++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &tt_emlrtBCI, sp);
      }

      layerSlds->data[b_i].f1->data[kstr] = 1.0;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &hd_emlrtRTEI, sp);
  i1 = sldProfiles->size[0];
  sldProfiles->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i1, &pq_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &ht_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &uq_emlrtRTEI);
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &ht_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &uq_emlrtRTEI);
    i1 = sldProfiles->size[0];
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &ht_emlrtBCI, sp);
    }

    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &ht_emlrtBCI, sp);
    }

    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &gv_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &gv_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &gv_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &gv_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &id_emlrtRTEI, sp);
  i1 = allLayers->size[0];
  allLayers->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i1, &pq_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &it_emlrtBCI,
        sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &vq_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &it_emlrtBCI,
        sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &vq_emlrtRTEI);
    i1 = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &it_emlrtBCI,
        sp);
    }

    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &it_emlrtBCI,
        sp);
    }

    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &hv_emlrtBCI,
        sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &hv_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

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
    st.site = &th_emlrtRSI;
    standardTF_custXY_single(&st, problemDef, problemDef_cells, controls,
      problem->ssubs, problem->backgrounds, problem->qshifts,
      problem->scalefactors, problem->nbairs, problem->nbsubs,
      problem->resolutions, problem->calculations.all_chis, reflectivity,
      Simulation, shifted_data, layerSlds, sldProfiles, allLayers,
      problem->allSubRough);
    break;

   case 1:
    st.site = &uh_emlrtRSI;

    /*  Multi threaded version of the custom XY profile over reflectivity points */
    /*  for standardTF reflectivity calculation.  */
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
    /* Pre-Allocation... */
    if (problemDef->numberOfContrasts != problemDef->numberOfContrasts) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &nd_emlrtDCI, &st);
    }

    emxInit_real_T(&st, &backgs, 1, &nq_emlrtRTEI, true);
    i1 = backgs->size[0];
    backgs->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, backgs, i1, &nq_emlrtRTEI);
    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &cd_emlrtDCI, &st);
    }

    i1 = problem->nbairs->size[0];
    problem->nbairs->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, problem->nbairs, i1, &br_emlrtRTEI);
    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &od_emlrtDCI, &st);
    }

    for (i1 = 0; i1 < loop_ub; i1++) {
      problem->nbairs->data[i1] = 0.0;
    }

    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &pd_emlrtDCI, &st);
    }

    i1 = problem->ssubs->size[0];
    problem->ssubs->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, problem->ssubs, i1, &cr_emlrtRTEI);
    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &pd_emlrtDCI, &st);
    }

    for (i1 = 0; i1 < loop_ub; i1++) {
      problem->ssubs->data[i1] = 0.0;
    }

    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ad_emlrtDCI, &st);
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &jd_emlrtRTEI, &st);
    i = reflectivity->size[0];
    reflectivity->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_9(&st, reflectivity, i, &dr_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      if (b_i > reflectivity->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
          &jt_emlrtBCI, &st);
      }

      i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->
        size[1];
      reflectivity->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i, &er_emlrtRTEI);
      if (b_i > reflectivity->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
          &jt_emlrtBCI, &st);
      }

      i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->
        size[1];
      reflectivity->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i, &er_emlrtRTEI);
      i = reflectivity->size[0];
      if (b_i > reflectivity->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
          &jt_emlrtBCI, &st);
      }

      if (b_i > reflectivity->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
          &jt_emlrtBCI, &st);
      }

      if (b_i > reflectivity->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
          &iv_emlrtBCI, &st);
      }

      reflectivity->data[b_i].f1->data[0] = 1.0;
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &iv_emlrtBCI, &st);
      }

      reflectivity->data[b_i].f1->data[1] = 1.0;
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &iv_emlrtBCI, &st);
      }

      reflectivity->data[b_i].f1->data[2] = 1.0;
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &iv_emlrtBCI, &st);
      }

      reflectivity->data[b_i].f1->data[3] = 1.0;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    /* coder.varsize('reflectivity{:}',[10000 2],[1 0]); */
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &kd_emlrtRTEI, &st);
    i = Simulation->size[0];
    Simulation->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_9(&st, Simulation, i, &dr_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      if (b_i > Simulation->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
          &kt_emlrtBCI, &st);
      }

      i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
      Simulation->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, Simulation->data[b_i].f1, i, &fr_emlrtRTEI);
      if (b_i > Simulation->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
          &kt_emlrtBCI, &st);
      }

      i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
      Simulation->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, Simulation->data[b_i].f1, i, &fr_emlrtRTEI);
      i = Simulation->size[0];
      if (b_i > Simulation->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
          &kt_emlrtBCI, &st);
      }

      if (b_i > Simulation->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
          &kt_emlrtBCI, &st);
      }

      if (b_i > Simulation->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
          &jv_emlrtBCI, &st);
      }

      Simulation->data[b_i].f1->data[0] = 1.0;
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &jv_emlrtBCI, &st);
      }

      Simulation->data[b_i].f1->data[1] = 1.0;
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &jv_emlrtBCI, &st);
      }

      Simulation->data[b_i].f1->data[2] = 1.0;
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &jv_emlrtBCI, &st);
      }

      Simulation->data[b_i].f1->data[3] = 1.0;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    /* coder.varsize('Simulation{:}',[10000 2],[1 0]); */
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &ld_emlrtRTEI, &st);
    i = allLayers->size[0];
    allLayers->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_14(&st, allLayers, i, &dr_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
          &lt_emlrtBCI, &st);
      }

      i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
      allLayers->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i, &gr_emlrtRTEI);
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
          &lt_emlrtBCI, &st);
      }

      i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
      allLayers->data[b_i].f1->size[1] = 1;
      emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i, &gr_emlrtRTEI);
      i = allLayers->size[0];
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
          &lt_emlrtBCI, &st);
      }

      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
          &lt_emlrtBCI, &st);
      }

      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
          &kv_emlrtBCI, &st);
      }

      allLayers->data[b_i].f1->data[0] = 1.0;
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &kv_emlrtBCI, &st);
      }

      allLayers->data[b_i].f1->data[1] = 1.0;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    /* coder.varsize('allLayers{:}',[10000 3],[1 1]); */
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &md_emlrtRTEI, &st);
    i = problem->qshifts->size[0];
    problem->qshifts->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, problem->qshifts, i, &nq_emlrtRTEI);
    i = problem->scalefactors->size[0];
    problem->scalefactors->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, problem->scalefactors, i, &nq_emlrtRTEI);
    i = problem->nbsubs->size[0];
    problem->nbsubs->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, problem->nbsubs, i, &nq_emlrtRTEI);
    i = problem->resolutions->size[0];
    problem->resolutions->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, problem->resolutions, i, &nq_emlrtRTEI);
    i = problem->allSubRough->size[0];
    problem->allSubRough->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, problem->allSubRough, i, &nq_emlrtRTEI);
    i = sldProfiles->size[0];
    sldProfiles->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_14(&st, sldProfiles, i, &dr_emlrtRTEI);
    i = layerSlds->size[0];
    layerSlds->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_10(&st, layerSlds, i, &dr_emlrtRTEI);
    i = allLayers->size[0];
    allLayers->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_14(&st, allLayers, i, &dr_emlrtRTEI);
    i = shifted_data->size[0];
    shifted_data->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_14(&st, shifted_data, i, &dr_emlrtRTEI);
    i = problem->calculations.all_chis->size[0];
    problem->calculations.all_chis->size[0] = loop_ub;
    emxEnsureCapacity_real_T(&st, problem->calculations.all_chis, i,
      &nq_emlrtRTEI);
    i = Simulation->size[0];
    Simulation->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_9(&st, Simulation, i, &dr_emlrtRTEI);
    i = reflectivity->size[0];
    reflectivity->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_9(&st, reflectivity, i, &dr_emlrtRTEI);
    emxInit_real_T(&st, &layerSld, 2, &qr_emlrtRTEI, true);
    emxInit_real_T(&st, &shifted_dat, 2, &rr_emlrtRTEI, true);
    emxInit_real_T(&st, &sldProfile, 2, &pr_emlrtRTEI, true);
    emxInit_real_T(&st, &reflect, 2, &pr_emlrtRTEI, true);
    emxInit_real_T(&st, &Simul, 2, &pr_emlrtRTEI, true);
    emxInit_real_T(&st, &b_problemDef_cells, 2, &lr_emlrtRTEI, true);
    emxInit_real_T(&st, &b_problem, 1, &hr_emlrtRTEI, true);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      if ((int32_T)(b_i + 1U) > problemDef->contrastBacks->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
          problemDef->contrastBacks->size[1], &ut_emlrtBCI, &st);
      }

      if ((int32_T)(b_i + 1U) > problemDef->contrastShifts->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
          problemDef->contrastShifts->size[1], &vt_emlrtBCI, &st);
      }

      if ((int32_T)(b_i + 1U) > problemDef->contrastScales->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
          problemDef->contrastScales->size[1], &wt_emlrtBCI, &st);
      }

      if ((int32_T)(b_i + 1U) > problemDef->contrastNbas->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
          problemDef->contrastNbas->size[1], &xt_emlrtBCI, &st);
      }

      if ((int32_T)(b_i + 1U) > problemDef->contrastNbss->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
          problemDef->contrastNbss->size[1], &yt_emlrtBCI, &st);
      }

      if ((int32_T)(b_i + 1U) > problemDef->contrastRes->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
          problemDef->contrastRes->size[1], &au_emlrtBCI, &st);
      }

      if ((int32_T)(b_i + 1U) > backgs->size[0]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, backgs->size[0],
          &bu_emlrtBCI, &st);
      }

      if ((int32_T)(b_i + 1U) > problem->qshifts->size[0]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, problem->
          qshifts->size[0], &cu_emlrtBCI, &st);
      }

      if ((int32_T)(b_i + 1U) > problem->scalefactors->size[0]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
          problem->scalefactors->size[0], &du_emlrtBCI, &st);
      }

      if ((int32_T)(b_i + 1U) > problem->nbairs->size[0]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, problem->
          nbairs->size[0], &eu_emlrtBCI, &st);
      }

      if ((int32_T)(b_i + 1U) > problem->nbsubs->size[0]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, problem->
          nbsubs->size[0], &fu_emlrtBCI, &st);
      }

      if ((int32_T)(b_i + 1U) > problem->resolutions->size[0]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
          problem->resolutions->size[0], &gu_emlrtBCI, &st);
      }

      b_st.site = &gi_emlrtRSI;
      backSort(&b_st, problemDef->contrastBacks->data[b_i],
               problemDef->contrastShifts->data[b_i], problemDef->
               contrastScales->data[b_i], problemDef->contrastNbas->data[b_i],
               problemDef->contrastNbss->data[b_i], problemDef->
               contrastRes->data[b_i], problemDef->backs, problemDef->shifts,
               problemDef->sf, problemDef->nba, problemDef->nbs, problemDef->res,
               &backgs->data[b_i], &problem->qshifts->data[b_i],
               &problem->scalefactors->data[b_i], &problem->nbairs->data[b_i],
               &problem->nbsubs->data[b_i], &problem->resolutions->data[b_i]);
      if ((int32_T)(b_i + 1U) > problemDef->contrastCustomFiles->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
          problemDef->contrastCustomFiles->size[1], &hu_emlrtBCI, &st);
      }

      d = problemDef->contrastCustomFiles->data[b_i];
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &bd_emlrtDCI, &st);
      }

      if (((int32_T)d - 1 < 0) || ((int32_T)d - 1 > problemDef_cells->f14->size
           [1] - 1)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d - 1, 0, problemDef_cells->
          f14->size[1] - 1, &ct_emlrtBCI, &st);
      }

      if ((int32_T)(b_i + 1U) > problem->nbsubs->size[0]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, problem->
          nbsubs->size[0], &iu_emlrtBCI, &st);
      }

      if ((int32_T)(b_i + 1U) > problem->allSubRough->size[0]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
          problem->allSubRough->size[0], &ju_emlrtBCI, &st);
      }

      i = b_problem->size[0];
      b_problem->size[0] = problem->nbairs->size[0];
      emxEnsureCapacity_real_T(&st, b_problem, i, &hr_emlrtRTEI);
      kstr = problem->nbairs->size[0] - 1;
      for (i = 0; i <= kstr; i++) {
        b_problem->data[i] = problem->nbairs->data[i];
      }

      b_st.site = &hi_emlrtRSI;
      b_call_customLayers(&b_st, problemDef->params, (real_T)b_i + 1.0,
                          problemDef_cells->f14->data[(int32_T)
                          problemDef->contrastCustomFiles->data[b_i] - 1].f1,
                          b_problem, problem->nbsubs->data[b_i], loop_ub,
                          sldProfile, &problem->allSubRough->data[b_i]);
      kstr = sldProfile->size[0] * sldProfile->size[1];
      if (b_i > sldProfiles->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
          &mt_emlrtBCI, &st);
      }

      i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
      sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
      emxEnsureCapacity_real_T(&st, sldProfiles->data[b_i].f1, i, &ir_emlrtRTEI);
      if (b_i > sldProfiles->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
          &mt_emlrtBCI, &st);
      }

      i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
      sldProfiles->data[b_i].f1->size[1] = sldProfile->size[1];
      emxEnsureCapacity_real_T(&st, sldProfiles->data[b_i].f1, i, &ir_emlrtRTEI);
      i = sldProfiles->size[0];
      if (b_i > sldProfiles->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
          &mt_emlrtBCI, &st);
      }

      if (b_i > sldProfiles->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
          &mt_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &ku_emlrtBCI, &st);
        }

        sldProfiles->data[b_i].f1->data[i1] = sldProfile->data[i1];
      }

      b_st.site = &ii_emlrtRSI;
      b_resampleLayers(&b_st, sldProfile, controls->resamPars, layerSld);
      kstr = layerSld->size[0] * layerSld->size[1];
      if (b_i > layerSlds->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
          &nt_emlrtBCI, &st);
      }

      i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
      layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
      emxEnsureCapacity_real_T(&st, layerSlds->data[b_i].f1, i, &jr_emlrtRTEI);
      if (b_i > layerSlds->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
          &nt_emlrtBCI, &st);
      }

      i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
      layerSlds->data[b_i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(&st, layerSlds->data[b_i].f1, i, &jr_emlrtRTEI);
      i = layerSlds->size[0];
      if (b_i > layerSlds->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
          &nt_emlrtBCI, &st);
      }

      if (b_i > layerSlds->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
          &nt_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &lu_emlrtBCI, &st);
        }

        layerSlds->data[b_i].f1->data[i1] = layerSld->data[i1];
      }

      kstr = layerSld->size[0] * layerSld->size[1];
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
          &ot_emlrtBCI, &st);
      }

      i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
      allLayers->data[b_i].f1->size[0] = layerSld->size[0];
      emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i, &kr_emlrtRTEI);
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
          &ot_emlrtBCI, &st);
      }

      i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
      allLayers->data[b_i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i, &kr_emlrtRTEI);
      i = allLayers->size[0];
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
          &ot_emlrtBCI, &st);
      }

      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
          &ot_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &mu_emlrtBCI, &st);
        }

        allLayers->data[b_i].f1->data[i1] = layerSld->data[i1];
      }

      if (b_i + 1 > problem->scalefactors->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, problem->scalefactors->size[0],
          &nu_emlrtBCI, &st);
      }

      if (b_i + 1 > problem->qshifts->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, problem->qshifts->size[0],
          &ou_emlrtBCI, &st);
      }

      if (b_i + 1 > problemDef->dataPresent->size[1]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, problemDef->dataPresent->size
          [1], &pu_emlrtBCI, &st);
      }

      if (b_i > problemDef_cells->f2->size[1] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f2->size[1] - 1,
          &qu_emlrtBCI, &st);
      }

      if (b_i > problemDef_cells->f3->size[1] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f3->size[1] - 1,
          &ru_emlrtBCI, &st);
      }

      if (b_i > problemDef_cells->f4->size[1] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f4->size[1] - 1,
          &su_emlrtBCI, &st);
      }

      i = b_problemDef_cells->size[0] * b_problemDef_cells->size[1];
      b_problemDef_cells->size[0] = problemDef_cells->f2->data[b_i].f1->size[0];
      b_problemDef_cells->size[1] = problemDef_cells->f2->data[b_i].f1->size[1];
      emxEnsureCapacity_real_T(&st, b_problemDef_cells, i, &lr_emlrtRTEI);
      kstr = problemDef_cells->f2->data[b_i].f1->size[0] * problemDef_cells->
        f2->data[b_i].f1->size[1] - 1;
      for (i = 0; i <= kstr; i++) {
        b_problemDef_cells->data[i] = problemDef_cells->f2->data[b_i].f1->data[i];
      }

      b_st.site = &ji_emlrtRSI;
      shiftdata(&b_st, problem->scalefactors->data[b_i], problem->qshifts->
                data[b_i], problemDef->dataPresent->data[b_i],
                b_problemDef_cells, problemDef_cells->f3->data[b_i].f1, (real_T *)
                problemDef_cells->f4->data[b_i].f1->data, problemDef_cells->
                f4->data[b_i].f1->size, shifted_dat);
      kstr = shifted_dat->size[0] * shifted_dat->size[1];
      if (b_i > shifted_data->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
          &pt_emlrtBCI, &st);
      }

      i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->
        size[1];
      shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
      emxEnsureCapacity_real_T(&st, shifted_data->data[b_i].f1, i, &mr_emlrtRTEI);
      if (b_i > shifted_data->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
          &pt_emlrtBCI, &st);
      }

      i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->
        size[1];
      shifted_data->data[b_i].f1->size[1] = shifted_dat->size[1];
      emxEnsureCapacity_real_T(&st, shifted_data->data[b_i].f1, i, &mr_emlrtRTEI);
      i = shifted_data->size[0];
      if (b_i > shifted_data->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
          &pt_emlrtBCI, &st);
      }

      if (b_i > shifted_data->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
          &pt_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &tu_emlrtBCI, &st);
        }

        shifted_data->data[b_i].f1->data[i1] = shifted_dat->data[i1];
      }

      i = b_i + 1;
      if (i > loop_ub) {
        emlrtDynamicBoundsCheckR2012b(i, 1, loop_ub, &xs_emlrtBCI, &st);
      }

      if (b_i + 1 > problem->nbairs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, problem->nbairs->size[0],
          &uu_emlrtBCI, &st);
      }

      if (b_i + 1 > problem->nbsubs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, problem->nbsubs->size[0],
          &vu_emlrtBCI, &st);
      }

      if (b_i > problemDef_cells->f4->size[1] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f4->size[1] - 1,
          &wu_emlrtBCI, &st);
      }

      if (b_i > problemDef_cells->f1->size[1] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f1->size[1] - 1,
          &xu_emlrtBCI, &st);
      }

      if (b_i + 1 > problem->resolutions->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, problem->resolutions->size[0],
          &yu_emlrtBCI, &st);
      }

      b_st.site = &ki_emlrtRSI;
      b_callReflectivity(&b_st, problem->nbairs->data[b_i], problem->
                         nbsubs->data[b_i], (real_T *)problemDef_cells->f4->
                         data[b_i].f1->data, problemDef_cells->f4->data[b_i].
                         f1->size, problemDef_cells->f1->data[b_i].f1,
                         shifted_dat, layerSld, 0.0, problem->resolutions->
                         data[b_i], reflect, Simul);
      b_st.site = &li_emlrtRSI;
      i = b_i + 1;
      if (i > backgs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &ys_emlrtBCI, &b_st);
      }

      i = b_i + 1;
      if (i > problemDef->contrastBacksType->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastBacksType->size
          [1], &at_emlrtBCI, &b_st);
      }

      if (problemDef->contrastBacksType->data[b_i] != (int32_T)
          muDoubleScalarFloor(problemDef->contrastBacksType->data[b_i])) {
        emlrtIntegerCheckR2012b(problemDef->contrastBacksType->data[b_i],
          &cb_emlrtDCI, &b_st);
      }

      switch ((int32_T)problemDef->contrastBacksType->data[b_i]) {
       case 1:
        /* Add background to the simulation */
        kstr = reflect->size[0] * reflect->size[1];
        i = reflect->size[0] * reflect->size[1];
        reflect->size[1] = 2;
        emxEnsureCapacity_real_T(&b_st, reflect, i, &ph_emlrtRTEI);
        for (i = 0; i < kstr; i++) {
          reflect->data[i] += backgs->data[b_i];
        }

        kstr = Simul->size[0] * Simul->size[1];
        i = Simul->size[0] * Simul->size[1];
        Simul->size[1] = 2;
        emxEnsureCapacity_real_T(&b_st, Simul, i, &rh_emlrtRTEI);
        for (i = 0; i < kstr; i++) {
          Simul->data[i] += backgs->data[b_i];
        }
        break;

       case 2:
        /*          %Subtract the background from the data.. */
        if (2 > shifted_dat->size[1]) {
          emlrtDynamicBoundsCheckR2012b(2, 1, shifted_dat->size[1], &re_emlrtBCI,
            &b_st);
        }

        emlrtSubAssignSizeCheckR2012b(&shifted_dat->size[0], 1,
          &shifted_dat->size[0], 1, &emlrtECI, &b_st);
        kstr = shifted_dat->size[0] - 1;
        i = b_problem->size[0];
        b_problem->size[0] = shifted_dat->size[0];
        emxEnsureCapacity_real_T(&b_st, b_problem, i, &qh_emlrtRTEI);
        for (i = 0; i <= kstr; i++) {
          b_problem->data[i] = shifted_dat->data[i + shifted_dat->size[0]] -
            backgs->data[b_i];
        }

        kstr = b_problem->size[0];
        for (i = 0; i < kstr; i++) {
          shifted_dat->data[i + shifted_dat->size[0]] = b_problem->data[i];
        }

        /* shifted_dat(:,3) = shifted_dat(:,3) - backg;    */
        break;
      }

      kstr = reflect->size[0] * reflect->size[1];
      if (b_i > reflectivity->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
          &qt_emlrtBCI, &st);
      }

      i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->
        size[1];
      reflectivity->data[b_i].f1->size[0] = reflect->size[0];
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i, &nr_emlrtRTEI);
      if (b_i > reflectivity->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
          &qt_emlrtBCI, &st);
      }

      i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->
        size[1];
      reflectivity->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i, &nr_emlrtRTEI);
      i = reflectivity->size[0];
      if (b_i > reflectivity->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
          &qt_emlrtBCI, &st);
      }

      if (b_i > reflectivity->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
          &qt_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &av_emlrtBCI, &st);
        }

        reflectivity->data[b_i].f1->data[i1] = reflect->data[i1];
      }

      kstr = Simul->size[0] * Simul->size[1];
      if (b_i > Simulation->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
          &rt_emlrtBCI, &st);
      }

      i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
      Simulation->data[b_i].f1->size[0] = Simul->size[0];
      emxEnsureCapacity_real_T(&st, Simulation->data[b_i].f1, i, &or_emlrtRTEI);
      if (b_i > Simulation->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
          &rt_emlrtBCI, &st);
      }

      i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
      Simulation->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, Simulation->data[b_i].f1, i, &or_emlrtRTEI);
      i = Simulation->size[0];
      if (b_i > Simulation->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
          &rt_emlrtBCI, &st);
      }

      if (b_i > Simulation->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
          &rt_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &bv_emlrtBCI, &st);
        }

        Simulation->data[b_i].f1->data[i1] = Simul->data[i1];
      }

      i = b_i + 1;
      if (i > problemDef->dataPresent->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->dataPresent->size[1],
          &bt_emlrtBCI, &st);
      }

      b_st.site = &mi_emlrtRSI;
      if (muDoubleScalarIsNaN(problemDef->dataPresent->data[b_i])) {
        emlrtErrorWithMessageIdR2018a(&b_st, &nd_emlrtRTEI,
          "MATLAB:nologicalnan", "MATLAB:nologicalnan", 0);
      }

      if (problemDef->dataPresent->data[b_i] != 0.0) {
        if (b_i + 1 > problem->calculations.all_chis->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
            problem->calculations.all_chis->size[0], &dv_emlrtBCI, &st);
        }

        b_st.site = &ni_emlrtRSI;
        problem->calculations.all_chis->data[b_i] = chiSquared(&b_st,
          shifted_dat, reflect, problemDef->params->size[1]);
      } else {
        if (b_i + 1 > problem->calculations.all_chis->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
            problem->calculations.all_chis->size[0], &cv_emlrtBCI, &st);
        }

        problem->calculations.all_chis->data[b_i] = 0.0;
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    emxFree_real_T(&b_problem);
    emxFree_real_T(&b_problemDef_cells);
    emxFree_real_T(&Simul);
    emxFree_real_T(&reflect);
    emxFree_real_T(&sldProfile);
    emxFree_real_T(&shifted_dat);
    emxFree_real_T(&layerSld);
    i = problem->backgrounds->size[0];
    problem->backgrounds->size[0] = backgs->size[0];
    emxEnsureCapacity_real_T(sp, problem->backgrounds, i, &nq_emlrtRTEI);
    loop_ub = backgs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->backgrounds->data[i] = backgs->data[i];
    }

    emxFree_real_T(&backgs);
    break;

   case 2:
    emxInit_cell_wrap_9(sp, &b_reflectivity, 1, &pr_emlrtRTEI, true);
    emxInit_cell_wrap_12(sp, &r, 1, &pr_emlrtRTEI, true);
    emxInit_cell_wrap_12(sp, &r1, 1, &pr_emlrtRTEI, true);
    emxInit_cell_wrap_28(sp, &r2, 1, &pr_emlrtRTEI, true);
    st.site = &vh_emlrtRSI;
    standardTF_custXY_paraContrasts(&st, problemDef, problemDef_cells, controls,
      problem->ssubs, problem->backgrounds, problem->qshifts,
      problem->scalefactors, problem->nbairs, problem->nbsubs,
      problem->resolutions, problem->calculations.all_chis, r, r1, shifted_data,
      layerSlds, sldProfiles, r2, problem->allSubRough);
    i = b_reflectivity->size[0];
    b_reflectivity->size[0] = r->size[0];
    emxEnsureCapacity_cell_wrap_9(sp, b_reflectivity, i, &wq_emlrtRTEI);
    i = r->size[0];
    for (i1 = 0; i1 < i; i1++) {
      kstr = b_reflectivity->data[i1].f1->size[0] * b_reflectivity->data[i1].
        f1->size[1];
      b_reflectivity->data[i1].f1->size[0] = r->data[i1].f1->size[0];
      b_reflectivity->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, b_reflectivity->data[i1].f1, kstr,
        &wq_emlrtRTEI);
      loop_ub = r->data[i1].f1->size[0] * r->data[i1].f1->size[1];
      for (kstr = 0; kstr < loop_ub; kstr++) {
        b_reflectivity->data[i1].f1->data[kstr] = r->data[i1].f1->data[kstr];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    emxFree_cell_wrap_12(&r);
    emxInit_cell_wrap_9(sp, &b_Simulation, 1, &pr_emlrtRTEI, true);
    i = b_Simulation->size[0];
    b_Simulation->size[0] = r1->size[0];
    emxEnsureCapacity_cell_wrap_9(sp, b_Simulation, i, &wq_emlrtRTEI);
    i = r1->size[0];
    for (i1 = 0; i1 < i; i1++) {
      kstr = b_Simulation->data[i1].f1->size[0] * b_Simulation->data[i1]
        .f1->size[1];
      b_Simulation->data[i1].f1->size[0] = r1->data[i1].f1->size[0];
      b_Simulation->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, b_Simulation->data[i1].f1, kstr,
        &wq_emlrtRTEI);
      loop_ub = r1->data[i1].f1->size[0] * r1->data[i1].f1->size[1];
      for (kstr = 0; kstr < loop_ub; kstr++) {
        b_Simulation->data[i1].f1->data[kstr] = r1->data[i1].f1->data[kstr];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    emxFree_cell_wrap_12(&r1);
    emxInit_cell_wrap_14(sp, &b_allLayers, 1, &pr_emlrtRTEI, true);
    i = b_allLayers->size[0];
    b_allLayers->size[0] = r2->size[0];
    emxEnsureCapacity_cell_wrap_14(sp, b_allLayers, i, &yq_emlrtRTEI);
    i = r2->size[0];
    for (i1 = 0; i1 < i; i1++) {
      kstr = b_allLayers->data[i1].f1->size[0] * b_allLayers->data[i1].f1->size
        [1];
      b_allLayers->data[i1].f1->size[0] = r2->data[i1].f1->size[0];
      b_allLayers->data[i1].f1->size[1] = r2->data[i1].f1->size[1];
      emxEnsureCapacity_real_T(sp, b_allLayers->data[i1].f1, kstr, &yq_emlrtRTEI);
      loop_ub = r2->data[i1].f1->size[0] * r2->data[i1].f1->size[1];
      for (kstr = 0; kstr < loop_ub; kstr++) {
        b_allLayers->data[i1].f1->data[kstr] = r2->data[i1].f1->data[kstr];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    emxFree_cell_wrap_28(&r2);
    i = reflectivity->size[0];
    reflectivity->size[0] = b_reflectivity->size[0];
    emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &wq_emlrtRTEI);
    loop_ub = b_reflectivity->size[0];
    for (i = 0; i < loop_ub; i++) {
      emxCopyStruct_cell_wrap_9(sp, &reflectivity->data[i],
        &b_reflectivity->data[i], &wq_emlrtRTEI);
    }

    emxFree_cell_wrap_9(&b_reflectivity);
    i = Simulation->size[0];
    Simulation->size[0] = b_Simulation->size[0];
    emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &ar_emlrtRTEI);
    loop_ub = b_Simulation->size[0];
    for (i = 0; i < loop_ub; i++) {
      emxCopyStruct_cell_wrap_9(sp, &Simulation->data[i], &b_Simulation->data[i],
        &ar_emlrtRTEI);
    }

    emxFree_cell_wrap_9(&b_Simulation);
    i = allLayers->size[0];
    allLayers->size[0] = b_allLayers->size[0];
    emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &yq_emlrtRTEI);
    loop_ub = b_allLayers->size[0];
    for (i = 0; i < loop_ub; i++) {
      emxCopyStruct_cell_wrap_14(sp, &allLayers->data[i], &b_allLayers->data[i],
        &yq_emlrtRTEI);
    }

    emxFree_cell_wrap_14(&b_allLayers);
    break;
  }

  st.site = &wh_emlrtRSI;
  problem->calculations.sum_chi = sum(&st, problem->calculations.all_chis);
  i = problem->resample->size[0] * problem->resample->size[1];
  problem->resample->size[0] = 1;
  problem->resample->size[1] = problem->allSubRough->size[0];
  emxEnsureCapacity_real_T(sp, problem->resample, i, &xq_emlrtRTEI);
  loop_ub = problem->allSubRough->size[0];
  for (i = 0; i < loop_ub; i++) {
    problem->resample->data[i] = 1.0;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_custXY_reflectivityCalculation.c) */
