/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
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
    131610U,                                              /* fVersionInfo */
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
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" /* pathName */
};

emlrtRSInfo w_emlrtRSI = {
    58,                       /* lineNo */
    "standardTF_layers_core", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pathName */
};

emlrtRSInfo x_emlrtRSI = {
    69,                       /* lineNo */
    "standardTF_layers_core", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pathName */
};

emlrtRSInfo y_emlrtRSI = {
    76,                       /* lineNo */
    "standardTF_layers_core", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pathName */
};

emlrtRSInfo ab_emlrtRSI = {
    84,                       /* lineNo */
    "standardTF_layers_core", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pathName */
};

emlrtRSInfo bb_emlrtRSI = {
    88,                       /* lineNo */
    "standardTF_layers_core", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pathName */
};

emlrtRSInfo cb_emlrtRSI = {
    91,                       /* lineNo */
    "standardTF_layers_core", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pathName */
};

emlrtRSInfo db_emlrtRSI = {
    94,                       /* lineNo */
    "standardTF_layers_core", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pathName */
};

emlrtRSInfo
    nb_emlrtRSI =
        {
            22,    /* lineNo */
            "cat", /* fcnName */
            "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
            "cat.m" /* pathName */
};

emlrtRSInfo
    ob_emlrtRSI =
        {
            96,         /* lineNo */
            "cat_impl", /* fcnName */
            "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
            "cat.m" /* pathName */
};

emlrtRSInfo pd_emlrtRSI = {
    15,    /* lineNo */
    "max", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/max.m" /* pathName
                                                                            */
};

emlrtRSInfo qd_emlrtRSI = {
    44,         /* lineNo */
    "minOrMax", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "minOrMax.m" /* pathName */
};

emlrtRSInfo rd_emlrtRSI = {
    79,        /* lineNo */
    "maximum", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "minOrMax.m" /* pathName */
};

emlrtRSInfo sd_emlrtRSI = {
    175,             /* lineNo */
    "unaryMinOrMax", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "unaryMinOrMax.m" /* pathName */
};

emlrtRSInfo td_emlrtRSI = {
    871,                    /* lineNo */
    "maxRealVectorOmitNaN", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "unaryMinOrMax.m" /* pathName */
};

emlrtRSInfo ie_emlrtRSI = {
    39,     /* lineNo */
    "find", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/elmat/find.m" /* pathName
                                                                           */
};

emlrtRSInfo ff_emlrtRSI = {
    34,               /* lineNo */
    "rdivide_helper", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "rdivide_helper.m" /* pathName */
};

emlrtRSInfo
    gf_emlrtRSI =
        {
            51,    /* lineNo */
            "div", /* fcnName */
            "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
            "div.m" /* pathName */
};

emlrtRSInfo
    hf_emlrtRSI =
        {
            259,                    /* lineNo */
            "assertCompatibleSize", /* fcnName */
            "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
            "div.m" /* pathName */
};

emlrtRSInfo if_emlrtRSI =
    {
        52,      /* lineNo */
        "ixfun", /* fcnName */
        "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
        "ixfun.m" /* pathName */
};

emlrtRSInfo jf_emlrtRSI = {
    45,                          /* lineNo */
    "applyBinaryScalarFunction", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "applyBinaryScalarFunction.m" /* pathName */
};

emlrtRSInfo kf_emlrtRSI = {
    66,                          /* lineNo */
    "applyBinaryScalarFunction", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "applyBinaryScalarFunction.m" /* pathName */
};

emlrtRSInfo lf_emlrtRSI = {
    127,        /* lineNo */
    "flatIter", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "applyBinaryScalarFunction.m" /* pathName */
};

emlrtRSInfo mf_emlrtRSI = {
    214,        /* lineNo */
    "flatIter", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "applyBinaryScalarFunction.m" /* pathName */
};

emlrtRSInfo pf_emlrtRSI = {
    33,                           /* lineNo */
    "applyScalarFunctionInPlace", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "applyScalarFunctionInPlace.m" /* pathName */
};

omp_lock_t emlrtLockGlobal;

omp_nest_lock_t emlrtNestLockGlobal;

emlrtRTEInfo u_emlrtRTEI = {
    15,                      /* lineNo */
    9,                       /* colNo */
    "assertSupportedString", /* fName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "assertSupportedString.m" /* pName */
};

emlrtDCInfo db_emlrtDCI = {
    3,                           /* lineNo */
    8,                           /* colNo */
    "applyBackgroundCorrection", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "applyBackgroundCorrection.m", /* pName */
    1                              /* checkKind */
};

emlrtBCInfo wf_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    10,                          /* lineNo */
    23,                          /* colNo */
    "shifted_dat",               /* aName */
    "applyBackgroundCorrection", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "applyBackgroundCorrection.m", /* pName */
    0                              /* checkKind */
};

emlrtECInfo emlrtECI = {
    -1,                          /* nDims */
    10,                          /* lineNo */
    9,                           /* colNo */
    "applyBackgroundCorrection", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "applyBackgroundCorrection.m" /* pName */
};

emlrtRTEInfo
    jb_emlrtRTEI =
        {
            271,                   /* lineNo */
            27,                    /* colNo */
            "check_non_axis_size", /* fName */
            "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
            "cat.m" /* pName */
};

emlrtRTEInfo rb_emlrtRTEI = {
    19,             /* lineNo */
    23,             /* colNo */
    "scalexpAlloc", /* fName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "scalexpAlloc.m" /* pName */
};

emlrtRTEInfo tb_emlrtRTEI = {
    14,     /* lineNo */
    9,      /* colNo */
    "asin", /* fName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/elfun/asin.m" /* pName
                                                                           */
};

emlrtRTEInfo ld_emlrtRTEI = {
    13,               /* lineNo */
    13,               /* colNo */
    "toLogicalCheck", /* fName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "toLogicalCheck.m" /* pName */
};

emlrtRTEInfo hh_emlrtRTEI = {
    71,                       /* lineNo */
    5,                        /* colNo */
    "standardTF_layers_core", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pName */
};

emlrtRTEInfo ih_emlrtRTEI = {
    79,                       /* lineNo */
    5,                        /* colNo */
    "standardTF_layers_core", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pName */
};

emlrtRTEInfo jh_emlrtRTEI = {
    77,                       /* lineNo */
    5,                        /* colNo */
    "standardTF_layers_core", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pName */
};

emlrtRTEInfo kh_emlrtRTEI = {
    80,                       /* lineNo */
    5,                        /* colNo */
    "standardTF_layers_core", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pName */
};

emlrtRTEInfo mh_emlrtRTEI = {
    6,                           /* lineNo */
    9,                           /* colNo */
    "applyBackgroundCorrection", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "applyBackgroundCorrection.m" /* pName */
};

emlrtRTEInfo nh_emlrtRTEI = {
    10,                          /* lineNo */
    28,                          /* colNo */
    "applyBackgroundCorrection", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "applyBackgroundCorrection.m" /* pName */
};

emlrtRTEInfo oh_emlrtRTEI = {
    7,                           /* lineNo */
    9,                           /* colNo */
    "applyBackgroundCorrection", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/callReflectivity/"
    "applyBackgroundCorrection.m" /* pName */
};

emlrtRTEInfo ph_emlrtRTEI = {
    76,                       /* lineNo */
    5,                        /* colNo */
    "standardTF_layers_core", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/standard_TF/"
    "standardTF_layers_core.m" /* pName */
};

emlrtRTEInfo xj_emlrtRTEI = {
    31,     /* lineNo */
    6,      /* colNo */
    "find", /* fName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/elmat/find.m" /* pName
                                                                           */
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

/* End of code generation (reflectivity_calculation_data.c) */
