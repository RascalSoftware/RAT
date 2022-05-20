/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * adaptive_new.c
 *
 * Code generation for function 'adaptive_new'
 *
 */

/* Include files */
#include "adaptive_new.h"
#include "acos.h"
#include "any.h"
#include "eml_int_forloop_overflow_check.h"
#include "find.h"
#include "linspace.h"
#include "power.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sortrows.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo kd_emlrtRSI = { 241,/* lineNo */
  "adaptive_new",                      /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pathName */
};

static emlrtRSInfo ld_emlrtRSI = { 252,/* lineNo */
  "adaptive_new",                      /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pathName */
};

static emlrtRSInfo md_emlrtRSI = { 255,/* lineNo */
  "adaptive_new",                      /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pathName */
};

static emlrtRSInfo nd_emlrtRSI = { 267,/* lineNo */
  "adaptive_new",                      /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pathName */
};

static emlrtRSInfo od_emlrtRSI = { 281,/* lineNo */
  "adaptive_new",                      /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pathName */
};

static emlrtRSInfo pd_emlrtRSI = { 304,/* lineNo */
  "adaptive_new",                      /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pathName */
};

static emlrtRSInfo qd_emlrtRSI = { 305,/* lineNo */
  "adaptive_new",                      /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pathName */
};

static emlrtRSInfo td_emlrtRSI = { 376,/* lineNo */
  "normalizeFunction",                 /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pathName */
};

static emlrtRSInfo ud_emlrtRSI = { 24, /* lineNo */
  "sldFunc",                           /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/sldFunc.m"/* pathName */
};

static emlrtRSInfo vd_emlrtRSI = { 29, /* lineNo */
  "sldFunc",                           /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/sldFunc.m"/* pathName */
};

static emlrtRSInfo wd_emlrtRSI = { 30, /* lineNo */
  "sldFunc",                           /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/sldFunc.m"/* pathName */
};

static emlrtRSInfo ce_emlrtRSI = { 169,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo de_emlrtRSI = { 328,/* lineNo */
  "unaryMinOrMaxDispatch",             /* fcnName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo ee_emlrtRSI = { 396,/* lineNo */
  "minOrMax2D",                        /* fcnName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo fe_emlrtRSI = { 478,/* lineNo */
  "minOrMax2DColumnMajorDim1",         /* fcnName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo ge_emlrtRSI = { 14, /* lineNo */
  "min",                               /* fcnName */
  "/opt/matlab2020b/toolbox/eml/lib/matlab/datafun/min.m"/* pathName */
};

static emlrtRSInfo he_emlrtRSI = { 46, /* lineNo */
  "minOrMax",                          /* fcnName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo ie_emlrtRSI = { 92, /* lineNo */
  "minimum",                           /* fcnName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo je_emlrtRSI = { 398,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pathName */
};

static emlrtRSInfo ke_emlrtRSI = { 399,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pathName */
};

static emlrtRSInfo le_emlrtRSI = { 401,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pathName */
};

static emlrtRSInfo me_emlrtRSI = { 403,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pathName */
};

static emlrtRSInfo ne_emlrtRSI = { 404,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pathName */
};

static emlrtRSInfo oe_emlrtRSI = { 405,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pathName */
};

static emlrtRSInfo pe_emlrtRSI = { 408,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pathName */
};

static emlrtRSInfo qe_emlrtRSI = { 407,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pathName */
};

static emlrtRSInfo re_emlrtRSI = { 409,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pathName */
};

static emlrtRSInfo we_emlrtRSI = { 16, /* lineNo */
  "sqrt",                              /* fcnName */
  "/opt/matlab2020b/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pathName */
};

static emlrtRSInfo bf_emlrtRSI = { 431,/* lineNo */
  "increaseSampling",                  /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pathName */
};

static emlrtRSInfo cf_emlrtRSI = { 433,/* lineNo */
  "increaseSampling",                  /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pathName */
};

static emlrtRSInfo df_emlrtRSI = { 27, /* lineNo */
  "cat",                               /* fcnName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtDCInfo kb_emlrtDCI = { 274,/* lineNo */
  30,                                  /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m",/* pName */
  4                                    /* checkKind */
};

static emlrtECInfo f_emlrtECI = { -1,  /* nDims */
  283,                                 /* lineNo */
  25,                                  /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtECInfo g_emlrtECI = { -1,  /* nDims */
  289,                                 /* lineNo */
  21,                                  /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 26,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 97,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pName */
};

static emlrtECInfo h_emlrtECI = { -1,  /* nDims */
  429,                                 /* lineNo */
  29,                                  /* colNo */
  "increaseSampling",                  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtECInfo i_emlrtECI = { -1,  /* nDims */
  429,                                 /* lineNo */
  1,                                   /* colNo */
  "increaseSampling",                  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtECInfo j_emlrtECI = { -1,  /* nDims */
  431,                                 /* lineNo */
  1,                                   /* colNo */
  "increaseSampling",                  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtBCInfo nf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  425,                                 /* lineNo */
  39,                                  /* colNo */
  "segmentsToSplit",                   /* aName */
  "increaseSampling",                  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo of_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  429,                                 /* lineNo */
  40,                                  /* colNo */
  "dataPoints",                        /* aName */
  "increaseSampling",                  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  430,                                 /* lineNo */
  14,                                  /* colNo */
  "dataPoints",                        /* aName */
  "increaseSampling",                  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  376,                                 /* lineNo */
  22,                                  /* colNo */
  "x",                                 /* aName */
  "normalizeFunction",                 /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo k_emlrtECI = { -1,  /* nDims */
  376,                                 /* lineNo */
  5,                                   /* colNo */
  "normalizeFunction",                 /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtBCInfo rf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  23,                                  /* colNo */
  "belowVals",                         /* aName */
  "sldFunc",                           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/sldFunc.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  32,                                  /* lineNo */
  23,                                  /* colNo */
  "aboveVals",                         /* aName */
  "sldFunc",                           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/sldFunc.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  18,                                  /* colNo */
  "rho",                               /* aName */
  "sldFunc",                           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/sldFunc.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  18,                                  /* colNo */
  "rho",                               /* aName */
  "sldFunc",                           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/sldFunc.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  26,                                  /* colNo */
  "z",                                 /* aName */
  "sldFunc",                           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/sldFunc.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  20,                                  /* colNo */
  "z",                                 /* aName */
  "sldFunc",                           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/sldFunc.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  27,                                  /* lineNo */
  18,                                  /* colNo */
  "rho",                               /* aName */
  "sldFunc",                           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/sldFunc.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  376,                                 /* lineNo */
  5,                                   /* colNo */
  "y",                                 /* aName */
  "normalizeFunction",                 /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo l_emlrtECI = { 2,   /* nDims */
  398,                                 /* lineNo */
  3,                                   /* colNo */
  "calculateCentralAngles",            /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtECInfo m_emlrtECI = { -1,  /* nDims */
  403,                                 /* lineNo */
  21,                                  /* colNo */
  "calculateCentralAngles",            /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtECInfo n_emlrtECI = { -1,  /* nDims */
  404,                                 /* lineNo */
  21,                                  /* colNo */
  "calculateCentralAngles",            /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtECInfo o_emlrtECI = { -1,  /* nDims */
  405,                                 /* lineNo */
  21,                                  /* colNo */
  "calculateCentralAngles",            /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtECInfo p_emlrtECI = { -1,  /* nDims */
  407,                                 /* lineNo */
  4,                                   /* colNo */
  "calculateCentralAngles",            /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtECInfo q_emlrtECI = { -1,  /* nDims */
  408,                                 /* lineNo */
  8,                                   /* colNo */
  "calculateCentralAngles",            /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtBCInfo ag_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  386,                                 /* lineNo */
  20,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  386,                                 /* lineNo */
  22,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  386,                                 /* lineNo */
  40,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  386,                                 /* lineNo */
  42,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo r_emlrtECI = { 2,   /* nDims */
  386,                                 /* lineNo */
  13,                                  /* colNo */
  "calculateTrianglesSides",           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtBCInfo eg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  387,                                 /* lineNo */
  23,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  387,                                 /* lineNo */
  41,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  387,                                 /* lineNo */
  43,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo s_emlrtECI = { 2,   /* nDims */
  387,                                 /* lineNo */
  14,                                  /* colNo */
  "calculateTrianglesSides",           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtBCInfo hg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  388,                                 /* lineNo */
  22,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ig_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  388,                                 /* lineNo */
  40,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  388,                                 /* lineNo */
  42,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo t_emlrtECI = { 2,   /* nDims */
  388,                                 /* lineNo */
  13,                                  /* colNo */
  "calculateTrianglesSides",           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "/opt/matlab2020b/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

static emlrtBCInfo qx_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  11,                                  /* colNo */
  "SLD",                               /* aName */
  "sldFunc",                           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/sldFunc.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rx_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  13,                                  /* colNo */
  "SLD",                               /* aName */
  "sldFunc",                           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/sldFunc.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo vi_emlrtRTEI = { 241,/* lineNo */
  3,                                   /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo wi_emlrtRTEI = { 255,/* lineNo */
  1,                                   /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo xi_emlrtRTEI = { 281,/* lineNo */
  42,                                  /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo yi_emlrtRTEI = { 282,/* lineNo */
  5,                                   /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo aj_emlrtRTEI = { 283,/* lineNo */
  5,                                   /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo bj_emlrtRTEI = { 289,/* lineNo */
  21,                                  /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo cj_emlrtRTEI = { 289,/* lineNo */
  50,                                  /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo dj_emlrtRTEI = { 426,/* lineNo */
  1,                                   /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo ej_emlrtRTEI = { 429,/* lineNo */
  40,                                  /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo fj_emlrtRTEI = { 430,/* lineNo */
  14,                                  /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo gj_emlrtRTEI = { 305,/* lineNo */
  18,                                  /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo hj_emlrtRTEI = { 429,/* lineNo */
  22,                                  /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo ij_emlrtRTEI = { 431,/* lineNo */
  40,                                  /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo jj_emlrtRTEI = { 303,/* lineNo */
  14,                                  /* colNo */
  "cat",                               /* fName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo kj_emlrtRTEI = { 305,/* lineNo */
  5,                                   /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo lj_emlrtRTEI = { 252,/* lineNo */
  1,                                   /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo mj_emlrtRTEI = { 289,/* lineNo */
  3,                                   /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo nj_emlrtRTEI = { 241,/* lineNo */
  15,                                  /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo pj_emlrtRTEI = { 360,/* lineNo */
  5,                                   /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo qj_emlrtRTEI = { 24,/* lineNo */
  14,                                  /* colNo */
  "sldFunc",                           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/sldFunc.m"/* pName */
};

static emlrtRTEInfo rj_emlrtRTEI = { 24,/* lineNo */
  1,                                   /* colNo */
  "sldFunc",                           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/sldFunc.m"/* pName */
};

static emlrtRTEInfo sj_emlrtRTEI = { 376,/* lineNo */
  12,                                  /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo tj_emlrtRTEI = { 29,/* lineNo */
  22,                                  /* colNo */
  "sldFunc",                           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/sldFunc.m"/* pName */
};

static emlrtRTEInfo uj_emlrtRTEI = { 29,/* lineNo */
  5,                                   /* colNo */
  "sldFunc",                           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/sldFunc.m"/* pName */
};

static emlrtRTEInfo vj_emlrtRTEI = { 30,/* lineNo */
  22,                                  /* colNo */
  "sldFunc",                           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/sldFunc.m"/* pName */
};

static emlrtRTEInfo wj_emlrtRTEI = { 30,/* lineNo */
  5,                                   /* colNo */
  "sldFunc",                           /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/sldFunc.m"/* pName */
};

static emlrtRTEInfo bk_emlrtRTEI = { 398,/* lineNo */
  3,                                   /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo ck_emlrtRTEI = { 397,/* lineNo */
  1,                                   /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo dk_emlrtRTEI = { 386,/* lineNo */
  1,                                   /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo ek_emlrtRTEI = { 387,/* lineNo */
  1,                                   /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo fk_emlrtRTEI = { 388,/* lineNo */
  1,                                   /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo gk_emlrtRTEI = { 403,/* lineNo */
  21,                                  /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo hk_emlrtRTEI = { 403,/* lineNo */
  42,                                  /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo ik_emlrtRTEI = { 404,/* lineNo */
  21,                                  /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo jk_emlrtRTEI = { 404,/* lineNo */
  42,                                  /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo kk_emlrtRTEI = { 405,/* lineNo */
  21,                                  /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo lk_emlrtRTEI = { 405,/* lineNo */
  42,                                  /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo mk_emlrtRTEI = { 407,/* lineNo */
  3,                                   /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo nk_emlrtRTEI = { 409,/* lineNo */
  20,                                  /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo ok_emlrtRTEI = { 409,/* lineNo */
  1,                                   /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo pk_emlrtRTEI = { 403,/* lineNo */
  1,                                   /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo qk_emlrtRTEI = { 404,/* lineNo */
  1,                                   /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo rk_emlrtRTEI = { 405,/* lineNo */
  1,                                   /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

static emlrtRTEInfo sk_emlrtRTEI = { 391,/* lineNo */
  24,                                  /* colNo */
  "adaptive_new",                      /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/resampleLayers/adaptive_new.m"/* pName */
};

/* Function Declarations */
static void b_normalizeFunction(const emlrtStack *sp, const emxArray_real_T *x,
  const emxArray_real_T *sldProfile, emxArray_real_T *y);
static void calculateCentralAngles(const emlrtStack *sp, const emxArray_real_T
  *XYdata, const real_T dataBoxSize[2], emxArray_real_T *cornerAngle);
static void normalizeFunction(const emlrtStack *sp, const emxArray_real_T *x,
  const emxArray_real_T *sldProfile, emxArray_real_T *y);

/* Function Definitions */
static void b_normalizeFunction(const emlrtStack *sp, const emxArray_real_T *x,
  const emxArray_real_T *sldProfile, emxArray_real_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_boolean_T *b_sldProfile;
  emxArray_int32_T *ii;
  emxArray_int32_T *where;
  emxArray_real_T *aboveVals;
  real_T deltaY;
  real_T deltaY_tmp;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  Subfunctions */
  /*  NORMALIZEFUNCTION evaluates a function and returns a NxM array, where N */
  /*  is the number of elements of x and M is the number of outputs of func. */
  /*  All the outputs of func must be scalar. */
  /*  The optional parameter 'vectorizable' (default false) allows to specify */
  /*  that the input function can be vectorized. */
  /*  Modified by AVH for use with coder */
  /* if (~exist('vectorizable','var') || isempty(vectorizable)) */
  /*  end */
  /* abs(nargout(func)); %for anonymous functions nargout<0 */
  i = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity_real_T(sp, y, i, &pj_emlrtRTEI);

  /*  if vectorizable */
  /*    % For uniformity reasons, transform the 'x' array into a column vector. */
  /*    % In this way it does not matter if it is given as a column or a row */
  /*    % vector. */
  /*    [newValues{:}] = func(x(:)); */
  /*    y = cell2mat(newValues); */
  /*  else */
  i = x->size[0];
  emxInit_int32_T(sp, &where, 1, &rj_emlrtRTEI, true);
  emxInit_real_T(sp, &aboveVals, 1, &wj_emlrtRTEI, true);
  emxInit_int32_T(sp, &ii, 1, &xj_emlrtRTEI, true);
  emxInit_boolean_T(sp, &b_sldProfile, 1, &qj_emlrtRTEI, true);
  for (b_i = 0; b_i < i; b_i++) {
    /*  Remove cell array so no need for cell2mat */
    /*  which won't compile - AVH */
    /* [newValues{:}] = func(x(i)); */
    /* y(i,:) = cell2mat(newValues); */
    st.site = &td_emlrtRSI;
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > x->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, x->size[0], &qf_emlrtBCI, &st);
    }

    /*  sldVal = sldFunc(x,SLD) */
    /*  SLD = [x rho;....xn rho] */
    /*    x = value in Angstrom. */
    /*  */
    /*  This function returns the SLD (y) value associated with the */
    /*  supplied value of x. SLD is a two column, XY array defining an */
    /*  SLD profile. This function interpolates the SLD profile */
    /*  to return the SLD at the specific value of X. X can be a vector of */
    /*  multiple points. */
    /*  */
    /*  (c) Arwel Hughes 2019. */
    /*  Last modified - AVH, 26/11/19. */
    /*  global sldProfile */
    /*   */
    /*  SLD = sldProfile; */
    /* SLD = getappdata(0,'sldFuncSLD'); */
    if (1 > sldProfile->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, sldProfile->size[1], &qx_emlrtBCI, &st);
    }

    if (2 > sldProfile->size[1]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, sldProfile->size[1], &rx_emlrtBCI, &st);
    }

    b_st.site = &ud_emlrtRSI;
    loop_ub = sldProfile->size[0];
    i1 = b_sldProfile->size[0];
    b_sldProfile->size[0] = sldProfile->size[0];
    emxEnsureCapacity_boolean_T(&b_st, b_sldProfile, i1, &qj_emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_sldProfile->data[i1] = (sldProfile->data[i1] == x->data[b_i]);
    }

    c_st.site = &xd_emlrtRSI;
    eml_find(&c_st, b_sldProfile, ii);
    i1 = where->size[0];
    where->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(&b_st, where, i1, &rj_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      where->data[i1] = ii->data[i1];
    }

    if (where->size[0] != 0) {
      i1 = aboveVals->size[0];
      aboveVals->size[0] = where->size[0];
      emxEnsureCapacity_real_T(&st, aboveVals, i1, &sj_emlrtRTEI);
      loop_ub = where->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        if ((where->data[i1] < 1) || (where->data[i1] > sldProfile->size[0])) {
          emlrtDynamicBoundsCheckR2012b(where->data[i1], 1, sldProfile->size[0],
            &xf_emlrtBCI, &st);
        }

        aboveVals->data[i1] = sldProfile->data[(where->data[i1] +
          sldProfile->size[0]) - 1];
      }
    } else {
      b_st.site = &vd_emlrtRSI;
      loop_ub = sldProfile->size[0];
      i1 = b_sldProfile->size[0];
      b_sldProfile->size[0] = sldProfile->size[0];
      emxEnsureCapacity_boolean_T(&b_st, b_sldProfile, i1, &tj_emlrtRTEI);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_sldProfile->data[i1] = (x->data[b_i] > sldProfile->data[i1]);
      }

      c_st.site = &xd_emlrtRSI;
      eml_find(&c_st, b_sldProfile, ii);
      i1 = where->size[0];
      where->size[0] = ii->size[0];
      emxEnsureCapacity_int32_T(&b_st, where, i1, &uj_emlrtRTEI);
      loop_ub = ii->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        where->data[i1] = ii->data[i1];
      }

      b_st.site = &wd_emlrtRSI;
      loop_ub = sldProfile->size[0];
      i1 = b_sldProfile->size[0];
      b_sldProfile->size[0] = sldProfile->size[0];
      emxEnsureCapacity_boolean_T(&b_st, b_sldProfile, i1, &vj_emlrtRTEI);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_sldProfile->data[i1] = (x->data[b_i] < sldProfile->data[i1]);
      }

      c_st.site = &xd_emlrtRSI;
      eml_find(&c_st, b_sldProfile, ii);
      i1 = aboveVals->size[0];
      aboveVals->size[0] = ii->size[0];
      emxEnsureCapacity_real_T(&b_st, aboveVals, i1, &wj_emlrtRTEI);
      loop_ub = ii->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        aboveVals->data[i1] = ii->data[i1];
      }

      if (where->size[0] < 1) {
        emlrtDynamicBoundsCheckR2012b(where->size[0], 1, where->size[0],
          &rf_emlrtBCI, &st);
      }

      if (1 > aboveVals->size[0]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, aboveVals->size[0], &sf_emlrtBCI,
          &st);
      }

      i1 = where->data[where->size[0] - 1];
      if ((i1 < 1) || (i1 > sldProfile->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, sldProfile->size[0], &tf_emlrtBCI,
          &st);
      }

      if (((int32_T)aboveVals->data[0] < 1) || ((int32_T)aboveVals->data[0] >
           sldProfile->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)aboveVals->data[0], 1,
          sldProfile->size[0], &uf_emlrtBCI, &st);
      }

      i1 = where->data[where->size[0] - 1];
      if ((i1 < 1) || (i1 > sldProfile->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, sldProfile->size[0], &vf_emlrtBCI,
          &st);
      }

      i1 = where->data[where->size[0] - 1];
      if ((i1 < 1) || (i1 > sldProfile->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, sldProfile->size[0], &wf_emlrtBCI,
          &st);
      }

      deltaY_tmp = sldProfile->data[((int32_T)aboveVals->data[0] +
        sldProfile->size[0]) - 1];
      deltaY = (x->data[b_i] - sldProfile->data[where->data[where->size[0] - 1]
                - 1]) * (muDoubleScalarAbs(deltaY_tmp - sldProfile->data
        [(where->data[where->size[0] - 1] + sldProfile->size[0]) - 1]) /
                         (sldProfile->data[(int32_T)aboveVals->data[0] - 1] -
                          sldProfile->data[where->data[where->size[0] - 1] - 1]));
      if (sldProfile->data[(where->data[where->size[0] - 1] + sldProfile->size[0])
          - 1] < deltaY_tmp) {
        i1 = aboveVals->size[0];
        aboveVals->size[0] = 1;
        emxEnsureCapacity_real_T(&st, aboveVals, i1, &sj_emlrtRTEI);
        aboveVals->data[0] = sldProfile->data[(where->data[where->size[0] - 1] +
          sldProfile->size[0]) - 1] + deltaY;
      } else {
        i1 = aboveVals->size[0];
        aboveVals->size[0] = 1;
        emxEnsureCapacity_real_T(&st, aboveVals, i1, &sj_emlrtRTEI);
        aboveVals->data[0] = sldProfile->data[(where->data[where->size[0] - 1] +
          sldProfile->size[0]) - 1] - deltaY;
      }

      /* sldVal = interp1(z,rho,x); */
    }

    if (1 != aboveVals->size[0]) {
      emlrtSubAssignSizeCheck1dR2017a(1, aboveVals->size[0], &k_emlrtECI, sp);
    }

    if ((b_i + 1 < 1) || (b_i + 1 > y->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, y->size[0], &yf_emlrtBCI, sp);
    }

    y->data[b_i] = aboveVals->data[0];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_boolean_T(&b_sldProfile);
  emxFree_int32_T(&ii);
  emxFree_real_T(&aboveVals);
  emxFree_int32_T(&where);

  /* end */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void calculateCentralAngles(const emlrtStack *sp, const emxArray_real_T
  *XYdata, const real_T dataBoxSize[2], emxArray_real_T *cornerAngle)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  emxArray_creal_T *r1;
  emxArray_real_T *b_firstStep;
  emxArray_real_T *firstStep;
  emxArray_real_T *firstStepSquared;
  emxArray_real_T *longStep;
  emxArray_real_T *longStepSquared;
  emxArray_real_T *normalizedData;
  emxArray_real_T *r;
  emxArray_real_T *secondStep;
  emxArray_real_T *secondStepSquared;
  real_T minval[2];
  real_T b;
  int32_T iv[2];
  int32_T iv1[2];
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T k;
  int32_T m;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &normalizedData, 2, &ck_emlrtRTEI, true);

  /*  Calculate the central angle of the triangles formed by data points. */
  /*  For input size NxM, the output size is (N-2)xN, because the first and the */
  /*  last point are not the central corner of any triangle. */
  /*  Normalize data, because angles depend on scaling. */
  st.site = &je_emlrtRSI;
  b_st.site = &je_emlrtRSI;
  repmat(&b_st, dataBoxSize, XYdata->size[0], normalizedData);
  if (XYdata->size[0] != normalizedData->size[0]) {
    emlrtErrorWithMessageIdR2018a(&st, &pb_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  m = XYdata->size[0] * XYdata->size[1];
  i = normalizedData->size[0] * normalizedData->size[1];
  normalizedData->size[0] = XYdata->size[0];
  normalizedData->size[1] = 2;
  emxEnsureCapacity_real_T(&st, normalizedData, i, &bk_emlrtRTEI);
  for (i = 0; i < m; i++) {
    normalizedData->data[i] = XYdata->data[i] / normalizedData->data[i];
  }

  st.site = &ke_emlrtRSI;
  b_st.site = &ge_emlrtRSI;
  c_st.site = &he_emlrtRSI;
  d_st.site = &ie_emlrtRSI;
  if (XYdata->size[0] == 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &lb_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility",
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (XYdata->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &mb_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &ce_emlrtRSI;
  f_st.site = &de_emlrtRSI;
  g_st.site = &ee_emlrtRSI;
  m = XYdata->size[0];
  overflow = ((2 <= XYdata->size[0]) && (XYdata->size[0] > 2147483646));
  minval[0] = XYdata->data[0];
  h_st.site = &fe_emlrtRSI;
  if (overflow) {
    i_st.site = &j_emlrtRSI;
    check_forloop_overflow_error(&i_st);
  }

  for (b_i = 2; b_i <= m; b_i++) {
    b = XYdata->data[b_i - 1];
    overflow = ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN(minval[0]) ||
      (minval[0] > b)));
    if (overflow) {
      minval[0] = b;
    }
  }

  minval[1] = XYdata->data[XYdata->size[0]];
  h_st.site = &fe_emlrtRSI;
  for (b_i = 2; b_i <= m; b_i++) {
    b = XYdata->data[(b_i + XYdata->size[0]) - 1];
    overflow = ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN(minval[1]) ||
      (minval[1] > b)));
    if (overflow) {
      minval[1] = b;
    }
  }

  emxInit_real_T(&g_st, &longStep, 2, &sk_emlrtRTEI, true);
  st.site = &ke_emlrtRSI;
  repmat(&st, minval, XYdata->size[0], longStep);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])normalizedData->size, *(int32_T (*)
    [2])longStep->size, &l_emlrtECI, sp);
  m = normalizedData->size[0] * normalizedData->size[1];
  i = normalizedData->size[0] * normalizedData->size[1];
  normalizedData->size[1] = 2;
  emxEnsureCapacity_real_T(sp, normalizedData, i, &ck_emlrtRTEI);
  for (i = 0; i < m; i++) {
    normalizedData->data[i] -= longStep->data[i];
  }

  /*  calculate cosine of central angles */
  st.site = &le_emlrtRSI;

  /*  Return the sides (deltaX, deltaY) of the triangles formed by data points. */
  /*  For input size NxM, the output size is (N-2)xN, because the first and the */
  /*  last point are not the central corner of any triangle. */
  if (2 > normalizedData->size[0] - 1) {
    i = -1;
    i1 = -1;
  } else {
    if (2 > normalizedData->size[0]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, normalizedData->size[0], &ag_emlrtBCI,
        &st);
    }

    i = 0;
    if ((normalizedData->size[0] - 1 < 1) || (normalizedData->size[0] - 1 >
         normalizedData->size[0])) {
      emlrtDynamicBoundsCheckR2012b(normalizedData->size[0] - 1, 1,
        normalizedData->size[0], &bg_emlrtBCI, &st);
    }

    i1 = normalizedData->size[0] - 2;
  }

  if (1 > normalizedData->size[0] - 2) {
    b_i = 0;
  } else {
    if (1 > normalizedData->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, normalizedData->size[0], &cg_emlrtBCI,
        &st);
    }

    if ((normalizedData->size[0] - 2 < 1) || (normalizedData->size[0] - 2 >
         normalizedData->size[0])) {
      emlrtDynamicBoundsCheckR2012b(normalizedData->size[0] - 2, 1,
        normalizedData->size[0], &dg_emlrtBCI, &st);
    }

    b_i = normalizedData->size[0] - 2;
  }

  m = i1 - i;
  iv[0] = m;
  iv[1] = 2;
  iv1[0] = b_i;
  iv1[1] = 2;
  if (m != b_i) {
    emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &r_emlrtECI, &st);
  }

  emxInit_real_T(&st, &firstStep, 2, &sk_emlrtRTEI, true);
  i1 = firstStep->size[0] * firstStep->size[1];
  firstStep->size[0] = m;
  firstStep->size[1] = 2;
  emxEnsureCapacity_real_T(&st, firstStep, i1, &dk_emlrtRTEI);
  for (i1 = 0; i1 < m; i1++) {
    firstStep->data[i1] = normalizedData->data[(i + i1) + 1] -
      normalizedData->data[i1];
  }

  for (i1 = 0; i1 < m; i1++) {
    firstStep->data[i1 + firstStep->size[0]] = normalizedData->data[((i + i1) +
      normalizedData->size[0]) + 1] - normalizedData->data[i1 +
      normalizedData->size[0]];
  }

  if (3 > normalizedData->size[0]) {
    i = -1;
    i1 = -1;
  } else {
    i = 1;
    if (normalizedData->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(normalizedData->size[0], 1,
        normalizedData->size[0], &eg_emlrtBCI, &st);
    }

    i1 = normalizedData->size[0] - 1;
  }

  if (2 > normalizedData->size[0] - 1) {
    b_i = -1;
    k = 0;
  } else {
    if (2 > normalizedData->size[0]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, normalizedData->size[0], &fg_emlrtBCI,
        &st);
    }

    b_i = 0;
    if ((normalizedData->size[0] - 1 < 1) || (normalizedData->size[0] - 1 >
         normalizedData->size[0])) {
      emlrtDynamicBoundsCheckR2012b(normalizedData->size[0] - 1, 1,
        normalizedData->size[0], &gg_emlrtBCI, &st);
    }

    k = normalizedData->size[0] - 1;
  }

  m = i1 - i;
  iv[0] = m;
  iv[1] = 2;
  iv1[0] = (k - b_i) - 1;
  iv1[1] = 2;
  if (m != iv1[0]) {
    emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &s_emlrtECI, &st);
  }

  emxInit_real_T(&st, &secondStep, 2, &sk_emlrtRTEI, true);
  i1 = secondStep->size[0] * secondStep->size[1];
  secondStep->size[0] = m;
  secondStep->size[1] = 2;
  emxEnsureCapacity_real_T(&st, secondStep, i1, &ek_emlrtRTEI);
  for (i1 = 0; i1 < m; i1++) {
    secondStep->data[i1] = normalizedData->data[(i + i1) + 1] -
      normalizedData->data[(b_i + i1) + 1];
  }

  for (i1 = 0; i1 < m; i1++) {
    secondStep->data[i1 + secondStep->size[0]] = normalizedData->data[((i + i1)
      + normalizedData->size[0]) + 1] - normalizedData->data[((b_i + i1) +
      normalizedData->size[0]) + 1];
  }

  if (3 > normalizedData->size[0]) {
    i = -1;
    i1 = -1;
  } else {
    i = 1;
    if (normalizedData->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(normalizedData->size[0], 1,
        normalizedData->size[0], &hg_emlrtBCI, &st);
    }

    i1 = normalizedData->size[0] - 1;
  }

  if (1 > normalizedData->size[0] - 2) {
    b_i = 0;
  } else {
    if (1 > normalizedData->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, normalizedData->size[0], &ig_emlrtBCI,
        &st);
    }

    if ((normalizedData->size[0] - 2 < 1) || (normalizedData->size[0] - 2 >
         normalizedData->size[0])) {
      emlrtDynamicBoundsCheckR2012b(normalizedData->size[0] - 2, 1,
        normalizedData->size[0], &jg_emlrtBCI, &st);
    }

    b_i = normalizedData->size[0] - 2;
  }

  m = i1 - i;
  iv[0] = m;
  iv[1] = 2;
  iv1[0] = b_i;
  iv1[1] = 2;
  if (m != b_i) {
    emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &t_emlrtECI, &st);
  }

  i1 = longStep->size[0] * longStep->size[1];
  longStep->size[0] = m;
  longStep->size[1] = 2;
  emxEnsureCapacity_real_T(&st, longStep, i1, &fk_emlrtRTEI);
  for (i1 = 0; i1 < m; i1++) {
    longStep->data[i1] = normalizedData->data[(i + i1) + 1] -
      normalizedData->data[i1];
  }

  for (i1 = 0; i1 < m; i1++) {
    longStep->data[i1 + longStep->size[0]] = normalizedData->data[((i + i1) +
      normalizedData->size[0]) + 1] - normalizedData->data[i1 +
      normalizedData->size[0]];
  }

  emxFree_real_T(&normalizedData);
  emxInit_real_T(&st, &b_firstStep, 1, &gk_emlrtRTEI, true);

  /*  calculate area of squares of length of triangle sides */
  m = firstStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = firstStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &gk_emlrtRTEI);
  for (i = 0; i < m; i++) {
    b_firstStep->data[i] = firstStep->data[i];
  }

  emxInit_real_T(sp, &firstStepSquared, 1, &pk_emlrtRTEI, true);
  st.site = &me_emlrtRSI;
  power(&st, b_firstStep, firstStepSquared);
  m = firstStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = firstStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &hk_emlrtRTEI);
  for (i = 0; i < m; i++) {
    b_firstStep->data[i] = firstStep->data[i + firstStep->size[0]];
  }

  emxFree_real_T(&firstStep);
  emxInit_real_T(sp, &r, 1, &sk_emlrtRTEI, true);
  st.site = &me_emlrtRSI;
  power(&st, b_firstStep, r);
  if (firstStepSquared->size[0] != r->size[0]) {
    emlrtSizeEqCheck1DR2012b(firstStepSquared->size[0], r->size[0], &m_emlrtECI,
      sp);
  }

  m = firstStepSquared->size[0];
  for (i = 0; i < m; i++) {
    firstStepSquared->data[i] += r->data[i];
  }

  m = secondStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = secondStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &ik_emlrtRTEI);
  for (i = 0; i < m; i++) {
    b_firstStep->data[i] = secondStep->data[i];
  }

  emxInit_real_T(sp, &secondStepSquared, 1, &qk_emlrtRTEI, true);
  st.site = &ne_emlrtRSI;
  power(&st, b_firstStep, secondStepSquared);
  m = secondStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = secondStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &jk_emlrtRTEI);
  for (i = 0; i < m; i++) {
    b_firstStep->data[i] = secondStep->data[i + secondStep->size[0]];
  }

  emxFree_real_T(&secondStep);
  st.site = &ne_emlrtRSI;
  power(&st, b_firstStep, r);
  if (secondStepSquared->size[0] != r->size[0]) {
    emlrtSizeEqCheck1DR2012b(secondStepSquared->size[0], r->size[0], &n_emlrtECI,
      sp);
  }

  m = secondStepSquared->size[0];
  for (i = 0; i < m; i++) {
    secondStepSquared->data[i] += r->data[i];
  }

  m = longStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = longStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &kk_emlrtRTEI);
  for (i = 0; i < m; i++) {
    b_firstStep->data[i] = longStep->data[i];
  }

  emxInit_real_T(sp, &longStepSquared, 1, &rk_emlrtRTEI, true);
  st.site = &oe_emlrtRSI;
  power(&st, b_firstStep, longStepSquared);
  m = longStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = longStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &lk_emlrtRTEI);
  for (i = 0; i < m; i++) {
    b_firstStep->data[i] = longStep->data[i + longStep->size[0]];
  }

  emxFree_real_T(&longStep);
  st.site = &oe_emlrtRSI;
  power(&st, b_firstStep, r);
  emxFree_real_T(&b_firstStep);
  if (longStepSquared->size[0] != r->size[0]) {
    emlrtSizeEqCheck1DR2012b(longStepSquared->size[0], r->size[0], &o_emlrtECI,
      sp);
  }

  m = longStepSquared->size[0];
  for (i = 0; i < m; i++) {
    longStepSquared->data[i] += r->data[i];
  }

  emxFree_real_T(&r);
  if (firstStepSquared->size[0] != secondStepSquared->size[0]) {
    emlrtSizeEqCheck1DR2012b(firstStepSquared->size[0], secondStepSquared->size
      [0], &p_emlrtECI, sp);
  }

  if (firstStepSquared->size[0] != longStepSquared->size[0]) {
    emlrtSizeEqCheck1DR2012b(firstStepSquared->size[0], longStepSquared->size[0],
      &p_emlrtECI, sp);
  }

  if (firstStepSquared->size[0] != secondStepSquared->size[0]) {
    emlrtSizeEqCheck1DR2012b(firstStepSquared->size[0], secondStepSquared->size
      [0], &q_emlrtECI, sp);
  }

  st.site = &qe_emlrtRSI;
  i = longStepSquared->size[0];
  longStepSquared->size[0] = firstStepSquared->size[0];
  emxEnsureCapacity_real_T(&st, longStepSquared, i, &mk_emlrtRTEI);
  m = firstStepSquared->size[0];
  for (i = 0; i < m; i++) {
    longStepSquared->data[i] = ((firstStepSquared->data[i] +
      secondStepSquared->data[i]) - longStepSquared->data[i]) / 2.0;
  }

  b_st.site = &pe_emlrtRSI;
  m = firstStepSquared->size[0];
  for (i = 0; i < m; i++) {
    firstStepSquared->data[i] *= secondStepSquared->data[i];
  }

  emxFree_real_T(&secondStepSquared);
  overflow = false;
  i = firstStepSquared->size[0];
  for (k = 0; k < i; k++) {
    if (overflow || (firstStepSquared->data[k] < 0.0)) {
      overflow = true;
    }
  }

  if (overflow) {
    emlrtErrorWithMessageIdR2018a(&b_st, &qb_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  c_st.site = &we_emlrtRSI;
  m = firstStepSquared->size[0];
  d_st.site = &xe_emlrtRSI;
  if ((1 <= firstStepSquared->size[0]) && (firstStepSquared->size[0] >
       2147483646)) {
    e_st.site = &j_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (k = 0; k < m; k++) {
    firstStepSquared->data[k] = muDoubleScalarSqrt(firstStepSquared->data[k]);
  }

  if (longStepSquared->size[0] != firstStepSquared->size[0]) {
    emlrtErrorWithMessageIdR2018a(&st, &pb_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  emxInit_creal_T(&st, &r1, 1, &nk_emlrtRTEI, true);
  i = r1->size[0];
  r1->size[0] = longStepSquared->size[0];
  emxEnsureCapacity_creal_T(sp, r1, i, &nk_emlrtRTEI);
  m = longStepSquared->size[0];
  for (i = 0; i < m; i++) {
    r1->data[i].re = longStepSquared->data[i] / firstStepSquared->data[i];
    r1->data[i].im = 0.0;
  }

  emxFree_real_T(&longStepSquared);
  emxFree_real_T(&firstStepSquared);
  st.site = &re_emlrtRSI;
  b_acos(&st, r1);
  i = cornerAngle->size[0];
  cornerAngle->size[0] = r1->size[0];
  emxEnsureCapacity_real_T(sp, cornerAngle, i, &ok_emlrtRTEI);
  m = r1->size[0];
  for (i = 0; i < m; i++) {
    cornerAngle->data[i] = r1->data[i].re;
  }

  emxFree_creal_T(&r1);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void normalizeFunction(const emlrtStack *sp, const emxArray_real_T *x,
  const emxArray_real_T *sldProfile, emxArray_real_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_boolean_T *b_sldProfile;
  emxArray_int32_T *ii;
  emxArray_int32_T *where;
  emxArray_real_T *aboveVals;
  real_T deltaY;
  real_T deltaY_tmp;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  Subfunctions */
  /*  NORMALIZEFUNCTION evaluates a function and returns a NxM array, where N */
  /*  is the number of elements of x and M is the number of outputs of func. */
  /*  All the outputs of func must be scalar. */
  /*  The optional parameter 'vectorizable' (default false) allows to specify */
  /*  that the input function can be vectorized. */
  /*  Modified by AVH for use with coder */
  /* if (~exist('vectorizable','var') || isempty(vectorizable)) */
  /*  end */
  /* abs(nargout(func)); %for anonymous functions nargout<0 */
  i = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity_real_T(sp, y, i, &pj_emlrtRTEI);

  /*  if vectorizable */
  /*    % For uniformity reasons, transform the 'x' array into a column vector. */
  /*    % In this way it does not matter if it is given as a column or a row */
  /*    % vector. */
  /*    [newValues{:}] = func(x(:)); */
  /*    y = cell2mat(newValues); */
  /*  else */
  i = x->size[0];
  emxInit_int32_T(sp, &where, 1, &rj_emlrtRTEI, true);
  emxInit_real_T(sp, &aboveVals, 1, &wj_emlrtRTEI, true);
  emxInit_int32_T(sp, &ii, 1, &xj_emlrtRTEI, true);
  emxInit_boolean_T(sp, &b_sldProfile, 1, &qj_emlrtRTEI, true);
  for (b_i = 0; b_i < i; b_i++) {
    /*  Remove cell array so no need for cell2mat */
    /*  which won't compile - AVH */
    /* [newValues{:}] = func(x(i)); */
    /* y(i,:) = cell2mat(newValues); */
    st.site = &td_emlrtRSI;
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > x->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, x->size[0], &qf_emlrtBCI, &st);
    }

    /*  sldVal = sldFunc(x,SLD) */
    /*  SLD = [x rho;....xn rho] */
    /*    x = value in Angstrom. */
    /*  */
    /*  This function returns the SLD (y) value associated with the */
    /*  supplied value of x. SLD is a two column, XY array defining an */
    /*  SLD profile. This function interpolates the SLD profile */
    /*  to return the SLD at the specific value of X. X can be a vector of */
    /*  multiple points. */
    /*  */
    /*  (c) Arwel Hughes 2019. */
    /*  Last modified - AVH, 26/11/19. */
    /*  global sldProfile */
    /*   */
    /*  SLD = sldProfile; */
    /* SLD = getappdata(0,'sldFuncSLD'); */
    b_st.site = &ud_emlrtRSI;
    loop_ub = sldProfile->size[0];
    i1 = b_sldProfile->size[0];
    b_sldProfile->size[0] = sldProfile->size[0];
    emxEnsureCapacity_boolean_T(&b_st, b_sldProfile, i1, &qj_emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_sldProfile->data[i1] = (sldProfile->data[i1] == x->data[b_i]);
    }

    c_st.site = &xd_emlrtRSI;
    eml_find(&c_st, b_sldProfile, ii);
    i1 = where->size[0];
    where->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(&b_st, where, i1, &rj_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      where->data[i1] = ii->data[i1];
    }

    if (where->size[0] != 0) {
      i1 = aboveVals->size[0];
      aboveVals->size[0] = where->size[0];
      emxEnsureCapacity_real_T(&st, aboveVals, i1, &sj_emlrtRTEI);
      loop_ub = where->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        if ((where->data[i1] < 1) || (where->data[i1] > sldProfile->size[0])) {
          emlrtDynamicBoundsCheckR2012b(where->data[i1], 1, sldProfile->size[0],
            &xf_emlrtBCI, &st);
        }

        aboveVals->data[i1] = sldProfile->data[(where->data[i1] +
          sldProfile->size[0]) - 1];
      }
    } else {
      b_st.site = &vd_emlrtRSI;
      loop_ub = sldProfile->size[0];
      i1 = b_sldProfile->size[0];
      b_sldProfile->size[0] = sldProfile->size[0];
      emxEnsureCapacity_boolean_T(&b_st, b_sldProfile, i1, &tj_emlrtRTEI);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_sldProfile->data[i1] = (x->data[b_i] > sldProfile->data[i1]);
      }

      c_st.site = &xd_emlrtRSI;
      eml_find(&c_st, b_sldProfile, ii);
      i1 = where->size[0];
      where->size[0] = ii->size[0];
      emxEnsureCapacity_int32_T(&b_st, where, i1, &uj_emlrtRTEI);
      loop_ub = ii->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        where->data[i1] = ii->data[i1];
      }

      b_st.site = &wd_emlrtRSI;
      loop_ub = sldProfile->size[0];
      i1 = b_sldProfile->size[0];
      b_sldProfile->size[0] = sldProfile->size[0];
      emxEnsureCapacity_boolean_T(&b_st, b_sldProfile, i1, &vj_emlrtRTEI);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_sldProfile->data[i1] = (x->data[b_i] < sldProfile->data[i1]);
      }

      c_st.site = &xd_emlrtRSI;
      eml_find(&c_st, b_sldProfile, ii);
      i1 = aboveVals->size[0];
      aboveVals->size[0] = ii->size[0];
      emxEnsureCapacity_real_T(&b_st, aboveVals, i1, &wj_emlrtRTEI);
      loop_ub = ii->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        aboveVals->data[i1] = ii->data[i1];
      }

      if (where->size[0] < 1) {
        emlrtDynamicBoundsCheckR2012b(where->size[0], 1, where->size[0],
          &rf_emlrtBCI, &st);
      }

      if (1 > aboveVals->size[0]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, aboveVals->size[0], &sf_emlrtBCI,
          &st);
      }

      i1 = where->data[where->size[0] - 1];
      if ((i1 < 1) || (i1 > sldProfile->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, sldProfile->size[0], &tf_emlrtBCI,
          &st);
      }

      if (((int32_T)aboveVals->data[0] < 1) || ((int32_T)aboveVals->data[0] >
           sldProfile->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)aboveVals->data[0], 1,
          sldProfile->size[0], &uf_emlrtBCI, &st);
      }

      i1 = where->data[where->size[0] - 1];
      if ((i1 < 1) || (i1 > sldProfile->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, sldProfile->size[0], &vf_emlrtBCI,
          &st);
      }

      i1 = where->data[where->size[0] - 1];
      if ((i1 < 1) || (i1 > sldProfile->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, sldProfile->size[0], &wf_emlrtBCI,
          &st);
      }

      deltaY_tmp = sldProfile->data[((int32_T)aboveVals->data[0] +
        sldProfile->size[0]) - 1];
      deltaY = (x->data[b_i] - sldProfile->data[where->data[where->size[0] - 1]
                - 1]) * (muDoubleScalarAbs(deltaY_tmp - sldProfile->data
        [(where->data[where->size[0] - 1] + sldProfile->size[0]) - 1]) /
                         (sldProfile->data[(int32_T)aboveVals->data[0] - 1] -
                          sldProfile->data[where->data[where->size[0] - 1] - 1]));
      if (sldProfile->data[(where->data[where->size[0] - 1] + sldProfile->size[0])
          - 1] < deltaY_tmp) {
        i1 = aboveVals->size[0];
        aboveVals->size[0] = 1;
        emxEnsureCapacity_real_T(&st, aboveVals, i1, &sj_emlrtRTEI);
        aboveVals->data[0] = sldProfile->data[(where->data[where->size[0] - 1] +
          sldProfile->size[0]) - 1] + deltaY;
      } else {
        i1 = aboveVals->size[0];
        aboveVals->size[0] = 1;
        emxEnsureCapacity_real_T(&st, aboveVals, i1, &sj_emlrtRTEI);
        aboveVals->data[0] = sldProfile->data[(where->data[where->size[0] - 1] +
          sldProfile->size[0]) - 1] - deltaY;
      }

      /* sldVal = interp1(z,rho,x); */
    }

    if (1 != aboveVals->size[0]) {
      emlrtSubAssignSizeCheck1dR2017a(1, aboveVals->size[0], &k_emlrtECI, sp);
    }

    if ((b_i + 1 < 1) || (b_i + 1 > y->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, y->size[0], &yf_emlrtBCI, sp);
    }

    y->data[b_i] = aboveVals->data[0];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_boolean_T(&b_sldProfile);
  emxFree_int32_T(&ii);
  emxFree_real_T(&aboveVals);
  emxFree_int32_T(&where);

  /* end */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void adaptive_new(const emlrtStack *sp, const emxArray_real_T *sldProfile, const
                  real_T startDomain[2], real_T minAngle, real_T nPoints,
                  cell_19 *out)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  emxArray_boolean_T *r1;
  emxArray_boolean_T *segmentsToSplit;
  emxArray_boolean_T *sharpCorners;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_int32_T *r4;
  emxArray_int32_T *r5;
  emxArray_real_T *b_out;
  emxArray_real_T *hiVal;
  emxArray_real_T *newDataPoints;
  emxArray_real_T *newDomain;
  emxArray_real_T *r;
  real_T maxval[2];
  real_T b;
  real_T minval_idx_0;
  real_T minval_idx_1;
  int32_T b_i;
  int32_T b_input_sizes_idx_0;
  int32_T i;
  int32_T input_sizes_idx_0;
  int32_T nRefinements;
  int32_T trueCount;
  boolean_T exitg1;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &newDomain, 1, &vi_emlrtRTEI, true);
  emxInit_real_T(sp, &r, 2, &nj_emlrtRTEI, true);

  /*  adaptive: evaluates a matlab function on a given range */
  /*  */
  /*  'adaptive.m' allows to sample a function using a reduced number of */
  /*  points. It works iteratively adding new points where needed. */
  /*  It is especially useful for functions which are computationally intensive */
  /*  (e.g. involve solving a differential equation). */
  /*  */
  /*  Usage: */
  /*  XY = adaptive(func, [xstart, xend]) */
  /*   evaluates 'func' in the range [xstart, xend]. Key-value arguments are */
  /*   used to control the function evaluation. If the function 'func' returns */
  /*   multiple output values, only the first one is used for the refinement */
  /*   process, but all of them are calculated and returned as additional */
  /*   columns in the output matrix. The output matrix XY contains the new */
  /*   domain points in the first column and the output values in the other */
  /*   columns. */
  /*  [x,yy] = adaptive(func, [xstart, xend]) */
  /*    as before but separately returns the array with the domain points and */
  /*    the array/matrix with the function output values. */
  /*  [x,yy] = adaptive(func, xarray, ...) */
  /*    as before but explicitly provide an initial array of domain points. */
  /*  */
  /*  Methods: */
  /*    'adaptive' provides three methods for refining the function evaluation: */
  /*    1) add more points near the sharp corners, which are found by */
  /*     considering the triangles formed by three successive points and */
  /*     measuring the central angle. */
  /*    2) measure the area of the same triangles and add more points when the */
  /*     area is bigger than a threshold. */
  /*    3) measure the length of the segments formed by pairs of successive */
  /*     and split the segments which are longer than a threshold. */
  /*    If no methods is explicitly specified, the 'angle' method is used. */
  /*  */
  /*  Input parameters */
  /*   - func: input function (function handle) */
  /*   - initialDomain: initial domain points (1D array) */
  /*  */
  /*  Optional key-value input parameters */
  /*   - 'nPoints': (default 20) */
  /*        initial number of domain points, only used if an initial domain */
  /*        array is not excplitely provided. */
  /*   - 'maxRefinements': (default 10) */
  /*        Specifies the maximum number of refinement steps. */
  /*   - 'minAngle': (default 0.8*pi) */
  /*        Refine near the  points which forms, together with their left and right */
  /*        neighbours, a triangle with central angle smaller than a given value. */
  /*   - 'maxArea': (default 5e-4) */
  /*        Refine near the points which forms, together with their left and right */
  /*        neighbours, a triangle with area larger than a threshold. The threshold */
  /*        in normalized to the area enclosing th graph: */
  /*        threshold==maxArea*(max(x)-min(x))*(max(f(x))-min(f(x))) */
  /*   - 'maxLength': (default Inf) */
  /*        Refine all the sements which are longer than a given threshold. The */
  /*        threshold is relative to the input and output ranges. Specifically, */
  /*        before applying the threshold, the data are normalized so that */
  /*        max(x)-min(x)==1 and max(f(x))-min(f(x))==1. */
  /*   - 'minLength': (default 0) */
  /*        Exclude from the refinement process the segments which are shorter */
  /*        than a given threshold. The threshold is relative to the input and */
  /*        output ranges. Specifically, before applying the threshold, the */
  /*        data are normalized so that max(x)-min(x)==1 and max(f(x))-min(f(x))==1. */
  /*   - 'minSignal': (default 0.2) */
  /*        Exclude from the refinement process the points where the function is */
  /*        below a threshold. The threshold is relative to the output range: In */
  /*        this example threshold == 0.01*(max(f(x))-min(f(x))). */
  /*   - 'vectorizable': (default false) */
  /*        Specifies whether the input function accepts arrays as input */
  /*        (e.g. f(x)==x.^2). */
  /*   - 'waitbar': (default false) */
  /*        Display a waitbar. */
  /*  */
  /*  Output parameters */
  /*   - a NxM array where N is the number of domain points and M is the number */
  /*     of output parameters of the input function. */
  /*  */
  /*  */
  /*  Examples: */
  /*  */
  /*    % Refine a function near sharp corners. The option 'minAngle' is useful */
  /*    % for having more points near the peaks of the function. */
  /*    f = @(x) exp(-x.^2/4).*sin(3*x); */
  /*    % for test-purpose also evaluate the function directly */
  /*    x2 = -10:0.01:10; */
  /*    y2 = f(x2); */
  /*    y = adaptive(f, [-5,5], 'minAngle',0.8*pi); */
  /*    figure(1); plot(x2,f(x2),'k--',y(:,1),y(:,2),'o-'); */
  /*    legend('high sampling','adaptive') */
  /*    title('y = adaptive(f, [xstart, xend], ''minAngle'',0.8*pi)') */
  /*    % as before but starting with an inital array of domain points */
  /*    x = -5:5; */
  /*    y = adaptive(f, x, 'minAngle',0.8*pi); */
  /*    figure(2); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-'); */
  /*    legend('initial sampling','high sampling','adaptive') */
  /*    title('y = adaptive(f, x, ''minAngle'',0.8*pi)') */
  /*  */
  /*    % Refine a function near sharp corners, but do not split segments which */
  /*    % are already shorter than 'minLength'. */
  /*    y = adaptive(f, x, 'minAngle',0.8*pi, 'minLength',0.05); */
  /*    figure(3); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-'); */
  /*    legend('initial sampling','high sampling','adaptive') */
  /*    title('y = adaptive(f, x, ''minAngle'',0.8*pi, ''minLength'',0.05)'); */
  /*  */
  /*    % Refine a function until the areas of the triangles formed by */
  /*    % triplets of successive points are smaller than 'maxArea'. */
  /*    y = adaptive(f, x, 'maxArea',1e-3); */
  /*    figure(4); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-'); */
  /*    legend('initial sampling','high sampling','adaptive') */
  /*    title('y = adaptive(f, x, ''maxArea'',1e-3)') */
  /*  */
  /*    % Refine a function until the segments formed by pairs of successive */
  /*    % points are shorter than 'maxLength'. */
  /*    y = adaptive(f, x, 'maxLength',0.1); */
  /*    figure(5); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-'); */
  /*    legend('initial sampling','high sampling','adaptive') */
  /*    title('y = adaptive(f, x, ''maxLength'',0.1)'); */
  /*  Copyright */
  /*  2017, Alberto Comin -  LMU Muenchen */
  /*  Version changes: */
  /*  */
  /*  24/01/2017: 1) new default: when no optional argument is given, use the */
  /*   'angle' method as default 2) it is now possible to provide just the */
  /*   start and the end of the function domain, instead of having to */
  /*   explicitly provide an initial array 3) a new key-word argument */
  /*   'nPoints' controls the number of initial domain points in the cases when */
  /*   the initial array is not explicitly provided. 4) it is now possible to */
  /*   return the domain points and the function values either as a single 2D */
  /*   array or as two separate arrays. */
  /*  25/01/2017: fixed defaults for the case when no method is specified */
  /*  Default settings */
  /* nPoints = 20; */
  /* minAngle = 0.8*pi; */
  /*  units normalized to data range */
  /*  units normalized to data range */
  /*  units normalized to data range */
  /*  units normalized to data range */
  /*  Test-mode */
  /*  The test mode is activated by calling 'adaptive.m' with no input. */
  /*  if nargin==0 */
  /*    initialDomain =  -10:10; */
  /*    input_func = @(x) 100*exp(-(x+5.2).^2) + 50*exp(-5*(x-0.5).^2)+ 20*exp(-10*(x-5.8).^2); */
  /*    thresholdingAngles = true; */
  /*    minAngle = 0.8*pi; */
  /*    thresholdingLength = true; */
  /*    minLength = 0.02; */
  /*    disp('Running adaptive.m in test mode'); */
  /*    fprintf('input function: %s\n',func2str(input_func)); */
  /*    disp('Plotting the function on a initial set of points'); */
  /*    testFigureHandle = figure(); */
  /*    plot(initialDomain, input_func(initialDomain),'bs-','LineWidth',1.5); */
  /*    grid on; xlabel('x'); ylabel('y'); title('adaptive.m example'); */
  /*  end */
  /*  Processing input arguments */
  /*  assert(isa(input_func,'function_handle'),'adaptiveFunctionEvaluation:ArgChk',... */
  /*    'the first argument must be a function handle'); */
  /*  assert(isnumeric(initialDomain) && isvector(initialDomain),... */
  /*    'adaptiveFunctionEvaluation:ArgChk','initial points must be specified as a numeric vector'); */
  /*   */
  /* nExtraArgIn = numel(varargin); */
  /*  if mod(nExtraArgIn,2)==1 */
  /*    error('adaptiveFunctionEvaluation:ArgChk', ... */
  /*      'At least a key or a value is missing in the key-value arguments list.'); */
  /*  end */
  /* usingDefaultMethod = true; */
  /* n = 1; */
  /* minAngle = 0.7 * pi; */
  /* thresholdingAngles = true; */
  /* nPoints = 50; */
  /*  while n < nExtraArgIn */
  /*    switch lower(varargin{n})   */
  /*      case 'minangle' */
  /* minAngle = varargin{n+1}; */
  /* n = n+2; */
  /*      case 'maxarea' */
  /*        maxArea = varargin{n+1}; */
  /*        thresholdingArea = true; */
  /*        usingDefaultMethod = false; */
  /*        n = n+2; */
  /*      case 'maxlength' */
  /*        maxLength = varargin{n+1}; */
  /*        thresholdingLength = true; */
  /*        usingDefaultMethod = false; */
  /*        n = n+2; */
  /*      case 'minlength' */
  /*        minLength = varargin{n+1}; */
  /*        thresholdingLength = true; */
  /*        n = n+2; */
  /*      case 'minsignal' */
  /*        minSignal = varargin{n+1}; */
  /*        thresholdingSignal = true; */
  /*        n = n+2; */
  /*      case 'npoints' */
  /*        nPoints = varargin{n+1}; */
  /*        n = n+2; */
  /*      case 'vectorize' */
  /*        vectorizable = varargin{n+1}; */
  /*        n = n+2; */
  /*      case 'maxrefinements' */
  /*        maxRefinements = varargin{n+1}; */
  /*        n = n+2; */
  /*      case 'waitbar' */
  /*        displayWaitbar = varargin{n+1}; */
  /*        n = n+2; */
  /*      otherwise */
  /*        error('adaptiveFunctionEvaluation:ArgChk',... */
  /*          ['unknown keyword argument: ', varargin{n}]); */
  /*    end */
  /*  end */
  /*  if no method is specified use the 'angle' method as default */
  /*  if usingDefaultMethod */
  /*    thresholdingAngles = true; */
  /*  end */
  /*  Initial function evaluation */
  /*  if initialDomain only contains the start and the end points, create a new */
  /*  array with 'nPoints' points. */
  st.site = &kd_emlrtRSI;
  linspace(&st, startDomain[0], startDomain[1], nPoints, r);
  i = newDomain->size[0];
  newDomain->size[0] = r->size[1];
  emxEnsureCapacity_real_T(sp, newDomain, i, &vi_emlrtRTEI);
  input_sizes_idx_0 = r->size[1];
  for (i = 0; i < input_sizes_idx_0; i++) {
    newDomain->data[i] = r->data[i];
  }

  emxFree_real_T(&r);
  emxInit_real_T(sp, &hiVal, 1, &lj_emlrtRTEI, true);

  /*  Normalize the input function: This step allows to use the same syntax for */
  /*  functions with single or multiple output parameters. */
  /*  Remove this syntax for compile - AVH */
  /* func = @(x) normalizeFunction(x,sldProfile,vectorizable); */
  /*  Evaluate the input function on the initial set of points. */
  st.site = &ld_emlrtRSI;
  normalizeFunction(&st, newDomain, sldProfile, hiVal);

  /* dataPoints = [initialDomain(:), func(initialDomain(:))]; */
  st.site = &md_emlrtRSI;
  b_st.site = &nb_emlrtRSI;
  c_st.site = &ob_emlrtRSI;
  if (hiVal->size[0] != newDomain->size[0]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &hb_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  i = out->f1->size[0] * out->f1->size[1];
  out->f1->size[0] = newDomain->size[0];
  out->f1->size[1] = 2;
  emxEnsureCapacity_real_T(&b_st, out->f1, i, &wi_emlrtRTEI);
  input_sizes_idx_0 = newDomain->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    out->f1->data[i] = newDomain->data[i];
  }

  input_sizes_idx_0 = hiVal->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    out->f1->data[i + out->f1->size[0]] = hiVal->data[i];
  }

  /*  Iterative function refinement */
  /*  if displayWaitbar */
  /*    refinementWaitbar = waitbar(0,['Evaluating function ',func2str(func)],... */
  /*      'CreateCancelBtn','setappdata(gcbf,''canceling'',true)'); */
  /*    setappdata(refinementWaitbar,'canceling',false) */
  /*  end */
  nRefinements = 0;
  emxInit_boolean_T(sp, &sharpCorners, 1, &yi_emlrtRTEI, true);
  emxInit_boolean_T(sp, &segmentsToSplit, 1, &mj_emlrtRTEI, true);
  emxInit_boolean_T(sp, &r1, 1, &ej_emlrtRTEI, true);
  emxInit_real_T(sp, &newDataPoints, 2, &dj_emlrtRTEI, true);
  emxInit_int32_T(sp, &r2, 1, &ej_emlrtRTEI, true);
  emxInit_int32_T(sp, &r3, 1, &fj_emlrtRTEI, true);
  emxInit_int32_T(sp, &r4, 1, &ej_emlrtRTEI, true);
  emxInit_int32_T(sp, &r5, 1, &fj_emlrtRTEI, true);
  emxInit_real_T(sp, &b_out, 2, &xi_emlrtRTEI, true);
  exitg1 = false;
  while ((!exitg1) && (nRefinements < 10)) {
    /*  calculate the box which encloses the current data points: */
    st.site = &nd_emlrtRSI;
    b_st.site = &dd_emlrtRSI;
    c_st.site = &ed_emlrtRSI;
    d_st.site = &fd_emlrtRSI;
    if (out->f1->size[0] == 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &lb_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility",
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (out->f1->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &mb_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero",
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    e_st.site = &ce_emlrtRSI;
    f_st.site = &de_emlrtRSI;
    g_st.site = &ee_emlrtRSI;
    i = out->f1->size[0];
    overflow = ((2 <= out->f1->size[0]) && (out->f1->size[0] > 2147483646));
    maxval[0] = out->f1->data[0];
    h_st.site = &fe_emlrtRSI;
    if (overflow) {
      i_st.site = &j_emlrtRSI;
      check_forloop_overflow_error(&i_st);
    }

    for (b_i = 2; b_i <= i; b_i++) {
      b = out->f1->data[b_i - 1];
      overflow = ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN(maxval[0]) ||
        (maxval[0] < b)));
      if (overflow) {
        maxval[0] = b;
      }
    }

    maxval[1] = out->f1->data[out->f1->size[0]];
    h_st.site = &fe_emlrtRSI;
    for (b_i = 2; b_i <= i; b_i++) {
      b = out->f1->data[(b_i + out->f1->size[0]) - 1];
      overflow = ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN(maxval[1]) ||
        (maxval[1] < b)));
      if (overflow) {
        maxval[1] = b;
      }
    }

    st.site = &nd_emlrtRSI;
    b_st.site = &ge_emlrtRSI;
    c_st.site = &he_emlrtRSI;
    d_st.site = &ie_emlrtRSI;
    if (out->f1->size[0] == 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &lb_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility",
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (out->f1->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &mb_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero",
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    e_st.site = &ce_emlrtRSI;
    f_st.site = &de_emlrtRSI;
    g_st.site = &ee_emlrtRSI;
    i = out->f1->size[0];
    overflow = ((2 <= out->f1->size[0]) && (out->f1->size[0] > 2147483646));
    minval_idx_0 = out->f1->data[0];
    h_st.site = &fe_emlrtRSI;
    if (overflow) {
      i_st.site = &j_emlrtRSI;
      check_forloop_overflow_error(&i_st);
    }

    for (b_i = 2; b_i <= i; b_i++) {
      b = out->f1->data[b_i - 1];
      overflow = ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN(minval_idx_0)
        || (minval_idx_0 > b)));
      if (overflow) {
        minval_idx_0 = b;
      }
    }

    minval_idx_1 = out->f1->data[out->f1->size[0]];
    h_st.site = &fe_emlrtRSI;
    for (b_i = 2; b_i <= i; b_i++) {
      b = out->f1->data[(b_i + out->f1->size[0]) - 1];
      overflow = ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN(minval_idx_1)
        || (minval_idx_1 > b)));
      if (overflow) {
        minval_idx_1 = b;
      }
    }

    /*  Each point is considered as the central corner of the triangle formed */
    /*  with its left and right hand side neighbours. The first and the last */
    /*  points are not the central corner of any triangle, so for N points */
    /*  there are only N-2 triangles. */
    if (!((real_T)out->f1->size[0] - 2.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b((real_T)out->f1->size[0] - 2.0, &kb_emlrtDCI,
        sp);
    }

    /*    if thresholdingArea */
    /*      triangleArea = calculateTrianglesArea(dataPoints(:,1:2)); */
    /*      bigTriangles = triangleArea > (maxArea * dataBoxArea); */
    /*      trianglesToRefine = trianglesToRefine | bigTriangles; */
    /*    end */
    input_sizes_idx_0 = out->f1->size[0];
    i = b_out->size[0] * b_out->size[1];
    b_out->size[0] = out->f1->size[0];
    b_out->size[1] = 2;
    emxEnsureCapacity_real_T(sp, b_out, i, &xi_emlrtRTEI);
    for (i = 0; i < input_sizes_idx_0; i++) {
      b_out->data[i] = out->f1->data[i];
    }

    maxval[0] -= minval_idx_0;
    for (i = 0; i < input_sizes_idx_0; i++) {
      b_out->data[i + b_out->size[0]] = out->f1->data[i + out->f1->size[0]];
    }

    maxval[1] -= minval_idx_1;
    st.site = &od_emlrtRSI;
    calculateCentralAngles(&st, b_out, maxval, newDomain);
    i = sharpCorners->size[0];
    sharpCorners->size[0] = newDomain->size[0];
    emxEnsureCapacity_boolean_T(sp, sharpCorners, i, &yi_emlrtRTEI);
    input_sizes_idx_0 = newDomain->size[0];
    for (i = 0; i < input_sizes_idx_0; i++) {
      sharpCorners->data[i] = (newDomain->data[i] < minAngle);
    }

    if (out->f1->size[0] - 2 != sharpCorners->size[0]) {
      emlrtSizeEqCheck1DR2012b(out->f1->size[0] - 2, sharpCorners->size[0],
        &f_emlrtECI, sp);
    }

    i = sharpCorners->size[0];
    sharpCorners->size[0] = out->f1->size[0] - 2;
    emxEnsureCapacity_boolean_T(sp, sharpCorners, i, &aj_emlrtRTEI);

    /*  For N points there are N-2 triangles and N-1 triangle sides. Each */
    /*  triangle side is a segment, which can be split or not depending on the */
    /*  refinement parameters. */
    i = segmentsToSplit->size[0];
    segmentsToSplit->size[0] = out->f1->size[0] - 1;
    emxEnsureCapacity_boolean_T(sp, segmentsToSplit, i, &bj_emlrtRTEI);
    input_sizes_idx_0 = out->f1->size[0] - 2;
    for (i = 0; i < input_sizes_idx_0; i++) {
      segmentsToSplit->data[i] = sharpCorners->data[i];
    }

    segmentsToSplit->data[out->f1->size[0] - 2] = false;
    i = r1->size[0];
    r1->size[0] = out->f1->size[0] - 1;
    emxEnsureCapacity_boolean_T(sp, r1, i, &cj_emlrtRTEI);
    r1->data[0] = false;
    input_sizes_idx_0 = out->f1->size[0] - 2;
    for (i = 0; i < input_sizes_idx_0; i++) {
      r1->data[i + 1] = sharpCorners->data[i];
    }

    if (segmentsToSplit->size[0] != r1->size[0]) {
      emlrtSizeEqCheck1DR2012b(segmentsToSplit->size[0], r1->size[0],
        &g_emlrtECI, sp);
    }

    input_sizes_idx_0 = segmentsToSplit->size[0];
    for (i = 0; i < input_sizes_idx_0; i++) {
      segmentsToSplit->data[i] = (segmentsToSplit->data[i] || r1->data[i]);
    }

    /*    if thresholdingLength */
    /*      dataSegments = diff(dataPoints(:,1:2)); */
    /*      normalizedSegments = bsxfun(@rdivide, dataSegments, dataBoxSize); */
    /*      segmentsLengthNormalized = hypot(normalizedSegments(:,1), normalizedSegments(:,2)); */
    /*      tooLongSegments = segmentsLengthNormalized > maxLength; */
    /*      longEnoughSegments = segmentsLengthNormalized > minLength; */
    /*      segmentsToSplit = (segmentsToSplit | tooLongSegments) & longEnoughSegments; */
    /*    end */
    /*    if thresholdingSignal */
    /*      segmentsCenters = (dataPoints(1:end-1,2)+dataPoints(2:end,2))/2; */
    /*      centerAboveThreshold = segmentsCenters > minSignal * max(abs(dataPoints(:,2))); */
    /*      segmentsToSplit = segmentsToSplit & centerAboveThreshold; */
    /*    end */
    st.site = &pd_emlrtRSI;
    if (any(segmentsToSplit)) {
      st.site = &qd_emlrtRSI;

      /*  increaseSampling increase the sampling of an input function */
      b_input_sizes_idx_0 = segmentsToSplit->size[0];
      for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
        if (segmentsToSplit->data[b_i] && ((b_i + 1 < 1) || (b_i + 1 >
              segmentsToSplit->size[0]))) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, segmentsToSplit->size[0],
            &nf_emlrtBCI, &st);
        }
      }

      b_input_sizes_idx_0 = segmentsToSplit->size[0];
      trueCount = 0;
      for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
        if (segmentsToSplit->data[b_i]) {
          trueCount++;
        }
      }

      i = newDataPoints->size[0] * newDataPoints->size[1];
      newDataPoints->size[0] = trueCount;
      newDataPoints->size[1] = 2;
      emxEnsureCapacity_real_T(&st, newDataPoints, i, &dj_emlrtRTEI);
      input_sizes_idx_0 = trueCount << 1;
      for (i = 0; i < input_sizes_idx_0; i++) {
        newDataPoints->data[i] = 0.0;
      }

      i = r1->size[0];
      r1->size[0] = segmentsToSplit->size[0] + 1;
      emxEnsureCapacity_boolean_T(&st, r1, i, &ej_emlrtRTEI);
      input_sizes_idx_0 = segmentsToSplit->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        r1->data[i] = segmentsToSplit->data[i];
      }

      r1->data[segmentsToSplit->size[0]] = false;
      b_input_sizes_idx_0 = r1->size[0];
      for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
        if (r1->data[b_i] && ((b_i + 1 < 1) || (b_i + 1 > out->f1->size[0]))) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, out->f1->size[0],
            &of_emlrtBCI, &st);
        }
      }

      i = sharpCorners->size[0];
      sharpCorners->size[0] = segmentsToSplit->size[0] + 1;
      emxEnsureCapacity_boolean_T(&st, sharpCorners, i, &fj_emlrtRTEI);
      sharpCorners->data[0] = false;
      input_sizes_idx_0 = segmentsToSplit->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        sharpCorners->data[i + 1] = segmentsToSplit->data[i];
      }

      b_input_sizes_idx_0 = sharpCorners->size[0];
      for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
        if (sharpCorners->data[b_i] && ((b_i + 1 < 1) || (b_i + 1 > out->
              f1->size[0]))) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, out->f1->size[0],
            &pf_emlrtBCI, &st);
        }
      }

      b_input_sizes_idx_0 = r1->size[0] - 1;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (r1->data[b_i]) {
          input_sizes_idx_0++;
        }
      }

      i = r2->size[0];
      r2->size[0] = input_sizes_idx_0;
      emxEnsureCapacity_int32_T(&st, r2, i, &gj_emlrtRTEI);
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (r1->data[b_i]) {
          r2->data[input_sizes_idx_0] = b_i + 1;
          input_sizes_idx_0++;
        }
      }

      b_input_sizes_idx_0 = sharpCorners->size[0] - 1;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (sharpCorners->data[b_i]) {
          input_sizes_idx_0++;
        }
      }

      i = r3->size[0];
      r3->size[0] = input_sizes_idx_0;
      emxEnsureCapacity_int32_T(&st, r3, i, &gj_emlrtRTEI);
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (sharpCorners->data[b_i]) {
          r3->data[input_sizes_idx_0] = b_i + 1;
          input_sizes_idx_0++;
        }
      }

      if (r2->size[0] != r3->size[0]) {
        emlrtSizeEqCheck1DR2012b(r2->size[0], r3->size[0], &h_emlrtECI, &st);
      }

      b_input_sizes_idx_0 = r1->size[0] - 1;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (r1->data[b_i]) {
          input_sizes_idx_0++;
        }
      }

      i = r4->size[0];
      r4->size[0] = input_sizes_idx_0;
      emxEnsureCapacity_int32_T(&st, r4, i, &gj_emlrtRTEI);
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (r1->data[b_i]) {
          r4->data[input_sizes_idx_0] = b_i + 1;
          input_sizes_idx_0++;
        }
      }

      b_input_sizes_idx_0 = sharpCorners->size[0] - 1;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (sharpCorners->data[b_i]) {
          input_sizes_idx_0++;
        }
      }

      i = r5->size[0];
      r5->size[0] = input_sizes_idx_0;
      emxEnsureCapacity_int32_T(&st, r5, i, &gj_emlrtRTEI);
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (sharpCorners->data[b_i]) {
          r5->data[input_sizes_idx_0] = b_i + 1;
          input_sizes_idx_0++;
        }
      }

      i = newDomain->size[0];
      newDomain->size[0] = r4->size[0];
      emxEnsureCapacity_real_T(&st, newDomain, i, &hj_emlrtRTEI);
      input_sizes_idx_0 = r4->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        newDomain->data[i] = 0.5 * (out->f1->data[r4->data[i] - 1] + out->
          f1->data[r5->data[i] - 1]);
      }

      emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &newDomain->size[0], 1,
        &i_emlrtECI, &st);
      input_sizes_idx_0 = newDomain->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        newDataPoints->data[i] = newDomain->data[i];
      }

      input_sizes_idx_0 = newDataPoints->size[0];
      i = hiVal->size[0];
      hiVal->size[0] = newDataPoints->size[0];
      emxEnsureCapacity_real_T(&st, hiVal, i, &ij_emlrtRTEI);
      for (i = 0; i < input_sizes_idx_0; i++) {
        hiVal->data[i] = newDataPoints->data[i];
      }

      b_st.site = &bf_emlrtRSI;
      normalizeFunction(&b_st, hiVal, sldProfile, newDomain);
      emlrtSubAssignSizeCheckR2012b(&newDataPoints->size[0], 1, &newDomain->
        size[0], 1, &j_emlrtECI, &st);
      input_sizes_idx_0 = newDomain->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        newDataPoints->data[i + newDataPoints->size[0]] = newDomain->data[i];
      }

      /*  For simplicity append the new points at the end and then sort. */
      b_st.site = &cf_emlrtRSI;
      c_st.site = &df_emlrtRSI;
      d_st.site = &ob_emlrtRSI;
      if (out->f1->size[0] != 0) {
        input_sizes_idx_0 = out->f1->size[0];
      } else {
        input_sizes_idx_0 = 0;
      }

      if (newDataPoints->size[0] != 0) {
        b_input_sizes_idx_0 = newDataPoints->size[0];
      } else {
        b_input_sizes_idx_0 = 0;
      }

      if (out->f1->size[0] != 0) {
        trueCount = out->f1->size[0];
      } else {
        trueCount = 0;
      }

      i = b_out->size[0] * b_out->size[1];
      b_out->size[0] = input_sizes_idx_0 + b_input_sizes_idx_0;
      b_out->size[1] = 2;
      emxEnsureCapacity_real_T(&st, b_out, i, &jj_emlrtRTEI);
      for (i = 0; i < input_sizes_idx_0; i++) {
        b_out->data[i] = out->f1->data[i];
      }

      for (i = 0; i < input_sizes_idx_0; i++) {
        b_out->data[i + b_out->size[0]] = out->f1->data[i + out->f1->size[0]];
      }

      for (i = 0; i < b_input_sizes_idx_0; i++) {
        b_out->data[i + trueCount] = newDataPoints->data[i];
      }

      for (i = 0; i < b_input_sizes_idx_0; i++) {
        b_out->data[(i + trueCount) + b_out->size[0]] = newDataPoints->data[i +
          newDataPoints->size[0]];
      }

      i = out->f1->size[0] * out->f1->size[1];
      out->f1->size[0] = b_out->size[0];
      out->f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, out->f1, i, &kj_emlrtRTEI);
      input_sizes_idx_0 = b_out->size[0] * b_out->size[1];
      for (i = 0; i < input_sizes_idx_0; i++) {
        out->f1->data[i] = b_out->data[i];
      }

      b_st.site = &cf_emlrtRSI;
      sortrows(&b_st, out->f1);

      /*  Removed waitbar for compile - AVH */
      /*    if displayWaitbar */
      /*      if getappdata(refinementWaitbar,'canceling'), break; end */
      /*      waitbar(nRefinements/maxRefinements,refinementWaitbar); */
      /*    end */
      nRefinements++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    } else {
      exitg1 = true;
    }
  }

  emxFree_real_T(&b_out);
  emxFree_int32_T(&r5);
  emxFree_int32_T(&r4);
  emxFree_int32_T(&r3);
  emxFree_int32_T(&r2);
  emxFree_real_T(&newDataPoints);
  emxFree_boolean_T(&r1);
  emxFree_boolean_T(&segmentsToSplit);
  emxFree_boolean_T(&sharpCorners);
  emxFree_real_T(&hiVal);
  emxFree_real_T(&newDomain);

  /*  if displayWaitbar */
  /*    delete(refinementWaitbar); */
  /*  end */
  /*  Plotting refined function */
  /*  Removed for compile - AVH */
  /*  if nargin==0 % test mode */
  /*    figure(testFigureHandle); */
  /*    hold on; */
  /*    plot(dataPoints(:,1), dataPoints(:,2),'ro-'); */
  /*    legend('initial', 'refiniment'); */
  /*  end */
  /* if nargout==1 */
  /*  elseif nargout>1 */
  /*    out{1} = dataPoints(:,1); */
  /*    out{2} = dataPoints(:,2:end); */
  /*  end */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void b_adaptive_new(const emlrtStack *sp, const emxArray_real_T *sldProfile,
                    const real_T startDomain[2], real_T minAngle, real_T nPoints,
                    cell_19 *out)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  emxArray_boolean_T *r1;
  emxArray_boolean_T *segmentsToSplit;
  emxArray_boolean_T *sharpCorners;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_int32_T *r4;
  emxArray_int32_T *r5;
  emxArray_real_T *b_out;
  emxArray_real_T *hiVal;
  emxArray_real_T *newDataPoints;
  emxArray_real_T *newDomain;
  emxArray_real_T *r;
  real_T maxval[2];
  real_T b;
  real_T minval_idx_0;
  real_T minval_idx_1;
  int32_T b_i;
  int32_T b_input_sizes_idx_0;
  int32_T i;
  int32_T input_sizes_idx_0;
  int32_T nRefinements;
  int32_T trueCount;
  boolean_T exitg1;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &newDomain, 1, &vi_emlrtRTEI, true);
  emxInit_real_T(sp, &r, 2, &nj_emlrtRTEI, true);

  /*  adaptive: evaluates a matlab function on a given range */
  /*  */
  /*  'adaptive.m' allows to sample a function using a reduced number of */
  /*  points. It works iteratively adding new points where needed. */
  /*  It is especially useful for functions which are computationally intensive */
  /*  (e.g. involve solving a differential equation). */
  /*  */
  /*  Usage: */
  /*  XY = adaptive(func, [xstart, xend]) */
  /*   evaluates 'func' in the range [xstart, xend]. Key-value arguments are */
  /*   used to control the function evaluation. If the function 'func' returns */
  /*   multiple output values, only the first one is used for the refinement */
  /*   process, but all of them are calculated and returned as additional */
  /*   columns in the output matrix. The output matrix XY contains the new */
  /*   domain points in the first column and the output values in the other */
  /*   columns. */
  /*  [x,yy] = adaptive(func, [xstart, xend]) */
  /*    as before but separately returns the array with the domain points and */
  /*    the array/matrix with the function output values. */
  /*  [x,yy] = adaptive(func, xarray, ...) */
  /*    as before but explicitly provide an initial array of domain points. */
  /*  */
  /*  Methods: */
  /*    'adaptive' provides three methods for refining the function evaluation: */
  /*    1) add more points near the sharp corners, which are found by */
  /*     considering the triangles formed by three successive points and */
  /*     measuring the central angle. */
  /*    2) measure the area of the same triangles and add more points when the */
  /*     area is bigger than a threshold. */
  /*    3) measure the length of the segments formed by pairs of successive */
  /*     and split the segments which are longer than a threshold. */
  /*    If no methods is explicitly specified, the 'angle' method is used. */
  /*  */
  /*  Input parameters */
  /*   - func: input function (function handle) */
  /*   - initialDomain: initial domain points (1D array) */
  /*  */
  /*  Optional key-value input parameters */
  /*   - 'nPoints': (default 20) */
  /*        initial number of domain points, only used if an initial domain */
  /*        array is not excplitely provided. */
  /*   - 'maxRefinements': (default 10) */
  /*        Specifies the maximum number of refinement steps. */
  /*   - 'minAngle': (default 0.8*pi) */
  /*        Refine near the  points which forms, together with their left and right */
  /*        neighbours, a triangle with central angle smaller than a given value. */
  /*   - 'maxArea': (default 5e-4) */
  /*        Refine near the points which forms, together with their left and right */
  /*        neighbours, a triangle with area larger than a threshold. The threshold */
  /*        in normalized to the area enclosing th graph: */
  /*        threshold==maxArea*(max(x)-min(x))*(max(f(x))-min(f(x))) */
  /*   - 'maxLength': (default Inf) */
  /*        Refine all the sements which are longer than a given threshold. The */
  /*        threshold is relative to the input and output ranges. Specifically, */
  /*        before applying the threshold, the data are normalized so that */
  /*        max(x)-min(x)==1 and max(f(x))-min(f(x))==1. */
  /*   - 'minLength': (default 0) */
  /*        Exclude from the refinement process the segments which are shorter */
  /*        than a given threshold. The threshold is relative to the input and */
  /*        output ranges. Specifically, before applying the threshold, the */
  /*        data are normalized so that max(x)-min(x)==1 and max(f(x))-min(f(x))==1. */
  /*   - 'minSignal': (default 0.2) */
  /*        Exclude from the refinement process the points where the function is */
  /*        below a threshold. The threshold is relative to the output range: In */
  /*        this example threshold == 0.01*(max(f(x))-min(f(x))). */
  /*   - 'vectorizable': (default false) */
  /*        Specifies whether the input function accepts arrays as input */
  /*        (e.g. f(x)==x.^2). */
  /*   - 'waitbar': (default false) */
  /*        Display a waitbar. */
  /*  */
  /*  Output parameters */
  /*   - a NxM array where N is the number of domain points and M is the number */
  /*     of output parameters of the input function. */
  /*  */
  /*  */
  /*  Examples: */
  /*  */
  /*    % Refine a function near sharp corners. The option 'minAngle' is useful */
  /*    % for having more points near the peaks of the function. */
  /*    f = @(x) exp(-x.^2/4).*sin(3*x); */
  /*    % for test-purpose also evaluate the function directly */
  /*    x2 = -10:0.01:10; */
  /*    y2 = f(x2); */
  /*    y = adaptive(f, [-5,5], 'minAngle',0.8*pi); */
  /*    figure(1); plot(x2,f(x2),'k--',y(:,1),y(:,2),'o-'); */
  /*    legend('high sampling','adaptive') */
  /*    title('y = adaptive(f, [xstart, xend], ''minAngle'',0.8*pi)') */
  /*    % as before but starting with an inital array of domain points */
  /*    x = -5:5; */
  /*    y = adaptive(f, x, 'minAngle',0.8*pi); */
  /*    figure(2); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-'); */
  /*    legend('initial sampling','high sampling','adaptive') */
  /*    title('y = adaptive(f, x, ''minAngle'',0.8*pi)') */
  /*  */
  /*    % Refine a function near sharp corners, but do not split segments which */
  /*    % are already shorter than 'minLength'. */
  /*    y = adaptive(f, x, 'minAngle',0.8*pi, 'minLength',0.05); */
  /*    figure(3); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-'); */
  /*    legend('initial sampling','high sampling','adaptive') */
  /*    title('y = adaptive(f, x, ''minAngle'',0.8*pi, ''minLength'',0.05)'); */
  /*  */
  /*    % Refine a function until the areas of the triangles formed by */
  /*    % triplets of successive points are smaller than 'maxArea'. */
  /*    y = adaptive(f, x, 'maxArea',1e-3); */
  /*    figure(4); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-'); */
  /*    legend('initial sampling','high sampling','adaptive') */
  /*    title('y = adaptive(f, x, ''maxArea'',1e-3)') */
  /*  */
  /*    % Refine a function until the segments formed by pairs of successive */
  /*    % points are shorter than 'maxLength'. */
  /*    y = adaptive(f, x, 'maxLength',0.1); */
  /*    figure(5); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-'); */
  /*    legend('initial sampling','high sampling','adaptive') */
  /*    title('y = adaptive(f, x, ''maxLength'',0.1)'); */
  /*  Copyright */
  /*  2017, Alberto Comin -  LMU Muenchen */
  /*  Version changes: */
  /*  */
  /*  24/01/2017: 1) new default: when no optional argument is given, use the */
  /*   'angle' method as default 2) it is now possible to provide just the */
  /*   start and the end of the function domain, instead of having to */
  /*   explicitly provide an initial array 3) a new key-word argument */
  /*   'nPoints' controls the number of initial domain points in the cases when */
  /*   the initial array is not explicitly provided. 4) it is now possible to */
  /*   return the domain points and the function values either as a single 2D */
  /*   array or as two separate arrays. */
  /*  25/01/2017: fixed defaults for the case when no method is specified */
  /*  Default settings */
  /* nPoints = 20; */
  /* minAngle = 0.8*pi; */
  /*  units normalized to data range */
  /*  units normalized to data range */
  /*  units normalized to data range */
  /*  units normalized to data range */
  /*  Test-mode */
  /*  The test mode is activated by calling 'adaptive.m' with no input. */
  /*  if nargin==0 */
  /*    initialDomain =  -10:10; */
  /*    input_func = @(x) 100*exp(-(x+5.2).^2) + 50*exp(-5*(x-0.5).^2)+ 20*exp(-10*(x-5.8).^2); */
  /*    thresholdingAngles = true; */
  /*    minAngle = 0.8*pi; */
  /*    thresholdingLength = true; */
  /*    minLength = 0.02; */
  /*    disp('Running adaptive.m in test mode'); */
  /*    fprintf('input function: %s\n',func2str(input_func)); */
  /*    disp('Plotting the function on a initial set of points'); */
  /*    testFigureHandle = figure(); */
  /*    plot(initialDomain, input_func(initialDomain),'bs-','LineWidth',1.5); */
  /*    grid on; xlabel('x'); ylabel('y'); title('adaptive.m example'); */
  /*  end */
  /*  Processing input arguments */
  /*  assert(isa(input_func,'function_handle'),'adaptiveFunctionEvaluation:ArgChk',... */
  /*    'the first argument must be a function handle'); */
  /*  assert(isnumeric(initialDomain) && isvector(initialDomain),... */
  /*    'adaptiveFunctionEvaluation:ArgChk','initial points must be specified as a numeric vector'); */
  /*   */
  /* nExtraArgIn = numel(varargin); */
  /*  if mod(nExtraArgIn,2)==1 */
  /*    error('adaptiveFunctionEvaluation:ArgChk', ... */
  /*      'At least a key or a value is missing in the key-value arguments list.'); */
  /*  end */
  /* usingDefaultMethod = true; */
  /* n = 1; */
  /* minAngle = 0.7 * pi; */
  /* thresholdingAngles = true; */
  /* nPoints = 50; */
  /*  while n < nExtraArgIn */
  /*    switch lower(varargin{n})   */
  /*      case 'minangle' */
  /* minAngle = varargin{n+1}; */
  /* n = n+2; */
  /*      case 'maxarea' */
  /*        maxArea = varargin{n+1}; */
  /*        thresholdingArea = true; */
  /*        usingDefaultMethod = false; */
  /*        n = n+2; */
  /*      case 'maxlength' */
  /*        maxLength = varargin{n+1}; */
  /*        thresholdingLength = true; */
  /*        usingDefaultMethod = false; */
  /*        n = n+2; */
  /*      case 'minlength' */
  /*        minLength = varargin{n+1}; */
  /*        thresholdingLength = true; */
  /*        n = n+2; */
  /*      case 'minsignal' */
  /*        minSignal = varargin{n+1}; */
  /*        thresholdingSignal = true; */
  /*        n = n+2; */
  /*      case 'npoints' */
  /*        nPoints = varargin{n+1}; */
  /*        n = n+2; */
  /*      case 'vectorize' */
  /*        vectorizable = varargin{n+1}; */
  /*        n = n+2; */
  /*      case 'maxrefinements' */
  /*        maxRefinements = varargin{n+1}; */
  /*        n = n+2; */
  /*      case 'waitbar' */
  /*        displayWaitbar = varargin{n+1}; */
  /*        n = n+2; */
  /*      otherwise */
  /*        error('adaptiveFunctionEvaluation:ArgChk',... */
  /*          ['unknown keyword argument: ', varargin{n}]); */
  /*    end */
  /*  end */
  /*  if no method is specified use the 'angle' method as default */
  /*  if usingDefaultMethod */
  /*    thresholdingAngles = true; */
  /*  end */
  /*  Initial function evaluation */
  /*  if initialDomain only contains the start and the end points, create a new */
  /*  array with 'nPoints' points. */
  st.site = &kd_emlrtRSI;
  linspace(&st, startDomain[0], startDomain[1], nPoints, r);
  i = newDomain->size[0];
  newDomain->size[0] = r->size[1];
  emxEnsureCapacity_real_T(sp, newDomain, i, &vi_emlrtRTEI);
  input_sizes_idx_0 = r->size[1];
  for (i = 0; i < input_sizes_idx_0; i++) {
    newDomain->data[i] = r->data[i];
  }

  emxFree_real_T(&r);
  emxInit_real_T(sp, &hiVal, 1, &lj_emlrtRTEI, true);

  /*  Normalize the input function: This step allows to use the same syntax for */
  /*  functions with single or multiple output parameters. */
  /*  Remove this syntax for compile - AVH */
  /* func = @(x) normalizeFunction(x,sldProfile,vectorizable); */
  /*  Evaluate the input function on the initial set of points. */
  st.site = &ld_emlrtRSI;
  b_normalizeFunction(&st, newDomain, sldProfile, hiVal);

  /* dataPoints = [initialDomain(:), func(initialDomain(:))]; */
  st.site = &md_emlrtRSI;
  b_st.site = &nb_emlrtRSI;
  c_st.site = &ob_emlrtRSI;
  if (hiVal->size[0] != newDomain->size[0]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &hb_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  i = out->f1->size[0] * out->f1->size[1];
  out->f1->size[0] = newDomain->size[0];
  out->f1->size[1] = 2;
  emxEnsureCapacity_real_T(&b_st, out->f1, i, &wi_emlrtRTEI);
  input_sizes_idx_0 = newDomain->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    out->f1->data[i] = newDomain->data[i];
  }

  input_sizes_idx_0 = hiVal->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    out->f1->data[i + out->f1->size[0]] = hiVal->data[i];
  }

  /*  Iterative function refinement */
  /*  if displayWaitbar */
  /*    refinementWaitbar = waitbar(0,['Evaluating function ',func2str(func)],... */
  /*      'CreateCancelBtn','setappdata(gcbf,''canceling'',true)'); */
  /*    setappdata(refinementWaitbar,'canceling',false) */
  /*  end */
  nRefinements = 0;
  emxInit_boolean_T(sp, &sharpCorners, 1, &yi_emlrtRTEI, true);
  emxInit_boolean_T(sp, &segmentsToSplit, 1, &mj_emlrtRTEI, true);
  emxInit_boolean_T(sp, &r1, 1, &ej_emlrtRTEI, true);
  emxInit_real_T(sp, &newDataPoints, 2, &dj_emlrtRTEI, true);
  emxInit_int32_T(sp, &r2, 1, &ej_emlrtRTEI, true);
  emxInit_int32_T(sp, &r3, 1, &fj_emlrtRTEI, true);
  emxInit_int32_T(sp, &r4, 1, &ej_emlrtRTEI, true);
  emxInit_int32_T(sp, &r5, 1, &fj_emlrtRTEI, true);
  emxInit_real_T(sp, &b_out, 2, &xi_emlrtRTEI, true);
  exitg1 = false;
  while ((!exitg1) && (nRefinements < 10)) {
    /*  calculate the box which encloses the current data points: */
    st.site = &nd_emlrtRSI;
    b_st.site = &dd_emlrtRSI;
    c_st.site = &ed_emlrtRSI;
    d_st.site = &fd_emlrtRSI;
    if (out->f1->size[0] == 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &lb_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility",
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (out->f1->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &mb_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero",
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    e_st.site = &ce_emlrtRSI;
    f_st.site = &de_emlrtRSI;
    g_st.site = &ee_emlrtRSI;
    i = out->f1->size[0];
    overflow = ((2 <= out->f1->size[0]) && (out->f1->size[0] > 2147483646));
    maxval[0] = out->f1->data[0];
    h_st.site = &fe_emlrtRSI;
    if (overflow) {
      i_st.site = &j_emlrtRSI;
      check_forloop_overflow_error(&i_st);
    }

    for (b_i = 2; b_i <= i; b_i++) {
      b = out->f1->data[b_i - 1];
      overflow = ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN(maxval[0]) ||
        (maxval[0] < b)));
      if (overflow) {
        maxval[0] = b;
      }
    }

    maxval[1] = out->f1->data[out->f1->size[0]];
    h_st.site = &fe_emlrtRSI;
    for (b_i = 2; b_i <= i; b_i++) {
      b = out->f1->data[(b_i + out->f1->size[0]) - 1];
      overflow = ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN(maxval[1]) ||
        (maxval[1] < b)));
      if (overflow) {
        maxval[1] = b;
      }
    }

    st.site = &nd_emlrtRSI;
    b_st.site = &ge_emlrtRSI;
    c_st.site = &he_emlrtRSI;
    d_st.site = &ie_emlrtRSI;
    if (out->f1->size[0] == 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &lb_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility",
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (out->f1->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &mb_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero",
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    e_st.site = &ce_emlrtRSI;
    f_st.site = &de_emlrtRSI;
    g_st.site = &ee_emlrtRSI;
    i = out->f1->size[0];
    overflow = ((2 <= out->f1->size[0]) && (out->f1->size[0] > 2147483646));
    minval_idx_0 = out->f1->data[0];
    h_st.site = &fe_emlrtRSI;
    if (overflow) {
      i_st.site = &j_emlrtRSI;
      check_forloop_overflow_error(&i_st);
    }

    for (b_i = 2; b_i <= i; b_i++) {
      b = out->f1->data[b_i - 1];
      overflow = ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN(minval_idx_0)
        || (minval_idx_0 > b)));
      if (overflow) {
        minval_idx_0 = b;
      }
    }

    minval_idx_1 = out->f1->data[out->f1->size[0]];
    h_st.site = &fe_emlrtRSI;
    for (b_i = 2; b_i <= i; b_i++) {
      b = out->f1->data[(b_i + out->f1->size[0]) - 1];
      overflow = ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN(minval_idx_1)
        || (minval_idx_1 > b)));
      if (overflow) {
        minval_idx_1 = b;
      }
    }

    /*  Each point is considered as the central corner of the triangle formed */
    /*  with its left and right hand side neighbours. The first and the last */
    /*  points are not the central corner of any triangle, so for N points */
    /*  there are only N-2 triangles. */
    if (!((real_T)out->f1->size[0] - 2.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b((real_T)out->f1->size[0] - 2.0, &kb_emlrtDCI,
        sp);
    }

    /*    if thresholdingArea */
    /*      triangleArea = calculateTrianglesArea(dataPoints(:,1:2)); */
    /*      bigTriangles = triangleArea > (maxArea * dataBoxArea); */
    /*      trianglesToRefine = trianglesToRefine | bigTriangles; */
    /*    end */
    input_sizes_idx_0 = out->f1->size[0];
    i = b_out->size[0] * b_out->size[1];
    b_out->size[0] = out->f1->size[0];
    b_out->size[1] = 2;
    emxEnsureCapacity_real_T(sp, b_out, i, &xi_emlrtRTEI);
    for (i = 0; i < input_sizes_idx_0; i++) {
      b_out->data[i] = out->f1->data[i];
    }

    maxval[0] -= minval_idx_0;
    for (i = 0; i < input_sizes_idx_0; i++) {
      b_out->data[i + b_out->size[0]] = out->f1->data[i + out->f1->size[0]];
    }

    maxval[1] -= minval_idx_1;
    st.site = &od_emlrtRSI;
    calculateCentralAngles(&st, b_out, maxval, newDomain);
    i = sharpCorners->size[0];
    sharpCorners->size[0] = newDomain->size[0];
    emxEnsureCapacity_boolean_T(sp, sharpCorners, i, &yi_emlrtRTEI);
    input_sizes_idx_0 = newDomain->size[0];
    for (i = 0; i < input_sizes_idx_0; i++) {
      sharpCorners->data[i] = (newDomain->data[i] < minAngle);
    }

    if (out->f1->size[0] - 2 != sharpCorners->size[0]) {
      emlrtSizeEqCheck1DR2012b(out->f1->size[0] - 2, sharpCorners->size[0],
        &f_emlrtECI, sp);
    }

    i = sharpCorners->size[0];
    sharpCorners->size[0] = out->f1->size[0] - 2;
    emxEnsureCapacity_boolean_T(sp, sharpCorners, i, &aj_emlrtRTEI);

    /*  For N points there are N-2 triangles and N-1 triangle sides. Each */
    /*  triangle side is a segment, which can be split or not depending on the */
    /*  refinement parameters. */
    i = segmentsToSplit->size[0];
    segmentsToSplit->size[0] = out->f1->size[0] - 1;
    emxEnsureCapacity_boolean_T(sp, segmentsToSplit, i, &bj_emlrtRTEI);
    input_sizes_idx_0 = out->f1->size[0] - 2;
    for (i = 0; i < input_sizes_idx_0; i++) {
      segmentsToSplit->data[i] = sharpCorners->data[i];
    }

    segmentsToSplit->data[out->f1->size[0] - 2] = false;
    i = r1->size[0];
    r1->size[0] = out->f1->size[0] - 1;
    emxEnsureCapacity_boolean_T(sp, r1, i, &cj_emlrtRTEI);
    r1->data[0] = false;
    input_sizes_idx_0 = out->f1->size[0] - 2;
    for (i = 0; i < input_sizes_idx_0; i++) {
      r1->data[i + 1] = sharpCorners->data[i];
    }

    if (segmentsToSplit->size[0] != r1->size[0]) {
      emlrtSizeEqCheck1DR2012b(segmentsToSplit->size[0], r1->size[0],
        &g_emlrtECI, sp);
    }

    input_sizes_idx_0 = segmentsToSplit->size[0];
    for (i = 0; i < input_sizes_idx_0; i++) {
      segmentsToSplit->data[i] = (segmentsToSplit->data[i] || r1->data[i]);
    }

    /*    if thresholdingLength */
    /*      dataSegments = diff(dataPoints(:,1:2)); */
    /*      normalizedSegments = bsxfun(@rdivide, dataSegments, dataBoxSize); */
    /*      segmentsLengthNormalized = hypot(normalizedSegments(:,1), normalizedSegments(:,2)); */
    /*      tooLongSegments = segmentsLengthNormalized > maxLength; */
    /*      longEnoughSegments = segmentsLengthNormalized > minLength; */
    /*      segmentsToSplit = (segmentsToSplit | tooLongSegments) & longEnoughSegments; */
    /*    end */
    /*    if thresholdingSignal */
    /*      segmentsCenters = (dataPoints(1:end-1,2)+dataPoints(2:end,2))/2; */
    /*      centerAboveThreshold = segmentsCenters > minSignal * max(abs(dataPoints(:,2))); */
    /*      segmentsToSplit = segmentsToSplit & centerAboveThreshold; */
    /*    end */
    st.site = &pd_emlrtRSI;
    if (any(segmentsToSplit)) {
      st.site = &qd_emlrtRSI;

      /*  increaseSampling increase the sampling of an input function */
      b_input_sizes_idx_0 = segmentsToSplit->size[0];
      for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
        if (segmentsToSplit->data[b_i] && ((b_i + 1 < 1) || (b_i + 1 >
              segmentsToSplit->size[0]))) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, segmentsToSplit->size[0],
            &nf_emlrtBCI, &st);
        }
      }

      b_input_sizes_idx_0 = segmentsToSplit->size[0];
      trueCount = 0;
      for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
        if (segmentsToSplit->data[b_i]) {
          trueCount++;
        }
      }

      i = newDataPoints->size[0] * newDataPoints->size[1];
      newDataPoints->size[0] = trueCount;
      newDataPoints->size[1] = 2;
      emxEnsureCapacity_real_T(&st, newDataPoints, i, &dj_emlrtRTEI);
      input_sizes_idx_0 = trueCount << 1;
      for (i = 0; i < input_sizes_idx_0; i++) {
        newDataPoints->data[i] = 0.0;
      }

      i = r1->size[0];
      r1->size[0] = segmentsToSplit->size[0] + 1;
      emxEnsureCapacity_boolean_T(&st, r1, i, &ej_emlrtRTEI);
      input_sizes_idx_0 = segmentsToSplit->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        r1->data[i] = segmentsToSplit->data[i];
      }

      r1->data[segmentsToSplit->size[0]] = false;
      b_input_sizes_idx_0 = r1->size[0];
      for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
        if (r1->data[b_i] && ((b_i + 1 < 1) || (b_i + 1 > out->f1->size[0]))) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, out->f1->size[0],
            &of_emlrtBCI, &st);
        }
      }

      i = sharpCorners->size[0];
      sharpCorners->size[0] = segmentsToSplit->size[0] + 1;
      emxEnsureCapacity_boolean_T(&st, sharpCorners, i, &fj_emlrtRTEI);
      sharpCorners->data[0] = false;
      input_sizes_idx_0 = segmentsToSplit->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        sharpCorners->data[i + 1] = segmentsToSplit->data[i];
      }

      b_input_sizes_idx_0 = sharpCorners->size[0];
      for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
        if (sharpCorners->data[b_i] && ((b_i + 1 < 1) || (b_i + 1 > out->
              f1->size[0]))) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, out->f1->size[0],
            &pf_emlrtBCI, &st);
        }
      }

      b_input_sizes_idx_0 = r1->size[0] - 1;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (r1->data[b_i]) {
          input_sizes_idx_0++;
        }
      }

      i = r2->size[0];
      r2->size[0] = input_sizes_idx_0;
      emxEnsureCapacity_int32_T(&st, r2, i, &gj_emlrtRTEI);
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (r1->data[b_i]) {
          r2->data[input_sizes_idx_0] = b_i + 1;
          input_sizes_idx_0++;
        }
      }

      b_input_sizes_idx_0 = sharpCorners->size[0] - 1;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (sharpCorners->data[b_i]) {
          input_sizes_idx_0++;
        }
      }

      i = r3->size[0];
      r3->size[0] = input_sizes_idx_0;
      emxEnsureCapacity_int32_T(&st, r3, i, &gj_emlrtRTEI);
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (sharpCorners->data[b_i]) {
          r3->data[input_sizes_idx_0] = b_i + 1;
          input_sizes_idx_0++;
        }
      }

      if (r2->size[0] != r3->size[0]) {
        emlrtSizeEqCheck1DR2012b(r2->size[0], r3->size[0], &h_emlrtECI, &st);
      }

      b_input_sizes_idx_0 = r1->size[0] - 1;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (r1->data[b_i]) {
          input_sizes_idx_0++;
        }
      }

      i = r4->size[0];
      r4->size[0] = input_sizes_idx_0;
      emxEnsureCapacity_int32_T(&st, r4, i, &gj_emlrtRTEI);
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (r1->data[b_i]) {
          r4->data[input_sizes_idx_0] = b_i + 1;
          input_sizes_idx_0++;
        }
      }

      b_input_sizes_idx_0 = sharpCorners->size[0] - 1;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (sharpCorners->data[b_i]) {
          input_sizes_idx_0++;
        }
      }

      i = r5->size[0];
      r5->size[0] = input_sizes_idx_0;
      emxEnsureCapacity_int32_T(&st, r5, i, &gj_emlrtRTEI);
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (sharpCorners->data[b_i]) {
          r5->data[input_sizes_idx_0] = b_i + 1;
          input_sizes_idx_0++;
        }
      }

      i = newDomain->size[0];
      newDomain->size[0] = r4->size[0];
      emxEnsureCapacity_real_T(&st, newDomain, i, &hj_emlrtRTEI);
      input_sizes_idx_0 = r4->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        newDomain->data[i] = 0.5 * (out->f1->data[r4->data[i] - 1] + out->
          f1->data[r5->data[i] - 1]);
      }

      emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &newDomain->size[0], 1,
        &i_emlrtECI, &st);
      input_sizes_idx_0 = newDomain->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        newDataPoints->data[i] = newDomain->data[i];
      }

      input_sizes_idx_0 = newDataPoints->size[0];
      i = hiVal->size[0];
      hiVal->size[0] = newDataPoints->size[0];
      emxEnsureCapacity_real_T(&st, hiVal, i, &ij_emlrtRTEI);
      for (i = 0; i < input_sizes_idx_0; i++) {
        hiVal->data[i] = newDataPoints->data[i];
      }

      b_st.site = &bf_emlrtRSI;
      b_normalizeFunction(&b_st, hiVal, sldProfile, newDomain);
      emlrtSubAssignSizeCheckR2012b(&newDataPoints->size[0], 1, &newDomain->
        size[0], 1, &j_emlrtECI, &st);
      input_sizes_idx_0 = newDomain->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        newDataPoints->data[i + newDataPoints->size[0]] = newDomain->data[i];
      }

      /*  For simplicity append the new points at the end and then sort. */
      b_st.site = &cf_emlrtRSI;
      c_st.site = &df_emlrtRSI;
      d_st.site = &ob_emlrtRSI;
      if (out->f1->size[0] != 0) {
        input_sizes_idx_0 = out->f1->size[0];
      } else {
        input_sizes_idx_0 = 0;
      }

      if (newDataPoints->size[0] != 0) {
        b_input_sizes_idx_0 = newDataPoints->size[0];
      } else {
        b_input_sizes_idx_0 = 0;
      }

      if (out->f1->size[0] != 0) {
        trueCount = out->f1->size[0];
      } else {
        trueCount = 0;
      }

      i = b_out->size[0] * b_out->size[1];
      b_out->size[0] = input_sizes_idx_0 + b_input_sizes_idx_0;
      b_out->size[1] = 2;
      emxEnsureCapacity_real_T(&st, b_out, i, &jj_emlrtRTEI);
      for (i = 0; i < input_sizes_idx_0; i++) {
        b_out->data[i] = out->f1->data[i];
      }

      for (i = 0; i < input_sizes_idx_0; i++) {
        b_out->data[i + b_out->size[0]] = out->f1->data[i + out->f1->size[0]];
      }

      for (i = 0; i < b_input_sizes_idx_0; i++) {
        b_out->data[i + trueCount] = newDataPoints->data[i];
      }

      for (i = 0; i < b_input_sizes_idx_0; i++) {
        b_out->data[(i + trueCount) + b_out->size[0]] = newDataPoints->data[i +
          newDataPoints->size[0]];
      }

      i = out->f1->size[0] * out->f1->size[1];
      out->f1->size[0] = b_out->size[0];
      out->f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, out->f1, i, &kj_emlrtRTEI);
      input_sizes_idx_0 = b_out->size[0] * b_out->size[1];
      for (i = 0; i < input_sizes_idx_0; i++) {
        out->f1->data[i] = b_out->data[i];
      }

      b_st.site = &cf_emlrtRSI;
      sortrows(&b_st, out->f1);

      /*  Removed waitbar for compile - AVH */
      /*    if displayWaitbar */
      /*      if getappdata(refinementWaitbar,'canceling'), break; end */
      /*      waitbar(nRefinements/maxRefinements,refinementWaitbar); */
      /*    end */
      nRefinements++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    } else {
      exitg1 = true;
    }
  }

  emxFree_real_T(&b_out);
  emxFree_int32_T(&r5);
  emxFree_int32_T(&r4);
  emxFree_int32_T(&r3);
  emxFree_int32_T(&r2);
  emxFree_real_T(&newDataPoints);
  emxFree_boolean_T(&r1);
  emxFree_boolean_T(&segmentsToSplit);
  emxFree_boolean_T(&sharpCorners);
  emxFree_real_T(&hiVal);
  emxFree_real_T(&newDomain);

  /*  if displayWaitbar */
  /*    delete(refinementWaitbar); */
  /*  end */
  /*  Plotting refined function */
  /*  Removed for compile - AVH */
  /*  if nargin==0 % test mode */
  /*    figure(testFigureHandle); */
  /*    hold on; */
  /*    plot(dataPoints(:,1), dataPoints(:,2),'ro-'); */
  /*    legend('initial', 'refiniment'); */
  /*  end */
  /* if nargout==1 */
  /*  elseif nargout>1 */
  /*    out{1} = dataPoints(:,1); */
  /*    out{2} = dataPoints(:,2:end); */
  /*  end */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (adaptive_new.c) */
