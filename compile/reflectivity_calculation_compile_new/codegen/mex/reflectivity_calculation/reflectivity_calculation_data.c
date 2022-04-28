/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * reflectivity_calculation_data.c
 *
 * Code generation for function 'reflectivity_calculation_data'
 *
 */

/* Include files */
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131611U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "reflectivity_calculation",                           /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

emlrtRSInfo j_emlrtRSI = {
    21,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" /* pathName */
};

emlrtRSInfo w_emlrtRSI = {
    58,                       /* lineNo */
    "standardTF_layers_core", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pathName */
};

emlrtRSInfo x_emlrtRSI = {
    69,                       /* lineNo */
    "standardTF_layers_core", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pathName */
};

emlrtRSInfo y_emlrtRSI = {
    76,                       /* lineNo */
    "standardTF_layers_core", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pathName */
};

emlrtRSInfo ab_emlrtRSI = {
    84,                       /* lineNo */
    "standardTF_layers_core", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pathName */
};

emlrtRSInfo bb_emlrtRSI = {
    88,                       /* lineNo */
    "standardTF_layers_core", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pathName */
};

emlrtRSInfo cb_emlrtRSI = {
    91,                       /* lineNo */
    "standardTF_layers_core", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pathName */
};

emlrtRSInfo db_emlrtRSI = {
    94,                       /* lineNo */
    "standardTF_layers_core", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pathName */
};

emlrtRSInfo nb_emlrtRSI = {
    26,    /* lineNo */
    "cat", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/cat.m" /* pathName
                                                                       */
};

emlrtRSInfo ob_emlrtRSI = {
    100,        /* lineNo */
    "cat_impl", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/cat.m" /* pathName
                                                                       */
};

emlrtRSInfo oc_emlrtRSI = {
    71,                                                           /* lineNo */
    "power",                                                      /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/ops/power.m" /* pathName */
};

emlrtRSInfo pd_emlrtRSI = {
    15,    /* lineNo */
    "max", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/datafun/max.m" /* pathName
                                                                     */
};

emlrtRSInfo qd_emlrtRSI = {
    44,         /* lineNo */
    "minOrMax", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                            */
};

emlrtRSInfo rd_emlrtRSI = {
    79,        /* lineNo */
    "maximum", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                            */
};

emlrtRSInfo ie_emlrtRSI = {
    39,                                                            /* lineNo */
    "find",                                                        /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/elmat/find.m" /* pathName
                                                                    */
};

emlrtRSInfo ff_emlrtRSI =
    {
        34,               /* lineNo */
        "rdivide_helper", /* fcnName */
        "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/"
        "rdivide_helper.m" /* pathName */
};

emlrtRSInfo gf_emlrtRSI = {
    51,    /* lineNo */
    "div", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/div.m" /* pathName
                                                                       */
};

emlrtRSInfo if_emlrtRSI = {
    33,                           /* lineNo */
    "applyScalarFunctionInPlace", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/"
    "applyScalarFunctionInPlace.m" /* pathName */
};

omp_lock_t emlrtLockGlobal;

omp_nest_lock_t reflectivity_calculation_nestLockGlobal;

emlrtRTEInfo s_emlrtRTEI = {
    15,                      /* lineNo */
    9,                       /* colNo */
    "assertSupportedString", /* fName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/"
    "assertSupportedString.m" /* pName */
};

emlrtDCInfo db_emlrtDCI = {
    3,                           /* lineNo */
    8,                           /* colNo */
    "applyBackgroundCorrection", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callReflectivity/applyBackgroundCorrection.m", /* pName */
    1                                               /* checkKind */
};

emlrtBCInfo qf_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    10,                          /* lineNo */
    23,                          /* colNo */
    "shifted_dat",               /* aName */
    "applyBackgroundCorrection", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callReflectivity/applyBackgroundCorrection.m", /* pName */
    0                                               /* checkKind */
};

emlrtECInfo emlrtECI = {
    -1,                          /* nDims */
    10,                          /* lineNo */
    9,                           /* colNo */
    "applyBackgroundCorrection", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callReflectivity/applyBackgroundCorrection.m" /* pName */
};

emlrtRTEInfo gb_emlrtRTEI = {
    275,                   /* lineNo */
    27,                    /* colNo */
    "check_non_axis_size", /* fName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/cat.m" /* pName
                                                                       */
};

emlrtRTEInfo ob_emlrtRTEI = {
    13,                     /* lineNo */
    27,                     /* colNo */
    "assertCompatibleDims", /* fName */
    "/usr/local/MATLAB/R2021b/toolbox/shared/coder/coder/lib/+coder/+internal/"
    "assertCompatibleDims.m" /* pName */
};

emlrtRTEInfo sb_emlrtRTEI = {
    14,                                                            /* lineNo */
    9,                                                             /* colNo */
    "asin",                                                        /* fName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/elfun/asin.m" /* pName */
};

emlrtRTEInfo md_emlrtRTEI =
    {
        13,               /* lineNo */
        13,               /* colNo */
        "toLogicalCheck", /* fName */
        "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/"
        "toLogicalCheck.m" /* pName */
};

emlrtRTEInfo ih_emlrtRTEI = {
    71,                       /* lineNo */
    5,                        /* colNo */
    "standardTF_layers_core", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pName */
};

emlrtRTEInfo jh_emlrtRTEI = {
    79,                       /* lineNo */
    5,                        /* colNo */
    "standardTF_layers_core", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pName */
};

emlrtRTEInfo kh_emlrtRTEI = {
    77,                       /* lineNo */
    5,                        /* colNo */
    "standardTF_layers_core", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pName */
};

emlrtRTEInfo lh_emlrtRTEI = {
    80,                       /* lineNo */
    5,                        /* colNo */
    "standardTF_layers_core", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pName */
};

emlrtRTEInfo nh_emlrtRTEI = {
    6,                           /* lineNo */
    9,                           /* colNo */
    "applyBackgroundCorrection", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callReflectivity/applyBackgroundCorrection.m" /* pName */
};

emlrtRTEInfo oh_emlrtRTEI = {
    10,                          /* lineNo */
    28,                          /* colNo */
    "applyBackgroundCorrection", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callReflectivity/applyBackgroundCorrection.m" /* pName */
};

emlrtRTEInfo ph_emlrtRTEI = {
    7,                           /* lineNo */
    9,                           /* colNo */
    "applyBackgroundCorrection", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callReflectivity/applyBackgroundCorrection.m" /* pName */
};

emlrtRTEInfo qh_emlrtRTEI = {
    76,                       /* lineNo */
    5,                        /* colNo */
    "standardTF_layers_core", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pName */
};

emlrtRTEInfo fi_emlrtRTEI = {
    50,                 /* lineNo */
    5,                  /* colNo */
    "makeSLDProfileXY", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "makeSLDProfiles/makeSLDProfileXY.m" /* pName */
};

emlrtRTEInfo ij_emlrtRTEI = {
    429,            /* lineNo */
    22,             /* colNo */
    "adaptive_new", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/"
    "adaptive_new.m" /* pName */
};

emlrtRTEInfo yj_emlrtRTEI = {
    31,                                                            /* lineNo */
    6,                                                             /* colNo */
    "find",                                                        /* fName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/elmat/find.m" /* pName */
};

const char_T cv[128] = {
    '\x00', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\x07', '\x08',
    '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f', '\x10', '\x11',
    '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1a',
    '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ',    '!',    '\"',   '#',
    '$',    '%',    '&',    '\'',   '(',    ')',    '*',    '+',    ',',
    '-',    '.',    '/',    '0',    '1',    '2',    '3',    '4',    '5',
    '6',    '7',    '8',    '9',    ':',    ';',    '<',    '=',    '>',
    '?',    '@',    'a',    'b',    'c',    'd',    'e',    'f',    'g',
    'h',    'i',    'j',    'k',    'l',    'm',    'n',    'o',    'p',
    'q',    'r',    's',    't',    'u',    'v',    'w',    'x',    'y',
    'z',    '[',    '\\',   ']',    '^',    '_',    '`',    'a',    'b',
    'c',    'd',    'e',    'f',    'g',    'h',    'i',    'j',    'k',
    'l',    'm',    'n',    'o',    'p',    'q',    'r',    's',    't',
    'u',    'v',    'w',    'x',    'y',    'z',    '{',    '|',    '}',
    '~',    '\x7f'};

const char_T cv1[9] = {'c', 'o', 'n', 't', 'r', 'a', 's', 't', 's'};

emlrtRSInfo ij_emlrtRSI =
    {
        76,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" /* pathName */
};

emlrtRSInfo mj_emlrtRSI = {
    52,    /* lineNo */
    "div", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/eml/+coder/+internal/div.m" /* pathName
                                                                       */
};

/* End of code generation (reflectivity_calculation_data.c) */
