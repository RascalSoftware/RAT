/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_custlay_paraContrasts.c
 *
 * Code generation for function 'standardTF_custlay_paraContrasts'
 *
 */

/* Include files */
#include "standardTF_custlay_paraContrasts.h"
#include "backSort.h"
#include "call_customLayers.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo gi_emlrtRSI = {
    71,                                 /* lineNo */
    "standardTF_custlay_paraContrasts", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pathName */
};

static emlrtRSInfo hi_emlrtRSI = {
    75,                                 /* lineNo */
    "standardTF_custlay_paraContrasts", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pathName */
};

static emlrtRSInfo ii_emlrtRSI = {
    97,                                 /* lineNo */
    "standardTF_custlay_paraContrasts", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pathName */
};

static emlrtRTEInfo wc_emlrtRTEI = {
    47,                                 /* lineNo */
    9,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo xc_emlrtRTEI = {
    52,                                 /* lineNo */
    9,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo yc_emlrtRTEI = {
    57,                                 /* lineNo */
    9,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtDCInfo qc_emlrtDCI = {
    66,                                 /* lineNo */
    14,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    1                                                        /* checkKind */
};

static emlrtRTEInfo ad_emlrtRTEI = {
    66,                                 /* lineNo */
    12,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtDCInfo rc_emlrtDCI = {
    74,                                 /* lineNo */
    34,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    1                                                        /* checkKind */
};

static emlrtBCInfo ws_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    81,                                 /* lineNo */
    27,                                 /* colNo */
    "allRoughs",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo xs_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    83,                                 /* lineNo */
    29,                                 /* colNo */
    "resample",                         /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ys_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    86,                                 /* lineNo */
    35,                                 /* colNo */
    "dataPresent",                      /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo at_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    89,                                 /* lineNo */
    31,                                 /* colNo */
    "backsType",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo bt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    74,                                 /* lineNo */
    34,                                 /* colNo */
    "customFiles",                      /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ct_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    82,                                 /* lineNo */
    37,                                 /* colNo */
    "repeatLayers",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo dt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    85,                                 /* lineNo */
    24,                                 /* colNo */
    "allData",                          /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo et_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    87,                                 /* lineNo */
    33,                                 /* colNo */
    "dataLimits",                       /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ft_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    88,                                 /* lineNo */
    31,                                 /* colNo */
    "simLimits",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo gt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    48,                                 /* lineNo */
    18,                                 /* colNo */
    "reflectivity",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ht_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    53,                                 /* lineNo */
    16,                                 /* colNo */
    "Simulation",                       /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo it_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    58,                                 /* lineNo */
    15,                                 /* colNo */
    "allLayers",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo jt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    76,                                 /* lineNo */
    15,                                 /* colNo */
    "allLayers",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo kt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    109,                                /* lineNo */
    17,                                 /* colNo */
    "sldProfiles",                      /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo lt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    110,                                /* lineNo */
    18,                                 /* colNo */
    "reflectivity",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo mt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    111,                                /* lineNo */
    16,                                 /* colNo */
    "Simulation",                       /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo nt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    112,                                /* lineNo */
    18,                                 /* colNo */
    "shifted_data",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ot_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    113,                                /* lineNo */
    15,                                 /* colNo */
    "layerSlds",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo pt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    114,                                /* lineNo */
    15,                                 /* colNo */
    "allLayers",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtDCInfo sc_emlrtDCI = {
    33,                                 /* lineNo */
    17,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    1                                                        /* checkKind */
};

static emlrtDCInfo tc_emlrtDCI = {
    32,                                 /* lineNo */
    16,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    1                                                        /* checkKind */
};

static emlrtDCInfo uc_emlrtDCI = {
    32,                                 /* lineNo */
    16,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    4                                                        /* checkKind */
};

static emlrtBCInfo qt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    41,                                 /* lineNo */
    36,                                 /* colNo */
    "layerSlds",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo rt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    41,                                 /* lineNo */
    36,                                 /* colNo */
    "sldProfiles",                      /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo st_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    41,                                 /* lineNo */
    36,                                 /* colNo */
    "shifted_data",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo tt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    41,                                 /* lineNo */
    36,                                 /* colNo */
    "reflectivity",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ut_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    41,                                 /* lineNo */
    36,                                 /* colNo */
    "Simulation",                       /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo vt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    41,                                 /* lineNo */
    36,                                 /* colNo */
    "allLayers",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo wt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    71,                                 /* lineNo */
    77,                                 /* colNo */
    "cBacks",                           /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo xt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    71,                                 /* lineNo */
    87,                                 /* colNo */
    "cShifts",                          /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo yt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    71,                                 /* lineNo */
    98,                                 /* colNo */
    "cScales",                          /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo au_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    71,                                 /* lineNo */
    109,                                /* colNo */
    "cNbas",                            /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo bu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    71,                                 /* lineNo */
    118,                                /* colNo */
    "cNbss",                            /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo cu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    71,                                 /* lineNo */
    127,                                /* colNo */
    "cRes",                             /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo du_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    74,                                 /* lineNo */
    34,                                 /* colNo */
    "cCustFiles",                       /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo eu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    75,                                 /* lineNo */
    16,                                 /* colNo */
    "allRoughs",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo fu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    76,                                 /* lineNo */
    5,                                  /* colNo */
    "allLayers",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo gu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    108,                                /* lineNo */
    5,                                  /* colNo */
    "outSsubs",                         /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo hu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    109,                                /* lineNo */
    5,                                  /* colNo */
    "sldProfiles",                      /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo iu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    110,                                /* lineNo */
    5,                                  /* colNo */
    "reflectivity",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ju_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    111,                                /* lineNo */
    5,                                  /* colNo */
    "Simulation",                       /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ku_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    112,                                /* lineNo */
    5,                                  /* colNo */
    "shifted_data",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo lu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    113,                                /* lineNo */
    5,                                  /* colNo */
    "layerSlds",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo mu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    114,                                /* lineNo */
    5,                                  /* colNo */
    "allLayers",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo nu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    116,                                /* lineNo */
    5,                                  /* colNo */
    "chis",                             /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ou_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    117,                                /* lineNo */
    5,                                  /* colNo */
    "backgs",                           /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo pu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    118,                                /* lineNo */
    5,                                  /* colNo */
    "qshifts",                          /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo qu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    119,                                /* lineNo */
    5,                                  /* colNo */
    "sfs",                              /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ru_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    120,                                /* lineNo */
    5,                                  /* colNo */
    "nbas",                             /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo su_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    121,                                /* lineNo */
    5,                                  /* colNo */
    "nbss",                             /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo tu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    122,                                /* lineNo */
    5,                                  /* colNo */
    "resols",                           /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo uu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    123,                                /* lineNo */
    5,                                  /* colNo */
    "allRoughs",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo vu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    58,                                 /* lineNo */
    5,                                  /* colNo */
    "allLayers",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo wu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    53,                                 /* lineNo */
    5,                                  /* colNo */
    "Simulation",                       /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo xu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    48,                                 /* lineNo */
    5,                                  /* colNo */
    "reflectivity",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtRTEInfo jp_emlrtRTEI = {
    32,                                 /* lineNo */
    10,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo kp_emlrtRTEI = {
    3,                                  /* lineNo */
    18,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo lp_emlrtRTEI = {
    41,                                 /* lineNo */
    36,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo mp_emlrtRTEI = {
    48,                                 /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo np_emlrtRTEI = {
    53,                                 /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo op_emlrtRTEI = {
    58,                                 /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo pp_emlrtRTEI = {
    38,                                 /* lineNo */
    13,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo qp_emlrtRTEI = {
    76,                                 /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo rp_emlrtRTEI = {
    109,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo sp_emlrtRTEI = {
    110,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo tp_emlrtRTEI = {
    111,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo up_emlrtRTEI = {
    112,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo vp_emlrtRTEI = {
    113,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo wp_emlrtRTEI = {
    114,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo xp_emlrtRTEI = {
    85,                                 /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

/* Function Definitions */
void c_standardTF_custlay_paraContra(
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
  jmp_buf emlrtJBEnviron;
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T *Simul;
  emxArray_real_T *layerSld;
  emxArray_real_T *outLayers;
  emxArray_real_T *reflect;
  emxArray_real_T *resamLayers;
  emxArray_real_T *sldProfile;
  emxArray_real_T *thisData;
  real_T calcSld;
  real_T numberOfContrasts;
  real_T thisBackground;
  real_T thisChiSquared;
  real_T thisNba;
  real_T thisNbs;
  real_T thisQshift;
  real_T thisResol;
  real_T thisSf;
  real_T thisSsubs;
  int32_T b_i;
  int32_T b_layerSlds;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T loop_ub;
  int32_T nParams;
  int32_T unnamed_idx_0_tmp_tmp;
  boolean_T emlrtHadParallelError = false;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /*  Multi threaded version of the custom layers over reflectivity contrasts */
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
  nParams = problemDef->params->size[1];
  numberOfContrasts = problemDef->numberOfContrasts;
  calcSld = controls->calcSld;
  /*  Pre-Allocation of output arrays... */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &uc_emlrtDCI,
                                (emlrtCTX)sp);
  }
  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &tc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &jp_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &sc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  unnamed_idx_0_tmp_tmp = (int32_T)problemDef->numberOfContrasts;
  i1 = layerSlds->size[0];
  layerSlds->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i1, &kp_emlrtRTEI);
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    b_layerSlds = layerSlds->size[0] - 1;
    if (i1 > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, layerSlds->size[0] - 1, &qt_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    layerSlds->data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &qt_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    b_layerSlds =
        layerSlds->data[i1].f1->size[0] * layerSlds->data[i1].f1->size[1];
    layerSlds->data[i1].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[i1].f1, b_layerSlds,
                             &kp_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i1 = sldProfiles->size[0];
  sldProfiles->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i1, &kp_emlrtRTEI);
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    b_layerSlds = sldProfiles->size[0] - 1;
    if (i1 > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, sldProfiles->size[0] - 1,
                                    &rt_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &rt_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sldProfiles->data[i1].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i1 = shifted_data->size[0];
  shifted_data->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i1, &kp_emlrtRTEI);
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    b_layerSlds = shifted_data->size[0] - 1;
    if (i1 > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, shifted_data->size[0] - 1,
                                    &st_emlrtBCI, (emlrtCTX)sp);
    }
    shifted_data->data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &st_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    shifted_data->data[i1].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i1 = reflectivity->size[0];
  reflectivity->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i1, &kp_emlrtRTEI);
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    b_layerSlds = reflectivity->size[0] - 1;
    if (i1 > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, reflectivity->size[0] - 1,
                                    &tt_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &tt_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    b_layerSlds =
        reflectivity->data[i1].f1->size[0] * reflectivity->data[i1].f1->size[1];
    reflectivity->data[i1].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[i1].f1, b_layerSlds,
                             &kp_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &wc_emlrtRTEI, (emlrtCTX)sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i1, &lp_emlrtRTEI);
  for (b_layerSlds = 0; b_layerSlds < unnamed_idx_0_tmp_tmp; b_layerSlds++) {
    if (b_layerSlds > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, reflectivity->size[0] - 1,
                                    &gt_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = reflectivity->data[b_layerSlds].f1->size[0] *
         reflectivity->data[b_layerSlds].f1->size[1];
    reflectivity->data[b_layerSlds].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_layerSlds].f1, i1,
                             &mp_emlrtRTEI);
    if (b_layerSlds > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, reflectivity->size[0] - 1,
                                    &gt_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = reflectivity->data[b_layerSlds].f1->size[0] *
         reflectivity->data[b_layerSlds].f1->size[1];
    reflectivity->data[b_layerSlds].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_layerSlds].f1, i1,
                             &mp_emlrtRTEI);
    i1 = reflectivity->size[0];
    if (b_layerSlds > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, reflectivity->size[0] - 1,
                                    &gt_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_layerSlds].f1->data[0] = 1.0;
    if (b_layerSlds > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, i1 - 1, &xu_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    reflectivity->data[b_layerSlds].f1->data[1] = 1.0;
    if (b_layerSlds > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, i1 - 1, &xu_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    reflectivity->data[b_layerSlds].f1->data[2] = 1.0;
    if (b_layerSlds > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, i1 - 1, &xu_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    reflectivity->data[b_layerSlds].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i1 = Simulation->size[0];
  Simulation->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i1, &kp_emlrtRTEI);
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    b_layerSlds = Simulation->size[0] - 1;
    if (i1 > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, Simulation->size[0] - 1,
                                    &ut_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &ut_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    b_layerSlds =
        Simulation->data[i1].f1->size[0] * Simulation->data[i1].f1->size[1];
    Simulation->data[i1].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[i1].f1, b_layerSlds,
                             &kp_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &xc_emlrtRTEI, (emlrtCTX)sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i1, &lp_emlrtRTEI);
  for (b_layerSlds = 0; b_layerSlds < unnamed_idx_0_tmp_tmp; b_layerSlds++) {
    if (b_layerSlds > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, Simulation->size[0] - 1,
                                    &ht_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = Simulation->data[b_layerSlds].f1->size[0] *
         Simulation->data[b_layerSlds].f1->size[1];
    Simulation->data[b_layerSlds].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_layerSlds].f1, i1,
                             &np_emlrtRTEI);
    if (b_layerSlds > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, Simulation->size[0] - 1,
                                    &ht_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = Simulation->data[b_layerSlds].f1->size[0] *
         Simulation->data[b_layerSlds].f1->size[1];
    Simulation->data[b_layerSlds].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_layerSlds].f1, i1,
                             &np_emlrtRTEI);
    i1 = Simulation->size[0];
    if (b_layerSlds > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, Simulation->size[0] - 1,
                                    &ht_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_layerSlds].f1->data[0] = 1.0;
    if (b_layerSlds > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, i1 - 1, &wu_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation->data[b_layerSlds].f1->data[1] = 1.0;
    if (b_layerSlds > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, i1 - 1, &wu_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation->data[b_layerSlds].f1->data[2] = 1.0;
    if (b_layerSlds > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, i1 - 1, &wu_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation->data[b_layerSlds].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i1 = allLayers->size[0];
  allLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i1, &kp_emlrtRTEI);
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    b_layerSlds = allLayers->size[0] - 1;
    if (i1 > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, allLayers->size[0] - 1, &vt_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &vt_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[i1].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &yc_emlrtRTEI, (emlrtCTX)sp);
  i1 = allLayers->size[0];
  allLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i1, &lp_emlrtRTEI);
  for (b_layerSlds = 0; b_layerSlds < unnamed_idx_0_tmp_tmp; b_layerSlds++) {
    if (b_layerSlds > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, allLayers->size[0] - 1,
                                    &it_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = allLayers->data[b_layerSlds].f1->size[0] *
         allLayers->data[b_layerSlds].f1->size[1];
    allLayers->data[b_layerSlds].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_layerSlds].f1, i1,
                             &op_emlrtRTEI);
    if (b_layerSlds > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, allLayers->size[0] - 1,
                                    &it_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = allLayers->data[b_layerSlds].f1->size[0] *
         allLayers->data[b_layerSlds].f1->size[1];
    allLayers->data[b_layerSlds].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_layerSlds].f1, i1,
                             &op_emlrtRTEI);
    i1 = allLayers->size[0];
    if (b_layerSlds > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, allLayers->size[0] - 1,
                                    &it_emlrtBCI, (emlrtCTX)sp);
    }
    allLayers->data[b_layerSlds].f1->data[0] = 1.0;
    if (b_layerSlds > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, i1 - 1, &vu_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[b_layerSlds].f1->data[1] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  /*    --- End Memory Allocation --- */
  /*  Multi cored over all contrasts */
  if (unnamed_idx_0_tmp_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &qc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &ad_emlrtRTEI, (emlrtCTX)sp);
  i = allRoughs->size[0];
  allRoughs->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, allRoughs, i, &pp_emlrtRTEI);
  i = allLayers->size[0];
  allLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &lp_emlrtRTEI);
  i = outSsubs->size[0];
  outSsubs->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, outSsubs, i, &pp_emlrtRTEI);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &lp_emlrtRTEI);
  i = reflectivity->size[0];
  reflectivity->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &lp_emlrtRTEI);
  i = Simulation->size[0];
  Simulation->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &lp_emlrtRTEI);
  i = shifted_data->size[0];
  shifted_data->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &lp_emlrtRTEI);
  i = layerSlds->size[0];
  layerSlds->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &lp_emlrtRTEI);
  i = chis->size[0];
  chis->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, chis, i, &pp_emlrtRTEI);
  i = qshifts->size[0];
  qshifts->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, qshifts, i, &pp_emlrtRTEI);
  i = sfs->size[0];
  sfs->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, sfs, i, &pp_emlrtRTEI);
  i = nbas->size[0];
  nbas->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, nbas, i, &pp_emlrtRTEI);
  i = nbss->size[0];
  nbss->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, nbss, i, &pp_emlrtRTEI);
  i = resols->size[0];
  resols->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, resols, i, &pp_emlrtRTEI);
  b_layerSlds = unnamed_idx_0_tmp_tmp - 1;
  emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
#pragma omp parallel num_threads(emlrtAllocRegionTLSs(                         \
    sp->tls, omp_in_parallel(), omp_get_max_threads(),                         \
    omp_get_num_procs())) private(outLayers, sldProfile, reflect, Simul,       \
                                  thisData, layerSld, resamLayers, thisSsubs,  \
                                  thisChiSquared, thisResol, thisNbs, thisNba, \
                                  thisSf, thisQshift, thisBackground,          \
                                  emlrtJBEnviron, b_st, b_i, loop_ub, i2, i3)  \
    firstprivate(st, emlrtHadParallelError)
  {
    if (setjmp(emlrtJBEnviron) == 0) {

      st.prev = sp;
      st.tls = emlrtAllocTLS((emlrtCTX)sp, omp_get_thread_num());
      st.site = NULL;
      emlrtSetJmpBuf(&st, &emlrtJBEnviron);
      b_st.prev = &st;
      b_st.tls = st.tls;
      emxInit_real_T(&st, &outLayers, 2, &kp_emlrtRTEI, true);
      emxInit_real_T(&st, &sldProfile, 2, &kp_emlrtRTEI, true);
      emxInit_real_T(&st, &reflect, 2, &kp_emlrtRTEI, true);
      emxInit_real_T(&st, &Simul, 2, &kp_emlrtRTEI, true);
      emxInit_real_T(&st, &thisData, 2, &xp_emlrtRTEI, true);
      emxInit_real_T(&st, &layerSld, 2, &kp_emlrtRTEI, true);
      emxInit_real_T(&st, &resamLayers, 2, &kp_emlrtRTEI, true);
    } else {
      emlrtHadParallelError = true;
    }
#pragma omp for nowait
    for (b_i = 0; b_i <= b_layerSlds; b_i++) {
      if (emlrtHadParallelError)
        continue;
      if (setjmp(emlrtJBEnviron) == 0) {

        /*  Extract the relevant parameter values for this contrast */
        /*  from the input arrays. */
        /*  First need to decide which values of the backrounds, scalefactors */
        /*  data shifts and bulk contrasts are associated with this contrast */
        if ((int32_T)(b_i + 1U) > problemDef->contrastBacks->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                        problemDef->contrastBacks->size[1],
                                        &wt_emlrtBCI, &st);
        }
        if ((int32_T)(b_i + 1U) > problemDef->contrastShifts->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                        problemDef->contrastShifts->size[1],
                                        &xt_emlrtBCI, &st);
        }
        if ((int32_T)(b_i + 1U) > problemDef->contrastScales->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                        problemDef->contrastScales->size[1],
                                        &yt_emlrtBCI, &st);
        }
        if ((int32_T)(b_i + 1U) > problemDef->contrastNbas->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                        problemDef->contrastNbas->size[1],
                                        &au_emlrtBCI, &st);
        }
        if ((int32_T)(b_i + 1U) > problemDef->contrastNbss->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                        problemDef->contrastNbss->size[1],
                                        &bu_emlrtBCI, &st);
        }
        if ((int32_T)(b_i + 1U) > problemDef->contrastRes->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                        problemDef->contrastRes->size[1],
                                        &cu_emlrtBCI, &st);
        }
        b_st.site = &gi_emlrtRSI;
        backSort(&b_st, problemDef->contrastBacks->data[b_i],
                 problemDef->contrastShifts->data[b_i],
                 problemDef->contrastScales->data[b_i],
                 problemDef->contrastNbas->data[b_i],
                 problemDef->contrastNbss->data[b_i],
                 problemDef->contrastRes->data[b_i], problemDef->backs,
                 problemDef->shifts, problemDef->sf, problemDef->nba,
                 problemDef->nbs, problemDef->res, &thisBackground, &thisQshift,
                 &thisSf, &thisNba, &thisNbs, &thisResol);
        /*  Call the custom layers function to get the layers array... */
        if ((int32_T)(b_i + 1U) > problemDef->contrastCustomFiles->size[1]) {
          emlrtDynamicBoundsCheckR2012b(
              (int32_T)(b_i + 1U), 1, problemDef->contrastCustomFiles->size[1],
              &du_emlrtBCI, &st);
        }
        thisSsubs = problemDef->contrastCustomFiles->data[b_i];
        if (thisSsubs != (int32_T)muDoubleScalarFloor(thisSsubs)) {
          emlrtIntegerCheckR2012b(thisSsubs, &rc_emlrtDCI, &st);
        }
        if (((int32_T)thisSsubs - 1 < 0) ||
            ((int32_T)thisSsubs - 1 > problemDef_cells->f14->size[1] - 1)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)thisSsubs - 1, 0,
                                        problemDef_cells->f14->size[1] - 1,
                                        &bt_emlrtBCI, &st);
        }
        b_st.site = &hi_emlrtRSI;
        call_customLayers(
            &b_st, problemDef->params, (real_T)b_i + 1.0,
            problemDef_cells->f14
                ->data[(int32_T)problemDef->contrastCustomFiles->data[b_i] - 1]
                .f1,
            thisNba, thisNbs, numberOfContrasts, outLayers, &thisSsubs);
        if ((int32_T)(b_i + 1U) > allRoughs->size[0]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                        allRoughs->size[0], &eu_emlrtBCI, &st);
        }
        allRoughs->data[b_i] = thisSsubs;
        loop_ub = outLayers->size[0] * outLayers->size[1];
        if (b_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                        &jt_emlrtBCI, &st);
        }
        i2 =
            allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
        allLayers->data[b_i].f1->size[0] = outLayers->size[0];
        emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i2,
                                 &qp_emlrtRTEI);
        if (b_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                        &jt_emlrtBCI, &st);
        }
        i2 =
            allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
        allLayers->data[b_i].f1->size[1] = outLayers->size[1];
        emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i2,
                                 &qp_emlrtRTEI);
        i2 = allLayers->size[0];
        if (b_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                        &jt_emlrtBCI, &st);
        }
        if (b_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                        &jt_emlrtBCI, &st);
        }
        for (i3 = 0; i3 < loop_ub; i3++) {
          if (b_i > i2 - 1) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, i2 - 1, &fu_emlrtBCI, &st);
          }
          allLayers->data[b_i].f1->data[i3] = outLayers->data[i3];
        }
        /*  For the other parameters, we extract the correct ones from the input
         */
        /*  arrays */
        if (b_i + 1 > allRoughs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, allRoughs->size[0],
                                        &ws_emlrtBCI, &st);
        }
        if (b_i > problemDef_cells->f1->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(
              b_i, 0, problemDef_cells->f1->size[1] - 1, &ct_emlrtBCI, &st);
        }
        if (b_i + 1 > problemDef->resample->size[1]) {
          emlrtDynamicBoundsCheckR2012b(
              b_i + 1, 1, problemDef->resample->size[1], &xs_emlrtBCI, &st);
        }
        if (b_i > problemDef_cells->f2->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(
              b_i, 0, problemDef_cells->f2->size[1] - 1, &dt_emlrtBCI, &st);
        }
        if (b_i + 1 > problemDef->dataPresent->size[1]) {
          emlrtDynamicBoundsCheckR2012b(
              b_i + 1, 1, problemDef->dataPresent->size[1], &ys_emlrtBCI, &st);
        }
        if (b_i > problemDef_cells->f3->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(
              b_i, 0, problemDef_cells->f3->size[1] - 1, &et_emlrtBCI, &st);
        }
        if (b_i > problemDef_cells->f4->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(
              b_i, 0, problemDef_cells->f4->size[1] - 1, &ft_emlrtBCI, &st);
        }
        if (b_i + 1 > problemDef->contrastBacksType->size[1]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                                        problemDef->contrastBacksType->size[1],
                                        &at_emlrtBCI, &st);
        }
        /*  Now call the core standardTF_stanlay reflectivity calculation */
        /*  In this case we are single cored, so we do not parallelise over */
        /*  points */
        /*  Call the reflectivity calculation */
        b_st.site = &ii_emlrtRSI;
        b_standardTF_layers_core(
            &b_st, outLayers, allRoughs->data[b_i], problemDef->geometry,
            thisNba, thisNbs, problemDef->resample->data[b_i], calcSld, thisSf,
            thisQshift, problemDef->dataPresent->data[b_i],
            problemDef_cells->f2->data[b_i].f1,
            problemDef_cells->f3->data[b_i].f1,
            (real_T *)problemDef_cells->f4->data[b_i].f1->data,
            *(int32_T(*)[2])problemDef_cells->f4->data[b_i].f1->size,
            problemDef_cells->f1->data[b_i].f1, thisBackground, thisResol,
            problemDef->contrastBacksType->data[b_i], nParams,
            controls->resamPars, sldProfile, reflect, Simul, thisData, layerSld,
            resamLayers, &thisChiSquared, &thisSsubs);
        /*  Store returned values for this contrast in the output arrays. */
        /*  As well as the calculated profiles, we also store a record of  */
        /*  the other values (background, scalefactors etc) for each contrast */
        /*  for future use. */
        if (b_i + 1 > outSsubs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, outSsubs->size[0],
                                        &gu_emlrtBCI, &st);
        }
        outSsubs->data[b_i] = thisSsubs;
        loop_ub = sldProfile->size[0] * 2;
        if (b_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                        &kt_emlrtBCI, &st);
        }
        i2 = sldProfiles->data[b_i].f1->size[0] *
             sldProfiles->data[b_i].f1->size[1];
        sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
        emxEnsureCapacity_real_T(&st, sldProfiles->data[b_i].f1, i2,
                                 &rp_emlrtRTEI);
        if (b_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                        &kt_emlrtBCI, &st);
        }
        i2 = sldProfiles->data[b_i].f1->size[0] *
             sldProfiles->data[b_i].f1->size[1];
        sldProfiles->data[b_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(&st, sldProfiles->data[b_i].f1, i2,
                                 &rp_emlrtRTEI);
        i2 = sldProfiles->size[0];
        if (b_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                        &kt_emlrtBCI, &st);
        }
        if (b_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                        &kt_emlrtBCI, &st);
        }
        for (i3 = 0; i3 < loop_ub; i3++) {
          if (b_i > i2 - 1) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, i2 - 1, &hu_emlrtBCI, &st);
          }
          sldProfiles->data[b_i].f1->data[i3] = sldProfile->data[i3];
        }
        loop_ub = reflect->size[0] * 2;
        if (b_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                        &lt_emlrtBCI, &st);
        }
        i2 = reflectivity->data[b_i].f1->size[0] *
             reflectivity->data[b_i].f1->size[1];
        reflectivity->data[b_i].f1->size[0] = reflect->size[0];
        emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i2,
                                 &sp_emlrtRTEI);
        if (b_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                        &lt_emlrtBCI, &st);
        }
        i2 = reflectivity->data[b_i].f1->size[0] *
             reflectivity->data[b_i].f1->size[1];
        reflectivity->data[b_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(&st, reflectivity->data[b_i].f1, i2,
                                 &sp_emlrtRTEI);
        i2 = reflectivity->size[0];
        if (b_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                        &lt_emlrtBCI, &st);
        }
        if (b_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                        &lt_emlrtBCI, &st);
        }
        for (i3 = 0; i3 < loop_ub; i3++) {
          if (b_i > i2 - 1) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, i2 - 1, &iu_emlrtBCI, &st);
          }
          reflectivity->data[b_i].f1->data[i3] = reflect->data[i3];
        }
        loop_ub = Simul->size[0] * 2;
        if (b_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                        &mt_emlrtBCI, &st);
        }
        i2 = Simulation->data[b_i].f1->size[0] *
             Simulation->data[b_i].f1->size[1];
        Simulation->data[b_i].f1->size[0] = Simul->size[0];
        emxEnsureCapacity_real_T(&st, Simulation->data[b_i].f1, i2,
                                 &tp_emlrtRTEI);
        if (b_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                        &mt_emlrtBCI, &st);
        }
        i2 = Simulation->data[b_i].f1->size[0] *
             Simulation->data[b_i].f1->size[1];
        Simulation->data[b_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(&st, Simulation->data[b_i].f1, i2,
                                 &tp_emlrtRTEI);
        i2 = Simulation->size[0];
        if (b_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                        &mt_emlrtBCI, &st);
        }
        if (b_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                        &mt_emlrtBCI, &st);
        }
        for (i3 = 0; i3 < loop_ub; i3++) {
          if (b_i > i2 - 1) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, i2 - 1, &ju_emlrtBCI, &st);
          }
          Simulation->data[b_i].f1->data[i3] = Simul->data[i3];
        }
        loop_ub = thisData->size[0] * thisData->size[1];
        if (b_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                        &nt_emlrtBCI, &st);
        }
        i2 = shifted_data->data[b_i].f1->size[0] *
             shifted_data->data[b_i].f1->size[1];
        shifted_data->data[b_i].f1->size[0] = thisData->size[0];
        emxEnsureCapacity_real_T(&st, shifted_data->data[b_i].f1, i2,
                                 &up_emlrtRTEI);
        if (b_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                        &nt_emlrtBCI, &st);
        }
        i2 = shifted_data->data[b_i].f1->size[0] *
             shifted_data->data[b_i].f1->size[1];
        shifted_data->data[b_i].f1->size[1] = thisData->size[1];
        emxEnsureCapacity_real_T(&st, shifted_data->data[b_i].f1, i2,
                                 &up_emlrtRTEI);
        i2 = shifted_data->size[0];
        if (b_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                        &nt_emlrtBCI, &st);
        }
        if (b_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                        &nt_emlrtBCI, &st);
        }
        for (i3 = 0; i3 < loop_ub; i3++) {
          if (b_i > i2 - 1) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, i2 - 1, &ku_emlrtBCI, &st);
          }
          shifted_data->data[b_i].f1->data[i3] = thisData->data[i3];
        }
        loop_ub = layerSld->size[0] * 3;
        if (b_i > layerSlds->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                        &ot_emlrtBCI, &st);
        }
        i2 =
            layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
        layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
        emxEnsureCapacity_real_T(&st, layerSlds->data[b_i].f1, i2,
                                 &vp_emlrtRTEI);
        if (b_i > layerSlds->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                        &ot_emlrtBCI, &st);
        }
        i2 =
            layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
        layerSlds->data[b_i].f1->size[1] = 3;
        emxEnsureCapacity_real_T(&st, layerSlds->data[b_i].f1, i2,
                                 &vp_emlrtRTEI);
        i2 = layerSlds->size[0];
        if (b_i > layerSlds->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                        &ot_emlrtBCI, &st);
        }
        if (b_i > layerSlds->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                        &ot_emlrtBCI, &st);
        }
        for (i3 = 0; i3 < loop_ub; i3++) {
          if (b_i > i2 - 1) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, i2 - 1, &lu_emlrtBCI, &st);
          }
          layerSlds->data[b_i].f1->data[i3] = layerSld->data[i3];
        }
        loop_ub = resamLayers->size[0] * 3;
        if (b_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                        &pt_emlrtBCI, &st);
        }
        i2 =
            allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
        allLayers->data[b_i].f1->size[0] = resamLayers->size[0];
        emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i2,
                                 &wp_emlrtRTEI);
        if (b_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                        &pt_emlrtBCI, &st);
        }
        i2 =
            allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
        allLayers->data[b_i].f1->size[1] = 3;
        emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i2,
                                 &wp_emlrtRTEI);
        i2 = allLayers->size[0];
        if (b_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                        &pt_emlrtBCI, &st);
        }
        if (b_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                        &pt_emlrtBCI, &st);
        }
        for (i3 = 0; i3 < loop_ub; i3++) {
          if (b_i > i2 - 1) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, i2 - 1, &mu_emlrtBCI, &st);
          }
          allLayers->data[b_i].f1->data[i3] = resamLayers->data[i3];
        }
        if (b_i + 1 > chis->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, chis->size[0], &nu_emlrtBCI,
                                        &st);
        }
        chis->data[b_i] = thisChiSquared;
        if (b_i + 1 > backgs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, backgs->size[0],
                                        &ou_emlrtBCI, &st);
        }
        backgs->data[b_i] = thisBackground;
        if (b_i + 1 > qshifts->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, qshifts->size[0],
                                        &pu_emlrtBCI, &st);
        }
        qshifts->data[b_i] = thisQshift;
        if (b_i + 1 > sfs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, sfs->size[0], &qu_emlrtBCI,
                                        &st);
        }
        sfs->data[b_i] = thisSf;
        if (b_i + 1 > nbas->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbas->size[0], &ru_emlrtBCI,
                                        &st);
        }
        nbas->data[b_i] = thisNba;
        if (b_i + 1 > nbss->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbss->size[0], &su_emlrtBCI,
                                        &st);
        }
        nbss->data[b_i] = thisNbs;
        if (b_i + 1 > resols->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, resols->size[0],
                                        &tu_emlrtBCI, &st);
        }
        resols->data[b_i] = thisResol;
        if (b_i + 1 > allRoughs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, allRoughs->size[0],
                                        &uu_emlrtBCI, &st);
        }
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      } else {
        emlrtHadParallelError = true;
      }
    }
    if (!emlrtHadParallelError) {
      emlrtHeapReferenceStackLeaveScope(&st, 7);
      emxFree_real_T(&resamLayers);
      emxFree_real_T(&layerSld);
      emxFree_real_T(&thisData);
      emxFree_real_T(&Simul);
      emxFree_real_T(&reflect);
      emxFree_real_T(&sldProfile);
      emxFree_real_T(&outLayers);
    }
  }
  emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (standardTF_custlay_paraContrasts.c) */
