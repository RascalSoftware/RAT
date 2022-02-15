/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_stanlay_paraContrasts.c
 *
 * Code generation for function 'standardTF_stanlay_paraContrasts'
 *
 */

/* Include files */
#include "standardTF_stanlay_paraContrasts.h"
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
static emlrtRSInfo ph_emlrtRSI = {
    64,                                 /* lineNo */
    "standardTF_stanlay_paraContrasts", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pathName */
};

static emlrtRSInfo qh_emlrtRSI = {
    76,                                 /* lineNo */
    "standardTF_stanlay_paraContrasts", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pathName */
};

static emlrtRSInfo rh_emlrtRSI = {
    81,                                 /* lineNo */
    "standardTF_stanlay_paraContrasts", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pathName */
};

static emlrtRSInfo sh_emlrtRSI = {
    101,                                /* lineNo */
    "standardTF_stanlay_paraContrasts", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pathName */
};

static emlrtRTEInfo ec_emlrtRTEI = {
    45,                                 /* lineNo */
    9,                                  /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo fc_emlrtRTEI = {
    50,                                 /* lineNo */
    9,                                  /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = {
    55,                                 /* lineNo */
    9,                                  /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pName */
};

static emlrtDCInfo pb_emlrtDCI = {
    70,                                 /* lineNo */
    14,                                 /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    1                                                        /* checkKind */
};

static emlrtRTEInfo hc_emlrtRTEI = {
    70,                                 /* lineNo */
    12,                                 /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pName */
};

static emlrtBCInfo ql_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    85,                                 /* lineNo */
    24,                                 /* colNo */
    "params",                           /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo rl_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    87,                                 /* lineNo */
    29,                                 /* colNo */
    "resample",                         /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo sl_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    90,                                 /* lineNo */
    35,                                 /* colNo */
    "dataPresent",                      /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo tl_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    93,                                 /* lineNo */
    31,                                 /* colNo */
    "backsType",                        /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ul_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    86,                                 /* lineNo */
    37,                                 /* colNo */
    "repeatLayers",                     /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo vl_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    89,                                 /* lineNo */
    24,                                 /* colNo */
    "allData",                          /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo wl_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    91,                                 /* lineNo */
    33,                                 /* colNo */
    "dataLimits",                       /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo xl_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    92,                                 /* lineNo */
    31,                                 /* colNo */
    "simLimits",                        /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo yl_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    46,                                 /* lineNo */
    18,                                 /* colNo */
    "reflectivity",                     /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo am_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    51,                                 /* lineNo */
    16,                                 /* colNo */
    "Simulation",                       /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo bm_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    56,                                 /* lineNo */
    15,                                 /* colNo */
    "allLayers",                        /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo cm_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    112,                                /* lineNo */
    17,                                 /* colNo */
    "sldProfiles",                      /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo dm_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    113,                                /* lineNo */
    18,                                 /* colNo */
    "reflectivity",                     /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo em_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    114,                                /* lineNo */
    16,                                 /* colNo */
    "Simulation",                       /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo fm_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    115,                                /* lineNo */
    18,                                 /* colNo */
    "shifted_data",                     /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo gm_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    116,                                /* lineNo */
    15,                                 /* colNo */
    "layerSlds",                        /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo hm_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    125,                                /* lineNo */
    15,                                 /* colNo */
    "allLayers",                        /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtDCInfo qb_emlrtDCI = {
    32,                                 /* lineNo */
    17,                                 /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    1                                                        /* checkKind */
};

static emlrtDCInfo rb_emlrtDCI = {
    31,                                 /* lineNo */
    16,                                 /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    1                                                        /* checkKind */
};

static emlrtDCInfo sb_emlrtDCI = {
    31,                                 /* lineNo */
    16,                                 /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    4                                                        /* checkKind */
};

static emlrtBCInfo im_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    40,                                 /* lineNo */
    36,                                 /* colNo */
    "layerSlds",                        /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo jm_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    40,                                 /* lineNo */
    36,                                 /* colNo */
    "sldProfiles",                      /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo km_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    40,                                 /* lineNo */
    36,                                 /* colNo */
    "shifted_data",                     /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo lm_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    40,                                 /* lineNo */
    36,                                 /* colNo */
    "reflectivity",                     /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo mm_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    40,                                 /* lineNo */
    36,                                 /* colNo */
    "Simulation",                       /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo nm_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    40,                                 /* lineNo */
    36,                                 /* colNo */
    "allLayers",                        /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo om_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    76,                                 /* lineNo */
    77,                                 /* colNo */
    "cBacks",                           /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo pm_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    76,                                 /* lineNo */
    87,                                 /* colNo */
    "cShifts",                          /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo qm_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    76,                                 /* lineNo */
    98,                                 /* colNo */
    "cScales",                          /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo rm_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    76,                                 /* lineNo */
    109,                                /* colNo */
    "cNbas",                            /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo sm_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    76,                                 /* lineNo */
    118,                                /* colNo */
    "cNbss",                            /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo tm_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    76,                                 /* lineNo */
    127,                                /* colNo */
    "cRes",                             /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo um_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    81,                                 /* lineNo */
    52,                                 /* colNo */
    "contrastLayers",                   /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo vm_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    111,                                /* lineNo */
    5,                                  /* colNo */
    "outSsubs",                         /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo wm_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    112,                                /* lineNo */
    5,                                  /* colNo */
    "sldProfiles",                      /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo xm_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    113,                                /* lineNo */
    5,                                  /* colNo */
    "reflectivity",                     /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ym_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    114,                                /* lineNo */
    5,                                  /* colNo */
    "Simulation",                       /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo an_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    115,                                /* lineNo */
    5,                                  /* colNo */
    "shifted_data",                     /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo bn_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    116,                                /* lineNo */
    5,                                  /* colNo */
    "layerSlds",                        /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo cn_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    117,                                /* lineNo */
    5,                                  /* colNo */
    "chis",                             /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo dn_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    118,                                /* lineNo */
    5,                                  /* colNo */
    "backgs",                           /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo en_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    119,                                /* lineNo */
    5,                                  /* colNo */
    "qshifts",                          /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo fn_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    120,                                /* lineNo */
    5,                                  /* colNo */
    "sfs",                              /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo gn_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    121,                                /* lineNo */
    5,                                  /* colNo */
    "nbas",                             /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo hn_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    122,                                /* lineNo */
    5,                                  /* colNo */
    "nbss",                             /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo in_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    123,                                /* lineNo */
    5,                                  /* colNo */
    "resols",                           /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo jn_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    124,                                /* lineNo */
    5,                                  /* colNo */
    "allRoughs",                        /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo kn_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    125,                                /* lineNo */
    5,                                  /* colNo */
    "allLayers",                        /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ln_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    56,                                 /* lineNo */
    5,                                  /* colNo */
    "allLayers",                        /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo mn_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    51,                                 /* lineNo */
    5,                                  /* colNo */
    "Simulation",                       /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo nn_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    46,                                 /* lineNo */
    5,                                  /* colNo */
    "reflectivity",                     /* aName */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtRTEInfo tm_emlrtRTEI = {
    31,                                 /* lineNo */
    10,                                 /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo um_emlrtRTEI = {
    4,                                  /* lineNo */
    18,                                 /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo vm_emlrtRTEI = {
    40,                                 /* lineNo */
    36,                                 /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo wm_emlrtRTEI = {
    46,                                 /* lineNo */
    5,                                  /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo xm_emlrtRTEI = {
    51,                                 /* lineNo */
    5,                                  /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo ym_emlrtRTEI = {
    56,                                 /* lineNo */
    5,                                  /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo an_emlrtRTEI = {
    38,                                 /* lineNo */
    12,                                 /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo bn_emlrtRTEI = {
    112,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo cn_emlrtRTEI = {
    113,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo dn_emlrtRTEI = {
    114,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo en_emlrtRTEI = {
    115,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo fn_emlrtRTEI = {
    116,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo gn_emlrtRTEI = {
    125,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo hn_emlrtRTEI = {
    89,                                 /* lineNo */
    5,                                  /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo in_emlrtRTEI = {
    81,                                 /* lineNo */
    5,                                  /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo jn_emlrtRTEI = {
    64,                                 /* lineNo */
    1,                                  /* colNo */
    "standardTF_stanlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_stanLay/standardTF_stanlay_paraContrasts.m" /* pName */
};

/* Function Definitions */
void c_standardTF_stanlay_paraContra(
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
  emlrtStack c_st;
  emlrtStack st;
  emxArray_cell_wrap_17 *outParameterisedLayers;
  emxArray_real_T *Simul;
  emxArray_real_T *layerSld;
  emxArray_real_T *reflect;
  emxArray_real_T *resampledLayers;
  emxArray_real_T *sldProfile;
  emxArray_real_T *thisContrastLayers;
  emxArray_real_T *thisData;
  real_T calcSld;
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
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /*  Standard Layers calculation paralelised over the outer loop */
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
  nParams = problemDef->params->size[1];
  calcSld = controls->calcSld;
  /*  Allocate the memory for the output arrays before the main loop */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &sb_emlrtDCI,
                                (emlrtCTX)sp);
  }
  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &rb_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &tm_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &qb_emlrtDCI,
                            (emlrtCTX)sp);
  }
  unnamed_idx_0_tmp_tmp = (int32_T)problemDef->numberOfContrasts;
  i1 = layerSlds->size[0];
  layerSlds->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i1, &um_emlrtRTEI);
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    b_layerSlds = layerSlds->size[0] - 1;
    if (i1 > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, layerSlds->size[0] - 1, &im_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    layerSlds->data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &im_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    b_layerSlds =
        layerSlds->data[i1].f1->size[0] * layerSlds->data[i1].f1->size[1];
    layerSlds->data[i1].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[i1].f1, b_layerSlds,
                             &um_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i1 = sldProfiles->size[0];
  sldProfiles->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i1, &um_emlrtRTEI);
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    b_layerSlds = sldProfiles->size[0] - 1;
    if (i1 > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, sldProfiles->size[0] - 1,
                                    &jm_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &jm_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sldProfiles->data[i1].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i1 = shifted_data->size[0];
  shifted_data->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i1, &um_emlrtRTEI);
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    b_layerSlds = shifted_data->size[0] - 1;
    if (i1 > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, shifted_data->size[0] - 1,
                                    &km_emlrtBCI, (emlrtCTX)sp);
    }
    shifted_data->data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &km_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    shifted_data->data[i1].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i1 = reflectivity->size[0];
  reflectivity->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i1, &um_emlrtRTEI);
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    b_layerSlds = reflectivity->size[0] - 1;
    if (i1 > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, reflectivity->size[0] - 1,
                                    &lm_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &lm_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    b_layerSlds =
        reflectivity->data[i1].f1->size[0] * reflectivity->data[i1].f1->size[1];
    reflectivity->data[i1].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[i1].f1, b_layerSlds,
                             &um_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &ec_emlrtRTEI, (emlrtCTX)sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i1, &vm_emlrtRTEI);
  for (b_layerSlds = 0; b_layerSlds < unnamed_idx_0_tmp_tmp; b_layerSlds++) {
    if (b_layerSlds > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, reflectivity->size[0] - 1,
                                    &yl_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = reflectivity->data[b_layerSlds].f1->size[0] *
         reflectivity->data[b_layerSlds].f1->size[1];
    reflectivity->data[b_layerSlds].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_layerSlds].f1, i1,
                             &wm_emlrtRTEI);
    if (b_layerSlds > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, reflectivity->size[0] - 1,
                                    &yl_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = reflectivity->data[b_layerSlds].f1->size[0] *
         reflectivity->data[b_layerSlds].f1->size[1];
    reflectivity->data[b_layerSlds].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_layerSlds].f1, i1,
                             &wm_emlrtRTEI);
    i1 = reflectivity->size[0];
    if (b_layerSlds > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, reflectivity->size[0] - 1,
                                    &yl_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_layerSlds].f1->data[0] = 1.0;
    if (b_layerSlds > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, i1 - 1, &nn_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    reflectivity->data[b_layerSlds].f1->data[1] = 1.0;
    if (b_layerSlds > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, i1 - 1, &nn_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    reflectivity->data[b_layerSlds].f1->data[2] = 1.0;
    if (b_layerSlds > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, i1 - 1, &nn_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    reflectivity->data[b_layerSlds].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i1 = Simulation->size[0];
  Simulation->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i1, &um_emlrtRTEI);
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    b_layerSlds = Simulation->size[0] - 1;
    if (i1 > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, Simulation->size[0] - 1,
                                    &mm_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &mm_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    b_layerSlds =
        Simulation->data[i1].f1->size[0] * Simulation->data[i1].f1->size[1];
    Simulation->data[i1].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[i1].f1, b_layerSlds,
                             &um_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &fc_emlrtRTEI, (emlrtCTX)sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i1, &vm_emlrtRTEI);
  for (b_layerSlds = 0; b_layerSlds < unnamed_idx_0_tmp_tmp; b_layerSlds++) {
    if (b_layerSlds > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, Simulation->size[0] - 1,
                                    &am_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = Simulation->data[b_layerSlds].f1->size[0] *
         Simulation->data[b_layerSlds].f1->size[1];
    Simulation->data[b_layerSlds].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_layerSlds].f1, i1,
                             &xm_emlrtRTEI);
    if (b_layerSlds > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, Simulation->size[0] - 1,
                                    &am_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = Simulation->data[b_layerSlds].f1->size[0] *
         Simulation->data[b_layerSlds].f1->size[1];
    Simulation->data[b_layerSlds].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_layerSlds].f1, i1,
                             &xm_emlrtRTEI);
    i1 = Simulation->size[0];
    if (b_layerSlds > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, Simulation->size[0] - 1,
                                    &am_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_layerSlds].f1->data[0] = 1.0;
    if (b_layerSlds > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, i1 - 1, &mn_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation->data[b_layerSlds].f1->data[1] = 1.0;
    if (b_layerSlds > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, i1 - 1, &mn_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation->data[b_layerSlds].f1->data[2] = 1.0;
    if (b_layerSlds > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, i1 - 1, &mn_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation->data[b_layerSlds].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i1 = allLayers->size[0];
  allLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i1, &um_emlrtRTEI);
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    b_layerSlds = allLayers->size[0] - 1;
    if (i1 > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, allLayers->size[0] - 1, &nm_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &nm_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[i1].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &gc_emlrtRTEI, (emlrtCTX)sp);
  i1 = allLayers->size[0];
  allLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i1, &vm_emlrtRTEI);
  for (b_layerSlds = 0; b_layerSlds < unnamed_idx_0_tmp_tmp; b_layerSlds++) {
    if (b_layerSlds > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, allLayers->size[0] - 1,
                                    &bm_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = allLayers->data[b_layerSlds].f1->size[0] *
         allLayers->data[b_layerSlds].f1->size[1];
    allLayers->data[b_layerSlds].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_layerSlds].f1, i1,
                             &ym_emlrtRTEI);
    if (b_layerSlds > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, allLayers->size[0] - 1,
                                    &bm_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = allLayers->data[b_layerSlds].f1->size[0] *
         allLayers->data[b_layerSlds].f1->size[1];
    allLayers->data[b_layerSlds].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_layerSlds].f1, i1,
                             &ym_emlrtRTEI);
    i1 = allLayers->size[0];
    if (b_layerSlds > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, allLayers->size[0] - 1,
                                    &bm_emlrtBCI, (emlrtCTX)sp);
    }
    allLayers->data[b_layerSlds].f1->data[0] = 1.0;
    if (b_layerSlds > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, i1 - 1, &ln_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[b_layerSlds].f1->data[1] = 1.0;
    if (b_layerSlds > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, i1 - 1, &ln_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[b_layerSlds].f1->data[2] = 1.0;
    if (b_layerSlds > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_layerSlds, 0, i1 - 1, &ln_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[b_layerSlds].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxInit_cell_wrap_17(sp, &outParameterisedLayers, 2, &jn_emlrtRTEI, true);
  /*  end memory allocation. */
  /*  First we need to allocate the absolute values of the input */
  /*  parameters to all the layers in the layers list. This only needs */
  /*  to be done once, and so is done outside the contrasts loop */
  st.site = &ph_emlrtRSI;
  allocateParamsToLayers(&st, problemDef->params, problemDef_cells->f6,
                         outParameterisedLayers);
  /*  Resample parameters is required */
  /*  Parallel loop over all the contrasts */
  if (unnamed_idx_0_tmp_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &pb_emlrtDCI,
                            (emlrtCTX)sp);
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &hc_emlrtRTEI, (emlrtCTX)sp);
  i = outSsubs->size[0];
  outSsubs->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, outSsubs, i, &an_emlrtRTEI);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &vm_emlrtRTEI);
  i = reflectivity->size[0];
  reflectivity->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &vm_emlrtRTEI);
  i = Simulation->size[0];
  Simulation->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &vm_emlrtRTEI);
  i = shifted_data->size[0];
  shifted_data->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &vm_emlrtRTEI);
  i = layerSlds->size[0];
  layerSlds->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &vm_emlrtRTEI);
  i = chis->size[0];
  chis->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, chis, i, &an_emlrtRTEI);
  i = qshifts->size[0];
  qshifts->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, qshifts, i, &an_emlrtRTEI);
  i = sfs->size[0];
  sfs->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, sfs, i, &an_emlrtRTEI);
  i = nbas->size[0];
  nbas->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, nbas, i, &an_emlrtRTEI);
  i = nbss->size[0];
  nbss->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, nbss, i, &an_emlrtRTEI);
  i = resols->size[0];
  resols->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, resols, i, &an_emlrtRTEI);
  i = allRoughs->size[0];
  allRoughs->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, allRoughs, i, &an_emlrtRTEI);
  i = allLayers->size[0];
  allLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &vm_emlrtRTEI);
  b_layerSlds = unnamed_idx_0_tmp_tmp - 1;
  emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
#pragma omp parallel num_threads(emlrtAllocRegionTLSs(                         \
    sp->tls, omp_in_parallel(), omp_get_max_threads(),                         \
    omp_get_num_procs())) private(thisContrastLayers, sldProfile, reflect,     \
                                  Simul, thisData, layerSld, resampledLayers,  \
                                  thisSsubs, thisChiSquared, thisResol,        \
                                  thisNbs, thisNba, thisSf, thisQshift,        \
                                  thisBackground, emlrtJBEnviron, c_st, b_i,   \
                                  loop_ub, i2, i3)                             \
    firstprivate(b_st, emlrtHadParallelError)
  {
    if (setjmp(emlrtJBEnviron) == 0) {

      b_st.prev = sp;
      b_st.tls = emlrtAllocTLS((emlrtCTX)sp, omp_get_thread_num());
      b_st.site = NULL;
      emlrtSetJmpBuf(&b_st, &emlrtJBEnviron);
      c_st.prev = &b_st;
      c_st.tls = b_st.tls;
      emxInit_real_T(&b_st, &thisContrastLayers, 2, &in_emlrtRTEI, true);
      emxInit_real_T(&b_st, &sldProfile, 2, &um_emlrtRTEI, true);
      emxInit_real_T(&b_st, &reflect, 2, &um_emlrtRTEI, true);
      emxInit_real_T(&b_st, &Simul, 2, &um_emlrtRTEI, true);
      emxInit_real_T(&b_st, &thisData, 2, &hn_emlrtRTEI, true);
      emxInit_real_T(&b_st, &layerSld, 2, &um_emlrtRTEI, true);
      emxInit_real_T(&b_st, &resampledLayers, 2, &um_emlrtRTEI, true);
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
                                        &om_emlrtBCI, &b_st);
        }
        if ((int32_T)(b_i + 1U) > problemDef->contrastShifts->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                        problemDef->contrastShifts->size[1],
                                        &pm_emlrtBCI, &b_st);
        }
        if ((int32_T)(b_i + 1U) > problemDef->contrastScales->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                        problemDef->contrastScales->size[1],
                                        &qm_emlrtBCI, &b_st);
        }
        if ((int32_T)(b_i + 1U) > problemDef->contrastNbas->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                        problemDef->contrastNbas->size[1],
                                        &rm_emlrtBCI, &b_st);
        }
        if ((int32_T)(b_i + 1U) > problemDef->contrastNbss->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                        problemDef->contrastNbss->size[1],
                                        &sm_emlrtBCI, &b_st);
        }
        if ((int32_T)(b_i + 1U) > problemDef->contrastRes->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                        problemDef->contrastRes->size[1],
                                        &tm_emlrtBCI, &b_st);
        }
        c_st.site = &qh_emlrtRSI;
        backSort(&c_st, problemDef->contrastBacks->data[b_i],
                 problemDef->contrastShifts->data[b_i],
                 problemDef->contrastScales->data[b_i],
                 problemDef->contrastNbas->data[b_i],
                 problemDef->contrastNbss->data[b_i],
                 problemDef->contrastRes->data[b_i], problemDef->backs,
                 problemDef->shifts, problemDef->sf, problemDef->nba,
                 problemDef->nbs, problemDef->res, &thisBackground, &thisQshift,
                 &thisSf, &thisNba, &thisNbs, &thisResol);
        /*  Also need to determine which layers from the overall layers list */
        /*  are required for this contrast, and put them in the correct order */
        /*  according to geometry */
        if (b_i > problemDef_cells->f5->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(
              b_i, 0, problemDef_cells->f5->size[1] - 1, &um_emlrtBCI, &b_st);
        }
        c_st.site = &rh_emlrtRSI;
        allocateLayersForContrast(&c_st, problemDef_cells->f5->data[b_i].f1,
                                  outParameterisedLayers, thisContrastLayers);
        /*  For the other parameters, we extract the correct ones from the input
         */
        /*  arrays */
        if (1 > problemDef->params->size[1]) {
          emlrtDynamicBoundsCheckR2012b(1, 1, problemDef->params->size[1],
                                        &ql_emlrtBCI, &b_st);
        }
        /*  Substrate roughness is always first parameter for standard layers */
        if (b_i > problemDef_cells->f1->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(
              b_i, 0, problemDef_cells->f1->size[1] - 1, &ul_emlrtBCI, &b_st);
        }
        if (b_i + 1 > problemDef->resample->size[1]) {
          emlrtDynamicBoundsCheckR2012b(
              b_i + 1, 1, problemDef->resample->size[1], &rl_emlrtBCI, &b_st);
        }
        if (b_i > problemDef_cells->f2->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(
              b_i, 0, problemDef_cells->f2->size[1] - 1, &vl_emlrtBCI, &b_st);
        }
        if (b_i + 1 > problemDef->dataPresent->size[1]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                                        problemDef->dataPresent->size[1],
                                        &sl_emlrtBCI, &b_st);
        }
        if (b_i > problemDef_cells->f3->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(
              b_i, 0, problemDef_cells->f3->size[1] - 1, &wl_emlrtBCI, &b_st);
        }
        if (b_i > problemDef_cells->f4->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(
              b_i, 0, problemDef_cells->f4->size[1] - 1, &xl_emlrtBCI, &b_st);
        }
        if (b_i + 1 > problemDef->contrastBacksType->size[1]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                                        problemDef->contrastBacksType->size[1],
                                        &tl_emlrtBCI, &b_st);
        }
        /*  Now call the core standardTF_stanlay reflectivity calculation */
        /*  In this case we are single cored, so we do not parallelise over */
        /*  points */
        /*  Call the core layers calculation */
        c_st.site = &sh_emlrtRSI;
        standardTF_layers_core(
            &c_st, thisContrastLayers, problemDef->params->data[0],
            problemDef->geometry, thisNba, thisNbs,
            problemDef->resample->data[b_i], calcSld, thisSf, thisQshift,
            problemDef->dataPresent->data[b_i],
            problemDef_cells->f2->data[b_i].f1,
            problemDef_cells->f3->data[b_i].f1,
            (real_T *)problemDef_cells->f4->data[b_i].f1->data,
            *(int32_T(*)[2])problemDef_cells->f4->data[b_i].f1->size,
            problemDef_cells->f1->data[b_i].f1, thisBackground, thisResol,
            problemDef->contrastBacksType->data[b_i], nParams,
            controls->resamPars, sldProfile, reflect, Simul, thisData, layerSld,
            resampledLayers, &thisChiSquared, &thisSsubs);
        /*  Store returned values for this contrast in the output arrays. */
        /*  As well as the calculated profiles, we also store a record of  */
        /*  the other values (background, scalefactors etc) for each contrast */
        /*  for future use. */
        if (b_i + 1 > outSsubs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, outSsubs->size[0],
                                        &vm_emlrtBCI, &b_st);
        }
        outSsubs->data[b_i] = thisSsubs;
        loop_ub = sldProfile->size[0] * 2;
        if (b_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                        &cm_emlrtBCI, &b_st);
        }
        i2 = sldProfiles->data[b_i].f1->size[0] *
             sldProfiles->data[b_i].f1->size[1];
        sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
        emxEnsureCapacity_real_T(&b_st, sldProfiles->data[b_i].f1, i2,
                                 &bn_emlrtRTEI);
        if (b_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                        &cm_emlrtBCI, &b_st);
        }
        i2 = sldProfiles->data[b_i].f1->size[0] *
             sldProfiles->data[b_i].f1->size[1];
        sldProfiles->data[b_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(&b_st, sldProfiles->data[b_i].f1, i2,
                                 &bn_emlrtRTEI);
        i2 = sldProfiles->size[0];
        if (b_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                        &cm_emlrtBCI, &b_st);
        }
        if (b_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                        &cm_emlrtBCI, &b_st);
        }
        for (i3 = 0; i3 < loop_ub; i3++) {
          if (b_i > i2 - 1) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, i2 - 1, &wm_emlrtBCI, &b_st);
          }
          sldProfiles->data[b_i].f1->data[i3] = sldProfile->data[i3];
        }
        loop_ub = reflect->size[0] * 2;
        if (b_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                        &dm_emlrtBCI, &b_st);
        }
        i2 = reflectivity->data[b_i].f1->size[0] *
             reflectivity->data[b_i].f1->size[1];
        reflectivity->data[b_i].f1->size[0] = reflect->size[0];
        emxEnsureCapacity_real_T(&b_st, reflectivity->data[b_i].f1, i2,
                                 &cn_emlrtRTEI);
        if (b_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                        &dm_emlrtBCI, &b_st);
        }
        i2 = reflectivity->data[b_i].f1->size[0] *
             reflectivity->data[b_i].f1->size[1];
        reflectivity->data[b_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(&b_st, reflectivity->data[b_i].f1, i2,
                                 &cn_emlrtRTEI);
        i2 = reflectivity->size[0];
        if (b_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                        &dm_emlrtBCI, &b_st);
        }
        if (b_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                        &dm_emlrtBCI, &b_st);
        }
        for (i3 = 0; i3 < loop_ub; i3++) {
          if (b_i > i2 - 1) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, i2 - 1, &xm_emlrtBCI, &b_st);
          }
          reflectivity->data[b_i].f1->data[i3] = reflect->data[i3];
        }
        loop_ub = Simul->size[0] * 2;
        if (b_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                        &em_emlrtBCI, &b_st);
        }
        i2 = Simulation->data[b_i].f1->size[0] *
             Simulation->data[b_i].f1->size[1];
        Simulation->data[b_i].f1->size[0] = Simul->size[0];
        emxEnsureCapacity_real_T(&b_st, Simulation->data[b_i].f1, i2,
                                 &dn_emlrtRTEI);
        if (b_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                        &em_emlrtBCI, &b_st);
        }
        i2 = Simulation->data[b_i].f1->size[0] *
             Simulation->data[b_i].f1->size[1];
        Simulation->data[b_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(&b_st, Simulation->data[b_i].f1, i2,
                                 &dn_emlrtRTEI);
        i2 = Simulation->size[0];
        if (b_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                        &em_emlrtBCI, &b_st);
        }
        if (b_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                        &em_emlrtBCI, &b_st);
        }
        for (i3 = 0; i3 < loop_ub; i3++) {
          if (b_i > i2 - 1) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, i2 - 1, &ym_emlrtBCI, &b_st);
          }
          Simulation->data[b_i].f1->data[i3] = Simul->data[i3];
        }
        loop_ub = thisData->size[0] * thisData->size[1];
        if (b_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                        &fm_emlrtBCI, &b_st);
        }
        i2 = shifted_data->data[b_i].f1->size[0] *
             shifted_data->data[b_i].f1->size[1];
        shifted_data->data[b_i].f1->size[0] = thisData->size[0];
        emxEnsureCapacity_real_T(&b_st, shifted_data->data[b_i].f1, i2,
                                 &en_emlrtRTEI);
        if (b_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                        &fm_emlrtBCI, &b_st);
        }
        i2 = shifted_data->data[b_i].f1->size[0] *
             shifted_data->data[b_i].f1->size[1];
        shifted_data->data[b_i].f1->size[1] = thisData->size[1];
        emxEnsureCapacity_real_T(&b_st, shifted_data->data[b_i].f1, i2,
                                 &en_emlrtRTEI);
        i2 = shifted_data->size[0];
        if (b_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                        &fm_emlrtBCI, &b_st);
        }
        if (b_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                        &fm_emlrtBCI, &b_st);
        }
        for (i3 = 0; i3 < loop_ub; i3++) {
          if (b_i > i2 - 1) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, i2 - 1, &an_emlrtBCI, &b_st);
          }
          shifted_data->data[b_i].f1->data[i3] = thisData->data[i3];
        }
        loop_ub = layerSld->size[0] * 3;
        if (b_i > layerSlds->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                        &gm_emlrtBCI, &b_st);
        }
        i2 =
            layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
        layerSlds->data[b_i].f1->size[0] = layerSld->size[0];
        emxEnsureCapacity_real_T(&b_st, layerSlds->data[b_i].f1, i2,
                                 &fn_emlrtRTEI);
        if (b_i > layerSlds->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                        &gm_emlrtBCI, &b_st);
        }
        i2 =
            layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
        layerSlds->data[b_i].f1->size[1] = 3;
        emxEnsureCapacity_real_T(&b_st, layerSlds->data[b_i].f1, i2,
                                 &fn_emlrtRTEI);
        i2 = layerSlds->size[0];
        if (b_i > layerSlds->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                        &gm_emlrtBCI, &b_st);
        }
        if (b_i > layerSlds->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                        &gm_emlrtBCI, &b_st);
        }
        for (i3 = 0; i3 < loop_ub; i3++) {
          if (b_i > i2 - 1) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, i2 - 1, &bn_emlrtBCI, &b_st);
          }
          layerSlds->data[b_i].f1->data[i3] = layerSld->data[i3];
        }
        if (b_i + 1 > chis->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, chis->size[0], &cn_emlrtBCI,
                                        &b_st);
        }
        chis->data[b_i] = thisChiSquared;
        if (b_i + 1 > backgs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, backgs->size[0],
                                        &dn_emlrtBCI, &b_st);
        }
        backgs->data[b_i] = thisBackground;
        if (b_i + 1 > qshifts->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, qshifts->size[0],
                                        &en_emlrtBCI, &b_st);
        }
        qshifts->data[b_i] = thisQshift;
        if (b_i + 1 > sfs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, sfs->size[0], &fn_emlrtBCI,
                                        &b_st);
        }
        sfs->data[b_i] = thisSf;
        if (b_i + 1 > nbas->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbas->size[0], &gn_emlrtBCI,
                                        &b_st);
        }
        nbas->data[b_i] = thisNba;
        if (b_i + 1 > nbss->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbss->size[0], &hn_emlrtBCI,
                                        &b_st);
        }
        nbss->data[b_i] = thisNbs;
        if (b_i + 1 > resols->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, resols->size[0],
                                        &in_emlrtBCI, &b_st);
        }
        resols->data[b_i] = thisResol;
        if (b_i + 1 > allRoughs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, allRoughs->size[0],
                                        &jn_emlrtBCI, &b_st);
        }
        allRoughs->data[b_i] = problemDef->params->data[0];
        loop_ub = resampledLayers->size[0] * 3;
        if (b_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                        &hm_emlrtBCI, &b_st);
        }
        i2 =
            allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
        allLayers->data[b_i].f1->size[0] = resampledLayers->size[0];
        emxEnsureCapacity_real_T(&b_st, allLayers->data[b_i].f1, i2,
                                 &gn_emlrtRTEI);
        if (b_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                        &hm_emlrtBCI, &b_st);
        }
        i2 =
            allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
        allLayers->data[b_i].f1->size[1] = 3;
        emxEnsureCapacity_real_T(&b_st, allLayers->data[b_i].f1, i2,
                                 &gn_emlrtRTEI);
        i2 = allLayers->size[0];
        if (b_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                        &hm_emlrtBCI, &b_st);
        }
        if (b_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                        &hm_emlrtBCI, &b_st);
        }
        for (i3 = 0; i3 < loop_ub; i3++) {
          if (b_i > i2 - 1) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, i2 - 1, &kn_emlrtBCI, &b_st);
          }
          allLayers->data[b_i].f1->data[i3] = resampledLayers->data[i3];
        }
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&b_st);
        }
      } else {
        emlrtHadParallelError = true;
      }
    }
    if (!emlrtHadParallelError) {
      emlrtHeapReferenceStackLeaveScope(&b_st, 7);
      emxFree_real_T(&resampledLayers);
      emxFree_real_T(&layerSld);
      emxFree_real_T(&thisData);
      emxFree_real_T(&Simul);
      emxFree_real_T(&reflect);
      emxFree_real_T(&sldProfile);
      emxFree_real_T(&thisContrastLayers);
    }
  }
  emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emxFree_cell_wrap_17(&outParameterisedLayers);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (standardTF_stanlay_paraContrasts.c) */
