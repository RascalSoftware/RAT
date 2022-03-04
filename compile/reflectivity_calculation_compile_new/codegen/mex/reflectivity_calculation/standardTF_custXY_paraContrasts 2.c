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
static emlrtRSInfo ej_emlrtRSI = {
    56,                                /* lineNo */
    "standardTF_custXY_paraContrasts", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pathName */
};

static emlrtRSInfo fj_emlrtRSI = {
    59,                                /* lineNo */
    "standardTF_custXY_paraContrasts", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pathName */
};

static emlrtRSInfo gj_emlrtRSI = {
    64,                                /* lineNo */
    "standardTF_custXY_paraContrasts", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pathName */
};

static emlrtRSInfo hj_emlrtRSI = {
    68,                                /* lineNo */
    "standardTF_custXY_paraContrasts", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pathName */
};

static emlrtRSInfo ij_emlrtRSI = {
    72,                                /* lineNo */
    "standardTF_custXY_paraContrasts", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pathName */
};

static emlrtRSInfo jj_emlrtRSI = {
    74,                                /* lineNo */
    "standardTF_custXY_paraContrasts", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pathName */
};

static emlrtRSInfo kj_emlrtRSI = {
    79,                                /* lineNo */
    "standardTF_custXY_paraContrasts", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pathName */
};

static emlrtRSInfo lj_emlrtRSI = {
    80,                                /* lineNo */
    "standardTF_custXY_paraContrasts", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pathName */
};

static emlrtDCInfo vd_emlrtDCI = {
    31,                                /* lineNo */
    18,                                /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    1                                                      /* checkKind */
};

static emlrtRTEInfo qd_emlrtRTEI = {
    37,                                /* lineNo */
    9,                                 /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

static emlrtRTEInfo rd_emlrtRTEI = {
    43,                                /* lineNo */
    9,                                 /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

static emlrtRTEInfo sd_emlrtRTEI = {
    49,                                /* lineNo */
    9,                                 /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

static emlrtRTEInfo td_emlrtRTEI = {
    55,                                /* lineNo */
    9,                                 /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

static emlrtDCInfo wd_emlrtDCI = {
    58,                                /* lineNo */
    34,                                /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    1                                                      /* checkKind */
};

static emlrtECInfo fb_emlrtECI = {
    1,                                 /* nDims */
    66,                                /* lineNo */
    5,                                 /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

static emlrtBCInfo mbb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    72,                                /* lineNo */
    115,                               /* colNo */
    "outSsubs",                        /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo nbb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    74,                                /* lineNo */
    94,                                /* colNo */
    "backgs",                          /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo obb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    74,                                /* lineNo */
    107,                               /* colNo */
    "backsType",                       /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtECInfo gb_emlrtECI = {
    1,                                 /* nDims */
    76,                                /* lineNo */
    5,                                 /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

static emlrtECInfo hb_emlrtECI = {
    1,                                 /* nDims */
    77,                                /* lineNo */
    5,                                 /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

static emlrtBCInfo pbb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    79,                                /* lineNo */
    20,                                /* colNo */
    "dataPresent",                     /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo qbb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    58,                                /* lineNo */
    34,                                /* colNo */
    "customFiles",                     /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo rbb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    38,                                /* lineNo */
    18,                                /* colNo */
    "reflectivity",                    /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo sbb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    44,                                /* lineNo */
    16,                                /* colNo */
    "Simulation",                      /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo tbb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    50,                                /* lineNo */
    15,                                /* colNo */
    "allLayers",                       /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo ubb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    61,                                /* lineNo */
    17,                                /* colNo */
    "sldProfiles",                     /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo vbb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    65,                                /* lineNo */
    15,                                /* colNo */
    "layerSlds",                       /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo wbb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    66,                                /* lineNo */
    15,                                /* colNo */
    "allLayers",                       /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo xbb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    69,                                /* lineNo */
    18,                                /* colNo */
    "shifted_data",                    /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo ybb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    76,                                /* lineNo */
    18,                                /* colNo */
    "reflectivity",                    /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo acb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    77,                                /* lineNo */
    16,                                /* colNo */
    "Simulation",                      /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtDCInfo xd_emlrtDCI = {
    23,                                /* lineNo */
    17,                                /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    1                                                      /* checkKind */
};

static emlrtDCInfo yd_emlrtDCI = {
    22,                                /* lineNo */
    16,                                /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    1                                                      /* checkKind */
};

static emlrtDCInfo ae_emlrtDCI = {
    22,                                /* lineNo */
    16,                                /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    4                                                      /* checkKind */
};

static emlrtDCInfo be_emlrtDCI = {
    25,                                /* lineNo */
    1,                                 /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    1                                                      /* checkKind */
};

static emlrtDCInfo ce_emlrtDCI = {
    29,                                /* lineNo */
    1,                                 /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    1                                                      /* checkKind */
};

static emlrtBCInfo bcb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    31,                                /* lineNo */
    36,                                /* colNo */
    "allLayers",                       /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo ccb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    31,                                /* lineNo */
    36,                                /* colNo */
    "layerSlds",                       /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo dcb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    31,                                /* lineNo */
    36,                                /* colNo */
    "sldProfiles",                     /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo ecb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    31,                                /* lineNo */
    36,                                /* colNo */
    "shifted_data",                    /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo fcb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    31,                                /* lineNo */
    36,                                /* colNo */
    "reflectivity",                    /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo gcb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    31,                                /* lineNo */
    36,                                /* colNo */
    "Simulation",                      /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo hcb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    56,                                /* lineNo */
    72,                                /* colNo */
    "cBacks",                          /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo icb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    56,                                /* lineNo */
    82,                                /* colNo */
    "cShifts",                         /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo jcb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    56,                                /* lineNo */
    93,                                /* colNo */
    "cScales",                         /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo kcb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    56,                                /* lineNo */
    104,                               /* colNo */
    "cNbas",                           /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo lcb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    56,                                /* lineNo */
    113,                               /* colNo */
    "cNbss",                           /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo mcb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    56,                                /* lineNo */
    122,                               /* colNo */
    "cRes",                            /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo ncb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    56,                                /* lineNo */
    6,                                 /* colNo */
    "backgs",                          /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo ocb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    56,                                /* lineNo */
    16,                                /* colNo */
    "qshifts",                         /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo pcb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    56,                                /* lineNo */
    27,                                /* colNo */
    "sfs",                             /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo qcb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    56,                                /* lineNo */
    34,                                /* colNo */
    "nbas",                            /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo rcb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    56,                                /* lineNo */
    42,                                /* colNo */
    "nbss",                            /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo scb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    56,                                /* lineNo */
    50,                                /* colNo */
    "resols",                          /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo tcb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    58,                                /* lineNo */
    34,                                /* colNo */
    "cCustFiles",                      /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo ucb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    59,                                /* lineNo */
    80,                                /* colNo */
    "nbss",                            /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo vcb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    59,                                /* lineNo */
    17,                                /* colNo */
    "allRoughs",                       /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo wcb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    61,                                /* lineNo */
    5,                                 /* colNo */
    "sldProfiles",                     /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo xcb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    65,                                /* lineNo */
    5,                                 /* colNo */
    "layerSlds",                       /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo ycb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    66,                                /* lineNo */
    5,                                 /* colNo */
    "allLayers",                       /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo adb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    68,                                /* lineNo */
    30,                                /* colNo */
    "sfs",                             /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo bdb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    68,                                /* lineNo */
    37,                                /* colNo */
    "qshifts",                         /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo cdb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    68,                                /* lineNo */
    48,                                /* colNo */
    "dataPresent",                     /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo ddb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    68,                                /* lineNo */
    63,                                /* colNo */
    "allData",                         /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo edb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    68,                                /* lineNo */
    74,                                /* colNo */
    "dataLimits",                      /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo fdb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    68,                                /* lineNo */
    88,                                /* colNo */
    "simLimits",                       /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo gdb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    69,                                /* lineNo */
    5,                                 /* colNo */
    "shifted_data",                    /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo hdb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    72,                                /* lineNo */
    40,                                /* colNo */
    "nbas",                            /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo idb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    72,                                /* lineNo */
    48,                                /* colNo */
    "nbss",                            /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo jdb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    72,                                /* lineNo */
    56,                                /* colNo */
    "simLimits",                       /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo kdb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    72,                                /* lineNo */
    69,                                /* colNo */
    "repeatLayers",                    /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo ldb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    72,                                /* lineNo */
    118,                               /* colNo */
    "resols",                          /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo mdb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    76,                                /* lineNo */
    5,                                 /* colNo */
    "reflectivity",                    /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo ndb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    77,                                /* lineNo */
    5,                                 /* colNo */
    "Simulation",                      /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo odb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    82,                                /* lineNo */
    9,                                 /* colNo */
    "chis",                            /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo pdb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    80,                                /* lineNo */
    9,                                 /* colNo */
    "chis",                            /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo qdb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    50,                                /* lineNo */
    5,                                 /* colNo */
    "allLayers",                       /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo rdb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    44,                                /* lineNo */
    5,                                 /* colNo */
    "Simulation",                      /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo sdb_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    38,                                /* lineNo */
    5,                                 /* colNo */
    "reflectivity",                    /* aName */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtRTEInfo gs_emlrtRTEI = {
    22,                                /* lineNo */
    10,                                /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

static emlrtRTEInfo hs_emlrtRTEI = {
    25,                                /* lineNo */
    1,                                 /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

static emlrtRTEInfo is_emlrtRTEI = {
    29,                                /* lineNo */
    1,                                 /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

static emlrtRTEInfo js_emlrtRTEI = {
    3,                                 /* lineNo */
    18,                                /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

static emlrtRTEInfo ks_emlrtRTEI = {
    31,                                /* lineNo */
    36,                                /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

static emlrtRTEInfo ls_emlrtRTEI = {
    38,                                /* lineNo */
    5,                                 /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

static emlrtRTEInfo ms_emlrtRTEI = {
    44,                                /* lineNo */
    5,                                 /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

static emlrtRTEInfo ns_emlrtRTEI = {
    50,                                /* lineNo */
    5,                                 /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

static emlrtRTEInfo os_emlrtRTEI = {
    61,                                /* lineNo */
    5,                                 /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

static emlrtRTEInfo ps_emlrtRTEI = {
    65,                                /* lineNo */
    5,                                 /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

static emlrtRTEInfo qs_emlrtRTEI = {
    66,                                /* lineNo */
    5,                                 /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

static emlrtRTEInfo rs_emlrtRTEI = {
    68,                                /* lineNo */
    63,                                /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

static emlrtRTEInfo ss_emlrtRTEI = {
    69,                                /* lineNo */
    5,                                 /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

static emlrtRTEInfo ts_emlrtRTEI = {
    76,                                /* lineNo */
    5,                                 /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

static emlrtRTEInfo us_emlrtRTEI = {
    77,                                /* lineNo */
    5,                                 /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

static emlrtRTEInfo vs_emlrtRTEI = {
    64,                                /* lineNo */
    5,                                 /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

static emlrtRTEInfo ws_emlrtRTEI = {
    68,                                /* lineNo */
    5,                                 /* colNo */
    "standardTF_custXY_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custXY/standardTF_custXY_paraContrasts.m" /* pName */
};

/* Function Definitions */
void standardTF_custXY_paraContrasts(
    const emlrtStack *sp, const struct0_T *problemDef,
    const cell_16 *problemDef_cells, const struct2_T *controls,
    emxArray_real_T *outSsubs, emxArray_real_T *backgs,
    emxArray_real_T *qshifts, emxArray_real_T *sfs, emxArray_real_T *nbas,
    emxArray_real_T *nbss, emxArray_real_T *resols, emxArray_real_T *chis,
    emxArray_cell_wrap_12 *reflectivity, emxArray_cell_wrap_12 *Simulation,
    emxArray_cell_wrap_14 *shifted_data, emxArray_cell_wrap_10 *layerSlds,
    emxArray_cell_wrap_14 *sldProfiles, emxArray_cell_wrap_25 *allLayers,
    emxArray_real_T *allRoughs)
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
  real_T numberOfContrasts_tmp;
  int32_T b_allLayers;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T loop_ub_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
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
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &ae_emlrtDCI,
                                (emlrtCTX)sp);
  }
  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &yd_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &gs_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &xd_emlrtDCI,
                            (emlrtCTX)sp);
  }
  loop_ub_tmp = (int32_T)problemDef->numberOfContrasts;
  i1 = nbas->size[0];
  nbas->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, nbas, i1, &hs_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &be_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    nbas->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ce_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = outSsubs->size[0];
  outSsubs->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, outSsubs, i1, &is_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &ce_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    outSsubs->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &vd_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i = allLayers->size[0];
  allLayers->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_25(sp, allLayers, i, &js_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    b_allLayers = allLayers->size[0] - 1;
    if (i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, allLayers->size[0] - 1, &bcb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[i].f1->size[0] = 0;
    if (i > b_allLayers) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_allLayers, &bcb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = layerSlds->size[0];
  layerSlds->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &js_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    b_allLayers = layerSlds->size[0] - 1;
    if (i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, layerSlds->size[0] - 1, &ccb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    layerSlds->data[i].f1->size[0] = 0;
    if (i > b_allLayers) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_allLayers, &ccb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
    layerSlds->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[i].f1, i1, &js_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = sldProfiles->size[0];
  sldProfiles->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &js_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    b_allLayers = sldProfiles->size[0] - 1;
    if (i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, sldProfiles->size[0] - 1,
                                    &dcb_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[i].f1->size[0] = 0;
    if (i > b_allLayers) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_allLayers, &dcb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sldProfiles->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = shifted_data->size[0];
  shifted_data->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &js_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    b_allLayers = shifted_data->size[0] - 1;
    if (i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, shifted_data->size[0] - 1,
                                    &ecb_emlrtBCI, (emlrtCTX)sp);
    }
    shifted_data->data[i].f1->size[0] = 0;
    if (i > b_allLayers) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_allLayers, &ecb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    shifted_data->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = reflectivity->size[0];
  reflectivity->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_12(sp, reflectivity, i, &js_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    b_allLayers = reflectivity->size[0] - 1;
    if (i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, reflectivity->size[0] - 1,
                                    &fcb_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[i].f1->size[0] = 0;
    if (i > b_allLayers) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_allLayers, &fcb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = reflectivity->data[i].f1->size[0] * reflectivity->data[i].f1->size[1];
    reflectivity->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[i].f1, i1, &js_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &qd_emlrtRTEI, (emlrtCTX)sp);
  i = reflectivity->size[0];
  reflectivity->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_12(sp, reflectivity, i, &ks_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &rbb_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity->data[b_i].f1->size[0] *
        reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &ls_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &rbb_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity->data[b_i].f1->size[0] *
        reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &ls_emlrtRTEI);
    i = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &rbb_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &sdb_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &sdb_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &sdb_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = Simulation->size[0];
  Simulation->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_12(sp, Simulation, i, &js_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    b_allLayers = Simulation->size[0] - 1;
    if (i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, Simulation->size[0] - 1,
                                    &gcb_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[i].f1->size[0] = 0;
    if (i > b_allLayers) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_allLayers, &gcb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = Simulation->data[i].f1->size[0] * Simulation->data[i].f1->size[1];
    Simulation->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[i].f1, i1, &js_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &rd_emlrtRTEI, (emlrtCTX)sp);
  i = Simulation->size[0];
  Simulation->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_12(sp, Simulation, i, &ks_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &sbb_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &ms_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &sbb_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &ms_emlrtRTEI);
    i = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &sbb_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &rdb_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &rdb_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &rdb_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = allLayers->size[0];
  allLayers->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_25(sp, allLayers, i, &js_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    b_allLayers = allLayers->size[0] - 1;
    if (i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, allLayers->size[0] - 1, &bcb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[i].f1->size[0] = 0;
    if (i > b_allLayers) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_allLayers, &bcb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &sd_emlrtRTEI, (emlrtCTX)sp);
  i = allLayers->size[0];
  allLayers->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_25(sp, allLayers, i, &ks_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &tbb_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &ns_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &tbb_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &ns_emlrtRTEI);
    i = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &tbb_emlrtBCI, (emlrtCTX)sp);
    }
    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &qdb_emlrtBCI, (emlrtCTX)sp);
    }
    allLayers->data[b_i].f1->data[1] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &td_emlrtRTEI, (emlrtCTX)sp);
  i = qshifts->size[0];
  qshifts->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, qshifts, i, &gs_emlrtRTEI);
  i = sfs->size[0];
  sfs->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, sfs, i, &gs_emlrtRTEI);
  i = nbss->size[0];
  nbss->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, nbss, i, &gs_emlrtRTEI);
  i = resols->size[0];
  resols->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, resols, i, &gs_emlrtRTEI);
  i = allRoughs->size[0];
  allRoughs->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, allRoughs, i, &gs_emlrtRTEI);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &ks_emlrtRTEI);
  i = layerSlds->size[0];
  layerSlds->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &ks_emlrtRTEI);
  i = allLayers->size[0];
  allLayers->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_25(sp, allLayers, i, &ks_emlrtRTEI);
  i = shifted_data->size[0];
  shifted_data->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &ks_emlrtRTEI);
  i = chis->size[0];
  chis->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, chis, i, &gs_emlrtRTEI);
  i = Simulation->size[0];
  Simulation->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_12(sp, Simulation, i, &ks_emlrtRTEI);
  i = reflectivity->size[0];
  reflectivity->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_12(sp, reflectivity, i, &ks_emlrtRTEI);
  emxInit_real_T(sp, &layerSld, 2, &vs_emlrtRTEI, true);
  emxInit_real_T(sp, &shifted_dat, 2, &ws_emlrtRTEI, true);
  emxInit_real_T(sp, &sldProfile, 2, &js_emlrtRTEI, true);
  emxInit_real_T(sp, &reflect, 2, &js_emlrtRTEI, true);
  emxInit_real_T(sp, &Simul, 2, &js_emlrtRTEI, true);
  emxInit_real_T(sp, &b_shifted_dat, 1, &nh_emlrtRTEI, true);
  emxInit_real_T(sp, &b_problemDef_cells, 2, &rs_emlrtRTEI, true);
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    if ((int32_T)(b_i + 1U) > problemDef->contrastBacks->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastBacks->size[1],
                                    &hcb_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastShifts->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastShifts->size[1],
                                    &icb_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastScales->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastScales->size[1],
                                    &jcb_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastNbas->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastNbas->size[1],
                                    &kcb_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastNbss->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastNbss->size[1],
                                    &lcb_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastRes->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastRes->size[1],
                                    &mcb_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > backgs->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, backgs->size[0],
                                    &ncb_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > qshifts->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, qshifts->size[0],
                                    &ocb_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > sfs->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, sfs->size[0],
                                    &pcb_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, nbas->size[0],
                                    &qcb_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, nbss->size[0],
                                    &rcb_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > resols->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, resols->size[0],
                                    &scb_emlrtBCI, (emlrtCTX)sp);
    }
    st.site = &ej_emlrtRSI;
    backSort(&st, problemDef->contrastBacks->data[b_i],
             problemDef->contrastShifts->data[b_i],
             problemDef->contrastScales->data[b_i],
             problemDef->contrastNbas->data[b_i],
             problemDef->contrastNbss->data[b_i],
             problemDef->contrastRes->data[b_i], problemDef->backs,
             problemDef->shifts, problemDef->sf, problemDef->nba,
             problemDef->nbs, problemDef->res, &backgs->data[b_i],
             &qshifts->data[b_i], &sfs->data[b_i], &nbas->data[b_i],
             &nbss->data[b_i], &resols->data[b_i]);
    if ((int32_T)(b_i + 1U) > problemDef->contrastCustomFiles->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastCustomFiles->size[1],
                                    &tcb_emlrtBCI, (emlrtCTX)sp);
    }
    d = problemDef->contrastCustomFiles->data[b_i];
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &wd_emlrtDCI, (emlrtCTX)sp);
    }
    if (((int32_T)d - 1 < 0) ||
        ((int32_T)d - 1 > problemDef_cells->f14->size[1] - 1)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d - 1, 0,
                                    problemDef_cells->f14->size[1] - 1,
                                    &qbb_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, nbss->size[0],
                                    &ucb_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, allRoughs->size[0],
                                    &vcb_emlrtBCI, (emlrtCTX)sp);
    }
    st.site = &fj_emlrtRSI;
    b_call_customLayers(
        &st, problemDef->params, (real_T)b_i + 1.0,
        problemDef_cells->f14
            ->data[(int32_T)problemDef->contrastCustomFiles->data[b_i] - 1]
            .f1,
        nbas, nbss->data[b_i], numberOfContrasts_tmp, sldProfile,
        &allRoughs->data[b_i]);
    b_allLayers = sldProfile->size[0] * sldProfile->size[1];
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &ubb_emlrtBCI, (emlrtCTX)sp);
    }
    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &os_emlrtRTEI);
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &ubb_emlrtBCI, (emlrtCTX)sp);
    }
    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = sldProfile->size[1];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &os_emlrtRTEI);
    i = sldProfiles->size[0];
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &ubb_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &ubb_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_allLayers; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &wcb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      sldProfiles->data[b_i].f1->data[i1] = sldProfile->data[i1];
    }
    st.site = &gj_emlrtRSI;
    b_resampleLayers(&st, sldProfile, controls->resamPars, layerSld);
    b_allLayers = layerSld->size[0] * 3;
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                    &vbb_emlrtBCI, (emlrtCTX)sp);
    }
    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &ps_emlrtRTEI);
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                    &vbb_emlrtBCI, (emlrtCTX)sp);
    }
    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &ps_emlrtRTEI);
    i = layerSlds->size[0];
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                    &vbb_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                    &vbb_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_allLayers; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &xcb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      layerSlds->data[b_i].f1->data[i1] = layerSld->data[i1];
    }
    if (10000 < layerSld->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, layerSld->size[0], &fb_emlrtECI,
                                 (emlrtCTX)sp);
    }
    b_allLayers = layerSld->size[0] * 3;
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &wbb_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = layerSld->size[0];
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &qs_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &wbb_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &qs_emlrtRTEI);
    i = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &wbb_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &wbb_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_allLayers; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &ycb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      allLayers->data[b_i].f1->data[i1] = layerSld->data[i1];
    }
    if (b_i + 1 > sfs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, sfs->size[0], &adb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (b_i + 1 > qshifts->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, qshifts->size[0], &bdb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (b_i + 1 > problemDef->dataPresent->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                                    problemDef->dataPresent->size[1],
                                    &cdb_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f2->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f2->size[1] - 1,
                                    &ddb_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f3->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f3->size[1] - 1,
                                    &edb_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f4->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f4->size[1] - 1,
                                    &fdb_emlrtBCI, (emlrtCTX)sp);
    }
    i = b_problemDef_cells->size[0] * b_problemDef_cells->size[1];
    b_problemDef_cells->size[0] = problemDef_cells->f2->data[b_i].f1->size[0];
    b_problemDef_cells->size[1] = problemDef_cells->f2->data[b_i].f1->size[1];
    emxEnsureCapacity_real_T(sp, b_problemDef_cells, i, &rs_emlrtRTEI);
    b_allLayers = problemDef_cells->f2->data[b_i].f1->size[0] *
                      problemDef_cells->f2->data[b_i].f1->size[1] -
                  1;
    for (i = 0; i <= b_allLayers; i++) {
      b_problemDef_cells->data[i] = problemDef_cells->f2->data[b_i].f1->data[i];
    }
    st.site = &hj_emlrtRSI;
    shiftdata(&st, sfs->data[b_i], qshifts->data[b_i],
              problemDef->dataPresent->data[b_i], b_problemDef_cells,
              problemDef_cells->f3->data[b_i].f1,
              (real_T *)problemDef_cells->f4->data[b_i].f1->data,
              *(int32_T(*)[2])problemDef_cells->f4->data[b_i].f1->size,
              shifted_dat);
    b_allLayers = shifted_dat->size[0] * shifted_dat->size[1];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &xbb_emlrtBCI, (emlrtCTX)sp);
    }
    i = shifted_data->data[b_i].f1->size[0] *
        shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &ss_emlrtRTEI);
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &xbb_emlrtBCI, (emlrtCTX)sp);
    }
    i = shifted_data->data[b_i].f1->size[0] *
        shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[1] = shifted_dat->size[1];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &ss_emlrtRTEI);
    i = shifted_data->size[0];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &xbb_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &xbb_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_allLayers; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &gdb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      shifted_data->data[b_i].f1->data[i1] = shifted_dat->data[i1];
    }
    if (b_i + 1 > loop_ub_tmp) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, (int32_T)numberOfContrasts_tmp,
                                    &mbb_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i + 1 > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbas->size[0], &hdb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (b_i + 1 > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbss->size[0], &idb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f4->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f4->size[1] - 1,
                                    &jdb_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f1->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f1->size[1] - 1,
                                    &kdb_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i + 1 > resols->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, resols->size[0], &ldb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    st.site = &ij_emlrtRSI;
    callReflectivity(&st, nbas->data[b_i], nbss->data[b_i],
                     (real_T *)problemDef_cells->f4->data[b_i].f1->data,
                     *(int32_T(*)[2])problemDef_cells->f4->data[b_i].f1->size,
                     problemDef_cells->f1->data[b_i].f1, shifted_dat, layerSld,
                     0.0, resols->data[b_i], reflect, Simul);
    st.site = &jj_emlrtRSI;
    if (b_i + 1 > backgs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, backgs->size[0], &nbb_emlrtBCI,
                                    &st);
    }
    if (b_i + 1 > problemDef->contrastBacksType->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                                    problemDef->contrastBacksType->size[1],
                                    &obb_emlrtBCI, &st);
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
      b_allLayers = reflect->size[0] * 2;
      i = reflect->size[0] * reflect->size[1];
      reflect->size[1] = 2;
      emxEnsureCapacity_real_T(&st, reflect, i, &mh_emlrtRTEI);
      for (i = 0; i < b_allLayers; i++) {
        reflect->data[i] += backgs->data[b_i];
      }
      b_allLayers = Simul->size[0] * 2;
      i = Simul->size[0] * Simul->size[1];
      Simul->size[1] = 2;
      emxEnsureCapacity_real_T(&st, Simul, i, &oh_emlrtRTEI);
      for (i = 0; i < b_allLayers; i++) {
        Simul->data[i] += backgs->data[b_i];
      }
      break;
    case 2:
      /*          %Subtract the background from the data.. */
      if (2 > shifted_dat->size[1]) {
        emlrtDynamicBoundsCheckR2012b(2, 1, shifted_dat->size[1], &wf_emlrtBCI,
                                      &st);
      }
      emlrtSubAssignSizeCheckR2012b(&shifted_dat->size[0], 1,
                                    &shifted_dat->size[0], 1, &emlrtECI, &st);
      b_allLayers = shifted_dat->size[0] - 1;
      i = b_shifted_dat->size[0];
      b_shifted_dat->size[0] = shifted_dat->size[0];
      emxEnsureCapacity_real_T(&st, b_shifted_dat, i, &nh_emlrtRTEI);
      for (i = 0; i <= b_allLayers; i++) {
        b_shifted_dat->data[i] =
            shifted_dat->data[i + shifted_dat->size[0]] - backgs->data[b_i];
      }
      b_allLayers = b_shifted_dat->size[0];
      for (i = 0; i < b_allLayers; i++) {
        shifted_dat->data[i + shifted_dat->size[0]] = b_shifted_dat->data[i];
      }
      /* shifted_dat(:,3) = shifted_dat(:,3) - backg;    */
      break;
    }
    if (10000 < reflect->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, reflect->size[0], &gb_emlrtECI,
                                 (emlrtCTX)sp);
    }
    b_allLayers = reflect->size[0] * 2;
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &ybb_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity->data[b_i].f1->size[0] *
        reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = reflect->size[0];
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &ts_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &ybb_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity->data[b_i].f1->size[0] *
        reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &ts_emlrtRTEI);
    i = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &ybb_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &ybb_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_allLayers; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &mdb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      reflectivity->data[b_i].f1->data[i1] = reflect->data[i1];
    }
    if (10000 < Simul->size[0]) {
      emlrtDimSizeGeqCheckR2012b(10000, Simul->size[0], &hb_emlrtECI,
                                 (emlrtCTX)sp);
    }
    b_allLayers = Simul->size[0] * 2;
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &acb_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = Simul->size[0];
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &us_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &acb_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &us_emlrtRTEI);
    i = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &acb_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &acb_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_allLayers; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &ndb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      Simulation->data[b_i].f1->data[i1] = Simul->data[i1];
    }
    if (b_i + 1 > problemDef->dataPresent->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                                    problemDef->dataPresent->size[1],
                                    &pbb_emlrtBCI, (emlrtCTX)sp);
    }
    st.site = &kj_emlrtRSI;
    if (muDoubleScalarIsNaN(problemDef->dataPresent->data[b_i])) {
      emlrtErrorWithMessageIdR2018a(&st, &ld_emlrtRTEI, "MATLAB:nologicalnan",
                                    "MATLAB:nologicalnan", 0);
    }
    if (problemDef->dataPresent->data[b_i] != 0.0) {
      if (b_i + 1 > chis->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, chis->size[0], &pdb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      st.site = &lj_emlrtRSI;
      chis->data[b_i] =
          chiSquared(&st, shifted_dat, reflect, problemDef->params->size[1]);
    } else {
      if (b_i + 1 > chis->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, chis->size[0], &odb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      chis->data[b_i] = 0.0;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_real_T(&b_problemDef_cells);
  emxFree_real_T(&b_shifted_dat);
  emxFree_real_T(&Simul);
  emxFree_real_T(&reflect);
  emxFree_real_T(&sldProfile);
  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&layerSld);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (standardTF_custXY_paraContrasts.c) */
