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
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
omp_lock_t emlrtLockGlobal;
omp_nest_lock_t emlrtNestLockGlobal;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131594U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "reflectivity_calculation",          /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo t_emlrtRSI = { 22,         /* lineNo */
  "cat",                               /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

emlrtRSInfo u_emlrtRSI = { 102,        /* lineNo */
  "cat_impl",                          /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

emlrtRSInfo hb_emlrtRSI = { 20,        /* lineNo */
  "sum",                               /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/sum.m"/* pathName */
};

emlrtRSInfo ib_emlrtRSI = { 99,        /* lineNo */
  "sumprod",                           /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pathName */
};

emlrtRSInfo jb_emlrtRSI = { 125,       /* lineNo */
  "combineVectorElements",             /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

emlrtRSInfo kb_emlrtRSI = { 185,       /* lineNo */
  "colMajorFlatIter",                  /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

emlrtRSInfo lb_emlrtRSI = { 21,        /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

emlrtRSInfo pb_emlrtRSI = { 41,        /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"/* pathName */
};

emlrtRSInfo qb_emlrtRSI = { 139,       /* lineNo */
  "scalar_float_power",                /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

emlrtRSInfo xb_emlrtRSI = { 62,        /* lineNo */
  "applyScalarFunction",               /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pathName */
};

emlrtRSInfo yb_emlrtRSI = { 51,        /* lineNo */
  "scalar_erf",                        /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/specfun/private/eml_erfcore.m"/* pathName */
};

emlrtRSInfo ac_emlrtRSI = { 236,       /* lineNo */
  "scalar_erf_and_erfc",               /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/specfun/private/eml_erfcore.m"/* pathName */
};

emlrtRSInfo bc_emlrtRSI = { 238,       /* lineNo */
  "scalar_erf_and_erfc",               /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/specfun/private/eml_erfcore.m"/* pathName */
};

emlrtRSInfo cc_emlrtRSI = { 17,        /* lineNo */
  "log2",                              /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elfun/log2.m"/* pathName */
};

emlrtRSInfo dc_emlrtRSI = { 47,        /* lineNo */
  "applyScalarFunction",               /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pathName */
};

emlrtRSInfo ec_emlrtRSI = { 17,        /* lineNo */
  "log2",                              /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/+scalar/log2.m"/* pathName */
};

emlrtRSInfo fc_emlrtRSI = { 12,        /* lineNo */
  "pow2",                              /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elfun/pow2.m"/* pathName */
};

emlrtRSInfo gc_emlrtRSI = { 49,        /* lineNo */
  "applyScalarFunction",               /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pathName */
};

emlrtRSInfo hc_emlrtRSI = { 12,        /* lineNo */
  "pow2",                              /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/+scalar/pow2.m"/* pathName */
};

emlrtRSInfo kc_emlrtRSI = { 14,        /* lineNo */
  "max",                               /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/max.m"/* pathName */
};

emlrtRSInfo lc_emlrtRSI = { 44,        /* lineNo */
  "minOrMax",                          /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

emlrtRSInfo mc_emlrtRSI = { 79,        /* lineNo */
  "maximum",                           /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

emlrtRSInfo qc_emlrtRSI = { 924,       /* lineNo */
  "minOrMaxRealVector",                /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

emlrtRSInfo rc_emlrtRSI = { 992,       /* lineNo */
  "minOrMaxRealVectorKernel",          /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

emlrtRSInfo dd_emlrtRSI = { 41,        /* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

emlrtRSInfo ed_emlrtRSI = { 153,       /* lineNo */
  "eml_find",                          /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

emlrtRSInfo fd_emlrtRSI = { 377,       /* lineNo */
  "find_first_indices",                /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

emlrtRSInfo gd_emlrtRSI = { 397,       /* lineNo */
  "find_first_indices",                /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

emlrtRSInfo de_emlrtRSI = { 33,        /* lineNo */
  "applyScalarFunctionInPlace",        /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/applyScalarFunctionInPlace.m"/* pathName */
};

emlrtRSInfo je_emlrtRSI = { 27,        /* lineNo */
  "cat",                               /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

emlrtRSInfo ue_emlrtRSI = { 17,        /* lineNo */
  "sortLE",                            /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/sortLE.m"/* pathName */
};

emlrtRSInfo ve_emlrtRSI = { 48,        /* lineNo */
  "sortrowsLE",                        /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/sortrowsLE.m"/* pathName */
};

emlrtRSInfo lf_emlrtRSI = { 306,       /* lineNo */
  "eml_float_colon",                   /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

emlrtRSInfo nf_emlrtRSI = { 29,        /* lineNo */
  "abeles_single",                     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/Abeles/abeles_single.m"/* pathName */
};

emlrtRSInfo of_emlrtRSI = { 45,        /* lineNo */
  "abeles_single",                     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/Abeles/abeles_single.m"/* pathName */
};

emlrtRSInfo ig_emlrtRSI = { 32,        /* lineNo */
  "abeles_paraPoints",                 /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/Abeles/abeles_paraPoints.m"/* pathName */
};

emlrtRSInfo jg_emlrtRSI = { 48,        /* lineNo */
  "abeles_paraPoints",                 /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/Abeles/abeles_paraPoints.m"/* pathName */
};

emlrtRTEInfo hb_emlrtRTEI = { 283,     /* lineNo */
  27,                                  /* colNo */
  "check_non_axis_size",               /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

emlrtRTEInfo kb_emlrtRTEI = { 46,      /* lineNo */
  23,                                  /* colNo */
  "sumprod",                           /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pName */
};

emlrtRTEInfo ob_emlrtRTEI = { 387,     /* lineNo */
  1,                                   /* colNo */
  "find_first_indices",                /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

emlrtRTEInfo pb_emlrtRTEI = { 20,      /* lineNo */
  15,                                  /* colNo */
  "rdivide_helper",                    /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/rdivide_helper.m"/* pName */
};

emlrtRTEInfo tb_emlrtRTEI = { 14,      /* lineNo */
  9,                                   /* colNo */
  "asin",                              /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elfun/asin.m"/* pName */
};

emlrtRTEInfo lh_emlrtRTEI = { 153,     /* lineNo */
  13,                                  /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

emlrtRTEInfo mh_emlrtRTEI = { 41,      /* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

emlrtRTEInfo vh_emlrtRTEI = { 33,      /* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

/* End of code generation (reflectivity_calculation_data.c) */
