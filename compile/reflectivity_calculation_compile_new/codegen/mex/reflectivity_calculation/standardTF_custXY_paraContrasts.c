/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_custXY_paraContrasts.c
 *
 * Code generation for function 'standardTF_custXY_paraContrasts'
 *
 */

/* Include files */
#include "standardTF_custXY_paraContrasts.h"
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
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo oi_emlrtRSI = { 56, /* lineNo */
  "standardTF_custXY_paraContrasts",   /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pathName */
};

static emlrtRSInfo pi_emlrtRSI = { 59, /* lineNo */
  "standardTF_custXY_paraContrasts",   /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pathName */
};

static emlrtRSInfo qi_emlrtRSI = { 64, /* lineNo */
  "standardTF_custXY_paraContrasts",   /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pathName */
};

static emlrtRSInfo ri_emlrtRSI = { 68, /* lineNo */
  "standardTF_custXY_paraContrasts",   /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pathName */
};

static emlrtRSInfo si_emlrtRSI = { 72, /* lineNo */
  "standardTF_custXY_paraContrasts",   /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pathName */
};

static emlrtRSInfo ti_emlrtRSI = { 74, /* lineNo */
  "standardTF_custXY_paraContrasts",   /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pathName */
};

static emlrtRSInfo ui_emlrtRSI = { 79, /* lineNo */
  "standardTF_custXY_paraContrasts",   /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pathName */
};

static emlrtRSInfo vi_emlrtRSI = { 80, /* lineNo */
  "standardTF_custXY_paraContrasts",   /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pathName */
};

static emlrtDCInfo xd_emlrtDCI = { 31, /* lineNo */
  18,                                  /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo sd_emlrtRTEI = { 37,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

static emlrtRTEInfo td_emlrtRTEI = { 43,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

static emlrtRTEInfo ud_emlrtRTEI = { 49,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

static emlrtRTEInfo vd_emlrtRTEI = { 55,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

static emlrtDCInfo yd_emlrtDCI = { 58, /* lineNo */
  34,                                  /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo hb_emlrtECI = { 1,  /* nDims */
  66,                                  /* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

static emlrtBCInfo sx_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  115,                                 /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tx_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  94,                                  /* colNo */
  "backgs",                            /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ux_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  107,                                 /* colNo */
  "backsType",                         /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo ib_emlrtECI = { 1,  /* nDims */
  76,                                  /* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

static emlrtECInfo jb_emlrtECI = { 1,  /* nDims */
  77,                                  /* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

static emlrtBCInfo vx_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  20,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wx_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  34,                                  /* colNo */
  "customFiles",                       /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xx_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  18,                                  /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yx_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  16,                                  /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ay_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  15,                                  /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo by_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  17,                                  /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cy_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  65,                                  /* lineNo */
  15,                                  /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dy_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  15,                                  /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ey_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  18,                                  /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fy_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  18,                                  /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gy_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  16,                                  /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo ae_emlrtDCI = { 23, /* lineNo */
  17,                                  /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo be_emlrtDCI = { 22, /* lineNo */
  16,                                  /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo ce_emlrtDCI = { 22, /* lineNo */
  16,                                  /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo de_emlrtDCI = { 25, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo ee_emlrtDCI = { 29, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo hy_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  72,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo iy_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  82,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jy_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  93,                                  /* colNo */
  "cScales",                           /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ky_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  104,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ly_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  113,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo my_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  122,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ny_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  6,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oy_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  16,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo py_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  27,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qy_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  34,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ry_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  42,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sy_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  50,                                  /* colNo */
  "resols",                            /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ty_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  34,                                  /* colNo */
  "cCustFiles",                        /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uy_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  80,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vy_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  17,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wy_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xy_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  65,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yy_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo aab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  30,                                  /* colNo */
  "sfs",                               /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  37,                                  /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  48,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  63,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  74,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  88,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  40,                                  /* colNo */
  "nbas",                              /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo iab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  48,                                  /* colNo */
  "nbss",                              /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  56,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  69,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  118,                                 /* colNo */
  "resols",                            /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  9,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  9,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo ms_emlrtRTEI = { 22,/* lineNo */
  10,                                  /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

static emlrtRTEInfo ns_emlrtRTEI = { 25,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

static emlrtRTEInfo os_emlrtRTEI = { 29,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

static emlrtRTEInfo ps_emlrtRTEI = { 22,/* lineNo */
  16,                                  /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

static emlrtRTEInfo qs_emlrtRTEI = { 38,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

static emlrtRTEInfo rs_emlrtRTEI = { 44,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

static emlrtRTEInfo ss_emlrtRTEI = { 50,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

static emlrtRTEInfo ts_emlrtRTEI = { 61,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

static emlrtRTEInfo us_emlrtRTEI = { 65,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

static emlrtRTEInfo vs_emlrtRTEI = { 66,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

static emlrtRTEInfo ws_emlrtRTEI = { 68,/* lineNo */
  63,                                  /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

static emlrtRTEInfo xs_emlrtRTEI = { 69,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

static emlrtRTEInfo ys_emlrtRTEI = { 76,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

static emlrtRTEInfo at_emlrtRTEI = { 77,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

static emlrtRTEInfo bt_emlrtRTEI = { 64,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

static emlrtRTEInfo ct_emlrtRTEI = { 68,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

static emlrtRTEInfo dt_emlrtRTEI = { 3,/* lineNo */
  18,                                  /* colNo */
  "standardTF_custXY_paraContrasts",   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custXY/standardTF_custXY_paraContrasts.m"/* pName */
};

/* Function Definitions */
void standardTF_custXY_paraContrasts(const emlrtStack *sp, const struct0_T
  *problemDef, const cell_16 *problemDef_cells, const struct2_T *controls,
  emxArray_real_T *outSsubs, emxArray_real_T *backgs, emxArray_real_T *qshifts,
  emxArray_real_T *sfs, emxArray_real_T *nbas, emxArray_real_T *nbss,
  emxArray_real_T *resols, emxArray_real_T *chis, emxArray_cell_wrap_12
  *reflectivity, emxArray_cell_wrap_12 *Simulation, emxArray_cell_wrap_14
  *shifted_data, emxArray_cell_wrap_10 *layerSlds, emxArray_cell_wrap_14
  *sldProfiles, emxArray_cell_wrap_28 *allLayers, emxArray_real_T *allRoughs)
{
  emlrtStack st;
  emxArray_real_T *Simul;
  emxArray_real_T *b_problemDef_cells;
  emxArray_real_T *b_shifted_dat;
  emxArray_real_T *layerSld;
  emxArray_real_T *reflect;
  emxArray_real_T *shifted_dat;
  emxArray_real_T *sldProfile;
  real_T d;
  real_T numberOfContrasts;
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

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
  numberOfContrasts = problemDef->numberOfContrasts;

  /* Pre-Allocation... */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &ce_emlrtDCI, sp);
  }

  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &be_emlrtDCI, sp);
  }

  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &ms_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ae_emlrtDCI, sp);
  }

  i1 = nbas->size[0];
  loop_ub = (int32_T)problemDef->numberOfContrasts;
  nbas->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, nbas, i1, &ns_emlrtRTEI);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &de_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    nbas->data[i1] = 0.0;
  }

  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ee_emlrtDCI, sp);
  }

  i1 = outSsubs->size[0];
  outSsubs->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, outSsubs, i1, &os_emlrtRTEI);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ee_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    outSsubs->data[i1] = 0.0;
  }

  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &xd_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &sd_emlrtRTEI, sp);
  i = reflectivity->size[0];
  reflectivity->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_12(sp, reflectivity, i, &ps_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &xx_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &qs_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &xx_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &qs_emlrtRTEI);
    i = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &xx_emlrtBCI, sp);
    }

    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &xx_emlrtBCI, sp);
    }

    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &qab_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &qab_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &qab_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &qab_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &td_emlrtRTEI, sp);
  i = Simulation->size[0];
  Simulation->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_12(sp, Simulation, i, &ps_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &yx_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &rs_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &yx_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &rs_emlrtRTEI);
    i = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &yx_emlrtBCI, sp);
    }

    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &yx_emlrtBCI, sp);
    }

    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &rab_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &rab_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &rab_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &rab_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &ud_emlrtRTEI, sp);
  i = allLayers->size[0];
  allLayers->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_28(sp, allLayers, i, &ps_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &ay_emlrtBCI,
        sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &ss_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &ay_emlrtBCI,
        sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &ss_emlrtRTEI);
    i = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &ay_emlrtBCI,
        sp);
    }

    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &ay_emlrtBCI,
        sp);
    }

    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
        &sab_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &sab_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &vd_emlrtRTEI, sp);
  i = qshifts->size[0];
  qshifts->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, qshifts, i, &ms_emlrtRTEI);
  i = sfs->size[0];
  sfs->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, sfs, i, &ms_emlrtRTEI);
  i = nbss->size[0];
  nbss->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, nbss, i, &ms_emlrtRTEI);
  i = resols->size[0];
  resols->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, resols, i, &ms_emlrtRTEI);
  i = allRoughs->size[0];
  allRoughs->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, allRoughs, i, &ms_emlrtRTEI);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &ps_emlrtRTEI);
  i = layerSlds->size[0];
  layerSlds->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &ps_emlrtRTEI);
  i = allLayers->size[0];
  allLayers->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_28(sp, allLayers, i, &ps_emlrtRTEI);
  i = shifted_data->size[0];
  shifted_data->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &ps_emlrtRTEI);
  i = chis->size[0];
  chis->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, chis, i, &ms_emlrtRTEI);
  i = Simulation->size[0];
  Simulation->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_12(sp, Simulation, i, &ps_emlrtRTEI);
  i = reflectivity->size[0];
  reflectivity->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_12(sp, reflectivity, i, &ps_emlrtRTEI);
  emxInit_real_T(sp, &layerSld, 2, &bt_emlrtRTEI, true);
  emxInit_real_T(sp, &shifted_dat, 2, &ct_emlrtRTEI, true);
  emxInit_real_T(sp, &sldProfile, 2, &dt_emlrtRTEI, true);
  emxInit_real_T(sp, &reflect, 2, &dt_emlrtRTEI, true);
  emxInit_real_T(sp, &Simul, 2, &dt_emlrtRTEI, true);
  emxInit_real_T(sp, &b_shifted_dat, 1, &qh_emlrtRTEI, true);
  emxInit_real_T(sp, &b_problemDef_cells, 2, &ws_emlrtRTEI, true);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if ((int32_T)(b_i + 1U) > problemDef->contrastBacks->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastBacks->size[1], &hy_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > problemDef->contrastShifts->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastShifts->size[1], &iy_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > problemDef->contrastScales->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastScales->size[1], &jy_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > problemDef->contrastNbas->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastNbas->size[1], &ky_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > problemDef->contrastNbss->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastNbss->size[1], &ly_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > problemDef->contrastRes->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastRes->size[1], &my_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > backgs->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, backgs->size[0],
        &ny_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > qshifts->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, qshifts->size[0],
        &oy_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > sfs->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, sfs->size[0],
        &py_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, nbas->size[0],
        &qy_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, nbss->size[0],
        &ry_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > resols->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, resols->size[0],
        &sy_emlrtBCI, sp);
    }

    st.site = &oi_emlrtRSI;
    backSort(&st, problemDef->contrastBacks->data[b_i],
             problemDef->contrastShifts->data[b_i], problemDef->
             contrastScales->data[b_i], problemDef->contrastNbas->data[b_i],
             problemDef->contrastNbss->data[b_i], problemDef->contrastRes->
             data[b_i], problemDef->backs, problemDef->shifts, problemDef->sf,
             problemDef->nba, problemDef->nbs, problemDef->res, &backgs->
             data[b_i], &qshifts->data[b_i], &sfs->data[b_i], &nbas->data[b_i],
             &nbss->data[b_i], &resols->data[b_i]);
    if ((int32_T)(b_i + 1U) > problemDef->contrastCustomFiles->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
        problemDef->contrastCustomFiles->size[1], &ty_emlrtBCI, sp);
    }

    d = problemDef->contrastCustomFiles->data[b_i];
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &yd_emlrtDCI, sp);
    }

    if (((int32_T)d - 1 < 0) || ((int32_T)d - 1 > problemDef_cells->f14->size[1]
         - 1)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d - 1, 0, problemDef_cells->
        f14->size[1] - 1, &wx_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, nbss->size[0],
        &uy_emlrtBCI, sp);
    }

    if ((int32_T)(b_i + 1U) > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, allRoughs->size[0],
        &vy_emlrtBCI, sp);
    }

    st.site = &pi_emlrtRSI;
    b_call_customLayers(&st, problemDef->params, (real_T)b_i + 1.0,
                        problemDef_cells->f14->data[(int32_T)
                        problemDef->contrastCustomFiles->data[b_i] - 1].f1, nbas,
                        nbss->data[b_i], numberOfContrasts, sldProfile,
                        &allRoughs->data[b_i]);
    b_loop_ub = sldProfile->size[0] * sldProfile->size[1];
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &by_emlrtBCI, sp);
    }

    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &ts_emlrtRTEI);
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &by_emlrtBCI, sp);
    }

    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = sldProfile->size[1];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &ts_emlrtRTEI);
    i = sldProfiles->size[0];
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &by_emlrtBCI, sp);
    }

    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &by_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &wy_emlrtBCI, sp);
      }

      sldProfiles->data[b_i].f1->data[i1] = sldProfile->data[i1];
    }

    st.site = &qi_emlrtRSI;
    b_resampleLayers(&st, sldProfile, controls->resamPars, layerSld);
    b_loop_ub = layerSld->size[0] * layerSld->size[1];
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &cy_emlrtBCI,
        sp);
    }

    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &us_emlrtRTEI);
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &cy_emlrtBCI,
        sp);
    }

    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &us_emlrtRTEI);
    i = layerSlds->size[0];
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &cy_emlrtBCI,
        sp);
    }

    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &cy_emlrtBCI,
        sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &xy_emlrtBCI, sp);
      }

      layerSlds->data[b_i].f1->data[i1] = layerSld->data[i1];
    }

    if (10000 < layerSld->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, layerSld->size[0], &hb_emlrtECI, sp);
    }

    b_loop_ub = layerSld->size[0] * layerSld->size[1];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &dy_emlrtBCI,
        sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = layerSld->size[0];
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &vs_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &dy_emlrtBCI,
        sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &vs_emlrtRTEI);
    i = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &dy_emlrtBCI,
        sp);
    }

    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &dy_emlrtBCI,
        sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &yy_emlrtBCI, sp);
      }

      allLayers->data[b_i].f1->data[i1] = layerSld->data[i1];
    }

    if (b_i + 1 > sfs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, sfs->size[0], &aab_emlrtBCI, sp);
    }

    if (b_i + 1 > qshifts->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, qshifts->size[0], &bab_emlrtBCI,
        sp);
    }

    if (b_i + 1 > problemDef->dataPresent->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, problemDef->dataPresent->size[1],
        &cab_emlrtBCI, sp);
    }

    if (b_i > problemDef_cells->f2->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f2->size[1] - 1,
        &dab_emlrtBCI, sp);
    }

    if (b_i > problemDef_cells->f3->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f3->size[1] - 1,
        &eab_emlrtBCI, sp);
    }

    if (b_i > problemDef_cells->f4->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f4->size[1] - 1,
        &fab_emlrtBCI, sp);
    }

    i = b_problemDef_cells->size[0] * b_problemDef_cells->size[1];
    b_problemDef_cells->size[0] = problemDef_cells->f2->data[b_i].f1->size[0];
    b_problemDef_cells->size[1] = problemDef_cells->f2->data[b_i].f1->size[1];
    emxEnsureCapacity_real_T(sp, b_problemDef_cells, i, &ws_emlrtRTEI);
    b_loop_ub = problemDef_cells->f2->data[b_i].f1->size[0] *
      problemDef_cells->f2->data[b_i].f1->size[1] - 1;
    for (i = 0; i <= b_loop_ub; i++) {
      b_problemDef_cells->data[i] = problemDef_cells->f2->data[b_i].f1->data[i];
    }

    st.site = &ri_emlrtRSI;
    shiftdata(&st, sfs->data[b_i], qshifts->data[b_i], problemDef->
              dataPresent->data[b_i], b_problemDef_cells, problemDef_cells->
              f3->data[b_i].f1, (real_T *)problemDef_cells->f4->data[b_i]
              .f1->data, problemDef_cells->f4->data[b_i].f1->size, shifted_dat);
    b_loop_ub = shifted_dat->size[0] * shifted_dat->size[1];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &ey_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &xs_emlrtRTEI);
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &ey_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[1] = shifted_dat->size[1];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &xs_emlrtRTEI);
    i = shifted_data->size[0];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &ey_emlrtBCI, sp);
    }

    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &ey_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &gab_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[i1] = shifted_dat->data[i1];
    }

    i = b_i + 1;
    if (i > (int32_T)numberOfContrasts) {
      emlrtDynamicBoundsCheckR2012b(i, 1, (int32_T)numberOfContrasts,
        &sx_emlrtBCI, sp);
    }

    if (b_i + 1 > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbas->size[0], &hab_emlrtBCI, sp);
    }

    if (b_i + 1 > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbss->size[0], &iab_emlrtBCI, sp);
    }

    if (b_i > problemDef_cells->f4->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f4->size[1] - 1,
        &jab_emlrtBCI, sp);
    }

    if (b_i > problemDef_cells->f1->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f1->size[1] - 1,
        &kab_emlrtBCI, sp);
    }

    if (b_i + 1 > resols->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, resols->size[0], &lab_emlrtBCI,
        sp);
    }

    st.site = &si_emlrtRSI;
    callReflectivity(&st, nbas->data[b_i], nbss->data[b_i], (real_T *)
                     problemDef_cells->f4->data[b_i].f1->data,
                     problemDef_cells->f4->data[b_i].f1->size,
                     problemDef_cells->f1->data[b_i].f1, shifted_dat, layerSld,
                     0.0, resols->data[b_i], reflect, Simul);
    st.site = &ti_emlrtRSI;
    i = b_i + 1;
    if (i > backgs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, backgs->size[0], &tx_emlrtBCI, &st);
    }

    i = b_i + 1;
    if (i > problemDef->contrastBacksType->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastBacksType->size[1],
        &ux_emlrtBCI, &st);
    }

    if (problemDef->contrastBacksType->data[b_i] != (int32_T)muDoubleScalarFloor
        (problemDef->contrastBacksType->data[b_i])) {
      emlrtIntegerCheckR2012b(problemDef->contrastBacksType->data[b_i],
        &cb_emlrtDCI, &st);
    }

    switch ((int32_T)problemDef->contrastBacksType->data[b_i]) {
     case 1:
      /* Add background to the simulation */
      b_loop_ub = reflect->size[0] * reflect->size[1];
      i = reflect->size[0] * reflect->size[1];
      reflect->size[1] = 2;
      emxEnsureCapacity_real_T(&st, reflect, i, &ph_emlrtRTEI);
      for (i = 0; i < b_loop_ub; i++) {
        reflect->data[i] += backgs->data[b_i];
      }

      b_loop_ub = Simul->size[0] * Simul->size[1];
      i = Simul->size[0] * Simul->size[1];
      Simul->size[1] = 2;
      emxEnsureCapacity_real_T(&st, Simul, i, &rh_emlrtRTEI);
      for (i = 0; i < b_loop_ub; i++) {
        Simul->data[i] += backgs->data[b_i];
      }
      break;

     case 2:
      /*          %Subtract the background from the data.. */
      if (2 > shifted_dat->size[1]) {
        emlrtDynamicBoundsCheckR2012b(2, 1, shifted_dat->size[1], &re_emlrtBCI,
          &st);
      }

      emlrtSubAssignSizeCheckR2012b(&shifted_dat->size[0], 1, &shifted_dat->
        size[0], 1, &emlrtECI, &st);
      b_loop_ub = shifted_dat->size[0] - 1;
      i = b_shifted_dat->size[0];
      b_shifted_dat->size[0] = shifted_dat->size[0];
      emxEnsureCapacity_real_T(&st, b_shifted_dat, i, &qh_emlrtRTEI);
      for (i = 0; i <= b_loop_ub; i++) {
        b_shifted_dat->data[i] = shifted_dat->data[i + shifted_dat->size[0]] -
          backgs->data[b_i];
      }

      b_loop_ub = b_shifted_dat->size[0];
      for (i = 0; i < b_loop_ub; i++) {
        shifted_dat->data[i + shifted_dat->size[0]] = b_shifted_dat->data[i];
      }

      /* shifted_dat(:,3) = shifted_dat(:,3) - backg;    */
      break;
    }

    if (10000 < reflect->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, reflect->size[0], &ib_emlrtECI, sp);
    }

    b_loop_ub = reflect->size[0] * reflect->size[1];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &fy_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = reflect->size[0];
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &ys_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &fy_emlrtBCI, sp);
    }

    i = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &ys_emlrtRTEI);
    i = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &fy_emlrtBCI, sp);
    }

    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &fy_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &mab_emlrtBCI, sp);
      }

      reflectivity->data[b_i].f1->data[i1] = reflect->data[i1];
    }

    if (10000 < Simul->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, Simul->size[0], &jb_emlrtECI, sp);
    }

    b_loop_ub = Simul->size[0] * Simul->size[1];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &gy_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = Simul->size[0];
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &at_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &gy_emlrtBCI, sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &at_emlrtRTEI);
    i = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &gy_emlrtBCI, sp);
    }

    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &gy_emlrtBCI, sp);
    }

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &nab_emlrtBCI, sp);
      }

      Simulation->data[b_i].f1->data[i1] = Simul->data[i1];
    }

    i = b_i + 1;
    if (i > problemDef->dataPresent->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->dataPresent->size[1],
        &vx_emlrtBCI, sp);
    }

    st.site = &ui_emlrtRSI;
    if (muDoubleScalarIsNaN(problemDef->dataPresent->data[b_i])) {
      emlrtErrorWithMessageIdR2018a(&st, &nd_emlrtRTEI, "MATLAB:nologicalnan",
        "MATLAB:nologicalnan", 0);
    }

    if (problemDef->dataPresent->data[b_i] != 0.0) {
      if (b_i + 1 > chis->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, chis->size[0], &pab_emlrtBCI,
          sp);
      }

      st.site = &vi_emlrtRSI;
      chis->data[b_i] = chiSquared(&st, shifted_dat, reflect, problemDef->
        params->size[1]);
    } else {
      if (b_i + 1 > chis->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, chis->size[0], &oab_emlrtBCI,
          sp);
      }

      chis->data[b_i] = 0.0;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_problemDef_cells);
  emxFree_real_T(&b_shifted_dat);
  emxFree_real_T(&Simul);
  emxFree_real_T(&reflect);
  emxFree_real_T(&sldProfile);
  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&layerSld);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_custXY_paraContrasts.c) */
