/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * reflectivity_calculation.c
 *
 * Code generation for function 'reflectivity_calculation'
 *
 */

/* Include files */
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_reflectivityCalculation.h"
#include "strcmp.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    88,                         /* lineNo */
    "reflectivity_calculation", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pathName */
};

static emlrtDCInfo emlrtDCI = {
    47,                         /* lineNo */
    21,                         /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    4                                                      /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    47,                         /* lineNo */
    21,                         /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    1                                                      /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    48,                         /* lineNo */
    9,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtDCInfo c_emlrtDCI = {
    53,                         /* lineNo */
    19,                         /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    1                                                      /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    54,                         /* lineNo */
    9,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    60,                         /* lineNo */
    9,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    66,                         /* lineNo */
    9,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    72,                         /* lineNo */
    9,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    78,                         /* lineNo */
    9,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    103,                        /* lineNo */
    9,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    109,                        /* lineNo */
    9,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    115,                        /* lineNo */
    9,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    121,                        /* lineNo */
    9,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    127,                        /* lineNo */
    9,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo l_emlrtRTEI = {
    133,                        /* lineNo */
    9,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    49,                         /* lineNo */
    18,                         /* colNo */
    "reflectivity",             /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    55,                         /* lineNo */
    16,                         /* colNo */
    "Simulation",               /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    61,                         /* lineNo */
    18,                         /* colNo */
    "shifted_data",             /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    67,                         /* lineNo */
    15,                         /* colNo */
    "layerSlds",                /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    73,                         /* lineNo */
    17,                         /* colNo */
    "sldProfiles",              /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    79,                         /* lineNo */
    15,                         /* colNo */
    "allLayers",                /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    104,                        /* lineNo */
    29,                         /* colNo */
    "reflectivity",             /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    104,                        /* lineNo */
    11,                         /* colNo */
    "cell1",                    /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    110,                        /* lineNo */
    27,                         /* colNo */
    "Simulation",               /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    110,                        /* lineNo */
    11,                         /* colNo */
    "cell2",                    /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    116,                        /* lineNo */
    29,                         /* colNo */
    "shifted_data",             /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    116,                        /* lineNo */
    11,                         /* colNo */
    "cell3",                    /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    122,                        /* lineNo */
    26,                         /* colNo */
    "layerSlds",                /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    122,                        /* lineNo */
    11,                         /* colNo */
    "cell4",                    /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    128,                        /* lineNo */
    28,                         /* colNo */
    "sldProfiles",              /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    128,                        /* lineNo */
    11,                         /* colNo */
    "cell5",                    /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    134,                        /* lineNo */
    26,                         /* colNo */
    "allLayers",                /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    134,                        /* lineNo */
    11,                         /* colNo */
    "cell6",                    /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    47,                         /* lineNo */
    39,                         /* colNo */
    "reflectivity",             /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    47,                         /* lineNo */
    39,                         /* colNo */
    "Simulation",               /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    47,                         /* lineNo */
    39,                         /* colNo */
    "shifted_data",             /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    47,                         /* lineNo */
    39,                         /* colNo */
    "layerSlds",                /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    61,                         /* lineNo */
    5,                          /* colNo */
    "shifted_data",             /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    47,                         /* lineNo */
    39,                         /* colNo */
    "sldProfiles",              /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    67,                         /* lineNo */
    5,                          /* colNo */
    "layerSlds",                /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    47,                         /* lineNo */
    39,                         /* colNo */
    "allLayers",                /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    79,                         /* lineNo */
    5,                          /* colNo */
    "allLayers",                /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    47,                         /* lineNo */
    39,                         /* colNo */
    "cell1",                    /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    47,                         /* lineNo */
    39,                         /* colNo */
    "cell2",                    /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    47,                         /* lineNo */
    39,                         /* colNo */
    "cell3",                    /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    104,                        /* lineNo */
    16,                         /* colNo */
    "reflectivity",             /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    104,                        /* lineNo */
    5,                          /* colNo */
    "cell1",                    /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    47,                         /* lineNo */
    39,                         /* colNo */
    "cell4",                    /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    110,                        /* lineNo */
    16,                         /* colNo */
    "Simulation",               /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    110,                        /* lineNo */
    5,                          /* colNo */
    "cell2",                    /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    47,                         /* lineNo */
    39,                         /* colNo */
    "cell5",                    /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    116,                        /* lineNo */
    16,                         /* colNo */
    "shifted_data",             /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    116,                        /* lineNo */
    5,                          /* colNo */
    "cell3",                    /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    47,                         /* lineNo */
    39,                         /* colNo */
    "cell6",                    /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    122,                        /* lineNo */
    16,                         /* colNo */
    "layerSlds",                /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    122,                        /* lineNo */
    5,                          /* colNo */
    "cell4",                    /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    128,                        /* lineNo */
    16,                         /* colNo */
    "sldProfiles",              /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    128,                        /* lineNo */
    5,                          /* colNo */
    "cell5",                    /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    134,                        /* lineNo */
    16,                         /* colNo */
    "allLayers",                /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    134,                        /* lineNo */
    5,                          /* colNo */
    "cell6",                    /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    73,                         /* lineNo */
    5,                          /* colNo */
    "sldProfiles",              /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    55,                         /* lineNo */
    5,                          /* colNo */
    "Simulation",               /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    49,                         /* lineNo */
    5,                          /* colNo */
    "reflectivity",             /* aName */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m", /* pName */
    0                                                      /* checkKind */
};

static emlrtRTEInfo vd_emlrtRTEI = {
    28,                         /* lineNo */
    1,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo wd_emlrtRTEI = {
    29,                         /* lineNo */
    1,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo xd_emlrtRTEI = {
    30,                         /* lineNo */
    1,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo yd_emlrtRTEI = {
    31,                         /* lineNo */
    1,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo ae_emlrtRTEI = {
    32,                         /* lineNo */
    1,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo be_emlrtRTEI = {
    33,                         /* lineNo */
    1,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo ce_emlrtRTEI = {
    34,                         /* lineNo */
    1,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo de_emlrtRTEI = {
    35,                         /* lineNo */
    1,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo ee_emlrtRTEI = {
    37,                         /* lineNo */
    1,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo fe_emlrtRTEI = {
    38,                         /* lineNo */
    1,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo ge_emlrtRTEI = {
    1,                          /* lineNo */
    29,                         /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo he_emlrtRTEI = {
    47,                         /* lineNo */
    39,                         /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo ie_emlrtRTEI = {
    49,                         /* lineNo */
    5,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo je_emlrtRTEI = {
    55,                         /* lineNo */
    5,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo ke_emlrtRTEI = {
    61,                         /* lineNo */
    5,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo le_emlrtRTEI = {
    67,                         /* lineNo */
    5,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo me_emlrtRTEI = {
    73,                         /* lineNo */
    5,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo ne_emlrtRTEI = {
    79,                         /* lineNo */
    5,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo oe_emlrtRTEI = {
    88,                         /* lineNo */
    136,                        /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo pe_emlrtRTEI = {
    104,                        /* lineNo */
    5,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo qe_emlrtRTEI = {
    88,                         /* lineNo */
    9,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo re_emlrtRTEI = {
    110,                        /* lineNo */
    5,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo se_emlrtRTEI = {
    116,                        /* lineNo */
    5,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo te_emlrtRTEI = {
    122,                        /* lineNo */
    5,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo ue_emlrtRTEI = {
    128,                        /* lineNo */
    5,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo ve_emlrtRTEI = {
    134,                        /* lineNo */
    5,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo we_emlrtRTEI = {
    88,                         /* lineNo */
    18,                         /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo xe_emlrtRTEI = {
    88,                         /* lineNo */
    42,                         /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo ye_emlrtRTEI = {
    88,                         /* lineNo */
    55,                         /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo af_emlrtRTEI = {
    88,                         /* lineNo */
    65,                         /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo bf_emlrtRTEI = {
    47,                         /* lineNo */
    1,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo cf_emlrtRTEI = {
    53,                         /* lineNo */
    1,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo df_emlrtRTEI = {
    59,                         /* lineNo */
    1,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo ef_emlrtRTEI = {
    65,                         /* lineNo */
    1,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo ff_emlrtRTEI = {
    71,                         /* lineNo */
    1,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

static emlrtRTEInfo gf_emlrtRTEI = {
    77,                         /* lineNo */
    1,                          /* colNo */
    "reflectivity_calculation", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/"
    "reflectivity_calculation/reflectivity_calculation.m" /* pName */
};

/* Function Definitions */
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

void reflectivity_calculation(const emlrtStack *sp, const struct0_T *problemDef,
                              const cell_8 *problemDef_cells,
                              const struct1_T *problemDef_limits,
                              const struct2_T *controls, struct4_T *problem,
                              cell_11 *result)
{
  cell_16 expl_temp;
  emlrtStack st;
  emxArray_cell_wrap_10 *b_layerSlds;
  emxArray_cell_wrap_12 *Simulation;
  emxArray_cell_wrap_12 *reflectivity;
  emxArray_cell_wrap_12 *sldProfiles;
  emxArray_cell_wrap_13 *allLayers;
  emxArray_cell_wrap_13 *layerSlds;
  emxArray_cell_wrap_13 *shifted_data;
  emxArray_cell_wrap_14 *b_allLayers;
  emxArray_cell_wrap_14 *b_shifted_data;
  emxArray_cell_wrap_14 *b_sldProfiles;
  emxArray_cell_wrap_9 *b_Simulation;
  emxArray_cell_wrap_9 *c_reflectivity;
  int32_T b_i;
  int32_T b_reflectivity;
  int32_T i;
  int32_T i1;
  int32_T unnamed_idx_0_tmp_tmp;
  (void)problemDef_limits;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /*  Main entry point into the reflectivity calculation for the toolbox. */
  /*  This is the main function that is called by any of the minimisers or */
  /*  analysis tools from the rest of the toolbox. The main job of this */
  /*  function is to decide which type of calculation (i.e. 'Target function' */
  /*  is required, and call the relevant routines. The types of available  */
  /*  target functions are: */
  /*  */
  /*  1. standardTF       - The main basic target function type, for non
   * polarised  */
  /*                        neutrons (or x-rays) with non-absorbing samples. */
  /*                        Different model types are specified in sub functions
   */
  /*                        from here. */
  /*  */
  /*  2. standardTFAbs    - Identical to standardTF, but includes imaginary
   * refractive  */
  /*                        index terms. */
  /*  */
  /*  3. oilWaterTF       - Target function for oil-water samples */
  /*  */
  /*  4. domainsTF        - Target function for samples consisting of domains */
  /*                        which are larger than the beam lateral coherence
   * length. */
  /*  */
  /*  5. polarisedTF      - Target function for cases for polarised neutrons */
  /*                        with polarisation analysis */
  /*  for compilation, we have to preallocate memory for the output arrays */
  /*  Setting these parameters in the struct defines them as doubles */
  i = problem->ssubs->size[0];
  problem->ssubs->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->ssubs, i, &vd_emlrtRTEI);
  problem->ssubs->data[0] = 0.0;
  i = problem->backgrounds->size[0];
  problem->backgrounds->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->backgrounds, i, &wd_emlrtRTEI);
  problem->backgrounds->data[0] = 0.0;
  i = problem->qshifts->size[0];
  problem->qshifts->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->qshifts, i, &xd_emlrtRTEI);
  problem->qshifts->data[0] = 0.0;
  i = problem->scalefactors->size[0];
  problem->scalefactors->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->scalefactors, i, &yd_emlrtRTEI);
  problem->scalefactors->data[0] = 0.0;
  i = problem->nbairs->size[0];
  problem->nbairs->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->nbairs, i, &ae_emlrtRTEI);
  problem->nbairs->data[0] = 0.0;
  i = problem->nbsubs->size[0];
  problem->nbsubs->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->nbsubs, i, &be_emlrtRTEI);
  problem->nbsubs->data[0] = 0.0;
  i = problem->resolutions->size[0];
  problem->resolutions->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->resolutions, i, &ce_emlrtRTEI);
  problem->resolutions->data[0] = 0.0;
  i = problem->calculations.all_chis->size[0];
  problem->calculations.all_chis->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->calculations.all_chis, i,
                           &de_emlrtRTEI);
  problem->calculations.all_chis->data[0] = 0.0;
  problem->calculations.sum_chi = 0.0;
  i = problem->allSubRough->size[0];
  problem->allSubRough->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->allSubRough, i, &ee_emlrtRTEI);
  problem->allSubRough->data[0] = 0.0;
  i = problem->resample->size[0] * problem->resample->size[1];
  problem->resample->size[0] = 1;
  problem->resample->size[1] = 1;
  emxEnsureCapacity_real_T(sp, problem->resample, i, &fe_emlrtRTEI);
  problem->resample->data[0] = 0.0;
  /*  We also foll the results arrays to define their */
  /*  type and size. (NOTE: at the moment we have a 'coder.varsize' */
  /*  pre-processor directives for the compiler here and at the  */
  /*  end for the results block. We are unlikely to need both */
  /*  TODO: Find out which is necessary and tidy this up. */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &emlrtDCI,
                                (emlrtCTX)sp);
  }
  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &b_emlrtDCI,
                            (emlrtCTX)sp);
  }
  emxInit_cell_wrap_12(sp, &reflectivity, 1, &bf_emlrtRTEI, true);
  unnamed_idx_0_tmp_tmp = (int32_T)problemDef->numberOfContrasts;
  i1 = reflectivity->size[0];
  reflectivity->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_12(sp, reflectivity, i1, &ge_emlrtRTEI);
  for (i1 = 0; i1 < unnamed_idx_0_tmp_tmp; i1++) {
    b_reflectivity = reflectivity->size[0] - 1;
    if (i1 > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, reflectivity->size[0] - 1,
                                    &s_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[i1].f1->size[0] = 0;
    if (i1 > b_reflectivity) {
      emlrtDynamicBoundsCheckR2012b(i1, 0, b_reflectivity, &s_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    b_i =
        reflectivity->data[i1].f1->size[0] * reflectivity->data[i1].f1->size[1];
    reflectivity->data[i1].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[i1].f1, b_i, &ge_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &emlrtRTEI, (emlrtCTX)sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_12(sp, reflectivity, i1, &he_emlrtRTEI);
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &emlrtBCI, (emlrtCTX)sp);
    }
    i1 = reflectivity->data[b_i].f1->size[0] *
         reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &ie_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &emlrtBCI, (emlrtCTX)sp);
    }
    i1 = reflectivity->data[b_i].f1->size[0] *
         reflectivity->data[b_i].f1->size[1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &ie_emlrtRTEI);
    i1 = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &wb_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &wb_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &wb_emlrtBCI, (emlrtCTX)sp);
    }
    reflectivity->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  if (unnamed_idx_0_tmp_tmp != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &c_emlrtDCI,
                            (emlrtCTX)sp);
  }
  emxInit_cell_wrap_12(sp, &Simulation, 1, &cf_emlrtRTEI, true);
  i = Simulation->size[0];
  Simulation->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_12(sp, Simulation, i, &ge_emlrtRTEI);
  for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
    b_reflectivity = Simulation->size[0] - 1;
    if (i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, Simulation->size[0] - 1, &t_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    Simulation->data[i].f1->size[0] = 0;
    if (i > b_reflectivity) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_reflectivity, &t_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = Simulation->data[i].f1->size[0] * Simulation->data[i].f1->size[1];
    Simulation->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[i].f1, i1, &ge_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &b_emlrtRTEI, (emlrtCTX)sp);
  i = Simulation->size[0];
  Simulation->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_12(sp, Simulation, i, &he_emlrtRTEI);
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &b_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &je_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &b_emlrtBCI, (emlrtCTX)sp);
    }
    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &je_emlrtRTEI);
    i = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &b_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &vb_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &vb_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &vb_emlrtBCI, (emlrtCTX)sp);
    }
    Simulation->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxInit_cell_wrap_13(sp, &shifted_data, 1, &df_emlrtRTEI, true);
  i = shifted_data->size[0];
  shifted_data->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_13(sp, shifted_data, i, &ge_emlrtRTEI);
  for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
    b_reflectivity = shifted_data->size[0] - 1;
    if (i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, shifted_data->size[0] - 1,
                                    &u_emlrtBCI, (emlrtCTX)sp);
    }
    shifted_data->data[i].f1->size[0] = 0;
    if (i > b_reflectivity) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_reflectivity, &u_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = shifted_data->data[i].f1->size[0] * shifted_data->data[i].f1->size[1];
    shifted_data->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[i].f1, i1, &ge_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &c_emlrtRTEI, (emlrtCTX)sp);
  i = shifted_data->size[0];
  shifted_data->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_13(sp, shifted_data, i, &he_emlrtRTEI);
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &c_emlrtBCI, (emlrtCTX)sp);
    }
    i = shifted_data->data[b_i].f1->size[0] *
        shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &ke_emlrtRTEI);
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &c_emlrtBCI, (emlrtCTX)sp);
    }
    i = shifted_data->data[b_i].f1->size[0] *
        shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &ke_emlrtRTEI);
    i = shifted_data->size[0];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &c_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 6; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &w_emlrtBCI, (emlrtCTX)sp);
      }
      shifted_data->data[b_i].f1->data[i1] = 1.0;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxInit_cell_wrap_13(sp, &layerSlds, 1, &ef_emlrtRTEI, true);
  i = layerSlds->size[0];
  layerSlds->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_13(sp, layerSlds, i, &ge_emlrtRTEI);
  for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
    b_reflectivity = layerSlds->size[0] - 1;
    if (i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, layerSlds->size[0] - 1, &v_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    layerSlds->data[i].f1->size[0] = 0;
    if (i > b_reflectivity) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_reflectivity, &v_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
    layerSlds->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[i].f1, i1, &ge_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &d_emlrtRTEI, (emlrtCTX)sp);
  i = layerSlds->size[0];
  layerSlds->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_13(sp, layerSlds, i, &he_emlrtRTEI);
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &d_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &le_emlrtRTEI);
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &d_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &le_emlrtRTEI);
    i = layerSlds->size[0];
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &d_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 6; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &y_emlrtBCI, (emlrtCTX)sp);
      }
      layerSlds->data[b_i].f1->data[i1] = 1.0;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxInit_cell_wrap_12(sp, &sldProfiles, 1, &ff_emlrtRTEI, true);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_12(sp, sldProfiles, i, &ge_emlrtRTEI);
  for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
    b_reflectivity = sldProfiles->size[0] - 1;
    if (i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, sldProfiles->size[0] - 1, &x_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    sldProfiles->data[i].f1->size[0] = 0;
    if (i > b_reflectivity) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_reflectivity, &x_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = sldProfiles->data[i].f1->size[0] * sldProfiles->data[i].f1->size[1];
    sldProfiles->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[i].f1, i1, &ge_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &e_emlrtRTEI, (emlrtCTX)sp);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_12(sp, sldProfiles, i, &he_emlrtRTEI);
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &e_emlrtBCI, (emlrtCTX)sp);
    }
    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &me_emlrtRTEI);
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &e_emlrtBCI, (emlrtCTX)sp);
    }
    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &me_emlrtRTEI);
    i = sldProfiles->size[0];
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &e_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &ub_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[b_i].f1->data[1] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &ub_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[b_i].f1->data[2] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &ub_emlrtBCI, (emlrtCTX)sp);
    }
    sldProfiles->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxInit_cell_wrap_13(sp, &allLayers, 1, &gf_emlrtRTEI, true);
  i = allLayers->size[0];
  allLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_13(sp, allLayers, i, &ge_emlrtRTEI);
  for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
    b_reflectivity = allLayers->size[0] - 1;
    if (i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, allLayers->size[0] - 1, &ab_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    allLayers->data[i].f1->size[0] = 0;
    if (i > b_reflectivity) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_reflectivity, &ab_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = allLayers->data[i].f1->size[0] * allLayers->data[i].f1->size[1];
    allLayers->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers->data[i].f1, i1, &ge_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &f_emlrtRTEI, (emlrtCTX)sp);
  i = allLayers->size[0];
  allLayers->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_13(sp, allLayers, i, &he_emlrtRTEI);
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &f_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &ne_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &f_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &ne_emlrtRTEI);
    i = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &f_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < 6; i1++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &bb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      allLayers->data[b_i].f1->data[i1] = 1.0;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  /* Decide which target function we are calling ans call the relevant routines
   */
  if (b_strcmp(problemDef->TF)) {
    i = 0;
  } else {
    i = -1;
  }
  switch (i) {
  case 0:
    emxInitStruct_cell_16(sp, &expl_temp, &qe_emlrtRTEI, true);
    i = expl_temp.f2->size[0] * expl_temp.f2->size[1];
    expl_temp.f2->size[0] = 1;
    expl_temp.f2->size[1] = problemDef_cells->f2->size[1];
    emxEnsureCapacity_cell_wrap_14(sp, expl_temp.f2, i, &oe_emlrtRTEI);
    i = problemDef_cells->f2->size[1] - 1;
    for (i1 = 0; i1 <= i; i1++) {
      b_i = expl_temp.f2->data[i1].f1->size[0] *
            expl_temp.f2->data[i1].f1->size[1];
      expl_temp.f2->data[i1].f1->size[0] =
          problemDef_cells->f2->data[i1].f1->size[0];
      expl_temp.f2->data[i1].f1->size[1] =
          problemDef_cells->f2->data[i1].f1->size[1];
      emxEnsureCapacity_real_T(sp, expl_temp.f2->data[i1].f1, b_i,
                               &oe_emlrtRTEI);
      b_reflectivity = problemDef_cells->f2->data[i1].f1->size[0] *
                       problemDef_cells->f2->data[i1].f1->size[1];
      for (b_i = 0; b_i < b_reflectivity; b_i++) {
        expl_temp.f2->data[i1].f1->data[b_i] =
            problemDef_cells->f2->data[i1].f1->data[b_i];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    i = expl_temp.f4->size[0] * expl_temp.f4->size[1];
    expl_temp.f4->size[0] = 1;
    expl_temp.f4->size[1] = problemDef_cells->f4->size[1];
    emxEnsureCapacity_cell_wrap_14(sp, expl_temp.f4, i, &oe_emlrtRTEI);
    i = problemDef_cells->f4->size[1] - 1;
    for (i1 = 0; i1 <= i; i1++) {
      b_i = expl_temp.f4->data[i1].f1->size[0] *
            expl_temp.f4->data[i1].f1->size[1];
      expl_temp.f4->data[i1].f1->size[0] =
          problemDef_cells->f4->data[i1].f1.size[0];
      expl_temp.f4->data[i1].f1->size[1] =
          problemDef_cells->f4->data[i1].f1.size[1];
      emxEnsureCapacity_real_T(sp, expl_temp.f4->data[i1].f1, b_i,
                               &oe_emlrtRTEI);
      b_reflectivity = problemDef_cells->f4->data[i1].f1.size[0] *
                       problemDef_cells->f4->data[i1].f1.size[1];
      for (b_i = 0; b_i < b_reflectivity; b_i++) {
        expl_temp.f4->data[i1].f1->data[b_i] =
            problemDef_cells->f4->data[i1].f1.data[b_i];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    i = expl_temp.f5->size[0] * expl_temp.f5->size[1];
    expl_temp.f5->size[0] = 1;
    expl_temp.f5->size[1] = problemDef_cells->f5->size[1];
    emxEnsureCapacity_cell_wrap_14(sp, expl_temp.f5, i, &oe_emlrtRTEI);
    i = problemDef_cells->f5->size[1] - 1;
    for (i1 = 0; i1 <= i; i1++) {
      b_i = expl_temp.f5->data[i1].f1->size[0] *
            expl_temp.f5->data[i1].f1->size[1];
      expl_temp.f5->data[i1].f1->size[0] =
          problemDef_cells->f5->data[i1].f1->size[0];
      expl_temp.f5->data[i1].f1->size[1] =
          problemDef_cells->f5->data[i1].f1->size[1];
      emxEnsureCapacity_real_T(sp, expl_temp.f5->data[i1].f1, b_i,
                               &oe_emlrtRTEI);
      b_reflectivity = problemDef_cells->f5->data[i1].f1->size[0] *
                       problemDef_cells->f5->data[i1].f1->size[1];
      for (b_i = 0; b_i < b_reflectivity; b_i++) {
        expl_temp.f5->data[i1].f1->data[b_i] =
            problemDef_cells->f5->data[i1].f1->data[b_i];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    i = expl_temp.f6->size[0];
    expl_temp.f6->size[0] = problemDef_cells->f6->size[0];
    emxEnsureCapacity_cell_wrap_14(sp, expl_temp.f6, i, &oe_emlrtRTEI);
    i = problemDef_cells->f6->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = expl_temp.f6->data[i1].f1->size[0] *
            expl_temp.f6->data[i1].f1->size[1];
      expl_temp.f6->data[i1].f1->size[0] =
          problemDef_cells->f6->data[i1].f1.size[0];
      expl_temp.f6->data[i1].f1->size[1] =
          problemDef_cells->f6->data[i1].f1.size[1];
      emxEnsureCapacity_real_T(sp, expl_temp.f6->data[i1].f1, b_i,
                               &oe_emlrtRTEI);
      b_reflectivity = problemDef_cells->f6->data[i1].f1.size[0] *
                       problemDef_cells->f6->data[i1].f1.size[1];
      for (b_i = 0; b_i < b_reflectivity; b_i++) {
        expl_temp.f6->data[i1].f1->data[b_i] =
            problemDef_cells->f6->data[i1].f1.data[b_i];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    i = expl_temp.f14->size[0] * expl_temp.f14->size[1];
    expl_temp.f14->size[0] = 1;
    expl_temp.f14->size[1] = problemDef_cells->f14->size[1];
    emxEnsureCapacity_cell_wrap_7(sp, expl_temp.f14, i, &qe_emlrtRTEI);
    b_reflectivity = problemDef_cells->f14->size[1];
    for (i = 0; i < b_reflectivity; i++) {
      emxCopyStruct_cell_wrap_7(sp, &expl_temp.f14->data[i],
                                &problemDef_cells->f14->data[i], &qe_emlrtRTEI);
    }
    i = expl_temp.f13->size[0] * expl_temp.f13->size[1];
    expl_temp.f13->size[0] = 1;
    expl_temp.f13->size[1] = problemDef_cells->f13->size[1];
    emxEnsureCapacity_cell_wrap_6(sp, expl_temp.f13, i, &qe_emlrtRTEI);
    b_reflectivity = problemDef_cells->f13->size[1];
    for (i = 0; i < b_reflectivity; i++) {
      emxCopyStruct_cell_wrap_6(sp, &expl_temp.f13->data[i],
                                &problemDef_cells->f13->data[i], &qe_emlrtRTEI);
    }
    i = expl_temp.f12->size[0] * expl_temp.f12->size[1];
    expl_temp.f12->size[0] = 1;
    expl_temp.f12->size[1] = problemDef_cells->f12->size[1];
    emxEnsureCapacity_cell_wrap_6(sp, expl_temp.f12, i, &qe_emlrtRTEI);
    b_reflectivity = problemDef_cells->f12->size[1];
    for (i = 0; i < b_reflectivity; i++) {
      emxCopyStruct_cell_wrap_6(sp, &expl_temp.f12->data[i],
                                &problemDef_cells->f12->data[i], &qe_emlrtRTEI);
    }
    i = expl_temp.f11->size[0] * expl_temp.f11->size[1];
    expl_temp.f11->size[0] = 1;
    expl_temp.f11->size[1] = problemDef_cells->f11->size[1];
    emxEnsureCapacity_cell_wrap_6(sp, expl_temp.f11, i, &qe_emlrtRTEI);
    b_reflectivity = problemDef_cells->f11->size[1];
    for (i = 0; i < b_reflectivity; i++) {
      emxCopyStruct_cell_wrap_6(sp, &expl_temp.f11->data[i],
                                &problemDef_cells->f11->data[i], &qe_emlrtRTEI);
    }
    i = expl_temp.f10->size[0] * expl_temp.f10->size[1];
    expl_temp.f10->size[0] = 1;
    expl_temp.f10->size[1] = problemDef_cells->f10->size[1];
    emxEnsureCapacity_cell_wrap_6(sp, expl_temp.f10, i, &qe_emlrtRTEI);
    b_reflectivity = problemDef_cells->f10->size[1];
    for (i = 0; i < b_reflectivity; i++) {
      emxCopyStruct_cell_wrap_6(sp, &expl_temp.f10->data[i],
                                &problemDef_cells->f10->data[i], &qe_emlrtRTEI);
    }
    i = expl_temp.f9->size[0] * expl_temp.f9->size[1];
    expl_temp.f9->size[0] = 1;
    expl_temp.f9->size[1] = problemDef_cells->f9->size[1];
    emxEnsureCapacity_cell_wrap_6(sp, expl_temp.f9, i, &qe_emlrtRTEI);
    b_reflectivity = problemDef_cells->f9->size[1];
    for (i = 0; i < b_reflectivity; i++) {
      emxCopyStruct_cell_wrap_6(sp, &expl_temp.f9->data[i],
                                &problemDef_cells->f9->data[i], &qe_emlrtRTEI);
    }
    i = expl_temp.f8->size[0] * expl_temp.f8->size[1];
    expl_temp.f8->size[0] = 1;
    expl_temp.f8->size[1] = problemDef_cells->f8->size[1];
    emxEnsureCapacity_cell_wrap_6(sp, expl_temp.f8, i, &qe_emlrtRTEI);
    b_reflectivity = problemDef_cells->f8->size[1];
    for (i = 0; i < b_reflectivity; i++) {
      emxCopyStruct_cell_wrap_6(sp, &expl_temp.f8->data[i],
                                &problemDef_cells->f8->data[i], &qe_emlrtRTEI);
    }
    i = expl_temp.f7->size[0] * expl_temp.f7->size[1];
    expl_temp.f7->size[0] = 1;
    expl_temp.f7->size[1] = problemDef_cells->f7->size[1];
    emxEnsureCapacity_cell_wrap_5(sp, expl_temp.f7, i, &qe_emlrtRTEI);
    b_reflectivity = problemDef_cells->f7->size[1];
    for (i = 0; i < b_reflectivity; i++) {
      emxCopyStruct_cell_wrap_5(sp, &expl_temp.f7->data[i],
                                &problemDef_cells->f7->data[i], &qe_emlrtRTEI);
    }
    i = expl_temp.f3->size[0] * expl_temp.f3->size[1];
    expl_temp.f3->size[0] = 1;
    expl_temp.f3->size[1] = problemDef_cells->f3->size[1];
    emxEnsureCapacity_cell_wrap_0(sp, expl_temp.f3, i, &qe_emlrtRTEI);
    b_reflectivity = problemDef_cells->f3->size[1];
    for (i = 0; i < b_reflectivity; i++) {
      expl_temp.f3->data[i] = problemDef_cells->f3->data[i];
    }
    i = expl_temp.f1->size[0] * expl_temp.f1->size[1];
    expl_temp.f1->size[0] = 1;
    expl_temp.f1->size[1] = problemDef_cells->f1->size[1];
    emxEnsureCapacity_cell_wrap_0(sp, expl_temp.f1, i, &qe_emlrtRTEI);
    b_reflectivity = problemDef_cells->f1->size[1];
    for (i = 0; i < b_reflectivity; i++) {
      expl_temp.f1->data[i] = problemDef_cells->f1->data[i];
    }
    emxInit_cell_wrap_9(sp, &c_reflectivity, 1, &ge_emlrtRTEI, true);
    emxInit_cell_wrap_9(sp, &b_Simulation, 1, &ge_emlrtRTEI, true);
    emxInit_cell_wrap_14(sp, &b_shifted_data, 1, &ge_emlrtRTEI, true);
    emxInit_cell_wrap_10(sp, &b_layerSlds, 1, &ge_emlrtRTEI, true);
    emxInit_cell_wrap_14(sp, &b_sldProfiles, 1, &ge_emlrtRTEI, true);
    emxInit_cell_wrap_14(sp, &b_allLayers, 1, &ge_emlrtRTEI, true);
    st.site = &emlrtRSI;
    c_standardTF_reflectivityCalcul(
        &st, problemDef, &expl_temp, controls, problem, c_reflectivity,
        b_Simulation, b_shifted_data, b_layerSlds, b_sldProfiles, b_allLayers);
    i = reflectivity->size[0];
    reflectivity->size[0] = c_reflectivity->size[0];
    emxEnsureCapacity_cell_wrap_12(sp, reflectivity, i, &we_emlrtRTEI);
    i = c_reflectivity->size[0];
    emxFreeStruct_cell_16(&expl_temp);
    for (i1 = 0; i1 < i; i1++) {
      b_i = reflectivity->data[i1].f1->size[0] *
            reflectivity->data[i1].f1->size[1];
      reflectivity->data[i1].f1->size[0] = c_reflectivity->data[i1].f1->size[0];
      reflectivity->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, reflectivity->data[i1].f1, b_i,
                               &we_emlrtRTEI);
      b_reflectivity = c_reflectivity->data[i1].f1->size[0] * 2;
      for (b_i = 0; b_i < b_reflectivity; b_i++) {
        reflectivity->data[i1].f1->data[b_i] =
            c_reflectivity->data[i1].f1->data[b_i];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    emxFree_cell_wrap_9(&c_reflectivity);
    i = Simulation->size[0];
    Simulation->size[0] = b_Simulation->size[0];
    emxEnsureCapacity_cell_wrap_12(sp, Simulation, i, &we_emlrtRTEI);
    i = b_Simulation->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = Simulation->data[i1].f1->size[0] * Simulation->data[i1].f1->size[1];
      Simulation->data[i1].f1->size[0] = b_Simulation->data[i1].f1->size[0];
      Simulation->data[i1].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, Simulation->data[i1].f1, b_i, &we_emlrtRTEI);
      b_reflectivity = b_Simulation->data[i1].f1->size[0] * 2;
      for (b_i = 0; b_i < b_reflectivity; b_i++) {
        Simulation->data[i1].f1->data[b_i] =
            b_Simulation->data[i1].f1->data[b_i];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    emxFree_cell_wrap_9(&b_Simulation);
    i = shifted_data->size[0];
    shifted_data->size[0] = b_shifted_data->size[0];
    emxEnsureCapacity_cell_wrap_13(sp, shifted_data, i, &xe_emlrtRTEI);
    i = b_shifted_data->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = shifted_data->data[i1].f1->size[0] *
            shifted_data->data[i1].f1->size[1];
      shifted_data->data[i1].f1->size[0] = b_shifted_data->data[i1].f1->size[0];
      shifted_data->data[i1].f1->size[1] = b_shifted_data->data[i1].f1->size[1];
      emxEnsureCapacity_real_T(sp, shifted_data->data[i1].f1, b_i,
                               &xe_emlrtRTEI);
      b_reflectivity = b_shifted_data->data[i1].f1->size[0] *
                       b_shifted_data->data[i1].f1->size[1];
      for (b_i = 0; b_i < b_reflectivity; b_i++) {
        shifted_data->data[i1].f1->data[b_i] =
            b_shifted_data->data[i1].f1->data[b_i];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    emxFree_cell_wrap_14(&b_shifted_data);
    i = layerSlds->size[0];
    layerSlds->size[0] = b_layerSlds->size[0];
    emxEnsureCapacity_cell_wrap_13(sp, layerSlds, i, &ye_emlrtRTEI);
    i = b_layerSlds->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = layerSlds->data[i1].f1->size[0] * layerSlds->data[i1].f1->size[1];
      layerSlds->data[i1].f1->size[0] = b_layerSlds->data[i1].f1->size[0];
      layerSlds->data[i1].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, layerSlds->data[i1].f1, b_i, &ye_emlrtRTEI);
      b_reflectivity = b_layerSlds->data[i1].f1->size[0] * 3;
      for (b_i = 0; b_i < b_reflectivity; b_i++) {
        layerSlds->data[i1].f1->data[b_i] = b_layerSlds->data[i1].f1->data[b_i];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    emxFree_cell_wrap_10(&b_layerSlds);
    i = sldProfiles->size[0];
    sldProfiles->size[0] = b_sldProfiles->size[0];
    emxEnsureCapacity_cell_wrap_12(sp, sldProfiles, i, &af_emlrtRTEI);
    i = b_sldProfiles->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i =
          sldProfiles->data[i1].f1->size[0] * sldProfiles->data[i1].f1->size[1];
      sldProfiles->data[i1].f1->size[0] = b_sldProfiles->data[i1].f1->size[0];
      sldProfiles->data[i1].f1->size[1] = b_sldProfiles->data[i1].f1->size[1];
      emxEnsureCapacity_real_T(sp, sldProfiles->data[i1].f1, b_i,
                               &af_emlrtRTEI);
      b_reflectivity = b_sldProfiles->data[i1].f1->size[0] *
                       b_sldProfiles->data[i1].f1->size[1];
      for (b_i = 0; b_i < b_reflectivity; b_i++) {
        sldProfiles->data[i1].f1->data[b_i] =
            b_sldProfiles->data[i1].f1->data[b_i];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    emxFree_cell_wrap_14(&b_sldProfiles);
    i = allLayers->size[0];
    allLayers->size[0] = b_allLayers->size[0];
    emxEnsureCapacity_cell_wrap_13(sp, allLayers, i, &xe_emlrtRTEI);
    i = b_allLayers->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_i = allLayers->data[i1].f1->size[0] * allLayers->data[i1].f1->size[1];
      allLayers->data[i1].f1->size[0] = b_allLayers->data[i1].f1->size[0];
      allLayers->data[i1].f1->size[1] = b_allLayers->data[i1].f1->size[1];
      emxEnsureCapacity_real_T(sp, allLayers->data[i1].f1, b_i, &xe_emlrtRTEI);
      b_reflectivity =
          b_allLayers->data[i1].f1->size[0] * b_allLayers->data[i1].f1->size[1];
      for (b_i = 0; b_i < b_reflectivity; b_i++) {
        allLayers->data[i1].f1->data[b_i] = b_allLayers->data[i1].f1->data[b_i];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    emxFree_cell_wrap_14(&b_allLayers);
    /* case 'standardTFAbs' */
    /* [problem,reflectivity,Simulation,shifted_data,layerSlds,sldProfiles,allLayers]
     * =
     * standardTFAbs_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls);
     */
    /* case 'oilWaterTF' */
    /* problem =
     * oilWaterTF_reflectivityCalculation(problemDef,problemDef_cells,controls);
     */
    /* case 'polarisedTF' */
    /* problem =
     * polarisedTF_reflectivityCalculation(problemDef,problemDef_cells,controls);
     */
    /* case 'domainsTF' */
    /* [problem,reflectivity,Simulation,shifted_data,layerSlds,sldProfiles,allLayers]
     * =
     * domainsTF_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls);
     */
    break;
  }
  i = result->f1->size[0];
  result->f1->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, result->f1, i, &ge_emlrtRTEI);
  for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
    b_reflectivity = result->f1->size[0] - 1;
    if (i > result->f1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, result->f1->size[0] - 1, &cb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    result->f1->data[i].f1->size[0] = 0;
    if (i > b_reflectivity) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_reflectivity, &cb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = result->f1->data[i].f1->size[0] * result->f1->data[i].f1->size[1];
    result->f1->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, result->f1->data[i].f1, i1, &ge_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &g_emlrtRTEI, (emlrtCTX)sp);
  i = result->f1->size[0];
  result->f1->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, result->f1, i, &he_emlrtRTEI);
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &g_emlrtBCI, (emlrtCTX)sp);
    }
    b_reflectivity = reflectivity->data[b_i].f1->size[0] * 2;
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                    &g_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > result->f1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f1->size[0] - 1,
                                    &h_emlrtBCI, (emlrtCTX)sp);
    }
    i = result->f1->data[b_i].f1->size[0] * result->f1->data[b_i].f1->size[1];
    result->f1->data[b_i].f1->size[0] = reflectivity->data[b_i].f1->size[0];
    emxEnsureCapacity_real_T(sp, result->f1->data[b_i].f1, i, &pe_emlrtRTEI);
    if (b_i > result->f1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f1->size[0] - 1,
                                    &h_emlrtBCI, (emlrtCTX)sp);
    }
    i = result->f1->data[b_i].f1->size[0] * result->f1->data[b_i].f1->size[1];
    result->f1->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, result->f1->data[b_i].f1, i, &pe_emlrtRTEI);
    i = result->f1->size[0];
    if (b_i > result->f1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f1->size[0] - 1,
                                    &h_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > result->f1->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f1->size[0] - 1,
                                    &h_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_reflectivity; i1++) {
      if (b_i > reflectivity->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
                                      &fb_emlrtBCI, (emlrtCTX)sp);
      }
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &gb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      result->f1->data[b_i].f1->data[i1] = reflectivity->data[b_i].f1->data[i1];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_cell_wrap_12(&reflectivity);
  i = result->f2->size[0];
  result->f2->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, result->f2, i, &ge_emlrtRTEI);
  for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
    b_reflectivity = result->f2->size[0] - 1;
    if (i > result->f2->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, result->f2->size[0] - 1, &db_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    result->f2->data[i].f1->size[0] = 0;
    if (i > b_reflectivity) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_reflectivity, &db_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = result->f2->data[i].f1->size[0] * result->f2->data[i].f1->size[1];
    result->f2->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, result->f2->data[i].f1, i1, &ge_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &h_emlrtRTEI, (emlrtCTX)sp);
  i = result->f2->size[0];
  result->f2->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, result->f2, i, &he_emlrtRTEI);
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &i_emlrtBCI, (emlrtCTX)sp);
    }
    b_reflectivity = Simulation->data[b_i].f1->size[0] * 2;
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                    &i_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > result->f2->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f2->size[0] - 1,
                                    &j_emlrtBCI, (emlrtCTX)sp);
    }
    i = result->f2->data[b_i].f1->size[0] * result->f2->data[b_i].f1->size[1];
    result->f2->data[b_i].f1->size[0] = Simulation->data[b_i].f1->size[0];
    emxEnsureCapacity_real_T(sp, result->f2->data[b_i].f1, i, &re_emlrtRTEI);
    if (b_i > result->f2->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f2->size[0] - 1,
                                    &j_emlrtBCI, (emlrtCTX)sp);
    }
    i = result->f2->data[b_i].f1->size[0] * result->f2->data[b_i].f1->size[1];
    result->f2->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, result->f2->data[b_i].f1, i, &re_emlrtRTEI);
    i = result->f2->size[0];
    if (b_i > result->f2->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f2->size[0] - 1,
                                    &j_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > result->f2->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f2->size[0] - 1,
                                    &j_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_reflectivity; i1++) {
      if (b_i > Simulation->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
                                      &ib_emlrtBCI, (emlrtCTX)sp);
      }
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &jb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      result->f2->data[b_i].f1->data[i1] = Simulation->data[b_i].f1->data[i1];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_cell_wrap_12(&Simulation);
  i = result->f3->size[0];
  result->f3->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, result->f3, i, &ge_emlrtRTEI);
  for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
    b_reflectivity = result->f3->size[0] - 1;
    if (i > result->f3->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, result->f3->size[0] - 1, &eb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    result->f3->data[i].f1->size[0] = 0;
    if (i > b_reflectivity) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_reflectivity, &eb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = result->f3->data[i].f1->size[0] * result->f3->data[i].f1->size[1];
    result->f3->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, result->f3->data[i].f1, i1, &ge_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &i_emlrtRTEI, (emlrtCTX)sp);
  i = result->f3->size[0];
  result->f3->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, result->f3, i, &he_emlrtRTEI);
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &k_emlrtBCI, (emlrtCTX)sp);
    }
    b_reflectivity = shifted_data->data[b_i].f1->size[0] * 3;
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                    &k_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > result->f3->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f3->size[0] - 1,
                                    &l_emlrtBCI, (emlrtCTX)sp);
    }
    i = result->f3->data[b_i].f1->size[0] * result->f3->data[b_i].f1->size[1];
    result->f3->data[b_i].f1->size[0] = shifted_data->data[b_i].f1->size[0];
    emxEnsureCapacity_real_T(sp, result->f3->data[b_i].f1, i, &se_emlrtRTEI);
    if (b_i > result->f3->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f3->size[0] - 1,
                                    &l_emlrtBCI, (emlrtCTX)sp);
    }
    i = result->f3->data[b_i].f1->size[0] * result->f3->data[b_i].f1->size[1];
    result->f3->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, result->f3->data[b_i].f1, i, &se_emlrtRTEI);
    i = result->f3->size[0];
    if (b_i > result->f3->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f3->size[0] - 1,
                                    &l_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > result->f3->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f3->size[0] - 1,
                                    &l_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_reflectivity; i1++) {
      if (b_i > shifted_data->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
                                      &lb_emlrtBCI, (emlrtCTX)sp);
      }
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &mb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      result->f3->data[b_i].f1->data[i1] = shifted_data->data[b_i].f1->data[i1];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_cell_wrap_13(&shifted_data);
  i = result->f4->size[0];
  result->f4->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, result->f4, i, &ge_emlrtRTEI);
  for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
    b_reflectivity = result->f4->size[0] - 1;
    if (i > result->f4->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, result->f4->size[0] - 1, &hb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    result->f4->data[i].f1->size[0] = 0;
    if (i > b_reflectivity) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_reflectivity, &hb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = result->f4->data[i].f1->size[0] * result->f4->data[i].f1->size[1];
    result->f4->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, result->f4->data[i].f1, i1, &ge_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &j_emlrtRTEI, (emlrtCTX)sp);
  i = result->f4->size[0];
  result->f4->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, result->f4, i, &he_emlrtRTEI);
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &m_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    b_reflectivity = layerSlds->data[b_i].f1->size[0] * 3;
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &m_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (b_i > result->f4->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f4->size[0] - 1,
                                    &n_emlrtBCI, (emlrtCTX)sp);
    }
    i = result->f4->data[b_i].f1->size[0] * result->f4->data[b_i].f1->size[1];
    result->f4->data[b_i].f1->size[0] = layerSlds->data[b_i].f1->size[0];
    emxEnsureCapacity_real_T(sp, result->f4->data[b_i].f1, i, &te_emlrtRTEI);
    if (b_i > result->f4->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f4->size[0] - 1,
                                    &n_emlrtBCI, (emlrtCTX)sp);
    }
    i = result->f4->data[b_i].f1->size[0] * result->f4->data[b_i].f1->size[1];
    result->f4->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, result->f4->data[b_i].f1, i, &te_emlrtRTEI);
    i = result->f4->size[0];
    if (b_i > result->f4->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f4->size[0] - 1,
                                    &n_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > result->f4->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f4->size[0] - 1,
                                    &n_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_reflectivity; i1++) {
      if (b_i > layerSlds->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
                                      &ob_emlrtBCI, (emlrtCTX)sp);
      }
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &pb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      result->f4->data[b_i].f1->data[i1] = layerSlds->data[b_i].f1->data[i1];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_cell_wrap_13(&layerSlds);
  i = result->f5->size[0];
  result->f5->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, result->f5, i, &ge_emlrtRTEI);
  for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
    b_reflectivity = result->f5->size[0] - 1;
    if (i > result->f5->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, result->f5->size[0] - 1, &kb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    result->f5->data[i].f1->size[0] = 0;
    if (i > b_reflectivity) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_reflectivity, &kb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = result->f5->data[i].f1->size[0] * result->f5->data[i].f1->size[1];
    result->f5->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, result->f5->data[i].f1, i1, &ge_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &k_emlrtRTEI, (emlrtCTX)sp);
  i = result->f5->size[0];
  result->f5->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_9(sp, result->f5, i, &he_emlrtRTEI);
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &o_emlrtBCI, (emlrtCTX)sp);
    }
    b_reflectivity = sldProfiles->data[b_i].f1->size[0] * 2;
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                    &o_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > result->f5->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f5->size[0] - 1,
                                    &p_emlrtBCI, (emlrtCTX)sp);
    }
    i = result->f5->data[b_i].f1->size[0] * result->f5->data[b_i].f1->size[1];
    result->f5->data[b_i].f1->size[0] = sldProfiles->data[b_i].f1->size[0];
    emxEnsureCapacity_real_T(sp, result->f5->data[b_i].f1, i, &ue_emlrtRTEI);
    if (b_i > result->f5->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f5->size[0] - 1,
                                    &p_emlrtBCI, (emlrtCTX)sp);
    }
    i = result->f5->data[b_i].f1->size[0] * result->f5->data[b_i].f1->size[1];
    result->f5->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, result->f5->data[b_i].f1, i, &ue_emlrtRTEI);
    i = result->f5->size[0];
    if (b_i > result->f5->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f5->size[0] - 1,
                                    &p_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > result->f5->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f5->size[0] - 1,
                                    &p_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_reflectivity; i1++) {
      if (b_i > sldProfiles->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
                                      &qb_emlrtBCI, (emlrtCTX)sp);
      }
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &rb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      result->f5->data[b_i].f1->data[i1] = sldProfiles->data[b_i].f1->data[i1];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_cell_wrap_12(&sldProfiles);
  i = result->f6->size[0];
  result->f6->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, result->f6, i, &ge_emlrtRTEI);
  for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
    b_reflectivity = result->f6->size[0] - 1;
    if (i > result->f6->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, result->f6->size[0] - 1, &nb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    result->f6->data[i].f1->size[0] = 0;
    if (i > b_reflectivity) {
      emlrtDynamicBoundsCheckR2012b(i, 0, b_reflectivity, &nb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = result->f6->data[i].f1->size[0] * result->f6->data[i].f1->size[1];
    result->f6->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, result->f6->data[i].f1, i1, &ge_emlrtRTEI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtForLoopVectorCheckR2021a(
      1.0, 1.0, problemDef->numberOfContrasts, mxDOUBLE_CLASS,
      (int32_T)problemDef->numberOfContrasts, &l_emlrtRTEI, (emlrtCTX)sp);
  i = result->f6->size[0];
  result->f6->size[0] = unnamed_idx_0_tmp_tmp;
  emxEnsureCapacity_cell_wrap_10(sp, result->f6, i, &he_emlrtRTEI);
  for (b_i = 0; b_i < unnamed_idx_0_tmp_tmp; b_i++) {
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &q_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    b_reflectivity = allLayers->data[b_i].f1->size[0] * 3;
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &q_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (b_i > result->f6->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f6->size[0] - 1,
                                    &r_emlrtBCI, (emlrtCTX)sp);
    }
    i = result->f6->data[b_i].f1->size[0] * result->f6->data[b_i].f1->size[1];
    result->f6->data[b_i].f1->size[0] = allLayers->data[b_i].f1->size[0];
    emxEnsureCapacity_real_T(sp, result->f6->data[b_i].f1, i, &ve_emlrtRTEI);
    if (b_i > result->f6->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f6->size[0] - 1,
                                    &r_emlrtBCI, (emlrtCTX)sp);
    }
    i = result->f6->data[b_i].f1->size[0] * result->f6->data[b_i].f1->size[1];
    result->f6->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, result->f6->data[b_i].f1, i, &ve_emlrtRTEI);
    i = result->f6->size[0];
    if (b_i > result->f6->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f6->size[0] - 1,
                                    &r_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_i > result->f6->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f6->size[0] - 1,
                                    &r_emlrtBCI, (emlrtCTX)sp);
    }
    for (i1 = 0; i1 < b_reflectivity; i1++) {
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
                                      &sb_emlrtBCI, (emlrtCTX)sp);
      }
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &tb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      result->f6->data[b_i].f1->data[i1] = allLayers->data[b_i].f1->data[i1];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_cell_wrap_13(&allLayers);
  /*  Pre-processor directives for Matlab Coder */
  /*  to define the size of the output array */
  /* Result coder definitions.... */
  /* Reflectivity */
  /* Simulatin */
  /* Shifted data */
  /* Layers slds */
  /* Sld profiles */
  /* All layers (resampled) */
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (reflectivity_calculation.c) */
