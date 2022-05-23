/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * standardTF_custlay_paraContrasts.c
 *
 * Code generation for function 'standardTF_custlay_paraContrasts'
 *
 */

/* Include files */
#include "standardTF_custlay_paraContrasts.h"
#include "backSort.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_mexutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo yh_emlrtRSI = {
    68,                                 /* lineNo */
    "standardTF_custlay_paraContrasts", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pathName */
};

static emlrtRSInfo ai_emlrtRSI = {
    79,                                 /* lineNo */
    "standardTF_custlay_paraContrasts", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pathName */
};

static emlrtRSInfo bi_emlrtRSI = {
    102,                                /* lineNo */
    "standardTF_custlay_paraContrasts", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pathName */
};

static emlrtMCInfo c_emlrtMCI = {
    23,                         /* lineNo */
    2,                          /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "loopMatlabCustomLayers/loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtRTEInfo vc_emlrtRTEI = {
    51,                                 /* lineNo */
    9,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = {
    56,                                 /* lineNo */
    9,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo xc_emlrtRTEI = {
    61,                                 /* lineNo */
    9,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtDCInfo qc_emlrtDCI = {
    74,                                 /* lineNo */
    14,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    1                                                        /* checkKind */
};

static emlrtRTEInfo yc_emlrtRTEI = {
    74,                                 /* lineNo */
    12,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtBCInfo qs_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    86,                                 /* lineNo */
    27,                                 /* colNo */
    "allRoughs",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo rs_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    88,                                 /* lineNo */
    29,                                 /* colNo */
    "resample",                         /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ss_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    91,                                 /* lineNo */
    35,                                 /* colNo */
    "dataPresent",                      /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ts_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    94,                                 /* lineNo */
    31,                                 /* colNo */
    "backsType",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo us_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    82,                                 /* lineNo */
    36,                                 /* colNo */
    "allLayers",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo vs_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    87,                                 /* lineNo */
    37,                                 /* colNo */
    "repeatLayers",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ws_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    90,                                 /* lineNo */
    24,                                 /* colNo */
    "allData",                          /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo xs_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    92,                                 /* lineNo */
    33,                                 /* colNo */
    "dataLimits",                       /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ys_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    93,                                 /* lineNo */
    31,                                 /* colNo */
    "simLimits",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtDCInfo rc_emlrtDCI = {
    9,                          /* lineNo */
    23,                         /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "loopMatlabCustomLayers/loopMatalbCustlayWrapper.m", /* pName */
    1                                                    /* checkKind */
};

static emlrtDCInfo sc_emlrtDCI = {
    11,                         /* lineNo */
    20,                         /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "loopMatlabCustomLayers/loopMatalbCustlayWrapper.m", /* pName */
    1                                                    /* checkKind */
};

static emlrtRTEInfo ad_emlrtRTEI = {
    13,                         /* lineNo */
    10,                         /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "loopMatlabCustomLayers/loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = {
    28,                         /* lineNo */
    10,                         /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "loopMatlabCustomLayers/loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtBCInfo at_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    29,                         /* lineNo */
    30,                         /* colNo */
    "tempAllLayers",            /* aName */
    "loopMatalbCustlayWrapper", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "loopMatlabCustomLayers/loopMatalbCustlayWrapper.m", /* pName */
    0                                                    /* checkKind */
};

static emlrtBCInfo bt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    52,                                 /* lineNo */
    18,                                 /* colNo */
    "reflectivity",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ct_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    57,                                 /* lineNo */
    16,                                 /* colNo */
    "Simulation",                       /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo dt_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    14,                         /* lineNo */
    16,                         /* colNo */
    "allLayers",                /* aName */
    "loopMatalbCustlayWrapper", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "loopMatlabCustomLayers/loopMatalbCustlayWrapper.m", /* pName */
    0                                                    /* checkKind */
};

static emlrtBCInfo et_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    15,                         /* lineNo */
    20,                         /* colNo */
    "tempAllLayers",            /* aName */
    "loopMatalbCustlayWrapper", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "loopMatlabCustomLayers/loopMatalbCustlayWrapper.m", /* pName */
    0                                                    /* checkKind */
};

static emlrtBCInfo ft_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    34,                         /* lineNo */
    16,                         /* colNo */
    "allLayers",                /* aName */
    "loopMatalbCustlayWrapper", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "loopMatlabCustomLayers/loopMatalbCustlayWrapper.m", /* pName */
    0                                                    /* checkKind */
};

static emlrtBCInfo gt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    114,                                /* lineNo */
    17,                                 /* colNo */
    "sldProfiles",                      /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ht_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    115,                                /* lineNo */
    18,                                 /* colNo */
    "reflectivity",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo it_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    116,                                /* lineNo */
    16,                                 /* colNo */
    "Simulation",                       /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo jt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    117,                                /* lineNo */
    18,                                 /* colNo */
    "shifted_data",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo kt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    118,                                /* lineNo */
    15,                                 /* colNo */
    "layerSlds",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo lt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    119,                                /* lineNo */
    15,                                 /* colNo */
    "allLayers",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtDCInfo tc_emlrtDCI = {
    37,                                 /* lineNo */
    17,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    1                                                        /* checkKind */
};

static emlrtDCInfo uc_emlrtDCI = {
    36,                                 /* lineNo */
    16,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    1                                                        /* checkKind */
};

static emlrtDCInfo vc_emlrtDCI = {
    36,                                 /* lineNo */
    16,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    4                                                        /* checkKind */
};

static emlrtBCInfo mt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    45,                                 /* lineNo */
    36,                                 /* colNo */
    "layerSlds",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo nt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    45,                                 /* lineNo */
    36,                                 /* colNo */
    "sldProfiles",                      /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ot_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    45,                                 /* lineNo */
    36,                                 /* colNo */
    "shifted_data",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo pt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    45,                                 /* lineNo */
    36,                                 /* colNo */
    "reflectivity",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo qt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    45,                                 /* lineNo */
    36,                                 /* colNo */
    "Simulation",                       /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo rt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    68,                                 /* lineNo */
    1,                                  /* colNo */
    "tempAllLayers",                    /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo st_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    68,                                 /* lineNo */
    1,                                  /* colNo */
    "allLayers",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo tt_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    15,                         /* lineNo */
    6,                          /* colNo */
    "tempAllLayers",            /* aName */
    "loopMatalbCustlayWrapper", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "loopMatlabCustomLayers/loopMatalbCustlayWrapper.m", /* pName */
    0                                                    /* checkKind */
};

static emlrtBCInfo ut_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    34,                         /* lineNo */
    6,                          /* colNo */
    "allLayers",                /* aName */
    "loopMatalbCustlayWrapper", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "loopMatlabCustomLayers/loopMatalbCustlayWrapper.m", /* pName */
    0                                                    /* checkKind */
};

static emlrtBCInfo vt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    79,                                 /* lineNo */
    84,                                 /* colNo */
    "cBacks",                           /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo wt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    79,                                 /* lineNo */
    95,                                 /* colNo */
    "cShifts",                          /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo xt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    79,                                 /* lineNo */
    106,                                /* colNo */
    "cScales",                          /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo yt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    79,                                 /* lineNo */
    115,                                /* colNo */
    "cNbas",                            /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo au_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    79,                                 /* lineNo */
    124,                                /* colNo */
    "cNbss",                            /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo bu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    79,                                 /* lineNo */
    132,                                /* colNo */
    "cRes",                             /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo cu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    113,                                /* lineNo */
    14,                                 /* colNo */
    "outSsubs",                         /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo du_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    114,                                /* lineNo */
    5,                                  /* colNo */
    "sldProfiles",                      /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo eu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    115,                                /* lineNo */
    5,                                  /* colNo */
    "reflectivity",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo fu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    116,                                /* lineNo */
    5,                                  /* colNo */
    "Simulation",                       /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo gu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    117,                                /* lineNo */
    5,                                  /* colNo */
    "shifted_data",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo hu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    118,                                /* lineNo */
    5,                                  /* colNo */
    "layerSlds",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo iu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    119,                                /* lineNo */
    5,                                  /* colNo */
    "allLayers",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ju_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    121,                                /* lineNo */
    10,                                 /* colNo */
    "chis",                             /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ku_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    122,                                /* lineNo */
    12,                                 /* colNo */
    "backgs",                           /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo lu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    123,                                /* lineNo */
    13,                                 /* colNo */
    "qshifts",                          /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo mu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    124,                                /* lineNo */
    9,                                  /* colNo */
    "sfs",                              /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo nu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    125,                                /* lineNo */
    10,                                 /* colNo */
    "nbas",                             /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ou_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    126,                                /* lineNo */
    10,                                 /* colNo */
    "nbss",                             /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo pu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    127,                                /* lineNo */
    12,                                 /* colNo */
    "resols",                           /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo qu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    128,                                /* lineNo */
    15,                                 /* colNo */
    "allRoughs",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ru_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    14,                         /* lineNo */
    6,                          /* colNo */
    "allLayers",                /* aName */
    "loopMatalbCustlayWrapper", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "loopMatlabCustomLayers/loopMatalbCustlayWrapper.m", /* pName */
    0                                                    /* checkKind */
};

static emlrtBCInfo su_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    62,                                 /* lineNo */
    5,                                  /* colNo */
    "allLayers",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo tu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    57,                                 /* lineNo */
    5,                                  /* colNo */
    "Simulation",                       /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo uu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    52,                                 /* lineNo */
    5,                                  /* colNo */
    "reflectivity",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtRTEInfo lp_emlrtRTEI = {
    36,                                 /* lineNo */
    10,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo mp_emlrtRTEI = {
    3,                                  /* lineNo */
    18,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo np_emlrtRTEI = {
    45,                                 /* lineNo */
    36,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo op_emlrtRTEI = {
    52,                                 /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo pp_emlrtRTEI = {
    57,                                 /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo qp_emlrtRTEI = {
    68,                                 /* lineNo */
    1,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo rp_emlrtRTEI = {
    9,                          /* lineNo */
    41,                         /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "loopMatlabCustomLayers/loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtRTEInfo sp_emlrtRTEI = {
    14,                         /* lineNo */
    6,                          /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "loopMatlabCustomLayers/loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtRTEInfo tp_emlrtRTEI = {
    15,                         /* lineNo */
    6,                          /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "loopMatlabCustomLayers/loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtRTEInfo up_emlrtRTEI = {
    24,                         /* lineNo */
    57,                         /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "loopMatlabCustomLayers/loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtRTEInfo vp_emlrtRTEI = {
    34,                         /* lineNo */
    6,                          /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "loopMatlabCustomLayers/loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtRTEInfo wp_emlrtRTEI = {
    43,                                 /* lineNo */
    12,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo xp_emlrtRTEI = {
    114,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo yp_emlrtRTEI = {
    115,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo aq_emlrtRTEI = {
    116,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo bq_emlrtRTEI = {
    117,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo cq_emlrtRTEI = {
    118,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo dq_emlrtRTEI = {
    119,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo eq_emlrtRTEI = {
    90,                                 /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo fq_emlrtRTEI = {
    2,                                  /* lineNo */
    51,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_custLay/standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo gq_emlrtRTEI = {
    9,                          /* lineNo */
    2,                          /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "loopMatlabCustomLayers/loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtRSInfo hj_emlrtRSI = {
    23,                         /* lineNo */
    "loopMatalbCustlayWrapper", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "loopMatlabCustomLayers/loopMatalbCustlayWrapper.m" /* pathName */
};

static emlrtRSInfo tj_emlrtRSI = {
    38,                         /* lineNo */
    "loopMatalbCustlayWrapper", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "loopMatlabCustomLayers/loopMatalbCustlayWrapper.m" /* pathName */
};

/* Function Declarations */
static void b_feval(const emlrtStack *sp, const mxArray *m, const mxArray *m1,
                    const mxArray *m2, const mxArray *m3, const mxArray *m4,
                    const mxArray *m5, const mxArray *m6, const mxArray *m7,
                    const mxArray *m8, const mxArray *m9, const mxArray *m10,
                    const mxArray *m11, const mxArray *m12, const mxArray *m13,
                    const mxArray *m14, const mxArray *m15, const mxArray *m16,
                    emlrtMCInfo *location, const mxArray **r,
                    const mxArray **r1);

static void g_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *tempAllLayers,
                               const char_T *identifier,
                               emxArray_cell_wrap_28 *y);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_cell_wrap_28 *y);

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void j_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *tempAllRoughs,
                               const char_T *identifier, emxArray_real_T *y);

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void qb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret);

static void rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret);

/* Function Definitions */
static void b_feval(const emlrtStack *sp, const mxArray *m, const mxArray *m1,
                    const mxArray *m2, const mxArray *m3, const mxArray *m4,
                    const mxArray *m5, const mxArray *m6, const mxArray *m7,
                    const mxArray *m8, const mxArray *m9, const mxArray *m10,
                    const mxArray *m11, const mxArray *m12, const mxArray *m13,
                    const mxArray *m14, const mxArray *m15, const mxArray *m16,
                    emlrtMCInfo *location, const mxArray **r,
                    const mxArray **r1)
{
  const mxArray *pArrays[17];
  const mxArray *mv[2];
  pArrays[0] = m;
  pArrays[1] = m1;
  pArrays[2] = m2;
  pArrays[3] = m3;
  pArrays[4] = m4;
  pArrays[5] = m5;
  pArrays[6] = m6;
  pArrays[7] = m7;
  pArrays[8] = m8;
  pArrays[9] = m9;
  pArrays[10] = m10;
  pArrays[11] = m11;
  pArrays[12] = m12;
  pArrays[13] = m13;
  pArrays[14] = m14;
  pArrays[15] = m15;
  pArrays[16] = m16;
  emlrtAssign(r,
              emlrtCallMATLABR2012b((emlrtCTX)sp, 2, &mv[0], 17, &pArrays[0],
                                    (const char_T *)"feval", true, location));
  emlrtAssign(r1, mv[1]);
}

static void g_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *tempAllLayers,
                               const char_T *identifier,
                               emxArray_cell_wrap_28 *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(tempAllLayers), &thisId, y);
  emlrtDestroyArray(&tempAllLayers);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_cell_wrap_28 *y)
{
  cell_wrap_28 *y_data;
  emlrtMsgIdentifier thisId;
  int32_T n;
  int32_T sizes;
  char_T str[11];
  boolean_T b;
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  b = true;
  n = -1;
  emlrtCheckVsCell((emlrtCTX)sp, parentId, u, 1U, &n, &b, &sizes);
  n = y->size[0];
  y->size[0] = sizes;
  emxEnsureCapacity_cell_wrap_28(sp, y, n, (emlrtRTEInfo *)NULL);
  y_data = y->data;
  for (n = 0; n < sizes; n++) {
    sprintf(&str[0], "%d", n + 1);
    thisId.fIdentifier = &str[0];
    i_emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, n)),
                       &thisId, y_data[n].f1);
  }
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  qb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void j_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *tempAllRoughs,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  k_emlrt_marshallIn(sp, emlrtAlias(tempAllRoughs), &thisId, y);
  emlrtDestroyArray(&tempAllRoughs);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  rb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void qb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret)
{
  static const int32_T dims[2] = {10000, 5};
  real_T *ret_data;
  int32_T iv[2];
  int32_T i;
  const boolean_T bv[2] = {true, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret_data[0], 8, false);
  emlrtDestroyArray(&src);
}

static void rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret)
{
  static const int32_T dims = -1;
  real_T *ret_data;
  int32_T i;
  int32_T i1;
  const boolean_T b = true;
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 1U, (void *)&dims, &b, &i);
  i1 = ret->size[0];
  ret->size[0] = i;
  emxEnsureCapacity_real_T(sp, ret, i1, (emlrtRTEInfo *)NULL);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret_data[0], 8, false);
  emlrtDestroyArray(&src);
}

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
  static const int32_T iv[2] = {1, 22};
  static const char_T u[22] = {'l', 'o', 'o', 'p', 'M', 'a', 't', 'l',
                               'a', 'b', 'C', 'u', 's', 't', 'o', 'm',
                               'L', 'a', 'y', 'e', 'r', 's'};
  jmp_buf emlrtJBEnviron;
  jmp_buf *volatile emlrtJBStack;
  cell_wrap_10 *layerSlds_data;
  cell_wrap_14 *b_allLayers_data;
  cell_wrap_14 *shifted_data_data;
  cell_wrap_14 *sldProfiles_data;
  cell_wrap_27 *allLayers_data;
  cell_wrap_28 *tempAllLayers_data;
  cell_wrap_6 b_u[3];
  cell_wrap_9 *Simulation_data;
  cell_wrap_9 *reflectivity_data;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_cell_wrap_27 *b_allLayers;
  emxArray_cell_wrap_28 *b_tempAllLayers;
  emxArray_char_T *c_u;
  emxArray_real_T *Simul;
  emxArray_real_T *layerSld;
  emxArray_real_T *reflect;
  emxArray_real_T *resamLayers;
  emxArray_real_T *sldProfile;
  emxArray_real_T *thisData;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *m;
  const mxArray *tempAllLayers;
  const mxArray *tempAllRoughs;
  const mxArray *y;
  real_T calcSld;
  real_T thisBackground;
  real_T thisChiSquared;
  real_T thisNba;
  real_T thisNbs;
  real_T thisQshift;
  real_T thisResol;
  real_T thisSf;
  real_T thisSsubs;
  real_T *Simul_data;
  real_T *allRoughs_data;
  real_T *backgs_data;
  real_T *chis_data;
  real_T *layerSld_data;
  real_T *nbas_data;
  real_T *nbss_data;
  real_T *outSsubs_data;
  real_T *qshifts_data;
  real_T *reflect_data;
  real_T *resamLayers_data;
  real_T *resols_data;
  real_T *sfs_data;
  real_T *sldProfile_data;
  real_T *thisData_data;
  int32_T iv1[2];
  int32_T b_i;
  int32_T b_layerSlds;
  int32_T c_i;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T loop_ub;
  int32_T nParams;
  int32_T unnamed_idx_0_tmp_tmp;
  char_T *u_data;
  boolean_T emlrtHadParallelError = false;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /*  Multi threaded version of the custom layers over reflectivity contrasts */
  /*  for standardTF reflectivity calculation.  */
  /*  The function extracts the relevant parameters from the input */
  /*  arrays, allocates these on a pre-contrast basis, then calls the 'core'  */
  /*  calculation (the core layers standardTf calc is shared between multiple */
  /*  calculation types). */
  /*  This differs from the other two paralellisations in that the custom model
   */
  /*  files are processed in a paralell loop (using the Matlab Paralell */
  /*  Computing Toolbox) outside the main loop, before the main loop is then
   * processed */
  /*  in the compiled version using OpenMP. */
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
  /*  Pre-Allocation of output arrays... */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &vc_emlrtDCI,
                                (emlrtCTX)sp);
  }
  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &uc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &lp_emlrtRTEI);
  backgs_data = backgs->data;
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &tc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  unnamed_idx_0_tmp_tmp = (int32_T)problemDef->numberOfContrasts;
  i1 = layerSlds->size[0];
  layerSlds->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i1, &mp_emlrtRTEI);
  layerSlds_data = layerSlds->data;
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    b_layerSlds = layerSlds->size[0] - 1;
    if (i1 > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, layerSlds->size[0] - 1, &mt_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    layerSlds_data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &mt_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i2 = layerSlds_data[i1].f1->size[0] * layerSlds_data[i1].f1->size[1];
    layerSlds_data[i1].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds_data[i1].f1, i2, &mp_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i1 = sldProfiles->size[0];
  sldProfiles->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i1, &mp_emlrtRTEI);
  sldProfiles_data = sldProfiles->data;
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    b_layerSlds = sldProfiles->size[0] - 1;
    if (i1 > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, sldProfiles->size[0] - 1,
                                    &nt_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles_data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &nt_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sldProfiles_data[i1].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i1 = shifted_data->size[0];
  shifted_data->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i1, &mp_emlrtRTEI);
  shifted_data_data = shifted_data->data;
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    b_layerSlds = shifted_data->size[0] - 1;
    if (i1 > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, shifted_data->size[0] - 1,
                                    &ot_emlrtBCI, (emlrtCTX)sp);
    }
    shifted_data_data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &ot_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    shifted_data_data[i1].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i1 = reflectivity->size[0];
  reflectivity->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i1, &mp_emlrtRTEI);
  reflectivity_data = reflectivity->data;
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    b_layerSlds = reflectivity->size[0] - 1;
    if (i1 > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, reflectivity->size[0] - 1,
                                    &pt_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity_data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &pt_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i2 = reflectivity_data[i1].f1->size[0] * reflectivity_data[i1].f1->size[1];
    reflectivity_data[i1].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity_data[i1].f1, i2, &mp_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &vc_emlrtRTEI, (emlrtCTX)sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i1, &np_emlrtRTEI);
  reflectivity_data = reflectivity->data;
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &bt_emlrtBCI, (emlrtCTX)sp);
    }
    i1 =
        reflectivity_data[b_i].f1->size[0] * reflectivity_data[b_i].f1->size[1];
    reflectivity_data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity_data[b_i].f1, i1, &op_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &bt_emlrtBCI, (emlrtCTX)sp);
    }
    i1 =
        reflectivity_data[b_i].f1->size[0] * reflectivity_data[b_i].f1->size[1];
    reflectivity_data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity_data[b_i].f1, i1, &op_emlrtRTEI);
    i1 = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &bt_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity_data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &uu_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity_data[b_i].f1->data[1] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &uu_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity_data[b_i].f1->data[2] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &uu_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity_data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i1 = Simulation->size[0];
  Simulation->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i1, &mp_emlrtRTEI);
  Simulation_data = Simulation->data;
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    b_layerSlds = Simulation->size[0] - 1;
    if (i1 > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, Simulation->size[0] - 1,
                                    &qt_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation_data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &qt_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i2 = Simulation_data[i1].f1->size[0] * Simulation_data[i1].f1->size[1];
    Simulation_data[i1].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation_data[i1].f1, i2, &mp_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &wc_emlrtRTEI, (emlrtCTX)sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i1, &np_emlrtRTEI);
  Simulation_data = Simulation->data;
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &ct_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = Simulation_data[b_i].f1->size[0] * Simulation_data[b_i].f1->size[1];
    Simulation_data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation_data[b_i].f1, i1, &pp_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &ct_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = Simulation_data[b_i].f1->size[0] * Simulation_data[b_i].f1->size[1];
    Simulation_data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation_data[b_i].f1, i1, &pp_emlrtRTEI);
    i1 = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &ct_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation_data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &tu_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation_data[b_i].f1->data[1] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &tu_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation_data[b_i].f1->data[2] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &tu_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation_data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxInit_cell_wrap_27(sp, &b_allLayers, &fq_emlrtRTEI);
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &xc_emlrtRTEI, (emlrtCTX)sp);
  i1 = b_allLayers->size[0];
  b_allLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_27(sp, b_allLayers, i1, &np_emlrtRTEI);
  allLayers_data = b_allLayers->data;
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    b_layerSlds = b_allLayers->size[0] - 1;
    if (b_i > b_allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, b_allLayers->size[0] - 1,
                                    &su_emlrtBCI, (emlrtCTX)sp);
    }
    allLayers_data[b_i].f1[0] = 1.0;
    if (b_i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, b_layerSlds, &su_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers_data[b_i].f1[1] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_cell_wrap_27(sp, &b_allLayers);
  /*    --- End Memory Allocation --- */
  /*  Call the Matlab parallel loop to process the custom models..... */
  st.site = &yh_emlrtRSI;
  tempAllLayers = NULL;
  tempAllRoughs = NULL;
  /*  Wrapper function for calling 'loopMatlabCustomLayers'. This wrapper is */
  /*  necessary to deal with typedef problems for the coder if feval is used */
  /*  directly from the main function */
  if (unnamed_idx_0_tmp_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &rc_emlrtDCI, &st);
  }
  emxInit_cell_wrap_28(&st, &b_tempAllLayers, &gq_emlrtRTEI);
  i1 = b_tempAllLayers->size[0];
  b_tempAllLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_28(&st, b_tempAllLayers, i1, &qp_emlrtRTEI);
  tempAllLayers_data = b_tempAllLayers->data;
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    b_layerSlds = b_tempAllLayers->size[0] - 1;
    if (i1 > b_tempAllLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_tempAllLayers->size[0] - 1,
                                    &rt_emlrtBCI, &st);
    }
    tempAllLayers_data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &rt_emlrtBCI, &st);
    }
    tempAllLayers_data[i1].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  i1 = allLayers->size[0];
  allLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(&st, allLayers, i1, &qp_emlrtRTEI);
  b_allLayers_data = allLayers->data;
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    b_layerSlds = allLayers->size[0] - 1;
    if (i1 > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, allLayers->size[0] - 1, &st_emlrtBCI,
                                    &st);
    }
    b_allLayers_data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &st_emlrtBCI, &st);
    }
    b_allLayers_data[i1].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  if (unnamed_idx_0_tmp_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &sc_emlrtDCI, &st);
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &ad_emlrtRTEI, &st);
  i1 = allLayers->size[0];
  allLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(&st, allLayers, i1, &rp_emlrtRTEI);
  b_allLayers_data = allLayers->data;
  i1 = b_tempAllLayers->size[0];
  b_tempAllLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_28(&st, b_tempAllLayers, i1, &rp_emlrtRTEI);
  tempAllLayers_data = b_tempAllLayers->data;
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &dt_emlrtBCI, &st);
    }
    i1 = b_allLayers_data[b_i].f1->size[0] * b_allLayers_data[b_i].f1->size[1];
    b_allLayers_data[b_i].f1->size[0] = 1;
    emxEnsureCapacity_real_T(&st, b_allLayers_data[b_i].f1, i1, &sp_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &dt_emlrtBCI, &st);
    }
    i1 = b_allLayers_data[b_i].f1->size[0] * b_allLayers_data[b_i].f1->size[1];
    b_allLayers_data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(&st, b_allLayers_data[b_i].f1, i1, &sp_emlrtRTEI);
    i1 = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &dt_emlrtBCI, &st);
    }
    b_allLayers_data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &ru_emlrtBCI, &st);
    }
    b_allLayers_data[b_i].f1->data[1] = 1.0;
    /*  Type def as double (size not important) */
    if (b_i > b_tempAllLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, b_tempAllLayers->size[0] - 1,
                                    &et_emlrtBCI, &st);
    }
    i1 = tempAllLayers_data[b_i].f1->size[0] *
         tempAllLayers_data[b_i].f1->size[1];
    tempAllLayers_data[b_i].f1->size[0] = 1;
    emxEnsureCapacity_real_T(&st, tempAllLayers_data[b_i].f1, i1,
                             &tp_emlrtRTEI);
    if (b_i > b_tempAllLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, b_tempAllLayers->size[0] - 1,
                                    &et_emlrtBCI, &st);
    }
    i1 = tempAllLayers_data[b_i].f1->size[0] *
         tempAllLayers_data[b_i].f1->size[1];
    tempAllLayers_data[b_i].f1->size[1] = 5;
    emxEnsureCapacity_real_T(&st, tempAllLayers_data[b_i].f1, i1,
                             &tp_emlrtRTEI);
    i1 = b_tempAllLayers->size[0];
    if (b_i > b_tempAllLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, b_tempAllLayers->size[0] - 1,
                                    &et_emlrtBCI, &st);
    }
    for (i2 = 0; i2 < 5; i2++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &tt_emlrtBCI, &st);
      }
      tempAllLayers_data[b_i].f1->data[i2] = 0.0;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  /*  Call the Matlab parallel loop for the custom models..... */
  /*  We do this using feval, which automatically makes this function call */
  /*  only extrinsic... the loop is then handled in the matlab file (using  */
  /*  paralell computing toolbox) */
  y = NULL;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a(&st, 22, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = NULL;
  m = emlrtCreateDoubleScalar(problemDef->numberOfContrasts);
  emlrtAssign(&b_y, m);
  c_y = NULL;
  emlrtAssign(&c_y,
              emlrtCreateCellArrayR2014a(2, &problemDef_cells->f14->size[0]));
  i1 = 0;
  emxInitMatrix_cell_wrap_6(&st, b_u, &mp_emlrtRTEI, true);
  emxInit_char_T(&st, &c_u, &mp_emlrtRTEI, true);
  while (i1 < problemDef_cells->f14->size[1]) {
    emxCopyStruct_cell_wrap_6(
        &st, &b_u[0], &problemDef_cells->f14->data[i1].f1[0], &up_emlrtRTEI);
    emxCopyStruct_cell_wrap_6(
        &st, &b_u[1], &problemDef_cells->f14->data[i1].f1[1], &up_emlrtRTEI);
    emxCopyStruct_cell_wrap_6(
        &st, &b_u[2], &problemDef_cells->f14->data[i1].f1[2], &up_emlrtRTEI);
    d_y = NULL;
    iv1[0] = 1;
    iv1[1] = 3;
    emlrtAssign(&d_y, emlrtCreateCellArrayR2014a(2, &iv1[0]));
    iv1[0] = 1;
    for (i2 = 0; i2 < 3; i2++) {
      b_i = c_u->size[0] * c_u->size[1];
      c_u->size[0] = 1;
      c_u->size[1] = b_u[i2].f1->size[1];
      emxEnsureCapacity_char_T(&st, c_u, b_i, &up_emlrtRTEI);
      u_data = c_u->data;
      b_layerSlds = b_u[i2].f1->size[1];
      for (b_i = 0; b_i < b_layerSlds; b_i++) {
        u_data[b_i] = b_u[i2].f1->data[b_i];
      }
      e_y = NULL;
      iv1[1] = c_u->size[1];
      m = emlrtCreateCharArray(2, &iv1[0]);
      emlrtInitCharArrayR2013a(&st, c_u->size[1], m, &u_data[0]);
      emlrtAssign(&e_y, m);
      emlrtSetCell(d_y, i2, e_y);
    }
    emlrtSetCell(c_y, i1, d_y);
    i1++;
  }
  emxFree_char_T(&st, &c_u);
  emxFreeMatrix_cell_wrap_6(&st, b_u);
  b_st.site = &hj_emlrtRSI;
  b_feval(&b_st, y, emlrt_marshallOut(problemDef->contrastBacks),
          emlrt_marshallOut(problemDef->contrastShifts),
          emlrt_marshallOut(problemDef->contrastScales),
          emlrt_marshallOut(problemDef->contrastNbas),
          emlrt_marshallOut(problemDef->contrastNbss),
          emlrt_marshallOut(problemDef->contrastRes),
          emlrt_marshallOut(problemDef->backs),
          emlrt_marshallOut(problemDef->shifts),
          emlrt_marshallOut(problemDef->sf), emlrt_marshallOut(problemDef->nba),
          emlrt_marshallOut(problemDef->nbs),
          emlrt_marshallOut(problemDef->res),
          emlrt_marshallOut(problemDef->contrastCustomFiles), b_y, c_y,
          emlrt_marshallOut(problemDef->params), &c_emlrtMCI, &tempAllLayers,
          &tempAllRoughs);
  b_st.site = &hj_emlrtRSI;
  g_emlrt_marshallIn(&b_st, emlrtAlias(tempAllLayers), "tempAllLayers",
                     b_tempAllLayers);
  tempAllLayers_data = b_tempAllLayers->data;
  /*  All the following is intended to be casting from mxArray's to doubles. */
  /*  I'm not sure if all of this is necessary, but it compiles... */
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &bd_emlrtRTEI, &st);
  i1 = allLayers->size[0];
  allLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(&st, allLayers, i1, &rp_emlrtRTEI);
  b_allLayers_data = allLayers->data;
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > b_tempAllLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, b_tempAllLayers->size[0] - 1,
                                    &at_emlrtBCI, &st);
    }
    b_layerSlds = tempAllLayers_data[b_i].f1->size[0] *
                  tempAllLayers_data[b_i].f1->size[1];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &ft_emlrtBCI, &st);
    }
    i1 = b_allLayers_data[b_i].f1->size[0] * b_allLayers_data[b_i].f1->size[1];
    b_allLayers_data[b_i].f1->size[0] = tempAllLayers_data[b_i].f1->size[0];
    emxEnsureCapacity_real_T(&st, b_allLayers_data[b_i].f1, i1, &vp_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &ft_emlrtBCI, &st);
    }
    i1 = b_allLayers_data[b_i].f1->size[0] * b_allLayers_data[b_i].f1->size[1];
    b_allLayers_data[b_i].f1->size[1] = tempAllLayers_data[b_i].f1->size[1];
    emxEnsureCapacity_real_T(&st, b_allLayers_data[b_i].f1, i1, &vp_emlrtRTEI);
    i1 = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &ft_emlrtBCI, &st);
    }
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &ft_emlrtBCI, &st);
    }
    for (i2 = 0; i2 < b_layerSlds; i2++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &ut_emlrtBCI, &st);
      }
      b_allLayers_data[b_i].f1->data[i2] = tempAllLayers_data[b_i].f1->data[i2];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  emxFree_cell_wrap_28(&st, &b_tempAllLayers);
  /* allLayers = tempAllLayers; */
  b_st.site = &tj_emlrtRSI;
  j_emlrt_marshallIn(&b_st, emlrtAlias(tempAllRoughs), "tempAllRoughs",
                     allRoughs);
  allRoughs_data = allRoughs->data;
  emlrtDestroyArray(&tempAllLayers);
  emlrtDestroyArray(&tempAllRoughs);
  /*  Multi cored over all contrasts */
  if (unnamed_idx_0_tmp_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &qc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &yc_emlrtRTEI, (emlrtCTX)sp);
  i = outSsubs->size[0];
  outSsubs->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, outSsubs, i, &wp_emlrtRTEI);
  outSsubs_data = outSsubs->data;
  i = sldProfiles->size[0];
  sldProfiles->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &np_emlrtRTEI);
  sldProfiles_data = sldProfiles->data;
  i = reflectivity->size[0];
  reflectivity->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &np_emlrtRTEI);
  reflectivity_data = reflectivity->data;
  i = Simulation->size[0];
  Simulation->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &np_emlrtRTEI);
  Simulation_data = Simulation->data;
  i = shifted_data->size[0];
  shifted_data->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &np_emlrtRTEI);
  shifted_data_data = shifted_data->data;
  i = layerSlds->size[0];
  layerSlds->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &np_emlrtRTEI);
  layerSlds_data = layerSlds->data;
  i = chis->size[0];
  chis->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, chis, i, &wp_emlrtRTEI);
  chis_data = chis->data;
  i = qshifts->size[0];
  qshifts->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, qshifts, i, &wp_emlrtRTEI);
  qshifts_data = qshifts->data;
  i = sfs->size[0];
  sfs->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, sfs, i, &wp_emlrtRTEI);
  sfs_data = sfs->data;
  i = nbas->size[0];
  nbas->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, nbas, i, &wp_emlrtRTEI);
  nbas_data = nbas->data;
  i = nbss->size[0];
  nbss->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, nbss, i, &wp_emlrtRTEI);
  nbss_data = nbss->data;
  i = resols->size[0];
  resols->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, resols, i, &wp_emlrtRTEI);
  resols_data = resols->data;
  b_layerSlds = unnamed_idx_0_tmp_tmp - 1;
  emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
#pragma omp parallel num_threads(emlrtAllocRegionTLSs(                         \
    sp->tls, omp_in_parallel(), omp_get_max_threads(),                         \
    omp_get_num_procs())) private(thisData_data, sldProfile_data,              \
                                  reflect_data, Simul_data, layerSld_data,     \
                                  resamLayers_data, sldProfile, reflect,       \
                                  Simul, thisData, layerSld, resamLayers,      \
                                  thisSsubs, thisChiSquared, thisResol,        \
                                  thisNbs, thisNba, thisSf, thisQshift,        \
                                  thisBackground, emlrtJBEnviron, d_st,        \
                                  loop_ub, i3, i4)                             \
    firstprivate(c_st, emlrtHadParallelError)
  {
    if (setjmp(emlrtJBEnviron) == 0) {

      c_st.prev = sp;
      c_st.tls = emlrtAllocTLS((emlrtCTX)sp, omp_get_thread_num());
      c_st.site = NULL;
      emlrtSetJmpBuf(&c_st, &emlrtJBEnviron);
      d_st.prev = &c_st;
      d_st.tls = c_st.tls;
      emxInit_real_T(&c_st, &sldProfile, 2, &mp_emlrtRTEI, true);
      emxInit_real_T(&c_st, &reflect, 2, &mp_emlrtRTEI, true);
      emxInit_real_T(&c_st, &Simul, 2, &mp_emlrtRTEI, true);
      emxInit_real_T(&c_st, &thisData, 2, &eq_emlrtRTEI, true);
      emxInit_real_T(&c_st, &layerSld, 2, &mp_emlrtRTEI, true);
      emxInit_real_T(&c_st, &resamLayers, 2, &mp_emlrtRTEI, true);
    } else {
      emlrtHadParallelError = true;
    }
#pragma omp for nowait
    for (c_i = 0; c_i <= b_layerSlds; c_i++) {
      if (emlrtHadParallelError)
        continue;
      if (setjmp(emlrtJBEnviron) == 0) {

        /*  Extract the relevant parameter values for this contrast */
        /*  from the input arrays. */
        /*  First need to decide which values of the backrounds, scalefactors */
        /*  data shifts and bulk contrasts are associated with this contrast */
        if ((int32_T)(c_i + 1U) > problemDef->contrastBacks->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(c_i + 1U), 1,
                                        problemDef->contrastBacks->size[1],
                                        &vt_emlrtBCI, &c_st);
        }
        if ((int32_T)(c_i + 1U) > problemDef->contrastShifts->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(c_i + 1U), 1,
                                        problemDef->contrastShifts->size[1],
                                        &wt_emlrtBCI, &c_st);
        }
        if ((int32_T)(c_i + 1U) > problemDef->contrastScales->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(c_i + 1U), 1,
                                        problemDef->contrastScales->size[1],
                                        &xt_emlrtBCI, &c_st);
        }
        if ((int32_T)(c_i + 1U) > problemDef->contrastNbas->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(c_i + 1U), 1,
                                        problemDef->contrastNbas->size[1],
                                        &yt_emlrtBCI, &c_st);
        }
        if ((int32_T)(c_i + 1U) > problemDef->contrastNbss->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(c_i + 1U), 1,
                                        problemDef->contrastNbss->size[1],
                                        &au_emlrtBCI, &c_st);
        }
        if ((int32_T)(c_i + 1U) > problemDef->contrastRes->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(c_i + 1U), 1,
                                        problemDef->contrastRes->size[1],
                                        &bu_emlrtBCI, &c_st);
        }
        d_st.site = &ai_emlrtRSI;
        backSort(&d_st, problemDef->contrastBacks->data[c_i],
                 problemDef->contrastShifts->data[c_i],
                 problemDef->contrastScales->data[c_i],
                 problemDef->contrastNbas->data[c_i],
                 problemDef->contrastNbss->data[c_i],
                 problemDef->contrastRes->data[c_i], problemDef->backs,
                 problemDef->shifts, problemDef->sf, problemDef->nba,
                 problemDef->nbs, problemDef->res, &thisBackground, &thisQshift,
                 &thisSf, &thisNba, &thisNbs, &thisResol);
        /*  Get the custom layers output for this contrast */
        if (c_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, allLayers->size[0] - 1,
                                        &us_emlrtBCI, &c_st);
        }
        /*  For the other parameters, we extract the correct ones from the input
         */
        /*  arrays */
        if (c_i + 1 > allRoughs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, allRoughs->size[0],
                                        &qs_emlrtBCI, &c_st);
        }
        if (c_i > problemDef_cells->f1->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(
              c_i, 0, problemDef_cells->f1->size[1] - 1, &vs_emlrtBCI, &c_st);
        }
        if (c_i + 1 > problemDef->resample->size[1]) {
          emlrtDynamicBoundsCheckR2012b(
              c_i + 1, 1, problemDef->resample->size[1], &rs_emlrtBCI, &c_st);
        }
        if (c_i > problemDef_cells->f2->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(
              c_i, 0, problemDef_cells->f2->size[1] - 1, &ws_emlrtBCI, &c_st);
        }
        if (c_i + 1 > problemDef->dataPresent->size[1]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1,
                                        problemDef->dataPresent->size[1],
                                        &ss_emlrtBCI, &c_st);
        }
        if (c_i > problemDef_cells->f3->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(
              c_i, 0, problemDef_cells->f3->size[1] - 1, &xs_emlrtBCI, &c_st);
        }
        if (c_i > problemDef_cells->f4->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(
              c_i, 0, problemDef_cells->f4->size[1] - 1, &ys_emlrtBCI, &c_st);
        }
        if (c_i + 1 > problemDef->contrastBacksType->size[1]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1,
                                        problemDef->contrastBacksType->size[1],
                                        &ts_emlrtBCI, &c_st);
        }
        /*  Now call the core standardTF_stanlay reflectivity calculation */
        /*  In this case we are single cored, so we do not parallelise over */
        /*  points */
        /*  Call the reflectivity calculation */
        d_st.site = &bi_emlrtRSI;
        b_standardTF_layers_core(
            &d_st, b_allLayers_data[c_i].f1, allRoughs_data[c_i],
            problemDef->geometry, thisNba, thisNbs,
            problemDef->resample->data[c_i], calcSld, thisSf, thisQshift,
            problemDef->dataPresent->data[c_i],
            problemDef_cells->f2->data[c_i].f1,
            problemDef_cells->f3->data[c_i].f1,
            (real_T *)problemDef_cells->f4->data[c_i].f1->data,
            *(int32_T(*)[2])problemDef_cells->f4->data[c_i].f1->size,
            problemDef_cells->f1->data[c_i].f1, thisBackground, thisResol,
            problemDef->contrastBacksType->data[c_i], nParams,
            controls->resamPars, sldProfile, reflect, Simul, thisData, layerSld,
            resamLayers, &thisChiSquared, &thisSsubs);
        resamLayers_data = resamLayers->data;
        layerSld_data = layerSld->data;
        thisData_data = thisData->data;
        Simul_data = Simul->data;
        reflect_data = reflect->data;
        sldProfile_data = sldProfile->data;
        /*  Store returned values for this contrast in the output arrays. */
        /*  As well as the calculated profiles, we also store a record of  */
        /*  the other values (background, scalefactors etc) for each contrast */
        /*  for future use. */
        if (c_i + 1 > outSsubs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, outSsubs->size[0],
                                        &cu_emlrtBCI, &c_st);
        }
        outSsubs_data[c_i] = thisSsubs;
        loop_ub = sldProfile->size[0] * 2;
        if (c_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, sldProfiles->size[0] - 1,
                                        &gt_emlrtBCI, &c_st);
        }
        i3 = sldProfiles_data[c_i].f1->size[0] *
             sldProfiles_data[c_i].f1->size[1];
        sldProfiles_data[c_i].f1->size[0] = sldProfile->size[0];
        emxEnsureCapacity_real_T(&c_st, sldProfiles_data[c_i].f1, i3,
                                 &xp_emlrtRTEI);
        if (c_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, sldProfiles->size[0] - 1,
                                        &gt_emlrtBCI, &c_st);
        }
        i3 = sldProfiles_data[c_i].f1->size[0] *
             sldProfiles_data[c_i].f1->size[1];
        sldProfiles_data[c_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(&c_st, sldProfiles_data[c_i].f1, i3,
                                 &xp_emlrtRTEI);
        i3 = sldProfiles->size[0];
        if (c_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, sldProfiles->size[0] - 1,
                                        &gt_emlrtBCI, &c_st);
        }
        if (c_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, sldProfiles->size[0] - 1,
                                        &gt_emlrtBCI, &c_st);
        }
        for (i4 = 0; i4 < loop_ub; i4++) {
          if (c_i > i3 - 1) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3 - 1, &du_emlrtBCI, &c_st);
          }
          sldProfiles_data[c_i].f1->data[i4] = sldProfile_data[i4];
        }
        loop_ub = reflect->size[0] * 2;
        if (c_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, reflectivity->size[0] - 1,
                                        &ht_emlrtBCI, &c_st);
        }
        i3 = reflectivity_data[c_i].f1->size[0] *
             reflectivity_data[c_i].f1->size[1];
        reflectivity_data[c_i].f1->size[0] = reflect->size[0];
        emxEnsureCapacity_real_T(&c_st, reflectivity_data[c_i].f1, i3,
                                 &yp_emlrtRTEI);
        if (c_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, reflectivity->size[0] - 1,
                                        &ht_emlrtBCI, &c_st);
        }
        i3 = reflectivity_data[c_i].f1->size[0] *
             reflectivity_data[c_i].f1->size[1];
        reflectivity_data[c_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(&c_st, reflectivity_data[c_i].f1, i3,
                                 &yp_emlrtRTEI);
        i3 = reflectivity->size[0];
        if (c_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, reflectivity->size[0] - 1,
                                        &ht_emlrtBCI, &c_st);
        }
        if (c_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, reflectivity->size[0] - 1,
                                        &ht_emlrtBCI, &c_st);
        }
        for (i4 = 0; i4 < loop_ub; i4++) {
          if (c_i > i3 - 1) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3 - 1, &eu_emlrtBCI, &c_st);
          }
          reflectivity_data[c_i].f1->data[i4] = reflect_data[i4];
        }
        loop_ub = Simul->size[0] * 2;
        if (c_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, Simulation->size[0] - 1,
                                        &it_emlrtBCI, &c_st);
        }
        i3 =
            Simulation_data[c_i].f1->size[0] * Simulation_data[c_i].f1->size[1];
        Simulation_data[c_i].f1->size[0] = Simul->size[0];
        emxEnsureCapacity_real_T(&c_st, Simulation_data[c_i].f1, i3,
                                 &aq_emlrtRTEI);
        if (c_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, Simulation->size[0] - 1,
                                        &it_emlrtBCI, &c_st);
        }
        i3 =
            Simulation_data[c_i].f1->size[0] * Simulation_data[c_i].f1->size[1];
        Simulation_data[c_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(&c_st, Simulation_data[c_i].f1, i3,
                                 &aq_emlrtRTEI);
        i3 = Simulation->size[0];
        if (c_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, Simulation->size[0] - 1,
                                        &it_emlrtBCI, &c_st);
        }
        if (c_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, Simulation->size[0] - 1,
                                        &it_emlrtBCI, &c_st);
        }
        for (i4 = 0; i4 < loop_ub; i4++) {
          if (c_i > i3 - 1) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3 - 1, &fu_emlrtBCI, &c_st);
          }
          Simulation_data[c_i].f1->data[i4] = Simul_data[i4];
        }
        loop_ub = thisData->size[0] * thisData->size[1];
        if (c_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, shifted_data->size[0] - 1,
                                        &jt_emlrtBCI, &c_st);
        }
        i3 = shifted_data_data[c_i].f1->size[0] *
             shifted_data_data[c_i].f1->size[1];
        shifted_data_data[c_i].f1->size[0] = thisData->size[0];
        emxEnsureCapacity_real_T(&c_st, shifted_data_data[c_i].f1, i3,
                                 &bq_emlrtRTEI);
        if (c_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, shifted_data->size[0] - 1,
                                        &jt_emlrtBCI, &c_st);
        }
        i3 = shifted_data_data[c_i].f1->size[0] *
             shifted_data_data[c_i].f1->size[1];
        shifted_data_data[c_i].f1->size[1] = thisData->size[1];
        emxEnsureCapacity_real_T(&c_st, shifted_data_data[c_i].f1, i3,
                                 &bq_emlrtRTEI);
        i3 = shifted_data->size[0];
        if (c_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, shifted_data->size[0] - 1,
                                        &jt_emlrtBCI, &c_st);
        }
        if (c_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, shifted_data->size[0] - 1,
                                        &jt_emlrtBCI, &c_st);
        }
        for (i4 = 0; i4 < loop_ub; i4++) {
          if (c_i > i3 - 1) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3 - 1, &gu_emlrtBCI, &c_st);
          }
          shifted_data_data[c_i].f1->data[i4] = thisData_data[i4];
        }
        loop_ub = layerSld->size[0] * 3;
        if (c_i > layerSlds->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, layerSlds->size[0] - 1,
                                        &kt_emlrtBCI, &c_st);
        }
        i3 = layerSlds_data[c_i].f1->size[0] * layerSlds_data[c_i].f1->size[1];
        layerSlds_data[c_i].f1->size[0] = layerSld->size[0];
        emxEnsureCapacity_real_T(&c_st, layerSlds_data[c_i].f1, i3,
                                 &cq_emlrtRTEI);
        if (c_i > layerSlds->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, layerSlds->size[0] - 1,
                                        &kt_emlrtBCI, &c_st);
        }
        i3 = layerSlds_data[c_i].f1->size[0] * layerSlds_data[c_i].f1->size[1];
        layerSlds_data[c_i].f1->size[1] = 3;
        emxEnsureCapacity_real_T(&c_st, layerSlds_data[c_i].f1, i3,
                                 &cq_emlrtRTEI);
        i3 = layerSlds->size[0];
        if (c_i > layerSlds->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, layerSlds->size[0] - 1,
                                        &kt_emlrtBCI, &c_st);
        }
        if (c_i > layerSlds->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, layerSlds->size[0] - 1,
                                        &kt_emlrtBCI, &c_st);
        }
        for (i4 = 0; i4 < loop_ub; i4++) {
          if (c_i > i3 - 1) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3 - 1, &hu_emlrtBCI, &c_st);
          }
          layerSlds_data[c_i].f1->data[i4] = layerSld_data[i4];
        }
        loop_ub = resamLayers->size[0] * 3;
        if (c_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, allLayers->size[0] - 1,
                                        &lt_emlrtBCI, &c_st);
        }
        i3 = b_allLayers_data[c_i].f1->size[0] *
             b_allLayers_data[c_i].f1->size[1];
        b_allLayers_data[c_i].f1->size[0] = resamLayers->size[0];
        emxEnsureCapacity_real_T(&c_st, b_allLayers_data[c_i].f1, i3,
                                 &dq_emlrtRTEI);
        if (c_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, allLayers->size[0] - 1,
                                        &lt_emlrtBCI, &c_st);
        }
        i3 = b_allLayers_data[c_i].f1->size[0] *
             b_allLayers_data[c_i].f1->size[1];
        b_allLayers_data[c_i].f1->size[1] = 3;
        emxEnsureCapacity_real_T(&c_st, b_allLayers_data[c_i].f1, i3,
                                 &dq_emlrtRTEI);
        i3 = allLayers->size[0];
        if (c_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, allLayers->size[0] - 1,
                                        &lt_emlrtBCI, &c_st);
        }
        if (c_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, allLayers->size[0] - 1,
                                        &lt_emlrtBCI, &c_st);
        }
        for (i4 = 0; i4 < loop_ub; i4++) {
          if (c_i > i3 - 1) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3 - 1, &iu_emlrtBCI, &c_st);
          }
          b_allLayers_data[c_i].f1->data[i4] = resamLayers_data[i4];
        }
        if (c_i + 1 > chis->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, chis->size[0], &ju_emlrtBCI,
                                        &c_st);
        }
        chis_data[c_i] = thisChiSquared;
        if (c_i + 1 > backgs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, backgs->size[0],
                                        &ku_emlrtBCI, &c_st);
        }
        backgs_data[c_i] = thisBackground;
        if (c_i + 1 > qshifts->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, qshifts->size[0],
                                        &lu_emlrtBCI, &c_st);
        }
        qshifts_data[c_i] = thisQshift;
        if (c_i + 1 > sfs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, sfs->size[0], &mu_emlrtBCI,
                                        &c_st);
        }
        sfs_data[c_i] = thisSf;
        if (c_i + 1 > nbas->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, nbas->size[0], &nu_emlrtBCI,
                                        &c_st);
        }
        nbas_data[c_i] = thisNba;
        if (c_i + 1 > nbss->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, nbss->size[0], &ou_emlrtBCI,
                                        &c_st);
        }
        nbss_data[c_i] = thisNbs;
        if (c_i + 1 > resols->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, resols->size[0],
                                        &pu_emlrtBCI, &c_st);
        }
        resols_data[c_i] = thisResol;
        if (c_i + 1 > allRoughs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, allRoughs->size[0],
                                        &qu_emlrtBCI, &c_st);
        }
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&c_st);
        }
      } else {
        emlrtHadParallelError = true;
      }
    }
    if (!emlrtHadParallelError) {
      emlrtHeapReferenceStackLeaveScope(&c_st, 6);
      emxFree_real_T(&c_st, &resamLayers);
      emxFree_real_T(&c_st, &layerSld);
      emxFree_real_T(&c_st, &thisData);
      emxFree_real_T(&c_st, &Simul);
      emxFree_real_T(&c_st, &reflect);
      emxFree_real_T(&c_st, &sldProfile);
    }
  }
  emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (standardTF_custlay_paraContrasts.c) */
