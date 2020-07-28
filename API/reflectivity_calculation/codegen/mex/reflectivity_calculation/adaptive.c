/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * adaptive.c
 *
 * Code generation for function 'adaptive'
 *
 */

/* Include files */
#include "adaptive.h"
#include "acos.h"
#include "any.h"
#include "eml_int_forloop_overflow_check.h"
#include "linspace.h"
#include "mwmathutil.h"
#include "power.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sldFunc.h"
#include "sortrows.h"

/* Variable Definitions */
static emlrtRSInfo vc_emlrtRSI = { 252,/* lineNo */
  "adaptive",                          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo wc_emlrtRSI = { 267,/* lineNo */
  "adaptive",                          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo xc_emlrtRSI = { 281,/* lineNo */
  "adaptive",                          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo yc_emlrtRSI = { 304,/* lineNo */
  "adaptive",                          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo ad_emlrtRSI = { 305,/* lineNo */
  "adaptive",                          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo bd_emlrtRSI = { 376,/* lineNo */
  "normalizeFunction",                 /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo jd_emlrtRSI = { 167,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo kd_emlrtRSI = { 326,/* lineNo */
  "unaryMinOrMaxDispatch",             /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo ld_emlrtRSI = { 394,/* lineNo */
  "minOrMax2D",                        /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo md_emlrtRSI = { 476,/* lineNo */
  "minOrMax2DColumnMajorDim1",         /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo nd_emlrtRSI = { 14, /* lineNo */
  "min",                               /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/min.m"/* pathName */
};

static emlrtRSInfo od_emlrtRSI = { 46, /* lineNo */
  "minOrMax",                          /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo pd_emlrtRSI = { 92, /* lineNo */
  "minimum",                           /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo qd_emlrtRSI = { 398,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo rd_emlrtRSI = { 399,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo sd_emlrtRSI = { 401,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo td_emlrtRSI = { 403,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo ud_emlrtRSI = { 404,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo vd_emlrtRSI = { 405,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo wd_emlrtRSI = { 408,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo xd_emlrtRSI = { 407,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo yd_emlrtRSI = { 409,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo ee_emlrtRSI = { 16, /* lineNo */
  "sqrt",                              /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pathName */
};

static emlrtRSInfo je_emlrtRSI = { 431,/* lineNo */
  "increaseSampling",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo ke_emlrtRSI = { 433,/* lineNo */
  "increaseSampling",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo le_emlrtRSI = { 27, /* lineNo */
  "cat",                               /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtDCInfo hb_emlrtDCI = { 274,/* lineNo */
  30,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  4                                    /* checkKind */
};

static emlrtECInfo e_emlrtECI = { -1,  /* nDims */
  283,                                 /* lineNo */
  25,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtECInfo f_emlrtECI = { -1,  /* nDims */
  289,                                 /* lineNo */
  21,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = { 26,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 95,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pName */
};

static emlrtECInfo g_emlrtECI = { -1,  /* nDims */
  376,                                 /* lineNo */
  5,                                   /* colNo */
  "normalizeFunction",                 /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtECInfo h_emlrtECI = { 2,   /* nDims */
  398,                                 /* lineNo */
  3,                                   /* colNo */
  "calculateCentralAngles",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtECInfo i_emlrtECI = { -1,  /* nDims */
  403,                                 /* lineNo */
  21,                                  /* colNo */
  "calculateCentralAngles",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtECInfo j_emlrtECI = { -1,  /* nDims */
  404,                                 /* lineNo */
  21,                                  /* colNo */
  "calculateCentralAngles",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtECInfo k_emlrtECI = { -1,  /* nDims */
  405,                                 /* lineNo */
  21,                                  /* colNo */
  "calculateCentralAngles",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtECInfo l_emlrtECI = { -1,  /* nDims */
  407,                                 /* lineNo */
  4,                                   /* colNo */
  "calculateCentralAngles",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtECInfo m_emlrtECI = { -1,  /* nDims */
  408,                                 /* lineNo */
  8,                                   /* colNo */
  "calculateCentralAngles",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtBCInfo ye_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  386,                                 /* lineNo */
  20,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo af_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  386,                                 /* lineNo */
  22,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  386,                                 /* lineNo */
  40,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  386,                                 /* lineNo */
  42,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo n_emlrtECI = { 2,   /* nDims */
  386,                                 /* lineNo */
  13,                                  /* colNo */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtBCInfo df_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  387,                                 /* lineNo */
  23,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ef_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  387,                                 /* lineNo */
  41,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ff_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  387,                                 /* lineNo */
  43,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo o_emlrtECI = { 2,   /* nDims */
  387,                                 /* lineNo */
  14,                                  /* colNo */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtBCInfo gf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  388,                                 /* lineNo */
  22,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  388,                                 /* lineNo */
  40,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo if_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  388,                                 /* lineNo */
  42,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo p_emlrtECI = { 2,   /* nDims */
  388,                                 /* lineNo */
  13,                                  /* colNo */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

static emlrtECInfo bb_emlrtECI = { -1, /* nDims */
  429,                                 /* lineNo */
  29,                                  /* colNo */
  "increaseSampling",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtECInfo cb_emlrtECI = { -1, /* nDims */
  429,                                 /* lineNo */
  1,                                   /* colNo */
  "increaseSampling",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtECInfo db_emlrtECI = { -1, /* nDims */
  431,                                 /* lineNo */
  1,                                   /* colNo */
  "increaseSampling",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtBCInfo vq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  425,                                 /* lineNo */
  39,                                  /* colNo */
  "segmentsToSplit",                   /* aName */
  "increaseSampling",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  429,                                 /* lineNo */
  40,                                  /* colNo */
  "dataPoints",                        /* aName */
  "increaseSampling",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  430,                                 /* lineNo */
  14,                                  /* colNo */
  "dataPoints",                        /* aName */
  "increaseSampling",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  376,                                 /* lineNo */
  20,                                  /* colNo */
  "x",                                 /* aName */
  "normalizeFunction",                 /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ar_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  376,                                 /* lineNo */
  5,                                   /* colNo */
  "y",                                 /* aName */
  "normalizeFunction",                 /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo xh_emlrtRTEI = { 255,/* lineNo */
  1,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo yh_emlrtRTEI = { 334,/* lineNo */
  3,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo ai_emlrtRTEI = { 281,/* lineNo */
  42,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo bi_emlrtRTEI = { 282,/* lineNo */
  5,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo ci_emlrtRTEI = { 283,/* lineNo */
  5,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo di_emlrtRTEI = { 289,/* lineNo */
  21,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo ei_emlrtRTEI = { 289,/* lineNo */
  50,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo fi_emlrtRTEI = { 281,/* lineNo */
  5,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo gi_emlrtRTEI = { 289,/* lineNo */
  3,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo hi_emlrtRTEI = { 1,/* lineNo */
  16,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo ui_emlrtRTEI = { 398,/* lineNo */
  3,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo vi_emlrtRTEI = { 397,/* lineNo */
  1,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo wi_emlrtRTEI = { 386,/* lineNo */
  1,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo xi_emlrtRTEI = { 387,/* lineNo */
  1,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo yi_emlrtRTEI = { 388,/* lineNo */
  1,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo aj_emlrtRTEI = { 403,/* lineNo */
  21,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo bj_emlrtRTEI = { 403,/* lineNo */
  42,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo cj_emlrtRTEI = { 404,/* lineNo */
  21,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo dj_emlrtRTEI = { 404,/* lineNo */
  42,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo ej_emlrtRTEI = { 405,/* lineNo */
  21,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo fj_emlrtRTEI = { 405,/* lineNo */
  42,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo gj_emlrtRTEI = { 407,/* lineNo */
  3,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo hj_emlrtRTEI = { 409,/* lineNo */
  20,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo ij_emlrtRTEI = { 409,/* lineNo */
  1,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo jj_emlrtRTEI = { 403,/* lineNo */
  1,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo kj_emlrtRTEI = { 404,/* lineNo */
  1,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo lj_emlrtRTEI = { 405,/* lineNo */
  1,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo mj_emlrtRTEI = { 391,/* lineNo */
  24,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo qo_emlrtRTEI = { 426,/* lineNo */
  1,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo ro_emlrtRTEI = { 429,/* lineNo */
  40,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo so_emlrtRTEI = { 430,/* lineNo */
  14,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo to_emlrtRTEI = { 422,/* lineNo */
  23,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo uo_emlrtRTEI = { 429,/* lineNo */
  22,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo vo_emlrtRTEI = { 431,/* lineNo */
  22,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo wo_emlrtRTEI = { 303,/* lineNo */
  14,                                  /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

/* Function Declarations */
static void calculateCentralAngles(const emlrtStack *sp, const emxArray_real_T
  *XYdata, const real_T dataBoxSize[2], emxArray_real_T *cornerAngle);
static void increaseSampling(const emlrtStack *sp, emxArray_real_T *dataPoints,
  const emxArray_boolean_T *segmentsToSplit, const emxArray_real_T *sldProfile);

/* Function Definitions */
static void calculateCentralAngles(const emlrtStack *sp, const emxArray_real_T
  *XYdata, const real_T dataBoxSize[2], emxArray_real_T *cornerAngle)
{
  emxArray_real_T *normalizedData;
  real_T varargin_1[2];
  uint32_T varargin_2[2];
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  boolean_T overflow;
  int32_T m;
  int32_T i;
  int32_T b_i;
  real_T b;
  emxArray_real_T *longStep;
  int32_T i1;
  int32_T iv[2];
  int32_T iv1[2];
  emxArray_real_T *firstStep;
  emxArray_real_T *secondStep;
  emxArray_real_T *b_firstStep;
  emxArray_real_T *firstStepSquared;
  emxArray_real_T *r;
  emxArray_real_T *secondStepSquared;
  emxArray_real_T *longStepSquared;
  emxArray_creal_T *r1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
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
  emxInit_real_T(sp, &normalizedData, 2, &vi_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 13U, 3U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 17U);

  /*  Calculate the central angle of the triangles formed by data points. */
  /*  For input size NxM, the output size is (N-2)xN, because the first and the */
  /*  last point are not the central corner of any triangle. */
  /*  Normalize data, because angles depend on scaling. */
  st.site = &qd_emlrtRSI;
  b_st.site = &qd_emlrtRSI;
  repmat(&b_st, dataBoxSize, XYdata->size[0], normalizedData);
  varargin_1[0] = XYdata->size[0];
  varargin_2[0] = (uint32_T)normalizedData->size[0];
  varargin_1[1] = XYdata->size[1];
  varargin_2[1] = (uint32_T)normalizedData->size[1];
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((int32_T)(uint32_T)varargin_1[k] != (int32_T)varargin_2[k]) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  overflow = (int32_T)p;
  if (!overflow) {
    emlrtErrorWithMessageIdR2018a(&st, &lb_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  m = XYdata->size[0] * XYdata->size[1];
  i = normalizedData->size[0] * normalizedData->size[1];
  normalizedData->size[0] = XYdata->size[0];
  normalizedData->size[1] = 2;
  emxEnsureCapacity_real_T(&st, normalizedData, i, &ui_emlrtRTEI);
  for (i = 0; i < m; i++) {
    normalizedData->data[i] = XYdata->data[i] / normalizedData->data[i];
  }

  st.site = &rd_emlrtRSI;
  b_st.site = &nd_emlrtRSI;
  c_st.site = &od_emlrtRSI;
  d_st.site = &pd_emlrtRSI;
  if (XYdata->size[0] == 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &ib_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility",
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (XYdata->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &jb_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &jd_emlrtRSI;
  f_st.site = &kd_emlrtRSI;
  g_st.site = &ld_emlrtRSI;
  m = XYdata->size[0];
  overflow = ((2 <= XYdata->size[0]) && (XYdata->size[0] > 2147483646));
  varargin_1[0] = XYdata->data[0];
  h_st.site = &md_emlrtRSI;
  if (overflow) {
    i_st.site = &nb_emlrtRSI;
    check_forloop_overflow_error(&i_st);
  }

  for (b_i = 2; b_i <= m; b_i++) {
    b = XYdata->data[b_i - 1];
    overflow = ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN(varargin_1[0])
      || (varargin_1[0] > b)));
    if (overflow) {
      varargin_1[0] = b;
    }
  }

  varargin_1[1] = XYdata->data[XYdata->size[0]];
  h_st.site = &md_emlrtRSI;
  for (b_i = 2; b_i <= m; b_i++) {
    b = XYdata->data[(b_i + XYdata->size[0]) - 1];
    overflow = ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN(varargin_1[1])
      || (varargin_1[1] > b)));
    if (overflow) {
      varargin_1[1] = b;
    }
  }

  emxInit_real_T(&g_st, &longStep, 2, &mj_emlrtRTEI, true);
  st.site = &rd_emlrtRSI;
  repmat(&st, varargin_1, XYdata->size[0], longStep);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])normalizedData->size, *(int32_T (*)
    [2])longStep->size, &h_emlrtECI, sp);
  m = normalizedData->size[0] * normalizedData->size[1];
  i = normalizedData->size[0] * normalizedData->size[1];
  normalizedData->size[1] = 2;
  emxEnsureCapacity_real_T(sp, normalizedData, i, &vi_emlrtRTEI);
  for (i = 0; i < m; i++) {
    normalizedData->data[i] -= longStep->data[i];
  }

  /*  calculate cosine of central angles */
  st.site = &sd_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 13U, 2U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 16U);

  /*  Return the sides (deltaX, deltaY) of the triangles formed by data points. */
  /*  For input size NxM, the output size is (N-2)xN, because the first and the */
  /*  last point are not the central corner of any triangle. */
  if (2 > normalizedData->size[0] - 1) {
    i = -1;
    i1 = -1;
  } else {
    if (2 > normalizedData->size[0]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, normalizedData->size[0], &ye_emlrtBCI,
        &st);
    }

    i = 0;
    i1 = normalizedData->size[0] - 1;
    if ((i1 < 1) || (i1 > normalizedData->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, normalizedData->size[0], &af_emlrtBCI,
        &st);
    }

    i1--;
  }

  if (1 > normalizedData->size[0] - 2) {
    b_i = 0;
  } else {
    if (1 > normalizedData->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, normalizedData->size[0], &bf_emlrtBCI,
        &st);
    }

    b_i = normalizedData->size[0] - 2;
    if ((b_i < 1) || (b_i > normalizedData->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, normalizedData->size[0],
        &cf_emlrtBCI, &st);
    }
  }

  m = i1 - i;
  iv[0] = m;
  iv[1] = 2;
  iv1[0] = b_i;
  iv1[1] = 2;
  if (m != b_i) {
    emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &n_emlrtECI, &st);
  }

  emxInit_real_T(&st, &firstStep, 2, &mj_emlrtRTEI, true);
  i1 = firstStep->size[0] * firstStep->size[1];
  firstStep->size[0] = m;
  firstStep->size[1] = 2;
  emxEnsureCapacity_real_T(&st, firstStep, i1, &wi_emlrtRTEI);
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
        normalizedData->size[0], &df_emlrtBCI, &st);
    }

    i1 = normalizedData->size[0] - 1;
  }

  if (2 > normalizedData->size[0] - 1) {
    b_i = -1;
    k = 0;
  } else {
    if (2 > normalizedData->size[0]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, normalizedData->size[0], &ef_emlrtBCI,
        &st);
    }

    b_i = 0;
    k = normalizedData->size[0] - 1;
    if ((k < 1) || (k > normalizedData->size[0])) {
      emlrtDynamicBoundsCheckR2012b(k, 1, normalizedData->size[0], &ff_emlrtBCI,
        &st);
    }
  }

  m = i1 - i;
  iv[0] = m;
  iv[1] = 2;
  iv1[0] = (k - b_i) - 1;
  iv1[1] = 2;
  if (m != iv1[0]) {
    emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &o_emlrtECI, &st);
  }

  emxInit_real_T(&st, &secondStep, 2, &mj_emlrtRTEI, true);
  i1 = secondStep->size[0] * secondStep->size[1];
  secondStep->size[0] = m;
  secondStep->size[1] = 2;
  emxEnsureCapacity_real_T(&st, secondStep, i1, &xi_emlrtRTEI);
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
        normalizedData->size[0], &gf_emlrtBCI, &st);
    }

    i1 = normalizedData->size[0] - 1;
  }

  if (1 > normalizedData->size[0] - 2) {
    b_i = 0;
  } else {
    if (1 > normalizedData->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, normalizedData->size[0], &hf_emlrtBCI,
        &st);
    }

    b_i = normalizedData->size[0] - 2;
    if ((b_i < 1) || (b_i > normalizedData->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, normalizedData->size[0],
        &if_emlrtBCI, &st);
    }
  }

  m = i1 - i;
  iv[0] = m;
  iv[1] = 2;
  iv1[0] = b_i;
  iv1[1] = 2;
  if (m != b_i) {
    emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &p_emlrtECI, &st);
  }

  i1 = longStep->size[0] * longStep->size[1];
  longStep->size[0] = m;
  longStep->size[1] = 2;
  emxEnsureCapacity_real_T(&st, longStep, i1, &yi_emlrtRTEI);
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
  emxInit_real_T(&st, &b_firstStep, 1, &aj_emlrtRTEI, true);

  /*  calculate area of squares of length of triangle sides */
  m = firstStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = firstStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &aj_emlrtRTEI);
  for (i = 0; i < m; i++) {
    b_firstStep->data[i] = firstStep->data[i];
  }

  emxInit_real_T(sp, &firstStepSquared, 1, &jj_emlrtRTEI, true);
  st.site = &td_emlrtRSI;
  power(&st, b_firstStep, firstStepSquared);
  m = firstStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = firstStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &bj_emlrtRTEI);
  for (i = 0; i < m; i++) {
    b_firstStep->data[i] = firstStep->data[i + firstStep->size[0]];
  }

  emxFree_real_T(&firstStep);
  emxInit_real_T(sp, &r, 1, &mj_emlrtRTEI, true);
  st.site = &td_emlrtRSI;
  power(&st, b_firstStep, r);
  if (firstStepSquared->size[0] != r->size[0]) {
    emlrtSizeEqCheck1DR2012b(firstStepSquared->size[0], r->size[0], &i_emlrtECI,
      sp);
  }

  m = firstStepSquared->size[0];
  for (i = 0; i < m; i++) {
    firstStepSquared->data[i] += r->data[i];
  }

  m = secondStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = secondStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &cj_emlrtRTEI);
  for (i = 0; i < m; i++) {
    b_firstStep->data[i] = secondStep->data[i];
  }

  emxInit_real_T(sp, &secondStepSquared, 1, &kj_emlrtRTEI, true);
  st.site = &ud_emlrtRSI;
  power(&st, b_firstStep, secondStepSquared);
  m = secondStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = secondStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &dj_emlrtRTEI);
  for (i = 0; i < m; i++) {
    b_firstStep->data[i] = secondStep->data[i + secondStep->size[0]];
  }

  emxFree_real_T(&secondStep);
  st.site = &ud_emlrtRSI;
  power(&st, b_firstStep, r);
  if (secondStepSquared->size[0] != r->size[0]) {
    emlrtSizeEqCheck1DR2012b(secondStepSquared->size[0], r->size[0], &j_emlrtECI,
      sp);
  }

  m = secondStepSquared->size[0];
  for (i = 0; i < m; i++) {
    secondStepSquared->data[i] += r->data[i];
  }

  m = longStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = longStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &ej_emlrtRTEI);
  for (i = 0; i < m; i++) {
    b_firstStep->data[i] = longStep->data[i];
  }

  emxInit_real_T(sp, &longStepSquared, 1, &lj_emlrtRTEI, true);
  st.site = &vd_emlrtRSI;
  power(&st, b_firstStep, longStepSquared);
  m = longStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = longStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &fj_emlrtRTEI);
  for (i = 0; i < m; i++) {
    b_firstStep->data[i] = longStep->data[i + longStep->size[0]];
  }

  emxFree_real_T(&longStep);
  st.site = &vd_emlrtRSI;
  power(&st, b_firstStep, r);
  emxFree_real_T(&b_firstStep);
  if (longStepSquared->size[0] != r->size[0]) {
    emlrtSizeEqCheck1DR2012b(longStepSquared->size[0], r->size[0], &k_emlrtECI,
      sp);
  }

  m = longStepSquared->size[0];
  for (i = 0; i < m; i++) {
    longStepSquared->data[i] += r->data[i];
  }

  emxFree_real_T(&r);
  if (firstStepSquared->size[0] != secondStepSquared->size[0]) {
    emlrtSizeEqCheck1DR2012b(firstStepSquared->size[0], secondStepSquared->size
      [0], &l_emlrtECI, sp);
  }

  if (firstStepSquared->size[0] != longStepSquared->size[0]) {
    emlrtSizeEqCheck1DR2012b(firstStepSquared->size[0], longStepSquared->size[0],
      &l_emlrtECI, sp);
  }

  if (firstStepSquared->size[0] != secondStepSquared->size[0]) {
    emlrtSizeEqCheck1DR2012b(firstStepSquared->size[0], secondStepSquared->size
      [0], &m_emlrtECI, sp);
  }

  st.site = &xd_emlrtRSI;
  i = longStepSquared->size[0];
  longStepSquared->size[0] = firstStepSquared->size[0];
  emxEnsureCapacity_real_T(&st, longStepSquared, i, &gj_emlrtRTEI);
  m = firstStepSquared->size[0];
  for (i = 0; i < m; i++) {
    longStepSquared->data[i] = ((firstStepSquared->data[i] +
      secondStepSquared->data[i]) - longStepSquared->data[i]) / 2.0;
  }

  b_st.site = &wd_emlrtRSI;
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
    emlrtErrorWithMessageIdR2018a(&b_st, &mb_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  c_st.site = &ee_emlrtRSI;
  m = firstStepSquared->size[0];
  d_st.site = &fe_emlrtRSI;
  overflow = ((1 <= firstStepSquared->size[0]) && (firstStepSquared->size[0] >
    2147483646));
  if (overflow) {
    e_st.site = &nb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (k = 0; k < m; k++) {
    firstStepSquared->data[k] = muDoubleScalarSqrt(firstStepSquared->data[k]);
  }

  varargin_1[0] = longStepSquared->size[0];
  varargin_1[1] = 1.0;
  varargin_2[0] = (uint32_T)firstStepSquared->size[0];
  varargin_2[1] = 1U;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((int32_T)(uint32_T)varargin_1[k] != (int32_T)varargin_2[k]) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  overflow = (int32_T)p;
  if (!overflow) {
    emlrtErrorWithMessageIdR2018a(&st, &lb_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  emxInit_creal_T(&st, &r1, 1, &hj_emlrtRTEI, true);
  i = r1->size[0];
  r1->size[0] = longStepSquared->size[0];
  emxEnsureCapacity_creal_T(sp, r1, i, &hj_emlrtRTEI);
  m = longStepSquared->size[0];
  for (i = 0; i < m; i++) {
    r1->data[i].re = longStepSquared->data[i] / firstStepSquared->data[i];
    r1->data[i].im = 0.0;
  }

  emxFree_real_T(&longStepSquared);
  emxFree_real_T(&firstStepSquared);
  st.site = &yd_emlrtRSI;
  b_acos(&st, r1);
  i = cornerAngle->size[0];
  cornerAngle->size[0] = r1->size[0];
  emxEnsureCapacity_real_T(sp, cornerAngle, i, &ij_emlrtRTEI);
  m = r1->size[0];
  for (i = 0; i < m; i++) {
    cornerAngle->data[i] = r1->data[i].re;
  }

  emxFree_creal_T(&r1);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void increaseSampling(const emlrtStack *sp, emxArray_real_T *dataPoints,
  const emxArray_boolean_T *segmentsToSplit, const emxArray_real_T *sldProfile)
{
  int32_T input_sizes_idx_0;
  int32_T i;
  int32_T trueCount;
  int32_T b_i;
  emxArray_real_T *newDataPoints;
  int32_T b_input_sizes_idx_0;
  emxArray_boolean_T *r;
  emxArray_boolean_T *r1;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_int32_T *r4;
  emxArray_int32_T *r5;
  emxArray_real_T *r6;
  emxArray_real_T *r7;
  emxArray_real_T *b_dataPoints;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 13U, 5U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 19U);

  /*  increaseSampling increase the sampling of an input function */
  input_sizes_idx_0 = segmentsToSplit->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    if (segmentsToSplit->data[i]) {
      b_i = i + 1;
      if ((b_i < 1) || (b_i > segmentsToSplit->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_i, 1, segmentsToSplit->size[0],
          &vq_emlrtBCI, sp);
      }
    }
  }

  input_sizes_idx_0 = segmentsToSplit->size[0];
  trueCount = 0;
  for (i = 0; i < input_sizes_idx_0; i++) {
    if (segmentsToSplit->data[i]) {
      trueCount++;
    }
  }

  emxInit_real_T(sp, &newDataPoints, 2, &qo_emlrtRTEI, true);
  b_i = newDataPoints->size[0] * newDataPoints->size[1];
  newDataPoints->size[0] = trueCount;
  newDataPoints->size[1] = 2;
  emxEnsureCapacity_real_T(sp, newDataPoints, b_i, &qo_emlrtRTEI);
  b_input_sizes_idx_0 = trueCount << 1;
  for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
    newDataPoints->data[b_i] = 0.0;
  }

  emxInit_boolean_T(sp, &r, 1, &ro_emlrtRTEI, true);
  b_i = r->size[0];
  r->size[0] = segmentsToSplit->size[0] + 1;
  emxEnsureCapacity_boolean_T(sp, r, b_i, &ro_emlrtRTEI);
  b_input_sizes_idx_0 = segmentsToSplit->size[0];
  for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
    r->data[b_i] = segmentsToSplit->data[b_i];
  }

  r->data[segmentsToSplit->size[0]] = false;
  input_sizes_idx_0 = r->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    if (r->data[i]) {
      b_i = dataPoints->size[0];
      b_input_sizes_idx_0 = i + 1;
      if ((b_input_sizes_idx_0 < 1) || (b_input_sizes_idx_0 > b_i)) {
        emlrtDynamicBoundsCheckR2012b(b_input_sizes_idx_0, 1, b_i, &wq_emlrtBCI,
          sp);
      }
    }
  }

  emxInit_boolean_T(sp, &r1, 1, &so_emlrtRTEI, true);
  b_i = r1->size[0];
  r1->size[0] = segmentsToSplit->size[0] + 1;
  emxEnsureCapacity_boolean_T(sp, r1, b_i, &so_emlrtRTEI);
  r1->data[0] = false;
  b_input_sizes_idx_0 = segmentsToSplit->size[0];
  for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
    r1->data[b_i + 1] = segmentsToSplit->data[b_i];
  }

  input_sizes_idx_0 = r1->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    if (r1->data[i]) {
      b_i = dataPoints->size[0];
      b_input_sizes_idx_0 = i + 1;
      if ((b_input_sizes_idx_0 < 1) || (b_input_sizes_idx_0 > b_i)) {
        emlrtDynamicBoundsCheckR2012b(b_input_sizes_idx_0, 1, b_i, &xq_emlrtBCI,
          sp);
      }
    }
  }

  input_sizes_idx_0 = r->size[0] - 1;
  b_input_sizes_idx_0 = 0;
  for (i = 0; i <= input_sizes_idx_0; i++) {
    if (r->data[i]) {
      b_input_sizes_idx_0++;
    }
  }

  emxInit_int32_T(sp, &r2, 1, &ro_emlrtRTEI, true);
  b_i = r2->size[0];
  r2->size[0] = b_input_sizes_idx_0;
  emxEnsureCapacity_int32_T(sp, r2, b_i, &to_emlrtRTEI);
  b_input_sizes_idx_0 = 0;
  for (i = 0; i <= input_sizes_idx_0; i++) {
    if (r->data[i]) {
      r2->data[b_input_sizes_idx_0] = i + 1;
      b_input_sizes_idx_0++;
    }
  }

  input_sizes_idx_0 = r1->size[0] - 1;
  b_input_sizes_idx_0 = 0;
  for (i = 0; i <= input_sizes_idx_0; i++) {
    if (r1->data[i]) {
      b_input_sizes_idx_0++;
    }
  }

  emxInit_int32_T(sp, &r3, 1, &so_emlrtRTEI, true);
  b_i = r3->size[0];
  r3->size[0] = b_input_sizes_idx_0;
  emxEnsureCapacity_int32_T(sp, r3, b_i, &to_emlrtRTEI);
  b_input_sizes_idx_0 = 0;
  for (i = 0; i <= input_sizes_idx_0; i++) {
    if (r1->data[i]) {
      r3->data[b_input_sizes_idx_0] = i + 1;
      b_input_sizes_idx_0++;
    }
  }

  if (r2->size[0] != r3->size[0]) {
    emlrtSizeEqCheck1DR2012b(r2->size[0], r3->size[0], &bb_emlrtECI, sp);
  }

  emxFree_int32_T(&r3);
  emxFree_int32_T(&r2);
  input_sizes_idx_0 = r->size[0] - 1;
  b_input_sizes_idx_0 = 0;
  for (i = 0; i <= input_sizes_idx_0; i++) {
    if (r->data[i]) {
      b_input_sizes_idx_0++;
    }
  }

  emxInit_int32_T(sp, &r4, 1, &ro_emlrtRTEI, true);
  b_i = r4->size[0];
  r4->size[0] = b_input_sizes_idx_0;
  emxEnsureCapacity_int32_T(sp, r4, b_i, &to_emlrtRTEI);
  b_input_sizes_idx_0 = 0;
  for (i = 0; i <= input_sizes_idx_0; i++) {
    if (r->data[i]) {
      r4->data[b_input_sizes_idx_0] = i + 1;
      b_input_sizes_idx_0++;
    }
  }

  emxFree_boolean_T(&r);
  input_sizes_idx_0 = r1->size[0] - 1;
  b_input_sizes_idx_0 = 0;
  for (i = 0; i <= input_sizes_idx_0; i++) {
    if (r1->data[i]) {
      b_input_sizes_idx_0++;
    }
  }

  emxInit_int32_T(sp, &r5, 1, &so_emlrtRTEI, true);
  b_i = r5->size[0];
  r5->size[0] = b_input_sizes_idx_0;
  emxEnsureCapacity_int32_T(sp, r5, b_i, &to_emlrtRTEI);
  b_input_sizes_idx_0 = 0;
  for (i = 0; i <= input_sizes_idx_0; i++) {
    if (r1->data[i]) {
      r5->data[b_input_sizes_idx_0] = i + 1;
      b_input_sizes_idx_0++;
    }
  }

  emxFree_boolean_T(&r1);
  emxInit_real_T(sp, &r6, 1, &to_emlrtRTEI, true);
  b_i = r6->size[0];
  r6->size[0] = r4->size[0];
  emxEnsureCapacity_real_T(sp, r6, b_i, &uo_emlrtRTEI);
  b_input_sizes_idx_0 = r4->size[0];
  for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
    r6->data[b_i] = 0.5 * (dataPoints->data[r4->data[b_i] - 1] +
      dataPoints->data[r5->data[b_i] - 1]);
  }

  emxFree_int32_T(&r5);
  emxFree_int32_T(&r4);
  emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &r6->size[0], 1, &cb_emlrtECI, sp);
  b_input_sizes_idx_0 = r6->size[0];
  for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
    newDataPoints->data[b_i] = r6->data[b_i];
  }

  emxInit_real_T(sp, &r7, 1, &to_emlrtRTEI, true);
  st.site = &je_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 13U, 1U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 14U);

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
  b_i = r7->size[0];
  r7->size[0] = newDataPoints->size[0];
  emxEnsureCapacity_real_T(&st, r7, b_i, &vo_emlrtRTEI);

  /*  if vectorizable */
  /*    % For uniformity reasons, transform the 'x' array into a column vector. */
  /*    % In this way it does not matter if it is given as a column or a row */
  /*    % vector. */
  /*    [newValues{:}] = func(x(:)); */
  /*    y = cell2mat(newValues); */
  /*  else */
  b_i = newDataPoints->size[0] - 1;
  for (i = 0; i <= b_i; i++) {
    covrtLogFor(&emlrtCoverageInstance, 13U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 15U);

    /*  Remove cell array so no need for cell2mat */
    /*  which won't compile - AVH */
    /* [newValues{:}] = func(x(i)); */
    /* y(i,:) = cell2mat(newValues); */
    b_input_sizes_idx_0 = i + 1;
    if ((b_input_sizes_idx_0 < 1) || (b_input_sizes_idx_0 > newDataPoints->size
         [0])) {
      emlrtDynamicBoundsCheckR2012b(b_input_sizes_idx_0, 1, newDataPoints->size
        [0], &yq_emlrtBCI, &st);
    }

    b_st.site = &bd_emlrtRSI;
    sldFunc(&b_st, newDataPoints->data[b_input_sizes_idx_0 - 1], sldProfile, r6);
    if (1 != r6->size[0]) {
      emlrtSubAssignSizeCheck1dR2017a(1, r6->size[0], &g_emlrtECI, &st);
    }

    b_input_sizes_idx_0 = i + 1;
    if ((b_input_sizes_idx_0 < 1) || (b_input_sizes_idx_0 > r7->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_input_sizes_idx_0, 1, r7->size[0],
        &ar_emlrtBCI, &st);
    }

    r7->data[b_input_sizes_idx_0 - 1] = r6->data[0];
  }

  emxFree_real_T(&r6);
  covrtLogFor(&emlrtCoverageInstance, 13U, 0U, 1, 0);

  /* end */
  emlrtSubAssignSizeCheckR2012b(&newDataPoints->size[0], 1, &r7->size[0], 1,
    &db_emlrtECI, sp);
  b_input_sizes_idx_0 = r7->size[0];
  for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
    newDataPoints->data[b_i + newDataPoints->size[0]] = r7->data[b_i];
  }

  emxFree_real_T(&r7);

  /*  For simplicity append the new points at the end and then sort. */
  st.site = &ke_emlrtRSI;
  b_st.site = &le_emlrtRSI;
  if (dataPoints->size[0] != 0) {
    b_input_sizes_idx_0 = dataPoints->size[0];
  } else {
    b_input_sizes_idx_0 = 0;
  }

  if (newDataPoints->size[0] != 0) {
    input_sizes_idx_0 = newDataPoints->size[0];
  } else {
    input_sizes_idx_0 = 0;
  }

  emxInit_real_T(&b_st, &b_dataPoints, 2, &wo_emlrtRTEI, true);
  b_i = b_dataPoints->size[0] * b_dataPoints->size[1];
  b_dataPoints->size[0] = b_input_sizes_idx_0 + input_sizes_idx_0;
  b_dataPoints->size[1] = 2;
  emxEnsureCapacity_real_T(sp, b_dataPoints, b_i, &wo_emlrtRTEI);
  for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
    b_dataPoints->data[b_i] = dataPoints->data[b_i];
  }

  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    b_dataPoints->data[b_i + b_input_sizes_idx_0] = newDataPoints->data[b_i];
  }

  for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
    b_dataPoints->data[b_i + b_dataPoints->size[0]] = dataPoints->data[b_i +
      dataPoints->size[0]];
  }

  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    b_dataPoints->data[(b_i + b_input_sizes_idx_0) + b_dataPoints->size[0]] =
      newDataPoints->data[b_i + newDataPoints->size[0]];
  }

  emxFree_real_T(&newDataPoints);
  b_i = dataPoints->size[0] * dataPoints->size[1];
  dataPoints->size[0] = b_dataPoints->size[0];
  dataPoints->size[1] = 2;
  emxEnsureCapacity_real_T(sp, dataPoints, b_i, &to_emlrtRTEI);
  b_input_sizes_idx_0 = b_dataPoints->size[0];
  for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
    dataPoints->data[b_i] = b_dataPoints->data[b_i];
  }

  for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
    dataPoints->data[b_i + dataPoints->size[0]] = b_dataPoints->data[b_i +
      b_dataPoints->size[0]];
  }

  emxFree_real_T(&b_dataPoints);
  st.site = &ke_emlrtRSI;
  sortrows(&st, dataPoints);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void adaptive(const emlrtStack *sp, const emxArray_real_T *sldProfile, const
              real_T startDomain[2], cell_19 *out)
{
  real_T newDomain[50];
  emxArray_real_T *cornerAngle;
  int32_T i;
  int32_T b_i;
  emxArray_real_T *dataPoints;
  real_T b_newDomain[100];
  real_T hiVal[50];
  int32_T nRefinements;
  emxArray_boolean_T *sharpCorners;
  emxArray_boolean_T *segmentsToSplit;
  emxArray_boolean_T *r;
  emxArray_real_T *b_dataPoints;
  int32_T exitg1;
  boolean_T overflow;
  real_T maxval[2];
  real_T b;
  real_T minval_idx_0;
  real_T minval_idx_1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
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
  covrtLogFcn(&emlrtCoverageInstance, 13U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 0U);

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
  /*  if mod(nExtraArgIn,2)==1 */
  /*    error('adaptiveFunctionEvaluation:ArgChk', ... */
  /*      'At least a key or a value is missing in the key-value arguments list.'); */
  /*  end */
  /*  while n < nExtraArgIn */
  /*    switch lower(varargin{n})   */
  /*      case 'minangle' */
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
  covrtLogIf(&emlrtCoverageInstance, 13U, 0U, 0, false);

  /*  Initial function evaluation */
  /*  if initialDomain only contains the start and the end points, create a new */
  /*  array with 'nPoints' points. */
  covrtLogIf(&emlrtCoverageInstance, 13U, 0U, 1, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 2U);
  linspace(startDomain[0], startDomain[1], newDomain);
  covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 3U);

  /*  Normalize the input function: This step allows to use the same syntax for */
  /*  functions with single or multiple output parameters. */
  /*  Remove this syntax for compile - AVH */
  /* func = @(x) normalizeFunction(x,sldProfile,vectorizable); */
  /*  Evaluate the input function on the initial set of points. */
  st.site = &vc_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 13U, 1U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 14U);

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
  /*  if vectorizable */
  /*    % For uniformity reasons, transform the 'x' array into a column vector. */
  /*    % In this way it does not matter if it is given as a column or a row */
  /*    % vector. */
  /*    [newValues{:}] = func(x(:)); */
  /*    y = cell2mat(newValues); */
  /*  else */
  emxInit_real_T(&st, &cornerAngle, 1, &fi_emlrtRTEI, true);
  for (i = 0; i < 50; i++) {
    covrtLogFor(&emlrtCoverageInstance, 13U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 15U);

    /*  Remove cell array so no need for cell2mat */
    /*  which won't compile - AVH */
    /* [newValues{:}] = func(x(i)); */
    /* y(i,:) = cell2mat(newValues); */
    b_st.site = &bd_emlrtRSI;
    sldFunc(&b_st, newDomain[i], sldProfile, cornerAngle);
    if (1 != cornerAngle->size[0]) {
      emlrtSubAssignSizeCheck1dR2017a(1, cornerAngle->size[0], &g_emlrtECI, &st);
    }

    hiVal[i] = cornerAngle->data[0];
  }

  covrtLogFor(&emlrtCoverageInstance, 13U, 0U, 1, 0);

  /* end */
  /* dataPoints = [initialDomain(:), func(initialDomain(:))]; */
  for (b_i = 0; b_i < 50; b_i++) {
    b_newDomain[b_i] = newDomain[b_i];
    b_newDomain[b_i + 50] = hiVal[b_i];
  }

  emxInit_real_T(sp, &dataPoints, 2, &xh_emlrtRTEI, true);
  b_i = dataPoints->size[0] * dataPoints->size[1];
  dataPoints->size[0] = 50;
  dataPoints->size[1] = 2;
  emxEnsureCapacity_real_T(sp, dataPoints, b_i, &xh_emlrtRTEI);
  for (b_i = 0; b_i < 100; b_i++) {
    dataPoints->data[b_i] = b_newDomain[b_i];
  }

  /*  Iterative function refinement */
  /*  if displayWaitbar */
  /*    refinementWaitbar = waitbar(0,['Evaluating function ',func2str(func)],... */
  /*      'CreateCancelBtn','setappdata(gcbf,''canceling'',true)'); */
  /*    setappdata(refinementWaitbar,'canceling',false) */
  /*  end */
  nRefinements = 0;
  emxInit_boolean_T(sp, &sharpCorners, 1, &bi_emlrtRTEI, true);
  emxInit_boolean_T(sp, &segmentsToSplit, 1, &gi_emlrtRTEI, true);
  emxInit_boolean_T(sp, &r, 1, &hi_emlrtRTEI, true);
  emxInit_real_T(sp, &b_dataPoints, 2, &ai_emlrtRTEI, true);
  do {
    exitg1 = 0;
    if (nRefinements < 10) {
      covrtLogFor(&emlrtCoverageInstance, 13U, 0U, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 4U);

      /*  calculate the box which encloses the current data points: */
      st.site = &wc_emlrtRSI;
      b_st.site = &mc_emlrtRSI;
      c_st.site = &nc_emlrtRSI;
      d_st.site = &oc_emlrtRSI;
      if (dataPoints->size[0] == 1) {
        emlrtErrorWithMessageIdR2018a(&d_st, &ib_emlrtRTEI,
          "Coder:toolbox:autoDimIncompatibility",
          "Coder:toolbox:autoDimIncompatibility", 0);
      }

      if (dataPoints->size[0] < 1) {
        emlrtErrorWithMessageIdR2018a(&d_st, &jb_emlrtRTEI,
          "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }

      e_st.site = &jd_emlrtRSI;
      f_st.site = &kd_emlrtRSI;
      g_st.site = &ld_emlrtRSI;
      b_i = dataPoints->size[0];
      overflow = ((2 <= dataPoints->size[0]) && (dataPoints->size[0] >
        2147483646));
      maxval[0] = dataPoints->data[0];
      h_st.site = &md_emlrtRSI;
      if (overflow) {
        i_st.site = &nb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (i = 2; i <= b_i; i++) {
        b = dataPoints->data[i - 1];
        overflow = ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN(maxval[0])
          || (maxval[0] < b)));
        if (overflow) {
          maxval[0] = b;
        }
      }

      maxval[1] = dataPoints->data[dataPoints->size[0]];
      h_st.site = &md_emlrtRSI;
      for (i = 2; i <= b_i; i++) {
        b = dataPoints->data[(i + dataPoints->size[0]) - 1];
        overflow = ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN(maxval[1])
          || (maxval[1] < b)));
        if (overflow) {
          maxval[1] = b;
        }
      }

      st.site = &wc_emlrtRSI;
      b_st.site = &nd_emlrtRSI;
      c_st.site = &od_emlrtRSI;
      d_st.site = &pd_emlrtRSI;
      if (dataPoints->size[0] == 1) {
        emlrtErrorWithMessageIdR2018a(&d_st, &ib_emlrtRTEI,
          "Coder:toolbox:autoDimIncompatibility",
          "Coder:toolbox:autoDimIncompatibility", 0);
      }

      if (dataPoints->size[0] < 1) {
        emlrtErrorWithMessageIdR2018a(&d_st, &jb_emlrtRTEI,
          "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }

      e_st.site = &jd_emlrtRSI;
      f_st.site = &kd_emlrtRSI;
      g_st.site = &ld_emlrtRSI;
      b_i = dataPoints->size[0];
      overflow = ((2 <= dataPoints->size[0]) && (dataPoints->size[0] >
        2147483646));
      minval_idx_0 = dataPoints->data[0];
      h_st.site = &md_emlrtRSI;
      if (overflow) {
        i_st.site = &nb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (i = 2; i <= b_i; i++) {
        b = dataPoints->data[i - 1];
        overflow = ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN
          (minval_idx_0) || (minval_idx_0 > b)));
        if (overflow) {
          minval_idx_0 = b;
        }
      }

      minval_idx_1 = dataPoints->data[dataPoints->size[0]];
      h_st.site = &md_emlrtRSI;
      for (i = 2; i <= b_i; i++) {
        b = dataPoints->data[(i + dataPoints->size[0]) - 1];
        overflow = ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN
          (minval_idx_1) || (minval_idx_1 > b)));
        if (overflow) {
          minval_idx_1 = b;
        }
      }

      /*  Each point is considered as the central corner of the triangle formed */
      /*  with its left and right hand side neighbours. The first and the last */
      /*  points are not the central corner of any triangle, so for N points */
      /*  there are only N-2 triangles. */
      if (!((real_T)dataPoints->size[0] - 2.0 >= 0.0)) {
        emlrtNonNegativeCheckR2012b((real_T)dataPoints->size[0] - 2.0,
          &hb_emlrtDCI, sp);
      }

      covrtLogIf(&emlrtCoverageInstance, 13U, 0U, 2, false);
      covrtLogIf(&emlrtCoverageInstance, 13U, 0U, 3, true);
      covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 6U);
      i = dataPoints->size[0];
      b_i = b_dataPoints->size[0] * b_dataPoints->size[1];
      b_dataPoints->size[0] = dataPoints->size[0];
      b_dataPoints->size[1] = 2;
      emxEnsureCapacity_real_T(sp, b_dataPoints, b_i, &ai_emlrtRTEI);
      for (b_i = 0; b_i < i; b_i++) {
        b_dataPoints->data[b_i] = dataPoints->data[b_i];
      }

      maxval[0] -= minval_idx_0;
      for (b_i = 0; b_i < i; b_i++) {
        b_dataPoints->data[b_i + b_dataPoints->size[0]] = dataPoints->data[b_i +
          dataPoints->size[0]];
      }

      maxval[1] -= minval_idx_1;
      st.site = &xc_emlrtRSI;
      calculateCentralAngles(&st, b_dataPoints, maxval, cornerAngle);
      b_i = sharpCorners->size[0];
      sharpCorners->size[0] = cornerAngle->size[0];
      emxEnsureCapacity_boolean_T(sp, sharpCorners, b_i, &bi_emlrtRTEI);
      i = cornerAngle->size[0];
      for (b_i = 0; b_i < i; b_i++) {
        sharpCorners->data[b_i] = (cornerAngle->data[b_i] < 2.1991148575128552);
      }

      b_i = dataPoints->size[0] - 2;
      if (b_i != sharpCorners->size[0]) {
        emlrtSizeEqCheck1DR2012b(b_i, sharpCorners->size[0], &e_emlrtECI, sp);
      }

      b_i = sharpCorners->size[0];
      sharpCorners->size[0] = dataPoints->size[0] - 2;
      emxEnsureCapacity_boolean_T(sp, sharpCorners, b_i, &ci_emlrtRTEI);
      covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 7U);

      /*  For N points there are N-2 triangles and N-1 triangle sides. Each */
      /*  triangle side is a segment, which can be split or not depending on the */
      /*  refinement parameters. */
      b_i = segmentsToSplit->size[0];
      segmentsToSplit->size[0] = dataPoints->size[0] - 1;
      emxEnsureCapacity_boolean_T(sp, segmentsToSplit, b_i, &di_emlrtRTEI);
      i = dataPoints->size[0] - 2;
      for (b_i = 0; b_i < i; b_i++) {
        segmentsToSplit->data[b_i] = sharpCorners->data[b_i];
      }

      segmentsToSplit->data[dataPoints->size[0] - 2] = false;
      b_i = r->size[0];
      r->size[0] = dataPoints->size[0] - 1;
      emxEnsureCapacity_boolean_T(sp, r, b_i, &ei_emlrtRTEI);
      r->data[0] = false;
      i = dataPoints->size[0] - 2;
      for (b_i = 0; b_i < i; b_i++) {
        r->data[b_i + 1] = sharpCorners->data[b_i];
      }

      if (segmentsToSplit->size[0] != r->size[0]) {
        emlrtSizeEqCheck1DR2012b(segmentsToSplit->size[0], r->size[0],
          &f_emlrtECI, sp);
      }

      i = segmentsToSplit->size[0];
      for (b_i = 0; b_i < i; b_i++) {
        segmentsToSplit->data[b_i] = (segmentsToSplit->data[b_i] || r->data[b_i]);
      }

      covrtLogIf(&emlrtCoverageInstance, 13U, 0U, 4, false);
      covrtLogIf(&emlrtCoverageInstance, 13U, 0U, 5, false);
      st.site = &yc_emlrtRSI;
      if (covrtLogIf(&emlrtCoverageInstance, 13U, 0U, 6, any(&st,
            segmentsToSplit))) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 10U);
        st.site = &ad_emlrtRSI;
        increaseSampling(&st, dataPoints, segmentsToSplit, sldProfile);

        /*  Removed waitbar for compile - AVH */
        /*    if displayWaitbar */
        /*      if getappdata(refinementWaitbar,'canceling'), break; end */
        /*      waitbar(nRefinements/maxRefinements,refinementWaitbar); */
        /*    end */
        nRefinements++;
      } else {
        covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 11U);
        exitg1 = 1;
      }
    } else {
      covrtLogFor(&emlrtCoverageInstance, 13U, 0U, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxFree_real_T(&b_dataPoints);
  emxFree_boolean_T(&r);
  emxFree_boolean_T(&segmentsToSplit);
  emxFree_boolean_T(&sharpCorners);
  emxFree_real_T(&cornerAngle);

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
  covrtLogIf(&emlrtCoverageInstance, 13U, 0U, 7, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 12U);
  b_i = out->f1->size[0] * out->f1->size[1];
  out->f1->size[0] = dataPoints->size[0];
  out->f1->size[1] = 2;
  emxEnsureCapacity_real_T(sp, out->f1, b_i, &yh_emlrtRTEI);
  i = dataPoints->size[0] * dataPoints->size[1];
  for (b_i = 0; b_i < i; b_i++) {
    out->f1->data[b_i] = dataPoints->data[b_i];
  }

  emxFree_real_T(&dataPoints);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (adaptive.c) */
