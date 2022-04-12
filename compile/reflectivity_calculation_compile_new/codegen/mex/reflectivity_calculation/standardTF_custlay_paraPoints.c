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
#include "backSort.h"
#include "callReflectivity.h"
#include "call_customLayers.h"
#include "chiSquared.h"
#include "groupLayers_Mod.h"
#include "makeSLDProfiles.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo ci_emlrtRSI = {
    70,                              /* lineNo */
    "standardTF_custlay_paraPoints", /* fcnName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m" /* pathName */
};

static emlrtRSInfo di_emlrtRSI = {
    74,                              /* lineNo */
    "standardTF_custlay_paraPoints", /* fcnName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m" /* pathName */
};

static emlrtRSInfo ei_emlrtRSI = {
    96,                              /* lineNo */
    "standardTF_custlay_paraPoints", /* fcnName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m" /* pathName */
};

static emlrtRTEInfo qc_emlrtRTEI = {
    46,                              /* lineNo */
    9,                               /* colNo */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo rc_emlrtRTEI = {
    51,                              /* lineNo */
    9,                               /* colNo */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = {
    56,                              /* lineNo */
    9,                               /* colNo */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo tc_emlrtRTEI = {
    65,                              /* lineNo */
    9,                               /* colNo */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m" /* pName */
};

static emlrtDCInfo mc_emlrtDCI = {
    73,                              /* lineNo */
    34,                              /* colNo */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    1                                                          /* checkKind */
};

static emlrtBCInfo uq_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    80,                              /* lineNo */
    27,                              /* colNo */
    "allRoughs",                     /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo vq_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    82,                              /* lineNo */
    29,                              /* colNo */
    "resample",                      /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo wq_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    85,                              /* lineNo */
    35,                              /* colNo */
    "dataPresent",                   /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo xq_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    88,                              /* lineNo */
    31,                              /* colNo */
    "backsType",                     /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo yq_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    73,                              /* lineNo */
    34,                              /* colNo */
    "customFiles",                   /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo ar_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    81,                              /* lineNo */
    37,                              /* colNo */
    "repeatLayers",                  /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo br_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    84,                              /* lineNo */
    24,                              /* colNo */
    "allData",                       /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo cr_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    86,                              /* lineNo */
    33,                              /* colNo */
    "dataLimits",                    /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo dr_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    87,                              /* lineNo */
    31,                              /* colNo */
    "simLimits",                     /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo er_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    47,                              /* lineNo */
    18,                              /* colNo */
    "reflectivity",                  /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo fr_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    52,                              /* lineNo */
    16,                              /* colNo */
    "Simulation",                    /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo gr_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    57,                              /* lineNo */
    15,                              /* colNo */
    "allLayers",                     /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo hr_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    75,                              /* lineNo */
    15,                              /* colNo */
    "allLayers",                     /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo ir_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    108,                             /* lineNo */
    17,                              /* colNo */
    "sldProfiles",                   /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo jr_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    109,                             /* lineNo */
    18,                              /* colNo */
    "reflectivity",                  /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo kr_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    110,                             /* lineNo */
    16,                              /* colNo */
    "Simulation",                    /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo lr_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    111,                             /* lineNo */
    18,                              /* colNo */
    "shifted_data",                  /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo mr_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    112,                             /* lineNo */
    15,                              /* colNo */
    "layerSlds",                     /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo nr_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    113,                             /* lineNo */
    15,                              /* colNo */
    "allLayers",                     /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtDCInfo nc_emlrtDCI = {
    32,                              /* lineNo */
    17,                              /* colNo */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    1                                                          /* checkKind */
};

static emlrtDCInfo oc_emlrtDCI = {
    31,                              /* lineNo */
    16,                              /* colNo */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    1                                                          /* checkKind */
};

static emlrtDCInfo pc_emlrtDCI = {
    31,                              /* lineNo */
    16,                              /* colNo */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    4                                                          /* checkKind */
};

static emlrtBCInfo or_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    40,                              /* lineNo */
    36,                              /* colNo */
    "layerSlds",                     /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo pr_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    40,                              /* lineNo */
    36,                              /* colNo */
    "sldProfiles",                   /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo qr_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    40,                              /* lineNo */
    36,                              /* colNo */
    "shifted_data",                  /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo rr_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    40,                              /* lineNo */
    36,                              /* colNo */
    "reflectivity",                  /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo sr_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    40,                              /* lineNo */
    36,                              /* colNo */
    "Simulation",                    /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo tr_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    40,                              /* lineNo */
    36,                              /* colNo */
    "allLayers",                     /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo ur_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    70,                              /* lineNo */
    77,                              /* colNo */
    "cBacks",                        /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo vr_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    70,                              /* lineNo */
    87,                              /* colNo */
    "cShifts",                       /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo wr_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    70,                              /* lineNo */
    98,                              /* colNo */
    "cScales",                       /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo xr_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    70,                              /* lineNo */
    109,                             /* colNo */
    "cNbas",                         /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo yr_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    70,                              /* lineNo */
    118,                             /* colNo */
    "cNbss",                         /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo as_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    70,                              /* lineNo */
    127,                             /* colNo */
    "cRes",                          /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo bs_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    73,                              /* lineNo */
    34,                              /* colNo */
    "cCustFiles",                    /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo cs_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    74,                              /* lineNo */
    16,                              /* colNo */
    "allRoughs",                     /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo ds_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    75,                              /* lineNo */
    5,                               /* colNo */
    "allLayers",                     /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo es_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    107,                             /* lineNo */
    5,                               /* colNo */
    "outSsubs",                      /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo fs_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    115,                             /* lineNo */
    5,                               /* colNo */
    "chis",                          /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo gs_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    108,                             /* lineNo */
    5,                               /* colNo */
    "sldProfiles",                   /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo hs_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    109,                             /* lineNo */
    5,                               /* colNo */
    "reflectivity",                  /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo is_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    110,                             /* lineNo */
    5,                               /* colNo */
    "Simulation",                    /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo js_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    111,                             /* lineNo */
    5,                               /* colNo */
    "shifted_data",                  /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo ks_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    112,                             /* lineNo */
    5,                               /* colNo */
    "layerSlds",                     /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo ls_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    113,                             /* lineNo */
    5,                               /* colNo */
    "allLayers",                     /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo ms_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    116,                             /* lineNo */
    5,                               /* colNo */
    "backgs",                        /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo ns_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    117,                             /* lineNo */
    5,                               /* colNo */
    "qshifts",                       /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo os_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    118,                             /* lineNo */
    5,                               /* colNo */
    "sfs",                           /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo ps_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    119,                             /* lineNo */
    5,                               /* colNo */
    "nbas",                          /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo qs_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    120,                             /* lineNo */
    5,                               /* colNo */
    "nbss",                          /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo rs_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    121,                             /* lineNo */
    5,                               /* colNo */
    "resols",                        /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo ss_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    122,                             /* lineNo */
    5,                               /* colNo */
    "allRoughs",                     /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo ts_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    57,                              /* lineNo */
    5,                               /* colNo */
    "allLayers",                     /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo us_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    52,                              /* lineNo */
    5,                               /* colNo */
    "Simulation",                    /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo vs_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    47,                              /* lineNo */
    5,                               /* colNo */
    "reflectivity",                  /* aName */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtRTEInfo to_emlrtRTEI = {
    31,                              /* lineNo */
    10,                              /* colNo */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo uo_emlrtRTEI = {
    3,                               /* lineNo */
    18,                              /* colNo */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo vo_emlrtRTEI = {
    40,                              /* lineNo */
    36,                              /* colNo */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo wo_emlrtRTEI = {
    47,                              /* lineNo */
    5,                               /* colNo */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo xo_emlrtRTEI = {
    52,                              /* lineNo */
    5,                               /* colNo */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo yo_emlrtRTEI = {
    57,                              /* lineNo */
    5,                               /* colNo */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo ap_emlrtRTEI = {
    37,                              /* lineNo */
    13,                              /* colNo */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo bp_emlrtRTEI = {
    75,                              /* lineNo */
    5,                               /* colNo */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo cp_emlrtRTEI = {
    84,                              /* lineNo */
    16,                              /* colNo */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo dp_emlrtRTEI = {
    108,                             /* lineNo */
    5,                               /* colNo */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo ep_emlrtRTEI = {
    109,                             /* lineNo */
    5,                               /* colNo */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo fp_emlrtRTEI = {
    110,                             /* lineNo */
    5,                               /* colNo */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo gp_emlrtRTEI = {
    111,                             /* lineNo */
    5,                               /* colNo */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo hp_emlrtRTEI = {
    112,                             /* lineNo */
    5,                               /* colNo */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo ip_emlrtRTEI = {
    113,                             /* lineNo */
    5,                               /* colNo */
    "standardTF_custlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_custLay\\standardTF_custlay_paraPoints.m" /* pName */
};

/* Function Definitions */
void standardTF_custlay_paraPoints(
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
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T *Simul;
  emxArray_real_T *b_problemDef_cells;
  emxArray_real_T *b_shifted_dat;
  emxArray_real_T *layerSld;
  emxArray_real_T *outLayers;
  emxArray_real_T *reflect;
  emxArray_real_T *resamLayers;
  emxArray_real_T *shifted_dat;
  emxArray_real_T *sldProfile;
  emxArray_real_T *theseLayers;
  real_T b_calcSld;
  real_T calcSld;
  real_T ssubs;
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
  int32_T problemDef_tmp_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /*  Multi threaded version of the custom layers over reflectivity poimnts */
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
  calcSld = controls->calcSld;
  /*  Pre-Allocation of output arrays... */
  /*    --- Begin Memory Allocation --- */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &pc_emlrtDCI,
                                (emlrtCTX)sp);
  }
  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &oc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &to_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &nc_emlrtDCI,
                            (emlrtCTX)sp);
  }
  problemDef_tmp_tmp = (int32_T)problemDef->numberOfContrasts;
  i = layerSlds->size[0];
  layerSlds->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &uo_emlrtRTEI);
  for (i = 0; i < problemDef_tmp_tmp; i++) {
    b_layerSlds = layerSlds->size[0] - 1;
    if (i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, layerSlds->size[0] - 1, &or_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    layerSlds->data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &or_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
    layerSlds->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[i].f1, i1, &uo_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = sldProfiles->size[0];
  sldProfiles->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &uo_emlrtRTEI);
  for (i = 0; i < problemDef_tmp_tmp; i++) {
    b_layerSlds = sldProfiles->size[0] - 1;
    if (i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, sldProfiles->size[0] - 1,
                                    &pr_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &pr_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sldProfiles->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = shifted_data->size[0];
  shifted_data->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &uo_emlrtRTEI);
  for (i = 0; i < problemDef_tmp_tmp; i++) {
    b_layerSlds = shifted_data->size[0] - 1;
    if (i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, shifted_data->size[0] - 1,
                                    &qr_emlrtBCI, (emlrtCTX)sp);
    }
    shifted_data->data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &qr_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    shifted_data->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = reflectivity->size[0];
  reflectivity->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &uo_emlrtRTEI);
  for (i = 0; i < problemDef_tmp_tmp; i++) {
    b_layerSlds = reflectivity->size[0] - 1;
    if (i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, reflectivity->size[0] - 1,
                                    &rr_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &rr_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = reflectivity->data[i].f1->size[0] * reflectivity->data[i].f1->size[1];
    reflectivity->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[i].f1, i1, &uo_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &qc_emlrtRTEI, (emlrtCTX)sp);
  i = reflectivity->size[0];
  reflectivity->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &vo_emlrtRTEI);
  for (b_i = 0; b_i < problemDef_tmp_tmp; b_i++) {
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &er_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity->data[b_i].f1->size[0] *
        reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &wo_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &er_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity->data[b_i].f1->size[0] *
        reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &wo_emlrtRTEI);
    i = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &er_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &vs_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &vs_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &vs_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = Simulation->size[0];
  Simulation->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &uo_emlrtRTEI);
  for (i = 0; i < problemDef_tmp_tmp; i++) {
    b_layerSlds = Simulation->size[0] - 1;
    if (i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, Simulation->size[0] - 1, &sr_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation->data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &sr_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = Simulation->data[i].f1->size[0] * Simulation->data[i].f1->size[1];
    Simulation->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[i].f1, i1, &uo_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &rc_emlrtRTEI, (emlrtCTX)sp);
  i = Simulation->size[0];
  Simulation->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &vo_emlrtRTEI);
  for (b_i = 0; b_i < problemDef_tmp_tmp; b_i++) {
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &fr_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &xo_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &fr_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &xo_emlrtRTEI);
    i = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &fr_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &us_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &us_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &us_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = allLayers->size[0];
  allLayers->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &uo_emlrtRTEI);
  for (i = 0; i < problemDef_tmp_tmp; i++) {
    b_layerSlds = allLayers->size[0] - 1;
    if (i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, allLayers->size[0] - 1, &tr_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &tr_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &sc_emlrtRTEI, (emlrtCTX)sp);
  i = allLayers->size[0];
  allLayers->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &vo_emlrtRTEI);
  for (b_i = 0; b_i < problemDef_tmp_tmp; b_i++) {
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &gr_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &yo_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &gr_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &yo_emlrtRTEI);
    i = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &gr_emlrtBCI, (emlrtCTX)sp);
    }
    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &ts_emlrtBCI, (emlrtCTX)sp);
    }
    allLayers->data[b_i].f1->data[1] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  /*    --- End Memory Allocation --- */
  /*  Single cored over all contrasts */
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &tc_emlrtRTEI, (emlrtCTX)sp);
  i = allRoughs->size[0];
  allRoughs->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_real_T(sp, allRoughs, i, &ap_emlrtRTEI);
  i = allLayers->size[0];
  allLayers->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &vo_emlrtRTEI);
  i = outSsubs->size[0];
  outSsubs->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_real_T(sp, outSsubs, i, &ap_emlrtRTEI);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &vo_emlrtRTEI);
  i = reflectivity->size[0];
  reflectivity->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &vo_emlrtRTEI);
  i = Simulation->size[0];
  Simulation->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &vo_emlrtRTEI);
  i = shifted_data->size[0];
  shifted_data->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &vo_emlrtRTEI);
  i = layerSlds->size[0];
  layerSlds->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &vo_emlrtRTEI);
  i = chis->size[0];
  chis->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_real_T(sp, chis, i, &ap_emlrtRTEI);
  i = qshifts->size[0];
  qshifts->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_real_T(sp, qshifts, i, &ap_emlrtRTEI);
  i = sfs->size[0];
  sfs->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_real_T(sp, sfs, i, &ap_emlrtRTEI);
  i = nbas->size[0];
  nbas->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_real_T(sp, nbas, i, &ap_emlrtRTEI);
  i = nbss->size[0];
  nbss->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_real_T(sp, nbss, i, &ap_emlrtRTEI);
  i = resols->size[0];
  resols->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_real_T(sp, resols, i, &ap_emlrtRTEI);
  emxInit_real_T(sp, &outLayers, 2, &uo_emlrtRTEI, true);
  emxInit_real_T(sp, &sldProfile, 2, &uo_emlrtRTEI, true);
  emxInit_real_T(sp, &shifted_dat, 2, &uo_emlrtRTEI, true);
  emxInit_real_T(sp, &resamLayers, 2, &uo_emlrtRTEI, true);
  emxInit_real_T(sp, &layerSld, 2, &ph_emlrtRTEI, true);
  emxInit_real_T(sp, &theseLayers, 2, &uo_emlrtRTEI, true);
  emxInit_real_T(sp, &reflect, 2, &uo_emlrtRTEI, true);
  emxInit_real_T(sp, &Simul, 2, &uo_emlrtRTEI, true);
  emxInit_real_T(sp, &b_shifted_dat, 1, &nh_emlrtRTEI, true);
  emxInit_real_T(sp, &b_problemDef_cells, 2, &cp_emlrtRTEI, true);
  for (b_i = 0; b_i < problemDef_tmp_tmp; b_i++) {
    /*  Extract the relevant parameter values for this contrast */
    /*  from the input arrays. */
    /*  First need to decide which values of the backrounds, scalefactors */
    /*  data shifts and bulk contrasts are associated with this contrast */
    if ((int32_T)(b_i + 1U) > problemDef->contrastBacks->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastBacks->size[1],
                                    &ur_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastShifts->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastShifts->size[1],
                                    &vr_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastScales->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastScales->size[1],
                                    &wr_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastNbas->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastNbas->size[1],
                                    &xr_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastNbss->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastNbss->size[1],
                                    &yr_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastRes->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastRes->size[1],
                                    &as_emlrtBCI, (emlrtCTX)sp);
    }
    st.site = &ci_emlrtRSI;
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
                                    &bs_emlrtBCI, (emlrtCTX)sp);
    }
    b_calcSld = problemDef->contrastCustomFiles->data[b_i];
    if (b_calcSld != (int32_T)muDoubleScalarFloor(b_calcSld)) {
      emlrtIntegerCheckR2012b(b_calcSld, &mc_emlrtDCI, (emlrtCTX)sp);
    }
    if (((int32_T)b_calcSld - 1 < 0) ||
        ((int32_T)b_calcSld - 1 > problemDef_cells->f14->size[1] - 1)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b_calcSld - 1, 0,
                                    problemDef_cells->f14->size[1] - 1,
                                    &yq_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, allRoughs->size[0],
                                    &cs_emlrtBCI, (emlrtCTX)sp);
    }
    st.site = &di_emlrtRSI;
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
                                    &hr_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = outLayers->size[0];
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &bp_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &hr_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = outLayers->size[1];
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &bp_emlrtRTEI);
    i = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &hr_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &hr_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &ds_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      allLayers->data[b_i].f1->data[i1] = outLayers->data[i1];
    }
    /*  For the other parameters, we extract the correct ones from the input */
    /*  arrays */
    if (b_i + 1 > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, allRoughs->size[0],
                                    &uq_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f1->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f1->size[1] - 1,
                                    &ar_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i + 1 > problemDef->resample->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, problemDef->resample->size[1],
                                    &vq_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f2->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f2->size[1] - 1,
                                    &br_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i + 1 > problemDef->dataPresent->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                                    problemDef->dataPresent->size[1],
                                    &wq_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f3->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f3->size[1] - 1,
                                    &cr_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f4->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f4->size[1] - 1,
                                    &dr_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i + 1 > problemDef->contrastBacksType->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                                    problemDef->contrastBacksType->size[1],
                                    &xq_emlrtBCI, (emlrtCTX)sp);
    }
    /*  Now call the core standardTF_stanlay reflectivity calculation */
    /*  In this case we are single cored, so we do not parallelise over */
    /*  points */
    /*  Call the reflectivity calculation */
    st.site = &ei_emlrtRSI;
    b_calcSld = calcSld;
    /*    This is the main reflectivity calculation for all Layers models in the
     */
    /*    standard target function.  */
    /*  */
    /*    The function first arranges the  */
    /*    roughness' in the correct order according */
    /*    to geometry. Then, if required it calculates the SLD profile and if */
    /*    requested resamples this into a number of zero-roughness layers */
    /*    (roughness resampling). It the applies any scalefactors and qz shifts
     */
    /*    the data requires. This is done before calculating the reflectivity to
     */
    /*    ensure that the reflectivity is calculated over the same range in qz
     * as */
    /*    the shifted datapoints. The main reflectivity calculation is then */
    /*    called, including the resolution function. The calculation outputs two
     */
    /*    profiles - 'reflect' which is the same range as the points, and */
    /*    'Simulation' which can be a different range to allow extrapolation. */
    /*    The background correction is the applied, and finally chi-squared is
     */
    /*    calculated. */
    /*  */
    /*  Inputs: */
    /*    contrastLayers  : */
    /*    rough           : */
    /*    geometry        : */
    /*    nba             : */
    /*    nbs             : */
    /*    resample        : */
    /*    calcSld         : */
    /*    sf              : */
    /*    qshift          : */
    /*    dataPresent     : */
    /*    data            : */
    /*    dataLimits      : */
    /*    simLimits       : */
    /*    repeatLayers    : */
    /*    background      : */
    /*    resol           : */
    /*    backsType       : */
    /*    params          : */
    /*    paralellPoints  : */
    /*  */
    /*  Outputs: */
    /*  */
    /*  */
    /*  */
    /*  ------------------------------------------------------------------------
     */
    /*  */
    /*        (c) Arwel Hughes  -   12/1/21 */
    /*  */
    /*        Last Modified: 12/1/21 by Arwel Hughes. */
    /*  */
    /*  ------------------------------------------------------------------------
     */
    /*  Bulid up the layers matrix for this contrast */
    b_st.site = &w_emlrtRSI;
    b_groupLayers_Mod(&b_st, outLayers, allRoughs->data[b_i],
                      problemDef->geometry, thisNba, thisNbs, theseLayers,
                      &ssubs);
    if (b_i + 1 > outSsubs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, outSsubs->size[0], &es_emlrtBCI,
                                    &st);
    }
    outSsubs->data[b_i] = ssubs;
    /*  Make the SLD profiles. */
    /*  If resampling is needed, then enforce the calcSLD flag, so as to catch
     */
    /*  the error af trying to resample a non-existent profile. */
    if ((problemDef->resample->data[b_i] == 1.0) && (calcSld == 0.0)) {
      b_calcSld = 1.0;
    }
    /*  If calc SLD flag is set, then calculate the SLD profile */
    if (b_calcSld == 1.0) {
      b_st.site = &x_emlrtRSI;
      makeSLDProfiles(&b_st, thisNba, thisNbs, theseLayers, ssubs,
                      problemDef_cells->f1->data[b_i].f1, sldProfile);
    } else {
      i = sldProfile->size[0] * sldProfile->size[1];
      sldProfile->size[0] = 1;
      sldProfile->size[1] = 2;
      emxEnsureCapacity_real_T(&st, sldProfile, i, &hh_emlrtRTEI);
      sldProfile->data[0] = 0.0;
      sldProfile->data[1] = 0.0;
    }
    /*  If required, then resample the SLD */
    if (problemDef->resample->data[b_i] == 1.0) {
      b_st.site = &y_emlrtRSI;
      resampleLayers(&b_st, sldProfile, controls->resamPars, layerSld);
      i = resamLayers->size[0] * resamLayers->size[1];
      resamLayers->size[0] = layerSld->size[0];
      resamLayers->size[1] = 3;
      emxEnsureCapacity_real_T(&st, resamLayers, i, &jh_emlrtRTEI);
      b_layerSlds = layerSld->size[0] * 3;
      for (i = 0; i < b_layerSlds; i++) {
        resamLayers->data[i] = layerSld->data[i];
      }
    } else {
      i = layerSld->size[0] * layerSld->size[1];
      layerSld->size[0] = theseLayers->size[0];
      layerSld->size[1] = 3;
      emxEnsureCapacity_real_T(&st, layerSld, i, &ih_emlrtRTEI);
      b_layerSlds = theseLayers->size[0] * 3;
      for (i = 0; i < b_layerSlds; i++) {
        layerSld->data[i] = theseLayers->data[i];
      }
      i = resamLayers->size[0] * resamLayers->size[1];
      resamLayers->size[0] = 1;
      resamLayers->size[1] = 3;
      emxEnsureCapacity_real_T(&st, resamLayers, i, &kh_emlrtRTEI);
      resamLayers->data[0] = 0.0;
      resamLayers->data[1] = 0.0;
      resamLayers->data[2] = 0.0;
    }
    /*  Apply scale factors and q shifts to the data */
    i = b_problemDef_cells->size[0] * b_problemDef_cells->size[1];
    b_problemDef_cells->size[0] = problemDef_cells->f2->data[b_i].f1->size[0];
    b_problemDef_cells->size[1] = problemDef_cells->f2->data[b_i].f1->size[1];
    emxEnsureCapacity_real_T(&st, b_problemDef_cells, i, &cp_emlrtRTEI);
    b_layerSlds = problemDef_cells->f2->data[b_i].f1->size[0] *
                      problemDef_cells->f2->data[b_i].f1->size[1] -
                  1;
    for (i = 0; i <= b_layerSlds; i++) {
      b_problemDef_cells->data[i] = problemDef_cells->f2->data[b_i].f1->data[i];
    }
    b_st.site = &ab_emlrtRSI;
    shiftdata(&b_st, thisSf, thisQshift, problemDef->dataPresent->data[b_i],
              b_problemDef_cells, problemDef_cells->f3->data[b_i].f1,
              (real_T *)problemDef_cells->f4->data[b_i].f1->data,
              *(int32_T(*)[2])problemDef_cells->f4->data[b_i].f1->size,
              shifted_dat);
    /*  Calculate the reflectivity */
    b_st.site = &bb_emlrtRSI;
    b_callReflectivity(&b_st, thisNba, thisNbs,
                       (real_T *)problemDef_cells->f4->data[b_i].f1->data,
                       *(int32_T(*)[2])problemDef_cells->f4->data[b_i].f1->size,
                       problemDef_cells->f1->data[b_i].f1, shifted_dat,
                       layerSld, ssubs, thisResol, reflect, Simul);
    /*  Apply background correction, either to the simulation or the data */
    b_st.site = &cb_emlrtRSI;
    if (problemDef->contrastBacksType->data[b_i] !=
        (int32_T)muDoubleScalarFloor(
            problemDef->contrastBacksType->data[b_i])) {
      emlrtIntegerCheckR2012b(problemDef->contrastBacksType->data[b_i],
                              &db_emlrtDCI, &b_st);
    }
    switch ((int32_T)problemDef->contrastBacksType->data[b_i]) {
    case 1:
      /* Add background to the simulation */
      b_layerSlds = reflect->size[0] * 2;
      i = reflect->size[0] * reflect->size[1];
      reflect->size[1] = 2;
      emxEnsureCapacity_real_T(&b_st, reflect, i, &mh_emlrtRTEI);
      for (i = 0; i < b_layerSlds; i++) {
        reflect->data[i] += thisBackground;
      }
      b_layerSlds = Simul->size[0] * 2;
      i = Simul->size[0] * Simul->size[1];
      Simul->size[1] = 2;
      emxEnsureCapacity_real_T(&b_st, Simul, i, &oh_emlrtRTEI);
      for (i = 0; i < b_layerSlds; i++) {
        Simul->data[i] += thisBackground;
      }
      break;
    case 2:
      /*          %Subtract the background from the data.. */
      if (2 > shifted_dat->size[1]) {
        emlrtDynamicBoundsCheckR2012b(2, 1, shifted_dat->size[1], &wf_emlrtBCI,
                                      &b_st);
      }
      emlrtSubAssignSizeCheckR2012b(&shifted_dat->size[0], 1,
                                    &shifted_dat->size[0], 1, &emlrtECI, &b_st);
      b_layerSlds = shifted_dat->size[0] - 1;
      i = b_shifted_dat->size[0];
      b_shifted_dat->size[0] = shifted_dat->size[0];
      emxEnsureCapacity_real_T(&b_st, b_shifted_dat, i, &nh_emlrtRTEI);
      for (i = 0; i <= b_layerSlds; i++) {
        b_shifted_dat->data[i] =
            shifted_dat->data[i + shifted_dat->size[0]] - thisBackground;
      }
      b_layerSlds = b_shifted_dat->size[0];
      for (i = 0; i < b_layerSlds; i++) {
        shifted_dat->data[i + shifted_dat->size[0]] = b_shifted_dat->data[i];
      }
      /* shifted_dat(:,3) = shifted_dat(:,3) - backg;    */
      break;
    }
    /*  Calculate chi squared. */
    if (b_i + 1 > chis->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, chis->size[0], &fs_emlrtBCI,
                                    &st);
    }
    b_st.site = &db_emlrtRSI;
    chis->data[b_i] =
        chiSquared(&b_st, shifted_dat, reflect, problemDef->params->size[1]);
    /*  Store returned values for this contrast in the output arrays. */
    /*  As well as the calculated profiles, we also store a record of  */
    /*  the other values (background, scalefactors etc) for each contrast */
    /*  for future use. */
    b_layerSlds = sldProfile->size[0] * 2;
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &ir_emlrtBCI, (emlrtCTX)sp);
    }
    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &dp_emlrtRTEI);
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &ir_emlrtBCI, (emlrtCTX)sp);
    }
    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &dp_emlrtRTEI);
    i = sldProfiles->size[0];
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &ir_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &ir_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &gs_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      sldProfiles->data[b_i].f1->data[i1] = sldProfile->data[i1];
    }
    b_layerSlds = reflect->size[0] * 2;
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &jr_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity->data[b_i].f1->size[0] *
        reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = reflect->size[0];
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &ep_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &jr_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity->data[b_i].f1->size[0] *
        reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &ep_emlrtRTEI);
    i = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &jr_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &jr_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &hs_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      reflectivity->data[b_i].f1->data[i1] = reflect->data[i1];
    }
    b_layerSlds = Simul->size[0] * 2;
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &kr_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = Simul->size[0];
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &fp_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &kr_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &fp_emlrtRTEI);
    i = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &kr_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &kr_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &is_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      Simulation->data[b_i].f1->data[i1] = Simul->data[i1];
    }
    b_layerSlds = shifted_dat->size[0] * shifted_dat->size[1];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &lr_emlrtBCI, (emlrtCTX)sp);
    }
    i = shifted_data->data[b_i].f1->size[0] *
        shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &gp_emlrtRTEI);
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &lr_emlrtBCI, (emlrtCTX)sp);
    }
    i = shifted_data->data[b_i].f1->size[0] *
        shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[1] = shifted_dat->size[1];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &gp_emlrtRTEI);
    i = shifted_data->size[0];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &lr_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &lr_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &js_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      shifted_data->data[b_i].f1->data[i1] = shifted_dat->data[i1];
    }
    b_layerSlds = theseLayers->size[0] * 3;
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                    &mr_emlrtBCI, (emlrtCTX)sp);
    }
    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = theseLayers->size[0];
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &hp_emlrtRTEI);
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                    &mr_emlrtBCI, (emlrtCTX)sp);
    }
    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &hp_emlrtRTEI);
    i = layerSlds->size[0];
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                    &mr_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                    &mr_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &ks_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      layerSlds->data[b_i].f1->data[i1] = theseLayers->data[i1];
    }
    b_layerSlds = resamLayers->size[0] * 3;
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &nr_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = resamLayers->size[0];
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &ip_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &nr_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &ip_emlrtRTEI);
    i = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &nr_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &nr_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &ls_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      allLayers->data[b_i].f1->data[i1] = resamLayers->data[i1];
    }
    if (b_i + 1 > backgs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, backgs->size[0], &ms_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    backgs->data[b_i] = thisBackground;
    if (b_i + 1 > qshifts->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, qshifts->size[0], &ns_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    qshifts->data[b_i] = thisQshift;
    if (b_i + 1 > sfs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, sfs->size[0], &os_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sfs->data[b_i] = thisSf;
    if (b_i + 1 > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbas->size[0], &ps_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    nbas->data[b_i] = thisNba;
    if (b_i + 1 > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbss->size[0], &qs_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    nbss->data[b_i] = thisNbs;
    if (b_i + 1 > resols->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, resols->size[0], &rs_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    resols->data[b_i] = thisResol;
    if (b_i + 1 > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, allRoughs->size[0],
                                    &ss_emlrtBCI, (emlrtCTX)sp);
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_real_T(&b_problemDef_cells);
  emxFree_real_T(&b_shifted_dat);
  emxFree_real_T(&Simul);
  emxFree_real_T(&reflect);
  emxFree_real_T(&theseLayers);
  emxFree_real_T(&layerSld);
  emxFree_real_T(&resamLayers);
  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&sldProfile);
  emxFree_real_T(&outLayers);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (standardTF_custlay_paraPoints.c) */
