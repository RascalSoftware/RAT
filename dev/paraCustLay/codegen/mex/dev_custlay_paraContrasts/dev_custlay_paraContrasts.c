/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * dev_custlay_paraContrasts.c
 *
 * Code generation for function 'dev_custlay_paraContrasts'
 *
 */

/* Include files */
#include "dev_custlay_paraContrasts.h"
#include "backSort.h"
#include "dev_custlay_paraContrasts_data.h"
#include "dev_custlay_paraContrasts_emxutil.h"
#include "dev_custlay_paraContrasts_types.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    68,                          /* lineNo */
    "dev_custlay_paraContrasts", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    79,                          /* lineNo */
    "dev_custlay_paraContrasts", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    102,                         /* lineNo */
    "dev_custlay_paraContrasts", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pathName */
};

static emlrtMCInfo emlrtMCI = {
    23,                         /* lineNo */
    2,                          /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtRTEInfo emlrtRTEI = {
    51,                          /* lineNo */
    9,                           /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo b_emlrtRTEI = {
    56,                          /* lineNo */
    9,                           /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    61,                          /* lineNo */
    9,                           /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pName */
};

static emlrtDCInfo emlrtDCI = {
    74,                          /* lineNo */
    14,                          /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    1                              /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = {
    74,                          /* lineNo */
    12,                          /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    86,                          /* lineNo */
    27,                          /* colNo */
    "allRoughs",                 /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    88,                          /* lineNo */
    29,                          /* colNo */
    "resample",                  /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    91,                          /* lineNo */
    35,                          /* colNo */
    "dataPresent",               /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    94,                          /* lineNo */
    31,                          /* colNo */
    "backsType",                 /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    82,                          /* lineNo */
    36,                          /* colNo */
    "allLayers",                 /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    87,                          /* lineNo */
    37,                          /* colNo */
    "repeatLayers",              /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    90,                          /* lineNo */
    24,                          /* colNo */
    "allData",                   /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    92,                          /* lineNo */
    33,                          /* colNo */
    "dataLimits",                /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    93,                          /* lineNo */
    31,                          /* colNo */
    "simLimits",                 /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    9,                          /* lineNo */
    23,                         /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "loopMatalbCustlayWrapper.m", /* pName */
    1                             /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    11,                         /* lineNo */
    20,                         /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "loopMatalbCustlayWrapper.m", /* pName */
    1                             /* checkKind */
};

static emlrtRTEInfo e_emlrtRTEI = {
    13,                         /* lineNo */
    10,                         /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    28,                         /* lineNo */
    10,                         /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    29,                         /* lineNo */
    30,                         /* colNo */
    "tempAllLayers",            /* aName */
    "loopMatalbCustlayWrapper", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "loopMatalbCustlayWrapper.m", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    52,                          /* lineNo */
    18,                          /* colNo */
    "reflectivity",              /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    57,                          /* lineNo */
    16,                          /* colNo */
    "Simulation",                /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    14,                         /* lineNo */
    16,                         /* colNo */
    "allLayers",                /* aName */
    "loopMatalbCustlayWrapper", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "loopMatalbCustlayWrapper.m", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    15,                         /* lineNo */
    20,                         /* colNo */
    "tempAllLayers",            /* aName */
    "loopMatalbCustlayWrapper", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "loopMatalbCustlayWrapper.m", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    34,                         /* lineNo */
    16,                         /* colNo */
    "allLayers",                /* aName */
    "loopMatalbCustlayWrapper", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "loopMatalbCustlayWrapper.m", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    114,                         /* lineNo */
    17,                          /* colNo */
    "sldProfiles",               /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    115,                         /* lineNo */
    18,                          /* colNo */
    "reflectivity",              /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    116,                         /* lineNo */
    16,                          /* colNo */
    "Simulation",                /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    117,                         /* lineNo */
    18,                          /* colNo */
    "shifted_data",              /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    118,                         /* lineNo */
    15,                          /* colNo */
    "layerSlds",                 /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    119,                         /* lineNo */
    15,                          /* colNo */
    "allLayers",                 /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    37,                          /* lineNo */
    17,                          /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    1                              /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    36,                          /* lineNo */
    16,                          /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    1                              /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    36,                          /* lineNo */
    16,                          /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    4                              /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    45,                          /* lineNo */
    36,                          /* colNo */
    "layerSlds",                 /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    45,                          /* lineNo */
    36,                          /* colNo */
    "sldProfiles",               /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    45,                          /* lineNo */
    36,                          /* colNo */
    "shifted_data",              /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    45,                          /* lineNo */
    36,                          /* colNo */
    "reflectivity",              /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    45,                          /* lineNo */
    36,                          /* colNo */
    "Simulation",                /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    68,                          /* lineNo */
    1,                           /* colNo */
    "tempAllLayers",             /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    68,                          /* lineNo */
    1,                           /* colNo */
    "allLayers",                 /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    15,                         /* lineNo */
    6,                          /* colNo */
    "tempAllLayers",            /* aName */
    "loopMatalbCustlayWrapper", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "loopMatalbCustlayWrapper.m", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    34,                         /* lineNo */
    6,                          /* colNo */
    "allLayers",                /* aName */
    "loopMatalbCustlayWrapper", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "loopMatalbCustlayWrapper.m", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    79,                          /* lineNo */
    77,                          /* colNo */
    "cBacks",                    /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    79,                          /* lineNo */
    87,                          /* colNo */
    "cShifts",                   /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    79,                          /* lineNo */
    98,                          /* colNo */
    "cScales",                   /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    79,                          /* lineNo */
    109,                         /* colNo */
    "cNbas",                     /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    79,                          /* lineNo */
    118,                         /* colNo */
    "cNbss",                     /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    79,                          /* lineNo */
    127,                         /* colNo */
    "cRes",                      /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    113,                         /* lineNo */
    5,                           /* colNo */
    "outSsubs",                  /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    114,                         /* lineNo */
    5,                           /* colNo */
    "sldProfiles",               /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    115,                         /* lineNo */
    5,                           /* colNo */
    "reflectivity",              /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    116,                         /* lineNo */
    5,                           /* colNo */
    "Simulation",                /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    117,                         /* lineNo */
    5,                           /* colNo */
    "shifted_data",              /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    118,                         /* lineNo */
    5,                           /* colNo */
    "layerSlds",                 /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    119,                         /* lineNo */
    5,                           /* colNo */
    "allLayers",                 /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    121,                         /* lineNo */
    5,                           /* colNo */
    "chis",                      /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    122,                         /* lineNo */
    5,                           /* colNo */
    "backgs",                    /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    123,                         /* lineNo */
    5,                           /* colNo */
    "qshifts",                   /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    124,                         /* lineNo */
    5,                           /* colNo */
    "sfs",                       /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    125,                         /* lineNo */
    5,                           /* colNo */
    "nbas",                      /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    126,                         /* lineNo */
    5,                           /* colNo */
    "nbss",                      /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    127,                         /* lineNo */
    5,                           /* colNo */
    "resols",                    /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    128,                         /* lineNo */
    5,                           /* colNo */
    "allRoughs",                 /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    14,                         /* lineNo */
    6,                          /* colNo */
    "allLayers",                /* aName */
    "loopMatalbCustlayWrapper", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "loopMatalbCustlayWrapper.m", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    62,                          /* lineNo */
    5,                           /* colNo */
    "allLayers",                 /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    57,                          /* lineNo */
    5,                           /* colNo */
    "Simulation",                /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    52,                          /* lineNo */
    5,                           /* colNo */
    "reflectivity",              /* aName */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m", /* pName */
    0                              /* checkKind */
};

static emlrtRTEInfo y_emlrtRTEI = {
    25,                          /* lineNo */
    33,                          /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    36,                          /* lineNo */
    10,                          /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    3,                           /* lineNo */
    18,                          /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    45,                          /* lineNo */
    36,                          /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo db_emlrtRTEI = {
    52,                          /* lineNo */
    5,                           /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = {
    57,                          /* lineNo */
    5,                           /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = {
    68,                          /* lineNo */
    1,                           /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = {
    9,                          /* lineNo */
    41,                         /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    14,                         /* lineNo */
    6,                          /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = {
    15,                         /* lineNo */
    6,                          /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = {
    24,                         /* lineNo */
    57,                         /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = {
    34,                         /* lineNo */
    6,                          /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = {
    43,                          /* lineNo */
    12,                          /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = {
    114,                         /* lineNo */
    5,                           /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = {
    115,                         /* lineNo */
    5,                           /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = {
    116,                         /* lineNo */
    5,                           /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = {
    117,                         /* lineNo */
    5,                           /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = {
    118,                         /* lineNo */
    5,                           /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = {
    119,                         /* lineNo */
    5,                           /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = {
    90,                          /* lineNo */
    5,                           /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = {
    20,                          /* lineNo */
    2,                           /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = {
    22,                          /* lineNo */
    2,                           /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = {
    2,                           /* lineNo */
    51,                          /* colNo */
    "dev_custlay_paraContrasts", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "dev_custlay_paraContrasts.m" /* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = {
    9,                          /* lineNo */
    2,                          /* colNo */
    "loopMatalbCustlayWrapper", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "loopMatalbCustlayWrapper.m" /* pName */
};

static emlrtRSInfo pg_emlrtRSI = {
    23,                         /* lineNo */
    "loopMatalbCustlayWrapper", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "loopMatalbCustlayWrapper.m" /* pathName */
};

static emlrtRSInfo qg_emlrtRSI = {
    38,                         /* lineNo */
    "loopMatalbCustlayWrapper", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
    "loopMatalbCustlayWrapper.m" /* pathName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_cell_wrap_16 *y);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void d_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *tempAllRoughs,
                               const char_T *identifier, emxArray_real_T *y);

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *tempAllLayers,
                             const char_T *identifier,
                             emxArray_cell_wrap_16 *y);

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);

static void feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                  const mxArray *d, const mxArray *e, const mxArray *f,
                  const mxArray *g, const mxArray *h, const mxArray *i,
                  const mxArray *j, const mxArray *k, const mxArray *l,
                  const mxArray *m, const mxArray *n, const mxArray *o,
                  const mxArray *p, const mxArray *q, const mxArray *r,
                  emlrtMCInfo *location, const mxArray **s, const mxArray **t);

static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret);

static void kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_cell_wrap_16 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T n;
  int32_T sizes;
  char_T str[11];
  boolean_T b;
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  n = -1;
  b = true;
  emlrtCheckVsCell((emlrtCTX)sp, parentId, u, 1U, &n, &b, &sizes);
  n = y->size[0];
  y->size[0] = sizes;
  emxEnsureCapacity_cell_wrap_16(sp, y, n, (emlrtRTEInfo *)NULL);
  for (n = 0; n < sizes; n++) {
    sprintf(&str[0], "%d", n + 1);
    thisId.fIdentifier = &str[0];
    c_emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, n)),
                       &thisId, y->data[n].f1);
  }
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  jb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void d_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *tempAllRoughs,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  e_emlrt_marshallIn(sp, emlrtAlias(tempAllRoughs), &thisId, y);
  emlrtDestroyArray(&tempAllRoughs);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  kb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *tempAllLayers,
                             const char_T *identifier, emxArray_cell_wrap_16 *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(tempAllLayers), &thisId, y);
  emlrtDestroyArray(&tempAllLayers);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T iv[2];
  int32_T b_i;
  int32_T i;
  y = NULL;
  iv[0] = 1;
  iv[1] = u->size[1];
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < u->size[1]; b_i++) {
    pData[i] = u->data[b_i];
    i++;
  }
  emlrtAssign(&y, m);
  return y;
}

static void feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
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

static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static void kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

void dev_custlay_paraContrasts(
    const emlrtStack *sp, const struct0_T *problemDef,
    const cell_8 *problemDef_cells, const struct1_T *problemDef_limits,
    const struct2_T *controls, emxArray_real_T *outSsubs,
    emxArray_real_T *backgs, emxArray_real_T *qshifts, emxArray_real_T *sfs,
    emxArray_real_T *nbas, emxArray_real_T *nbss, emxArray_real_T *resols,
    emxArray_real_T *chis, emxArray_cell_wrap_9 *reflectivity,
    emxArray_cell_wrap_9 *Simulation, emxArray_cell_wrap_10 *shifted_data,
    emxArray_cell_wrap_11 *layerSlds, emxArray_cell_wrap_9 *sldProfiles,
    emxArray_cell_wrap_10 *allLayers, emxArray_real_T *allRoughs)
{
  static const int32_T iv[2] = {1, 22};
  static const char_T u[22] = {'l', 'o', 'o', 'p', 'M', 'a', 't', 'l',
                               'a', 'b', 'C', 'u', 's', 't', 'o', 'm',
                               'L', 'a', 'y', 'e', 'r', 's'};
  jmp_buf emlrtJBEnviron;
  jmp_buf *volatile emlrtJBStack;
  cell_wrap_6 b_u[3];
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_cell_wrap_10 *allData;
  emxArray_cell_wrap_10 *simLimits;
  emxArray_cell_wrap_13 *b_allLayers;
  emxArray_cell_wrap_16 *b_tempAllLayers;
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
  int32_T b_loop_ub;
  int32_T c_i;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T loop_ub;
  int32_T nParams;
  int32_T unnamed_idx_0_tmp_tmp;
  boolean_T emlrtHadParallelError = false;
  (void)problemDef_limits;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_cell_wrap_10(sp, &allData, 2, &tb_emlrtRTEI, true);
  /*  Multi threaded version of the custom layers over reflectivity contrasts */
  /*  for standardTF reflectivity calculation.  */
  /*  The function extracts the relevant parameters from the input */
  /*  arrays, allocates these on a pre-contrast basis, then calls the 'core'  */
  /*  calculation (the core layers standardTf calc is shared between multiple */
  /*  calculation types). */
  /*  This differs from the other two paralellisations in that the custom model
   */
  /*  files are processed in a paralell loop (using the Matlab Paralell */
  /*  Computing Toolbox) outside the main loop, before this is then processed */
  /*  in the compiled version using OpenMP. */
  /*  Extract individual cell arrays */
  i = allData->size[0] * allData->size[1];
  allData->size[0] = 1;
  allData->size[1] = problemDef_cells->f2->size[1];
  emxEnsureCapacity_cell_wrap_10(sp, allData, i, &y_emlrtRTEI);
  i = problemDef_cells->f2->size[1] - 1;
  for (i1 = 0; i1 <= i; i1++) {
    i2 = allData->data[i1].f1->size[0] * allData->data[i1].f1->size[1];
    allData->data[i1].f1->size[0] = problemDef_cells->f2->data[i1].f1->size[0];
    allData->data[i1].f1->size[1] = problemDef_cells->f2->data[i1].f1->size[1];
    emxEnsureCapacity_real_T(sp, allData->data[i1].f1, i2, &y_emlrtRTEI);
    loop_ub = problemDef_cells->f2->data[i1].f1->size[0] *
              problemDef_cells->f2->data[i1].f1->size[1];
    for (i2 = 0; i2 < loop_ub; i2++) {
      allData->data[i1].f1->data[i2] =
          problemDef_cells->f2->data[i1].f1->data[i2];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxInit_cell_wrap_10(sp, &simLimits, 2, &ub_emlrtRTEI, true);
  i = simLimits->size[0] * simLimits->size[1];
  simLimits->size[0] = 1;
  simLimits->size[1] = problemDef_cells->f4->size[1];
  emxEnsureCapacity_cell_wrap_10(sp, simLimits, i, &y_emlrtRTEI);
  i = problemDef_cells->f4->size[1] - 1;
  for (i1 = 0; i1 <= i; i1++) {
    i2 = simLimits->data[i1].f1->size[0] * simLimits->data[i1].f1->size[1];
    simLimits->data[i1].f1->size[0] = problemDef_cells->f4->data[i1].f1.size[0];
    simLimits->data[i1].f1->size[1] = problemDef_cells->f4->data[i1].f1.size[1];
    emxEnsureCapacity_real_T(sp, simLimits->data[i1].f1, i2, &y_emlrtRTEI);
    loop_ub = problemDef_cells->f4->data[i1].f1.size[0] *
              problemDef_cells->f4->data[i1].f1.size[1];
    for (i2 = 0; i2 < loop_ub; i2++) {
      simLimits->data[i1].f1->data[i2] =
          problemDef_cells->f4->data[i1].f1.data[i2];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = problemDef_cells->f5->size[1];
  for (i1 = 0; i1 < i; i1++) {
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = problemDef_cells->f6->size[0];
  for (i1 = 0; i1 < i; i1++) {
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
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
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &f_emlrtDCI,
                                (emlrtCTX)sp);
  }
  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &e_emlrtDCI,
                            (emlrtCTX)sp);
  }
  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &ab_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &d_emlrtDCI,
                            (emlrtCTX)sp);
  }
  unnamed_idx_0_tmp_tmp = (int32_T)problemDef->numberOfContrasts;
  i1 = layerSlds->size[0];
  layerSlds->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_11(sp, layerSlds, i1, &bb_emlrtRTEI);
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    loop_ub = layerSlds->size[0] - 1;
    if (i1 > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, layerSlds->size[0] - 1, &v_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    layerSlds->data[i1].f1->size[0] = 0;
    if (i1 > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, loop_ub, &v_emlrtBCI, (emlrtCTX)sp);
    }
    i2 = layerSlds->data[i1].f1->size[0] * layerSlds->data[i1].f1->size[1];
    layerSlds->data[i1].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[i1].f1, i2, &bb_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i1 = sldProfiles->size[0];
  sldProfiles->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, sldProfiles, i1, &bb_emlrtRTEI);
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    loop_ub = sldProfiles->size[0] - 1;
    if (i1 > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, sldProfiles->size[0] - 1,
                                    &w_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[i1].f1->size[0] = 0;
    if (i1 > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, loop_ub, &w_emlrtBCI, (emlrtCTX)sp);
    }
    i2 = sldProfiles->data[i1].f1->size[0] * sldProfiles->data[i1].f1->size[1];
    sldProfiles->data[i1].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[i1].f1, i2, &bb_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i1 = shifted_data->size[0];
  shifted_data->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, shifted_data, i1, &bb_emlrtRTEI);
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    loop_ub = shifted_data->size[0] - 1;
    if (i1 > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, shifted_data->size[0] - 1,
                                    &x_emlrtBCI, (emlrtCTX)sp);
    }
    shifted_data->data[i1].f1->size[0] = 0;
    if (i1 > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, loop_ub, &x_emlrtBCI, (emlrtCTX)sp);
    }
    shifted_data->data[i1].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i1 = reflectivity->size[0];
  reflectivity->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i1, &bb_emlrtRTEI);
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    loop_ub = reflectivity->size[0] - 1;
    if (i1 > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, reflectivity->size[0] - 1,
                                    &y_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[i1].f1->size[0] = 0;
    if (i1 > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, loop_ub, &y_emlrtBCI, (emlrtCTX)sp);
    }
    i2 =
        reflectivity->data[i1].f1->size[0] * reflectivity->data[i1].f1->size[1];
    reflectivity->data[i1].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[i1].f1, i2, &bb_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &emlrtRTEI, (emlrtCTX)sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i1, &cb_emlrtRTEI);
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &k_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = reflectivity->data[b_i].f1->size[0] *
         reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &db_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &k_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = reflectivity->data[b_i].f1->size[0] *
         reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &db_emlrtRTEI);
    i1 = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &k_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &ec_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &ec_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &ec_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i1 = Simulation->size[0];
  Simulation->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i1, &bb_emlrtRTEI);
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    loop_ub = Simulation->size[0] - 1;
    if (i1 > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, Simulation->size[0] - 1,
                                    &ab_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[i1].f1->size[0] = 0;
    if (i1 > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, loop_ub, &ab_emlrtBCI, (emlrtCTX)sp);
    }
    i2 = Simulation->data[i1].f1->size[0] * Simulation->data[i1].f1->size[1];
    Simulation->data[i1].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[i1].f1, i2, &bb_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &b_emlrtRTEI, (emlrtCTX)sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i1, &cb_emlrtRTEI);
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &l_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &eb_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &l_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &eb_emlrtRTEI);
    i1 = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &l_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &dc_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &dc_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &dc_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxInit_cell_wrap_13(sp, &b_allLayers, 1, &vb_emlrtRTEI, true);
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &c_emlrtRTEI, (emlrtCTX)sp);
  i1 = b_allLayers->size[0];
  b_allLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_13(sp, b_allLayers, i1, &cb_emlrtRTEI);
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    loop_ub = b_allLayers->size[0] - 1;
    if (b_i > b_allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, b_allLayers->size[0] - 1,
                                    &cc_emlrtBCI, (emlrtCTX)sp);
    }
    b_allLayers->data[b_i].f1[0] = 1.0;
    if (b_i > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, loop_ub, &cc_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    b_allLayers->data[b_i].f1[1] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_cell_wrap_13(&b_allLayers);
  /*    --- End Memory Allocation --- */
  /*  Call the Matlab parallel loop to process the custom models..... */
  st.site = &emlrtRSI;
  tempAllLayers = NULL;
  tempAllRoughs = NULL;
  /*  Wrapper function for calling 'loopMatlabCustomLayers'. This wrapper is */
  /*  necessary to deal with typedef problems for the coder if feval is used */
  /*  directly from the main function */
  if (unnamed_idx_0_tmp_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &b_emlrtDCI, &st);
  }
  emxInit_cell_wrap_16(&st, &b_tempAllLayers, 1, &wb_emlrtRTEI, true);
  i1 = b_tempAllLayers->size[0];
  b_tempAllLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_16(&st, b_tempAllLayers, i1, &fb_emlrtRTEI);
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    loop_ub = b_tempAllLayers->size[0] - 1;
    if (i1 > b_tempAllLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_tempAllLayers->size[0] - 1,
                                    &bb_emlrtBCI, &st);
    }
    b_tempAllLayers->data[i1].f1->size[0] = 0;
    if (i1 > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, loop_ub, &bb_emlrtBCI, &st);
    }
    b_tempAllLayers->data[i1].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  i1 = allLayers->size[0];
  allLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(&st, allLayers, i1, &fb_emlrtRTEI);
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    loop_ub = allLayers->size[0] - 1;
    if (i1 > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, allLayers->size[0] - 1, &cb_emlrtBCI,
                                    &st);
    }
    allLayers->data[i1].f1->size[0] = 0;
    if (i1 > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, loop_ub, &cb_emlrtBCI, &st);
    }
    allLayers->data[i1].f1->size[1] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  if (unnamed_idx_0_tmp_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &c_emlrtDCI, &st);
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &e_emlrtRTEI, &st);
  i1 = allLayers->size[0];
  allLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(&st, allLayers, i1, &gb_emlrtRTEI);
  i1 = b_tempAllLayers->size[0];
  b_tempAllLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_16(&st, b_tempAllLayers, i1, &gb_emlrtRTEI);
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &m_emlrtBCI,
                                    &st);
    }
    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 1;
    emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i1, &hb_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &m_emlrtBCI,
                                    &st);
    }
    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i1, &hb_emlrtRTEI);
    i1 = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &m_emlrtBCI,
                                    &st);
    }
    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &bc_emlrtBCI, &st);
    }
    allLayers->data[b_i].f1->data[1] = 1.0;
    /*  Type def as double (size not important) */
    if (b_i > b_tempAllLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, b_tempAllLayers->size[0] - 1,
                                    &n_emlrtBCI, &st);
    }
    i1 = b_tempAllLayers->data[b_i].f1->size[0] *
         b_tempAllLayers->data[b_i].f1->size[1];
    b_tempAllLayers->data[b_i].f1->size[0] = 1;
    emxEnsureCapacity_real_T(&st, b_tempAllLayers->data[b_i].f1, i1,
                             &ib_emlrtRTEI);
    if (b_i > b_tempAllLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, b_tempAllLayers->size[0] - 1,
                                    &n_emlrtBCI, &st);
    }
    i1 = b_tempAllLayers->data[b_i].f1->size[0] *
         b_tempAllLayers->data[b_i].f1->size[1];
    b_tempAllLayers->data[b_i].f1->size[1] = 5;
    emxEnsureCapacity_real_T(&st, b_tempAllLayers->data[b_i].f1, i1,
                             &ib_emlrtRTEI);
    i1 = b_tempAllLayers->size[0];
    if (b_i > b_tempAllLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, b_tempAllLayers->size[0] - 1,
                                    &n_emlrtBCI, &st);
    }
    for (i2 = 0; i2 < 5; i2++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &db_emlrtBCI, &st);
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
  emxInitMatrix_cell_wrap_6(&st, b_u, &bb_emlrtRTEI, true);
  emxInit_char_T(&st, &c_u, 2, &bb_emlrtRTEI, true);
  while (i1 < problemDef_cells->f14->size[1]) {
    emxCopyStruct_cell_wrap_6(
        &st, &b_u[0], &problemDef_cells->f14->data[i1].f1[0], &jb_emlrtRTEI);
    emxCopyStruct_cell_wrap_6(
        &st, &b_u[1], &problemDef_cells->f14->data[i1].f1[1], &jb_emlrtRTEI);
    emxCopyStruct_cell_wrap_6(
        &st, &b_u[2], &problemDef_cells->f14->data[i1].f1[2], &jb_emlrtRTEI);
    d_y = NULL;
    iv1[0] = 1;
    iv1[1] = 3;
    emlrtAssign(&d_y, emlrtCreateCellArrayR2014a(2, &iv1[0]));
    iv1[0] = 1;
    for (i2 = 0; i2 < 3; i2++) {
      b_i = c_u->size[0] * c_u->size[1];
      c_u->size[0] = 1;
      c_u->size[1] = b_u[i2].f1->size[1];
      emxEnsureCapacity_char_T(&st, c_u, b_i, &jb_emlrtRTEI);
      loop_ub = b_u[i2].f1->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
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
  b_st.site = &pg_emlrtRSI;
  feval(&b_st, y, emlrt_marshallOut(problemDef->contrastBacks),
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
        emlrt_marshallOut(problemDef->params), &emlrtMCI, &tempAllLayers,
        &tempAllRoughs);
  b_st.site = &pg_emlrtRSI;
  emlrt_marshallIn(&b_st, emlrtAlias(tempAllLayers), "tempAllLayers",
                   b_tempAllLayers);
  /*  All the following is intended to be casting from mxArray's to doubles. */
  /*  I'm not sure if all of this is necessary, but it compiles... */
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &f_emlrtRTEI, &st);
  i1 = allLayers->size[0];
  allLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(&st, allLayers, i1, &gb_emlrtRTEI);
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > b_tempAllLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, b_tempAllLayers->size[0] - 1,
                                    &j_emlrtBCI, &st);
    }
    loop_ub = b_tempAllLayers->data[b_i].f1->size[0] *
              b_tempAllLayers->data[b_i].f1->size[1];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &o_emlrtBCI,
                                    &st);
    }
    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = b_tempAllLayers->data[b_i].f1->size[0];
    emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i1, &kb_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &o_emlrtBCI,
                                    &st);
    }
    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = b_tempAllLayers->data[b_i].f1->size[1];
    emxEnsureCapacity_real_T(&st, allLayers->data[b_i].f1, i1, &kb_emlrtRTEI);
    i1 = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &o_emlrtBCI,
                                    &st);
    }
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &o_emlrtBCI,
                                    &st);
    }
    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &eb_emlrtBCI, &st);
      }
      allLayers->data[b_i].f1->data[i2] =
          b_tempAllLayers->data[b_i].f1->data[i2];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  emxFree_cell_wrap_16(&b_tempAllLayers);
  /* allLayers = tempAllLayers; */
  b_st.site = &qg_emlrtRSI;
  d_emlrt_marshallIn(&b_st, emlrtAlias(tempAllRoughs), "tempAllRoughs",
                     allRoughs);
  emlrtDestroyArray(&tempAllLayers);
  emlrtDestroyArray(&tempAllRoughs);
  /*  Multi cored over all contrasts */
  if (unnamed_idx_0_tmp_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &emlrtDCI,
                            (emlrtCTX)sp);
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &d_emlrtRTEI, (emlrtCTX)sp);
  i = outSsubs->size[0];
  outSsubs->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, outSsubs, i, &lb_emlrtRTEI);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, sldProfiles, i, &cb_emlrtRTEI);
  i = reflectivity->size[0];
  reflectivity->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &cb_emlrtRTEI);
  i = Simulation->size[0];
  Simulation->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &cb_emlrtRTEI);
  i = shifted_data->size[0];
  shifted_data->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, shifted_data, i, &cb_emlrtRTEI);
  i = layerSlds->size[0];
  layerSlds->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_11(sp, layerSlds, i, &cb_emlrtRTEI);
  i = chis->size[0];
  chis->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, chis, i, &lb_emlrtRTEI);
  i = qshifts->size[0];
  qshifts->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, qshifts, i, &lb_emlrtRTEI);
  i = sfs->size[0];
  sfs->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, sfs, i, &lb_emlrtRTEI);
  i = nbas->size[0];
  nbas->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, nbas, i, &lb_emlrtRTEI);
  i = nbss->size[0];
  nbss->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, nbss, i, &lb_emlrtRTEI);
  i = resols->size[0];
  resols->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_real_T(sp, resols, i, &lb_emlrtRTEI);
  loop_ub = unnamed_idx_0_tmp_tmp - 1;
  emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
#pragma omp parallel num_threads(emlrtAllocRegionTLSs(                         \
    sp->tls, omp_in_parallel(), omp_get_max_threads(),                         \
    omp_get_num_procs())) private(sldProfile, reflect, Simul, thisData,        \
                                  layerSld, resamLayers, thisSsubs,            \
                                  thisChiSquared, thisResol, thisNbs, thisNba, \
                                  thisSf, thisQshift, thisBackground,          \
                                  emlrtJBEnviron, d_st, c_i, b_loop_ub, i3,    \
                                  i4)                                          \
    firstprivate(c_st, emlrtHadParallelError)
  {
    if (setjmp(emlrtJBEnviron) == 0) {

      c_st.prev = sp;
      c_st.tls = emlrtAllocTLS((emlrtCTX)sp, omp_get_thread_num());
      c_st.site = NULL;
      emlrtSetJmpBuf(&c_st, &emlrtJBEnviron);
      d_st.prev = &c_st;
      d_st.tls = c_st.tls;
      emxInit_real_T(&c_st, &sldProfile, 2, &bb_emlrtRTEI, true);
      emxInit_real_T(&c_st, &reflect, 2, &bb_emlrtRTEI, true);
      emxInit_real_T(&c_st, &Simul, 2, &bb_emlrtRTEI, true);
      emxInit_real_T(&c_st, &thisData, 2, &sb_emlrtRTEI, true);
      emxInit_real_T(&c_st, &layerSld, 2, &bb_emlrtRTEI, true);
      emxInit_real_T(&c_st, &resamLayers, 2, &bb_emlrtRTEI, true);
    } else {
      emlrtHadParallelError = true;
    }
#pragma omp for nowait
    for (c_i = 0; c_i <= loop_ub; c_i++) {
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
                                        &fb_emlrtBCI, &c_st);
        }
        if ((int32_T)(c_i + 1U) > problemDef->contrastShifts->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(c_i + 1U), 1,
                                        problemDef->contrastShifts->size[1],
                                        &gb_emlrtBCI, &c_st);
        }
        if ((int32_T)(c_i + 1U) > problemDef->contrastScales->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(c_i + 1U), 1,
                                        problemDef->contrastScales->size[1],
                                        &hb_emlrtBCI, &c_st);
        }
        if ((int32_T)(c_i + 1U) > problemDef->contrastNbas->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(c_i + 1U), 1,
                                        problemDef->contrastNbas->size[1],
                                        &ib_emlrtBCI, &c_st);
        }
        if ((int32_T)(c_i + 1U) > problemDef->contrastNbss->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(c_i + 1U), 1,
                                        problemDef->contrastNbss->size[1],
                                        &jb_emlrtBCI, &c_st);
        }
        if ((int32_T)(c_i + 1U) > problemDef->contrastRes->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(c_i + 1U), 1,
                                        problemDef->contrastRes->size[1],
                                        &kb_emlrtBCI, &c_st);
        }
        d_st.site = &b_emlrtRSI;
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
                                        &e_emlrtBCI, &c_st);
        }
        /*  For the other parameters, we extract the correct ones from the input
         */
        /*  arrays */
        if (c_i + 1 > allRoughs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, allRoughs->size[0],
                                        &emlrtBCI, &c_st);
        }
        if (c_i > problemDef_cells->f1->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(
              c_i, 0, problemDef_cells->f1->size[1] - 1, &f_emlrtBCI, &c_st);
        }
        if (c_i + 1 > problemDef->resample->size[1]) {
          emlrtDynamicBoundsCheckR2012b(
              c_i + 1, 1, problemDef->resample->size[1], &b_emlrtBCI, &c_st);
        }
        if (c_i > allData->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, allData->size[1] - 1,
                                        &g_emlrtBCI, &c_st);
        }
        if (c_i + 1 > problemDef->dataPresent->size[1]) {
          emlrtDynamicBoundsCheckR2012b(
              c_i + 1, 1, problemDef->dataPresent->size[1], &c_emlrtBCI, &c_st);
        }
        if (c_i > problemDef_cells->f3->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(
              c_i, 0, problemDef_cells->f3->size[1] - 1, &h_emlrtBCI, &c_st);
        }
        if (c_i > simLimits->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, simLimits->size[1] - 1,
                                        &i_emlrtBCI, &c_st);
        }
        if (c_i + 1 > problemDef->contrastBacksType->size[1]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1,
                                        problemDef->contrastBacksType->size[1],
                                        &d_emlrtBCI, &c_st);
        }
        /*  Now call the core standardTF_stanlay reflectivity calculation */
        /*  In this case we are single cored, so we do not parallelise over */
        /*  points */
        /*  Call the reflectivity calculation */
        d_st.site = &c_emlrtRSI;
        standardTF_layers_core(
            &d_st, allLayers->data[c_i].f1, allRoughs->data[c_i],
            problemDef->geometry, thisNba, thisNbs,
            problemDef->resample->data[c_i], calcSld, thisSf, thisQshift,
            problemDef->dataPresent->data[c_i], allData->data[c_i].f1,
            problemDef_cells->f3->data[c_i].f1,
            (real_T *)simLimits->data[c_i].f1->data,
            *(int32_T(*)[2])simLimits->data[c_i].f1->size,
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
                                        &lb_emlrtBCI, &c_st);
        }
        outSsubs->data[c_i] = thisSsubs;
        b_loop_ub = sldProfile->size[0] * 2;
        if (c_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, sldProfiles->size[0] - 1,
                                        &p_emlrtBCI, &c_st);
        }
        i3 = sldProfiles->data[c_i].f1->size[0] *
             sldProfiles->data[c_i].f1->size[1];
        sldProfiles->data[c_i].f1->size[0] = sldProfile->size[0];
        emxEnsureCapacity_real_T(&c_st, sldProfiles->data[c_i].f1, i3,
                                 &mb_emlrtRTEI);
        if (c_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, sldProfiles->size[0] - 1,
                                        &p_emlrtBCI, &c_st);
        }
        i3 = sldProfiles->data[c_i].f1->size[0] *
             sldProfiles->data[c_i].f1->size[1];
        sldProfiles->data[c_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(&c_st, sldProfiles->data[c_i].f1, i3,
                                 &mb_emlrtRTEI);
        i3 = sldProfiles->size[0];
        if (c_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, sldProfiles->size[0] - 1,
                                        &p_emlrtBCI, &c_st);
        }
        if (c_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, sldProfiles->size[0] - 1,
                                        &p_emlrtBCI, &c_st);
        }
        for (i4 = 0; i4 < b_loop_ub; i4++) {
          if (c_i > i3 - 1) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3 - 1, &mb_emlrtBCI, &c_st);
          }
          sldProfiles->data[c_i].f1->data[i4] = sldProfile->data[i4];
        }
        b_loop_ub = reflect->size[0] * 2;
        if (c_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, reflectivity->size[0] - 1,
                                        &q_emlrtBCI, &c_st);
        }
        i3 = reflectivity->data[c_i].f1->size[0] *
             reflectivity->data[c_i].f1->size[1];
        reflectivity->data[c_i].f1->size[0] = reflect->size[0];
        emxEnsureCapacity_real_T(&c_st, reflectivity->data[c_i].f1, i3,
                                 &nb_emlrtRTEI);
        if (c_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, reflectivity->size[0] - 1,
                                        &q_emlrtBCI, &c_st);
        }
        i3 = reflectivity->data[c_i].f1->size[0] *
             reflectivity->data[c_i].f1->size[1];
        reflectivity->data[c_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(&c_st, reflectivity->data[c_i].f1, i3,
                                 &nb_emlrtRTEI);
        i3 = reflectivity->size[0];
        if (c_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, reflectivity->size[0] - 1,
                                        &q_emlrtBCI, &c_st);
        }
        if (c_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, reflectivity->size[0] - 1,
                                        &q_emlrtBCI, &c_st);
        }
        for (i4 = 0; i4 < b_loop_ub; i4++) {
          if (c_i > i3 - 1) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3 - 1, &nb_emlrtBCI, &c_st);
          }
          reflectivity->data[c_i].f1->data[i4] = reflect->data[i4];
        }
        b_loop_ub = Simul->size[0] * 2;
        if (c_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, Simulation->size[0] - 1,
                                        &r_emlrtBCI, &c_st);
        }
        i3 = Simulation->data[c_i].f1->size[0] *
             Simulation->data[c_i].f1->size[1];
        Simulation->data[c_i].f1->size[0] = Simul->size[0];
        emxEnsureCapacity_real_T(&c_st, Simulation->data[c_i].f1, i3,
                                 &ob_emlrtRTEI);
        if (c_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, Simulation->size[0] - 1,
                                        &r_emlrtBCI, &c_st);
        }
        i3 = Simulation->data[c_i].f1->size[0] *
             Simulation->data[c_i].f1->size[1];
        Simulation->data[c_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(&c_st, Simulation->data[c_i].f1, i3,
                                 &ob_emlrtRTEI);
        i3 = Simulation->size[0];
        if (c_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, Simulation->size[0] - 1,
                                        &r_emlrtBCI, &c_st);
        }
        if (c_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, Simulation->size[0] - 1,
                                        &r_emlrtBCI, &c_st);
        }
        for (i4 = 0; i4 < b_loop_ub; i4++) {
          if (c_i > i3 - 1) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3 - 1, &ob_emlrtBCI, &c_st);
          }
          Simulation->data[c_i].f1->data[i4] = Simul->data[i4];
        }
        b_loop_ub = thisData->size[0] * thisData->size[1];
        if (c_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, shifted_data->size[0] - 1,
                                        &s_emlrtBCI, &c_st);
        }
        i3 = shifted_data->data[c_i].f1->size[0] *
             shifted_data->data[c_i].f1->size[1];
        shifted_data->data[c_i].f1->size[0] = thisData->size[0];
        emxEnsureCapacity_real_T(&c_st, shifted_data->data[c_i].f1, i3,
                                 &pb_emlrtRTEI);
        if (c_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, shifted_data->size[0] - 1,
                                        &s_emlrtBCI, &c_st);
        }
        i3 = shifted_data->data[c_i].f1->size[0] *
             shifted_data->data[c_i].f1->size[1];
        shifted_data->data[c_i].f1->size[1] = thisData->size[1];
        emxEnsureCapacity_real_T(&c_st, shifted_data->data[c_i].f1, i3,
                                 &pb_emlrtRTEI);
        i3 = shifted_data->size[0];
        if (c_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, shifted_data->size[0] - 1,
                                        &s_emlrtBCI, &c_st);
        }
        if (c_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, shifted_data->size[0] - 1,
                                        &s_emlrtBCI, &c_st);
        }
        for (i4 = 0; i4 < b_loop_ub; i4++) {
          if (c_i > i3 - 1) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3 - 1, &pb_emlrtBCI, &c_st);
          }
          shifted_data->data[c_i].f1->data[i4] = thisData->data[i4];
        }
        b_loop_ub = layerSld->size[0] * 3;
        if (c_i > layerSlds->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, layerSlds->size[0] - 1,
                                        &t_emlrtBCI, &c_st);
        }
        i3 =
            layerSlds->data[c_i].f1->size[0] * layerSlds->data[c_i].f1->size[1];
        layerSlds->data[c_i].f1->size[0] = layerSld->size[0];
        emxEnsureCapacity_real_T(&c_st, layerSlds->data[c_i].f1, i3,
                                 &qb_emlrtRTEI);
        if (c_i > layerSlds->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, layerSlds->size[0] - 1,
                                        &t_emlrtBCI, &c_st);
        }
        i3 =
            layerSlds->data[c_i].f1->size[0] * layerSlds->data[c_i].f1->size[1];
        layerSlds->data[c_i].f1->size[1] = 3;
        emxEnsureCapacity_real_T(&c_st, layerSlds->data[c_i].f1, i3,
                                 &qb_emlrtRTEI);
        i3 = layerSlds->size[0];
        if (c_i > layerSlds->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, layerSlds->size[0] - 1,
                                        &t_emlrtBCI, &c_st);
        }
        if (c_i > layerSlds->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, layerSlds->size[0] - 1,
                                        &t_emlrtBCI, &c_st);
        }
        for (i4 = 0; i4 < b_loop_ub; i4++) {
          if (c_i > i3 - 1) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3 - 1, &qb_emlrtBCI, &c_st);
          }
          layerSlds->data[c_i].f1->data[i4] = layerSld->data[i4];
        }
        b_loop_ub = resamLayers->size[0] * 3;
        if (c_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, allLayers->size[0] - 1,
                                        &u_emlrtBCI, &c_st);
        }
        i3 =
            allLayers->data[c_i].f1->size[0] * allLayers->data[c_i].f1->size[1];
        allLayers->data[c_i].f1->size[0] = resamLayers->size[0];
        emxEnsureCapacity_real_T(&c_st, allLayers->data[c_i].f1, i3,
                                 &rb_emlrtRTEI);
        if (c_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, allLayers->size[0] - 1,
                                        &u_emlrtBCI, &c_st);
        }
        i3 =
            allLayers->data[c_i].f1->size[0] * allLayers->data[c_i].f1->size[1];
        allLayers->data[c_i].f1->size[1] = 3;
        emxEnsureCapacity_real_T(&c_st, allLayers->data[c_i].f1, i3,
                                 &rb_emlrtRTEI);
        i3 = allLayers->size[0];
        if (c_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, allLayers->size[0] - 1,
                                        &u_emlrtBCI, &c_st);
        }
        if (c_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, allLayers->size[0] - 1,
                                        &u_emlrtBCI, &c_st);
        }
        for (i4 = 0; i4 < b_loop_ub; i4++) {
          if (c_i > i3 - 1) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3 - 1, &rb_emlrtBCI, &c_st);
          }
          allLayers->data[c_i].f1->data[i4] = resamLayers->data[i4];
        }
        if (c_i + 1 > chis->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, chis->size[0], &sb_emlrtBCI,
                                        &c_st);
        }
        chis->data[c_i] = thisChiSquared;
        if (c_i + 1 > backgs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, backgs->size[0],
                                        &tb_emlrtBCI, &c_st);
        }
        backgs->data[c_i] = thisBackground;
        if (c_i + 1 > qshifts->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, qshifts->size[0],
                                        &ub_emlrtBCI, &c_st);
        }
        qshifts->data[c_i] = thisQshift;
        if (c_i + 1 > sfs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, sfs->size[0], &vb_emlrtBCI,
                                        &c_st);
        }
        sfs->data[c_i] = thisSf;
        if (c_i + 1 > nbas->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, nbas->size[0], &wb_emlrtBCI,
                                        &c_st);
        }
        nbas->data[c_i] = thisNba;
        if (c_i + 1 > nbss->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, nbss->size[0], &xb_emlrtBCI,
                                        &c_st);
        }
        nbss->data[c_i] = thisNbs;
        if (c_i + 1 > resols->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, resols->size[0],
                                        &yb_emlrtBCI, &c_st);
        }
        resols->data[c_i] = thisResol;
        if (c_i + 1 > allRoughs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, allRoughs->size[0],
                                        &ac_emlrtBCI, &c_st);
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
  emxFree_cell_wrap_10(&simLimits);
  emxFree_cell_wrap_10(&allData);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

emlrtCTX emlrtGetRootTLSGlobal(void)
{
  return emlrtRootTLSGlobal;
}

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData)
{
  omp_set_lock(&emlrtLockGlobal);
  emlrtCallLockeeFunction(aLockee, aTLS, aData);
  omp_unset_lock(&emlrtLockGlobal);
}

/* End of code generation (dev_custlay_paraContrasts.c) */
