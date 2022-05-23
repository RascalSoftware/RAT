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
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 88,    /* lineNo */
  "reflectivity_calculation",          /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pathName */
};

static emlrtDCInfo emlrtDCI = { 47,    /* lineNo */
  21,                                  /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 47,  /* lineNo */
  21,                                  /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = { 48,  /* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtDCInfo c_emlrtDCI = { 53,  /* lineNo */
  19,                                  /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = { 54,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 60,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 66,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 72,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 78,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 104,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 110,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 116,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 122,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 128,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 134,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  49,                                  /* lineNo */
  18,                                  /* colNo */
  "reflectivity",                      /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  55,                                  /* lineNo */
  16,                                  /* colNo */
  "Simulation",                        /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  18,                                  /* colNo */
  "shifted_data",                      /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  15,                                  /* colNo */
  "layerSlds",                         /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  17,                                  /* colNo */
  "sldProfiles",                       /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  15,                                  /* colNo */
  "allLayers",                         /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  29,                                  /* colNo */
  "reflectivity",                      /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  11,                                  /* colNo */
  "cell1",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  27,                                  /* colNo */
  "Simulation",                        /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  11,                                  /* colNo */
  "cell2",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  117,                                 /* lineNo */
  29,                                  /* colNo */
  "shifted_data",                      /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  117,                                 /* lineNo */
  11,                                  /* colNo */
  "cell3",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  123,                                 /* lineNo */
  26,                                  /* colNo */
  "layerSlds",                         /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  123,                                 /* lineNo */
  11,                                  /* colNo */
  "cell4",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  129,                                 /* lineNo */
  28,                                  /* colNo */
  "sldProfiles",                       /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  129,                                 /* lineNo */
  11,                                  /* colNo */
  "cell5",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  135,                                 /* lineNo */
  26,                                  /* colNo */
  "allLayers",                         /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  135,                                 /* lineNo */
  11,                                  /* colNo */
  "cell6",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  16,                                  /* colNo */
  "reflectivity",                      /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  5,                                   /* colNo */
  "cell1",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  16,                                  /* colNo */
  "Simulation",                        /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  5,                                   /* colNo */
  "cell2",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  117,                                 /* lineNo */
  16,                                  /* colNo */
  "shifted_data",                      /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  117,                                 /* lineNo */
  5,                                   /* colNo */
  "cell3",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  123,                                 /* lineNo */
  16,                                  /* colNo */
  "layerSlds",                         /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  123,                                 /* lineNo */
  5,                                   /* colNo */
  "cell4",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  129,                                 /* lineNo */
  16,                                  /* colNo */
  "sldProfiles",                       /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  129,                                 /* lineNo */
  5,                                   /* colNo */
  "cell5",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  135,                                 /* lineNo */
  16,                                  /* colNo */
  "allLayers",                         /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  135,                                 /* lineNo */
  5,                                   /* colNo */
  "cell6",                             /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  49,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  55,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo wd_emlrtRTEI = { 28,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo xd_emlrtRTEI = { 29,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo yd_emlrtRTEI = { 30,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ae_emlrtRTEI = { 31,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo be_emlrtRTEI = { 32,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ce_emlrtRTEI = { 33,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo de_emlrtRTEI = { 34,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ee_emlrtRTEI = { 35,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo fe_emlrtRTEI = { 37,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ge_emlrtRTEI = { 38,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo he_emlrtRTEI = { 49,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ie_emlrtRTEI = { 55,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo je_emlrtRTEI = { 61,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ke_emlrtRTEI = { 67,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo le_emlrtRTEI = { 73,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo me_emlrtRTEI = { 79,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ne_emlrtRTEI = { 88,/* lineNo */
  136,                                 /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo oe_emlrtRTEI = { 107,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo pe_emlrtRTEI = { 105,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo qe_emlrtRTEI = { 113,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo re_emlrtRTEI = { 88,/* lineNo */
  9,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo se_emlrtRTEI = { 111,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo te_emlrtRTEI = { 119,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ue_emlrtRTEI = { 117,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ve_emlrtRTEI = { 125,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo we_emlrtRTEI = { 123,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo xe_emlrtRTEI = { 129,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ye_emlrtRTEI = { 135,/* lineNo */
  5,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo af_emlrtRTEI = { 88,/* lineNo */
  18,                                  /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo bf_emlrtRTEI = { 88,/* lineNo */
  42,                                  /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo cf_emlrtRTEI = { 88,/* lineNo */
  55,                                  /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo df_emlrtRTEI = { 88,/* lineNo */
  65,                                  /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ef_emlrtRTEI = { 47,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo ff_emlrtRTEI = { 53,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo gf_emlrtRTEI = { 59,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo hf_emlrtRTEI = { 65,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo if_emlrtRTEI = { 71,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo jf_emlrtRTEI = { 77,/* lineNo */
  1,                                   /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

static emlrtRTEInfo kf_emlrtRTEI = { 1,/* lineNo */
  29,                                  /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

/* Function Definitions */
emlrtCTX emlrtGetRootTLSGlobal(void)
{
  return emlrtRootTLSGlobal;
}

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, const emlrtConstCTX aTLS,
  void *aData)
{
  omp_set_lock(&emlrtLockGlobal);
  emlrtCallLockeeFunction(aLockee, aTLS, aData);
  omp_unset_lock(&emlrtLockGlobal);
}

void reflectivity_calculation(const emlrtStack *sp, const struct0_T *problemDef,
  const cell_8 *problemDef_cells, const struct1_T *problemDef_limits, const
  struct2_T *controls, struct4_T *problem, cell_11 *result)
{
  static const char_T b_cv[10] = { 's', 't', 'a', 'n', 'd', 'a', 'r', 'd', 'T',
    'F' };

  cell_16 expl_temp;
  emlrtStack st;
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
  int32_T b_i;
  int32_T exitg1;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T kstr;
  boolean_T b_bool;
  (void)problemDef_limits;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  Main entry point into the reflectivity calculation for the toolbox. */
  /*  This is the main function that is called by any of the minimisers or */
  /*  analysis tools from the rest of the toolbox. The main job of this */
  /*  function is to decide which type of calculation (i.e. 'Target function' */
  /*  is required, and call the relevant routines. The types of available  */
  /*  target functions are: */
  /*  */
  /*  1. standardTF       - The main basic target function type, for non polarised  */
  /*                        neutrons (or x-rays) with non-absorbing samples. */
  /*                        Different model types are specified in sub functions */
  /*                        from here. */
  /*  */
  /*  2. standardTFAbs    - Identical to standardTF, but includes imaginary refractive  */
  /*                        index terms. */
  /*  */
  /*  3. oilWaterTF       - Target function for oil-water samples */
  /*  */
  /*  4. domainsTF        - Target function for samples consisting of domains  */
  /*                        which are larger than the beam lateral coherence length. */
  /*  */
  /*  5. polarisedTF      - Target function for cases for polarised neutrons */
  /*                        with polarisation analysis */
  /*  for compilation, we have to preallocate memory for the output arrays */
  /*  Setting these parameters in the struct defines them as doubles */
  i = problem->ssubs->size[0];
  problem->ssubs->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->ssubs, i, &wd_emlrtRTEI);
  problem->ssubs->data[0] = 0.0;
  i = problem->backgrounds->size[0];
  problem->backgrounds->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->backgrounds, i, &xd_emlrtRTEI);
  problem->backgrounds->data[0] = 0.0;
  i = problem->qshifts->size[0];
  problem->qshifts->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->qshifts, i, &yd_emlrtRTEI);
  problem->qshifts->data[0] = 0.0;
  i = problem->scalefactors->size[0];
  problem->scalefactors->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->scalefactors, i, &ae_emlrtRTEI);
  problem->scalefactors->data[0] = 0.0;
  i = problem->nbairs->size[0];
  problem->nbairs->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->nbairs, i, &be_emlrtRTEI);
  problem->nbairs->data[0] = 0.0;
  i = problem->nbsubs->size[0];
  problem->nbsubs->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->nbsubs, i, &ce_emlrtRTEI);
  problem->nbsubs->data[0] = 0.0;
  i = problem->resolutions->size[0];
  problem->resolutions->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->resolutions, i, &de_emlrtRTEI);
  problem->resolutions->data[0] = 0.0;
  i = problem->calculations.all_chis->size[0];
  problem->calculations.all_chis->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->calculations.all_chis, i, &ee_emlrtRTEI);
  problem->calculations.all_chis->data[0] = 0.0;
  problem->calculations.sum_chi = 0.0;
  i = problem->allSubRough->size[0];
  problem->allSubRough->size[0] = 1;
  emxEnsureCapacity_real_T(sp, problem->allSubRough, i, &fe_emlrtRTEI);
  problem->allSubRough->data[0] = 0.0;
  i = problem->resample->size[0] * problem->resample->size[1];
  problem->resample->size[0] = 1;
  problem->resample->size[1] = 1;
  emxEnsureCapacity_real_T(sp, problem->resample, i, &ge_emlrtRTEI);
  problem->resample->data[0] = 0.0;

  /*  We also foll the results arrays to define their */
  /*  type and size. (NOTE: at the moment we have a 'coder.varsize' */
  /*  pre-processor directives for the compiler here and at the  */
  /*  end for the results block. We are unlikely to need both */
  /*  TODO: Find out which is necessary and tidy this up. */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &emlrtDCI, sp);
  }

  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &b_emlrtDCI, sp);
  }

  emxInit_cell_wrap_12(sp, &reflectivity, 1, &ef_emlrtRTEI, true);
  i1 = (int32_T)problemDef->numberOfContrasts;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &emlrtRTEI, sp);
  i2 = reflectivity->size[0];
  reflectivity->size[0] = i1;
  emxEnsureCapacity_cell_wrap_12(sp, reflectivity, i2, &wd_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1, &emlrtBCI,
        sp);
    }

    i2 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i2, &he_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1, &emlrtBCI,
        sp);
    }

    i2 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i2, &he_emlrtRTEI);
    i2 = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1, &emlrtBCI,
        sp);
    }

    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1, &emlrtBCI,
        sp);
    }

    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &ib_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i2 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2 - 1, &ib_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i2 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2 - 1, &ib_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i2 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2 - 1, &ib_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  if (i1 != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &c_emlrtDCI, sp);
  }

  emxInit_cell_wrap_12(sp, &Simulation, 1, &ff_emlrtRTEI, true);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &b_emlrtRTEI, sp);
  i = Simulation->size[0];
  Simulation->size[0] = i1;
  emxEnsureCapacity_cell_wrap_12(sp, Simulation, i, &wd_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1, &b_emlrtBCI,
        sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &ie_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1, &b_emlrtBCI,
        sp);
    }

    i = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i, &ie_emlrtRTEI);
    i = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1, &b_emlrtBCI,
        sp);
    }

    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1, &b_emlrtBCI,
        sp);
    }

    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &jb_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &jb_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &jb_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &jb_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxInit_cell_wrap_13(sp, &shifted_data, 1, &gf_emlrtRTEI, true);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &c_emlrtRTEI, sp);
  i = shifted_data->size[0];
  shifted_data->size[0] = i1;
  emxEnsureCapacity_cell_wrap_13(sp, shifted_data, i, &wd_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &c_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &je_emlrtRTEI);
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &c_emlrtBCI, sp);
    }

    i = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i].f1->size[1];
    shifted_data->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data->data[b_i].f1, i, &je_emlrtRTEI);
    i = shifted_data->size[0];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &c_emlrtBCI, sp);
    }

    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &c_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < 6; i2++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &s_emlrtBCI, sp);
      }

      shifted_data->data[b_i].f1->data[i2] = 1.0;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxInit_cell_wrap_13(sp, &layerSlds, 1, &hf_emlrtRTEI, true);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &d_emlrtRTEI, sp);
  i = layerSlds->size[0];
  layerSlds->size[0] = i1;
  emxEnsureCapacity_cell_wrap_13(sp, layerSlds, i, &wd_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &d_emlrtBCI,
        sp);
    }

    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &ke_emlrtRTEI);
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &d_emlrtBCI,
        sp);
    }

    i = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    layerSlds->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layerSlds->data[b_i].f1, i, &ke_emlrtRTEI);
    i = layerSlds->size[0];
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &d_emlrtBCI,
        sp);
    }

    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &d_emlrtBCI,
        sp);
    }

    for (i2 = 0; i2 < 6; i2++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &t_emlrtBCI, sp);
      }

      layerSlds->data[b_i].f1->data[i2] = 1.0;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxInit_cell_wrap_12(sp, &sldProfiles, 1, &if_emlrtRTEI, true);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &e_emlrtRTEI, sp);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = i1;
  emxEnsureCapacity_cell_wrap_12(sp, sldProfiles, i, &wd_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &e_emlrtBCI, sp);
    }

    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &le_emlrtRTEI);
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &e_emlrtBCI, sp);
    }

    i = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i, &le_emlrtRTEI);
    i = sldProfiles->size[0];
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &e_emlrtBCI, sp);
    }

    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &e_emlrtBCI, sp);
    }

    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &kb_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[0] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &kb_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[1] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &kb_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[2] = 1.0;
    if (b_i > i - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &kb_emlrtBCI, sp);
    }

    sldProfiles->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxInit_cell_wrap_13(sp, &allLayers, 1, &jf_emlrtRTEI, true);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &f_emlrtRTEI, sp);
  i = allLayers->size[0];
  allLayers->size[0] = i1;
  emxEnsureCapacity_cell_wrap_13(sp, allLayers, i, &wd_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &f_emlrtBCI,
        sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &me_emlrtRTEI);
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &f_emlrtBCI,
        sp);
    }

    i = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i, &me_emlrtRTEI);
    i = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &f_emlrtBCI,
        sp);
    }

    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &f_emlrtBCI,
        sp);
    }

    for (i2 = 0; i2 < 6; i2++) {
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &u_emlrtBCI, sp);
      }

      allLayers->data[b_i].f1->data[i2] = 1.0;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /* Decide which target function we are calling ans call the relevant routines */
  b_bool = false;
  if (problemDef->TF->size[1] == 10) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 10) {
        if (problemDef->TF->data[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  if (b_bool) {
    kstr = 0;
  } else {
    kstr = -1;
  }

  switch (kstr) {
   case 0:
    emxInitStruct_cell_16(sp, &expl_temp, &re_emlrtRTEI, true);
    i = expl_temp.f2->size[0] * expl_temp.f2->size[1];
    expl_temp.f2->size[0] = 1;
    expl_temp.f2->size[1] = problemDef_cells->f2->size[1];
    emxEnsureCapacity_cell_wrap_14(sp, expl_temp.f2, i, &ne_emlrtRTEI);
    i = problemDef_cells->f2->size[1] - 1;
    for (i2 = 0; i2 <= i; i2++) {
      b_i = expl_temp.f2->data[i2].f1->size[0] * expl_temp.f2->data[i2].f1->
        size[1];
      expl_temp.f2->data[i2].f1->size[0] = problemDef_cells->f2->data[i2]
        .f1->size[0];
      expl_temp.f2->data[i2].f1->size[1] = problemDef_cells->f2->data[i2]
        .f1->size[1];
      emxEnsureCapacity_real_T(sp, expl_temp.f2->data[i2].f1, b_i, &ne_emlrtRTEI);
      kstr = problemDef_cells->f2->data[i2].f1->size[0] * problemDef_cells->
        f2->data[i2].f1->size[1];
      for (b_i = 0; b_i < kstr; b_i++) {
        expl_temp.f2->data[i2].f1->data[b_i] = problemDef_cells->f2->data[i2].
          f1->data[b_i];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    i = expl_temp.f4->size[0] * expl_temp.f4->size[1];
    expl_temp.f4->size[0] = 1;
    expl_temp.f4->size[1] = problemDef_cells->f4->size[1];
    emxEnsureCapacity_cell_wrap_14(sp, expl_temp.f4, i, &ne_emlrtRTEI);
    i = problemDef_cells->f4->size[1] - 1;
    for (i2 = 0; i2 <= i; i2++) {
      b_i = expl_temp.f4->data[i2].f1->size[0] * expl_temp.f4->data[i2].f1->
        size[1];
      expl_temp.f4->data[i2].f1->size[0] = problemDef_cells->f4->data[i2].
        f1.size[0];
      expl_temp.f4->data[i2].f1->size[1] = problemDef_cells->f4->data[i2].
        f1.size[1];
      emxEnsureCapacity_real_T(sp, expl_temp.f4->data[i2].f1, b_i, &ne_emlrtRTEI);
      kstr = problemDef_cells->f4->data[i2].f1.size[0] * problemDef_cells->
        f4->data[i2].f1.size[1];
      for (b_i = 0; b_i < kstr; b_i++) {
        expl_temp.f4->data[i2].f1->data[b_i] = problemDef_cells->f4->data[i2].
          f1.data[b_i];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    i = expl_temp.f5->size[0] * expl_temp.f5->size[1];
    expl_temp.f5->size[0] = 1;
    expl_temp.f5->size[1] = problemDef_cells->f5->size[1];
    emxEnsureCapacity_cell_wrap_14(sp, expl_temp.f5, i, &ne_emlrtRTEI);
    i = problemDef_cells->f5->size[1] - 1;
    for (i2 = 0; i2 <= i; i2++) {
      b_i = expl_temp.f5->data[i2].f1->size[0] * expl_temp.f5->data[i2].f1->
        size[1];
      expl_temp.f5->data[i2].f1->size[0] = problemDef_cells->f5->data[i2]
        .f1->size[0];
      expl_temp.f5->data[i2].f1->size[1] = problemDef_cells->f5->data[i2]
        .f1->size[1];
      emxEnsureCapacity_real_T(sp, expl_temp.f5->data[i2].f1, b_i, &ne_emlrtRTEI);
      kstr = problemDef_cells->f5->data[i2].f1->size[0] * problemDef_cells->
        f5->data[i2].f1->size[1];
      for (b_i = 0; b_i < kstr; b_i++) {
        expl_temp.f5->data[i2].f1->data[b_i] = problemDef_cells->f5->data[i2].
          f1->data[b_i];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    i = expl_temp.f6->size[0];
    expl_temp.f6->size[0] = problemDef_cells->f6->size[0];
    emxEnsureCapacity_cell_wrap_14(sp, expl_temp.f6, i, &ne_emlrtRTEI);
    i = problemDef_cells->f6->size[0];
    for (i2 = 0; i2 < i; i2++) {
      b_i = expl_temp.f6->data[i2].f1->size[0] * expl_temp.f6->data[i2].f1->
        size[1];
      expl_temp.f6->data[i2].f1->size[0] = problemDef_cells->f6->data[i2].
        f1.size[0];
      expl_temp.f6->data[i2].f1->size[1] = problemDef_cells->f6->data[i2].
        f1.size[1];
      emxEnsureCapacity_real_T(sp, expl_temp.f6->data[i2].f1, b_i, &ne_emlrtRTEI);
      kstr = problemDef_cells->f6->data[i2].f1.size[0] * problemDef_cells->
        f6->data[i2].f1.size[1];
      for (b_i = 0; b_i < kstr; b_i++) {
        expl_temp.f6->data[i2].f1->data[b_i] = problemDef_cells->f6->data[i2].
          f1.data[b_i];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    i = expl_temp.f14->size[0] * expl_temp.f14->size[1];
    expl_temp.f14->size[0] = 1;
    expl_temp.f14->size[1] = problemDef_cells->f14->size[1];
    emxEnsureCapacity_cell_wrap_7(sp, expl_temp.f14, i, &re_emlrtRTEI);
    kstr = problemDef_cells->f14->size[0] * problemDef_cells->f14->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_7(sp, &expl_temp.f14->data[i],
        &problemDef_cells->f14->data[i], &re_emlrtRTEI);
    }

    i = expl_temp.f13->size[0] * expl_temp.f13->size[1];
    expl_temp.f13->size[0] = 1;
    expl_temp.f13->size[1] = problemDef_cells->f13->size[1];
    emxEnsureCapacity_cell_wrap_6(sp, expl_temp.f13, i, &re_emlrtRTEI);
    kstr = problemDef_cells->f13->size[0] * problemDef_cells->f13->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_6(sp, &expl_temp.f13->data[i],
        &problemDef_cells->f13->data[i], &re_emlrtRTEI);
    }

    i = expl_temp.f12->size[0] * expl_temp.f12->size[1];
    expl_temp.f12->size[0] = 1;
    expl_temp.f12->size[1] = problemDef_cells->f12->size[1];
    emxEnsureCapacity_cell_wrap_6(sp, expl_temp.f12, i, &re_emlrtRTEI);
    kstr = problemDef_cells->f12->size[0] * problemDef_cells->f12->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_6(sp, &expl_temp.f12->data[i],
        &problemDef_cells->f12->data[i], &re_emlrtRTEI);
    }

    i = expl_temp.f11->size[0] * expl_temp.f11->size[1];
    expl_temp.f11->size[0] = 1;
    expl_temp.f11->size[1] = problemDef_cells->f11->size[1];
    emxEnsureCapacity_cell_wrap_6(sp, expl_temp.f11, i, &re_emlrtRTEI);
    kstr = problemDef_cells->f11->size[0] * problemDef_cells->f11->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_6(sp, &expl_temp.f11->data[i],
        &problemDef_cells->f11->data[i], &re_emlrtRTEI);
    }

    i = expl_temp.f10->size[0] * expl_temp.f10->size[1];
    expl_temp.f10->size[0] = 1;
    expl_temp.f10->size[1] = problemDef_cells->f10->size[1];
    emxEnsureCapacity_cell_wrap_6(sp, expl_temp.f10, i, &re_emlrtRTEI);
    kstr = problemDef_cells->f10->size[0] * problemDef_cells->f10->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_6(sp, &expl_temp.f10->data[i],
        &problemDef_cells->f10->data[i], &re_emlrtRTEI);
    }

    i = expl_temp.f9->size[0] * expl_temp.f9->size[1];
    expl_temp.f9->size[0] = 1;
    expl_temp.f9->size[1] = problemDef_cells->f9->size[1];
    emxEnsureCapacity_cell_wrap_6(sp, expl_temp.f9, i, &re_emlrtRTEI);
    kstr = problemDef_cells->f9->size[0] * problemDef_cells->f9->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_6(sp, &expl_temp.f9->data[i],
        &problemDef_cells->f9->data[i], &re_emlrtRTEI);
    }

    i = expl_temp.f8->size[0] * expl_temp.f8->size[1];
    expl_temp.f8->size[0] = 1;
    expl_temp.f8->size[1] = problemDef_cells->f8->size[1];
    emxEnsureCapacity_cell_wrap_6(sp, expl_temp.f8, i, &re_emlrtRTEI);
    kstr = problemDef_cells->f8->size[0] * problemDef_cells->f8->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_6(sp, &expl_temp.f8->data[i],
        &problemDef_cells->f8->data[i], &re_emlrtRTEI);
    }

    i = expl_temp.f7->size[0] * expl_temp.f7->size[1];
    expl_temp.f7->size[0] = 1;
    expl_temp.f7->size[1] = problemDef_cells->f7->size[1];
    emxEnsureCapacity_cell_wrap_5(sp, expl_temp.f7, i, &re_emlrtRTEI);
    kstr = problemDef_cells->f7->size[0] * problemDef_cells->f7->size[1];
    for (i = 0; i < kstr; i++) {
      emxCopyStruct_cell_wrap_5(sp, &expl_temp.f7->data[i],
        &problemDef_cells->f7->data[i], &re_emlrtRTEI);
    }

    i = expl_temp.f3->size[0] * expl_temp.f3->size[1];
    expl_temp.f3->size[0] = 1;
    expl_temp.f3->size[1] = problemDef_cells->f3->size[1];
    emxEnsureCapacity_cell_wrap_0(sp, expl_temp.f3, i, &re_emlrtRTEI);
    kstr = problemDef_cells->f3->size[0] * problemDef_cells->f3->size[1];
    for (i = 0; i < kstr; i++) {
      expl_temp.f3->data[i] = problemDef_cells->f3->data[i];
    }

    i = expl_temp.f1->size[0] * expl_temp.f1->size[1];
    expl_temp.f1->size[0] = 1;
    expl_temp.f1->size[1] = problemDef_cells->f1->size[1];
    emxEnsureCapacity_cell_wrap_0(sp, expl_temp.f1, i, &re_emlrtRTEI);
    kstr = problemDef_cells->f1->size[0] * problemDef_cells->f1->size[1];
    for (i = 0; i < kstr; i++) {
      expl_temp.f1->data[i] = problemDef_cells->f1->data[i];
    }

    emxInit_cell_wrap_9(sp, &b_Simulation, 1, &kf_emlrtRTEI, true);
    emxInit_cell_wrap_14(sp, &b_shifted_data, 1, &kf_emlrtRTEI, true);
    emxInit_cell_wrap_14(sp, &b_sldProfiles, 1, &kf_emlrtRTEI, true);
    emxInit_cell_wrap_14(sp, &b_allLayers, 1, &kf_emlrtRTEI, true);
    st.site = &emlrtRSI;
    c_standardTF_reflectivityCalcul(&st, problemDef, &expl_temp, controls,
      problem, result->f5, b_Simulation, b_shifted_data, result->f6,
      b_sldProfiles, b_allLayers);
    i = reflectivity->size[0];
    reflectivity->size[0] = result->f5->size[0];
    emxEnsureCapacity_cell_wrap_12(sp, reflectivity, i, &af_emlrtRTEI);
    i = result->f5->size[0];
    emxFreeStruct_cell_16(&expl_temp);
    for (i2 = 0; i2 < i; i2++) {
      b_i = reflectivity->data[i2].f1->size[0] * reflectivity->data[i2].f1->
        size[1];
      reflectivity->data[i2].f1->size[0] = result->f5->data[i2].f1->size[0];
      reflectivity->data[i2].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, reflectivity->data[i2].f1, b_i, &af_emlrtRTEI);
      kstr = result->f5->data[i2].f1->size[0] * result->f5->data[i2].f1->size[1];
      for (b_i = 0; b_i < kstr; b_i++) {
        reflectivity->data[i2].f1->data[b_i] = result->f5->data[i2].f1->data[b_i];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    i = Simulation->size[0];
    Simulation->size[0] = b_Simulation->size[0];
    emxEnsureCapacity_cell_wrap_12(sp, Simulation, i, &af_emlrtRTEI);
    i = b_Simulation->size[0];
    for (i2 = 0; i2 < i; i2++) {
      b_i = Simulation->data[i2].f1->size[0] * Simulation->data[i2].f1->size[1];
      Simulation->data[i2].f1->size[0] = b_Simulation->data[i2].f1->size[0];
      Simulation->data[i2].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, Simulation->data[i2].f1, b_i, &af_emlrtRTEI);
      kstr = b_Simulation->data[i2].f1->size[0] * b_Simulation->data[i2]
        .f1->size[1];
      for (b_i = 0; b_i < kstr; b_i++) {
        Simulation->data[i2].f1->data[b_i] = b_Simulation->data[i2].f1->data[b_i];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    emxFree_cell_wrap_9(&b_Simulation);
    i = shifted_data->size[0];
    shifted_data->size[0] = b_shifted_data->size[0];
    emxEnsureCapacity_cell_wrap_13(sp, shifted_data, i, &bf_emlrtRTEI);
    i = b_shifted_data->size[0];
    for (i2 = 0; i2 < i; i2++) {
      b_i = shifted_data->data[i2].f1->size[0] * shifted_data->data[i2].f1->
        size[1];
      shifted_data->data[i2].f1->size[0] = b_shifted_data->data[i2].f1->size[0];
      shifted_data->data[i2].f1->size[1] = b_shifted_data->data[i2].f1->size[1];
      emxEnsureCapacity_real_T(sp, shifted_data->data[i2].f1, b_i, &bf_emlrtRTEI);
      kstr = b_shifted_data->data[i2].f1->size[0] * b_shifted_data->data[i2].
        f1->size[1];
      for (b_i = 0; b_i < kstr; b_i++) {
        shifted_data->data[i2].f1->data[b_i] = b_shifted_data->data[i2].f1->
          data[b_i];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    emxFree_cell_wrap_14(&b_shifted_data);
    i = layerSlds->size[0];
    layerSlds->size[0] = result->f6->size[0];
    emxEnsureCapacity_cell_wrap_13(sp, layerSlds, i, &cf_emlrtRTEI);
    i = result->f6->size[0];
    for (i2 = 0; i2 < i; i2++) {
      b_i = layerSlds->data[i2].f1->size[0] * layerSlds->data[i2].f1->size[1];
      layerSlds->data[i2].f1->size[0] = result->f6->data[i2].f1->size[0];
      layerSlds->data[i2].f1->size[1] = 3;
      emxEnsureCapacity_real_T(sp, layerSlds->data[i2].f1, b_i, &cf_emlrtRTEI);
      kstr = result->f6->data[i2].f1->size[0] * result->f6->data[i2].f1->size[1];
      for (b_i = 0; b_i < kstr; b_i++) {
        layerSlds->data[i2].f1->data[b_i] = result->f6->data[i2].f1->data[b_i];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    i = sldProfiles->size[0];
    sldProfiles->size[0] = b_sldProfiles->size[0];
    emxEnsureCapacity_cell_wrap_12(sp, sldProfiles, i, &df_emlrtRTEI);
    i = b_sldProfiles->size[0];
    for (i2 = 0; i2 < i; i2++) {
      b_i = sldProfiles->data[i2].f1->size[0] * sldProfiles->data[i2].f1->size[1];
      sldProfiles->data[i2].f1->size[0] = b_sldProfiles->data[i2].f1->size[0];
      sldProfiles->data[i2].f1->size[1] = b_sldProfiles->data[i2].f1->size[1];
      emxEnsureCapacity_real_T(sp, sldProfiles->data[i2].f1, b_i, &df_emlrtRTEI);
      kstr = b_sldProfiles->data[i2].f1->size[0] * b_sldProfiles->data[i2]
        .f1->size[1];
      for (b_i = 0; b_i < kstr; b_i++) {
        sldProfiles->data[i2].f1->data[b_i] = b_sldProfiles->data[i2].f1->
          data[b_i];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    emxFree_cell_wrap_14(&b_sldProfiles);
    i = allLayers->size[0];
    allLayers->size[0] = b_allLayers->size[0];
    emxEnsureCapacity_cell_wrap_13(sp, allLayers, i, &bf_emlrtRTEI);
    i = b_allLayers->size[0];
    for (i2 = 0; i2 < i; i2++) {
      b_i = allLayers->data[i2].f1->size[0] * allLayers->data[i2].f1->size[1];
      allLayers->data[i2].f1->size[0] = b_allLayers->data[i2].f1->size[0];
      allLayers->data[i2].f1->size[1] = b_allLayers->data[i2].f1->size[1];
      emxEnsureCapacity_real_T(sp, allLayers->data[i2].f1, b_i, &bf_emlrtRTEI);
      kstr = b_allLayers->data[i2].f1->size[0] * b_allLayers->data[i2].f1->size
        [1];
      for (b_i = 0; b_i < kstr; b_i++) {
        allLayers->data[i2].f1->data[b_i] = b_allLayers->data[i2].f1->data[b_i];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    emxFree_cell_wrap_14(&b_allLayers);

    /* case 'standardTFAbs' */
    /* [problem,reflectivity,Simulation,shifted_data,layerSlds,sldProfiles,allLayers] = standardTFAbs_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls); */
    /* case 'oilWaterTF' */
    /* problem = oilWaterTF_reflectivityCalculation(problemDef,problemDef_cells,controls);     */
    /* case 'polarisedTF' */
    /* problem = polarisedTF_reflectivityCalculation(problemDef,problemDef_cells,controls); */
    /* case 'domainsTF' */
    /* [problem,reflectivity,Simulation,shifted_data,layerSlds,sldProfiles,allLayers] = domainsTF_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls); */
    break;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &g_emlrtRTEI, sp);
  i = result->f5->size[0];
  result->f5->size[0] = i1;
  emxEnsureCapacity_cell_wrap_9(sp, result->f5, i, &wd_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &g_emlrtBCI, sp);
    }

    kstr = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i]
      .f1->size[1];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &g_emlrtBCI, sp);
    }

    if (b_i > result->f5->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f5->size[0] - 1, &h_emlrtBCI,
        sp);
    }

    i = result->f5->data[b_i].f1->size[0] * result->f5->data[b_i].f1->size[1];
    result->f5->data[b_i].f1->size[0] = reflectivity->data[b_i].f1->size[0];
    emxEnsureCapacity_real_T(sp, result->f5->data[b_i].f1, i, &pe_emlrtRTEI);
    if (b_i > result->f5->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f5->size[0] - 1, &h_emlrtBCI,
        sp);
    }

    i = result->f5->data[b_i].f1->size[0] * result->f5->data[b_i].f1->size[1];
    result->f5->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, result->f5->data[b_i].f1, i, &pe_emlrtRTEI);
    i = result->f5->size[0];
    if (b_i > result->f5->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f5->size[0] - 1, &h_emlrtBCI,
        sp);
    }

    if (b_i > result->f5->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f5->size[0] - 1, &h_emlrtBCI,
        sp);
    }

    for (i2 = 0; i2 < kstr; i2++) {
      if (b_i > reflectivity->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
          &v_emlrtBCI, sp);
      }

      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &w_emlrtBCI, sp);
      }

      result->f5->data[b_i].f1->data[i2] = reflectivity->data[b_i].f1->data[i2];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_cell_wrap_12(&reflectivity);
  i = result->f1->size[0];
  result->f1->size[0] = result->f5->size[0];
  emxEnsureCapacity_cell_wrap_9(sp, result->f1, i, &oe_emlrtRTEI);
  kstr = result->f5->size[0];
  for (i = 0; i < kstr; i++) {
    emxCopyStruct_cell_wrap_9(sp, &result->f1->data[i], &result->f5->data[i],
      &oe_emlrtRTEI);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &h_emlrtRTEI, sp);
  i = result->f5->size[0];
  result->f5->size[0] = i1;
  emxEnsureCapacity_cell_wrap_9(sp, result->f5, i, &wd_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1, &i_emlrtBCI,
        sp);
    }

    kstr = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1, &i_emlrtBCI,
        sp);
    }

    if (b_i > result->f5->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f5->size[0] - 1, &j_emlrtBCI,
        sp);
    }

    i = result->f5->data[b_i].f1->size[0] * result->f5->data[b_i].f1->size[1];
    result->f5->data[b_i].f1->size[0] = Simulation->data[b_i].f1->size[0];
    emxEnsureCapacity_real_T(sp, result->f5->data[b_i].f1, i, &se_emlrtRTEI);
    if (b_i > result->f5->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f5->size[0] - 1, &j_emlrtBCI,
        sp);
    }

    i = result->f5->data[b_i].f1->size[0] * result->f5->data[b_i].f1->size[1];
    result->f5->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, result->f5->data[b_i].f1, i, &se_emlrtRTEI);
    i = result->f5->size[0];
    if (b_i > result->f5->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f5->size[0] - 1, &j_emlrtBCI,
        sp);
    }

    if (b_i > result->f5->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f5->size[0] - 1, &j_emlrtBCI,
        sp);
    }

    for (i2 = 0; i2 < kstr; i2++) {
      if (b_i > Simulation->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
          &x_emlrtBCI, sp);
      }

      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &y_emlrtBCI, sp);
      }

      result->f5->data[b_i].f1->data[i2] = Simulation->data[b_i].f1->data[i2];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_cell_wrap_12(&Simulation);
  i = result->f2->size[0];
  result->f2->size[0] = result->f5->size[0];
  emxEnsureCapacity_cell_wrap_9(sp, result->f2, i, &qe_emlrtRTEI);
  kstr = result->f5->size[0];
  for (i = 0; i < kstr; i++) {
    emxCopyStruct_cell_wrap_9(sp, &result->f2->data[i], &result->f5->data[i],
      &qe_emlrtRTEI);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &i_emlrtRTEI, sp);
  i = result->f6->size[0];
  result->f6->size[0] = i1;
  emxEnsureCapacity_cell_wrap_10(sp, result->f6, i, &wd_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &k_emlrtBCI, sp);
    }

    kstr = shifted_data->data[b_i].f1->size[0] * shifted_data->data[b_i]
      .f1->size[1];
    if (b_i > shifted_data->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
        &k_emlrtBCI, sp);
    }

    if (b_i > result->f6->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f6->size[0] - 1, &l_emlrtBCI,
        sp);
    }

    i = result->f6->data[b_i].f1->size[0] * result->f6->data[b_i].f1->size[1];
    result->f6->data[b_i].f1->size[0] = shifted_data->data[b_i].f1->size[0];
    emxEnsureCapacity_real_T(sp, result->f6->data[b_i].f1, i, &ue_emlrtRTEI);
    if (b_i > result->f6->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f6->size[0] - 1, &l_emlrtBCI,
        sp);
    }

    i = result->f6->data[b_i].f1->size[0] * result->f6->data[b_i].f1->size[1];
    result->f6->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, result->f6->data[b_i].f1, i, &ue_emlrtRTEI);
    i = result->f6->size[0];
    if (b_i > result->f6->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f6->size[0] - 1, &l_emlrtBCI,
        sp);
    }

    if (b_i > result->f6->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f6->size[0] - 1, &l_emlrtBCI,
        sp);
    }

    for (i2 = 0; i2 < kstr; i2++) {
      if (b_i > shifted_data->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, shifted_data->size[0] - 1,
          &ab_emlrtBCI, sp);
      }

      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &bb_emlrtBCI, sp);
      }

      result->f6->data[b_i].f1->data[i2] = shifted_data->data[b_i].f1->data[i2];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_cell_wrap_13(&shifted_data);
  i = result->f3->size[0];
  result->f3->size[0] = result->f6->size[0];
  emxEnsureCapacity_cell_wrap_10(sp, result->f3, i, &te_emlrtRTEI);
  kstr = result->f6->size[0];
  for (i = 0; i < kstr; i++) {
    emxCopyStruct_cell_wrap_10(sp, &result->f3->data[i], &result->f6->data[i],
      &te_emlrtRTEI);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &j_emlrtRTEI, sp);
  i = result->f6->size[0];
  result->f6->size[0] = i1;
  emxEnsureCapacity_cell_wrap_10(sp, result->f6, i, &wd_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &m_emlrtBCI,
        sp);
    }

    kstr = layerSlds->data[b_i].f1->size[0] * layerSlds->data[b_i].f1->size[1];
    if (b_i > layerSlds->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1, &m_emlrtBCI,
        sp);
    }

    if (b_i > result->f6->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f6->size[0] - 1, &n_emlrtBCI,
        sp);
    }

    i = result->f6->data[b_i].f1->size[0] * result->f6->data[b_i].f1->size[1];
    result->f6->data[b_i].f1->size[0] = layerSlds->data[b_i].f1->size[0];
    emxEnsureCapacity_real_T(sp, result->f6->data[b_i].f1, i, &we_emlrtRTEI);
    if (b_i > result->f6->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f6->size[0] - 1, &n_emlrtBCI,
        sp);
    }

    i = result->f6->data[b_i].f1->size[0] * result->f6->data[b_i].f1->size[1];
    result->f6->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, result->f6->data[b_i].f1, i, &we_emlrtRTEI);
    i = result->f6->size[0];
    if (b_i > result->f6->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f6->size[0] - 1, &n_emlrtBCI,
        sp);
    }

    if (b_i > result->f6->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f6->size[0] - 1, &n_emlrtBCI,
        sp);
    }

    for (i2 = 0; i2 < kstr; i2++) {
      if (b_i > layerSlds->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, layerSlds->size[0] - 1,
          &cb_emlrtBCI, sp);
      }

      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &db_emlrtBCI, sp);
      }

      result->f6->data[b_i].f1->data[i2] = layerSlds->data[b_i].f1->data[i2];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_cell_wrap_13(&layerSlds);
  i = result->f4->size[0];
  result->f4->size[0] = result->f6->size[0];
  emxEnsureCapacity_cell_wrap_10(sp, result->f4, i, &ve_emlrtRTEI);
  kstr = result->f6->size[0];
  for (i = 0; i < kstr; i++) {
    emxCopyStruct_cell_wrap_10(sp, &result->f4->data[i], &result->f6->data[i],
      &ve_emlrtRTEI);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &k_emlrtRTEI, sp);
  i = result->f5->size[0];
  result->f5->size[0] = i1;
  emxEnsureCapacity_cell_wrap_9(sp, result->f5, i, &wd_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &o_emlrtBCI, sp);
    }

    kstr = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size
      [1];
    if (b_i > sldProfiles->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
        &o_emlrtBCI, sp);
    }

    if (b_i > result->f5->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f5->size[0] - 1, &p_emlrtBCI,
        sp);
    }

    i = result->f5->data[b_i].f1->size[0] * result->f5->data[b_i].f1->size[1];
    result->f5->data[b_i].f1->size[0] = sldProfiles->data[b_i].f1->size[0];
    emxEnsureCapacity_real_T(sp, result->f5->data[b_i].f1, i, &xe_emlrtRTEI);
    if (b_i > result->f5->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f5->size[0] - 1, &p_emlrtBCI,
        sp);
    }

    i = result->f5->data[b_i].f1->size[0] * result->f5->data[b_i].f1->size[1];
    result->f5->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, result->f5->data[b_i].f1, i, &xe_emlrtRTEI);
    i = result->f5->size[0];
    if (b_i > result->f5->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f5->size[0] - 1, &p_emlrtBCI,
        sp);
    }

    if (b_i > result->f5->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f5->size[0] - 1, &p_emlrtBCI,
        sp);
    }

    for (i2 = 0; i2 < kstr; i2++) {
      if (b_i > sldProfiles->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, sldProfiles->size[0] - 1,
          &eb_emlrtBCI, sp);
      }

      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &fb_emlrtBCI, sp);
      }

      result->f5->data[b_i].f1->data[i2] = sldProfiles->data[b_i].f1->data[i2];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_cell_wrap_12(&sldProfiles);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &l_emlrtRTEI, sp);
  i = result->f6->size[0];
  result->f6->size[0] = i1;
  emxEnsureCapacity_cell_wrap_10(sp, result->f6, i, &wd_emlrtRTEI);
  for (b_i = 0; b_i < i1; b_i++) {
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &q_emlrtBCI,
        sp);
    }

    kstr = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &q_emlrtBCI,
        sp);
    }

    if (b_i > result->f6->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f6->size[0] - 1, &r_emlrtBCI,
        sp);
    }

    i = result->f6->data[b_i].f1->size[0] * result->f6->data[b_i].f1->size[1];
    result->f6->data[b_i].f1->size[0] = allLayers->data[b_i].f1->size[0];
    emxEnsureCapacity_real_T(sp, result->f6->data[b_i].f1, i, &ye_emlrtRTEI);
    if (b_i > result->f6->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f6->size[0] - 1, &r_emlrtBCI,
        sp);
    }

    i = result->f6->data[b_i].f1->size[0] * result->f6->data[b_i].f1->size[1];
    result->f6->data[b_i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(sp, result->f6->data[b_i].f1, i, &ye_emlrtRTEI);
    i = result->f6->size[0];
    if (b_i > result->f6->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f6->size[0] - 1, &r_emlrtBCI,
        sp);
    }

    if (b_i > result->f6->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, result->f6->size[0] - 1, &r_emlrtBCI,
        sp);
    }

    for (i2 = 0; i2 < kstr; i2++) {
      if (b_i > allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1,
          &gb_emlrtBCI, sp);
      }

      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &hb_emlrtBCI, sp);
      }

      result->f6->data[b_i].f1->data[i2] = allLayers->data[b_i].f1->data[i2];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
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
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (reflectivity_calculation.c) */
