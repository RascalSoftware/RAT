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
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_mexutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo fi_emlrtRSI = {
    76,                                 /* lineNo */
    "standardTF_custlay_paraContrasts", /* fcnName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m" /* pathName */
};

static emlrtRSInfo gi_emlrtRSI = {
    91,                                 /* lineNo */
    "standardTF_custlay_paraContrasts", /* fcnName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m" /* pathName */
};

static emlrtRSInfo hi_emlrtRSI = {
    114,                                /* lineNo */
    "standardTF_custlay_paraContrasts", /* fcnName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m" /* pathName */
};

static emlrtMCInfo c_emlrtMCI = {
    23,                         /* lineNo */
    2,                          /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\loop"
    "MatlabCustomLayers\\loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtDCInfo qc_emlrtDCI = {
    45,                                 /* lineNo */
    18,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    1 /* checkKind */
};

static emlrtRTEInfo uc_emlrtRTEI = {
    51,                                 /* lineNo */
    9,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo vc_emlrtRTEI = {
    56,                                 /* lineNo */
    9,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = {
    61,                                 /* lineNo */
    9,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtDCInfo rc_emlrtDCI = {
    86,                                 /* lineNo */
    14,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    1 /* checkKind */
};

static emlrtRTEInfo xc_emlrtRTEI = {
    86,                                 /* lineNo */
    12,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtBCInfo ws_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    98,                                 /* lineNo */
    27,                                 /* colNo */
    "allRoughs",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo xs_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    100,                                /* lineNo */
    29,                                 /* colNo */
    "resample",                         /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ys_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    103,                                /* lineNo */
    35,                                 /* colNo */
    "dataPresent",                      /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo at_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    106,                                /* lineNo */
    31,                                 /* colNo */
    "backsType",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo bt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    72,                                 /* lineNo */
    20,                                 /* colNo */
    "customFiles",                      /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ct_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    94,                                 /* lineNo */
    36,                                 /* colNo */
    "allLayers",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo dt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    99,                                 /* lineNo */
    37,                                 /* colNo */
    "repeatLayers",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo et_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    102,                                /* lineNo */
    24,                                 /* colNo */
    "allData",                          /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ft_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    104,                                /* lineNo */
    33,                                 /* colNo */
    "dataLimits",                       /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo gt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    105,                                /* lineNo */
    31,                                 /* colNo */
    "simLimits",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtDCInfo sc_emlrtDCI = {
    9,                          /* lineNo */
    23,                         /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\loop"
    "MatlabCustomLayers\\loopMatalbCustlayWrapper.m", /* pName */
    1                                                 /* checkKind */
};

static emlrtDCInfo tc_emlrtDCI = {
    11,                         /* lineNo */
    20,                         /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\loop"
    "MatlabCustomLayers\\loopMatalbCustlayWrapper.m", /* pName */
    1                                                 /* checkKind */
};

static emlrtRTEInfo yc_emlrtRTEI = {
    13,                         /* lineNo */
    10,                         /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\loop"
    "MatlabCustomLayers\\loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = {
    28,                         /* lineNo */
    10,                         /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\loop"
    "MatlabCustomLayers\\loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtBCInfo ht_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    29,                         /* lineNo */
    30,                         /* colNo */
    "tempAllLayers",            /* aName */
    "loopMatalbCustlayWrapper", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\loop"
    "MatlabCustomLayers\\loopMatalbCustlayWrapper.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo it_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    52,                                 /* lineNo */
    18,                                 /* colNo */
    "reflectivity",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo jt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    57,                                 /* lineNo */
    16,                                 /* colNo */
    "Simulation",                       /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo kt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    62,                                 /* lineNo */
    15,                                 /* colNo */
    "allLayers",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo lt_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    14,                         /* lineNo */
    16,                         /* colNo */
    "allLayers",                /* aName */
    "loopMatalbCustlayWrapper", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\loop"
    "MatlabCustomLayers\\loopMatalbCustlayWrapper.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo mt_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    15,                         /* lineNo */
    20,                         /* colNo */
    "tempAllLayers",            /* aName */
    "loopMatalbCustlayWrapper", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\loop"
    "MatlabCustomLayers\\loopMatalbCustlayWrapper.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo nt_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    34,                         /* lineNo */
    16,                         /* colNo */
    "allLayers",                /* aName */
    "loopMatalbCustlayWrapper", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\loop"
    "MatlabCustomLayers\\loopMatalbCustlayWrapper.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo ot_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    126,                                /* lineNo */
    17,                                 /* colNo */
    "sldProfiles",                      /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo pt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    127,                                /* lineNo */
    18,                                 /* colNo */
    "reflectivity",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo qt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    128,                                /* lineNo */
    16,                                 /* colNo */
    "Simulation",                       /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo rt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    129,                                /* lineNo */
    18,                                 /* colNo */
    "shifted_data",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo st_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    130,                                /* lineNo */
    15,                                 /* colNo */
    "layerSlds",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo tt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    131,                                /* lineNo */
    15,                                 /* colNo */
    "allLayers",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtDCInfo uc_emlrtDCI = {
    37,                                 /* lineNo */
    17,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    1 /* checkKind */
};

static emlrtDCInfo vc_emlrtDCI = {
    36,                                 /* lineNo */
    16,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    1 /* checkKind */
};

static emlrtDCInfo wc_emlrtDCI = {
    36,                                 /* lineNo */
    16,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    4 /* checkKind */
};

static emlrtDCInfo xc_emlrtDCI = {
    42,                                 /* lineNo */
    1,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    1 /* checkKind */
};

static emlrtBCInfo ut_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    45,                                 /* lineNo */
    36,                                 /* colNo */
    "layerSlds",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo vt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    45,                                 /* lineNo */
    36,                                 /* colNo */
    "sldProfiles",                      /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo wt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    45,                                 /* lineNo */
    36,                                 /* colNo */
    "shifted_data",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo xt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    45,                                 /* lineNo */
    36,                                 /* colNo */
    "reflectivity",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo yt_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    45,                                 /* lineNo */
    36,                                 /* colNo */
    "Simulation",                       /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo au_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    45,                                 /* lineNo */
    36,                                 /* colNo */
    "allLayers",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo bu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    76,                                 /* lineNo */
    5,                                  /* colNo */
    "tempAllLayers",                    /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo cu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    76,                                 /* lineNo */
    5,                                  /* colNo */
    "allLayers",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo du_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    15,                         /* lineNo */
    6,                          /* colNo */
    "tempAllLayers",            /* aName */
    "loopMatalbCustlayWrapper", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\loop"
    "MatlabCustomLayers\\loopMatalbCustlayWrapper.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo eu_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    34,                         /* lineNo */
    6,                          /* colNo */
    "allLayers",                /* aName */
    "loopMatalbCustlayWrapper", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\loop"
    "MatlabCustomLayers\\loopMatalbCustlayWrapper.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo fu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    91,                                 /* lineNo */
    77,                                 /* colNo */
    "cBacks",                           /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo gu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    91,                                 /* lineNo */
    87,                                 /* colNo */
    "cShifts",                          /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo hu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    91,                                 /* lineNo */
    98,                                 /* colNo */
    "cScales",                          /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo iu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    91,                                 /* lineNo */
    109,                                /* colNo */
    "cNbas",                            /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ju_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    91,                                 /* lineNo */
    118,                                /* colNo */
    "cNbss",                            /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ku_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    91,                                 /* lineNo */
    127,                                /* colNo */
    "cRes",                             /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo lu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    125,                                /* lineNo */
    5,                                  /* colNo */
    "outSsubs",                         /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo mu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    126,                                /* lineNo */
    5,                                  /* colNo */
    "sldProfiles",                      /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo nu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    127,                                /* lineNo */
    5,                                  /* colNo */
    "reflectivity",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ou_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    128,                                /* lineNo */
    5,                                  /* colNo */
    "Simulation",                       /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo pu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    129,                                /* lineNo */
    5,                                  /* colNo */
    "shifted_data",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo qu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    130,                                /* lineNo */
    5,                                  /* colNo */
    "layerSlds",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ru_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    131,                                /* lineNo */
    5,                                  /* colNo */
    "allLayers",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo su_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    133,                                /* lineNo */
    5,                                  /* colNo */
    "chis",                             /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo tu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    134,                                /* lineNo */
    5,                                  /* colNo */
    "backgs",                           /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo uu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    135,                                /* lineNo */
    5,                                  /* colNo */
    "qshifts",                          /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo vu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    136,                                /* lineNo */
    5,                                  /* colNo */
    "sfs",                              /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo wu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    137,                                /* lineNo */
    5,                                  /* colNo */
    "nbas",                             /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo xu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    138,                                /* lineNo */
    5,                                  /* colNo */
    "nbss",                             /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo yu_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    139,                                /* lineNo */
    5,                                  /* colNo */
    "resols",                           /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo av_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    140,                                /* lineNo */
    5,                                  /* colNo */
    "allRoughs",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo bv_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    14,                         /* lineNo */
    6,                          /* colNo */
    "allLayers",                /* aName */
    "loopMatalbCustlayWrapper", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\loop"
    "MatlabCustomLayers\\loopMatalbCustlayWrapper.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo cv_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    62,                                 /* lineNo */
    5,                                  /* colNo */
    "allLayers",                        /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo dv_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    57,                                 /* lineNo */
    5,                                  /* colNo */
    "Simulation",                       /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ev_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    52,                                 /* lineNo */
    5,                                  /* colNo */
    "reflectivity",                     /* aName */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m", /* pName */
    0 /* checkKind */
};

static emlrtRTEInfo jp_emlrtRTEI = {
    36,                                 /* lineNo */
    10,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo kp_emlrtRTEI = {
    42,                                 /* lineNo */
    1,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo lp_emlrtRTEI = {
    3,                                  /* lineNo */
    18,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo mp_emlrtRTEI = {
    45,                                 /* lineNo */
    36,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo np_emlrtRTEI = {
    52,                                 /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo op_emlrtRTEI = {
    57,                                 /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo pp_emlrtRTEI = {
    62,                                 /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo qp_emlrtRTEI = {
    43,                                 /* lineNo */
    12,                                 /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo rp_emlrtRTEI = {
    76,                                 /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo sp_emlrtRTEI = {
    9,                          /* lineNo */
    41,                         /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\loop"
    "MatlabCustomLayers\\loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtRTEInfo tp_emlrtRTEI = {
    14,                         /* lineNo */
    6,                          /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\loop"
    "MatlabCustomLayers\\loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtRTEInfo up_emlrtRTEI = {
    15,                         /* lineNo */
    6,                          /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\loop"
    "MatlabCustomLayers\\loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtRTEInfo vp_emlrtRTEI = {
    24,                         /* lineNo */
    57,                         /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\loop"
    "MatlabCustomLayers\\loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtRTEInfo wp_emlrtRTEI = {
    34,                         /* lineNo */
    6,                          /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\loop"
    "MatlabCustomLayers\\loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtRTEInfo xp_emlrtRTEI = {
    126,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo yp_emlrtRTEI = {
    127,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo aq_emlrtRTEI = {
    128,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo bq_emlrtRTEI = {
    129,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo cq_emlrtRTEI = {
    130,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo dq_emlrtRTEI = {
    131,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo eq_emlrtRTEI = {
    102,                                /* lineNo */
    5,                                  /* colNo */
    "standardTF_custlay_paraContrasts", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo fq_emlrtRTEI = {
    9,                          /* lineNo */
    2,                          /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\loop"
    "MatlabCustomLayers\\loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtRSInfo nj_emlrtRSI = {
    23,                         /* lineNo */
    "loopMatalbCustlayWrapper", /* fcnName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\loop"
    "MatlabCustomLayers\\loopMatalbCustlayWrapper.m" /* pathName */
};

static emlrtRSInfo qj_emlrtRSI = {
    38,                         /* lineNo */
    "loopMatalbCustlayWrapper", /* fcnName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\loop"
    "MatlabCustomLayers\\loopMatalbCustlayWrapper.m" /* pathName */
};

/* Function Declarations */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    const mxArray *d, const mxArray *e, const mxArray *f,
                    const mxArray *g, const mxArray *h, const mxArray *i,
                    const mxArray *j, const mxArray *k, const mxArray *l,
                    const mxArray *m, const mxArray *n, const mxArray *o,
                    const mxArray *p, const mxArray *q, const mxArray *r,
                    emlrtMCInfo *location, const mxArray **s,
                    const mxArray **t);

static void g_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *tempAllLayers,
                               const char_T *identifier,
                               emxArray_cell_wrap_25 *y);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_cell_wrap_25 *y);

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
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    const mxArray *d, const mxArray *e, const mxArray *f,
                    const mxArray *g, const mxArray *h, const mxArray *i,
                    const mxArray *j, const mxArray *k, const mxArray *l,
                    const mxArray *m, const mxArray *n, const mxArray *o,
                    const mxArray *p, const mxArray *q, const mxArray *r,
                    emlrtMCInfo *location, const mxArray **s, const mxArray **t)
{
  const mxArray *pArrays[17];
  const mxArray *mv[2];
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  pArrays[4] = f;
  pArrays[5] = g;
  pArrays[6] = h;
  pArrays[7] = i;
  pArrays[8] = j;
  pArrays[9] = k;
  pArrays[10] = l;
  pArrays[11] = m;
  pArrays[12] = n;
  pArrays[13] = o;
  pArrays[14] = p;
  pArrays[15] = q;
  pArrays[16] = r;
  emlrtAssign(s,
              emlrtCallMATLABR2012b((emlrtCTX)sp, 2, &mv[0], 17, &pArrays[0],
                                    (const char_T *)"feval", true, location));
  emlrtAssign(t, mv[1]);
}

static void g_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *tempAllLayers,
                               const char_T *identifier,
                               emxArray_cell_wrap_25 *y)
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
                               emxArray_cell_wrap_25 *y)
{
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
  emxEnsureCapacity_cell_wrap_25(sp, y, n, (emlrtRTEInfo *)NULL);
  for (n = 0; n < sizes; n++) {
    sprintf(&str[0], "%d", n + 1);
    thisId.fIdentifier = &str[0];
    i_emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, n)),
                       &thisId, y->data[n].f1);
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
  int32_T iv[2];
  int32_T i;
  const boolean_T bv[2] = {true, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret->data[0], 8, false);
  emlrtDestroyArray(&src);
}

static void rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret)
{
  static const int32_T dims = -1;
  int32_T i;
  int32_T i1;
  const boolean_T b = true;
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 1U, (void *)&dims, &b, &i);
  i1 = ret->size[0];
  ret->size[0] = i;
  emxEnsureCapacity_real_T(sp, ret, i1, (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret->data[0], 8, false);
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
  static const char_T b_cv[6] = {'m', 'a', 't', 'l', 'a', 'b'};
  jmp_buf emlrtJBEnviron;
  jmp_buf *volatile emlrtJBStack;
  cell_wrap_6 b_u[3];
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_cell_wrap_25 *b_tempAllLayers;
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
  int32_T iv1[2];
  int32_T b_i;
  int32_T b_layerSlds;
  int32_T c_i;
  int32_T exitg1;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  int32_T nParams;
  boolean_T b_bool;
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
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &wc_emlrtDCI,
                                (emlrtCTX)sp);
  }
  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &vc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &jp_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &uc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  loop_ub_tmp = (int32_T)problemDef->numberOfContrasts;
  i1 = allRoughs->size[0];
  allRoughs->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, allRoughs, i1, &kp_emlrtRTEI);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &xc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    allRoughs->data[i1] = 0.0;
  }
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &qc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = layerSlds->size[0];
  layerSlds->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i1, &lp_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    b_layerSlds = layerSlds->size[0] - 1;
    if (i1 > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, layerSlds->size[0] - 1, &ut_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    layerSlds->data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &ut_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i2 = layerSlds->data[i1].f1->size[0] * layerSlds->data[i1].f1->size[1];
    layerSlds->data[i1].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[i1].f1, i2, &lp_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i1 = sldProfiles->size[0];
  sldProfiles->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i1, &lp_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    b_layerSlds = sldProfiles->size[0] - 1;
    if (i1 > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, sldProfiles->size[0] - 1,
                                    &vt_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &vt_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sldProfiles->data[i1].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i1 = shifted_data->size[0];
  shifted_data->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i1, &lp_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    b_layerSlds = shifted_data->size[0] - 1;
    if (i1 > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, shifted_data->size[0] - 1,
                                    &wt_emlrtBCI, (emlrtCTX)sp);
    }
    shifted_data->data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &wt_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    shifted_data->data[i1].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i1 = reflectivity->size[0];
  reflectivity->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i1, &lp_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    b_layerSlds = reflectivity->size[0] - 1;
    if (i1 > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, reflectivity->size[0] - 1,
                                    &xt_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &xt_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i2 =
        reflectivity->data[i1].f1->size[0] * reflectivity->data[i1].f1->size[1];
    reflectivity->data[i1].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[i1].f1, i2, &lp_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &uc_emlrtRTEI, (emlrtCTX)sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i1, &mp_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &it_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = reflectivity->data[b_i].f1->size[0] *
         reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &np_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &it_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = reflectivity->data[b_i].f1->size[0] *
         reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &np_emlrtRTEI);
    i1 = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &it_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &ev_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &ev_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &ev_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i1 = Simulation->size[0];
  Simulation->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i1, &lp_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    b_layerSlds = Simulation->size[0] - 1;
    if (i1 > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, Simulation->size[0] - 1,
                                    &yt_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &yt_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i2 = Simulation->data[i1].f1->size[0] * Simulation->data[i1].f1->size[1];
    Simulation->data[i1].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[i1].f1, i2, &lp_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &vc_emlrtRTEI, (emlrtCTX)sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i1, &mp_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &jt_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &op_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &jt_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &op_emlrtRTEI);
    i1 = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &jt_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &dv_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &dv_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &dv_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i1 = allLayers->size[0];
  allLayers->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i1, &lp_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    b_layerSlds = allLayers->size[0] - 1;
    if (i1 > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, allLayers->size[0] - 1, &au_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[i1].f1->size[0] = 0;
    if (i1 > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &au_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[i1].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &wc_emlrtRTEI, (emlrtCTX)sp);
  i1 = allLayers->size[0];
  allLayers->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i1, &mp_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &kt_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &pp_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &kt_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &pp_emlrtRTEI);
    i1 = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &kt_emlrtBCI, (emlrtCTX)sp);
    }
    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &cv_emlrtBCI, (emlrtCTX)sp);
    }
    allLayers->data[b_i].f1->data[1] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  /*    --- End Memory Allocation --- */
  /*  Depending on custom layer language we change the functions used */
  if (0 > problemDef_cells->f14->size[1] - 1) {
    emlrtDynamicBoundsCheckR2012b(0, 0, problemDef_cells->f14->size[1] - 1,
                                  &bt_emlrtBCI, (emlrtCTX)sp);
  }
  /*  so if there are multiple language models we should have a variable that
   * seeks what language model is being used */
  b_bool = false;
  if (problemDef_cells->f14->data[0].f1[1].f1->size[1] == 6) {
    b_layerSlds = 0;
    do {
      exitg1 = 0;
      if (b_layerSlds < 6) {
        if (problemDef_cells->f14->data[0].f1[1].f1->data[b_layerSlds] !=
            b_cv[b_layerSlds]) {
          exitg1 = 1;
        } else {
          b_layerSlds++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (b_bool) {
    b_layerSlds = 0;
  } else {
    b_layerSlds = -1;
  }
  switch (b_layerSlds) {
  case 0:
    /*  Call the Matlab parallel loop to process the custom models..... */
    st.site = &fi_emlrtRSI;
    tempAllLayers = NULL;
    tempAllRoughs = NULL;
    /*  Wrapper function for calling 'loopMatlabCustomLayers'. This wrapper is
     */
    /*  necessary to deal with typedef problems for the coder if feval is used
     */
    /*  directly from the main function */
    if (loop_ub_tmp != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &sc_emlrtDCI, &st);
    }
    emxInit_cell_wrap_25(&st, &b_tempAllLayers, 1, &fq_emlrtRTEI, true);
    i1 = b_tempAllLayers->size[0];
    b_tempAllLayers->size[0] = loop_ub_tmp;
    emxEnsureCapacity_cell_wrap_25(&st, b_tempAllLayers, i1, &rp_emlrtRTEI);
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      b_layerSlds = b_tempAllLayers->size[0] - 1;
      if (i1 > b_tempAllLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i1, 0, b_tempAllLayers->size[0] - 1,
                                      &bu_emlrtBCI, &st);
      }
      b_tempAllLayers->data[i1].f1->size[0] = 0;
      if (i1 > b_layerSlds) {
        emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &bu_emlrtBCI, &st);
      }
      b_tempAllLayers->data[i1].f1->size[1] = 0;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    i1 = allLayers->size[0];
    allLayers->size[0] = loop_ub_tmp;
    emxEnsureCapacity_cell_wrap_14(&st, allLayers, i1, &rp_emlrtRTEI);
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      b_layerSlds = allLayers->size[0] - 1;
      if (i1 > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i1, 0, allLayers->size[0] - 1,
                                      &cu_emlrtBCI, &st);
      }
      allLayers->data[i1].f1->size[0] = 0;
      if (i1 > b_layerSlds) {
        emlrtDynamicBoundsCheckR2012b(i1, 0, b_layerSlds, &cu_emlrtBCI, &st);
      }
      allLayers->data[i1].f1->size[1] = 0;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    if (loop_ub_tmp != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &tc_emlrtDCI, &st);
    }
    emlrtForLoopVectorCheckR2021a(
        1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
        (int32_T)problemDef->numberOfContrasts, &yc_emlrtRTEI, &st);
    i1 = allLayers->size[0];
    allLayers->size[0] = loop_ub_tmp;
    emxEnsureCapacity_cell_wrap_14(&st, allLayers, i1, &sp_emlrtRTEI);
    i1 = b_tempAllLayers->size[0];
    b_tempAllLayers->size[0] = loop_ub_tmp;
    emxEnsureCapacity_cell_wrap_25(&st, b_tempAllLayers, i1, &sp_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                      &lt_emlrtBCI, &st);
      }
      i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
      allLayers->data[b_i].f1->size[0] = 1;
      emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i1, &tp_emlrtRTEI);
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                      &lt_emlrtBCI, &st);
      }
      i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
      allLayers->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i1, &tp_emlrtRTEI);
      i1 = allLayers->size[0];
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                      &lt_emlrtBCI, &st);
      }
      allLayers->data[b_i].f1->data[0] = 1.0;
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &bv_emlrtBCI, &st);
      }
      allLayers->data[b_i].f1->data[1] = 1.0;
      /*  Type def as double (size not important) */
      if (b_i > b_tempAllLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_tempAllLayers->size[0] - 1,
                                      &mt_emlrtBCI, &st);
      }
      i1 = b_tempAllLayers->data[b_i].f1->size[0] *
           b_tempAllLayers->data[b_i].f1->size[1];
      b_tempAllLayers->data[b_i].f1->size[0] = 1;
      emxEnsureCapacity_real_T(&st, b_tempAllLayers->data[b_i].f1, i1,
                               &up_emlrtRTEI);
      if (b_i > b_tempAllLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_tempAllLayers->size[0] - 1,
                                      &mt_emlrtBCI, &st);
      }
      i1 = b_tempAllLayers->data[b_i].f1->size[0] *
           b_tempAllLayers->data[b_i].f1->size[1];
      b_tempAllLayers->data[b_i].f1->size[1] = 5;
      emxEnsureCapacity_real_T(&st, b_tempAllLayers->data[b_i].f1, i1,
                               &up_emlrtRTEI);
      i1 = b_tempAllLayers->size[0];
      if (b_i > b_tempAllLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_tempAllLayers->size[0] - 1,
                                      &mt_emlrtBCI, &st);
      }
      for (i2 = 0; i2 < 5; i2++) {
        if (b_i > i1 - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &du_emlrtBCI, &st);
        }
        b_tempAllLayers->data[b_i].f1->data[i2] = 0.0;
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
    emxInitMatrix_cell_wrap_6(&st, b_u, &lp_emlrtRTEI, true);
    emxInit_char_T(&st, &c_u, 2, &lp_emlrtRTEI, true);
    while (i1 < problemDef_cells->f14->size[1]) {
      emxCopyStruct_cell_wrap_6(
          &st, &b_u[0], &problemDef_cells->f14->data[i1].f1[0], &vp_emlrtRTEI);
      emxCopyStruct_cell_wrap_6(
          &st, &b_u[1], &problemDef_cells->f14->data[i1].f1[1], &vp_emlrtRTEI);
      emxCopyStruct_cell_wrap_6(
          &st, &b_u[2], &problemDef_cells->f14->data[i1].f1[2], &vp_emlrtRTEI);
      d_y = NULL;
      iv1[0] = 1;
      iv1[1] = 3;
      emlrtAssign(&d_y, emlrtCreateCellArrayR2014a(2, &iv1[0]));
      iv1[0] = 1;
      for (i2 = 0; i2 < 3; i2++) {
        b_i = c_u->size[0] * c_u->size[1];
        c_u->size[0] = 1;
        c_u->size[1] = b_u[i2].f1->size[1];
        emxEnsureCapacity_char_T(&st, c_u, b_i, &vp_emlrtRTEI);
        b_layerSlds = b_u[i2].f1->size[1];
        for (b_i = 0; b_i < b_layerSlds; b_i++) {
          c_u->data[b_i] = b_u[i2].f1->data[b_i];
        }
        e_y = NULL;
        iv1[1] = c_u->size[1];
        m = emlrtCreateCharArray(2, &iv1[0]);
        emlrtInitCharArrayR2013a(&st, c_u->size[1], m, &c_u->data[0]);
        emlrtAssign(&e_y, m);
        emlrtSetCell(d_y, i2, e_y);
      }
      emlrtSetCell(c_y, i1, d_y);
      i1++;
    }
    emxFree_char_T(&c_u);
    emxFreeMatrix_cell_wrap_6(b_u);
    b_st.site = &nj_emlrtRSI;
    b_feval(
        &b_st, y, emlrt_marshallOut(problemDef->contrastBacks),
        emlrt_marshallOut(problemDef->contrastShifts),
        emlrt_marshallOut(problemDef->contrastScales),
        emlrt_marshallOut(problemDef->contrastNbas),
        emlrt_marshallOut(problemDef->contrastNbss),
        emlrt_marshallOut(problemDef->contrastRes),
        emlrt_marshallOut(problemDef->backs),
        emlrt_marshallOut(problemDef->shifts),
        emlrt_marshallOut(problemDef->sf), emlrt_marshallOut(problemDef->nba),
        emlrt_marshallOut(problemDef->nbs), emlrt_marshallOut(problemDef->res),
        emlrt_marshallOut(problemDef->contrastCustomFiles), b_y, c_y,
        emlrt_marshallOut(problemDef->params), &c_emlrtMCI, &tempAllLayers,
        &tempAllRoughs);
    b_st.site = &nj_emlrtRSI;
    g_emlrt_marshallIn(&b_st, emlrtAlias(tempAllLayers), "tempAllLayers",
                       b_tempAllLayers);
    /*  All the following is intended to be casting from mxArray's to doubles.
     */
    /*  I'm not sure if all of this is necessary, but it compiles... */
    emlrtForLoopVectorCheckR2021a(
        1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
        (int32_T)problemDef->numberOfContrasts, &ad_emlrtRTEI, &st);
    i1 = allLayers->size[0];
    allLayers->size[0] = loop_ub_tmp;
    emxEnsureCapacity_cell_wrap_14(&st, allLayers, i1, &sp_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
      if (b_i > b_tempAllLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_tempAllLayers->size[0] - 1,
                                      &ht_emlrtBCI, &st);
      }
      b_layerSlds = b_tempAllLayers->data[b_i].f1->size[0] *
                    b_tempAllLayers->data[b_i].f1->size[1];
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                      &nt_emlrtBCI, &st);
      }
      i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
      allLayers->data[b_i].f1->size[0] = b_tempAllLayers->data[b_i].f1->size[0];
      emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i1, &wp_emlrtRTEI);
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                      &nt_emlrtBCI, &st);
      }
      i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
      allLayers->data[b_i].f1->size[1] = b_tempAllLayers->data[b_i].f1->size[1];
      emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i1, &wp_emlrtRTEI);
      i1 = allLayers->size[0];
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                      &nt_emlrtBCI, &st);
      }
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                      &nt_emlrtBCI, &st);
      }
      for (i2 = 0; i2 < b_layerSlds; i2++) {
        if (b_i > i1 - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &eu_emlrtBCI, &st);
        }
        allLayers->data[b_i].f1->data[i2] =
            b_tempAllLayers->data[b_i].f1->data[i2];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    emxFree_cell_wrap_25(&b_tempAllLayers);
    /* allLayers = tempAllLayers; */
    b_st.site = &qj_emlrtRSI;
    j_emlrt_marshallIn(&b_st, emlrtAlias(tempAllRoughs), "tempAllRoughs",
                       allRoughs);
    emlrtDestroyArray(&tempAllLayers);
    emlrtDestroyArray(&tempAllRoughs);
    /*   */
    /*  case 'cpp' */
    /*      [allLayers,allRoughs] =
     * loopCppCustlayWrapper(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
     */
    /*      shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params);
     */
    break;
  }
  /*  Multi cored over all contrasts */
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &rc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &xc_emlrtRTEI, (emlrtCTX)sp);
  i = outSsubs->size[0];
  outSsubs->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, outSsubs, i, &qp_emlrtRTEI);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &mp_emlrtRTEI);
  i = reflectivity->size[0];
  reflectivity->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &mp_emlrtRTEI);
  i = Simulation->size[0];
  Simulation->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &mp_emlrtRTEI);
  i = shifted_data->size[0];
  shifted_data->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &mp_emlrtRTEI);
  i = layerSlds->size[0];
  layerSlds->size[0] = loop_ub_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &mp_emlrtRTEI);
  i = chis->size[0];
  chis->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, chis, i, &qp_emlrtRTEI);
  i = qshifts->size[0];
  qshifts->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, qshifts, i, &qp_emlrtRTEI);
  i = sfs->size[0];
  sfs->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, sfs, i, &qp_emlrtRTEI);
  i = nbas->size[0];
  nbas->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, nbas, i, &qp_emlrtRTEI);
  i = nbss->size[0];
  nbss->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, nbss, i, &qp_emlrtRTEI);
  i = resols->size[0];
  resols->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, resols, i, &qp_emlrtRTEI);
  b_layerSlds = loop_ub_tmp - 1;
  emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
#pragma omp parallel num_threads(emlrtAllocRegionTLSs(                         \
    sp->tls, omp_in_parallel(), omp_get_max_threads(),                         \
    omp_get_num_procs())) private(sldProfile, reflect, Simul, thisData,        \
                                  layerSld, resamLayers, thisSsubs,            \
                                  thisChiSquared, thisResol, thisNbs, thisNba, \
                                  thisSf, thisQshift, thisBackground,          \
                                  emlrtJBEnviron, d_st, c_i, loop_ub, i3, i4)  \
    firstprivate(c_st, emlrtHadParallelError)
  {
    if (setjmp(emlrtJBEnviron) == 0) {

      c_st.prev = sp;
      c_st.tls = emlrtAllocTLS((emlrtCTX)sp, omp_get_thread_num());
      c_st.site = NULL;
      emlrtSetJmpBuf(&c_st, &emlrtJBEnviron);
      d_st.prev = &c_st;
      d_st.tls = c_st.tls;
      emxInit_real_T(&c_st, &sldProfile, 2, &lp_emlrtRTEI, true);
      emxInit_real_T(&c_st, &reflect, 2, &lp_emlrtRTEI, true);
      emxInit_real_T(&c_st, &Simul, 2, &lp_emlrtRTEI, true);
      emxInit_real_T(&c_st, &thisData, 2, &eq_emlrtRTEI, true);
      emxInit_real_T(&c_st, &layerSld, 2, &lp_emlrtRTEI, true);
      emxInit_real_T(&c_st, &resamLayers, 2, &lp_emlrtRTEI, true);
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
                                        &fu_emlrtBCI, &c_st);
        }
        if ((int32_T)(c_i + 1U) > problemDef->contrastShifts->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(c_i + 1U), 1,
                                        problemDef->contrastShifts->size[1],
                                        &gu_emlrtBCI, &c_st);
        }
        if ((int32_T)(c_i + 1U) > problemDef->contrastScales->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(c_i + 1U), 1,
                                        problemDef->contrastScales->size[1],
                                        &hu_emlrtBCI, &c_st);
        }
        if ((int32_T)(c_i + 1U) > problemDef->contrastNbas->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(c_i + 1U), 1,
                                        problemDef->contrastNbas->size[1],
                                        &iu_emlrtBCI, &c_st);
        }
        if ((int32_T)(c_i + 1U) > problemDef->contrastNbss->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(c_i + 1U), 1,
                                        problemDef->contrastNbss->size[1],
                                        &ju_emlrtBCI, &c_st);
        }
        if ((int32_T)(c_i + 1U) > problemDef->contrastRes->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(c_i + 1U), 1,
                                        problemDef->contrastRes->size[1],
                                        &ku_emlrtBCI, &c_st);
        }
        d_st.site = &gi_emlrtRSI;
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
                                        &ct_emlrtBCI, &c_st);
        }
        /*  For the other parameters, we extract the correct ones from the input
         */
        /*  arrays */
        if (c_i + 1 > allRoughs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, allRoughs->size[0],
                                        &ws_emlrtBCI, &c_st);
        }
        if (c_i > problemDef_cells->f1->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(
              c_i, 0, problemDef_cells->f1->size[1] - 1, &dt_emlrtBCI, &c_st);
        }
        if (c_i + 1 > problemDef->resample->size[1]) {
          emlrtDynamicBoundsCheckR2012b(
              c_i + 1, 1, problemDef->resample->size[1], &xs_emlrtBCI, &c_st);
        }
        if (c_i > problemDef_cells->f2->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(
              c_i, 0, problemDef_cells->f2->size[1] - 1, &et_emlrtBCI, &c_st);
        }
        if (c_i + 1 > problemDef->dataPresent->size[1]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1,
                                        problemDef->dataPresent->size[1],
                                        &ys_emlrtBCI, &c_st);
        }
        if (c_i > problemDef_cells->f3->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(
              c_i, 0, problemDef_cells->f3->size[1] - 1, &ft_emlrtBCI, &c_st);
        }
        if (c_i > problemDef_cells->f4->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(
              c_i, 0, problemDef_cells->f4->size[1] - 1, &gt_emlrtBCI, &c_st);
        }
        if (c_i + 1 > problemDef->contrastBacksType->size[1]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1,
                                        problemDef->contrastBacksType->size[1],
                                        &at_emlrtBCI, &c_st);
        }
        /*  Now call the core standardTF_stanlay reflectivity calculation */
        /*  In this case we are single cored, so we do not parallelise over */
        /*  points */
        /*  Call the reflectivity calculation */
        d_st.site = &hi_emlrtRSI;
        b_standardTF_layers_core(
            &d_st, allLayers->data[c_i].f1, allRoughs->data[c_i],
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
        /*  Store returned values for this contrast in the output arrays. */
        /*  As well as the calculated profiles, we also store a record of  */
        /*  the other values (background, scalefactors etc) for each contrast */
        /*  for future use. */
        if (c_i + 1 > outSsubs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, outSsubs->size[0],
                                        &lu_emlrtBCI, &c_st);
        }
        outSsubs->data[c_i] = thisSsubs;
        loop_ub = sldProfile->size[0] * 2;
        if (c_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, sldProfiles->size[0] - 1,
                                        &ot_emlrtBCI, &c_st);
        }
        i3 = sldProfiles->data[c_i].f1->size[0] *
             sldProfiles->data[c_i].f1->size[1];
        sldProfiles->data[c_i].f1->size[0] = sldProfile->size[0];
        emxEnsureCapacity_real_T(&c_st, sldProfiles->data[c_i].f1, i3,
                                 &xp_emlrtRTEI);
        if (c_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, sldProfiles->size[0] - 1,
                                        &ot_emlrtBCI, &c_st);
        }
        i3 = sldProfiles->data[c_i].f1->size[0] *
             sldProfiles->data[c_i].f1->size[1];
        sldProfiles->data[c_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(&c_st, sldProfiles->data[c_i].f1, i3,
                                 &xp_emlrtRTEI);
        i3 = sldProfiles->size[0];
        if (c_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, sldProfiles->size[0] - 1,
                                        &ot_emlrtBCI, &c_st);
        }
        if (c_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, sldProfiles->size[0] - 1,
                                        &ot_emlrtBCI, &c_st);
        }
        for (i4 = 0; i4 < loop_ub; i4++) {
          if (c_i > i3 - 1) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3 - 1, &mu_emlrtBCI, &c_st);
          }
          sldProfiles->data[c_i].f1->data[i4] = sldProfile->data[i4];
        }
        loop_ub = reflect->size[0] * 2;
        if (c_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, reflectivity->size[0] - 1,
                                        &pt_emlrtBCI, &c_st);
        }
        i3 = reflectivity->data[c_i].f1->size[0] *
             reflectivity->data[c_i].f1->size[1];
        reflectivity->data[c_i].f1->size[0] = reflect->size[0];
        emxEnsureCapacity_real_T(&c_st, reflectivity->data[c_i].f1, i3,
                                 &yp_emlrtRTEI);
        if (c_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, reflectivity->size[0] - 1,
                                        &pt_emlrtBCI, &c_st);
        }
        i3 = reflectivity->data[c_i].f1->size[0] *
             reflectivity->data[c_i].f1->size[1];
        reflectivity->data[c_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(&c_st, reflectivity->data[c_i].f1, i3,
                                 &yp_emlrtRTEI);
        i3 = reflectivity->size[0];
        if (c_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, reflectivity->size[0] - 1,
                                        &pt_emlrtBCI, &c_st);
        }
        if (c_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, reflectivity->size[0] - 1,
                                        &pt_emlrtBCI, &c_st);
        }
        for (i4 = 0; i4 < loop_ub; i4++) {
          if (c_i > i3 - 1) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3 - 1, &nu_emlrtBCI, &c_st);
          }
          reflectivity->data[c_i].f1->data[i4] = reflect->data[i4];
        }
        loop_ub = Simul->size[0] * 2;
        if (c_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, Simulation->size[0] - 1,
                                        &qt_emlrtBCI, &c_st);
        }
        i3 = Simulation->data[c_i].f1->size[0] *
             Simulation->data[c_i].f1->size[1];
        Simulation->data[c_i].f1->size[0] = Simul->size[0];
        emxEnsureCapacity_real_T(&c_st, Simulation->data[c_i].f1, i3,
                                 &aq_emlrtRTEI);
        if (c_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, Simulation->size[0] - 1,
                                        &qt_emlrtBCI, &c_st);
        }
        i3 = Simulation->data[c_i].f1->size[0] *
             Simulation->data[c_i].f1->size[1];
        Simulation->data[c_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(&c_st, Simulation->data[c_i].f1, i3,
                                 &aq_emlrtRTEI);
        i3 = Simulation->size[0];
        if (c_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, Simulation->size[0] - 1,
                                        &qt_emlrtBCI, &c_st);
        }
        if (c_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, Simulation->size[0] - 1,
                                        &qt_emlrtBCI, &c_st);
        }
        for (i4 = 0; i4 < loop_ub; i4++) {
          if (c_i > i3 - 1) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3 - 1, &ou_emlrtBCI, &c_st);
          }
          Simulation->data[c_i].f1->data[i4] = Simul->data[i4];
        }
        loop_ub = thisData->size[0] * thisData->size[1];
        if (c_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, shifted_data->size[0] - 1,
                                        &rt_emlrtBCI, &c_st);
        }
        i3 = shifted_data->data[c_i].f1->size[0] *
             shifted_data->data[c_i].f1->size[1];
        shifted_data->data[c_i].f1->size[0] = thisData->size[0];
        emxEnsureCapacity_real_T(&c_st, shifted_data->data[c_i].f1, i3,
                                 &bq_emlrtRTEI);
        if (c_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, shifted_data->size[0] - 1,
                                        &rt_emlrtBCI, &c_st);
        }
        i3 = shifted_data->data[c_i].f1->size[0] *
             shifted_data->data[c_i].f1->size[1];
        shifted_data->data[c_i].f1->size[1] = thisData->size[1];
        emxEnsureCapacity_real_T(&c_st, shifted_data->data[c_i].f1, i3,
                                 &bq_emlrtRTEI);
        i3 = shifted_data->size[0];
        if (c_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, shifted_data->size[0] - 1,
                                        &rt_emlrtBCI, &c_st);
        }
        if (c_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, shifted_data->size[0] - 1,
                                        &rt_emlrtBCI, &c_st);
        }
        for (i4 = 0; i4 < loop_ub; i4++) {
          if (c_i > i3 - 1) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3 - 1, &pu_emlrtBCI, &c_st);
          }
          shifted_data->data[c_i].f1->data[i4] = thisData->data[i4];
        }
        loop_ub = layerSld->size[0] * 3;
        if (c_i > layerSlds->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, layerSlds->size[0] - 1,
                                        &st_emlrtBCI, &c_st);
        }
        i3 =
            layerSlds->data[c_i].f1->size[0] * layerSlds->data[c_i].f1->size[1];
        layerSlds->data[c_i].f1->size[0] = layerSld->size[0];
        emxEnsureCapacity_real_T(&c_st, layerSlds->data[c_i].f1, i3,
                                 &cq_emlrtRTEI);
        if (c_i > layerSlds->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, layerSlds->size[0] - 1,
                                        &st_emlrtBCI, &c_st);
        }
        i3 =
            layerSlds->data[c_i].f1->size[0] * layerSlds->data[c_i].f1->size[1];
        layerSlds->data[c_i].f1->size[1] = 3;
        emxEnsureCapacity_real_T(&c_st, layerSlds->data[c_i].f1, i3,
                                 &cq_emlrtRTEI);
        i3 = layerSlds->size[0];
        if (c_i > layerSlds->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, layerSlds->size[0] - 1,
                                        &st_emlrtBCI, &c_st);
        }
        if (c_i > layerSlds->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, layerSlds->size[0] - 1,
                                        &st_emlrtBCI, &c_st);
        }
        for (i4 = 0; i4 < loop_ub; i4++) {
          if (c_i > i3 - 1) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3 - 1, &qu_emlrtBCI, &c_st);
          }
          layerSlds->data[c_i].f1->data[i4] = layerSld->data[i4];
        }
        loop_ub = resamLayers->size[0] * 3;
        if (c_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, allLayers->size[0] - 1,
                                        &tt_emlrtBCI, &c_st);
        }
        i3 =
            allLayers->data[c_i].f1->size[0] * allLayers->data[c_i].f1->size[1];
        allLayers->data[c_i].f1->size[0] = resamLayers->size[0];
        emxEnsureCapacity_real_T(&c_st, allLayers->data[c_i].f1, i3,
                                 &dq_emlrtRTEI);
        if (c_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, allLayers->size[0] - 1,
                                        &tt_emlrtBCI, &c_st);
        }
        i3 =
            allLayers->data[c_i].f1->size[0] * allLayers->data[c_i].f1->size[1];
        allLayers->data[c_i].f1->size[1] = 3;
        emxEnsureCapacity_real_T(&c_st, allLayers->data[c_i].f1, i3,
                                 &dq_emlrtRTEI);
        i3 = allLayers->size[0];
        if (c_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, allLayers->size[0] - 1,
                                        &tt_emlrtBCI, &c_st);
        }
        if (c_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, allLayers->size[0] - 1,
                                        &tt_emlrtBCI, &c_st);
        }
        for (i4 = 0; i4 < loop_ub; i4++) {
          if (c_i > i3 - 1) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3 - 1, &ru_emlrtBCI, &c_st);
          }
          allLayers->data[c_i].f1->data[i4] = resamLayers->data[i4];
        }
        if (c_i + 1 > chis->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, chis->size[0], &su_emlrtBCI,
                                        &c_st);
        }
        chis->data[c_i] = thisChiSquared;
        if (c_i + 1 > backgs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, backgs->size[0],
                                        &tu_emlrtBCI, &c_st);
        }
        backgs->data[c_i] = thisBackground;
        if (c_i + 1 > qshifts->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, qshifts->size[0],
                                        &uu_emlrtBCI, &c_st);
        }
        qshifts->data[c_i] = thisQshift;
        if (c_i + 1 > sfs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, sfs->size[0], &vu_emlrtBCI,
                                        &c_st);
        }
        sfs->data[c_i] = thisSf;
        if (c_i + 1 > nbas->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, nbas->size[0], &wu_emlrtBCI,
                                        &c_st);
        }
        nbas->data[c_i] = thisNba;
        if (c_i + 1 > nbss->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, nbss->size[0], &xu_emlrtBCI,
                                        &c_st);
        }
        nbss->data[c_i] = thisNbs;
        if (c_i + 1 > resols->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, resols->size[0],
                                        &yu_emlrtBCI, &c_st);
        }
        resols->data[c_i] = thisResol;
        if (c_i + 1 > allRoughs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, allRoughs->size[0],
                                        &av_emlrtBCI, &c_st);
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
      emxFree_real_T(&resamLayers);
      emxFree_real_T(&layerSld);
      emxFree_real_T(&thisData);
      emxFree_real_T(&Simul);
      emxFree_real_T(&reflect);
      emxFree_real_T(&sldProfile);
    }
  }
  emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (standardTF_custlay_paraContrasts.c) */
