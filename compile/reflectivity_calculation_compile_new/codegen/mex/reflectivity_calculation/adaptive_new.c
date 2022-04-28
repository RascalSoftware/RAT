/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
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
#include "assertCompatibleDims.h"
#include "div.h"
#include "eml_int_forloop_overflow_check.h"
#include "eml_mtimes_helper.h"
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
static emlrtRSInfo wd_emlrtRSI = {
    241,            /* lineNo */
    "adaptive_new", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo xd_emlrtRSI = {
    252,            /* lineNo */
    "adaptive_new", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo yd_emlrtRSI = {
    255,            /* lineNo */
    "adaptive_new", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo ae_emlrtRSI = {
    267,            /* lineNo */
    "adaptive_new", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo be_emlrtRSI = {
    281,            /* lineNo */
    "adaptive_new", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo ce_emlrtRSI = {
    304,            /* lineNo */
    "adaptive_new", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo de_emlrtRSI = {
    305,            /* lineNo */
    "adaptive_new", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo ee_emlrtRSI = {
    376,                 /* lineNo */
    "normalizeFunction", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo fe_emlrtRSI = {
    24,        /* lineNo */
    "sldFunc", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m" /* pathName */
};

static emlrtRSInfo ge_emlrtRSI = {
    29,        /* lineNo */
    "sldFunc", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m" /* pathName */
};

static emlrtRSInfo he_emlrtRSI = {
    30,        /* lineNo */
    "sldFunc", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m" /* pathName */
};

static emlrtRSInfo me_emlrtRSI =
    {
        221,             /* lineNo */
        "unaryMinOrMax", /* fcnName */
        "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo ne_emlrtRSI =
    {
        314,                     /* lineNo */
        "unaryMinOrMaxDispatch", /* fcnName */
        "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo oe_emlrtRSI =
    {
        382,          /* lineNo */
        "minOrMax2D", /* fcnName */
        "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo pe_emlrtRSI =
    {
        464,                         /* lineNo */
        "minOrMax2DColumnMajorDim1", /* fcnName */
        "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo qe_emlrtRSI = {
    15,    /* lineNo */
    "min", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/datafun/min.m" /* pathName
                                                                     */
};

static emlrtRSInfo re_emlrtRSI = {
    46,         /* lineNo */
    "minOrMax", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                            */
};

static emlrtRSInfo se_emlrtRSI = {
    92,        /* lineNo */
    "minimum", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                            */
};

static emlrtRSInfo te_emlrtRSI = {
    398,                      /* lineNo */
    "calculateCentralAngles", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo ue_emlrtRSI = {
    399,                      /* lineNo */
    "calculateCentralAngles", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo ve_emlrtRSI = {
    401,                      /* lineNo */
    "calculateCentralAngles", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo we_emlrtRSI = {
    403,                      /* lineNo */
    "calculateCentralAngles", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo xe_emlrtRSI = {
    404,                      /* lineNo */
    "calculateCentralAngles", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo ye_emlrtRSI = {
    405,                      /* lineNo */
    "calculateCentralAngles", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo af_emlrtRSI = {
    408,                      /* lineNo */
    "calculateCentralAngles", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo bf_emlrtRSI = {
    407,                      /* lineNo */
    "calculateCentralAngles", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo cf_emlrtRSI = {
    409,                      /* lineNo */
    "calculateCentralAngles", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo hf_emlrtRSI = {
    16,                                                            /* lineNo */
    "sqrt",                                                        /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/elfun/sqrt.m" /* pathName
                                                                    */
};

static emlrtRSInfo mf_emlrtRSI = {
    431,                /* lineNo */
    "increaseSampling", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo nf_emlrtRSI = {
    433,                /* lineNo */
    "increaseSampling", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo of_emlrtRSI = {
    28,    /* lineNo */
    "cat", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/cat.m" /* pathName
                                                                       */
};

static emlrtECInfo f_emlrtECI = {
    1,              /* nDims */
    283,            /* lineNo */
    25,             /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtECInfo g_emlrtECI = {
    1,              /* nDims */
    289,            /* lineNo */
    21,             /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo kb_emlrtRTEI =
    {
        28,              /* lineNo */
        27,              /* colNo */
        "unaryMinOrMax", /* fName */
        "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pName */
};

static emlrtRTEInfo lb_emlrtRTEI =
    {
        130,             /* lineNo */
        27,              /* colNo */
        "unaryMinOrMax", /* fName */
        "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pName */
};

static emlrtECInfo h_emlrtECI = {
    1,                  /* nDims */
    429,                /* lineNo */
    29,                 /* colNo */
    "increaseSampling", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtECInfo i_emlrtECI = {
    -1,                 /* nDims */
    429,                /* lineNo */
    1,                  /* colNo */
    "increaseSampling", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtECInfo j_emlrtECI = {
    -1,                 /* nDims */
    431,                /* lineNo */
    1,                  /* colNo */
    "increaseSampling", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtBCInfo kg_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    425,                /* lineNo */
    39,                 /* colNo */
    "segmentsToSplit",  /* aName */
    "increaseSampling", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo lg_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    429,                /* lineNo */
    40,                 /* colNo */
    "dataPoints",       /* aName */
    "increaseSampling", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo mg_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    430,                /* lineNo */
    14,                 /* colNo */
    "dataPoints",       /* aName */
    "increaseSampling", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo ng_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    376,                 /* lineNo */
    22,                  /* colNo */
    "x",                 /* aName */
    "normalizeFunction", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtECInfo k_emlrtECI = {
    -1,                  /* nDims */
    376,                 /* lineNo */
    5,                   /* colNo */
    "normalizeFunction", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtBCInfo og_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    31,          /* lineNo */
    23,          /* colNo */
    "belowVals", /* aName */
    "sldFunc",   /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo pg_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    32,          /* lineNo */
    23,          /* colNo */
    "aboveVals", /* aName */
    "sldFunc",   /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo qg_emlrtBCI = {
    -1,        /* iFirst */
    -1,        /* iLast */
    34,        /* lineNo */
    18,        /* colNo */
    "rho",     /* aName */
    "sldFunc", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo rg_emlrtBCI = {
    -1,        /* iFirst */
    -1,        /* iLast */
    35,        /* lineNo */
    18,        /* colNo */
    "rho",     /* aName */
    "sldFunc", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo sg_emlrtBCI = {
    -1,        /* iFirst */
    -1,        /* iLast */
    38,        /* lineNo */
    26,        /* colNo */
    "z",       /* aName */
    "sldFunc", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo tg_emlrtBCI = {
    -1,        /* iFirst */
    -1,        /* iLast */
    42,        /* lineNo */
    20,        /* colNo */
    "z",       /* aName */
    "sldFunc", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ug_emlrtBCI = {
    -1,        /* iFirst */
    -1,        /* iLast */
    27,        /* lineNo */
    18,        /* colNo */
    "rho",     /* aName */
    "sldFunc", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo vg_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    376,                 /* lineNo */
    7,                   /* colNo */
    "y",                 /* aName */
    "normalizeFunction", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtECInfo l_emlrtECI = {
    1,                        /* nDims */
    398,                      /* lineNo */
    3,                        /* colNo */
    "calculateCentralAngles", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtECInfo m_emlrtECI = {
    1,                        /* nDims */
    403,                      /* lineNo */
    21,                       /* colNo */
    "calculateCentralAngles", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtECInfo n_emlrtECI = {
    1,                        /* nDims */
    404,                      /* lineNo */
    21,                       /* colNo */
    "calculateCentralAngles", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtECInfo o_emlrtECI = {
    1,                        /* nDims */
    405,                      /* lineNo */
    21,                       /* colNo */
    "calculateCentralAngles", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtECInfo p_emlrtECI = {
    1,                        /* nDims */
    407,                      /* lineNo */
    4,                        /* colNo */
    "calculateCentralAngles", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtECInfo q_emlrtECI = {
    1,                        /* nDims */
    408,                      /* lineNo */
    8,                        /* colNo */
    "calculateCentralAngles", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtBCInfo wg_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    386,                       /* lineNo */
    20,                        /* colNo */
    "XYdata",                  /* aName */
    "calculateTrianglesSides", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo xg_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    386,                       /* lineNo */
    22,                        /* colNo */
    "XYdata",                  /* aName */
    "calculateTrianglesSides", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo yg_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    386,                       /* lineNo */
    40,                        /* colNo */
    "XYdata",                  /* aName */
    "calculateTrianglesSides", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo ah_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    386,                       /* lineNo */
    42,                        /* colNo */
    "XYdata",                  /* aName */
    "calculateTrianglesSides", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtECInfo r_emlrtECI = {
    1,                         /* nDims */
    386,                       /* lineNo */
    13,                        /* colNo */
    "calculateTrianglesSides", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtBCInfo bh_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    387,                       /* lineNo */
    41,                        /* colNo */
    "XYdata",                  /* aName */
    "calculateTrianglesSides", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo ch_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    387,                       /* lineNo */
    43,                        /* colNo */
    "XYdata",                  /* aName */
    "calculateTrianglesSides", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtECInfo s_emlrtECI = {
    1,                         /* nDims */
    387,                       /* lineNo */
    14,                        /* colNo */
    "calculateTrianglesSides", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtBCInfo dh_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    388,                       /* lineNo */
    40,                        /* colNo */
    "XYdata",                  /* aName */
    "calculateTrianglesSides", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtBCInfo eh_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    388,                       /* lineNo */
    42,                        /* colNo */
    "XYdata",                  /* aName */
    "calculateTrianglesSides", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m", /* pName */
    0                 /* checkKind */
};

static emlrtECInfo t_emlrtECI = {
    1,                         /* nDims */
    388,                       /* lineNo */
    13,                        /* colNo */
    "calculateTrianglesSides", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = {
    13,                                                            /* lineNo */
    9,                                                             /* colNo */
    "sqrt",                                                        /* fName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/elfun/sqrt.m" /* pName */
};

static emlrtBCInfo yx_emlrtBCI = {
    -1,        /* iFirst */
    -1,        /* iLast */
    21,        /* lineNo */
    11,        /* colNo */
    "SLD",     /* aName */
    "sldFunc", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo ay_emlrtBCI = {
    -1,        /* iFirst */
    -1,        /* iLast */
    22,        /* lineNo */
    13,        /* colNo */
    "SLD",     /* aName */
    "sldFunc", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m", /* pName */
    0            /* checkKind */
};

static emlrtRTEInfo vi_emlrtRTEI = {
    241,            /* lineNo */
    3,              /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo wi_emlrtRTEI = {
    255,            /* lineNo */
    1,              /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo xi_emlrtRTEI = {
    334,            /* lineNo */
    2,              /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo yi_emlrtRTEI = {
    281,            /* lineNo */
    42,             /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo aj_emlrtRTEI = {
    282,            /* lineNo */
    5,              /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo bj_emlrtRTEI = {
    283,            /* lineNo */
    5,              /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo cj_emlrtRTEI = {
    289,            /* lineNo */
    21,             /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo dj_emlrtRTEI = {
    289,            /* lineNo */
    50,             /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo ej_emlrtRTEI = {
    426,            /* lineNo */
    1,              /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo fj_emlrtRTEI = {
    429,            /* lineNo */
    40,             /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo gj_emlrtRTEI = {
    430,            /* lineNo */
    14,             /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo hj_emlrtRTEI = {
    305,            /* lineNo */
    18,             /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo jj_emlrtRTEI = {
    431,            /* lineNo */
    40,             /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo kj_emlrtRTEI = {
    295,   /* lineNo */
    14,    /* colNo */
    "cat", /* fName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/cat.m" /* pName
                                                                       */
};

static emlrtRTEInfo lj_emlrtRTEI = {
    305,            /* lineNo */
    5,              /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo mj_emlrtRTEI = {
    252,            /* lineNo */
    1,              /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo nj_emlrtRTEI = {
    289,            /* lineNo */
    3,              /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo oj_emlrtRTEI = {
    241,            /* lineNo */
    15,             /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo qj_emlrtRTEI = {
    360,            /* lineNo */
    5,              /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo rj_emlrtRTEI = {
    24,        /* lineNo */
    14,        /* colNo */
    "sldFunc", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m" /* pName */
};

static emlrtRTEInfo sj_emlrtRTEI = {
    24,        /* lineNo */
    1,         /* colNo */
    "sldFunc", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m" /* pName */
};

static emlrtRTEInfo tj_emlrtRTEI = {
    376,            /* lineNo */
    12,             /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo uj_emlrtRTEI = {
    29,        /* lineNo */
    22,        /* colNo */
    "sldFunc", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m" /* pName */
};

static emlrtRTEInfo vj_emlrtRTEI = {
    29,        /* lineNo */
    5,         /* colNo */
    "sldFunc", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m" /* pName */
};

static emlrtRTEInfo wj_emlrtRTEI = {
    30,        /* lineNo */
    22,        /* colNo */
    "sldFunc", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m" /* pName */
};

static emlrtRTEInfo xj_emlrtRTEI = {
    30,        /* lineNo */
    5,         /* colNo */
    "sldFunc", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "sldFunc.m" /* pName */
};

static emlrtRTEInfo ck_emlrtRTEI = {
    398,            /* lineNo */
    3,              /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo dk_emlrtRTEI = {
    397,            /* lineNo */
    1,              /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo ek_emlrtRTEI = {
    386,            /* lineNo */
    1,              /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo fk_emlrtRTEI = {
    387,            /* lineNo */
    1,              /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo gk_emlrtRTEI = {
    388,            /* lineNo */
    1,              /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo hk_emlrtRTEI = {
    403,            /* lineNo */
    21,             /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo ik_emlrtRTEI = {
    403,            /* lineNo */
    42,             /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo jk_emlrtRTEI = {
    404,            /* lineNo */
    21,             /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo kk_emlrtRTEI = {
    404,            /* lineNo */
    42,             /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo lk_emlrtRTEI = {
    405,            /* lineNo */
    21,             /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo mk_emlrtRTEI = {
    405,            /* lineNo */
    42,             /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo nk_emlrtRTEI = {
    407,            /* lineNo */
    4,              /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo ok_emlrtRTEI = {
    409,            /* lineNo */
    20,             /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo pk_emlrtRTEI = {
    409,            /* lineNo */
    1,              /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo qk_emlrtRTEI = {
    403,            /* lineNo */
    1,              /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo rk_emlrtRTEI = {
    404,            /* lineNo */
    1,              /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo sk_emlrtRTEI = {
    405,            /* lineNo */
    1,              /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo tk_emlrtRTEI = {
    391,            /* lineNo */
    24,             /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo uk_emlrtRTEI = {
    407,            /* lineNo */
    3,              /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo nt_emlrtRTEI = {
    283,            /* lineNo */
    25,             /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRTEInfo ot_emlrtRTEI = {
    408,            /* lineNo */
    8,              /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

static emlrtRSInfo jj_emlrtRSI = {
    289,            /* lineNo */
    "adaptive_new", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo kj_emlrtRSI = {
    283,            /* lineNo */
    "adaptive_new", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo lj_emlrtRSI = {
    397,                      /* lineNo */
    "calculateCentralAngles", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo nj_emlrtRSI = {
    387,                       /* lineNo */
    "calculateTrianglesSides", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo oj_emlrtRSI = {
    388,                       /* lineNo */
    "calculateTrianglesSides", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

static emlrtRSInfo pj_emlrtRSI = {
    386,                       /* lineNo */
    "calculateTrianglesSides", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pathName */
};

/* Function Declarations */
static void b_normalizeFunction(const emlrtStack *sp, const emxArray_real_T *x,
                                const emxArray_real_T *sldProfile,
                                emxArray_real_T *y);

static void b_plus(const emlrtStack *sp, emxArray_real_T *longStepSquared,
                   const emxArray_real_T *x);

static void calculateCentralAngles(const emlrtStack *sp,
                                   const emxArray_real_T *XYdata,
                                   const real_T dataBoxSize[2],
                                   emxArray_real_T *cornerAngle);

static void d_binary_expand_op(const emlrtStack *sp,
                               emxArray_boolean_T *sharpCorners,
                               const emxArray_real_T *dataPoints);

static void e_binary_expand_op(const emlrtStack *sp, emxArray_creal_T *r1,
                               const emxArray_real_T *x,
                               const emxArray_real_T *firstStepSquared);

static void f_binary_expand_op(const emlrtStack *sp, emxArray_real_T *x,
                               const emxArray_real_T *longStepSquared);

static void g_binary_expand_op(const emlrtStack *sp, emxArray_real_T *longStep,
                               const emxArray_real_T *normalizedData,
                               int32_T i2, int32_T i3, int32_T i4);

static void h_binary_expand_op(const emlrtStack *sp,
                               emxArray_real_T *secondStep,
                               const emxArray_real_T *normalizedData,
                               int32_T i2, int32_T i3, int32_T i4, int32_T i5);

static void minus(const emlrtStack *sp, emxArray_real_T *normalizedData,
                  const emxArray_real_T *longStep);

static void normalizeFunction(const emlrtStack *sp, const emxArray_real_T *x,
                              const emxArray_real_T *sldProfile,
                              emxArray_real_T *y);

static void or (const emlrtStack *sp, emxArray_boolean_T *segmentsToSplit,
                const emxArray_boolean_T *r1);

static void plus(const emlrtStack *sp, emxArray_real_T *x,
                 const emxArray_real_T *firstStepSquared,
                 const emxArray_real_T *secondStepSquared);

static void times(const emlrtStack *sp, emxArray_real_T *firstStepSquared,
                  const emxArray_real_T *secondStepSquared);

/* Function Definitions */
static void b_normalizeFunction(const emlrtStack *sp, const emxArray_real_T *x,
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
  const real_T *sldProfile_data;
  const real_T *x_data;
  real_T deltaY;
  real_T deltaY_tmp;
  real_T *aboveVals_data;
  real_T *y_data;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T *ii_data;
  int32_T *where_data;
  boolean_T *b_sldProfile_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  sldProfile_data = sldProfile->data;
  x_data = x->data;
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
  emxEnsureCapacity_real_T(sp, y, i, &qj_emlrtRTEI);
  y_data = y->data;
  /*  if vectorizable */
  /*    % For uniformity reasons, transform the 'x' array into a column vector.
   */
  /*    % In this way it does not matter if it is given as a column or a row */
  /*    % vector. */
  /*    [newValues{:}] = func(x(:)); */
  /*    y = cell2mat(newValues); */
  /*  else */
  i = x->size[0];
  emxInit_int32_T(sp, &where, &sj_emlrtRTEI);
  emxInit_real_T(sp, &aboveVals, 1, &xj_emlrtRTEI, true);
  emxInit_int32_T(sp, &ii, &yj_emlrtRTEI);
  emxInit_boolean_T(sp, &b_sldProfile, &rj_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    /*  Remove cell array so no need for cell2mat */
    /*  which won't compile - AVH */
    /* [newValues{:}] = func(x(i)); */
    /* y(i,:) = cell2mat(newValues); */
    st.site = &ee_emlrtRSI;
    if (b_i + 1 > x->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, x->size[0], &ng_emlrtBCI, &st);
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
      emlrtDynamicBoundsCheckR2012b(1, 1, sldProfile->size[1], &yx_emlrtBCI,
                                    &st);
    }
    if (2 > sldProfile->size[1]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, sldProfile->size[1], &ay_emlrtBCI,
                                    &st);
    }
    b_st.site = &fe_emlrtRSI;
    loop_ub = sldProfile->size[0];
    i1 = b_sldProfile->size[0];
    b_sldProfile->size[0] = sldProfile->size[0];
    emxEnsureCapacity_boolean_T(&b_st, b_sldProfile, i1, &rj_emlrtRTEI);
    b_sldProfile_data = b_sldProfile->data;
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_sldProfile_data[i1] = (sldProfile_data[i1] == x_data[b_i]);
    }
    c_st.site = &ie_emlrtRSI;
    eml_find(&c_st, b_sldProfile, ii);
    ii_data = ii->data;
    i1 = where->size[0];
    where->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(&b_st, where, i1, &sj_emlrtRTEI);
    where_data = where->data;
    loop_ub = ii->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      where_data[i1] = ii_data[i1];
    }
    if (where->size[0] != 0) {
      i1 = aboveVals->size[0];
      aboveVals->size[0] = where->size[0];
      emxEnsureCapacity_real_T(&st, aboveVals, i1, &tj_emlrtRTEI);
      aboveVals_data = aboveVals->data;
      loop_ub = where->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        if ((where_data[i1] < 1) || (where_data[i1] > sldProfile->size[0])) {
          emlrtDynamicBoundsCheckR2012b(where_data[i1], 1, sldProfile->size[0],
                                        &ug_emlrtBCI, &st);
        }
        aboveVals_data[i1] =
            sldProfile_data[(where_data[i1] + sldProfile->size[0]) - 1];
      }
    } else {
      b_st.site = &ge_emlrtRSI;
      loop_ub = sldProfile->size[0];
      i1 = b_sldProfile->size[0];
      b_sldProfile->size[0] = sldProfile->size[0];
      emxEnsureCapacity_boolean_T(&b_st, b_sldProfile, i1, &uj_emlrtRTEI);
      b_sldProfile_data = b_sldProfile->data;
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_sldProfile_data[i1] = (x_data[b_i] > sldProfile_data[i1]);
      }
      c_st.site = &ie_emlrtRSI;
      eml_find(&c_st, b_sldProfile, ii);
      ii_data = ii->data;
      i1 = where->size[0];
      where->size[0] = ii->size[0];
      emxEnsureCapacity_int32_T(&b_st, where, i1, &vj_emlrtRTEI);
      where_data = where->data;
      loop_ub = ii->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        where_data[i1] = ii_data[i1];
      }
      b_st.site = &he_emlrtRSI;
      loop_ub = sldProfile->size[0];
      i1 = b_sldProfile->size[0];
      b_sldProfile->size[0] = sldProfile->size[0];
      emxEnsureCapacity_boolean_T(&b_st, b_sldProfile, i1, &wj_emlrtRTEI);
      b_sldProfile_data = b_sldProfile->data;
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_sldProfile_data[i1] = (x_data[b_i] < sldProfile_data[i1]);
      }
      c_st.site = &ie_emlrtRSI;
      eml_find(&c_st, b_sldProfile, ii);
      ii_data = ii->data;
      i1 = aboveVals->size[0];
      aboveVals->size[0] = ii->size[0];
      emxEnsureCapacity_real_T(&b_st, aboveVals, i1, &xj_emlrtRTEI);
      aboveVals_data = aboveVals->data;
      loop_ub = ii->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        aboveVals_data[i1] = ii_data[i1];
      }
      if (where->size[0] < 1) {
        emlrtDynamicBoundsCheckR2012b(where->size[0], 1, where->size[0],
                                      &og_emlrtBCI, &st);
      }
      if (1 > aboveVals->size[0]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, aboveVals->size[0], &pg_emlrtBCI,
                                      &st);
      }
      i1 = where_data[where->size[0] - 1];
      if ((i1 < 1) || (i1 > sldProfile->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, sldProfile->size[0], &qg_emlrtBCI,
                                      &st);
      }
      if (((int32_T)aboveVals_data[0] < 1) ||
          ((int32_T)aboveVals_data[0] > sldProfile->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)aboveVals_data[0], 1,
                                      sldProfile->size[0], &rg_emlrtBCI, &st);
      }
      i1 = where_data[where->size[0] - 1];
      if ((i1 < 1) || (i1 > sldProfile->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, sldProfile->size[0], &sg_emlrtBCI,
                                      &st);
      }
      i1 = where_data[where->size[0] - 1];
      if ((i1 < 1) || (i1 > sldProfile->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, sldProfile->size[0], &tg_emlrtBCI,
                                      &st);
      }
      deltaY_tmp =
          sldProfile_data[((int32_T)aboveVals_data[0] + sldProfile->size[0]) -
                          1];
      deltaY =
          (x_data[b_i] - sldProfile_data[where_data[where->size[0] - 1] - 1]) *
          (muDoubleScalarAbs(deltaY_tmp -
                             sldProfile_data[(where_data[where->size[0] - 1] +
                                              sldProfile->size[0]) -
                                             1]) /
           (sldProfile_data[(int32_T)aboveVals_data[0] - 1] -
            sldProfile_data[where_data[where->size[0] - 1] - 1]));
      if (sldProfile_data[(where_data[where->size[0] - 1] +
                           sldProfile->size[0]) -
                          1] < deltaY_tmp) {
        i1 = aboveVals->size[0];
        aboveVals->size[0] = 1;
        emxEnsureCapacity_real_T(&st, aboveVals, i1, &tj_emlrtRTEI);
        aboveVals_data = aboveVals->data;
        aboveVals_data[0] = sldProfile_data[(where_data[where->size[0] - 1] +
                                             sldProfile->size[0]) -
                                            1] +
                            deltaY;
      } else {
        i1 = aboveVals->size[0];
        aboveVals->size[0] = 1;
        emxEnsureCapacity_real_T(&st, aboveVals, i1, &tj_emlrtRTEI);
        aboveVals_data = aboveVals->data;
        aboveVals_data[0] = sldProfile_data[(where_data[where->size[0] - 1] +
                                             sldProfile->size[0]) -
                                            1] -
                            deltaY;
      }
      /* sldVal = interp1(z,rho,x); */
    }
    if (1 != aboveVals->size[0]) {
      emlrtSubAssignSizeCheck1dR2017a(1, aboveVals->size[0], &k_emlrtECI,
                                      (emlrtCTX)sp);
    }
    if (b_i + 1 > y->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, y->size[0], &vg_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    y_data[b_i] = aboveVals_data[0];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_boolean_T(sp, &b_sldProfile);
  emxFree_int32_T(sp, &ii);
  emxFree_real_T(sp, &aboveVals);
  emxFree_int32_T(sp, &where);
  /* end */
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void b_plus(const emlrtStack *sp, emxArray_real_T *longStepSquared,
                   const emxArray_real_T *x)
{
  emxArray_real_T *b_longStepSquared;
  const real_T *x_data;
  real_T *b_longStepSquared_data;
  real_T *longStepSquared_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  x_data = x->data;
  longStepSquared_data = longStepSquared->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_longStepSquared, 1, &lk_emlrtRTEI, true);
  i = b_longStepSquared->size[0];
  if (x->size[0] == 1) {
    b_longStepSquared->size[0] = longStepSquared->size[0];
  } else {
    b_longStepSquared->size[0] = x->size[0];
  }
  emxEnsureCapacity_real_T(sp, b_longStepSquared, i, &lk_emlrtRTEI);
  b_longStepSquared_data = b_longStepSquared->data;
  stride_0_0 = (longStepSquared->size[0] != 1);
  stride_1_0 = (x->size[0] != 1);
  if (x->size[0] == 1) {
    loop_ub = longStepSquared->size[0];
  } else {
    loop_ub = x->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    b_longStepSquared_data[i] =
        longStepSquared_data[i * stride_0_0] + x_data[i * stride_1_0];
  }
  i = longStepSquared->size[0];
  longStepSquared->size[0] = b_longStepSquared->size[0];
  emxEnsureCapacity_real_T(sp, longStepSquared, i, &lk_emlrtRTEI);
  longStepSquared_data = longStepSquared->data;
  loop_ub = b_longStepSquared->size[0];
  for (i = 0; i < loop_ub; i++) {
    longStepSquared_data[i] = b_longStepSquared_data[i];
  }
  emxFree_real_T(sp, &b_longStepSquared);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

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
  emxArray_creal_T *r;
  emxArray_real_T *b_firstStep;
  emxArray_real_T *firstStep;
  emxArray_real_T *firstStepSquared;
  emxArray_real_T *longStep;
  emxArray_real_T *longStepSquared;
  emxArray_real_T *normalizedData;
  emxArray_real_T *secondStep;
  emxArray_real_T *secondStepSquared;
  emxArray_real_T *x;
  creal_T *r1;
  real_T minval[2];
  const real_T *XYdata_data;
  real_T b;
  real_T *firstStepSquared_data;
  real_T *longStepSquared_data;
  real_T *longStep_data;
  real_T *normalizedData_data;
  real_T *secondStepSquared_data;
  real_T *secondStep_data;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T j;
  int32_T m;
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
  XYdata_data = XYdata->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &normalizedData, 2, &dk_emlrtRTEI, true);
  /*  Calculate the central angle of the triangles formed by data points. */
  /*  For input size NxM, the output size is (N-2)xN, because the first and the
   */
  /*  last point are not the central corner of any triangle. */
  /*  Normalize data, because angles depend on scaling. */
  st.site = &te_emlrtRSI;
  b_st.site = &te_emlrtRSI;
  repmat(&b_st, dataBoxSize, XYdata->size[0], normalizedData);
  b_st.site = &ff_emlrtRSI;
  c_st.site = &gf_emlrtRSI;
  if ((XYdata->size[0] != 1) && (normalizedData->size[0] != 1) &&
      (XYdata->size[0] != normalizedData->size[0])) {
    emlrtErrorWithMessageIdR2018a(&c_st, &ob_emlrtRTEI,
                                  "MATLAB:sizeDimensionsMustMatch",
                                  "MATLAB:sizeDimensionsMustMatch", 0);
  }
  if (XYdata->size[0] == normalizedData->size[0]) {
    m = XYdata->size[0] * 2;
    i = normalizedData->size[0] * normalizedData->size[1];
    normalizedData->size[0] = XYdata->size[0];
    normalizedData->size[1] = 2;
    emxEnsureCapacity_real_T(&b_st, normalizedData, i, &ck_emlrtRTEI);
    normalizedData_data = normalizedData->data;
    for (i = 0; i < m; i++) {
      normalizedData_data[i] = XYdata_data[i] / normalizedData_data[i];
    }
  } else {
    c_st.site = &mj_emlrtRSI;
    rdivide(&c_st, normalizedData, XYdata);
  }
  st.site = &ue_emlrtRSI;
  b_st.site = &qe_emlrtRSI;
  c_st.site = &re_emlrtRSI;
  d_st.site = &se_emlrtRSI;
  if (XYdata->size[0] == 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &kb_emlrtRTEI,
                                  "Coder:toolbox:autoDimIncompatibility",
                                  "Coder:toolbox:autoDimIncompatibility", 0);
  }
  if (XYdata->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &lb_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &me_emlrtRSI;
  f_st.site = &ne_emlrtRSI;
  g_st.site = &oe_emlrtRSI;
  m = XYdata->size[0];
  overflow = ((2 <= XYdata->size[0]) && (XYdata->size[0] > 2147483646));
  for (j = 0; j < 2; j++) {
    minval[j] = XYdata_data[XYdata->size[0] * j];
    h_st.site = &pe_emlrtRSI;
    if (overflow) {
      i_st.site = &j_emlrtRSI;
      check_forloop_overflow_error(&i_st);
    }
    for (b_i = 2; b_i <= m; b_i++) {
      b = XYdata_data[(b_i + XYdata->size[0] * j) - 1];
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
  emxInit_real_T(&g_st, &longStep, 2, &tk_emlrtRTEI, true);
  st.site = &ue_emlrtRSI;
  repmat(&st, minval, XYdata->size[0], longStep);
  longStep_data = longStep->data;
  if ((normalizedData->size[0] != longStep->size[0]) &&
      ((normalizedData->size[0] != 1) && (longStep->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(normalizedData->size[0], longStep->size[0],
                                &l_emlrtECI, (emlrtCTX)sp);
  }
  if (normalizedData->size[0] == longStep->size[0]) {
    m = normalizedData->size[0] * 2;
    i = normalizedData->size[0] * normalizedData->size[1];
    normalizedData->size[1] = 2;
    emxEnsureCapacity_real_T(sp, normalizedData, i, &dk_emlrtRTEI);
    normalizedData_data = normalizedData->data;
    for (i = 0; i < m; i++) {
      normalizedData_data[i] -= longStep_data[i];
    }
  } else {
    st.site = &lj_emlrtRSI;
    minus(&st, normalizedData, longStep);
    normalizedData_data = normalizedData->data;
  }
  /*  calculate cosine of central angles */
  st.site = &ve_emlrtRSI;
  /*  Return the sides (deltaX, deltaY) of the triangles formed by data points.
   */
  /*  For input size NxM, the output size is (N-2)xN, because the first and the
   */
  /*  last point are not the central corner of any triangle. */
  if (2 > normalizedData->size[0] - 1) {
    i = -1;
    b_i = -1;
  } else {
    if (2 > normalizedData->size[0]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, normalizedData->size[0], &wg_emlrtBCI,
                                    &st);
    }
    i = 0;
    if ((normalizedData->size[0] - 1 < 1) ||
        (normalizedData->size[0] - 1 > normalizedData->size[0])) {
      emlrtDynamicBoundsCheckR2012b(normalizedData->size[0] - 1, 1,
                                    normalizedData->size[0], &xg_emlrtBCI, &st);
    }
    b_i = normalizedData->size[0] - 2;
  }
  if (1 > normalizedData->size[0] - 2) {
    i1 = 0;
  } else {
    if (1 > normalizedData->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, normalizedData->size[0], &yg_emlrtBCI,
                                    &st);
    }
    if ((normalizedData->size[0] - 2 < 1) ||
        (normalizedData->size[0] - 2 > normalizedData->size[0])) {
      emlrtDynamicBoundsCheckR2012b(normalizedData->size[0] - 2, 1,
                                    normalizedData->size[0], &ah_emlrtBCI, &st);
    }
    i1 = normalizedData->size[0] - 2;
  }
  m = b_i - i;
  if ((m != i1) && ((m != 1) && (i1 != 1))) {
    emlrtDimSizeImpxCheckR2021b(m, i1, &r_emlrtECI, &st);
  }
  emxInit_real_T(&st, &firstStep, 2, &tk_emlrtRTEI, true);
  if (m == i1) {
    b_i = firstStep->size[0] * firstStep->size[1];
    firstStep->size[0] = m;
    firstStep->size[1] = 2;
    emxEnsureCapacity_real_T(&st, firstStep, b_i, &ek_emlrtRTEI);
    longStepSquared_data = firstStep->data;
    for (b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < m; i1++) {
        longStepSquared_data[i1 + firstStep->size[0] * b_i] =
            normalizedData_data[((i + i1) + normalizedData->size[0] * b_i) +
                                1] -
            normalizedData_data[i1 + normalizedData->size[0] * b_i];
      }
    }
  } else {
    b_st.site = &pj_emlrtRSI;
    g_binary_expand_op(&b_st, firstStep, normalizedData, i + 1, b_i, i1 - 1);
    longStepSquared_data = firstStep->data;
  }
  if (3 > normalizedData->size[0]) {
    i = -1;
    b_i = -1;
    i1 = -1;
    i2 = -1;
  } else {
    i = 1;
    b_i = normalizedData->size[0] - 1;
    if (2 > normalizedData->size[0]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, normalizedData->size[0], &bh_emlrtBCI,
                                    &st);
    }
    i1 = 0;
    if ((normalizedData->size[0] - 1 < 1) ||
        (normalizedData->size[0] - 1 > normalizedData->size[0])) {
      emlrtDynamicBoundsCheckR2012b(normalizedData->size[0] - 1, 1,
                                    normalizedData->size[0], &ch_emlrtBCI, &st);
    }
    i2 = normalizedData->size[0] - 2;
  }
  m = b_i - i;
  j = i2 - i1;
  if ((m != j) && ((m != 1) && (j != 1))) {
    emlrtDimSizeImpxCheckR2021b(m, j, &s_emlrtECI, &st);
  }
  emxInit_real_T(&st, &secondStep, 2, &tk_emlrtRTEI, true);
  if (m == j) {
    b_i = secondStep->size[0] * secondStep->size[1];
    secondStep->size[0] = m;
    secondStep->size[1] = 2;
    emxEnsureCapacity_real_T(&st, secondStep, b_i, &fk_emlrtRTEI);
    secondStep_data = secondStep->data;
    for (b_i = 0; b_i < 2; b_i++) {
      for (i2 = 0; i2 < m; i2++) {
        secondStep_data[i2 + secondStep->size[0] * b_i] =
            normalizedData_data[((i + i2) + normalizedData->size[0] * b_i) +
                                1] -
            normalizedData_data[((i1 + i2) + normalizedData->size[0] * b_i) +
                                1];
      }
    }
  } else {
    b_st.site = &nj_emlrtRSI;
    h_binary_expand_op(&b_st, secondStep, normalizedData, i + 1, b_i, i1 + 1,
                       i2);
    secondStep_data = secondStep->data;
  }
  if (3 > normalizedData->size[0]) {
    i = -1;
    b_i = -1;
    i1 = 0;
  } else {
    i = 1;
    b_i = normalizedData->size[0] - 1;
    if (1 > normalizedData->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, normalizedData->size[0], &dh_emlrtBCI,
                                    &st);
    }
    if ((normalizedData->size[0] - 2 < 1) ||
        (normalizedData->size[0] - 2 > normalizedData->size[0])) {
      emlrtDynamicBoundsCheckR2012b(normalizedData->size[0] - 2, 1,
                                    normalizedData->size[0], &eh_emlrtBCI, &st);
    }
    i1 = normalizedData->size[0] - 2;
  }
  m = b_i - i;
  if ((m != i1) && ((m != 1) && (i1 != 1))) {
    emlrtDimSizeImpxCheckR2021b(m, i1, &t_emlrtECI, &st);
  }
  if (m == i1) {
    b_i = longStep->size[0] * longStep->size[1];
    longStep->size[0] = m;
    longStep->size[1] = 2;
    emxEnsureCapacity_real_T(&st, longStep, b_i, &gk_emlrtRTEI);
    longStep_data = longStep->data;
    for (b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < m; i1++) {
        longStep_data[i1 + longStep->size[0] * b_i] =
            normalizedData_data[((i + i1) + normalizedData->size[0] * b_i) +
                                1] -
            normalizedData_data[i1 + normalizedData->size[0] * b_i];
      }
    }
  } else {
    b_st.site = &oj_emlrtRSI;
    g_binary_expand_op(&b_st, longStep, normalizedData, i + 1, b_i, i1 - 1);
    longStep_data = longStep->data;
  }
  emxFree_real_T(&st, &normalizedData);
  emxInit_real_T(&st, &b_firstStep, 1, &hk_emlrtRTEI, true);
  /*  calculate area of squares of length of triangle sides */
  m = firstStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = firstStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &hk_emlrtRTEI);
  normalizedData_data = b_firstStep->data;
  for (i = 0; i < m; i++) {
    normalizedData_data[i] = longStepSquared_data[i];
  }
  emxInit_real_T(sp, &firstStepSquared, 1, &qk_emlrtRTEI, true);
  st.site = &we_emlrtRSI;
  power(&st, b_firstStep, firstStepSquared);
  firstStepSquared_data = firstStepSquared->data;
  m = firstStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = firstStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &ik_emlrtRTEI);
  normalizedData_data = b_firstStep->data;
  for (i = 0; i < m; i++) {
    normalizedData_data[i] = longStepSquared_data[i + firstStep->size[0]];
  }
  emxFree_real_T(sp, &firstStep);
  emxInit_real_T(sp, &x, 1, &uk_emlrtRTEI, true);
  st.site = &we_emlrtRSI;
  power(&st, b_firstStep, x);
  normalizedData_data = x->data;
  if ((firstStepSquared->size[0] != x->size[0]) &&
      ((firstStepSquared->size[0] != 1) && (x->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(firstStepSquared->size[0], x->size[0],
                                &m_emlrtECI, (emlrtCTX)sp);
  }
  if (firstStepSquared->size[0] == x->size[0]) {
    m = firstStepSquared->size[0];
    for (i = 0; i < m; i++) {
      firstStepSquared_data[i] += normalizedData_data[i];
    }
  } else {
    st.site = &we_emlrtRSI;
    b_plus(&st, firstStepSquared, x);
    firstStepSquared_data = firstStepSquared->data;
  }
  m = secondStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = secondStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &jk_emlrtRTEI);
  normalizedData_data = b_firstStep->data;
  for (i = 0; i < m; i++) {
    normalizedData_data[i] = secondStep_data[i];
  }
  emxInit_real_T(sp, &secondStepSquared, 1, &rk_emlrtRTEI, true);
  st.site = &xe_emlrtRSI;
  power(&st, b_firstStep, secondStepSquared);
  secondStepSquared_data = secondStepSquared->data;
  m = secondStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = secondStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &kk_emlrtRTEI);
  normalizedData_data = b_firstStep->data;
  for (i = 0; i < m; i++) {
    normalizedData_data[i] = secondStep_data[i + secondStep->size[0]];
  }
  emxFree_real_T(sp, &secondStep);
  st.site = &xe_emlrtRSI;
  power(&st, b_firstStep, x);
  normalizedData_data = x->data;
  if ((secondStepSquared->size[0] != x->size[0]) &&
      ((secondStepSquared->size[0] != 1) && (x->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(secondStepSquared->size[0], x->size[0],
                                &n_emlrtECI, (emlrtCTX)sp);
  }
  if (secondStepSquared->size[0] == x->size[0]) {
    m = secondStepSquared->size[0];
    for (i = 0; i < m; i++) {
      secondStepSquared_data[i] += normalizedData_data[i];
    }
  } else {
    st.site = &xe_emlrtRSI;
    b_plus(&st, secondStepSquared, x);
    secondStepSquared_data = secondStepSquared->data;
  }
  m = longStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = longStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &lk_emlrtRTEI);
  normalizedData_data = b_firstStep->data;
  for (i = 0; i < m; i++) {
    normalizedData_data[i] = longStep_data[i];
  }
  emxInit_real_T(sp, &longStepSquared, 1, &sk_emlrtRTEI, true);
  st.site = &ye_emlrtRSI;
  power(&st, b_firstStep, longStepSquared);
  longStepSquared_data = longStepSquared->data;
  m = longStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = longStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &mk_emlrtRTEI);
  normalizedData_data = b_firstStep->data;
  for (i = 0; i < m; i++) {
    normalizedData_data[i] = longStep_data[i + longStep->size[0]];
  }
  emxFree_real_T(sp, &longStep);
  st.site = &ye_emlrtRSI;
  power(&st, b_firstStep, x);
  normalizedData_data = x->data;
  emxFree_real_T(sp, &b_firstStep);
  if ((longStepSquared->size[0] != x->size[0]) &&
      ((longStepSquared->size[0] != 1) && (x->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(longStepSquared->size[0], x->size[0],
                                &o_emlrtECI, (emlrtCTX)sp);
  }
  if (longStepSquared->size[0] == x->size[0]) {
    m = longStepSquared->size[0];
    for (i = 0; i < m; i++) {
      longStepSquared_data[i] += normalizedData_data[i];
    }
  } else {
    st.site = &ye_emlrtRSI;
    b_plus(&st, longStepSquared, x);
    longStepSquared_data = longStepSquared->data;
  }
  if ((firstStepSquared->size[0] != secondStepSquared->size[0]) &&
      ((firstStepSquared->size[0] != 1) && (secondStepSquared->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(firstStepSquared->size[0],
                                secondStepSquared->size[0], &p_emlrtECI,
                                (emlrtCTX)sp);
  }
  if (firstStepSquared->size[0] == secondStepSquared->size[0]) {
    i = x->size[0];
    x->size[0] = firstStepSquared->size[0];
    emxEnsureCapacity_real_T(sp, x, i, &nk_emlrtRTEI);
    normalizedData_data = x->data;
    m = firstStepSquared->size[0];
    for (i = 0; i < m; i++) {
      normalizedData_data[i] =
          firstStepSquared_data[i] + secondStepSquared_data[i];
    }
  } else {
    st.site = &bf_emlrtRSI;
    plus(&st, x, firstStepSquared, secondStepSquared);
    normalizedData_data = x->data;
  }
  if ((x->size[0] != longStepSquared->size[0]) &&
      ((x->size[0] != 1) && (longStepSquared->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(x->size[0], longStepSquared->size[0],
                                &p_emlrtECI, (emlrtCTX)sp);
  }
  if ((firstStepSquared->size[0] != secondStepSquared->size[0]) &&
      ((firstStepSquared->size[0] != 1) && (secondStepSquared->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(firstStepSquared->size[0],
                                secondStepSquared->size[0], &q_emlrtECI,
                                (emlrtCTX)sp);
  }
  st.site = &bf_emlrtRSI;
  if (x->size[0] == longStepSquared->size[0]) {
    m = x->size[0];
    for (i = 0; i < m; i++) {
      normalizedData_data[i] =
          (normalizedData_data[i] - longStepSquared_data[i]) / 2.0;
    }
  } else {
    b_st.site = &bf_emlrtRSI;
    f_binary_expand_op(&b_st, x, longStepSquared);
    normalizedData_data = x->data;
  }
  emxFree_real_T(&st, &longStepSquared);
  b_st.site = &af_emlrtRSI;
  if (firstStepSquared->size[0] == secondStepSquared->size[0]) {
    m = firstStepSquared->size[0];
    for (i = 0; i < m; i++) {
      firstStepSquared_data[i] *= secondStepSquared_data[i];
    }
  } else {
    c_st.site = &af_emlrtRSI;
    times(&c_st, firstStepSquared, secondStepSquared);
    firstStepSquared_data = firstStepSquared->data;
  }
  emxFree_real_T(&b_st, &secondStepSquared);
  p = false;
  i = firstStepSquared->size[0];
  for (j = 0; j < i; j++) {
    if (p || (firstStepSquared_data[j] < 0.0)) {
      p = true;
    }
  }
  if (p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &pb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  c_st.site = &hf_emlrtRSI;
  m = firstStepSquared->size[0];
  d_st.site = &if_emlrtRSI;
  if ((1 <= firstStepSquared->size[0]) &&
      (firstStepSquared->size[0] > 2147483646)) {
    e_st.site = &j_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  for (j = 0; j < m; j++) {
    firstStepSquared_data[j] = muDoubleScalarSqrt(firstStepSquared_data[j]);
  }
  b_st.site = &ff_emlrtRSI;
  c_st.site = &gf_emlrtRSI;
  assertCompatibleDims(&c_st, x, firstStepSquared);
  emxInit_creal_T(sp, &r, &ok_emlrtRTEI);
  if (x->size[0] == firstStepSquared->size[0]) {
    i = r->size[0];
    r->size[0] = x->size[0];
    emxEnsureCapacity_creal_T(sp, r, i, &ok_emlrtRTEI);
    r1 = r->data;
    m = x->size[0];
    for (i = 0; i < m; i++) {
      r1[i].re = normalizedData_data[i] / firstStepSquared_data[i];
      r1[i].im = 0.0;
    }
  } else {
    e_binary_expand_op(sp, r, x, firstStepSquared);
  }
  emxFree_real_T(sp, &x);
  emxFree_real_T(sp, &firstStepSquared);
  st.site = &cf_emlrtRSI;
  b_acos(&st, r);
  r1 = r->data;
  i = cornerAngle->size[0];
  cornerAngle->size[0] = r->size[0];
  emxEnsureCapacity_real_T(sp, cornerAngle, i, &pk_emlrtRTEI);
  normalizedData_data = cornerAngle->data;
  m = r->size[0];
  for (i = 0; i < m; i++) {
    normalizedData_data[i] = r1[i].re;
  }
  emxFree_creal_T(sp, &r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void d_binary_expand_op(const emlrtStack *sp,
                               emxArray_boolean_T *sharpCorners,
                               const emxArray_real_T *dataPoints)
{
  emxArray_boolean_T *r;
  int32_T dataPoints_idx_0;
  int32_T i;
  int32_T stride_1_0;
  boolean_T *r1;
  boolean_T *sharpCorners_data;
  sharpCorners_data = sharpCorners->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_boolean_T(sp, &r, &nt_emlrtRTEI);
  dataPoints_idx_0 = dataPoints->size[0] - 2;
  i = r->size[0];
  if (sharpCorners->size[0] == 1) {
    r->size[0] = dataPoints_idx_0;
  } else {
    r->size[0] = sharpCorners->size[0];
  }
  emxEnsureCapacity_boolean_T(sp, r, i, &nt_emlrtRTEI);
  r1 = r->data;
  stride_1_0 = (sharpCorners->size[0] != 1);
  if (sharpCorners->size[0] != 1) {
    dataPoints_idx_0 = sharpCorners->size[0];
  }
  for (i = 0; i < dataPoints_idx_0; i++) {
    r1[i] = sharpCorners_data[i * stride_1_0];
  }
  i = sharpCorners->size[0];
  sharpCorners->size[0] = r->size[0];
  emxEnsureCapacity_boolean_T(sp, sharpCorners, i, &nt_emlrtRTEI);
  sharpCorners_data = sharpCorners->data;
  dataPoints_idx_0 = r->size[0];
  for (i = 0; i < dataPoints_idx_0; i++) {
    sharpCorners_data[i] = r1[i];
  }
  emxFree_boolean_T(sp, &r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void e_binary_expand_op(const emlrtStack *sp, emxArray_creal_T *r1,
                               const emxArray_real_T *x,
                               const emxArray_real_T *firstStepSquared)
{
  creal_T *r;
  const real_T *firstStepSquared_data;
  const real_T *x_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  firstStepSquared_data = firstStepSquared->data;
  x_data = x->data;
  i = r1->size[0];
  if (firstStepSquared->size[0] == 1) {
    r1->size[0] = x->size[0];
  } else {
    r1->size[0] = firstStepSquared->size[0];
  }
  emxEnsureCapacity_creal_T(sp, r1, i, &ok_emlrtRTEI);
  r = r1->data;
  stride_0_0 = (x->size[0] != 1);
  stride_1_0 = (firstStepSquared->size[0] != 1);
  if (firstStepSquared->size[0] == 1) {
    loop_ub = x->size[0];
  } else {
    loop_ub = firstStepSquared->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    r[i].re = x_data[i * stride_0_0] / firstStepSquared_data[i * stride_1_0];
    r[i].im = 0.0;
  }
}

static void f_binary_expand_op(const emlrtStack *sp, emxArray_real_T *x,
                               const emxArray_real_T *longStepSquared)
{
  emxArray_real_T *b_x;
  const real_T *longStepSquared_data;
  real_T *b_x_data;
  real_T *x_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  longStepSquared_data = longStepSquared->data;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_x, 1, &uk_emlrtRTEI, true);
  i = b_x->size[0];
  if (longStepSquared->size[0] == 1) {
    b_x->size[0] = x->size[0];
  } else {
    b_x->size[0] = longStepSquared->size[0];
  }
  emxEnsureCapacity_real_T(sp, b_x, i, &uk_emlrtRTEI);
  b_x_data = b_x->data;
  stride_0_0 = (x->size[0] != 1);
  stride_1_0 = (longStepSquared->size[0] != 1);
  if (longStepSquared->size[0] == 1) {
    loop_ub = x->size[0];
  } else {
    loop_ub = longStepSquared->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    b_x_data[i] =
        (x_data[i * stride_0_0] - longStepSquared_data[i * stride_1_0]) / 2.0;
  }
  i = x->size[0];
  x->size[0] = b_x->size[0];
  emxEnsureCapacity_real_T(sp, x, i, &uk_emlrtRTEI);
  x_data = x->data;
  loop_ub = b_x->size[0];
  for (i = 0; i < loop_ub; i++) {
    x_data[i] = b_x_data[i];
  }
  emxFree_real_T(sp, &b_x);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void g_binary_expand_op(const emlrtStack *sp, emxArray_real_T *longStep,
                               const emxArray_real_T *normalizedData,
                               int32_T i2, int32_T i3, int32_T i4)
{
  const real_T *normalizedData_data;
  real_T *longStep_data;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  normalizedData_data = normalizedData->data;
  i = longStep->size[0] * longStep->size[1];
  if (i4 + 1 == 1) {
    longStep->size[0] = (i3 - i2) + 1;
  } else {
    longStep->size[0] = i4 + 1;
  }
  longStep->size[1] = 2;
  emxEnsureCapacity_real_T(sp, longStep, i, &gk_emlrtRTEI);
  longStep_data = longStep->data;
  stride_0_0 = ((i3 - i2) + 1 != 1);
  stride_1_0 = (i4 + 1 != 1);
  if (i4 + 1 == 1) {
    loop_ub = (i3 - i2) + 1;
  } else {
    loop_ub = i4 + 1;
  }
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      longStep_data[i1 + longStep->size[0] * i] =
          normalizedData_data[(i2 + i1 * stride_0_0) +
                              normalizedData->size[0] * i] -
          normalizedData_data[i1 * stride_1_0 + normalizedData->size[0] * i];
    }
  }
}

static void h_binary_expand_op(const emlrtStack *sp,
                               emxArray_real_T *secondStep,
                               const emxArray_real_T *normalizedData,
                               int32_T i2, int32_T i3, int32_T i4, int32_T i5)
{
  const real_T *normalizedData_data;
  real_T *secondStep_data;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  normalizedData_data = normalizedData->data;
  i = secondStep->size[0] * secondStep->size[1];
  if ((i5 - i4) + 1 == 1) {
    secondStep->size[0] = (i3 - i2) + 1;
  } else {
    secondStep->size[0] = (i5 - i4) + 1;
  }
  secondStep->size[1] = 2;
  emxEnsureCapacity_real_T(sp, secondStep, i, &fk_emlrtRTEI);
  secondStep_data = secondStep->data;
  stride_0_0 = ((i3 - i2) + 1 != 1);
  stride_1_0 = ((i5 - i4) + 1 != 1);
  if ((i5 - i4) + 1 == 1) {
    loop_ub = (i3 - i2) + 1;
  } else {
    loop_ub = (i5 - i4) + 1;
  }
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      secondStep_data[i1 + secondStep->size[0] * i] =
          normalizedData_data[(i2 + i1 * stride_0_0) +
                              normalizedData->size[0] * i] -
          normalizedData_data[(i4 + i1 * stride_1_0) +
                              normalizedData->size[0] * i];
    }
  }
}

static void minus(const emlrtStack *sp, emxArray_real_T *normalizedData,
                  const emxArray_real_T *longStep)
{
  emxArray_real_T *b_normalizedData;
  const real_T *longStep_data;
  real_T *b_normalizedData_data;
  real_T *normalizedData_data;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  longStep_data = longStep->data;
  normalizedData_data = normalizedData->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_normalizedData, 2, &ck_emlrtRTEI, true);
  i = b_normalizedData->size[0] * b_normalizedData->size[1];
  if (longStep->size[0] == 1) {
    b_normalizedData->size[0] = normalizedData->size[0];
  } else {
    b_normalizedData->size[0] = longStep->size[0];
  }
  b_normalizedData->size[1] = 2;
  emxEnsureCapacity_real_T(sp, b_normalizedData, i, &ck_emlrtRTEI);
  b_normalizedData_data = b_normalizedData->data;
  stride_0_0 = (normalizedData->size[0] != 1);
  stride_1_0 = (longStep->size[0] != 1);
  if (longStep->size[0] == 1) {
    loop_ub = normalizedData->size[0];
  } else {
    loop_ub = longStep->size[0];
  }
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_normalizedData_data[i1 + b_normalizedData->size[0] * i] =
          normalizedData_data[i1 * stride_0_0 + normalizedData->size[0] * i] -
          longStep_data[i1 * stride_1_0 + longStep->size[0] * i];
    }
  }
  i = normalizedData->size[0] * normalizedData->size[1];
  normalizedData->size[0] = b_normalizedData->size[0];
  normalizedData->size[1] = 2;
  emxEnsureCapacity_real_T(sp, normalizedData, i, &ck_emlrtRTEI);
  normalizedData_data = normalizedData->data;
  loop_ub = b_normalizedData->size[0];
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      normalizedData_data[i1 + normalizedData->size[0] * i] =
          b_normalizedData_data[i1 + b_normalizedData->size[0] * i];
    }
  }
  emxFree_real_T(sp, &b_normalizedData);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
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
  const real_T *sldProfile_data;
  const real_T *x_data;
  real_T deltaY;
  real_T deltaY_tmp;
  real_T *aboveVals_data;
  real_T *y_data;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T *ii_data;
  int32_T *where_data;
  boolean_T *b_sldProfile_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  sldProfile_data = sldProfile->data;
  x_data = x->data;
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
  emxEnsureCapacity_real_T(sp, y, i, &qj_emlrtRTEI);
  y_data = y->data;
  /*  if vectorizable */
  /*    % For uniformity reasons, transform the 'x' array into a column vector.
   */
  /*    % In this way it does not matter if it is given as a column or a row */
  /*    % vector. */
  /*    [newValues{:}] = func(x(:)); */
  /*    y = cell2mat(newValues); */
  /*  else */
  i = x->size[0];
  emxInit_int32_T(sp, &where, &sj_emlrtRTEI);
  emxInit_real_T(sp, &aboveVals, 1, &xj_emlrtRTEI, true);
  emxInit_int32_T(sp, &ii, &yj_emlrtRTEI);
  emxInit_boolean_T(sp, &b_sldProfile, &rj_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    /*  Remove cell array so no need for cell2mat */
    /*  which won't compile - AVH */
    /* [newValues{:}] = func(x(i)); */
    /* y(i,:) = cell2mat(newValues); */
    st.site = &ee_emlrtRSI;
    if (b_i + 1 > x->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, x->size[0], &ng_emlrtBCI, &st);
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
    b_st.site = &fe_emlrtRSI;
    loop_ub = sldProfile->size[0];
    i1 = b_sldProfile->size[0];
    b_sldProfile->size[0] = sldProfile->size[0];
    emxEnsureCapacity_boolean_T(&b_st, b_sldProfile, i1, &rj_emlrtRTEI);
    b_sldProfile_data = b_sldProfile->data;
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_sldProfile_data[i1] = (sldProfile_data[i1] == x_data[b_i]);
    }
    c_st.site = &ie_emlrtRSI;
    eml_find(&c_st, b_sldProfile, ii);
    ii_data = ii->data;
    i1 = where->size[0];
    where->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(&b_st, where, i1, &sj_emlrtRTEI);
    where_data = where->data;
    loop_ub = ii->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      where_data[i1] = ii_data[i1];
    }
    if (where->size[0] != 0) {
      i1 = aboveVals->size[0];
      aboveVals->size[0] = where->size[0];
      emxEnsureCapacity_real_T(&st, aboveVals, i1, &tj_emlrtRTEI);
      aboveVals_data = aboveVals->data;
      loop_ub = where->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        if ((where_data[i1] < 1) || (where_data[i1] > sldProfile->size[0])) {
          emlrtDynamicBoundsCheckR2012b(where_data[i1], 1, sldProfile->size[0],
                                        &ug_emlrtBCI, &st);
        }
        aboveVals_data[i1] =
            sldProfile_data[(where_data[i1] + sldProfile->size[0]) - 1];
      }
    } else {
      b_st.site = &ge_emlrtRSI;
      loop_ub = sldProfile->size[0];
      i1 = b_sldProfile->size[0];
      b_sldProfile->size[0] = sldProfile->size[0];
      emxEnsureCapacity_boolean_T(&b_st, b_sldProfile, i1, &uj_emlrtRTEI);
      b_sldProfile_data = b_sldProfile->data;
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_sldProfile_data[i1] = (x_data[b_i] > sldProfile_data[i1]);
      }
      c_st.site = &ie_emlrtRSI;
      eml_find(&c_st, b_sldProfile, ii);
      ii_data = ii->data;
      i1 = where->size[0];
      where->size[0] = ii->size[0];
      emxEnsureCapacity_int32_T(&b_st, where, i1, &vj_emlrtRTEI);
      where_data = where->data;
      loop_ub = ii->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        where_data[i1] = ii_data[i1];
      }
      b_st.site = &he_emlrtRSI;
      loop_ub = sldProfile->size[0];
      i1 = b_sldProfile->size[0];
      b_sldProfile->size[0] = sldProfile->size[0];
      emxEnsureCapacity_boolean_T(&b_st, b_sldProfile, i1, &wj_emlrtRTEI);
      b_sldProfile_data = b_sldProfile->data;
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_sldProfile_data[i1] = (x_data[b_i] < sldProfile_data[i1]);
      }
      c_st.site = &ie_emlrtRSI;
      eml_find(&c_st, b_sldProfile, ii);
      ii_data = ii->data;
      i1 = aboveVals->size[0];
      aboveVals->size[0] = ii->size[0];
      emxEnsureCapacity_real_T(&b_st, aboveVals, i1, &xj_emlrtRTEI);
      aboveVals_data = aboveVals->data;
      loop_ub = ii->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        aboveVals_data[i1] = ii_data[i1];
      }
      if (where->size[0] < 1) {
        emlrtDynamicBoundsCheckR2012b(where->size[0], 1, where->size[0],
                                      &og_emlrtBCI, &st);
      }
      if (1 > aboveVals->size[0]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, aboveVals->size[0], &pg_emlrtBCI,
                                      &st);
      }
      i1 = where_data[where->size[0] - 1];
      if ((i1 < 1) || (i1 > sldProfile->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, sldProfile->size[0], &qg_emlrtBCI,
                                      &st);
      }
      if (((int32_T)aboveVals_data[0] < 1) ||
          ((int32_T)aboveVals_data[0] > sldProfile->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)aboveVals_data[0], 1,
                                      sldProfile->size[0], &rg_emlrtBCI, &st);
      }
      i1 = where_data[where->size[0] - 1];
      if ((i1 < 1) || (i1 > sldProfile->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, sldProfile->size[0], &sg_emlrtBCI,
                                      &st);
      }
      i1 = where_data[where->size[0] - 1];
      if ((i1 < 1) || (i1 > sldProfile->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, sldProfile->size[0], &tg_emlrtBCI,
                                      &st);
      }
      deltaY_tmp =
          sldProfile_data[((int32_T)aboveVals_data[0] + sldProfile->size[0]) -
                          1];
      deltaY =
          (x_data[b_i] - sldProfile_data[where_data[where->size[0] - 1] - 1]) *
          (muDoubleScalarAbs(deltaY_tmp -
                             sldProfile_data[(where_data[where->size[0] - 1] +
                                              sldProfile->size[0]) -
                                             1]) /
           (sldProfile_data[(int32_T)aboveVals_data[0] - 1] -
            sldProfile_data[where_data[where->size[0] - 1] - 1]));
      if (sldProfile_data[(where_data[where->size[0] - 1] +
                           sldProfile->size[0]) -
                          1] < deltaY_tmp) {
        i1 = aboveVals->size[0];
        aboveVals->size[0] = 1;
        emxEnsureCapacity_real_T(&st, aboveVals, i1, &tj_emlrtRTEI);
        aboveVals_data = aboveVals->data;
        aboveVals_data[0] = sldProfile_data[(where_data[where->size[0] - 1] +
                                             sldProfile->size[0]) -
                                            1] +
                            deltaY;
      } else {
        i1 = aboveVals->size[0];
        aboveVals->size[0] = 1;
        emxEnsureCapacity_real_T(&st, aboveVals, i1, &tj_emlrtRTEI);
        aboveVals_data = aboveVals->data;
        aboveVals_data[0] = sldProfile_data[(where_data[where->size[0] - 1] +
                                             sldProfile->size[0]) -
                                            1] -
                            deltaY;
      }
      /* sldVal = interp1(z,rho,x); */
    }
    if (1 != aboveVals->size[0]) {
      emlrtSubAssignSizeCheck1dR2017a(1, aboveVals->size[0], &k_emlrtECI,
                                      (emlrtCTX)sp);
    }
    if (b_i + 1 > y->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, y->size[0], &vg_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    y_data[b_i] = aboveVals_data[0];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_boolean_T(sp, &b_sldProfile);
  emxFree_int32_T(sp, &ii);
  emxFree_real_T(sp, &aboveVals);
  emxFree_int32_T(sp, &where);
  /* end */
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void or (const emlrtStack *sp, emxArray_boolean_T *segmentsToSplit,
                const emxArray_boolean_T *r1)
{
  emxArray_boolean_T *b_segmentsToSplit;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  const boolean_T *r;
  boolean_T *b_segmentsToSplit_data;
  boolean_T *segmentsToSplit_data;
  r = r1->data;
  segmentsToSplit_data = segmentsToSplit->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_boolean_T(sp, &b_segmentsToSplit, &cj_emlrtRTEI);
  i = b_segmentsToSplit->size[0];
  if (r1->size[0] == 1) {
    b_segmentsToSplit->size[0] = segmentsToSplit->size[0];
  } else {
    b_segmentsToSplit->size[0] = r1->size[0];
  }
  emxEnsureCapacity_boolean_T(sp, b_segmentsToSplit, i, &cj_emlrtRTEI);
  b_segmentsToSplit_data = b_segmentsToSplit->data;
  stride_0_0 = (segmentsToSplit->size[0] != 1);
  stride_1_0 = (r1->size[0] != 1);
  if (r1->size[0] == 1) {
    loop_ub = segmentsToSplit->size[0];
  } else {
    loop_ub = r1->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    b_segmentsToSplit_data[i] =
        (segmentsToSplit_data[i * stride_0_0] || r[i * stride_1_0]);
  }
  i = segmentsToSplit->size[0];
  segmentsToSplit->size[0] = b_segmentsToSplit->size[0];
  emxEnsureCapacity_boolean_T(sp, segmentsToSplit, i, &cj_emlrtRTEI);
  segmentsToSplit_data = segmentsToSplit->data;
  loop_ub = b_segmentsToSplit->size[0];
  for (i = 0; i < loop_ub; i++) {
    segmentsToSplit_data[i] = b_segmentsToSplit_data[i];
  }
  emxFree_boolean_T(sp, &b_segmentsToSplit);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void plus(const emlrtStack *sp, emxArray_real_T *x,
                 const emxArray_real_T *firstStepSquared,
                 const emxArray_real_T *secondStepSquared)
{
  const real_T *firstStepSquared_data;
  const real_T *secondStepSquared_data;
  real_T *x_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  secondStepSquared_data = secondStepSquared->data;
  firstStepSquared_data = firstStepSquared->data;
  i = x->size[0];
  if (secondStepSquared->size[0] == 1) {
    x->size[0] = firstStepSquared->size[0];
  } else {
    x->size[0] = secondStepSquared->size[0];
  }
  emxEnsureCapacity_real_T(sp, x, i, &nk_emlrtRTEI);
  x_data = x->data;
  stride_0_0 = (firstStepSquared->size[0] != 1);
  stride_1_0 = (secondStepSquared->size[0] != 1);
  if (secondStepSquared->size[0] == 1) {
    loop_ub = firstStepSquared->size[0];
  } else {
    loop_ub = secondStepSquared->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    x_data[i] = firstStepSquared_data[i * stride_0_0] +
                secondStepSquared_data[i * stride_1_0];
  }
}

static void times(const emlrtStack *sp, emxArray_real_T *firstStepSquared,
                  const emxArray_real_T *secondStepSquared)
{
  emxArray_real_T *b_firstStepSquared;
  const real_T *secondStepSquared_data;
  real_T *b_firstStepSquared_data;
  real_T *firstStepSquared_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  secondStepSquared_data = secondStepSquared->data;
  firstStepSquared_data = firstStepSquared->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_firstStepSquared, 1, &ot_emlrtRTEI, true);
  i = b_firstStepSquared->size[0];
  if (secondStepSquared->size[0] == 1) {
    b_firstStepSquared->size[0] = firstStepSquared->size[0];
  } else {
    b_firstStepSquared->size[0] = secondStepSquared->size[0];
  }
  emxEnsureCapacity_real_T(sp, b_firstStepSquared, i, &ot_emlrtRTEI);
  b_firstStepSquared_data = b_firstStepSquared->data;
  stride_0_0 = (firstStepSquared->size[0] != 1);
  stride_1_0 = (secondStepSquared->size[0] != 1);
  if (secondStepSquared->size[0] == 1) {
    loop_ub = firstStepSquared->size[0];
  } else {
    loop_ub = secondStepSquared->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    b_firstStepSquared_data[i] = firstStepSquared_data[i * stride_0_0] *
                                 secondStepSquared_data[i * stride_1_0];
  }
  i = firstStepSquared->size[0];
  firstStepSquared->size[0] = b_firstStepSquared->size[0];
  emxEnsureCapacity_real_T(sp, firstStepSquared, i, &ot_emlrtRTEI);
  firstStepSquared_data = firstStepSquared->data;
  loop_ub = b_firstStepSquared->size[0];
  for (i = 0; i < loop_ub; i++) {
    firstStepSquared_data[i] = b_firstStepSquared_data[i];
  }
  emxFree_real_T(sp, &b_firstStepSquared);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void adaptive_new(const emlrtStack *sp, const emxArray_real_T *sldProfile,
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
  emxArray_real_T *b_dataPoints;
  emxArray_real_T *dataPoints;
  emxArray_real_T *hiVal;
  emxArray_real_T *newDataPoints;
  emxArray_real_T *newDomain;
  emxArray_real_T *r;
  real_T maxval[2];
  real_T minval[2];
  real_T b;
  real_T *dataPoints_data;
  real_T *hiVal_data;
  real_T *newDataPoints_data;
  real_T *newDomain_data;
  int32_T b_i;
  int32_T b_input_sizes_idx_0;
  int32_T i;
  int32_T input_sizes_idx_0;
  int32_T nRefinements;
  int32_T trueCount;
  int32_T *r7;
  int32_T *r8;
  boolean_T exitg1;
  boolean_T overflow;
  boolean_T p;
  boolean_T *r6;
  boolean_T *segmentsToSplit_data;
  boolean_T *sharpCorners_data;
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
  emxInit_real_T(sp, &newDomain, 1, &vi_emlrtRTEI, true);
  emxInit_real_T(sp, &r, 2, &oj_emlrtRTEI, true);
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
  st.site = &wd_emlrtRSI;
  linspace(&st, startDomain[0], startDomain[1], nPoints, r);
  hiVal_data = r->data;
  i = newDomain->size[0];
  newDomain->size[0] = r->size[1];
  emxEnsureCapacity_real_T(sp, newDomain, i, &vi_emlrtRTEI);
  newDomain_data = newDomain->data;
  input_sizes_idx_0 = r->size[1];
  for (i = 0; i < input_sizes_idx_0; i++) {
    newDomain_data[i] = hiVal_data[i];
  }
  emxFree_real_T(sp, &r);
  emxInit_real_T(sp, &hiVal, 1, &mj_emlrtRTEI, true);
  /*  Normalize the input function: This step allows to use the same syntax for
   */
  /*  functions with single or multiple output parameters. */
  /*  Remove this syntax for compile - AVH */
  /* func = @(x) normalizeFunction(x,sldProfile,vectorizable); */
  /*  Evaluate the input function on the initial set of points. */
  st.site = &xd_emlrtRSI;
  normalizeFunction(&st, newDomain, sldProfile, hiVal);
  hiVal_data = hiVal->data;
  /* dataPoints = [initialDomain(:), func(initialDomain(:))]; */
  st.site = &yd_emlrtRSI;
  b_st.site = &nb_emlrtRSI;
  c_st.site = &ob_emlrtRSI;
  if (hiVal->size[0] != newDomain->size[0]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &gb_emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  emxInit_real_T(&c_st, &dataPoints, 2, &wi_emlrtRTEI, true);
  i = dataPoints->size[0] * dataPoints->size[1];
  dataPoints->size[0] = newDomain->size[0];
  dataPoints->size[1] = 2;
  emxEnsureCapacity_real_T(&b_st, dataPoints, i, &wi_emlrtRTEI);
  dataPoints_data = dataPoints->data;
  input_sizes_idx_0 = newDomain->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    dataPoints_data[i] = newDomain_data[i];
  }
  input_sizes_idx_0 = hiVal->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    dataPoints_data[i + dataPoints->size[0]] = hiVal_data[i];
  }
  /*  Iterative function refinement */
  /*  if displayWaitbar */
  /*    refinementWaitbar = waitbar(0,['Evaluating function
   * ',func2str(func)],... */
  /*      'CreateCancelBtn','setappdata(gcbf,''canceling'',true)'); */
  /*    setappdata(refinementWaitbar,'canceling',false) */
  /*  end */
  nRefinements = 0;
  emxInit_boolean_T(sp, &sharpCorners, &aj_emlrtRTEI);
  emxInit_boolean_T(sp, &segmentsToSplit, &nj_emlrtRTEI);
  emxInit_boolean_T(sp, &r1, &fj_emlrtRTEI);
  emxInit_real_T(sp, &newDataPoints, 2, &ej_emlrtRTEI, true);
  emxInit_int32_T(sp, &r2, &fj_emlrtRTEI);
  emxInit_int32_T(sp, &r3, &gj_emlrtRTEI);
  emxInit_int32_T(sp, &r4, &fj_emlrtRTEI);
  emxInit_int32_T(sp, &r5, &gj_emlrtRTEI);
  emxInit_real_T(sp, &b_dataPoints, 2, &yi_emlrtRTEI, true);
  exitg1 = false;
  while ((!exitg1) && (nRefinements < 10)) {
    /*  calculate the box which encloses the current data points: */
    st.site = &ae_emlrtRSI;
    b_st.site = &pd_emlrtRSI;
    c_st.site = &qd_emlrtRSI;
    d_st.site = &rd_emlrtRSI;
    if (dataPoints->size[0] == 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &kb_emlrtRTEI,
                                    "Coder:toolbox:autoDimIncompatibility",
                                    "Coder:toolbox:autoDimIncompatibility", 0);
    }
    if (dataPoints->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &lb_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }
    e_st.site = &me_emlrtRSI;
    f_st.site = &ne_emlrtRSI;
    g_st.site = &oe_emlrtRSI;
    i = dataPoints->size[0];
    overflow =
        ((2 <= dataPoints->size[0]) && (dataPoints->size[0] > 2147483646));
    for (input_sizes_idx_0 = 0; input_sizes_idx_0 < 2; input_sizes_idx_0++) {
      maxval[input_sizes_idx_0] =
          dataPoints_data[dataPoints->size[0] * input_sizes_idx_0];
      h_st.site = &pe_emlrtRSI;
      if (overflow) {
        i_st.site = &j_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (b_i = 2; b_i <= i; b_i++) {
        b = dataPoints_data[(b_i + dataPoints->size[0] * input_sizes_idx_0) -
                            1];
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
    st.site = &ae_emlrtRSI;
    b_st.site = &qe_emlrtRSI;
    c_st.site = &re_emlrtRSI;
    d_st.site = &se_emlrtRSI;
    if (dataPoints->size[0] == 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &kb_emlrtRTEI,
                                    "Coder:toolbox:autoDimIncompatibility",
                                    "Coder:toolbox:autoDimIncompatibility", 0);
    }
    e_st.site = &me_emlrtRSI;
    f_st.site = &ne_emlrtRSI;
    g_st.site = &oe_emlrtRSI;
    i = dataPoints->size[0];
    overflow = (dataPoints->size[0] > 2147483646);
    for (input_sizes_idx_0 = 0; input_sizes_idx_0 < 2; input_sizes_idx_0++) {
      minval[input_sizes_idx_0] =
          dataPoints_data[dataPoints->size[0] * input_sizes_idx_0];
      h_st.site = &pe_emlrtRSI;
      if (overflow) {
        i_st.site = &j_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (b_i = 2; b_i <= i; b_i++) {
        b = dataPoints_data[(b_i + dataPoints->size[0] * input_sizes_idx_0) -
                            1];
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
    emxEnsureCapacity_real_T(sp, b_dataPoints, i, &yi_emlrtRTEI);
    hiVal_data = b_dataPoints->data;
    for (i = 0; i < 2; i++) {
      for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
        hiVal_data[b_i + b_dataPoints->size[0] * i] =
            dataPoints_data[b_i + dataPoints->size[0] * i];
      }
      maxval[i] -= minval[i];
    }
    st.site = &be_emlrtRSI;
    calculateCentralAngles(&st, b_dataPoints, maxval, newDomain);
    newDomain_data = newDomain->data;
    i = sharpCorners->size[0];
    sharpCorners->size[0] = newDomain->size[0];
    emxEnsureCapacity_boolean_T(sp, sharpCorners, i, &aj_emlrtRTEI);
    sharpCorners_data = sharpCorners->data;
    input_sizes_idx_0 = newDomain->size[0];
    for (i = 0; i < input_sizes_idx_0; i++) {
      sharpCorners_data[i] = (newDomain_data[i] < minAngle);
    }
    if ((dataPoints->size[0] - 2 != sharpCorners->size[0]) &&
        ((dataPoints->size[0] - 2 != 1) && (sharpCorners->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(dataPoints->size[0] - 2,
                                  sharpCorners->size[0], &f_emlrtECI,
                                  (emlrtCTX)sp);
    }
    if (dataPoints->size[0] - 2 == sharpCorners->size[0]) {
      i = sharpCorners->size[0];
      sharpCorners->size[0] = dataPoints->size[0] - 2;
      emxEnsureCapacity_boolean_T(sp, sharpCorners, i, &bj_emlrtRTEI);
      sharpCorners_data = sharpCorners->data;
    } else {
      st.site = &kj_emlrtRSI;
      d_binary_expand_op(&st, sharpCorners, dataPoints);
      sharpCorners_data = sharpCorners->data;
    }
    /*  For N points there are N-2 triangles and N-1 triangle sides. Each */
    /*  triangle side is a segment, which can be split or not depending on the
     */
    /*  refinement parameters. */
    i = segmentsToSplit->size[0];
    segmentsToSplit->size[0] = sharpCorners->size[0] + 1;
    emxEnsureCapacity_boolean_T(sp, segmentsToSplit, i, &cj_emlrtRTEI);
    segmentsToSplit_data = segmentsToSplit->data;
    input_sizes_idx_0 = sharpCorners->size[0];
    for (i = 0; i < input_sizes_idx_0; i++) {
      segmentsToSplit_data[i] = sharpCorners_data[i];
    }
    segmentsToSplit_data[sharpCorners->size[0]] = false;
    i = r1->size[0];
    r1->size[0] = sharpCorners->size[0] + 1;
    emxEnsureCapacity_boolean_T(sp, r1, i, &dj_emlrtRTEI);
    r6 = r1->data;
    r6[0] = false;
    input_sizes_idx_0 = sharpCorners->size[0];
    for (i = 0; i < input_sizes_idx_0; i++) {
      r6[i + 1] = sharpCorners_data[i];
    }
    if ((segmentsToSplit->size[0] != r1->size[0]) &&
        ((segmentsToSplit->size[0] != 1) && (r1->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(segmentsToSplit->size[0], r1->size[0],
                                  &g_emlrtECI, (emlrtCTX)sp);
    }
    if (segmentsToSplit->size[0] == r1->size[0]) {
      input_sizes_idx_0 = segmentsToSplit->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        segmentsToSplit_data[i] = (segmentsToSplit_data[i] || r6[i]);
      }
    } else {
      st.site = &jj_emlrtRSI;
      or (&st, segmentsToSplit, r1);
      segmentsToSplit_data = segmentsToSplit->data;
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
    st.site = &ce_emlrtRSI;
    if (any(&st, segmentsToSplit)) {
      st.site = &de_emlrtRSI;
      /*  increaseSampling increase the sampling of an input function */
      b_input_sizes_idx_0 = segmentsToSplit->size[0];
      for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
        if (segmentsToSplit_data[b_i] &&
            ((b_i + 1 < 1) || (b_i + 1 > segmentsToSplit->size[0]))) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, segmentsToSplit->size[0],
                                        &kg_emlrtBCI, &st);
        }
      }
      b_input_sizes_idx_0 = segmentsToSplit->size[0];
      trueCount = 0;
      for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
        if (segmentsToSplit_data[b_i]) {
          trueCount++;
        }
      }
      i = newDataPoints->size[0] * newDataPoints->size[1];
      newDataPoints->size[0] = trueCount;
      newDataPoints->size[1] = 2;
      emxEnsureCapacity_real_T(&st, newDataPoints, i, &ej_emlrtRTEI);
      newDataPoints_data = newDataPoints->data;
      input_sizes_idx_0 = trueCount << 1;
      for (i = 0; i < input_sizes_idx_0; i++) {
        newDataPoints_data[i] = 0.0;
      }
      i = r1->size[0];
      r1->size[0] = segmentsToSplit->size[0] + 1;
      emxEnsureCapacity_boolean_T(&st, r1, i, &fj_emlrtRTEI);
      r6 = r1->data;
      input_sizes_idx_0 = segmentsToSplit->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        r6[i] = segmentsToSplit_data[i];
      }
      r6[segmentsToSplit->size[0]] = false;
      b_input_sizes_idx_0 = r1->size[0];
      for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
        if (r6[b_i] && (b_i + 1 > dataPoints->size[0])) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, dataPoints->size[0],
                                        &lg_emlrtBCI, &st);
        }
      }
      i = sharpCorners->size[0];
      sharpCorners->size[0] = segmentsToSplit->size[0] + 1;
      emxEnsureCapacity_boolean_T(&st, sharpCorners, i, &gj_emlrtRTEI);
      sharpCorners_data = sharpCorners->data;
      sharpCorners_data[0] = false;
      input_sizes_idx_0 = segmentsToSplit->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        sharpCorners_data[i + 1] = segmentsToSplit_data[i];
      }
      b_input_sizes_idx_0 = sharpCorners->size[0];
      for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
        if (sharpCorners_data[b_i] && (b_i + 1 > dataPoints->size[0])) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, dataPoints->size[0],
                                        &mg_emlrtBCI, &st);
        }
      }
      b_input_sizes_idx_0 = r1->size[0] - 1;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (r6[b_i]) {
          input_sizes_idx_0++;
        }
      }
      i = r2->size[0];
      r2->size[0] = input_sizes_idx_0;
      emxEnsureCapacity_int32_T(&st, r2, i, &hj_emlrtRTEI);
      r7 = r2->data;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (r6[b_i]) {
          r7[input_sizes_idx_0] = b_i + 1;
          input_sizes_idx_0++;
        }
      }
      b_input_sizes_idx_0 = sharpCorners->size[0] - 1;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (sharpCorners_data[b_i]) {
          input_sizes_idx_0++;
        }
      }
      i = r3->size[0];
      r3->size[0] = input_sizes_idx_0;
      emxEnsureCapacity_int32_T(&st, r3, i, &hj_emlrtRTEI);
      r7 = r3->data;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (sharpCorners_data[b_i]) {
          r7[input_sizes_idx_0] = b_i + 1;
          input_sizes_idx_0++;
        }
      }
      if ((r2->size[0] != r3->size[0]) &&
          ((r2->size[0] != 1) && (r3->size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(r2->size[0], r3->size[0], &h_emlrtECI, &st);
      }
      b_input_sizes_idx_0 = r1->size[0] - 1;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (r6[b_i]) {
          input_sizes_idx_0++;
        }
      }
      i = r4->size[0];
      r4->size[0] = input_sizes_idx_0;
      emxEnsureCapacity_int32_T(&st, r4, i, &hj_emlrtRTEI);
      r7 = r4->data;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (r6[b_i]) {
          r7[input_sizes_idx_0] = b_i + 1;
          input_sizes_idx_0++;
        }
      }
      b_input_sizes_idx_0 = sharpCorners->size[0] - 1;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (sharpCorners_data[b_i]) {
          input_sizes_idx_0++;
        }
      }
      i = r5->size[0];
      r5->size[0] = input_sizes_idx_0;
      emxEnsureCapacity_int32_T(&st, r5, i, &hj_emlrtRTEI);
      r8 = r5->data;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (sharpCorners_data[b_i]) {
          r8[input_sizes_idx_0] = b_i + 1;
          input_sizes_idx_0++;
        }
      }
      if (r4->size[0] == r5->size[0]) {
        i = newDomain->size[0];
        newDomain->size[0] = r4->size[0];
        emxEnsureCapacity_real_T(&st, newDomain, i, &ij_emlrtRTEI);
        newDomain_data = newDomain->data;
        input_sizes_idx_0 = r4->size[0];
        for (i = 0; i < input_sizes_idx_0; i++) {
          newDomain_data[i] =
              0.5 * (dataPoints_data[r7[i] - 1] + dataPoints_data[r8[i] - 1]);
        }
      } else {
        b_st.site = &ij_emlrtRSI;
        c_binary_expand_op(&b_st, newDomain, dataPoints, r4, r5);
        newDomain_data = newDomain->data;
      }
      emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &newDomain->size[0], 1,
                                    &i_emlrtECI, &st);
      input_sizes_idx_0 = newDomain->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        newDataPoints_data[i] = newDomain_data[i];
      }
      input_sizes_idx_0 = newDataPoints->size[0];
      i = hiVal->size[0];
      hiVal->size[0] = newDataPoints->size[0];
      emxEnsureCapacity_real_T(&st, hiVal, i, &jj_emlrtRTEI);
      hiVal_data = hiVal->data;
      for (i = 0; i < input_sizes_idx_0; i++) {
        hiVal_data[i] = newDataPoints_data[i];
      }
      b_st.site = &mf_emlrtRSI;
      normalizeFunction(&b_st, hiVal, sldProfile, newDomain);
      newDomain_data = newDomain->data;
      emlrtSubAssignSizeCheckR2012b(&newDataPoints->size[0], 1,
                                    &newDomain->size[0], 1, &j_emlrtECI, &st);
      input_sizes_idx_0 = newDomain->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        newDataPoints_data[i + newDataPoints->size[0]] = newDomain_data[i];
      }
      /*  For simplicity append the new points at the end and then sort. */
      b_st.site = &nf_emlrtRSI;
      c_st.site = &of_emlrtRSI;
      d_st.site = &ob_emlrtRSI;
      if (dataPoints->size[0] != 0) {
        input_sizes_idx_0 = dataPoints->size[0];
      } else {
        input_sizes_idx_0 = 0;
      }
      if (newDataPoints->size[0] != 0) {
        b_input_sizes_idx_0 = newDataPoints->size[0];
      } else {
        b_input_sizes_idx_0 = 0;
      }
      if (dataPoints->size[0] != 0) {
        trueCount = dataPoints->size[0];
      } else {
        trueCount = 0;
      }
      i = b_dataPoints->size[0] * b_dataPoints->size[1];
      b_dataPoints->size[0] = input_sizes_idx_0 + b_input_sizes_idx_0;
      b_dataPoints->size[1] = 2;
      emxEnsureCapacity_real_T(&st, b_dataPoints, i, &kj_emlrtRTEI);
      hiVal_data = b_dataPoints->data;
      for (i = 0; i < 2; i++) {
        for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
          hiVal_data[b_i + b_dataPoints->size[0] * i] =
              dataPoints_data[b_i + dataPoints->size[0] * i];
        }
      }
      for (i = 0; i < 2; i++) {
        for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
          hiVal_data[(b_i + trueCount) + b_dataPoints->size[0] * i] =
              newDataPoints_data[b_i + newDataPoints->size[0] * i];
        }
      }
      i = dataPoints->size[0] * dataPoints->size[1];
      dataPoints->size[0] = b_dataPoints->size[0];
      dataPoints->size[1] = 2;
      emxEnsureCapacity_real_T(&st, dataPoints, i, &lj_emlrtRTEI);
      dataPoints_data = dataPoints->data;
      input_sizes_idx_0 = b_dataPoints->size[0] * 2;
      for (i = 0; i < input_sizes_idx_0; i++) {
        dataPoints_data[i] = hiVal_data[i];
      }
      b_st.site = &nf_emlrtRSI;
      sortrows(&b_st, dataPoints);
      dataPoints_data = dataPoints->data;
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
  emxFree_real_T(sp, &b_dataPoints);
  emxFree_int32_T(sp, &r5);
  emxFree_int32_T(sp, &r4);
  emxFree_int32_T(sp, &r3);
  emxFree_int32_T(sp, &r2);
  emxFree_real_T(sp, &newDataPoints);
  emxFree_boolean_T(sp, &r1);
  emxFree_boolean_T(sp, &segmentsToSplit);
  emxFree_boolean_T(sp, &sharpCorners);
  emxFree_real_T(sp, &hiVal);
  emxFree_real_T(sp, &newDomain);
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
  emxEnsureCapacity_real_T(sp, out->f1, i, &xi_emlrtRTEI);
  input_sizes_idx_0 = dataPoints->size[0] * 2;
  for (i = 0; i < input_sizes_idx_0; i++) {
    out->f1->data[i] = dataPoints_data[i];
  }
  emxFree_real_T(sp, &dataPoints);
  /*  elseif nargout>1 */
  /*    out{1} = dataPoints(:,1); */
  /*    out{2} = dataPoints(:,2:end); */
  /*  end */
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void b_adaptive_new(const emlrtStack *sp, const emxArray_real_T *sldProfile,
                    const real_T startDomain[2], real_T minAngle,
                    real_T nPoints, cell_19 *out)
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
  real_T *dataPoints_data;
  real_T *hiVal_data;
  real_T *newDataPoints_data;
  real_T *newDomain_data;
  int32_T b_i;
  int32_T b_input_sizes_idx_0;
  int32_T i;
  int32_T input_sizes_idx_0;
  int32_T nRefinements;
  int32_T trueCount;
  int32_T *r7;
  int32_T *r8;
  boolean_T exitg1;
  boolean_T overflow;
  boolean_T p;
  boolean_T *r6;
  boolean_T *segmentsToSplit_data;
  boolean_T *sharpCorners_data;
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
  emxInit_real_T(sp, &newDomain, 1, &vi_emlrtRTEI, true);
  emxInit_real_T(sp, &r, 2, &oj_emlrtRTEI, true);
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
  st.site = &wd_emlrtRSI;
  linspace(&st, startDomain[0], startDomain[1], nPoints, r);
  hiVal_data = r->data;
  i = newDomain->size[0];
  newDomain->size[0] = r->size[1];
  emxEnsureCapacity_real_T(sp, newDomain, i, &vi_emlrtRTEI);
  newDomain_data = newDomain->data;
  input_sizes_idx_0 = r->size[1];
  for (i = 0; i < input_sizes_idx_0; i++) {
    newDomain_data[i] = hiVal_data[i];
  }
  emxFree_real_T(sp, &r);
  emxInit_real_T(sp, &hiVal, 1, &mj_emlrtRTEI, true);
  /*  Normalize the input function: This step allows to use the same syntax for
   */
  /*  functions with single or multiple output parameters. */
  /*  Remove this syntax for compile - AVH */
  /* func = @(x) normalizeFunction(x,sldProfile,vectorizable); */
  /*  Evaluate the input function on the initial set of points. */
  st.site = &xd_emlrtRSI;
  b_normalizeFunction(&st, newDomain, sldProfile, hiVal);
  hiVal_data = hiVal->data;
  /* dataPoints = [initialDomain(:), func(initialDomain(:))]; */
  st.site = &yd_emlrtRSI;
  b_st.site = &nb_emlrtRSI;
  c_st.site = &ob_emlrtRSI;
  if (hiVal->size[0] != newDomain->size[0]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &gb_emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  emxInit_real_T(&c_st, &dataPoints, 2, &wi_emlrtRTEI, true);
  i = dataPoints->size[0] * dataPoints->size[1];
  dataPoints->size[0] = newDomain->size[0];
  dataPoints->size[1] = 2;
  emxEnsureCapacity_real_T(&b_st, dataPoints, i, &wi_emlrtRTEI);
  dataPoints_data = dataPoints->data;
  input_sizes_idx_0 = newDomain->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    dataPoints_data[i] = newDomain_data[i];
  }
  input_sizes_idx_0 = hiVal->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    dataPoints_data[i + dataPoints->size[0]] = hiVal_data[i];
  }
  /*  Iterative function refinement */
  /*  if displayWaitbar */
  /*    refinementWaitbar = waitbar(0,['Evaluating function
   * ',func2str(func)],... */
  /*      'CreateCancelBtn','setappdata(gcbf,''canceling'',true)'); */
  /*    setappdata(refinementWaitbar,'canceling',false) */
  /*  end */
  nRefinements = 0;
  emxInit_boolean_T(sp, &sharpCorners, &aj_emlrtRTEI);
  emxInit_boolean_T(sp, &segmentsToSplit, &nj_emlrtRTEI);
  emxInit_boolean_T(sp, &r1, &fj_emlrtRTEI);
  emxInit_real_T(sp, &newDataPoints, 2, &ej_emlrtRTEI, true);
  emxInit_int32_T(sp, &r2, &fj_emlrtRTEI);
  emxInit_int32_T(sp, &r3, &gj_emlrtRTEI);
  emxInit_int32_T(sp, &r4, &fj_emlrtRTEI);
  emxInit_int32_T(sp, &r5, &gj_emlrtRTEI);
  emxInit_real_T(sp, &b_dataPoints, 2, &yi_emlrtRTEI, true);
  exitg1 = false;
  while ((!exitg1) && (nRefinements < 10)) {
    /*  calculate the box which encloses the current data points: */
    st.site = &ae_emlrtRSI;
    b_st.site = &pd_emlrtRSI;
    c_st.site = &qd_emlrtRSI;
    d_st.site = &rd_emlrtRSI;
    if (dataPoints->size[0] == 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &kb_emlrtRTEI,
                                    "Coder:toolbox:autoDimIncompatibility",
                                    "Coder:toolbox:autoDimIncompatibility", 0);
    }
    if (dataPoints->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &lb_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }
    e_st.site = &me_emlrtRSI;
    f_st.site = &ne_emlrtRSI;
    g_st.site = &oe_emlrtRSI;
    i = dataPoints->size[0];
    overflow =
        ((2 <= dataPoints->size[0]) && (dataPoints->size[0] > 2147483646));
    for (input_sizes_idx_0 = 0; input_sizes_idx_0 < 2; input_sizes_idx_0++) {
      maxval[input_sizes_idx_0] =
          dataPoints_data[dataPoints->size[0] * input_sizes_idx_0];
      h_st.site = &pe_emlrtRSI;
      if (overflow) {
        i_st.site = &j_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (b_i = 2; b_i <= i; b_i++) {
        b = dataPoints_data[(b_i + dataPoints->size[0] * input_sizes_idx_0) -
                            1];
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
    st.site = &ae_emlrtRSI;
    b_st.site = &qe_emlrtRSI;
    c_st.site = &re_emlrtRSI;
    d_st.site = &se_emlrtRSI;
    if (dataPoints->size[0] == 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &kb_emlrtRTEI,
                                    "Coder:toolbox:autoDimIncompatibility",
                                    "Coder:toolbox:autoDimIncompatibility", 0);
    }
    e_st.site = &me_emlrtRSI;
    f_st.site = &ne_emlrtRSI;
    g_st.site = &oe_emlrtRSI;
    i = dataPoints->size[0];
    overflow = (dataPoints->size[0] > 2147483646);
    for (input_sizes_idx_0 = 0; input_sizes_idx_0 < 2; input_sizes_idx_0++) {
      minval[input_sizes_idx_0] =
          dataPoints_data[dataPoints->size[0] * input_sizes_idx_0];
      h_st.site = &pe_emlrtRSI;
      if (overflow) {
        i_st.site = &j_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (b_i = 2; b_i <= i; b_i++) {
        b = dataPoints_data[(b_i + dataPoints->size[0] * input_sizes_idx_0) -
                            1];
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
    emxEnsureCapacity_real_T(sp, b_dataPoints, i, &yi_emlrtRTEI);
    hiVal_data = b_dataPoints->data;
    for (i = 0; i < 2; i++) {
      for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
        hiVal_data[b_i + b_dataPoints->size[0] * i] =
            dataPoints_data[b_i + dataPoints->size[0] * i];
      }
      maxval[i] -= minval[i];
    }
    st.site = &be_emlrtRSI;
    calculateCentralAngles(&st, b_dataPoints, maxval, newDomain);
    newDomain_data = newDomain->data;
    i = sharpCorners->size[0];
    sharpCorners->size[0] = newDomain->size[0];
    emxEnsureCapacity_boolean_T(sp, sharpCorners, i, &aj_emlrtRTEI);
    sharpCorners_data = sharpCorners->data;
    input_sizes_idx_0 = newDomain->size[0];
    for (i = 0; i < input_sizes_idx_0; i++) {
      sharpCorners_data[i] = (newDomain_data[i] < minAngle);
    }
    if ((dataPoints->size[0] - 2 != sharpCorners->size[0]) &&
        ((dataPoints->size[0] - 2 != 1) && (sharpCorners->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(dataPoints->size[0] - 2,
                                  sharpCorners->size[0], &f_emlrtECI,
                                  (emlrtCTX)sp);
    }
    if (dataPoints->size[0] - 2 == sharpCorners->size[0]) {
      i = sharpCorners->size[0];
      sharpCorners->size[0] = dataPoints->size[0] - 2;
      emxEnsureCapacity_boolean_T(sp, sharpCorners, i, &bj_emlrtRTEI);
      sharpCorners_data = sharpCorners->data;
    } else {
      st.site = &kj_emlrtRSI;
      d_binary_expand_op(&st, sharpCorners, dataPoints);
      sharpCorners_data = sharpCorners->data;
    }
    /*  For N points there are N-2 triangles and N-1 triangle sides. Each */
    /*  triangle side is a segment, which can be split or not depending on the
     */
    /*  refinement parameters. */
    i = segmentsToSplit->size[0];
    segmentsToSplit->size[0] = sharpCorners->size[0] + 1;
    emxEnsureCapacity_boolean_T(sp, segmentsToSplit, i, &cj_emlrtRTEI);
    segmentsToSplit_data = segmentsToSplit->data;
    input_sizes_idx_0 = sharpCorners->size[0];
    for (i = 0; i < input_sizes_idx_0; i++) {
      segmentsToSplit_data[i] = sharpCorners_data[i];
    }
    segmentsToSplit_data[sharpCorners->size[0]] = false;
    i = r1->size[0];
    r1->size[0] = sharpCorners->size[0] + 1;
    emxEnsureCapacity_boolean_T(sp, r1, i, &dj_emlrtRTEI);
    r6 = r1->data;
    r6[0] = false;
    input_sizes_idx_0 = sharpCorners->size[0];
    for (i = 0; i < input_sizes_idx_0; i++) {
      r6[i + 1] = sharpCorners_data[i];
    }
    if ((segmentsToSplit->size[0] != r1->size[0]) &&
        ((segmentsToSplit->size[0] != 1) && (r1->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(segmentsToSplit->size[0], r1->size[0],
                                  &g_emlrtECI, (emlrtCTX)sp);
    }
    if (segmentsToSplit->size[0] == r1->size[0]) {
      input_sizes_idx_0 = segmentsToSplit->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        segmentsToSplit_data[i] = (segmentsToSplit_data[i] || r6[i]);
      }
    } else {
      st.site = &jj_emlrtRSI;
      or (&st, segmentsToSplit, r1);
      segmentsToSplit_data = segmentsToSplit->data;
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
    st.site = &ce_emlrtRSI;
    if (any(&st, segmentsToSplit)) {
      st.site = &de_emlrtRSI;
      /*  increaseSampling increase the sampling of an input function */
      b_input_sizes_idx_0 = segmentsToSplit->size[0];
      for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
        if (segmentsToSplit_data[b_i] &&
            ((b_i + 1 < 1) || (b_i + 1 > segmentsToSplit->size[0]))) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, segmentsToSplit->size[0],
                                        &kg_emlrtBCI, &st);
        }
      }
      b_input_sizes_idx_0 = segmentsToSplit->size[0];
      trueCount = 0;
      for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
        if (segmentsToSplit_data[b_i]) {
          trueCount++;
        }
      }
      i = newDataPoints->size[0] * newDataPoints->size[1];
      newDataPoints->size[0] = trueCount;
      newDataPoints->size[1] = 2;
      emxEnsureCapacity_real_T(&st, newDataPoints, i, &ej_emlrtRTEI);
      newDataPoints_data = newDataPoints->data;
      input_sizes_idx_0 = trueCount << 1;
      for (i = 0; i < input_sizes_idx_0; i++) {
        newDataPoints_data[i] = 0.0;
      }
      i = r1->size[0];
      r1->size[0] = segmentsToSplit->size[0] + 1;
      emxEnsureCapacity_boolean_T(&st, r1, i, &fj_emlrtRTEI);
      r6 = r1->data;
      input_sizes_idx_0 = segmentsToSplit->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        r6[i] = segmentsToSplit_data[i];
      }
      r6[segmentsToSplit->size[0]] = false;
      b_input_sizes_idx_0 = r1->size[0];
      for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
        if (r6[b_i] && (b_i + 1 > dataPoints->size[0])) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, dataPoints->size[0],
                                        &lg_emlrtBCI, &st);
        }
      }
      i = sharpCorners->size[0];
      sharpCorners->size[0] = segmentsToSplit->size[0] + 1;
      emxEnsureCapacity_boolean_T(&st, sharpCorners, i, &gj_emlrtRTEI);
      sharpCorners_data = sharpCorners->data;
      sharpCorners_data[0] = false;
      input_sizes_idx_0 = segmentsToSplit->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        sharpCorners_data[i + 1] = segmentsToSplit_data[i];
      }
      b_input_sizes_idx_0 = sharpCorners->size[0];
      for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
        if (sharpCorners_data[b_i] && (b_i + 1 > dataPoints->size[0])) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, dataPoints->size[0],
                                        &mg_emlrtBCI, &st);
        }
      }
      b_input_sizes_idx_0 = r1->size[0] - 1;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (r6[b_i]) {
          input_sizes_idx_0++;
        }
      }
      i = r2->size[0];
      r2->size[0] = input_sizes_idx_0;
      emxEnsureCapacity_int32_T(&st, r2, i, &hj_emlrtRTEI);
      r7 = r2->data;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (r6[b_i]) {
          r7[input_sizes_idx_0] = b_i + 1;
          input_sizes_idx_0++;
        }
      }
      b_input_sizes_idx_0 = sharpCorners->size[0] - 1;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (sharpCorners_data[b_i]) {
          input_sizes_idx_0++;
        }
      }
      i = r3->size[0];
      r3->size[0] = input_sizes_idx_0;
      emxEnsureCapacity_int32_T(&st, r3, i, &hj_emlrtRTEI);
      r7 = r3->data;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (sharpCorners_data[b_i]) {
          r7[input_sizes_idx_0] = b_i + 1;
          input_sizes_idx_0++;
        }
      }
      if ((r2->size[0] != r3->size[0]) &&
          ((r2->size[0] != 1) && (r3->size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(r2->size[0], r3->size[0], &h_emlrtECI, &st);
      }
      b_input_sizes_idx_0 = r1->size[0] - 1;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (r6[b_i]) {
          input_sizes_idx_0++;
        }
      }
      i = r4->size[0];
      r4->size[0] = input_sizes_idx_0;
      emxEnsureCapacity_int32_T(&st, r4, i, &hj_emlrtRTEI);
      r7 = r4->data;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (r6[b_i]) {
          r7[input_sizes_idx_0] = b_i + 1;
          input_sizes_idx_0++;
        }
      }
      b_input_sizes_idx_0 = sharpCorners->size[0] - 1;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (sharpCorners_data[b_i]) {
          input_sizes_idx_0++;
        }
      }
      i = r5->size[0];
      r5->size[0] = input_sizes_idx_0;
      emxEnsureCapacity_int32_T(&st, r5, i, &hj_emlrtRTEI);
      r8 = r5->data;
      input_sizes_idx_0 = 0;
      for (b_i = 0; b_i <= b_input_sizes_idx_0; b_i++) {
        if (sharpCorners_data[b_i]) {
          r8[input_sizes_idx_0] = b_i + 1;
          input_sizes_idx_0++;
        }
      }
      if (r4->size[0] == r5->size[0]) {
        i = newDomain->size[0];
        newDomain->size[0] = r4->size[0];
        emxEnsureCapacity_real_T(&st, newDomain, i, &ij_emlrtRTEI);
        newDomain_data = newDomain->data;
        input_sizes_idx_0 = r4->size[0];
        for (i = 0; i < input_sizes_idx_0; i++) {
          newDomain_data[i] =
              0.5 * (dataPoints_data[r7[i] - 1] + dataPoints_data[r8[i] - 1]);
        }
      } else {
        b_st.site = &ij_emlrtRSI;
        c_binary_expand_op(&b_st, newDomain, dataPoints, r4, r5);
        newDomain_data = newDomain->data;
      }
      emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &newDomain->size[0], 1,
                                    &i_emlrtECI, &st);
      input_sizes_idx_0 = newDomain->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        newDataPoints_data[i] = newDomain_data[i];
      }
      input_sizes_idx_0 = newDataPoints->size[0];
      i = hiVal->size[0];
      hiVal->size[0] = newDataPoints->size[0];
      emxEnsureCapacity_real_T(&st, hiVal, i, &jj_emlrtRTEI);
      hiVal_data = hiVal->data;
      for (i = 0; i < input_sizes_idx_0; i++) {
        hiVal_data[i] = newDataPoints_data[i];
      }
      b_st.site = &mf_emlrtRSI;
      b_normalizeFunction(&b_st, hiVal, sldProfile, newDomain);
      newDomain_data = newDomain->data;
      emlrtSubAssignSizeCheckR2012b(&newDataPoints->size[0], 1,
                                    &newDomain->size[0], 1, &j_emlrtECI, &st);
      input_sizes_idx_0 = newDomain->size[0];
      for (i = 0; i < input_sizes_idx_0; i++) {
        newDataPoints_data[i + newDataPoints->size[0]] = newDomain_data[i];
      }
      /*  For simplicity append the new points at the end and then sort. */
      b_st.site = &nf_emlrtRSI;
      c_st.site = &of_emlrtRSI;
      d_st.site = &ob_emlrtRSI;
      if (dataPoints->size[0] != 0) {
        input_sizes_idx_0 = dataPoints->size[0];
      } else {
        input_sizes_idx_0 = 0;
      }
      if (newDataPoints->size[0] != 0) {
        b_input_sizes_idx_0 = newDataPoints->size[0];
      } else {
        b_input_sizes_idx_0 = 0;
      }
      if (dataPoints->size[0] != 0) {
        trueCount = dataPoints->size[0];
      } else {
        trueCount = 0;
      }
      i = b_dataPoints->size[0] * b_dataPoints->size[1];
      b_dataPoints->size[0] = input_sizes_idx_0 + b_input_sizes_idx_0;
      b_dataPoints->size[1] = 2;
      emxEnsureCapacity_real_T(&st, b_dataPoints, i, &kj_emlrtRTEI);
      hiVal_data = b_dataPoints->data;
      for (i = 0; i < 2; i++) {
        for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
          hiVal_data[b_i + b_dataPoints->size[0] * i] =
              dataPoints_data[b_i + dataPoints->size[0] * i];
        }
      }
      for (i = 0; i < 2; i++) {
        for (b_i = 0; b_i < b_input_sizes_idx_0; b_i++) {
          hiVal_data[(b_i + trueCount) + b_dataPoints->size[0] * i] =
              newDataPoints_data[b_i + newDataPoints->size[0] * i];
        }
      }
      i = dataPoints->size[0] * dataPoints->size[1];
      dataPoints->size[0] = b_dataPoints->size[0];
      dataPoints->size[1] = 2;
      emxEnsureCapacity_real_T(&st, dataPoints, i, &lj_emlrtRTEI);
      dataPoints_data = dataPoints->data;
      input_sizes_idx_0 = b_dataPoints->size[0] * 2;
      for (i = 0; i < input_sizes_idx_0; i++) {
        dataPoints_data[i] = hiVal_data[i];
      }
      b_st.site = &nf_emlrtRSI;
      sortrows(&b_st, dataPoints);
      dataPoints_data = dataPoints->data;
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
  emxFree_real_T(sp, &b_dataPoints);
  emxFree_int32_T(sp, &r5);
  emxFree_int32_T(sp, &r4);
  emxFree_int32_T(sp, &r3);
  emxFree_int32_T(sp, &r2);
  emxFree_real_T(sp, &newDataPoints);
  emxFree_boolean_T(sp, &r1);
  emxFree_boolean_T(sp, &segmentsToSplit);
  emxFree_boolean_T(sp, &sharpCorners);
  emxFree_real_T(sp, &hiVal);
  emxFree_real_T(sp, &newDomain);
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
  emxEnsureCapacity_real_T(sp, out->f1, i, &xi_emlrtRTEI);
  input_sizes_idx_0 = dataPoints->size[0] * 2;
  for (i = 0; i < input_sizes_idx_0; i++) {
    out->f1->data[i] = dataPoints_data[i];
  }
  emxFree_real_T(sp, &dataPoints);
  /*  elseif nargout>1 */
  /*    out{1} = dataPoints(:,1); */
  /*    out{2} = dataPoints(:,2:end); */
  /*  end */
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (adaptive_new.c) */
