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
#include "dev_custlay_paraContrasts_data.h"
#include "dev_custlay_paraContrasts_emxutil.h"
#include "dev_custlay_paraContrasts_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "find.h"
#include "linspace.h"
#include "power.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sortrows.h"
#include "sqrt.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo hd_emlrtRSI = {
    241,            /* lineNo */
    "adaptive_new", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo id_emlrtRSI = {
    252,            /* lineNo */
    "adaptive_new", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo jd_emlrtRSI = {
    255,            /* lineNo */
    "adaptive_new", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo kd_emlrtRSI = {
    267,            /* lineNo */
    "adaptive_new", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo ld_emlrtRSI = {
    281,            /* lineNo */
    "adaptive_new", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo md_emlrtRSI = {
    304,            /* lineNo */
    "adaptive_new", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo nd_emlrtRSI = {
    305,            /* lineNo */
    "adaptive_new", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo od_emlrtRSI = {
    376,                 /* lineNo */
    "normalizeFunction", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo pd_emlrtRSI = {
    24,        /* lineNo */
    "sldFunc", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m" /* pathName */
};

static emlrtRSInfo qd_emlrtRSI = {
    29,        /* lineNo */
    "sldFunc", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m" /* pathName */
};

static emlrtRSInfo rd_emlrtRSI = {
    30,        /* lineNo */
    "sldFunc", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m" /* pathName */
};

static emlrtRSInfo wd_emlrtRSI = {
    197,             /* lineNo */
    "unaryMinOrMax", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo xd_emlrtRSI = {
    288,                     /* lineNo */
    "unaryMinOrMaxDispatch", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo yd_emlrtRSI = {
    356,          /* lineNo */
    "minOrMax2D", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo ae_emlrtRSI = {
    438,                         /* lineNo */
    "minOrMax2DColumnMajorDim1", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo be_emlrtRSI = {
    15,    /* lineNo */
    "min", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/min.m" /* pathName
                                                                            */
};

static emlrtRSInfo ce_emlrtRSI = {
    46,         /* lineNo */
    "minOrMax", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "minOrMax.m" /* pathName */
};

static emlrtRSInfo de_emlrtRSI = {
    92,        /* lineNo */
    "minimum", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "minOrMax.m" /* pathName */
};

static emlrtRSInfo ee_emlrtRSI = {
    398,                      /* lineNo */
    "calculateCentralAngles", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo fe_emlrtRSI = {
    399,                      /* lineNo */
    "calculateCentralAngles", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo ge_emlrtRSI = {
    401,                      /* lineNo */
    "calculateCentralAngles", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo he_emlrtRSI = {
    403,                      /* lineNo */
    "calculateCentralAngles", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo ie_emlrtRSI = {
    404,                      /* lineNo */
    "calculateCentralAngles", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo je_emlrtRSI = {
    405,                      /* lineNo */
    "calculateCentralAngles", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo ke_emlrtRSI = {
    408,                      /* lineNo */
    "calculateCentralAngles", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo le_emlrtRSI = {
    407,                      /* lineNo */
    "calculateCentralAngles", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo me_emlrtRSI = {
    409,                      /* lineNo */
    "calculateCentralAngles", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo df_emlrtRSI = {
    431,                /* lineNo */
    "increaseSampling", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo ef_emlrtRSI = {
    433,                /* lineNo */
    "increaseSampling", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo
    ff_emlrtRSI =
        {
            24,    /* lineNo */
            "cat", /* fcnName */
            "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
            "cat.m" /* pathName */
};

static emlrtECInfo k_emlrtECI = {
    -1,             /* nDims */
    283,            /* lineNo */
    25,             /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtECInfo l_emlrtECI = {
    -1,             /* nDims */
    289,            /* lineNo */
    21,             /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    26,              /* lineNo */
    27,              /* colNo */
    "unaryMinOrMax", /* fName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "unaryMinOrMax.m" /* pName */
};

static emlrtRTEInfo n_emlrtRTEI = {
    124,             /* lineNo */
    27,              /* colNo */
    "unaryMinOrMax", /* fName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "unaryMinOrMax.m" /* pName */
};

static emlrtECInfo m_emlrtECI = {
    -1,                 /* nDims */
    429,                /* lineNo */
    29,                 /* colNo */
    "increaseSampling", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtECInfo n_emlrtECI = {
    -1,                 /* nDims */
    429,                /* lineNo */
    1,                  /* colNo */
    "increaseSampling", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtECInfo o_emlrtECI = {
    -1,                 /* nDims */
    431,                /* lineNo */
    1,                  /* colNo */
    "increaseSampling", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtBCInfo wd_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    425,                /* lineNo */
    39,                 /* colNo */
    "segmentsToSplit",  /* aName */
    "increaseSampling", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    429,                /* lineNo */
    40,                 /* colNo */
    "dataPoints",       /* aName */
    "increaseSampling", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo yd_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    430,                /* lineNo */
    14,                 /* colNo */
    "dataPoints",       /* aName */
    "increaseSampling", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    376,                 /* lineNo */
    22,                  /* colNo */
    "x",                 /* aName */
    "normalizeFunction", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtECInfo p_emlrtECI = {
    -1,                  /* nDims */
    376,                 /* lineNo */
    5,                   /* colNo */
    "normalizeFunction", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtBCInfo be_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    31,          /* lineNo */
    23,          /* colNo */
    "belowVals", /* aName */
    "sldFunc",   /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ce_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    32,          /* lineNo */
    23,          /* colNo */
    "aboveVals", /* aName */
    "sldFunc",   /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo de_emlrtBCI = {
    -1,        /* iFirst */
    -1,        /* iLast */
    34,        /* lineNo */
    18,        /* colNo */
    "rho",     /* aName */
    "sldFunc", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ee_emlrtBCI = {
    -1,        /* iFirst */
    -1,        /* iLast */
    35,        /* lineNo */
    18,        /* colNo */
    "rho",     /* aName */
    "sldFunc", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo fe_emlrtBCI = {
    -1,        /* iFirst */
    -1,        /* iLast */
    38,        /* lineNo */
    26,        /* colNo */
    "z",       /* aName */
    "sldFunc", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ge_emlrtBCI = {
    -1,        /* iFirst */
    -1,        /* iLast */
    42,        /* lineNo */
    20,        /* colNo */
    "z",       /* aName */
    "sldFunc", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo he_emlrtBCI = {
    -1,        /* iFirst */
    -1,        /* iLast */
    27,        /* lineNo */
    18,        /* colNo */
    "rho",     /* aName */
    "sldFunc", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ie_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    376,                 /* lineNo */
    5,                   /* colNo */
    "y",                 /* aName */
    "normalizeFunction", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtECInfo q_emlrtECI = {
    2,                        /* nDims */
    398,                      /* lineNo */
    3,                        /* colNo */
    "calculateCentralAngles", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtECInfo r_emlrtECI = {
    -1,                       /* nDims */
    403,                      /* lineNo */
    21,                       /* colNo */
    "calculateCentralAngles", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtECInfo s_emlrtECI = {
    -1,                       /* nDims */
    404,                      /* lineNo */
    21,                       /* colNo */
    "calculateCentralAngles", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtECInfo t_emlrtECI = {
    -1,                       /* nDims */
    405,                      /* lineNo */
    21,                       /* colNo */
    "calculateCentralAngles", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtECInfo u_emlrtECI = {
    -1,                       /* nDims */
    407,                      /* lineNo */
    4,                        /* colNo */
    "calculateCentralAngles", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtECInfo v_emlrtECI = {
    -1,                       /* nDims */
    408,                      /* lineNo */
    8,                        /* colNo */
    "calculateCentralAngles", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtBCInfo je_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    386,                       /* lineNo */
    20,                        /* colNo */
    "XYdata",                  /* aName */
    "calculateTrianglesSides", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo ke_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    386,                       /* lineNo */
    22,                        /* colNo */
    "XYdata",                  /* aName */
    "calculateTrianglesSides", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo le_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    386,                       /* lineNo */
    40,                        /* colNo */
    "XYdata",                  /* aName */
    "calculateTrianglesSides", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo me_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    386,                       /* lineNo */
    42,                        /* colNo */
    "XYdata",                  /* aName */
    "calculateTrianglesSides", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtECInfo w_emlrtECI = {
    2,                         /* nDims */
    386,                       /* lineNo */
    13,                        /* colNo */
    "calculateTrianglesSides", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtBCInfo ne_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    387,                       /* lineNo */
    41,                        /* colNo */
    "XYdata",                  /* aName */
    "calculateTrianglesSides", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo oe_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    387,                       /* lineNo */
    43,                        /* colNo */
    "XYdata",                  /* aName */
    "calculateTrianglesSides", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtECInfo x_emlrtECI = {
    2,                         /* nDims */
    387,                       /* lineNo */
    14,                        /* colNo */
    "calculateTrianglesSides", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtBCInfo pe_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    388,                       /* lineNo */
    40,                        /* colNo */
    "XYdata",                  /* aName */
    "calculateTrianglesSides", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo qe_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    388,                       /* lineNo */
    42,                        /* colNo */
    "XYdata",                  /* aName */
    "calculateTrianglesSides", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtECInfo y_emlrtECI = {
    2,                         /* nDims */
    388,                       /* lineNo */
    13,                        /* colNo */
    "calculateTrianglesSides", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo ud_emlrtRTEI = {
    241,            /* lineNo */
    3,              /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo vd_emlrtRTEI = {
    255,            /* lineNo */
    1,              /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo wd_emlrtRTEI = {
    334,            /* lineNo */
    2,              /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo xd_emlrtRTEI = {
    281,            /* lineNo */
    42,             /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo yd_emlrtRTEI = {
    282,            /* lineNo */
    5,              /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo ae_emlrtRTEI = {
    283,            /* lineNo */
    5,              /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo be_emlrtRTEI = {
    289,            /* lineNo */
    21,             /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo ce_emlrtRTEI = {
    289,            /* lineNo */
    50,             /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo de_emlrtRTEI = {
    426,            /* lineNo */
    1,              /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo ee_emlrtRTEI = {
    429,            /* lineNo */
    40,             /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo fe_emlrtRTEI = {
    430,            /* lineNo */
    14,             /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo ge_emlrtRTEI = {
    305,            /* lineNo */
    18,             /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo he_emlrtRTEI = {
    429,            /* lineNo */
    22,             /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo ie_emlrtRTEI = {
    431,            /* lineNo */
    40,             /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo
    je_emlrtRTEI =
        {
            291,   /* lineNo */
            14,    /* colNo */
            "cat", /* fName */
            "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
            "cat.m" /* pName */
};

static emlrtRTEInfo ke_emlrtRTEI = {
    305,            /* lineNo */
    5,              /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo le_emlrtRTEI = {
    252,            /* lineNo */
    1,              /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo me_emlrtRTEI = {
    289,            /* lineNo */
    3,              /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo ne_emlrtRTEI = {
    241,            /* lineNo */
    15,             /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo pe_emlrtRTEI = {
    360,            /* lineNo */
    5,              /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo qe_emlrtRTEI = {
    24,        /* lineNo */
    14,        /* colNo */
    "sldFunc", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m" /* pName */
};

static emlrtRTEInfo re_emlrtRTEI = {
    24,        /* lineNo */
    1,         /* colNo */
    "sldFunc", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m" /* pName */
};

static emlrtRTEInfo se_emlrtRTEI = {
    376,            /* lineNo */
    12,             /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo te_emlrtRTEI = {
    29,        /* lineNo */
    22,        /* colNo */
    "sldFunc", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m" /* pName */
};

static emlrtRTEInfo ue_emlrtRTEI = {
    29,        /* lineNo */
    5,         /* colNo */
    "sldFunc", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m" /* pName */
};

static emlrtRTEInfo ve_emlrtRTEI = {
    30,        /* lineNo */
    22,        /* colNo */
    "sldFunc", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m" /* pName */
};

static emlrtRTEInfo we_emlrtRTEI = {
    30,        /* lineNo */
    5,         /* colNo */
    "sldFunc", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m" /* pName */
};

static emlrtRTEInfo af_emlrtRTEI = {
    398,            /* lineNo */
    3,              /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo bf_emlrtRTEI = {
    403,            /* lineNo */
    21,             /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo cf_emlrtRTEI = {
    403,            /* lineNo */
    42,             /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo df_emlrtRTEI = {
    404,            /* lineNo */
    21,             /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo ef_emlrtRTEI = {
    404,            /* lineNo */
    42,             /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo ff_emlrtRTEI = {
    405,            /* lineNo */
    21,             /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo gf_emlrtRTEI = {
    405,            /* lineNo */
    42,             /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo hf_emlrtRTEI = {
    407,            /* lineNo */
    3,              /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo if_emlrtRTEI = {
    409,            /* lineNo */
    20,             /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo jf_emlrtRTEI = {
    409,            /* lineNo */
    1,              /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo kf_emlrtRTEI = {
    403,            /* lineNo */
    1,              /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo lf_emlrtRTEI = {
    404,            /* lineNo */
    1,              /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo mf_emlrtRTEI = {
    405,            /* lineNo */
    1,              /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo nf_emlrtRTEI = {
    391,            /* lineNo */
    24,             /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo of_emlrtRTEI = {
    398,            /* lineNo */
    13,             /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo qf_emlrtRTEI = {
    386,            /* lineNo */
    1,              /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo rf_emlrtRTEI = {
    387,            /* lineNo */
    1,              /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo sf_emlrtRTEI = {
    388,            /* lineNo */
    1,              /* colNo */
    "adaptive_new", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

/* Function Declarations */
static void calculateCentralAngles(const emlrtStack *sp,
                                   const emxArray_real_T *XYdata,
                                   const real_T dataBoxSize[2],
                                   emxArray_real_T *cornerAngle);

static void calculateTrianglesSides(const emlrtStack *sp,
                                    const emxArray_real_T *XYdata,
                                    emxArray_real_T *firstStep,
                                    emxArray_real_T *secondStep,
                                    emxArray_real_T *longStep);

static void normalizeFunction(const emlrtStack *sp, const emxArray_real_T *x,
                              const emxArray_real_T *sldProfile,
                              emxArray_real_T *y);

/* Function Definitions */
static void calculateCentralAngles(const emlrtStack *sp,
                                   const emxArray_real_T *XYdata,
                                   const real_T dataBoxSize[2],
                                   emxArray_real_T *cornerAngle)
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
  emxArray_real_T *b_y;
  emxArray_real_T *firstStep;
  emxArray_real_T *firstStepSquared;
  emxArray_real_T *longStep;
  emxArray_real_T *longStepSquared;
  emxArray_real_T *r;
  emxArray_real_T *secondStep;
  emxArray_real_T *secondStepSquared;
  emxArray_real_T *y;
  real_T minval[2];
  real_T b;
  int32_T iv[2];
  int32_T z_size[2];
  int32_T b_i;
  int32_T i;
  int32_T j;
  int32_T m;
  boolean_T exitg1;
  boolean_T overflow;
  boolean_T p;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &y, 2, &of_emlrtRTEI, true);
  /*  Calculate the central angle of the triangles formed by data points. */
  /*  For input size NxM, the output size is (N-2)xN, because the first and the
   */
  /*  last point are not the central corner of any triangle. */
  /*  Normalize data, because angles depend on scaling. */
  st.site = &ee_emlrtRSI;
  b_st.site = &ee_emlrtRSI;
  repmat(&b_st, dataBoxSize, XYdata->size[0], y);
  b_st.site = &pe_emlrtRSI;
  c_st.site = &qe_emlrtRSI;
  d_st.site = &re_emlrtRSI;
  e_st.site = &se_emlrtRSI;
  f_st.site = &te_emlrtRSI;
  if (XYdata->size[0] <= y->size[0]) {
    z_size[0] = XYdata->size[0];
  } else {
    z_size[0] = y->size[0];
  }
  z_size[1] = 2;
  p = true;
  overflow = true;
  m = 0;
  exitg1 = false;
  while ((!exitg1) && (m < 2)) {
    if (z_size[m] != XYdata->size[m]) {
      overflow = false;
      exitg1 = true;
    } else {
      m++;
    }
  }
  if (overflow) {
    overflow = true;
    m = 0;
    exitg1 = false;
    while ((!exitg1) && (m < 2)) {
      if (z_size[m] != y->size[m]) {
        overflow = false;
        exitg1 = true;
      } else {
        m++;
      }
    }
    if (!overflow) {
      p = false;
    }
  } else {
    p = false;
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&f_st, &q_emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  f_st.site = &ue_emlrtRSI;
  g_st.site = &ve_emlrtRSI;
  if (XYdata->size[0] <= y->size[0]) {
    z_size[0] = XYdata->size[0];
  } else {
    z_size[0] = y->size[0];
  }
  z_size[1] = 2;
  p = true;
  overflow = true;
  m = 0;
  exitg1 = false;
  while ((!exitg1) && (m < 2)) {
    if (z_size[m] != XYdata->size[m]) {
      overflow = false;
      exitg1 = true;
    } else {
      m++;
    }
  }
  if (overflow) {
    overflow = true;
    m = 0;
    exitg1 = false;
    while ((!exitg1) && (m < 2)) {
      if (z_size[m] != y->size[m]) {
        overflow = false;
        exitg1 = true;
      } else {
        m++;
      }
    }
    if (!overflow) {
      p = false;
    }
  } else {
    p = false;
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&g_st, &q_emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  if (XYdata->size[0] <= y->size[0]) {
    m = XYdata->size[0];
  } else {
    m = y->size[0];
  }
  m <<= 1;
  g_st.site = &we_emlrtRSI;
  if ((1 <= m) && (m > 2147483646)) {
    h_st.site = &wb_emlrtRSI;
    check_forloop_overflow_error(&h_st);
  }
  m = XYdata->size[0] * 2;
  i = y->size[0] * y->size[1];
  y->size[0] = XYdata->size[0];
  y->size[1] = 2;
  emxEnsureCapacity_real_T(&b_st, y, i, &af_emlrtRTEI);
  for (i = 0; i < m; i++) {
    y->data[i] = XYdata->data[i] / y->data[i];
  }
  st.site = &fe_emlrtRSI;
  b_st.site = &be_emlrtRSI;
  c_st.site = &ce_emlrtRSI;
  d_st.site = &de_emlrtRSI;
  if (XYdata->size[0] == 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &m_emlrtRTEI,
                                  "Coder:toolbox:autoDimIncompatibility",
                                  "Coder:toolbox:autoDimIncompatibility", 0);
  }
  if (XYdata->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &n_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &wd_emlrtRSI;
  f_st.site = &xd_emlrtRSI;
  g_st.site = &yd_emlrtRSI;
  m = XYdata->size[0];
  overflow = ((2 <= XYdata->size[0]) && (XYdata->size[0] > 2147483646));
  for (j = 0; j < 2; j++) {
    minval[j] = XYdata->data[XYdata->size[0] * j];
    h_st.site = &ae_emlrtRSI;
    if (overflow) {
      i_st.site = &wb_emlrtRSI;
      check_forloop_overflow_error(&i_st);
    }
    for (b_i = 2; b_i <= m; b_i++) {
      b = XYdata->data[(b_i + XYdata->size[0] * j) - 1];
      if (muDoubleScalarIsNaN(b)) {
        p = false;
      } else if (muDoubleScalarIsNaN(minval[j])) {
        p = true;
      } else {
        p = (minval[j] > b);
      }
      if (p) {
        minval[j] = b;
      }
    }
  }
  emxInit_real_T(&g_st, &secondStep, 2, &nf_emlrtRTEI, true);
  emxInit_real_T(&g_st, &b_y, 2, &af_emlrtRTEI, true);
  st.site = &fe_emlrtRSI;
  repmat(&st, minval, XYdata->size[0], secondStep);
  z_size[0] = (*(int32_T(*)[2])y->size)[0];
  z_size[1] = (*(int32_T(*)[2])y->size)[1];
  iv[0] = (*(int32_T(*)[2])secondStep->size)[0];
  iv[1] = (*(int32_T(*)[2])secondStep->size)[1];
  emlrtSizeEqCheckNDR2012b(&z_size[0], &iv[0], &q_emlrtECI, (emlrtCTX)sp);
  /*  calculate cosine of central angles */
  i = b_y->size[0] * b_y->size[1];
  b_y->size[0] = y->size[0];
  b_y->size[1] = 2;
  emxEnsureCapacity_real_T(sp, b_y, i, &af_emlrtRTEI);
  m = y->size[0] * 2;
  for (i = 0; i < m; i++) {
    b_y->data[i] = y->data[i] - secondStep->data[i];
  }
  emxInit_real_T(sp, &longStep, 2, &nf_emlrtRTEI, true);
  emxInit_real_T(sp, &firstStep, 1, &bf_emlrtRTEI, true);
  st.site = &ge_emlrtRSI;
  calculateTrianglesSides(&st, b_y, y, secondStep, longStep);
  /*  calculate area of squares of length of triangle sides */
  m = y->size[0];
  i = firstStep->size[0];
  firstStep->size[0] = y->size[0];
  emxEnsureCapacity_real_T(sp, firstStep, i, &bf_emlrtRTEI);
  emxFree_real_T(&b_y);
  for (i = 0; i < m; i++) {
    firstStep->data[i] = y->data[i];
  }
  emxInit_real_T(sp, &firstStepSquared, 1, &kf_emlrtRTEI, true);
  st.site = &he_emlrtRSI;
  power(&st, firstStep, firstStepSquared);
  m = y->size[0];
  i = firstStep->size[0];
  firstStep->size[0] = y->size[0];
  emxEnsureCapacity_real_T(sp, firstStep, i, &cf_emlrtRTEI);
  for (i = 0; i < m; i++) {
    firstStep->data[i] = y->data[i + y->size[0]];
  }
  emxFree_real_T(&y);
  emxInit_real_T(sp, &r, 1, &nf_emlrtRTEI, true);
  st.site = &he_emlrtRSI;
  power(&st, firstStep, r);
  if (firstStepSquared->size[0] != r->size[0]) {
    emlrtSizeEqCheck1DR2012b(firstStepSquared->size[0], r->size[0], &r_emlrtECI,
                             (emlrtCTX)sp);
  }
  m = firstStepSquared->size[0];
  for (i = 0; i < m; i++) {
    firstStepSquared->data[i] += r->data[i];
  }
  m = secondStep->size[0];
  i = firstStep->size[0];
  firstStep->size[0] = secondStep->size[0];
  emxEnsureCapacity_real_T(sp, firstStep, i, &df_emlrtRTEI);
  for (i = 0; i < m; i++) {
    firstStep->data[i] = secondStep->data[i];
  }
  emxInit_real_T(sp, &secondStepSquared, 1, &lf_emlrtRTEI, true);
  st.site = &ie_emlrtRSI;
  power(&st, firstStep, secondStepSquared);
  m = secondStep->size[0];
  i = firstStep->size[0];
  firstStep->size[0] = secondStep->size[0];
  emxEnsureCapacity_real_T(sp, firstStep, i, &ef_emlrtRTEI);
  for (i = 0; i < m; i++) {
    firstStep->data[i] = secondStep->data[i + secondStep->size[0]];
  }
  emxFree_real_T(&secondStep);
  st.site = &ie_emlrtRSI;
  power(&st, firstStep, r);
  if (secondStepSquared->size[0] != r->size[0]) {
    emlrtSizeEqCheck1DR2012b(secondStepSquared->size[0], r->size[0],
                             &s_emlrtECI, (emlrtCTX)sp);
  }
  m = secondStepSquared->size[0];
  for (i = 0; i < m; i++) {
    secondStepSquared->data[i] += r->data[i];
  }
  m = longStep->size[0];
  i = firstStep->size[0];
  firstStep->size[0] = longStep->size[0];
  emxEnsureCapacity_real_T(sp, firstStep, i, &ff_emlrtRTEI);
  for (i = 0; i < m; i++) {
    firstStep->data[i] = longStep->data[i];
  }
  emxInit_real_T(sp, &longStepSquared, 1, &mf_emlrtRTEI, true);
  st.site = &je_emlrtRSI;
  power(&st, firstStep, longStepSquared);
  m = longStep->size[0];
  i = firstStep->size[0];
  firstStep->size[0] = longStep->size[0];
  emxEnsureCapacity_real_T(sp, firstStep, i, &gf_emlrtRTEI);
  for (i = 0; i < m; i++) {
    firstStep->data[i] = longStep->data[i + longStep->size[0]];
  }
  emxFree_real_T(&longStep);
  st.site = &je_emlrtRSI;
  power(&st, firstStep, r);
  emxFree_real_T(&firstStep);
  if (longStepSquared->size[0] != r->size[0]) {
    emlrtSizeEqCheck1DR2012b(longStepSquared->size[0], r->size[0], &t_emlrtECI,
                             (emlrtCTX)sp);
  }
  m = longStepSquared->size[0];
  for (i = 0; i < m; i++) {
    longStepSquared->data[i] += r->data[i];
  }
  emxFree_real_T(&r);
  if (firstStepSquared->size[0] != secondStepSquared->size[0]) {
    emlrtSizeEqCheck1DR2012b(firstStepSquared->size[0],
                             secondStepSquared->size[0], &u_emlrtECI,
                             (emlrtCTX)sp);
  }
  if (firstStepSquared->size[0] != longStepSquared->size[0]) {
    emlrtSizeEqCheck1DR2012b(firstStepSquared->size[0],
                             longStepSquared->size[0], &u_emlrtECI,
                             (emlrtCTX)sp);
  }
  if (firstStepSquared->size[0] != secondStepSquared->size[0]) {
    emlrtSizeEqCheck1DR2012b(firstStepSquared->size[0],
                             secondStepSquared->size[0], &v_emlrtECI,
                             (emlrtCTX)sp);
  }
  st.site = &le_emlrtRSI;
  i = longStepSquared->size[0];
  longStepSquared->size[0] = firstStepSquared->size[0];
  emxEnsureCapacity_real_T(&st, longStepSquared, i, &hf_emlrtRTEI);
  m = firstStepSquared->size[0];
  for (i = 0; i < m; i++) {
    longStepSquared->data[i] =
        ((firstStepSquared->data[i] + secondStepSquared->data[i]) -
         longStepSquared->data[i]) /
        2.0;
  }
  m = firstStepSquared->size[0];
  for (i = 0; i < m; i++) {
    firstStepSquared->data[i] *= secondStepSquared->data[i];
  }
  emxFree_real_T(&secondStepSquared);
  b_st.site = &ke_emlrtRSI;
  b_sqrt(&b_st, firstStepSquared);
  b_st.site = &pe_emlrtRSI;
  c_st.site = &qe_emlrtRSI;
  d_st.site = &re_emlrtRSI;
  e_st.site = &se_emlrtRSI;
  f_st.site = &te_emlrtRSI;
  if (longStepSquared->size[0] <= firstStepSquared->size[0]) {
    j = longStepSquared->size[0];
  } else {
    j = firstStepSquared->size[0];
  }
  p = true;
  overflow = true;
  m = 0;
  exitg1 = false;
  while ((!exitg1) && (m < 2)) {
    if (m + 1 <= 1) {
      i = j;
      b_i = longStepSquared->size[0];
    } else {
      i = 1;
      b_i = 1;
    }
    if (i != b_i) {
      overflow = false;
      exitg1 = true;
    } else {
      m++;
    }
  }
  if (overflow) {
    overflow = true;
    m = 0;
    exitg1 = false;
    while ((!exitg1) && (m < 2)) {
      if (m + 1 <= 1) {
        i = j;
        b_i = firstStepSquared->size[0];
      } else {
        i = 1;
        b_i = 1;
      }
      if (i != b_i) {
        overflow = false;
        exitg1 = true;
      } else {
        m++;
      }
    }
    if (!overflow) {
      p = false;
    }
  } else {
    p = false;
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&f_st, &q_emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  f_st.site = &ue_emlrtRSI;
  g_st.site = &ve_emlrtRSI;
  if (longStepSquared->size[0] <= firstStepSquared->size[0]) {
    j = longStepSquared->size[0];
  } else {
    j = firstStepSquared->size[0];
  }
  p = true;
  overflow = true;
  m = 0;
  exitg1 = false;
  while ((!exitg1) && (m < 2)) {
    if (m + 1 <= 1) {
      i = j;
      b_i = longStepSquared->size[0];
    } else {
      i = 1;
      b_i = 1;
    }
    if (i != b_i) {
      overflow = false;
      exitg1 = true;
    } else {
      m++;
    }
  }
  if (overflow) {
    overflow = true;
    m = 0;
    exitg1 = false;
    while ((!exitg1) && (m < 2)) {
      if (m + 1 <= 1) {
        i = j;
        b_i = firstStepSquared->size[0];
      } else {
        i = 1;
        b_i = 1;
      }
      if (i != b_i) {
        overflow = false;
        exitg1 = true;
      } else {
        m++;
      }
    }
    if (!overflow) {
      p = false;
    }
  } else {
    p = false;
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&g_st, &q_emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  g_st.site = &we_emlrtRSI;
  if ((1 <= j) && (j > 2147483646)) {
    h_st.site = &wb_emlrtRSI;
    check_forloop_overflow_error(&h_st);
  }
  emxInit_creal_T(&g_st, &r1, 1, &if_emlrtRTEI, true);
  i = r1->size[0];
  r1->size[0] = longStepSquared->size[0];
  emxEnsureCapacity_creal_T(sp, r1, i, &if_emlrtRTEI);
  m = longStepSquared->size[0];
  for (i = 0; i < m; i++) {
    r1->data[i].re = longStepSquared->data[i] / firstStepSquared->data[i];
    r1->data[i].im = 0.0;
  }
  emxFree_real_T(&longStepSquared);
  emxFree_real_T(&firstStepSquared);
  st.site = &me_emlrtRSI;
  b_acos(&st, r1);
  i = cornerAngle->size[0];
  cornerAngle->size[0] = r1->size[0];
  emxEnsureCapacity_real_T(sp, cornerAngle, i, &jf_emlrtRTEI);
  m = r1->size[0];
  for (i = 0; i < m; i++) {
    cornerAngle->data[i] = r1->data[i].re;
  }
  emxFree_creal_T(&r1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void calculateTrianglesSides(const emlrtStack *sp,
                                    const emxArray_real_T *XYdata,
                                    emxArray_real_T *firstStep,
                                    emxArray_real_T *secondStep,
                                    emxArray_real_T *longStep)
{
  int32_T iv[2];
  int32_T iv1[2];
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T loop_ub;
  /*  Return the sides (deltaX, deltaY) of the triangles formed by data points.
   */
  /*  For input size NxM, the output size is (N-2)xN, because the first and the
   */
  /*  last point are not the central corner of any triangle. */
  if (2 > XYdata->size[0] - 1) {
    i = -1;
    i1 = -1;
  } else {
    if (2 > XYdata->size[0]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, XYdata->size[0], &je_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i = 0;
    if ((XYdata->size[0] - 1 < 1) || (XYdata->size[0] - 1 > XYdata->size[0])) {
      emlrtDynamicBoundsCheckR2012b(XYdata->size[0] - 1, 1, XYdata->size[0],
                                    &ke_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = XYdata->size[0] - 2;
  }
  if (1 > XYdata->size[0] - 2) {
    i2 = 0;
  } else {
    if (1 > XYdata->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, XYdata->size[0], &le_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if ((XYdata->size[0] - 2 < 1) || (XYdata->size[0] - 2 > XYdata->size[0])) {
      emlrtDynamicBoundsCheckR2012b(XYdata->size[0] - 2, 1, XYdata->size[0],
                                    &me_emlrtBCI, (emlrtCTX)sp);
    }
    i2 = XYdata->size[0] - 2;
  }
  loop_ub = i1 - i;
  iv[0] = loop_ub;
  iv[1] = 2;
  iv1[0] = i2;
  iv1[1] = 2;
  if (loop_ub != i2) {
    emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &w_emlrtECI, (emlrtCTX)sp);
  }
  i1 = firstStep->size[0] * firstStep->size[1];
  firstStep->size[0] = loop_ub;
  firstStep->size[1] = 2;
  emxEnsureCapacity_real_T(sp, firstStep, i1, &qf_emlrtRTEI);
  for (i1 = 0; i1 < 2; i1++) {
    for (i2 = 0; i2 < loop_ub; i2++) {
      firstStep->data[i2 + firstStep->size[0] * i1] =
          XYdata->data[((i + i2) + XYdata->size[0] * i1) + 1] -
          XYdata->data[i2 + XYdata->size[0] * i1];
    }
  }
  if (3 > XYdata->size[0]) {
    i = -1;
    i1 = -1;
    i2 = -1;
    i3 = 0;
  } else {
    i = 1;
    i1 = XYdata->size[0] - 1;
    if (2 > XYdata->size[0]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, XYdata->size[0], &ne_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i2 = 0;
    if ((XYdata->size[0] - 1 < 1) || (XYdata->size[0] - 1 > XYdata->size[0])) {
      emlrtDynamicBoundsCheckR2012b(XYdata->size[0] - 1, 1, XYdata->size[0],
                                    &oe_emlrtBCI, (emlrtCTX)sp);
    }
    i3 = XYdata->size[0] - 1;
  }
  loop_ub = i1 - i;
  iv[0] = loop_ub;
  iv[1] = 2;
  iv1[0] = (i3 - i2) - 1;
  iv1[1] = 2;
  if (loop_ub != iv1[0]) {
    emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &x_emlrtECI, (emlrtCTX)sp);
  }
  i1 = secondStep->size[0] * secondStep->size[1];
  secondStep->size[0] = loop_ub;
  secondStep->size[1] = 2;
  emxEnsureCapacity_real_T(sp, secondStep, i1, &rf_emlrtRTEI);
  for (i1 = 0; i1 < 2; i1++) {
    for (i3 = 0; i3 < loop_ub; i3++) {
      secondStep->data[i3 + secondStep->size[0] * i1] =
          XYdata->data[((i + i3) + XYdata->size[0] * i1) + 1] -
          XYdata->data[((i2 + i3) + XYdata->size[0] * i1) + 1];
    }
  }
  if (3 > XYdata->size[0]) {
    i = -1;
    i1 = -1;
    i2 = 0;
  } else {
    i = 1;
    i1 = XYdata->size[0] - 1;
    if (1 > XYdata->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, XYdata->size[0], &pe_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if ((XYdata->size[0] - 2 < 1) || (XYdata->size[0] - 2 > XYdata->size[0])) {
      emlrtDynamicBoundsCheckR2012b(XYdata->size[0] - 2, 1, XYdata->size[0],
                                    &qe_emlrtBCI, (emlrtCTX)sp);
    }
    i2 = XYdata->size[0] - 2;
  }
  loop_ub = i1 - i;
  iv[0] = loop_ub;
  iv[1] = 2;
  iv1[0] = i2;
  iv1[1] = 2;
  if (loop_ub != i2) {
    emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &y_emlrtECI, (emlrtCTX)sp);
  }
  i1 = longStep->size[0] * longStep->size[1];
  longStep->size[0] = loop_ub;
  longStep->size[1] = 2;
  emxEnsureCapacity_real_T(sp, longStep, i1, &sf_emlrtRTEI);
  for (i1 = 0; i1 < 2; i1++) {
    for (i2 = 0; i2 < loop_ub; i2++) {
      longStep->data[i2 + longStep->size[0] * i1] =
          XYdata->data[((i + i2) + XYdata->size[0] * i1) + 1] -
          XYdata->data[i2 + XYdata->size[0] * i1];
    }
  }
}

static void normalizeFunction(const emlrtStack *sp, const emxArray_real_T *x,
                              const emxArray_real_T *sldProfile,
                              emxArray_real_T *y)
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
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
  emxEnsureCapacity_real_T(sp, y, i, &pe_emlrtRTEI);
  /*  if vectorizable */
  /*    % For uniformity reasons, transform the 'x' array into a column vector.
   */
  /*    % In this way it does not matter if it is given as a column or a row */
  /*    % vector. */
  /*    [newValues{:}] = func(x(:)); */
  /*    y = cell2mat(newValues); */
  /*  else */
  i = x->size[0];
  emxInit_int32_T(sp, &where, 1, &re_emlrtRTEI, true);
  emxInit_real_T(sp, &aboveVals, 1, &we_emlrtRTEI, true);
  emxInit_int32_T(sp, &ii, 1, &oc_emlrtRTEI, true);
  emxInit_boolean_T(sp, &b_sldProfile, 1, &qe_emlrtRTEI, true);
  for (b_i = 0; b_i < i; b_i++) {
    /*  Remove cell array so no need for cell2mat */
    /*  which won't compile - AVH */
    /* [newValues{:}] = func(x(i)); */
    /* y(i,:) = cell2mat(newValues); */
    st.site = &od_emlrtRSI;
    if (b_i + 1 > x->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, x->size[0], &ae_emlrtBCI, &st);
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
    b_st.site = &pd_emlrtRSI;
    loop_ub = sldProfile->size[0];
    i1 = b_sldProfile->size[0];
    b_sldProfile->size[0] = sldProfile->size[0];
    emxEnsureCapacity_boolean_T(&b_st, b_sldProfile, i1, &qe_emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_sldProfile->data[i1] = (sldProfile->data[i1] == x->data[b_i]);
    }
    c_st.site = &sd_emlrtRSI;
    eml_find(&c_st, b_sldProfile, ii);
    i1 = where->size[0];
    where->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(&b_st, where, i1, &re_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      where->data[i1] = ii->data[i1];
    }
    if (where->size[0] != 0) {
      i1 = aboveVals->size[0];
      aboveVals->size[0] = where->size[0];
      emxEnsureCapacity_real_T(&st, aboveVals, i1, &se_emlrtRTEI);
      loop_ub = where->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        if ((where->data[i1] < 1) || (where->data[i1] > sldProfile->size[0])) {
          emlrtDynamicBoundsCheckR2012b(where->data[i1], 1, sldProfile->size[0],
                                        &he_emlrtBCI, &st);
        }
        aboveVals->data[i1] =
            sldProfile->data[(where->data[i1] + sldProfile->size[0]) - 1];
      }
    } else {
      b_st.site = &qd_emlrtRSI;
      loop_ub = sldProfile->size[0];
      i1 = b_sldProfile->size[0];
      b_sldProfile->size[0] = sldProfile->size[0];
      emxEnsureCapacity_boolean_T(&b_st, b_sldProfile, i1, &te_emlrtRTEI);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_sldProfile->data[i1] = (x->data[b_i] > sldProfile->data[i1]);
      }
      c_st.site = &sd_emlrtRSI;
      eml_find(&c_st, b_sldProfile, ii);
      i1 = where->size[0];
      where->size[0] = ii->size[0];
      emxEnsureCapacity_int32_T(&b_st, where, i1, &ue_emlrtRTEI);
      loop_ub = ii->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        where->data[i1] = ii->data[i1];
      }
      b_st.site = &rd_emlrtRSI;
      loop_ub = sldProfile->size[0];
      i1 = b_sldProfile->size[0];
      b_sldProfile->size[0] = sldProfile->size[0];
      emxEnsureCapacity_boolean_T(&b_st, b_sldProfile, i1, &ve_emlrtRTEI);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_sldProfile->data[i1] = (x->data[b_i] < sldProfile->data[i1]);
      }
      c_st.site = &sd_emlrtRSI;
      eml_find(&c_st, b_sldProfile, ii);
      i1 = aboveVals->size[0];
      aboveVals->size[0] = ii->size[0];
      emxEnsureCapacity_real_T(&b_st, aboveVals, i1, &we_emlrtRTEI);
      loop_ub = ii->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        aboveVals->data[i1] = ii->data[i1];
      }
      if (where->size[0] < 1) {
        emlrtDynamicBoundsCheckR2012b(where->size[0], 1, where->size[0],
                                      &be_emlrtBCI, &st);
      }
      if (1 > aboveVals->size[0]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, aboveVals->size[0], &ce_emlrtBCI,
                                      &st);
      }
      i1 = where->data[where->size[0] - 1];
      if ((i1 < 1) || (i1 > sldProfile->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, sldProfile->size[0], &de_emlrtBCI,
                                      &st);
      }
      if (((int32_T)aboveVals->data[0] < 1) ||
          ((int32_T)aboveVals->data[0] > sldProfile->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)aboveVals->data[0], 1,
                                      sldProfile->size[0], &ee_emlrtBCI, &st);
      }
      i1 = where->data[where->size[0] - 1];
      if ((i1 < 1) || (i1 > sldProfile->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, sldProfile->size[0], &fe_emlrtBCI,
                                      &st);
      }
      i1 = where->data[where->size[0] - 1];
      if ((i1 < 1) || (i1 > sldProfile->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, sldProfile->size[0], &ge_emlrtBCI,
                                      &st);
      }
      deltaY_tmp =
          sldProfile
              ->data[((int32_T)aboveVals->data[0] + sldProfile->size[0]) - 1];
      deltaY =
          (x->data[b_i] -
           sldProfile->data[where->data[where->size[0] - 1] - 1]) *
          (muDoubleScalarAbs(deltaY_tmp -
                             sldProfile->data[(where->data[where->size[0] - 1] +
                                               sldProfile->size[0]) -
                                              1]) /
           (sldProfile->data[(int32_T)aboveVals->data[0] - 1] -
            sldProfile->data[where->data[where->size[0] - 1] - 1]));
      if (sldProfile
              ->data[(where->data[where->size[0] - 1] + sldProfile->size[0]) -
                     1] < deltaY_tmp) {
        i1 = aboveVals->size[0];
        aboveVals->size[0] = 1;
        emxEnsureCapacity_real_T(&st, aboveVals, i1, &se_emlrtRTEI);
        aboveVals->data[0] =
            sldProfile
                ->data[(where->data[where->size[0] - 1] + sldProfile->size[0]) -
                       1] +
            deltaY;
      } else {
        i1 = aboveVals->size[0];
        aboveVals->size[0] = 1;
        emxEnsureCapacity_real_T(&st, aboveVals, i1, &se_emlrtRTEI);
        aboveVals->data[0] =
            sldProfile
                ->data[(where->data[where->size[0] - 1] + sldProfile->size[0]) -
                       1] -
            deltaY;
      }
      /* sldVal = interp1(z,rho,x); */
    }
    if (1 != aboveVals->size[0]) {
      emlrtSubAssignSizeCheck1dR2017a(1, aboveVals->size[0], &p_emlrtECI,
                                      (emlrtCTX)sp);
    }
    if (b_i + 1 > y->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, y->size[0], &ie_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    y->data[b_i] = aboveVals->data[0];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_boolean_T(&b_sldProfile);
  emxFree_int32_T(&ii);
  emxFree_real_T(&aboveVals);
  emxFree_int32_T(&where);
  /* end */
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void adaptive_new(const emlrtStack *sp, const emxArray_real_T *sldProfile,
                  const real_T startDomain[2], real_T minAngle, real_T nPoints,
                  cell_18 *out)
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
  emxArray_real_T *b_dataPoints;
  emxArray_real_T *dataPoints;
  emxArray_real_T *hiVal;
  emxArray_real_T *newDataPoints;
  emxArray_real_T *newDomain;
  emxArray_real_T *r;
  real_T maxval[2];
  real_T minval[2];
  real_T b;
  int32_T b_i;
  int32_T b_input_sizes_idx_0;
  int32_T i;
  int32_T input_sizes_idx_0;
  int32_T nRefinements;
  int32_T trueCount;
  boolean_T exitg1;
  boolean_T overflow;
  boolean_T p;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &newDomain, 1, &ud_emlrtRTEI, true);
  emxInit_real_T(sp, &r, 2, &ne_emlrtRTEI, true);
  /*  adaptive: evaluates a matlab function on a given range */
  /*  */
  /*  'adaptive.m' allows to sample a function using a reduced number of */
  /*  points. It works iteratively adding new points where needed. */
  /*  It is especially useful for functions which are computationally intensive
   */
  /*  (e.g. involve solving a differential equation). */
  /*  */
  /*  Usage: */
  /*  XY = adaptive(func, [xstart, xend]) */
  /*   evaluates 'func' in the range [xstart, xend]. Key-value arguments are */
  /*   used to control the function evaluation. If the function 'func' returns
   */
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
  /*    'adaptive' provides three methods for refining the function evaluation:
   */
  /*    1) add more points near the sharp corners, which are found by */
  /*     considering the triangles formed by three successive points and */
  /*     measuring the central angle. */
  /*    2) measure the area of the same triangles and add more points when the
   */
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
  /*        Refine near the  points which forms, together with their left and
   * right */
  /*        neighbours, a triangle with central angle smaller than a given
   * value. */
  /*   - 'maxArea': (default 5e-4) */
  /*        Refine near the points which forms, together with their left and
   * right */
  /*        neighbours, a triangle with area larger than a threshold. The
   * threshold */
  /*        in normalized to the area enclosing th graph: */
  /*        threshold==maxArea*(max(x)-min(x))*(max(f(x))-min(f(x))) */
  /*   - 'maxLength': (default Inf) */
  /*        Refine all the sements which are longer than a given threshold. The
   */
  /*        threshold is relative to the input and output ranges. Specifically,
   */
  /*        before applying the threshold, the data are normalized so that */
  /*        max(x)-min(x)==1 and max(f(x))-min(f(x))==1. */
  /*   - 'minLength': (default 0) */
  /*        Exclude from the refinement process the segments which are shorter
   */
  /*        than a given threshold. The threshold is relative to the input and
   */
  /*        output ranges. Specifically, before applying the threshold, the */
  /*        data are normalized so that max(x)-min(x)==1 and
   * max(f(x))-min(f(x))==1. */
  /*   - 'minSignal': (default 0.2) */
  /*        Exclude from the refinement process the points where the function is
   */
  /*        below a threshold. The threshold is relative to the output range: In
   */
  /*        this example threshold == 0.01*(max(f(x))-min(f(x))). */
  /*   - 'vectorizable': (default false) */
  /*        Specifies whether the input function accepts arrays as input */
  /*        (e.g. f(x)==x.^2). */
  /*   - 'waitbar': (default false) */
  /*        Display a waitbar. */
  /*  */
  /*  Output parameters */
  /*   - a NxM array where N is the number of domain points and M is the number
   */
  /*     of output parameters of the input function. */
  /*  */
  /*  */
  /*  Examples: */
  /*  */
  /*    % Refine a function near sharp corners. The option 'minAngle' is useful
   */
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
  /*    % Refine a function near sharp corners, but do not split segments which
   */
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
  /*   'nPoints' controls the number of initial domain points in the cases when
   */
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
  /*    input_func = @(x) 100*exp(-(x+5.2).^2) + 50*exp(-5*(x-0.5).^2)+
   * 20*exp(-10*(x-5.8).^2); */
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
  /*  assert(isa(input_func,'function_handle'),'adaptiveFunctionEvaluation:ArgChk',...
   */
  /*    'the first argument must be a function handle'); */
  /*  assert(isnumeric(initialDomain) && isvector(initialDomain),... */
  /*    'adaptiveFunctionEvaluation:ArgChk','initial points must be specified as
   * a numeric vector'); */
  /*   */
  /* nExtraArgIn = numel(varargin); */
  /*  if mod(nExtraArgIn,2)==1 */
  /*    error('adaptiveFunctionEvaluation:ArgChk', ... */
  /*      'At least a key or a value is missing in the key-value arguments
   * list.'); */
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
  /*  if initialDomain only contains the start and the end points, create a new
   */
  /*  array with 'nPoints' points. */
  st.site = &hd_emlrtRSI;
  linspace(&st, startDomain[0], startDomain[1], nPoints, r);
  i = newDomain->size[0];
  newDomain->size[0] = r->size[1];
  emxEnsureCapacity_real_T(sp, newDomain, i, &ud_emlrtRTEI);
  input_sizes_idx_0 = r->size[1];
  for (i = 0; i < input_sizes_idx_0; i++) {
    newDomain->data[i] = r->data[i];
  }
  emxFree_real_T(&r);
  emxInit_real_T(sp, &hiVal, 1, &le_emlrtRTEI, true);
  /*  Normalize the input function: This step allows to use the same syntax for
   */
  /*  functions with single or multiple output parameters. */
  /*  Remove this syntax for compile - AVH */
  /* func = @(x) normalizeFunction(x,sldProfile,vectorizable); */
  /*  Evaluate the input function on the initial set of points. */
  st.site = &id_emlrtRSI;
  normalizeFunction(&st, newDomain, sldProfile, hiVal);
  /* dataPoints = [initialDomain(:), func(initialDomain(:))]; */
  st.site = &jd_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  c_st.site = &x_emlrtRSI;
  if (hiVal->size[0] != newDomain->size[0]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &h_emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  emxInit_real_T(&c_st, &dataPoints, 2, &vd_emlrtRTEI, true);
  i = dataPoints->size[0] * dataPoints->size[1];
  dataPoints->size[0] = newDomain->size[0];
  dataPoints->size[1] = 2;
  emxEnsureCapacity_real_T(&b_st, dataPoints, i, &vd_emlrtRTEI);
  input_sizes_idx_0 = newDomain->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    dataPoints->data[i] = newDomain->data[i];
  }
  input_sizes_idx_0 = hiVal->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    dataPoints->data[i + dataPoints->size[0]] = hiVal->data[i];
  }
  /*  Iterative function refinement */
  /*  if displayWaitbar */
  /*    refinementWaitbar = waitbar(0,['Evaluating function
   * ',func2str(func)],... */
  /*      'CreateCancelBtn','setappdata(gcbf,''canceling'',true)'); */
  /*    setappdata(refinementWaitbar,'canceling',false) */
  /*  end */
  nRefinements = 0;
  emxInit_boolean_T(sp, &sharpCorners, 1, &yd_emlrtRTEI, true);
  emxInit_boolean_T(sp, &segmentsToSplit, 1, &me_emlrtRTEI, true);
  emxInit_boolean_T(sp, &r1, 1, &ee_emlrtRTEI, true);
  emxInit_real_T(sp, &newDataPoints, 2, &de_emlrtRTEI, true);
  emxInit_int32_T(sp, &r2, 1, &ee_emlrtRTEI, true);
  emxInit_int32_T(sp, &r3, 1, &fe_emlrtRTEI, true);
  emxInit_int32_T(sp, &r4, 1, &ee_emlrtRTEI, true);
  emxInit_int32_T(sp, &r5, 1, &fe_emlrtRTEI, true);
  emxInit_real_T(sp, &b_dataPoints, 2, &xd_emlrtRTEI, true);
  exitg1 = false;
  while ((!exitg1) && (nRefinements < 10)) {
    /*  calculate the box which encloses the current data points: */
    st.site = &kd_emlrtRSI;
    b_st.site = &ad_emlrtRSI;
    c_st.site = &bd_emlrtRSI;
    d_st.site = &cd_emlrtRSI;
    if (dataPoints->size[0] == 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &m_emlrtRTEI,
                                    "Coder:toolbox:autoDimIncompatibility",
                                    "Coder:toolbox:autoDimIncompatibility", 0);
    }
    if (dataPoints->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &n_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }
    e_st.site = &wd_emlrtRSI;
    f_st.site = &xd_emlrtRSI;
    g_st.site = &yd_emlrtRSI;
    i = dataPoints->size[0];
    overflow =
        ((2 <= dataPoints->size[0]) && (dataPoints->size[0] > 2147483646));
    for (input_sizes_idx_0 = 0; input_sizes_idx_0 < 2; input_sizes_idx_0++) {
      maxval[input_sizes_idx_0] =
          dataPoints->data[dataPoints->size[0] * input_sizes_idx_0];
      h_st.site = &ae_emlrtRSI;
      if (overflow) {
        i_st.site = &wb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (b_i = 2; b_i <= i; b_i++) {
        b = dataPoints
                ->data[(b_i + dataPoints->size[0] * input_sizes_idx_0) - 1];
        if (muDoubleScalarIsNaN(b)) {
          p = false;
        } else if (muDoubleScalarIsNaN(maxval[input_sizes_idx_0])) {
          p = true;
        } else {
          p = (maxval[input_sizes_idx_0] < b);
        }
        if (p) {
          maxval[input_sizes_idx_0] = b;
        }
      }
    }
    st.site = &kd_emlrtRSI;
    b_st.site = &be_emlrtRSI;
    c_st.site = &ce_emlrtRSI;
    d_st.site = &de_emlrtRSI;
    if (dataPoints->size[0] == 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &m_emlrtRTEI,
                                    "Coder:toolbox:autoDimIncompatibility",
                                    "Coder:toolbox:autoDimIncompatibility", 0);
    }
    e_st.site = &wd_emlrtRSI;
    f_st.site = &xd_emlrtRSI;
    g_st.site = &yd_emlrtRSI;
    i = dataPoints->size[0];
    overflow = (dataPoints->size[0] > 2147483646);
    for (input_sizes_idx_0 = 0; input_sizes_idx_0 < 2; input_sizes_idx_0++) {
      minval[input_sizes_idx_0] =
          dataPoints->data[dataPoints->size[0] * input_sizes_idx_0];
      h_st.site = &ae_emlrtRSI;
      if (overflow) {
        i_st.site = &wb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (b_i = 2; b_i <= i; b_i++) {
        b = dataPoints
                ->data[(b_i + dataPoints->size[0] * input_sizes_idx_0) - 1];
        if (muDoubleScalarIsNaN(b)) {
          p = false;
        } else if (muDoubleScalarIsNaN(minval[input_sizes_idx_0])) {
          p = true;
        } else {
          p = (minval[input_sizes_idx_0] > b);
        }
        if (p) {
          minval[input_sizes_idx_0] = b;
        }
      }
    }
    /*  Each point is considered as the central corner of the triangle formed */
    /*  with its left and right hand side neighbours. The first and the last */
    /*  points are not the central corner of any triangle, so for N points */
    /*  there are only N-2 triangles. */
    /*    if thresholdingArea */
    /*      triangleArea = calculateTrianglesArea(dataPoints(:,1:2)); */
    /*      bigTriangles = triangleArea > (maxArea * dataBoxArea); */
    /*      trianglesToRefine = trianglesToRefine | bigTriangles; */
    /*    end */
    input_sizes_idx_0 = dataPoints->size[0];
    i = b_dataPoints->size[0] * b_dataPoints->size[1];
    b_dataPoints->size[0] = dataPoints->size[0];
    b_dataPoints->size[1] = 2;
    emxEnsureCapacity_real_T(sp, b_dataPoints, i, &xd_emlrtRTEI);
    for (i = 0; i < 2; i++) {
      for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
        b_dataPoints->data[b_i + b_dataPoints->size[0] * i] =
            dataPoints->data[b_i + dataPoints->size[0] * i];
      }
      maxval[i] -= minval[i];
    }
    st.site = &ld_emlrtRSI;
    calculateCentralAngles(&st, b_dataPoints, maxval, newDomain);
    i = sharpCorners->size[0];
    sharpCorners->size[0] = newDomain->size[0];
    emxEnsureCapacity_boolean_T(sp, sharpCorners, i, &yd_emlrtRTEI);
    input_sizes_idx_0 = newDomain->size[0];
    for (i = 0; i < input_sizes_idx_0; i++) {
      sharpCorners->data[i] = (newDomain->data[i] < minAngle);
    }
    if (dataPoints->size[0] - 2 != sharpCorners->size[0]) {
      emlrtSizeEqCheck1DR2012b(dataPoints->size[0] - 2, sharpCorners->size[0],
                               &k_emlrtECI, (emlrtCTX)sp);
    }
    i = sharpCorners->size[0];
    sharpCorners->size[0] = dataPoints->size[0] - 2;
    emxEnsureCapacity_boolean_T(sp, sharpCorners, i, &ae_emlrtRTEI);
    /*  For N points there are N-2 triangles and N-1 triangle sides. Each */
    /*  triangle side is a segment, which can be split or not depending on the
     */
    /*  refinement parameters. */
    i = segmentsToSplit->size[0];
    segmentsToSplit->size[0] = dataPoints->size[0] - 1;
    emxEnsureCapacity_boolean_T(sp, segmentsToSplit, i, &be_emlrtRTEI);
    input_sizes_idx_0 = dataPoints->size[0] - 2;
    for (i = 0; i < input_sizes_idx_0; i++) {
      segmentsToSplit->data[i] = sharpCorners->data[i];
    }
    segmentsToSplit->data[dataPoints->size[0] - 2] = false;
    i = r1->size[0];
    r1->size[0] = dataPoints->size[0] - 1;
    emxEnsureCapacity_boolean_T(sp, r1, i, &ce_emlrtRTEI);
    r1->data[0] = false;
    input_sizes_idx_0 = dataPoints->size[0] - 2;
    for (i = 0; i < input_sizes_idx_0; i++) {
      r1->data[i + 1] = sharpCorners->data[i];
    }
    if (segmentsToSplit->size[0] != r1->size[0]) {
      emlrtSizeEqCheck1DR2012b(segmentsToSplit->size[0], r1->size[0],
                               &l_emlrtECI, (emlrtCTX)sp);
    }
    input_sizes_idx_0 = segmentsToSplit->size[0];
    for (i = 0; i < input_sizes_idx_0; i++) {
      segmentsToSplit->data[i] = (segmentsToSplit->data[i] || r1->data[i]);
    }
    /*    if thresholdingLength */
    /*      dataSegments = diff(dataPoints(:,1:2)); */
    /*      normalizedSegments = bsxfun(@rdivide, dataSegments, dataBoxSize); */
    /*      segmentsLengthNormalized = hypot(normalizedSegments(:,1),
     * normalizedSegments(:,2)); */
    /*      tooLongSegments = segmentsLengthNormalized > maxLength; */
    /*      longEnoughSegments = segmentsLengthNormalized > minLength; */
    /*      segmentsToSplit = (segmentsToSplit | tooLongSegments) &
     * longEnoughSegments; */
    /*    end */
    /*    if thresholdingSignal */
    /*      segmentsCenters = (dataPoints(1:end-1,2)+dataPoints(2:end,2))/2; */
    /*      centerAboveThreshold = segmentsCenters > minSignal *
     * max(abs(dataPoints(:,2))); */
    /*      segmentsToSplit = segmentsToSplit & centerAboveThreshold; */
    /*    end */
    st.site = &md_emlrtRSI;
    if (any(segmentsToSplit)) {
      st.site = &nd_emlrtRSI;
      /*  increaseSampling increase the sampling of an input function */
      b_input_sizes_idx_0 = segmentsToSplit->size[0];
      for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
        if (segmentsToSplit->data[b_i] &&
            (b_i + 1 > segmentsToSplit->size[0])) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, segmentsToSplit->size[0],
                                        &wd_emlrtBCI, &st);
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
      emxEnsureCapacity_real_T(&st, newDataPoints, i, &de_emlrtRTEI);
      input_sizes_idx_0 = trueCount << 1;
      for (i = 0; i < input_sizes_idx_0; i++) {
        newDataPoints->data[i] = 0.0;
      }
      i = r1->size[0];
      r1->size[0] = segmentsToSplit->size[0] + 1;
      emxEnsureCapacity_boolean_T(&st, r1, i, &ee_emlrtRTEI);
      input_sizes_idx_0 = segmentsToSplit->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        r1->data[i] = segmentsToSplit->data[i];
      }
      r1->data[segmentsToSplit->size[0]] = false;
      b_input_sizes_idx_0 = r1->size[0];
      for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
        if (r1->data[b_i] && (b_i + 1 > dataPoints->size[0])) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, dataPoints->size[0],
                                        &xd_emlrtBCI, &st);
        }
      }
      i = sharpCorners->size[0];
      sharpCorners->size[0] = segmentsToSplit->size[0] + 1;
      emxEnsureCapacity_boolean_T(&st, sharpCorners, i, &fe_emlrtRTEI);
      sharpCorners->data[0] = false;
      input_sizes_idx_0 = segmentsToSplit->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        sharpCorners->data[i + 1] = segmentsToSplit->data[i];
      }
      b_input_sizes_idx_0 = sharpCorners->size[0];
      for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
        if (sharpCorners->data[b_i] && (b_i + 1 > dataPoints->size[0])) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, dataPoints->size[0],
                                        &yd_emlrtBCI, &st);
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
      emxEnsureCapacity_int32_T(&st, r2, i, &ge_emlrtRTEI);
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
      emxEnsureCapacity_int32_T(&st, r3, i, &ge_emlrtRTEI);
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (sharpCorners->data[b_i]) {
          r3->data[input_sizes_idx_0] = b_i + 1;
          input_sizes_idx_0++;
        }
      }
      if (r2->size[0] != r3->size[0]) {
        emlrtSizeEqCheck1DR2012b(r2->size[0], r3->size[0], &m_emlrtECI, &st);
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
      emxEnsureCapacity_int32_T(&st, r4, i, &ge_emlrtRTEI);
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
      emxEnsureCapacity_int32_T(&st, r5, i, &ge_emlrtRTEI);
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (sharpCorners->data[b_i]) {
          r5->data[input_sizes_idx_0] = b_i + 1;
          input_sizes_idx_0++;
        }
      }
      i = newDomain->size[0];
      newDomain->size[0] = r4->size[0];
      emxEnsureCapacity_real_T(&st, newDomain, i, &he_emlrtRTEI);
      input_sizes_idx_0 = r4->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        newDomain->data[i] = 0.5 * (dataPoints->data[r4->data[i] - 1] +
                                    dataPoints->data[r5->data[i] - 1]);
      }
      emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &newDomain->size[0], 1,
                                    &n_emlrtECI, &st);
      input_sizes_idx_0 = newDomain->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        newDataPoints->data[i] = newDomain->data[i];
      }
      input_sizes_idx_0 = newDataPoints->size[0];
      i = hiVal->size[0];
      hiVal->size[0] = newDataPoints->size[0];
      emxEnsureCapacity_real_T(&st, hiVal, i, &ie_emlrtRTEI);
      for (i = 0; i < input_sizes_idx_0; i++) {
        hiVal->data[i] = newDataPoints->data[i];
      }
      b_st.site = &df_emlrtRSI;
      normalizeFunction(&b_st, hiVal, sldProfile, newDomain);
      emlrtSubAssignSizeCheckR2012b(&newDataPoints->size[0], 1,
                                    &newDomain->size[0], 1, &o_emlrtECI, &st);
      input_sizes_idx_0 = newDomain->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        newDataPoints->data[i + newDataPoints->size[0]] = newDomain->data[i];
      }
      /*  For simplicity append the new points at the end and then sort. */
      b_st.site = &ef_emlrtRSI;
      c_st.site = &ff_emlrtRSI;
      d_st.site = &x_emlrtRSI;
      input_sizes_idx_0 = dataPoints->size[0];
      if (newDataPoints->size[0] != 0) {
        b_input_sizes_idx_0 = newDataPoints->size[0];
      } else {
        b_input_sizes_idx_0 = 0;
      }
      trueCount = dataPoints->size[0];
      i = b_dataPoints->size[0] * b_dataPoints->size[1];
      b_dataPoints->size[0] = dataPoints->size[0] + b_input_sizes_idx_0;
      b_dataPoints->size[1] = 2;
      emxEnsureCapacity_real_T(&st, b_dataPoints, i, &je_emlrtRTEI);
      for (i = 0; i < 2; i++) {
        for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
          b_dataPoints->data[b_i + b_dataPoints->size[0] * i] =
              dataPoints->data[b_i + dataPoints->size[0] * i];
        }
      }
      for (i = 0; i < 2; i++) {
        for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
          b_dataPoints->data[(b_i + trueCount) + b_dataPoints->size[0] * i] =
              newDataPoints->data[b_i + newDataPoints->size[0] * i];
        }
      }
      i = dataPoints->size[0] * dataPoints->size[1];
      dataPoints->size[0] = b_dataPoints->size[0];
      dataPoints->size[1] = 2;
      emxEnsureCapacity_real_T(&st, dataPoints, i, &ke_emlrtRTEI);
      input_sizes_idx_0 = b_dataPoints->size[0] * 2;
      for (i = 0; i < input_sizes_idx_0; i++) {
        dataPoints->data[i] = b_dataPoints->data[i];
      }
      b_st.site = &ef_emlrtRSI;
      sortrows(&b_st, dataPoints);
      /*  Removed waitbar for compile - AVH */
      /*    if displayWaitbar */
      /*      if getappdata(refinementWaitbar,'canceling'), break; end */
      /*      waitbar(nRefinements/maxRefinements,refinementWaitbar); */
      /*    end */
      nRefinements++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    } else {
      exitg1 = true;
    }
  }
  emxFree_real_T(&b_dataPoints);
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
  i = out->f1->size[0] * out->f1->size[1];
  out->f1->size[0] = dataPoints->size[0];
  out->f1->size[1] = 2;
  emxEnsureCapacity_real_T(sp, out->f1, i, &wd_emlrtRTEI);
  input_sizes_idx_0 = dataPoints->size[0] * 2;
  for (i = 0; i < input_sizes_idx_0; i++) {
    out->f1->data[i] = dataPoints->data[i];
  }
  emxFree_real_T(&dataPoints);
  /*  elseif nargout>1 */
  /*    out{1} = dataPoints(:,1); */
  /*    out{2} = dataPoints(:,2:end); */
  /*  end */
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (adaptive_new.c) */
