/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_custlay_single.c
 *
 * Code generation for function 'standardTF_custlay_single'
 *
 */

/* Include files */
#include "standardTF_custlay_single.h"
#include "backSort.h"
#include "call_customLayers.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo xh_emlrtRSI = {
    74,                          /* lineNo */
    "standardTF_custlay_single", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m" /* pathName */
};

static emlrtRSInfo yh_emlrtRSI = {
    78,                          /* lineNo */
    "standardTF_custlay_single", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m" /* pathName */
};

static emlrtRSInfo ai_emlrtRSI = {
    101,                         /* lineNo */
    "standardTF_custlay_single", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m" /* pathName */
};

static emlrtRTEInfo mc_emlrtRTEI = {
    46,                          /* lineNo */
    9,                           /* colNo */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m" /* pName */
};

static emlrtRTEInfo nc_emlrtRTEI = {
    51,                          /* lineNo */
    9,                           /* colNo */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m" /* pName */
};

static emlrtRTEInfo oc_emlrtRTEI = {
    56,                          /* lineNo */
    9,                           /* colNo */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m" /* pName */
};

static emlrtRTEInfo pc_emlrtRTEI = {
    69,                          /* lineNo */
    9,                           /* colNo */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m" /* pName */
};

static emlrtDCInfo fc_emlrtDCI = {
    77,                          /* lineNo */
    34,                          /* colNo */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    1                                                 /* checkKind */
};

static emlrtBCInfo ho_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    85,                          /* lineNo */
    27,                          /* colNo */
    "allRoughs",                 /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo io_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    87,                          /* lineNo */
    29,                          /* colNo */
    "resample",                  /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo jo_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    90,                          /* lineNo */
    35,                          /* colNo */
    "dataPresent",               /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo ko_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    93,                          /* lineNo */
    31,                          /* colNo */
    "backsType",                 /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo lo_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    77,                          /* lineNo */
    34,                          /* colNo */
    "customFiles",               /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo mo_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    86,                          /* lineNo */
    37,                          /* colNo */
    "repeatLayers",              /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo no_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    89,                          /* lineNo */
    24,                          /* colNo */
    "allData",                   /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo oo_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    91,                          /* lineNo */
    33,                          /* colNo */
    "dataLimits",                /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo po_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    92,                          /* lineNo */
    31,                          /* colNo */
    "simLimits",                 /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo qo_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    47,                          /* lineNo */
    18,                          /* colNo */
    "reflectivity",              /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo ro_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    52,                          /* lineNo */
    16,                          /* colNo */
    "Simulation",                /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo so_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    57,                          /* lineNo */
    15,                          /* colNo */
    "allLayers",                 /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo to_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    80,                          /* lineNo */
    15,                          /* colNo */
    "allLayers",                 /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo uo_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    113,                         /* lineNo */
    17,                          /* colNo */
    "sldProfiles",               /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo vo_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    116,                         /* lineNo */
    18,                          /* colNo */
    "shifted_data",              /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo wo_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    118,                         /* lineNo */
    15,                          /* colNo */
    "allLayers",                 /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtDCInfo gc_emlrtDCI = {
    32,                          /* lineNo */
    17,                          /* colNo */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    1                                                 /* checkKind */
};

static emlrtDCInfo hc_emlrtDCI = {
    31,                          /* lineNo */
    16,                          /* colNo */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    1                                                 /* checkKind */
};

static emlrtDCInfo ic_emlrtDCI = {
    31,                          /* lineNo */
    16,                          /* colNo */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    4                                                 /* checkKind */
};

static emlrtBCInfo xo_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    40,                          /* lineNo */
    36,                          /* colNo */
    "layerSlds",                 /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo yo_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    40,                          /* lineNo */
    36,                          /* colNo */
    "sldProfiles",               /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo ap_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    40,                          /* lineNo */
    36,                          /* colNo */
    "shifted_data",              /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo bp_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    40,                          /* lineNo */
    36,                          /* colNo */
    "reflectivity",              /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo cp_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    40,                          /* lineNo */
    36,                          /* colNo */
    "Simulation",                /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo dp_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    40,                          /* lineNo */
    36,                          /* colNo */
    "allLayers",                 /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo ep_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    74,                          /* lineNo */
    77,                          /* colNo */
    "cBacks",                    /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo fp_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    74,                          /* lineNo */
    87,                          /* colNo */
    "cShifts",                   /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo gp_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    74,                          /* lineNo */
    98,                          /* colNo */
    "cScales",                   /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo hp_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    74,                          /* lineNo */
    109,                         /* colNo */
    "cNbas",                     /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo ip_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    74,                          /* lineNo */
    118,                         /* colNo */
    "cNbss",                     /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo jp_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    74,                          /* lineNo */
    127,                         /* colNo */
    "cRes",                      /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo kp_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    77,                          /* lineNo */
    34,                          /* colNo */
    "cCustFiles",                /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo lp_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    78,                          /* lineNo */
    16,                          /* colNo */
    "allRoughs",                 /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo mp_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    80,                          /* lineNo */
    5,                           /* colNo */
    "allLayers",                 /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo np_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    114,                         /* lineNo */
    5,                           /* colNo */
    "reflectivity",              /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo op_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    115,                         /* lineNo */
    5,                           /* colNo */
    "Simulation",                /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo pp_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    117,                         /* lineNo */
    5,                           /* colNo */
    "layerSlds",                 /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo qp_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    120,                         /* lineNo */
    5,                           /* colNo */
    "chis",                      /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo rp_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    112,                         /* lineNo */
    5,                           /* colNo */
    "outSsubs",                  /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo sp_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    113,                         /* lineNo */
    5,                           /* colNo */
    "sldProfiles",               /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo tp_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    116,                         /* lineNo */
    5,                           /* colNo */
    "shifted_data",              /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo up_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    118,                         /* lineNo */
    5,                           /* colNo */
    "allLayers",                 /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo vp_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    121,                         /* lineNo */
    5,                           /* colNo */
    "backgs",                    /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo wp_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    122,                         /* lineNo */
    5,                           /* colNo */
    "qshifts",                   /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo xp_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    123,                         /* lineNo */
    5,                           /* colNo */
    "sfs",                       /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo yp_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    124,                         /* lineNo */
    5,                           /* colNo */
    "nbas",                      /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo aq_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    125,                         /* lineNo */
    5,                           /* colNo */
    "nbss",                      /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo bq_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    126,                         /* lineNo */
    5,                           /* colNo */
    "resols",                    /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo cq_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    127,                         /* lineNo */
    5,                           /* colNo */
    "allRoughs",                 /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo dq_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    57,                          /* lineNo */
    5,                           /* colNo */
    "allLayers",                 /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo eq_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    52,                          /* lineNo */
    5,                           /* colNo */
    "Simulation",                /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo fq_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    47,                          /* lineNo */
    5,                           /* colNo */
    "reflectivity",              /* aName */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtRTEInfo do_emlrtRTEI = {
    31,                          /* lineNo */
    10,                          /* colNo */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m" /* pName */
};

static emlrtRTEInfo eo_emlrtRTEI = {
    3,                           /* lineNo */
    18,                          /* colNo */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m" /* pName */
};

static emlrtRTEInfo fo_emlrtRTEI = {
    40,                          /* lineNo */
    36,                          /* colNo */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m" /* pName */
};

static emlrtRTEInfo go_emlrtRTEI = {
    47,                          /* lineNo */
    5,                           /* colNo */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m" /* pName */
};

static emlrtRTEInfo ho_emlrtRTEI = {
    52,                          /* lineNo */
    5,                           /* colNo */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m" /* pName */
};

static emlrtRTEInfo io_emlrtRTEI = {
    57,                          /* lineNo */
    5,                           /* colNo */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m" /* pName */
};

static emlrtRTEInfo jo_emlrtRTEI = {
    37,                          /* lineNo */
    13,                          /* colNo */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m" /* pName */
};

static emlrtRTEInfo ko_emlrtRTEI = {
    80,                          /* lineNo */
    5,                           /* colNo */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m" /* pName */
};

static emlrtRTEInfo lo_emlrtRTEI = {
    113,                         /* lineNo */
    5,                           /* colNo */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m" /* pName */
};

static emlrtRTEInfo mo_emlrtRTEI = {
    116,                         /* lineNo */
    5,                           /* colNo */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m" /* pName */
};

static emlrtRTEInfo no_emlrtRTEI = {
    118,                         /* lineNo */
    5,                           /* colNo */
    "standardTF_custlay_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_single.m" /* pName */
};

/* Function Definitions */
void standardTF_custlay_single(
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
  emlrtStack st;
  emxArray_real_T *outLayers;
  emxArray_real_T *resamLayers;
  emxArray_real_T *shifted_dat;
  emxArray_real_T *sldProfile;
  real_T d;
  real_T thisBackground;
  real_T thisNba;
  real_T thisNbs;
  real_T thisQshift;
  real_T thisResol;
  real_T thisSf;
  int32_T b_i;
  int32_T b_layerSlds;
  int32_T i;
  int32_T i1;
  int32_T unnamed_idx_0_tmp_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /*  Single threaded version of the custom layers, standardTF reflectivity */
  /*  calculation. The function extracts the relevant parameters from the input
   */
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
  /*  Pre-Allocation of output arrays... */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &ic_emlrtDCI,
                                (emlrtCTX)sp);
  }
  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &hc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &do_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &gc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  unnamed_idx_0_tmp_tmp = (int32_T)problemDef->numberOfContrasts;
  i = layerSlds->size[0];
  layerSlds->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &eo_emlrtRTEI);
  for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
    b_layerSlds = layerSlds->size[0] - 1;
    if (i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, layerSlds->size[0] - 1, &xo_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    layerSlds->data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &xo_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
    layerSlds->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[i].f1, i1, &eo_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = sldProfiles->size[0];
  sldProfiles->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &eo_emlrtRTEI);
  for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
    b_layerSlds = sldProfiles->size[0] - 1;
    if (i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, sldProfiles->size[0] - 1,
                                    &yo_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &yo_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sldProfiles->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = shifted_data->size[0];
  shifted_data->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &eo_emlrtRTEI);
  for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
    b_layerSlds = shifted_data->size[0] - 1;
    if (i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, shifted_data->size[0] - 1,
                                    &ap_emlrtBCI, (emlrtCTX)sp);
    }
    shifted_data->data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &ap_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    shifted_data->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = reflectivity->size[0];
  reflectivity->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &eo_emlrtRTEI);
  for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
    b_layerSlds = reflectivity->size[0] - 1;
    if (i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, reflectivity->size[0] - 1,
                                    &bp_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &bp_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = reflectivity->data[i].f1->size[0] * reflectivity->data[i].f1->size[1];
    reflectivity->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[i].f1, i1, &eo_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &mc_emlrtRTEI, (emlrtCTX)sp);
  i = reflectivity->size[0];
  reflectivity->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &fo_emlrtRTEI);
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &qo_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity->data[b_i].f1->size[0] *
        reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &go_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &qo_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity->data[b_i].f1->size[0] *
        reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &go_emlrtRTEI);
    i = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &qo_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &fq_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &fq_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &fq_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = Simulation->size[0];
  Simulation->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &eo_emlrtRTEI);
  for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
    b_layerSlds = Simulation->size[0] - 1;
    if (i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, Simulation->size[0] - 1, &cp_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation->data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &cp_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = Simulation->data[i].f1->size[0] * Simulation->data[i].f1->size[1];
    Simulation->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[i].f1, i1, &eo_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &nc_emlrtRTEI, (emlrtCTX)sp);
  i = Simulation->size[0];
  Simulation->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &fo_emlrtRTEI);
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &ro_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &ho_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &ro_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &ho_emlrtRTEI);
    i = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &ro_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &eq_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &eq_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &eq_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = allLayers->size[0];
  allLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &eo_emlrtRTEI);
  for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
    b_layerSlds = allLayers->size[0] - 1;
    if (i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, allLayers->size[0] - 1, &dp_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &dp_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &oc_emlrtRTEI, (emlrtCTX)sp);
  i = allLayers->size[0];
  allLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &fo_emlrtRTEI);
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &so_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &io_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &so_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &io_emlrtRTEI);
    i = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &so_emlrtBCI, (emlrtCTX)sp);
    }
    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &dq_emlrtBCI, (emlrtCTX)sp);
    }
    allLayers->data[b_i].f1->data[1] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  /*    --- End Memory Allocation --- */
  /*  Resampling parameters */
  /*  Custom model loop */
  /*  Single cored over all contrasts */
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &pc_emlrtRTEI, (emlrtCTX)sp);
  i = allRoughs->size[0];
  allRoughs->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, allRoughs, i, &jo_emlrtRTEI);
  i = allLayers->size[0];
  allLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &fo_emlrtRTEI);
  i = outSsubs->size[0];
  outSsubs->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, outSsubs, i, &jo_emlrtRTEI);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &fo_emlrtRTEI);
  i = reflectivity->size[0];
  reflectivity->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &fo_emlrtRTEI);
  i = Simulation->size[0];
  Simulation->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &fo_emlrtRTEI);
  i = shifted_data->size[0];
  shifted_data->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &fo_emlrtRTEI);
  i = layerSlds->size[0];
  layerSlds->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &fo_emlrtRTEI);
  i = chis->size[0];
  chis->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, chis, i, &jo_emlrtRTEI);
  i = qshifts->size[0];
  qshifts->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, qshifts, i, &jo_emlrtRTEI);
  i = sfs->size[0];
  sfs->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, sfs, i, &jo_emlrtRTEI);
  i = nbas->size[0];
  nbas->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, nbas, i, &jo_emlrtRTEI);
  i = nbss->size[0];
  nbss->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, nbss, i, &jo_emlrtRTEI);
  i = resols->size[0];
  resols->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, resols, i, &jo_emlrtRTEI);
  emxInit_real_T(sp, &outLayers, 2, &eo_emlrtRTEI, true);
  emxInit_real_T(sp, &sldProfile, 2, &eo_emlrtRTEI, true);
  emxInit_real_T(sp, &shifted_dat, 2, &eo_emlrtRTEI, true);
  emxInit_real_T(sp, &resamLayers, 2, &eo_emlrtRTEI, true);
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    /*  Extract the relevant parameter values for this contrast */
    /*  from the input arrays. */
    /*  First need to decide which values of the backrounds, scalefactors */
    /*  data shifts and bulk contrasts are associated with this contrast */
    if ((int32_T)(b_i + 1U) > problemDef->contrastBacks->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastBacks->size[1],
                                    &ep_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastShifts->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastShifts->size[1],
                                    &fp_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastScales->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastScales->size[1],
                                    &gp_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastNbas->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastNbas->size[1],
                                    &hp_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastNbss->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastNbss->size[1],
                                    &ip_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastRes->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastRes->size[1],
                                    &jp_emlrtBCI, (emlrtCTX)sp);
    }
    st.site = &xh_emlrtRSI;
    backSort(&st, problemDef->contrastBacks->data[b_i],
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
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastCustomFiles->size[1],
                                    &kp_emlrtBCI, (emlrtCTX)sp);
    }
    d = problemDef->contrastCustomFiles->data[b_i];
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &fc_emlrtDCI, (emlrtCTX)sp);
    }
    if (((int32_T)d - 1 < 0) ||
        ((int32_T)d - 1 > problemDef_cells->f14->size[1] - 1)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d - 1, 0,
                                    problemDef_cells->f14->size[1] - 1,
                                    &lo_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, allRoughs->size[0],
                                    &lp_emlrtBCI, (emlrtCTX)sp);
    }
    st.site = &yh_emlrtRSI;
    call_customLayers(
        &st, problemDef->params, (real_T)b_i + 1.0,
        problemDef_cells->f14
            ->data[(int32_T)problemDef->contrastCustomFiles->data[b_i] - 1]
            .f1,
        thisNba, thisNbs, problemDef->numberOfContrasts, outLayers,
        &allRoughs->data[b_i]);
    b_layerSlds = outLayers->size[0] * outLayers->size[1];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &to_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = outLayers->size[0];
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &ko_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &to_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = outLayers->size[1];
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &ko_emlrtRTEI);
    i = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &to_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &to_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &mp_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      allLayers->data[b_i].f1->data[i1] = outLayers->data[i1];
    }
    /*  For the other parameters, we extract the correct ones from the input */
    /*  arrays */
    if (b_i + 1 > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, allRoughs->size[0],
                                    &ho_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f1->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f1->size[1] - 1,
                                    &mo_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i + 1 > problemDef->resample->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, problemDef->resample->size[1],
                                    &io_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f2->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f2->size[1] - 1,
                                    &no_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i + 1 > problemDef->dataPresent->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                                    problemDef->dataPresent->size[1],
                                    &jo_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f3->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f3->size[1] - 1,
                                    &oo_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f4->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f4->size[1] - 1,
                                    &po_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i + 1 > problemDef->contrastBacksType->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                                    problemDef->contrastBacksType->size[1],
                                    &ko_emlrtBCI, (emlrtCTX)sp);
    }
    /*  Now call the core standardTF_stanlay reflectivity calculation */
    /*  In this case we are single cored, so we do not parallelise over */
    /*  points */
    /*  Call the reflectivity calculation */
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &np_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &op_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                    &pp_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i + 1 > chis->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, chis->size[0], &qp_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (b_i + 1 > outSsubs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, outSsubs->size[0], &rp_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    st.site = &ai_emlrtRSI;
    b_standardTF_layers_core(
        &st, outLayers, allRoughs->data[b_i], problemDef->geometry, thisNba,
        thisNbs, problemDef->resample->data[b_i], controls->calcSld, thisSf,
        thisQshift, problemDef->dataPresent->data[b_i],
        problemDef_cells->f2->data[b_i].f1, problemDef_cells->f3->data[b_i].f1,
        (real_T *)problemDef_cells->f4->data[b_i].f1->data,
        *(int32_T(*)[2])problemDef_cells->f4->data[b_i].f1->size,
        problemDef_cells->f1->data[b_i].f1, thisBackground, thisResol,
        problemDef->contrastBacksType->data[b_i], problemDef->params->size[1],
        controls->resamPars, sldProfile, reflectivity->data[b_i].f1,
        Simulation->data[b_i].f1, shifted_dat, layerSlds->data[b_i].f1,
        resamLayers, &chis->data[b_i], &outSsubs->data[b_i]);
    /*  Store returned values for this contrast in the output arrays. */
    /*  As well as the calculated profiles, we also store a record of  */
    /*  the other values (background, scalefactors etc) for each contrast */
    /*  for future use. */
    b_layerSlds = sldProfile->size[0] * 2;
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &uo_emlrtBCI, (emlrtCTX)sp);
    }
    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &lo_emlrtRTEI);
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &uo_emlrtBCI, (emlrtCTX)sp);
    }
    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &lo_emlrtRTEI);
    i = sldProfiles->size[0];
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &uo_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &uo_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &sp_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      sldProfiles->data[b_i].f1->data[i1] = sldProfile->data[i1];
    }
    b_layerSlds = shifted_dat->size[0] * shifted_dat->size[1];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &vo_emlrtBCI, (emlrtCTX)sp);
    }
    i = shifted_data->data[b_i].f1->size[0] *
        shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &mo_emlrtRTEI);
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &vo_emlrtBCI, (emlrtCTX)sp);
    }
    i = shifted_data->data[b_i].f1->size[0] *
        shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[1] = shifted_dat->size[1];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &mo_emlrtRTEI);
    i = shifted_data->size[0];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &vo_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &vo_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &tp_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      shifted_data->data[b_i].f1->data[i1] = shifted_dat->data[i1];
    }
    b_layerSlds = resamLayers->size[0] * 3;
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &wo_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = resamLayers->size[0];
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &no_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &wo_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &no_emlrtRTEI);
    i = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &wo_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &wo_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &up_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      allLayers->data[b_i].f1->data[i1] = resamLayers->data[i1];
    }
    if (b_i + 1 > backgs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, backgs->size[0], &vp_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    backgs->data[b_i] = thisBackground;
    if (b_i + 1 > qshifts->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, qshifts->size[0], &wp_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    qshifts->data[b_i] = thisQshift;
    if (b_i + 1 > sfs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, sfs->size[0], &xp_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sfs->data[b_i] = thisSf;
    if (b_i + 1 > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbas->size[0], &yp_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    nbas->data[b_i] = thisNba;
    if (b_i + 1 > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbss->size[0], &aq_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    nbss->data[b_i] = thisNbs;
    if (b_i + 1 > resols->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, resols->size[0], &bq_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    resols->data[b_i] = thisResol;
    if (b_i + 1 > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, allRoughs->size[0],
                                    &cq_emlrtBCI, (emlrtCTX)sp);
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_real_T(&resamLayers);
  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&sldProfile);
  emxFree_real_T(&outLayers);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (standardTF_custlay_single.c) */
