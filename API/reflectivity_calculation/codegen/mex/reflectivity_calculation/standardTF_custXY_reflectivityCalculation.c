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
#include "applyBackgroundCorrection.h"
#include "backSort.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "matlabEngineCaller_customLayers.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"
#include "standardTF_custXY_single.h"
#include "sum.h"

/* Variable Definitions */
static emlrtRSInfo fi_emlrtRSI = { 102,/* lineNo */
  "standardTF_custXY_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo gi_emlrtRSI = { 149,/* lineNo */
  "standardTF_custXY_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo hi_emlrtRSI = { 252,/* lineNo */
  "standardTF_custXY_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pathName */
};

static emlrtRSInfo qi_emlrtRSI = { 85, /* lineNo */
  "standardTF_custXY_paraPoints",      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pathName */
};

static emlrtRSInfo ri_emlrtRSI = { 87, /* lineNo */
  "standardTF_custXY_paraPoints",      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pathName */
};

static emlrtRSInfo si_emlrtRSI = { 96, /* lineNo */
  "standardTF_custXY_paraPoints",      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pathName */
};

static emlrtRSInfo ti_emlrtRSI = { 103,/* lineNo */
  "standardTF_custXY_paraPoints",      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pathName */
};

static emlrtRSInfo ui_emlrtRSI = { 106,/* lineNo */
  "standardTF_custXY_paraPoints",      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pathName */
};

static emlrtRSInfo vi_emlrtRSI = { 108,/* lineNo */
  "standardTF_custXY_paraPoints",      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pathName */
};

static emlrtRSInfo wi_emlrtRSI = { 113,/* lineNo */
  "standardTF_custXY_paraPoints",      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pathName */
};

static emlrtBCInfo vq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  97,                                  /* colNo */
  "backsType",                         /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ar_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  87,                                  /* colNo */
  "backgs",                            /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo br_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  128,                                 /* colNo */
  "resols",                            /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  69,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  56,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo er_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  48,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  40,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  73,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ir_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  47,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  36,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  29,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  62,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo or_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  17,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  50,                                  /* colNo */
  "resols",                            /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  27,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ur_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  16,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  6,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  122,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  113,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  104,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo as_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  93,                                  /* colNo */
  "cScales",                           /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  82,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  72,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ds_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo es_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo cc_emlrtDCI = { 58, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo gs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  94,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo is_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo js_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ks_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ls_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo dc_emlrtDCI = { 253,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo ec_emlrtDCI = { 250,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo fc_emlrtDCI = { 57, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo gc_emlrtDCI = { 249,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo hc_emlrtDCI = { 248,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo ic_emlrtDCI = { 247,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo jc_emlrtDCI = { 246,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo kc_emlrtDCI = { 245,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo lc_emlrtDCI = { 245,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo mc_emlrtDCI = { 51, /* lineNo */
  16,                                  /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo nc_emlrtDCI = { 60, /* lineNo */
  18,                                  /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo bb_emlrtECI = { 1,  /* nDims */
  111,                                 /* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtECInfo cb_emlrtECI = { 1,  /* nDims */
  110,                                 /* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtBCInfo ns_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  125,                                 /* colNo */
  "backgs",                            /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo os_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  115,                                 /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ps_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  80,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  72,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo vc_emlrtRTEI = { 84,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = { 78,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo xc_emlrtRTEI = { 72,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo yc_emlrtRTEI = { 66,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = { 93,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = { 87,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo cd_emlrtRTEI = { 81,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo dd_emlrtRTEI = { 75,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ed_emlrtRTEI = { 68,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo fd_emlrtRTEI = { 62,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtDCInfo oc_emlrtDCI = { 61, /* lineNo */
  21,                                  /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo rs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  19,                                  /* colNo */
  "params",                            /* aName */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo bp_emlrtRTEI = { 244,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo cp_emlrtRTEI = { 245,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo dp_emlrtRTEI = { 246,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ep_emlrtRTEI = { 247,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo fp_emlrtRTEI = { 248,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo gp_emlrtRTEI = { 249,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo hp_emlrtRTEI = { 57,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo ip_emlrtRTEI = { 250,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo jp_emlrtRTEI = { 253,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo kp_emlrtRTEI = { 1,/* lineNo */
  91,                                  /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo lp_emlrtRTEI = { 63,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo mp_emlrtRTEI = { 69,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo np_emlrtRTEI = { 76,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo op_emlrtRTEI = { 82,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo pp_emlrtRTEI = { 88,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo qp_emlrtRTEI = { 94,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo rp_emlrtRTEI = { 251,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pName */
};

static emlrtRTEInfo sp_emlrtRTEI = { 58,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo tp_emlrtRTEI = { 67,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo up_emlrtRTEI = { 73,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo vp_emlrtRTEI = { 79,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo wp_emlrtRTEI = { 93,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo yp_emlrtRTEI = { 97,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo aq_emlrtRTEI = { 103,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo bq_emlrtRTEI = { 104,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo cq_emlrtRTEI = { 110,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo dq_emlrtRTEI = { 111,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

static emlrtRTEInfo eq_emlrtRTEI = { 96,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraPoints",      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraPoints.m"/* pName */
};

/* Function Definitions */
void c_standardTF_custXY_reflectivit(const emlrtStack *sp, const struct0_T
  *problemDef, const cell_13 *problemDef_cells, const struct2_T *controls,
  struct4_T *problem, emxArray_cell_wrap_14 *reflectivity, emxArray_cell_wrap_8 *
  Simulation, emxArray_cell_wrap_9 *shifted_data, emxArray_cell_wrap_9
  *layerSlds, emxArray_cell_wrap_8 *sldProfiles, emxArray_cell_wrap_15
  *allLayers)
{
  int32_T i;
  int32_T loop_ub;
  int32_T i1;
  emxArray_real_T *chis;
  int32_T b_i;
  int32_T kstr;
  boolean_T b_bool;
  int32_T exitg1;
  emxArray_cell_wrap_6 *b_reflectivity;
  static const char_T b_cv[6] = { 's', 'i', 'n', 'g', 'l', 'e' };

  emxArray_cell_wrap_6 *b_Simulation;
  emxArray_cell_wrap_1 *b_shifted_data;
  emxArray_cell_wrap_1 *b_layerSlds;
  static const char_T b_cv1[6] = { 'p', 'o', 'i', 'n', 't', 's' };

  emxArray_cell_wrap_6 *b_sldProfiles;
  emxArray_cell_wrap_11 *b_allLayers;
  emxArray_cell_wrap_8 *r;
  emxArray_cell_wrap_8 *r1;
  emxArray_cell_wrap_15 *r2;
  emxArray_real_T *backgs;
  emxArray_real_T *qshifts;
  emxArray_real_T *sfs;
  emxArray_real_T *nbas;
  emxArray_real_T *nbss;
  emxArray_real_T *resols;
  emxArray_real_T *allRoughs;
  emxArray_real_T *layerSld;
  emxArray_real_T *shifted_dat;
  emxArray_real_T *Simul;
  emxArray_real_T *b_shifted_dat;
  real_T layers;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* Extract individual parameters from problemDef */
  /* nbairs = problemDef.nbairs; */
  /* nbsubs = problemDef.nbsubs; */
  /* repeats = problemDef.repeatLayers; */
  /* allData = problemDef.allData; */
  /* dataLimits = problemDef.dataLimits; */
  /* simLimits = problemDef.simLimits; */
  /* repeatLayers = problemDef.repeatLayers; */
  /* contrastLayers = problemDef.contrastLayers; */
  /* layersDetails = problemDef.layersDetails; */
  /* Pre-allocation */
  if (1 > problemDef->params->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, problemDef->params->size[1],
      &rs_emlrtBCI, sp);
  }

  i = problem->ssubs->size[0];
  problem->ssubs->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->ssubs, i, &bp_emlrtRTEI);
  problem->ssubs->data[0] = problemDef->params->data[0];
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &kc_emlrtDCI, sp);
  }

  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &lc_emlrtDCI, sp);
  }

  loop_ub = (int32_T)problemDef->numberOfContrasts;
  i1 = problem->backgrounds->size[0];
  problem->backgrounds->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->backgrounds, i1, &cp_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &lc_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->backgrounds->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &jc_emlrtDCI, sp);
  }

  i1 = problem->qshifts->size[0];
  problem->qshifts->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->qshifts, i1, &dp_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &jc_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->qshifts->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ic_emlrtDCI, sp);
  }

  i1 = problem->scalefactors->size[0];
  problem->scalefactors->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->scalefactors, i1, &ep_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ic_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->scalefactors->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &hc_emlrtDCI, sp);
  }

  i1 = problem->nbairs->size[0];
  problem->nbairs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->nbairs, i1, &fp_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &hc_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->nbairs->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &gc_emlrtDCI, sp);
  }

  i1 = problem->nbsubs->size[0];
  problem->nbsubs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->nbsubs, i1, &gp_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &gc_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->nbsubs->data[i1] = 0.0;
  }

  emxInit_real_T(sp, &chis, 1, &hp_emlrtRTEI, true);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &fc_emlrtDCI, sp);
  }

  i1 = chis->size[0];
  chis->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, chis, i1, &hp_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &fc_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    chis->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ec_emlrtDCI, sp);
  }

  i1 = problem->resolutions->size[0];
  problem->resolutions->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->resolutions, i1, &ip_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ec_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->resolutions->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &dc_emlrtDCI, sp);
  }

  i1 = problem->allSubRough->size[0];
  problem->allSubRough->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, problem->allSubRough, i1, &jp_emlrtRTEI);
  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &dc_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->allSubRough->data[i1] = 0.0;
  }

  if ((int32_T)problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &oc_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &fd_emlrtRTEI, sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_14(sp, reflectivity, i1, &kp_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ls_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &lp_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ls_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &lp_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    kstr = reflectivity->size[0] - 1;
    if (b_i > kstr) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &ls_emlrtBCI, sp);
    }

    kstr = reflectivity->size[0] - 1;
    if (b_i > kstr) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &ls_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ls_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ls_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ls_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ls_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &ed_emlrtRTEI, sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, Simulation, i1, &kp_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ks_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &mp_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ks_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &mp_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    kstr = Simulation->size[0] - 1;
    if (b_i > kstr) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &ks_emlrtBCI, sp);
    }

    kstr = Simulation->size[0] - 1;
    if (b_i > kstr) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &ks_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ks_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ks_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ks_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ks_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &dd_emlrtRTEI, sp);
  i1 = shifted_data->size[0];
  shifted_data->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_9(sp, shifted_data, i1, &kp_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &js_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i1, &np_emlrtRTEI);
    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &js_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i1, &np_emlrtRTEI);
    i1 = shifted_data->size[0] - 1;
    kstr = shifted_data->size[0] - 1;
    if (b_i > kstr) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &js_emlrtBCI, sp);
    }

    kstr = shifted_data->size[0] - 1;
    if (b_i > kstr) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &js_emlrtBCI, sp);
    }

    for (kstr = 0; kstr < 6; kstr++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &js_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[kstr] = 1.0;
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &cd_emlrtRTEI, sp);
  i1 = layerSlds->size[0];
  layerSlds->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_9(sp, layerSlds, i1, &kp_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = layerSlds->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &is_emlrtBCI, sp);
    }

    i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &op_emlrtRTEI);
    i1 = layerSlds->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &is_emlrtBCI, sp);
    }

    i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &op_emlrtRTEI);
    i1 = layerSlds->size[0] - 1;
    kstr = layerSlds->size[0] - 1;
    if (b_i > kstr) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &is_emlrtBCI, sp);
    }

    kstr = layerSlds->size[0] - 1;
    if (b_i > kstr) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &is_emlrtBCI, sp);
    }

    for (kstr = 0; kstr < 6; kstr++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &is_emlrtBCI, sp);
      }

      layerSlds->data[b_i].f1->data[kstr] = 1.0;
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &bd_emlrtRTEI, sp);
  i1 = sldProfiles->size[0];
  sldProfiles->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, sldProfiles, i1, &kp_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hs_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &pp_emlrtRTEI);
    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hs_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &pp_emlrtRTEI);
    i1 = sldProfiles->size[0] - 1;
    kstr = sldProfiles->size[0] - 1;
    if (b_i > kstr) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &hs_emlrtBCI, sp);
    }

    kstr = sldProfiles->size[0] - 1;
    if (b_i > kstr) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &hs_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hs_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hs_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hs_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hs_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[3] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &ad_emlrtRTEI, sp);
  i1 = allLayers->size[0];
  allLayers->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_15(sp, allLayers, i1, &kp_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &gs_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &qp_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &gs_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &qp_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    kstr = allLayers->size[0] - 1;
    if (b_i > kstr) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &gs_emlrtBCI, sp);
    }

    kstr = allLayers->size[0] - 1;
    if (b_i > kstr) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &gs_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &gs_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &gs_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
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
      kstr = -1;
    }
  }

  emxInit_cell_wrap_6(sp, &b_reflectivity, 1, &kp_emlrtRTEI, true);
  emxInit_cell_wrap_6(sp, &b_Simulation, 1, &kp_emlrtRTEI, true);
  emxInit_cell_wrap_1(sp, &b_shifted_data, 1, &kp_emlrtRTEI, true);
  emxInit_cell_wrap_1(sp, &b_layerSlds, 1, &kp_emlrtRTEI, true);
  emxInit_cell_wrap_6(sp, &b_sldProfiles, 1, &kp_emlrtRTEI, true);
  emxInit_cell_wrap_11(sp, &b_allLayers, 1, &kp_emlrtRTEI, true);
  emxInit_cell_wrap_8(sp, &r, 1, &kp_emlrtRTEI, true);
  emxInit_cell_wrap_8(sp, &r1, 1, &kp_emlrtRTEI, true);
  emxInit_cell_wrap_15(sp, &r2, 1, &kp_emlrtRTEI, true);
  switch (kstr) {
   case 0:
    st.site = &fi_emlrtRSI;
    standardTF_custXY_single(&st, problemDef->numberOfContrasts,
      problemDef_cells->f1, problemDef->contrastBacks,
      problemDef->contrastShifts, problemDef->contrastScales,
      problemDef->contrastNbas, problemDef->contrastNbss,
      problemDef->contrastRes, problemDef->backs, problemDef->shifts,
      problemDef->sf, problemDef->nba, problemDef->nbs, problemDef->res,
      problemDef->dataPresent, problemDef_cells->f2, problemDef_cells->f3,
      problemDef_cells->f4, problemDef->params->size[1], problemDef->params,
      problemDef->modelFilename, problemDef->path, problemDef->contrastBacksType,
      problem->ssubs, problem->backgrounds, problem->qshifts,
      problem->scalefactors, problem->nbairs, problem->nbsubs,
      problem->resolutions, chis, r, r1, b_shifted_data, b_layerSlds,
      b_sldProfiles, r2, problem->allSubRough);
    i = b_reflectivity->size[0];
    b_reflectivity->size[0] = r->size[0];
    emxEnsureCapacity_cell_wrap_6(sp, b_reflectivity, i, &sf_emlrtRTEI);
    i = r->size[0];
    for (i1 = 0; i1 < i; i1++) {
      kstr = b_reflectivity->data[i1].f1->size[0] * b_reflectivity->data[i1].
        f1->size[1];
      b_reflectivity->data[i1].f1->size[0] = r->data[i1].f1->size[0];
      b_reflectivity->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, b_reflectivity->data[i1].f1, kstr,
        &sf_emlrtRTEI);
      loop_ub = r->data[i1].f1->size[0] * r->data[i1].f1->size[1];
      for (kstr = 0; kstr < loop_ub; kstr++) {
        b_reflectivity->data[i1].f1->data[kstr] = r->data[i1].f1->data[kstr];
      }
    }

    i = b_Simulation->size[0];
    b_Simulation->size[0] = r1->size[0];
    emxEnsureCapacity_cell_wrap_6(sp, b_Simulation, i, &sf_emlrtRTEI);
    i = r1->size[0];
    for (i1 = 0; i1 < i; i1++) {
      kstr = b_Simulation->data[i1].f1->size[0] * b_Simulation->data[i1]
        .f1->size[1];
      b_Simulation->data[i1].f1->size[0] = r1->data[i1].f1->size[0];
      b_Simulation->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, b_Simulation->data[i1].f1, kstr,
        &sf_emlrtRTEI);
      loop_ub = r1->data[i1].f1->size[0] * r1->data[i1].f1->size[1];
      for (kstr = 0; kstr < loop_ub; kstr++) {
        b_Simulation->data[i1].f1->data[kstr] = r1->data[i1].f1->data[kstr];
      }
    }

    i = b_allLayers->size[0];
    b_allLayers->size[0] = r2->size[0];
    emxEnsureCapacity_cell_wrap_111(sp, b_allLayers, i, &vf_emlrtRTEI);
    i = r2->size[0];
    for (i1 = 0; i1 < i; i1++) {
      kstr = b_allLayers->data[i1].f1->size[0] * b_allLayers->data[i1].f1->size
        [1];
      b_allLayers->data[i1].f1->size[0] = r2->data[i1].f1->size[0];
      b_allLayers->data[i1].f1->size[1] = r2->data[i1].f1->size[1];
      emxEnsureCapacity_real_T(sp, b_allLayers->data[i1].f1, kstr, &vf_emlrtRTEI);
      loop_ub = r2->data[i1].f1->size[0] * r2->data[i1].f1->size[1];
      for (kstr = 0; kstr < loop_ub; kstr++) {
        b_allLayers->data[i1].f1->data[kstr] = r2->data[i1].f1->data[kstr];
      }
    }

    i = reflectivity->size[0];
    reflectivity->size[0] = b_reflectivity->size[0];
    emxEnsureCapacity_cell_wrap_14(sp, reflectivity, i, &sf_emlrtRTEI);
    i = b_reflectivity->size[0];
    for (i1 = 0; i1 < i; i1++) {
      kstr = reflectivity->data[i1].f1->size[0] * reflectivity->data[i1]
        .f1->size[1];
      reflectivity->data[i1].f1->size[0] = b_reflectivity->data[i1].f1->size[0];
      reflectivity->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, reflectivity->data[i1].f1, kstr,
        &sf_emlrtRTEI);
      loop_ub = b_reflectivity->data[i1].f1->size[0] * b_reflectivity->data[i1].
        f1->size[1];
      for (kstr = 0; kstr < loop_ub; kstr++) {
        reflectivity->data[i1].f1->data[kstr] = b_reflectivity->data[i1]
          .f1->data[kstr];
      }
    }

    i = Simulation->size[0];
    Simulation->size[0] = b_Simulation->size[0];
    emxEnsureCapacity_cell_wrap_8(sp, Simulation, i, &pe_emlrtRTEI);
    i = b_Simulation->size[0];
    for (i1 = 0; i1 < i; i1++) {
      kstr = Simulation->data[i1].f1->size[0] * Simulation->data[i1].f1->size[1];
      Simulation->data[i1].f1->size[0] = b_Simulation->data[i1].f1->size[0];
      Simulation->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, Simulation->data[i1].f1, kstr, &pe_emlrtRTEI);
      loop_ub = b_Simulation->data[i1].f1->size[0] * b_Simulation->data[i1]
        .f1->size[1];
      for (kstr = 0; kstr < loop_ub; kstr++) {
        Simulation->data[i1].f1->data[kstr] = b_Simulation->data[i1].f1->
          data[kstr];
      }
    }

    i = shifted_data->size[0];
    shifted_data->size[0] = b_shifted_data->size[0];
    emxEnsureCapacity_cell_wrap_9(sp, shifted_data, i, &qe_emlrtRTEI);
    i = b_shifted_data->size[0];
    for (i1 = 0; i1 < i; i1++) {
      kstr = shifted_data->data[i1].f1->size[0] * shifted_data->data[i1]
        .f1->size[1];
      shifted_data->data[i1].f1->size[0] = b_shifted_data->data[i1].f1->size[0];
      shifted_data->data[i1].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, shifted_data->data[i1].f1, kstr,
        &qe_emlrtRTEI);
      loop_ub = b_shifted_data->data[i1].f1->size[0] * b_shifted_data->data[i1].
        f1->size[1];
      for (kstr = 0; kstr < loop_ub; kstr++) {
        shifted_data->data[i1].f1->data[kstr] = b_shifted_data->data[i1]
          .f1->data[kstr];
      }
    }

    i = layerSlds->size[0];
    layerSlds->size[0] = b_layerSlds->size[0];
    emxEnsureCapacity_cell_wrap_9(sp, layerSlds, i, &qe_emlrtRTEI);
    i = b_layerSlds->size[0];
    for (i1 = 0; i1 < i; i1++) {
      kstr = layerSlds->data[i1].f1->size[0] * layerSlds->data[i1].f1->size[1];
      layerSlds->data[i1].f1->size[0] = b_layerSlds->data[i1].f1->size[0];
      layerSlds->data[i1].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, layerSlds->data[i1].f1, kstr, &qe_emlrtRTEI);
      loop_ub = b_layerSlds->data[i1].f1->size[0] * b_layerSlds->data[i1]
        .f1->size[1];
      for (kstr = 0; kstr < loop_ub; kstr++) {
        layerSlds->data[i1].f1->data[kstr] = b_layerSlds->data[i1].f1->data[kstr];
      }
    }

    i = sldProfiles->size[0];
    sldProfiles->size[0] = b_sldProfiles->size[0];
    emxEnsureCapacity_cell_wrap_8(sp, sldProfiles, i, &pe_emlrtRTEI);
    i = b_sldProfiles->size[0];
    for (i1 = 0; i1 < i; i1++) {
      kstr = sldProfiles->data[i1].f1->size[0] * sldProfiles->data[i1].f1->size
        [1];
      sldProfiles->data[i1].f1->size[0] = b_sldProfiles->data[i1].f1->size[0];
      sldProfiles->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, sldProfiles->data[i1].f1, kstr, &pe_emlrtRTEI);
      loop_ub = b_sldProfiles->data[i1].f1->size[0] * b_sldProfiles->data[i1].
        f1->size[1];
      for (kstr = 0; kstr < loop_ub; kstr++) {
        sldProfiles->data[i1].f1->data[kstr] = b_sldProfiles->data[i1].f1->
          data[kstr];
      }
    }

    i = allLayers->size[0];
    allLayers->size[0] = b_allLayers->size[0];
    emxEnsureCapacity_cell_wrap_15(sp, allLayers, i, &vf_emlrtRTEI);
    i = b_allLayers->size[0];
    for (i1 = 0; i1 < i; i1++) {
      kstr = allLayers->data[i1].f1->size[0] * allLayers->data[i1].f1->size[1];
      allLayers->data[i1].f1->size[0] = b_allLayers->data[i1].f1->size[0];
      allLayers->data[i1].f1->size[1] = b_allLayers->data[i1].f1->size[1];
      emxEnsureCapacity_real_T(sp, allLayers->data[i1].f1, kstr, &vf_emlrtRTEI);
      loop_ub = b_allLayers->data[i1].f1->size[0] * b_allLayers->data[i1]
        .f1->size[1];
      for (kstr = 0; kstr < loop_ub; kstr++) {
        allLayers->data[i1].f1->data[kstr] = b_allLayers->data[i1].f1->data[kstr];
      }
    }
    break;

   case 1:
    st.site = &gi_emlrtRSI;

    /* coder.extrinsic('callModules');             */
    /* Pre-Allocation... */
    if ((int32_T)problemDef->numberOfContrasts != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &mc_emlrtDCI, &st);
    }

    i1 = problem->ssubs->size[0];
    problem->ssubs->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, problem->ssubs, i1, &sp_emlrtRTEI);
    if ((int32_T)problemDef->numberOfContrasts != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &cc_emlrtDCI, &st);
    }

    for (i1 = 0; i1 < loop_ub; i1++) {
      problem->ssubs->data[i1] = 0.0;
    }

    if ((int32_T)problemDef->numberOfContrasts != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &nc_emlrtDCI, &st);
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &yc_emlrtRTEI, &st);
    i = r->size[0];
    r->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_8(&st, r, i, &jp_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = r->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &fs_emlrtBCI, &st);
      }

      i = r->data[b_i].f1->size[0] * r->data[b_i].f1->size[1];
      r->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, r->data[b_i].f1, i, &tp_emlrtRTEI);
      i = r->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &fs_emlrtBCI, &st);
      }

      i = r->data[b_i].f1->size[0] * r->data[b_i].f1->size[1];
      r->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, r->data[b_i].f1, i, &tp_emlrtRTEI);
      i = r->size[0] - 1;
      i1 = r->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &fs_emlrtBCI, &st);
      }

      i1 = r->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &fs_emlrtBCI, &st);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &fs_emlrtBCI, &st);
      }

      r->data[b_i].f1->data[0] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &fs_emlrtBCI, &st);
      }

      r->data[b_i].f1->data[1] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &fs_emlrtBCI, &st);
      }

      r->data[b_i].f1->data[2] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &fs_emlrtBCI, &st);
      }

      r->data[b_i].f1->data[3] = 1.0;
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &xc_emlrtRTEI, &st);
    i = r1->size[0];
    r1->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_8(&st, r1, i, &jp_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = r1->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &es_emlrtBCI, &st);
      }

      i = r1->data[b_i].f1->size[0] * r1->data[b_i].f1->size[1];
      r1->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, r1->data[b_i].f1, i, &up_emlrtRTEI);
      i = r1->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &es_emlrtBCI, &st);
      }

      i = r1->data[b_i].f1->size[0] * r1->data[b_i].f1->size[1];
      r1->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, r1->data[b_i].f1, i, &up_emlrtRTEI);
      i = r1->size[0] - 1;
      i1 = r1->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &es_emlrtBCI, &st);
      }

      i1 = r1->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &es_emlrtBCI, &st);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &es_emlrtBCI, &st);
      }

      r1->data[b_i].f1->data[0] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &es_emlrtBCI, &st);
      }

      r1->data[b_i].f1->data[1] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &es_emlrtBCI, &st);
      }

      r1->data[b_i].f1->data[2] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &es_emlrtBCI, &st);
      }

      r1->data[b_i].f1->data[3] = 1.0;
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &wc_emlrtRTEI, &st);
    i = r2->size[0];
    r2->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_15(&st, r2, i, &jp_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = r2->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ds_emlrtBCI, &st);
      }

      i = r2->data[b_i].f1->size[0] * r2->data[b_i].f1->size[1];
      r2->data[b_i].f1->size[0] = 2;
      emxEnsureCapacity_real_T(&st, r2->data[b_i].f1, i, &vp_emlrtRTEI);
      i = r2->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ds_emlrtBCI, &st);
      }

      i = r2->data[b_i].f1->size[0] * r2->data[b_i].f1->size[1];
      r2->data[b_i].f1->size[1] = 1;
      emxEnsureCapacity_real_T(&st, r2->data[b_i].f1, i, &vp_emlrtRTEI);
      i = r2->size[0] - 1;
      i1 = r2->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ds_emlrtBCI, &st);
      }

      i1 = r2->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ds_emlrtBCI, &st);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ds_emlrtBCI, &st);
      }

      r2->data[b_i].f1->data[0] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ds_emlrtBCI, &st);
      }

      r2->data[b_i].f1->data[1] = 1.0;
    }

    emxInit_real_T(&st, &backgs, 1, &jp_emlrtRTEI, true);
    emxInit_real_T(&st, &qshifts, 1, &jp_emlrtRTEI, true);
    emxInit_real_T(&st, &sfs, 1, &jp_emlrtRTEI, true);
    emxInit_real_T(&st, &nbas, 1, &jp_emlrtRTEI, true);
    emxInit_real_T(&st, &nbss, 1, &jp_emlrtRTEI, true);
    emxInit_real_T(&st, &resols, 1, &jp_emlrtRTEI, true);
    emxInit_real_T(&st, &allRoughs, 1, &jp_emlrtRTEI, true);
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &vc_emlrtRTEI, &st);
    i = backgs->size[0];
    backgs->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, backgs, i, &jp_emlrtRTEI);
    i = qshifts->size[0];
    qshifts->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, qshifts, i, &jp_emlrtRTEI);
    i = sfs->size[0];
    sfs->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, sfs, i, &jp_emlrtRTEI);
    i = nbas->size[0];
    nbas->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, nbas, i, &jp_emlrtRTEI);
    i = nbss->size[0];
    nbss->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, nbss, i, &jp_emlrtRTEI);
    i = resols->size[0];
    resols->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, resols, i, &jp_emlrtRTEI);
    i = allRoughs->size[0];
    allRoughs->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, allRoughs, i, &jp_emlrtRTEI);
    i = r2->size[0];
    r2->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_15(&st, r2, i, &jp_emlrtRTEI);
    i = b_sldProfiles->size[0];
    b_sldProfiles->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_6(&st, b_sldProfiles, i, &jp_emlrtRTEI);
    i = b_layerSlds->size[0];
    b_layerSlds->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_1(&st, b_layerSlds, i, &jp_emlrtRTEI);
    i = b_shifted_data->size[0];
    b_shifted_data->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_1(&st, b_shifted_data, i, &jp_emlrtRTEI);
    i = chis->size[0];
    chis->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_real_T(&st, chis, i, &jp_emlrtRTEI);
    i = r1->size[0];
    r1->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_8(&st, r1, i, &jp_emlrtRTEI);
    i = r->size[0];
    r->size[0] = (int32_T)problemDef->numberOfContrasts;
    emxEnsureCapacity_cell_wrap_8(&st, r, i, &jp_emlrtRTEI);
    emxInit_real_T(&st, &layerSld, 2, &eq_emlrtRTEI, true);
    emxInit_real_T(&st, &shifted_dat, 2, &aq_emlrtRTEI, true);
    emxInit_real_T(&st, &Simul, 2, &kp_emlrtRTEI, true);
    emxInit_real_T(&st, &b_shifted_dat, 2, &xp_emlrtRTEI, true);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = (int32_T)(b_i + 1U);
      if (i > resols->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, resols->size[0], &qr_emlrtBCI, &st);
      }

      if (i > nbss->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, nbss->size[0], &rr_emlrtBCI, &st);
      }

      if (i > nbas->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, nbas->size[0], &sr_emlrtBCI, &st);
      }

      if (i > sfs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, sfs->size[0], &tr_emlrtBCI, &st);
      }

      if (i > qshifts->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, qshifts->size[0], &ur_emlrtBCI, &st);
      }

      if (i > backgs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &vr_emlrtBCI, &st);
      }

      if (i > problemDef->contrastRes->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastRes->size[1],
          &wr_emlrtBCI, &st);
      }

      if (i > problemDef->contrastNbss->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastNbss->size[1],
          &xr_emlrtBCI, &st);
      }

      if (i > problemDef->contrastNbas->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastNbas->size[1],
          &yr_emlrtBCI, &st);
      }

      if (i > problemDef->contrastScales->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastScales->size[1],
          &as_emlrtBCI, &st);
      }

      if (i > problemDef->contrastShifts->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastShifts->size[1],
          &bs_emlrtBCI, &st);
      }

      if (i > problemDef->contrastBacks->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastBacks->size[1],
          &cs_emlrtBCI, &st);
      }

      b_st.site = &qi_emlrtRSI;
      backSort(&b_st, problemDef->contrastBacks->data[i - 1],
               problemDef->contrastShifts->data[i - 1],
               problemDef->contrastScales->data[i - 1], problemDef->
               contrastNbas->data[i - 1], problemDef->contrastNbss->data[i - 1],
               problemDef->contrastRes->data[i - 1], problemDef->backs,
               problemDef->shifts, problemDef->sf, problemDef->nba,
               problemDef->nbs, problemDef->res, &backgs->data[i - 1],
               &qshifts->data[i - 1], &sfs->data[i - 1], &nbas->data[i - 1],
               &nbss->data[i - 1], &resols->data[i - 1]);
      b_st.site = &ri_emlrtRSI;
      i1 = b_i + 1;
      if (i1 > nbas->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, nbas->size[0], &qs_emlrtBCI, &b_st);
      }

      i1 = b_i + 1;
      if (i1 > nbss->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &ps_emlrtBCI, &b_st);
      }

      c_st.site = &pi_emlrtRSI;
      matlabEngineCaller_customLayers(&c_st, problemDef->params, (real_T)b_i +
        1.0, problemDef->modelFilename, problemDef->path, nbas->data[b_i],
        nbss->data[b_i], shifted_dat, &layers);
      if (1 > problemDef->params->size[1]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, problemDef->params->size[1],
          &ms_emlrtBCI, &b_st);
      }

      if (i > allRoughs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, allRoughs->size[0], &pr_emlrtBCI,
          &b_st);
      }

      allRoughs->data[i - 1] = problemDef->params->data[0];
      i = r2->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &or_emlrtBCI, &st);
      }

      r2->data[b_i].f1->size[0] = 0;
      i = r2->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &or_emlrtBCI, &st);
      }

      r2->data[b_i].f1->size[1] = 0;
      i = r2->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &or_emlrtBCI, &st);
      }

      i = r2->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &or_emlrtBCI, &st);
      }

      /* [outLayers, outSsubs(i)] = groupLayers_Mod(outLayers,allRoughs(i),geometry,nbas(i),nbss(i)); */
      /* sldProfile = makeSLDProfiles(nbas(i),nbss(i),outLayers,outSsubs(i),repeatLayers{i}); */
      i = b_sldProfiles->size[0] - 1;
      kstr = shifted_dat->size[0];
      i1 = b_sldProfiles->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &nr_emlrtBCI, &st);
      }

      i1 = b_sldProfiles->data[b_i].f1->size[0] * b_sldProfiles->data[b_i]
        .f1->size[1];
      b_sldProfiles->data[b_i].f1->size[0] = shifted_dat->size[0];
      emxEnsureCapacity_real_T(&st, b_sldProfiles->data[b_i].f1, i1,
        &wp_emlrtRTEI);
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nr_emlrtBCI, &st);
      }

      i1 = b_sldProfiles->data[b_i].f1->size[0] * b_sldProfiles->data[b_i]
        .f1->size[1];
      b_sldProfiles->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, b_sldProfiles->data[b_i].f1, i1,
        &wp_emlrtRTEI);
      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nr_emlrtBCI, &st);
        }

        b_sldProfiles->data[b_i].f1->data[i1] = shifted_dat->data[i1];
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nr_emlrtBCI, &st);
        }

        b_sldProfiles->data[b_i].f1->data[i1 + b_sldProfiles->data[b_i].f1->
          size[0]] = shifted_dat->data[i1 + shifted_dat->size[0]];
      }

      /* if resample(i) == 1 */
      kstr = shifted_dat->size[0];
      i = b_shifted_dat->size[0] * b_shifted_dat->size[1];
      b_shifted_dat->size[0] = shifted_dat->size[0];
      b_shifted_dat->size[1] = 2;
      emxEnsureCapacity_real_T(&st, b_shifted_dat, i, &xp_emlrtRTEI);
      for (i = 0; i < kstr; i++) {
        b_shifted_dat->data[i] = shifted_dat->data[i];
      }

      for (i = 0; i < kstr; i++) {
        b_shifted_dat->data[i + b_shifted_dat->size[0]] = shifted_dat->data[i +
          shifted_dat->size[0]];
      }

      b_st.site = &si_emlrtRSI;
      resampleLayers(&b_st, b_shifted_dat, layerSld);
      kstr = layerSld->size[0] * layerSld->size[1];
      i = b_layerSlds->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &mr_emlrtBCI, &st);
      }

      i = b_layerSlds->data[b_i].f1->size[0] * b_layerSlds->data[b_i].f1->size[1];
      b_layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
      emxEnsureCapacity_real_T(&st, b_layerSlds->data[b_i].f1, i, &yp_emlrtRTEI);
      i = b_layerSlds->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &mr_emlrtBCI, &st);
      }

      i = b_layerSlds->data[b_i].f1->size[0] * b_layerSlds->data[b_i].f1->size[1];
      b_layerSlds->data[b_i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(&st, b_layerSlds->data[b_i].f1, i, &yp_emlrtRTEI);
      i = b_layerSlds->size[0] - 1;
      i1 = b_layerSlds->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &mr_emlrtBCI, &st);
      }

      i1 = b_layerSlds->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &mr_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &mr_emlrtBCI, &st);
        }

        b_layerSlds->data[b_i].f1->data[i1] = layerSld->data[i1];
      }

      /* else */
      /*    layerSld = outLayers; */
      /*    layerSlds{i} = layerSld; */
      /* end */
      i = problemDef_cells->f2->size[1] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &lr_emlrtBCI, &st);
      }

      i = shifted_dat->size[0] * shifted_dat->size[1];
      shifted_dat->size[0] = problemDef_cells->f2->data[b_i].f1->size[0];
      shifted_dat->size[1] = 3;
      emxEnsureCapacity_real_T(&st, shifted_dat, i, &aq_emlrtRTEI);
      i = problemDef_cells->f2->size[1] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &lr_emlrtBCI, &st);
      }

      i = problemDef_cells->f2->size[1] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &lr_emlrtBCI, &st);
      }

      kstr = problemDef_cells->f2->data[b_i].f1->size[0] * problemDef_cells->
        f2->data[b_i].f1->size[1];
      for (i = 0; i < kstr; i++) {
        i1 = problemDef_cells->f2->size[1] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &lr_emlrtBCI, &st);
        }

        i1 = problemDef_cells->f2->size[1] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &lr_emlrtBCI, &st);
        }

        i1 = problemDef_cells->f2->size[1] - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &lr_emlrtBCI, &st);
        }

        shifted_dat->data[i] = problemDef_cells->f2->data[b_i].f1->data[i];
      }

      i = problemDef_cells->f3->size[1] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &hr_emlrtBCI, &st);
      }

      i = b_i + 1;
      if (i > problemDef->dataPresent->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->dataPresent->size[1],
          &ir_emlrtBCI, &st);
      }

      i1 = b_i + 1;
      if (i1 > qshifts->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, qshifts->size[0], &jr_emlrtBCI, &st);
      }

      kstr = b_i + 1;
      if (kstr > sfs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(kstr, 1, sfs->size[0], &kr_emlrtBCI, &st);
      }

      b_st.site = &ti_emlrtRSI;
      shiftdata(&b_st, sfs->data[kstr - 1], qshifts->data[i1 - 1],
                problemDef->dataPresent->data[i - 1], shifted_dat,
                problemDef_cells->f3->data[b_i].f1);
      kstr = shifted_dat->size[0] * shifted_dat->size[1];
      i = b_shifted_data->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &gr_emlrtBCI, &st);
      }

      i = b_shifted_data->data[b_i].f1->size[0] * b_shifted_data->data[b_i]
        .f1->size[1];
      b_shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
      emxEnsureCapacity_real_T(&st, b_shifted_data->data[b_i].f1, i,
        &bq_emlrtRTEI);
      i = b_shifted_data->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &gr_emlrtBCI, &st);
      }

      i = b_shifted_data->data[b_i].f1->size[0] * b_shifted_data->data[b_i]
        .f1->size[1];
      b_shifted_data->data[b_i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(&st, b_shifted_data->data[b_i].f1, i,
        &bq_emlrtRTEI);
      i = b_shifted_data->size[0] - 1;
      i1 = b_shifted_data->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &gr_emlrtBCI, &st);
      }

      i1 = b_shifted_data->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &gr_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &gr_emlrtBCI, &st);
        }

        b_shifted_data->data[b_i].f1->data[i1] = shifted_dat->data[i1];
      }

      i = b_i + 1;
      if (i > backgs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &ns_emlrtBCI, &st);
      }

      i = b_i + 1;
      if (i > loop_ub) {
        emlrtDynamicBoundsCheckR2012b(i, 1, loop_ub, &os_emlrtBCI, &st);
      }

      i = b_i + 1;
      if (i > resols->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, resols->size[0], &br_emlrtBCI, &st);
      }

      i1 = problemDef_cells->f1->size[1] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &cr_emlrtBCI, &st);
      }

      i1 = problemDef_cells->f4->size[1] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &dr_emlrtBCI, &st);
      }

      i1 = b_i + 1;
      if (i1 > nbss->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &er_emlrtBCI, &st);
      }

      kstr = b_i + 1;
      if (kstr > nbas->size[0]) {
        emlrtDynamicBoundsCheckR2012b(kstr, 1, nbas->size[0], &fr_emlrtBCI, &st);
      }

      b_st.site = &ui_emlrtRSI;
      b_callReflectivity(&b_st, nbas->data[kstr - 1], nbss->data[i1 - 1],
                         problemDef_cells->f4->data[b_i].f1,
                         problemDef_cells->f1->data[b_i].f1, shifted_dat,
                         layerSld, 0.0, resols->data[i - 1], b_shifted_dat,
                         Simul);
      i = b_i + 1;
      if (i > problemDef->contrastBacksType->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastBacksType->size
          [1], &yq_emlrtBCI, &st);
      }

      i1 = b_i + 1;
      if (i1 > backgs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, backgs->size[0], &ar_emlrtBCI, &st);
      }

      b_st.site = &vi_emlrtRSI;
      applyBackgroundCorrection(&b_st, b_shifted_dat, Simul, shifted_dat,
        backgs->data[i1 - 1], problemDef->contrastBacksType->data[i - 1]);
      if (10000 < b_shifted_dat->size[0]) {
        emlrtDimSizeGeqCheckR2012b(10000, b_shifted_dat->size[0], &cb_emlrtECI,
          &st);
      }

      kstr = b_shifted_dat->size[0] * b_shifted_dat->size[1];
      i = r->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xq_emlrtBCI, &st);
      }

      i = r->data[b_i].f1->size[0] * r->data[b_i].f1->size[1];
      r->data[b_i].f1->size[0] = b_shifted_dat->size[0];
      emxEnsureCapacity_real_T(&st, r->data[b_i].f1, i, &cq_emlrtRTEI);
      i = r->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xq_emlrtBCI, &st);
      }

      i = r->data[b_i].f1->size[0] * r->data[b_i].f1->size[1];
      r->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, r->data[b_i].f1, i, &cq_emlrtRTEI);
      i = r->size[0] - 1;
      i1 = r->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &xq_emlrtBCI, &st);
      }

      i1 = r->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &xq_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xq_emlrtBCI, &st);
        }

        r->data[b_i].f1->data[i1] = b_shifted_dat->data[i1];
      }

      if (10000 < Simul->size[0]) {
        emlrtDimSizeGeqCheckR2012b(10000, Simul->size[0], &bb_emlrtECI, &st);
      }

      kstr = Simul->size[0] * Simul->size[1];
      i = r1->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &wq_emlrtBCI, &st);
      }

      i = r1->data[b_i].f1->size[0] * r1->data[b_i].f1->size[1];
      r1->data[b_i].f1->size[0] = Simul->size[0];
      emxEnsureCapacity_real_T(&st, r1->data[b_i].f1, i, &dq_emlrtRTEI);
      i = r1->size[0] - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &wq_emlrtBCI, &st);
      }

      i = r1->data[b_i].f1->size[0] * r1->data[b_i].f1->size[1];
      r1->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, r1->data[b_i].f1, i, &dq_emlrtRTEI);
      i = r1->size[0] - 1;
      i1 = r1->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &wq_emlrtBCI, &st);
      }

      i1 = r1->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &wq_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &wq_emlrtBCI, &st);
        }

        r1->data[b_i].f1->data[i1] = Simul->data[i1];
      }

      i = b_i + 1;
      if (i > chis->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, chis->size[0], &vq_emlrtBCI, &st);
      }

      b_st.site = &wi_emlrtRSI;
      chis->data[i - 1] = chiSquared(&b_st, shifted_dat, b_shifted_dat,
        problemDef->params->size[1]);
    }

    emxFree_real_T(&b_shifted_dat);
    emxFree_real_T(&Simul);
    emxFree_real_T(&shifted_dat);
    emxFree_real_T(&layerSld);
    i = problem->backgrounds->size[0];
    problem->backgrounds->size[0] = backgs->size[0];
    emxEnsureCapacity_real_T(sp, problem->backgrounds, i, &jp_emlrtRTEI);
    loop_ub = backgs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->backgrounds->data[i] = backgs->data[i];
    }

    emxFree_real_T(&backgs);
    i = problem->qshifts->size[0];
    problem->qshifts->size[0] = qshifts->size[0];
    emxEnsureCapacity_real_T(sp, problem->qshifts, i, &jp_emlrtRTEI);
    loop_ub = qshifts->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->qshifts->data[i] = qshifts->data[i];
    }

    emxFree_real_T(&qshifts);
    i = problem->scalefactors->size[0];
    problem->scalefactors->size[0] = sfs->size[0];
    emxEnsureCapacity_real_T(sp, problem->scalefactors, i, &jp_emlrtRTEI);
    loop_ub = sfs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->scalefactors->data[i] = sfs->data[i];
    }

    emxFree_real_T(&sfs);
    i = problem->nbairs->size[0];
    problem->nbairs->size[0] = nbas->size[0];
    emxEnsureCapacity_real_T(sp, problem->nbairs, i, &jp_emlrtRTEI);
    loop_ub = nbas->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->nbairs->data[i] = nbas->data[i];
    }

    emxFree_real_T(&nbas);
    i = problem->nbsubs->size[0];
    problem->nbsubs->size[0] = nbss->size[0];
    emxEnsureCapacity_real_T(sp, problem->nbsubs, i, &jp_emlrtRTEI);
    loop_ub = nbss->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->nbsubs->data[i] = nbss->data[i];
    }

    emxFree_real_T(&nbss);
    i = problem->resolutions->size[0];
    problem->resolutions->size[0] = resols->size[0];
    emxEnsureCapacity_real_T(sp, problem->resolutions, i, &jp_emlrtRTEI);
    loop_ub = resols->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->resolutions->data[i] = resols->data[i];
    }

    emxFree_real_T(&resols);
    i = problem->allSubRough->size[0];
    problem->allSubRough->size[0] = allRoughs->size[0];
    emxEnsureCapacity_real_T(sp, problem->allSubRough, i, &jp_emlrtRTEI);
    loop_ub = allRoughs->size[0];
    for (i = 0; i < loop_ub; i++) {
      problem->allSubRough->data[i] = allRoughs->data[i];
    }

    emxFree_real_T(&allRoughs);
    i = b_reflectivity->size[0];
    b_reflectivity->size[0] = r->size[0];
    emxEnsureCapacity_cell_wrap_6(sp, b_reflectivity, i, &sf_emlrtRTEI);
    i = r->size[0];
    for (i1 = 0; i1 < i; i1++) {
      kstr = b_reflectivity->data[i1].f1->size[0] * b_reflectivity->data[i1].
        f1->size[1];
      b_reflectivity->data[i1].f1->size[0] = r->data[i1].f1->size[0];
      b_reflectivity->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, b_reflectivity->data[i1].f1, kstr,
        &sf_emlrtRTEI);
      loop_ub = r->data[i1].f1->size[0] * r->data[i1].f1->size[1];
      for (kstr = 0; kstr < loop_ub; kstr++) {
        b_reflectivity->data[i1].f1->data[kstr] = r->data[i1].f1->data[kstr];
      }
    }

    i = b_Simulation->size[0];
    b_Simulation->size[0] = r1->size[0];
    emxEnsureCapacity_cell_wrap_6(sp, b_Simulation, i, &sf_emlrtRTEI);
    i = r1->size[0];
    for (i1 = 0; i1 < i; i1++) {
      kstr = b_Simulation->data[i1].f1->size[0] * b_Simulation->data[i1]
        .f1->size[1];
      b_Simulation->data[i1].f1->size[0] = r1->data[i1].f1->size[0];
      b_Simulation->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, b_Simulation->data[i1].f1, kstr,
        &sf_emlrtRTEI);
      loop_ub = r1->data[i1].f1->size[0] * r1->data[i1].f1->size[1];
      for (kstr = 0; kstr < loop_ub; kstr++) {
        b_Simulation->data[i1].f1->data[kstr] = r1->data[i1].f1->data[kstr];
      }
    }

    i = b_allLayers->size[0];
    b_allLayers->size[0] = r2->size[0];
    emxEnsureCapacity_cell_wrap_111(sp, b_allLayers, i, &vf_emlrtRTEI);
    i = r2->size[0];
    for (i1 = 0; i1 < i; i1++) {
      kstr = b_allLayers->data[i1].f1->size[0] * b_allLayers->data[i1].f1->size
        [1];
      b_allLayers->data[i1].f1->size[0] = r2->data[i1].f1->size[0];
      b_allLayers->data[i1].f1->size[1] = r2->data[i1].f1->size[1];
      emxEnsureCapacity_real_T(sp, b_allLayers->data[i1].f1, kstr, &vf_emlrtRTEI);
      loop_ub = r2->data[i1].f1->size[0] * r2->data[i1].f1->size[1];
      for (kstr = 0; kstr < loop_ub; kstr++) {
        b_allLayers->data[i1].f1->data[kstr] = r2->data[i1].f1->data[kstr];
      }
    }

    i = reflectivity->size[0];
    reflectivity->size[0] = b_reflectivity->size[0];
    emxEnsureCapacity_cell_wrap_14(sp, reflectivity, i, &sf_emlrtRTEI);
    i = b_reflectivity->size[0];
    for (i1 = 0; i1 < i; i1++) {
      kstr = reflectivity->data[i1].f1->size[0] * reflectivity->data[i1]
        .f1->size[1];
      reflectivity->data[i1].f1->size[0] = b_reflectivity->data[i1].f1->size[0];
      reflectivity->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, reflectivity->data[i1].f1, kstr,
        &sf_emlrtRTEI);
      loop_ub = b_reflectivity->data[i1].f1->size[0] * b_reflectivity->data[i1].
        f1->size[1];
      for (kstr = 0; kstr < loop_ub; kstr++) {
        reflectivity->data[i1].f1->data[kstr] = b_reflectivity->data[i1]
          .f1->data[kstr];
      }
    }

    i = Simulation->size[0];
    Simulation->size[0] = b_Simulation->size[0];
    emxEnsureCapacity_cell_wrap_8(sp, Simulation, i, &pe_emlrtRTEI);
    i = b_Simulation->size[0];
    for (i1 = 0; i1 < i; i1++) {
      kstr = Simulation->data[i1].f1->size[0] * Simulation->data[i1].f1->size[1];
      Simulation->data[i1].f1->size[0] = b_Simulation->data[i1].f1->size[0];
      Simulation->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, Simulation->data[i1].f1, kstr, &pe_emlrtRTEI);
      loop_ub = b_Simulation->data[i1].f1->size[0] * b_Simulation->data[i1]
        .f1->size[1];
      for (kstr = 0; kstr < loop_ub; kstr++) {
        Simulation->data[i1].f1->data[kstr] = b_Simulation->data[i1].f1->
          data[kstr];
      }
    }

    i = shifted_data->size[0];
    shifted_data->size[0] = b_shifted_data->size[0];
    emxEnsureCapacity_cell_wrap_9(sp, shifted_data, i, &qe_emlrtRTEI);
    i = b_shifted_data->size[0];
    for (i1 = 0; i1 < i; i1++) {
      kstr = shifted_data->data[i1].f1->size[0] * shifted_data->data[i1]
        .f1->size[1];
      shifted_data->data[i1].f1->size[0] = b_shifted_data->data[i1].f1->size[0];
      shifted_data->data[i1].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, shifted_data->data[i1].f1, kstr,
        &qe_emlrtRTEI);
      loop_ub = b_shifted_data->data[i1].f1->size[0] * b_shifted_data->data[i1].
        f1->size[1];
      for (kstr = 0; kstr < loop_ub; kstr++) {
        shifted_data->data[i1].f1->data[kstr] = b_shifted_data->data[i1]
          .f1->data[kstr];
      }
    }

    i = layerSlds->size[0];
    layerSlds->size[0] = b_layerSlds->size[0];
    emxEnsureCapacity_cell_wrap_9(sp, layerSlds, i, &qe_emlrtRTEI);
    i = b_layerSlds->size[0];
    for (i1 = 0; i1 < i; i1++) {
      kstr = layerSlds->data[i1].f1->size[0] * layerSlds->data[i1].f1->size[1];
      layerSlds->data[i1].f1->size[0] = b_layerSlds->data[i1].f1->size[0];
      layerSlds->data[i1].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, layerSlds->data[i1].f1, kstr, &qe_emlrtRTEI);
      loop_ub = b_layerSlds->data[i1].f1->size[0] * b_layerSlds->data[i1]
        .f1->size[1];
      for (kstr = 0; kstr < loop_ub; kstr++) {
        layerSlds->data[i1].f1->data[kstr] = b_layerSlds->data[i1].f1->data[kstr];
      }
    }

    i = sldProfiles->size[0];
    sldProfiles->size[0] = b_sldProfiles->size[0];
    emxEnsureCapacity_cell_wrap_8(sp, sldProfiles, i, &pe_emlrtRTEI);
    i = b_sldProfiles->size[0];
    for (i1 = 0; i1 < i; i1++) {
      kstr = sldProfiles->data[i1].f1->size[0] * sldProfiles->data[i1].f1->size
        [1];
      sldProfiles->data[i1].f1->size[0] = b_sldProfiles->data[i1].f1->size[0];
      sldProfiles->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, sldProfiles->data[i1].f1, kstr, &pe_emlrtRTEI);
      loop_ub = b_sldProfiles->data[i1].f1->size[0] * b_sldProfiles->data[i1].
        f1->size[1];
      for (kstr = 0; kstr < loop_ub; kstr++) {
        sldProfiles->data[i1].f1->data[kstr] = b_sldProfiles->data[i1].f1->
          data[kstr];
      }
    }

    i = allLayers->size[0];
    allLayers->size[0] = b_allLayers->size[0];
    emxEnsureCapacity_cell_wrap_15(sp, allLayers, i, &vf_emlrtRTEI);
    i = b_allLayers->size[0];
    for (i1 = 0; i1 < i; i1++) {
      kstr = allLayers->data[i1].f1->size[0] * allLayers->data[i1].f1->size[1];
      allLayers->data[i1].f1->size[0] = b_allLayers->data[i1].f1->size[0];
      allLayers->data[i1].f1->size[1] = b_allLayers->data[i1].f1->size[1];
      emxEnsureCapacity_real_T(sp, allLayers->data[i1].f1, kstr, &vf_emlrtRTEI);
      loop_ub = b_allLayers->data[i1].f1->size[0] * b_allLayers->data[i1]
        .f1->size[1];
      for (kstr = 0; kstr < loop_ub; kstr++) {
        allLayers->data[i1].f1->data[kstr] = b_allLayers->data[i1].f1->data[kstr];
      }
    }

    /*       case 'contrasts' */
    /*          [outSsubs,... */
    /*              backgs,... */
    /*              qshifts,... */
    /*              sfs,... */
    /*              nbas,... */
    /*              nbss,... */
    /*              resols,... */
    /*              chis,... */
    /*              reflectivity,... */
    /*              Simulation,... */
    /*              shifted_data,... */
    /*              layerSlds,... */
    /*              sldProfiles,... */
    /*              allLayers,... */
    /*              allRoughs] = standardTF_custXY_paraContrasts(resample, ... */
    /*              numberOfContrasts, ... */
    /*              geometry, ... */
    /*              repeatLayers , ... */
    /*              cBacks , ... */
    /*              cShifts , ... */
    /*              cScales , ... */
    /*              cNbas , ... */
    /*              cNbss, ... */
    /*              cRes , ... */
    /*              backs , ... */
    /*              shifts , ... */
    /*              sf, ... */
    /*              nba , ... */
    /*              nbs , ... */
    /*              res , ... */
    /*              dataPresent , ... */
    /*              allData , ... */
    /*              dataLimits , ... */
    /*              simLimits , ... */
    /*              nParams , ... */
    /*              params , ... */
    /*              contrastLayers , ... */
    /*              numberOfLayers , ... */
    /*              layersDetails, ... */
    /*              problemDef_limits, ... */
    /*              fname, ... */
    /*              lang, ... */
    /*              path,... */
    /*              backsType,... */
    /*              calcSLD); */
    break;
  }

  emxFree_cell_wrap_15(&r2);
  emxFree_cell_wrap_8(&r1);
  emxFree_cell_wrap_8(&r);
  emxFree_cell_wrap_11(&b_allLayers);
  emxFree_cell_wrap_6(&b_sldProfiles);
  emxFree_cell_wrap_1(&b_layerSlds);
  emxFree_cell_wrap_1(&b_shifted_data);
  emxFree_cell_wrap_6(&b_Simulation);
  emxFree_cell_wrap_6(&b_reflectivity);
  i = problem->calculations.all_chis->size[0];
  problem->calculations.all_chis->size[0] = chis->size[0];
  emxEnsureCapacity_real_T(sp, problem->calculations.all_chis, i, &rp_emlrtRTEI);
  loop_ub = chis->size[0];
  for (i = 0; i < loop_ub; i++) {
    problem->calculations.all_chis->data[i] = chis->data[i];
  }

  st.site = &hi_emlrtRSI;
  problem->calculations.sum_chi = sum(&st, chis);

  /* problem.calculations.reflectivity = reflectivity; */
  /* problem.calculations.Simulation = Simulation; */
  /* problem.shifted_data = shifted_data; */
  /* problem.layers = layerSlds; */
  /* problem.calculations.slds = sldProfiles; */
  /* problem.allLayers = allLayers; */
  /*  result = cell(1,6); */
  /*   */
  /*   */
  /*   */
  /*  %result = {{};{};{};{};{};{};{}}; */
  /*  result{1} = reflectivity; */
  /*  result{2} = Simulation; */
  /*  result{3} = shifted_data; */
  /*  result{4} = layerSlds; */
  /*  result{5} = sldProfiles; */
  /*  result{6} = allLayers; */
  /*   */
  /*   */
  /*  %Result coder definitions.... */
  /*   coder.varsize('result{1}',[Inf 1],[1 0]);           %Reflectivity */
  /*   coder.varsize('result{1}{:}',[Inf 2],[1 0]);         */
  /*  %  */
  /*   coder.varsize('result{2}',[Inf 1],[1 0]);           %Simulatin */
  /*   coder.varsize('result{2}{:}',[Inf 2],[1 0]); */
  /*  %  */
  /*   coder.varsize('result{3}',[Inf 1],[1 0]);           %Shifted data */
  /*   coder.varsize('result{3}{:}',[Inf 3],[1 0]); */
  /*  %  */
  /*   coder.varsize('result{4}',[Inf 1],[1 0]);           %Layers slds */
  /*   coder.varsize('result{4}{:}',[Inf 3],[1 0]); */
  /*  %  */
  /*   coder.varsize('result{5}',[Inf 1],[1 0]);           %Sld profiles */
  /*   coder.varsize('results{5}{:}',[Inf 2],[1 0]); */
  /*  %  */
  /*   coder.varsize('result{6}',[Inf 1],[1 0]);           %All layers  */
  /*   coder.varsize('result{6}{:}',[Inf 1],[1 0]); */
  emxFree_real_T(&chis);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_custXY_reflectivityCalculation.c) */
