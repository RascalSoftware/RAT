/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_stanlay_paraPoints.c
 *
 * Code generation for function 'standardTF_stanlay_paraPoints'
 *
 */

/* Include files */
#include "standardTF_stanlay_paraPoints.h"
#include "allocateLayersForContrast.h"
#include "allocateParamsToLayers.h"
#include "backSort.h"
#include "callReflectivity.h"
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
static emlrtRSInfo eh_emlrtRSI = {
    65,                              /* lineNo */
    "standardTF_stanlay_paraPoints", /* fcnName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pathName */
};

static emlrtRSInfo fh_emlrtRSI = {
    77,                              /* lineNo */
    "standardTF_stanlay_paraPoints", /* fcnName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pathName */
};

static emlrtRSInfo gh_emlrtRSI = {
    82,                              /* lineNo */
    "standardTF_stanlay_paraPoints", /* fcnName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pathName */
};

static emlrtRSInfo hh_emlrtRSI = {
    102,                             /* lineNo */
    "standardTF_stanlay_paraPoints", /* fcnName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pathName */
};

static emlrtRTEInfo wb_emlrtRTEI = {
    46,                              /* lineNo */
    9,                               /* colNo */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = {
    51,                              /* lineNo */
    9,                               /* colNo */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = {
    56,                              /* lineNo */
    9,                               /* colNo */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = {
    71,                              /* lineNo */
    9,                               /* colNo */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pName */
};

static emlrtBCInfo mj_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    86,                              /* lineNo */
    24,                              /* colNo */
    "params",                        /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo nj_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    88,                              /* lineNo */
    29,                              /* colNo */
    "resample",                      /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo oj_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    91,                              /* lineNo */
    35,                              /* colNo */
    "dataPresent",                   /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo pj_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    94,                              /* lineNo */
    31,                              /* colNo */
    "backsType",                     /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo qj_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    87,                              /* lineNo */
    37,                              /* colNo */
    "repeatLayers",                  /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo rj_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    90,                              /* lineNo */
    24,                              /* colNo */
    "allData",                       /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo sj_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    92,                              /* lineNo */
    33,                              /* colNo */
    "dataLimits",                    /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo tj_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    93,                              /* lineNo */
    31,                              /* colNo */
    "simLimits",                     /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo uj_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    47,                              /* lineNo */
    18,                              /* colNo */
    "reflectivity",                  /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo vj_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    52,                              /* lineNo */
    16,                              /* colNo */
    "Simulation",                    /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo wj_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    57,                              /* lineNo */
    15,                              /* colNo */
    "allLayers",                     /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo xj_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    113,                             /* lineNo */
    17,                              /* colNo */
    "sldProfiles",                   /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo yj_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    114,                             /* lineNo */
    18,                              /* colNo */
    "reflectivity",                  /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo ak_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    115,                             /* lineNo */
    16,                              /* colNo */
    "Simulation",                    /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo bk_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    116,                             /* lineNo */
    18,                              /* colNo */
    "shifted_data",                  /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo ck_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    117,                             /* lineNo */
    15,                              /* colNo */
    "layerSlds",                     /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo dk_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    126,                             /* lineNo */
    15,                              /* colNo */
    "allLayers",                     /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtDCInfo mb_emlrtDCI = {
    33,                              /* lineNo */
    17,                              /* colNo */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    1                                                          /* checkKind */
};

static emlrtDCInfo nb_emlrtDCI = {
    32,                              /* lineNo */
    16,                              /* colNo */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    1                                                          /* checkKind */
};

static emlrtDCInfo ob_emlrtDCI = {
    32,                              /* lineNo */
    16,                              /* colNo */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    4                                                          /* checkKind */
};

static emlrtBCInfo ek_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    41,                              /* lineNo */
    36,                              /* colNo */
    "layerSlds",                     /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo fk_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    41,                              /* lineNo */
    36,                              /* colNo */
    "sldProfiles",                   /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo gk_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    41,                              /* lineNo */
    36,                              /* colNo */
    "shifted_data",                  /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo hk_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    41,                              /* lineNo */
    36,                              /* colNo */
    "reflectivity",                  /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo ik_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    41,                              /* lineNo */
    36,                              /* colNo */
    "Simulation",                    /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo jk_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    41,                              /* lineNo */
    36,                              /* colNo */
    "allLayers",                     /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo kk_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    77,                              /* lineNo */
    77,                              /* colNo */
    "cBacks",                        /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo lk_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    77,                              /* lineNo */
    87,                              /* colNo */
    "cShifts",                       /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo mk_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    77,                              /* lineNo */
    98,                              /* colNo */
    "cScales",                       /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo nk_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    77,                              /* lineNo */
    109,                             /* colNo */
    "cNbas",                         /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo ok_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    77,                              /* lineNo */
    118,                             /* colNo */
    "cNbss",                         /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo pk_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    77,                              /* lineNo */
    127,                             /* colNo */
    "cRes",                          /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo qk_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    82,                              /* lineNo */
    52,                              /* colNo */
    "contrastLayers",                /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo rk_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    112,                             /* lineNo */
    5,                               /* colNo */
    "outSsubs",                      /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo sk_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    118,                             /* lineNo */
    5,                               /* colNo */
    "chis",                          /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo tk_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    113,                             /* lineNo */
    5,                               /* colNo */
    "sldProfiles",                   /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo uk_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    114,                             /* lineNo */
    5,                               /* colNo */
    "reflectivity",                  /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo vk_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    115,                             /* lineNo */
    5,                               /* colNo */
    "Simulation",                    /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo wk_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    116,                             /* lineNo */
    5,                               /* colNo */
    "shifted_data",                  /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo xk_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    117,                             /* lineNo */
    5,                               /* colNo */
    "layerSlds",                     /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo yk_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    119,                             /* lineNo */
    5,                               /* colNo */
    "backgs",                        /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo al_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    120,                             /* lineNo */
    5,                               /* colNo */
    "qshifts",                       /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo bl_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    121,                             /* lineNo */
    5,                               /* colNo */
    "sfs",                           /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo cl_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    122,                             /* lineNo */
    5,                               /* colNo */
    "nbas",                          /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo dl_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    123,                             /* lineNo */
    5,                               /* colNo */
    "nbss",                          /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo el_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    124,                             /* lineNo */
    5,                               /* colNo */
    "resols",                        /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo fl_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    125,                             /* lineNo */
    5,                               /* colNo */
    "allRoughs",                     /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo gl_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    126,                             /* lineNo */
    5,                               /* colNo */
    "allLayers",                     /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo hl_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    57,                              /* lineNo */
    5,                               /* colNo */
    "allLayers",                     /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo il_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    52,                              /* lineNo */
    5,                               /* colNo */
    "Simulation",                    /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo jl_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    47,                              /* lineNo */
    5,                               /* colNo */
    "reflectivity",                  /* aName */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtRTEInfo am_emlrtRTEI = {
    32,                              /* lineNo */
    10,                              /* colNo */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo bm_emlrtRTEI = {
    4,                               /* lineNo */
    18,                              /* colNo */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo cm_emlrtRTEI = {
    41,                              /* lineNo */
    36,                              /* colNo */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo dm_emlrtRTEI = {
    47,                              /* lineNo */
    5,                               /* colNo */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo em_emlrtRTEI = {
    52,                              /* lineNo */
    5,                               /* colNo */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo fm_emlrtRTEI = {
    57,                              /* lineNo */
    5,                               /* colNo */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo gm_emlrtRTEI = {
    39,                              /* lineNo */
    12,                              /* colNo */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo hm_emlrtRTEI = {
    90,                              /* lineNo */
    16,                              /* colNo */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo im_emlrtRTEI = {
    113,                             /* lineNo */
    5,                               /* colNo */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo jm_emlrtRTEI = {
    114,                             /* lineNo */
    5,                               /* colNo */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo km_emlrtRTEI = {
    115,                             /* lineNo */
    5,                               /* colNo */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo lm_emlrtRTEI = {
    116,                             /* lineNo */
    5,                               /* colNo */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo mm_emlrtRTEI = {
    117,                             /* lineNo */
    5,                               /* colNo */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo nm_emlrtRTEI = {
    126,                             /* lineNo */
    5,                               /* colNo */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo om_emlrtRTEI = {
    65,                              /* lineNo */
    1,                               /* colNo */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pName */
};

static emlrtRTEInfo pm_emlrtRTEI = {
    82,                              /* lineNo */
    5,                               /* colNo */
    "standardTF_stanlay_paraPoints", /* fName */
    "C:\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\standard_"
    "TF\\standardTF_stanLay\\standardTF_stanlay_paraPoints.m" /* pName */
};

/* Function Definitions */
void standardTF_stanlay_paraPoints(
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
  emxArray_cell_wrap_17 *outParameterisedLayers;
  emxArray_real_T *Simul;
  emxArray_real_T *b_problemDef_cells;
  emxArray_real_T *b_shifted_dat;
  emxArray_real_T *layerSld;
  emxArray_real_T *reflect;
  emxArray_real_T *resampledLayers;
  emxArray_real_T *shifted_dat;
  emxArray_real_T *sldProfile;
  emxArray_real_T *theseLayers;
  emxArray_real_T *thisContrastLayers;
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
  /*  Standard Layers calculation paralelised over the inner loop */
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
  calcSld = controls->calcSld;
  /*  Allocate the memory for the output arrays before the main loop */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &ob_emlrtDCI,
                                (emlrtCTX)sp);
  }
  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &nb_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &am_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &mb_emlrtDCI,
                            (emlrtCTX)sp);
  }
  problemDef_tmp_tmp = (int32_T)problemDef->numberOfContrasts;
  i = layerSlds->size[0];
  layerSlds->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &bm_emlrtRTEI);
  for (i = 0; i < problemDef_tmp_tmp; i++) {
    b_layerSlds = layerSlds->size[0] - 1;
    if (i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, layerSlds->size[0] - 1, &ek_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    layerSlds->data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &ek_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
    layerSlds->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[i].f1, i1, &bm_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = sldProfiles->size[0];
  sldProfiles->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &bm_emlrtRTEI);
  for (i = 0; i < problemDef_tmp_tmp; i++) {
    b_layerSlds = sldProfiles->size[0] - 1;
    if (i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, sldProfiles->size[0] - 1,
                                    &fk_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &fk_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sldProfiles->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = shifted_data->size[0];
  shifted_data->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &bm_emlrtRTEI);
  for (i = 0; i < problemDef_tmp_tmp; i++) {
    b_layerSlds = shifted_data->size[0] - 1;
    if (i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, shifted_data->size[0] - 1,
                                    &gk_emlrtBCI, (emlrtCTX)sp);
    }
    shifted_data->data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &gk_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    shifted_data->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = reflectivity->size[0];
  reflectivity->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &bm_emlrtRTEI);
  for (i = 0; i < problemDef_tmp_tmp; i++) {
    b_layerSlds = reflectivity->size[0] - 1;
    if (i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, reflectivity->size[0] - 1,
                                    &hk_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &hk_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = reflectivity->data[i].f1->size[0] * reflectivity->data[i].f1->size[1];
    reflectivity->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[i].f1, i1, &bm_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &wb_emlrtRTEI, (emlrtCTX)sp);
  i = reflectivity->size[0];
  reflectivity->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &cm_emlrtRTEI);
  for (b_i = 0; b_i < problemDef_tmp_tmp; b_i++) {
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &uj_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity->data[b_i].f1->size[0] *
        reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &dm_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &uj_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity->data[b_i].f1->size[0] *
        reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &dm_emlrtRTEI);
    i = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &uj_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &jl_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &jl_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &jl_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = Simulation->size[0];
  Simulation->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &bm_emlrtRTEI);
  for (i = 0; i < problemDef_tmp_tmp; i++) {
    b_layerSlds = Simulation->size[0] - 1;
    if (i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, Simulation->size[0] - 1, &ik_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation->data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &ik_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = Simulation->data[i].f1->size[0] * Simulation->data[i].f1->size[1];
    Simulation->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[i].f1, i1, &bm_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &xb_emlrtRTEI, (emlrtCTX)sp);
  i = Simulation->size[0];
  Simulation->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &cm_emlrtRTEI);
  for (b_i = 0; b_i < problemDef_tmp_tmp; b_i++) {
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &vj_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &em_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &vj_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &em_emlrtRTEI);
    i = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &vj_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &il_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &il_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &il_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = allLayers->size[0];
  allLayers->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &bm_emlrtRTEI);
  for (i = 0; i < problemDef_tmp_tmp; i++) {
    b_layerSlds = allLayers->size[0] - 1;
    if (i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, allLayers->size[0] - 1, &jk_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[i].f1->size[0] = 0;
    if (i > b_layerSlds) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_layerSlds, &jk_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[i].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &yb_emlrtRTEI, (emlrtCTX)sp);
  i = allLayers->size[0];
  allLayers->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &cm_emlrtRTEI);
  for (b_i = 0; b_i < problemDef_tmp_tmp; b_i++) {
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &wj_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &fm_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &wj_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &fm_emlrtRTEI);
    i = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &wj_emlrtBCI, (emlrtCTX)sp);
    }
    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &hl_emlrtBCI, (emlrtCTX)sp);
    }
    allLayers->data[b_i].f1->data[1] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &hl_emlrtBCI, (emlrtCTX)sp);
    }
    allLayers->data[b_i].f1->data[2] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &hl_emlrtBCI, (emlrtCTX)sp);
    }
    allLayers->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxInit_cell_wrap_17(sp, &outParameterisedLayers, 2, &om_emlrtRTEI, true);
  /*  end memory allocation. */
  /*  First we need to allocate the absolute values of the input */
  /*  parameters to all the layers in the layers list. This only needs */
  /*  to be done once, and so is done outside the contrasts loop */
  st.site = &eh_emlrtRSI;
  allocateParamsToLayers(&st, problemDef->params, problemDef_cells->f6,
                         outParameterisedLayers);
  /*  Resample params if required */
  /*  Loop over all the contrasts */
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &ac_emlrtRTEI, (emlrtCTX)sp);
  i = outSsubs->size[0];
  outSsubs->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_real_T(sp, outSsubs, i, &gm_emlrtRTEI);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &cm_emlrtRTEI);
  i = reflectivity->size[0];
  reflectivity->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &cm_emlrtRTEI);
  i = Simulation->size[0];
  Simulation->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &cm_emlrtRTEI);
  i = shifted_data->size[0];
  shifted_data->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &cm_emlrtRTEI);
  i = layerSlds->size[0];
  layerSlds->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &cm_emlrtRTEI);
  i = chis->size[0];
  chis->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_real_T(sp, chis, i, &gm_emlrtRTEI);
  i = qshifts->size[0];
  qshifts->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_real_T(sp, qshifts, i, &gm_emlrtRTEI);
  i = sfs->size[0];
  sfs->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_real_T(sp, sfs, i, &gm_emlrtRTEI);
  i = nbas->size[0];
  nbas->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_real_T(sp, nbas, i, &gm_emlrtRTEI);
  i = nbss->size[0];
  nbss->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_real_T(sp, nbss, i, &gm_emlrtRTEI);
  i = resols->size[0];
  resols->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_real_T(sp, resols, i, &gm_emlrtRTEI);
  i = allRoughs->size[0];
  allRoughs->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_real_T(sp, allRoughs, i, &gm_emlrtRTEI);
  i = allLayers->size[0];
  allLayers->size[0] = problemDef_tmp_tmp;
  emxEnsureCapacity_cell_wrap_14(sp, allLayers, i, &cm_emlrtRTEI);
  emxInit_real_T(sp, &thisContrastLayers, 2, &pm_emlrtRTEI, true);
  emxInit_real_T(sp, &sldProfile, 2, &bm_emlrtRTEI, true);
  emxInit_real_T(sp, &shifted_dat, 2, &bm_emlrtRTEI, true);
  emxInit_real_T(sp, &resampledLayers, 2, &bm_emlrtRTEI, true);
  emxInit_real_T(sp, &layerSld, 2, &ph_emlrtRTEI, true);
  emxInit_real_T(sp, &theseLayers, 2, &bm_emlrtRTEI, true);
  emxInit_real_T(sp, &reflect, 2, &bm_emlrtRTEI, true);
  emxInit_real_T(sp, &Simul, 2, &bm_emlrtRTEI, true);
  emxInit_real_T(sp, &b_shifted_dat, 1, &nh_emlrtRTEI, true);
  emxInit_real_T(sp, &b_problemDef_cells, 2, &hm_emlrtRTEI, true);
  for (b_i = 0; b_i < problemDef_tmp_tmp; b_i++) {
    /*  Extract the relevant parameter values for this contrast */
    /*  from the input arrays. */
    /*  First need to decide which values of the backrounds, scalefactors */
    /*  data shifts and bulk contrasts are associated with this contrast */
    if ((int32_T)(b_i + 1U) > problemDef->contrastBacks->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastBacks->size[1],
                                    &kk_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastShifts->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastShifts->size[1],
                                    &lk_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastScales->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastScales->size[1],
                                    &mk_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastNbas->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastNbas->size[1],
                                    &nk_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastNbss->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastNbss->size[1],
                                    &ok_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)(b_i + 1U) > problemDef->contrastRes->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1,
                                    problemDef->contrastRes->size[1],
                                    &pk_emlrtBCI, (emlrtCTX)sp);
    }
    st.site = &fh_emlrtRSI;
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
                                    &qk_emlrtBCI, (emlrtCTX)sp);
    }
    st.site = &gh_emlrtRSI;
    allocateLayersForContrast(&st, problemDef_cells->f5->data[b_i].f1,
                              outParameterisedLayers, thisContrastLayers);
    /*  For the other parameters, we extract the correct ones from the input */
    /*  arrays */
    if (1 > problemDef->params->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, problemDef->params->size[1],
                                    &mj_emlrtBCI, (emlrtCTX)sp);
    }
    /*  Substrate roughness is always first parameter for standard layers */
    if (b_i > problemDef_cells->f1->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f1->size[1] - 1,
                                    &qj_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i + 1 > problemDef->resample->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, problemDef->resample->size[1],
                                    &nj_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f2->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f2->size[1] - 1,
                                    &rj_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i + 1 > problemDef->dataPresent->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                                    problemDef->dataPresent->size[1],
                                    &oj_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f3->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f3->size[1] - 1,
                                    &sj_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > problemDef_cells->f4->size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, problemDef_cells->f4->size[1] - 1,
                                    &tj_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i + 1 > problemDef->contrastBacksType->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                                    problemDef->contrastBacksType->size[1],
                                    &pj_emlrtBCI, (emlrtCTX)sp);
    }
    /*  Now call the core standardTF_stanlay reflectivity calculation */
    /*  In this case we are single cored, so we do not parallelise over */
    /*  points */
    /*  Call the core layers calculation */
    st.site = &hh_emlrtRSI;
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
    groupLayers_Mod(&b_st, thisContrastLayers, problemDef->params->data[0],
                    problemDef->geometry, thisNba, thisNbs, theseLayers,
                    &ssubs);
    if (b_i + 1 > outSsubs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, outSsubs->size[0], &rk_emlrtBCI,
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
      i = resampledLayers->size[0] * resampledLayers->size[1];
      resampledLayers->size[0] = layerSld->size[0];
      resampledLayers->size[1] = 3;
      emxEnsureCapacity_real_T(&st, resampledLayers, i, &jh_emlrtRTEI);
      b_layerSlds = layerSld->size[0] * 3;
      for (i = 0; i < b_layerSlds; i++) {
        resampledLayers->data[i] = layerSld->data[i];
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
      i = resampledLayers->size[0] * resampledLayers->size[1];
      resampledLayers->size[0] = 1;
      resampledLayers->size[1] = 3;
      emxEnsureCapacity_real_T(&st, resampledLayers, i, &kh_emlrtRTEI);
      resampledLayers->data[0] = 0.0;
      resampledLayers->data[1] = 0.0;
      resampledLayers->data[2] = 0.0;
    }
    /*  Apply scale factors and q shifts to the data */
    i = b_problemDef_cells->size[0] * b_problemDef_cells->size[1];
    b_problemDef_cells->size[0] = problemDef_cells->f2->data[b_i].f1->size[0];
    b_problemDef_cells->size[1] = problemDef_cells->f2->data[b_i].f1->size[1];
    emxEnsureCapacity_real_T(&st, b_problemDef_cells, i, &hm_emlrtRTEI);
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
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, chis->size[0], &sk_emlrtBCI,
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
                                    &xj_emlrtBCI, (emlrtCTX)sp);
    }
    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &im_emlrtRTEI);
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &xj_emlrtBCI, (emlrtCTX)sp);
    }
    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &im_emlrtRTEI);
    i = sldProfiles->size[0];
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &xj_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &xj_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &tk_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      sldProfiles->data[b_i].f1->data[i1] = sldProfile->data[i1];
    }
    b_layerSlds = reflect->size[0] * 2;
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &yj_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity->data[b_i].f1->size[0] *
        reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = reflect->size[0];
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &jm_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &yj_emlrtBCI, (emlrtCTX)sp);
    }
    i = reflectivity->data[b_i].f1->size[0] *
        reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i, &jm_emlrtRTEI);
    i = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &yj_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &yj_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &uk_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      reflectivity->data[b_i].f1->data[i1] = reflect->data[i1];
    }
    b_layerSlds = Simul->size[0] * 2;
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &ak_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = Simul->size[0];
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &km_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &ak_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &km_emlrtRTEI);
    i = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &ak_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &ak_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &vk_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      Simulation->data[b_i].f1->data[i1] = Simul->data[i1];
    }
    b_layerSlds = shifted_dat->size[0] * shifted_dat->size[1];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &bk_emlrtBCI, (emlrtCTX)sp);
    }
    i = shifted_data->data[b_i].f1->size[0] *
        shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[0] = shifted_dat->size[0];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &lm_emlrtRTEI);
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &bk_emlrtBCI, (emlrtCTX)sp);
    }
    i = shifted_data->data[b_i].f1->size[0] *
        shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[1] = shifted_dat->size[1];
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &lm_emlrtRTEI);
    i = shifted_data->size[0];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &bk_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &bk_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &wk_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      shifted_data->data[b_i].f1->data[i1] = shifted_dat->data[i1];
    }
    b_layerSlds = theseLayers->size[0] * 3;
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                    &ck_emlrtBCI, (emlrtCTX)sp);
    }
    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = theseLayers->size[0];
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &mm_emlrtRTEI);
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                    &ck_emlrtBCI, (emlrtCTX)sp);
    }
    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &mm_emlrtRTEI);
    i = layerSlds->size[0];
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                    &ck_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                    &ck_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &xk_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      layerSlds->data[b_i].f1->data[i1] = theseLayers->data[i1];
    }
    if (b_i + 1 > backgs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, backgs->size[0], &yk_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    backgs->data[b_i] = thisBackground;
    if (b_i + 1 > qshifts->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, qshifts->size[0], &al_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    qshifts->data[b_i] = thisQshift;
    if (b_i + 1 > sfs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, sfs->size[0], &bl_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sfs->data[b_i] = thisSf;
    if (b_i + 1 > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbas->size[0], &cl_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    nbas->data[b_i] = thisNba;
    if (b_i + 1 > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, nbss->size[0], &dl_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    nbss->data[b_i] = thisNbs;
    if (b_i + 1 > resols->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, resols->size[0], &el_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    resols->data[b_i] = thisResol;
    if (b_i + 1 > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, allRoughs->size[0],
                                    &fl_emlrtBCI, (emlrtCTX)sp);
    }
    allRoughs->data[b_i] = problemDef->params->data[0];
    b_layerSlds = resampledLayers->size[0] * 3;
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &dk_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = resampledLayers->size[0];
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &nm_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &dk_emlrtBCI, (emlrtCTX)sp);
    }
    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &nm_emlrtRTEI);
    i = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &dk_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                    &dk_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_layerSlds; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &gl_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      allLayers->data[b_i].f1->data[i1] = resampledLayers->data[i1];
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
  emxFree_real_T(&resampledLayers);
  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&sldProfile);
  emxFree_real_T(&thisContrastLayers);
  emxFree_cell_wrap_17(&outParameterisedLayers);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (standardTF_stanlay_paraPoints.c) */
