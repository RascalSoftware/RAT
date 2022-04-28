/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
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
static emlrtRSInfo o_emlrtRSI = {
    65,                          /* lineNo */
    "standardTF_stanlay_single", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    77,                          /* lineNo */
    "standardTF_stanlay_single", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m" /* pathName */
};

static emlrtRSInfo q_emlrtRSI = {
    82,                          /* lineNo */
    "standardTF_stanlay_single", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m" /* pathName */
};

static emlrtRSInfo r_emlrtRSI = {
    102,                         /* lineNo */
    "standardTF_stanlay_single", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m" /* pathName */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    46,                          /* lineNo */
    9,                           /* colNo */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m" /* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    51,                          /* lineNo */
    9,                           /* colNo */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m" /* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    56,                          /* lineNo */
    9,                           /* colNo */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m" /* pName */
};

static emlrtRTEInfo db_emlrtRTEI = {
    71,                          /* lineNo */
    9,                           /* colNo */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m" /* pName */
};

static emlrtBCInfo dd_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    86,                          /* lineNo */
    24,                          /* colNo */
    "params",                    /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    88,                          /* lineNo */
    29,                          /* colNo */
    "resample",                  /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    91,                          /* lineNo */
    35,                          /* colNo */
    "dataPresent",               /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    94,                          /* lineNo */
    31,                          /* colNo */
    "backsType",                 /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo hd_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    87,                          /* lineNo */
    37,                          /* colNo */
    "repeatLayers",              /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    90,                          /* lineNo */
    24,                          /* colNo */
    "allData",                   /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo jd_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    92,                          /* lineNo */
    33,                          /* colNo */
    "dataLimits",                /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo kd_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    93,                          /* lineNo */
    31,                          /* colNo */
    "simLimits",                 /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    47,                          /* lineNo */
    18,                          /* colNo */
    "reflectivity",              /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo md_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    52,                          /* lineNo */
    16,                          /* colNo */
    "Simulation",                /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    57,                          /* lineNo */
    15,                          /* colNo */
    "allLayers",                 /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo od_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    113,                         /* lineNo */
    17,                          /* colNo */
    "sldProfiles",               /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    116,                         /* lineNo */
    18,                          /* colNo */
    "shifted_data",              /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    126,                         /* lineNo */
    15,                          /* colNo */
    "allLayers",                 /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = {
    33,                          /* lineNo */
    17,                          /* colNo */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    1                                                 /* checkKind */
};

static emlrtDCInfo s_emlrtDCI = {
    32,                          /* lineNo */
    16,                          /* colNo */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    1                                                 /* checkKind */
};

static emlrtDCInfo t_emlrtDCI = {
    32,                          /* lineNo */
    16,                          /* colNo */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    4                                                 /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    41,                          /* lineNo */
    36,                          /* colNo */
    "layerSlds",                 /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    41,                          /* lineNo */
    36,                          /* colNo */
    "sldProfiles",               /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    41,                          /* lineNo */
    36,                          /* colNo */
    "shifted_data",              /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    41,                          /* lineNo */
    36,                          /* colNo */
    "reflectivity",              /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    41,                          /* lineNo */
    36,                          /* colNo */
    "Simulation",                /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    41,                          /* lineNo */
    36,                          /* colNo */
    "allLayers",                 /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    57,                          /* lineNo */
    5,                           /* colNo */
    "allLayers",                 /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo yd_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    77,                          /* lineNo */
    84,                          /* colNo */
    "cBacks",                    /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    77,                          /* lineNo */
    95,                          /* colNo */
    "cShifts",                   /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo be_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    77,                          /* lineNo */
    106,                         /* colNo */
    "cScales",                   /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo ce_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    77,                          /* lineNo */
    115,                         /* colNo */
    "cNbas",                     /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo de_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    77,                          /* lineNo */
    124,                         /* colNo */
    "cNbss",                     /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo ee_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    77,                          /* lineNo */
    132,                         /* colNo */
    "cRes",                      /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo fe_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    82,                          /* lineNo */
    67,                          /* colNo */
    "contrastLayers",            /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo ge_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    114,                         /* lineNo */
    18,                          /* colNo */
    "reflectivity",              /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo he_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    115,                         /* lineNo */
    16,                          /* colNo */
    "Simulation",                /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo ie_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    117,                         /* lineNo */
    15,                          /* colNo */
    "layerSlds",                 /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo je_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    118,                         /* lineNo */
    10,                          /* colNo */
    "chis",                      /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo ke_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    112,                         /* lineNo */
    14,                          /* colNo */
    "outSsubs",                  /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo le_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    113,                         /* lineNo */
    5,                           /* colNo */
    "sldProfiles",               /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo me_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    116,                         /* lineNo */
    5,                           /* colNo */
    "shifted_data",              /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo ne_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    119,                         /* lineNo */
    12,                          /* colNo */
    "backgs",                    /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo oe_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    120,                         /* lineNo */
    13,                          /* colNo */
    "qshifts",                   /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo pe_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    121,                         /* lineNo */
    9,                           /* colNo */
    "sfs",                       /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo qe_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    122,                         /* lineNo */
    10,                          /* colNo */
    "nbas",                      /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo re_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    123,                         /* lineNo */
    10,                          /* colNo */
    "nbss",                      /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo se_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    124,                         /* lineNo */
    12,                          /* colNo */
    "resols",                    /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo te_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    125,                         /* lineNo */
    15,                          /* colNo */
    "allRoughs",                 /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo ue_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    126,                         /* lineNo */
    5,                           /* colNo */
    "allLayers",                 /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo ve_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    52,                          /* lineNo */
    5,                           /* colNo */
    "Simulation",                /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo we_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    47,                          /* lineNo */
    5,                           /* colNo */
    "reflectivity",              /* aName */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtRTEInfo sg_emlrtRTEI = {
    32,                          /* lineNo */
    10,                          /* colNo */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m" /* pName */
};

static emlrtRTEInfo tg_emlrtRTEI = {
    4,                           /* lineNo */
    18,                          /* colNo */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m" /* pName */
};

static emlrtRTEInfo ug_emlrtRTEI = {
    41,                          /* lineNo */
    36,                          /* colNo */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m" /* pName */
};

static emlrtRTEInfo vg_emlrtRTEI = {
    47,                          /* lineNo */
    5,                           /* colNo */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m" /* pName */
};

static emlrtRTEInfo wg_emlrtRTEI = {
    52,                          /* lineNo */
    5,                           /* colNo */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m" /* pName */
};

static emlrtRTEInfo xg_emlrtRTEI = {
    57,                          /* lineNo */
    5,                           /* colNo */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m" /* pName */
};

static emlrtRTEInfo yg_emlrtRTEI = {
    39,                          /* lineNo */
    12,                          /* colNo */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m" /* pName */
};

static emlrtRTEInfo ah_emlrtRTEI = {
    113,                         /* lineNo */
    5,                           /* colNo */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m" /* pName */
};

static emlrtRTEInfo bh_emlrtRTEI = {
    116,                         /* lineNo */
    5,                           /* colNo */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m" /* pName */
};

static emlrtRTEInfo ch_emlrtRTEI = {
    126,                         /* lineNo */
    5,                           /* colNo */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m" /* pName */
};

static emlrtRTEInfo dh_emlrtRTEI = {
    65,                          /* lineNo */
    1,                           /* colNo */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m" /* pName */
};

static emlrtRTEInfo eh_emlrtRTEI = {
    82,                          /* lineNo */
    5,                           /* colNo */
    "standardTF_stanlay_single", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_single.m" /* pName */
};

/* Function Definitions */
void standardTF_stanlay_single(
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
  real_T *allRoughs_data;
  real_T *backgs_data;
  real_T *chis_data;
  real_T *nbas_data;
  real_T *nbss_data;
  real_T *outSsubs_data;
  real_T *qshifts_data;
  real_T *resampledLayers_data;
  real_T *resols_data;
  real_T *sfs_data;
  real_T *shifted_dat_data;
  real_T *sldProfile_data;
  int32_T b_i;
  int32_T b_layerSlds;
  int32_T i;
  int32_T i1;
  int32_T unnamed_idx_0_tmp_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
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
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &t_emlrtDCI,
                                (emlrtCTX)sp);
  }
  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &s_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &sg_emlrtRTEI);
  backgs_data = backgs->data;
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &r_emlrtDCI,
                            (emlrtCTX)sp);
  }
  unnamed_idx_0_tmp_tmp = (int32_T)problemDef->numberOfContrasts;
  i = layerSlds->size[0];
  layerSlds->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &tg_emlrtRTEI);
  layerSlds_data = layerSlds->data;
  for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
    b_layerSlds = layerSlds->size[0] - 1;
    if (i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, layerSlds->size[0] - 1, &rd_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    layerSlds_data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &rd_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = layerSlds_data[i].f1->size[0] * layerSlds_data[i].f1->size[1];
    layerSlds_data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds_data[i].f1, i1, &tg_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = sldProfiles->size[0];
  sldProfiles->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &tg_emlrtRTEI);
  sldProfiles_data = sldProfiles->data;
  for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
    b_layerSlds = sldProfiles->size[0] - 1;
    if (i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, sldProfiles->size[0] - 1,
                                    &sd_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles_data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &sd_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sldProfiles_data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = shifted_data->size[0];
  shifted_data->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &tg_emlrtRTEI);
  shifted_data_data = shifted_data->data;
  for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
    b_layerSlds = shifted_data->size[0] - 1;
    if (i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, shifted_data->size[0] - 1,
                                    &td_emlrtBCI, (emlrtCTX)sp);
    }
    shifted_data_data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &td_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    shifted_data_data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = reflectivity->size[0];
  reflectivity->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &tg_emlrtRTEI);
  reflectivity_data = reflectivity->data;
  for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
    b_layerSlds = reflectivity->size[0] - 1;
    if (i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, reflectivity->size[0] - 1,
                                    &ud_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity_data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &ud_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = reflectivity_data[i].f1->size[0] * reflectivity_data[i].f1->size[1];
    reflectivity_data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity_data[i].f1, i1, &tg_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &ab_emlrtRTEI, (emlrtCTX)sp);
  i = reflectivity->size[0];
  reflectivity->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &ug_emlrtRTEI);
  reflectivity_data = reflectivity->data;
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &ld_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity_data[b_i].f1->size[0] * reflectivity_data[b_i].f1->size[1];
    reflectivity_data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity_data[b_i].f1, i, &vg_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &ld_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity_data[b_i].f1->size[0] * reflectivity_data[b_i].f1->size[1];
    reflectivity_data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity_data[b_i].f1, i, &vg_emlrtRTEI);
    i = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &ld_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity_data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &we_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity_data[b_i].f1->data[1] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &we_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity_data[b_i].f1->data[2] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &we_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity_data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = Simulation->size[0];
  Simulation->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &tg_emlrtRTEI);
  Simulation_data = Simulation->data;
  for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
    b_layerSlds = Simulation->size[0] - 1;
    if (i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, Simulation->size[0] - 1, &vd_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation_data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &vd_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = Simulation_data[i].f1->size[0] * Simulation_data[i].f1->size[1];
    Simulation_data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation_data[i].f1, i1, &tg_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &bb_emlrtRTEI, (emlrtCTX)sp);
  i = Simulation->size[0];
  Simulation->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &ug_emlrtRTEI);
  Simulation_data = Simulation->data;
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &md_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation_data[b_i].f1->size[0] * Simulation_data[b_i].f1->size[1];
    Simulation_data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation_data[b_i].f1, i, &wg_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &md_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation_data[b_i].f1->size[0] * Simulation_data[b_i].f1->size[1];
    Simulation_data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation_data[b_i].f1, i, &wg_emlrtRTEI);
    i = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &md_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation_data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &ve_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation_data[b_i].f1->data[1] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &ve_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation_data[b_i].f1->data[2] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &ve_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation_data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = allLayers->size[0];
  allLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &tg_emlrtRTEI);
  allLayers_data = allLayers->data;
  for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
    b_layerSlds = allLayers->size[0] - 1;
    if (i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, allLayers->size[0] - 1, &wd_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers_data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &wd_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers_data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &cb_emlrtRTEI, (emlrtCTX)sp);
  i = allLayers->size[0];
  allLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &ug_emlrtRTEI);
  allLayers_data = allLayers->data;
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &nd_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers_data[b_i].f1->size[0] * allLayers_data[b_i].f1->size[1];
    allLayers_data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers_data[b_i].f1, i, &xg_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &nd_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers_data[b_i].f1->size[0] * allLayers_data[b_i].f1->size[1];
    allLayers_data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers_data[b_i].f1, i, &xg_emlrtRTEI);
    i = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &nd_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 6; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &xd_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      allLayers_data[b_i].f1->data[i1] = 1.0;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxInit_cell_wrap_17(sp, &outParameterisedLayers, &dh_emlrtRTEI);
  /*  end memory allocation. */
  /*  First we need to allocate the absolute values of the input */
  /*  parameters to all the layers in the layers list. This only needs */
  /*  to be done once, and so is done outside the contrasts loop */
  st.site = &o_emlrtRSI;
  allocateParamsToLayers(&st, problemDef->params, problemDef_cells->f6,
                         outParameterisedLayers);
  /*  Resample params if requiired */
  /*  Loop over all the contrasts */
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &db_emlrtRTEI, (emlrtCTX)sp);
  i = outSsubs->size[0];
  outSsubs->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, outSsubs, i, &yg_emlrtRTEI);
  outSsubs_data = outSsubs->data;
  i = sldProfiles->size[0];
  sldProfiles->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &ug_emlrtRTEI);
  sldProfiles_data = sldProfiles->data;
  i = reflectivity->size[0];
  reflectivity->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &ug_emlrtRTEI);
  reflectivity_data = reflectivity->data;
  i = Simulation->size[0];
  Simulation->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &ug_emlrtRTEI);
  Simulation_data = Simulation->data;
  i = shifted_data->size[0];
  shifted_data->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &ug_emlrtRTEI);
  shifted_data_data = shifted_data->data;
  i = layerSlds->size[0];
  layerSlds->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &ug_emlrtRTEI);
  layerSlds_data = layerSlds->data;
  i = chis->size[0];
  chis->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, chis, i, &yg_emlrtRTEI);
  chis_data = chis->data;
  i = qshifts->size[0];
  qshifts->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, qshifts, i, &yg_emlrtRTEI);
  qshifts_data = qshifts->data;
  i = sfs->size[0];
  sfs->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, sfs, i, &yg_emlrtRTEI);
  sfs_data = sfs->data;
  i = nbas->size[0];
  nbas->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, nbas, i, &yg_emlrtRTEI);
  nbas_data = nbas->data;
  i = nbss->size[0];
  nbss->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, nbss, i, &yg_emlrtRTEI);
  nbss_data = nbss->data;
  i = resols->size[0];
  resols->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, resols, i, &yg_emlrtRTEI);
  resols_data = resols->data;
  i = allRoughs->size[0];
  allRoughs->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, allRoughs, i, &yg_emlrtRTEI);
  allRoughs_data = allRoughs->data;
  i = allLayers->size[0];
  allLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &ug_emlrtRTEI);
  allLayers_data = allLayers->data;
  emxInit_real_T(sp, &thisContrastLayers, 2, &eh_emlrtRTEI, true);
  emxInit_real_T(sp, &sldProfile, 2, &tg_emlrtRTEI, true);
  emxInit_real_T(sp, &shifted_dat, 2, &tg_emlrtRTEI, true);
  emxInit_real_T(sp, &resampledLayers, 2, &tg_emlrtRTEI, true);
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    /*  Extract the relevant parameter values for this contrast */
    /*  from the input arrays. */
    /*  First need to decide which values of the backrounds, scalefactors */
    /*  data shifts and bulk contrasts are associated with this contrast */
    if ((int32_T)(b_i + 1U) > problemDef->contrastBacks->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastBacks->size[1],
                                    &yd_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastShifts->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastShifts->size[1],
                                    &ae_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastScales->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastScales->size[1],
                                    &be_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastNbas->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastNbas->size[1],
                                    &ce_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastNbss->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastNbss->size[1],
                                    &de_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastRes->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastRes->size[1],
                                    &ee_emlrtBCI, (emlrtCTX)sp);
    }
    st.site = &p_emlrtRSI;
    backSort(&st, problemDef->contrastBacks->data[b_i],
             problemDef->contrastShifts->data[b_i],
             problemDef->contrastScales->data[b_i],
             problemDef->contrastNbas->data[b_i],
             problemDef->contrastNbss->data[b_i],
             problemDef->contrastRes->data[b_i], problemDef->backs,
             problemDef->shifts, problemDef->sf, problemDef->nba,
             problemDef->nbs, problemDef->res, &thisBackground, &thisQshift,
             &thisSf, &thisNba, &thisNbs, &thisResol);
    /*  Also need to determine which layers from the overall layers list */
    /*  are required for this contrast, and put them in the correct order  */
    /*  according to geometry */
    if (b_i > problemDef_cells->f5->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f5->size[1] - 1,
                                    &fe_emlrtBCI, (emlrtCTX)sp);
    }
    st.site = &q_emlrtRSI;
    allocateLayersForContrast(&st, problemDef_cells->f5->data[b_i].f1,
                              outParameterisedLayers, thisContrastLayers);
    /*  For the other parameters, we extract the correct ones from the input */
    /*  arrays */
    if (1 > problemDef->params->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, problemDef->params->size[1],
                                    &dd_emlrtBCI, (emlrtCTX)sp);
    }
    /*  Substrate roughness is always first parameter for standard layers */
    if (b_i > problemDef_cells->f1->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f1->size[1] - 1,
                                    &hd_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i + 1 > problemDef->resample->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, problemDef->resample->size[1],
                                    &ed_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f2->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f2->size[1] - 1,
                                    &id_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i + 1 > problemDef->dataPresent->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                                    problemDef->dataPresent->size[1],
                                    &fd_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f3->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f3->size[1] - 1,
                                    &jd_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f4->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f4->size[1] - 1,
                                    &kd_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i + 1 > problemDef->contrastBacksType->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                                    problemDef->contrastBacksType->size[1],
                                    &gd_emlrtBCI, (emlrtCTX)sp);
    }
    /*  Now call the core standardTF_stanlay reflectivity calculation */
    /*  In this case we are single cored, so we do not parallelise over */
    /*  points */
    /*  Call the core layers calculation */
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &ge_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &he_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                    &ie_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i + 1 > chis->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, chis->size[0], &je_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (b_i + 1 > outSsubs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, outSsubs->size[0], &ke_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    st.site = &r_emlrtRSI;
    standardTF_layers_core(
        &st, thisContrastLayers, problemDef->params->data[0],
        problemDef->geometry, thisNba, thisNbs, problemDef->resample->data[b_i],
        controls->calcSld, thisSf, thisQshift,
        problemDef->dataPresent->data[b_i], problemDef_cells->f2->data[b_i].f1,
        problemDef_cells->f3->data[b_i].f1,
        (real_T *)problemDef_cells->f4->data[b_i].f1->data,
        *(int32_T(*)[2])problemDef_cells->f4->data[b_i].f1->size,
        problemDef_cells->f1->data[b_i].f1, thisBackground, thisResol,
        problemDef->contrastBacksType->data[b_i], problemDef->params->size[1],
        controls->resamPars, sldProfile, reflectivity_data[b_i].f1,
        Simulation_data[b_i].f1, shifted_dat, layerSlds_data[b_i].f1,
        resampledLayers, &chis_data[b_i], &outSsubs_data[b_i]);
    resampledLayers_data = resampledLayers->data;
    shifted_dat_data = shifted_dat->data;
    sldProfile_data = sldProfile->data;
    /*  Store returned values for this contrast in the output arrays. */
    /*  As well as the calculated profiles, we also store a record of  */
    /*  the other values (background, scalefactors etc) for each contrast */
    /*  for future use. */
    b_layerSlds = sldProfile->size[0] * 2;
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &od_emlrtBCI, (emlrtCTX)sp);
    }
    i = sldProfiles_data[b_i].f1->size[0] * sldProfiles_data[b_i].f1->size[1];
    sldProfiles_data[b_i].f1->size[0] = sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, sldProfiles_data[b_i].f1, i, &ah_emlrtRTEI);
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &od_emlrtBCI, (emlrtCTX)sp);
    }
    i = sldProfiles_data[b_i].f1->size[0] * sldProfiles_data[b_i].f1->size[1];
    sldProfiles_data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles_data[b_i].f1, i, &ah_emlrtRTEI);
    i = sldProfiles->size[0];
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &od_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &od_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &le_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      sldProfiles_data[b_i].f1->data[i1] = sldProfile_data[i1];
    }
    b_layerSlds = shifted_dat->size[0] * shifted_dat->size[1];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &pd_emlrtBCI, (emlrtCTX)sp);
    }
    i = shifted_data_data[b_i].f1->size[0] * shifted_data_data[b_i].f1->size[1];
    shifted_data_data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, shifted_data_data[b_i].f1, i, &bh_emlrtRTEI);
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &pd_emlrtBCI, (emlrtCTX)sp);
    }
    i = shifted_data_data[b_i].f1->size[0] * shifted_data_data[b_i].f1->size[1];
    shifted_data_data[b_i].f1->size[1] = shifted_dat->size[1];
    emxEnsureCapacity_real_T(sp, shifted_data_data[b_i].f1, i, &bh_emlrtRTEI);
    i = shifted_data->size[0];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &pd_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &pd_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &me_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      shifted_data_data[b_i].f1->data[i1] = shifted_dat_data[i1];
    }
    if (b_i + 1 > backgs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, backgs->size[0], &ne_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    backgs_data[b_i] = thisBackground;
    if (b_i + 1 > qshifts->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, qshifts->size[0], &oe_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    qshifts_data[b_i] = thisQshift;
    if (b_i + 1 > sfs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, sfs->size[0], &pe_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sfs_data[b_i] = thisSf;
    if (b_i + 1 > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbas->size[0], &qe_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    nbas_data[b_i] = thisNba;
    if (b_i + 1 > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbss->size[0], &re_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    nbss_data[b_i] = thisNbs;
    if (b_i + 1 > resols->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, resols->size[0], &se_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    resols_data[b_i] = thisResol;
    if (b_i + 1 > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, allRoughs->size[0],
                                    &te_emlrtBCI, (emlrtCTX)sp);
    }
    allRoughs_data[b_i] = problemDef->params->data[0];
    b_layerSlds = resampledLayers->size[0] * 3;
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &qd_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers_data[b_i].f1->size[0] * allLayers_data[b_i].f1->size[1];
    allLayers_data[b_i].f1->size[0] = resampledLayers->size[0];
    emxEnsureCapacity_real_T(sp, allLayers_data[b_i].f1, i, &ch_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &qd_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers_data[b_i].f1->size[0] * allLayers_data[b_i].f1->size[1];
    allLayers_data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers_data[b_i].f1, i, &ch_emlrtRTEI);
    i = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &qd_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &qd_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &ue_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      allLayers_data[b_i].f1->data[i1] = resampledLayers_data[i1];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_real_T(sp, &resampledLayers);
  emxFree_real_T(sp, &shifted_dat);
  emxFree_real_T(sp, &sldProfile);
  emxFree_real_T(sp, &thisContrastLayers);
  emxFree_cell_wrap_17(sp, &outParameterisedLayers);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (standardTF_stanlay_single.c) */
