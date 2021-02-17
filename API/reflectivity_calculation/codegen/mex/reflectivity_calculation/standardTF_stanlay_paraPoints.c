/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_stanlay_paraPoints.c
 *
 * Code generation for function 'standardTF_stanlay_paraPoints'
 *
 */

/* Include files */
#include "standardTF_stanlay_paraPoints.h"
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
static emlrtRSInfo xf_emlrtRSI = { 78, /* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo yf_emlrtRSI = { 81, /* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo ag_emlrtRSI = { 84, /* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo bg_emlrtRSI = { 85, /* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo cg_emlrtRSI = { 93, /* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo dg_emlrtRSI = { 101,/* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo eg_emlrtRSI = { 108,/* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo fg_emlrtRSI = { 110,/* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo gg_emlrtRSI = { 112,/* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo hg_emlrtRSI = { 118,/* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRTEInfo sb_emlrtRTEI = { 62,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = { 67,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = { 72,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = { 80,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtBCInfo vf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  79,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  90,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  101,                                 /* colNo */
  "cScales",                           /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  110,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ag_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  119,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  127,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  27,                                  /* colNo */
  "params",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  43,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  51,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  73,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  125,                                 /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  89,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo ib_emlrtDCI = { 46, /* lineNo */
  16,                                  /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ig_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  6,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo og_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  16,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  27,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ug_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  50,                                  /* colNo */
  "resols",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  5,                                   /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  52,                                  /* colNo */
  "contrastLayers",                    /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ah_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  67,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  89,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ch_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  97,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  17,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  8,                                   /* colNo */
  "resample",                          /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  98,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  100,                                 /* lineNo */
  8,                                   /* colNo */
  "resample",                          /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ih_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  62,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  29,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  36,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  47,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  73,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  40,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ph_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  48,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  56,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  69,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  106,                                 /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo th_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  128,                                 /* colNo */
  "resols",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  115,                                 /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  112,                                 /* lineNo */
  87,                                  /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  112,                                 /* lineNo */
  97,                                  /* colNo */
  "backsType",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  114,                                 /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  116,                                 /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ai_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  118,                                 /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo el_emlrtRTEI = { 15,/* lineNo */
  26,                                  /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo fl_emlrtRTEI = { 63,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo gl_emlrtRTEI = { 68,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo hl_emlrtRTEI = { 46,/* lineNo */
  10,                                  /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo il_emlrtRTEI = { 73,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo jl_emlrtRTEI = { 95,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo kl_emlrtRTEI = { 98,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo ll_emlrtRTEI = { 93,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo ml_emlrtRTEI = { 105,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo nl_emlrtRTEI = { 102,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo ol_emlrtRTEI = { 108,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo pl_emlrtRTEI = { 114,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo ql_emlrtRTEI = { 116,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo rl_emlrtRTEI = { 78,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo sl_emlrtRTEI = { 84,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo tl_emlrtRTEI = { 101,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo ul_emlrtRTEI = { 93,/* lineNo */
  22,                                  /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_stanlay_paraPoints.m"/* pName */
};

/* Function Definitions */
void standardTF_stanlay_paraPoints(const emlrtStack *sp, const emxArray_real_T
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
  int32_T loop_ub;
  int32_T i3;
  real_T thisCalcSld;
  int32_T i4;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 21U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 0U);

  /* Pre-Allocation... */
  if (numberOfContrasts != (int32_T)muDoubleScalarFloor(numberOfContrasts)) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &ib_emlrtDCI, sp);
  }

  /*   */
  i = (int32_T)numberOfContrasts;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &sb_emlrtRTEI, sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_11(sp, reflectivity, i1, &el_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 21U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 1U);
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ig_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &fl_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ig_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &fl_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ig_emlrtBCI, sp);
    }

    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ig_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ig_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ig_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ig_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ig_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 21U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 2U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &tb_emlrtRTEI, sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, Simulation, i1, &el_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 21U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 3U);
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &jg_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &gl_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &jg_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &gl_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &jg_emlrtBCI, sp);
    }

    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &jg_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &jg_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &jg_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &jg_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &jg_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 21U, 0U, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 4U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &ub_emlrtRTEI, sp);
  i1 = allLayers->size[0];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_11(sp, allLayers, i1, &el_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 21U, 0U, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 5U);
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &kg_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &il_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &kg_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &il_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &kg_emlrtBCI, sp);
    }

    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &kg_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &kg_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &kg_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
  }

  emxInit_cell_wrap_16(sp, &outParameterisedLayers, 2, &rl_emlrtRTEI, true);
  covrtLogFor(&emlrtCoverageInstance, 21U, 0U, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 6U);
  st.site = &xf_emlrtRSI;
  allocateParamsToLayers(&st, params, layersDetails, outParameterisedLayers);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &vb_emlrtRTEI, sp);
  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &hl_emlrtRTEI);
  i1 = qshifts->size[0];
  qshifts->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, qshifts, i1, &hl_emlrtRTEI);
  i1 = sfs->size[0];
  sfs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, sfs, i1, &hl_emlrtRTEI);
  i1 = nbas->size[0];
  nbas->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbas, i1, &hl_emlrtRTEI);
  i1 = nbss->size[0];
  nbss->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbss, i1, &hl_emlrtRTEI);
  i1 = resols->size[0];
  resols->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, resols, i1, &hl_emlrtRTEI);
  i1 = allRoughs->size[0];
  allRoughs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, allRoughs, i1, &hl_emlrtRTEI);
  i1 = outSsubs->size[0];
  outSsubs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, outSsubs, i1, &hl_emlrtRTEI);
  i1 = sldProfiles->size[0];
  sldProfiles->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_11(sp, sldProfiles, i1, &el_emlrtRTEI);
  i1 = layerSlds->size[0];
  layerSlds->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, layerSlds, i1, &el_emlrtRTEI);
  i1 = shifted_data->size[0];
  shifted_data->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, shifted_data, i1, &el_emlrtRTEI);
  i1 = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, Simulation, i1, &el_emlrtRTEI);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_11(sp, reflectivity, i1, &el_emlrtRTEI);
  i1 = chis->size[0];
  chis->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, chis, i1, &hl_emlrtRTEI);
  emxInit_real_T(sp, &thisContrastLayers, 2, &sl_emlrtRTEI, true);
  emxInit_real_T(sp, &sldProfile, 2, &ll_emlrtRTEI, true);
  emxInit_real_T(sp, &layerSld, 2, &tl_emlrtRTEI, true);
  emxInit_real_T(sp, &shifted_dat, 2, &ol_emlrtRTEI, true);
  emxInit_real_T(sp, &b_sldProfile, 2, &ul_emlrtRTEI, true);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 21U, 0U, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 7U);
    st.site = &yf_emlrtRSI;
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cBacks->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cBacks->size[1], &vf_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cShifts->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cShifts->size[1], &wf_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cScales->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cScales->size[1], &xf_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cNbas->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cNbas->size[1], &yf_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cNbss->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cNbss->size[1], &ag_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > cRes->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cRes->size[1], &bg_emlrtBCI, &st);
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
      emlrtIntegerCheckR2012b(cBacks->data[b_i], &jb_emlrtDCI, &st);
    }

    i1 = (int32_T)cBacks->data[b_i];
    if ((i1 < 1) || (i1 > backs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, backs->size[1], &lg_emlrtBCI, &st);
    }

    i2 = (int32_T)(b_i + 1U);
    if ((i2 < 1) || (i2 > backgs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, backgs->size[0], &mg_emlrtBCI, &st);
    }

    backgs->data[i2 - 1] = backs->data[i1 - 1];

    /* thisShift = cShifts(i); */
    if (cShifts->data[b_i] != (int32_T)muDoubleScalarFloor(cShifts->data[b_i]))
    {
      emlrtIntegerCheckR2012b(cShifts->data[b_i], &kb_emlrtDCI, &st);
    }

    i1 = (int32_T)cShifts->data[b_i];
    if ((i1 < 1) || (i1 > shifts->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, shifts->size[1], &ng_emlrtBCI, &st);
    }

    if (i2 > qshifts->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, qshifts->size[0], &og_emlrtBCI, &st);
    }

    qshifts->data[i2 - 1] = shifts->data[i1 - 1];

    /* thisScale = cScales(i); */
    if (cScales->data[b_i] != (int32_T)muDoubleScalarFloor(cScales->data[b_i]))
    {
      emlrtIntegerCheckR2012b(cScales->data[b_i], &lb_emlrtDCI, &st);
    }

    i1 = (int32_T)cScales->data[b_i];
    if ((i1 < 1) || (i1 > sf->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, sf->size[1], &pg_emlrtBCI, &st);
    }

    if (i2 > sfs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, sfs->size[0], &qg_emlrtBCI, &st);
    }

    sfs->data[i2 - 1] = sf->data[i1 - 1];

    /* thisNbair = cNbas(i); */
    if (cNbas->data[b_i] != (int32_T)muDoubleScalarFloor(cNbas->data[b_i])) {
      emlrtIntegerCheckR2012b(cNbas->data[b_i], &mb_emlrtDCI, &st);
    }

    i1 = (int32_T)cNbas->data[b_i];
    if ((i1 < 1) || (i1 > nba->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nba->size[1], &rg_emlrtBCI, &st);
    }

    if (i2 > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, nbas->size[0], &sg_emlrtBCI, &st);
    }

    nbas->data[i2 - 1] = nba->data[i1 - 1];

    /* thisNbsub = cNbss(i); */
    if (cNbss->data[b_i] != (int32_T)muDoubleScalarFloor(cNbss->data[b_i])) {
      emlrtIntegerCheckR2012b(cNbss->data[b_i], &nb_emlrtDCI, &st);
    }

    i1 = (int32_T)cNbss->data[b_i];
    if ((i1 < 1) || (i1 > nbs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbs->size[1], &tg_emlrtBCI, &st);
    }

    if (i2 > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, nbss->size[0], &ug_emlrtBCI, &st);
    }

    nbss->data[i2 - 1] = nbs->data[i1 - 1];

    /* thisResol = cRes(i); */
    if (cRes->data[b_i] != (int32_T)muDoubleScalarFloor(cRes->data[b_i])) {
      emlrtIntegerCheckR2012b(cRes->data[b_i], &ob_emlrtDCI, &st);
    }

    i1 = (int32_T)cRes->data[b_i];
    if ((i1 < 1) || (i1 > res->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, res->size[1], &vg_emlrtBCI, &st);
    }

    if (i2 > resols->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, resols->size[0], &wg_emlrtBCI, &st);
    }

    resols->data[i2 - 1] = res->data[i1 - 1];

    /* end */
    if (1 > params->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, params->size[1], &cg_emlrtBCI, sp);
    }

    if (i2 > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, allRoughs->size[0], &xg_emlrtBCI, sp);
    }

    allRoughs->data[i2 - 1] = params->data[0];
    i1 = contrastLayers->size[1] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &yg_emlrtBCI, sp);
    }

    st.site = &ag_emlrtRSI;
    allocateLayersForContrast(&st, contrastLayers->data[b_i].f1,
      outParameterisedLayers, thisContrastLayers);
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > allRoughs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, allRoughs->size[0], &ah_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > nbas->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, nbas->size[0], &bh_emlrtBCI, sp);
    }

    loop_ub = b_i + 1;
    if ((loop_ub < 1) || (loop_ub > nbss->size[0])) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, nbss->size[0], &ch_emlrtBCI, sp);
    }

    i3 = b_i + 1;
    if ((i3 < 1) || (i3 > outSsubs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, outSsubs->size[0], &dh_emlrtBCI, sp);
    }

    st.site = &bg_emlrtRSI;
    groupLayers_Mod(&st, thisContrastLayers, allRoughs->data[i1 - 1], geometry,
                    nbas->data[i2 - 1], nbss->data[loop_ub - 1], layerSld,
                    &outSsubs->data[i3 - 1]);
    thisCalcSld = calcSld;
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > resample->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, resample->size[1], &eh_emlrtBCI, sp);
    }

    if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 0, resample->data[i1 - 1] ==
                   1.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 8U);
      thisCalcSld = 1.0;
    }

    if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 1, thisCalcSld == 1.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 9U);
      st.site = &cg_emlrtRSI;
      i1 = b_i + 1;
      if ((i1 < 1) || (i1 > nbas->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, nbas->size[0], &dg_emlrtBCI, &st);
      }

      i1 = b_i + 1;
      if ((i1 < 1) || (i1 > nbss->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &eg_emlrtBCI, &st);
      }

      i1 = b_i + 1;
      if ((i1 < 1) || (i1 > outSsubs->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, outSsubs->size[0], &fg_emlrtBCI,
          &st);
      }

      i1 = repeatLayers->size[1] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hg_emlrtBCI, &st);
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
      makeSLDProfileXY(&b_st, nbas->data[b_i], nbss->data[b_i], outSsubs->
                       data[b_i], layerSld, layerSld->size[0], thisCalcSld,
                       b_sldProfile);
      i1 = sldProfile->size[0] * sldProfile->size[1];
      sldProfile->size[0] = b_sldProfile->size[0];
      sldProfile->size[1] = 2;
      emxEnsureCapacity_real_T(sp, sldProfile, i1, &ll_emlrtRTEI);
      loop_ub = b_sldProfile->size[0] * b_sldProfile->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        sldProfile->data[i1] = b_sldProfile->data[i1];
      }
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 10U);
      i1 = sldProfile->size[0] * sldProfile->size[1];
      sldProfile->size[0] = 1;
      sldProfile->size[1] = 3;
      emxEnsureCapacity_real_T(sp, sldProfile, i1, &jl_emlrtRTEI);
      sldProfile->data[0] = 0.0;
      sldProfile->data[1] = 0.0;
      sldProfile->data[2] = 0.0;
    }

    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 11U);
    loop_ub = sldProfile->size[0] * sldProfile->size[1];
    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &fh_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &kl_emlrtRTEI);
    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &fh_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = sldProfile->size[1];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &kl_emlrtRTEI);
    i1 = sldProfiles->size[0] - 1;
    i2 = sldProfiles->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &fh_emlrtBCI, sp);
    }

    i2 = sldProfiles->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &fh_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &fh_emlrtBCI, sp);
      }

      sldProfiles->data[b_i].f1->data[i2] = sldProfile->data[i2];
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > resample->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, resample->size[1], &gh_emlrtBCI, sp);
    }

    if (covrtLogIf(&emlrtCoverageInstance, 21U, 0U, 2, resample->data[i1 - 1] ==
                   1.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 12U);
      st.site = &dg_emlrtRSI;
      resampleLayers(&st, sldProfile, layerSld);
      loop_ub = layerSld->size[0] * layerSld->size[1];
      i1 = layerSlds->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ih_emlrtBCI, sp);
      }

      i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
      layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
      emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &nl_emlrtRTEI);
      i1 = layerSlds->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ih_emlrtBCI, sp);
      }

      i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
      layerSlds->data[b_i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &nl_emlrtRTEI);
      i1 = layerSlds->size[0] - 1;
      i2 = layerSlds->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ih_emlrtBCI, sp);
      }

      i2 = layerSlds->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ih_emlrtBCI, sp);
      }

      for (i2 = 0; i2 < loop_ub; i2++) {
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ih_emlrtBCI, sp);
        }

        layerSlds->data[b_i].f1->data[i2] = layerSld->data[i2];
      }
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 13U);
      loop_ub = layerSld->size[0] * layerSld->size[1];
      i1 = layerSlds->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hh_emlrtBCI, sp);
      }

      i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
      layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
      emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &ml_emlrtRTEI);
      i1 = layerSlds->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hh_emlrtBCI, sp);
      }

      i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
      layerSlds->data[b_i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &ml_emlrtRTEI);
      i1 = layerSlds->size[0] - 1;
      i2 = layerSlds->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &hh_emlrtBCI, sp);
      }

      i2 = layerSlds->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &hh_emlrtBCI, sp);
      }

      for (i2 = 0; i2 < loop_ub; i2++) {
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hh_emlrtBCI, sp);
        }

        layerSlds->data[b_i].f1->data[i2] = layerSld->data[i2];
      }
    }

    covrtLogBasicBlock(&emlrtCoverageInstance, 21U, 14U);
    i1 = allData->size[1] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &jh_emlrtBCI, sp);
    }

    i1 = shifted_dat->size[0] * shifted_dat->size[1];
    shifted_dat->size[0] = allData->data[b_i].f1->size[0];
    shifted_dat->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_dat, i1, &ol_emlrtRTEI);
    i1 = allData->size[1] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &jh_emlrtBCI, sp);
    }

    i1 = allData->size[1] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &jh_emlrtBCI, sp);
    }

    loop_ub = allData->data[b_i].f1->size[0] * allData->data[b_i].f1->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      i2 = allData->size[1] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &jh_emlrtBCI, sp);
      }

      i2 = allData->size[1] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &jh_emlrtBCI, sp);
      }

      i2 = allData->size[1] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &jh_emlrtBCI, sp);
      }

      shifted_dat->data[i1] = allData->data[b_i].f1->data[i1];
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > sfs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, sfs->size[0], &kh_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > qshifts->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, qshifts->size[0], &lh_emlrtBCI, sp);
    }

    loop_ub = b_i + 1;
    if ((loop_ub < 1) || (loop_ub > dataPresent->size[1])) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, dataPresent->size[1],
        &mh_emlrtBCI, sp);
    }

    i3 = dataLimits->size[1] - 1;
    if (b_i > i3) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &nh_emlrtBCI, sp);
    }

    st.site = &eg_emlrtRSI;
    shiftdata(&st, sfs->data[i1 - 1], qshifts->data[i2 - 1], dataPresent->
              data[loop_ub - 1], shifted_dat, dataLimits->data[b_i].f1);
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > backgs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, backgs->size[0], &gg_emlrtBCI, sp);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbas->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbas->size[0], &oh_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > nbss->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, nbss->size[0], &ph_emlrtBCI, sp);
    }

    loop_ub = simLimits->size[1] - 1;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &qh_emlrtBCI, sp);
    }

    loop_ub = repeatLayers->size[1] - 1;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &rh_emlrtBCI, sp);
    }

    loop_ub = b_i + 1;
    if ((loop_ub < 1) || (loop_ub > outSsubs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, outSsubs->size[0], &sh_emlrtBCI,
        sp);
    }

    i3 = b_i + 1;
    if ((i3 < 1) || (i3 > resols->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, resols->size[0], &th_emlrtBCI, sp);
    }

    i4 = Simulation->size[0] - 1;
    if (b_i > i4) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i4, &uh_emlrtBCI, sp);
    }

    st.site = &fg_emlrtRSI;
    b_callReflectivity(&st, nbas->data[i1 - 1], nbss->data[i2 - 1],
                       simLimits->data[b_i].f1, repeatLayers->data[b_i].f1,
                       shifted_dat, layerSld, outSsubs->data[loop_ub - 1],
                       resols->data[i3 - 1], b_sldProfile, Simulation->data[b_i]
                       .f1);
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &uh_emlrtBCI, sp);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > backgs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, backgs->size[0], &vh_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > backsType->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, backsType->size[1], &wh_emlrtBCI, sp);
    }

    st.site = &gg_emlrtRSI;
    applyBackgroundCorrection(&st, b_sldProfile, Simulation->data[b_i].f1,
      shifted_dat, backgs->data[i1 - 1], backsType->data[i2 - 1]);
    loop_ub = b_sldProfile->size[0] * b_sldProfile->size[1];
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &xh_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = b_sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &pl_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &xh_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &pl_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &xh_emlrtBCI, sp);
    }

    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &xh_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &xh_emlrtBCI, sp);
      }

      reflectivity->data[b_i].f1->data[i2] = b_sldProfile->data[i2];
    }

    loop_ub = shifted_dat->size[0] * shifted_dat->size[1];
    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &yh_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i1, &ql_emlrtRTEI);
    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &yh_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i1, &ql_emlrtRTEI);
    i1 = shifted_data->size[0] - 1;
    i2 = shifted_data->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &yh_emlrtBCI, sp);
    }

    i2 = shifted_data->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &yh_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &yh_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[i2] = shifted_dat->data[i2];
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > chis->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, chis->size[0], &ai_emlrtBCI, sp);
    }

    st.site = &hg_emlrtRSI;
    chis->data[i1 - 1] = chiSquared(&st, shifted_dat, b_sldProfile, nParams);
  }

  emxFree_real_T(&b_sldProfile);
  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&layerSld);
  emxFree_real_T(&sldProfile);
  emxFree_real_T(&thisContrastLayers);
  emxFree_cell_wrap_16(&outParameterisedLayers);
  covrtLogFor(&emlrtCoverageInstance, 21U, 0U, 3, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_stanlay_paraPoints.c) */
