/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * dev_custlay_paraContrasts_data.c
 *
 * Code generation for function 'dev_custlay_paraContrasts_data'
 *
 */

/* Include files */
#include "dev_custlay_paraContrasts_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131610U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "dev_custlay_paraContrasts",                          /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

emlrtRSInfo
    w_emlrtRSI =
        {
            22,    /* lineNo */
            "cat", /* fcnName */
            "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
            "cat.m" /* pathName */
};

emlrtRSInfo
    x_emlrtRSI =
        {
            96,         /* lineNo */
            "cat_impl", /* fcnName */
            "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
            "cat.m" /* pathName */
};

emlrtRSInfo wb_emlrtRSI = {
    21,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" /* pathName */
};

emlrtRSInfo ad_emlrtRSI = {
    15,    /* lineNo */
    "max", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/max.m" /* pathName
                                                                            */
};

emlrtRSInfo bd_emlrtRSI = {
    44,         /* lineNo */
    "minOrMax", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "minOrMax.m" /* pathName */
};

emlrtRSInfo cd_emlrtRSI = {
    79,        /* lineNo */
    "maximum", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "minOrMax.m" /* pathName */
};

emlrtRSInfo dd_emlrtRSI = {
    175,             /* lineNo */
    "unaryMinOrMax", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "unaryMinOrMax.m" /* pathName */
};

emlrtRSInfo ed_emlrtRSI = {
    871,                    /* lineNo */
    "maxRealVectorOmitNaN", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "unaryMinOrMax.m" /* pathName */
};

emlrtRSInfo sd_emlrtRSI = {
    39,     /* lineNo */
    "find", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/elmat/find.m" /* pathName
                                                                           */
};

emlrtRSInfo pe_emlrtRSI = {
    34,               /* lineNo */
    "rdivide_helper", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "rdivide_helper.m" /* pathName */
};

emlrtRSInfo
    qe_emlrtRSI =
        {
            51,    /* lineNo */
            "div", /* fcnName */
            "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
            "div.m" /* pathName */
};

emlrtRSInfo
    re_emlrtRSI =
        {
            259,                    /* lineNo */
            "assertCompatibleSize", /* fcnName */
            "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
            "div.m" /* pathName */
};

emlrtRSInfo se_emlrtRSI =
    {
        52,      /* lineNo */
        "ixfun", /* fcnName */
        "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
        "ixfun.m" /* pathName */
};

emlrtRSInfo te_emlrtRSI = {
    45,                          /* lineNo */
    "applyBinaryScalarFunction", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "applyBinaryScalarFunction.m" /* pathName */
};

emlrtRSInfo ue_emlrtRSI = {
    66,                          /* lineNo */
    "applyBinaryScalarFunction", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "applyBinaryScalarFunction.m" /* pathName */
};

emlrtRSInfo ve_emlrtRSI = {
    127,        /* lineNo */
    "flatIter", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "applyBinaryScalarFunction.m" /* pathName */
};

emlrtRSInfo we_emlrtRSI = {
    214,        /* lineNo */
    "flatIter", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "applyBinaryScalarFunction.m" /* pathName */
};

emlrtRSInfo af_emlrtRSI = {
    33,                           /* lineNo */
    "applyScalarFunctionInPlace", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "applyScalarFunctionInPlace.m" /* pathName */
};

omp_lock_t emlrtLockGlobal;

omp_nest_lock_t emlrtNestLockGlobal;

emlrtRTEInfo
    h_emlrtRTEI =
        {
            271,                   /* lineNo */
            27,                    /* colNo */
            "check_non_axis_size", /* fName */
            "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
            "cat.m" /* pName */
};

emlrtRTEInfo q_emlrtRTEI = {
    19,             /* lineNo */
    23,             /* colNo */
    "scalexpAlloc", /* fName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "scalexpAlloc.m" /* pName */
};

emlrtRTEInfo oc_emlrtRTEI = {
    31,     /* lineNo */
    6,      /* colNo */
    "find", /* fName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/elmat/find.m" /* pName
                                                                           */
};

/* End of code generation (dev_custlay_paraContrasts_data.c) */
