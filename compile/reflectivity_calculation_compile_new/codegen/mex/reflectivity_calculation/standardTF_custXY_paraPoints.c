/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * standardTF_custXY_paraPoints.c
 *
 * Code generation for function 'standardTF_custXY_paraPoints'
 *
 */

/* Include files */
#include "standardTF_custXY_paraPoints.h"
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
static emlrtRSInfo oi_emlrtRSI = {
    59,                             /* lineNo */
    "standardTF_custXY_paraPoints", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pathName */
};

static emlrtRSInfo pi_emlrtRSI = {
    62,                             /* lineNo */
    "standardTF_custXY_paraPoints", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pathName */
};

static emlrtRSInfo qi_emlrtRSI = {
    67,                             /* lineNo */
    "standardTF_custXY_paraPoints", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pathName */
};

static emlrtRSInfo ri_emlrtRSI = {
    71,                             /* lineNo */
    "standardTF_custXY_paraPoints", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pathName */
};

static emlrtRSInfo si_emlrtRSI = {
    75,                             /* lineNo */
    "standardTF_custXY_paraPoints", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pathName */
};

static emlrtRSInfo ti_emlrtRSI = {
    77,                             /* lineNo */
    "standardTF_custXY_paraPoints", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pathName */
};

static emlrtRSInfo ui_emlrtRSI = {
    82,                             /* lineNo */
    "standardTF_custXY_paraPoints", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pathName */
};

static emlrtRSInfo vi_emlrtRSI = {
    83,                             /* lineNo */
    "standardTF_custXY_paraPoints", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pathName */
};

static emlrtDCInfo pd_emlrtDCI = {
    34,                             /* lineNo */
    18,                             /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    1                                                   /* checkKind */
};

static emlrtRTEInfo nd_emlrtRTEI = {
    40,                             /* lineNo */
    9,                              /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pName */
};

static emlrtRTEInfo od_emlrtRTEI = {
    46,                             /* lineNo */
    9,                              /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pName */
};

static emlrtRTEInfo pd_emlrtRTEI = {
    52,                             /* lineNo */
    9,                              /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pName */
};

static emlrtRTEInfo qd_emlrtRTEI = {
    58,                             /* lineNo */
    9,                              /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pName */
};

static emlrtDCInfo qd_emlrtDCI = {
    61,                             /* lineNo */
    34,                             /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    1                                                   /* checkKind */
};

static emlrtBCInfo by_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    75,                             /* lineNo */
    115,                            /* colNo */
    "outSsubs",                     /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo cy_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    77,                             /* lineNo */
    94,                             /* colNo */
    "backgs",                       /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo dy_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    77,                             /* lineNo */
    107,                            /* colNo */
    "backsType",                    /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo ey_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    82,                             /* lineNo */
    20,                             /* colNo */
    "dataPresent",                  /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo fy_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    61,                             /* lineNo */
    34,                             /* colNo */
    "customFiles",                  /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo gy_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    41,                             /* lineNo */
    18,                             /* colNo */
    "reflectivity",                 /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo hy_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    47,                             /* lineNo */
    16,                             /* colNo */
    "Simulation",                   /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo iy_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    53,                             /* lineNo */
    15,                             /* colNo */
    "allLayers",                    /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo jy_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    64,                             /* lineNo */
    17,                             /* colNo */
    "sldProfiles",                  /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo ky_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    68,                             /* lineNo */
    15,                             /* colNo */
    "layerSlds",                    /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo ly_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    69,                             /* lineNo */
    15,                             /* colNo */
    "allLayers",                    /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo my_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    72,                             /* lineNo */
    18,                             /* colNo */
    "shifted_data",                 /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo ny_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    79,                             /* lineNo */
    18,                             /* colNo */
    "reflectivity",                 /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo oy_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    80,                             /* lineNo */
    16,                             /* colNo */
    "Simulation",                   /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtDCInfo rd_emlrtDCI = {
    26,                             /* lineNo */
    17,                             /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    1                                                   /* checkKind */
};

static emlrtDCInfo sd_emlrtDCI = {
    25,                             /* lineNo */
    16,                             /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    1                                                   /* checkKind */
};

static emlrtDCInfo td_emlrtDCI = {
    25,                             /* lineNo */
    16,                             /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    4                                                   /* checkKind */
};

static emlrtDCInfo ud_emlrtDCI = {
    28,                             /* lineNo */
    1,                              /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    1                                                   /* checkKind */
};

static emlrtDCInfo vd_emlrtDCI = {
    32,                             /* lineNo */
    1,                              /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    1                                                   /* checkKind */
};

static emlrtBCInfo py_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    34,                             /* lineNo */
    36,                             /* colNo */
    "layerSlds",                    /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo qy_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    34,                             /* lineNo */
    36,                             /* colNo */
    "sldProfiles",                  /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo ry_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    34,                             /* lineNo */
    36,                             /* colNo */
    "shifted_data",                 /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo sy_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    34,                             /* lineNo */
    36,                             /* colNo */
    "reflectivity",                 /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo ty_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    34,                             /* lineNo */
    36,                             /* colNo */
    "Simulation",                   /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo uy_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    34,                             /* lineNo */
    36,                             /* colNo */
    "allLayers",                    /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo vy_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    59,                             /* lineNo */
    79,                             /* colNo */
    "cBacks",                       /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo wy_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    59,                             /* lineNo */
    90,                             /* colNo */
    "cShifts",                      /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo xy_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    59,                             /* lineNo */
    101,                            /* colNo */
    "cScales",                      /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo yy_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    59,                             /* lineNo */
    110,                            /* colNo */
    "cNbas",                        /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo aab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    59,                             /* lineNo */
    119,                            /* colNo */
    "cNbss",                        /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo bab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    59,                             /* lineNo */
    127,                            /* colNo */
    "cRes",                         /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo cab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    59,                             /* lineNo */
    13,                             /* colNo */
    "backgs",                       /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo dab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    59,                             /* lineNo */
    24,                             /* colNo */
    "qshifts",                      /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo eab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    59,                             /* lineNo */
    31,                             /* colNo */
    "sfs",                          /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo fab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    59,                             /* lineNo */
    39,                             /* colNo */
    "nbas",                         /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo gab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    59,                             /* lineNo */
    47,                             /* colNo */
    "nbss",                         /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo hab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    59,                             /* lineNo */
    57,                             /* colNo */
    "resols",                       /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo iab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    61,                             /* lineNo */
    45,                             /* colNo */
    "cCustFiles",                   /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo jab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    62,                             /* lineNo */
    85,                             /* colNo */
    "nbss",                         /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo kab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    62,                             /* lineNo */
    27,                             /* colNo */
    "allRoughs",                    /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo lab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    64,                             /* lineNo */
    5,                              /* colNo */
    "sldProfiles",                  /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo mab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    68,                             /* lineNo */
    5,                              /* colNo */
    "layerSlds",                    /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo nab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    69,                             /* lineNo */
    5,                              /* colNo */
    "allLayers",                    /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo oab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    71,                             /* lineNo */
    34,                             /* colNo */
    "sfs",                          /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo pab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    71,                             /* lineNo */
    45,                             /* colNo */
    "qshifts",                      /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo qab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    71,                             /* lineNo */
    60,                             /* colNo */
    "dataPresent",                  /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo rab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    71,                             /* lineNo */
    71,                             /* colNo */
    "allData",                      /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo sab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    71,                             /* lineNo */
    85,                             /* colNo */
    "dataLimits",                   /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo tab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    71,                             /* lineNo */
    98,                             /* colNo */
    "simLimits",                    /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo uab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    72,                             /* lineNo */
    5,                              /* colNo */
    "shifted_data",                 /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo vab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    75,                             /* lineNo */
    45,                             /* colNo */
    "nbas",                         /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo wab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    75,                             /* lineNo */
    53,                             /* colNo */
    "nbss",                         /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo xab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    75,                             /* lineNo */
    66,                             /* colNo */
    "simLimits",                    /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo yab_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    75,                             /* lineNo */
    82,                             /* colNo */
    "repeatLayers",                 /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo abb_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    75,                             /* lineNo */
    125,                            /* colNo */
    "resols",                       /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo bbb_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    79,                             /* lineNo */
    5,                              /* colNo */
    "reflectivity",                 /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo cbb_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    80,                             /* lineNo */
    5,                              /* colNo */
    "Simulation",                   /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo dbb_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    85,                             /* lineNo */
    14,                             /* colNo */
    "chis",                         /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo ebb_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    83,                             /* lineNo */
    14,                             /* colNo */
    "chis",                         /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo fbb_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    53,                             /* lineNo */
    5,                              /* colNo */
    "allLayers",                    /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo gbb_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    47,                             /* lineNo */
    5,                              /* colNo */
    "Simulation",                   /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtBCInfo hbb_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    41,                             /* lineNo */
    5,                              /* colNo */
    "reflectivity",                 /* aName */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtRTEInfo wr_emlrtRTEI = {
    25,                             /* lineNo */
    10,                             /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pName */
};

static emlrtRTEInfo xr_emlrtRTEI = {
    28,                             /* lineNo */
    1,                              /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pName */
};

static emlrtRTEInfo yr_emlrtRTEI = {
    32,                             /* lineNo */
    1,                              /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pName */
};

static emlrtRTEInfo as_emlrtRTEI = {
    3,                              /* lineNo */
    18,                             /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pName */
};

static emlrtRTEInfo bs_emlrtRTEI = {
    34,                             /* lineNo */
    36,                             /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pName */
};

static emlrtRTEInfo cs_emlrtRTEI = {
    41,                             /* lineNo */
    5,                              /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pName */
};

static emlrtRTEInfo ds_emlrtRTEI = {
    47,                             /* lineNo */
    5,                              /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pName */
};

static emlrtRTEInfo es_emlrtRTEI = {
    53,                             /* lineNo */
    5,                              /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pName */
};

static emlrtRTEInfo fs_emlrtRTEI = {
    64,                             /* lineNo */
    5,                              /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pName */
};

static emlrtRTEInfo gs_emlrtRTEI = {
    68,                             /* lineNo */
    5,                              /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pName */
};

static emlrtRTEInfo hs_emlrtRTEI = {
    69,                             /* lineNo */
    5,                              /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pName */
};

static emlrtRTEInfo is_emlrtRTEI = {
    71,                             /* lineNo */
    63,                             /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pName */
};

static emlrtRTEInfo js_emlrtRTEI = {
    72,                             /* lineNo */
    5,                              /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pName */
};

static emlrtRTEInfo ks_emlrtRTEI = {
    79,                             /* lineNo */
    5,                              /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pName */
};

static emlrtRTEInfo ls_emlrtRTEI = {
    80,                             /* lineNo */
    5,                              /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pName */
};

static emlrtRTEInfo ms_emlrtRTEI = {
    67,                             /* lineNo */
    5,                              /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pName */
};

static emlrtRTEInfo ns_emlrtRTEI = {
    71,                             /* lineNo */
    5,                              /* colNo */
    "standardTF_custXY_paraPoints", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraPoints.m" /* pName */
};

/* Function Definitions */
void standardTF_custXY_paraPoints(
    const emlrtStack *sp, const struct0_T *problemDef,
    const cell_16 *problemDef_cells, const struct2_T *controls,
    emxArray_real_T *outSsubs, emxArray_real_T *backgs,
    emxArray_real_T *qshifts, emxArray_real_T *sfs, emxArray_real_T *nbas,
    emxArray_real_T *nbss, emxArray_real_T *resols, emxArray_real_T *chis,
    emxArray_cell_wrap_9 *reflectivity, emxArray_cell_wrap_9 *Simulation,
    emxArray_cell_wrap_14 *shifted_data, emxArray_cell_wrap_10 *layerSlds,
    emxArray_cell_wrap_14 *sldProfiles, emxArray_cell_wrap_14 *allLayers,
    emxArray_real_T *allRoughs)
{
  cell_wrap_10 *layerSlds_data;
  cell_wrap_14 *allLayers_data;
  cell_wrap_14 *shifted_data_data;
  cell_wrap_14 *sldProfiles_data;
  cell_wrap_9 *Simulation_data;
  cell_wrap_9 *reflectivity_data;
  emlrtStack st;
  emxArray_real_T *Simul;
  emxArray_real_T *b_problemDef_cells;
  emxArray_real_T *b_shifted_dat;
  emxArray_real_T *layerSld;
  emxArray_real_T *reflect;
  emxArray_real_T *shifted_dat;
  emxArray_real_T *sldProfile;
  real_T d;
  real_T numberOfContrasts_tmp;
  real_T *Simul_data;
  real_T *allRoughs_data;
  real_T *backgs_data;
  real_T *chis_data;
  real_T *nbas_data;
  real_T *nbss_data;
  real_T *outSsubs_data;
  real_T *qshifts_data;
  real_T *reflect_data;
  real_T *resols_data;
  real_T *sfs_data;
  real_T *shifted_dat_data;
  int32_T b_i;
  int32_T b_layerSlds;
  int32_T i;
  int32_T i1;
  int32_T loop_ub_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /*  Multi threaded version of the custom XY profile over reflectivity points
   */
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
  numberOfContrasts_tmp = problemDef->numberOfContrasts;
  /* Pre-Allocation... */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &td_emlrtDCI,
                                (emlrtCTX)sp);
  }
  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &sd_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &wr_emlrtRTEI);
  backgs_data = backgs->data;
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &rd_emlrtDCI,
                            (emlrtCTX)sp);
  }
  loop_ub_tmp = (int32_T)problemDef->numberOfContrasts;
  i1 = nbas->size[0];
  nbas->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, nbas, i1, &xr_emlrtRTEI);
  nbas_data = nbas->data;
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ud_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    nbas_data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &vd_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = outSsubs->size[0];
  outSsubs->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, outSsubs, i1, &yr_emlrtRTEI);
  outSsubs_data = outSsubs->data;
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &vd_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    outSsubs_data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &pd_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i = layerSlds->size[0];
  layerSlds->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &as_emlrtRTEI);
  layerSlds_data = layerSlds->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    b_layerSlds = layerSlds->size[0] - 1;
    if (i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, layerSlds->size[0] - 1, &py_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    layerSlds_data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &py_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = layerSlds_data[i].f1->size[0] * layerSlds_data[i].f1->size[1];
    layerSlds_data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds_data[i].f1, i1, &as_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = sldProfiles->size[0];
  sldProfiles->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &as_emlrtRTEI);
  sldProfiles_data = sldProfiles->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    b_layerSlds = sldProfiles->size[0] - 1;
    if (i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, sldProfiles->size[0] - 1,
                                    &qy_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles_data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &qy_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sldProfiles_data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = shifted_data->size[0];
  shifted_data->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &as_emlrtRTEI);
  shifted_data_data = shifted_data->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    b_layerSlds = shifted_data->size[0] - 1;
    if (i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, shifted_data->size[0] - 1,
                                    &ry_emlrtBCI, (emlrtCTX)sp);
    }
    shifted_data_data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &ry_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    shifted_data_data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = reflectivity->size[0];
  reflectivity->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &as_emlrtRTEI);
  reflectivity_data = reflectivity->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    b_layerSlds = reflectivity->size[0] - 1;
    if (i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, reflectivity->size[0] - 1,
                                    &sy_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity_data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &sy_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = reflectivity_data[i].f1->size[0] * reflectivity_data[i].f1->size[1];
    reflectivity_data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity_data[i].f1, i1, &as_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &nd_emlrtRTEI, (emlrtCTX)sp);
  i = reflectivity->size[0];
  reflectivity->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &bs_emlrtRTEI);
  reflectivity_data = reflectivity->data;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &gy_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity_data[b_i].f1->size[0] * reflectivity_data[b_i].f1->size[1];
    reflectivity_data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity_data[b_i].f1, i, &cs_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &gy_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity_data[b_i].f1->size[0] * reflectivity_data[b_i].f1->size[1];
    reflectivity_data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity_data[b_i].f1, i, &cs_emlrtRTEI);
    i = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &gy_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity_data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &hbb_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity_data[b_i].f1->data[1] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &hbb_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity_data[b_i].f1->data[2] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &hbb_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity_data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  /* coder.varsize('reflectivity{:}',[10000 2],[1 0]); */
  i = Simulation->size[0];
  Simulation->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &as_emlrtRTEI);
  Simulation_data = Simulation->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    b_layerSlds = Simulation->size[0] - 1;
    if (i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, Simulation->size[0] - 1, &ty_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation_data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &ty_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = Simulation_data[i].f1->size[0] * Simulation_data[i].f1->size[1];
    Simulation_data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation_data[i].f1, i1, &as_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &od_emlrtRTEI, (emlrtCTX)sp);
  i = Simulation->size[0];
  Simulation->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &bs_emlrtRTEI);
  Simulation_data = Simulation->data;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &hy_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation_data[b_i].f1->size[0] * Simulation_data[b_i].f1->size[1];
    Simulation_data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation_data[b_i].f1, i, &ds_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &hy_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation_data[b_i].f1->size[0] * Simulation_data[b_i].f1->size[1];
    Simulation_data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation_data[b_i].f1, i, &ds_emlrtRTEI);
    i = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &hy_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation_data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &gbb_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation_data[b_i].f1->data[1] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &gbb_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation_data[b_i].f1->data[2] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &gbb_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation_data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  /* coder.varsize('Simulation{:}',[10000 2],[1 0]); */
  i = allLayers->size[0];
  allLayers->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &as_emlrtRTEI);
  allLayers_data = allLayers->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    b_layerSlds = allLayers->size[0] - 1;
    if (i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, allLayers->size[0] - 1, &uy_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers_data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &uy_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers_data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &pd_emlrtRTEI, (emlrtCTX)sp);
  i = allLayers->size[0];
  allLayers->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &bs_emlrtRTEI);
  allLayers_data = allLayers->data;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &iy_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers_data[b_i].f1->size[0] * allLayers_data[b_i].f1->size[1];
    allLayers_data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers_data[b_i].f1, i, &es_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &iy_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers_data[b_i].f1->size[0] * allLayers_data[b_i].f1->size[1];
    allLayers_data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers_data[b_i].f1, i, &es_emlrtRTEI);
    i = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &iy_emlrtBCI, (emlrtCTX)sp);
    }
    allLayers_data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &fbb_emlrtBCI, (emlrtCTX)sp);
    }
    allLayers_data[b_i].f1->data[1] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  /* coder.varsize('allLayers{:}',[10000 3],[1 1]); */
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &qd_emlrtRTEI, (emlrtCTX)sp);
  i = qshifts->size[0];
  qshifts->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, qshifts, i, &wr_emlrtRTEI);
  qshifts_data = qshifts->data;
  i = sfs->size[0];
  sfs->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, sfs, i, &wr_emlrtRTEI);
  sfs_data = sfs->data;
  i = nbss->size[0];
  nbss->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, nbss, i, &wr_emlrtRTEI);
  nbss_data = nbss->data;
  i = resols->size[0];
  resols->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, resols, i, &wr_emlrtRTEI);
  resols_data = resols->data;
  i = allRoughs->size[0];
  allRoughs->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, allRoughs, i, &wr_emlrtRTEI);
  allRoughs_data = allRoughs->data;
  i = sldProfiles->size[0];
  sldProfiles->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &bs_emlrtRTEI);
  sldProfiles_data = sldProfiles->data;
  i = layerSlds->size[0];
  layerSlds->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &bs_emlrtRTEI);
  layerSlds_data = layerSlds->data;
  i = allLayers->size[0];
  allLayers->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &bs_emlrtRTEI);
  allLayers_data = allLayers->data;
  i = shifted_data->size[0];
  shifted_data->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &bs_emlrtRTEI);
  shifted_data_data = shifted_data->data;
  i = chis->size[0];
  chis->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, chis, i, &wr_emlrtRTEI);
  chis_data = chis->data;
  i = Simulation->size[0];
  Simulation->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &bs_emlrtRTEI);
  Simulation_data = Simulation->data;
  i = reflectivity->size[0];
  reflectivity->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &bs_emlrtRTEI);
  reflectivity_data = reflectivity->data;
  emxInit_real_T(sp, &layerSld, 2, &ms_emlrtRTEI, true);
  emxInit_real_T(sp, &shifted_dat, 2, &ns_emlrtRTEI, true);
  emxInit_real_T(sp, &sldProfile, 2, &as_emlrtRTEI, true);
  emxInit_real_T(sp, &reflect, 2, &as_emlrtRTEI, true);
  emxInit_real_T(sp, &Simul, 2, &as_emlrtRTEI, true);
  emxInit_real_T(sp, &b_shifted_dat, 1, &oh_emlrtRTEI, true);
  emxInit_real_T(sp, &b_problemDef_cells, 2, &is_emlrtRTEI, true);
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    if ((int32_T)(b_i + 1U) > problemDef->contrastBacks->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastBacks->size[1],
                                    &vy_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastShifts->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastShifts->size[1],
                                    &wy_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastScales->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastScales->size[1],
                                    &xy_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastNbas->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastNbas->size[1],
                                    &yy_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastNbss->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastNbss->size[1],
                                    &aab_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastRes->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastRes->size[1],
                                    &bab_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > backgs->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, backgs->size[0],
                                    &cab_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > qshifts->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, qshifts->size[0],
                                    &dab_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > sfs->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, sfs->size[0],
                                    &eab_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, nbas->size[0],
                                    &fab_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, nbss->size[0],
                                    &gab_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > resols->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, resols->size[0],
                                    &hab_emlrtBCI, (emlrtCTX)sp);
    }
    st.site = &oi_emlrtRSI;
    backSort(
        &st, problemDef->contrastBacks->data[b_i],
        problemDef->contrastShifts->data[b_i],
        problemDef->contrastScales->data[b_i],
        problemDef->contrastNbas->data[b_i],
        problemDef->contrastNbss->data[b_i], problemDef->contrastRes->data[b_i],
        problemDef->backs, problemDef->shifts, problemDef->sf, problemDef->nba,
        problemDef->nbs, problemDef->res, &backgs_data[b_i], &qshifts_data[b_i],
        &sfs_data[b_i], &nbas_data[b_i], &nbss_data[b_i], &resols_data[b_i]);
    if ((int32_T)(b_i + 1U) > problemDef->contrastCustomFiles->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastCustomFiles->size[1],
                                    &iab_emlrtBCI, (emlrtCTX)sp);
    }
    d = problemDef->contrastCustomFiles->data[b_i];
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &qd_emlrtDCI, (emlrtCTX)sp);
    }
    if (((int32_T)d - 1 < 0) ||
        ((int32_T)d - 1 > problemDef_cells->f14->size[1] - 1)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d - 1, 0,
                                    problemDef_cells->f14->size[1] - 1,
                                    &fy_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, nbss->size[0],
                                    &jab_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, allRoughs->size[0],
                                    &kab_emlrtBCI, (emlrtCTX)sp);
    }
    st.site = &pi_emlrtRSI;
    b_call_customLayers(
        &st, problemDef->params, (real_T)b_i + 1.0,
        problemDef_cells->f14
            ->data[(int32_T)problemDef->contrastCustomFiles->data[b_i] - 1]
            .f1,
        nbas, nbss_data[b_i], numberOfContrasts_tmp, sldProfile,
        &allRoughs_data[b_i]);
    outSsubs_data = sldProfile->data;
    b_layerSlds = sldProfile->size[0] * sldProfile->size[1];
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &jy_emlrtBCI, (emlrtCTX)sp);
    }
    i = sldProfiles_data[b_i].f1->size[0] * sldProfiles_data[b_i].f1->size[1];
    sldProfiles_data[b_i].f1->size[0] = sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, sldProfiles_data[b_i].f1, i, &fs_emlrtRTEI);
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &jy_emlrtBCI, (emlrtCTX)sp);
    }
    i = sldProfiles_data[b_i].f1->size[0] * sldProfiles_data[b_i].f1->size[1];
    sldProfiles_data[b_i].f1->size[1] = sldProfile->size[1];
    emxEnsureCapacity_real_T(sp, sldProfiles_data[b_i].f1, i, &fs_emlrtRTEI);
    i = sldProfiles->size[0];
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &jy_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &jy_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &lab_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      sldProfiles_data[b_i].f1->data[i1] = outSsubs_data[i1];
    }
    st.site = &qi_emlrtRSI;
    b_resampleLayers(&st, sldProfile, controls->resamPars, layerSld);
    outSsubs_data = layerSld->data;
    b_layerSlds = layerSld->size[0] * 3;
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                    &ky_emlrtBCI, (emlrtCTX)sp);
    }
    i = layerSlds_data[b_i].f1->size[0] * layerSlds_data[b_i].f1->size[1];
    layerSlds_data[b_i].f1->size[0] = layerSld->size[0];
    emxEnsureCapacity_real_T(sp, layerSlds_data[b_i].f1, i, &gs_emlrtRTEI);
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                    &ky_emlrtBCI, (emlrtCTX)sp);
    }
    i = layerSlds_data[b_i].f1->size[0] * layerSlds_data[b_i].f1->size[1];
    layerSlds_data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds_data[b_i].f1, i, &gs_emlrtRTEI);
    i = layerSlds->size[0];
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                    &ky_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                    &ky_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &mab_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      layerSlds_data[b_i].f1->data[i1] = outSsubs_data[i1];
    }
    b_layerSlds = layerSld->size[0] * 3;
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &ly_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers_data[b_i].f1->size[0] * allLayers_data[b_i].f1->size[1];
    allLayers_data[b_i].f1->size[0] = layerSld->size[0];
    emxEnsureCapacity_real_T(sp, allLayers_data[b_i].f1, i, &hs_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &ly_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers_data[b_i].f1->size[0] * allLayers_data[b_i].f1->size[1];
    allLayers_data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers_data[b_i].f1, i, &hs_emlrtRTEI);
    i = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &ly_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &ly_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &nab_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      allLayers_data[b_i].f1->data[i1] = outSsubs_data[i1];
    }
    if (b_i + 1 > sfs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, sfs->size[0], &oab_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (b_i + 1 > qshifts->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, qshifts->size[0], &pab_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (b_i + 1 > problemDef->dataPresent->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                                    problemDef->dataPresent->size[1],
                                    &qab_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f2->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f2->size[1] - 1,
                                    &rab_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f3->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f3->size[1] - 1,
                                    &sab_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f4->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f4->size[1] - 1,
                                    &tab_emlrtBCI, (emlrtCTX)sp);
    }
    i = b_problemDef_cells->size[0] * b_problemDef_cells->size[1];
    b_problemDef_cells->size[0] = problemDef_cells->f2->data[b_i].f1->size[0];
    b_problemDef_cells->size[1] = problemDef_cells->f2->data[b_i].f1->size[1];
    emxEnsureCapacity_real_T(sp, b_problemDef_cells, i, &is_emlrtRTEI);
    outSsubs_data = b_problemDef_cells->data;
    b_layerSlds = problemDef_cells->f2->data[b_i].f1->size[0] *
                      problemDef_cells->f2->data[b_i].f1->size[1] -
                  1;
    for (i = 0; i <= b_layerSlds; i++) {
      outSsubs_data[i] = problemDef_cells->f2->data[b_i].f1->data[i];
    }
    st.site = &ri_emlrtRSI;
    shiftdata(&st, sfs_data[b_i], qshifts_data[b_i],
              problemDef->dataPresent->data[b_i], b_problemDef_cells,
              problemDef_cells->f3->data[b_i].f1,
              (real_T *)problemDef_cells->f4->data[b_i].f1->data,
              *(int32_T(*)[2])problemDef_cells->f4->data[b_i].f1->size,
              shifted_dat);
    outSsubs_data = shifted_dat->data;
    b_layerSlds = shifted_dat->size[0] * shifted_dat->size[1];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &my_emlrtBCI, (emlrtCTX)sp);
    }
    i = shifted_data_data[b_i].f1->size[0] * shifted_data_data[b_i].f1->size[1];
    shifted_data_data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, shifted_data_data[b_i].f1, i, &js_emlrtRTEI);
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &my_emlrtBCI, (emlrtCTX)sp);
    }
    i = shifted_data_data[b_i].f1->size[0] * shifted_data_data[b_i].f1->size[1];
    shifted_data_data[b_i].f1->size[1] = shifted_dat->size[1];
    emxEnsureCapacity_real_T(sp, shifted_data_data[b_i].f1, i, &js_emlrtRTEI);
    i = shifted_data->size[0];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &my_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &my_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &uab_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      shifted_data_data[b_i].f1->data[i1] = outSsubs_data[i1];
    }
    if (b_i + 1 > loop_ub_tmp) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, (int32_T)numberOfContrasts_tmp,
                                    &by_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i + 1 > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbas->size[0], &vab_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (b_i + 1 > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbss->size[0], &wab_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f4->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f4->size[1] - 1,
                                    &xab_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f1->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f1->size[1] - 1,
                                    &yab_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i + 1 > resols->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, resols->size[0], &abb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    st.site = &si_emlrtRSI;
    b_callReflectivity(&st, nbas_data[b_i], nbss_data[b_i],
                       (real_T *)problemDef_cells->f4->data[b_i].f1->data,
                       *(int32_T(*)[2])problemDef_cells->f4->data[b_i].f1->size,
                       problemDef_cells->f1->data[b_i].f1, shifted_dat,
                       layerSld, 0.0, resols_data[b_i], reflect, Simul);
    Simul_data = Simul->data;
    reflect_data = reflect->data;
    st.site = &ti_emlrtRSI;
    if (b_i + 1 > backgs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, backgs->size[0], &cy_emlrtBCI,
                                    &st);
    }
    if (b_i + 1 > problemDef->contrastBacksType->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                                    problemDef->contrastBacksType->size[1],
                                    &dy_emlrtBCI, &st);
    }
    if (problemDef->contrastBacksType->data[b_i] !=
        (int32_T)muDoubleScalarFloor(
            problemDef->contrastBacksType->data[b_i])) {
      emlrtIntegerCheckR2012b(problemDef->contrastBacksType->data[b_i],
                              &db_emlrtDCI, &st);
    }
    switch ((int32_T)problemDef->contrastBacksType->data[b_i]) {
    case 1:
      /* Add background to the simulation */
      b_layerSlds = reflect->size[0] * 2;
      i = reflect->size[0] * reflect->size[1];
      reflect->size[1] = 2;
      emxEnsureCapacity_real_T(&st, reflect, i, &nh_emlrtRTEI);
      reflect_data = reflect->data;
      for (i = 0; i < b_layerSlds; i++) {
        reflect_data[i] += backgs_data[b_i];
      }
      b_layerSlds = Simul->size[0] * 2;
      i = Simul->size[0] * Simul->size[1];
      Simul->size[1] = 2;
      emxEnsureCapacity_real_T(&st, Simul, i, &ph_emlrtRTEI);
      Simul_data = Simul->data;
      for (i = 0; i < b_layerSlds; i++) {
        Simul_data[i] += backgs_data[b_i];
      }
      break;
    case 2:
      /*          %Subtract the background from the data.. */
      if (2 > shifted_dat->size[1]) {
        emlrtDynamicBoundsCheckR2012b(2, 1, shifted_dat->size[1], &qf_emlrtBCI,
                                      &st);
      }
      emlrtSubAssignSizeCheckR2012b(&shifted_dat->size[0], 1,
                                    &shifted_dat->size[0], 1, &emlrtECI, &st);
      b_layerSlds = shifted_dat->size[0] - 1;
      i = b_shifted_dat->size[0];
      b_shifted_dat->size[0] = shifted_dat->size[0];
      emxEnsureCapacity_real_T(&st, b_shifted_dat, i, &oh_emlrtRTEI);
      shifted_dat_data = b_shifted_dat->data;
      for (i = 0; i <= b_layerSlds; i++) {
        shifted_dat_data[i] =
            outSsubs_data[i + shifted_dat->size[0]] - backgs_data[b_i];
      }
      b_layerSlds = b_shifted_dat->size[0];
      for (i = 0; i < b_layerSlds; i++) {
        outSsubs_data[i + shifted_dat->size[0]] = shifted_dat_data[i];
      }
      /* shifted_dat(:,3) = shifted_dat(:,3) - backg;    */
      break;
    }
    b_layerSlds = reflect->size[0] * 2;
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &ny_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity_data[b_i].f1->size[0] * reflectivity_data[b_i].f1->size[1];
    reflectivity_data[b_i].f1->size[0] = reflect->size[0];
    emxEnsureCapacity_real_T(sp, reflectivity_data[b_i].f1, i, &ks_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &ny_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity_data[b_i].f1->size[0] * reflectivity_data[b_i].f1->size[1];
    reflectivity_data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity_data[b_i].f1, i, &ks_emlrtRTEI);
    i = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &ny_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &ny_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &bbb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      reflectivity_data[b_i].f1->data[i1] = reflect_data[i1];
    }
    b_layerSlds = Simul->size[0] * 2;
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &oy_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation_data[b_i].f1->size[0] * Simulation_data[b_i].f1->size[1];
    Simulation_data[b_i].f1->size[0] = Simul->size[0];
    emxEnsureCapacity_real_T(sp, Simulation_data[b_i].f1, i, &ls_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &oy_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation_data[b_i].f1->size[0] * Simulation_data[b_i].f1->size[1];
    Simulation_data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation_data[b_i].f1, i, &ls_emlrtRTEI);
    i = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &oy_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &oy_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &cbb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      Simulation_data[b_i].f1->data[i1] = Simul_data[i1];
    }
    if (b_i + 1 > problemDef->dataPresent->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                                    problemDef->dataPresent->size[1],
                                    &ey_emlrtBCI, (emlrtCTX)sp);
    }
    st.site = &ui_emlrtRSI;
    if (muDoubleScalarIsNaN(problemDef->dataPresent->data[b_i])) {
      emlrtErrorWithMessageIdR2018a(&st, &md_emlrtRTEI, "MATLAB:nologicalnan",
                                    "MATLAB:nologicalnan", 0);
    }
    if (problemDef->dataPresent->data[b_i] != 0.0) {
      if (b_i + 1 > chis->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, chis->size[0], &ebb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      st.site = &vi_emlrtRSI;
      chis_data[b_i] =
          chiSquared(&st, shifted_dat, reflect, problemDef->params->size[1]);
    } else {
      if (b_i + 1 > chis->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, chis->size[0], &dbb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      chis_data[b_i] = 0.0;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_real_T(sp, &b_problemDef_cells);
  emxFree_real_T(sp, &b_shifted_dat);
  emxFree_real_T(sp, &Simul);
  emxFree_real_T(sp, &reflect);
  emxFree_real_T(sp, &sldProfile);
  emxFree_real_T(sp, &shifted_dat);
  emxFree_real_T(sp, &layerSld);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (standardTF_custXY_paraPoints.c) */
