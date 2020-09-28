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
#include "applyBackgroundCorrection.h"
#include "backSort.h"
#include "callReflectivity.h"
#include "call_customLayers.h"
#include "chiSquared.h"
#include "groupLayers_Mod.h"
#include "makeSLDProfiles.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_emxutil.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"

/* Variable Definitions */
static emlrtRSInfo mh_emlrtRSI = { 85, /* lineNo */
  "standardTF_custlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo nh_emlrtRSI = { 87, /* lineNo */
  "standardTF_custlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo oh_emlrtRSI = { 90, /* lineNo */
  "standardTF_custlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo ph_emlrtRSI = { 92, /* lineNo */
  "standardTF_custlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo qh_emlrtRSI = { 96, /* lineNo */
  "standardTF_custlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo rh_emlrtRSI = { 103,/* lineNo */
  "standardTF_custlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo sh_emlrtRSI = { 106,/* lineNo */
  "standardTF_custlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo th_emlrtRSI = { 108,/* lineNo */
  "standardTF_custlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo uh_emlrtRSI = { 113,/* lineNo */
  "standardTF_custlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pathName */
};

static emlrtRTEInfo nc_emlrtRTEI = { 66,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo oc_emlrtRTEI = { 72,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo pc_emlrtRTEI = { 78,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo qc_emlrtRTEI = { 84,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtECInfo u_emlrtECI = { 1,   /* nDims */
  88,                                  /* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtBCInfo xm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  85,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ym_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  93,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo an_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  125,                                 /* colNo */
  "backgs",                            /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo v_emlrtECI = { 1,   /* nDims */
  110,                                 /* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtECInfo w_emlrtECI = { 1,   /* nDims */
  111,                                 /* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtDCInfo yb_emlrtDCI = { 51, /* lineNo */
  16,                                  /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo bn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo en_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  72,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  82,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  93,                                  /* colNo */
  "cScales",                           /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  104,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo in_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  113,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  122,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  6,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ln_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  16,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  27,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo on_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  50,                                  /* colNo */
  "resols",                            /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  70,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  78,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  16,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo un_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  58,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  17,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yn_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  60,                                  /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ao_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  72,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo co_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  8,                                   /* colNo */
  "resample",                          /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo do_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  100,                                 /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  97,                                  /* lineNo */
  9,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  62,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo go_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  29,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ho_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  36,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo io_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  47,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  73,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ko_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  40,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  48,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo no_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  56,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  69,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo po_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  106,                                 /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  128,                                 /* colNo */
  "resols",                            /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ro_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  87,                                  /* colNo */
  "backgs",                            /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo so_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  97,                                  /* colNo */
  "backsType",                         /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo to_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo vn_emlrtRTEI = { 15,/* lineNo */
  26,                                  /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo wn_emlrtRTEI = { 67,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo xn_emlrtRTEI = { 73,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo yn_emlrtRTEI = { 51,/* lineNo */
  10,                                  /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo ao_emlrtRTEI = { 79,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo bo_emlrtRTEI = { 88,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo co_emlrtRTEI = { 93,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo do_emlrtRTEI = { 100,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo eo_emlrtRTEI = { 97,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo fo_emlrtRTEI = { 103,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo go_emlrtRTEI = { 104,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo ho_emlrtRTEI = { 110,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo io_emlrtRTEI = { 111,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo jo_emlrtRTEI = { 92,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo ko_emlrtRTEI = { 96,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraPoints.m"/* pName */
};

/* Function Definitions */
void standardTF_custlay_paraPoints(const emlrtStack *sp, const emxArray_real_T
  *resample, real_T numberOfContrasts, const emxArray_char_T *geometry, const
  emxArray_cell_wrap_0 *repeatLayers, const emxArray_real_T *cBacks, const
  emxArray_real_T *cShifts, const emxArray_real_T *cScales, const
  emxArray_real_T *cNbas, const emxArray_real_T *cNbss, const emxArray_real_T
  *cRes, const emxArray_real_T *backs, const emxArray_real_T *shifts, const
  emxArray_real_T *sf, const emxArray_real_T *nba, const emxArray_real_T *nbs,
  const emxArray_real_T *res, const emxArray_real_T *dataPresent, const
  emxArray_cell_wrap_1 *allData, const emxArray_cell_wrap_0 *dataLimits, const
  emxArray_cell_wrap_0 *simLimits, real_T nParams, const emxArray_real_T *params,
  const emxArray_char_T *fname, const emxArray_char_T *path, const
  emxArray_real_T *backsType, emxArray_real_T *outSsubs, emxArray_real_T *backgs,
  emxArray_real_T *qshifts, emxArray_real_T *sfs, emxArray_real_T *nbas,
  emxArray_real_T *nbss, emxArray_real_T *resols, emxArray_real_T *chis,
  emxArray_cell_wrap_8 *reflectivity, emxArray_cell_wrap_8 *Simulation,
  emxArray_cell_wrap_1 *shifted_data, emxArray_cell_wrap_1 *layerSlds,
  emxArray_cell_wrap_6 *sldProfiles, emxArray_cell_wrap_15 *allLayers,
  emxArray_real_T *allRoughs)
{
  int32_T i;
  int32_T i1;
  int32_T b_i;
  int32_T i2;
  emxArray_real_T *sldProfile;
  emxArray_real_T *layerSld;
  emxArray_real_T *shifted_dat;
  emxArray_real_T *Simul;
  int32_T loop_ub;
  int32_T i3;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* coder.extrinsic('callModules');             */
  /* Pre-Allocation... */
  if (numberOfContrasts != (int32_T)muDoubleScalarFloor(numberOfContrasts)) {
    emlrtIntegerCheckR2012b(numberOfContrasts, &yb_emlrtDCI, sp);
  }

  i = (int32_T)numberOfContrasts;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &nc_emlrtRTEI, sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, reflectivity, i1, &vn_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bn_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &wn_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bn_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &wn_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &bn_emlrtBCI, sp);
    }

    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &bn_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bn_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bn_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bn_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bn_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &oc_emlrtRTEI, sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, Simulation, i1, &vn_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &cn_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &xn_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &cn_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &xn_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &cn_emlrtBCI, sp);
    }

    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &cn_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &cn_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &cn_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &cn_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &cn_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &pc_emlrtRTEI, sp);
  i1 = allLayers->size[0];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_15(sp, allLayers, i1, &vn_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &dn_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &ao_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &dn_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &ao_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &dn_emlrtBCI, sp);
    }

    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &dn_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &dn_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &dn_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfContrasts, mxDOUBLE_CLASS,
    (int32_T)numberOfContrasts, &qc_emlrtRTEI, sp);
  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &yn_emlrtRTEI);
  i1 = qshifts->size[0];
  qshifts->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, qshifts, i1, &yn_emlrtRTEI);
  i1 = sfs->size[0];
  sfs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, sfs, i1, &yn_emlrtRTEI);
  i1 = nbas->size[0];
  nbas->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbas, i1, &yn_emlrtRTEI);
  i1 = nbss->size[0];
  nbss->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbss, i1, &yn_emlrtRTEI);
  i1 = resols->size[0];
  resols->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, resols, i1, &yn_emlrtRTEI);
  i1 = allRoughs->size[0];
  allRoughs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, allRoughs, i1, &yn_emlrtRTEI);
  i1 = allLayers->size[0];
  allLayers->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_15(sp, allLayers, i1, &vn_emlrtRTEI);
  i1 = outSsubs->size[0];
  outSsubs->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, outSsubs, i1, &yn_emlrtRTEI);
  i1 = sldProfiles->size[0];
  sldProfiles->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_6(sp, sldProfiles, i1, &vn_emlrtRTEI);
  i1 = layerSlds->size[0];
  layerSlds->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, layerSlds, i1, &vn_emlrtRTEI);
  i1 = shifted_data->size[0];
  shifted_data->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, shifted_data, i1, &vn_emlrtRTEI);
  i1 = chis->size[0];
  chis->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_real_T(sp, chis, i1, &yn_emlrtRTEI);
  i1 = Simulation->size[0];
  Simulation->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, Simulation, i1, &vn_emlrtRTEI);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)numberOfContrasts;
  emxEnsureCapacity_cell_wrap_8(sp, reflectivity, i1, &vn_emlrtRTEI);
  emxInit_real_T(sp, &sldProfile, 2, &jo_emlrtRTEI, true);
  emxInit_real_T(sp, &layerSld, 2, &ko_emlrtRTEI, true);
  emxInit_real_T(sp, &shifted_dat, 2, &fo_emlrtRTEI, true);
  emxInit_real_T(sp, &Simul, 2, &vn_emlrtRTEI, true);
  for (b_i = 0; b_i < i; b_i++) {
    i1 = (int32_T)(b_i + 1U);
    if ((i1 < 1) || (i1 > cBacks->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cBacks->size[1], &en_emlrtBCI, sp);
    }

    if (i1 > cShifts->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cShifts->size[1], &fn_emlrtBCI, sp);
    }

    if (i1 > cScales->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cScales->size[1], &gn_emlrtBCI, sp);
    }

    if (i1 > cNbas->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cNbas->size[1], &hn_emlrtBCI, sp);
    }

    if (i1 > cNbss->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cNbss->size[1], &in_emlrtBCI, sp);
    }

    if (i1 > cRes->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, cRes->size[1], &jn_emlrtBCI, sp);
    }

    if (i1 > backgs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, backgs->size[0], &kn_emlrtBCI, sp);
    }

    if (i1 > qshifts->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, qshifts->size[0], &ln_emlrtBCI, sp);
    }

    if (i1 > sfs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, sfs->size[0], &mn_emlrtBCI, sp);
    }

    if (i1 > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbas->size[0], &nn_emlrtBCI, sp);
    }

    if (i1 > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &on_emlrtBCI, sp);
    }

    if (i1 > resols->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, resols->size[0], &pn_emlrtBCI, sp);
    }

    st.site = &mh_emlrtRSI;
    backSort(&st, cBacks->data[i1 - 1], cShifts->data[i1 - 1], cScales->data[i1
             - 1], cNbas->data[i1 - 1], cNbss->data[i1 - 1], cRes->data[i1 - 1],
             backs, shifts, sf, nba, nbs, res, &backgs->data[i1 - 1],
             &qshifts->data[i1 - 1], &sfs->data[i1 - 1], &nbas->data[i1 - 1],
             &nbss->data[i1 - 1], &resols->data[i1 - 1]);
    if (i1 > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbas->size[0], &qn_emlrtBCI, sp);
    }

    if (i1 > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &rn_emlrtBCI, sp);
    }

    if (i1 > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, allRoughs->size[0], &sn_emlrtBCI, sp);
    }

    st.site = &nh_emlrtRSI;
    call_customLayers(&st, params, (real_T)b_i + 1.0, fname, path, nbas->data[i1
                      - 1], nbss->data[i1 - 1], shifted_dat, &allRoughs->data[i1
                      - 1]);
    if (10000 < shifted_dat->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, shifted_dat->size[0], &u_emlrtECI, sp);
    }

    loop_ub = shifted_dat->size[0] * shifted_dat->size[1];
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &tn_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &bo_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &tn_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &bo_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &tn_emlrtBCI, sp);
    }

    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &tn_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &tn_emlrtBCI, sp);
      }

      allLayers->data[b_i].f1->data[i2] = shifted_dat->data[i2];
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbas->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbas->size[0], &xm_emlrtBCI, sp);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbss->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &ym_emlrtBCI, sp);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > allRoughs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, allRoughs->size[0], &un_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > outSsubs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, outSsubs->size[0], &vn_emlrtBCI, sp);
    }

    st.site = &oh_emlrtRSI;
    b_groupLayers_Mod(&st, shifted_dat, allRoughs->data[i1 - 1], geometry,
                      layerSld, &outSsubs->data[i2 - 1]);
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbas->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbas->size[0], &wn_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > nbss->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, nbss->size[0], &xn_emlrtBCI, sp);
    }

    loop_ub = b_i + 1;
    if ((loop_ub < 1) || (loop_ub > outSsubs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, outSsubs->size[0], &yn_emlrtBCI,
        sp);
    }

    i3 = repeatLayers->size[1] - 1;
    if (b_i > i3) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &ao_emlrtBCI, sp);
    }

    st.site = &ph_emlrtRSI;
    makeSLDProfiles(&st, nbas->data[i1 - 1], nbss->data[i2 - 1], layerSld,
                    outSsubs->data[loop_ub - 1], repeatLayers->data[b_i].f1,
                    sldProfile);
    loop_ub = sldProfile->size[0] * sldProfile->size[1];
    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bo_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &co_emlrtRTEI);
    i1 = sldProfiles->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bo_emlrtBCI, sp);
    }

    i1 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i1, &co_emlrtRTEI);
    i1 = sldProfiles->size[0] - 1;
    i2 = sldProfiles->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &bo_emlrtBCI, sp);
    }

    i2 = sldProfiles->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &bo_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bo_emlrtBCI, sp);
      }

      sldProfiles->data[b_i].f1->data[i2] = sldProfile->data[i2];
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > resample->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, resample->size[1], &co_emlrtBCI, sp);
    }

    if (resample->data[i1 - 1] == 1.0) {
      st.site = &qh_emlrtRSI;
      resampleLayers(&st, sldProfile, layerSld);
      loop_ub = layerSld->size[0] * layerSld->size[1];
      i1 = layerSlds->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &eo_emlrtBCI, sp);
      }

      i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
      layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
      emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &eo_emlrtRTEI);
      i1 = layerSlds->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &eo_emlrtBCI, sp);
      }

      i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
      layerSlds->data[b_i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &eo_emlrtRTEI);
      i1 = layerSlds->size[0] - 1;
      i2 = layerSlds->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &eo_emlrtBCI, sp);
      }

      i2 = layerSlds->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &eo_emlrtBCI, sp);
      }

      for (i2 = 0; i2 < loop_ub; i2++) {
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &eo_emlrtBCI, sp);
        }

        layerSlds->data[b_i].f1->data[i2] = layerSld->data[i2];
      }
    } else {
      loop_ub = layerSld->size[0] * layerSld->size[1];
      i1 = layerSlds->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &do_emlrtBCI, sp);
      }

      i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
      layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
      emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &do_emlrtRTEI);
      i1 = layerSlds->size[0] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &do_emlrtBCI, sp);
      }

      i1 = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
      layerSlds->data[b_i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i1, &do_emlrtRTEI);
      i1 = layerSlds->size[0] - 1;
      i2 = layerSlds->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &do_emlrtBCI, sp);
      }

      i2 = layerSlds->size[0] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &do_emlrtBCI, sp);
      }

      for (i2 = 0; i2 < loop_ub; i2++) {
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &do_emlrtBCI, sp);
        }

        layerSlds->data[b_i].f1->data[i2] = layerSld->data[i2];
      }
    }

    i1 = allData->size[1] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &fo_emlrtBCI, sp);
    }

    i1 = shifted_dat->size[0] * shifted_dat->size[1];
    shifted_dat->size[0] = allData->data[b_i].f1->size[0];
    shifted_dat->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_dat, i1, &fo_emlrtRTEI);
    i1 = allData->size[1] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &fo_emlrtBCI, sp);
    }

    i1 = allData->size[1] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &fo_emlrtBCI, sp);
    }

    loop_ub = allData->data[b_i].f1->size[0] * allData->data[b_i].f1->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      i2 = allData->size[1] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &fo_emlrtBCI, sp);
      }

      i2 = allData->size[1] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &fo_emlrtBCI, sp);
      }

      i2 = allData->size[1] - 1;
      if (b_i > i2) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &fo_emlrtBCI, sp);
      }

      shifted_dat->data[i1] = allData->data[b_i].f1->data[i1];
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > sfs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, sfs->size[0], &go_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > qshifts->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, qshifts->size[0], &ho_emlrtBCI, sp);
    }

    loop_ub = b_i + 1;
    if ((loop_ub < 1) || (loop_ub > dataPresent->size[1])) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, dataPresent->size[1],
        &io_emlrtBCI, sp);
    }

    i3 = dataLimits->size[1] - 1;
    if (b_i > i3) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &jo_emlrtBCI, sp);
    }

    st.site = &rh_emlrtRSI;
    shiftdata(&st, sfs->data[i1 - 1], qshifts->data[i2 - 1], dataPresent->
              data[loop_ub - 1], shifted_dat, dataLimits->data[b_i].f1);
    loop_ub = shifted_dat->size[0] * shifted_dat->size[1];
    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ko_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i1, &go_emlrtRTEI);
    i1 = shifted_data->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ko_emlrtBCI, sp);
    }

    i1 = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size
      [1];
    shifted_data->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i1, &go_emlrtRTEI);
    i1 = shifted_data->size[0] - 1;
    i2 = shifted_data->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ko_emlrtBCI, sp);
    }

    i2 = shifted_data->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ko_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ko_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[i2] = shifted_dat->data[i2];
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > backgs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, backgs->size[0], &an_emlrtBCI, sp);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > nbas->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbas->size[0], &lo_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > nbss->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, nbss->size[0], &mo_emlrtBCI, sp);
    }

    loop_ub = simLimits->size[1] - 1;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &no_emlrtBCI, sp);
    }

    loop_ub = repeatLayers->size[1] - 1;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &oo_emlrtBCI, sp);
    }

    loop_ub = b_i + 1;
    if ((loop_ub < 1) || (loop_ub > outSsubs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, outSsubs->size[0], &po_emlrtBCI,
        sp);
    }

    i3 = b_i + 1;
    if ((i3 < 1) || (i3 > resols->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, resols->size[0], &qo_emlrtBCI, sp);
    }

    st.site = &sh_emlrtRSI;
    b_callReflectivity(&st, nbas->data[i1 - 1], nbss->data[i2 - 1],
                       simLimits->data[b_i].f1, repeatLayers->data[b_i].f1,
                       shifted_dat, layerSld, outSsubs->data[loop_ub - 1],
                       resols->data[i3 - 1], sldProfile, Simul);
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > backgs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, backgs->size[0], &ro_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > backsType->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, backsType->size[1], &so_emlrtBCI, sp);
    }

    st.site = &th_emlrtRSI;
    applyBackgroundCorrection(&st, sldProfile, Simul, shifted_dat, backgs->
      data[i1 - 1], backsType->data[i2 - 1]);
    if (10000 < sldProfile->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, sldProfile->size[0], &v_emlrtECI, sp);
    }

    loop_ub = sldProfile->size[0] * sldProfile->size[1];
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &to_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &ho_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &to_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &ho_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &to_emlrtBCI, sp);
    }

    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &to_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &to_emlrtBCI, sp);
      }

      reflectivity->data[b_i].f1->data[i2] = sldProfile->data[i2];
    }

    if (10000 < Simul->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, Simul->size[0], &w_emlrtECI, sp);
    }

    loop_ub = Simul->size[0] * Simul->size[1];
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &uo_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = Simul->size[0];
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &io_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &uo_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &io_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &uo_emlrtBCI, sp);
    }

    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &uo_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &uo_emlrtBCI, sp);
      }

      Simulation->data[b_i].f1->data[i2] = Simul->data[i2];
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > chis->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, chis->size[0], &vo_emlrtBCI, sp);
    }

    st.site = &uh_emlrtRSI;
    chis->data[i1 - 1] = chiSquared(&st, shifted_dat, sldProfile, nParams);
  }

  emxFree_real_T(&Simul);
  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&layerSld);
  emxFree_real_T(&sldProfile);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_custlay_paraPoints.c) */
